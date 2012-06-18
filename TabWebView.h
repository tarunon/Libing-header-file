@interface TabWebView : UIView <CustomWebViewDelegate, SwitchScrollViewDelegate, UIGestureRecognizerDelegate, UIActionSheetDelegate, NSURLConnectionDelegate, NSURLConnectionDataDelegate>
// CustomWebViewのdelegateに指定されています。これらのメソッドを使用する場合、Hide Adsアドオンが必要になります。

@property (strong, nonatomic) BrowserViewController *viewController;
@property (strong, nonatomic) SwitchScrollView *switchView;
@property (strong, nonatomic) AddressBar *addressBar;
@property (strong, nonatomic) SearchBar *searchBar;
// インターフェースにアクセスできます。希望があれば、それぞれのヘッダーを可能な範囲で公開します。

@property (strong, nonatomic) NSUserDefaults *defaults; 
// ユーザーデフォルトです。設定の値を直接書き換えることが可能です。UserDefaultValues参照。

- (void)setValue:(id)value forKey:(NSString *)key
- (id)valueForKey:(NSString *)key
- (void)removeValueForKey:(NSString *)key;
// NSDictionaryのメソッドに同じ。
// これらのメソッドを使うことで、タブ間での値の共有や、一時的に生成したオブジェクトの保持が可能になります。
// 再起動しても値を保持する必要がある場合はdefaultsからどうぞ。ただし他の設定用変数と名前がかぶらないように注意。
// callback等の一部の環境変数はここに含まれます。

- (void)addEmptyTab; // タブ配列の最後に空タブを追加します。
- (void)insertTab:(NSURLRequest *)req; // 現在開いているタブの次に、reqのリクエスト内容でタブを開きます。
- (void)download:(NSURLRequest *)req; // reqのリクエスト内容をダウンロードします。
- (NSArray *)tabArray; // タブ配列です。直接操作することは出来ません。他のタブへアクセスするのに使用します。

- (NSURLRequest *)requestWithString:(NSString *)urlString withReferer:(CustomWebView *)webView
// urlStringのURLへのリクエストを生成します。webViewに指定したタブをリファラーとして扱います。
- (CustomWebView *)customWebViewInitialized;
// タブ配列に追加せず、webViewを生成する。delegate,文字コード等の基本設定は自動的に行われる。
// 上記二つに加え、NSArray,NSString,NSURL以外のインスタンスは意図して生成することは出来ません。

- (void)callATOKPad; // ATOKPadを呼び出します。フォーカスが存在しなければ返り値はクリップボードへ。
- (UIImage *)getImage:(NSUInteger)index; // タブ一覧で表示する画像を取得するためのメソッド。無限ループでメモリ解放ツール化。


@end
