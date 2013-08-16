@protocol CustomWebViewDelegate;
@interface CustomWebView : UIWebView

@property (assign, nonatomic) id<CustomWebViewDelegate> delegate;
// デリゲート(BrowserViewController)

@property (nonatomic) NSString *textEncode, *userAgent;
// エンコードとユーザーエージェントの設定。
// エンコードもユーザーエージェントも、実際の値を直接指定する。

@property (nonatomic) NSMutableArray *rotatingSheetButtons;
// 長押しした時のボタンに表示する文字列。ブックマークレットのタイトル打ち込みゃ動く。

@property (nonatomic) NSMutableArray *backURLs, *forwardURLs;
// タブ履歴。backURLsの先頭が現在のページ。だいたいあってる。

@property (nonatomic) NSString *location;
// デコード済みURL。アドレスバーに表示される。
// UIWebViewのrequestか、JSのlocation.hrefを参照する。

@property (nonatomic) PreviewInWebView *preview;
// Preview関連クラス。

- (void)addRotatingSheetButtonWithTitle:(NSString *)title;
// rotatingSheetButtonsに指定したタイトルを追加する。
// ぶっちゃけ直に置き換えてもいい。

- (void)transferLoading;
// 読み込みを転送する。Libingではダウンロードに。読込中でなければ動かない。

- (void)restore;
// backURLsとforwardURLsにURLを入れた後、このメソッドでタブを再生する。
// ただしタブが新品で無い場合の動作は保証しない。

// 他はUIWebViewに殆ど同じ。SmoothScroll然りプライベートメソッドもゴニョれるので、これだけでも結構遊べたり。

- (void)close
// タブを閉じる。

@end

//デリゲートメソッド。使うかなぁ？
@protocol CustomWebViewDelegate <NSObject>
@optional

- (BOOL)customWebView:(CustomWebView *)customWebView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)customWebViewDidStartLoad:(CustomWebView *)customWebView;
- (void)customWebViewDidFinishLoad:(CustomWebView *)customWebView;
- (void)customWebView:(CustomWebView *)customWebView didFailLoadWithError:(NSError *)error;
// UIWebViewDelegateのラッパー。呼び出すタイミングとか、navigationTypeとかをちょっと弄ったり。
- (BOOL)customWebView:(CustomWebView *)customWebView shouldStartRenderingConnectionClosed:(BOOL)closed;
// レンダリングを開始するかどうか。Connectionが閉じられていれば、closed=YES

- (CustomWebView *)customWebView:(CustomWebView *)customWebView createWindowWithRequest:(NSURLRequest *)request;
// 新しいタブを開く。だいぶ上手く動くようになった(｀・ω・´)

- (void)customWebViewClose:(CustomWebView *)customWebView;
// タブを閉じる。

- (void)customWebView:(CustomWebView *)customWebView didAjaxTransitionWithAjaxType:(CustomWebViewAjaxType)ajaxType;
// Ajax関連の通信完了とかの通知。戻る進む、リンククリック。

- (void)customWebView:(CustomWebView *)customWebView progressEstimateChanged:(float)progress;
// プログレスサークルで使う。

- (id<NSURLConnectionDelegate, NSURLConnectionDataDelegate>)customWebView:(CustomWebView *)customWebView requiredNewConnectionDelegate:(NSURLConnection *)connection;
// 通信の転送要請が来た場合に新しいNSURLConnectionDelegateを返す。ダウンロードクラスを作って返してる。

- (NSURLCredential *)customWebView:(CustomWebView *)customWebView requiredCredentialWithAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
// ベーシック認証

- (NSString *)customWebView:(CustomWebView *)customWebView shouldShowPrompt:(NSString *)prompt defaultText:(NSString *)text;
// prompt()の乗っ取り。今は使ってないと思う。

- (NSHTTPURLResponse *)customWebView:(CustomWebView *)customWebView shouldReceiveResponse:(NSHTTPURLResponse *)response;
- (NSMutableURLRequest *)customWebView:(CustomWebView *)customWebView shouldSendRequest:(NSMutableURLRequest *)request;
// リクエスト、レスポンス換装用。UAとか文字コードとかは内部的にやってるので、こっちは広告ブロックとかメディアダウンロードとかに使う。

- (BOOL)customWebView:(CustomWebView *)customWebView shouldShowRotatingSheet:(UIActionSheet *)rotatingSheet;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheet:(UIActionSheet *)rotatingSheet clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)customWebView:(CustomWebView *)customWebView rotatingSheetCancel:(UIActionSheet *)actionSheet;
// 長押しボタンのアレコレ

// 晒しといてなんだけど、デリゲートは絶対使わない、使えない。

@end
