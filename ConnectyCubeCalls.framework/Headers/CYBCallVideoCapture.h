//
//  CYBCallVideoCapture.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallMacros.h>

@class RTCVideoFrame;
@class CYBCallLocalVideoTrack;

/**
 CYBCallVideoCapture class interface.
 This class allows you to send frames to your opponent using any video source.
 
 @see CYBCallCameraCapture for sending frames from native camera.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallVideoCapture)
@interface CYBCallVideoCapture : NSObject

/**
 Serial queue to process video frames.

 @remark For example AVCaptureVideoDataOutput needs a queue, so you can call AVCaptureVideoDataOutput instance setSampleBufferDelegate:self queue:self.videoQueue
 */
@property (nonatomic, strong, readonly) dispatch_queue_t videoQueue;

/**
 Called when video track is set.

 @param videoTrack local video track instance
 */
- (void)didSetToVideoTrack:(CYBCallLocalVideoTrack *)videoTrack;

/**
 Called when video track was removed.

 @param videoTrack local video track instance
 */
- (void)didRemoveFromVideoTrack:(CYBCallLocalVideoTrack *)videoTrack;

/**
 Send video frames to opponents.

 @param frame video frame to send
 */
- (void)sendVideoFrame:(__kindof RTCVideoFrame *)frame;

/**
 Adapt frames to a specific width, height and fps before sending.

 @param width desired frame width
 @param height desired frame height
 @param fps desired fps

 @discussion Calling this function will cause frames to be scaled down to the
             requested resolution. Also, frames will be cropped to match the
             requested aspect ratio, and frames will be dropped to match the
             requested fps. The requested aspect ratio is orientation agnostic and
             will be adjusted to maintain the input orientation, so it doesn't
             matter if e.g. 1280x720 or 720x1280 is requested.
 */
- (void)adaptOutputFormatToWidth:(NSUInteger)width height:(NSUInteger)height fps:(NSUInteger)fps;

@end
