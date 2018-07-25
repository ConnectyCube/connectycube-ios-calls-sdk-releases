//
//  CYBCallVideoFormat.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallTypes.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallVideoFormat class interface.
 This class represents format management.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallVideoFormat)
@interface CYBCallVideoFormat : NSObject <NSCoding>

/**
 Frame width.
 */
@property (nonatomic, assign) NSUInteger width;

/**
 Frame height.
 */
@property (nonatomic, assign) NSUInteger height;

/**
 Frames per second.
 */
@property (nonatomic, assign) NSUInteger frameRate;

/**
 Pixel format.
 */
@property (nonatomic, assign) CYBCallPixelFormat pixelFormat;

/**
 Initialize video format with all settings.

 @param width       frame width
 @param height      frame height
 @param frameRate   frame rate, default is 30 FPS
 @param pixelFormat CYBCallPixelFormat type

 @return CYBCallVideoFormat instance
 */
+ (instancetype)videoFormatWithWidth:(NSUInteger)width
                              height:(NSUInteger)height
                           frameRate:(NSUInteger)frameRate
                         pixelFormat:(CYBCallPixelFormat)pixelFormat;

/**
 Default video format.

 @remark width: 640
         height: 480
         framerate: 30
         pixelFormat: CYBCallPixelFormat420f

 @return CYBCallVideoFormat instance
 */
+ (instancetype)defaultFormat;
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
