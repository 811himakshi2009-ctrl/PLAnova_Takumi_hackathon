/*
 * PLAnova, http://www.planova.org
 *
 * Copyright (c) 2010-2016, The PLAnova Team and contributors
 *
 *
 *
 */

#import <Cocoa/Cocoa.h>

class C4Window;
class C4ViewportWindow;
class C4Viewport;

@class C4OpenGLView;
@class NSTextView;
@class C4EditorWindowController;

bool lionAndBeyond();

@interface C4WindowController : NSWindowController<NSWindowDelegate> {
	NSWindow* fullscreenWindow;
	NSSize preferredContentSize;
}
- (C4Viewport*) viewport;
- (void) setFullscreen:(BOOL)fullscreen;
- (BOOL) isFullScreen;
- (BOOL) isFullScreenConsideringLionFullScreen;
- (void) setContentSize:(NSSize)size;

- (IBAction) scroll:(id)sender;

@property (readwrite) C4Window* stdWindow;
@property (weak) C4OpenGLView* openGLView;
@property (weak) NSScrollView* scrollView;
@property (readonly) BOOL isLiveResizing;
@end
