//
//  UMGSMMAP_SubscriberInfo.h
//  ulibgsmmap
//
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import <ulibasn1/ulibasn1.h>
#import "UMGSMMAP_asn1_protocol.h"

#import "UMGSMMAP_LocationInformation.h"
#import "UMGSMMAP_SubscriberState.h"
#import "UMGSMMAP_ExtensionContainer.h"
#import "UMGSMMAP_LocationInformationGPRS.h"
#import "UMGSMMAP_PS_SubscriberState.h"
#import "UMGSMMAP_IMEI.h"
#import "UMGSMMAP_MS_Classmark2.h"
#import "UMGSMMAP_GPRSMSClass.h"
#import "UMGSMMAP_MNPInfoRes.h"
#import "UMGSMMAP_IMS_VoiceOverPS_SessionsInd.h"
#import "UMGSMMAP_ASNTime.h"
#import "UMGSMMAP_Used_RAT_Type.h"
#import "UMGSMMAP_LocationInformationEPS.h"
#import "UMGSMMAP_ASNTimeZone.h"
#import "UMGSMMAP_DaylightSavingTime.h"

@interface UMGSMMAP_SubscriberInfo : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_LocationInformation *locationInformation;
	UMGSMMAP_SubscriberState *subscriberState;
	UMGSMMAP_ExtensionContainer *extensionContainer;
	UMGSMMAP_LocationInformationGPRS *locationInformationGPRS;
	UMGSMMAP_PS_SubscriberState *ps_SubscriberState;
	UMGSMMAP_IMEI *imei;
	UMGSMMAP_MS_Classmark2 *ms_Classmark2;
	UMGSMMAP_GPRSMSClass *gprs_MS_Class;
	UMGSMMAP_MNPInfoRes *mnpInfoRes;
	UMGSMMAP_IMS_VoiceOverPS_SessionsInd *imsVoiceOverPS_SessionsIndication;
	UMGSMMAP_ASNTime *lastUE_ActivityTime;
	UMGSMMAP_Used_RAT_Type *lastRAT_Type;
	UMGSMMAP_PS_SubscriberState *eps_SubscriberState;
	UMGSMMAP_LocationInformationEPS *locationInformationEPS;
	UMGSMMAP_ASNTimeZone *timeZone;
	UMGSMMAP_DaylightSavingTime *daylightSavingTime;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_LocationInformation *locationInformation;
@property(readwrite,strong)	UMGSMMAP_SubscriberState *subscriberState;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;
@property(readwrite,strong)	UMGSMMAP_LocationInformationGPRS *locationInformationGPRS;
@property(readwrite,strong)	UMGSMMAP_PS_SubscriberState *ps_SubscriberState;
@property(readwrite,strong)	UMGSMMAP_IMEI *imei;
@property(readwrite,strong)	UMGSMMAP_MS_Classmark2 *ms_Classmark2;
@property(readwrite,strong)	UMGSMMAP_GPRSMSClass *gprs_MS_Class;
@property(readwrite,strong)	UMGSMMAP_MNPInfoRes *mnpInfoRes;
@property(readwrite,strong)	UMGSMMAP_IMS_VoiceOverPS_SessionsInd *imsVoiceOverPS_SessionsIndication;
@property(readwrite,strong)	UMGSMMAP_ASNTime *lastUE_ActivityTime;
@property(readwrite,strong)	UMGSMMAP_Used_RAT_Type *lastRAT_Type;
@property(readwrite,strong)	UMGSMMAP_PS_SubscriberState *eps_SubscriberState;
@property(readwrite,strong)	UMGSMMAP_LocationInformationEPS *locationInformationEPS;
@property(readwrite,strong)	UMGSMMAP_ASNTimeZone *timeZone;
@property(readwrite,strong)	UMGSMMAP_DaylightSavingTime *daylightSavingTime;


- (void)processBeforeEncode;
- (UMGSMMAP_SubscriberInfo *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
