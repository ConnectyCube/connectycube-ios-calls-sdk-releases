//
//  CYBCallConferenceClient.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallBaseClient.h>

#import <ConnectyCubeCalls/CYBCallConferenceClientDelegate.h>
#import <ConnectyCubeCalls/CYBCallTypes.h>

@class CYBCallConferenceSession;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallConferenceClient class interface.
 Represents conference client and session management.

 @note Enterprise-only feature, conferenceEndpoint param must be set in CYBCallConfig

 @see CYBCallConfig, https://connectycube.com/pricing/
 */
NS_SWIFT_NAME(CallConferenceClient)
@interface CYBCallConferenceClient : CYBCallBaseClient

/**
 CYBCallConferenceClient shared instance.

 @return CYBCallConferenceClient instance
 */
+ (instancetype)instance;

/**
 Add delegate to the observers list.

 @param delegate delegate that conforms to CYBCallConferenceClientDelegate protocol

 @see CYBCallConferenceClientDelegate
 */
- (void)addDelegate:(id<CYBCallConferenceClientDelegate>)delegate;

/**
 Remove delegate from the observers list.

 @param delegate delegate that conforms to CYBCallConferenceClientDelegate protocol

 @see CYBCallConferenceClientDelegate
 */
- (void)removeDelegate:(id<CYBCallConferenceClientDelegate>)delegate;

/**
 Send create session request with conference type.

 @param chatDialogID chat dialog ID
 @param conferenceType conference type (video/audio)

 @note Returns session without ID. When session will be created on server ID will be assigned and session will be returned in 'didCreateNewSession:' callback.
 
 @see CYBCallConferenceClientDelegate, CYBCallConferenceType
 */
- (CYBCallConferenceSession *)createSessionWithChatDialogID:(NSString *)chatDialogID conferenceType:(CYBCallConferenceType)conferenceType;

@end

NS_ASSUME_NONNULL_END
