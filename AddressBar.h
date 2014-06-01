//
//  AddressBar.h
//  Libing
//
//  Created by tarunon on 12/01/12.
//  Copyright (c) 2012年 Nobuo Saito. All rights reserved.
//

// Use to open URL, or Search text.

#import <UIKit/UIKit.h>
#import "PullActionView.h"
#import "BookmarkCollectionViewCell.h"

@protocol AddressBarDelegate;
@class AddressBarTextField;

@interface AddressBar : UIView <PullActionViewDelegate, UITextFieldDelegate, UITableViewDelegate, UITableViewDataSource, UICollectionViewDelegate, UICollectionViewDataSource> {
    UINavigationBar *_navigationBar;
    AddressBarTextField *_textField;
    UIToolbar *_leftBar, *_rightBar;
    UILongPressGestureRecognizer *_tableLongPress, *_collectionLongPress;
    UIScreenEdgePanGestureRecognizer *_leftEdge;
    UIScreenEdgePanGestureRecognizer *_rightEdge;
    UIBarButtonItem *_space;
    PullActionView *_pullActionView;
    BOOL _isFirstResponder, _showLog;
    UISegmentedControl *_segmentedControl;
}

@property (weak, nonatomic) id<AddressBarDelegate> delegate;
@property (nonatomic) BOOL saveLog;
@property (nonatomic) UIBarButtonItem *rightBarButtonItem, *leftBarButtonItem;
@property (nonatomic) NSArray *rightBarButtonItems, *leftBarButtonItems, *searchEngines;
@property (nonatomic) NSMutableArray *searchLogs;
@property (nonatomic) NSString *text, *placeholder;
@property (nonatomic) UITableView *searchSuggestTableView;
@property (nonatomic) UICollectionView *searchEngineCollectionView;

- (void)reloadData;
- (void)searchOrURL:(NSString *)text withEngine:(BookmarkLeafEntity *)engine newWindow:(BOOL)newWindow;

@end

@protocol AddressBarDelegate <NSObject>

@required
- (void)addressBar:(AddressBar *)addressBar searchText:(NSString *)text withEngine:(BookmarkLeafEntity *)engine newWindow:(BOOL)newWindow;

@optional
- (BOOL)addressBarSholdBeginEditing:(AddressBar *)addressBar;
- (void)addressBarDidBeginEditing:(AddressBar *)addressBar;
- (void)addressBarTextDidChange:(AddressBar *)addressBar;
- (void)addressBarDidEndEditing:(AddressBar *)addressBar;

// Define tableview's behavior when user input text.
- (NSInteger)numberOfSectionsInAddressBar:(AddressBar *)addressBar;
- (NSInteger)addressBar:(AddressBar *)addressBar numberOfRowsInSection:(NSInteger)section;
- (NSString *)addressBar:(AddressBar *)addressBar titleForHeaderInSection:(NSInteger)section;
- (UITableViewCell *)addressBar:(AddressBar *)addressBar cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)addressBar:(AddressBar *)addressBar didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)addressBar:(AddressBar *)addressBar accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath;
- (UITableViewCellEditingStyle)addressBar:(AddressBar *)addressBar editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)addressBar:(AddressBar *)addressBar commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath;

@end