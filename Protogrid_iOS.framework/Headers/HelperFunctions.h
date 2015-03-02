//
//  HelperFunctions.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 22.09.14.
//
//

#import <Foundation/Foundation.h>

@interface HelperFunctions : NSObject

+ (id) deepMutableCopy:(id)resource;
+ (NSString*) get_best_matching_locale_out_of:(NSArray*)supported_locales;

@end
