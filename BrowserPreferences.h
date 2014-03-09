#import <Foundation/Foundation.h>

@interface BrowserPreferences : NSObject {
    NSUserDefaults *_defaults;
}

/*
 * 表示設定
 */
@property (nonatomic) BOOL additionalView;
// 補助表示

@property (nonatomic) BOOL showStatusBar;
// ステータスバー

@property (nonatomic) NSArray *menuButtons;
// ボタンの並べ替え

@property (nonatomic) NSString *firstMenu;
// 最初に表示するメニュー


/*
 * 操作設定
 */
@property (nonatomic) BOOL inertialScroll;
// 慣性スクロール

@property (nonatomic) BOOL scrollSwitchTab;
// タブ切り替え

@property (nonatomic) CGFloat determinateLeft;
// 画面端の幅(左端)

@property (nonatomic) CGFloat determinateRight;
// 画面端の幅(右端)

@property (nonatomic) CGFloat determinateBottom;
// 画面端の幅(下端)

@property (nonatomic) BOOL tripleTap;
// メニュー表示ジェスチャー(トリプルタップ)

@property (nonatomic) BOOL screenBottom;
// メニュー表示ジェスチャー(画面の下端)

@property (nonatomic) CGFloat oppositeDirection;
// 反転する角度の範囲(60~120)

@property (nonatomic) CGFloat scrollSpeed;
// スクロール速度(1.0~2.0)

@property (nonatomic) BOOL normalLeft;
// ノーマルスクローラー(左端)

@property (nonatomic) BOOL normalRight;
// ノーマルスクローラー(右端)

@property (nonatomic) BOOL normalBottom;
// ノーマルスクローラー(下端)


/*
 * ダウンロード設定
 */
@property (nonatomic) BOOL mediaPreview;
// Webでプレビューを開く

@property (nonatomic) BOOL localBrowser;
// ローカルブラウザ

@property (nonatomic) BOOL dismissDelete;
// プレビューを閉じて削除

@property (nonatomic) BOOL downloadAccelerator;
// DLアクセラレータ

/*
 * 拡張機能
 */
@property (nonatomic) BOOL monitorClipboard;
// クリップボードを監視

@property (nonatomic) BOOL displayNotification;
// 通知を表示する

@property (nonatomic) BOOL iCloudSync;
// iCloud同期

@property (nonatomic) BOOL cacheFavicon;
// ファビコンを保存

@property (nonatomic) NSString *shareSentence;
// シェアする文章

@property (nonatomic) NSArray *userAgents;
// 環境変数(UA)

@property (nonatomic) NSArray *agentNames;
// 環境変数(UA名)

@property (nonatomic) NSArray *textEncodings;
// 環境変数(文字コード)


/*
 * プライバシー設定
 */
@property (nonatomic) BOOL autoFill;
// フォームの自動入力

@property (nonatomic) NSInteger cookieMode;
// Cookieをブロック(0~2)

@property (nonatomic) NSArray *blockCookies;
// Cookieブロックリスト


/*
 * 広告を非表示にする
 */
@property (nonatomic) NSArray *blockHosts;
// アドブロックリスト


/*
 * らぼらとり
 */
@property (nonatomic) BOOL sendLaunch;
// 起動時に情報を送信

@property (nonatomic) BOOL sendLogs;
// 操作のフィードバック

@property (nonatomic) BOOL handSide;
// 持ち手補正


/*
 * その他(設定項目なし)
 */
@property (nonatomic) NSInteger rotationLock;
// 画面の固定向き(0無固定 1~4↑↓←→)

@property (nonatomic) NSInteger tabIndex;
// 最後に開いたタブのインデックス

@property (nonatomic) NSString *homepage;
// ホームページのURL

@property (nonatomic) NSArray *webTabArray;
// 最後に開いた全てのタブの情報。


- (void)synchronize;
// 変更内容を保存する。

@end
