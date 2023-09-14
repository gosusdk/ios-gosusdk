//
//  ABInstallEvent.h
//  AirBridge
//
//  Created by WOF on 06/03/2019.
//  Copyright © 2019 ab180. All rights reserved.
//

#import <AirBridge/ABEvent.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABInstallEvent : ABEvent

- (instancetype)init;
- (void)setAppleSearchAds:(NSDictionary*)appleSearchAds;
- (void)setAppleSearchAdsToken:(NSString*)appleSearchAdsToken;

@end

NS_ASSUME_NONNULL_END
