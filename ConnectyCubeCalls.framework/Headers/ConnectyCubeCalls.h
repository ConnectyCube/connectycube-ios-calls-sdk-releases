//
//  ConnectyCubeCalls.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCubeCalls/CYBCallAudioSession.h>
#import <ConnectyCubeCalls/CYBCallAudioSessionConfiguration.h>
#import <ConnectyCubeCalls/CYBCallAudioTrack.h>
#import <ConnectyCubeCalls/CYBCallBaseClient.h>
#import <ConnectyCubeCalls/CYBCallBaseClientDelegate.h>
#import <ConnectyCubeCalls/CYBCallBaseSession.h>
#import <ConnectyCubeCalls/CYBCallBitrateTracker.h>
#import <ConnectyCubeCalls/CYBCallCameraCapture.h>
#import <ConnectyCubeCalls/CYBCallClient.h>
#import <ConnectyCubeCalls/CYBCallClientDelegate.h>
#import <ConnectyCubeCalls/CYBCallConfig.h>
#import <ConnectyCubeCalls/CYBCallIceServer.h>
#import <ConnectyCubeCalls/CYBCallLocalAudioTrack.h>
#import <ConnectyCubeCalls/CYBCallLocalVideoTrack.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>
#import <ConnectyCubeCalls/CYBCallMediaStream.h>
#import <ConnectyCubeCalls/CYBCallMediaStreamConfiguration.h>
#import <ConnectyCubeCalls/CYBCallMediaStreamTrack.h>
#import <ConnectyCubeCalls/CYBCallRecorder.h>
#import <ConnectyCubeCalls/CYBCallRemoteVideoView.h>
#import <ConnectyCubeCalls/CYBCallSession.h>
#import <ConnectyCubeCalls/CYBCallStatsReport.h>
#import <ConnectyCubeCalls/CYBCallTimer.h>
#import <ConnectyCubeCalls/CYBCallTypes.h>
#import <ConnectyCubeCalls/CYBCallVideoCapture.h>
#import <ConnectyCubeCalls/CYBCallVideoFormat.h>
#import <ConnectyCubeCalls/CYBCallVideoFrame.h>
#import <ConnectyCubeCalls/CYBCallVideoTrack.h>
#import <ConnectyCubeCalls/RTCVideoFrame.h>
#import <ConnectyCubeCalls/RTCVideoFrameBuffer.h>
#import <ConnectyCubeCalls/RTCVideoRenderer.h>
#import <ConnectyCubeCalls/UIDevice+CYBCallPerformance.h>

/*
 *  Enterprise-only.
 *
 *  @see https://connectycube.com/pricing/
 */
#import <ConnectyCubeCalls/CYBCallConferenceClient.h>
#import <ConnectyCubeCalls/CYBCallConferenceClientDelegate.h>
#import <ConnectyCubeCalls/CYBCallConferenceSession.h>

//! Framework version 1.2
FOUNDATION_EXPORT NSString * const ConnectyCubeCallsFrameworkVersion;

//! WebRTC revision 24701
FOUNDATION_EXPORT NSString * const ConnectyCubeCallsRevision;
