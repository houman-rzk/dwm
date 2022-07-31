/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
//#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int gap                = 30;
static const unsigned int gappih    = gap;       /* horiz inner gap between windows */
static const unsigned int gappiv    = gap;       /* vert inner gap between windows */
static const unsigned int gappoh    = gap;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = gap;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
//static const char *fonts[]          = { "monospace:size=11", "NotoColorEmoji:pixelsize=12:antialias=true:autohint=true", "BitstreamVeraSansMono Nerd Font Mono:style=Roman:pixelsize=25:antialias=true:autohint=true" };
static const char *fonts[]          = { "monospace:size=11", "BitstreamVeraSansMono Nerd Font Mono:style=Roman:pixelsize=25:antialias=true:autohint=true" };
//static const char dmenufont[]       = "monospace:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_scarlet[]     = "#9a2323";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeInv]  = { col_gray1, col_gray3, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_scarlet },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x24", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-g", "50x20",  "-f", "monospace:size=16", "-e", "bc", "-lq", NULL };
/*const char *spcmd3[] = {TERMINAL, "-n", "sptasks", "-g", "120x34", "-e", "tasks-wraper", NULL };
const char *spcmd4[] = {TERMINAL, "-n", "spkeepass", "-g", "120x34", "-e", "keepassxc", NULL };
const char *spcmd5[] = {TERMINAL, "-n", "splf", "-g", "120x34", "-e", "lfrun", NULL };
const char *spcmd6[] = {TERMINAL, "-n", "spmusic", "-g", "120x34", "-e", "ncmpcpp", NULL };
const char *spcmd7[] = {TERMINAL, "-n", "spweather", "-g", "120x34",  "-f", "monospace:size=12", "-e", "less", "-Srf", "/home/ache/.cache/weatherreport", NULL };
const char *spcmd8[] = {TERMINAL, "-n", "spvolume", "-g", "120x34", "-e", "pulsemixer", NULL };
const char *spcmd9[] = {TERMINAL, "-n", "spnetwork", "-g", "120x34", "-e", "nmtui", NULL };
const char *spcmd10[] = {TERMINAL, "-n", "spresources", "-g", "120x34", "-e", "htop", NULL };*/
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
	/*{"sptasks",     spcmd3},
	{"spkeepass",   spcmd4},
	{"splf",        spcmd5},
	{"spmusic",     spcmd6},
	{"spweather",   spcmd7},
	{"spvolume",    spcmd8},
	{"spnetwork",   spcmd9},
	{"spresources", spcmd10},*/
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ TERMINAL,  NULL,     NULL,           0,         0,          1,       0,        -1 },
	{ TERMINAL,  "spterm", NULL,	       SPTAG(0),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spcalc", NULL,	       SPTAG(1),  1,	      1,	   0,	     -1 },
	/*{ TERMINAL,  "sptasks",NULL,	       SPTAG(2),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spkeepass",NULL,	       SPTAG(3),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "splf",   NULL,	       SPTAG(4),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spmusic",NULL,	       SPTAG(5),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spweather",NULL,	       SPTAG(6),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spvolume",NULL,	       SPTAG(7),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spnetwork",NULL,	       SPTAG(8),  1,	      1,	   0,	     -1 },
	{ TERMINAL,  "spresources",NULL,       SPTAG(9),  1,	      1,	   0,	     -1 },*/
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
	/* Uncomment to disable swallowing */
//	{ "gimp",    NULL,     NULL,           0,         1,          0,           1,        -1 },
//	{ "Firefox", NULL,     NULL,           0,         0,          0,           1,        -1 },
//	{ "tabbed",  NULL,     NULL,           0,         0,          0,           1,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

/* Never used. Here only to avoid compiling warnings when commenting out Layout in layouts[] */
static const Layout all[]={{"[]=",tile },{"[M]",monocle },{"[@]",spiral },{"[\\]",dwindle},{"H[]",deck},{"TTT",bstack},{"===",bstackhoriz},{"HHH",grid},{"###",nrowgrid},{"---",horizgrid},{":::",gaplessgrid},{"|M|",centeredmaster},{">M>",centeredfloatingmaster},{"><>",NULL},{NULL, NULL},};


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define LEFTALT Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run",/* "-n", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4,*/ NULL };
static const char *termcmd[]  = { TERMINAL, NULL };
//static const char *lfcmd[]  = { TERMINAL, "-e", "lf", NULL };
//static const char *musiccmd[]  = { TERMINAL, "-e", "ncmpcpp", NULL };

#include "movestack.c"
#include "X11/XF86keysym.h"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,	                    XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,		        XK_space,  unfloatvisible, {0} },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_minus,  setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_plus,   setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,			            XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY,		                XK_period, cyclelayout,    {.i = +1 } },

	{ MODKEY|ShiftMask,		        XK_s,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,		        XK_x,  	   togglescratch,  {.ui = 1 } },
	/*{ MODKEY|ShiftMask,		        XK_t,  	   togglescratch,  {.ui = 2 } },
	{ MODKEY|ShiftMask,	        	XK_p,  	   togglescratch,  {.ui = 3 } },
	{ MODKEY|ShiftMask,	        	XK_f,  	   togglescratch,  {.ui = 4 } },
	{ MODKEY|ShiftMask,     		XK_m,  	   togglescratch,  {.ui = 5 } },
	{ MODKEY|ShiftMask,	        	XK_n,  	   togglescratch,  {.ui = 8 } },
	{ MODKEY|ShiftMask,		        XK_r,  	   togglescratch,  {.ui = 9 } },*/

	//{ MODKEY|ShiftMask,		        XK_x,  	   spawn,  SHCMD("setsid -f $TERMINAL -e bc -lq") },
	{ MODKEY|ShiftMask,		        XK_t,  	   spawn,  SHCMD("setsid -f $TERMINAL -e tasks-wraper") },
	{ MODKEY|ShiftMask,	        	XK_p,  	   spawn,  SHCMD("setsid -f $TERMINAL -e keepassxc") },
	{ MODKEY|ShiftMask,	        	XK_f,  	   spawn,  SHCMD("setsid -f $TERMINAL -e lfrun") },
	{ MODKEY|ShiftMask,	        	XK_w,  	   spawn,  SHCMD("setsid -f $TERMINAL -f monospace:size=9 -e less -Srf ~/.cache/weatherreport") },
	{ MODKEY|ShiftMask,	        	XK_v,  	   spawn,  SHCMD("setsid -f $TERMINAL -e pulsemixer ; pkill -RTMIN+6 dwmblocks") },
	{ MODKEY|ShiftMask,		        XK_r,  	   spawn,  SHCMD("setsid -f $TERMINAL -e htop") },
	{ MODKEY|ShiftMask,	        	XK_i,  	   spawn,  SHCMD("setsid -f $TERMINAL -e nmtui ; pkill -RTMIN+4 dwmblocks") },
	{ MODKEY|ShiftMask,		        XK_n,  	   spawn,  SHCMD("setsid -f $TERMINAL -e newsboat") },
	{ MODKEY|ShiftMask,     		XK_m,  	   spawn,  SHCMD("setsid -f $TERMINAL -e ncmpcpp ; pkill -RTMIN+7 dwmblocks") },
	{ MODKEY|ControlMask,    		XK_m,  	   spawn,  SHCMD("setsid -f $TERMINAL -e neomutt") },

	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = (const char*[]){"dmenuunicode", NULL} } },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          {.v = (const char*[]){"clipmenu", NULL} } },
	{ MODKEY|ShiftMask|ControlMask, XK_c,      spawn,          {.v = (const char*[]){"clear-clipboards", NULL} } },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = (const char*[]){"sysact", NULL} } },
	{ MODKEY|ControlMask,           XK_l,      spawn,          SHCMD("mpc pause ; slock") },
//	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                    XK_c,      killclient,     {0} },
	{ LEFTALT|ShiftMask,            XK_x,      killunsel,      {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_u,      togglefloating, {0} },
	{ LEFTALT,                      XK_f,      togglefullscr,  {0} },
	{ LEFTALT,						XK_h,	   focusmon,       {.i = -1 } },
	{ LEFTALT,						XK_l,	   focusmon,       {.i = +1 } },
	{ LEFTALT|ShiftMask,			XK_h,	   tagmon,         {.i = -1 } },
	{ LEFTALT|ShiftMask,			XK_l,	   tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_l,      viewnext,       {0} },
	{ MODKEY,                       XK_h,      viewprev,       {0} },
	{ MODKEY|ShiftMask,             XK_l,      tagtonext,      {0} },
	{ MODKEY|ShiftMask,             XK_h,      tagtoprev,      {0} },
//	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, // Restart dwm

	{ 0,XF86XK_MonBrightnessUp,                spawn,          {.v = (const char*[]){"brightness", "up", NULL} } },
	{ 0,XF86XK_MonBrightnessDown,              spawn,          {.v = (const char*[]){"brightness", "down", NULL} } },
	{ 0,XF86XK_AudioRaiseVolume,               spawn,          SHCMD("pulsemixer --change-volume +5 ; pkill -RTMIN+6 dwmblocks") },
	{ 0,XF86XK_AudioLowerVolume,               spawn,          SHCMD("pulsemixer --change-volume -5 ; pkill -RTMIN+6 dwmblocks") },
	{ 0,XF86XK_AudioMute,                      spawn,          SHCMD("pulsemixer --toggle-mute ; pkill -RTMIN+6 dwmblocks") },

	{ 0,XF86XK_Display,                        spawn,          {.v = (const char*[]){"video-output", NULL} } },
	{ MODKEY|ControlMask,           XK_d,      spawn,          {.v = (const char*[]){"video-output", NULL} } },
	{ ControlMask,                  XK_F7,     spawn,          {.v = (const char*[]){"audio-output", NULL} } },
	{ MODKEY|ControlMask,           XK_a,      spawn,          {.v = (const char*[]){"audio-output", NULL} } },

	{ MODKEY|ControlMask,           XK_F6,     spawn,          {.v = (const char*[]){"redlight", "up", NULL} } },
	{ MODKEY|ControlMask,           XK_F5,     spawn,          {.v = (const char*[]){"redlight", "down", NULL} } },

	{ MODKEY|ShiftMask,             XK_less,   spawn,          SHCMD("music next") },
	{ MODKEY,                       XK_less,   spawn,          SHCMD("music prev") },
	{ MODKEY|ControlMask,           XK_p,      spawn,          SHCMD("music toggle") },

	{ MODKEY|ControlMask|ShiftMask, XK_p,      spawn,          {.v = (const char*[]){"power-profile", NULL} } },

	{ 0,XF86XK_WLAN,                           spawn,          {.v = (const char*[]){"wireless-toggle", "-w", NULL} } },
	{ ControlMask,                  XK_F8,     spawn,          {.v = (const char*[]){"wireless-toggle", "-b", NULL} } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
