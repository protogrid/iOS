//
//  PGridReplicatorViewController.h
//  Protogrid
//
//  Created by Dominik Rüttimann on 16.11.14.
//  Copyright (c) 2017 ATEGRA AG. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "PGridApplication.h"

@class PGridAppDelegate;



@interface PGridReplicatorViewController : UIViewController

//@property (strong, nonatomic) IBOutlet UIView *view;
@property (weak, nonatomic) IBOutlet UISwitch *continuousSwitch;
@property (weak, nonatomic) IBOutlet UINavigationItem *navigation_item;
@property (weak, nonatomic) IBOutlet UILabel *generalInfo;
@property (weak, nonatomic) IBOutlet UILabel *loginInfo;
@property (weak, nonatomic) IBOutlet UILabel *synchronizationStatus;
@property (weak, nonatomic) IBOutlet UIButton *buttonSynchronizeNow;
@property (weak, nonatomic) IBOutlet UILabel *synchronizationInfo;
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak) PGridAppDelegate *app_delegate;
- (id) initWithNibName:(NSString*)nibName bundle:(NSBundle*)bundle delete_all_data_with_trigger:(void (^)(NSString*))delete_all_data_with_trigger;
- (void) update_loginInfo;
- (void) update_replication_info:(int)amount_new_docs;
- (void) update_status:(REPLICATION_STATUS)replication_status documents_to_be_updated:(int)documents_to_be_updated;

@end
