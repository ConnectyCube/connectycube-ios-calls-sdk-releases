//
//  CYBCallClientDelegate.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallMacros.h>

@class CYBCallSession;

@protocol CYBCallBaseClientDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallClientDelegate protocol.

 @note All delegate methods will be called on main thread due to webrtc restrictions.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallClientDelegate)
@protocol CYBCallClientDelegate <CYBCallBaseClientDelegate>

/**
 Protocol methods down below are optional and not required to be implemented.
 */
@optional

/**
 Called when someone started a new session with you.

 @param session  CYBCallSession instance
 @param userInfo The user information dictionary for the new session. May be nil.
 */
- (void)didReceiveNewSession:(CYBCallSession *)session userInfo:(nullable NSDictionary <NSString *, NSString *> *)userInfo;

/**
 Called in case when user did not respond to your call within timeout.

 @param userID ID of user

 @remark use +[CYBCallConfig setAnswerTimeInterval:value] to set answer time interval default value: 45 seconds
 */
- (void)session:(CYBCallSession *)session userDidNotRespond:(NSNumber *)userID;

/**
 Called in case when user rejected you call.

 @param userID ID of user
 @param userInfo The user information dictionary for the reject call. May be nil
 */
- (void)session:(CYBCallSession *)session rejectedByUser:(NSNumber *)userID userInfo:(nullable NSDictionary <NSString *, NSString *> *)userInfo;

/**
 Called in case when user accepted your call.

 @param userID ID of user
 */
- (void)session:(CYBCallSession *)session acceptedByUser:(NSNumber *)userID userInfo:(nullable NSDictionary <NSString *, NSString *> *)userInfo;

/**
 Called when user hung up.

 @param session     CYBCallSession instance
 @param userID      ID of user
 @param userInfo    The user information dictionary for the hung up; may be nil
 */
- (void)session:(CYBCallSession *)session hungUpByUser:(NSNumber *)userID userInfo:(nullable NSDictionary <NSString *, NSString *> *)userInfo;

/**
 Called when session is closed.

 @param session CYBCallSession instance
 */
- (void)sessionDidClose:(CYBCallSession *)session;

@end

NS_ASSUME_NONNULL_END
