//
//  CYBCallMediaStream.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBCallLocalAudioTrack;
@class CYBCallLocalVideoTrack;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallMediaStream class interface.
 This class represents media information such as video and audio tracks.
 
 @note You can access an instance of this class from CYBCallSession class, localMediaStream property.
 */
NS_SWIFT_NAME(CallMediaStream)
@interface CYBCallMediaStream : NSObject

/**
 Audio track, can be enabled or disabled.
 */
@property (strong, nonatomic, readonly) CYBCallLocalAudioTrack *audioTrack;

/**
 Video track, can be enabled or disabled.
 */
@property (strong, nonatomic, readonly) CYBCallLocalVideoTrack *videoTrack;

// unavailable initializers
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
