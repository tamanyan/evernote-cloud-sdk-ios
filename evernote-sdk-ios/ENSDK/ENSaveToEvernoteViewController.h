/*
 * Copyright (c) 2014 by Evernote Corporation, All rights reserved.
 *
 * Use of the source code and binary libraries included in this package
 * is permitted under the following terms:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <UIKit/UIKit.h>
#import "ENSDK.h"
#import "ENNotebookChooserViewController.h"
#import "ENNotebookPickerButton.h"
#import "ENNotebookPickerView.h"
#import "RMSTokenView.h"

@class ENSaveToEvernoteViewController;

@protocol ENSendToEvernoteViewControllerDelegate <NSObject>
- (ENNote *)noteForViewController:(ENSaveToEvernoteViewController *)viewController;
- (NSString *)defaultNoteTitleForViewController:(ENSaveToEvernoteViewController *)viewController;
- (void)viewController:(ENSaveToEvernoteViewController *)viewController didFinishWithSuccess:(BOOL)success uploadError:(NSError *)error;
@end

@interface ENSaveToEvernoteViewController : UIViewController
@property (nonatomic, weak) id<ENSendToEvernoteViewControllerDelegate> delegate;
@property (nonatomic, strong) UIBarButtonItem * saveButtonItem;
@property (nonatomic, strong) UITextField * titleField;
@property (nonatomic, strong) UITextField * notebookField;
@property (nonatomic, strong) UIWebView * noteView;
@property (nonatomic, strong) ENNotebookPickerView *notebookPickerView;
@property (nonatomic, strong) ENNotebookPickerButton * notebookPickerButton;
@property (nonatomic, strong) RMSTokenView * tagsView;
@property (nonatomic, strong) NSArray * notebookList;
@property (nonatomic, strong) ENNotebook * currentNotebook;

- (void)updateCurrentNotebookDisplay;
@end
