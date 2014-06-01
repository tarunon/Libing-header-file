//
//  LibingRoomPreferences.h
//  Libing
//
//  Created by tarunon on 2014/04/26.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomPreferences.h"

@interface LibingRoomPreferences : RoomPreferences

@property (nonatomic) BOOL additionalView, inertialScroll, normalLeft, normalRight, normalBottom, mediaPreview, localBrowser, dismissDelete, downloadAccelerator, monitorClipboard, displayNotification, saveFavicon, hideAds, autoFill, sendLogs, handSide, sendLaunch;
@property (nonatomic) NSInteger rotationLock, cookieMode;
@property (nonatomic) CGFloat oppositeDirection, scrollSpeed;
@property (nonatomic) NSString *shareSentence, *homepage, *loadedURL;
@property (nonatomic) NSArray *activityButtons, *blockHosts, *blockCookies, *userAgents, *agentNames, *textEncodings, *webCookie;

+ (LibingRoomPreferences *)sharedPreferences;

@end
