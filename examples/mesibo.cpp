/* 
 * mesibo sample code for sending and receiving real-time messages in C++
 * 
 * Refer to https://mesibo.com/documentation/install/linux/ for downloading mesibo C++ library
 *
 * Once you download and install mesibo C++ library, you can compile this sample code by issuing 
 * the following command
 *
 * $ g++ mesibo.com -lmesibo -o mesibo_sample
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

	int Mesibo_onMessage(MesiboMessageParams *p, const char *data, uint32_t len) {
		int printlen = len;
		if(printlen > 64)
			printlen = 64;

		ERRORLOG("===> Mesibo_onMessage: uid %u status %d type %u id %" PRIx64 " refid %lu groupid %u, when %" PRIu64 " from %s, flag: %x len %d: %.*s\n", p->uid, p->status, p->type, p->mid, p->refid, p->groupid, p->ts, p->peer, p->flags, len, printlen, data);

		return 1;
	}
	
	int Mesibo_onRichMessage(MesiboMessageParams *p, MesiboRichMessage *m) {
		ERRORLOG("file url %s size %u lat %f long %f\n", m->file.url, m->file.size, m->location.lat_d, m->location.lon_d); 
		return 0;
	}

	int Mesibo_onMessageStatus(MesiboMessageParams *p)  {
		ERRORLOG("===> Mesibo_onMessageStatus status %u id %u when %u ms (%u %u) from: %s\n", p->status, p->mid, m_api->getTimestamp()-p->ts, m_api->getTimestamp(), p->ts, p->peer?p->peer:"");
		return 0;
	}

	int Mesibo_onConnectionStatus(int status) {
		ERRORLOG("===> Mesibo_onConnectionStatus: %u\n", status);
		return 0;
	}

	int Mesibo_onActivity(MesiboMessageParams *p, uint32_t activity, uint32_t value) {
		ERRORLOG("===> Mesibo_onActivity: %x\n", activity);
		return 0;
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

	MesiboMessageParams params;
	memset(&params, 0, sizeof(MesiboMessageParams));
	params.peer = "12345678";
	params.expiry = 3600;
	params.flags = MESIBO_FLAG_DEFAULT;

	const char *message = "Hello from mesibo CPP library";

	int rv = m_api->sendMessage(&params, m_api->random(), message, strlen(message));
	fprintf(stderr, "sent result %d\n", rv);

	fprintf(stderr, "Waiting for messages. Press Enter to send a message\n");
	keypress();
	return 0;

}
