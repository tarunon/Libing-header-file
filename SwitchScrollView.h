//
//  SwitchScrollView.h
//  Libing
//
//  Created by tarunon on 12/01/01.
//  Copyright (c) 2012年 Nobuo Saito. All rights reserved.
//

// For switch and management some views.

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "CustomSwipeGestureRecognizer.h"


@interface UIPageControlBaseView : UIView {
    UIImageView *_background;
}
@property (nonatomic) UIPageControl *pageControl;

@end

@class SwitchScrollContainerView;
@protocol SwitchScrollViewDelegate;

@interface SwitchScrollView : UIView <UIScrollViewDelegate, UIGestureRecognizerDelegate>{
    NSInteger _current, _openingIdx, _deletingIdx;
    BOOL _scrollCheck, _requireAddBase;
    CustomSwipeGestureRecognizer *_swipeGesture;
    SwitchScrollContainerView *_movingContainer, *_removingContainer;
    BOOL _listAnimate;
    CGPoint _movingPointDif;
    UIScrollView *_scrollTopListener;
    NSInteger _pageControllShowing, _scrollFlag;
    NSMutableSet *_reorderFailerGestureRecognizers;
    NSMutableArray *_containers;
}

@property (assign, nonatomic) id<SwitchScrollViewDelegate> delegate;
@property (weak, nonatomic) UIView *requireNextOpenView;
@property (nonatomic) NSInteger current;
@property (nonatomic) BOOL scrollCheck, scrollSwitch, listMode;
@property (nonatomic) float decelerationRate;
@property (nonatomic) UIScrollView *baseView;
@property (nonatomic) UIPageControlBaseView *pageControlBaseView;
@property (nonatomic) UITapGestureRecognizer *dismissListModeGestureRecognizer, *toggleListModeGestureRecognizer;
@property (nonatomic) UILongPressGestureRecognizer *reorderGestureRecognizer;

- (void)addView:(UIView *)view;
- (void)insertView:(UIView *)view atIndex:(NSInteger)index;
- (void)replaceView:(UIView *)view atIndex:(NSInteger)index;
- (void)exchangeViewAtIndex:(NSInteger)index1 withViewAtIndex:(NSInteger)index2;
- (void)openView:(UIView *)view animated:(BOOL)animated;
- (void)openViewAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)deleteView:(UIView *)view animated:(BOOL)animated;
- (void)deleteViewAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)deleteAllViewAnimated:(BOOL)animated;
- (void)reset;
- (UIScrollView *)scrollView;
- (NSArray *)views;
- (NSInteger)count;
- (NSInteger)prev;
- (NSInteger)next;
- (void)setRequireGestureRecognizerToFail:(UIView *)view;
- (void)setListMode:(BOOL)listMode animated:(BOOL)animated;

- (void)didScroll:(UIScrollView *)scrollView;
- (void)didEndDragging:(UIScrollView *)scrollView;

@end

@protocol SwitchScrollViewDelegate <NSObject>

@optional

- (void)switchView:(SwitchScrollView *)switchView willShowView:(UIView *)view;
- (void)switchView:(SwitchScrollView *)switchView didShowView:(UIView *)view;
- (void)switchView:(SwitchScrollView *)switchView willHideView:(UIView *)view;
- (void)switchView:(SwitchScrollView *)switchView didHideView:(UIView *)view;

- (void)switchView:(SwitchScrollView *)switchView willOpenView:(UIView *)view;
- (void)switchView:(SwitchScrollView *)switchView didOpenView:(UIView *)view;
- (void)switchView:(SwitchScrollView *)switchView willDeleteView:(UIView *)view;
- (void)switchView:(SwitchScrollView *)switchView didDeleteView:(UIView *)view;

- (void)switchViewWillSwitchListMode:(SwitchScrollView *)switchView animated:(BOOL)animated;
- (void)switchViewDidSwitchListMode:(SwitchScrollView *)switchView animated:(BOOL)animated;
- (void)switchViewDidSorted:(SwitchScrollView *)switchView;
- (BOOL)switchViewShouldSwitch:(SwitchScrollView *)switchView;

@end
