//
//  CYBCallICEServer.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCubeCalls/CYBCallMacros.h>

/**
 CYBCallICEServer class interface.
 This class represents an entity to describe Stun or TURN ICE server.
 */
CYBCALL_EXPORT
NS_SWIFT_NAME(CallICEServer)
@interface CYBCallICEServer : NSObject

@property (nonatomic, copy, readonly) NSString *userName;
@property (nonatomic, copy, readonly) NSString *password;
@property (nonatomic, copy, readonly) NSArray <NSString *> *urls;

/**
 Initializer for RTCICEServer taking urls, username, and password.
 */
+ (instancetype)serverWithURLs:(NSArray <NSString *> *)URLs
                      username:(NSString *)username
                      password:(NSString *)password;

- (instancetype)init NS_UNAVAILABLE;

@end
