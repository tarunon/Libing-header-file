@interface BrowserApplication : UIApplication

@property (nonatomic) BookmarkRoot *bookmark, *history;
// ブックマークと履歴。

@property BrowserPreferences *preferences;
// 設定。UserDefaultsを書き換えるよりもこれを用いたほうが確実。

@property (nonatomic) NSMutableSet *loadedOtherHosts, *blockedHosts;
// 最も最近読み込んだホストと、ブロックしたホストの配列。

- (void)showNotificationAtStatusBar:(NSString *)text timeInterval:(NSTimeInterval)timeInterval override:(BOOL)override withAction:(void(^)())action;
// ステータスバー通知。通知タップ時や時間など細かい指定をする場合はコチラを使う。

- (void)hideNotificationAtStatusBar;
// ステータスバー通知を強制的にキャンセルする。

@end
