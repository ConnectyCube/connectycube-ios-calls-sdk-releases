//
//  CYBCallVideoFrame.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/RTCVideoFrame.h>

/**
 CYBCallVideoFrame class interface.
 This class represents an entity for storing pixel buffer and corresponding information.
 */
NS_SWIFT_NAME(CallVideoFrame)
@interface CYBCallVideoFrame : RTCVideoFrame

@property (nonatomic, readonly) CVPixelBufferRef pixelBuffer;
@property (nonatomic, readonly) CYBCallVideoRotation videoRotation;

/**
 Initialize video frame with pixel buffer.

 @param pixelBuffer CVPixelBufferRef

 @return CYBCallVideoFrame instance
 */
- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)pixelBuffer videoRotation:(CYBCallVideoRotation)videoRotation;

@end
