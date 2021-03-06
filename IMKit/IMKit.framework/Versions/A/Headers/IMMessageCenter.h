//
//  IMMessageCenter.h
//  IMClone
//
//  Created by Maxthon Chan on 13-2-28.
//  Copyright (c) 2013年 myWorld Creations. All rights reserved.
//

#import <IMKit/IMDecls.h>

IMBeginDecls

@class IMMessageCenter, IMMessage;

@protocol IMMessageCenter <NSObject>

- (void)registerWithIdentifier:(NSString *)identifier
                      userInfo:(NSDictionary *)info
                         error:(NSError **)error;
- (void)unregister;

- (void)sendMessage:(IMMessage *)message;

@end

@protocol IMMessageCenterDelegate <NSObject>

@optional

- (void)messageCenter:(IMMessageCenter *)messageCenter
    didReceiveMessage:(IMMessage *)message;

@end

@interface IMMessageCenter : NSObject <IMMessageCenter>

@property (weak) id<IMMessageCenterDelegate> delegate;

+ (IMInstanceType)messageCenterAtURL:(NSURL *)url;

- (id)initWithURL:(NSURL *)url;

@end

IMEndDecls
