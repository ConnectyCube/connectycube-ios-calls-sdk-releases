//
//  CYBCallAudioTrack.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallMediaStreamTrack.h>

#import <CoreAudio/CoreAudioTypes.h>
#import <CoreMedia/CoreMedia.h>

@class CYBCallAudioTrack;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallAudioTrackSinkInterface protocol.
 Used to sink audio data in real time for a specific audio track.
 */
NS_SWIFT_NAME(CallAudioTrackSinkInterface)
@protocol CYBCallAudioTrackSinkInterface <NSObject>

/**
 Audio track sink interface callback.

 @param audioTrack              CYBCallAudioTrack instance that is responsible for received audio data
 @param audioBufferList         audio buffer list with audio buffer (const)
 @param audioStreamDescription  audio stream description for audio buffer
 @param numberOfFrames          number of frames in current packet
 @param time                    media timestamp in nano seconds scale

 @note Do not modify audioBufferList struct in any way to avoid memory issues. But rather copy its data if you want to perform any memory modifications on audio data
 */
-     (void)audioTrack:(CYBCallAudioTrack *)audioTrack
didSinkAudioBufferList:(const AudioBufferList *)audioBufferList
audioStreamDescription:(const AudioStreamBasicDescription)audioStreamDescription
        numberOfFrames:(size_t)numberOfFrames
                  time:(CMTime)time;

@end

/**
 CYBCallAudioTrack class interface.
 This class represents remote audio track.
 */
NS_SWIFT_NAME(CallAudioTrack)
@interface CYBCallAudioTrack : CYBCallMediaStreamTrack

/**
 Volume of audio track.

 @discussion Sets the volume for the specific track

 @remark |volume] is a gain value in the range [0, 10]
 */
@property (assign, nonatomic) double volume;

/**
 Add sink.

 @param sink class instance that conforms to CYBCallAudioTrackSinkInterface protocol

 @see CYBCallAudioTrackSinkInterface
 */
- (void)addSink:(id<CYBCallAudioTrackSinkInterface>)sink;

/**
 Remove sink.

 @param sink class instance that conforms to CYBCallAudioTrackSinkInterface protocol

 @see CYBCallAudioTrackSinkInterface
 */
- (void)removeSink:(id<CYBCallAudioTrackSinkInterface>)sink;

@end

NS_ASSUME_NONNULL_END
