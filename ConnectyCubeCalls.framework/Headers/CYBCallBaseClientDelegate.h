//
//  CYBCallBaseClientDelegate.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallTypes.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

@class CYBCallBaseSession;
@class CYBCallStatsReport;
@class CYBCallAudioTrack;
@class CYBCallVideoTrack;

NS_ASSUME_NONNULL_BEGIN

/**
 Base client protocol.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallBaseClientDelegate)
@protocol CYBCallBaseClientDelegate <NSObject>

/**
 Protocol methods down below are optional and not required to be implemented.
 */
@optional

/**
 Called by timeout with updated stats report for user ID.

 @param session CYBCallSession instance
 @param report  CYBCallStatsReport instance
 @param userID  user ID

 @remark Configure time interval with [CYBCallConfig setStatsReportTimeInterval:timeInterval].
 */
- (void)session:(__kindof CYBCallBaseSession *)session updatedStatsReport:(CYBCallStatsReport *)report forUserID:(NSNumber *)userID;

/**
 Called when session state has been changed.

 @param session CYBCallSession instance
 @param state session state

 @discussion Use this to track a session state. As SDK 2.3 introduced states for session, you can now manage your own states based on this.
 */
- (void)session:(__kindof CYBCallBaseSession *)session didChangeState:(CYBCallSessionState)state;

/**
 Called when received remote audio track from user.

 @param audioTrack CYBCallAudioTrack instance
 @param userID     ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session receivedRemoteAudioTrack:(CYBCallAudioTrack *)audioTrack fromUser:(NSNumber *)userID;

/**
 Called when received remote video track from user.

 @param videoTrack CYBCallVideoTrack instance
 @param userID     ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session receivedRemoteVideoTrack:(CYBCallVideoTrack *)videoTrack fromUser:(NSNumber *)userID;

/**
 Called when connection is closed for user.

 @param session CYBCallSession instance
 @param userID  ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session connectionClosedForUser:(NSNumber *)userID;

/**
 Called when connection is initiated with user.

 @param session CYBCallSession instance
 @param userID  ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session startedConnectingToUser:(NSNumber *)userID;

/**
 Called when connection is established with user.

 @param session CYBCallSession instance
 @param userID  ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session connectedToUser:(NSNumber *)userID;

/**
 Called when disconnected from user.

 @param session CYBCallSession instance
 @param userID  ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session disconnectedFromUser:(NSNumber *)userID;

/**
 Called when connection failed with user.

 @param session CYBCallSession instance
 @param userID  ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session connectionFailedForUser:(NSNumber *)userID;

/**
 Called when session connection state changed for a specific user.

 @param session CYBCallSession instance
 @param state   state - @see CYBCallConnectionState
 @param userID  ID of user
 */
- (void)session:(__kindof CYBCallBaseSession *)session didChangeConnectionState:(CYBCallConnectionState)state forUser:(NSNumber *)userID;

@end

NS_ASSUME_NONNULL_END
