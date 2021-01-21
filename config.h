#include <X11/XF86keysym.h>

// Shell
char shell[] = "/bin/sh";

#define Super Mod4Mask
#define Alt Mod1Mask

enum {
  Music,
  App,
  Power,

  // Declare modes above this
  MODE_SIZE,
};

// Define mode key bindings here
// NOTE: "10" here is the maximum number of key bindings for each mode
Key modes[MODE_SIZE][10] = {
  [Music] = {
    { 0, XK_h,       cmd("playerctl previous") },
    { 0, XK_l,       cmd("playerctl next") },
    { 0, XK_space,   cmd("playerctl play-pause") },
  },
  [App] = {
    { 0, XK_b,   cmd("firefox") },
    { 0, XK_t,   cmd("st") },
  } ,
  [Power] = {
    { 0, XK_s,       cmd("notify-send shutting_down") },
    { 0, XK_r,       cmd("notify-send restarting") },
  },
};

// Define normal mode key bindings here
Key keys[] = {
  { Alt,  XK_z,             mode(Music, True) },
  { Alt,  XK_a,             mode(App, True) },
  { Alt,  XF86XK_PowerOff,  mode(Power, False) },

  /* { XF86XK_AudioPlay,  cmd("playerctl play-pause") }, */
  /* { XF86XK_AudioPrev,  cmd("playerctl previous") }, */
  /* { XF86XK_AudioNext,  cmd("playerctl next") }, */
  /* { XF86XK_AudioLowerVolume,  cmd("pactl set-sink-volume @DEFAULT_SINK@ -5%") }, */
  /* { XF86XK_AudioRaiseVolume,  cmd("pactl set-sink-volume @DEFAULT_SINK@ +5%") }, */

  { Super, XK_Pause,  cmd("playerctl play-pause") },
  { Super, XK_Home,  cmd("playerctl previous") },
  { Super, XK_End,  cmd("playerctl next") },
  { Super, XK_Next,  cmd("pactl set-sink-volume @DEFAULT_SINK@ -5%") },
  { Super, XK_Prior,  cmd("pactl set-sink-volume @DEFAULT_SINK@ +5%") },
};

ModeProperties mode_properties[MODE_SIZE] = {
  [Music] = { "Music player" },
  [App] = { "Applications" },
  [Power] = { "Power menu" },
};

// Call this script on mode change
char* on_mode_change = "echo \"kadj [$SHOTKEY_MODE_ID] $SHOTKEY_MODE_LABEL\"";

