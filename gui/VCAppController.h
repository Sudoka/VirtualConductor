//
//  VCAppController.h
//  VirtualConductor
//
//  Created by John Kooker on 3/7/10.
//  Copyright 2010 John Kooker. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "lo/lo.h"
#import "VCInstrumentView.h"

enum VCGestures {
    VCGestureVolumeUp = 1,
    VCGestureVolumeDown,
    VCGestureMute,
    VCGestureSolo
};

#define kInstrumentCount 4

@interface VCAppController : NSObject {
    lo_address oscPd;
    lo_server_thread st;
        
    IBOutlet VCInstrumentView *guitarView;
    IBOutlet VCInstrumentView *drumsView;
    IBOutlet VCInstrumentView *voxView;
    IBOutlet VCInstrumentView *crowdView;
    
    IBOutlet NSSlider *headIndicator;
    IBOutlet NSProgressIndicator *spinner;
    IBOutlet NSButton *startStopButton;
    
    NSInteger headAngle;
    NSInteger orientation;
    NSUInteger volumes[kInstrumentCount];
    NSArray *instrumentViews;
    NSInteger instrumentOffsets[kInstrumentCount];
    
    NSUInteger activeInstrumentIndex;
    
    BOOL isStarted;
}

- (void)handleGesture:(NSInteger)gestureID;
- (void)handleHeadAngle:(NSInteger)angle;
- (void)getHeadAngle;
- (void)sendUpdatesToPd;
- (void)updateInstrumentPositions;
- (void)setActiveInstrumentIndex:(NSUInteger)i;
- (void)updateWorld:(NSTimer*)theTimer;

- (IBAction)startStop:(id)sender;
- (IBAction)doOrientation:(id)sender;

@end
