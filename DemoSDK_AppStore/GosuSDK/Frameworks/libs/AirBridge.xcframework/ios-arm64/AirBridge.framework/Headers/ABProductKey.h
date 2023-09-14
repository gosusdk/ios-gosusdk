//
//  ABProductKey.h
//  AirBridge
//
//  Created by WOF on 2020/09/25.
//  Copyright © 2020 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABProductKey : NSObject

@property (class, nonatomic, readonly) NSString* productID;
@property (class, nonatomic, readonly) NSString* name;
@property (class, nonatomic, readonly) NSString* price;
@property (class, nonatomic, readonly) NSString* currency;
@property (class, nonatomic, readonly) NSString* position;
@property (class, nonatomic, readonly) NSString* quantity;

@end

NS_ASSUME_NONNULL_END
