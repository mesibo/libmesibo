#pragma once
#include <inttyes.h>

typedef struct _tMessageParams {
	uint64_t id;
	uint64_t refid;
	uint32_t uid;
	uint32_t groupid;
	int32_t  expiry; //expiry could be negative
	uint32_t flag;
	uint64_t when;
	uint64_t retaints;
	uint32_t uflags;
	uint16_t status;
	uint16_t channel;
	uint16_t type;
	uint8_t  origin;
	uint8_t  saved;
	//
	char *thumbnail;
	int 	tnlen;
	char *filepath;

	void *read_session;
	//uint8_t forced;
} tMessageParams;

typedef struct _tMessageBundle {
	const char *data; //original data
	uint32_t    datalen; 

	//TLV ecoded data 

	uint32_t    msglen;
	const char *message;
	const char *title;

	uint32_t filesize;
	uint16_t filetype;
	const char *fileurl;
	const char *filepath;

	const char *launchurl;
	
	const char *thumbnail_send;
	uint16_t 	tnslen;
	
	const char *thumbnail;
	uint16_t 	tnlen;

	int	has_location;
	uint32_t lat, lon;
	double lat_d, lon_d;
	uint64_t location;

	uint64_t rrid; //read receipt id
	int activity, has_activity;
	
	//TBD, more generic TLV structure

} tMessageBundle;

#define MESIBO_USERFLAG_DBMASK          0xFFFFFF
#define MESIBO_USERFLAG_ARCHIVE         1
#define MESIBO_USERFLAG_MUTE            2
#define MESIBO_USERFLAG_SELFPROFILE     0x10
#define MESIBO_USERFLAG_HIDDEN          0x20
#define MESIBO_USERFLAG_TEMPORARY       0x40
#define MESIBO_USERFLAG_DELETED         0x80

// Local blocked - messages
#define MESIBO_USERFLAG_LMBLOCKED           0x10000
// Local blocked - group messages
#define MESIBO_USERFLAG_LGBLOCKED           0x20000

//Local all blocked
#define MESIBO_USERFLAG_LABLOCKED           (MESIBO_USERFLAG_LMBLOCKED|MESIBO_USERFLAG_LGBLOCKED)
// Remote Messages blocked 
#define MESIBO_USERFLAG_RMBLOCKED           0x40000
// There is no such thing as remote group blocking as sending messages to group 
// never checks for blocking
//#define MESIBO_USERFLAG_RGBLOCKED           0
#define MESIBO_USERFLAG_BLOCKED           (MESIBO_USERFLAG_LMBLOCKED|MESIBO_USERFLAG_LGBLOCKED|MESIBO_USERFLAG_RMBLOCKED)

#define MESIBO_USERFLAG_MARKED              0x1000000
#define MESIBO_USERFLAG_PROFILEREQUESTED    0x2000000

typedef struct _tContact {
	uint32_t groupid;
	uint64_t ts;
	uint64_t lastseen;
	uint32_t flag;

	const char *name;
	const char *address;
	const char *photo;
	const char *other;

	const char *status;
	int  statuslen;

	const char *tn;
	int  tnlen;
} tContact;

class INotify {
	public:
		//virtual int on_message(uint8_t channel, uint64_t id, uint32_t groupid, uint64_t when, const char *from, const char *data, int len, int flag) = 0;
		virtual int on_message(tMessageParams *p, const char *from, const char *data, uint32_t len) = 0;
		virtual int on_messagebundle(tMessageParams *p, const char *from, tMessageBundle *m) = 0;
		virtual int on_messagestatus(tMessageParams *p, const char *from, int last) = 0;
		virtual int on_system_message(tMessageParams *p, const char *from, const char *data, uint32_t len) {return 0;}
		virtual int on_status(int status, uint32_t substatus, uint8_t channel, const char *from) = 0;
		//TBD virtual int is_forground() = 0;
		virtual int on_activity(tMessageParams *p, const char *from, uint32_t activity) = 0;
		//virtual int on_location(tMessageParams *p, tMesiboAddress *from, float lat, float lon, const char *title, const char *message, const char *thumbnail, int tnlen) = 0;
		//virtual int on_file(tMessageParams *p, tMesiboAddress *from, uint32_t fileflag, int filesize, const char *url, const char *thumbnail, int tnlen, const char *title, const char *message, const char *launchurl, const char *localpath) = 0;
		
		//peerid is useful for group calling (anyone can call group - it will call all group members or if call in progress. can join)
		virtual int on_call(uint32_t peerid, uint32_t callid, int status, const char *data, int datalen, uint64_t flags) = 0;
		
		virtual int on_contact(const tContact *c) = 0;
		
		virtual int on_key(const char *key, const char *value) = 0;
		
		virtual int on_server(int type, const char *server, const char *username, const char *password) = 0;
};

class IMesiboDB {
	public:
		virtual int execute_sql(const char *sql) = 0;
		virtual int execute_sqls(const char **sql) = 0;
		virtual int read_pending(INotify *listener);
};


class IMesibo {
	public:
		virtual ~IMesibo() {}

		virtual int start() = 0;
		virtual int stop() = 0;
	
		virtual void reconnect_now(int type) = 0;
		
		virtual void set_debug(int loglevl, uint32_t debugflags) = 0;
		virtual void set_loginflags(uint32_t flags) = 0;

		virtual void set_uniqid(uint32_t uniqid) = 0;
		virtual int set_device(uint8_t type, const char *deviceid, const char *package, const char *version) = 0;
		virtual void set_cpu(int family, uint64_t features, int count) = 0;
		virtual int set_credentials(const char *cookie) = 0;
		virtual int set_notify(uint8_t channel, INotify *i, int setdefault) = 0;
		virtual void set_appstore(int storeid, const char *store) = 0;
		virtual void set_pushtoken(const char *token) = 0;
		virtual int set_bufferlen(int len, int empty) = 0;
		virtual int set_network(uint8_t type, uint32_t ipaddr, uint32_t gwaddr, uint16_t lastport) = 0;
		
		//virtual int send_readreceipt(uint64_t id) = 0;
		//virtual int send_activity(uint8_t channel, const char *to, uint32_t type) = 0;
		
		virtual int message(tMessageParams *p, const char *to, const char *data, int len) = 0;
		virtual int message_send() = 0;
		virtual int cancel(int type, uint32_t id) = 0;
		virtual uint32_t random32() = 0;
		virtual uint64_t timestamp() = 0;
	
		//only for debug build
		virtual void set_secure(int secure) = 0;
		virtual int set_server(const char *server) = 0;

		//only for db version
		virtual int set_database(const char *path) = 0;
		virtual int reset_database(uint32_t tables) = 0;

		//This is only required for non-db application - but that even user can do it
		//client can use it during pause/resume
		virtual void *set_readsession(void *data, uint32_t flag, const char *from, uint32_t groupid, const char *searchquery) = 0;
		virtual int read(void *rs, int count) = 0;
		virtual int delete_messages(uint64_t *ids, int count, int del_type) = 0;
		virtual int delete_messages(uint64_t id, const char *from, uint32_t groupid, uint64_t ts) = 0;
		virtual int delete_policy(int max_interval, int delete_type) = 0;

		virtual int set_key(const char *key, const char *value) = 0;
		virtual int delete_key(const char *key) = 0;
		virtual int read_key(const char *key, char **value) = 0;
		virtual void free_keyvaluebuffer(char *value) = 0;
		virtual int count_key(const char *key, const char *value) = 0;

		virtual int set_contact(const tContact *c) = 0;
		virtual int read_contact(const char *address, uint32_t groupid, const char *orderby, int count) = 0;
		virtual int delete_contact(const char *address, uint32_t groupid) = 0;
		
		virtual int get_loginstatus() = 0;
		virtual int get_mapimage_url(float lat, float lon, int width, int zoom, char *url) = 0;
		virtual void phone_fqn(const char *phone, int country_code, int mcc, char *fqn) = 0;
		virtual void phone_strip(const char *phone, int strip_prefix, char *fqn) = 0;

		virtual int send_readreceipt(int type, const char *to, uint32_t groupid, uint64_t readid) = 0;

		virtual int send_activity(tMessageParams *p, const char *to, uint32_t activity, uint32_t interval) = 0;
		//virtual int send_tv(tMessageParams *p, const char *to, int type, uint64_t value, const char *str) = 0;

		virtual int send_messagebundle(tMessageParams *p, const char *to, tMessageBundle *m) = 0; 
		//virtual int send_file(tMessageParams *p, const char *to, int filetype, int filesize, const char *url, const char *pathname, const char *thumbnail_send, int tnslen, const char *thumbnail_view, int tnvlen, const char *title, const char *message, const char *launchurl) = 0; 
		//virtual int send_location(tMessageParams *p, const char *to, float lat, float lon, const char *title, const char *message) = 0;
		virtual int forward_message(tMessageParams *p, const char *to, uint64_t id) = 0;

		virtual int update_message(uint64_t id, int flag, int status, const char *thumbnail, int tnlen, const char *filepath) = 0;
		virtual int send_pending(uint32_t id, int flag) = 0;
		virtual int resend_message(uint32_t id) = 0;
		
	
		virtual int call(const char *destination, int type) = 0;
		virtual int answer(int video) = 0;
		virtual int hangup(uint32_t callid, int status) = 0;
		virtual int mute(int audio, int video, int enable) = 0;
		virtual int hold(int enable) = 0;
		virtual int set_pstn(const char *server, int port) = 0;

		virtual void set_callprocessing(int call_reject_status, int current_call_status) = 0;

		virtual void set_answer_mode(int lateconnect) = 0;

		virtual int mute_status() = 0;

		// 0 audio, 1 video
		virtual void set_callfactory(int type, void *factory) = 0;
		virtual int callstatus_from_proxyrtc(int status, const char *sdp, int sdplen) = 0;
		
		virtual uint32_t get_uid() = 0;

};

class CMesiboNotify: public INotify  {
	IMesibo *m_api;
	public:
	void set_api(IMesibo *api) {
		m_api = api;
	}

	IMesibo *get_api() { return m_api; }

	virtual int on_messagebundle(tMessageParams *p, const char *from, tMessageBundle *m) { return 0; }

	virtual int on_error(uint8_t error) { return 0; }

	virtual int on_activity(tMessageParams *p, const char *from, uint32_t event) { return 0; }

	virtual int on_location(tMessageParams *p, const char *from, float lat, float lon, const char *title, const char *message, const char *thumbnail, int tnlen) { return 0; }

	virtual int on_file(tMessageParams *p, const char *from, uint32_t fileflag, int filesize, const char *url, const char *thumbnail, int tnlen, const char *title, const char *message, const char *launchurl, const char *localpath) { return 0; }

	virtual int on_call(uint32_t peerid, uint32_t callid, int status, const char *data, int datalen, uint64_t flags) { return 0; }

	virtual int on_key(const char *key, const char *value) { return 0; }

	virtual int on_contact(const tContact *c) { return 0; }
		
	virtual int on_rtc(int type, uint32_t flags, uint32_t peerid, const char *sdp, int len) { return 0; }
		
	virtual int on_server(int type, const char *server, const char *username, const char *password) { return 0; }
};

extern "C" IMesibo *query_mesibo(const char *tempPath);
extern "C" IMesibo *query_mesibo_base(const char *tempPath);
