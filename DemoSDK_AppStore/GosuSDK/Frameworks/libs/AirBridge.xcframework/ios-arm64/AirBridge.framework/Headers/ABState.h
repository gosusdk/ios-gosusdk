//
//  ABSetting.h
//  AirBridge
//
//  Created by WOF on 18/06/2019.
//  Copyright © 2019 ab180. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AirBridge/ABUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABState : NSObject

// MARK: - General
- (void)setUser:(ABUser *) user;
- (void)setUserID:(NSString *)ID;
- (void)setUserEmail:(NSString *)email;
- (void)setUserPhone:(NSString *)phone;

- (void)setSDKDevelopmentPlatform:(NSString *)platform;

// MARK: - Alias
- (void)setUserAlias:(NSDictionary<NSString *, NSString *> *)alias;
- (void)addUserAliasWithKey:(NSString *)key value:(NSString *)value;
- (void)removeUserAlias:(NSString *)key;
- (void)clearUserAlias;

// MARK: - Attribute
- (void)setUserAttributes:(NSDictionary<NSString *, NSObject *> *)attributes;
- (void)addUserAttributesWithKey:(NSString *)key value:(NSObject *)value;
- (void)removeUserAttributes:(NSString *)key;
- (void)clearUserAttributes;

// MARK: - Device
- (void)addDeviceAliasWithKey:(NSString *)key value:(NSString *)value DEPRECATED_MSG_ATTRIBUTE("Use setDeviceAlias(key:value:) instead.");
- (void)setDeviceAlias:(NSDictionary<NSString *, NSString *> *)alias  DEPRECATED_MSG_ATTRIBUTE("Use setDeviceAlias(key:value:) instead.");
- (void)setDeviceAliasWithKey:(NSString *)key value:(NSString *)value NS_SWIFT_NAME(setDeviceAlias(key:value:));
- (void)removeDeviceAliasWithKey:(NSString *)key                      NS_SWIFT_NAME(removeDeviceAlias(key:));
- (void)clearDeviceAlias;

@end

NS_ASSUME_NONNULL_END
