//
//  CYBCallVideoTrack.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallMediaStreamTrack.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RTCVideoRenderer;

/**
 CYBCallVideoTrack class interface.
 This class represents remote audio track.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallVideoTrack)
@interface CYBCallVideoTrack : CYBCallMediaStreamTrack

/**
 Register a renderer that will render all frames received on this track.

 @param renderer class that conforms to RTCVideoRenderer protocol

 @see RTCVideoRenderer
 */
- (void)addRenderer:(id<RTCVideoRenderer>)renderer;

/**
 Unregister a renderer.

 @param renderer class that conforms to RTCVideoRenderer protocol

 @see RTCVideoRenderer
 */
- (void)removeRenderer:(id<RTCVideoRenderer>)renderer;

@end

NS_ASSUME_NONNULL_END
