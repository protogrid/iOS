//
//  PGridAppDelegate.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 05.08.14.
//
//
// $$$ Language //
// Match system language with available Protogrid languages (list, at moment only entry 'en_US'):
// 1. Search for same language (example: en_UK)
// 2. Search for similar language (example: en_*)
// 3. Use en_US for fallback


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CouchbaseLite/CouchbaseLite.h>
#import "Commons.h"

@class CBLDatabase, PGridRootViewController, PGridApplication, PGridCard, PGridCardService;

@interface PGridAppDelegate : NSObject <UIApplicationDelegate, UIAlertViewDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong) PGridRootViewController *root;
@property (strong) NSString *main_application_id;
@property (strong) NSMutableDictionary *applications_by_db_id;
@property (strong) NSString *user_id;
@property (strong) NSString *user_email;
@property (strong) PGridCard *default_card;
@property (strong) PGridCardService *card_service;
@property (strong) NSMutableDictionary *session;
@property (strong) NSMutableArray *flashed_messages;
@property (strong) NSString *default_error_message;
@property BOOL is_current_user_server_admin;
- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;
- (NSURLComponents*) get_db_url;
- (PGridCard*) get_current_user_card;
- (BOOL) get_lock_on_main_db;
- (void) reset_lock_on_main_db;
- (BOOL) set_user_id_with_email:(NSString*)email;
- (void) log_replication_message:(NSString*)message;
- (PGridCard*) resolve_key:(NSString*)card_key app_id:(NSString*)app_id;
- (PGridCard*) resolve_key:(NSString*)card_key app_id:(NSString*)app_id fallback_to_system_app:(BOOL)fallback_to_system_app force_cache:(BOOL)force_cache;
+ (NSString*) get_multilanguage_string_from_object_indexed_by_language:(NSDictionary*)language_index languages:(NSArray*)languages app:(PGridApplication*)app;
- (NSString*) get_multilanguage_text:(NSString*)ml_key app_id:(NSString*)app_id default_text:(NSString*)default_text force_cache:(BOOL)force_cache;
- (void) launch_replication_in_continuous_mode:(BOOL)is_continuous;
- (void) disable_replication;
- (void) update_replication_status;
- (void) delete_all_data_with_trigger:(NSString*)trigger;

@end
