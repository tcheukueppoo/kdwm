/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx        = 0;        /* border pixel of windows */
static unsigned int snap            = 32;       /* snap pixel */
static const unsigned int gappih    = 3;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 3;       /* vert inner gap between windows */
static const unsigned int gappoh    = 3;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 3;       /* vert outer gap between windows and screen edge */
static int smartgaps                = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning  = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft   = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing  = 2;   /* systray spacing */
static const unsigned int systrayiconsize = 50; /* reduce systray icon to 50% of it size(which is as a function of user_bh) */
static const int systraypinningfailfirst  = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray              = 1;     /* 0 means no systray */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 0;        /* 0 means bottom bar */
static int barvertpad         = 12;        /* vertical padding for status text */
static const int focusonwheel       = 0;
static const int vertpad            = 3;       /* vertical padding of bar */
static const int sidepad            = 3;       /* horizontal padding of bar */
static const int user_bh            = 31;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static char font[]            = "FantasqueSansMono Nerd Font:size=10";
static char dmenufont[]       = "FantasqueSansMono Nerd Font:size=10";
static const char *fonts[]          = { font };
static char normbgcolor[]           = "#282828";
static char normbordercolor[]       = "#b4cad9";
static char normfgcolor[]           = "#bdae93";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#328fa8";
static char selbgcolor[]            = "#005577";
static char termcol0[] = "#000000"; /* black   */
static char termcol1[] = "#ff0000"; /* red     */
static char termcol2[] = "#33ff00"; /* green   */
static char termcol3[] = "#ff0099"; /* yellow  */
static char termcol4[] = "#0066ff"; /* blue    */
static char termcol5[] = "#cc00ff"; /* magenta */
static char termcol6[] = "#00ffff"; /* cyan    */
static char termcol7[] = "#d0d0d0"; /* white   */
static char termcol8[] = "#808080"; /* black   */
static char termcol9[] = "#ff0000"; /* red     */
static char termcol10[] = "#33ff00"; /* green   */
static char termcol11[] = "#ff0099"; /* yellow  */
static char termcol12[] = "#0066ff"; /* blue    */
static char termcol13[] = "#cc00ff"; /* magenta */
static char termcol14[] = "#00ffff"; /* cyan    */
static char termcol15[] = "#ffffff"; /* white   */
static char *termcolor[] = {
  termcol0,
  termcol1,
  termcol2,
  termcol3,
  termcol4,
  termcol5,
  termcol6,
  termcol7,
  termcol8,
  termcol9,
  termcol10,
  termcol11,
  termcol12,
  termcol13,
  termcol14,
  termcol15,
};

static char *colors[][4] = {
	/*               fg         bg         border     float */
	[SchemeNorm]  = { normfgcolor, normbgcolor, normbordercolor, normbgcolor },
	[SchemeSel]   = { selfgcolor,  selbgcolor,  selbordercolor,  selbgcolor },
	[SchemeTitle] = { normfgcolor, normbgcolor, normbgcolor,  normbgcolor  },
};

/* tagging */
static const char *tags[] = { "A", "Б", "С", "Д", "Э", };

static char *tagsel[][2][2] = {
	/*      norm                          sel       */
	/*  fg          bg              fg          bg  */
	{ { normfgcolor, normbgcolor }, { termcol4, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { termcol2, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { termcol5, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { termcol6, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { termcol1, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { normfgcolor, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { normfgcolor, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { normfgcolor, normbgcolor } },
	{ { normfgcolor, normbgcolor }, { normfgcolor, normbgcolor } },
};

static const unsigned int ulinepad	   = 0;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		         = 0;	/* 1 to show underline on all tags, 0 for just the active ones */
static const unsigned int topbelow     = 2;  /* 0 to underline, 1 to overline and else for both */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered   isfloating   monitor    float x,y,w,h       floatborderpx*/
	{ "Zathura",          NULL,       NULL,       1 << 1,       0,           0,           -1,         50,50,500,500,        5 },
	{ "Mupdf",            NULL,       NULL,       1 << 1,       0,           0,           -1,         50,50,500,500,        5 },
	{ "Xchm",             NULL,       NULL,       1 << 1,       0,           0,           -1,         50,50,500,500,        5 },
	{ "TelegramDesktop",  NULL,       NULL,       1 << 2,       0,           0,           -1,         50,50,500,500,        5 },
	{ "Nyxt",             NULL,       NULL,       1 << 3,       0,           0,           -1,         50,50,500,500,        5 },
	{ "firefox",          NULL,       NULL,       1 << 3,       0,           0,           -1,         50,50,500,500,        5 },
	{ "Krita",            NULL,       NULL,       1 << 5,       0,           0,           -1,         50,50,500,500,        5 },
	{ "Gimp",             NULL,       NULL,       1 << 5,       0,           1,           -1,         50,50,500,500,        5 },
};
/* disable wm awareness for some windows based on their WM_CLASS */
/* this is mandatory for conky to work correctly */
static const char *wmaware[] = { "Conky" };

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
 	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
 	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ "HHH",      grid },
	{ "===",      bstackhoriz },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ ":::",      gaplessgrid },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTMOD Mod1Mask
#define CTRLMOD ControlMask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ CTRLMOD,                      KEY,      focusnthmon,    {.i  = TAG } }, \
	{ CTRLMOD|ShiftMask,            KEY,      tagnthmon,      {.i  = TAG } },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-h", "23", "-i", "-m", dmenumon, "-fn", dmenufont, NULL };
//static const char *dmenucmd[] = { "dmenu_run", "-h", "23", "-y", "36", "-x", "4", "-i", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *taski[]    = { "taski", NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "font",               STRING,  &font },
		{ "dmenufont",          STRING,  &dmenufont },
		{ "normbgcolor",        STRING,  &normbgcolor },
		{ "normbordercolor",    STRING,  &normbordercolor },
		{ "normfgcolor",        STRING,  &normfgcolor },
		{ "selbgcolor",         STRING,  &selbgcolor },
		{ "selbordercolor",     STRING,  &selbordercolor },
		{ "selfgcolor",			STRING,  &selfgcolor },
		{ "borderpx",			   INTEGER, &borderpx },
		{ "snap",				   INTEGER, &snap },
		{ "showbar",			   INTEGER, &showbar },
		{ "topbar",				   INTEGER, &topbar },
		{ "nmaster",          	INTEGER, &nmaster },
		{ "resizehints",       	INTEGER, &resizehints },
		{ "mfact",              FLOAT,   &mfact },
		{ "color0",             STRING,  &termcol0 },
		{ "color1",             STRING,  &termcol1 },
		{ "color2",             STRING,  &termcol2 },
		{ "color3",             STRING,  &termcol3 },
		{ "color4",             STRING,  &termcol4 },
		{ "color5",             STRING,  &termcol5 },
		{ "color6",             STRING,  &termcol6 },
		{ "color7",             STRING,  &termcol7 },
		{ "color8",             STRING,  &termcol8 },
		{ "color9",             STRING,  &termcol9 },
		{ "color10",            STRING,  &termcol10 },
		{ "color11",            STRING,  &termcol11 },
		{ "color12",            STRING,  &termcol12 },
		{ "color13",            STRING,  &termcol13 },
		{ "color14",            STRING,  &termcol14 },
		{ "color15",            STRING,  &termcol15 },
};

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static const StatusCmd statuscmds[] = {
	{ "notify-send Mouse$BUTTON", 1 },
	{ "notify-send Mouse$BUTTON", 2 },
	{ "notify-send Mouse$BUTTON", 3 },
	{ "notify-send Mouse$BUTTON", 4 },
};
static const char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_a,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = taski } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("slock") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("viper stop") },
	{ MODKEY,                       XK_r,      spawn,          SHCMD("sadp -next") },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          SHCMD("sadp -prev") },
	{ MODKEY,                       XK_x,      spawn,          SHCMD("nohup sadp -repeat >/dev/null 2>&1") },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("sadp -pause") },
	{ MODKEY,                       XK_e,      spawn,          SHCMD("sadp -search 'dmenu -p Search -i -c -l 20 -z 500 -h 20'") },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_Escape, togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_p,      zoom,           {0} },
	{ MODKEY,                       XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_g,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_g,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_t,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_t,      incrogaps,      {.i = -1 } },
	{ MODKEY,                       XK_y,      defaultgaps,    {0} },
	{ MODKEY|ShiftMask,             XK_y,      togglegaps,     {0} },
	{ MODKEY,                       XK_q,      view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ ALTMOD,                       XK_ampersand,        setlayout,      {.v = &layouts[0]} },
	{ ALTMOD,                       XK_eacute,           setlayout,      {.v = &layouts[1]} },
	{ ALTMOD,                       XK_quotedbl,         setlayout,      {.v = &layouts[2]} },
	{ ALTMOD,                       XK_apostrophe,       setlayout,      {.v = &layouts[3]} },
	{ ALTMOD,                       XK_parenleft,        setlayout,      {.v = &layouts[4]} },
	{ ALTMOD,                       XK_minus,            setlayout,      {.v = &layouts[5]} },
	{ ALTMOD,                       XK_egrave,           setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_space,  setlayout,         {0} },
	{ MODKEY,                       XK_s,      togglesticky,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,    {0} },
	{ MODKEY|ShiftMask,             XK_z,      togglealwaysontop, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,     {0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
	{ MODKEY,                       XK_agrave, view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave, tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, tagmon,      {.i = +1 } },
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_eacute,                 1)
	TAGKEYS(                        XK_quotedbl,               2)
	TAGKEYS(                        XK_apostrophe,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_minus,                  5)
	TAGKEYS(                        XK_egrave,                 6)
	TAGKEYS(                        XK_underscore,             7)
	TAGKEYS(                        XK_ccedilla,               8)
	{ MODKEY|ShiftMask,             XK_Escape, quit,              {0} },
	{ MODKEY,                       XK_n,      scratchpad_show,   {0} },
	{ MODKEY|ShiftMask,             XK_n,      scratchpad_hide,   {0} },
	{ MODKEY,                       XK_equal,  scratchpad_remove, {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[0]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = statuscmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,         ShiftMask,      Button1,        movemouse,      {0} },
	{ ClkClientWin,         ShiftMask,      Button2,        togglefloating, {0} },
	{ ClkClientWin,         ShiftMask,      Button3,        resizemouse,    {0} },
	{ ClkClientWin,         CTRLMOD,        Button1,        dragmfact,      {0} },
	{ ClkClientWin,         CTRLMOD,        Button3,        dragcfact,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
