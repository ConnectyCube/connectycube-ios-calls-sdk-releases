//
//  CYBCallBaseClient.h
//  ConnectyCubeCalls
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCubeCalls/CYBCallBaseClientDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCallBaseClient class interface.
 This class represents basic client methods.
 */
NS_SWIFT_NAME(CallBaseClient)
@interface CYBCallBaseClient : NSObject

// unavailable initializers
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Client instance singleton.

 @return Client instance
 */
+ (instancetype)instance;

/**
 Add delegate to the observers list.

 @param delegate class that conforms to CYBCallBaseClientDelegate protocol
 */
- (void)addDelegate:(id<CYBCallBaseClientDelegate>)delegate;

/**
 Remove delegate from the observers list.
 
 @param delegate class that conforms to CYBCallBaseClientDelegate protocol
 */
- (void)removeDelegate:(id<CYBCallBaseClientDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
