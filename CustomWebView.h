@protocol CustomWebViewDelegate;
@interface CustomWebView : UIWebView

@property (assign, nonatomic) id<CustomWebViewDelegate> delegate;
// デリゲート(BrowserViewController)

@property (nonatomic) NSString *textEncode, *userAgent;
// エンコードとユーザーエージェントの設定。
// エンコードもユーザーエージェントも、実際の値を直接指定する。

@property (nonatomic) NSMutableArray *rotatingSheetButtons;
// 長押しした時のボタンに表示する文字列。ブックマークレットのタイトル打ち込みゃ動く。

- (void)transferLoading;
// 読み込みを転送する。Libingではダウンロードに。読込中でなければ動かない。

// 他はUIWebViewに殆ど同じ。SmoothScroll然りプライベートメソッドもゴニョれるので、これだけでも結構遊べたり。

@end

//デリゲートメソッド。使うかなぁ？
@protocol CustomWebViewDelegate <NSObject>
@optional

- (BOOL)customWebView:(CustomWebView *)customWebView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)customWebViewDidStartLoad:(CustomWebView *)customWebView;
- (void)customWebViewDidFinishLoad:(CustomWebView *)customWebView;
- (void)customWebView:(CustomWebView *)customWebView didFailLoadWithError:(NSError *)error;
// UIWebViewDelegateのラッパー。呼び出すタイミングとか、navigationTypeとかをちょっと弄ったり。
- (void)customWebView:(CustomWebView *)customWebView didAjaxTransitionWithAjaxType:(CustomWebViewAjaxType)ajaxType;
// Ajax関連の通信完了とかの通知。戻る進む、リンククリック。

- (void)customWebView:(CustomWebView *)customWebView didReceiveDataLength:(float)dataLength;
- (void)customWebView:(CustomWebView *)customWebView didReceiveExpectedContentLength:(float)expectedContentLength;
// 受け取ったレスポンスの長さ、データの長さ。プログレスサークルで使う。

- (CustomWebView *)customWebView:(CustomWebView *)customWebView createWindowWithRequest:(NSURLRequest *)request;
// 新しいタブを開く。ひじょーに残念だが根っこがリジェクトされてるので使われていない。

- (id<NSURLConnectionDelegate, NSURLConnectionDataDelegate>)customWebView:(CustomWebView *)customWebView requiredNewConnectionDelegate:(NSURLConnection *)connection;
// 通信の転送要請が来た場合に新しいNSURLConnectionDelegateを返す。ダウンロードクラスを作って返してる。

- (NSURLCredential *)customWebView:(CustomWebView *)customWebView requiredCredentialWithAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
// ベーシック認証

- (BOOL)customWebView:(CustomWebView *)customWebView shouldShowRotatingSheet:(UIActionSheet *)rotatingSheet;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheet:(UIActionSheet *)rotatingSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheet:(UIActionSheet *)actionSheet didDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheet:(UIActionSheet *)actionSheet willDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheetCancel:(UIActionSheet *)actionSheet;
// 長押しボタンのアレコレ

- (NSHTTPURLResponse *)customWebView:(CustomWebView *)customWebView shouldReceiveResponse:(NSHTTPURLResponse *)response;
- (NSMutableURLRequest *)customWebView:(CustomWebView *)customWebView shouldSendRequest:(NSMutableURLRequest *)request;
// リクエスト、レスポンス換装用。UAとか文字コードとかは内部的にやってるので、こっちは広告ブロックとかメディアダウンロードとかに使う。

// 晒しといてなんだけど絶対使わない、使えない。

@end
