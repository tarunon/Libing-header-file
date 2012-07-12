@interface BrowserViewController : UIViewController <CustomWebViewDelegate, SwitchScrollViewDelegate, UIGestureRecognizerDelegate, UIActionSheetDelegate, DownloadContentDelegate> 
// CustomWebViewのdelegateに指定されています。これらのメソッドを使用する場合、Hide Adsアドオンが必要になります。

@property (strong, nonatomic) Bookmark *bookmark, *history;
@property (strong, nonatomic) Bookmarklet *bookmarklet;
@property (strong, nonatomic) UITabBarController *menuBar;
@property (strong, nonatomic) DownloadManager *download;
@property (strong, nonatomic) SwitchScrollView *switchView;
@property (strong, nonatomic) AddressBar *addressBar;
@property (strong, nonatomic) SearchBar *searchBar;
// インターフェースにアクセス可能。希望があれば、それぞれのヘッダーを可能な範囲で公開します。

@property (strong, nonatomic) NSMutableArray *blockHosts, *blockDomain; 
// アドブロック用の配列。hostsがホスト指定、domainが*以降のサブドメイン指定。
    
@property (nonatomic) BOOL isPrivate;
// プライベートブラウジングのフラグ。true→履歴クッキー記録しない。

@property (strong, nonatomic) NSUserDefaults *defaults; 
// ユーザーデフォルトです。設定の値を直接書き換えることが可能。UserDefaultValues参照。

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
- (NSArray *)tabArray; // タブ配列。readonly。他のタブへアクセスするのに使用する。
- (CustomWebView *)webView; // 現在開いているタブ。[self description]からアクセスした方が速い。

- (NSURLRequest *)requestWithString:(NSString *)urlString withReferer:(CustomWebView *)webView
// urlStringのURLへのリクエストを生成する。webViewに指定したタブをリファラーとして扱う。
- (CustomWebView *)customWebViewInitialized;
// タブ配列に追加せず、webViewを生成する。delegate,文字コード等の基本設定は自動的に行われる。
// 上記二つに加え、NSArray,NSString,NSURL以外のインスタンスは意図して生成することは出来ない。

- (void)callATOKPad; // ATOKPadを呼び出す。フォーカスが存在しなければ返り値はクリップボードへ。
- (UIImage *)getImage:(NSUInteger)index; // タブ一覧で表示する画像を取得するためのメソッド。無限ループでメモリ解放ツール化。

- (void)installBookmarklet:(NSString *)code withName:(NSString *)name withCmds:(NSArray *)cmds; // ブックマークレットのインストール画面を開く。
- (void)addBookmark:(NSString *)item withName:(NSString *)name; // ブックマークの追加画面を開く。
- (void)makeMail:(NSURL *)url; // メール作成画面を開く。


@end
