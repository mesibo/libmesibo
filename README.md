## mesibo C++ API for Linux, Mac and Raspberry Pi

mesibo offers high performance end-to-end encrypted chat, group chat, call and conferencing APIs. It's modular, lightweight, and easy to integrate.

mesibo supports almost all popular platforms and languages for you to quickly build your applications. Whether you are developing mobile apps (Android, iOS, Java, Objective-C, C++), web apps (Javascript), integrating with backend (Linux, macOS, Windows, Python, C++), or creating cool devices using Raspberry Pi, mesibo has APIs for you.

mesibo's high-performance C++ library enables you to interface your chat clients with various scientific computing and machine learning systems on your backend like TensorFlow, Matlab, Octave, NumPy, etc to create a powerful chat experience.

- **Website:** https://mesibo.com
- **Documentation:** https://mesibo.com/documentation/
- **Tutorials:** https://mesibo.com/documentation/tutorials/get-started

### Supported Platforms
Mesibo C++ API supports the following platforms.

- CentOS / RedHat 7.x or above
- Ubuntu / Debian
- Mac OS (x86 and M1 chip)
- Raspberry Pi 3 and 4

## Example
Below are some examples of typical usage. 

### Sending and Receiving Messages
```cpp

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
```

## Tutorial
[Write your First mesibo Enabled Application](https://mesibo.com/documentation/tutorials/get-started/)

## Support
If you are facing issues, contact us at [https://mesibo.com/support/](https://mesibo.com/support/)
