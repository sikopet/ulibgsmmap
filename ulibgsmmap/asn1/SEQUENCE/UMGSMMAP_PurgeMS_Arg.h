//
//  UMGSMMAP_PurgeMS_Arg.h
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
//

#import <ulibasn1/ulibasn1.h>
#import "UMGSMMAP_asn1_protocol.h"

#import "UMGSMMAP_IMSI.h"
#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_PurgeMS_Arg : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_IMSI *imsi;
	UMGSMMAP_ISDN_AddressString *vlr_Number;
	UMGSMMAP_ISDN_AddressString *sgsn_Number;
	UMGSMMAP_ExtensionContainer *extensionContainer;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_IMSI *imsi;
@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *vlr_Number;
@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *sgsn_Number;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;


- (void)processBeforeEncode;
- (UMGSMMAP_PurgeMS_Arg *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
