//
//  ABSemanticAttributes.h
//  AirBridge
//
//  Created by WOF on 04/03/2019.
//  Copyright © 2019 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AirBridge/ABData.h>
#import <AirBridge/ABProduct.h>

@interface ABSemanticAttributes : NSObject <ABData>

@property (nonatomic, strong) NSArray<ABProduct*>* products;
@property (nonatomic, strong) NSString* transactionID;
@property (nonatomic, strong) NSNumber* inAppPurchased;
@property (nonatomic, strong) NSString* cartID;
@property (nonatomic, strong) NSString* query;
@property (nonatomic, strong) NSString* productListID;
@property (nonatomic, strong) NSString* currency;
@property (nonatomic, strong) NSNumber* totalValue;

- (NSDictionary<NSString*, NSObject*>*) toDictionary;

@end
