//
//  ABEvent.h
//  AirBridge
//
//  Created by donutt on 2017. 8. 8..
//  Copyright © 2017년 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AirBridge/ABEvent.h>
#import <AirBridge/ABSemanticAttributes.h>

@interface ABInAppEvent : ABEvent 

- (instancetype)init;

- (void)setCategory:(NSString*)category;
- (void)setAction:(NSString*)action;
- (void)setLabel:(NSString*)label;
- (void)setValue:(NSNumber*)value;
- (void)setCustoms:(NSDictionary<NSString*, id>*)customs;
- (void)setSemantics:(NSDictionary<NSString*, id>*)semantics;
- (void)setSemanticAttributes:(ABSemanticAttributes*)semanticAttributes __deprecated_msg("use setSemantics instead");

@end
