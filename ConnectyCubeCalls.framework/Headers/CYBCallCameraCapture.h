//
//  CYBCallCameraCapture.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallVideoCapture.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

@class CYBCallVideoFormat;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallCameraCapture class interface.
 This class represent native camera capture based on CYBCallVideoCapture rtc capture.

 @see CYBCallVideoCapture
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallCameraCapture)
@interface CYBCallCameraCapture : CYBCallVideoCapture

/**
 AVCaptureSession is the central hub of the AVFoundation capture classes.
 */
@property (nonatomic, strong, readonly) AVCaptureSession *captureSession;

/**
 A CoreAnimation layer subclass for previewing the visual output of an AVCaptureSession.
 */
@property (nonatomic, strong, readonly) AVCaptureVideoPreviewLayer *previewLayer;

/**
 Current camera position.
 */
@property (nonatomic, assign) AVCaptureDevicePosition position;

/**
 Determines whether camera capture has started, but is not running yet (in set-up state).
 */
@property (nonatomic, readonly) BOOL hasStarted;

/**
 Determines whether capture session is running.
 */
@property (nonatomic, readonly) BOOL isRunning;

/**
 Supported orientation mask for camera.

 @discussion Change this if you want to prohibit some orientations for the camera

 @remark Default value is UIInterfaceOrientationMaskAll
 */
@property (nonatomic, assign) UIInterfaceOrientationMask supportedOrientations;

/**
 Initialize video capture with specific capture position.

 @param videoFormat CYBCallVideoFormat video format
 @param position    AVCaptureDevicePosition, must be back or front

 @return CYBCallVideoCapture instance
 */
- (instancetype)initWithVideoFormat:(CYBCallVideoFormat *)videoFormat
                           position:(AVCaptureDevicePosition)position NS_DESIGNATED_INITIALIZER;

/**
 Allows you to batch configuration changes to the session. Works while the session is stopped or running.

 @param configureBlock A handler block which applies the changes to the session

 @note If capture is running, this block will be called on the serial session queue. It is safe to call prepare/teardown or start/stop methods from capturer. Also, the session preset may be changed
 */
- (void)configureSession:(dispatch_block_t)configureBlock;

/**
 Start the capture session asynchronously with completion block.

 @param completion  operation completion block
 */
- (void)startSession:(nullable dispatch_block_t)completion;

/**
 Stop the capture session asynchronously with completion block.

 @param completion   operation completion block
 */
- (void)stopSession:(nullable dispatch_block_t)completion;

// MARK: Video format management

/**
 Current video format that is in use for requested camera position.

 @param position requested camera position

 @return CYBCallVideoFormat video format
 */
- (CYBCallVideoFormat *)videoFormatForPosition:(AVCaptureDevicePosition)position;

/**
 Set a specific video format for a requested camera position.

 @param videoFormat CYBCallVideoFormat wanted video format
 @param position requested camera position
 */
- (void)setVideoFormat:(CYBCallVideoFormat *)videoFormat forPosition:(AVCaptureDevicePosition)position;

// MARK: Helpers

/**
 Retrieve available array of CYBCallVideoFormat instances for given camera position.

 @param position requested camera position

 @return Array of possible CYBCallVideoFormat video formats for requested position
 */
+ (NSArray <CYBCallVideoFormat *> *)formatsWithPosition:(AVCaptureDevicePosition)position;

/**
 Check if device has back or front camera.

 @param cameraPosition AVCaptureDevicePosition
 */
- (BOOL)hasCameraForPosition:(AVCaptureDevicePosition)cameraPosition;

@end

NS_ASSUME_NONNULL_END
