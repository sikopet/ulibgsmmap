//
//  UMGSMMAP_Ext_ForwFeature.h
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
//

#import <ulibasn1/ulibasn1.h>
#import "UMGSMMAP_asn1_protocol.h"

#import "UMGSMMAP_Ext_BasicServiceCode.h"
#import "UMGSMMAP_Ext_SS_Status.h"
#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_ISDN_SubaddressString.h"
#import "UMGSMMAP_Ext_ForwOptions.h"
#import "UMGSMMAP_Ext_NoRepCondTime.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_Ext_ForwFeature : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_Ext_BasicServiceCode *basicService;
	UMGSMMAP_Ext_SS_Status *ss_Status;
	UMGSMMAP_ISDN_AddressString *forwardedToNumber;
	UMGSMMAP_ISDN_SubaddressString *forwardedToSubaddress;
	UMGSMMAP_Ext_ForwOptions *forwardingOptions;
	UMGSMMAP_Ext_NoRepCondTime *noReplyConditionTime;
	UMGSMMAP_ExtensionContainer *extensionContainer;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_Ext_BasicServiceCode *basicService;
@property(readwrite,strong)	UMGSMMAP_Ext_SS_Status *ss_Status;
@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *forwardedToNumber;
@property(readwrite,strong)	UMGSMMAP_ISDN_SubaddressString *forwardedToSubaddress;
@property(readwrite,strong)	UMGSMMAP_Ext_ForwOptions *forwardingOptions;
@property(readwrite,strong)	UMGSMMAP_Ext_NoRepCondTime *noReplyConditionTime;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;


- (void)processBeforeEncode;
- (UMGSMMAP_Ext_ForwFeature *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
