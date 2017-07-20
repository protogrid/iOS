//
//  KeychainUserPass.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 29.09.14.
//
//

#import <Foundation/Foundation.h>

@interface KeychainUserPass : NSObject

+ (void)save:(NSString *)service data:(id)data;
+ (id)load:(NSString *)service;
+ (void)delete:(NSString *)service;

@end

