//
//  PGridLogger.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 07.10.14.
//  Copyright (c) 2014 ATEGRA AG. All rights reserved.
//
//


#import <Foundation/Foundation.h>
#import "Commons.h"

@class PGridApplication, PGridCard, PGridLogger;



@interface PGridLogger : NSObject

typedef NS_ENUM(NSUInteger, LOG_LEVEL) {
    kMessage,
    kWarning,
    kError
};
- (id) init:(id)log_card;
- (id) init:(id)log_card application_context:(NSDictionary*)application_context user_context:(NSDictionary*)user_context environment_for_deferred_flashing:(id)environment_for_deferred_flashing;
- (void) store_log_and_flash_all_messages:(PGridApplication*)app;
- (void) store_log_and_flash_all_messages:(PGridApplication*)app print_to_console:(BOOL)print_to_console store_log:(BOOL)store_log;
- (void) log:(NSString*)message log_level:(LOG_LEVEL)log_level;
- (NSDictionary*) get_raw_log_card;
+ (PGridLogger*) get_logger_from_exception:(NSException*)exception previous_log_card:(PGridCard*)previous_log_card log_level:(LOG_LEVEL)log_level traceback:(NSString*)traceback;

@end
