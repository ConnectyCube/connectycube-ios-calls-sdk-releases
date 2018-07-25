//
//  CYBCallMediaStreamConfiguration.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallMacros.h>

typedef NS_ENUM(NSUInteger, CYBCallAudioCodec) {
    
    CYBCallAudioCodecOpus,
    CYBCallAudioCodecISAC,
    CYBCallAudioCodeciLBC
} NS_SWIFT_NAME(CallAudioCodec);

/**
 Video codec description.

 - CYBCallVideoCodecVP8: VP8 software supported video codec
 - CYBCallVideoCodecH264Baseline: H264 baseline hardware supported video codec, preferred, low-cost
 - CYBCallVideoCodecH264High: H264 high hardware supported video codec for high resolutions, primary profile for broadcast
 
 @discussion H264 is the best one for iOS devices, since it is hardware supported. Use it whenever is possible. H264 baseline is the best solution for your typical video calls
 */
typedef NS_ENUM(NSUInteger, CYBCallVideoCodec) {
    
    CYBCallVideoCodecVP8,
    CYBCallVideoCodecH264Baseline,
    CYBCallVideoCodecH264High,
} NS_SWIFT_NAME(CallVideoCodec);

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallMediaStreamConfiguration class interface.
 This class represents configuration of audio and video settings.
 
 @remark Default media stream configuration available with [CYBCallConfig mediaStreamConfiguration]. You can instantiate defaulConfiguration, change and then apply with [CYBCallConfig setMediaStreamConfiguration:].
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallMediaStreamConfiguration)
@interface CYBCallMediaStreamConfiguration : NSObject <NSCoding>

/**
 Audio codec.
 
 @see CYBCallAudioCodec
 */
@property (nonatomic, assign) CYBCallAudioCodec audioCodec;

/**
 Audio bandwidth.

 @note When set to 0 it is skipped in session description
 */
@property (nonatomic, assign) NSInteger audioBandwidth;

/**
 Video codec.

 @remark CYBCallVideoCodecVP8 or CYBCallVideoCodecH264 are possible values.
 */
@property (nonatomic, assign) CYBCallVideoCodec videoCodec;

/**
 Video bandwidth.

 @remark When set to 0 it is skipped in session description.
 */
@property (nonatomic, assign) NSInteger videoBandwidth;

/**
 Default media stream configuration with H264-baseline video codec and Opus audio codec.

 @return CYBCallMediaStreamConfiguration instance
 */
+ (instancetype)defaultConfiguration;

@end

NS_ASSUME_NONNULL_END
