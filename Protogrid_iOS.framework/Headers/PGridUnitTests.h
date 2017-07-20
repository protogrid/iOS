//
//  PGridUnitTests.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 05.08.14.
//
//


#import <Foundation/Foundation.h>
#import "Commons.h"

@class PGridApplication, PGridAppDelegate;



@interface PGridUnitTests : NSObject

+ (void) replication_unit_tests:(NSString*)db_name app_delegate:(PGridAppDelegate*)app_delegate;

@end
