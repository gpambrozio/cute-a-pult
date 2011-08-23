//
//  AppDelegate.h
//  cute-a-pult
//
//  Created by Gustavo Ambrozio on 23/8/11.
//  Copyright CodeCrop Software 2011. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RootViewController;

@interface AppDelegate : NSObject <UIApplicationDelegate> {
	UIWindow			*window;
	RootViewController	*viewController;
}

@property (nonatomic, retain) UIWindow *window;

@end
