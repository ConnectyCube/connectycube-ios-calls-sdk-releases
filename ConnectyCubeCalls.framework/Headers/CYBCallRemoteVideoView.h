//
//  CYBCallRemoteVideoView.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import <ConnectyCubeCalls/CYBCallMacros.h>
#import <ConnectyCubeCalls/RTCVideoRenderer.h>

NS_ASSUME_NONNULL_BEGIN

@class CYBCallRemoteVideoView;
@class CYBCallVideoTrack;

CYBCALL_EXPORT
NS_SWIFT_NAME(CallRemoteVideoViewDelegate)
@protocol CYBCallRemoteVideoViewDelegate

/**
 Called when video view size was changed.

 @param videoView CYBCallRemoteVideoView instance
 @param size size new size
 */
- (void)videoView:(CYBCallRemoteVideoView *)videoView didChangeVideoSize:(CGSize)size;

@end

/**
 CYBCallRemoteVideoView is an RTCVideoRenderer which renders video frames in its bounds using Metal (default) or OpenGLES 2.0.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallRemoteVideoView)
@interface CYBCallRemoteVideoView : UIView <RTCVideoRenderer>

/**
 Determines whether MetalKit should be used for drawing video frames (when possible). If not, GLKit will be used instead.
 
 @discussion Using MetalKit always if available which is the best performance wise. Otherwise just using old method by drawing video frames with GLKit.
 
 @remark Default value is YES. This is a class property and will be used by every instance of the class.
 
 @see https://developer.apple.com/documentation/metalkit
 */
@property (nonatomic, assign, class) BOOL preferMetal;

/**
 Delegate that conforms to CYBCallRemoteVideoViewDelegate protocol.
 
 @see CYBCallRemoteVideoViewDelegate
 */
@property (nonatomic, weak) id<CYBCallRemoteVideoViewDelegate> delegate;

/**
 Options are AVLayerVideoGravityResizeAspect, AVLayerVideoGravityResizeAspectFill and AVLayerVideoGravityResize. AVLayerVideoGravityResizeAspect is default.
 
 @remark Default value: AVLayerVideoGravityResize
 
 @see <AVFoundation/AVAnimation.h> for a description of these options.
 */
@property (nonatomic, copy) NSString *videoGravity;

/**
 Set video track
 
 @param videoTrack CYBCallVideoTrack instance
 */
- (void)setVideoTrack:(CYBCallVideoTrack *)videoTrack;

@end

NS_ASSUME_NONNULL_END
