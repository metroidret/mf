# Bugs and Glitches
These are known bugs and glitches in the game: code that clearly does not work as intended or was designed poorly. Some of them cause visible gameplay issues, while others are harmless. The bugs listed here can be fixed by compiling with the `BUGFIX` flag (bugs in the TODO section don't have a fix implemented yet). 


## Contents

- [Bugs](#bugs)
  - [Y-flipped Zoro uses the wrong size for top hitbox](#y-flipped-zoro-uses-the-wrong-size-for-top-hitbox)
  - [Y-flipped Sciser uses the wrong size for top hitbox](#y-flipped-sciser-uses-the-wrong-size-for-top-hitbox)
  - [Gerutas don't update their hitbox after turning around](#gerutas-dont-update-their-hitbox-after-turning-around)
  - [Rolling Yards use wrong Y value for left wall collision check](#rolling-yards-use-wrong-y-value-for-left-wall-collision-check)
  - [Choot spit explosion uses wrong X value for collision check](#choot-spit-explosion-uses-wrong-x-value-for-collision-check)
  - [Power bomb gerons use the wrong sprite ID to calculate their destroyed bit position](#power-bomb-gerons-use-the-wrong-sprite-id-to-calculate-their-destroyed-bit-position)
  - [Kihunter hives don't check if spawning a Kihunter failed](#kihunter-hives-dont-check-if-spawning-a-kihunter-failed)
  - [SA-X sprite AI has wrong declaration for `sSamusCollisionData`](#sa-x-sprite-ai-has-wrong-declaration-for-ssamuscollisiondata)
  - [Sprites that rotate toward a target will never target directly up](#sprites-that-rotate-toward-a-target-will-never-target-directly-up)
  - [Samus OAM for wall jumping left is missing a part](#samus-oam-for-wall-jumping-left-is-missing-a-part)
  - [Samus's arm doesn't recoil when shooting diagonally up right](#samuss-arm-doesnt-recoil-when-standing-and-shooting-diagonally-up-right)
  - [Arm cannon OAM data for shooting and crouching while facing right is malformed](#arm-cannon-oam-data-for-shooting-and-crouching-while-facing-right-is-malformed)
  - [Arm cannon animation for running left is missing an arm cannon offset](#arm-cannon-animation-for-running-left-is-missing-an-arm-cannon-offset)
  - [Changing the event in the debug menu doesn't equip suits](#changing-the-event-in-the-debug-menu-doesnt-equip-suits)
- [Oversights and Design Flaws](#oversights-and-design-flaws)
  - [`ClipdataConvertToCollision` is copied to RAM but still runs in ROM](#clipdataconverttocollision-is-copied-to-ram-but-still-runs-in-rom)
  - [`ClipdataCheckElevatorDisabled` checks every elevator when only one needs to be checked](#clipdatacheckelevatordisabled-checks-every-elevator-when-only-one-needs-to-be-checked)
  - [`BeamCoreXEyeHandleRotation` has duplicate code from `SpriteUtilMakeSpriteRotateTowardsTarget`](#beamcorexeyehandlerotation-has-duplicate-code-from-spriteutilmakespriterotatetowardstarget)
  - [The BOX fight can be triggered without triggering the screen shake](#the-box-fight-can-be-triggered-without-triggering-the-screen-shake)
- [Uninitialized Variables](#uninitialized-variables)
- [TODO](#todo)
  - [Bugs](#bugs-1)
  - [Oversights and Design Flaws](#oversights-and-design-flaws-1)


## Bugs

### Y-flipped Zoro uses the wrong size for top hitbox

**Fix:** Edit `ZoroSetHitboxAndDrawDistance` in [zoro.c](../src/sprites_AI/zoro.c) to make the `hitboxTop` value negative.

```diff
  if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
  {
-     gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f); // BUG: Should be negative
+     gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
      gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(0.9375f);
      gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.9375f);
      gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.9375f);
  }
```

### Y-flipped Sciser uses the wrong size for top hitbox

**Fix:** Edit `SciserUpdateHitbox` in [sciser.c](../src/sprites_AI/sciser.c) to make the `hitboxTop` value negative.

```diff
  if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
  {
-     gCurrentSprite.hitboxTop = BLOCK_TO_SUB_PIXEL(0.25f); // BUG: Should be negative
+     gCurrentSprite.hitboxTop = -BLOCK_TO_SUB_PIXEL(0.25f);
      gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.125f);
      gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(0.75f);
      gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(0.75f); 
  }
```

### Gerutas don't update their hitbox after turning around

Gerutas update their hitbox when returning to idle after attacking, but not after turning around. The difference is minor though, with the hitbox only being offset by a quarter of a block (4 pixels).

**Fix:** Edit `GerutaTurningAround` in [geruta.c](../src/sprites_AI/geruta.c) to call `GerutaSetIdleHitboxes`

```diff
  if (SpriteUtilHasCurrentAnimationNearlyEnded())
  {
-     // BUG: Hitbox isn't updated after turning around
      gCurrentSprite.pose = SPRITE_POSE_IDLE_INIT;
      gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
+     GerutaSetIdleHitboxes();
  }
```

### Rolling Yards use wrong Y value for left wall collision check

**Note:** Yards that can roll don't appear in the final game, so this code was likely unfinished/untested.

**Fix:** Edit `YardRolling` in [yard.c](../src/sprites_AI/yard.c) to subtract one pixel from the Y position instead of a quarter block.

```diff
  // Still on ground or slope, check block above bottom-left
- // BUG: Y position should be subtracted by one pixel
- SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.25f),
-     gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
+ SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_TO_SUB_PIXEL(0.0625f),
+     gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(0.5f));
  if (gPreviousCollisionCheck == COLLISION_SOLID)
  {
      // Hit a wall
      gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
      return;
  }
```

### Choot spit explosion uses wrong X value for collision check

Choot spit checks collision when exploding to determine which animation to use (on ground vs mid-air). However, it checks one block to the right when it should just check at the spit's X position. Note that there are no setups in the original game where this bug can occur.

**Fix:** Edit `ChootSpitExplodingInit` in [choot.c](../src/sprites_AI/choot.c) to not subtract one block from the X position.

```diff
- // BUG: Center of spit should be checked for collision, not one block to the right
- SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_TO_SUB_PIXEL(1.0f));
+ SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
  if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
      gCurrentSprite.pOam = sChootSpitOam_ExplodingOnGround;
  else
      gCurrentSprite.pOam = sChootSpitOam_ExplodingMidair;
```
### Power bomb gerons use the wrong sprite ID to calculate their destroyed bit position

Each geron type uses a variable to track which ones have been destroyed. Since the variables are 16-bit, up to 16 of each type can be tracked. The sprite IDs for each type appear sequentially, so subtracting the first geron's ID from the current geron's ID will get its bit position. However, power bomb gerons subtract the first *super missile* geron ID instead of the first *power bomb* geron ID. This ends up not causing any problems, because power bomb geron IDs are immediately after super missile geron IDs, and there are only 8 of each, so power bomb gerons end up using the top 8 bits of their destroyed variable.

**Fix:** Edit `PowerBombGeronInit` and `PowerBombGeronDying` in [power_bomb_geron.c](../src/sprites_AI/power_bomb_geron.c) to subtract the first power bomb geron sprite ID.

```diff
  spriteId = gCurrentSprite.spriteId;
- // BUG: The first super missile geron is used insead of the first power bomb geron
- spriteId -= PSPRITE_GERON_SUPER_MISSILE_1;
+ spriteId -= PSPRITE_GERON_POWER_BOMB_1;

  geronBit = gPowerBombGeronsDestroyed >> spriteId;

  if (geronBit & 1)
  {
      gCurrentSprite.status = 0;
      return;
  }

...

  spriteId = gCurrentSprite.spriteId;
- // BUG: The first super missile geron is used insead of the first power bomb geron
- spriteId -= PSPRITE_GERON_SUPER_MISSILE_1;
+ spriteId -= PSPRITE_GERON_POWER_BOMB_1;

  geronBit = 1 << spriteId;
  gPowerBombGeronsDestroyed |= geronBit;

  GeronSetCollision(CAA_REMOVE_SOLID);
```

### Kihunter hives don't check if spawning a Kihunter failed

When spawning a new sprite, if all the sprite slots are full, the spawn function will return 0xFF instead of a sprite data index. When kihunter hives spawn a kihunter, it uses the return value to index `gSpriteData` and set some values. If spawning fails, the index will be out of bounds.

**Note:** Kihunter hives don't appear in the final game, so this code was likely unfinished/untested.

**Fix:** Edit `KihunterHiveSpawnKihunter` in [kihunter.c](../src/sprites_AI/kihunter.c) to check the spawn function return value before modifying data on the sprite.

```diff
  ramSlot = SpriteSpawnPrimary(PSPRITE_KIHUNTER_FLYING, 0, gCurrentSprite.spritesetGfxSlot, SSP_X_ABSORBABLE_BY_SAMUS,
      gCurrentSprite.yPosition + BLOCK_TO_SUB_PIXEL(2.0f), gCurrentSprite.xPosition, flip);
- // BUG: Doesn't check if spawning failed, so ramSlot can go out of bounds
+ if (ramSlot != UCHAR_MAX)
  {
      gSpriteData[ramSlot].pose = SPRITE_POSE_SPAWNING_FROM_X_INIT;
      gSpriteData[ramSlot].status |= SPRITE_STATUS_MOSAIC | SPRITE_STATUS_IGNORE_PROJECTILES;
      gSpriteData[ramSlot].status &= ~SPRITE_STATUS_HIDDEN;
      gSpriteData[ramSlot].properties &= ~SP_CAN_ABSORB_X;
  }
```

### SA-X sprite AI has wrong declaration for `sSamusCollisionData`

The function `SaXSeeAndLocateSamus` in the SA-X sprite AI accesses `sSamusCollisionData` as if it has 6 items per pose, even though there are actually 5. The result is that the value read will be an unexpected or invalid hitbox type. In practice, this only has a minor effect on the SA-X's detection of Samus.

**Fix:** Edit [sa_x.c](../src/sprites_AI/sa_x.c) to remove the incorrect declaration and include samus_data.h instead.

```diff
- // Incorrectly declared here to produce matching code in SaXSeeAndLocateSamus
- extern const u8 sSamusCollisionData[SPOSE_END][6];
+ #include "data/samus_data.h"
```

### Sprites that rotate toward a target will never target directly up

Beam Core-X eyes and BOX's missiles rotate in order to target Samus. The condition for Samus being directly above the sprite is checked, but the result is not used due to a typo, so other conditions are checked instead. Note that sprites can still aim up while rotating, but will never remain aiming up. If Samus is directly above, sprites will aim up-left or up-right instead.

**Fix:** Edit `SpriteUtilMakeSpriteRotateTowardsTarget` in [sprite_util.c](../src/spite_util.c) to change the condition after the "directly above" check to `else if` instead of `if`.

```diff
  if (spriteX - BLOCK_SIZE < targetX && spriteX + BLOCK_SIZE > targetX)
  {
      // Target is directly above sprite
      targetRotation = Q_8_8(6.f / 8);
  }
- // BUG: Should be "else if"
- if (targetX > spriteX)
+ else if (targetX > spriteX)
  {
      // Target is right of sprite
      if (spriteY - targetY < BLOCK_SIZE)
      {
          // Target is directly right of sprite
          targetRotation = 0;
      }
      else
      {
          // Target is above and right of sprite
          targetRotation = Q_8_8(7.f / 8);
      }
  }
```

### Samus OAM for wall jumping left is missing a part

When Samus starts a wall jump facing left, the top right part is missing, due to the X coordinate being incorrect (the value is written as if it were 8 bits, but OAM X coordinates are 9 bits).

**Fix:** Edit `sSamusOam_StartingWallJump_Left_Frame0` in [samus_graphics.c](../src/data/samus/samus_graphics.c) to use the correct X coordinate.

```diff
  static const u16 sSamusOam_StartingWallJump_Left_Frame0[OAM_DATA_SIZE(3)] = {
      3,
      OAM_ENTRY(-22, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
-     OAM_ENTRY(250, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 0, 0),
+     OAM_ENTRY(-6, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 0, 0),
      OAM_ENTRY(-24, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 0, 0),
  };
```

### Samus's arm doesn't recoil when standing and shooting diagonally up right

Whenever Samus shoots while not moving, her arm cannon recoils a bit. This happens for every shooting pose and arm direction except for standing while aiming diagonally up right.

**Fix:** Edit `sArmCannonOam_Shooting_DiagonalUp_Right_Frame0` in [arm_cannon_data.c](../src/data/samus/arm_cannon_data.c) to move each arm cannon part left by 1 pixel.

```diff
  static const u16 sArmCannonOam_Shooting_DiagonalUp_Right_Frame0[OAM_DATA_SIZE(3)] = {
      3 | ARM_CANNON_OAM_ORDER_BEHIND,
-     OAM_ENTRY(3, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
-     OAM_ENTRY(19, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
-     OAM_ENTRY(3, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
+     OAM_ENTRY(2, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 1, 0),
+     OAM_ENTRY(18, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
+     OAM_ENTRY(2, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
  };
```

### Arm cannon OAM data for shooting and crouching while facing right is malformed

When shooting and crouching while facing right, the arm cannon disappears. This is because the OAM data seems to be shifted by 2 bytes somehow, with the part count missing, and an extra 0 at the end. This can also happen when forced into crouching by jumping on an enemy close to a ceiling, since it uses the same OAM.

**Fix:** Edit `sArmCannonOam_ShootingAndCrouching_None_Right_Frame0` in [arm_cannon_data.c](../src/data/samus/arm_cannon_data.c) to add the part count and remove the trailing 0.

```diff
  static const u16 sArmCannonOam_ShootingAndCrouching_None_Right_Frame0[OAM_DATA_SIZE(3)] = {
+     3 | ARM_CANNON_OAM_ORDER_BEHIND,
      OAM_ENTRY(1, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 1, 0),
      OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 1, 0),
      OAM_ENTRY(11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x5f, 1, 0),
-     0
  };
```

### Arm cannon animation for running left is missing an arm cannon offset

One of the arm cannon offsets for running left is missing, and the animation points to `sArmCannonOffset_Empty` instead. This bug can only be observed if you start charging your beam while running through a door transition.

**Fix:** Add `sArmCannonOffset_Running_None_Left_Frame5` in [arm_cannon_data.c](../src/data/samus/arm_cannon_data.c), and update the offset pointer in `sArmCannonAnim_Running_None_Left`.

```diff
+ static const s16 sArmCannonOffset_Running_None_Left_Frame5[ACO_COUNT] = {
+     [ACO_Y] = C_S8_2_S16(-22),
+     [ACO_X] = C_S9_2_S16(-3)
+ };

...

  {
      .pOffset = sArmCannonOffset_Running_None_Left_Frame4,
      .pOam = sSamusOam_Empty
  },
  {
-     .pOffset = sArmCannonOffset_Empty,
+     .pOffset = sArmCannonOffset_Running_None_Left_Frame5,
      .pOam = sSamusOam_Empty
  },
  {
      .pOffset = sArmCannonOffset_Running_None_Left_Frame6,
      .pOam = sSamusOam_Empty
  },
```

### Changing the event in the debug menu doesn't equip suits

When changing the event in the pause debug menu, `EventSet` is called for every event up to the value set. This will update the security hatch level and equipped abilities. However, suits are not equipped, because a short animation plays before they're equipped.

**Fix:** Edit `PauseDebugModifyValues` in [pause_debug.c](../src/menus/pause_debug.c) to equip the suits based on the ability count.

```diff
  // Set every event starting from the beginning up to the current event, keeps the event sequence intact
  for (updateFlag = EVENT_NONE; updateFlag <= editflag; updateFlag++)
      EventSet(updateFlag);
  
+ // Suits aren't equipped in EventSet, so equip them here
+ if (gAbilityCount >= ABILITY_COUNT_VARIA_SUIT)
+ {
+     gEquipment.suitMiscStatus |= SMF_VARIA_SUIT;
+
+     if (gAbilityCount >= ABILITY_COUNT_GRAVITY_SUIT)
+         gEquipment.suitMiscStatus |= SMF_GRAVITY_SUIT;
+ }
```


## Oversights and Design Flaws

### `ClipdataConvertToCollision` is copied to RAM but still runs in ROM

`ClipdataConvertToCollision` is copied to RAM, presumably for performance reasons, because it is often called many times per frame and code runs faster in RAM. However, the switch statement gets compiled as a jump table, which ends up jumping to the code in ROM.

**Fix:** Convert the switch statement to a series of if statements. Order them such that common block types (like solid and air) are checked first.

See `ClipdataConvertToCollision` in [clipdata.c](../src/clipdata.c)

### `ClipdataCheckElevatorDisabled` checks every elevator when only one needs to be checked

`ClipdataCheckElevatorDisabled` creates an array for every elevator and stores the disabled state for each one. However, after finishing the loop through `sElevatorDisabledEvents`, only `gLastElevatorUsed` is checked to see if it's disabled.

**Fix:** Edit `ClipdataCheckElevatorDisabled` in [clipdata.c](../src/clipdata.c) to only check `gLastElevatorUsed` and immediately return `TRUE` if it's disabled.

```diff
  // Check for disabled elevators
  j = ARRAY_SIZE(sElevatorDisabledEvents);
  while (j > 0)
  {
      j--;

      // Check in the event range
      if (sElevatorDisabledEvents[j].eventStart <= gEventCounter && gEventCounter < sElevatorDisabledEvents[j].eventEnd)
      {
-         // Apply flags
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK]    |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_OPERATIONS_DECK];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_LOBBY]              |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_LOBBY];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_1]           |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_1];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_2]           |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_2];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_4]           |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_4];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_5]           |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_5];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_6]           |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_6];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_3]           |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_SECTOR_3];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE] |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_LOBBY_POWER_OUTAGE];
-         disabledElevators[ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK]   |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_MAIN_DECK_TO_HABITATIONS_DECK];
-         disabledElevators[ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1]     |= sElevatorDisabledEvents[j].disabledElevators[ELEVATOR_RESTRICTED_ZONE_TO_SECTOR_1];
+         if (sElevatorDisabledEvents[j].disabledElevators[gLastElevatorUsed])
+             return TRUE;
      }
  }

- j = disabledElevators[gLastElevatorUsed];

- if (j)
-     return j;
```

### `BeamCoreXEyeHandleRotation` has duplicate code from `SpriteUtilMakeSpriteRotateTowardsTarget`

`BeamCoreXEyeHandleRotation` contains code for calculating the target angle and new rotation that was likely directly copied from `SpriteUtilMakeSpriteRotateTowardsTarget`. It even includes [the same bug](#sprites-that-rotate-toward-a-target-will-never-target-directly-up). Given the size and complexity of the code, a function call makes more sense.

**Fix:** Edit `BeamCoreXEyeHandleRotation` in [beam_core_x.c](../src/sprites_AI/beam_core_x.c) to replace all of the code from `SpriteUtilMakeSpriteRotateTowardsTarget` with a function call. Also remove the local variables `intensity` and `targetRotation`.

```diff
- u8 intensity;
- s32 targetRotation;

  ...

- intensity = Q_8_8(1.f / 128);

  ...

- // OVERSIGHT: This is copied from SpriteUtilMakeSpriteRotateTowardsTarget
- if (targetY < spriteY)
- {
-     ...
- }
-
- ...
-
- else if (targetRotation == Q_8_8(7.f / 8))
- {
-     ...
- }
+ oamRotation = SpriteUtilMakeSpriteRotateTowardsTarget(oamRotation, targetY, targetX, spriteY, spriteX);
```

### The BOX fight can be triggered without triggering the screen shake

To trigger the first BOX fight, the game calls `EventCheckRoomEventTrigger` to check if Samus is in a certain range and sets `EVENT_TRIGGERED_BOX_RUMBLE` if so. To trigger the screen shake, the game checks for both the event being set and Samus being within a certain range of the "ceiling debris" sprite. However, the screen shake range is smaller than the event range, so the screen shake can be skipped. Since having two range checks is redundant, the screen shake range check can be removed.

**Fix:** In [shake_trigger.c](../src/sprites_AI/shake_trigger.c), delete `PreBoxCeilingDebrisCheckSamusInRange` and remove the function call in `PreBoxCeilingDebris`.

```diff
  case SPRITE_POSE_IDLE:
-     if (PreBoxCeilingDebrisCheckSamusInRange(6, 6) && EventCheckOn_BoxRumble())
+     if (EventCheckOn_BoxRumble())
      {
          gCurrentSprite.pose = 0x18;
          gCurrentSprite.pOam = sShakeTriggerOam_TriggeredNotRestrictedLab;
          gCurrentSprite.animationDurationCounter = 0;
          gCurrentSprite.currentAnimationFrame = 0;
          gCurrentSprite.work1 = CONVERT_SECONDS(1.0f);
      }
      break;
```


## Uninitialized Variables

| Variable | Function | File |
|----------|----------|------|


## TODO

### Bugs

- SA-X boss can become invulnerable if frozen the same frame it's killed ([video](https://clips.twitch.tv/WealthyOpenFriseeAllenHuhu-jjY1Gm9_VoWQO928))
- SA-X monster can become invulnerable if killed while turning ([video](https://www.youtube.com/watch?v=2jdfxKUpugE))
- SA-X monster can jump out of bounds
- BOX 2's missiles can be kept alive until the core-X spawns, which changes their palette ([video](https://www.youtube.com/watch?v=_n4L5rAxI7s))
- BOX 2's music sometimes continues after the fight is over ([video](https://clips.twitch.tv/RefinedMushyPidgeonTinyFace-sKOop5aGrK66NnNo))
- Sidehoppers and Dessgeegas don't initialize the delay for their first jump
- Sidehoppers and Dessgeegas can clip into ceilings
- Sidehoppers and Dessgeegas can get stuck on tanks
- "Stop enemy" clipdata prevents bomb jumping ([video](https://www.youtube.com/watch?v=0rtuPdS8CFY))
- PowerBombExplosion doesn't check if out of bounds, which can lead to memory corruption
  - Fix: don't check collision with any blocks outside of the room
- Clipping into slopes ([video](https://www.youtube.com/watch?v=OGtZYyUtl8s))
- Frozen enemies
  - Double hitting a frozen enemy with ice missiles doesn't kill it
  - Killing, re-freezing, and running off of an enemy on the same frame lets Samus run in air ([video](https://www.youtube.com/watch?v=mjApFImfno0))
  - Killing, re-freezing, and landing on an enemy on the same frame lets Samus run in air
  - Killing a frozen Evir and landing on it on the same frame lets Samus run in air
  - Uncrouching under a frozen enemy can clip Samus into the floor
  - Samus can teleport if a new enemy spawns while standing in air ([video](https://www.youtube.com/watch?v=wffdvlwJknQ))
- Samus can clip into ceilings by jumping out of morph ball (fixed in JP)
- Running on the edge of extendable pillars
- Getting frozen by the SA-X forces Samus to stand, even if morphed in a tunnel
- Blue-X in blocks will teleport to Samus if touched before being freed
- Touching a blue-X stuck in a block will prevent Samus from absorbing other blue-X
- Kihunters can sink through blocks by making them turn
- Diagonal X targets determine horizontal direction twice
- Omega Metroid can get stuck in air
- Doing a standing jump while keeping speedbooster
- Ridley can clip Samus into the wall ([video](https://www.youtube.com/watch?v=g4RWuOPvDCw))
- Yakuza can clip Samus into the floor ([video](https://www.youtube.com/watch?v=lPIJYAXpOr4))
- Yakuza phase 1 end being delayed one round ([video](https://www.twitch.tv/videos/63605160))
- Yakuza can skip phase 2 if enough damage is dealt
- Dismissing the Habitation Deck gate message on the last possible frame results in a softlock
- Landing on closing hatches and "wall ball" ([video](https://www.youtube.com/watch?v=KJHS8bEsmXU))
- Crash from pausing during BOX explosion sound ([video](https://www.youtube.com/watch?v=z41Vk9o-mqo))
- Sector 4 nav room music ([video](https://www.youtube.com/watch?v=Crqrie5hKcs))
- Samus can push away from ledges during the atmospheric stabilizer messages
- Hornoads can float after jumping into a wall
- Diagonal aim can get stuck if `L` is released when starting to run
- The first frame of power bomb explosions has a visual bug

### Oversights and Design Flaws

- Floating point math is used when fixed point could have been used
- Bomb's hitbox isn't centered
- Geemers hide when any button is pressed
- Pseudo-screw collision with Nettori spores is inconsistent
- The Metroids in the Restricted Lab check Samus's Y position to set their X position
- X parasites can get stuck moving in a circle

### Room Issues
- An energy tank can be collected after Arachnus spawns, corrupting its graphics
- Various tiling errors ([video](https://www.youtube.com/watch?v=QKz8VtmCCrE))
  - Sector 1, Room 0D: clipdata error
  - Sector 2, Room 00: clipdata error
  - Sector 3, Room 22: platform on wrong layer
  - Sector 5, Room 07: two misplaced BG1 blocks
  - Sector 5, Room 12: misplaced BG1 block

### Graphical Issues
- Arming missiles with Varia or Gravity suit uses Fusion suit colors for Samus's arm
