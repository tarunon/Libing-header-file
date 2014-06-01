//
//  LibingRoomController_iPad.h
//  Libing
//
//  Created by tarunon on 2014/05/11.
//  Copyright (c) 2014年 tarunon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LibingRoomController.h"

@interface LibingRoomController_iPad : LibingRoomController <UIPopoverControllerDelegate> {
    NSArray *_menuViewControllers;
    UIPopoverController *_menuPopoverController;
    UIBarButtonItem *_popoverAppearanceButton;
}

@property (nonatomic) UIBarButtonItem *backButton, *forwardButton, *bookmarksButton, *historyButton, *downloadsButton, *settingsButton;

@end
