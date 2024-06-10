/************************************************************************
* By accessing and utilizing this work, you hereby acknowledge that you *
* have thoroughly reviewed, comprehended, and commit to adhering to the *
* terms and conditions stipulated on the mesibo website, thereby        *
* entering into a legally binding agreement.                            *
*                                                                       *
* mesibo website: https://mesibo.com                                    *
*                                                                       *
* Copyright ©2023 Mesibo. All rights reserved.                          *
*************************************************************************/
#pragma once

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#define __STDC_LIMIT_MACROS
#endif

#include <stdio.h>
#include <inttypes.h>

#define MESIBO_INTERFACE_VERSION	3

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
#define MESIBO_MSGSTATUS_DELETED        0x21
#define MESIBO_MSGSTATUS_WIPED         	0x22
#define MESIBO_MSGSTATUS_E2E         	0x23

// ONLY FOR UI USAGE
#define MESIBO_MSGSTATUS_TIMESTAMP      0x30

#define MESIBO_MSGSTATUS_FAIL           0x80
#define MESIBO_MSGSTATUS_USEROFFLINE    0x81
#define MESIBO_MSGSTATUS_INBOXFULL      0x82
#define MESIBO_MSGSTATUS_INVALIDDEST    0x83
#define MESIBO_MSGSTATUS_EXPIRED        0x84
#define MESIBO_MSGSTATUS_BLOCKED        0x88
#define MESIBO_MSGSTATUS_GROUPPAUSED    0x90
#define MESIBO_MSGSTATUS_NOTMEMBER      0x91


#define MESIBO_RESULT_OK                0
#define MESIBO_RESULT_FAIL              0x80

#define MESIBO_ADDRESSSTRING_MAXLENGTH  63

#define MESIBO_READFLAG_READRECEIPT     1
#define MESIBO_READFLAG_SENDLAST        2
#define MESIBO_READFLAG_FIFO            4
#define MESIBO_READFLAG_SUMMARY         0x10
#define MESIBO_READFLAG_SENDEOR         0x20
#define MESIBO_READFLAG_WITHFILES       0x80

#define MESIBO_ACTIVITY_NONE            0
#define MESIBO_ACTIVITY_ONLINE          1
#define MESIBO_ACTIVITY_ONLINERESP      2
#define MESIBO_ACTIVITY_TYPING          3
#define MESIBO_ACTIVITY_TYPINGCLEARED   4
#define MESIBO_ACTIVITY_JOINED          10
#define MESIBO_ACTIVITY_LEFT            11

#define MESIBO_RETRACT_MODIFY        1                                    
#define MESIBO_RETRACT_WIPE          2                                    
#define MESIBO_RETRACT_DELETE        4                                    
#define MESIBO_RETRACT_DELUNREAD     0x10                                 
#define MESIBO_RETRACT_DELREAD       0x20                                 
#define MESIBO_RETRACT_DELMEDIA      0x40                                 
#define MESIBO_RETRACT_DELTHREAD     0x80                                 
#define MESIBO_RETRACT_DELALL        0x100                                
#define MESIBO_RETRACT_DELCONTACT    0x1000                               

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
#define MESIBO_CALLSTATUS_BLOCKED            	0x4B
#define MESIBO_CALLSTATUS_DURATIONEXCEEDED            	0x4C

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

#define MESIBO_DATATYPE_MESSAGE	0
#define MESIBO_DATATYPE_BINARY	1

typedef struct _MesiboData {
	char *data; 
	uint32_t    len; 
	uint8_t type;
} MesiboData;

typedef struct _MesiboFle {
	uint8_t    type; 
	uint8_t    subtype; 
	uint32_t   size; 
	const char *name; 
	const char *path; 
	const char *url; 
	const char *mimeType; 
	
	MesiboData thumbnail;
} MesiboFile;

class MesiboDateTime {
	public:
	uint64_t ts;
	uint16_t year;
	uint8_t  wday;
	uint8_t  month;
	uint8_t  day;
	uint8_t  hour;
	uint8_t  min;
	uint8_t  sec;

	public:
		virtual ~MesiboDateTime() {}

		virtual int isValid() = 0;
		virtual int setTimestamp(uint64_t ts) = 0;
		virtual const char *getMonth() = 0;
		virtual char *getDate(int monthFirst) = 0;
		virtual char *getTime(int seconds) = 0;
};

class MesiboMessageProperties {
	public:
	uint64_t mid;
	uint32_t uid;
	uint32_t groupid;
	const char *peer;

	public:
		virtual ~MesiboMessageProperties() {}

		virtual void setType(int type) = 0;
		virtual int getType() = 0;
		virtual void setExpiry(int expiry) = 0;
		virtual int getExpiry() = 0;
		virtual void setStatus(int status) = 0;
		virtual int getStatus() = 0;
		// some of the function present in Android/iOS/Javascript are yet to be implented in C++ libraary
		//virtual int getCurrentStatus() = 0;
		//MesiboProfile getCurrentStatusSender() = 0;
		//virtual void setAge(int age) = 0;
		//virtual void setAgeAfterDelivered(int age) = 0;
		//virtual void setAgeAfterRead(int age) = 0;
		//virtual	uint32_t getAge() = 0;
		//virtual void setThreadId(uint32_t tid) = 0;
		//virtual	uint32_t getThreadId() = 0;
		//virtual void setSensitivity(int val) = 0;
		//virtual	long getSensitivity() = 0;
		virtual void setInReplyTo(uint64_t messageid) = 0;
		virtual	uint64_t getInReplyTo() = 0;
		virtual int isReply() = 0;
		virtual int isIncoming() = 0;
		virtual int isSent() = 0;
		virtual int isDelivered() = 0;
		virtual int isReadByPeer() = 0;
		virtual int isReadByUs() = 0;
		virtual int isUnread() = 0;
		virtual void markDeleted(int enable) = 0;
		virtual void markWiped(int enable) = 0;
		virtual int isDeleted() = 0;
		virtual int isWiped() = 0;
		virtual int isModified() = 0;
		virtual int isModifiedByPeer() = 0;
		virtual int isUpdated() = 0;
		virtual int isDynamic() = 0;
		virtual int isFileTransferFailed() = 0;
		virtual int isForwarded() = 0;
		virtual int isEndToEndEncrypted() = 0;
		virtual int isEndToEndEncryptionStatus() = 0;
		virtual int isPresence() = 0;
		virtual int isRichMessage() = 0;
		virtual int isPlainMessage() = 0;
		virtual int isSavedMessage() = 0;
		virtual int isCustom() = 0;
		virtual int isDate() = 0;
		virtual int isHeader() = 0;
		virtual int isInvisible() = 0;
		virtual int isMissedCall() = 0;
		virtual int isIncomingCall() = 0;
		virtual int isOutgoingCall() = 0;
		virtual int isCall() = 0;
		virtual int isVideoCall() = 0;
		virtual int isVoiceCall() = 0;
		virtual int isMessage() = 0;
		virtual int isPstnCall() = 0;
		virtual int getCallDuration() = 0;
		virtual int isOutgoing() = 0;
		virtual int isInOutbox() = 0;
		virtual int isLastMessage() = 0;
		virtual int isDbMessage() = 0;
		virtual int isDbSummaryMessage() = 0;
		virtual int isChatListMessage() = 0;
		virtual int isRealtimeMessage() = 0;
		virtual int isPendingMessage() = 0;
		virtual int isGroupMessage() = 0;
		virtual int isFailed() = 0;
		virtual int compare(const char * peer, uint32_t groupid) = 0;
		virtual int compare(MesiboMessageProperties *p) = 0;
		virtual void setPeer(const char * peer) = 0;
		virtual void setGroup(uint32_t groupid) = 0;
		//virtual int isMessageStatusInProgress() = 0;
		virtual void enableFlag(uint64_t f, int enable) = 0;
		virtual void enableTransient(int enable) = 0;
		virtual void enablePresence(int enable) = 0;
		virtual void enableReadReceipt(int enable) = 0;
		virtual void enableDeliveryReceipt(int enable) = 0;
		virtual void enableCustom(int enable) = 0;
		virtual void enableModify(int enable) = 0;
		virtual void enableBroadcast(int enable) = 0;
		
		virtual MesiboDateTime *getTimestamp() = 0;
		virtual MesiboDateTime *getDeliveryTimestamp(const char *peer) = 0;
		virtual MesiboDateTime *getReadTimestamp(const char *peer) = 0;
};

class MesiboMessage : public MesiboMessageProperties {
	public:
		virtual ~MesiboMessage() {}
		
		virtual void setMessage(const char *message) = 0;
		virtual void setTitle(const char *title) = 0;
		virtual void setSubtitle(const char *subtitle) = 0;
		virtual void setData(MesiboData *data) = 0;
		virtual void setContent(const char *fileOrUrl) = 0;
		virtual void setContentType(int type) = 0;
		virtual void setThumbnail(const char *tn, uint16_t len) = 0;

		virtual void setLatitude(double latitude) = 0;
		virtual void setLongitude(double longitude) = 0;
		
		virtual const char *getMessage() = 0;
		virtual const char *getTitle() = 0;
		virtual const char *getSubtitle() = 0;
		virtual MesiboData *getData() = 0;

		virtual const MesiboFile *getContent() = 0;

		virtual double getLatitude() = 0;
		virtual double getLongitude() = 0;


		virtual int send(void) = 0;
		virtual int resend() = 0;
		virtual MesiboMessage *forward(const char *peer) = 0;
		virtual MesiboMessage *forward(uint32_t gid) = 0;

		virtual int deleteMessage() = 0;
		virtual int wipe() = 0;
	        virtual int recall() = 0;
		virtual int wipeAndRecall() = 0;
		virtual int mayBeRetracted() = 0;
		
		virtual void free() = 0;
};

class MesiboPresence  {
	public:

		uint32_t presence;	
		uint32_t value;	
		uint32_t interval;	
		uint32_t expiry;	

		uint32_t groupid;
		const char *peer;

	public:
		virtual ~MesiboPresence() {}

		virtual int send(void) = 0;
		virtual int send(uint32_t presence) = 0;

		virtual int sendTyping() = 0;
		virtual int sendTypingCleared() = 0;
		virtual int sendJoined() = 0;
		virtual int sendChatting() = 0;
		virtual int sendLeft() = 0;
		virtual int sendOnline() = 0;
		virtual int sendOffline() = 0;

		virtual int isRequest() = 0;
		virtual int isOnline() = 0;
		virtual int isOffline() = 0;
		virtual int isTyping() = 0;
		virtual int isTypingCleared() = 0;
		virtual int isChatting() = 0;
		virtual int hasJoined() = 0;
		virtual int hasLeft() = 0;
};

class MesiboListener {
	public:
		virtual ~MesiboListener() {}
		virtual int Mesibo_onMessage(MesiboMessage *m) = 0;
		virtual int Mesibo_onMessageUpdate(MesiboMessage *m) = 0;
		virtual int Mesibo_onMessageStatus(MesiboMessage *m) = 0;

		virtual int Mesibo_onPresence(MesiboPresence *p) = 0;

		virtual int Mesibo_onConnectionStatus(int status) = 0;
		virtual void Mesibo_onEndToEndEncryption(const char *address, int status) = 0;
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

class MesiboEndToEndEncryption {
	public:
		virtual ~MesiboEndToEndEncryption() {}
		virtual void enable(int enable) = 0;
		virtual int getStatus(const char *address) = 0;
		virtual int isActive(const char *address) = 0;
		virtual int setLevel(int level) = 0;
		virtual int setCiphers(uint32_t supported, uint32_t preferred) = 0;
		virtual int setPassword(const char *address, const char *password, int len) = 0;
		virtual int setAuthenticationTaglen(int len) = 0;
		virtual int setAuthenticationData(const char *address, const char *password, int len) = 0;
		virtual int getPublicCertificate(const char *filename) = 0;
		virtual int setPrivateCertificate(const char *filename) = 0;
		virtual int setPeerCertificate(const char *address, const char *filename) = 0;
		virtual const char *getPeerCertificateOrg(const char *address) = 0;
		virtual const char *getPeerCertificateCommonName(const char *address) = 0;
		virtual const char *getFingerprint(const char *address) = 0;
		virtual const char *getUserFingerprint(const char *address) = 0;
		virtual int setConfig(int level, uint32_t minops, uint32_t maxops, uint32_t mindur, uint32_t maxudr) = 0;
};

class Mesibo {
	public:
		virtual ~Mesibo() {}
		virtual int getConnectionStatus() = 0;
		
		virtual int setPath(const char *path) = 0;
		virtual const char *getBasePath() = 0;
		virtual const char *getDatabasePath() = 0;
		virtual const char *getImagePath(int sent) = 0;
		virtual const char *getVideoPath(int sent) = 0;
		virtual const char *getAudioPath(int sent) = 0;
		virtual const char *getDocumentPath(int sent) = 0;

		virtual int setDatabase(const char *dbNameWithPath, int resetTables) = 0;
		virtual int resetDatabase(int tables) = 0;

		virtual int backupDatabase(const char *path) = 0;
		virtual int restoreDatabase(const char *path) = 0;

		virtual int setAccessToken(const char *token) = 0;

		virtual MesiboEndToEndEncryption *e2ee() = 0;

		virtual void setOnlineStatusMode(int mode) = 0;
		virtual void setUploadUrl(const char *url, const char *authToken) = 0;
		virtual int addListener(MesiboListener *listener) = 0;
		virtual uint64_t getTimestamp() = 0;
		virtual int resend(uint64_t id) = 0;
		//virtual int forwardMessage(MesiboMessageProperties *params, uint64_t mid, uint64_t forwardid) = 0;
		//virtual int sendMessage(MesiboMessageProperties *params, uint64_t mid, const char *msg, uint32_t len) = 0;
		//virtual int sendFile(MesiboMessageProperties *params, uint32_t msgid, FileInfo file) = 0;
		//virtual int sendFileURL(MesiboMessageProperties *params, uint64_t id, const char *url, const char *thumbail, const char *title, const char *message, const char *launchurl) = 0;
		//		virtual int sendActivity(MesiboMessageProperties *params, uint32_t mid, uint32_t activity, uint32_t value, int interval) = 0;
		//		virtual int sendActivity(MesiboMessageProperties *params, uint32_t mid, int activity, int interval) = 0;
		virtual int sendPresence(const char *peer, uint32_t gid, uint32_t presence, uint32_t value, int interval) = 0; 
		virtual int setBufferLen(int len, int empty) = 0;

		virtual int setMessageRetractionInterval(uint32_t interval) = 0;
		virtual int getMessageRetractionInterval() = 0;
		virtual void setRemoteRetractionPolicy(int policy) = 0;

		virtual int wipeMessages(uint64_t *mids, uint32_t count, int remote) = 0;
		virtual int wipeMessage(uint64_t mid, int remote) = 0;
		virtual int wipeMessage(uint64_t mid) = 0;

		virtual int deleteMessages(uint64_t *mids, uint32_t count, int remote) = 0;
		virtual int deleteMessage(uint64_t mid, int remote) = 0;
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

		//[[deprecated("You can now generate mesibo v2 tokens without providing an appid, making these APIs unnecessary.")]]
		virtual void setAppName(const char *name) = 0; // depreciated, use setAppId
		
		//[[deprecated("You can now generate mesibo v2 tokens without providing an appid, making these APIs unnecessary.")]]
		virtual void setAppId(const char *name) = 0;

		virtual uint32_t random() = 0; // depreciated, use getUniqueMessageId
		virtual uint32_t getUniqueMessageId() = 0;
		virtual uint32_t getSenderMessageId(uint64_t mid) = 0;
		virtual int setKey(const char *key, const char *value) = 0;
		virtual const char *readKey(const char *key) = 0;
		virtual int deleteKey(const char *key) = 0;
		virtual int setConfig(uint32_t type, uint32_t value) = 0;
		virtual int setConfig(uint32_t type, const char *value) = 0;

		virtual int isAccountSuspended() = 0;
		virtual int isAccountPaid() = 0;
		
		virtual MesiboMessage *newMessage(const char *to, uint32_t gid) = 0;
		virtual MesiboMessage *newMessage(const char *to) = 0;
		virtual MesiboMessage *newMessage(uint32_t gid) = 0;
		virtual MesiboPresence *newPresence(const char *to, uint32_t gid) = 0;

		// Do not use following functions - they are used for code generation
		virtual MesiboMessage *p_newMessage(const char *to) = 0;
		virtual MesiboMessage *p_newGroupMessage(uint32_t gid) = 0;
		virtual MesiboPresence *p_newPresence(const char *to) = 0;
		virtual MesiboPresence *p_newGroupPresence(uint32_t gid) = 0;
		//virtual void log(const char *string, ...) = 0;
		//
		//unread()
		
};

#if defined(WINDOWS) || defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#ifdef MESIBO_BUILD
#define DLL_SYMBOL __declspec(dllexport)
#else
#define DLL_SYMBOL __declspec(dllimport)
#endif
#else
#define DLL_SYMBOL  
#endif


extern "C" DLL_SYMBOL void *MesiboInstanceInternal(const char *path, uint32_t bufsize);
extern "C" DLL_SYMBOL Mesibo *MesiboInstance(uint32_t bufsize);
extern "C" DLL_SYMBOL MesiboMessage *MesiboMessageInstance(const char *peer, uint32_t gid);
extern "C" DLL_SYMBOL Mesibo *MesiboPythonInstance(uint32_t bufsize, const char *version, const char *pyversion);
extern "C" DLL_SYMBOL int MesiboInterfaceVersion();
extern "C" DLL_SYMBOL int MesiboIsUTF8(const char *data, uint32_t len);
