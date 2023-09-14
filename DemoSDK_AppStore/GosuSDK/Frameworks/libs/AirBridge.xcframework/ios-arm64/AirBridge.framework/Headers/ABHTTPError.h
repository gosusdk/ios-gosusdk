//
//  ABHTTPError.h
//  AirBridge
//
//  Created by WOF on 2022/05/03.
//  Copyright © 2022 ab180. All rights reserved.
//

#import <AirBridge/ABError.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABHTTPError : ABError

@property int32_t responseCode;
@property NSString* responseMessage;

+ (instancetype) code:(NSInteger)code message:(NSString*)message;

@end

NS_ASSUME_NONNULL_END
