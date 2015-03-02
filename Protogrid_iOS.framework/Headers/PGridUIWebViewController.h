//
//  PGridUIWebViewController.m
//  Protogrid
//
//  Created by Dominik Rüttimann on 08.08.14.
//
//


#import <Foundation/Foundation.h>
#import <UIKit/UIDocumentInteractionController.h>
#import <UIKit/UIWebView.h>
#import "Commons.h"
#import "HelperFunctions.h"

typedef NS_ENUM(NSUInteger, REPLICATION_STATUS) {
    kActive,
    kIdle,
    kOffline,
    kStopped,
    kFirst
};

@class PGridAppDelegate, PGridApplication, PGridCard;

typedef id(^response_func)(PGridApplication *app, PGridCard *previous_card, id result, NSString *related_key, NSString *related_app_id, NSString *element_id, NSString *proto_key);

@interface PGridUIWebViewController : NSObject <UIWebViewDelegate>

@property (strong) UIWebView *web_view;
- (void) card_view_handler_with_card_name:(NSString*)card_name app_name:(NSString*)app_name request:(NSURLRequest*)request;
- (id) initWithAppDelegate:(PGridAppDelegate*)app_delegate;
- (void) update_status:(REPLICATION_STATUS)replication_status;

@end
