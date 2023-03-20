/* 
 * mesibo sample code for sending and receiving real-time messages in C++
 * 
 * Refer to https://mesibo.com/documentation/install/linux/ for downloading mesibo C++ library
 *
 * Once you download and install mesibo C++ library, you can compile this sample code by issuing 
 * the following command
 *
 * $ g++ mesibo.cpp -lmesibo -o mesibo_sample
 *
 * Execute it by
 *
 * $ ./mesibo_sample
 *
 */
#include <stdlib.h>
#include <string.h>
#include <mesibo.h>

#define ERRORLOG(format, ...) do { fprintf(stderr, format, ## __VA_ARGS__); } while(0)
int gDebugEnabled = 1;

/* Refer following tutorial and API documentation to know how to create a user token
 * https://mesibo.com/documentation/tutorials/first-app/ 
 */
#define APP_TOKEN "<token>"
#define APP_ID "com.mesibo.cpp"

int keypress() {
	return getchar();      
}

class SampleListener: public MesiboListener  {
	Mesibo *m_api;
	public:
	void set_api(Mesibo *api) {
		m_api = api;
	}

	void logMessage(MesiboMessage *msg, const char *func) {
		MesiboDateTime *mt = msg->getTimestamp();
		if(msg->isRichMessage())
			ERRORLOG("===> %s: title %s message %s status %d (date: %s) (time: %s)\n", func, msg->getTitle(), msg->getMessage(), msg->getStatus(), mt->getDate(1), mt->getTime(1));
		else {
			MesiboData data;
			msg->getData(&data);
			ERRORLOG("===> %s: %.*s status: %d (date: %s) (time: %s)\n", func, data.len, data.data, msg->getStatus(), mt->getDate(1), mt->getTime(1));
		}
	}

	int Mesibo_onMessage(MesiboMessage *msg) {
		logMessage(msg, "Mesibo_onMessage");
		return 1;
	}
	
	int Mesibo_onMessageUpdate(MesiboMessage *msg) {
		logMessage(msg, "Mesibo_onMessageUpdate");
		return 1;
	}
	
	int Mesibo_onMessageStatus(MesiboMessage *msg) {
		logMessage(msg, "Mesibo_onMessageStatus");
		
		MesiboDateTime *dt = msg->getDeliveryTimestamp(NULL);
		MesiboDateTime *rt = msg->getReadTimestamp(NULL);
		if(dt) ERRORLOG("===> Delivery (date: %s) (time: %s)\n", dt->getDate(1), dt->getTime(1));
		if(rt) ERRORLOG("===> Read (date: %s) (time: %s)\n", rt->getDate(1), rt->getTime(1));
		return 1;
	}
	
	int Mesibo_onConnectionStatus(int status) {
		ERRORLOG("===> Mesibo_onConnectionStatus: %u\n", status);
		return 0;
	}

	int Mesibo_onPresence(MesiboPresence *p) {
		if(p->isTyping())
			ERRORLOG("===> Mesibo_onPresence: is typing\n");
		else if(p->isTypingCleared())
			ERRORLOG("===> Mesibo_onPresence: not typing\n");
		else if(p->isOnline())
			ERRORLOG("===> Mesibo_onPresence: has come online\n");
		else if(p->isOffline())
			ERRORLOG("===> Mesibo_onPresence: is offline\n");
		else if(p->hasJoined())
			ERRORLOG("===> Mesibo_onPresence: has Joined\n");
		else if(p->hasLeft())
			ERRORLOG("===> Mesibo_onPresence: has Left\n");
		else
			ERRORLOG("===> Mesibo_onPresence: %x\n", p->presence);

		return 0;
	}

	void Mesibo_onEndToEndEncryption(const char *address, int status) {
	}
};

int main() {

	// get mesibo API instance (singleton)
	Mesibo *m_api = MesiboInstance(0);

	// setup credentials
	m_api->setAppName(APP_ID);
	m_api->setAccessToken(APP_TOKEN);
	
	// create a listener instance to receive incoming messages
	SampleListener *n = new SampleListener();
	n->set_api(m_api); // Optional, in case listener need to access APIs
	m_api->addListener(n);

	// setup database to store incoming messages
	if(0 != m_api->setDatabase("mesibo.db", 0)) {
		fprintf(stderr, "Database failed\n");
		return -1;
	}

	// start mesibo
	m_api->start();


	fprintf(stderr, "Press Enter to send a message\n");
	keypress();

	MesiboMessage *m = m_api->newMessage("919740305019");
	m->setMessage("Hello from mesibo CPP library");
	
	fprintf(stderr, "sending\n");
	m->send();
	m->free();


	fprintf(stderr, "Waiting for messages. Press Enter to send a message\n");
	keypress();
	return 0;

}
