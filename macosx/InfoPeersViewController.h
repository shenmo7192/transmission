// This file Copyright © 2010-2022 Transmission authors and contributors.
// It may be used under the MIT (SPDX: MIT) license.
// License text can be found in the licenses/ folder.

#import <Cocoa/Cocoa.h>

#import "InfoViewController.h"

@interface InfoPeersViewController : NSViewController<InfoViewController>

- (void)setInfoForTorrents:(NSArray*)torrents;
- (void)updateInfo;

- (void)saveViewSize;
- (void)clearView;

@end
