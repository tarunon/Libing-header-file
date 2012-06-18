@protocol CustomWebViewDelegate;
@interface CustomWebView : UIWebView

@property (strong, nonatomic) NSString *textEncode, *userAgent;
// エンコードとユーザーエージェントの設定です。
// エンコードもユーザーエージェントも、実際の値を直接指定してください。

// 上以外はUIWebViewに同じです。SmoothScroll然りプライベートメソッドもゴニョれるので、これだけでも結構遊べます。

@end