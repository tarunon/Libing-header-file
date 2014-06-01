//
//  BookmarkManager.h
//  Libing
//
//  Created by tarunon on 2014/03/26.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

// This is Bookmarks manager class
// Use to manage Bookmark and History.
// Bookmark gives the parent node to "parent" property.
// History gives the date of open to "created" property.

#import <Foundation/Foundation.h>
#import "BookmarkLeafEntity.h"
#import "BookmarkNodeEntity.h"
#import "RoomProtocol.h"
#import "FaviconEntity.h"
#import "CommandEntity.h"

@interface BookmarkManager : NSObject {
    NSManagedObjectContext *_mainContext;
    NSManagedObjectContext *_privateContext;
}

@property (nonatomic) BOOL iCloudSync;

+ (BookmarkManager *)sharedManager;

- (void)undo;
- (void)rollback;
- (void)save;

// Get a bookmarks root node.
- (BookmarkNodeEntity *)rootNode;

// Get a temporary bookmarks.
- (BookmarkLeafEntity *)tempLeaf;
- (BookmarkNodeEntity *)tempNode;

// Get all nodes.
- (NSArray *)allNodes;

// Set a command to bookmark. [bookmark addCommandsObject:]
- (CommandEntity *)createCommand:(NSString *)command;
- (NSArray *)bookmarksWithCommand:(NSString *)command;

// This method is bound to RoomProtocol#standardsCommandStrings.
- (NSArray *)standardCommands;

// Search methods.
- (NSArray *)leafsBySearchQuery:(NSString *)query;
- (NSArray *)leafsBySearchQuery:(NSString *)query count:(NSInteger)count;
- (BookmarkLeafEntity *)bookmarkWithName:(NSString *)name;
- (BookmarkLeafEntity *)bookmarkWithUrl:(NSString *)url;

// Favicon methods.
- (void)getFaviconForBookmark:(BookmarkBaseEntity *)bookmark block:(void(^)(UIImage *favicon))block;
- (void)setFaviconForBookmark:(BookmarkBaseEntity *)bookmark url:(NSString *)url;
- (void)setFaviconForBookmark:(BookmarkBaseEntity *)bookmark image:(UIImage *)image;
- (void)getFavicon:(FaviconEntity *)favicon block:(void (^)(UIImage *favicon))block;

// Delete bookmarks that has not reference.
- (void)sweep;

// Delete history of more than a week ago.
- (void)removeHistories;

@end

@interface BookmarkBaseEntity (URL)

- (NSURL *)URL;

@end
