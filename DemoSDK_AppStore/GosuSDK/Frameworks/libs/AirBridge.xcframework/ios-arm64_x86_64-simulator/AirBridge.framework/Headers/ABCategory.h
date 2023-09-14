//
//  ABCategory.h
//  AirBridge
//
//  Created by WOF on 2021/01/26.
//  Copyright © 2021 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABCategory : NSObject

@property (class, nonatomic, readonly) NSString* signIn;
@property (class, nonatomic, readonly) NSString* signUp;
@property (class, nonatomic, readonly) NSString* signOut;
@property (class, nonatomic, readonly) NSString* viewHome;
@property (class, nonatomic, readonly) NSString* viewProductList;
@property (class, nonatomic, readonly) NSString* viewSearchResult;
@property (class, nonatomic, readonly) NSString* viewProductDetail;
@property (class, nonatomic, readonly) NSString* addToCart;
@property (class, nonatomic, readonly) NSString* purchase;

@end

NS_ASSUME_NONNULL_END
