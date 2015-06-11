//
//  VSThemeLoader.m
//  Q Branch LLC
//
//  Created by Brent Simmons on 6/26/13.
//  Copyright (c) 2012 Q Branch LLC. All rights reserved.
//

#import <Foundation/Foundation.h>


@class VSTheme;

@interface VSThemeLoader : NSObject

@property (nonatomic, strong, readonly) VSTheme  * __nullable defaultTheme;
@property (nonatomic, strong, readonly) NSArray  * __nullable themes;

- (VSTheme * __nullable)themeNamed:(NSString * __nonnull)themeName;

@end
