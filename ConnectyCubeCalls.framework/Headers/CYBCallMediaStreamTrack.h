//
//  CYBCallMediaStreamTrack.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallMacros.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallMediaStreamTrack class interface.
 Base class to describe class with media information.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallMediaStreamTrack)
@interface CYBCallMediaStreamTrack : NSObject

/**
 Media track user ID.

 @note nil for local
 */
@property (strong, nonatomic, readonly, nullable) NSNumber *userID;

/**
 Determines whether track is enabled or disabled for stream.
 */
@property (assign, nonatomic, getter=isEnabled) BOOL enabled;

// unavailable initializers
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
