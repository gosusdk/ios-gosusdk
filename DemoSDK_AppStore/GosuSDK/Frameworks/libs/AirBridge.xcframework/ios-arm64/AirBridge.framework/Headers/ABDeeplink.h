//
//  ABDeeplink.h
//  AirBridge
//
//  Created by WOF on 06/09/2019.
//  Copyright © 2019 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AirBridge/ABError.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABDeeplink : NSObject

- (BOOL)isAirbridgeDeeplink:(nullable NSURL*)url;

- (void)handleUserActivity:(NSUserActivity *)userActivity;

- (void)handleUserActivity:(NSUserActivity *)userActivity
                    onDone:(nullable void (^)(NSString *deeplink))onDone;

- (void)handleUserActivity:(NSUserActivity *)userActivity
                    onDone:(nullable void (^)(NSString *deeplink))onDone
                   onError:(nullable void (^)(NSError *error))onError;

- (void)handleUniversalLink:(NSURL*)link __deprecated_msg("use handleUserActivity instead");
- (void)handleUniversalLink:(NSURL*)link
                      onDone:(nullable void (^)(NSString* deeplink))onDone __deprecated_msg("use handleUserActivity instead");
- (void)handleUniversalLink:(NSURL*)link
                      onDone:(nullable void (^)(NSString* deeplink))onDone
                     onError:(nullable void (^)(NSError* error))onError __deprecated_msg("use handleUserActivity instead");

- (void)handleURLSchemeDeeplink:(NSURL*)url;
- (void)handleURLSchemeDeeplink:(NSURL*)url
                          onDone:(nullable void (^)(NSString* deeplink))onDone;

- (void)handleNotificationDeeplink:(NSURL*)url;

/* set callback */
- (void)setDeeplinkCallback:(void (^)(NSString* deeplink))callback;
- (void)setDeferredDeeplinkCallback:(void (^)(NSString* deeplink))callback;

/* set option */
- (void)setHandleTrackingLinkTimeout:(uint64_t)timeout;

@end

@interface ABDeeplinkError : ABError

+ (ABDeeplinkError*) noDeeplink;

@end

NS_ASSUME_NONNULL_END
