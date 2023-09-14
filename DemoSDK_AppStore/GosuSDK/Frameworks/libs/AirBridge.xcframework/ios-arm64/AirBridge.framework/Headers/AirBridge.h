//
//  AB.h
//  DLActivateTester
//
//  Created by TehranSlippers on 7/16/15.
//  Copyright © 2015 TehranSlippers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AirBridge/ABState.h>
#import <AirBridge/ABPlacement.h>
#import <AirBridge/ABDeeplink.h>
#import <AirBridge/ABWebInterface.h>
#import <AirBridge/ABSetting.h>

#import <AirBridge/ABLogLevel.h>

@interface AirBridge : NSObject

/* state */
/**
 *  state return instance of ABState which can modify user-information.
 */
+ (ABState*)state;

/* placement */
/**
 *  placement return instance of ABPlacement which can open trackingLink.
 */
+ (ABPlacement*)placement;

/* deeplink */
/**
 *  deeplink return instance of ABDeeplink which can get deeplink from trackingLink.
 */
+ (ABDeeplink*)deeplink;

+ (ABSetting*)setting;

+ (ABWebInterface*)webInterface;


/* instance */
/**
 *  instance return singleton of AirBridge
 */
+ (AirBridge*)instance;

/**
 *  getInstance initialize AirBridge.
 *
 *  @discussion Install or Open Event is sent by this method.
 *
 *              Should be called on application:didFinishLaunchingWithOptions:
 *
 *  @param      appToken        can find it on dashboard
 *  @param      appName         can find it on dashboard
 *  @param      launchOptions   can get it from caller's paramemter
 */
+ (AirBridge*)getInstance:(NSString*)appToken appName:(NSString*)appName withLaunchOptions:(NSDictionary*)launchOptions;

+ (void) registerPushToken:(NSData*)pushToken;


/* airbridge options */
+ (void)setLogLevel:(ABLogLevel) level;

/* option */
/**
 *  isUserInfoHashed is state whether SDK hash user-information before send it to server.
 *
 *  @discussion default value is YES
 */
+ (BOOL)isUserInfoHashed;
+ (void)setIsUserInfoHashed:(BOOL)enable;

/**
 *  autoStartTrackingEnabled is state whether SDK automatically start tracking.
 *
 *  @discussion default value is YES
 */
+ (BOOL) autoStartTrackingEnabled;
+ (void) setAutoStartTrackingEnabled:(BOOL)enable;

+ (BOOL) resetEventBufferEnabled;
+ (void) setResetEventBufferEnabled:(BOOL)enable;

+ (void) startTracking;

/// The methods of 'enableSDK' and 'disableSDK' serve to bring to a halt and resume all functionalities, respectively. It is advised to make use of the
/// 'autoStartTrackingEnabled' option before creating the instance of Airbridge for a more refined experience.
+ (BOOL)isSDKEnabled;
+ (void)enableSDK;
+ (void)disableSDK;
+ (void)setSDKEnabled:(BOOL)enable;

/**
 * sdkSignatureSecret enable sdk signature feature that protect airbridge sdk from sdk spoofing
 */

+ (void)setSDKSignatureSecretWithID:(NSString*)identifier
                             secret:(NSString*)string NS_SWIFT_NAME(setSDKSignatureSecret(id:secret:));

/**
 *  isTrackAirbridgeDeeplinkOnly whether SDK track airbridge-deeplink only
 *
 *  @discussion default value is NO
 */
+ (BOOL)isTrackAirbridgeDeeplinkOnly;
+ (void)setIsTrackAirbridgeDeeplinkOnly:(BOOL)enable;
/**
 *  isFacebookDeferredAppLinkEnabled fetch deferred app link from Facebook SDK
 *
 *  @discussion default value is NO
 */
+ (BOOL) isFacebookDeferredAppLinkEnabled;
+ (void) setIsFacebookDeferredAppLinkEnabled:(BOOL)enable;

/**
 *  setSessionTimeout set time-duration of session.
 *
 *  @discussion time-unit is millisecond
 */
+ (void)setSessionTimeout:(NSInteger)msec;


/* device */
/**
 *  deviceUUID return Device-Unique-Indentifier of AirBridge
 *
 *  @discussion It's format is UUID4
 */
+ (NSString*)deviceUUID;
/**
 *  isLimitADTracking return state of device's Limit-AD-Tracking
 */
+ (BOOL)isLimitADTracking;

@end
