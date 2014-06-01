//
//  LibingRoomController.h
//  Libing
//
//  Created by tarunon on 2014/04/22.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LibingViewController.h"
#import "LibingRoomPreferences.h"
#import "RoomController.h"
#import "WebContentSearchBar.h"
#import "AgentEncodeSelector.h"
#import "AdBlockSelector.h"
#import "ShakeActivityViewController.h"
#import "PopupBalloon.h"
#import "HistoryNavigationController.h"
#import "DownloadNavigationController.h"
#import "SettingsNavigationController.h"
#import "LogManager.h"

@interface LibingRoomController : RoomController <RoomControllerDelegate, LibingViewControllerDelegate, WebContentSearchDelegate, AgentEncodeSelectorDelegate, AdBlockSelectorDelegate, ShakeActivityDelegate, DownloadControllerDelegate> {
    NSString *_callbackSource, *_callbackURL, *_prebackBookmarklet, *_loadedSuggest;
    NSArray *_suggests;
    NSMutableArray *_searchedBookmarks;
    UIBarButtonItem *_atokBarButton;
}

@property (nonatomic) PopupBalloon *balloon;
@property (nonatomic) WebContentSearchBar *searchBar;
@property (nonatomic) LibingRoomPreferences *preferences;

- (LibingViewController *)currentViewController;
- (void)checkPasteBoard;

@end
