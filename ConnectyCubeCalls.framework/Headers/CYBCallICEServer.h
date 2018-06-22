//
//  CYBCallICEServer.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 CYBCallICEServer class interface.
 This class represents an entity to describe Stun or TURN ICE server.
 */
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
