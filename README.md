GosuSDK for iOS
========================

* Authentication
* Billing
* Tracking

## FEATURES
  - Login: Authenticate people with their my server ID, Google and Facebook credentials.
  - Payment IAP: Pay to buy products from in-app
  - Track Events: Track events with third parties including Appsflyer and Firebase tracking
    
## Try It Out
  - **Download the official version: [click here](https://github.com/gosusdk/ios-gosusdk/releases)**
  - GoogleService-Info.plist: send via mail
  - Install the following: App Tracking Transparency framework only available starting from Xcode 12 or later-The SDK supports iOS11+
  
## Integrate
- Embed the latest version of GosuSDK and third-party frameworks into your project.
- Additional libraries:
  - AuthenticationServices.framework
  - MediaPlayer.framework
  - MobileCoreServices.framework
  - SystemConfiguration.framework
  - MessageUI.framework
  - Accelerate.framework
  - AdSupport.framework
  - AppTrackingTransparency.framework
- Add Capabilities: Sign-in with Apple, Push Notifications
##### NOTE: For Facebook iOS SDK version 13 or later:
  - Create a Swift file with an arbitrary name, and confirm "Create Bridging Header" when prompted.
  - Enable Modules (C and Objective-C) by setting it to YES: Target --> Build Settings --> Enable Modules (C and Objective-C).
##### GRPC Framework Embed
  ![image](https://user-images.githubusercontent.com/94542020/160530360-23295245-4eb7-4f0b-b04b-cbcfee270a7e.png)

##### Configuration
- Add -ObjC, -lc++, and -lz to the 'Other Linker Flags' in your Xcode project: Main target -> Build Settings -> search for 'other linker flags.'
- Configure 'Tracking Usage Description' in your .plist file (default: info.plist).
Open it in source mode and insert the following code:
  ```xml
  <key>NSUserTrackingUsageDescription</key>
  <string>This identifier will be used to deliver personalized ads to you.</string>
  ```
- Configure 'GameClientID' in your .plist file (default: info.plist). In the <string> tag, the 'GameClientID' key will be provided privately via email:
```xml
<key>GameClientID</key>
<string>GameClientID</string>
```
- Configure 'GameClientID' in your .plist file (default: info.plist). In the <string> tag, the 'GameSdkSignature' key will be provided privately via email:
```xml
<key>GameSdkSignature</key>
<string>BundleId</string>
```
##### Configure Airbridge in your project (default info.plist)
  ```xml
    <key>AirbAppName</key>
    <string>sdkgosutest</string>
    <key>AirbAppToken</key>
    <string>d878da2af447440385fe9a4fe37b06a0</string>
```
##### Configure GoogleSignIn in your project (default info.plist)
  ** Refer [Get started with Google Sign-In for iOS](https://developers.google.com/identity/sign-in/ios/start-integrating) **
  ```xml
    <key>GIDClientID</key>
    <string>YOUR_IOS_CLIENT_ID</string>
    <key>CFBundleURLTypes</key>
    <array>
      <dict>
        <key>CFBundleURLSchemes</key>
        <array>
          <string>YOUR_DOT_REVERSED_IOS_CLIENT_ID</string>
        </array>
      </dict>
    </array>
  ```
  
##### Configure FacebookSDK in your project (default info.plist)
** Refer [Facebook get started](https://developers.facebook.com/docs/ios/getting-started#step-2---configure-your-project) **
```xml
<key>FacebookAppID</key>
<string>FacebookAppID</string>
<key>FacebookClientToken</key>
<string>CLIENT-TOKEN</string>
<key>FacebookDisplayName</key>
<string>FacebookDisplayName</string>
<key>CFBundleURLTypes</key>
<array>
  <dict>
    <key>CFBundleURLSchemes</key>
    <array>
      <string>fbFacebookAppID</string>
    </array>
  </dict>
</array>
<key>LSApplicationQueriesSchemes</key>
<array>
  <string>fbapi</string>
  <string>fbapi20130214</string>
  <string>fbapi20130410</string>
  <string>fbapi20130702</string>
  <string>fbapi20131010</string>
  <string>fbapi20131219</string>
  <string>fbapi20140410</string>
  <string>fbapi20140116</string>
  <string>fbapi20150313</string>
  <string>fbapi20150629</string>
  <string>fbapi20160328</string>
  <string>fbauth</string>
  <string>fb-messenger-share-api</string>
  <string>fbauth2</string>
  <string>fbshareextension</string>
</array>
```
* Replace APP-ID with FacebookApp ID
* In the key FacebookClientToken, replace CLIENT-TOKEN 
* In the key FacebookDisplayName, replaceAPP-NAME with the name of provided.

## Add services and SDK related resource library
1. The file Appdelegate.m configuration instructions are as follows:
   ```objectivec
    #import "GosuSDK.h"
    #import <UserNotifications/UserNotifications.h>
    @interfaceAppDelegate()<FIRMessagingDelegate, UNUserNotificationCenterDelegate>
    @end
    ```
2. Add openURL
  ```objectivec
  - (BOOL)application:(UIApplication *)application
              openURL:(NSURL *)url
              options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
      if (@available(iOS 9.0, *)) {
          BOOL handled = [[GosuDK sharedInstance] application:application openURL:url options:options];
          return handled;
      } else {
          return YES;
      }
  }
  ```
3. Add didFinishLaunchingWithOption
  ```objectivec
  - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
      //...
      [[GosuSDK sharedInstance] initSDK];
      [[GosuSDK sharedInstance] applicationDelegate:self andApplication:application didFinishLaunchingWithOptions:launchOptions];
      return YES;
  }
  ```
4. Add applicationDidBecomeActive
  ```objectivec
  - (void)applicationDidBecomeActive:(UIApplication *)application {
      NSLog(@"applicationDidBecomeActive");
      [[GosuSDK sharedInstance] applicationDidBecomeActive:application];
      application.applicationIconBadgeNumber = 0;
  }
```
5. Add applicationWillTerminate
  ```objectivec
    - (void)applicationWillTerminate:(UIApplication *)application {
        //reset owner billing had payment
        [[GosuSDK AppleIAP] terminateIAP];
    }
```
6. Registration FCM token and message
  ```objectivec
  - (void)messaging:(FIRMessaging *)messaging didReceiveRegistrationToken:(NSString *)fcmToken {
      NSLog(@"START refresh_token");
      [[FirebaseManager sharedInstance] messaging:messaging didReceiveRegistrationToken:fcmToken];
  }
  - (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
      NSLog(@"APNs Unable to register for remote notifications: %@", error);
  }
  - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [[GosuSDK sharedInstance] application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
      NSLog(@"APNs device token retrieved: %@", deviceToken);
      [[GosuSDK sharedInstance] application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
      //tracking uninstall
      [[GosuSDK GTracking] registerForRemoteNotifications:deviceToken];
  }
  - (void)application:(UIApplication *)application 
          didReceiveRemoteNotification:(NSDictionary *) userInfo {
      NSLog(@"APNs full message. %@", userInfo);
  }
  - (void)application:(UIApplication *)application 
        didReceiveRemoteNotification:(NSDictionary *) userInfo
            fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
      // Print full message.
      NSLog(@"APNs receive_message %@", userInfo);
      completionHandler(UIBackgroundFetchResultNewData);
  }
  // [START ios_10_message_handling]
  // Receive displayed notifications for iOS 10 devices.
  // Handle incoming notification messages while app is in the foreground.
  - (void)userNotificationCenter:(UNUserNotificationCenter *)center
         willPresentNotification:(UNNotification *)notification
           withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler API_AVAILABLE(ios(10.0)){
      NSDictionary *userInfo = notification.request.content.userInfo;
      // Print full message.
      [[FirebaseManager sharedInstance] showInAppMessage:userInfo];
      // Change this to your preferred presentation option
      completionHandler(UNNotificationPresentationOptionBadge);
  }
  
  // Handle notification messages after display notification is tapped by the user.
  - (void)userNotificationCenter:(UNUserNotificationCenter *)center
  didReceiveNotificationResponse:(UNNotificationResponse *)response
           withCompletionHandler:(void(^)(void))completionHandler {
    NSDictionary *userInfo = response.notification.request.content.userInfo;
      [[FirebaseManager sharedInstance] showInAppMessage:userInfo];
    completionHandler();
  }
  // [END ios_10_message_handling]
  ```
## USAGE GOSU LOGIN SDK
### Initialize configuration for GosuSDK
  ```objectivec
  //MainViewController.m
  @interface MainViewController ()<LoginDelegate, LogoutDelegate,IAPDelegate>
  @end  
  @implementation MainViewController
      - (void)viewDidLoad
      {
        [super viewDidLoad];
        [GosuSDK sharedInstance].delegate = self;
      }
      #pragma Login Delegate
      - (void)loginSuccess:(NSString *)userID andUserName:(NSString *)userName andAccessToken:(NSString *)access_token {
      }
      - (void)loginFail:(NSString *)message {
      }
      #pragma Logout Delegate
      - (void) logoutSuccess{
      }
      #pragma IAP Delegate
      - (void) IAPInitFailed:(NSString *)message andErrorCode:(NSString *)errorCode {
      }
      - (void) IAPPurchaseFailed:(NSString *)message andErrorCode:(NSString *)errorCode {
      }
      - (void) IAPCompleted:(NSString *)message{
      }
  @end
  ```
### GosuSDK Basic Functions
  ```objectivec
  //init SDK and show SignIn
  [[GosuSDK sharedInstance] initSDK];
  //init SDK
  [[GosuSDK sharedInstance] onlyInitSDK];
  //The result will return delegate.
  [[GosuSDK sharedInstance] showSignIn];
  [[GosuSDK sharedInstance] logout];
  [[GosuSDK sharedInstance] deleteAccount:^(NSDictionary<NSString *,id> *callback) {
      NSLog(@"delete account = %@",callback);
      /*
        The callback will have 2 values: success or failed
      */
  }];
  ```
### Make payments through Google Billing IAP for in-app purchases.
  ```objectivec
    NSString *productID = @"vn.devapp.pack1";
    NSString *appleSecret = @"";
    NSString *orderID = "orderID";
    NSString *orderInfo = @"Item 300 gold";
    NSString *amount = @"22000";
    NSString *server = @"22";
    NSString *roleId = @"role id";
    NSString *extraInfo = @"Extra_Info";
    IAPDataRequest *iapData = [[IAPDataRequest alloc] initWithData:_userName
          andOrderId:orderID
          andOrderInfo:orderInfo
          andServerID:server
          andAmount:amount
          andAppleProductID:productID
          andAppleShareSecrect:appleSecret
          andRoleID:roleId
          andExtraInfo:extraInfo];
    [[GosuSDK sharedInstance] showIAP:(IAPDataRequest *)iapData andMainView:self /*UIViewController*/];
    /**
    * OrderID: Partner's order number
    * OrderInfo: Item description
    * ServerID: ID of the server
    * Amount: Price of the item
    * ProductID: Item code
    * AppleShareSecrect: Empty
    * RoleID: ID of the character
    * ExtraInfo: Additional information that partners can send, which will be sent to the API to add gold after IAP payment.
    **/
  ```
### USAGE GOSU TRACKING SDK
  ```objectivec
  - (void) callGTrackingExample {
        //tracking start trial
        [[GosuSDK GTracking] trackingStartTrial];
    
        //tracking Turial Completion
        [[GosuSDK GTracking] trackingTurialCompleted];
        
        [[GosuSDK GTracking] trackingEvent:@"level_20"];
        
        [[GosuSDK GTracking] trackingEvent:[NSString stringWithFormat:@"level_%d", 20]];
        
        [[GosuSDK GTracking] doneNRU:@"server_id" andRoleId:@"role_id" andRoleName:@"role_name"];
        
        [[GosuSDK GTracking] trackingEvent:@"level_20" withValues:@{@"customerId": @"12345"}];
        
        [[GosuSDK GTracking] trackingEvent:@"user_checkinday_1"];
    }
  ```
