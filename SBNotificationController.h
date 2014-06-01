//
//  SBNotificationController.h
//  Libing
//
//  Created by tarunon on 2014/03/24.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

// Notification to Statusbar or Notification Center.

#import <Foundation/Foundation.h>

@interface SBNotificationController : NSObject {
    NSMutableDictionary *_localNotifications;
    UILabel *_statusLabel;
    UIButton *_statusButton;
    NSInteger _statusCount;
    dispatch_queue_t _statusQueue;
    void(^_statusBlock)();
}

@property (nonatomic) BOOL useNotificationCenter;

+ (SBNotificationController *)sharedController;

// Show notification. Put same key, remove old notification.
- (void)showNotification:(NSString *)text forKey:(id)key withAction:(void(^)())action;
- (void)hideNotification;

// Call this method in XXXAppDelegate#application:didReceiveLocalNotification:.
- (void)receiveLocalNotification:(UILocalNotification *)notification;

@end
