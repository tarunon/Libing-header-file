//
//  RoomViewController.h
//  Room
//
//  Created by tarunon on 2014/03/26.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

// For switch and management some ViewControllers.
// This class take the UIScrollViewDelegate(UITableViewDelegate also). (I plan to fix it)
// Supported Viewcontrollers life cycle, local storage, bookmark, and URL based operating.
// ViewController that can interpret a URL is good for this framework.

#import <UIKit/UIKit.h>
#import "AddressBar.h"
#import "SwitchScrollView.h"
#import "PullActionView.h"
#import "CustomSwipeGestureRecognizer.h"
#import "KeyboardShortcutsController.h"
#import "SBNotificationController.h"
#import "RoomPreferences.h"
#import "RoomMenuBarController.h"
#import "BookmarkNavigationController.h"

@protocol RoomControllerDelegate;

@interface RoomController : UIViewController <SwitchScrollViewDelegate, AddressBarDelegate, KeyboardShotcutsControllerDelegate, BookmarkControllerDelegate, PullActionViewDelegate, UIScrollViewDelegate, UIActionSheetDelegate, UITabBarControllerDelegate, UINavigationControllerDelegate, UIGestureRecognizerDelegate> {
    BOOL _statusBarHidden, _arrowKeyPressing, _insetAdjusting, _hiddenSwitching;
    CGFloat _tmpOffsetY;
    CGRect _tmpAddressFrame;
    UIViewController *_currentViewController;
    NSMutableArray *_viewControllers, *_closedViewControllerHistories;
}

@property (nonatomic) id<RoomControllerDelegate> delegate;

@property (nonatomic) AddressBar *addressBar;
@property (nonatomic) SwitchScrollView *switchView;
@property (nonatomic) PullActionView *pullActionView;
@property (nonatomic) NSArray *viewControllers;
@property (nonatomic) CustomSwipeGestureRecognizer *command;
@property (nonatomic) UIScreenEdgePanGestureRecognizer *showMenuGesture;
@property (nonatomic) KeyboardShortcutsController *keyboard;
@property (nonatomic) SBNotificationController *notification;
@property (nonatomic) BookmarkManager *bookmark;
@property (nonatomic) RoomPreferences *preferences;
@property (nonatomic) UIInterfaceOrientation supportedInterfaceOrientation;
@property (nonatomic) RoomMenuBarController *menuController;

// Show/hide user intarfaces.
- (void)setStatusBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setAddressBarHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setTabBarHidden:(BOOL)hidden animated:(BOOL)animated;

// Management ViewControllers.
- (void)addViewController:(UIViewController *)viewController;
- (void)insertViewController:(UIViewController *)viewController atIndex:(NSInteger)index;
- (void)repairViewController;
- (void)openViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)closeViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)closeAllViewControllerAnimated:(BOOL)animated;
- (UIViewController *)currentViewController;

// Save/restore local storage
- (void)saveViewControllers;
- (void)restoreViewControllers;

// Custom URL Scheme
- (void)executeURL:(NSURL *)URL forViewController:(UIViewController *)controller;

// InstallBookmark
- (void)installBookmark:(BookmarkBaseEntity *)bookmark withCommands:(NSArray *)commands;

@end

@protocol RoomControllerDelegate <NSObject>

@required
- (UIViewController *)roomControllerStandardViewController:(RoomController *)roomController;
- (UIViewController *)roomController:(RoomController *)roomController viewControllerForHistoryInfo:(NSDictionary *)historyInfo;
- (UIViewController *)roomController:(RoomController *)roomController viewControllerForURL:(NSURL *)URL;
- (NSDictionary *)roomController:(RoomController *)roomController historyInfoForViewController:(UIViewController *)controller;
- (void)roomController:(RoomController *)roomController loadURL:(NSURL *)URL forViewController:(UIViewController *)controller;
- (void)roomController:(RoomController *)roomController performBookmarklet:(NSString *)bookmarklet forViewController:(UIViewController *)controller;
- (void)roomController:(RoomController *)roomController executeURL:(NSURL *)URL forViewController:(UIViewController *)controller;

@optional
- (void)roomController:(RoomController *)roomController didOpenViewController:(UIViewController *)controller;
- (void)roomController:(RoomController *)roomController didCloseViewController:(UIViewController *)controller;

@end