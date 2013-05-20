@interface BrowserApplication : UIApplication

@property (nonatomic) BookmarkRoot *bookmark, *history;
// ブックマークと履歴。

@property (nonatomic) NSMutableArray *blockHosts, *blockDomain;
// アドブロック用の配列。
// blockDomainが*を含む。

@property (nonatomic) NSMutableSet *loadedOtherHosts, *blockedHosts;
// 最も最近読み込んだホストと、ブロックしたホストの配列。

- (void)showNotificationAtStatusBar:(NSString *)text timeInterval:(NSTimeInterval)timeInterval override:(BOOL)override withAction:(void(^)())action;
// ステータスバー通知。通知タップ時や時間など細かい指定をする場合はコチラを使う。

- (void)hideNotificationAtStatusBar;
// ステータスバー通知を強制的にキャンセルする。

@end
