//
//  AppDelegate.h
//  NativeDisplayBrightness
//
//  Created by Benno Krauss on 19.10.16.
//  Copyright © 2016 Benno Krauss. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#pragma mark - Key codes of special keys

#define BRIGHTNESS_DOWN_KEY         kVK_F1
#define BRIGHTNESS_UP_KEY           kVK_F2

#define COLOR_TEMPERATURE_DOWN_KEY  kVK_F3
#define COLOR_TEMPERATURE_UP_KEY    kVK_F4

#define APP_DELEGATE                ((AppDelegate *)[[NSApplication sharedApplication] delegate])

#define STATUS_ICON_WIDTH           24
#define STATUS_ICON_WIDTH_TEXT      52

// Extract from Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/Headers/Events.h
/* keycodes for keys that are independent of keyboard layout*/
enum {
    kVK_F17                       = 0x40,
    kVK_VolumeUp                  = 0x48,
    kVK_VolumeDown                = 0x49,
    kVK_Mute                      = 0x4A,
    kVK_F18                       = 0x4F,
    kVK_F19                       = 0x50,
    kVK_F20                       = 0x5A,
    kVK_F5                        = 0x60,
    kVK_F6                        = 0x61,
    kVK_F7                        = 0x62,
    kVK_F3                        = 0x63,
    kVK_F8                        = 0x64,
    kVK_F9                        = 0x65,
    kVK_F11                       = 0x67,
    kVK_F13                       = 0x69,
    kVK_F16                       = 0x6A,
    kVK_F14                       = 0x6B,
    kVK_F10                       = 0x6D,
    kVK_F12                       = 0x6F,
    kVK_F15                       = 0x71,
    kVK_Help                      = 0x72,
    kVK_Home                      = 0x73,
    kVK_PageUp                    = 0x74,
    kVK_ForwardDelete             = 0x75,
    kVK_F4                        = 0x76,
    kVK_End                       = 0x77,
    kVK_F2                        = 0x78,
    kVK_PageDown                  = 0x79,
    kVK_F1                        = 0x7A,
    kVK_LeftArrow                 = 0x7B,
    kVK_RightArrow                = 0x7C,
    kVK_DownArrow                 = 0x7D,
    kVK_UpArrow                   = 0x7E
};

#pragma mark - constants

@class BrightnessViewController;

static NSString *const kDisplaysBrightnessDefaultsKey = @"displays-brightness";
static const int brightnessStepsCount = 16;
static const int brightnessSubstepsPerStep = 6;
static const int brightnessSubstepsCount = brightnessStepsCount * brightnessSubstepsPerStep;

@interface AppDelegate : NSObject <NSApplicationDelegate> 

@property (strong) NSStatusItem *statusBarIcon;
@property (strong) NSMenu *statusBarMenu;
@property (strong) BrightnessViewController *brightnessView;
@property (assign) int currentBrightness;

//Settings values
@property (nonatomic, assign) BOOL multiMonitor;
@property (nonatomic, assign) BOOL smoothStep;
@property (nonatomic, assign) BOOL showBrightness;
@property (nonatomic, assign) int maxBrightness;
@property (nonatomic, assign) BOOL adjustTemp;
@property (nonatomic, assign) int tempLimit;

+(BOOL)loadSavedBrightness:(uint*) savedBrightness forDisplayID:(CGDirectDisplayID) displayID;
+(void)changeMainScreenBrightnessWithStep:(int) deltaInSubsteps;
+(void)changeMainScreenBrightness:(int) newBrightness;

@end

