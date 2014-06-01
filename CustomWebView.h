//
//  CustomWebView.h
//  Libing
//
//  Created by tarunon on 12/03/18.
//  Copyright (c) 2012年 Nobuo Saito. All rights reserved.
//


#import "CustomURLProtocol.h"
#import "CustomURLCache.h"
#import "PreviewInWebView.h"
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

typedef enum {
    CustomWebViewLoadTypeBackForward = 1 << 0,
    CustomWebViewLoadTypeLinkClick = 1 << 1
} CustomWebViewLoadType;

@protocol CustomWebViewDelegate;

@interface CustomWebView : UIWebView<UIWebViewDelegate, UIActionSheetDelegate>{
    __weak id<CustomWebViewDelegate> _delegate;
    BOOL _failed, _skipLoad, _backForwardCalled;
    NSError *_transferError;
    UIPanGestureRecognizer *_backPanGestureRecognizer, *_forwardPanGestureRecognizer;
    UIEdgeInsets contentInsetTemp;
    CustomWebViewLoadType _iframeLoadType;
}

@property (nonatomic) NSString *textEncode, *userAgent, *evaluatingScript;
@property (readonly, nonatomic) NSString *windowName;
@property (nonatomic) NSMutableArray *rotatingSheetButtons;
@property (nonatomic) NSArray *backURLs, *forwardURLs, *selectMenuItems;
@property (nonatomic) NSMutableDictionary *dataDictionary;
@property (nonatomic) NSDictionary *historyInfo;
@property (nonatomic) NSMutableURLRequest *loadingRequest;
@property (nonatomic) PreviewInWebView *preview;
@property (assign, nonatomic) id<UIActionSheetDelegate> rotatingSheetDelegate;
@property (weak, nonatomic) CustomWebView *parentWebView;
@property (nonatomic) CustomURLProtocol *transferProtocol;
@property (nonatomic) NSURLConnection *transferConnection;
@property (readonly, nonatomic) NSURLResponse *response;
@property (readonly, nonatomic) NSString *location;
@property (nonatomic) BOOL startLoading, backForwardRequested, stopedLoading, transferedLoading, nextRequestNewWindow, isPreviewTransfer, safeMode;
@property (readonly, nonatomic) BOOL isFocusing;
@property (nonatomic) float progressEstimate;

- (id<CustomWebViewDelegate>)delegate;
+ (void)deleteCacheFiles;
+ (BOOL)isPrivateBrowsingEnabled;
+ (void)setPrivateBrowsingEnabled:(BOOL)privateBrowse;
+ (NSArray *)activeWebViews;
- (void)setDelegate:(id<CustomWebViewDelegate>)delegate;
- (void)restore;
- (void)close;
- (void)transferLoading;
- (void)requiredCredentialWithAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
- (id<NSURLConnectionDelegate, NSURLConnectionDataDelegate>)setTransferConnectionDelegate:(NSURLConnection *)connection withProtocol:(CustomURLProtocol *)protocol;
- (NSURLResponse *)translateResponse:(NSURLResponse *)response withProtocol:(CustomURLProtocol *)protocol;
- (void)didChangeSelection;
- (BOOL)isPDF;

@end

@protocol CustomWebViewDelegate <NSObject>
@optional

- (BOOL)customWebView:(CustomWebView *)customWebView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (BOOL)customWebView:(CustomWebView *)customWebView shouldStartRenderingConnectionClosed:(BOOL)closed;
- (CustomWebView *)customWebView:(CustomWebView *)customWebView createWindowWithRequest:(NSURLRequest *)request withWindowName:(NSString *)windowName;
- (void)customWebViewClose:(CustomWebView *)customWebView;
- (void)customWebViewDidStartLoad:(CustomWebView *)customWebView;
- (void)customWebViewOnReady:(CustomWebView *)customWebView;
- (void)customWebViewDidStartRendering:(CustomWebView *)customWebView;
- (void)customWebView:(CustomWebView *)customWebView progressEstimateChanged:(float)progress;
- (void)customWebViewDidFinishLoad:(CustomWebView *)customWebView;
- (void)customWebView:(CustomWebView *)customWebView didIframeTransitionWithLoadType:(CustomWebViewLoadType)loadType;
- (void)customWebView:(CustomWebView *)customWebView didAjaxTransitionWithLoadType:(CustomWebViewLoadType)loadType;
- (void)customWebView:(CustomWebView *)customWebView didFailLoadWithError:(NSError *)error;
- (id<NSURLConnectionDelegate, NSURLConnectionDataDelegate>)customWebView:(CustomWebView *)customWebView requiredNewConnectionDelegate:(NSURLConnection *)connection;
- (NSURLCredential *)customWebView:(CustomWebView *)customWebView requiredCredentialWithAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
- (NSString *)customWebView:(CustomWebView *)customWebView shouldShowPrompt:(NSString *)prompt defaultText:(NSString *)text;
- (NSURLResponse *)customWebView:(CustomWebView *)customWebView shouldReceiveResponse:(NSURLResponse *)response;
- (NSMutableURLRequest *)customWebView:(CustomWebView *)customWebView shouldSendRequest:(NSMutableURLRequest *)request;
- (void)customWebView:(CustomWebView *)customWebView didShowKeyBoard:(UIView *)inputView withAccessoryView:(UIView *)accessoryView;

//RotatingSheet
- (BOOL)customWebView:(CustomWebView *)customWebView shouldShowRotatingSheet:(UIActionSheet *)rotatingSheet;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheet:(UIActionSheet *)rotatingSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheetCancel:(UIActionSheet *)actionSheet;

//SelectMenu
- (BOOL)customWebView:(CustomWebView *)customWebView canPerformSelectMenuAction:(SEL)action withSender:(id)sender;
- (void)customWebView:(CustomWebView *)customWebView performSelectMenuTitle:(NSString *)title;

//Preview
- (NSArray *)customWebView:(CustomWebView *)customWebView previewControllerAppendActivity:(FSPreviewController *)preview;

@end

