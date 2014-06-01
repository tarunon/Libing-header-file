//
//  BookmarkBaseEntity.h
//  Libing
//
//  Created by tarunon on 2014/04/14.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class BookmarkNodeEntity, CommandEntity, FaviconEntity;

@interface BookmarkBaseEntity : NSManagedObject

@property (nonatomic, retain) NSDate * created;
@property (nonatomic, retain) NSNumber * index;
@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) FaviconEntity *favicon;
@property (nonatomic, retain) BookmarkNodeEntity *parent;
@property (nonatomic, retain) NSSet *commands;
@end

@interface BookmarkBaseEntity (CoreDataGeneratedAccessors)

- (void)addCommandsObject:(CommandEntity *)value;
- (void)removeCommandsObject:(CommandEntity *)value;
- (void)addCommands:(NSSet *)values;
- (void)removeCommands:(NSSet *)values;

@end
