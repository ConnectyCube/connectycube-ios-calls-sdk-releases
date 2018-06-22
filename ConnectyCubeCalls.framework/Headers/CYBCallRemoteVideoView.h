//
//  CYBCallRemoteVideoView.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import <ConnectyCubeCalls/RTCVideoRenderer.h>

NS_ASSUME_NONNULL_BEGIN

@class CYBCallRemoteVideoView;
@class CYBCallVideoTrack;

NS_SWIFT_NAME(CallRemoteVideoViewDelegate)
@protocol CYBCallRemoteVideoViewDelegate

/**
 *  Called when video view size was changed.
 *
 *  @param videoView CYBCallRemoteVideoView instance
 *  @param size new size
 */
- (void)videoView:(CYBCallRemoteVideoView *)videoView didChangeVideoSize:(CGSize)size;

@end

/**
 *  CYBCallRemoteVideoView is an RTCVideoRenderer which renders video frames in its
 *  bounds using OpenGLES 2.0.
 */
NS_SWIFT_NAME(CallRemoteVideoView)
@interface CYBCallRemoteVideoView : UIView <RTCVideoRenderer>

/**
 *  Delegate that conforms to CYBCallRemoteVideoViewDelegate protocol.
 *
 *  @see CYBCallRemoteVideoViewDelegate
 */
@property (nonatomic, weak) id<CYBCallRemoteVideoViewDelegate> delegate;

/**
 *	Options are AVLayerVideoGravityResizeAspect, AVLayerVideoGravityResizeAspectFill
 *  and AVLayerVideoGravityResize. AVLayerVideoGravityResizeAspect is default.
 *  See <AVFoundation/AVAnimation.h> for a description of these options.
 *
 *  Default value: AVLayerVideoGravityResize
 */
@property (nonatomic, copy) NSString *videoGravity;

/**
 *  Set video track
 *
 *  @param videoTrack CYBCallVideoTrack instance
 */
- (void)setVideoTrack:(CYBCallVideoTrack *)videoTrack;

@end

NS_ASSUME_NONNULL_END
