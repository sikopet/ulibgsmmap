//
//  UMGSMMAP_SIWFSSignallingModifyRes.m
//  ulibgsmmap
//
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import "UMGSMMAP_SIWFSSignallingModifyRes.h"

@implementation UMGSMMAP_SIWFSSignallingModifyRes


@synthesize	operationName;
@synthesize	chosenChannel;
@synthesize	extensionContainer;


- (void) processBeforeEncode
{
	[super processBeforeEncode];
	[asn1_tag setTagIsConstructed];
	asn1_list = [[NSMutableArray alloc]init];
	if(chosenChannel)
	{
		chosenChannel.asn1_tag.tagNumber = 0;
		chosenChannel.asn1_tag.tagClass = UMASN1Class_ContextSpecific;
		[asn1_list addObject:chosenChannel];
	}
	if(extensionContainer)
	{
		extensionContainer.asn1_tag.tagNumber = 1;
		extensionContainer.asn1_tag.tagClass = UMASN1Class_ContextSpecific;
		[asn1_list addObject:extensionContainer];
	}
}


- (UMGSMMAP_SIWFSSignallingModifyRes *) processAfterDecodeWithContext:(id)context
{
	int p=0;
	UMASN1Object *o = [self getObjectAtPosition:p++];
	if((o) && (o.asn1_tag.tagNumber == 0) && (o.asn1_tag.tagClass == UMASN1Class_ContextSpecific))
	{
		chosenChannel = [[UMGSMMAP_ExternalSignalInfo alloc]initWithASN1Object:o context:context];
		o = [self getObjectAtPosition:p++];
	}
	if((o) && (o.asn1_tag.tagNumber == 1) && (o.asn1_tag.tagClass == UMASN1Class_ContextSpecific))
	{
		extensionContainer = [[UMGSMMAP_ExtensionContainer alloc]initWithASN1Object:o context:context];
		o = [self getObjectAtPosition:p++];
	}
	while(o)
	{
        /* ... */
        o = [self getObjectAtPosition:p++];
    }
	return self;
}

- (NSString *) objectName
{
	return @"SIWFSSignallingModifyRes";
}
- (id) objectValue
{
	UMSynchronizedSortedDictionary *dict = [[UMSynchronizedSortedDictionary alloc]init];
	if(chosenChannel)
	{
		dict[@"chosenChannel"] = chosenChannel.objectValue;
	}
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

