@protocol SwitchScrollViewDelegate;
@interface SwitchScrollView : UIView <UIScrollViewDelegate>

@property (assign, nonatomic) id<SwitchScrollViewDelegate> delegate;
// デリゲート

@property (nonatomic) NSMutableArray *viewArray;
// ScrollViewが沢山。Libingではタブ(CustomWebView)が入ってる。

@property (nonatomic) NSInteger current;
// 今開いてるindex

@property (nonatomic) float decelerationRate;
// 慣性スクロールとかなんとか、ここ変えると内蔵するUIScrollView全部切り替わる。

- (void)openView:(UIView *)view animated:(BOOL)animated;
- (void)openViewWithIndex:(NSInteger)index animated:(BOOL)animated;
// 指定したViewを開く。

- (id)deleteView:(UIView *)view animated:(BOOL)animated;
- (id)deleteViewWithIndex:(NSInteger)index animated:(BOOL)animated;
// 指定したViewを削除。開いてたら隣のを開く。

- (NSInteger) count;
// Viewの数。

- (NSInteger) prev;
- (NSInteger) next;
// 前後。

@end

// デリゲートメソッド。基本的にUIScrollViewDelegateのラッパー。使わn

@protocol SwitchScrollViewDelegate <NSObject>
@optional
- (void)switchViewDidEndDecelerating:(UIScrollView *)scrollView;
- (void)switchViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate shouldSwitch:(in BOOL *)shouldSwitch;
// shouldSwitchをNOにすると、隣のViewに移らない。
- (void)switchViewDidEndScrollingAnimation:(UIScrollView *)scrollView;
- (void)switchViewDidEndZooming:(UIScrollView *)scrollView withView:(UIView *)view atScale:(float)scale;
- (void)switchViewDidScroll:(UIScrollView *)scrollView;
- (void)switchViewDidScrollToTop:(UIScrollView *)scrollView;
- (void)switchViewDidZoom:(UIScrollView *)scrollView;
- (BOOL)switchViewShouldScrollToTop:(UIScrollView *)scrollView;
- (void)switchViewWillBeginDecelerating:(UIScrollView *)scrollView;
- (void)switchViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)switchViewWillBeginZooming:(UIScrollView *)scrollView withView:(UIView *)view;
- (void)switchViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset;
@end
