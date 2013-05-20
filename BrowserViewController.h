@interface BrowserViewController : UIViewController <CustomWebViewDelegate, SwitchScrollViewDelegate, UIGestureRecognizerDelegate, UIActionSheetDelegate, DownloadContentDelegate> 
// CustomWebViewのdelegateに指定されています。これらのメソッドを使用する場合、Hide Adsアドオンが必要になります。


<<<<<<< HEAD
@property (nonatomic) BrowserAppDelegate *appDelegate;
@property (nonatomic) BookmarkRoot *bookmark, *history;
@property (nonatomic) Bookmarklet *bookmarklet;
@property (nonatomic) UITabBarController *menuBar; // iPhone only
@property (nonatomic) UIPopoverController *popover; // iPad only
=======
@property (nonatomic) BrowserApplication *application;
@property (nonatomic) UITabBarController *menuBar;
>>>>>>> Libing v3.3.0
@property (nonatomic) DownloadManager *download;
@property (nonatomic) SwitchScrollView *switchView;
@property (nonatomic) AddressBar *addressBar;
@property (nonatomic) SearchBar *searchBar;
// インターフェースにアクセス可能。希望があれば、それぞれのヘッダーを可能な範囲で公開します。

<<<<<<< HEAD

@property (nonatomic, readonly) NSArray *tabArray;
// タブ配列。readonly。他のタブへアクセスするのに使用する。

@property (nonatomic, readonly) CustomWebView *webView;
// 現在開いているタブ。[self description]からアクセスした方が速い。

@property (nonatomic) NSMutableArray *blockHosts, *blockDomain;
// アドブロック用の配列。hostsがホスト指定、domainが*以降のサブドメイン指定。

=======
>>>>>>> Libing v3.3.0
@property (nonatomic) NSUserDefaults *defaults; 
// ユーザーデフォルトです。設定の値を直接書き換えることが可能。UserDefaultValues参照。

@property (nonatomic) UIPasteboard *pasteboard;
// クリップボード。

- (void)setValue:(id)value forKey:(NSString *)key
- (id)valueForKey:(NSString *)key
- (void)removeValueForKey:(NSString *)key;
// NSDictionaryのメソッドに同じ。
// これらのメソッドを使うことで、タブ間での値の共有や、一時的に生成したオブジェクトの保持が可能に。
// 再起動しても値を保持する必要がある場合はdefaultsを利用。ただし他の設定用変数と名前がかぶらないように注意。
// callbackやATOK連携時のクリップボードの待避等、一部の環境変数はここに含まれる。

- (void)addEmptyTab; // タブ配列の最後に空タブを追加。
- (void)insertTab:(NSURLRequest *)req; // 現在開いているタブの次に、reqのリクエスト内容でタブを開く。
- (void)download:(NSURLRequest *)req; // reqのリクエスト内容をダウンロードする。

- (NSURLRequest *)requestWithString:(NSString *)urlString withReferer:(CustomWebView *)webView
// urlStringのURLへのリクエストを生成する。webViewに指定したタブをリファラーとして扱う。
- (CustomWebView *)customWebViewInitialized;
// タブ配列に追加せず、webViewを生成する。delegate,文字コード等の基本設定は自動的に行われる。
// 上記二つに加え、NSArray,NSString,NSURL以外のインスタンスは意図して生成することは出来ない。

- (void)callATOKPad; // ATOKPadを呼び出す。フォーカスが存在しなければ返り値はクリップボードへ。

<<<<<<< HEAD
- (void)evalBookmark:(id<Bookmark>)bookmark webView:(CustomWebView *)webView;
// ブックマークの実行。

- (void)makeMail:(NSURL *)url;
// メール作成画面を開く。mailto:に同じ。

- (void)installBookmark:(id<Bookmark>)bookmark withCmds:(NSArray *)cmds;
// ブックマークを追加する。

- (void)doJavaScript:(NSString *)code arguments:(NSArray *)args webView:(CustomWebView *)webView;
// JavaScriptの実行。Libing.UIWebViewを必要に応じて実装する。

- (void)evalBookmarkWithCmd:(NSString *)cmd webView:(CustomWebView *)webView;
// cmdに指定したショートカットを持つブックマークレットを全て実行する。

=======
- (void)installBookmark:(id<Bookmark>)bookmark withCmds:(NSArray *)cmds; // ブックマークのインストール画面を開く。
// bookmarkは、履歴あたりを参照すると良さ気(履歴もブックマークと同様のインスタンスである)。

- (void)makeMail:(NSURL *)url; // メール作成画面を開く。
>>>>>>> Libing v3.3.0

- (void)notificationAtStatusBar:(id)notification; // ステータスバーに通知を表示。
// notificationにはCustomWebView, NSError, NSStringのインスタンスを入れる。
// ブックマークレットから利用する場合は、専ら文字列を突っ込む。

@end
