/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel size of windows */
static const unsigned int gappx     = 5;        /* gaps size between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=9", "fontawesome:size=9" };
static const char dmenufont[]       = "monospace:size=10";
//background color
static const char col_gray1[]       = "#000000";
//inactive window border color
static const char col_gray2[]       = "#000000";
//font color
static const char col_gray3[]       = "#f9e7c4";
//current tag and current window font color
static const char col_gray4[]       = "#000000";
//Top bar second color (blue) and active window border color
static const char col_cyan[]        = "#f9e7c4";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
//tag names (upper left)
static const char *tags[] = { "", "", "", "", "", "", "", "", "", ""};
//static const char *tags[] = { "ɪ", "ɪɪ", "ɪɪɪ", "ɪᴠ", "ᴠ", "ᴠɪ", "ᴠɪɪ", "ᴠɪɪɪ", "ɪx", "x" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class       instance   title       tags mask     iscentered   isfloating   monitor */
	{ "feh",	   NULL,      NULL,       0,       	    1,		     1,			  -1 },
 	{ "alscratch", NULL,      NULL,       0,            1,		     1,			  -1 },
	{ "mpv",       NULL,      NULL,       0,            1,		     1,			  -1 },
	{ "fileman",   NULL,      NULL,       0,            1,           1,			  -1 },
	{ "MyPaint",   NULL,      NULL,       0,            1,           1,			  -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-c", "-l", "30", 							  NULL };
static const char *monitor[]  = { "alacritty", "-e", "/usr/bin/./htop",						  NULL };
static const char *lockscr[]  = { "i3lock-fancy",  											  NULL };
static const char *browser[]  = { "librewolf",    							    			  NULL };
static const char *fileman[]  = { "alacritty", "--class=fileman", "--title=lf", "-e", "lf",   NULL };
static const char *spotify[]  = { "spotify-launcher", 	    								  NULL };
static const char *termcmd[]  = { "alacritty",  		    								  NULL };
static const char *termpop[]  = { "alacritty", "--class=alscratch",							  NULL };
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", 			  NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", 			  NULL };
static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", 			  	  NULL };
//wacom commands xsetwacom --set "$(($(xsetwacom --list devices | grep -Eo -m 1 -h "[0-9]{1,4}")))" MapToOutput "eDP-1"
//static const char *wacoms1[] = { "xsetwacom", "--set", "'$(($(xsetwacom --list devices | grep -Eo -m 1 -h "[0-9]{1,4}")))'", "MapToOutput", "'eDP-1'",  NULL };
//static const char *wacoms2[] = { "xsetwacom", "--set", "\"$(($(xsetwacom --list devices | grep -Eo -m 1 -h \"[0-9]{1,4}\")))\"", "MapToOutput", "\"HDMI-1\"",	  NULL };
//static const char *wacoms3[] = { "xsetwacom", "--set", "\"$(($(xsetwacom --list devices | grep -Eo -m 1 -h \"[0-9]{1,4}\")))\"", "MapToOutput", "\"3286x1080+0+0\"",  NULL };
//static const char *wacoms4[] = { "xsetwacom",  NULL };

#include "shiftview.c"
static char *endx[] = { "/bin/sh", "-c", "endx", "externalpipe", NULL };
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_w,      spawn,          {.v = browser } },
    { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ControlMask,           XK_h, 	   spawn,          {.v = monitor } },
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = termpop } },
	{ MODKEY,	                    XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_l, 	   spawn,          {.v = fileman } },
	{ MODKEY|ControlMask,           XK_u, 	   spawn,          {.v = spotify } },
 	{ MODKEY,	                    XK_F12,    spawn,          {.v = lockscr } },
	{ MODKEY,                       XK_t,      togglebar,      {0} }, 
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_z,	   zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                    XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_s,	   togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_F11,    fullscreen,     {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,              		    XK_n,      shiftview,  	   { .i = +1 } },
	{ MODKEY,              		    XK_b,      shiftview,      { .i = -1 } },
    { MODKEY,                       XK_F8,     spawn,          {.v = upvol   } },
    { MODKEY,                       XK_F7,     spawn,          {.v = downvol } },
    { MODKEY,                       XK_F5,     spawn,          {.v = mutevol } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

