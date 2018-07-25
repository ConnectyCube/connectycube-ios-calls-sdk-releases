//
//  CYBCallBaseSession.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallTypes.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

@class CYBCallMediaStream;
@class CYBCallAudioTrack;
@class CYBCallVideoTrack;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallBaseSession class interface.
 This class represents basic session methods.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallBaseSession)
@interface CYBCallBaseSession : NSObject

/**
 Conference type.

 @remark
    CYBCallConferenceTypeVideo - video conference
    CYBCallConferenceTypeAudio - audio conference

 @see CYBCallConferenceType
 */
@property (assign, nonatomic, readonly) CYBCallConferenceType conferenceType;

/**
 Session state.

 @see CYBCallSessionState
 */
@property (assign, nonatomic, readonly) CYBCallSessionState state;

/**
 Current user ID.
 */
@property (assign, nonatomic, readonly) NSNumber *currentUserID;

/**
 Local media stream with audio and video (if video conferene) tracks.

 @discussion CYBCallMediaStream instance that has both video and audio tracks and allows to manage them.
 */
@property (strong, nonatomic, readonly) CYBCallMediaStream *localMediaStream;

// unavailable initializers
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Remote audio track with opponent user ID.

 @param userID opponent user ID

 @return CYBCallAudioTrack audio track instance
 */
- (CYBCallAudioTrack *)remoteAudioTrackWithUserID:(NSNumber *)userID;

/**
 Remote video track with opponent user ID.

 @param userID opponent user ID

 @return CYBCallVideoTrack video track instance
 */
- (CYBCallVideoTrack *)remoteVideoTrackWithUserID:(NSNumber *)userID;

/**
 Connection state for opponent user ID.

 @param userID opponent user ID

 @return CYBCallConnectionState connection state for opponent user ID
 */
- (CYBCallConnectionState)connectionStateForUser:(NSNumber *)userID;

/**
 Limit self-media bitrate in the current session for all existent connections.

 @param bitrate bitrate value

 @note Any newly established connection in this session will not be limited.
 */
- (void)setBitrate:(NSUInteger)bitrate;

@end

NS_ASSUME_NONNULL_END
