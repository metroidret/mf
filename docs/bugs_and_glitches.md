# Bugs and Glitches
These are known bugs and glitches in the game: code that clearly does not work as intended or was designed poorly. Some of them cause visible gameplay issues, while others are harmless. The bugs listed here can be fixed by compiling with the `BUGFIX` flag (bugs in the TODO section don't have a fix implemented yet). 


## Contents

- [Bugs](#bugs)
  - [Y-flipped sciser uses the wrong size for top hitbox](#y-flipped-sciser-uses-the-wrong-size-for-top-hitbox)
- [Oversights and Design Flaws](#oversights-and-design-flaws)
- [Uninitialized Variables](#uninitialized-variables)
- [TODO](#todo)
  - [Bugs](#bugs-1)
  - [Oversights and Design Flaws](#oversights-and-design-flaws-1)


## Bugs

### Y-flipped sciser uses the wrong size for top hitbox

**Fix:** Edit `SciserUpdateHitbox` in [sciser.c](../src/sprites_AI/sciser.c) to make the `hitboxTop` value negative.

```diff
  if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
  {
-     gCurrentSprite.hitboxTop = QUARTER_BLOCK_SIZE; // BUG: should be -QUARTER_BLOCK_SIZE
+     gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
      gCurrentSprite.hitboxBottom = BLOCK_TO_SUB_PIXEL(1.125f);
      gCurrentSprite.hitboxLeft = -BLOCK_TO_SUB_PIXEL(.75f);
      gCurrentSprite.hitboxRight = BLOCK_TO_SUB_PIXEL(.75f); 
  }
```

## Oversights and Design Flaws


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
- Sidehoppers can clip into ceilings
- Sidehoppers can't jump off of tanks
- "Stop enemy" clipdata prevents bomb jumping ([video](https://www.youtube.com/watch?v=0rtuPdS8CFY))
- PowerBombExplosion doesn't check if out of bounds, which can lead to memory corruption
  - Fix: don't check collision with any blocks outside of the room
- Clipping into slopes ([video](https://www.youtube.com/watch?v=OGtZYyUtl8s))
- Landing on an enemy close to the ceiling doesn't draw the arm cannon when facing right
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
- Ki-hunters can sink through blocks by making them turn
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

### Oversights and Design Flaws

- Floating point math is used when fixed point could have been used
- `ClipdataConvertToCollision` is copied to RAM but still runs in ROM
- Geemers hide when any button is pressed
- X parasites can get stuck moving in a circle
- The Metroids in the Restricted Lab check Samus's Y position to set their X position
- Pseudo-screw collision with Nettori spores is inconsistent
- Power bomb gerons use the wrong sprite ID to calculate the destroyed bit position
- Bomb's hitbox isn't centered

### Room Issues
- An energy tank can be collected after Arachnus spawns, corrupting its graphics
- Various tiling errors ([video](https://www.youtube.com/watch?v=QKz8VtmCCrE))
  - Sector 1, Room 0D: clipdata error
  - Sector 2, Room 00: clipdata error
  - Sector 3, Room 22: platform on wrong layer
  - Sector 5, Room 07: two misplaced BG1 blocks
  - Sector 5, Room 12: misplaced BG1 block

### Graphical Issues
- The OAM for starting a wall jump while facing left is missing a part
- Arming missiles with Varia or Gravity suit uses Fusion suit colors for Samus's arm
