//
//  ABSemanticsKey.h
//  AirBridge
//
//  Created by WOF on 2020/09/24.
//  Copyright © 2020 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABSemanticsKey : NSObject

@property (class, nonatomic, readonly) NSString* products;
@property (class, nonatomic, readonly) NSString* transactionID;
@property (class, nonatomic, readonly) NSString* inAppPurchased;
@property (class, nonatomic, readonly) NSString* cartID;
@property (class, nonatomic, readonly) NSString* query;
@property (class, nonatomic, readonly) NSString* productListID;
@property (class, nonatomic, readonly) NSString* currency;
@property (class, nonatomic, readonly) NSString* totalValue;
@property (class, nonatomic, readonly) NSString* totalQuantity;

@end

NS_ASSUME_NONNULL_END
