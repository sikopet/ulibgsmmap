//
//  UMGSMMAP_UnknownOrUnreachableLCSClient_Param.m
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
//

#import "UMGSMMAP_UnknownOrUnreachableLCSClient_Param.h"

@implementation UMGSMMAP_UnknownOrUnreachableLCSClient_Param


@synthesize	operationName;
@synthesize	extensionContainer;


- (void) processBeforeEncode
{
	[super processBeforeEncode];
	[asn1_tag setTagIsConstructed];
	asn1_list = [[NSMutableArray alloc]init];
	if(extensionContainer)
	{
		[asn1_list addObject:extensionContainer];
	}
}


- (UMGSMMAP_UnknownOrUnreachableLCSClient_Param *) processAfterDecodeWithContext:(id)context
{
	[self setMagic:@"UMGSMMAP_UnknownOrUnreachableLCSClient_Param"];
	int p=0;
	UMASN1Object *o = [self getObjectAtPosition:p++];
	if(o)
	{
		extensionContainer = [[UMGSMMAP_ExtensionContainer alloc]initWithASN1Object:o context:context];
		o = [self getObjectAtPosition:p++];
	}
	while(o)
	{
	}
	return self;
}

- (NSString *) objectName
{
	return @"UnknownOrUnreachableLCSClient-Param";
}
- (id) objectValue
{
	UMSynchronizedSortedDictionary *dict = [[UMSynchronizedSortedDictionary alloc]init];
	if(extensionContainer)
	{
		dict[@"extensionContainer"] = extensionContainer.objectValue;
	}
	return dict;
}

- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context
{
    return self;
}


@end

