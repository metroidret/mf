# Debug Features

The final release of the game includes a pause debug menu that can be accessed by modifying the pause menu code. In addition, some beta versions of the game have been leaked that include other debug features, including the boot debug menu and no-clip mode.

- [Boot Debug Menu](#boot-debug-menu)
  - [Section](#section)
  - [Samus](#samus)
  - [BLDCNT](#bldcnt)
  - [Scroll](#scroll)
  - [Sound](#sound)
  - [Demo](#demo)
  - [Etc](#etc)
  - [Reset](#reset)
- [Pause Debug Menu](#pause-debug-menu)
  - [Equipment and Events](#equipment-and-events)
  - [Miscellaneous](#miscellaneous)
- [Additional Debug Features](#additional-debug-features)
  - [No-clip Mode](#no-clip-mode)


## Boot Debug Menu

The boot debug menu consists of various sub-menus for changing settings or testing parts of the game. You can access the boot debug menu from the intro or title screen by holding `B` and pressing `L`. You can also return to the title screen by pressing `R`. Pressing `Start` will start the game in the area selected in the Section menu.

### Section

Pressing `A` on any of the areas will start you in the first room of that area. These are the area names:
- ステーション - station (Main Deck)
- SR388 - (Sector 1)
- ネッタイ - tropics (Sector 2)
- シャクネツ - burning heat (Sector 3)
- スイチュウ - underwater (Sector 4)
- ゴッカン - extreme cold (Sector 5)
- アンコク - darkness (Sector 6)

You can also go to the title, or load any save files with data.

If you press `Select` with an area selected, a small menu will be displayed where you can choose the room or door to spawn at ("h" is short for 部屋 - *heya* - "room", "g" is short for "gate").

### Samus

"KeyLevel" lets you set how many security levels are unlocked. Interestingly, this value goes up to 7, even though there are only 4 security levels in the game.

"GetMap" lets you set which area maps are downloaded. The areas are in reverse order (first is Sector 6, last is Main Deck). Pressing `L` clears all values and pressing `R` sets all values. Pressing `Up` sets a value, pressing `Down` clears a value, and pressing `A` toggles a value.

"H-SHOT" and "ナナメ-SHOT" refer to the button assignments for arming missiles and diagonal aim ("H" likely refers to 発射 - *hassha* - "firing (a missile)", "ナナメ" means "diagonal"). You can press `L` or `R` to set that button, or `A` to swap the buttons.

"マップ" and "ミサイル" refer to the button assignments for the pause screen and swapping missiles ("マップ" means "map", "ミサイル" means "missile"). Pressing `A` swaps the buttons. In Fusion, there is no missile swapping functionality, so the button assignment for missiles is unused (it would later be used in Zero Mission). Note that the buttons displayed are incorrectly swapped.

### BLDCNT

TODO

### Scroll

TODO

### Sound

"BGM" lets you enable or disable background music during gameplay. "モノラル" and "ステレオ" refer to mono and stereo sound respectively. This is the same as the sound option on the file select screen. "TEST" lets you play all music and sounds in the game. Pressing `A` or `R` plays a sound, and pressing `L` stops a sound. Some sounds play indefinitely and can only be stopped with `L`. Not all numbers have a sound associated with them.

### Demo

This menu is for testing cutscenes and demos. The devs use "demo" to refer to cutscenes, and "auto demo" to refer to title screen demos.

"DEMO SW" likely means "demo switch", and seems to be an unused setting that would have disabled cutscenes. The following two options let you preview all the cutscenes in the game. "MonoPlay" is for the monologue cutscenes and a few others, while "DemoPlay" is for the title intro, new file intro, and ending cutscene.

"オートデモMODE" and "オートデモNUM" are "auto demo mode" and "auto demo number". For the demo mode, "0" puts you at the start of the demo and lets you move freely. "1" will record your inputs (until you press `Start`) and save them to RAM. "2" will play a demo recorded to RAM if you have recorded one. "3" will play the demo that is already on the ROM (same as the demos in the final release). The demo number lets you change which demo to play or record.

### Etc

Turning "Main-End OBJ" on will display a sprite at the left edge of the screen while in-game (the name likely means "objects (sprites) displayed at the end of the main code loop"). The sprite indicates the VCOUNT value at the end of the frame (essentially how many cycles the frame took). The closer it is to the bottom of the screen, the closer the game is to generating a lag frame.

"ゲート コウカ" is "gate effect". Turning this off will make all door transitions instant.

TODO: "マップスキャン L-R"

"STAFF ROLL" will play the credits.

### Reset

Selecting this will erase all SRAM, which does the same thing as the menu you get when you hold `L` + `R` while booting the game.


## Pause Debug Menu

The pause debug menu lets you change Samus's equipment, current event, and a few other options. You can access the pause debug menu from the status screen while the game is paused. The game must be launched from the boot debug menu, otherwise the pause debug menu won't be enabled. Holding `Select` while pausing will disable the debug menu until you pause again.

### Equipment and Events

Abilities can be toggled on or off. "CLUSTE" is diffusion missiles.

Changing the value next to "SAMUS" will give Samus abilities in the order that they are normally obtained. With the value selected, pressing `L` or `Select` will set all energy and ammo to their starting values. Pressing `R` or `Start` will set them all to their maximum values.

"EVENT" lets you set the current story event. Changing the value here will also update Samus's equipment and security levels unlocked. Changing the event is important for being able to visit rooms in the state you want, allowing bosses to spawn, and triggering story events. You can look at the [Event enum](../include/constants/event.h) to know what each value means.

"SEVENT" stands for either "sub-event" or "sound event". This value determines when to start, stop, or change the music based on story progression.

### Miscellaneous

"GET_MAP" lets you toggle area maps as downloaded.

"H" and "G" show the current room ID and door ID.

Selecting "QSAVE" will immediately save the game. Note that there's no indication the game was saved, you just have to press `A` anywhere on the text.

"KEY_LV" lets you change the current security level. Note that internally this is a value between 0-4 rather than bit flags (i.e. you can't have level 4 enabled while level 3 is disabled)

"TIME" displays the current in-game timer as hours and minutes. These can be changed to any value between 00:00 and 255:59.

TODO: Extra JP features


## Additional Debug Features

### No-clip Mode

While in-game, holding `L` + `R` and pressing `Select` will enable no-clip mode. In this mode, you can freely move around a room without interacting with collision. Holding `R` will let you move twice as fast. Pressing `Start` will switch the camera to be unaffected by scrolls and room boundaries. Pressing `Select` will turn off no-clip mode.
