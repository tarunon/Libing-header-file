@interface TabWebView : UIView <CustomWebViewDelegate, SwitchScrollViewDelegate, UIGestureRecognizerDelegate, UIActionSheetDelegate, NSURLConnectionDelegate, NSURLConnectionDataDelegate>
// CustomWebViewのdelegateに指定されています。これらのメソッドを使用する場合、Hide Adsアドオンが必要になります。

@property (strong, nonatomic) BrowserViewController *viewController;
@property (strong, nonatomic) SwitchScrollView *switchView;
@property (strong, nonatomic) AddressBar *addressBar;
@property (strong, nonatomic) SearchBar *searchBar;

// インターフェースにアクセスできます。希望があれば、それぞれのヘッダーを可能な範囲で公開します。

@property (strong, nonatomic) NSUserDefaults *defaults; // ユーザーデフォルトです。設定の値を直接書き換えることが可能です。

- (void)setValue:(id)value forKey:(NSString *)key
- (id)valueForKey:(NSString *)key
- (void)removeValueForKey:(NSString *)key;

// これらのメソッドを使うことで、タブ間での値の共有や、一時的に生成したオブジェクトの保持が可能になります。

- (void)addEmptyTab; // タブ配列の最後に空タブを追加します。
- (void)insertTab:(NSURLRequest *)req; // 現在開いているタブの次に、reqのリクエスト内容でタブを開きます。
- (void)download:(NSURLRequest *)req; // reqのリクエスト内容をダウンロードします。
- (NSArray *)tabArray; // タブ配列です。直接操作することは出来ません。他のタブへアクセスするのに使用します。

- (NSURLRequest *)requestWithString:(NSString *)urlString withReferer:(CustomWebView *)webView
// urlStringのURLへのリクエストを生成します。webViewに指定したタブをリファラーとして扱います。

@end
