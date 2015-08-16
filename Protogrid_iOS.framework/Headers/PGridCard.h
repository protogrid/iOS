//
//  PGridCard.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 05.08.14.
//
//


#import <Foundation/Foundation.h>
#import "Commons.h"
#import "HelperFunctions.h"



@interface PGridCard : NSObject

- (id) init:(id)doc;
- (id) type;
- (id) key;
- (id) name;
- (NSDictionary*) get_design_element:(NSString*)identifier default_value:(id)default_value;
- (NSDictionary*) get_design_element:(NSString*)identifier;
- (id) get_design_elements;
- (NSArray*) get_all_design_element_identifiers;
- (void) set_design_element:(NSString*)identifier content:(id)content;
- (void) append_design_element:(NSString*)identifier content:(id)content;
- (id) get:(NSString*)identifier default_value:(id)default_value;
- (id) get:(NSString*)identifier;
- (void) set:(NSString*)identifier object:(id)object;
- (NSDictionary*) get_raw_card;
- (NSString*) repr;
- (id) proto_key;

@end
