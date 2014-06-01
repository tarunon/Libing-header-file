//
//  LibingViewController.h
//  Libing
//
//  Created by tarunon on 2014/04/22.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "BFGestureWebView.h"
#import "ProgressCircle.h"
#import "LibingRoomProtocol.h"
#import "JS2UIWebView.h"
#import "PasswordManager.h"
#import "DownloadManager.h"
#import "BookmarkManager.h"
#import "CustomPanGestureRecognizer.h"

typedef enum {
    LibingScrollerModeInfiniteScroller,
    LibingScrollerModeNormalScroller
} LibingScrollerMode;

@protocol LibingViewControllerDelegate;

@interface LibingViewController : UIViewController <CustomWebViewDelegate, UIAlertViewDelegate, UIActionSheetDelegate, UIGestureRecognizerDelegate, MFMailComposeViewControllerDelegate> {
    JS2UIWebView *_js2WebView;
    UIAlertView *_authAlert;
    NSURLAuthenticationChallenge *_basicChallenge;
    NSURLCredential *_basicCredential;
    UIBarButtonItem *_atokBarButton;
    UIImageView *_captchaView;
    NSArray *_pasteTemp;
}

@property (nonatomic, assign) id<LibingViewControllerDelegate> delegate;
@property (nonatomic) BFGestureWebView *webView;
@property (nonatomic) ProgressCircle *circle;
@property (nonatomic) UILongPressGestureRecognizer *getLinkGestureRecognizer, *showActionGestureRecognizer;
@property (nonatomic) CustomPanGestureRecognizer *horizontalScroller, *verticalScroller;
@property (nonatomic) NSString *loadedHost;
@property (nonatomic) NSMutableSet *loadedOtherHosts, *blockedHosts;
@property (nonatomic) LibingScrollerMode leftEdge, rightEdge, bottomEdge;
@property (nonatomic) BOOL saveMemory, saveFavicon, mediaPreview, autoFill;
@property (nonatomic) CGFloat scrollSpeed, oppositeDirection;
@property (nonatomic) NSUserDefaults *defaults;

@property (nonatomic) BookmarkLeafEntity *latestUsedBookmark;

- (id)initWithHistoryInfo:(NSDictionary *)historyInfo;
- (NSDictionary *)historyInfo;
- (void)writeHistory;

- (NSString *)helprScript:(NSString *)script;
- (NSURLRequest *)refereredRequestWithURL:(NSURL *)URL;
- (void)makeMailWithURL:(NSURL *)URL;
- (void)doJavaScript:(NSString *)script;
- (void)performBookmark:(BookmarkLeafEntity *)bookmark;
- (void)performBookmarkWithCommand:(NSString *)command;
- (NSString *)outputText;
- (void)inputText:(NSString *)text;

- (void)removeValueForKey:(NSString *)key;

@end

@protocol LibingViewControllerDelegate <NSObject>

@required
- (void)libingViewController:(LibingViewController *)controller executeURL:(NSURL *)URL;
- (LibingViewController *)libingViewController:(LibingViewController *)controller openWindowName:(NSString *)windowName;
- (LibingViewController *)libingViewControllerOpenBackgroundWindow:(LibingViewController *)controller;
- (void)libingViewControllerClose:(LibingViewController *)controller;
- (void)libingViewControllerDidFinishLoad:(LibingViewController *)controller;
- (void)libingViewController:(LibingViewController *)controller failLoadWithError:(NSError *)error;
- (void)libingViewController:(LibingViewController *)controller didShowKeyBoard:(UIView *)inputView withAccessoryView:(UIView *)accessoryView;
- (NSArray *)libingViewControllerBlockHosts:(LibingViewController *)controller;
- (NSArray *)libingViewControllerBlockCookies:(LibingViewController *)controller;

@end
