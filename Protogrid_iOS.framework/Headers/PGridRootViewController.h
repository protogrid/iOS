//
//  PGridRootViewController.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 05.08.14.
//
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Commons.h"

@class PGridUIWebViewController, PGridReplicatorViewController, PGridDocumentInteractionController;

@interface PGridRootViewController : UIViewController

@property (strong) PGridUIWebViewController *web_view_controller;
@property (strong) PGridReplicatorViewController *replicator_view_controller;
@property (strong) PGridDocumentInteractionController *document_view_controller;
- (id) initWithAppDelegate:delegate delete_all_data_with_trigger:(void (^)(NSString*))delete_all_data_with_trigger;

@end
