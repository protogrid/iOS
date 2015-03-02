//
//  PGridCardService.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 29.09.14.
//
//


#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "Commons.h"

@class PGridCard;



@interface PGridCardService : NSObject

- (id) init;
- (NSDictionary*) get_rendered_tableview_data:(NSArray*)tableview_data element_id:(NSString*)element_id related_cards_by_key:(NSDictionary*)related_cards_by_key user_context:(NSDictionary*)user_context application_context:(NSDictionary*)application_context log_card:(NSDictionary*)log_card;
- (NSDictionary*) render_card_page:(id)card related_cards_by_key:(NSDictionary*)related_cards_by_key user_context:(id)user_context application_context:(id)application_context log_card:(NSDictionary*)log_card before_first_save:(BOOL)before_first_save;
- (NSDictionary*) get_template_card_keys:(id)application_context log_card:(NSDictionary*)log_card;
+ (NSDictionary*) get_templates;
- (NSDictionary*) get_updated_cards_and_validation_errors:(NSArray*)cards posted_form:(NSDictionary*)posted_form validation_errors:(NSDictionary*)validation_errors relating_cards:(NSArray*)relating_cards related_cards_by_key:(NSDictionary*)related_cards_by_key user_context:(NSDictionary*)user_context application_context:(NSDictionary*)application_context log_card:(NSDictionary*)log_card before_first_save:(BOOL)before_first_save;
- (NSDictionary*) get_updated_cards_or_rendered_if_invalid:(NSArray*)cards posted_form:(NSDictionary*)posted_form validation_errors:(NSDictionary*)validation_errors relating_cards:(NSArray*)relating_cards related_cards_by_key:(NSDictionary*)related_cards_by_key user_context:(NSDictionary*)user_context application_context:(NSDictionary*)application_context log_card:(NSDictionary*)log_card before_first_save:(BOOL)before_first_save;

@end



@interface CardEngineException : NSException

@property (strong) PGridCard *log_card;
+ (NSException*) exceptionWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo log_card:(PGridCard*)log_card;

@end
