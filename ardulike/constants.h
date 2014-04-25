#ifndef __ARDULIKE_CONSTANTS_H__
#define __ARDULIKE_CONSTANTS_H__

/* input */

#define BUTTON_NONE   0
#define BUTTON_SELECT 1
#define BUTTON_RIGHT  2
#define BUTTON_LEFT   3
#define BUTTON_UP     4
#define BUTTON_DOWN   5

/* screen */

#define SCREEN_ROWS   2
#define SCREEN_COLS  16
#define SCREEN_DEPTH  8  // 'z' axis going 'towards the player', i.e 8 is nearest

/* display depths */

#define DISPLAY_DEPTH_PLAYER  3
#define DISPLAY_DEPTH_NPCS    2
#define DISPLAY_DEPTH_ITEMS   1
#define DISPLAY_DEPTH_TERRAIN 0

/* characters */

#define CHAR_SPACE       ' '
#define CHAR_PLAYER      '@'
#define CHAR_WALL        '#'
#define CHAR_FLOOR       '.'
#define CHAR_TREE        'T'
#define CHAR_STAIRS_UP   '>'
#define CHAR_STAIRS_DOWN '<'
#define CHAR_OGRE        'O'
#define CHAR_ORC         'o'
#define CHAR_DOG         'd'

/* rules */
#define EXP_KILL_MULTIPLIER             8
#define EXP_LEVEL_MULTIPLIER          2.3
#define LEVELUP_HP_MULTIPLIER         1.2
#define LEVELUP_STRENGTH_MULTIPLIER   1.1
#define LEVELUP_TOUGHNESS_MULTIPLIER  1.5
#define LEVELUP_HEAL                  true

#endif
