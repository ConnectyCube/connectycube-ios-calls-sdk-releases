//
//  CYBCallRecorder.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallTypes.h>

@class CYBCallAudioTrack;
@class CYBCallVideoTrack;
@class CYBCallRecorder;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallRecorder state.

 - CYBCallRecorderStateNotActive: not active
 - CYBCallRecorderStateActive: active and recording or waiting for media data
 - CYBCallRecorderStateFinalizing: finalizing recording file
 */
typedef NS_ENUM(NSUInteger, CYBCallRecorderState) {
    CYBCallRecorderStateNotActive,
    CYBCallRecorderStateActive,
    CYBCallRecorderStateFinalizing
} NS_SWIFT_NAME(CallRecorderState);

NS_SWIFT_NAME(CallRecorderDelegate)
@protocol CYBCallRecorderDelegate <NSObject>

/**
 Called when recorder did fail to record at some point.

 @param recorder CYBCallRecorder instance
 @param error specific error
 */
- (void)recorder:(CYBCallRecorder *)recorder didFailWithError:(NSError *)error;

@end

/**
 CYBCallRecorder class interface.
 This class represents webrtc audio/video recorder.
 */
NS_SWIFT_NAME(CallRecorder)
@interface CYBCallRecorder : NSObject

/**
 Current output file url.
 */
@property (strong, nonatomic, readonly, nullable) NSURL *outputFileURL;

/**
 Recorder state.
 
 @see CYBCallRecorderState
 */
@property (assign, atomic, readonly) CYBCallRecorderState state;

/**
 Determines whether microphone should be muted on record.
 
 @discussion Can be set at any time of class instance life.
 */
@property (assign, nonatomic, getter=isMicrophoneMuted) BOOL microphoneMuted;

/**
 Determines whether local audio recording from the mic is enabled or not.
 
 @discussion Use this property to stop and/or re-start local mic audio record. Use it, for example, if you need to turn off the local audio record or restart the audio unit.
 @remark Default value is YES.
 */
@property (assign, nonatomic, getter=isLocalAudioEnabled) BOOL localAudioEnabled;

/**
 Delegate that conforms to CYBCallRecorderDelegate protocol.
 */
@property (weak, nonatomic, nullable) id<CYBCallRecorderDelegate> delegate;

// unavailable initializers
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Set video recording format.
 
 @param width video width
 @param height video height
 @param bitrate video bitrate
 @param fps video fps
 
 @note You can only set this params while recording is not in active state (e.g. haven't started yet).
 
 @remark Default values are 640x480 with 636528 bitrate 30 fps
 
 @see https://www.dr-lex.be/info-stuff/videocalc.html for bitrate calculation
 */
- (void)setVideoRecordingWidth:(NSUInteger)width
                        height:(NSUInteger)height
                       bitrate:(NSUInteger)bitrate
                           fps:(NSUInteger)fps;

/**
 Set video recording orientation.
 
 @param videoRotation video rotation
 
 @note You can only set this params while recording is not in active state (e.g. haven't started yet).
 Cannot be changed mid record.
 
 @remark Default is 0 degrees, e.g. landscape orientation.
 */
- (void)setVideoRecordingRotation:(CYBCallVideoRotation)videoRotation;

/**
 Start record with url.
 
 @param url preferred file url
 
 @note Url must contain mp4 extension.
 */
- (void)startRecordWithFileURL:(NSURL *)url;

/**
 Stop record.
 
 @param completion completion block with file url if record was successful
 
 @discussion Async operation that might take some time until record is finalized.
 
 @note File url will be nil if record failed, didn't start or there was nothing to record.
 */
- (void)stopRecord:(nullable void (^)(NSURL * _Nullable file))completion;

@end

NS_ASSUME_NONNULL_END
