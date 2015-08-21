//
//  PGridApplication.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 05.08.14.
//
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CouchbaseLite/CouchbaseLite.h>
#import "Commons.h"
#import "PGridUIWebViewController.h"

@class PGridCard, PGridAppDelegate;

@interface PGridApplication : NSObject

@property REPLICATION_STATUS replication_status;
@property int documents_to_be_updated;
@property (strong) NSString *application_id;
@property (strong, readonly) NSArray *template_related_keys;
@property (strong, readonly) NSRegularExpression* uuid_pattern;
@property BOOL table_view_needs_reload;
- (id) init_with_application_id:(NSString*)application_id app_delegate:(PGridAppDelegate*)app_delegate deleteFirst:(BOOL)deleteFirst delete_all_data_with_trigger:(void (^)(NSString*))delete_all_data_with_trigger;
- (void) start_synchronization:(void (^)())callbackHighPriorityPassed callbackContinuousPassed:(void (^)())callbackContinuousPassed;
- (void) stop_synchronization;
- (void) replicate_database:(NSString*)priority pathConfigurationList:(NSString*)pathConfigurationList thresholdDocAge:(NSString*)thresholdDocAge thresholdAttSize:(NSString*)thresholdAttSize callbackStatus:(void (^)(CBLReplicationStatus))callbackStatus;
- (void) replicate_database:(NSString*)priority pathConfigurationList:(NSString*)pathConfigurationList thresholdDocAge:(NSString*)thresholdDocAge thresholdAttSize:(NSString*)thresholdAttSize syncJS:(BOOL)syncJS password:(NSString*)password callbackStatus:(void (^)(CBLReplicationStatus))callbackStatus;
- (PGridCard*) get_card:(NSString*)card_key force_cache:(BOOL)force_cache throw_unauthorized_exceptions:(BOOL)throw_unauthorized_exceptions;
- (PGridCard*) get_card:(NSString*)card_key;
- (NSDictionary*) get:(NSString*)document_key;
//- (void) put:(NSDictionary*)document;
- (PGridCard*) get_card_with_id:(NSString*)card_key;
- (CBLAttachment*) get_attachment:(NSString*)card_key file_name:(NSString*)file_name;
- (void) update_card:(PGridCard*)card;
- (BOOL) card_exist:(NSString*)card_key;
- (NSUInteger) document_count;
- (NSDictionary*) get_context_for_card_engine;
- (NSDictionary*) get_multiindex_column_keys_by_proto_key;
- (void) compile_all_view_functions;
- (NSArray*) get_all_relating_cards:(NSArray*)cards;
- (NSDictionary*) get_all_related_cards;
- (NSDictionary*) get_all_related_cards:(NSArray*)keys;
- (NSDictionary*) get_all_related_cards:(NSArray*)keys depth:(NSNumber*)depth;
- (NSDictionary*) get_all_related_cards:(NSArray*)keys resolve_navigation_stack:(BOOL)resolve_navigation_stack;
- (NSDictionary*) get_all_related_cards:(NSArray*)keys depth:(NSNumber*)depth resolve_navigation_stack:(BOOL)resolve_navigation_stack resolve_foreign_app_relations:(BOOL)resolve_foreign_app_relations;
- (NSDictionary*) get_all_related_cards:(NSArray*)keys depth:(NSNumber*)depth resolve_navigation_stack:(BOOL)resolve_navigation_stack resolve_foreign_app_relations:(BOOL)resolve_foreign_app_relations resolve_template_cards:(BOOL)resolve_template_cards;
- (NSDictionary*) get_all_related_cards:(NSArray*)keys depth:(NSNumber*)depth resolve_navigation_stack:(BOOL)resolve_navigation_stack resolve_foreign_app_relations:(BOOL)resolve_foreign_app_relations resolve_template_cards:(BOOL)resolve_template_cards force_cache:(BOOL)force_cache exclude_keys:(NSArray*)exclude_keys;
- (NSMutableDictionary*) get_all_related_cards_for_card_rendering:(PGridCard*)card;
- (NSDictionary*) get_view_page_and_information:(NSString*)viewname design_card_key:(NSString*)design_card_key start_key:(id)start_key end_key:(id)end_key page_number:(NSNumber*)page_number limit:(NSNumber*)limit;
- (NSDictionary*) get_view_page_and_information:(NSString*)viewname start_key:(id)start_key end_key:(id)end_key page_number:(NSNumber*)page_number limit:(NSNumber*)limit;
- (NSDictionary*) get_view_page_and_information:(NSString*)viewname design_card_key:(NSString*)design_card_key start_key:(id)start_key end_key:(id)end_key page_number:(NSNumber*)page_number limit:(NSNumber*)limit descending:(BOOL)descending last_page_limit:(NSNumber*)last_page_limit include_docs:(BOOL)include_docs;
- (NSDictionary*) get_cards_and_page_information_from_view:(NSString*)viewname start_key:(id)start_key end_key:(id)end_key limit:(NSNumber*)limit;
- (NSArray*) get_values_from_view_with_card_keys:(NSString*)viewname keys:(id)keys;
- (NSDictionary*) get_view_with_keys:(NSString*)viewname keys:(NSArray*)keys;
+ (NSOrderedSet*) get_card_keys_from_view_result:(NSDictionary*)view_result id_index_in_key:(id)id_index_in_key;

@end



@interface PGridSystemApplication : PGridApplication

- (NSDictionary*) fixup_related_cards;

@end

//@interface NSDictionary_internal : NSDictionary;
//@property (readonly) NSString* cbl_id;
//@property (readonly) NSString* cbl_rev;
//@property (readonly) BOOL cbl_deleted;
//@property (readonly) NSDictionary* cbl_attachments;
//@end


@interface CBLBody_internal : NSObject <NSCopying>;

@property (strong, readonly) id json;

@end


@interface CBLRevision_internal : CBLRevision;

@property (strong, readonly) NSString *docID;
@property (strong, readonly) CBLBody_internal *body;

@end


@interface CBLDatabaseChange_internal : CBLDatabaseChange

@property (strong, readonly) CBLRevision_internal *addedRevision;

@end


