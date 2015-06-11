//
//  VSTheme.h
//  Q Branch LLC
//
//  Created by Brent Simmons on 6/26/13.
//  Copyright (c) 2012 Q Branch LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, VSTextCaseTransform) {
    VSTextCaseTransformNone,
    VSTextCaseTransformUpper,
    VSTextCaseTransformLower
};


@class VSAnimationSpecifier;

@interface VSTheme : NSObject

- (id __nullable)initWithDictionary:(NSDictionary * __nonnull)themeDictionary;

@property (nonatomic, strong) NSString * __nullable name;
@property (nonatomic, weak) VSTheme * __nullable parentTheme; /*can inherit*/

- (BOOL)boolForKey:(NSString * __nonnull )key;
- (NSString * __nullable)stringForKey:(NSString * __nonnull )key;
- (NSInteger)integerForKey:(NSString * __nonnull )key;
- (CGFloat)floatForKey:(NSString * __nonnull )key;
- (UIImage * __nullable)imageForKey:(NSString * __nonnull )key; /*Via UIImage imageNamed:*/
- (UIColor * __nonnull)colorForKey:(NSString * __nonnull )key; /*123ABC or #123ABC: 6 digits, leading # allowed but not required*/
- (UIColor* __nonnull)colorForName:(NSString * __nonnull)name; /* Returns a color based on another DB5 entry key name which can be resolved to a color */

- (UIEdgeInsets)edgeInsetsForKey:(NSString * __nonnull )key; /*xTop, xLeft, xRight, xBottom keys*/
- (UIFont * __nonnull)fontForKey:(nonnull NSString *)key; /*x and xSize keys*/
- (CGPoint)pointForKey:(nonnull NSString *)key; /*xX and xY keys*/
- (CGSize)sizeForKey:(nonnull NSString *)key; /*xWidth and xHeight keys*/
- (NSTimeInterval)timeIntervalForKey:(nonnull NSString *)key;

- (UIViewAnimationOptions)curveForKey:(nonnull NSString *)key; /*Possible values: easeinout, easeout, easein, linear*/
- (VSAnimationSpecifier * __nonnull)animationSpecifierForKey:(nonnull NSString *)key; /*xDuration, xDelay, xCurve*/

- (VSTextCaseTransform)textCaseTransformForKey:(nonnull NSString *)key; /*lowercase or uppercase -- returns VSTextCaseTransformNone*/

@end


@interface VSTheme (Animations)

- (void)animateWithAnimationSpecifierKey:(nonnull NSString *)animationSpecifierKey animations:( void (^ __nonnull )(void))animations completion:( void (^ __nullable )(BOOL finished))completion;

@end


@interface VSAnimationSpecifier : NSObject

@property (nonatomic, assign) NSTimeInterval delay;
@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign) UIViewAnimationOptions curve;

@end

