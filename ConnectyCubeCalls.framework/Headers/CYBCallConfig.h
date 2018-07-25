//
//  CYBCallConfig.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallTypes.h>
#import <ConnectyCubeCalls/CYBCallMacros.h>

NS_ASSUME_NONNULL_BEGIN

@class CYBCallMediaStreamConfiguration;
@class CYBCallICEServer;

/**
 CYBCallConfig class interface.
 This class represents configuration of all possible ConnectyCubeCalls settings.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallConfig)
@interface CYBCallConfig : NSObject

/**
 Determines whether framework is running from broadcast extension.
 
 @discussion Set this to YES if you are using framework from within broadcast extension.
 */
@property (class, nonatomic, getter=isBroadcastExtension) BOOL broadcastExtension;

- (instancetype)init NS_UNAVAILABLE;

// MARK: ICE configuration

/**
 Set custom ICE servers.

 @param iceServers array of CYBCallICEServer instances
 
 @remark By default we are using our public ICE servers.
 */
+ (void)setICEServers:(NSArray <CYBCallICEServer *>*)iceServers;

/**
 Get custom ICE servers

 @return array of CYBCallICEServer instances
 */
+ (NSArray <CYBCallICEServer *> *)iceServers;

// MARK: Time interval

/**
 Set dialing time interval.
 
 @param dialingTimeInterval time in seconds
 
 @note Indicates how often we send notifications to your opponents about your call.

 @remark Default value: 5 seconds
         Minimum value: 3 seconds
 */
+ (void)setDialingTimeInterval:(NSTimeInterval)dialingTimeInterval;

/**
 Set answer time interval.
 
 @param answerTimeInterval time interval in seconds

 @note If an opponent did not answer you within dialing time interval, then userDidNotRespond: and then connectionClosedForUser: delegate methods will be called

 @remark Default value: 45 seconds
         Minimum value: 10 seconds
 */
+ (void)setAnswerTimeInterval:(NSTimeInterval)answerTimeInterval;

/**
 Dialing time interval.

 @return current dialing time interval
 */
+ (NSTimeInterval)dialingTimeInterval;

/**
 Answer time interval.

 @return current answer time interval
 */
+ (NSTimeInterval)answerTimeInterval;

// MARK: Datagram Transport Layer Security

/**
 Enable / Disable Datagram Transport Layer Security.

 @param enabled YES/NO (default YES)
 */
+ (void)setDTLSEnabled:(BOOL)enabled;

/**
 Datagram Transport Layer Security state.

 @return current value (default YES)
 */
+ (BOOL)DTLSEnabled;

// MARK: Media stream configuration

/**
 Setter for media stream configuration.

 @param configuration CYBCallMediaStreamConfiguration configuration
 */
+ (void)setMediaStreamConfiguration:(CYBCallMediaStreamConfiguration *)configuration;

/**
 Media stream configuration.
 
 @remark By default it is [CYBCallMediaStreamConfiguration defaultConfiguration]

 @return CYBCallMediaStreamConfiguration instance
 */
+ (CYBCallMediaStreamConfiguration *)mediaStreamConfiguration;

// MARK: Stats reports

/**
 Set Stats report time interval. Default 0 which means you never receive stats.

 @note low time interval affects on CPU performance
 
 @param timeInterval time interval in seconds
 */
+ (void)setStatsReportTimeInterval:(NSTimeInterval)timeInterval;

/**
 Current stats report time interval.

 @return current value
 */
+ (NSTimeInterval)statsReportTimeInterval;

// MARK: Logging

/**
 Set ConnectyCubeCalls SDK log level (by default: CYBCallLogLevelDebug).

 Possible values:
 CYBCallLogLevelNothing:			    Nothing in Log
 CYBCallLogLevelVerbose:			    Full ConnectyCubeCalls Log
 CYBCallLogLevelVerboseWithWebRTC:    Full ConnectyCubeCalls and WebRTC native Log

 @param logLevel New log level
 */
+ (void)setLogLevel:(CYBCallLogLevel)logLevel;

/**
 Get ConnectyCubeCalls SDK log level (by default: CYBCallLogLevelDebug).

 @return CYBCallLogLevel current log level
 */
+ (CYBCallLogLevel)logLevel;

// MARK: Conference

/**
 Set conference server endpoint.

 @param conferenceEndpoint Connectycube conference server endpoint

 @note Enterprise-only feature

 @see https://connectycube.com/pricing/
 */
+ (void)setConferenceEndpoint:(NSString *)conferenceEndpoint;

/**
 Current ConnectyCube conference server endpoint.

 @note Enterprise-only feature, might be nil

 @see https://connectycube.com/pricing/

 @return Current conference server endpoint
 */
+ (nullable NSString *)conferenceEndpoint;

@end

NS_ASSUME_NONNULL_END
