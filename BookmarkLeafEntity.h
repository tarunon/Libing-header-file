//
//  BookmarkLeafEntity.h
//  Libing
//
//  Created by tarunon on 2014/04/13.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "BookmarkBaseEntity.h"


@interface BookmarkLeafEntity : BookmarkBaseEntity

@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSNumber * viewed;

@end
