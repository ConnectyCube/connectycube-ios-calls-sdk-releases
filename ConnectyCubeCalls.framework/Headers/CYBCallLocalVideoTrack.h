//
//  CYBCallLocalVideoTrack.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallMediaStreamTrack.h>

@class CYBCallVideoCapture;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallLocalVideoTrack class interface.
 This class represents local video track.
 */
NS_SWIFT_NAME(CallLocalVideoTrack)
@interface CYBCallLocalVideoTrack : CYBCallMediaStreamTrack

/**
 Video capture instance.
 */
@property (weak, nonatomic, nullable) CYBCallVideoCapture *videoCapture;

@end

NS_ASSUME_NONNULL_END
