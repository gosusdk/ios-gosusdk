//
//  ABError.h
//  AirBridge
//
//  Created by WOF on 2022/05/03.
//  Copyright © 2022 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ABErrorCodeHTTPError,
} ABErrorCode;

@interface ABError : NSError

@end

NS_ASSUME_NONNULL_END
