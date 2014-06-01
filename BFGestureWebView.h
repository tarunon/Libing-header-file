//
//  BFGestureWebView.h
//  Libing
//
//  Created by tarunon on 2013/09/16.
//  Copyright (c) 2013年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIGestureRecognizerSubclass.h>
#import "CustomWebView.h"

@interface BFGestureWebView : CustomWebView <UIGestureRecognizerDelegate>{
    UIImageView *_transitionView, *_currentView, *_shadowView;
    UIImage *_screenShot;
    NSMutableDictionary *_screenShots;
    CGFloat _continuas;
    CGPoint _previousLocation;
    BOOL _cannotGo;
}

@property (nonatomic) UIScreenEdgePanGestureRecognizer *interactiveBackGestureRecognizer, *interactiveForwardGestureRecognizer;
@property (nonatomic) NSMutableArray *backURLCaches, *forwardURLCaches;

- (UIImage *)screenShotAtBackForwardCount:(NSInteger)count;

@end
