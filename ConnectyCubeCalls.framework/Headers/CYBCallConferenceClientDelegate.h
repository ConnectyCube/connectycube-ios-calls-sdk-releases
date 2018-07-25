//
//  CYBCallConferenceClientDelegate.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallBaseClientDelegate.h>
#import <ConnectyCubeCalls/CYBCallTypes.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

@class CYBCallConferenceSession;

/**
 Conference client protocol.

 @note Enterprise-only feature

 @see CYBCallConferenceClient, https://connectycube.com/pricing/
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallConferenceClientDelegate)
@protocol CYBCallConferenceClientDelegate <CYBCallBaseClientDelegate>

/**
 Protocol methods down below are optional and not required to be implemented.
 */
@optional

/**
 Called when session was created on server.

 @param session CYBCallConferenceSession instance

 @discussion When this method is called, session instance that was already created by CYBCallConferenceClient will be assigned valid session ID from server.

 @see CYBCallConferenceSession, CYBCallConferenceClient
 */
- (void)didCreateNewSession:(CYBCallConferenceSession *)session;

/**
 Called when join to session is performed and acknowledged by server.

 @param session CYBCallConferenceSession instance
 @param chatDialogID chat dialog ID
 @param publishersList array of user IDs, that are currently publishers

 @see CYBCallConferenceSession
 */
- (void)session:(CYBCallConferenceSession *)session didJoinChatDialogWithID:(NSString *)chatDialogID publishersList:(NSArray <NSNumber *> *)publishersList;

/**
 Called when new publisher did join.

 @param session CYBCallConferenceSession instance
 @param userID new publisher user ID

 @see CYBCallConferenceSession
 */
- (void)session:(CYBCallConferenceSession *)session didReceiveNewPublisherWithUserID:(NSNumber *)userID;

/**
 Called when publisher did leave.

 @param session CYBCallConferenceSession instance
 @param userID publisher that left user ID

 @see CYBCallConferenceSession
 */
- (void)session:(CYBCallConferenceSession *)session publisherDidLeaveWithUserID:(NSNumber *)userID;

/**
 Called when session did receive error from server.

 @param session CYBCallConferenceSession instance
 @param error received error from server

 @note Error doesn't necessarily means that session is closed. Can be just a minor error that can be fixed/ignored.

 @see CYBCallConferenceSession
 */
- (void)session:(CYBCallConferenceSession *)session didReceiveError:(NSError *)error;

/**
 Called when slowlink was received.

 @param session  CYBCallConferenceSession instance
 @param uplink   whether the issue is uplink or not
 @param nacks    number of nacks

 @discussion this callback is triggered when serber reports trouble either sending or receiving media on the specified connection, typically as a consequence of too many NACKs received from/sent to the user in the last second: for instance, a slowLink with uplink=true means you notified several missing packets from server, while uplink=false means server is not receiving all your packets.

 @note useful to figure out when there are problems on the media path (e.g., excessive loss), in order to possibly react accordingly (e.g., decrease the bitrate if most of our packets are getting lost).

 @see CYBCallConferenceSession
 */
- (void)session:(CYBCallConferenceSession *)session didReceiveSlowlinkWithUplink:(BOOL)uplink nacks:(NSNumber *)nacks;

/**
 Called when media receiving state was changed on server.

 @param session CYBCallConferenceSession instance
 @param mediaType media type
 @param receiving whether media is receiving by server

 @see CYBCallConferenceSession, CYBCallConferenceMediaType
 */
- (void)session:(CYBCallConferenceSession *)session didChangeMediaStateWithType:(CYBCallConferenceMediaType)mediaType receiving:(BOOL)receiving;

/**
 Session did initiate close request.

 @param session CYBCallConferenceSession instance

 @discussion 'sessionDidClose:withTimeout:' will be called after server will close session with callback.

 @see CYBCallConferenceSession
 */
- (void)sessionWillClose:(CYBCallConferenceSession *)session;

/**
 Called when session was closed completely on server.

 @param session CYBCallConferenceSession instance
 @param timeout whether session was closed due to timeout on server

 @see CYBCallConferenceSession
 */
- (void)sessionDidClose:(CYBCallConferenceSession *)session withTimeout:(BOOL)timeout;

@end
