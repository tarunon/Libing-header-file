//
//  RoomPreferences.h
//  Libing
//
//  Created by tarunon on 2014/04/03.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RoomPreferences : NSObject {
    NSUserDefaults *_defaults;
}

@property (nonatomic) NSInteger tabIndex;
@property (nonatomic) NSString *firstMenuTitle;
@property (nonatomic) NSArray *viewControllerHistories, *searchLogs;
@property (nonatomic) BOOL showStatusBar, switchingTabs, tripleTap, screenBottoms, iCloudSync;

+ (RoomPreferences *)sharedPreferences;
+ (void)setSharedPreferences:(RoomPreferences *)sharedPreferences;
- (void)initialize;
- (void)save;

@end
