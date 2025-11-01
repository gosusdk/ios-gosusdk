SDK Tracking In-app events guide 
========================

* In-app events—Overview
* Lifecycle events
* Recommended In-app events in the Gaming


In-app events—Overview
------------
Recording in-app events helps analyze user behavior, assess user value (LTV), and campaign performance (ROI). When users perform actions like registration, completing tutorials, adding items to a cart, or making purchases, event data provides insights to measure KPIs.

In-app events include an event name and can have event parameters that add context and details (e.g., type of transaction, destination, revenue). Implementing in-app events is mandatory for post-installation analysis.

Lifecycle events
------------
SDK automatically tracks the following application lifecycle events:
- **Application Installed**
  - This event is tracked when the application is installed on the user's device.
- **Application Opened**
  - This event is tracked when the user opens the application.
- **Application Updated**
  - This event is tracked when the application is updated to a new version.
- **Application Backgrounded**
  - This event is tracked when the application is sent to the background.

Recommended In-app Events in the Gaming
------------
1. **Complete Registration**
   - This function tracks when a user completes the registration process.
   - Parameters:
      - `userId`: The ID of the user who completed the registration.
    ```objectivec
    [GTrackingManager completeRegistration:(NSString *)userId];
    ```
    **NOTE**: This event is already built into the SDK, you don't need to actively call it.
2. **Login**
   - This function tracks when a user logs in.
   - Parameters:
      - `userId`: The ID of the user who logged in.
      - `userName`: The username of the user.
      - `email`: The email of the user.
    ```objectivec
    [GTrackingManager login:(NSString *)userId userName:(NSString *)userName email:(NSString *)email];
    ```
    **NOTE**: This event is already built into the SDK, you don't need to actively call it.
3. **Create New Character**
    - This event tracks when a user creates a new character in the game.
    - Parameters:
        - `serverInfo`: Server information.
        - `charId`: The ID of the character.
        - `charName`: The name of the character.
    ```objectivec
    [GTrackingManager createNewCharacter:(NSString *)serverInfo charId:(NSString *)charId charName:(NSString *)charName];
    ```    
4. **Enter Game**
    - This event tracks when a user enters the game with a specific character.
    - Parameters:
        - `userId`: The ID of the user.
        - `charId`: The ID of the character.
        - `charName`: The name of the character.
        - `serverInfo`: Server information.
    ```objectivec
    [GTrackingManager enterGame:(NSString *)userId charId:(NSString *)charId charName:(NSString *)charName serverInfo:(NSString *)serverInfo];
    ``` 
5. **Start Tutorial**
    - This event tracks when a user starts the tutorial.
    - Parameters:
        - `userId`: The ID of the user.
        - `charId`: The ID of the character.
        - `charName`: The name of the character.
        - `serverInfo`: Server information.
    ```objectivec
    [GTrackingManager startTutorial:(NSString *)userId charId:(NSString *)charId charName:(NSString *)charName serverInfo:(NSString *)serverInfo];
    ```
6. **Complete Tutorial**
    - This event tracks when a user completes the tutorial.
    - Parameters:
        - `userId`: The ID of the user.
        - `charId`: The ID of the character.
        - `charName`: The name of the character.
        - `serverInfo`: Server information.
    ```objectivec
    [GTrackingManager completeTutorial:(NSString *)userId charId:(NSString *)charId charName:(NSString *)charName serverInfo:(NSString *)serverInfo];
    ```
7. **Checkout**
    - This event tracks when a user completes a checkout item.
    - Parameters:
        - `orderId`: The ID of the order.
        - `productId`: The ID of the product.
        - `amount`: The amount of the transaction.
        - `currency`: The currency of the transaction(USD/VND).
        - `customerId`: The ID of the user.
    ```objectivec
    [GTrackingManager checkout:(NSString *)orderId productId:(NSString *)productId amount:(NSString *)amount currency:(NSString *)currency customerId:(NSString *)customerId];
    ```
   **NOTE**: This event is already built into the SDK, you don't need to actively call it.
8. **Purchase**
    - This event tracks when a user makes a purchase.
    - Parameters:
        - `orderId`: The ID of the order.
        - `productId`: The ID of the product.
        - `amount`: The amount of the transaction.
        - `currency`: The currency of the transaction.
        - `customerId`: The ID of the user.
    ```objectivec
    [GTrackingManager purchase:(NSString *)orderId productId:(NSString *)productId amount:(NSString *)amount currency:(NSString *)currency customerId:(NSString *)customerId];
    ```
    - Note: This event is already built into the SDK, you don't need to actively call it.
9.  **Level Up**
    - This event tracks when a user level up.
    - Parameters:
        - `charId`: The ID of the character.
        - `serverInfo`: Server information.
        - `level`: The new level achieved by the user.
    ```objectivec
    [GTrackingManager levelUp:(NSString *)charId serverInfo:(NSString *)serverInfo level:(NSInteger)level];
    ```
10. **VIP Level**
    - This event tracks when a user achieves a VIP level.
    - Parameters:
        - `charId`: The ID of the character.
        - `serverInfo`: Server information.
        - `vipLevel`: The new VIP level achieved by the user.
    ```objectivec
    [GTrackingManager vipUp:(NSString *)charId serverInfo:(NSString *)serverInfo vipLevel:(NSInteger)vipLevel];
    ```
11. **Use Item**
    - This event tracks when a user uses an item.
    - Parameters:
        - `userId`: The ID of the user.
        - `charId`: The ID of the character.
        - `serverInfo`: Server information.
        - `itemId`: The ID of the item.
        - `quantity`: The quantity of the item used.
    ```objectivec
    [GTrackingManager useItem:(NSString *)userId charId:(NSString *)charId serverInfo:(NSString *)serverInfo itemId:(NSString *)itemId quantity:(NSInteger)quantity];
    ```
12. **Track Activity Result**
    - This event tracks the result of a user's activity.
    - Parameters:
        - `userId`: The ID of the user.
        - `charId`: The ID of the character.
        - `serverInfo`: The ID of the server.
        - `activityId`: The ID of the activity.
        - `activityResult`: The result of the activity.
    ```objectivec
    [GTrackingManager trackActivityResult:(NSString *)userId charId:(NSString *)charId serverInfo:(NSString *)serverInfo activityId:(NSString *)activityId activityResult:(NSString *)activityResult];
    ```
13. **Custom Event**
    - This event tracks custom events defined by the developer.
    - Parameters:
        - `eventName`: The name of the custom event.
        - `jsonObject`: A JSON object containing custom event data.
    ```objectivec
    /* example: 
        jsonObject =  {"key": "value", "key2": "value2"} }
    */
    [GTrackingManager trackCustomEvent:(NSString *)eventName jsonObject:(NSDictionary *)jsonObject];
    ```
14. **Logout Event**
    - This function tracks when a user logs out.
    - Parameters: None
    ```objectivec
    [GTrackingManager logout];
    ```
    **NOTE**: This event is already built into the SDK, you don't need to actively call it.