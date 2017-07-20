//
//  PGridDocumentInteractionController.h
//  Protogrid iOS
//
//  Created by Michel Müller on 10/12/14.
//  Copyright (c) 2014 Michel Müller. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PGridAppDelegate;

@interface PGridDocumentInteractionController : UIViewController <UIDocumentInteractionControllerDelegate>

- (id) initWithAppDelegate:(PGridAppDelegate*)app_delegate;

@end
