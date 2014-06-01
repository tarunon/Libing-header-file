//
//  BookmarkNodeEntity.h
//  Libing
//
//  Created by tarunon on 2014/04/13.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "BookmarkBaseEntity.h"

@class BookmarkBaseEntity;

@interface BookmarkNodeEntity : BookmarkBaseEntity

@property (nonatomic, retain) NSNumber * isRoot;
@property (nonatomic, retain) NSSet *children;
@end

@interface BookmarkNodeEntity (CoreDataGeneratedAccessors)

- (void)addChildrenObject:(BookmarkBaseEntity *)value;
- (void)removeChildrenObject:(BookmarkBaseEntity *)value;
- (void)addChildren:(NSSet *)values;
- (void)removeChildren:(NSSet *)values;

@end
