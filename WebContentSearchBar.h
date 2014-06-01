//
//  WebContentSearchBar.h
//  Libing
//
//  Created by tarunon on 2014/04/27.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WebContentSearchBarInternal;
@protocol WebContentSearchDelegate;

@interface WebContentSearchBar : UIView <UISearchBarDelegate>{
    UIToolbar *_toolbar;
    WebContentSearchBarInternal *_searchBar;
    BOOL _shouldAdjust, _searching;
}

@property (nonatomic, weak) id<WebContentSearchDelegate> delegate;
@property (nonatomic) UIScrollView *scrollView;
@property (nonatomic) NSInteger max, index;
@property (nonatomic) NSString *text;

- (void)beginSearch;
- (void)endSearch;

@end

@protocol WebContentSearchDelegate <NSObject>

@required
- (NSInteger)webContentSearchBar:(WebContentSearchBar *)searchBar numberOfSearchText:(NSString *)text;
- (void)webContentSearchBar:(WebContentSearchBar *)searchBar moveToIndex:(NSInteger)index;
- (void)webContentSearchBarDidEndSearch:(WebContentSearchBar *)searchBar;

@end