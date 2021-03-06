//
//  UMGSMMAP_ExternalClient.h
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
//

#import <ulibasn1/ulibasn1.h>
#import "UMGSMMAP_asn1_protocol.h"

#import "UMGSMMAP_LCSClientExternalID.h"
#import "UMGSMMAP_GMLC_Restriction.h"
#import "UMGSMMAP_NotificationToMSUser.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_ExternalClient : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_LCSClientExternalID *clientIdentity;
	UMGSMMAP_GMLC_Restriction *gmlc_Restriction;
	UMGSMMAP_NotificationToMSUser *notificationToMSUser;
	UMGSMMAP_ExtensionContainer *extensionContainer;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_LCSClientExternalID *clientIdentity;
@property(readwrite,strong)	UMGSMMAP_GMLC_Restriction *gmlc_Restriction;
@property(readwrite,strong)	UMGSMMAP_NotificationToMSUser *notificationToMSUser;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;


- (void)processBeforeEncode;
- (UMGSMMAP_ExternalClient *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
