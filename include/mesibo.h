#pragma once

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#define __STDC_LIMIT_MACROS
#endif

#include <stdio.h>
#include <inttypes.h>

#define MESIBO_FLAG_DELIVERYRECEIPT     0x1
#define MESIBO_FLAG_READRECEIPT         0x2
#define MESIBO_FLAG_TRANSIENT           0x4
#define MESIBO_FLAG_PRESENCE           0x8
#define MESIBO_FLAG_BROADCAST           0x20

//#define MESIBO_FLAG_QUEUE            0x40000
#define MESIBO_FLAG_NONBLOCKING         0x80000
#define MESIBO_FLAG_DONTSEND            0x200000
#define MESIBO_FLAG_LASTMESSAGE                 0x800000ULL
#define MESIBO_FLAG_EORS                 0x4000000ULL

#define MESIBO_FLAG_SAVECUSTOM                 (1ULL << 56)
#define MESIBO_FLAG_FILETRANSFERRED     (1ULL << 58)
#define MESIBO_FLAG_FILEFAILED          (1ULL << 59)


#define MESIBO_FLAG_DEFAULT             (MESIBO_FLAG_DELIVERYRECEIPT | MESIBO_FLAG_READRECEIPT)

#define MESIBO_FORMAT_DEFAULT           0
#define MESIBO_FORMAT_HEX               1
#define MESIBO_FORMAT_DECIMAL           2

#define MESIBO_STATUS_UNKNOWN            0
#define MESIBO_STATUS_ONLINE            1
#define MESIBO_STATUS_OFFLINE           2
#define MESIBO_STATUS_SIGNOUT           3
#define MESIBO_STATUS_AUTHFAIL          4
#define MESIBO_STATUS_STOPPED           5
#define MESIBO_STATUS_CONNECTING        6
#define MESIBO_STATUS_CONNECTFAILURE    7
#define MESIBO_STATUS_NONETWORK         8
#define MESIBO_STATUS_ONPREMISEERROR         9
#define MESIBO_STATUS_SUSPEND         10
#define MESIBO_STATUS_UPDATE         20
#define MESIBO_STATUS_MANDUPDATE        21
#define MESIBO_STATUS_SHUTDOWN          22
#define MESIBO_STATUS_ACTIVITY          -1

#define MESIBO_MSGSTATUS_OUTBOX         0
#define MESIBO_MSGSTATUS_SENT           1
#define MESIBO_MSGSTATUS_DELIVERED      2
#define MESIBO_MSGSTATUS_READ           3
#define MESIBO_MSGSTATUS_RECEIVEDNEW    0x12
#define MESIBO_MSGSTATUS_RECEIVEDREAD   0x13
#define MESIBO_MSGSTATUS_CALLMISSED     0x15
#define MESIBO_MSGSTATUS_CALLINCOMING   0x16
#define MESIBO_MSGSTATUS_CALLOUTGOING   0x17
#define MESIBO_MSGSTATUS_CUSTOM         0x20

// ONLY FOR UI USAGE
#define MESIBO_MSGSTATUS_TIMESTAMP      0x30

#define MESIBO_MSGSTATUS_FAIL           0x80
#define MESIBO_MSGSTATUS_USEROFFLINE    0x81
#define MESIBO_MSGSTATUS_INBOXFULL      0x82
#define MESIBO_MSGSTATUS_INVALIDDEST    0x83
#define MESIBO_MSGSTATUS_EXPIRED        0x84
#define MESIBO_MSGSTATUS_BLOCKED        0x88


#define MESIBO_RESULT_OK                0
#define MESIBO_RESULT_FAIL              0x80
#define MESIBO_RESULT_GENERROR          0x81
#define MESIBO_RESULT_NOSUCHERROR       0x83
#define MESIBO_RESULT_INBOXFULL         0x84
#define MESIBO_RESULT_BADREQ            0x85
#define MESIBO_RESULT_OVERCAPACITY      0x86
#define MESIBO_RESULT_RETRYLATER        0x87

#define MESIBO_RESULT_TIMEOUT           0xB0
#define MESIBO_RESULT_CONNECTFAIL       0xB1
#define MESIBO_RESULT_DISCONNECTED      0xB2
#define MESIBO_RESULT_REQINPROGRESS     0xB3
#define MESIBO_RESULT_BUFFERFULL        0xB4

#define MESIBO_RESULT_AUTHFAIL          0xC0
#define MESIBO_RESULT_DENIED            0xC1

#define MESIBO_ADDRESSSTRING_MAXLENGTH  63

#define MESIBO_READFLAG_READRECEIPT     1
#define MESIBO_READFLAG_SENDLAST        2
#define MESIBO_READFLAG_FIFO            4
#define MESIBO_READFLAG_SUMMARY         0x10
#define MESIBO_READFLAG_SENDEOR         0x20
#define MESIBO_READFLAG_WITHFILES       0x80


#define MESIBO_ORIGIN_REALTIME          0
#define MESIBO_ORIGIN_DBMESSAGE         1
#define MESIBO_ORIGIN_DBSUMMARY         2
#define MESIBO_ORIGIN_DBPENDING         3
#define MESIBO_ORIGIN_FILTER            4
#define MESIBO_ORIGIN_MESSAGESTATUS     5

#define MESIBO_ACTIVITY_NONE            0
#define MESIBO_ACTIVITY_ONLINE          1
#define MESIBO_ACTIVITY_ONLINERESP      2
#define MESIBO_ACTIVITY_TYPING          3
#define MESIBO_ACTIVITY_TYPINGCLEARED   4
#define MESIBO_ACTIVITY_JOINED          10
#define MESIBO_ACTIVITY_LEFT            11



// All status < 0x40 will keep call in progress - max status 0x7F (we can't go beyond that, as 0x80 will be treated as voice)
#define MESIBO_CALLSTATUS_NONE                  0x00
#define MESIBO_CALLSTATUS_INCOMING         0x01
#define MESIBO_CALLSTATUS_INPROGRESS            0x02
#define MESIBO_CALLSTATUS_RINGING               0x03
#define MESIBO_CALLSTATUS_ANSWER                0x05
#define MESIBO_CALLSTATUS_UPDATE                0x06
#define MESIBO_CALLSTATUS_DTMF                  0x07
#define MESIBO_CALLSTATUS_SDP                   0x08
#define MESIBO_CALLSTATUS_MUTE                  0x09
#define MESIBO_CALLSTATUS_UNMUTE                0x0A
#define MESIBO_CALLSTATUS_HOLD                  0x0B
#define MESIBO_CALLSTATUS_UNHOLD                0x0C

#define MESIBO_CALLSTATUS_PING                  0x21
#define MESIBO_CALLSTATUS_INFO                  0x23
#define MESIBO_CALLSTATUS_ECHO                  0x24
#define MESIBO_CALLSTATUS_REDIRECT              0x25

//Local Status used by client
#define MESIBO_CALLSTATUS_CHANNELUP             0x30
#define MESIBO_CALLSTATUS_CONNECTED             0x30
#define MESIBO_CALLSTATUS_QUALITY               0x31
#define MESIBO_CALLSTATUS_RECONNECTING          0x32

// Phone Specific ERRORs
#define MESIBO_CALLSTATUS_COMPLETE              0x40
#define MESIBO_CALLSTATUS_CANCEL                0x41
#define MESIBO_CALLSTATUS_NOANSWER              0x42
#define MESIBO_CALLSTATUS_BUSY                  0x43
#define MESIBO_CALLSTATUS_UNREACHABLE           0x44
#define MESIBO_CALLSTATUS_OFFLINE               0x45
#define MESIBO_CALLSTATUS_INVALIDDEST           0x46
#define MESIBO_CALLSTATUS_INVALIDSTATE          0x47
#define MESIBO_CALLSTATUS_NOCALLS               0x48
#define MESIBO_CALLSTATUS_NOVIDEOCALLS          0x49
#define MESIBO_CALLSTATUS_NOTALLOWED            0x4A

//TringMe specific errir
#define MESIBO_CALLSTATUS_AUTHFAIL              0x50
#define MESIBO_CALLSTATUS_NOCREDITS             0x51
#define MESIBO_CALLSTATUS_NONTRINGMEDEST        0x52
#define MESIBO_CALLSTATUS_INCOMPATIBLE          0x53
#define MESIBO_CALLSTATUS_BADCALLID             0x54

// Generic Errors
#define MESIBO_CALLSTATUS_ERROR                 0x60
#define MESIBO_CALLSTATUS_HWERROR               0x61
#define MESIBO_CALLSTATUS_NETWORKERROR          0x62
#define MESIBO_CALLSTATUS_NETWORKBLOCKED        0x63

#define MESIBO_CALLFLAG_AUDIO                   0x1
#define MESIBO_CALLFLAG_VIDEO                   0x2
#define MESIBO_CALLFLAG_STARTCALL               0x4
#define MESIBO_CALLFLAG_CALLWAITING               0x8
#define MESIBO_CALLFLAG_WIFI                    0x10
#define MESIBO_CALLFLAG_SLOWNETWORK             0x20
#define MESIBO_CALLFLAG_MISSED                  0x1000

#define MESIBO_DELETE_DEFAULT   -1
#define MESIBO_DELETE_LOCAL     0
#define MESIBO_DELETE_RECALL    1
#define MESIBO_DELETE_REMOVE    2

//Following CALL_STATUS_ are for internal use and for notifications
#define MESIBO_CALLSTATUS_DUREXCEED             19
#define MESIBO_CALLSTATUS_SRCRINGING            20
#define MESIBO_CALLSTATUS_SRCANSWERED           21
#define MESIBO_CALLSTATUS_USERINPUT             22

#define MESIBO_SERVERTYPE_STUN                  0
#define MESIBO_SERVERTYPE_TURN                  1

#define MESIBO_MUTESTATUS_AUDIO   1
#define MESIBO_MUTESTATUS_VIDEO   2
#define MESIBO_MUTESTATUS_HOLD    4

#define MESIBO_CONTACT_UPDATE           0
#define MESIBO_CONTACT_DELETE           1

//MUST be same as internal CONNECTION_DISCONNECTED, etc
#define MESIBO_CONNECTIVITY_DISCONNECTED 0xFF
#define MESIBO_CONNECTIVITY_UNKNOWN      -1
#define MESIBO_CONNECTIVITY_WIFI         0
#define MESIBO_CONNECTIVITY_2G           1
#define MESIBO_CONNECTIVITY_3G           2
#define MESIBO_CONNECTIVITY_4G           3

#define MESIBO_DBTABLE_MESSAGES          1
#define MESIBO_DBTABLE_PROFILES          2
#define MESIBO_DBTABLE_KEYS              4

#define MESIBO_DBTABLE_ALL (MESIBO_DBTABLE_MESSAGES|MESIBO_DBTABLE_PROFILES|MESIBO_DBTABLE_KEYS)

#define MESIBO_CONFIGTYPE_CALLFLAGS             0x100
#define MESIBO_CONFIGTYPE_CALLANSWERMODE        0x101
#define MESIBO_CONFIGTYPE_CALLREQTO             0x110
#define MESIBO_CONFIGTYPE_CALLANSTO             0x111
#define MESIBO_CONFIGTYPE_CALLCONNECTTO         0x112

#define MESIBO_VISIBILITY_NONE         0
#define MESIBO_VISIBILITY_PUBLIC       1
#define MESIBO_VISIBILITY_CONTACT      2
#define MESIBO_VISIBILITY_CUSTOM       4
#define MESIBO_VISIBILITY_LOCAL        8

#define MESIBO_SYNCTYPE_REALTIME               0
#define MESIBO_SYNCTYPE_LAZY                   1
#define MESIBO_SYNCTYPE_ONLINEONLY             2
#define MESIBO_SYNCTYPE_RECENTONLY             3

#define MESIBO_ONLINEMODE_LOGIN         1
#define MESIBO_ONLINEMODE_FOREGROUND    2
#define MESIBO_ONLINEMODE_MANUAL        3


#define MESIBO_MEMBERFLAG_SEND    1
#define MESIBO_MEMBERFLAG_RECV    2
#define MESIBO_MEMBERFLAG_PUBL    4
#define MESIBO_MEMBERFLAG_SUBS    8
#define MESIBO_MEMBERFLAG_LIST    0x10
#define MESIBO_MEMBERFLAG_RECORD  0x20
#define MEMBERFLAG_EXPIRYTS       0x100
#define MEMBERFLAG_DELETEWITHPIN  0x200
#define MEMBERFLAG_NOSELFDELETE   0x800

#define MESIBO_MEMBERFLAG_ADMIN   0x1000
    // prevents user from deleting itself
#define MESIBO_MEMBERFLAG_NOSELFDELETE    0x2000
#define MESIBO_MEMBERFLAG_SHAREDPIN      0x8000

#define MESIBO_MEMBERFLAG_DELETE  0x80000000
#define MESIBO_MEMBERFLAG_ALL    (MESIBO_MEMBERFLAG_SEND|MESIBO_MEMBERFLAG_RECV|MESIBO_MEMBERFLAG_PUBL|MESIBO_MEMBERFLAG_SUBS|MESIBO_MEMBERFLAG_LIST)

#define MESIBO_ADMINFLAG_MODIFY       1
#define MESIBO_ADMINFLAG_ADDUSER      0x10
#define MESIBO_ADMINFLAG_REMUSER      0x20
#define MESIBO_ADMINFLAG_ADDADMIN     0x40
#define MESIBO_ADMINFLAG_REMADMIN     0x80
#define MESIBO_ADMINFLAG_REMOWNER     0x100
#define MESIBO_ADMINFLAG_REMGROUP     0x200
#define MESIBO_ADMINFLAG_CALLCONTROL  0x400
#define MESIBO_ADMINFLAG_HANGUP       0x800
#define MESIBO_ADMINFLAG_OWNER        0x1000
#define MESIBO_ADMINFLAG_ADDPIN       0x2000
#define MESIBO_ADMINFLAG_REMOVEPIN    0x4000
#define MESIBO_ADMINFLAG_LISTPIN      0x8000


#define MESIBO_OWNERFLAG_ALL          0xFFFF
#define MESIBO_ADMINFLAG_ALL          (MESIBO_OWNERFLAG_ALL & ~MESIBO_ADMINFLAG_OWNER)

#define MESIBO_GROUPFLAG_SENDBYSELECTED      1
#define MESIBO_GROUPFLAG_SENDBYANYONE        2
#define MESIBO_GROUPFLAG_AUTOADDMEMBER       8
#define MESIBO_GROUPFLAG_RECVBYSELECTED      0x10
#define MESIBO_GROUPFLAG_RECVROUNDROBIN      0x20
#define MESIBO_GROUPFLAG_NOSTORAGE           0x40
#define MESIBO_GROUPFLAG_RECVLOOPBACK        0x80
#define MESIBO_GROUPFLAG_PUBBYSELECTED       0x100
#define MESIBO_GROUPFLAG_PUBBYANYONE         0x200
#define MESIBO_GROUPFLAG_SUBBYSELECTED       0x1000
#define MESIBO_GROUPFLAG_SUBBYANYONE         0x2000
#define MESIBO_GROUPFLAG_LISTBYSELECTED      0x10000
#define MESIBO_GROUPFLAG_LISTBYANYONE        0x20000
    //members can't delete themselves
#define MESIBO_GROUPFLAG_NOSELFDELETE        0x40000
    // these flags are not to be saved in database but sent by group_set request in profile_t
#define MESIBO_GROUPFLAG_DELETE              0x80000000

#define MESIBO_GROUPERROR_NOTMEMBER       1
#define MESIBO_GROUPERROR_PERMISSION      2
#define MESIBO_GROUPERROR_BADPIN          3
#define MESIBO_GROUPERROR_ACCESSDENIED    4
#define MESIBO_GROUPERROR_NOTSHAREDPIN    5
#define MESIBO_GROUPERROR_GENERAL         10

#define MESIBO_RESOLUTION_DEFAULT          0
#define MESIBO_RESOLUTION_QVGA             1
#define MESIBO_RESOLUTION_VGA              2
#define MESIBO_RESOLUTION_HD               3
#define MESIBO_RESOLUTION_FHD              4
#define MESIBO_RESOLUTION_4K               5
#define MESIBO_RESOLUTION_QQVGA            8
#define MESIBO_RESOLUTION_180P             9
#define MESIBO_RESOLUTION_NHD              10
#define MESIBO_RESOLUTION_MAX              10

#define MESIBO_GROUPCALLFLAG_VALID           1
#define MESIBO_GROUPCALLFLAG_AUDIO           2
#define MESIBO_GROUPCALLFLAG_VIDEO           4
#define MESIBO_GROUPCALLFLAG_DATA            8
#define MESIBO_GROUPCALLFLAG_SCREEN          0x100
#define MESIBO_GROUPCALLFLAG_SIMULCAST       0x200
#define MESIBO_GROUPCALLFLAG_SIMULCAST2      0x400
#define MESIBO_GROUPCALLFLAG_4_3             0x800
#define MESIBO_GROUPCALLFLAG_RECORD          0x1000
#define MESIBO_GROUPCALLFLAG_TALKING         0x8000
#define MESIBO_GROUPCALLFLAG_FIXEDBITRATE    0x10000
#define MESIBO_GROUPCALLFLAG_FIXEDRESOLUTION        0x20000
#define MESIBO_GROUPCALLFLAG_FIXEDFRAMERATE  0x40000
#define MESIBO_GROUPCALLFLAG_PREFER264       0x80000
#define MESIBO_GROUPCALLFLAG_DEFAULT          (MESIBO_GROUPCALLFLAG_AUDIO|MESIBO_GROUPCALLFLAG_VIDEO|MESIBO_GROUPCALLFLAG_VIDEO|MESIBO_GROUPCALLFLAG_TALKING)

#define MESIBO_GROUP_SUBSCRIBERS                 2
#define MESIBO_GROUP_KNOWNSUBSCRIBERS            3
#define MESIBO_GROUP_PROVSUBSCRIBERS             4
#define MESIBO_GROUP_KNOWNPROVSUBSCRIBERS        5
#define MESIBO_GROUP_SUBSCRIBERSALL              6
#define MESIBO_GROUP_KNOWNSUBSCRIBERSALL         7
#define MESIBO_GROUP_CONTACTS                    8
#define MESIBO_GROUP_CONTACTSUBSCRIBERS          9
#define MESIBO_GROUP_SUBSCRIBED                  10
#define MESIBO_GROUP_PROVSUBSCRIBED              11

typedef struct _MesiboData {
	char *data; 
	uint32_t    len; 
} MesiboData;

typedef struct _MesiboMessageParams {
	uint64_t mid;
	uint64_t refid;
	uint64_t flags;
	uint64_t ts;
	int32_t  expiry; 
	uint32_t uid;
	uint32_t groupid;
	uint16_t status;
	uint16_t type;
	uint8_t  origin;
	uint8_t  status_flags;
	const char *peer;
} MesiboMessageParams;

typedef struct _MesiboRichMessage {
	
	MesiboData data;

	MesiboData message;

	const char *title;
	const char *actionurl;

	struct {
		uint8_t valid;
		uint32_t size;
		uint32_t type;
		const char *url;
		const char *path;
		MesiboData thumbnail;
		MesiboData thumbnail_s;
	} file;

	struct {
		uint8_t valid;
		uint32_t lat, lon;
		double lat_d, lon_d;
		uint64_t location;
	} location;

} MesiboRichMessage;

class MesiboListener {
	public:
		virtual int Mesibo_onMessage(MesiboMessageParams *p, const char *data, uint32_t len) = 0;
		virtual int Mesibo_onRichMessage(MesiboMessageParams *p, MesiboRichMessage *m) = 0;
		virtual int Mesibo_onMessageStatus(MesiboMessageParams *p) = 0;
		virtual int Mesibo_onActivity(MesiboMessageParams *p, uint32_t activity, uint32_t value) = 0;
		
		virtual int Mesibo_onConnectionStatus(int status) = 0;
};

class MesiboReadSession {
	public:
		virtual ~MesiboReadSession() {}
		virtual int read(int count) = 0;
		virtual int start() = 0;
		virtual void stop() = 0;
		virtual int sync(int count)  = 0;
		virtual void enableReadReceipt(int enable)  = 0;
		virtual void enableSummary(int enable)  = 0;
		virtual void enableFifo(int enable)  = 0;
		virtual void enableFiles(int enable)  = 0;
		virtual void enableMessages(int enable)  = 0;
		virtual void enableMissedCalls(int enable)  = 0;
		virtual void enableIncomingCalls(int enable)  = 0;
		virtual void enableOutgoingCalls(int enable)  = 0;
		virtual void enableCalls(int enable)  = 0;
};

#define MESIBO_INTERFACE_VERSION	1
class Mesibo {
	public:
		virtual ~Mesibo() {}
		virtual int getConnectionStatus() = 0;
		virtual int setPath(const char *path) = 0;

		virtual int setDatabase(const char *dbNameWithPath, int resetTables) = 0;
		virtual int resetDatabase(int tables) = 0;

		virtual void setSecureConnection(int enabled) = 0;
		virtual int setAccessToken(const char *token) = 0;
		virtual void setOnlineStatusMode(int mode) = 0;
		virtual void setUploadUrl(const char *url, const char *authToken) = 0;
		virtual const char *getUploadUrl() = 0;
		virtual const char *getUploadAuthToken() = 0;
		virtual int addListener(MesiboListener *listener) = 0;
		virtual uint64_t getTimestamp() = 0;
		virtual int sendToWebhook(MesiboMessageParams *params, uint64_t mid, const char *msg, uint32_t len) = 0;
		virtual int saveCustomMessage(MesiboMessageParams *params, uint64_t mid, const char *msg, uint32_t len) = 0;
		virtual int addCustomMessage(MesiboMessageParams *params, uint64_t mid, const char *msg, uint32_t len) = 0;
		virtual void sendMessages() = 0;
		virtual int resend(uint64_t id) = 0;
		virtual int forwardMessage(MesiboMessageParams *params, uint64_t mid, uint64_t forwardid) = 0;
		virtual int sendMessage(MesiboMessageParams *params, uint64_t mid, const char *msg, uint32_t len) = 0;
		//virtual int sendFile(MesiboMessageParams *params, uint32_t msgid, FileInfo file) = 0;
		//virtual int sendFileURL(MesiboMessageParams *params, uint64_t id, const char *url, const char *thumbail, const char *title, const char *message, const char *launchurl) = 0;
		virtual int sendActivity(MesiboMessageParams *params, uint32_t mid, uint32_t activity, uint32_t value, int interval) = 0;
		virtual int sendActivity(MesiboMessageParams *params, uint32_t mid, int activity, int interval) = 0;
		virtual int setBufferLen(int len, int empty) = 0;
		virtual int deleteMessages(uint64_t *mids, uint32_t count, int type) = 0;
		virtual int deleteMessage(uint64_t mid, int type) = 0;
		virtual int deleteMessage(uint64_t mid) = 0;
		virtual int deleteMessages(const char *from, uint32_t groupid, uint32_t ts) = 0;
		//virtual int createGroup(MesiboGroupProfile.GroupSettings gp, GroupListener listener) = 0;
		//virtual int createGroup(const char *name, uint32_t flags, GroupListener listener) = 0;
		virtual int cancel(int type, uint64_t mid) = 0;

		virtual MesiboReadSession *createReadSession(const char *from, uint32_t groupid, const char *query, MesiboListener *listener) = 0;

		virtual int start() = 0;
		virtual int stop() = 0;
		virtual int reconnect() = 0;
		virtual int wait() = 0;
		virtual uint32_t getUid() = 0;
		virtual const char *getAddress() = 0;
		virtual void setAppName(const char *name) = 0;
		virtual uint32_t random() = 0;
		virtual int setKey(const char *key, const char *value) = 0;
		virtual const char *readKey(const char *key) = 0;
		virtual int deleteKey(const char *key) = 0;
		virtual const char *getBasePath() = 0;
		virtual const char *getFilePath(int type) = 0;
		virtual const char *version() = 0;
		virtual int setConfig(uint32_t type, uint32_t value) = 0;
		virtual int setConfig(uint32_t type, const char *value) = 0;
};

extern "C" Mesibo *MesiboInstance(uint32_t bufsize);
extern "C" Mesibo *MesiboPythonInstance(uint32_t bufsize, const char *version);
extern "C" int MesiboInterfaceVersion();
