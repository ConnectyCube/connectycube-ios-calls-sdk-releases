//
//  CYBCallTypes.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#ifndef CYBCallTypes_h
#define CYBCallTypes_h

#import <Foundation/Foundation.h>
#import <CoreVideo/CoreVideo.h>

/**
 Connection state.

 - CYBCallConnectionStateUnknown: connection state is unknown; this can occur when non of the others states are fit for the current situation
 - CYBCallConnectionStateNew: connection was created and ready for the next step
 - CYBCallConnectionStatePending: connection is in pending state for other actions to occur
 - CYBCallConnectionStateConnecting: one or more of the ICE transports are currently in the process of establishing a connection
 - CYBCallConnectionStateChecking: the ICE agent has been given one or more remote candidates and is checking pairs of local and remote candidates against one another to try to find a compatible match, but has not yet found a pair which will allow the peer connection to be made; it's possible that gathering of candidates is also still underway
 - CYBCallConnectionStateConnected: connection was performed successfully
 - CYBCallConnectionStateDisconnected: disconnected, but not closed; can still be reconnected
 - CYBCallConnectionStateClosed: connection was closed
 - CYBCallConnectionStateCount: ICE connection reached max numbers
 - CYBCallConnectionStateDisconnectTimeout: connection was disconnected by timeout
 - CYBCallConnectionStateNoAnswer: connection did not receive answer from the opponent user
 - CYBCallConnectionStateRejected: connection was rejected by the opponent user
 - CYBCallConnectionStateHangUp: connection was hanged up by the opponent user
 - CYBCallConnectionStateFailed: one or more of the ICE transports on the connection is in the failed state; this can occur on the different circumstances, e.g. bad network etc
 */
typedef NS_ENUM(NSUInteger, CYBCallConnectionState) {
    
    CYBCallConnectionStateUnknown = 0,
    CYBCallConnectionStateNew,
    CYBCallConnectionStatePending,
    CYBCallConnectionStateConnecting,
    CYBCallConnectionStateChecking,
    CYBCallConnectionStateConnected,
    CYBCallConnectionStateDisconnected,
    CYBCallConnectionStateClosed,
    CYBCallConnectionStateCount,
    CYBCallConnectionStateDisconnectTimeout,
    CYBCallConnectionStateNoAnswer,
    CYBCallConnectionStateRejected,
    CYBCallConnectionStateHangUp,
    CYBCallConnectionStateFailed
} NS_SWIFT_NAME(CallConnectionState);

/**
 Session state.

 - CYBCallSessionStateNew: session was successfully created and ready for the next step
 - CYBCallSessionStatePending: session is in pending state for other actions to occur
 - CYBCallSessionStateConnecting: session is in progress of establishing connection
 - CYBCallSessionStateConnected: session was successfully established
 - CYBCallSessionStateClosed: session was closed
 */
typedef NS_ENUM(NSUInteger, CYBCallSessionState) {
    
    CYBCallSessionStateNew,
    CYBCallSessionStatePending,
    CYBCallSessionStateConnecting,
    CYBCallSessionStateConnected,
    CYBCallSessionStateClosed
} NS_SWIFT_NAME(CallSessionState);

/**
 Conference types.

 - CYBCallConferenceTypeVideo: video conference type
 - CYBCallConferenceTypeAudio: audio conference type
 */
typedef NS_ENUM (NSUInteger, CYBCallConferenceType) {
    
    CYBCallConferenceTypeVideo = 1,
    CYBCallConferenceTypeAudio = 2,
} NS_SWIFT_NAME(CallConferenceType);

/**
 Available pixel formats.

 - CYBCallPixelFormat420f: Bi-Planar Component Y'CbCr 8-bit 4:2:0, full-range (luma=[0,255] chroma=[1,255]);  baseAddr points to a big-endian CVPlanarPixelBufferInfo_YCbCrBiPlanar struct
 -  CYBCallPixelFormatARGB: 32 bit ARGB
 */
typedef NS_ENUM(OSType, CYBCallPixelFormat) {
    
    CYBCallPixelFormat420f = kCVPixelFormatType_420YpCbCr8BiPlanarFullRange,
    CYBCallPixelFormatARGB = kCVPixelFormatType_32ARGB
} NS_SWIFT_NAME(CallPixelFormat);

/**
 Log level.

 - CYBCallLogLevelNothing: Nothing in Log
 - CYBCallLogLevelVerbose: Full ConnectyCubeCalls Log
 - CYBCallLogLevelVerboseWithWebRTC: Full ConnectyCubeCalls and WebRTC native Log
 */
typedef NS_ENUM(NSInteger, CYBCallLogLevel) {
    
    CYBCallLogLevelNothing = 0,
    CYBCallLogLevelVerbose,
    CYBCallLogLevelVerboseWithWebRTC
} NS_SWIFT_NAME(CallLogLevel);

/**
 Video rotation.

 - CYBCallVideoRotation_0: no rotation
 - CYBCallVideoRotation_90: 90 degrees rotation
 - CYBCallVideoRotation_180: 180 degrees rotation
 - CYBCallVideoRotation_270: 270 degrees rotation
 */
typedef NS_ENUM(NSUInteger, CYBCallVideoRotation) {
    
    CYBCallVideoRotation_0 = 0,
    CYBCallVideoRotation_90 = 90,
    CYBCallVideoRotation_180 = 180,
    CYBCallVideoRotation_270 = 270
} NS_SWIFT_NAME(CallVideoRotation);

/**
 Conference media type.

 - CYBCallConferenceMediaTypeUnknown: Unknown / not supported media type
 - CYBCallConferenceMediaTypeAudio: media type audio
 - CYBCallConferenceMediaTypeVideo: media type video
 */
typedef NS_ENUM(NSUInteger, CYBCallConferenceMediaType) {
    CYBCallConferenceMediaTypeUnknown,
    CYBCallConferenceMediaTypeAudio,
    CYBCallConferenceMediaTypeVideo
} NS_SWIFT_NAME(CallConferenceMediaType);

#endif /* CYBCallTypes_h */
