/*
 * Copyright (c) 2012, 2013 Samsung Electronics Co., Ltd.
 * Copyright (c) 2019 Collabora Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _PTP_DATACODES_H_
#define _PTP_DATACODES_H_

/*
 * PTP Data type codes.
 */
#define PTP_DATATYPE_UNDEFINED		0x0000
#define PTP_DATATYPE_INT8		0x0001
#define PTP_DATATYPE_UINT8		0x0002
#define PTP_DATATYPE_INT16		0x0003
#define PTP_DATATYPE_UINT16		0x0004
#define PTP_DATATYPE_INT32		0x0005
#define PTP_DATATYPE_UINT32		0x0006
#define PTP_DATATYPE_INT64		0x0007
#define PTP_DATATYPE_UINT64		0x0008
#define PTP_DATATYPE_INT128		0x0009
#define PTP_DATATYPE_UINT128		0x000A
#define PTP_DATATYPE_AINT8		0x4001
#define PTP_DATATYPE_AUINT8		0x4002
#define PTP_DATATYPE_AINT16		0x4003
#define PTP_DATATYPE_AUINT16		0x4004
#define PTP_DATATYPE_AINT32		0x4005
#define PTP_DATATYPE_AUINT32		0x4006
#define PTP_DATATYPE_AINT64		0x4007
#define PTP_DATATYPE_AUINT64		0x4008
#define PTP_DATATYPE_AINT128		0x4009
#define PTP_DATATYPE_AUINT128		0x400A
#define PTP_DATATYPE_STRING		0xFFFF
#define PTP_DATATYPE_ARRAYMASK		0x4FF0
#define PTP_DATATYPE_ARRAY		0x4000
#define PTP_DATATYPE_VALUEMASK		0xFFF0
#define PTP_DATATYPE_VALUE		0x0000

/*
 * Data code ranges and masks. Each data code has 16 bits:
 * Bit 15(std/vendor)
 * 0 -- the code is defined by PTP standard
 * 1 -- the code is vendor specific
 *
 * Bit 14 - 12(data type)
 * 14 13 12
 * 0  0  0    -- undefined data type
 * 0  0  1    -- op code
 * 0  1  0    -- response code
 * 0  1  1    -- format code
 * 1  0  0    -- event code
 * 1  0  1    -- property code
 * 1  1  0    -- reserved
 * 1  1  1    -- reserved
 *
 * Bit 11 - bit 0 (data value)
 */
#define  PTP_DATACODE_VENDORMASK	0x8000
#define  PTP_DATACODE_TYPEMASK		0x7000
#define  PTP_DATACODE_VALUEMASK		0x0FFF
#define  PTP_DATACODE_TYPE_UNKNOWN	0x0000
#define  PTP_DATACODE_TYPE_OPERATION	0x1000
#define  PTP_DATACODE_TYPE_RESPONSE	0x2000
#define  PTP_DATACODE_TYPE_FORMAT	0x3000
#define  PTP_DATACODE_TYPE_EVENT	0x4000
#define  PTP_DATACODE_TYPE_PROPERTY	0x5000
#define  PTP_DATACODE_TYPE_RESERVED_1	0x6000
#define  PTP_DATACODE_TYPE_RESERVED_2	0x7000

/*
 * To verify an op code
 *  (Code & PTP_DATACODE_TYPEMASK) == PTP_DATACODE_TYPE_OPERATION
 * To verify a response code
 *  (Code & PTP_DATACODE_TYPEMASK) == PTP_DATACODE_TYPE_RESPONSE)
 */

/*
 * Image format codes receive special treatment.
 */
#define  PTP_DATACODE_TYPEIMAGEMASK	0x7800;
#define  PTP_DATACODE_TYPE_IMAGEFORMAT	0x3800;
#define  PTP_DATACODE_VALUE_IMAGEVMASK	0x07FF;
/*
 * To verify an image code
 * (Code & PTP_DATACODE_TYPEIMAGEMASK) == PTP_DATACODE_TYPE_IMAGEFORMAT
 */

/*
 * PTP specially defined constants
 */
#define PTP_OBJECTHANDLE_ALL		0xFFFFFFFF
#define PTP_OBJECTHANDLE_UNDEFINED	0x0
#define PTP_OBJECTHANDLE_ROOT		0x0
#define PTP_PROPERTY_ALL		0xFFFFFFFF
#define PTP_PROPERTY_UNDEFINED		0x0
#define PTP_STORAGEID_ALL		0xFFFFFFFF
#define PTP_STORAGEID_DEFAULT		0
#define PTP_STORAGEID_UNDEFINED		0
#define PTP_STORAGEID_PHYSICAL		0x0000FFFF
#define PTP_STORAGEID_LOGICAL		0xFFFF0000
#define PTP_SESSIONID_ALL		0
#define PTP_SESSIONID_NOSESSION		0
#define PTP_FORMATCODE_NOTUSED		0x0
#define PTP_FORMATCODE_ALL		0xFFFFFFFF
#define PTP_FORMATCODE_DEFAULT		0x0000
#define PTP_TRANSACTIONID_ALL		0xFFFFFFFF
#define PTP_TRANSACTIONID_NOSESSION	0

/*
 * standard operation codes:
 */
#define PTP_OPCODE_UNDEFINED		0x1000
#define PTP_OPCODE_GETDEVICEINFO	0x1001
#define PTP_OPCODE_OPENSESSION		0x1002
#define PTP_OPCODE_CLOSESESSION		0x1003
#define PTP_OPCODE_GETSTORAGEIDS	0x1004
#define PTP_OPCODE_GETSTORAGEINFO	0x1005
#define PTP_OPCODE_GETNUMOBJECTS	0x1006
#define PTP_OPCODE_GETOBJECTHANDLES	0x1007
#define PTP_OPCODE_GETOBJECTINFO	0x1008
#define PTP_OPCODE_GETOBJECT		0x1009
#define PTP_OPCODE_DELETEOBJECT		0x100B
#define PTP_OPCODE_SENDOBJECTINFO	0x100C
#define PTP_OPCODE_SENDOBJECT		0x100D
#define PTP_OPCODE_INITIATECAPTURE	0x100E
#define PTP_OPCODE_FORMATSTORE		0x100F
#define PTP_OPCODE_RESETDEVICE		0x1010
#define PTP_OPCODE_SETOBJECTPROTECTION	0x1012
#define PTP_OPCODE_POWERDOWN		0x1013
#define PTP_OPCODE_GETDEVICEPROPDESC	0x1014
#define PTP_OPCODE_GETDEVICEPROPVALUE	0x1015
#define PTP_OPCODE_SETDEVICEPROPVALUE	0x1016
#define PTP_OPCODE_TERMINATECAPTURE	0x1018
#define PTP_OPCODE_GETPARTIALOBJECT	0x101B
#define PTP_OPCODE_INITIATEOPENCAPTURE	0x101C
#define PTP_OPCODE_VENDOREXTENDEDBASE	0x9000
#define PTP_CODE_VENDOR_OP1		0x9001

/* MTP extended operations */
#define	MTP_OPCODE_UNDEFINED			0x9800
#define	MTP_OPCODE_GETOBJECTPROPSUPPORTED	0x9801
#define	MTP_OPCODE_GETOBJECTPROPDESC		0x9802
#define	MTP_OPCODE_GETOBJECTPROPVALUE		0x9803
#define	MTP_OPCODE_SETOBJECTPROPVALUE		0x9804
#define	MTP_OPCODE_GETOBJECTPROPLIST		0x9805
#define MTP_OPCODE_GETINTERDEPPROPDESC		0x9807
#define	MTP_OPCODE_GETOBJECTREFERENCES		0x9810
#define	MTP_OPCODE_SETOBJECTREFERENCES		0x9811

/* MTP Playback control operation */
#define	MTP_OPCODE_PLAYBACK_SKIP		0x9820

/* Operation for Windows Media 10 MTP extension */
#define	MTP_OPCODE_WMP_UNDEFINED				0x9200
#define	MTP_OPCODE_WMP_METADATAROUNDTRIP			0x9201

/*
 * standard event codes:
 */
#define PTP_EVENTCODE_UNDEFINED			0x4000
#define PTP_EVENTCODE_CANCELTRANSACTION		0x4001
#define PTP_EVENTCODE_OBJECTADDED		0x4002
#define PTP_EVENTCODE_OBJECTREMOVED		0x4003
#define PTP_EVENTCODE_STOREADDED		0x4004
#define PTP_EVENTCODE_STOREREMOVED		0x4005
#define PTP_EVENTCODE_DEVICEPROPCHANGED		0x4006
#define PTP_EVENTCODE_OBJECTINFOCHANGED		0x4007
#define PTP_EVENTCODE_DEVICEINFOCHANGED		0x4008
#define PTP_EVENTCODE_REQUESTOBJECTTRANSFER	0x4009
#define PTP_EVENTCODE_STOREFULL			0x400A
#define PTP_EVENTCODE_DEVICERESET		0x400B
#define PTP_EVENTCODE_STORAGEINFOCHANGED	0x400C
#define PTP_EVENTCODE_CAPTURECOMPLETE		0x400D
#define PTP_EVENTCODE_UNREPORTEDSTATUS		0x400E
#define PTP_EVENTCODE_VENDOREXTENTION1		0xC001
#define PTP_EVENTCODE_VENDOREXTENTION2		0xC002

/*
 * MTP-extended Events
 */
#define MTP_EVENTCODE_UNDEFINED			0xB800
#define MTP_EVENTCODE_OBJECTPROPCHANGED		0xC801
#define MTP_EVENTCODE_OBJECTPROPDESCCHANGED	0xC802
#define MTP_EVENTCODE_OBJECTREFERENCESCHANGED	0xC803
#define MTP_EVENTCODE_DEVICEPROPDESCCHANGED	0xB804

/* Events for Janus MTP extension */
#define MTP_EVENTCODE_JANUS_UNDEFINED		0xC100
#define MTP_EVENTCODE_JANUS_EVENT1		0xC101

/*
 * standard response codes:
 */
#define PTP_RESPONSE_UNDEFINED			0x2000
#define PTP_RESPONSE_OK				0x2001
#define PTP_RESPONSE_GEN_ERROR			0x2002
#define PTP_RESPONSE_SESSIONNOTOPEN		0x2003
#define PTP_RESPONSE_INVALID_TRANSACTIONID	0x2004
#define PTP_RESPONSE_OP_NOT_SUPPORTED		0x2005
#define PTP_RESPONSE_PARAM_NOTSUPPORTED		0x2006
#define PTP_RESPONSE_INCOMPLETETRANSFER		0x2007
#define PTP_RESPONSE_INVALID_STORE_ID		0x2008
#define PTP_RESPONSE_INVALID_OBJ_HANDLE		0x2009
#define PTP_RESPONSE_PROP_NOTSUPPORTED		0x200A
#define PTP_RESPONSE_INVALID_OBJ_FMTCODE	0x200B
#define PTP_RESPONSE_STOREFULL			0x200C
#define PTP_RESPONSE_OBJ_WRITEPROTECTED		0x200D
#define PTP_RESPONSE_STORE_READONLY		0x200E
#define PTP_RESPONSE_ACCESSDENIED		0x200F
#define PTP_RESPONSE_SELFTEST_FAILED		0x2011
#define PTP_RESPONSE_PARTIAL_DELETION		0x2012
#define PTP_RESPONSE_STORENOTAVAILABLE		0x2013
#define PTP_RESPONSE_NOSPECIFICATIONBYFORMAT	0x2014
#define PTP_RESPONSE_NOVALID_OBJINFO		0x2015
#define PTP_RESPONSE_INVALIDCODEFORMAT		0x2016
#define PTP_RESPONSE_UNKNOWN_VENDORCODE		0x2017
#define PTP_RESPONSE_CAPTURE_ALREADYTERMINATED	0x2018
#define PTP_RESPONSE_DEVICEBUSY			0x2019
#define PTP_RESPONSE_INVALIDPARENT		0x201A
#define PTP_RESPONSE_INVALIDPROPFORMAT		0x201B
#define PTP_RESPONSE_INVALIDPROPVALUE		0x201C
#define PTP_RESPONSE_INVALIDPARAM		0x201D
#define PTP_RESPONSE_SESSIONALREADYOPENED	0x201E
#define PTP_RESPONSE_TRANSACTIONCANCELLED	0x201F
/*
 * MTP responses
 */
#define MTP_RESPONSE_UNDEFINED				0xA800
#define MTP_RESPONSE_INVALIDOBJPROPCODE			0xA801
#define MTP_RESPONSE_INVALIDOBJPROPFORMAT		0xA802
#define MTP_RESPONSE_INVALIDOBJPROPVALUE		0xA803
#define MTP_RESPONSE_INVALIDOBJREFERENCE		0xA804
#define MTP_RESPONSE_INVALIDOBJGROUPCODE		0xA805
#define MTP_RESPONSECODE_INVALIDDATASET			0xA806
#define MTP_RESPONSE_SPECIFICATION_BY_GROUP_UNSUPPORTED 0xA807
#define MTP_RESPONSE_SPECIFICATION_BY_DEPTH_UNSUPPORTED 0xA808
#define MTP_RESPONSE_OBJECT_TOO_LARGE			0xA809

/*
 * standard property codes:
 */
#define PTP_PROPERTYCODE_UNDEFINED		0x5000
#define PTP_PROPERTYCODE_BATTERYLEVEL		0x5001
#define PTP_PROPERTYCODE_FUNCTIONMODE		0x5002
#define PTP_PROPERTYCODE_IMAGESIZE		0x5003
#define PTP_PROPERTYCODE_COMPRESSIONSETTING	0x5004
#define PTP_PROPERTYCODE_WHITEBALANCE           0x5005
#define PTP_PROPERTYCODE_RGBGAIN                0x5006
#define PTP_PROPERTYCODE_FNUMBER                0x5007
#define PTP_PROPERTYCODE_FOCALLENGTH            0x5008
#define PTP_PROPERTYCODE_FOCUSDISTANCE		0x5009
#define PTP_PROPERTYCODE_FOCUSMODE              0x500A
#define PTP_PROPERTYCODE_EXPOSUREMETERINGMODE   0x500B
#define PTP_PROPERTYCODE_FLASHMODE              0x500C
#define PTP_PROPERTYCODE_EXPOSURETIME           0x500D
#define PTP_PROPERTYCODE_EXPOSUREPROGRAMMODE    0x500E
#define PTP_PROPERTYCODE_EXPOSUREINDEX          0x500F
#define PTP_PROPERTYCODE_EXPOSURECOMPENSATION   0x5010
#define PTP_PROPERTYCODE_DATETIME               0x5011
#define PTP_PROPERTYCODE_CAPTUREDELAY           0x5012
#define PTP_PROPERTYCODE_STILLCAPTUREMODE       0x5013
#define PTP_PROPERTYCODE_CONTRAST               0x5014
#define PTP_PROPERTYCODE_SHARPNESS              0x5015
#define PTP_PROPERTYCODE_DIGITALZOOM            0x5016
#define PTP_PROPERTYCODE_EFFECTMODE		0x5017
#define PTP_PROPERTYCODE_BURSTNUMBER            0x5018
#define PTP_PROPERTYCODE_BURSTINTERVAL          0x5019
#define PTP_PROPERTYCODE_TIMELAPSENUMBER        0x501A
#define PTP_PROPERTYCODE_TIMELAPSEINTERVAL	0x501B
#define PTP_PROPERTYCODE_FOCUSMETERINGMODE	0x501C
#define PTP_PROPERTYCODE_UPLOADURL		0x501D
#define PTP_PROPERTYCODE_ARTIST			0x501E
#define PTP_PROPERTYCODE_COPYRIGHT		0x501F
#define PTP_PROPERTYCODE_VENDOREXTENTION1	0xD001
#define PTP_PROPERTYCODE_VENDOREXTENTION2	0xD002

/* Device properties for MTP Playback */
#define MTP_PROPERTYCODE_PLAYBACK_OBJECT			0xD411
#define MTP_PROPERTYCODE_PLAYBACK_CONT_INDEX			0xD412
#define MTP_PROPERTYCODE_PLAYBACK_POSITION			0xD413

/* MTP extended object property codes */
#define	MTP_OBJ_PROPERTYCODE_PURCHASE_ALBTRK			0xD901

/* for support OMA DRM, request of Vodafone */
#define MTP_OBJ_PROPERTYCODE_OMADRMSTATUS			0xDB01
#define MTP_OBJ_PROPERTYCODE_OMADRMRIGHTSOBJECT			0xDB02

#define MTP_OBJ_PROPERTYCODE_STORAGEID				0xDC01
#define MTP_OBJ_PROPERTYCODE_OBJECTFORMAT			0xDC02
#define MTP_OBJ_PROPERTYCODE_PROTECTIONSTATUS			0xDC03
#define MTP_OBJ_PROPERTYCODE_OBJECTSIZE				0xDC04
#define MTP_OBJ_PROPERTYCODE_ASSOCIATIONTYPE			0xDC05
#define MTP_OBJ_PROPERTYCODE_ASSOCIATIONDESC			0xDC06
#define MTP_OBJ_PROPERTYCODE_OBJECTFILENAME			0xDC07
#define MTP_OBJ_PROPERTYCODE_DATECREATED			0xDC08
#define MTP_OBJ_PROPERTYCODE_DATEMODIFIED			0xDC09
#define MTP_OBJ_PROPERTYCODE_KEYWORDS				0xDC0A
#define MTP_OBJ_PROPERTYCODE_PARENT				0xDC0B

#define MTP_OBJ_PROPERTYCODE_PERSISTENTGUID			0xDC41
#define MTP_OBJ_PROPERTYCODE_SYNCID				0xDC42
#define MTP_OBJ_PROPERTYCODE_PROPERTYBAG			0xDC43
#define MTP_OBJ_PROPERTYCODE_NAME				0xDC44
#define MTP_OBJ_PROPERTYCODE_CREATEDBY				0xDC45
#define MTP_OBJ_PROPERTYCODE_ARTIST				0xDC46
#define MTP_OBJ_PROPERTYCODE_DATEAUTHORED			0xDC47
#define MTP_OBJ_PROPERTYCODE_DESCRIPTION			0xDC48
#define MTP_OBJ_PROPERTYCODE_URLREFERENCE			0xDC49
#define MTP_OBJ_PROPERTYCODE_LANGUAGELOCALE			0xDC4A
#define MTP_OBJ_PROPERTYCODE_COPYRIGHTINFO			0xDC4B
#define MTP_OBJ_PROPERTYCODE_SOURCE				0xDC4C
#define MTP_OBJ_PROPERTYCODE_ORIGINLOCATION			0xDC4D
#define MTP_OBJ_PROPERTYCODE_DATEADDED				0xDC4E
#define MTP_OBJ_PROPERTYCODE_NONCONSUMABLE			0xDC4F
#define MTP_OBJ_PROPERTYCODE_CORRUPTUNPLAYABLE			0xDC50

#define MTP_OBJ_PROPERTYCODE_SAMPLEFORMAT			0xDC81
#define MTP_OBJ_PROPERTYCODE_SAMPLESIZE				0xDC82
#define MTP_OBJ_PROPERTYCODE_SAMPLEHEIGHT			0xDC83
#define MTP_OBJ_PROPERTYCODE_SAMPLEWIDTH			0xDC84
#define MTP_OBJ_PROPERTYCODE_SAMPLEDURATION			0xDC85
#define MTP_OBJ_PROPERTYCODE_SAMPLEDATA				0xDC86
#define MTP_OBJ_PROPERTYCODE_WIDTH				0xDC87
#define MTP_OBJ_PROPERTYCODE_HEIGHT				0xDC88
#define MTP_OBJ_PROPERTYCODE_DURATION				0xDC89
#define MTP_OBJ_PROPERTYCODE_USERRATING				0xDC8A
#define MTP_OBJ_PROPERTYCODE_TRACK				0xDC8B
#define MTP_OBJ_PROPERTYCODE_GENRE				0xDC8C
#define MTP_OBJ_PROPERTYCODE_CREDITS				0xDC8D
#define MTP_OBJ_PROPERTYCODE_LYRICS				0xDC8E
#define MTP_OBJ_PROPERTYCODE_SUBSCRIPCONTENTID			0xDC8F
#define MTP_OBJ_PROPERTYCODE_PRODUCEDBY				0xDC90
#define MTP_OBJ_PROPERTYCODE_USECOUNT				0xDC91
#define MTP_OBJ_PROPERTYCODE_SKIPCOUNT				0xDC92
#define MTP_OBJ_PROPERTYCODE_LASTACCESSED			0xDC93
#define MTP_OBJ_PROPERTYCODE_PARENTALRATING			0xDC94
#define MTP_OBJ_PROPERTYCODE_METAGENRE				0xDC95
#define MTP_OBJ_PROPERTYCODE_COMPOSER				0xDC96
#define MTP_OBJ_PROPERTYCODE_EFFECTIVERATING			0xDC97
#define MTP_OBJ_PROPERTYCODE_SUBTITLE				0xDC98
#define MTP_OBJ_PROPERTYCODE_ORIGINALRELEASEDATE		0xDC99
#define MTP_OBJ_PROPERTYCODE_ALBUMNAME				0xDC9A
#define MTP_OBJ_PROPERTYCODE_ALBUMARTIST			0xDC9B
#define MTP_OBJ_PROPERTYCODE_MOOD				0xDC9C
#define MTP_OBJ_PROPERTYCODE_DRMSTATUS				0xDC9D
#define MTP_OBJ_PROPERTYCODE_SUBDESCRIPTION			0xDC9E

#define MTP_OBJ_PROPERTYCODE_ISCROPPED				0xDCD1
#define MTP_OBJ_PROPERTYCODE_ISCOLORCORRECTED			0xDCD2

#define MTP_OBJ_PROPERTYCODE_TOTALBITRATE			0xDE91
#define MTP_OBJ_PROPERTYCODE_BITRATETYPE			0xDE92
#define MTP_OBJ_PROPERTYCODE_SAMPLERATE				0xDE93
#define MTP_OBJ_PROPERTYCODE_NUMBEROFCHANNELS			0xDE94
#define MTP_OBJ_PROPERTYCODE_AUDIOBITDEPTH			0xDE95
#define MTP_OBJ_PROPERTYCODE_SCANTYPE				0xDE97
#define MTP_OBJ_PROPERTYCODE_AUDIOWAVECODEC			0xDE99
#define MTP_OBJ_PROPERTYCODE_AUDIOBITRATE			0xDE9A
#define MTP_OBJ_PROPERTYCODE_VIDEOFOURCCCODEC			0xDE9B
#define MTP_OBJ_PROPERTYCODE_VIDEOBITRATE			0xDE9C
#define MTP_OBJ_PROPERTYCODE_FRAMESPER1KSECONDS			0xDE9D
#define MTP_OBJ_PROPERTYCODE_KEYFRAMEDISTANCE			0xDE9E
#define MTP_OBJ_PROPERTYCODE_BUFFERSIZE				0xDE9F
#define MTP_OBJ_PROPERTYCODE_ENCODINGQUALITY			0xDEA0
#define MTP_OBJ_PROPERTYCODE_ENCODINGPROFILE			0xDEA1
#define	MTP_OBJ_PROPERTYCODE_PLAYBACK_RATE			0xDF01
#define	MTP_OBJ_PROPERTYCODE_PLAYBACK_OBJECT			0xDF02
#define	MTP_OBJ_PROPERTYCODE_PLAYBACK_CONT_INDEX		0xDF03
#define	MTP_OBJ_PROPERTYCODE_PLAYBACK_POSITION			0xDF04

/* standard format codes */
#define  PTP_FORMATMASK_IMAGE		0x0800

#define  PTP_FMT_UNDEF			0x3000
#define  PTP_FMT_ASSOCIATION		0x3001
#define  PTP_FMT_SCRIPT			0x3002
#define  PTP_FMT_EXEC			0x3003
#define  PTP_FMT_TEXT			0x3004
#define  PTP_FMT_HTML			0x3005
#define  PTP_FMT_DPOF			0x3006
#define  PTP_FMT_AIFF			0x3007
#define  PTP_FMT_WAVE			0x3008
#define  PTP_FMT_MP3			0x3009
#define  PTP_FMT_AVI			0x300A
#define  PTP_FMT_MPEG			0x300B
#define  PTP_FMT_ASF			0x300C

#define  PTP_FMT_IMG_UNDEF		0x3800
#define  PTP_FMT_IMG_EXIF		0x3801
#define  PTP_FMT_IMG_TIFFEP		0x3802
#define  PTP_FMT_IMG_FLASHPIX		0x3803
#define  PTP_FMT_IMG_BMP		0x3804
#define  PTP_FMT_IMG_CIFF		0x3805
#define  PTP_FMT_IMG_GIF		0x3807
#define  PTP_FMT_IMG_JFIF		0x3808
#define  PTP_FMT_IMG_PCD		0x3809
#define  PTP_FMT_IMG_PICT		0x380A
#define  PTP_FMT_IMG_PNG		0x380B
#define  PTP_FMT_IMG_TIFF		0x380D
#define  PTP_FMT_IMG_TIFFIT		0x380E
#define  PTP_FMT_IMG_JP2		0x380F
#define  PTP_FMT_IMG_JPX		0x3810

/* MTP-defined Object Formats */
#define  MTP_FMT_UNDEFINED_FIRMWARE		0xB802
#define  MTP_FMT_WINDOWS_IMG_FORMAT		0xB881
#define  MTP_FMT_UNDEFINED_AUDIO		0xB900
#define  MTP_FMT_WMA				0xB901
#define  MTP_FMT_UNDEFINED_VIDEO		0xB980
#define  MTP_FMT_WMV				0xB981
#define  MTP_FMT_UNDEFINED_COLLECTION		0xBA00
#define  MTP_FMT_ABSTRACT_MULTIMEDIA_ALBUM	0xBA01
#define  MTP_FMT_ABSTRACT_IMG_ALBUM		0xBA02
#define  MTP_FMT_ABSTRACT_AUDIO_ALBUM		0xBA03
#define  MTP_FMT_ABSTRACT_VIDEO_ALBUM		0xBA04
#define  MTP_FMT_ABSTRACT_CONTACT_GROUP		0xBA06
#define  MTP_FMT_ABSTRACT_MESSAGE_FOLDER	0xBA07
#define  MTP_FMT_ABSTRACT_CHAPTERED_PRODUCTION  0xBA08
#define  MTP_FMT_UNDEFINED_DOC			0xBA80
#define  MTP_FMT_ABSTRACT_DOC			0xBA81
#define  MTP_FMT_UNDEFINED_MESSAGE		0xBB00
#define  MTP_FMT_ABSTRACT_MESSAGE		0xBB01
#define  MTP_FMT_UNDEFINED_CONTACT		0xBB80
#define  MTP_FMT_ABSTRACT_CONTACT		0xBB81
#define  MTP_FMT_VCARD2				0xBB82
#define  MTP_FMT_VCARD3				0xBB83
#define  MTP_FMT_UNDEFINED_CALENDAR_ITEM	0xBE00
#define  MTP_FMT_ABSTRACT_CALENDAR_ITEM		0xBE01
#define  MTP_FMT_VCALENDAR1			0xBE02
#define  MTP_FMT_UNDEFINED_WINDOWS_EXECUTABLE	0xBE80

#define  MTP_FMT_FLAC				0xB906
#define	 MTP_FMT_MP4				0xB982
#define	 MTP_FMT_3GP				0xB984

/*
 * Property description data set form flags definitions
 */
#define PTP_FORMFLAGS_NONE			0x00
#define PTP_FORMFLAGS_RANGE			0x01
#define PTP_FORMFLAGS_ENUM			0x02

/*
 * power states:
 */
#define PTP_POWERSTATE_DEVICEOFF		0x0000
#define PTP_POWERSTATE_SLEEP			0x0001
#define PTP_POWERSTATE_FULL			0x0002

/*
 * white balances:
 */
#define PTP_WHITEBALANCE_UNDEFINED		0x0000
#define PTP_WHILEBALANCE_MANUAL			0x0001
#define PTP_WHITEBALANCE_AUTOMATIC		0x0002
#define PTP_WHITEBALANCE_ONEPUSHAUTO		0x0003
#define PTP_WHITEBALANCE_DAYLIGHT		0x0004
#define PTP_WHITEBALANCE_FLORESCENT		0x0005
#define PTP_WHITEBALANCE_TUNGSTEN		0x0006
#define PTP_WHITEBALANCE_FLASH			0x0007

/*
 * focus modes:
 */
#define PTP_FOCUSMODE_UNDEFINED			0x0000
#define PTP_FOCUSMODE_MANUAL			0x0001
#define PTP_FOCUSMODE_AUTO			0x0002
#define PTP_FOCUSMODE_MACRO			0x0003

/*
 * focus metering:
 */
#define  PTP_FOCUSMETERING_UNDEFINED		0x0000
#define  PTP_FOCUSMETERING_CENTERSPOT		0x0001
#define  PTP_FOCUSMETERING_MULTISPOT		0x0002

/*
 * flash modes:
 */
#define PTP_FLASHMODE_UNDEFINED			0x0000
#define PTP_FLASHMODE_AUTO			0x0001
#define PTP_FLASHMODE_OFF			0x0002
#define PTP_FLASHMODE_FILL			0x0003
#define PTP_FLASHMODE_REDEYEAUTO		0x0004
#define PTP_FLASHMODE_REDEYEFILL		0x0005
#define PTP_FLASHMODE_EXTERNALSYNC		0x0006
#define PTP_FLASHMODE_MASK			0xFFF0

/*
 * exposure modes:
 */
#define PTP_EXPOSUREMODE_UNDEFINED		0x0000
#define PTP_EXPOSUREMODE_MANUALSETTING		0x0001
#define PTP_EXPOSUREMODE_AUTOPROGRAM		0x0002
#define PTP_EXPOSUREMODE_APERTUREPRIORITY	0x0003
#define PTP_EXPOSUREMODE_SHUTTERPRIORITY	0x0004
#define PTP_EXPOSUREMODE_PROGRAMCREATIVE	0x0005
#define PTP_EXPOSUREMODE_PROGRAMACTION		0x0006
#define PTP_EXPOSUREMODE_PORTRAIT		0x0007

/*
 * capturing modes
 */
#define  PTP_CAPTUREMODE_UNDEFINED		0x0000
#define  PTP_CAPTUREMODE_NORMAL			0x0001
#define  PTP_CAPTUREMODE_BURST			0x0002
#define  PTP_CAPTUREMODE_TIMELAPSE		0x0003

/*
 * focus metering modes
 */
#define  PTP_FOCUSMETERMODE_UNDEFINED		0x0000
#define  PTP_FOCUSMETERMODE_CENTERSPOT		0x0001
#define  PTP_FOCUSMETERMODE_MULTISPOT		0x0002

/*
 * effect modes
 */
#define PTP_EFFECTMODE_UNDEFINED		0x0000
#define PTP_EFFECTMODE_COLOR			0x0001
#define PTP_EFFECTMODE_BW			0x0002
#define PTP_EFFECTMODE_SEPIA			0x0003

/*
 * storage types
 */
#define PTP_STORAGETYPE_UNDEFINED		0x0000
#define PTP_STORAGETYPE_FIXEDROM		0x0001
#define PTP_STORAGETYPE_REMOVABLEROM		0x0002
#define PTP_STORAGETYPE_FIXEDRAM		0x0003
#define PTP_STORAGETYPE_REMOVABLERAM		0x0004

/*
 * storage access capabilities
 */
#define PTP_STORAGEACCESS_RWD			0x0000
#define PTP_STORAGEACCESS_R			0x0001
#define PTP_STORAGEACCESS_RD			0x0002

/*
 * association types:
 */
#define PTP_ASSOCIATIONTYPE_UNDEFINED		0x0000
#define PTP_ASSOCIATIONTYPE_FOLDER		0x0001
#define PTP_ASSOCIATIONTYPE_ALBUM		0x0002
#define PTP_ASSOCIATIONTYPE_BURST		0x0003
#define PTP_ASSOCIATIONTYPE_HPANORAMA		0x0004
#define PTP_ASSOCIATIONTYPE_VPANORAMA		0x0005
#define PTP_ASSOCIATIONTYPE_2DPANORAMA		0x0006
#define PTP_ASSOCIATIONTYPE_ANCILLARYDATA	0x0007
#define PTP_ASSOCIATIONTYPE_MASK		0xFFF0

/*
 * protection status:
 */
#define PTP_PROTECTIONSTATUS_NOPROTECTION		0x0000
#define PTP_PROTECTIONSTATUS_READONLY			0x0001
#define MTP_PROTECTIONSTATUS_READONLY_DATA		0x8002
#define MTP_PROTECTIONSTATUS_NONTRANSFERABLE_DATA	0x8003

/* file system types */
#define PTP_FILESYSTEMTYPE_UNDEFINED			0x0000
#define PTP_FILESYSTEMTYPE_FLAT				0x0001
#define PTP_FILESYSTEMTYPE_HIERARCHICAL			0x0002
#define PTP_FILESYSTEMTYPE_DCF				0x0003

/*
 * functional modes:
 */
#define  PTP_FUNCTIONMODE_STANDARD			0x0000
#define  PTP_FUNCTIONMODE_SLEEP				0x0001

/*
 * Get/Set
 */
#define  PTP_PROPGETSET_GETONLY				0x00
#define  PTP_PROPGETSET_GETSET				0x01
#define	 PTP_PROPGETSET_GETSET2				0x02

/* Common Audio Sample Rate */
#define MTP_AUDIO_SAMPLERATE_UNKNOWN			0
#define MTP_AUDIO_SAMPLERATE_8K				8000
#define MTP_AUDIO_SAMPLERATE_32K			32000
#define MTP_AUDIO_SAMPLERATE_CD				44100
#define MTP_AUDIO_SAMPLERATE_48K			48000
#define MTP_AUDIO_SAMPLERATE_DVD			96000

/* Common Audio Bit Rate */
#define MTP_AUDIO_BITRATE_UNKNOWN			0
#define MTP_AUDIO_BITRATE_GSM				13000
#define MTP_AUDIO_BITRATE_16K				16999
#define MTP_AUDIO_BITRATE_G721				32000
#define MTP_AUDIO_BITRATE_G711				64000
#define MTP_AUDIO_BITRATE_128K				128999
#define MTP_AUDIO_BITRATE_CDDA				144100
#define MTP_AUDIO_BITRATE_160K				160999
#define MTP_AUDIO_BITRATE_192K				192999
#define MTP_AUDIO_BITRATE_256K				256999
#define MTP_AUDIO_BITRATE_STUDIO			384999
#define MTP_AUDIO_BITRATE_BLUERAY			10000000


/* Common Video Bit Rate */
#define MTP_VIDEO_BITRATE_MINIMUM        1000
#define MTP_VIDEO_BITRATE_BLUERAY        40000000

/* Common Metagenre defined */
#define MTP_METAGENRE_NOT_USED				0x0000
#define MTP_METAGENRE_GENERIC_MUSIC_AUDIO_FILE		0x0001
#define MTP_METAGENRE_GENERIC_NONMUSIC_AUDIO_FILE	0x0011
#define MTP_METAGENRE_SPOKEN_WORD_AUDIO_BOOK_FILES	0x0012
#define MTP_METAGENRE_SPOKEN_WORD_NONAUDIO_BOOK_FILES	0x0013
#define MTP_METAGENRE_SPOKEN_WORD_NEWS			0x0014
#define MTP_METAGENRE_SPOKEN_WORD_TALK_SHOWS		0x0015
#define MTP_METAGENRE_GENERIC_VIDEO_FILE		0x0021
#define MTP_METAGENRE_NEWS_VIDEO_FILE			0x0022
#define MTP_METAGENRE_MUSIC_VIDEO_FILE			0x0023
#define MTP_METAGENRE_HOME_VIDEO_FILE			0x0024
#define MTP_METAGENRE_FEATURE_FILM_VIDEO_FILE		0x0025
#define MTP_METAGENRE_TV_SHOW_VIDEO_FILE		0x0026
#define MTP_METAGENRE_TRAINING_VIDEO_FILE		0x0027
#define MTP_METAGENRE_PHOTO_MONTAGE_VIDEO_FILE		0x0028
#define MTP_METAGENRE_GENERIC_NONAUDIO_NONVIDEO_FILE	0x0030
#define MTP_METAGENRE_AUDIO_MEDIA_CAST_FILE		0x0040
#define MTP_METAGENRE_VIDEO_MEDIA_CAST_FILE		0x0041
#define MTP_METAGENRE_MIXED_MEDIA_CAST_FILE		0x0042
#define MTP_METAGENRE_VENDOR_DEFINED_MASK		0x8000

/* Common NumberOfChannels defined */
#define MTP_CHANNELS_NOT_USED				0x0000
#define MTP_CHANNELS_MONO				0x0001
#define MTP_CHANNELS_STEREO				0x0002
#define MTP_CHANNELS_2DOT1				0x0003
#define MTP_CHANNELS_3					0x0004
#define MTP_CHANNELS_3DOT1				0x0005
#define MTP_CHANNELS_4					0x0006
#define MTP_CHANNELS_4DOT1				0x0007
#define MTP_CHANNELS_5					0x0008
#define MTP_CHANNELS_5DOT1				0x0009
#define MTP_CHANNELS_6					0x000A
#define MTP_CHANNELS_6DOT1				0x000B
#define MTP_CHANNELS_7					0x000C
#define MTP_CHANNELS_7DOT1				0x000D
#define MTP_CHANNELS_8					0x000E
#define MTP_CHANNELS_8DOT1				0x000F
#define MTP_CHANNELS_9					0x0010
#define MTP_CHANNELS_9DOT1				0x0011

/* Common ScanTypes defined */
#define MTP_SCANTYPE_NOT_USED				0x0000
#define MTP_SCANTYPE_PROGESSIVE				0x0001
#define MTP_SCANTYPE_FIELDINTERLEAVEDUPPERFIRST		0x0002
#define MTP_SCANTYPE_FIELDINTERLEAVEDLOWERFIRST		0x0003
#define MTP_SCANTYPE_FIELDSINGLEUPPERFIRST		0x0004
#define MTP_SCANTYPE_FIELDSINGLELOWERFIRST		0x0005
#define MTP_SCANTYPE_MIXEDINTERLACE			0x0006
#define MTP_SCANTYPE_MIXEDINTERLACEANDPROGRESSIVE	0x0007

/* Selected Audio Wave Formats */
#define MTP_WAVEFORMAT_UNKNOWN				0x0000
#define MTP_WAVEFORMAT_PCM				0x0001
#define MTP_WAVEFORMAT_ADPCM				0x0002
#define MTP_WAVEFORMAT_IEEEFLOAT			0x0003
#define MTP_WAVEFORMAT_DTS				0x0008
#define MTP_WAVEFORMAT_DRM				0x0009
#define MTP_WAVEFORMAT_WMSP2				0x000B
#define MTP_WAVEFORMAT_GSM610				0x0031
#define MTP_WAVEFORMAT_MSNAUDIO				0x0032
#define MTP_WAVEFORMAT_MPEG				0x0050
#define MTP_WAVEFORMAT_MPEGLAYER3			0x0055
#define MTP_WAVEFORMAT_MSAUDIO1				0x0160
#define MTP_WAVEFORMAT_MSAUDIO2				0x0161
#define MTP_WAVEFORMAT_MSAUDIO3				0x0162
#define MTP_WAVEFORMAT_WMAUDIOLOSSLESS			0x0163
#define MTP_WAVEFORMAT_WMASPDIF				0x0164
#define MTP_WAVEFORMAT_AAC				0xA106
#define MTP_WAVEFORMAT_AMR_WB				0xA104
#define MTP_WAVEFORMAT_RAW_AAC1				0x00FF
#define MTP_WAVEFORMAT_MPEG_HEAAC			0x1610


/*
 * Check Supported codec on Device
 * Check Registered name on this site
 * http://msdn.microsoft.com/en-us/library/aa904731.aspx
 * Convert the name using this macro GST_MAKE_FOURCC(a, b, c, d)
 */
#define MTP_VIDEOFOURCC_UNKNOWN			0
#define MTP_VIDEOFOURCC_MP42			0x3234504D
#define MTP_VIDEOFOURCC_MP43			0x3334504D
#define MTP_VIDEOFOURCC_WMV1			0x31564D57
#define MTP_VIDEOFOURCC_WMV2			0x32564D57
#define MTP_VIDEOFOURCC_WMV3			0x33564D57
#define MTP_VIDEOFOURCC_DIVX			0x58564944
#define MTP_VIDEOFOURCC_XVID			0x44495658
#define MTP_VIDEOFOURCC_M4S2			0x3253344D
#define MTP_VIDEOFOURCC_MP4V			0x5634504D
#define MTP_VIDEOFOURCC_h264			0x34363268
#define MTP_VIDEOFOURCC_H263			0x33363268
#define MTP_VIDEOFOURCC_AVC1			0x31435641
#define MTP_VIDEOFOURCC_H264			0x34363248
#define MTP_VIDEOFOURCC_X264			0x34363258
#define MTP_VIDEOFOURCC_N264			0x34363278

/* BIT RATE */
#define MTP_MIN_VIDEO_BITRATE			0x0FA0
#define MTP_MAX_VIDEO_BITRATE			0x1312D00

/* FPS */
#define MTP_MIN_VIDEO_FPS			0
#define MTP_MAX_VIDEO_FPS			0x7652

#define MTP_VIDEO_HEIGHT_WIDTH_INTERVAL		0x2
#define MTP_AUDIO_SAMPLE_RATE_INTERVAL		0x19

/*
 * USB class-specific requests
 */
#define USB_PTPREQUEST_TYPE_OUT			0x21	/* Host to Device */
#define USB_PTPREQUEST_TYPE_IN			0xA1	/* Device to Host */
#define USB_PTPREQUEST_CANCELIO			0x64	/* Cancel request */
#define USB_PTPREQUEST_GETEVENT			0x65	/* Get extened event data */
#define USB_PTPREQUEST_RESET			0x66	/* Reset Device */
#define USB_PTPREQUEST_GETSTATUS		0x67	/* Get Device Status */

#define USB_PTPCANCELIO_ID			0x4001
#define USB_PTPREQUEST_CANCELIO_SIZE		6

#define MAX_PTP_STRING_CHARS			255
#define MAX_PTP_TIME_STRING_CHARS		20	/* eg: 20050526T171236 */

/*
 * Enumerated type that defines the data witin the PTP array.
 * Defines four types to be used with the PTP array.  The types include
 * unsigned 8-bit, unsigned 16-bit, unsigned 32-bit, and pointers.
 */
typedef enum {
	UINT8_TYPE,
	UINT16_TYPE,
	UINT32_TYPE,
	PTR_TYPE,
	UINT128_TYPE
} data_type_t;

/*
 * brief A PTP array structure.
 * The PTP array structure contains a variable length of data defined by the
 * type field.
 */
typedef struct {
	data_type_t type;
	mtp_uint32 arr_size;
	mtp_uint32 num_ele;
	void *array_entry;
} ptp_array_t;

typedef struct {
	mtp_word year;
	mtp_word month;
	mtp_word day_of_week;
	mtp_word day;
	mtp_word hour;
	mtp_word minute;
	mtp_word second;
	mtp_word millisecond;
} system_time_t;

/*
 * brief The PTP string structure.
 * The PTP string structure contains a Unicode string (16-bit) that is limited
 * to MAX_PTP_STRING_CHARS in length.  The default string length is defined as
 * 255 including the NUL terminating character.
 */
typedef struct {
	/* Num of chars in string including the NUL */
	mtp_uchar num_chars;
	/* Holds actual Unicode string with 2 bytes chars,'\0' terminated*/
	mtp_wchar str[MAX_PTP_STRING_CHARS];
} ptp_string_t;

typedef struct {
	/* Num of chars in string including the NUL */
	mtp_uchar num_chars;
	/* Holds actual Unicode string with 2 bytes chars,'\0' terminated*/
	mtp_wchar str[MAX_PTP_TIME_STRING_CHARS];
} ptp_time_string_t;

#endif /* _PTP_DATACODES_H_ */
