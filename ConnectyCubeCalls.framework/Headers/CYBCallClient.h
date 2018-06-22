//
//  CYBCallClient.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallBaseClient.h>

#import <ConnectyCubeCalls/CYBCallClientDelegate.h>
#import <ConnectyCubeCalls/CYBCallTypes.h>

@class CYBCallSession;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallClient class interface.
 Represents client to initialize call session and notify about call's state.
 */
NS_SWIFT_NAME(CallClient)
@interface CYBCallClient : CYBCallBaseClient

/**
 CYBCallClient shared instance.

 @return CYBCallClient instance
 */
+ (instancetype)instance;

/**
 Initialize RTCClient signaling in order to receive and send calls.

 @note You should call this method before any interaction with ConnectyCubeCalls.
 */
+ (void)initializeRTC;

/**
 Add delegate to the observers list.

 @param delegate delegate that conforms to CYBCallClientDelegate protocol

 @see CYBCallClientDelegate
 */
- (void)addDelegate:(id<CYBCallClientDelegate>)delegate;

/**
 Remove delegate from the observers list.

 @param delegate delegate that conforms to CYBCallClientDelegate protocol

 @see CYBCallClientDelegate
 */
- (void)removeDelegate:(id<CYBCallClientDelegate>)delegate;

/**
 Create new session.

 @param opponents        opponents IDs, array of NSNumber instances
 @param conferenceType   Type of conference. 'CYBCallConferenceTypeAudio' and 'CYBCallConferenceTypeVideo' values are available

 @return New CYBCallSession instance
 */
- (CYBCallSession *)createNewSessionWithOpponents:(NSArray <NSNumber *> *)opponents
                             withConferenceType:(CYBCallConferenceType)conferenceType;

@end

NS_ASSUME_NONNULL_END
