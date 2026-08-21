    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start Box2SyncSubSprites
Box2SyncSubSprites: @ 0x080519AC
	push {r4, lr}
	ldr r4, _08051A08 @ =gSubSpriteData1
	ldrh r0, [r4, #4]
	ldr r1, [r4]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r2, _08051A0C @ =gCurrentSprite
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, _08051A10 @ =0x0879B560
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r2, #0x18]
	ldr r0, [r0]
	cmp r1, r0
	beq _080519DE
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
_080519DE:
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	ldrh r4, [r4, #0xa]
	adds r0, r0, r4
	strh r0, [r2, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08051A08: .4byte gSubSpriteData1
_08051A0C: .4byte gCurrentSprite
_08051A10: .4byte 0x0879B560

	thumb_func_start Box2XMovement
Box2XMovement: @ 0x08051A14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov sl, r7
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	mov sb, r5
	movs r0, #0
	mov r8, r0
	ldr r6, _08051A60 @ =gCurrentSprite
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051A72
	ldr r4, _08051A64 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	adds r1, #0x6e
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08051A68 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051A6C
	adds r0, r6, #0
	adds r0, #0x24
	strb r5, [r0]
	movs r1, #1
	mov r8, r1
	b _08051AA8
	.align 2, 0
_08051A60: .4byte gCurrentSprite
_08051A64: .4byte gSubSpriteData1
_08051A68: .4byte gPreviousCollisionCheck
_08051A6C:
	ldrh r0, [r4, #0xa]
	adds r0, r7, r0
	b _08051AA6
_08051A72:
	ldr r4, _08051A98 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	subs r1, #0x6e
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08051A9C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051AA0
	adds r0, r6, #0
	adds r0, #0x24
	mov r1, sb
	strb r1, [r0]
	movs r0, #1
	mov r8, r0
	b _08051AA8
	.align 2, 0
_08051A98: .4byte gSubSpriteData1
_08051A9C: .4byte gPreviousCollisionCheck
_08051AA0:
	ldrh r0, [r4, #0xa]
	mov r1, sl
	subs r0, r0, r1
_08051AA6:
	strh r0, [r4, #0xa]
_08051AA8:
	mov r0, r8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Box2Init
Box2Init: @ 0x08051AB8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _08051AD4 @ =gEquipment
	ldrb r1, [r0, #0xa]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08051ADC
	ldr r1, _08051AD8 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	b _08051C82
	.align 2, 0
_08051AD4: .4byte gEquipment
_08051AD8: .4byte gCurrentSprite
_08051ADC:
	ldr r6, _08051C8C @ =gCurrentSprite
	adds r0, r6, #0
	adds r0, #0x25
	strb r7, [r0]
	ldrh r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r3, r1, #0
	movs r5, #0
	orrs r3, r0
	strh r3, [r6]
	adds r0, r6, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _08051C90 @ =0x0000FFD8
	strh r0, [r6, #0xa]
	movs r0, #0x40
	strh r0, [r6, #0xc]
	ldr r0, _08051C94 @ =0x0000FFD0
	strh r0, [r6, #0xe]
	movs r0, #0x30
	strh r0, [r6, #0x10]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r1, #7
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x22
	movs r0, #0xc
	strb r0, [r2]
	adds r2, #0x13
	movs r0, #2
	strb r0, [r2]
	strb r1, [r6, #0x1e]
	ldr r2, _08051C98 @ =sPrimarySpriteStats
	ldrb r1, [r6, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r6, #0x14]
	adds r2, r6, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08051C9C @ =0x08395658
	str r0, [r6, #0x18]
	strb r5, [r6, #0x1c]
	strh r7, [r6, #0x16]
	ldr r4, _08051CA0 @ =gSubSpriteData1
	ldrh r0, [r6, #2]
	strh r0, [r4, #8]
	ldrh r0, [r6, #4]
	strh r0, [r4, #0xa]
	ldr r0, _08051CA4 @ =0x0839126C
	str r0, [r4]
	strb r5, [r4, #6]
	strh r7, [r4, #4]
	strb r5, [r4, #0xe]
	adds r0, r6, #0
	adds r0, #0x2f
	strb r5, [r0]
	ldr r0, _08051CA8 @ =0x0000FDFF
	ands r3, r0
	strh r3, [r6]
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	ldrb r2, [r6, #0x1f]
	adds r5, r6, #0
	adds r5, #0x23
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #1
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #2
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #3
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #4
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #5
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #6
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #8
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #9
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #0xa
	bl SpriteSpawnSecondary
	ldrb r2, [r6, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x6c
	movs r1, #0xb
	bl SpriteSpawnSecondary
	ldrb r1, [r6, #0x1e]
	ldrh r0, [r6, #2]
	str r0, [sp]
	ldrh r0, [r6, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc5
	movs r2, #7
	movs r3, #0x10
	bl SpriteSpawnPrimary
_08051C82:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051C8C: .4byte gCurrentSprite
_08051C90: .4byte 0x0000FFD8
_08051C94: .4byte 0x0000FFD0
_08051C98: .4byte sPrimarySpriteStats
_08051C9C: .4byte 0x08395658
_08051CA0: .4byte gSubSpriteData1
_08051CA4: .4byte 0x0839126C
_08051CA8: .4byte 0x0000FDFF

	thumb_func_start Box2WaitingToRunInit
Box2WaitingToRunInit: @ 0x08051CAC
	push {lr}
	ldr r1, _08051CD4 @ =gSubSpriteData1
	ldr r0, _08051CD8 @ =0x083913DC
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r0, _08051CDC @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x18
	strb r1, [r2]
	adds r0, #0x2e
	strb r3, [r0]
	ldr r0, _08051CE0 @ =0x0000026A
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08051CD4: .4byte gSubSpriteData1
_08051CD8: .4byte 0x083913DC
_08051CDC: .4byte gCurrentSprite
_08051CE0: .4byte 0x0000026A

	thumb_func_start Box2WaitingToRun
Box2WaitingToRun: @ 0x08051CE4
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08051D08
	ldr r1, _08051D20 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08051D08
	adds r1, #0x24
	movs r0, #0x19
	strb r0, [r1]
_08051D08:
	ldr r1, _08051D20 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051D1A
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
_08051D1A:
	pop {r0}
	bx r0
	.align 2, 0
_08051D20: .4byte gCurrentSprite

	thumb_func_start Box2SlowRunningInit
Box2SlowRunningInit: @ 0x08051D24
	push {lr}
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldr r0, _08051D40 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051D4C
	ldr r1, _08051D44 @ =gSubSpriteData1
	ldr r0, _08051D48 @ =0x08391354
	b _08051D50
	.align 2, 0
_08051D40: .4byte gCurrentSprite
_08051D44: .4byte gSubSpriteData1
_08051D48: .4byte 0x08391354
_08051D4C:
	ldr r1, _08051D6C @ =gSubSpriteData1
	ldr r0, _08051D70 @ =0x083912C4
_08051D50:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r0, _08051D74 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x1a
	strb r1, [r2]
	adds r0, #0x2e
	strb r3, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08051D6C: .4byte gSubSpriteData1
_08051D70: .4byte 0x083912C4
_08051D74: .4byte gCurrentSprite

	thumb_func_start Box2SlowRunning
Box2SlowRunning: @ 0x08051D78
	push {r4, r5, lr}
	ldr r4, _08051DAC @ =gSubSpriteData1
	ldr r0, [r4, #4]
	ldr r1, _08051DB0 @ =0x00FFFFFF
	ands r0, r1
	ldr r1, _08051DB4 @ =0x00010003
	cmp r0, r1
	bne _08051DCE
	ldr r0, _08051DB8 @ =0x00000279
	bl SoundPlay
	ldr r0, _08051DBC @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051DC0
	ldrh r0, [r4, #8]
	subs r0, #0x28
	ldrh r1, [r4, #0xa]
	adds r1, #0x78
	movs r2, #0x38
	bl ParticleSet
	b _08051DCE
	.align 2, 0
_08051DAC: .4byte gSubSpriteData1
_08051DB0: .4byte 0x00FFFFFF
_08051DB4: .4byte 0x00010003
_08051DB8: .4byte 0x00000279
_08051DBC: .4byte gCurrentSprite
_08051DC0:
	ldrh r0, [r4, #8]
	subs r0, #0x28
	ldrh r1, [r4, #0xa]
	subs r1, #0x78
	movs r2, #0x38
	bl ParticleSet
_08051DCE:
	ldr r5, _08051E18 @ =gCurrentSprite
	adds r4, r5, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	movs r1, #0x37
	bl Box2XMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051E12
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08051E00
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _08051E00
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x1b
	strb r0, [r1]
_08051E00:
	ldr r1, _08051E18 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051E12
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
_08051E12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08051E18: .4byte gCurrentSprite

	thumb_func_start Box2FastRunningInit
Box2FastRunningInit: @ 0x08051E1C
	push {lr}
	ldr r2, _08051E34 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051E40
	ldr r1, _08051E38 @ =gSubSpriteData1
	ldr r0, _08051E3C @ =0x08391384
	b _08051E44
	.align 2, 0
_08051E34: .4byte gCurrentSprite
_08051E38: .4byte gSubSpriteData1
_08051E3C: .4byte 0x08391384
_08051E40:
	ldr r1, _08051E60 @ =gSubSpriteData1
	ldr r0, _08051E64 @ =0x083912F4
_08051E44:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1c
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0xa
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08051E60: .4byte gSubSpriteData1
_08051E64: .4byte 0x083912F4

	thumb_func_start Box2FastRunning
Box2FastRunning: @ 0x08051E68
	push {r4, lr}
	ldr r4, _08051E9C @ =gSubSpriteData1
	ldr r0, [r4, #4]
	ldr r1, _08051EA0 @ =0x00FFFFFF
	ands r0, r1
	ldr r1, _08051EA4 @ =0x00010003
	cmp r0, r1
	bne _08051EBE
	ldr r0, _08051EA8 @ =0x00000279
	bl SoundPlay
	ldr r0, _08051EAC @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051EB0
	ldrh r0, [r4, #8]
	subs r0, #0x3c
	ldrh r1, [r4, #0xa]
	adds r1, #0xa0
	movs r2, #0x38
	bl ParticleSet
	b _08051EBE
	.align 2, 0
_08051E9C: .4byte gSubSpriteData1
_08051EA0: .4byte 0x00FFFFFF
_08051EA4: .4byte 0x00010003
_08051EA8: .4byte 0x00000279
_08051EAC: .4byte gCurrentSprite
_08051EB0:
	ldrh r0, [r4, #8]
	subs r0, #0x3c
	ldrh r1, [r4, #0xa]
	subs r1, #0xa0
	movs r2, #0x38
	bl ParticleSet
_08051EBE:
	movs r0, #8
	movs r1, #0x37
	bl Box2XMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051F1A
	ldr r2, _08051EDC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _08051EE0
	subs r0, #1
	b _08051F2A
	.align 2, 0
_08051EDC: .4byte gCurrentSprite
_08051EE0:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051F04
	ldr r0, _08051EFC @ =gSubSpriteData1
	ldrh r0, [r0, #0xa]
	subs r0, #0xc8
	ldr r1, _08051F00 @ =gSamusData
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	ble _08051F1A
	b _08051F12
	.align 2, 0
_08051EFC: .4byte gSubSpriteData1
_08051F00: .4byte gSamusData
_08051F04:
	ldr r0, _08051F34 @ =gSubSpriteData1
	ldrh r0, [r0, #0xa]
	adds r0, #0xc8
	ldr r1, _08051F38 @ =gSamusData
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bge _08051F1A
_08051F12:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1d
	strb r0, [r1]
_08051F1A:
	ldr r1, _08051F3C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051F2C
	adds r1, #0x24
	movs r0, #0x3b
_08051F2A:
	strb r0, [r1]
_08051F2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08051F34: .4byte gSubSpriteData1
_08051F38: .4byte gSamusData
_08051F3C: .4byte gCurrentSprite

	thumb_func_start Box2SkiddingInit
Box2SkiddingInit: @ 0x08051F40
	push {lr}
	ldr r2, _08051F58 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08051F64
	ldr r1, _08051F5C @ =gSubSpriteData1
	ldr r0, _08051F60 @ =0x08391444
	b _08051F68
	.align 2, 0
_08051F58: .4byte gCurrentSprite
_08051F5C: .4byte gSubSpriteData1
_08051F60: .4byte 0x08391444
_08051F64:
	ldr r1, _08051F88 @ =gSubSpriteData1
	ldr r0, _08051F8C @ =0x08391424
_08051F68:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _08051F90 @ =0x00000263
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08051F88: .4byte gSubSpriteData1
_08051F8C: .4byte 0x08391424
_08051F90: .4byte 0x00000263

	thumb_func_start Box2Skidding
Box2Skidding: @ 0x08051F94
	push {r4, r5, lr}
	ldr r4, _08051FE0 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	lsrs r0, r0, #2
	movs r1, #0x1f
	cmp r0, #5
	bls _08051FA8
	movs r1, #0x37
_08051FA8:
	bl Box2XMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051FD8
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051FC6
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1f
	strb r0, [r1]
_08051FC6:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08051FD8
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
_08051FD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08051FE0: .4byte gCurrentSprite

	thumb_func_start Box2StopSkiddingInit
Box2StopSkiddingInit: @ 0x08051FE4
	push {lr}
	ldr r2, _08051FFC @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08052008
	ldr r1, _08052000 @ =gSubSpriteData1
	ldr r0, _08052004 @ =0x08391454
	b _0805200C
	.align 2, 0
_08051FFC: .4byte gCurrentSprite
_08052000: .4byte gSubSpriteData1
_08052004: .4byte 0x08391454
_08052008:
	ldr r1, _08052020 @ =gSubSpriteData1
	ldr r0, _08052024 @ =0x08391434
_0805200C:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08052020: .4byte gSubSpriteData1
_08052024: .4byte 0x08391434

	thumb_func_start Box2StopSkidding
Box2StopSkidding: @ 0x08052028
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08052048
	ldr r1, _08052044 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x3b
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #3
	b _08052058
	.align 2, 0
_08052044: .4byte gCurrentSprite
_08052048:
	ldr r1, _08052060 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805205A
	adds r1, #0x24
	movs r0, #0x3b
_08052058:
	strb r0, [r1]
_0805205A:
	pop {r0}
	bx r0
	.align 2, 0
_08052060: .4byte gCurrentSprite

	thumb_func_start Box2BonkingInit
Box2BonkingInit: @ 0x08052064
	push {lr}
	ldr r1, _080520A8 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	subs r0, #0x10
	movs r3, #0
	movs r2, #0
	strh r0, [r1, #8]
	ldr r0, _080520AC @ =0x08391214
	str r0, [r1]
	strb r3, [r1, #6]
	strh r2, [r1, #4]
	ldr r2, _080520B0 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x31
	strb r3, [r0]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	ldr r0, _080520B4 @ =0x00000267
	bl SoundPlay
	movs r0, #0x14
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	pop {r0}
	bx r0
	.align 2, 0
_080520A8: .4byte gSubSpriteData1
_080520AC: .4byte 0x08391214
_080520B0: .4byte gCurrentSprite
_080520B4: .4byte 0x00000267

	thumb_func_start Box2Bonking
Box2Bonking: @ 0x080520B8
	push {r4, r5, r6, r7, lr}
	ldr r4, _080520DC @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _080520E0 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080520E8
	strh r1, [r4, #8]
	ldr r0, _080520E4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x4b
	strb r1, [r0]
	b _080521A0
	.align 2, 0
_080520DC: .4byte gSubSpriteData1
_080520E0: .4byte gPreviousVerticalCollisionCheck
_080520E4: .4byte gCurrentSprite
_080520E8:
	ldr r6, _08052114 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r6
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _08052118 @ =0x08390550
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _0805211C @ =0x00007FFF
	cmp r1, r0
	bne _08052120
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #8]
	b _0805217A
	.align 2, 0
_08052114: .4byte gCurrentSprite
_08052118: .4byte 0x08390550
_0805211C: .4byte 0x00007FFF
_08052120:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	mov r0, ip
	strb r2, [r0]
	ldrh r0, [r4, #8]
	adds r0, r0, r3
	strh r0, [r4, #8]
	cmp r2, #0x10
	bne _0805217A
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805215E
	ldrh r0, [r4, #8]
	subs r0, #0x34
	ldrh r1, [r4, #0xa]
	subs r1, #0x40
	movs r2, #0x38
	bl ParticleSet
	ldrh r0, [r4, #8]
	subs r0, #0x34
	ldrh r1, [r4, #0xa]
	adds r1, #0x80
	movs r2, #0x38
	bl ParticleSet
	b _0805217A
_0805215E:
	ldrh r0, [r4, #8]
	subs r0, #0x34
	ldrh r1, [r4, #0xa]
	subs r1, #0x80
	movs r2, #0x38
	bl ParticleSet
	ldrh r0, [r4, #8]
	subs r0, #0x34
	ldrh r1, [r4, #0xa]
	adds r1, #0x40
	movs r2, #0x38
	bl ParticleSet
_0805217A:
	ldr r0, _08052190 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08052198
	ldr r1, _08052194 @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	adds r0, #6
	b _0805219E
	.align 2, 0
_08052190: .4byte gCurrentSprite
_08052194: .4byte gSubSpriteData1
_08052198:
	ldr r1, _080521A8 @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	subs r0, #6
_0805219E:
	strh r0, [r1, #0xa]
_080521A0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080521A8: .4byte gSubSpriteData1

	thumb_func_start Box2LandingFromBonkInit
Box2LandingFromBonkInit: @ 0x080521AC
	push {lr}
	ldr r1, _080521DC @ =gSubSpriteData1
	ldr r0, _080521E0 @ =0x08391224
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _080521E4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x4c
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x2f
	strb r2, [r0]
	adds r0, #2
	strb r2, [r0]
	ldr r0, _080521E8 @ =0x0000027A
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_080521DC: .4byte gSubSpriteData1
_080521E0: .4byte 0x08391224
_080521E4: .4byte gCurrentSprite
_080521E8: .4byte 0x0000027A

	thumb_func_start Box2LandingFromBonk
Box2LandingFromBonk: @ 0x080521EC
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08052240
	ldr r2, _08052218 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08052220
	ldr r1, _0805221C @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _08052238
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x3b
	b _0805223E
	.align 2, 0
_08052218: .4byte gCurrentSprite
_0805221C: .4byte gSamusData
_08052220:
	ldr r1, _08052234 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bhs _08052238
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x3b
	b _0805223E
	.align 2, 0
_08052234: .4byte gSamusData
_08052238:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x17
_0805223E:
	strb r0, [r1]
_08052240:
	pop {r0}
	bx r0

	thumb_func_start Box2LandingInit
Box2LandingInit: @ 0x08052244
	push {lr}
	ldr r1, _0805226C @ =gSubSpriteData1
	ldr r0, _08052270 @ =0x08391224
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r0, _08052274 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x3a
	strb r1, [r2]
	adds r0, #0x31
	strb r3, [r0]
	ldr r0, _08052278 @ =0x0000027A
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_0805226C: .4byte gSubSpriteData1
_08052270: .4byte 0x08391224
_08052274: .4byte gCurrentSprite
_08052278: .4byte 0x0000027A

	thumb_func_start Box2Landing
Box2Landing: @ 0x0805227C
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080522B0
	ldr r1, _08052298 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x2f
	ldrb r0, [r3]
	cmp r0, #0
	bne _0805229C
	adds r1, #0x24
	movs r0, #0x27
	b _080522AE
	.align 2, 0
_08052298: .4byte gCurrentSprite
_0805229C:
	subs r0, #1
	strb r0, [r3]
	movs r2, #0x7f
	ands r2, r0
	cmp r2, #0
	bne _080522AA
	strb r2, [r3]
_080522AA:
	adds r1, #0x24
	movs r0, #0x3b
_080522AE:
	strb r0, [r1]
_080522B0:
	pop {r0}
	bx r0

	thumb_func_start Box2FinishedCrawlingInit
Box2FinishedCrawlingInit: @ 0x080522B4
	push {r4, lr}
	ldr r2, _080522E4 @ =gSubSpriteData1
	ldr r0, _080522E8 @ =0x083913B4
	str r0, [r2]
	ldr r1, _080522EC @ =gCurrentSprite
	movs r0, #0x2e
	adds r0, r0, r1
	mov ip, r0
	movs r3, #0
	movs r0, #2
	mov r4, ip
	strb r0, [r4]
	strb r3, [r2, #6]
	strh r3, [r2, #4]
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	movs r0, #0x99
	lsls r0, r0, #2
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080522E4: .4byte gSubSpriteData1
_080522E8: .4byte 0x083913B4
_080522EC: .4byte gCurrentSprite

	thumb_func_start Box2FinishCrawling
Box2FinishCrawling: @ 0x080522F0
	push {r4, r5, lr}
	ldr r4, _08052310 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	cmp r0, #1
	bls _08052314
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08052346
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	b _08052346
	.align 2, 0
_08052310: .4byte gCurrentSprite
_08052314:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08052346
	bl SpriteUtilCheckSamusOnCeilingLadder
	cmp r0, #0
	beq _0805232C
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3b
	b _08052344
_0805232C:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0805233E
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3b
	b _08052344
_0805233E:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x19
_08052344:
	strb r0, [r1]
_08052346:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start Box2JumpWarningInit
Box2JumpWarningInit: @ 0x0805234C
	push {r4, lr}
	ldr r0, _08052370 @ =gSamusData
	ldrh r4, [r0, #0x16]
	ldr r0, _08052374 @ =gSubSpriteData1
	ldrh r2, [r0, #0xa]
	adds r1, r2, #0
	subs r1, #0x78
	adds r3, r0, #0
	cmp r1, r4
	bge _08052378
	adds r0, r2, #0
	adds r0, #0x78
	cmp r0, r4
	ble _08052378
	bl Box2StoppingToFireMissilesInit
	b _0805238A
	.align 2, 0
_08052370: .4byte gSamusData
_08052374: .4byte gSubSpriteData1
_08052378:
	ldr r0, _08052390 @ =0x08391244
	str r0, [r3]
	movs r0, #0
	strb r0, [r3, #6]
	strh r0, [r3, #4]
	ldr r0, _08052394 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x3c
	strb r1, [r0]
_0805238A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052390: .4byte 0x08391244
_08052394: .4byte gCurrentSprite

	thumb_func_start Box2JumpWarning
Box2JumpWarning: @ 0x08052398
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080523AA
	ldr r0, _080523B0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x3d
	strb r1, [r0]
_080523AA:
	pop {r0}
	bx r0
	.align 2, 0
_080523B0: .4byte gCurrentSprite

	thumb_func_start Box2JumpingInit
Box2JumpingInit: @ 0x080523B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	ldr r1, _080523F4 @ =gSubSpriteData1
	ldr r0, _080523F8 @ =0x08391214
	str r0, [r1]
	strb r5, [r1, #6]
	movs r2, #0
	strh r5, [r1, #4]
	ldr r3, _080523FC @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x3e
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	subs r0, #2
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080524B2
	bl SpriteUtilCheckSamusOnCeilingLadder
	cmp r0, #0
	beq _08052400
	bl SpriteUtilMakeSpriteFaceSamusDirection
	b _08052404
	.align 2, 0
_080523F4: .4byte gSubSpriteData1
_080523F8: .4byte 0x08391214
_080523FC: .4byte gCurrentSprite
_08052400:
	bl SpriteUtilMakeSpriteFaceAwayFromSamusDirection
_08052404:
	ldr r6, _08052458 @ =gCurrentSprite
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq _08052468
	ldr r4, _0805245C @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	subs r0, #0x20
	ldrh r1, [r4, #0xa]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _08052460 @ =gPreviousCollisionCheck
	ldrb r0, [r7]
	cmp r0, #0
	beq _08052434
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08052434:
	ldrh r0, [r4, #8]
	subs r0, #0x20
	ldrh r1, [r4, #0xa]
	adds r1, #0x78
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805244C
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0805244C:
	cmp r5, #0
	beq _080524B2
	ldrh r1, [r6]
	ldr r0, _08052464 @ =0x0000FDFF
	ands r0, r1
	b _080524A8
	.align 2, 0
_08052458: .4byte gCurrentSprite
_0805245C: .4byte gSubSpriteData1
_08052460: .4byte gPreviousCollisionCheck
_08052464: .4byte 0x0000FDFF
_08052468:
	ldr r4, _080524C4 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	subs r0, #0x20
	ldrh r1, [r4, #0xa]
	ldr r2, _080524C8 @ =0xFFFFFEA2
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _080524CC @ =gPreviousCollisionCheck
	ldrb r0, [r7]
	cmp r0, #0
	beq _08052486
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08052486:
	ldrh r0, [r4, #8]
	subs r0, #0x20
	ldrh r1, [r4, #0xa]
	subs r1, #0x78
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805249E
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0805249E:
	cmp r5, #0
	beq _080524B2
	ldrh r1, [r6]
	mov r0, r8
	orrs r0, r1
_080524A8:
	strh r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #0x82
	strb r0, [r1]
_080524B2:
	ldr r0, _080524D0 @ =0x00000265
	bl SoundPlay
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080524C4: .4byte gSubSpriteData1
_080524C8: .4byte 0xFFFFFEA2
_080524CC: .4byte gPreviousCollisionCheck
_080524D0: .4byte 0x00000265

	thumb_func_start Box2Jumping
Box2Jumping: @ 0x080524D4
	push {r4, r5, r6, lr}
	ldr r3, _080524FC @ =gCurrentSprite
	adds r4, r3, #0
	adds r4, #0x31
	ldrb r2, [r4]
	ldr r1, _08052500 @ =0x08390518
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08052504 @ =0x00007FFF
	cmp r1, r0
	bne _08052508
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x39
	strb r0, [r1]
	b _08052570
	.align 2, 0
_080524FC: .4byte gCurrentSprite
_08052500: .4byte 0x08390518
_08052504: .4byte 0x00007FFF
_08052508:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	strb r2, [r4]
	ldr r4, _08052548 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	adds r0, r0, r5
	strh r0, [r4, #8]
	cmp r2, #0x17
	bne _08052568
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805254C
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	subs r1, #0x40
	movs r2, #0x38
	bl ParticleSet
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	adds r1, #0x80
	movs r2, #0x38
	bl ParticleSet
	b _08052568
	.align 2, 0
_08052548: .4byte gSubSpriteData1
_0805254C:
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	subs r1, #0x80
	movs r2, #0x38
	bl ParticleSet
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	adds r1, #0x40
	movs r2, #0x38
	bl ParticleSet
_08052568:
	movs r0, #0xc
	movs r1, #0x37
	bl Box2XMovement
_08052570:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Box2StoppingToFireMissilesInit
Box2StoppingToFireMissilesInit: @ 0x08052578
	push {r4, lr}
	ldr r2, _080525A8 @ =gSubSpriteData1
	ldr r0, _080525AC @ =0x083913B4
	str r0, [r2]
	ldr r1, _080525B0 @ =gCurrentSprite
	movs r0, #0x2e
	adds r0, r0, r1
	mov ip, r0
	movs r3, #0
	movs r0, #3
	mov r4, ip
	strb r0, [r4]
	strb r3, [r2, #6]
	strh r3, [r2, #4]
	adds r1, #0x24
	movs r0, #0x28
	strb r0, [r1]
	movs r0, #0x99
	lsls r0, r0, #2
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080525A8: .4byte gSubSpriteData1
_080525AC: .4byte 0x083913B4
_080525B0: .4byte gCurrentSprite

	thumb_func_start Box2StoppingToFireMissiles
Box2StoppingToFireMissiles: @ 0x080525B4
	push {r4, r5, lr}
	ldr r5, _080525D4 @ =gCurrentSprite
	adds r4, r5, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	cmp r0, #1
	bls _080525D8
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _080525E8
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _080525E8
	.align 2, 0
_080525D4: .4byte gCurrentSprite
_080525D8:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080525E8
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
_080525E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Box2LoweringToFireMissilesInit
Box2LoweringToFireMissilesInit: @ 0x080525F0
	push {lr}
	ldr r1, _08052614 @ =gSubSpriteData1
	ldr r0, _08052618 @ =0x08391464
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _0805261C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2a
	strb r1, [r0]
	movs r0, #0x9a
	lsls r0, r0, #2
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08052614: .4byte gSubSpriteData1
_08052618: .4byte 0x08391464
_0805261C: .4byte gCurrentSprite

	thumb_func_start Box2LoweringToFireMissiles
Box2LoweringToFireMissiles: @ 0x08052620
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805263E
	ldr r0, _08052644 @ =gCurrentSprite
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x2c
	strb r1, [r0]
	ldr r0, _08052648 @ =gSubSpriteData1
	ldr r1, _0805264C @ =0x083914A4
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
_0805263E:
	pop {r0}
	bx r0
	.align 2, 0
_08052644: .4byte gCurrentSprite
_08052648: .4byte gSubSpriteData1
_0805264C: .4byte 0x083914A4

	thumb_func_start Box2FiringMissiles
Box2FiringMissiles: @ 0x08052650
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl SpriteUtilHasSubSprite1AnimationEnded
	adds r6, r0, #0
	cmp r6, #0
	beq _0805268C
	ldr r0, _0805267C @ =gCurrentSprite
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x2e
	strb r1, [r0]
	ldr r0, _08052680 @ =gSubSpriteData1
	ldr r1, _08052684 @ =0x0839150C
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
	ldr r0, _08052688 @ =0x00000269
	bl SoundPlay
	b _0805274C
	.align 2, 0
_0805267C: .4byte gCurrentSprite
_08052680: .4byte gSubSpriteData1
_08052684: .4byte 0x0839150C
_08052688: .4byte 0x00000269
_0805268C:
	ldr r3, _080526C4 @ =gCurrentSprite
	ldrh r4, [r3, #2]
	ldrh r5, [r3, #4]
	ldr r0, _080526C8 @ =gSubSpriteData1
	ldr r1, [r0, #4]
	ldr r0, _080526CC @ =0x00FFFFFF
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0xc
	cmp r1, r0
	bne _080526D0
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x8c
	str r0, [sp]
	adds r0, r5, #0
	subs r0, #0x30
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x6d
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0805274C
	.align 2, 0
_080526C4: .4byte gCurrentSprite
_080526C8: .4byte gSubSpriteData1
_080526CC: .4byte 0x00FFFFFF
_080526D0:
	ldr r0, _080526F8 @ =0x00080003
	cmp r1, r0
	bne _080526FC
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x90
	str r0, [sp]
	adds r0, r5, #0
	subs r0, #0x18
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x6d
	movs r1, #1
	bl SpriteSpawnSecondary
	b _0805274C
	.align 2, 0
_080526F8: .4byte 0x00080003
_080526FC:
	ldr r0, _08052724 @ =0x00080006
	cmp r1, r0
	bne _08052728
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x90
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0x18
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x6d
	movs r1, #2
	bl SpriteSpawnSecondary
	b _0805274C
	.align 2, 0
_08052724: .4byte 0x00080006
_08052728:
	ldr r0, _08052754 @ =0x00080009
	cmp r1, r0
	bne _0805274C
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x8c
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #0x30
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x6d
	movs r1, #3
	bl SpriteSpawnSecondary
_0805274C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08052754: .4byte 0x00080009

	thumb_func_start Box2DoneFiringMissiles
Box2DoneFiringMissiles: @ 0x08052758
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _0805276A
	ldr r0, _08052770 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x17
	strb r1, [r0]
_0805276A:
	pop {r0}
	bx r0
	.align 2, 0
_08052770: .4byte gCurrentSprite

	thumb_func_start Box2DyingInit
Box2DyingInit: @ 0x08052774
	ldr r0, _0805279C @ =gCurrentSprite
	ldr r1, _080527A0 @ =0x08395658
	str r1, [r0, #0x18]
	movs r2, #0
	strb r2, [r0, #0x1c]
	movs r3, #0
	strh r2, [r0, #0x16]
	adds r1, r0, #0
	adds r1, #0x31
	strb r3, [r1]
	adds r0, #0x24
	movs r1, #0x44
	strb r1, [r0]
	ldr r0, _080527A4 @ =gSubSpriteData1
	ldr r1, _080527A8 @ =0x0839126C
	str r1, [r0]
	strb r3, [r0, #6]
	strh r2, [r0, #4]
	bx lr
	.align 2, 0
_0805279C: .4byte gCurrentSprite
_080527A0: .4byte 0x08395658
_080527A4: .4byte gSubSpriteData1
_080527A8: .4byte 0x0839126C

	thumb_func_start Box2Dying
Box2Dying: @ 0x080527AC
	push {r4, lr}
	ldr r4, _080527D0 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _080527D4 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080527DC
	strh r1, [r4, #8]
	ldr r0, _080527D8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x45
	strb r1, [r0]
	b _080527E2
	.align 2, 0
_080527D0: .4byte gSubSpriteData1
_080527D4: .4byte gPreviousVerticalCollisionCheck
_080527D8: .4byte gCurrentSprite
_080527DC:
	ldrh r0, [r4, #8]
	adds r0, #0x10
	strh r0, [r4, #8]
_080527E2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Box2ExplodingInit
Box2ExplodingInit: @ 0x080527E8
	ldr r1, _08052808 @ =gCurrentSprite
	ldr r0, _0805280C @ =0x083956B8
	str r0, [r1, #0x18]
	movs r2, #0
	strb r2, [r1, #0x1c]
	movs r3, #0
	strh r2, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x46
	strb r0, [r1]
	ldr r0, _08052810 @ =gSubSpriteData1
	ldr r1, _08052814 @ =0x0839126C
	str r1, [r0]
	strb r3, [r0, #6]
	strh r2, [r0, #4]
	bx lr
	.align 2, 0
_08052808: .4byte gCurrentSprite
_0805280C: .4byte 0x083956B8
_08052810: .4byte gSubSpriteData1
_08052814: .4byte 0x0839126C

	thumb_func_start Box2Exploding
Box2Exploding: @ 0x08052818
	push {r4, lr}
	ldr r0, _08052838 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	movs r2, #7
	ands r2, r0
	ldr r4, _0805283C @ =gCurrentSprite
	cmp r2, #0
	bne _08052842
	adds r1, r4, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	bne _08052840
	movs r0, #0xb
	strb r0, [r1]
	b _08052842
	.align 2, 0
_08052838: .4byte gFrameCounter8Bit
_0805283C: .4byte gCurrentSprite
_08052840:
	strb r2, [r1]
_08052842:
	ldrh r0, [r4, #4]
	lsrs r0, r0, #2
	ldr r1, _08052870 @ =gBg1XPosition
	ldrh r1, [r1]
	lsrs r1, r1, #2
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08052874 @ =0xFFE70000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0xbe
	bhi _0805286A
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _0805286A
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x47
	strb r0, [r1]
_0805286A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052870: .4byte gBg1XPosition
_08052874: .4byte 0xFFE70000

	thumb_func_start Box2BrainRisingInit
Box2BrainRisingInit: @ 0x08052878
	push {lr}
	ldr r3, _080528A4 @ =gCurrentSprite
	ldr r0, _080528A8 @ =0x083958C8
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r2, #0
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x48
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x20
	strb r2, [r0]
	adds r0, #0xe
	strb r2, [r0]
	movs r0, #3
	bl RoomEffectStartStopEventBased
	pop {r0}
	bx r0
	.align 2, 0
_080528A4: .4byte gCurrentSprite
_080528A8: .4byte 0x083958C8

	thumb_func_start Box2BrainRising
Box2BrainRising: @ 0x080528AC
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, _080528E0 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	ldr r2, _080528E4 @ =gCurrentSprite
	cmp r0, #0
	bne _080528C6
	ldrh r0, [r2]
	movs r1, #4
	eors r0, r1
	strh r0, [r2]
_080528C6:
	ldrh r4, [r2, #2]
	ldrh r5, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0x42
	bls _080528D6
	b _08052AAC
_080528D6:
	lsls r0, r0, #2
	ldr r1, _080528E8 @ =_080528EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080528E0: .4byte gFrameCounter8Bit
_080528E4: .4byte gCurrentSprite
_080528E8: .4byte _080528EC
_080528EC: @ jump table
	.4byte _080529F8 @ case 0
	.4byte _08052A44 @ case 1
	.4byte _08052AAC @ case 2
	.4byte _08052AAC @ case 3
	.4byte _08052AAC @ case 4
	.4byte _08052AAC @ case 5
	.4byte _08052AAC @ case 6
	.4byte _08052AAC @ case 7
	.4byte _08052A4C @ case 8
	.4byte _08052AAC @ case 9
	.4byte _08052AAC @ case 10
	.4byte _08052AAC @ case 11
	.4byte _08052AAC @ case 12
	.4byte _08052AAC @ case 13
	.4byte _08052AAC @ case 14
	.4byte _08052AAC @ case 15
	.4byte _08052A56 @ case 16
	.4byte _08052AAC @ case 17
	.4byte _08052AAC @ case 18
	.4byte _08052AAC @ case 19
	.4byte _08052AAC @ case 20
	.4byte _08052AAC @ case 21
	.4byte _08052AAC @ case 22
	.4byte _08052AAC @ case 23
	.4byte _08052AAC @ case 24
	.4byte _08052AAC @ case 25
	.4byte _08052AAC @ case 26
	.4byte _08052AAC @ case 27
	.4byte _08052AAC @ case 28
	.4byte _08052AAC @ case 29
	.4byte _08052A66 @ case 30
	.4byte _08052AAC @ case 31
	.4byte _08052AAC @ case 32
	.4byte _08052AAC @ case 33
	.4byte _08052AAC @ case 34
	.4byte _08052AAC @ case 35
	.4byte _08052AAC @ case 36
	.4byte _08052AAC @ case 37
	.4byte _08052A76 @ case 38
	.4byte _08052AAC @ case 39
	.4byte _08052AAC @ case 40
	.4byte _08052AAC @ case 41
	.4byte _08052AAC @ case 42
	.4byte _08052AAC @ case 43
	.4byte _08052AAC @ case 44
	.4byte _08052AAC @ case 45
	.4byte _08052A80 @ case 46
	.4byte _08052AAC @ case 47
	.4byte _08052AAC @ case 48
	.4byte _08052AAC @ case 49
	.4byte _08052AAC @ case 50
	.4byte _08052AAC @ case 51
	.4byte _08052AAC @ case 52
	.4byte _08052AAC @ case 53
	.4byte _08052AAC @ case 54
	.4byte _08052AAC @ case 55
	.4byte _08052AAC @ case 56
	.4byte _08052AAC @ case 57
	.4byte _08052AAC @ case 58
	.4byte _08052AAC @ case 59
	.4byte _08052AAC @ case 60
	.4byte _08052AAC @ case 61
	.4byte _08052AAC @ case 62
	.4byte _08052AAC @ case 63
	.4byte _08052AAC @ case 64
	.4byte _08052AAC @ case 65
	.4byte _08052A90 @ case 66
_080529F8:
	ldr r0, _08052A38 @ =gCurrentSprite
	ldrb r2, [r0, #0x1f]
	adds r0, #0x23
	ldrb r3, [r0]
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x6e
	movs r1, #0
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08052A3C @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r1, #0x23
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r5, #0
	movs r2, #0x30
	bl ParticleSet
	ldr r0, _08052A40 @ =0x0000026E
	bl SoundPlay_3b1c
	b _08052AAC
	.align 2, 0
_08052A38: .4byte gCurrentSprite
_08052A3C: .4byte gSpriteData
_08052A40: .4byte 0x0000026E
_08052A44:
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	b _08052A6E
_08052A4C:
	adds r0, r4, #0
	adds r0, #0x86
	adds r1, r5, #0
	adds r1, #0x70
	b _08052A5E
_08052A56:
	adds r0, r4, #0
	adds r0, #0x86
	adds r1, r5, #0
	subs r1, #0x70
_08052A5E:
	movs r2, #0x30
	bl ParticleSet
	b _08052AAC
_08052A66:
	adds r0, r4, #0
	adds r0, #0x14
	adds r1, r5, #0
	subs r1, #0xa
_08052A6E:
	movs r2, #0x35
	bl ParticleSet
	b _08052AAC
_08052A76:
	adds r0, r4, #0
	adds r0, #0x5c
	adds r1, r5, #0
	adds r1, #0x90
	b _08052A88
_08052A80:
	adds r0, r4, #0
	adds r0, #0x5c
	adds r1, r5, #0
	subs r1, #0x90
_08052A88:
	movs r2, #0x2f
	bl ParticleSet
	b _08052AAC
_08052A90:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x49
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x3c
	strb r0, [r1]
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	b _08052AB6
_08052AAC:
	ldr r1, _08052AC0 @ =gCurrentSprite
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08052AB6:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052AC0: .4byte gCurrentSprite

	thumb_func_start Box2BrainFloating
Box2BrainFloating: @ 0x08052AC4
	push {lr}
	ldr r2, _08052AE0 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08052ADC
	strh r0, [r2]
_08052ADC:
	pop {r0}
	bx r0
	.align 2, 0
_08052AE0: .4byte gCurrentSprite

	thumb_func_start Box2IdleInit
Box2IdleInit: @ 0x08052AE4
	push {lr}
	ldr r2, _08052AFC @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08052B08
	ldr r1, _08052B00 @ =gSubSpriteData1
	ldr r0, _08052B04 @ =0x08391324
	b _08052B0C
	.align 2, 0
_08052AFC: .4byte gCurrentSprite
_08052B00: .4byte gSubSpriteData1
_08052B04: .4byte 0x08391324
_08052B08:
	ldr r1, _08052B20 @ =gSubSpriteData1
	ldr r0, _08052B24 @ =0x08391294
_08052B0C:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08052B20: .4byte gSubSpriteData1
_08052B24: .4byte 0x08391294

	thumb_func_start Box2Crawling
Box2Crawling: @ 0x08052B28
	push {lr}
	movs r0, #1
	movs r1, #7
	bl Box2XMovement
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Box2PartSetBoxWorkVar2
Box2PartSetBoxWorkVar2: @ 0x08052B38
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	ldr r2, _08052B5C @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, r3
	bhs _08052B56
	strb r3, [r1]
_08052B56:
	pop {r0}
	bx r0
	.align 2, 0
_08052B5C: .4byte gSpriteData

	thumb_func_start Box2PartCenterSetImmunity
Box2PartCenterSetImmunity: @ 0x08052B60
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _08052B88 @ =gSpriteData
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #0x29
	adds r3, r1, #0
	cmp r0, #0x19
	bhi _08052C2C
	lsls r0, r0, #2
	ldr r1, _08052B8C @ =_08052B90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08052B88: .4byte gSpriteData
_08052B8C: .4byte _08052B90
_08052B90: @ jump table
	.4byte _08052BF8 @ case 0
	.4byte _08052BF8 @ case 1
	.4byte _08052C2C @ case 2
	.4byte _08052BF8 @ case 3
	.4byte _08052C2C @ case 4
	.4byte _08052BF8 @ case 5
	.4byte _08052C2C @ case 6
	.4byte _08052C2C @ case 7
	.4byte _08052C2C @ case 8
	.4byte _08052C2C @ case 9
	.4byte _08052C2C @ case 10
	.4byte _08052C2C @ case 11
	.4byte _08052C2C @ case 12
	.4byte _08052C2C @ case 13
	.4byte _08052C2C @ case 14
	.4byte _08052C2C @ case 15
	.4byte _08052C2C @ case 16
	.4byte _08052C2C @ case 17
	.4byte _08052C2C @ case 18
	.4byte _08052C2C @ case 19
	.4byte _08052C2C @ case 20
	.4byte _08052C2C @ case 21
	.4byte _08052C1C @ case 22
	.4byte _08052C1C @ case 23
	.4byte _08052C1C @ case 24
	.4byte _08052C1C @ case 25
_08052BF8:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08052C2C
	ldr r0, _08052C18 @ =gCurrentSprite
	adds r0, #0x34
	ldrb r2, [r0]
	movs r1, #0x40
	orrs r1, r2
	b _08052C36
	.align 2, 0
_08052C18: .4byte gCurrentSprite
_08052C1C:
	ldr r0, _08052C28 @ =gCurrentSprite
	adds r0, #0x34
	ldrb r2, [r0]
	movs r1, #0x40
	orrs r1, r2
	b _08052C36
	.align 2, 0
_08052C28: .4byte gCurrentSprite
_08052C2C:
	ldr r0, _08052C3C @ =gCurrentSprite
	adds r0, #0x34
	ldrb r2, [r0]
	movs r1, #0xbf
	ands r1, r2
_08052C36:
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08052C3C: .4byte gCurrentSprite

	thumb_func_start Box2PartRemoveIgnoreProjectiles
Box2PartRemoveIgnoreProjectiles: @ 0x08052C40
	ldr r2, _08052C4C @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _08052C50 @ =0x00007FFF
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08052C4C: .4byte gCurrentSprite
_08052C50: .4byte 0x00007FFF

	thumb_func_start Box2PartInit
Box2PartInit: @ 0x08052C54
	push {r4, lr}
	ldr r2, _08052C8C @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _08052C90 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0x10
	strb r0, [r1]
	subs r1, #5
	movs r0, #2
	strb r0, [r1]
	ldrb r0, [r2, #0x1e]
	adds r4, r2, #0
	cmp r0, #6
	bhi _08052C94
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xb
	b _08052C9A
	.align 2, 0
_08052C8C: .4byte gCurrentSprite
_08052C90: .4byte 0x0000FFFB
_08052C94:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xd
_08052C9A:
	strb r0, [r1]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0xb
	bls _08052CA4
	b _08052E00
_08052CA4:
	lsls r0, r0, #2
	ldr r1, _08052CB0 @ =_08052CB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08052CB0: .4byte _08052CB4
_08052CB4: @ jump table
	.4byte _08052CE4 @ case 0
	.4byte _08052DC4 @ case 1
	.4byte _08052CE4 @ case 2
	.4byte _08052DC4 @ case 3
	.4byte _08052DC4 @ case 4
	.4byte _08052DC4 @ case 5
	.4byte _08052D34 @ case 6
	.4byte _08052E00 @ case 7
	.4byte _08052DC4 @ case 8
	.4byte _08052D80 @ case 9
	.4byte _08052DC4 @ case 10
	.4byte _08052DC4 @ case 11
_08052CE4:
	ldr r0, _08052D28 @ =0x0000FFB8
	strh r0, [r4, #0xa]
	movs r0, #0x48
	strh r0, [r4, #0xc]
	ldr r0, _08052D2C @ =0x0000FFE0
	strh r0, [r4, #0xe]
	movs r0, #0x20
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #2
	strb r0, [r1]
	subs r1, #0x10
	strb r0, [r1]
	ldr r1, _08052D30 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	bl Box2SyncSubSprites
	ldrb r0, [r4, #0x1e]
	cmp r0, #2
	bne _08052E04
	movs r0, #7
	strh r0, [r4, #0x16]
	b _08052E04
	.align 2, 0
_08052D28: .4byte 0x0000FFB8
_08052D2C: .4byte 0x0000FFE0
_08052D30: .4byte sSecondarySpriteStats
_08052D34:
	movs r2, #0
	movs r3, #0
	ldr r0, _08052D70 @ =0x0000FFD0
	strh r0, [r4, #0xa]
	movs r0, #0x40
	strh r0, [r4, #0xc]
	ldr r0, _08052D74 @ =0x0000FFE0
	strh r0, [r4, #0xe]
	movs r0, #0x20
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #1
	strb r0, [r1]
	subs r1, #0x10
	movs r0, #2
	strb r0, [r1]
	ldr r1, _08052D78 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	ldr r0, _08052D7C @ =0x08395868
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _08052E04
	.align 2, 0
_08052D70: .4byte 0x0000FFD0
_08052D74: .4byte 0x0000FFE0
_08052D78: .4byte sSecondarySpriteStats
_08052D7C: .4byte 0x08395868
_08052D80:
	ldr r0, _08052DB8 @ =0x0000FFE0
	strh r0, [r4, #0xa]
	movs r0, #0x20
	strh r0, [r4, #0xc]
	ldr r0, _08052DBC @ =0x0000FFC0
	strh r0, [r4, #0xe]
	movs r0, #0x40
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	ldr r1, _08052DC0 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	bl Box2SyncSubSprites
	b _08052E04
	.align 2, 0
_08052DB8: .4byte 0x0000FFE0
_08052DBC: .4byte 0x0000FFC0
_08052DC0: .4byte sSecondarySpriteStats
_08052DC4:
	movs r2, #0
	ldr r1, _08052DF8 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x25
	strb r2, [r0]
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _08052DFC @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	bl Box2SyncSubSprites
	b _08052E04
	.align 2, 0
_08052DF8: .4byte 0x0000FFFC
_08052DFC: .4byte sSecondarySpriteStats
_08052E00:
	movs r0, #0
	strh r0, [r4]
_08052E04:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Box2PartFrontLeftLeg
Box2PartFrontLeftLeg: @ 0x08052E0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08052E40 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	mov sb, r0
	mov sl, sb
	ldr r0, _08052E44 @ =gSpriteData
	mov r2, sb
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08052E48
	strh r1, [r4]
	b _08052F96
	.align 2, 0
_08052E40: .4byte gCurrentSprite
_08052E44: .4byte gSpriteData
_08052E48:
	ldrh r2, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _08052E56
	b _08052F96
_08052E56:
	ldr r1, _08052E78 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r5, [r0]
	ldrh r6, [r4, #2]
	ldrh r7, [r4, #4]
	mov r0, r8
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x46
	bne _08052E7C
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r0, r2
	strh r0, [r4]
	b _08052ED2
	.align 2, 0
_08052E78: .4byte sSecondarySpriteStats
_08052E7C:
	mov r0, sb
	bl Box2PartRemoveIgnoreProjectiles
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08052EE0
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	beq _08052EE6
	mov r0, r8
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08052EC8
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0
	bne _08052F96
	adds r0, r6, #0
	adds r0, #0x30
	adds r1, r7, #0
	movs r2, #0x2e
	bl ParticleSet
	b _08052F96
_08052EC8:
	ldrh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r1, r0
	strh r1, [r4]
_08052ED2:
	adds r0, r6, #0
	adds r0, #0x32
	adds r1, r7, #0
	movs r2, #0x2f
	bl ParticleSet
	b _08052F96
_08052EE0:
	ldrh r1, [r4, #0x14]
	cmp r1, #0
	bne _08052F28
_08052EE6:
	ldr r1, _08052F20 @ =gSpriteData
	mov r2, sl
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x2d
	ldrb r2, [r0]
	movs r1, #0xfe
	ands r1, r2
	strb r1, [r0]
	ldr r1, _08052F24 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r0, #4
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strh r0, [r1, #0x14]
	adds r1, #0x2e
	strb r3, [r1]
	adds r0, r6, #0
	adds r0, #0x32
	adds r1, r7, #0
	movs r2, #0x2f
	bl ParticleSet
	mov r0, sl
	b _08052F5A
	.align 2, 0
_08052F20: .4byte gSpriteData
_08052F24: .4byte gCurrentSprite
_08052F28:
	lsrs r0, r5, #2
	cmp r1, r0
	bhs _08052F38
	ldr r0, [r4, #0x18]
	ldr r1, _08052F34 @ =0x08395420
	b _08052F42
	.align 2, 0
_08052F34: .4byte 0x08395420
_08052F38:
	lsrs r0, r5, #1
	cmp r1, r0
	bhs _08052F68
	ldr r0, [r4, #0x18]
	ldr r1, _08052F64 @ =0x08395410
_08052F42:
	cmp r0, r1
	beq _08052F96
	str r1, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r0, r6, #0
	adds r0, #0x24
	adds r1, r7, #0
	movs r2, #0x2d
	bl ParticleSet
	mov r0, sb
_08052F5A:
	movs r1, #1
	bl Box2PartSetBoxWorkVar2
	b _08052F96
	.align 2, 0
_08052F64: .4byte 0x08395410
_08052F68:
	ldrh r1, [r4, #0x14]
	lsls r0, r5, #1
	adds r0, r0, r5
	asrs r0, r0, #2
	cmp r1, r0
	bge _08052F96
	ldr r0, [r4, #0x18]
	ldr r1, _08052FA4 @ =0x08395400
	cmp r0, r1
	beq _08052F96
	str r1, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r0, r6, #0
	adds r0, #0x24
	adds r1, r7, #0
	movs r2, #0x2d
	bl ParticleSet
	mov r0, sl
	movs r1, #1
	bl Box2PartSetBoxWorkVar2
_08052F96:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052FA4: .4byte 0x08395400

	thumb_func_start Box2PartFrontRightLeg
Box2PartFrontRightLeg: @ 0x08052FA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08052FDC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	mov sb, r0
	str r0, [sp]
	ldr r0, _08052FE0 @ =gSpriteData
	mov r2, sb
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	mov r8, r1
	ldrh r0, [r1]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08052FE4
	strh r1, [r4]
	b _08053132
	.align 2, 0
_08052FDC: .4byte gCurrentSprite
_08052FE0: .4byte gSpriteData
_08052FE4:
	ldrh r2, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	mov sl, r0
	ands r0, r2
	cmp r0, #0
	beq _08052FF4
	b _08053132
_08052FF4:
	ldr r1, _08053014 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r5, [r0]
	ldrh r6, [r4, #2]
	ldrh r7, [r4, #4]
	mov r0, r8
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x46
	bne _08053018
	mov r0, sl
	orrs r0, r2
	strh r0, [r4]
	b _0805306C
	.align 2, 0
_08053014: .4byte sSecondarySpriteStats
_08053018:
	mov r0, sb
	bl Box2PartRemoveIgnoreProjectiles
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0805307A
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	beq _08053080
	mov r0, r8
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08053064
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0
	bne _08053132
	adds r0, r6, #0
	adds r0, #0x30
	adds r1, r7, #0
	movs r2, #0x2e
	bl ParticleSet
	b _08053132
_08053064:
	ldrh r0, [r4]
	mov r1, sl
	orrs r1, r0
	strh r1, [r4]
_0805306C:
	adds r0, r6, #0
	adds r0, #0x32
	adds r1, r7, #0
	movs r2, #0x2f
	bl ParticleSet
	b _08053132
_0805307A:
	ldrh r1, [r4, #0x14]
	cmp r1, #0
	bne _080530C4
_08053080:
	ldr r1, _080530BC @ =gSpriteData
	ldr r2, [sp]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x2d
	ldrb r2, [r0]
	movs r1, #0xfd
	ands r1, r2
	strb r1, [r0]
	ldr r1, _080530C0 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r0, #4
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strh r0, [r1, #0x14]
	adds r1, #0x2e
	strb r3, [r1]
	adds r0, r6, #0
	adds r0, #0x32
	adds r1, r7, #0
	movs r2, #0x2f
	bl ParticleSet
	ldr r0, [sp]
	b _080530F6
	.align 2, 0
_080530BC: .4byte gSpriteData
_080530C0: .4byte gCurrentSprite
_080530C4:
	lsrs r0, r5, #2
	cmp r1, r0
	bhs _080530D4
	ldr r0, [r4, #0x18]
	ldr r1, _080530D0 @ =0x08395588
	b _080530DE
	.align 2, 0
_080530D0: .4byte 0x08395588
_080530D4:
	lsrs r0, r5, #1
	cmp r1, r0
	bhs _08053104
	ldr r0, [r4, #0x18]
	ldr r1, _08053100 @ =0x08395578
_080530DE:
	cmp r0, r1
	beq _08053132
	str r1, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r0, r6, #0
	adds r0, #0x24
	adds r1, r7, #0
	movs r2, #0x2d
	bl ParticleSet
	mov r0, sb
_080530F6:
	movs r1, #1
	bl Box2PartSetBoxWorkVar2
	b _08053132
	.align 2, 0
_08053100: .4byte 0x08395578
_08053104:
	ldrh r1, [r4, #0x14]
	lsls r0, r5, #1
	adds r0, r0, r5
	asrs r0, r0, #2
	cmp r1, r0
	bge _08053132
	ldr r0, [r4, #0x18]
	ldr r1, _08053144 @ =0x08395568
	cmp r0, r1
	beq _08053132
	str r1, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r0, r6, #0
	adds r0, #0x24
	adds r1, r7, #0
	movs r2, #0x2d
	bl ParticleSet
	ldr r0, [sp]
	movs r1, #1
	bl Box2PartSetBoxWorkVar2
_08053132:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053144: .4byte 0x08395568

	thumb_func_start Box2PartTopShell
Box2PartTopShell: @ 0x08053148
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08053178 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	mov sb, r0
	ldr r0, _0805317C @ =gSpriteData
	mov r2, sb
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r7, r1, r0
	ldrh r0, [r7]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08053180
	strh r1, [r4]
	b _08053270
	.align 2, 0
_08053178: .4byte gCurrentSprite
_0805317C: .4byte gSpriteData
_08053180:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	mov sl, r0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _08053270
	ldr r1, _080531DC @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r6, [r0]
	ldrh r3, [r4, #2]
	ldrh r2, [r4, #4]
	mov r8, r2
	mov r0, sb
	str r3, [sp]
	bl Box2PartCenterSetImmunity
	ldrh r1, [r4, #0x14]
	ldr r3, [sp]
	cmp r1, #0
	bne _080531E0
	adds r2, r7, #0
	adds r2, #0x2d
	ldrb r1, [r2]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x32
	mov r1, r8
	movs r2, #0x2f
	bl ParticleSet
	ldrh r1, [r4]
	mov r0, sl
	orrs r0, r1
	strh r0, [r4]
	adds r1, r7, #0
	adds r1, #0x24
	movs r0, #0x43
	strb r0, [r1]
	b _08053252
	.align 2, 0
_080531DC: .4byte sSecondarySpriteStats
_080531E0:
	lsrs r0, r6, #2
	cmp r1, r0
	bhs _080531F0
	ldr r0, [r4, #0x18]
	ldr r1, _080531EC @ =0x08395648
	b _08053210
	.align 2, 0
_080531EC: .4byte 0x08395648
_080531F0:
	lsrs r0, r6, #1
	cmp r1, r0
	bhs _08053200
	ldr r0, [r4, #0x18]
	ldr r1, _080531FC @ =0x08395638
	b _08053210
	.align 2, 0
_080531FC: .4byte 0x08395638
_08053200:
	ldrh r1, [r4, #0x14]
	lsls r0, r6, #1
	adds r0, r0, r6
	asrs r0, r0, #2
	cmp r1, r0
	bge _0805322C
	ldr r0, [r4, #0x18]
	ldr r1, _08053228 @ =0x08395628
_08053210:
	cmp r0, r1
	beq _08053252
	str r1, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r5, [r4, #0x16]
	adds r0, r3, #0
	adds r0, #0x24
	mov r1, r8
	movs r2, #0x30
	bl ParticleSet
	b _08053252
	.align 2, 0
_08053228: .4byte 0x08395628
_0805322C:
	cmp r1, r6
	bhs _08053252
	ldr r0, [r4, #0x18]
	ldr r2, _08053280 @ =0x08395618
	cmp r0, r2
	beq _08053252
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #2
	strb r0, [r1]
	str r2, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r5, [r4, #0x16]
	adds r0, r3, #0
	adds r0, #0x24
	mov r1, r8
	movs r2, #0x30
	bl ParticleSet
_08053252:
	ldr r0, _08053284 @ =gCurrentSprite
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08053270
	mov r0, sb
	movs r1, #2
	bl Box2PartSetBoxWorkVar2
	movs r0, #0x9e
	lsls r0, r0, #2
	bl SoundPlay
_08053270:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053280: .4byte 0x08395618
_08053284: .4byte gCurrentSprite

	thumb_func_start Box2PartBottomShell
Box2PartBottomShell: @ 0x08053288
	push {r4, r5, lr}
	ldr r3, _080532AC @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _080532B0 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r2, r0, r2
	ldrh r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080532B4
	strh r1, [r3]
	b _08053340
	.align 2, 0
_080532AC: .4byte gCurrentSprite
_080532B0: .4byte gSpriteData
_080532B4:
	ldrh r4, [r3]
	movs r5, #0x80
	lsls r5, r5, #6
	adds r0, r5, #0
	ands r0, r4
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08053340
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3c
	beq _080532E8
	cmp r0, #0x3c
	bgt _080532DE
	cmp r0, #8
	beq _080532E8
	cmp r0, #0x18
	beq _080532E8
	b _08053330
_080532DE:
	cmp r0, #0x46
	beq _080532F4
	cmp r0, #0x48
	beq _08053328
	b _08053330
_080532E8:
	ldr r0, [r3, #0x18]
	ldr r1, _080532F0 @ =0x08395728
	b _08053334
	.align 2, 0
_080532F0: .4byte 0x08395728
_080532F4:
	ldr r0, [r3, #0x18]
	ldr r2, _0805331C @ =0x08395728
	cmp r0, r2
	beq _08053302
	str r2, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
_08053302:
	ldr r0, _08053320 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	movs r1, #7
	ands r1, r0
	cmp r1, #0
	bne _08053340
	adds r3, #0x20
	ldrb r0, [r3]
	cmp r0, #0
	bne _08053324
	movs r0, #0xc
	strb r0, [r3]
	b _08053340
	.align 2, 0
_0805331C: .4byte 0x08395728
_08053320: .4byte gFrameCounter8Bit
_08053324:
	strb r1, [r3]
	b _08053340
_08053328:
	adds r0, r5, #0
	orrs r0, r4
	strh r0, [r3]
	b _08053340
_08053330:
	ldr r0, [r3, #0x18]
	ldr r1, _08053348 @ =0x08395718
_08053334:
	cmp r0, r1
	beq _08053340
	str r1, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
_08053340:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08053348: .4byte 0x08395718

	thumb_func_start Box2PartDefault
Box2PartDefault: @ 0x0805334C
	push {r4, r5, r6, lr}
	ldr r4, _08053370 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _08053374 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r5, r0, r2
	ldrh r0, [r5]
	movs r6, #1
	adds r1, r6, #0
	ands r1, r0
	cmp r1, #0
	bne _08053378
	strh r1, [r4]
	b _080533F2
	.align 2, 0
_08053370: .4byte gCurrentSprite
_08053374: .4byte gSpriteData
_08053378:
	ldrh r2, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	adds r0, r1, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080533F2
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x47
	beq _080533CC
	cmp r0, #0x47
	bgt _0805339E
	cmp r0, #0x46
	beq _080533A8
	b _080533F2
_0805339E:
	cmp r0, #0x48
	beq _080533D4
	cmp r0, #0x49
	beq _080533EC
	b _080533F2
_080533A8:
	ldr r0, _080533C4 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080533F2
	adds r1, r4, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	bne _080533C8
	movs r0, #0xd
	strb r0, [r1]
	b _080533F2
	.align 2, 0
_080533C4: .4byte gFrameCounter8Bit
_080533C8:
	strb r3, [r1]
	b _080533F2
_080533CC:
	adds r0, r4, #0
	adds r0, #0x20
	strb r3, [r0]
	b _080533F2
_080533D4:
	ldr r0, _080533E8 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080533F2
	movs r0, #4
	eors r0, r2
	b _080533F0
	.align 2, 0
_080533E8: .4byte gFrameCounter8Bit
_080533EC:
	adds r0, r1, #0
	orrs r0, r2
_080533F0:
	strh r0, [r4]
_080533F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Box2MissileInit
Box2MissileInit: @ 0x080533F8
	push {r4, lr}
	ldr r0, _08053488 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0805348C @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r2, #0
	movs r1, #0x80
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	ldr r0, _08053490 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	mov r1, ip
	adds r1, #0x21
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08053494 @ =0x0000FFF8
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #8
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _08053498 @ =0x083957E8
	str r0, [r4, #0x18]
	strb r3, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldr r1, _0805349C @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	mov r1, ip
	adds r1, #0x2b
	movs r0, #0xc0
	strb r0, [r1]
	adds r0, #0x40
	strh r0, [r4, #0x12]
	adds r1, #3
	movs r0, #0x24
	strb r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #6]
	subs r1, #0xa
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2d
	strb r3, [r0]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080534A0 @ =0x0000026B
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053488: .4byte gCurrentSprite
_0805348C: .4byte 0x0000FFFB
_08053490: .4byte gIoRegisters
_08053494: .4byte 0x0000FFF8
_08053498: .4byte 0x083957E8
_0805349C: .4byte sSecondarySpriteStats
_080534A0: .4byte 0x0000026B

	thumb_func_start Box2MissileLaunching
Box2MissileLaunching: @ 0x080534A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, _08053524 @ =gCurrentSprite
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	bne _080534BC
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
_080534BC:
	adds r6, r5, #0
	adds r6, #0x2e
	ldrb r1, [r6]
	lsrs r1, r1, #1
	ldrh r0, [r5, #2]
	subs r0, r0, r1
	movs r2, #0
	mov r8, r2
	strh r0, [r5, #2]
	cmp r1, #2
	bhi _080534EC
	adds r7, r5, #0
	adds r7, #0x2b
	ldrb r0, [r7]
	ldr r2, _08053528 @ =gSamusData
	ldrh r1, [r2, #0x18]
	subs r1, #0x40
	ldrh r2, [r2, #0x16]
	ldrh r3, [r5, #2]
	ldrh r4, [r5, #4]
	str r4, [sp]
	bl SpriteUtilMakeSpriteRotateTowardsTarget
	strb r0, [r7]
_080534EC:
	ldrb r0, [r6]
	subs r0, #2
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08053518
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2f
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	movs r1, #1
	strb r1, [r0]
	mov r2, r8
	strb r2, [r6]
	adds r0, #1
	strb r1, [r0]
_08053518:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053524: .4byte gCurrentSprite
_08053528: .4byte gSamusData

	thumb_func_start Box2MissileMoving
Box2MissileMoving: @ 0x0805352C
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _0805354C @ =gCurrentSprite
	ldrh r0, [r1, #6]
	subs r0, #1
	strh r0, [r1, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08053544
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	bne _08053550
_08053544:
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _080535F8
	.align 2, 0
_0805354C: .4byte gCurrentSprite
_08053550:
	ldrb r1, [r1, #0x1e]
	movs r2, #8
	cmp r1, #3
	beq _08053566
	movs r2, #0x28
	cmp r1, #2
	beq _08053566
	movs r2, #0x68
	cmp r1, #1
	bne _08053566
	movs r2, #0x48
_08053566:
	ldr r4, _080535D0 @ =gSamusData
	ldrh r0, [r4, #0x18]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0x16]
	movs r2, #2
	str r2, [sp]
	movs r2, #0x18
	movs r3, #0x28
	bl SpriteUtilMoveTowardsTarget
	ldr r5, _080535D4 @ =gCurrentSprite
	adds r6, r5, #0
	adds r6, #0x2b
	ldrb r0, [r6]
	ldrh r1, [r4, #0x18]
	subs r1, #0x40
	ldrh r2, [r4, #0x16]
	ldrh r3, [r5, #2]
	ldrh r4, [r5, #4]
	str r4, [sp]
	bl SpriteUtilMakeSpriteRotateTowardsTarget
	strb r0, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080535D8 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080535B0
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
_080535B0:
	ldr r0, _080535DC @ =gCurrentAffectingClipdata
	ldrh r4, [r0, #2]
	cmp r4, #1
	bne _080535E0
	adds r6, r5, #0
	adds r6, #0x2d
	ldrb r0, [r6]
	cmp r0, #0
	bne _080535F8
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	movs r2, #0x39
	bl ParticleSet
	strb r4, [r6]
	b _080535F8
	.align 2, 0
_080535D0: .4byte gSamusData
_080535D4: .4byte gCurrentSprite
_080535D8: .4byte gPreviousCollisionCheck
_080535DC: .4byte gCurrentAffectingClipdata
_080535E0:
	adds r4, r5, #0
	adds r4, #0x2d
	ldrb r0, [r4]
	cmp r0, #0
	beq _080535F8
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	movs r2, #0x39
	bl ParticleSet
	movs r0, #0
	strb r0, [r4]
_080535F8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start Box2MissileExploding
Box2MissileExploding: @ 0x08053600
	push {lr}
	ldr r1, _08053620 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r1, #2]
	ldrh r1, [r1, #4]
	movs r2, #0x25
	bl ParticleSet
	movs r0, #0x9b
	lsls r0, r0, #2
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08053620: .4byte gCurrentSprite

	thumb_func_start Box2BrainTopInit
Box2BrainTopInit: @ 0x08053624
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, _080536B0 @ =gCurrentSprite
	ldrh r1, [r5]
	ldr r0, _080536B4 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	strh r0, [r5]
	ldr r0, _080536B8 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0x21
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	movs r2, #0x20
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _080536BC @ =0x0000FFE0
	strh r1, [r5, #0xa]
	movs r0, #0x40
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r2, [r5, #0x10]
	ldr r0, _080536C0 @ =0x08395808
	str r0, [r5, #0x18]
	strb r3, [r5, #0x1c]
	strh r4, [r5, #0x16]
	ldr r1, _080536C4 @ =sSecondarySpriteStats
	ldrb r0, [r5, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0x5a
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldrb r2, [r5, #0x1f]
	subs r0, #2
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x6f
	movs r1, #0
	bl SpriteSpawnSecondary
	adds r1, r5, #0
	adds r1, #0x2f
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080536B0: .4byte gCurrentSprite
_080536B4: .4byte 0x0000FFFB
_080536B8: .4byte gIoRegisters
_080536BC: .4byte 0x0000FFE0
_080536C0: .4byte 0x08395808
_080536C4: .4byte sSecondarySpriteStats

	thumb_func_start Box2BrainTopRising
Box2BrainTopRising: @ 0x080536C8
	push {lr}
	ldr r0, _080536E8 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	movs r2, #7
	ands r2, r0
	ldr r3, _080536EC @ =gCurrentSprite
	cmp r2, #0
	bne _0805370C
	adds r1, r3, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	bne _080536F0
	movs r0, #0xb
	strb r0, [r1]
	b _080536F2
	.align 2, 0
_080536E8: .4byte gFrameCounter8Bit
_080536EC: .4byte gCurrentSprite
_080536F0:
	strb r2, [r1]
_080536F2:
	ldr r2, _08053738 @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x20
	ldrb r1, [r1]
	adds r0, #0x20
	strb r1, [r0]
_0805370C:
	movs r0, #0x2e
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0805373C
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x3c
	mov r1, ip
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	b _08053742
	.align 2, 0
_08053738: .4byte gSpriteData
_0805373C:
	ldrh r0, [r3, #2]
	subs r0, #2
	strh r0, [r3, #2]
_08053742:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Box2BrainTopFloating
Box2BrainTopFloating: @ 0x08053748
	push {r4, r5, r6, lr}
	ldr r0, _08053768 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	movs r2, #7
	ands r2, r0
	ldr r3, _0805376C @ =gCurrentSprite
	cmp r2, #0
	bne _0805378C
	adds r1, r3, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	bne _08053770
	movs r0, #0xb
	strb r0, [r1]
	b _08053772
	.align 2, 0
_08053768: .4byte gFrameCounter8Bit
_0805376C: .4byte gCurrentSprite
_08053770:
	strb r2, [r1]
_08053772:
	ldr r2, _080537EC @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x20
	ldrb r1, [r1]
	adds r0, #0x20
	strb r1, [r0]
_0805378C:
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _080537F0 @ =0x08390578
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _080537F4 @ =0x00007FFF
	cmp r1, r0
	bne _080537AA
	ldrh r4, [r5]
	movs r2, #0
_080537AA:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
	movs r4, #0
	strh r0, [r3, #2]
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080537E6
	subs r1, #0xa
	movs r0, #0x45
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x20
	strb r4, [r0]
	ldr r2, _080537EC @ =gSpriteData
	adds r0, #0xf
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x20
	strb r4, [r0]
_080537E6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080537EC: .4byte gSpriteData
_080537F0: .4byte 0x08390578
_080537F4: .4byte 0x00007FFF

	thumb_func_start Box2BrainTopTransformingInit
Box2BrainTopTransformingInit: @ 0x080537F8
	push {r4, lr}
	ldr r3, _0805381C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x46
	strb r0, [r1]
	ldrh r2, [r3]
	movs r0, #0
	ldr r1, _08053820 @ =0x00008020
	movs r4, #0x25
	strb r0, [r4, r3]
	movs r0, #0x2c
	strh r0, [r3, #6]
	orrs r1, r2
	strh r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805381C: .4byte gCurrentSprite
_08053820: .4byte 0x00008020

	thumb_func_start Box2BrainTopTransforming
Box2BrainTopTransforming: @ 0x08053824
	push {r4, r5, lr}
	movs r5, #0x59
	ldr r2, _0805387C @ =gWrittenToMosaic_H
	ldr r1, _08053880 @ =sXParasiteMosaicValues
	ldr r4, _08053884 @ =gCurrentSprite
	ldrh r0, [r4, #6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	ldrh r0, [r4, #6]
	subs r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bhi _08053888
	ldrh r2, [r4, #6]
	movs r0, #0x59
	movs r1, #0
	bl SpriteLoadGfx
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _08053896
	adds r0, r4, #0
	adds r0, #0x24
	strb r5, [r0]
	strb r5, [r4, #0x1d]
	ldrh r0, [r4, #2]
	adds r0, #0x5c
	strh r0, [r4, #2]
	ldrh r0, [r4]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	b _08053896
	.align 2, 0
_0805387C: .4byte gWrittenToMosaic_H
_08053880: .4byte sXParasiteMosaicValues
_08053884: .4byte gCurrentSprite
_08053888:
	cmp r0, #0x14
	bne _08053896
	movs r0, #0x59
	movs r1, #0
	movs r2, #5
	bl SpriteLoadPal
_08053896:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start Box2BrainBottomInit
Box2BrainBottomInit: @ 0x0805389C
	push {r4, lr}
	ldr r0, _08053908 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0805390C @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	ldr r0, _08053910 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r2, #3
	adds r0, r2, #0
	ands r0, r1
	mov r1, ip
	adds r1, #0x21
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x22
	strb r2, [r0]
	adds r0, #5
	strb r3, [r0]
	adds r1, #7
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	ldr r1, _08053914 @ =0x0000FFFC
	mov r2, ip
	strh r1, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldr r0, _08053918 @ =0x083958D8
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053908: .4byte gCurrentSprite
_0805390C: .4byte 0x0000FFFB
_08053910: .4byte gIoRegisters
_08053914: .4byte 0x0000FFFC
_08053918: .4byte 0x083958D8

	thumb_func_start Box2BrainBottomIdle
Box2BrainBottomIdle: @ 0x0805391C
	push {r4, lr}
	ldr r2, _0805394C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r4, [r0]
	ldr r3, _08053950 @ =gSpriteData
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	strh r1, [r2, #2]
	ldrh r1, [r0, #4]
	strh r1, [r2, #4]
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08053954
	ldrh r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	b _0805395A
	.align 2, 0
_0805394C: .4byte gCurrentSprite
_08053950: .4byte gSpriteData
_08053954:
	ldrh r1, [r2]
	ldr r0, _08053978 @ =0x0000FFDF
	ands r0, r1
_0805395A:
	strh r0, [r2]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x59
	bne _08053970
	movs r0, #0
	strh r0, [r2]
_08053970:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053978: .4byte 0x0000FFDF

	thumb_func_start Box2
Box2: @ 0x0805397C
	push {lr}
	ldr r0, _08053994 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x4c
	bls _0805398A
	b _08053B90
_0805398A:
	lsls r0, r0, #2
	ldr r1, _08053998 @ =_0805399C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053994: .4byte gCurrentSprite
_08053998: .4byte _0805399C
_0805399C: @ jump table
	.4byte _08053AD0 @ case 0
	.4byte _08053AD6 @ case 1
	.4byte _08053ADA @ case 2
	.4byte _08053B90 @ case 3
	.4byte _08053B90 @ case 4
	.4byte _08053B90 @ case 5
	.4byte _08053B90 @ case 6
	.4byte _08053B12 @ case 7
	.4byte _08053B16 @ case 8
	.4byte _08053B90 @ case 9
	.4byte _08053B90 @ case 10
	.4byte _08053B90 @ case 11
	.4byte _08053B90 @ case 12
	.4byte _08053B90 @ case 13
	.4byte _08053B90 @ case 14
	.4byte _08053B90 @ case 15
	.4byte _08053B90 @ case 16
	.4byte _08053B90 @ case 17
	.4byte _08053B90 @ case 18
	.4byte _08053B90 @ case 19
	.4byte _08053B90 @ case 20
	.4byte _08053B90 @ case 21
	.4byte _08053B90 @ case 22
	.4byte _08053AE0 @ case 23
	.4byte _08053AE4 @ case 24
	.4byte _08053AEA @ case 25
	.4byte _08053AEE @ case 26
	.4byte _08053AF4 @ case 27
	.4byte _08053AF8 @ case 28
	.4byte _08053AFE @ case 29
	.4byte _08053B02 @ case 30
	.4byte _08053B08 @ case 31
	.4byte _08053B0C @ case 32
	.4byte _08053B90 @ case 33
	.4byte _08053B90 @ case 34
	.4byte _08053B90 @ case 35
	.4byte _08053B90 @ case 36
	.4byte _08053B90 @ case 37
	.4byte _08053B90 @ case 38
	.4byte _08053B4E @ case 39
	.4byte _08053B52 @ case 40
	.4byte _08053B58 @ case 41
	.4byte _08053B5C @ case 42
	.4byte _08053B90 @ case 43
	.4byte _08053B62 @ case 44
	.4byte _08053B90 @ case 45
	.4byte _08053B68 @ case 46
	.4byte _08053B90 @ case 47
	.4byte _08053B90 @ case 48
	.4byte _08053B90 @ case 49
	.4byte _08053B90 @ case 50
	.4byte _08053B90 @ case 51
	.4byte _08053B90 @ case 52
	.4byte _08053B90 @ case 53
	.4byte _08053B90 @ case 54
	.4byte _08053B1C @ case 55
	.4byte _08053B20 @ case 56
	.4byte _08053B30 @ case 57
	.4byte _08053B34 @ case 58
	.4byte _08053B3A @ case 59
	.4byte _08053B3E @ case 60
	.4byte _08053B44 @ case 61
	.4byte _08053B48 @ case 62
	.4byte _08053B90 @ case 63
	.4byte _08053B90 @ case 64
	.4byte _08053B90 @ case 65
	.4byte _08053B90 @ case 66
	.4byte _08053B6E @ case 67
	.4byte _08053B72 @ case 68
	.4byte _08053B78 @ case 69
	.4byte _08053B7C @ case 70
	.4byte _08053B82 @ case 71
	.4byte _08053B86 @ case 72
	.4byte _08053B8C @ case 73
	.4byte _08053B90 @ case 74
	.4byte _08053B26 @ case 75
	.4byte _08053B2A @ case 76
_08053AD0:
	bl Box2Init
	b _08053B90
_08053AD6:
	bl Box2IdleInit
_08053ADA:
	bl Box2Crawling
	b _08053B90
_08053AE0:
	bl Box2WaitingToRunInit
_08053AE4:
	bl Box2WaitingToRun
	b _08053B90
_08053AEA:
	bl Box2SlowRunningInit
_08053AEE:
	bl Box2SlowRunning
	b _08053B90
_08053AF4:
	bl Box2FastRunningInit
_08053AF8:
	bl Box2FastRunning
	b _08053B90
_08053AFE:
	bl Box2SkiddingInit
_08053B02:
	bl Box2Skidding
	b _08053B90
_08053B08:
	bl Box2StopSkiddingInit
_08053B0C:
	bl Box2StopSkidding
	b _08053B90
_08053B12:
	bl Box2FinishedCrawlingInit
_08053B16:
	bl Box2FinishCrawling
	b _08053B90
_08053B1C:
	bl Box2BonkingInit
_08053B20:
	bl Box2Bonking
	b _08053B90
_08053B26:
	bl Box2LandingFromBonkInit
_08053B2A:
	bl Box2LandingFromBonk
	b _08053B90
_08053B30:
	bl Box2LandingInit
_08053B34:
	bl Box2Landing
	b _08053B90
_08053B3A:
	bl Box2JumpWarningInit
_08053B3E:
	bl Box2JumpWarning
	b _08053B90
_08053B44:
	bl Box2JumpingInit
_08053B48:
	bl Box2Jumping
	b _08053B90
_08053B4E:
	bl Box2StoppingToFireMissilesInit
_08053B52:
	bl Box2StoppingToFireMissiles
	b _08053B90
_08053B58:
	bl Box2LoweringToFireMissilesInit
_08053B5C:
	bl Box2LoweringToFireMissiles
	b _08053B90
_08053B62:
	bl Box2FiringMissiles
	b _08053B90
_08053B68:
	bl Box2DoneFiringMissiles
	b _08053B90
_08053B6E:
	bl Box2DyingInit
_08053B72:
	bl Box2Dying
	b _08053B90
_08053B78:
	bl Box2ExplodingInit
_08053B7C:
	bl Box2Exploding
	b _08053B90
_08053B82:
	bl Box2BrainRisingInit
_08053B86:
	bl Box2BrainRising
	b _08053B90
_08053B8C:
	bl Box2BrainFloating
_08053B90:
	bl SpriteUtilUpdateSubSpriteData1Animation
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	pop {r0}
	bx r0

	thumb_func_start Box2Part
Box2Part: @ 0x08053B9C
	push {r4, lr}
	ldr r0, _08053BB4 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x24
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	bne _08053BB8
	bl Box2PartInit
	b _08053C80
	.align 2, 0
_08053BB4: .4byte gCurrentSprite
_08053BB8:
	ldrb r0, [r2, #0x1e]
	cmp r0, #2
	beq _08053BF8
	cmp r0, #2
	bgt _08053BC8
	cmp r0, #0
	beq _08053BD2
	b _08053C60
_08053BC8:
	cmp r0, #6
	beq _08053C20
	cmp r0, #8
	beq _08053C38
	b _08053C60
_08053BD2:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08053BF4 @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _08053BEA
	strb r3, [r4]
_08053BEA:
	bl Box2PartFrontLeftLeg
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _08053C80
	.align 2, 0
_08053BF4: .4byte gSubSpriteData1
_08053BF8:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08053C1C @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _08053C10
	strb r3, [r4]
_08053C10:
	bl Box2PartFrontRightLeg
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _08053C80
	.align 2, 0
_08053C1C: .4byte gSubSpriteData1
_08053C20:
	ldr r0, _08053C34 @ =gSubSpriteData1
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r1, [r1]
	strb r1, [r0, #0xe]
	bl Box2PartTopShell
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _08053C80
	.align 2, 0
_08053C34: .4byte gSubSpriteData1
_08053C38:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08053C5C @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _08053C50
	strb r3, [r4]
_08053C50:
	bl Box2PartBottomShell
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _08053C80
	.align 2, 0
_08053C5C: .4byte gSubSpriteData1
_08053C60:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08053C88 @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _08053C78
	strb r3, [r4]
_08053C78:
	bl Box2PartDefault
	bl Box2SyncSubSprites
_08053C80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053C88: .4byte gSubSpriteData1

	thumb_func_start Box2Missile
Box2Missile: @ 0x08053C8C
	push {lr}
	ldr r0, _08053CA4 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08053CB8
	cmp r0, #2
	bgt _08053CA8
	cmp r0, #0
	beq _08053CB2
	b _08053CC8
	.align 2, 0
_08053CA4: .4byte gCurrentSprite
_08053CA8:
	cmp r0, #0x18
	beq _08053CBE
	cmp r0, #0x37
	beq _08053CC4
	b _08053CC8
_08053CB2:
	bl Box2MissileInit
	b _08053CC8
_08053CB8:
	bl Box2MissileLaunching
	b _08053CC8
_08053CBE:
	bl Box2MissileMoving
	b _08053CC8
_08053CC4:
	bl Box2MissileExploding
_08053CC8:
	pop {r0}
	bx r0

	thumb_func_start Box2BrainTop
Box2BrainTop: @ 0x08053CCC
	push {lr}
	ldr r0, _08053CE8 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _08053D02
	cmp r0, #0x18
	bgt _08053CEC
	cmp r0, #0
	beq _08053CF6
	cmp r0, #2
	beq _08053CFC
	b _08053D10
	.align 2, 0
_08053CE8: .4byte gCurrentSprite
_08053CEC:
	cmp r0, #0x45
	beq _08053D08
	cmp r0, #0x46
	beq _08053D0C
	b _08053D10
_08053CF6:
	bl Box2BrainTopInit
	b _08053D10
_08053CFC:
	bl Box2BrainTopRising
	b _08053D10
_08053D02:
	bl Box2BrainTopFloating
	b _08053D10
_08053D08:
	bl Box2BrainTopTransformingInit
_08053D0C:
	bl Box2BrainTopTransforming
_08053D10:
	pop {r0}
	bx r0

	thumb_func_start Box2BrainBottom
Box2BrainBottom: @ 0x08053D14
	push {lr}
	ldr r0, _08053D34 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _08053D2C
	bl Box2BrainBottomInit
_08053D2C:
	bl Box2BrainBottomIdle
	pop {r0}
	bx r0
	.align 2, 0
_08053D34: .4byte gCurrentSprite

	thumb_func_start OmagaMetroidSyncSubSPrites
OmagaMetroidSyncSubSPrites: @ 0x08053D38
	push {r4, lr}
	ldr r4, _08053D94 @ =gSubSpriteData1
	ldrh r0, [r4, #4]
	ldr r1, [r4]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r2, _08053D98 @ =gCurrentSprite
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, _08053D9C @ =0x0879B634
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r2, #0x18]
	ldr r0, [r0]
	cmp r1, r0
	beq _08053D6A
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
_08053D6A:
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	ldrh r4, [r4, #0xa]
	adds r0, r0, r4
	strh r0, [r2, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053D94: .4byte gSubSpriteData1
_08053D98: .4byte gCurrentSprite
_08053D9C: .4byte 0x0879B634

	thumb_func_start OmegaMetroidPartSetDrawOrder
OmegaMetroidPartSetDrawOrder: @ 0x08053DA0
	push {lr}
	ldr r0, _08053DB8 @ =gCurrentSprite
	ldrb r2, [r0, #0x1e]
	adds r3, r0, #0
	cmp r2, #7
	bhi _08053DF8
	lsls r0, r2, #2
	ldr r1, _08053DBC @ =_08053DC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08053DB8: .4byte gCurrentSprite
_08053DBC: .4byte _08053DC0
_08053DC0: @ jump table
	.4byte _08053DE0 @ case 0
	.4byte _08053DE0 @ case 1
	.4byte _08053DE0 @ case 2
	.4byte _08053DF8 @ case 3
	.4byte _08053DF0 @ case 4
	.4byte _08053DE8 @ case 5
	.4byte _08053DF0 @ case 6
	.4byte _08053DF0 @ case 7
_08053DE0:
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #3
	b _08053DF6
_08053DE8:
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #5
	b _08053DF6
_08053DF0:
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #0xc
_08053DF6:
	strb r0, [r1]
_08053DF8:
	pop {r0}
	bx r0

	thumb_func_start OmegaMetroidPartSetDrawOrder_2
OmegaMetroidPartSetDrawOrder_2: @ 0x08053DFC
	push {lr}
	ldr r1, _08053E10 @ =gCurrentSprite
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	blt _08053E22
	cmp r0, #2
	bgt _08053E14
	adds r1, #0x22
	movs r0, #0xb
	b _08053E20
	.align 2, 0
_08053E10: .4byte gCurrentSprite
_08053E14:
	cmp r0, #7
	bgt _08053E22
	cmp r0, #4
	blt _08053E22
	adds r1, #0x22
	movs r0, #0xd
_08053E20:
	strb r0, [r1]
_08053E22:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidUpdatePalette
OmegaMetroidUpdatePalette: @ 0x08053E28
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r0, _08053E4C @ =gCurrentSprite
	ldrh r5, [r0, #0x14]
	ldr r2, _08053E50 @ =sPrimarySpriteStats
	ldrb r1, [r0, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r4, _08053E54 @ =gBossWork1
	ldrb r1, [r4]
	cmp r1, #0
	beq _08053E58
	cmp r1, #1
	beq _08053E70
	b _08053E86
	.align 2, 0
_08053E4C: .4byte gCurrentSprite
_08053E50: .4byte sPrimarySpriteStats
_08053E54: .4byte gBossWork1
_08053E58:
	lsls r0, r0, #1
	movs r1, #3
	bl __divsi3
	cmp r5, r0
	bgt _08053E86
	ldr r6, _08053E6C @ =0x08399168
	movs r0, #1
	strb r0, [r4]
	b _08053E8A
	.align 2, 0
_08053E6C: .4byte 0x08399168
_08053E70:
	movs r1, #3
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r5, r0
	bhi _08053E86
	ldr r6, _08053EB4 @ =0x08399188
	movs r0, #2
	strb r0, [r4]
	movs r7, #1
_08053E86:
	cmp r7, #0
	beq _08053EAC
_08053E8A:
	ldr r0, _08053EB8 @ =0x040000D4
	str r6, [r0]
	ldr r1, _08053EBC @ =0x05000340
	str r1, [r0, #4]
	ldr r2, _08053EC0 @ =0x8000000B
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r6, [r0]
	ldr r1, _08053EC4 @ =0x050003A0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r6, [r0]
	ldr r1, _08053EC8 @ =0x050003C0
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
_08053EAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053EB4: .4byte 0x08399188
_08053EB8: .4byte 0x040000D4
_08053EBC: .4byte 0x05000340
_08053EC0: .4byte 0x8000000B
_08053EC4: .4byte 0x050003A0
_08053EC8: .4byte 0x050003C0

	thumb_func_start OmegaMetroidSaXIceBeamCollision
OmegaMetroidSaXIceBeamCollision: @ 0x08053ECC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r2, _08053F80 @ =gCurrentSprite
	ldrh r1, [r2, #2]
	ldrh r3, [r2, #4]
	ldrh r0, [r2, #0xa]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldrh r0, [r2, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	ldrh r0, [r2, #0xe]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldrh r0, [r2, #0x10]
	adds r3, r3, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	movs r0, #0
	mov r8, r0
_08053F0A:
	ldr r1, _08053F84 @ =gSpriteData
	mov r2, r8
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrh r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08053F88
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08053F88
	ldrb r7, [r4, #0x1d]
	cmp r7, #0
	bne _08053F88
	ldrh r5, [r4, #2]
	ldrh r6, [r4, #4]
	ldrh r3, [r4, #0xa]
	adds r3, r5, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldrh r2, [r4, #0xc]
	adds r2, r5, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r1, [r4, #0xe]
	adds r1, r6, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r4, #0x10]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r3, [sp]
	str r2, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	mov r2, sl
	mov r3, sb
	bl SpriteUtilCheckObjectsTouching
	cmp r0, #0
	beq _08053F88
	strh r7, [r4]
	movs r0, #2
	movs r1, #0x11
	adds r2, r5, #0
	adds r3, r6, #0
	bl ProjectileRandomSpriteDebris
	b _08053F96
	.align 2, 0
_08053F80: .4byte gCurrentSprite
_08053F84: .4byte gSpriteData
_08053F88:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x17
	bls _08053F0A
_08053F96:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidUpdateHeartPalette
OmegaMetroidUpdateHeartPalette: @ 0x08053FA8
	push {lr}
	ldr r1, _08053FCC @ =gCurrentSprite
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	beq _08053FF0
	adds r2, r1, #0
	adds r2, #0x2b
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x38
	bne _08053FD0
	movs r0, #1
	strb r0, [r2]
	b _08053FDE
	.align 2, 0
_08053FCC: .4byte gCurrentSprite
_08053FD0:
	cmp r0, #0xe
	bne _08053FDA
	adds r1, #0x20
	movs r0, #3
	b _08053FEE
_08053FDA:
	cmp r0, #0x1c
	bne _08053FE6
_08053FDE:
	adds r0, r1, #0
	adds r0, #0x20
	strb r3, [r0]
	b _08053FF0
_08053FE6:
	cmp r0, #0x2a
	bne _08053FF0
	adds r1, #0x20
	movs r0, #4
_08053FEE:
	strb r0, [r1]
_08053FF0:
	pop {r0}
	bx r0

	thumb_func_start OmegaMetroidUpdateHealthThreshold
OmegaMetroidUpdateHealthThreshold: @ 0x08053FF4
	push {r4, lr}
	bl EventCheckAfter_IceBeamRecovered
	cmp r0, #0
	beq _0805409C
	ldr r0, _08054014 @ =gCurrentSprite
	adds r0, #0x2c
	ldrb r0, [r0]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x10
	bne _0805401C
	ldr r0, _08054018 @ =0x00000222
	bl SoundPlayNotAlreadyPlaying
	b _08054026
	.align 2, 0
_08054014: .4byte gCurrentSprite
_08054018: .4byte 0x00000222
_0805401C:
	cmp r1, #0xe
	bne _08054026
	ldr r0, _0805405C @ =0x0000021B
	bl SoundPlayNotAlreadyPlaying
_08054026:
	ldr r4, _08054060 @ =gCurrentSprite
	ldrh r2, [r4, #0x14]
	cmp r2, #0
	bne _0805406C
	ldr r0, _08054064 @ =gSubSpriteData1
	ldrh r0, [r0, #0xc]
	cmp r0, #0
	beq _0805406C
	adds r0, r4, #0
	adds r0, #0x20
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x25
	strb r0, [r1]
	ldr r0, _08054068 @ =gBossWork5
	strh r2, [r0]
	movs r0, #0x6c
	bl EventCheckAdvance
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #0x3a
	bl ParticleSet
	b _08054094
	.align 2, 0
_0805405C: .4byte 0x0000021B
_08054060: .4byte gCurrentSprite
_08054064: .4byte gSubSpriteData1
_08054068: .4byte gBossWork5
_0805406C:
	ldr r3, _080540A4 @ =gBossWork5
	ldr r0, _080540A8 @ =gSubSpriteData1
	ldr r2, _080540AC @ =gCurrentSprite
	ldrh r0, [r0, #0xc]
	ldrh r1, [r2, #0x14]
	subs r0, r0, r1
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #0x11
	cmp r0, r1
	bls _08054094
	adds r0, r2, #0
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x25
	strb r1, [r0]
	strh r2, [r3]
_08054094:
	ldr r0, _080540A8 @ =gSubSpriteData1
	ldr r1, _080540AC @ =gCurrentSprite
	ldrh r1, [r1, #0x14]
	strh r1, [r0, #0xc]
_0805409C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080540A4: .4byte gBossWork5
_080540A8: .4byte gSubSpriteData1
_080540AC: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidCheckSamusOnLowHealth
OmegaMetroidCheckSamusOnLowHealth: @ 0x080540B0
	push {lr}
	ldr r0, _080540C8 @ =gSamusData
	ldrb r0, [r0, #1]
	cmp r0, #0x3f
	bne _080540D0
	ldr r0, _080540CC @ =gEquipment
	ldrh r0, [r0]
	cmp r0, #0x62
	bhi _080540D0
	movs r0, #1
	b _080540D2
	.align 2, 0
_080540C8: .4byte gSamusData
_080540CC: .4byte gEquipment
_080540D0:
	movs r0, #0
_080540D2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start OmegaMetroidBodyBlinking
OmegaMetroidBodyBlinking: @ 0x080540D8
	push {lr}
	ldr r2, _0805411C @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08054110
	movs r0, #4
	ands r1, r0
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805410A
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r0, [r0]
	ldrb r1, [r2, #0x1f]
	adds r0, r0, r1
	movs r1, #0xd
	subs r1, r1, r0
_0805410A:
	adds r0, r2, #0
	adds r0, #0x20
	strb r1, [r0]
_08054110:
	adds r1, r2, #0
	adds r1, #0x2b
	movs r0, #0
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0805411C: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidFullBodyBlinking
OmegaMetroidFullBodyBlinking: @ 0x08054120
	push {lr}
	ldr r2, _08054164 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08054158
	movs r0, #4
	ands r1, r0
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08054152
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r0, [r0]
	ldrb r1, [r2, #0x1f]
	adds r0, r0, r1
	movs r1, #0xd
	subs r1, r1, r0
_08054152:
	adds r0, r2, #0
	adds r0, #0x20
	strb r1, [r0]
_08054158:
	adds r1, r2, #0
	adds r1, #0x2b
	movs r0, #0
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08054164: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidCheckSamusInFrontRange
OmegaMetroidCheckSamusInFrontRange: @ 0x08054168
	push {lr}
	movs r0, #0xe0
	lsls r0, r0, #1
	movs r1, #0xbe
	lsls r1, r1, #1
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	beq _08054194
	ldr r0, _0805418C @ =gSubSpriteData1
	ldr r1, _08054190 @ =gSamusData
	ldrh r0, [r0, #0xa]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _08054194
	movs r0, #1
	b _08054196
	.align 2, 0
_0805418C: .4byte gSubSpriteData1
_08054190: .4byte gSamusData
_08054194:
	movs r0, #0
_08054196:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start OmegaMEtroidCheckBehindRightTrigger
OmegaMEtroidCheckBehindRightTrigger: @ 0x0805419C
	push {lr}
	ldr r0, _080541B8 @ =gSubSpriteData1
	ldrh r1, [r0, #0xa]
	lsrs r1, r1, #2
	ldr r0, _080541BC @ =gBg1XPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0xcc
	bhi _080541C0
	movs r0, #0
	b _080541C2
	.align 2, 0
_080541B8: .4byte gSubSpriteData1
_080541BC: .4byte gBg1XPosition
_080541C0:
	movs r0, #1
_080541C2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start OmegaMetroidCheckInFrontOfMiddleTrigger
OmegaMetroidCheckInFrontOfMiddleTrigger: @ 0x080541C8
	push {lr}
	ldr r0, _080541E4 @ =gSubSpriteData1
	ldrh r1, [r0, #0xa]
	lsrs r1, r1, #2
	ldr r0, _080541E8 @ =gBg1XPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x78
	bls _080541EC
	movs r0, #0
	b _080541EE
	.align 2, 0
_080541E4: .4byte gSubSpriteData1
_080541E8: .4byte gBg1XPosition
_080541EC:
	movs r0, #1
_080541EE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start OmegaMetroidCheckInFrontOfLeftTrigger
OmegaMetroidCheckInFrontOfLeftTrigger: @ 0x080541F4
	push {lr}
	ldr r0, _08054210 @ =gSubSpriteData1
	ldrh r1, [r0, #0xa]
	lsrs r1, r1, #2
	ldr r0, _08054214 @ =gBg1XPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x50
	bls _08054218
	movs r0, #0
	b _0805421A
	.align 2, 0
_08054210: .4byte gSubSpriteData1
_08054214: .4byte gBg1XPosition
_08054218:
	movs r0, #1
_0805421A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start OmegaMetroidXMovement
OmegaMetroidXMovement: @ 0x08054220
	push {r4, r5, lr}
	ldr r1, _0805424C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r4, [r0]
	adds r5, r4, #0
	ldrh r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08054254
	bl OmegaMEtroidCheckBehindRightTrigger
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08054268
	ldr r1, _08054250 @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	adds r0, r4, r0
	b _08054266
	.align 2, 0
_0805424C: .4byte gCurrentSprite
_08054250: .4byte gSubSpriteData1
_08054254:
	bl OmegaMetroidCheckInFrontOfLeftTrigger
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08054268
	ldr r1, _08054270 @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	subs r0, r0, r5
_08054266:
	strh r0, [r1, #0xa]
_08054268:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08054270: .4byte gSubSpriteData1

	thumb_func_start OmegaMetroidBackwardsMovement
OmegaMetroidBackwardsMovement: @ 0x08054274
	push {lr}
	ldr r1, _0805428C @ =gSubSpriteData1
	ldrh r0, [r1, #4]
	subs r0, #1
	adds r2, r1, #0
	cmp r0, #7
	bhi _080542EC
	lsls r0, r0, #2
	ldr r1, _08054290 @ =_08054294
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805428C: .4byte gSubSpriteData1
_08054290: .4byte _08054294
_08054294: @ jump table
	.4byte _080542B4 @ case 0
	.4byte _080542B8 @ case 1
	.4byte _080542BC @ case 2
	.4byte _080542EC @ case 3
	.4byte _080542B4 @ case 4
	.4byte _080542B8 @ case 5
	.4byte _080542D0 @ case 6
	.4byte _080542D8 @ case 7
_080542B4:
	movs r1, #2
	b _080542EE
_080542B8:
	movs r1, #3
	b _080542EE
_080542BC:
	ldrb r0, [r2, #6]
	cmp r0, #1
	bne _080542D0
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _080542D4 @ =0x0000021D
	bl SoundPlay
_080542D0:
	movs r1, #4
	b _080542EE
	.align 2, 0
_080542D4: .4byte 0x0000021D
_080542D8:
	ldrb r0, [r2, #6]
	cmp r0, #1
	bne _080542EC
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _08054300 @ =0x0000021D
	bl SoundPlay
_080542EC:
	movs r1, #0
_080542EE:
	ldr r0, _08054304 @ =gCurrentSprite
	adds r0, #0x30
	strb r1, [r0]
	bl OmegaMetroidXMovement
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_08054300: .4byte 0x0000021D
_08054304: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidForwardMovement
OmegaMetroidForwardMovement: @ 0x08054308
	push {lr}
	ldr r0, _08054320 @ =gSubSpriteData1
	ldrh r1, [r0, #4]
	adds r2, r0, #0
	cmp r1, #7
	bhi _08054380
	lsls r0, r1, #2
	ldr r1, _08054324 @ =_08054328
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08054320: .4byte gSubSpriteData1
_08054324: .4byte _08054328
_08054328: @ jump table
	.4byte _0805435C @ case 0
	.4byte _08054348 @ case 1
	.4byte _08054380 @ case 2
	.4byte _08054380 @ case 3
	.4byte _0805435C @ case 4
	.4byte _08054364 @ case 5
	.4byte _08054368 @ case 6
	.4byte _0805436C @ case 7
_08054348:
	ldrb r0, [r2, #6]
	cmp r0, #1
	bne _0805435C
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _08054360 @ =0x0000021D
	bl SoundPlay
_0805435C:
	movs r2, #2
	b _08054382
	.align 2, 0
_08054360: .4byte 0x0000021D
_08054364:
	movs r2, #3
	b _08054382
_08054368:
	movs r2, #4
	b _08054382
_0805436C:
	ldrb r0, [r2, #6]
	cmp r0, #1
	bne _08054380
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _080543B8 @ =0x0000021D
	bl SoundPlay
_08054380:
	movs r2, #0
_08054382:
	ldr r0, _080543BC @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x24
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #0x24
	beq _0805439A
	cmp r2, #0
	beq _0805439A
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0805439A:
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	bl OmegaMetroidXMovement
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080543B4
	bl OmegaMetroidCheckSamusInFrontRange
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080543B4:
	pop {r1}
	bx r1
	.align 2, 0
_080543B8: .4byte 0x0000021D
_080543BC: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidSlowMovement
OmegaMetroidSlowMovement: @ 0x080543C0
	push {lr}
	ldr r0, _080543D4 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x24
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0x24
	beq _080543D8
	movs r1, #0
	b _080543E2
	.align 2, 0
_080543D4: .4byte gCurrentSprite
_080543D8:
	ldr r0, _08054400 @ =gSubSpriteData1
	ldrh r1, [r0, #4]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
_080543E2:
	adds r0, r2, #0
	adds r0, #0x30
	strb r1, [r0]
	bl OmegaMetroidXMovement
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080543FC
	bl OmegaMetroidCheckSamusInFrontRange
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080543FC:
	pop {r1}
	bx r1
	.align 2, 0
_08054400: .4byte gSubSpriteData1

	thumb_func_start OmegaMetroidStandingMovement
OmegaMetroidStandingMovement: @ 0x08054404
	push {r4, lr}
	ldr r0, _08054420 @ =gCurrentSprite
	adds r0, #0x30
	movs r1, #1
	strb r1, [r0]
	movs r4, #0
	bl OmegaMetroidCheckSamusInFrontRange
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054424
	movs r4, #2
	b _08054430
	.align 2, 0
_08054420: .4byte gCurrentSprite
_08054424:
	bl OmegaMetroidXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054430
	movs r4, #1
_08054430:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start OmegaMetroidInit
OmegaMetroidInit: @ 0x08054438
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r1, _080545E0 @ =gBossWork1
	movs r0, #0
	strb r0, [r1]
	ldr r7, _080545E4 @ =gCurrentSprite
	ldrh r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r3, r1, #0
	movs r6, #0
	movs r5, #0
	orrs r3, r0
	strh r3, [r7]
	adds r2, r7, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r7, #2]
	mov r8, r0
	ldrh r1, [r7, #4]
	mov sb, r1
	strh r0, [r7, #6]
	strh r1, [r7, #8]
	ldr r1, _080545E8 @ =gAbilityRestingYPosition
	ldr r0, _080545EC @ =0xFFFFFE80
	add r0, r8
	strh r0, [r1]
	ldr r1, _080545F0 @ =gAbilityRestingXPosition
	ldr r0, _080545F4 @ =0xFFFFFDC0
	add r0, sb
	strh r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	strh r1, [r7, #4]
	ldr r4, _080545F8 @ =gSubSpriteData1
	ldrh r0, [r7, #2]
	strh r0, [r4, #8]
	strh r1, [r4, #0xa]
	adds r0, r7, #0
	adds r0, #0x27
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _080545FC @ =0x0000FF90
	strh r0, [r7, #0xa]
	movs r1, #0x40
	strh r1, [r7, #0xc]
	adds r0, #0x10
	strh r0, [r7, #0xe]
	strh r1, [r7, #0x10]
	adds r1, r7, #0
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	movs r0, #3
	strb r0, [r7, #0x1e]
	ldr r2, _08054600 @ =sPrimarySpriteStats
	ldrb r1, [r7, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x14]
	strh r0, [r4, #0xc]
	ldr r0, _08054604 @ =gBossWork5
	strh r5, [r0]
	ldr r0, _08054608 @ =0x083966A0
	str r0, [r4]
	strb r6, [r4, #6]
	strh r5, [r4, #4]
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	ldr r0, _0805460C @ =0x0000FDFF
	ands r3, r0
	strh r3, [r7]
	subs r1, #1
	movs r0, #0x37
	strb r0, [r1]
	adds r1, #0xd
	movs r0, #1
	strb r0, [r1]
	subs r1, #3
	movs r0, #0x1e
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	strb r6, [r0]
	subs r0, #2
	strb r6, [r0]
	ldrb r2, [r7, #0x1f]
	adds r6, r7, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #1
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #2
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #4
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #5
	bl SpriteSpawnSecondary
	adds r1, r7, #0
	adds r1, #0x36
	strb r0, [r1]
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #6
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x70
	movs r1, #7
	bl SpriteSpawnSecondary
	ldrb r3, [r6]
	movs r0, #0x10
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0x4c
	movs r1, #0
	movs r2, #0
	bl SpriteSpawnNewXParasite
	adds r1, r7, #0
	adds r1, #0x2f
	strb r0, [r1]
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080545E0: .4byte gBossWork1
_080545E4: .4byte gCurrentSprite
_080545E8: .4byte gAbilityRestingYPosition
_080545EC: .4byte 0xFFFFFE80
_080545F0: .4byte gAbilityRestingXPosition
_080545F4: .4byte 0xFFFFFDC0
_080545F8: .4byte gSubSpriteData1
_080545FC: .4byte 0x0000FF90
_08054600: .4byte sPrimarySpriteStats
_08054604: .4byte gBossWork5
_08054608: .4byte 0x083966A0
_0805460C: .4byte 0x0000FDFF

	thumb_func_start OmegaMetroidWaitingToAppear
OmegaMetroidWaitingToAppear: @ 0x08054610
	push {lr}
	ldr r2, _08054648 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _08054642
	adds r1, #8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08054642
	subs r1, #0xa
	movs r0, #0x38
	strb r0, [r1]
	ldrh r1, [r2]
	ldr r0, _0805464C @ =0x00007FFF
	ands r0, r1
	strh r0, [r2]
_08054642:
	pop {r0}
	bx r0
	.align 2, 0
_08054648: .4byte gCurrentSprite
_0805464C: .4byte 0x00007FFF

	thumb_func_start OmegaMetroidFirstJump
OmegaMetroidFirstJump: @ 0x08054650
	push {r4, r5, r6, r7, lr}
	ldr r1, _08054688 @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	subs r0, #0x10
	strh r0, [r1, #0xa]
	ldr r3, _0805468C @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r4, [r0]
	ldr r7, _08054690 @ =0x08395900
	lsls r0, r4, #1
	adds r0, r0, r7
	ldrh r6, [r0]
	movs r5, #0
	ldrsh r2, [r0, r5]
	ldr r0, _08054694 @ =0x00007FFF
	adds r5, r1, #0
	cmp r2, r0
	bne _08054698
	subs r1, r4, #1
	lsls r1, r1, #1
	adds r1, r1, r7
	ldrh r0, [r5, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _080546A2
	.align 2, 0
_08054688: .4byte gSubSpriteData1
_0805468C: .4byte gCurrentSprite
_08054690: .4byte 0x08395900
_08054694: .4byte 0x00007FFF
_08054698:
	adds r0, r4, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r5, #8]
	adds r0, r0, r6
_080546A2:
	strh r0, [r5, #8]
	adds r1, r3, #0
	ldrh r4, [r1, #6]
	ldrh r0, [r5, #8]
	cmp r0, r4
	bls _080546DC
	movs r2, #0
	movs r3, #0
	strh r4, [r5, #8]
	adds r1, #0x24
	movs r0, #0x3a
	strb r0, [r1]
	ldr r0, _080546D4 @ =0x083966B8
	str r0, [r5]
	strb r2, [r5, #6]
	strh r3, [r5, #4]
	movs r0, #0x3c
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _080546D8 @ =0x0000021F
	bl SoundPlay
	b _0805470E
	.align 2, 0
_080546D4: .4byte 0x083966B8
_080546D8: .4byte 0x0000021F
_080546DC:
	ldrh r1, [r5, #8]
	ldrh r0, [r3, #6]
	subs r0, #0x78
	cmp r1, r0
	ble _0805470E
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x10
	bls _0805470E
	ldr r2, _08054714 @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r3, r0, #0
	adds r3, #0x24
	ldrb r0, [r3]
	cmp r0, #8
	bne _0805470E
	movs r0, #0x17
	strb r0, [r3]
_0805470E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054714: .4byte gSpriteData

	thumb_func_start OmegaMetroidLandingFromFirstJump
OmegaMetroidLandingFromFirstJump: @ 0x08054718
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054736
	ldr r1, _0805473C @ =gSubSpriteData1
	ldr r0, _08054740 @ =0x08396858
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08054744 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x3c
	strb r1, [r0]
_08054736:
	pop {r0}
	bx r0
	.align 2, 0
_0805473C: .4byte gSubSpriteData1
_08054740: .4byte 0x08396858
_08054744: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidLandedAfterFirstJump
OmegaMetroidLandedAfterFirstJump: @ 0x08054748
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054774
	ldr r1, _08054778 @ =gSubSpriteData1
	ldr r0, _0805477C @ =0x08396870
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r1, _08054780 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x3e
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x64
	strb r0, [r1]
	ldr r0, _08054784 @ =0x00000219
	bl SoundPlay
_08054774:
	pop {r0}
	bx r0
	.align 2, 0
_08054778: .4byte gSubSpriteData1
_0805477C: .4byte 0x08396870
_08054780: .4byte gCurrentSprite
_08054784: .4byte 0x00000219

	thumb_func_start OmegaMetroidScreamingAfterFirstJump
OmegaMetroidScreamingAfterFirstJump: @ 0x08054788
	push {lr}
	ldr r3, _080547B4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080547B0
	ldr r0, _080547B8 @ =gSubSpriteData1
	ldr r1, _080547BC @ =0x08396898
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
_080547B0:
	pop {r0}
	bx r0
	.align 2, 0
_080547B4: .4byte gCurrentSprite
_080547B8: .4byte gSubSpriteData1
_080547BC: .4byte 0x08396898

	thumb_func_start OmegaMetroidFinishedScreamingAfterFirstJump
OmegaMetroidFinishedScreamingAfterFirstJump: @ 0x080547C0
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080547FC
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldr r3, _080547EC @ =gCurrentSprite
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080547F0
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x2b
	strb r0, [r1]
	b _080547FC
	.align 2, 0
_080547EC: .4byte gCurrentSprite
_080547F0:
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0x1f
	strb r1, [r0]
	adds r0, #9
	strb r2, [r0]
_080547FC:
	pop {r0}
	bx r0

	thumb_func_start OmegaMetroidJumpWarningInit
OmegaMetroidJumpWarningInit: @ 0x08054800
	push {lr}
	ldr r1, _08054820 @ =gSubSpriteData1
	ldr r0, _08054824 @ =0x08396688
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08054828 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x18
	strb r1, [r0]
	ldr r0, _0805482C @ =0x0000021E
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08054820: .4byte gSubSpriteData1
_08054824: .4byte 0x08396688
_08054828: .4byte gCurrentSprite
_0805482C: .4byte 0x0000021E

	thumb_func_start OmegaMetroidJumpWarning
OmegaMetroidJumpWarning: @ 0x08054830
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054856
	ldr r1, _0805485C @ =gSubSpriteData1
	ldr r0, _08054860 @ =0x083966A0
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r0, _08054864 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x31
	strb r2, [r1]
	adds r0, #0x24
	movs r1, #0x1a
	strb r1, [r0]
_08054856:
	pop {r0}
	bx r0
	.align 2, 0
_0805485C: .4byte gSubSpriteData1
_08054860: .4byte 0x083966A0
_08054864: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidJumping
OmegaMetroidJumping: @ 0x08054868
	push {r4, r5, r6, lr}
	ldr r5, _08054894 @ =gCurrentSprite
	adds r3, r5, #0
	adds r3, #0x31
	ldrb r2, [r3]
	ldr r1, _08054898 @ =0x08395948
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0805489C @ =0x00007FFF
	cmp r1, r0
	bne _080548A0
	adds r0, r5, #0
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x1c
	strb r1, [r0]
	strb r2, [r3]
	b _080548B0
	.align 2, 0
_08054894: .4byte gCurrentSprite
_08054898: .4byte 0x08395948
_0805489C: .4byte 0x00007FFF
_080548A0:
	adds r0, r2, #1
	strb r0, [r3]
	ldr r1, _080548B8 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	adds r0, r0, r4
	strh r0, [r1, #8]
	bl OmegaMetroidXMovement
_080548B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080548B8: .4byte gSubSpriteData1

	thumb_func_start OmegaMEtroidFalling
OmegaMEtroidFalling: @ 0x080548BC
	push {r4, r5, r6, lr}
	ldr r0, _080548EC @ =gCurrentSprite
	adds r5, r0, #0
	adds r5, #0x31
	ldrb r2, [r5]
	ldr r3, _080548F0 @ =0x08395978
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _080548F4 @ =0x00007FFF
	cmp r1, r0
	bne _080548FC
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldr r2, _080548F8 @ =gSubSpriteData1
	ldrh r1, [r2, #8]
	ldrh r0, [r0]
	adds r1, r1, r0
	strh r1, [r2, #8]
	adds r4, r2, #0
	b _0805490A
	.align 2, 0
_080548EC: .4byte gCurrentSprite
_080548F0: .4byte 0x08395978
_080548F4: .4byte 0x00007FFF
_080548F8: .4byte gSubSpriteData1
_080548FC:
	adds r0, r2, #1
	strb r0, [r5]
	ldr r1, _08054944 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	adds r0, r0, r4
	strh r0, [r1, #8]
	adds r4, r1, #0
_0805490A:
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r0, _08054948 @ =gPreviousVerticalCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08054938
	strh r2, [r4, #8]
	ldr r0, _0805494C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x1d
	strb r1, [r0]
	movs r0, #0x3c
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _08054950 @ =0x0000021F
	bl SoundPlay
_08054938:
	bl OmegaMetroidXMovement
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08054944: .4byte gSubSpriteData1
_08054948: .4byte gPreviousVerticalCollisionCheck
_0805494C: .4byte gCurrentSprite
_08054950: .4byte 0x0000021F

	thumb_func_start OmegaMetroidLandingInit
OmegaMetroidLandingInit: @ 0x08054954
	ldr r1, _0805496C @ =gSubSpriteData1
	ldr r0, _08054970 @ =0x083966B8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08054974 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x1e
	strb r1, [r0]
	bx lr
	.align 2, 0
_0805496C: .4byte gSubSpriteData1
_08054970: .4byte 0x083966B8
_08054974: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidLanding
OmegaMetroidLanding: @ 0x08054978
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080549E0
	bl EventCheckAfter_SaXKilledByOmega
	cmp r0, #0
	bne _080549B0
	bl OmegaMetroidCheckSamusOnLowHealth
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080549B0
	ldr r1, _080549A8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
	ldrh r2, [r1]
	ldr r0, _080549AC @ =0x0000FDFF
	ands r0, r2
	strh r0, [r1]
	b _080549E0
	.align 2, 0
_080549A8: .4byte gCurrentSprite
_080549AC: .4byte 0x0000FDFF
_080549B0:
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldr r3, _080549D0 @ =gCurrentSprite
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080549D4
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x2b
	strb r0, [r1]
	b _080549E0
	.align 2, 0
_080549D0: .4byte gCurrentSprite
_080549D4:
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0x1f
	strb r1, [r0]
	adds r0, #9
	strb r2, [r0]
_080549E0:
	pop {r0}
	bx r0

	thumb_func_start OmegaMetroidIdleInit
OmegaMetroidIdleInit: @ 0x080549E4
	push {lr}
	ldr r0, _080549FC @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x2d
	ldrb r2, [r2]
	adds r3, r0, #0
	cmp r2, #1
	bne _08054A08
	ldr r1, _08054A00 @ =gSubSpriteData1
	ldr r0, _08054A04 @ =0x08396600
	b _08054A20
	.align 2, 0
_080549FC: .4byte gCurrentSprite
_08054A00: .4byte gSubSpriteData1
_08054A04: .4byte 0x08396600
_08054A08:
	cmp r2, #2
	bne _08054A1C
	ldr r1, _08054A14 @ =gSubSpriteData1
	ldr r0, _08054A18 @ =0x08396730
	b _08054A20
	.align 2, 0
_08054A14: .4byte gSubSpriteData1
_08054A18: .4byte 0x08396730
_08054A1C:
	ldr r1, _08054A34 @ =gSubSpriteData1
	ldr r0, _08054A38 @ =0x083965D8
_08054A20:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08054A34: .4byte gSubSpriteData1
_08054A38: .4byte 0x083965D8

	thumb_func_start OmegaMetroidIdle
OmegaMetroidIdle: @ 0x08054A3C
	push {r4, lr}
	ldr r0, _08054A94 @ =gCurrentSprite
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _08054A5E
	ldr r0, _08054A98 @ =gSubSpriteData1
	ldr r0, [r0, #4]
	ldr r1, _08054A9C @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bne _08054A5E
	ldr r0, _08054AA0 @ =0x00000223
	bl SoundPlay
_08054A5E:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08054AF2
	bl EventCheckAfter_SaXKilledByOmega
	cmp r0, #0
	bne _08054AA4
	bl OmegaMetroidCheckSamusOnLowHealth
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054AA4
	ldr r1, _08054A94 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x17
	strb r0, [r2]
	adds r1, #0x30
	movs r0, #0x14
	b _08054AF0
	.align 2, 0
_08054A94: .4byte gCurrentSprite
_08054A98: .4byte gSubSpriteData1
_08054A9C: .4byte 0x00FFFFFF
_08054AA0: .4byte 0x00000223
_08054AA4:
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldr r4, _08054AC4 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08054AC8
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #0xc
	movs r0, #0x14
	b _08054AF0
	.align 2, 0
_08054AC4: .4byte gCurrentSprite
_08054AC8:
	bl OmegaMetroidCheckSamusInFrontRange
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054ADA
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	b _08054AF0
_08054ADA:
	bl EventCheckAfter_SaXKilledByOmega
	cmp r0, #0
	beq _08054AEA
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x23
	b _08054AF0
_08054AEA:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #1
_08054AF0:
	strb r0, [r1]
_08054AF2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start OmegaMetroidWalkingBeforeSaXInit
OmegaMetroidWalkingBeforeSaXInit: @ 0x08054AF8
	ldr r1, _08054B14 @ =gSubSpriteData1
	ldr r0, _08054B18 @ =0x08396758
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08054B1C @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x24
	movs r2, #2
	strb r2, [r1]
	adds r0, #0x2d
	strb r2, [r0]
	bx lr
	.align 2, 0
_08054B14: .4byte gSubSpriteData1
_08054B18: .4byte 0x08396758
_08054B1C: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidWalkingBeforeSaX
OmegaMetroidWalkingBeforeSaX: @ 0x08054B20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08054B58 @ =gCurrentSprite
	movs r0, #0x30
	adds r0, r0, r4
	mov r8, r0
	movs r6, #0
	strb r6, [r0]
	adds r7, r4, #0
	adds r7, #0x2d
	ldrb r0, [r7]
	cmp r0, #2
	bne _08054B64
	bl OmegaMetroidForwardMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054BAC
	ldr r0, _08054B5C @ =gSubSpriteData1
	ldr r1, _08054B60 @ =0x083967C8
	str r1, [r0]
	strb r6, [r0, #6]
	strh r6, [r0, #4]
	movs r0, #3
	strb r0, [r7]
	b _08054BAC
	.align 2, 0
_08054B58: .4byte gCurrentSprite
_08054B5C: .4byte gSubSpriteData1
_08054B60: .4byte 0x083967C8
_08054B64:
	bl OmegaMetroidStandingMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08054BAC
	cmp r5, #2
	bne _08054B82
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
	b _08054BAC
_08054B82:
	cmp r5, #1
	bne _08054BA2
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	movs r0, #0x14
	mov r1, r8
	strb r0, [r1]
	b _08054BAC
_08054BA2:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1f
	strb r0, [r1]
	strb r6, [r7]
_08054BAC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidSlowWalkInit
OmegaMetroidSlowWalkInit: @ 0x08054BB8
	ldr r1, _08054BD8 @ =gSubSpriteData1
	ldr r0, _08054BDC @ =0x08396758
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r1, _08054BE0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x22
	strb r0, [r2]
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08054BD8: .4byte gSubSpriteData1
_08054BDC: .4byte 0x08396758
_08054BE0: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidSlowWalk
OmegaMetroidSlowWalk: @ 0x08054BE4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08054C0C @ =gCurrentSprite
	movs r0, #0x30
	adds r0, r0, r4
	mov r8, r0
	movs r6, #0
	strb r6, [r0]
	adds r7, r4, #0
	adds r7, #0x2d
	ldrb r0, [r7]
	cmp r0, #1
	beq _08054C4E
	cmp r0, #1
	bgt _08054C10
	cmp r0, #0
	beq _08054C1A
	b _08054CFC
	.align 2, 0
_08054C0C: .4byte gCurrentSprite
_08054C10:
	cmp r0, #2
	beq _08054C90
	cmp r0, #3
	beq _08054CB4
	b _08054CFC
_08054C1A:
	bl OmegaMetroidSlowMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054CFC
	ldr r0, _08054C40 @ =gSubSpriteData1
	ldr r1, _08054C44 @ =0x08396758
	str r1, [r0]
	strb r6, [r0, #6]
	strh r6, [r0, #4]
	cmp r5, #0
	beq _08054C48
	movs r0, #2
	strb r0, [r7]
	b _08054CFC
	.align 2, 0
_08054C40: .4byte gSubSpriteData1
_08054C44: .4byte 0x08396758
_08054C48:
	movs r0, #1
	strb r0, [r7]
	b _08054CFC
_08054C4E:
	bl OmegaMetroidForwardMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054CFC
	cmp r5, #0
	beq _08054C78
	ldr r0, _08054C70 @ =gSubSpriteData1
	ldr r1, _08054C74 @ =0x083967C8
	str r1, [r0]
	movs r1, #3
	strb r1, [r7]
	adds r1, r0, #0
	b _08054C80
	.align 2, 0
_08054C70: .4byte gSubSpriteData1
_08054C74: .4byte 0x083967C8
_08054C78:
	ldr r1, _08054C88 @ =gSubSpriteData1
	ldr r0, _08054C8C @ =0x083967B0
	str r0, [r1]
	strb r6, [r7]
_08054C80:
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	b _08054CFC
	.align 2, 0
_08054C88: .4byte gSubSpriteData1
_08054C8C: .4byte 0x083967B0
_08054C90:
	bl OmegaMetroidForwardMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054CFC
	ldr r0, _08054CAC @ =gSubSpriteData1
	ldr r1, _08054CB0 @ =0x083967C8
	str r1, [r0]
	strb r6, [r0, #6]
	strh r6, [r0, #4]
	movs r0, #3
	strb r0, [r7]
	b _08054CFC
	.align 2, 0
_08054CAC: .4byte gSubSpriteData1
_08054CB0: .4byte 0x083967C8
_08054CB4:
	bl OmegaMetroidStandingMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08054CFC
	cmp r5, #2
	bne _08054CD2
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
	b _08054CFC
_08054CD2:
	cmp r5, #1
	bne _08054CF2
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	movs r0, #0x14
	mov r1, r8
	strb r0, [r1]
	b _08054CFC
_08054CF2:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1f
	strb r0, [r1]
	strb r6, [r7]
_08054CFC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidWalkInit
OmegaMetroidWalkInit: @ 0x08054D08
	ldr r1, _08054D28 @ =gSubSpriteData1
	ldr r0, _08054D2C @ =0x083967D8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r1, _08054D30 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x24
	strb r0, [r2]
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08054D28: .4byte gSubSpriteData1
_08054D2C: .4byte 0x083967D8
_08054D30: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidWalk
OmegaMetroidWalk: @ 0x08054D34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08054D5C @ =gCurrentSprite
	movs r0, #0x30
	adds r0, r0, r4
	mov r8, r0
	movs r6, #0
	strb r6, [r0]
	adds r7, r4, #0
	adds r7, #0x2d
	ldrb r0, [r7]
	cmp r0, #1
	beq _08054D9E
	cmp r0, #1
	bgt _08054D60
	cmp r0, #0
	beq _08054D6A
	b _08054E4C
	.align 2, 0
_08054D5C: .4byte gCurrentSprite
_08054D60:
	cmp r0, #2
	beq _08054DE0
	cmp r0, #3
	beq _08054E04
	b _08054E4C
_08054D6A:
	bl OmegaMetroidSlowMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054E4C
	ldr r0, _08054D90 @ =gSubSpriteData1
	ldr r1, _08054D94 @ =0x083967D8
	str r1, [r0]
	strb r6, [r0, #6]
	strh r6, [r0, #4]
	cmp r5, #0
	beq _08054D98
	movs r0, #2
	strb r0, [r7]
	b _08054E4C
	.align 2, 0
_08054D90: .4byte gSubSpriteData1
_08054D94: .4byte 0x083967D8
_08054D98:
	movs r0, #1
	strb r0, [r7]
	b _08054E4C
_08054D9E:
	bl OmegaMetroidForwardMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054E4C
	cmp r5, #0
	beq _08054DC8
	ldr r0, _08054DC0 @ =gSubSpriteData1
	ldr r1, _08054DC4 @ =0x08396848
	str r1, [r0]
	movs r1, #3
	strb r1, [r7]
	adds r1, r0, #0
	b _08054DD0
	.align 2, 0
_08054DC0: .4byte gSubSpriteData1
_08054DC4: .4byte 0x08396848
_08054DC8:
	ldr r1, _08054DD8 @ =gSubSpriteData1
	ldr r0, _08054DDC @ =0x08396830
	str r0, [r1]
	strb r6, [r7]
_08054DD0:
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	b _08054E4C
	.align 2, 0
_08054DD8: .4byte gSubSpriteData1
_08054DDC: .4byte 0x08396830
_08054DE0:
	bl OmegaMetroidForwardMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08054E4C
	ldr r0, _08054DFC @ =gSubSpriteData1
	ldr r1, _08054E00 @ =0x08396848
	str r1, [r0]
	strb r6, [r0, #6]
	strh r6, [r0, #4]
	movs r0, #3
	strb r0, [r7]
	b _08054E4C
	.align 2, 0
_08054DFC: .4byte gSubSpriteData1
_08054E00: .4byte 0x08396848
_08054E04:
	bl OmegaMetroidStandingMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08054E4C
	cmp r5, #2
	bne _08054E22
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
	b _08054E4C
_08054E22:
	cmp r5, #1
	bne _08054E42
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	movs r0, #0x14
	mov r1, r8
	strb r0, [r1]
	b _08054E4C
_08054E42:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1f
	strb r0, [r1]
	strb r6, [r7]
_08054E4C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidSwipingInit
OmegaMetroidSwipingInit: @ 0x08054E58
	push {r4, lr}
	ldr r1, _08054E8C @ =gSubSpriteData1
	ldr r0, _08054E90 @ =0x08396918
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r4, _08054E94 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bl EventCheckAfter_SaXKilledByOmega
	cmp r0, #0
	beq _08054E9C
	ldr r0, _08054E98 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsrs r2, r0, #2
	cmp r2, #0
	bne _08054E84
	movs r2, #1
_08054E84:
	adds r0, r4, #0
	adds r0, #0x2e
	strb r2, [r0]
	b _08054EA4
	.align 2, 0
_08054E8C: .4byte gSubSpriteData1
_08054E90: .4byte 0x08396918
_08054E94: .4byte gCurrentSprite
_08054E98: .4byte gSpriteRandomNumber
_08054E9C:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #3
	strb r0, [r1]
_08054EA4:
	ldr r0, _08054ED4 @ =gCurrentSprite
	adds r0, #0x36
	ldrb r1, [r0]
	ldr r2, _08054ED8 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r2, r0, #0
	adds r2, #0x25
	movs r1, #0x15
	strb r1, [r2]
	movs r1, #0x40
	strh r1, [r0, #0xc]
	movs r1, #0x90
	strh r1, [r0, #0x10]
	movs r0, #0x88
	lsls r0, r0, #2
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054ED4: .4byte gCurrentSprite
_08054ED8: .4byte gSpriteData

	thumb_func_start OmegaMetroidSwiping
OmegaMetroidSwiping: @ 0x08054EDC
	push {r4, lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08054FA4
	ldr r2, _08054F78 @ =gSubSpriteData1
	ldr r1, [r2]
	ldr r0, _08054F7C @ =0x08396918
	cmp r1, r0
	bne _08054EF4
	ldr r0, _08054F80 @ =0x083966D8
	str r0, [r2]
_08054EF4:
	bl EventCheckAfter_SaXKilledByOmega
	adds r1, r0, #0
	cmp r1, #0
	bne _08054F14
	ldr r0, _08054F84 @ =gEquipment
	ldrh r0, [r0]
	cmp r0, #0x62
	bhi _08054F14
	ldr r0, _08054F88 @ =gPoseLock
	ldrb r0, [r0]
	cmp r0, #0x80
	bne _08054F14
	ldr r0, _08054F8C @ =gCurrentSprite
	adds r0, #0x2e
	strb r1, [r0]
_08054F14:
	bl OmegaMetroidCheckSamusInFrontRange
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08054F26
	ldr r0, _08054F8C @ =gCurrentSprite
	adds r0, #0x2e
	strb r1, [r0]
_08054F26:
	ldr r4, _08054F8C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	bne _08054FD8
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r1, [r0]
	ldr r2, _08054F90 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r2, r0, #0
	adds r2, #0x25
	movs r1, #0x16
	strb r1, [r2]
	movs r1, #0x30
	strh r1, [r0, #0xc]
	movs r1, #0x40
	strh r1, [r0, #0x10]
	bl OmegaMetroidCheckInFrontOfMiddleTrigger
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08054F94
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #0xc
	movs r0, #0x14
	strb r0, [r1]
	b _08054FD8
	.align 2, 0
_08054F78: .4byte gSubSpriteData1
_08054F7C: .4byte 0x08396918
_08054F80: .4byte 0x083966D8
_08054F84: .4byte gEquipment
_08054F88: .4byte gPoseLock
_08054F8C: .4byte gCurrentSprite
_08054F90: .4byte gSpriteData
_08054F94:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1f
	strb r0, [r1]
	adds r1, #9
	movs r0, #1
	strb r0, [r1]
	b _08054FD8
_08054FA4:
	ldr r0, _08054FC0 @ =gSubSpriteData1
	ldr r1, [r0, #4]
	ldr r0, _08054FC4 @ =0x00FFFFFF
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bne _08054FCC
	ldr r1, _08054FC8 @ =gCurrentSprite
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08054FD8
	.align 2, 0
_08054FC0: .4byte gSubSpriteData1
_08054FC4: .4byte 0x00FFFFFF
_08054FC8: .4byte gCurrentSprite
_08054FCC:
	ldr r0, _08054FE0 @ =0x00010002
	cmp r1, r0
	bne _08054FD8
	ldr r0, _08054FE4 @ =0x00000221
	bl SoundPlay
_08054FD8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054FE0: .4byte 0x00010002
_08054FE4: .4byte 0x00000221

	thumb_func_start OmegaMetroidVerticalJumpInit
OmegaMetroidVerticalJumpInit: @ 0x08054FE8
	ldr r1, _08055010 @ =gSubSpriteData1
	ldr r0, _08055014 @ =0x083966B8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _08055018 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	adds r1, #1
	movs r0, #0x17
	strb r0, [r1]
	bx lr
	.align 2, 0
_08055010: .4byte gSubSpriteData1
_08055014: .4byte 0x083966B8
_08055018: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidVerticalJump
OmegaMetroidVerticalJump: @ 0x0805501C
	push {r4, r5, r6, lr}
	ldr r0, _0805504C @ =gCurrentSprite
	adds r5, r0, #0
	adds r5, #0x31
	ldrb r2, [r5]
	ldr r3, _08055050 @ =0x08395990
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08055054 @ =0x00007FFF
	cmp r1, r0
	bne _0805505C
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldr r2, _08055058 @ =gSubSpriteData1
	ldrh r1, [r2, #8]
	ldrh r0, [r0]
	adds r1, r1, r0
	strh r1, [r2, #8]
	adds r4, r2, #0
	b _0805506A
	.align 2, 0
_0805504C: .4byte gCurrentSprite
_08055050: .4byte 0x08395990
_08055054: .4byte 0x00007FFF
_08055058: .4byte gSubSpriteData1
_0805505C:
	adds r0, r2, #1
	strb r0, [r5]
	ldr r1, _080550A4 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	adds r0, r0, r4
	strh r0, [r1, #8]
	adds r4, r1, #0
_0805506A:
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r0, _080550A8 @ =gPreviousVerticalCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080550C6
	strh r2, [r4, #8]
	movs r0, #0x3c
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _080550AC @ =0x0000021F
	bl SoundPlay
	ldr r2, _080550B0 @ =gCurrentSprite
	ldr r1, _080550B4 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bhs _080550B8
	adds r1, r2, #0
	adds r1, #0x31
	movs r0, #0
	b _080550C4
	.align 2, 0
_080550A4: .4byte gSubSpriteData1
_080550A8: .4byte gPreviousVerticalCollisionCheck
_080550AC: .4byte 0x0000021F
_080550B0: .4byte gCurrentSprite
_080550B4: .4byte gSamusData
_080550B8:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1d
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x16
_080550C4:
	strb r0, [r1]
_080550C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start omegaMetroidSpawnSaX
omegaMetroidSpawnSaX: @ 0x080550CC
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _08055114 @ =gCurrentSprite
	ldr r0, _08055118 @ =0xFFFFFE80
	adds r1, r0, #0
	ldrh r2, [r4, #6]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0805511C @ =0xFFFFFC80
	adds r0, r2, #0
	ldrh r2, [r4, #8]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r4, #0
	adds r2, #0x23
	ldrb r3, [r2]
	movs r2, #0x10
	str r2, [sp]
	str r1, [sp, #4]
	subs r0, #0x20
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	movs r0, #0x4d
	movs r1, #0
	movs r2, #0
	bl SpriteSpawnNewXParasite
	adds r4, #0x2f
	strb r0, [r4]
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055114: .4byte gCurrentSprite
_08055118: .4byte 0xFFFFFE80
_0805511C: .4byte 0xFFFFFC80

	thumb_func_start OmegaMetroidWaitingForSaXInit
OmegaMetroidWaitingForSaXInit: @ 0x08055120
	ldr r1, _08055148 @ =gSubSpriteData1
	ldr r0, _0805514C @ =0x083965D8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _08055150 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x2d
	strb r2, [r0]
	adds r1, #0xa
	movs r0, #9
	strb r0, [r1]
	bx lr
	.align 2, 0
_08055148: .4byte gSubSpriteData1
_0805514C: .4byte 0x083965D8
_08055150: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidWaitingForSaX
OmegaMetroidWaitingForSaX: @ 0x08055154
	push {r4, r5, lr}
	ldr r4, _08055194 @ =gSamusData
	ldrh r0, [r4, #0x18]
	subs r0, #0x20
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #0x16]
	adds r1, r1, r2
	subs r1, #0x10
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08055198 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _08055178
	ldrh r0, [r4, #0x16]
	subs r0, #8
	strh r0, [r4, #0x16]
_08055178:
	ldr r1, _0805519C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #6
	bls _08055188
	b _0805534A
_08055188:
	lsls r0, r0, #2
	ldr r1, _080551A0 @ =_080551A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08055194: .4byte gSamusData
_08055198: .4byte gPreviousCollisionCheck
_0805519C: .4byte gCurrentSprite
_080551A0: .4byte _080551A4
_080551A4: @ jump table
	.4byte _080551C0 @ case 0
	.4byte _08055214 @ case 1
	.4byte _08055248 @ case 2
	.4byte _08055288 @ case 3
	.4byte _080552C8 @ case 4
	.4byte _080552F4 @ case 5
	.4byte _08055324 @ case 6
_080551C0:
	ldr r0, _080551E0 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _080551E4
	ldrb r2, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl SpriteLoadGfx
	b _080551F2
	.align 2, 0
_080551E0: .4byte gCurrentSprite
_080551E4:
	cmp r0, #8
	bne _080551F2
	movs r0, #0x4d
	movs r1, #0
	movs r2, #2
	bl SpriteLoadPal
_080551F2:
	ldr r1, _08055210 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #0
	beq _08055200
	b _0805534A
_08055200:
	adds r0, r1, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x64
	strb r0, [r2]
	b _0805534A
	.align 2, 0
_08055210: .4byte gCurrentSprite
_08055214:
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _08055224
	subs r0, #1
	b _08055348
_08055224:
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	bne _0805522E
	b _0805534A
_0805522E:
	ldr r0, _08055240 @ =gSubSpriteData1
	ldr r1, _08055244 @ =0x08396858
	str r1, [r0]
	strb r4, [r0, #6]
	strh r4, [r0, #4]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #2
	b _08055348
	.align 2, 0
_08055240: .4byte gSubSpriteData1
_08055244: .4byte 0x08396858
_08055248:
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	bne _08055252
	b _0805534A
_08055252:
	ldr r1, _08055278 @ =gSubSpriteData1
	ldr r0, _0805527C @ =0x08396870
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r1, _08055280 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2d
	movs r0, #3
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x64
	strb r0, [r1]
	ldr r0, _08055284 @ =0x00000219
	bl SoundPlay
	b _0805534A
	.align 2, 0
_08055278: .4byte gSubSpriteData1
_0805527C: .4byte 0x08396870
_08055280: .4byte gCurrentSprite
_08055284: .4byte 0x00000219
_08055288:
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _08055298
	subs r0, #1
	b _08055348
_08055298:
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805534A
	ldr r0, _080552C0 @ =gSubSpriteData1
	ldr r1, _080552C4 @ =0x08396898
	str r1, [r0]
	strb r4, [r0, #6]
	strh r4, [r0, #4]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #4
	strb r0, [r1]
	subs r1, #0xb
	movs r0, #0xc
	strb r0, [r1]
	bl omegaMetroidSpawnSaX
	b _0805534A
	.align 2, 0
_080552C0: .4byte gSubSpriteData1
_080552C4: .4byte 0x08396898
_080552C8:
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805534A
	ldr r1, _080552E8 @ =gSubSpriteData1
	ldr r0, _080552EC @ =0x08396758
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _080552F0 @ =gCurrentSprite
	adds r0, #0x2d
	movs r1, #5
	strb r1, [r0]
	b _0805534A
	.align 2, 0
_080552E8: .4byte gSubSpriteData1
_080552EC: .4byte 0x08396758
_080552F0: .4byte gCurrentSprite
_080552F4:
	adds r0, r5, #0
	adds r0, #0x30
	movs r4, #0
	strb r4, [r0]
	bl OmegaMetroidForwardMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805534A
	ldr r0, _0805531C @ =gSubSpriteData1
	ldr r1, _08055320 @ =0x083967C8
	str r1, [r0]
	strb r4, [r0, #6]
	strh r4, [r0, #4]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #6
	b _08055348
	.align 2, 0
_0805531C: .4byte gSubSpriteData1
_08055320: .4byte 0x083967C8
_08055324:
	adds r0, r5, #0
	adds r0, #0x30
	movs r4, #0
	strb r4, [r0]
	bl OmegaMetroidStandingMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805534A
	ldr r0, _08055350 @ =gSubSpriteData1
	ldr r1, _08055354 @ =0x08396600
	str r1, [r0]
	strb r4, [r0, #6]
	strh r4, [r0, #4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0xb
_08055348:
	strb r0, [r1]
_0805534A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08055350: .4byte gSubSpriteData1
_08055354: .4byte 0x08396600

	thumb_func_start OmegaMetroidWatchingSaX
OmegaMetroidWatchingSaX: @ 0x08055358
	push {lr}
	bl OmegaMetroidSaXIceBeamCollision
	ldr r2, _080553A0 @ =gSpriteData
	ldr r0, _080553A4 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x45
	bne _0805539A
	mov r1, ip
	adds r1, #0x24
	movs r3, #0
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _080553A8 @ =gSubSpriteData1
	ldr r0, _080553AC @ =0x08396628
	str r0, [r1]
	strb r3, [r1, #6]
	movs r2, #0
	strh r3, [r1, #4]
	mov r0, ip
	adds r0, #0x2e
	strb r2, [r0]
	ldr r0, _080553B0 @ =0x0000021A
	bl SoundPlay
_0805539A:
	pop {r0}
	bx r0
	.align 2, 0
_080553A0: .4byte gSpriteData
_080553A4: .4byte gCurrentSprite
_080553A8: .4byte gSubSpriteData1
_080553AC: .4byte 0x08396628
_080553B0: .4byte 0x0000021A

	thumb_func_start OmegaMetroidDamagedBySaX
OmegaMetroidDamagedBySaX: @ 0x080553B4
	push {r4, lr}
	bl OmegaMetroidSaXIceBeamCollision
	bl OmegaMetroidBodyBlinking
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _080553EE
	ldr r1, _080553F4 @ =gSubSpriteData1
	ldr r0, _080553F8 @ =0x083968B0
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r2, _080553FC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #9
	strb r0, [r1]
	ldrh r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x2d
	strb r3, [r2]
_080553EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080553F4: .4byte gSubSpriteData1
_080553F8: .4byte 0x083968B0
_080553FC: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidWalkingBackwardsFromSaX
OmegaMetroidWalkingBackwardsFromSaX: @ 0x08055400
	push {r4, r5, r6, lr}
	bl OmegaMetroidSaXIceBeamCollision
	bl OmegaMetroidBodyBlinking
	ldr r5, _0805541C @ =gCurrentSprite
	adds r6, r5, #0
	adds r6, #0x2d
	ldrb r4, [r6]
	cmp r4, #0
	beq _08055420
	cmp r4, #1
	beq _08055470
	b _08055490
	.align 2, 0
_0805541C: .4byte gCurrentSprite
_08055420:
	adds r0, r5, #0
	adds r0, #0x30
	strb r4, [r0]
	bl OmegaMetroidBackwardsMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08055490
	ldr r0, _08055460 @ =gSubSpriteData1
	ldr r1, _08055464 @ =0x08396908
	str r1, [r0]
	strb r4, [r0, #6]
	strh r4, [r0, #4]
	ldrh r1, [r5]
	ldr r0, _08055468 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r5]
	movs r0, #1
	strb r0, [r6]
	ldr r2, _0805546C @ =gSpriteData
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x31
	movs r1, #0x1a
	strb r1, [r0]
	b _08055490
	.align 2, 0
_08055460: .4byte gSubSpriteData1
_08055464: .4byte 0x08396908
_08055468: .4byte 0x0000FDFF
_0805546C: .4byte gSpriteData
_08055470:
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08055490
	ldr r1, _08055498 @ =gSubSpriteData1
	ldr r0, _0805549C @ =0x08396628
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	movs r0, #0x3c
	strb r0, [r6]
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0xa
	strb r0, [r1]
_08055490:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055498: .4byte gSubSpriteData1
_0805549C: .4byte 0x08396628

	thumb_func_start OmegaMetroidDamagedBySaX2
OmegaMetroidDamagedBySaX2: @ 0x080554A0
	push {r4, r5, r6, lr}
	bl OmegaMetroidSaXIceBeamCollision
	bl OmegaMetroidBodyBlinking
	ldr r5, _080554D4 @ =gSubSpriteData1
	ldr r0, [r5, #4]
	ldr r1, _080554D8 @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bne _080554C0
	ldr r0, _080554DC @ =0x0000021A
	bl SoundPlay
_080554C0:
	ldr r6, _080554E0 @ =gCurrentSprite
	adds r1, r6, #0
	adds r1, #0x2d
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _080554E4
	subs r0, #1
	b _080554FA
	.align 2, 0
_080554D4: .4byte gSubSpriteData1
_080554D8: .4byte 0x00FFFFFF
_080554DC: .4byte 0x0000021A
_080554E0: .4byte gCurrentSprite
_080554E4:
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _080554FC
	ldr r0, _08055504 @ =0x083965D8
	str r0, [r5]
	strb r4, [r5, #6]
	strh r4, [r5, #4]
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0xd
_080554FA:
	strb r0, [r1]
_080554FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055504: .4byte 0x083965D8

	thumb_func_start OmegaMetroidWaitingToSwipeSaX
OmegaMetroidWaitingToSwipeSaX: @ 0x08055508
	push {lr}
	bl OmegaMetroidSaXIceBeamCollision
	bl OmegaMetroidBodyBlinking
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08055536
	ldr r1, _0805553C @ =gSubSpriteData1
	ldr r0, _08055540 @ =0x08396918
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08055544 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0xe
	strb r1, [r0]
	movs r0, #0x88
	lsls r0, r0, #2
	bl SoundPlay
_08055536:
	pop {r0}
	bx r0
	.align 2, 0
_0805553C: .4byte gSubSpriteData1
_08055540: .4byte 0x08396918
_08055544: .4byte gCurrentSprite

	thumb_func_start OmegaMEtroidSwipingSaX
OmegaMEtroidSwipingSaX: @ 0x08055548
	push {lr}
	bl OmegaMetroidSaXIceBeamCollision
	bl OmegaMetroidBodyBlinking
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805558C
	ldr r1, _08055580 @ =gSubSpriteData1
	ldr r0, _08055584 @ =0x08396660
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _08055588 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0xf
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x20
	strb r2, [r0]
	subs r1, #2
	movs r0, #4
	strb r0, [r1]
	b _080555DA
	.align 2, 0
_08055580: .4byte gSubSpriteData1
_08055584: .4byte 0x08396660
_08055588: .4byte gCurrentSprite
_0805558C:
	ldr r1, _080555A4 @ =gSubSpriteData1
	ldrh r0, [r1, #4]
	cmp r0, #2
	bne _080555AC
	ldrb r0, [r1, #6]
	cmp r0, #1
	bne _080555DA
	ldr r0, _080555A8 @ =0x00000221
	bl SoundPlay
	b _080555DA
	.align 2, 0
_080555A4: .4byte gSubSpriteData1
_080555A8: .4byte 0x00000221
_080555AC:
	cmp r0, #3
	bne _080555DA
	ldrb r0, [r1, #6]
	cmp r0, #1
	bne _080555DA
	ldr r2, _080555E0 @ =gSpriteData
	ldr r0, _080555E4 @ =gCurrentSprite
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	movs r1, #0x47
	strb r1, [r0]
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _080555E8 @ =0x000002AF
	bl SoundPlay
_080555DA:
	pop {r0}
	bx r0
	.align 2, 0
_080555E0: .4byte gSpriteData
_080555E4: .4byte gCurrentSprite
_080555E8: .4byte 0x000002AF

	thumb_func_start OmegaMetroidKilledSaX
OmegaMetroidKilledSaX: @ 0x080555EC
	push {r4, lr}
	ldr r4, _08055648 @ =gSubSpriteData1
	ldr r0, [r4, #4]
	ldr r1, _0805564C @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bne _08055606
	movs r0, #0x89
	lsls r0, r0, #2
	bl SoundPlay
_08055606:
	bl EventCheckAfter_IceBeamRecovered
	cmp r0, #0
	beq _08055640
	ldr r0, _08055650 @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0xbf
	ands r0, r1
	movs r3, #0
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x24
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _08055654 @ =0x08396858
	str r0, [r4]
	strb r3, [r4, #6]
	movs r1, #0
	strh r3, [r4, #4]
	mov r0, ip
	adds r0, #0x2d
	strb r1, [r0]
	movs r0, #0x32
	movs r1, #7
	bl PlayMusic
_08055640:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055648: .4byte gSubSpriteData1
_0805564C: .4byte 0x00FFFFFF
_08055650: .4byte gCurrentSprite
_08055654: .4byte 0x08396858

	thumb_func_start OmegaMetroidScreamingAfterIceBeamObtained
OmegaMetroidScreamingAfterIceBeamObtained: @ 0x08055658
	push {r4, r5, r6, lr}
	ldr r5, _08055674 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x10
	bne _08055678
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
	b _080556F8
	.align 2, 0
_08055674: .4byte gCurrentSprite
_08055678:
	adds r6, r5, #0
	adds r6, #0x2d
	ldrb r4, [r6]
	cmp r4, #0
	bne _080556B4
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _080556F8
	ldr r0, _080556A8 @ =gSubSpriteData1
	ldr r1, _080556AC @ =0x08396870
	str r1, [r0]
	strb r4, [r0, #6]
	strh r4, [r0, #4]
	movs r0, #1
	strb r0, [r6]
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0x64
	strb r0, [r1]
	ldr r0, _080556B0 @ =0x00000219
	bl SoundPlay
	b _080556F8
	.align 2, 0
_080556A8: .4byte gSubSpriteData1
_080556AC: .4byte 0x08396870
_080556B0: .4byte 0x00000219
_080556B4:
	cmp r4, #1
	bne _080556E4
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080556F8
	ldr r0, _080556DC @ =gSubSpriteData1
	ldr r1, _080556E0 @ =0x08396898
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
	movs r0, #2
	strb r0, [r6]
	b _080556F8
	.align 2, 0
_080556DC: .4byte gSubSpriteData1
_080556E0: .4byte 0x08396898
_080556E4:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080556F8
	adds r0, r5, #0
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	strb r2, [r6]
_080556F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidWalkingBackwardsInit
OmegaMetroidWalkingBackwardsInit: @ 0x08055700
	push {r4, lr}
	ldr r3, _08055748 @ =gSubSpriteData1
	ldr r0, _0805574C @ =0x083968B0
	str r0, [r3]
	movs r0, #0
	strb r0, [r3, #6]
	strh r0, [r3, #4]
	ldr r2, _08055750 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x26
	strb r0, [r1]
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r3, #0xa]
	lsrs r1, r1, #2
	ldr r0, _08055754 @ =gBg1XPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x78
	bhi _08055758
	ldrh r0, [r3, #0xc]
	cmp r0, #0
	beq _08055758
	adds r1, r2, #0
	adds r1, #0x2d
	movs r0, #2
	b _0805575E
	.align 2, 0
_08055748: .4byte gSubSpriteData1
_0805574C: .4byte 0x083968B0
_08055750: .4byte gCurrentSprite
_08055754: .4byte gBg1XPosition
_08055758:
	adds r1, r2, #0
	adds r1, #0x2d
	movs r0, #1
_0805575E:
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r1, [r0]
	ldr r2, _0805578C @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r2
	adds r2, r1, #0
	adds r2, #0x25
	ldrb r0, [r2]
	cmp r0, #0x15
	bne _08055786
	movs r0, #0x16
	strb r0, [r2]
	movs r0, #0x30
	strh r0, [r1, #0xc]
	movs r0, #0x40
	strh r0, [r1, #0x10]
_08055786:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805578C: .4byte gSpriteData

	thumb_func_start OmegaMetroidWalkingBackwards
OmegaMetroidWalkingBackwards: @ 0x08055790
	push {r4, r5, lr}
	ldr r4, _080557D4 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0
	strb r1, [r0]
	adds r5, r4, #0
	adds r5, #0x2d
	ldrb r0, [r5]
	cmp r0, #0
	beq _080557E4
	bl OmegaMetroidBackwardsMovement
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805583C
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0805583C
	ldr r0, _080557D8 @ =gSubSpriteData1
	ldr r1, _080557DC @ =0x08396908
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
	ldrh r1, [r4]
	ldr r0, _080557E0 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r4]
	b _0805583C
	.align 2, 0
_080557D4: .4byte gCurrentSprite
_080557D8: .4byte gSubSpriteData1
_080557DC: .4byte 0x08396908
_080557E0: .4byte 0x0000FDFF
_080557E4:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _0805583C
	ldr r2, _0805580C @ =gSubSpriteData1
	ldrh r1, [r2, #0xc]
	cmp r1, #0
	bne _08055814
	ldr r0, _08055810 @ =0x08396858
	str r0, [r2]
	strb r1, [r2, #6]
	movs r0, #0
	strh r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
	subs r1, #0xb
	movs r0, #0x44
	b _0805583A
	.align 2, 0
_0805580C: .4byte gSubSpriteData1
_08055810: .4byte 0x08396858
_08055814:
	ldr r0, _08055830 @ =gSamusData
	ldrb r0, [r0, #0xc]
	cmp r0, #0x3f
	bhi _08055834
	bl OmegaMetroidCheckSamusInFrontRange
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08055834
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	b _0805583A
	.align 2, 0
_08055830: .4byte gSamusData
_08055834:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x23
_0805583A:
	strb r0, [r1]
_0805583C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidDyingInit
OmegaMetroidDyingInit: @ 0x08055844
	push {r4, r5, lr}
	ldr r4, _08055884 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	bl OmegaMetroidFullBodyBlinking
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0805587C
	ldr r0, _08055888 @ =gSubSpriteData1
	ldr r1, _0805588C @ =0x08396870
	str r1, [r0]
	strb r5, [r0, #6]
	strh r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x46
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x64
	strb r0, [r1]
	ldr r0, _08055890 @ =0x00000219
	bl SoundPlay
_0805587C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08055884: .4byte gCurrentSprite
_08055888: .4byte gSubSpriteData1
_0805588C: .4byte 0x08396870
_08055890: .4byte 0x00000219

	thumb_func_start OmegaMetroidDying1
OmegaMetroidDying1: @ 0x08055894
	push {r4, lr}
	ldr r4, _080558D8 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl OmegaMetroidFullBodyBlinking
	adds r3, r4, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080558D2
	ldr r0, _080558DC @ =gSubSpriteData1
	ldr r1, _080558E0 @ =0x08396628
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x48
	strb r0, [r1]
	movs r0, #0x78
	strb r0, [r3]
	movs r0, #0
	bl FadeMusic
_080558D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080558D8: .4byte gCurrentSprite
_080558DC: .4byte gSubSpriteData1
_080558E0: .4byte 0x08396628

	thumb_func_start OmegaMetroidDying2
OmegaMetroidDying2: @ 0x080558E4
	push {r4, r5, lr}
	ldr r4, _08055914 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x26
	movs r2, #1
	strb r2, [r0]
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	subs r1, r0, #1
	strb r1, [r5]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bhi _08055918
	ands r1, r2
	cmp r1, #0
	beq _0805592A
	ldrh r0, [r4]
	movs r1, #4
	eors r0, r1
	strh r0, [r4]
	b _0805592A
	.align 2, 0
_08055914: .4byte gCurrentSprite
_08055918:
	bl OmegaMetroidFullBodyBlinking
	ldrb r0, [r5]
	cmp r0, #0x3c
	bne _0805592A
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
_0805592A:
	ldr r2, _08055968 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	cmp r0, #0
	bne _0805594A
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x4a
	strb r0, [r1]
	movs r0, #0x1d
	strb r0, [r3]
_0805594A:
	ldrh r4, [r2, #2]
	ldrh r5, [r2, #4]
	ldrb r0, [r3]
	cmp r0, #0x40
	beq _080559FE
	cmp r0, #0x40
	bgt _08055976
	cmp r0, #0x10
	beq _08055A4A
	cmp r0, #0x10
	bgt _0805596C
	cmp r0, #0
	bne _08055966
	b _08055A66
_08055966:
	b _08055A80
	.align 2, 0
_08055968: .4byte gCurrentSprite
_0805596C:
	cmp r0, #0x20
	beq _08055A32
	cmp r0, #0x30
	beq _08055A16
	b _08055A80
_08055976:
	cmp r0, #0x60
	beq _080559D0
	cmp r0, #0x60
	bgt _08055984
	cmp r0, #0x50
	beq _080559E8
	b _08055A80
_08055984:
	cmp r0, #0x6b
	beq _080559B2
	cmp r0, #0x76
	bne _08055A80
	adds r0, r4, #0
	subs r0, #0x20
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #0x25
	bl ParticleSet
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r5, #0
	adds r1, #0x34
	movs r2, #0x22
	bl ParticleSet
	movs r0, #0x87
	lsls r0, r0, #2
	bl SoundPlay_3b1c
	b _08055A80
_080559B2:
	adds r0, r4, #0
	subs r0, #0x20
	adds r1, r5, #0
	subs r1, #0x24
	movs r2, #0x21
	bl ParticleSet
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r5, #0
	subs r1, #0x4c
	movs r2, #0x25
	bl ParticleSet
	b _08055A80
_080559D0:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	adds r1, #0x58
	movs r2, #0x25
	bl ParticleSet
	adds r0, r4, #0
	adds r0, #0x20
	adds r1, r5, #0
	adds r1, #0x20
	b _08055A5E
_080559E8:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	subs r1, #0x48
	movs r2, #0x21
	bl ParticleSet
	adds r1, r5, #0
	adds r1, #0x1e
	adds r0, r4, #0
	b _08055A5E
_080559FE:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	adds r1, #0x10
	movs r2, #0x2f
	bl ParticleSet
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r5, #0
	subs r1, #0x34
	b _08055A2A
_08055A16:
	adds r0, r4, #0
	subs r0, #0x20
	adds r1, r5, #0
	subs r1, #0x1c
	movs r2, #0x21
	bl ParticleSet
	adds r0, r4, #0
	adds r0, #0x46
	adds r1, r5, #0
_08055A2A:
	movs r2, #0x22
	bl ParticleSet
	b _08055A80
_08055A32:
	adds r0, r4, #0
	subs r0, #0x20
	adds r1, r5, #0
	adds r1, #0x24
	movs r2, #0x21
	bl ParticleSet
	adds r0, r4, #0
	adds r0, #0x40
	adds r1, r5, #0
	subs r1, #0x58
	b _08055A5E
_08055A4A:
	adds r0, r4, #0
	adds r0, #0x30
	adds r1, r5, #0
	subs r1, #0x4c
	movs r2, #0x2f
	bl ParticleSet
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
_08055A5E:
	movs r2, #0x2f
	bl ParticleSet
	b _08055A80
_08055A66:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	subs r1, #0x2a
	movs r2, #0x2f
	bl ParticleSet
	adds r1, r5, #0
	adds r1, #0x1e
	adds r0, r4, #0
	movs r2, #0x21
	bl ParticleSet
_08055A80:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroidDying3
OmegaMetroidDying3: @ 0x08055A88
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r1, _08055AB4 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x26
	movs r0, #1
	strb r0, [r2]
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1b
	bhi _08055AB8
	ldrb r2, [r1]
	movs r0, #0xc4
	movs r1, #0
	bl SpriteLoadGfx
	b _08055AC6
	.align 2, 0
_08055AB4: .4byte gCurrentSprite
_08055AB8:
	cmp r0, #0x1c
	bne _08055AC6
	movs r0, #0xc4
	movs r1, #0
	movs r2, #7
	bl SpriteLoadPal
_08055AC6:
	ldr r5, _08055AFC @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x2e
	ldrb r4, [r0]
	cmp r4, #0
	bne _08055AF4
	ldrh r1, [r5, #6]
	ldr r2, _08055B00 @ =0xFFFFFEC0
	adds r0, r2, #0
	ldrh r2, [r5, #8]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r1, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0xc4
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl SpriteSpawnPrimary
	strh r4, [r5]
_08055AF4:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08055AFC: .4byte gCurrentSprite
_08055B00: .4byte 0xFFFFFEC0

	thumb_func_start OmegaMetroidPartInit
OmegaMetroidPartInit: @ 0x08055B04
	push {r4, lr}
	ldr r4, _08055B44 @ =gCurrentSprite
	ldrh r1, [r4]
	ldr r0, _08055B48 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, #1
	strh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0x16
	strb r0, [r1]
	subs r1, #1
	movs r0, #2
	strb r0, [r1]
	bl OmegaMetroidPartSetDrawOrder
	ldrb r0, [r4, #0x1e]
	cmp r0, #7
	bls _08055B3A
	b _08055CE0
_08055B3A:
	lsls r0, r0, #2
	ldr r1, _08055B4C @ =_08055B50
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08055B44: .4byte gCurrentSprite
_08055B48: .4byte 0x0000FFFB
_08055B4C: .4byte _08055B50
_08055B50: @ jump table
	.4byte _08055B70 @ case 0
	.4byte _08055B9C @ case 1
	.4byte _08055BD0 @ case 2
	.4byte _08055CE0 @ case 3
	.4byte _08055C04 @ case 4
	.4byte _08055C48 @ case 5
	.4byte _08055C7C @ case 6
	.4byte _08055CB0 @ case 7
_08055B70:
	ldr r2, _08055B94 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x27
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x28
	movs r1, #0x40
	strb r1, [r0]
	adds r3, r2, #0
	adds r3, #0x29
	movs r0, #0x28
	strb r0, [r3]
	ldr r0, _08055B98 @ =0x0000FFA0
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	adds r0, #0x38
	b _08055CD0
	.align 2, 0
_08055B94: .4byte gCurrentSprite
_08055B98: .4byte 0x0000FFA0
_08055B9C:
	ldr r2, _08055BC4 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _08055BC8 @ =0x0000FFC0
	strh r0, [r2, #0xa]
	movs r0, #0x40
	strh r0, [r2, #0xc]
	ldr r0, _08055BCC @ =0x0000FFE0
	strh r0, [r2, #0xe]
	movs r0, #0x20
	strh r0, [r2, #0x10]
	b _08055CE6
	.align 2, 0
_08055BC4: .4byte gCurrentSprite
_08055BC8: .4byte 0x0000FFC0
_08055BCC: .4byte 0x0000FFE0
_08055BD0:
	ldr r2, _08055BF8 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x27
	movs r0, #0x48
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _08055BFC @ =0x0000FF20
	strh r0, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	ldr r0, _08055C00 @ =0x0000FFE0
	strh r0, [r2, #0xe]
	movs r0, #0x60
	strh r0, [r2, #0x10]
	b _08055CE6
	.align 2, 0
_08055BF8: .4byte gCurrentSprite
_08055BFC: .4byte 0x0000FF20
_08055C00: .4byte 0x0000FFE0
_08055C04:
	ldr r3, _08055C40 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0x29
	movs r0, #8
	strb r0, [r1]
	movs r2, #0
	ldr r1, _08055C44 @ =0x0000FFE0
	strh r1, [r3, #0xa]
	movs r0, #0x28
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	movs r0, #0x20
	strh r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	b _08055CE6
	.align 2, 0
_08055C40: .4byte gCurrentSprite
_08055C44: .4byte 0x0000FFE0
_08055C48:
	ldr r2, _08055C70 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08055C74 @ =0x0000FFD8
	strh r0, [r2, #0xa]
	movs r0, #0x30
	strh r0, [r2, #0xc]
	ldr r0, _08055C78 @ =0x0000FFA0
	strh r0, [r2, #0xe]
	movs r0, #0x40
	strh r0, [r2, #0x10]
	b _08055CE6
	.align 2, 0
_08055C70: .4byte gCurrentSprite
_08055C74: .4byte 0x0000FFD8
_08055C78: .4byte 0x0000FFA0
_08055C7C:
	ldr r0, _08055CA8 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x27
	movs r3, #0
	movs r2, #0x20
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x28
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x29
	strb r2, [r0]
	ldr r0, _08055CAC @ =0x0000FFA0
	mov r1, ip
	strh r0, [r1, #0xa]
	strh r2, [r1, #0xc]
	strh r3, [r1, #0xe]
	movs r0, #0x80
	strh r0, [r1, #0x10]
	b _08055CE6
	.align 2, 0
_08055CA8: .4byte gCurrentSprite
_08055CAC: .4byte 0x0000FFA0
_08055CB0:
	ldr r2, _08055CD8 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x27
	movs r0, #0x40
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _08055CDC @ =0x0000FF80
	strh r0, [r2, #0xa]
	movs r1, #4
	strh r1, [r2, #0xc]
	adds r0, #0x28
_08055CD0:
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	b _08055CE6
	.align 2, 0
_08055CD8: .4byte gCurrentSprite
_08055CDC: .4byte 0x0000FF80
_08055CE0:
	ldr r1, _08055CF0 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_08055CE6:
	bl OmagaMetroidSyncSubSPrites
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055CF0: .4byte gCurrentSprite

	thumb_func_start OmegaMetroidPartIdle
OmegaMetroidPartIdle: @ 0x08055CF4
	push {r4, r5, r6, lr}
	ldr r2, _08055D18 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r4, [r0]
	ldr r1, _08055D1C @ =gSpriteData
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r0, r3, #0
	adds r6, r1, #0
	cmp r0, #0
	bne _08055D20
	strh r0, [r2]
	b _08055ED0
	.align 2, 0
_08055D18: .4byte gCurrentSprite
_08055D1C: .4byte gSpriteData
_08055D20:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _08055D3A
	ldrh r0, [r2]
	movs r1, #4
	orrs r1, r0
	strh r1, [r2]
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	b _08055D42
_08055D3A:
	ldrh r1, [r2]
	ldr r0, _08055D74 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_08055D42:
	lsls r1, r4, #3
	subs r0, r1, r4
	lsls r0, r0, #3
	adds r3, r0, r6
	ldrh r0, [r3, #0x14]
	adds r5, r1, #0
	cmp r0, #0
	bne _08055D5C
	strh r0, [r2, #0x14]
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
_08055D5C:
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #8
	cmp r0, #0x42
	bls _08055D6A
	b _08055ED0
_08055D6A:
	lsls r0, r0, #2
	ldr r1, _08055D78 @ =_08055D7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08055D74: .4byte 0x0000FFFB
_08055D78: .4byte _08055D7C
_08055D7C: @ jump table
	.4byte _08055E88 @ case 0
	.4byte _08055ED0 @ case 1
	.4byte _08055ED0 @ case 2
	.4byte _08055ED0 @ case 3
	.4byte _08055ED0 @ case 4
	.4byte _08055ED0 @ case 5
	.4byte _08055ED0 @ case 6
	.4byte _08055E9C @ case 7
	.4byte _08055ED0 @ case 8
	.4byte _08055ED0 @ case 9
	.4byte _08055ED0 @ case 10
	.4byte _08055ED0 @ case 11
	.4byte _08055ED0 @ case 12
	.4byte _08055ED0 @ case 13
	.4byte _08055ED0 @ case 14
	.4byte _08055ED0 @ case 15
	.4byte _08055ED0 @ case 16
	.4byte _08055ED0 @ case 17
	.4byte _08055ED0 @ case 18
	.4byte _08055ED0 @ case 19
	.4byte _08055ED0 @ case 20
	.4byte _08055ED0 @ case 21
	.4byte _08055ED0 @ case 22
	.4byte _08055ED0 @ case 23
	.4byte _08055ED0 @ case 24
	.4byte _08055ED0 @ case 25
	.4byte _08055ED0 @ case 26
	.4byte _08055ED0 @ case 27
	.4byte _08055ED0 @ case 28
	.4byte _08055ED0 @ case 29
	.4byte _08055ED0 @ case 30
	.4byte _08055ED0 @ case 31
	.4byte _08055ED0 @ case 32
	.4byte _08055ED0 @ case 33
	.4byte _08055ED0 @ case 34
	.4byte _08055ED0 @ case 35
	.4byte _08055ED0 @ case 36
	.4byte _08055ED0 @ case 37
	.4byte _08055ED0 @ case 38
	.4byte _08055ED0 @ case 39
	.4byte _08055ED0 @ case 40
	.4byte _08055ED0 @ case 41
	.4byte _08055ED0 @ case 42
	.4byte _08055ED0 @ case 43
	.4byte _08055ED0 @ case 44
	.4byte _08055ED0 @ case 45
	.4byte _08055ED0 @ case 46
	.4byte _08055EA2 @ case 47
	.4byte _08055EB0 @ case 48
	.4byte _08055ED0 @ case 49
	.4byte _08055ED0 @ case 50
	.4byte _08055ED0 @ case 51
	.4byte _08055ED0 @ case 52
	.4byte _08055ED0 @ case 53
	.4byte _08055ED0 @ case 54
	.4byte _08055ED0 @ case 55
	.4byte _08055ED0 @ case 56
	.4byte _08055ED0 @ case 57
	.4byte _08055ED0 @ case 58
	.4byte _08055ED0 @ case 59
	.4byte _08055EC0 @ case 60
	.4byte _08055ED0 @ case 61
	.4byte _08055EC0 @ case 62
	.4byte _08055ED0 @ case 63
	.4byte _08055EC0 @ case 64
	.4byte _08055ED0 @ case 65
	.4byte _08055EC0 @ case 66
_08055E88:
	subs r0, r5, r4
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #4
	bne _08055ED0
	bl OmegaMetroidPartSetDrawOrder_2
	b _08055ED0
_08055E9C:
	bl OmegaMetroidPartSetDrawOrder
	b _08055ED0
_08055EA2:
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	b _08055ED0
_08055EB0:
	ldrh r1, [r2]
	ldr r0, _08055EBC @ =0x0000DFFF
	ands r0, r1
	strh r0, [r2]
	b _08055ED0
	.align 2, 0
_08055EBC: .4byte 0x0000DFFF
_08055EC0:
	subs r0, r5, r4
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r0, #0x20
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x20
	strb r1, [r0]
_08055ED0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OmegaMetroid
OmegaMetroid: @ 0x08055ED8
	push {lr}
	bl OmegaMetroidUpdateHeartPalette
	bl OmegaMetroidUpdateHealthThreshold
	ldr r0, _08055EF8 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x4a
	bls _08055EEE
	b _0805610C
_08055EEE:
	lsls r0, r0, #2
	ldr r1, _08055EFC @ =_08055F00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08055EF8: .4byte gCurrentSprite
_08055EFC: .4byte _08055F00
_08055F00: @ jump table
	.4byte _0805602C @ case 0
	.4byte _08056056 @ case 1
	.4byte _0805605A @ case 2
	.4byte _0805610C @ case 3
	.4byte _0805610C @ case 4
	.4byte _0805610C @ case 5
	.4byte _0805610C @ case 6
	.4byte _080560BC @ case 7
	.4byte _080560C0 @ case 8
	.4byte _080560D2 @ case 9
	.4byte _080560D8 @ case 10
	.4byte _080560C6 @ case 11
	.4byte _080560CC @ case 12
	.4byte _080560DE @ case 13
	.4byte _080560E4 @ case 14
	.4byte _080560EA @ case 15
	.4byte _080560F0 @ case 16
	.4byte _0805610C @ case 17
	.4byte _0805610C @ case 18
	.4byte _0805610C @ case 19
	.4byte _0805610C @ case 20
	.4byte _0805610C @ case 21
	.4byte _0805610C @ case 22
	.4byte _08056088 @ case 23
	.4byte _0805608C @ case 24
	.4byte _0805610C @ case 25
	.4byte _08056092 @ case 26
	.4byte _0805610C @ case 27
	.4byte _08056098 @ case 28
	.4byte _0805609E @ case 29
	.4byte _080560A2 @ case 30
	.4byte _08056074 @ case 31
	.4byte _08056078 @ case 32
	.4byte _08056060 @ case 33
	.4byte _08056064 @ case 34
	.4byte _0805606A @ case 35
	.4byte _0805606E @ case 36
	.4byte _0805607E @ case 37
	.4byte _08056082 @ case 38
	.4byte _0805610C @ case 39
	.4byte _0805610C @ case 40
	.4byte _080560A8 @ case 41
	.4byte _080560AC @ case 42
	.4byte _080560B2 @ case 43
	.4byte _080560B6 @ case 44
	.4byte _0805610C @ case 45
	.4byte _0805610C @ case 46
	.4byte _0805610C @ case 47
	.4byte _0805610C @ case 48
	.4byte _0805610C @ case 49
	.4byte _0805610C @ case 50
	.4byte _0805610C @ case 51
	.4byte _0805610C @ case 52
	.4byte _0805610C @ case 53
	.4byte _0805610C @ case 54
	.4byte _08056032 @ case 55
	.4byte _08056038 @ case 56
	.4byte _0805610C @ case 57
	.4byte _0805603E @ case 58
	.4byte _0805610C @ case 59
	.4byte _08056044 @ case 60
	.4byte _0805610C @ case 61
	.4byte _0805604A @ case 62
	.4byte _0805610C @ case 63
	.4byte _08056050 @ case 64
	.4byte _0805610C @ case 65
	.4byte _0805610C @ case 66
	.4byte _0805610C @ case 67
	.4byte _080560F6 @ case 68
	.4byte _0805610C @ case 69
	.4byte _080560FC @ case 70
	.4byte _0805610C @ case 71
	.4byte _08056102 @ case 72
	.4byte _0805610C @ case 73
	.4byte _08056108 @ case 74
_0805602C:
	bl OmegaMetroidInit
	b _0805610C
_08056032:
	bl OmegaMetroidWaitingToAppear
	b _0805610C
_08056038:
	bl OmegaMetroidFirstJump
	b _0805610C
_0805603E:
	bl OmegaMetroidLandingFromFirstJump
	b _0805610C
_08056044:
	bl OmegaMetroidLandedAfterFirstJump
	b _0805610C
_0805604A:
	bl OmegaMetroidScreamingAfterFirstJump
	b _0805610C
_08056050:
	bl OmegaMetroidFinishedScreamingAfterFirstJump
	b _0805610C
_08056056:
	bl OmegaMetroidWalkingBeforeSaXInit
_0805605A:
	bl OmegaMetroidWalkingBeforeSaX
	b _0805610C
_08056060:
	bl OmegaMetroidSlowWalkInit
_08056064:
	bl OmegaMetroidSlowWalk
	b _0805610C
_0805606A:
	bl OmegaMetroidWalkInit
_0805606E:
	bl OmegaMetroidWalk
	b _0805610C
_08056074:
	bl OmegaMetroidIdleInit
_08056078:
	bl OmegaMetroidIdle
	b _0805610C
_0805607E:
	bl OmegaMetroidWalkingBackwardsInit
_08056082:
	bl OmegaMetroidWalkingBackwards
	b _0805610C
_08056088:
	bl OmegaMetroidJumpWarningInit
_0805608C:
	bl OmegaMetroidJumpWarning
	b _0805610C
_08056092:
	bl OmegaMetroidJumping
	b _0805610C
_08056098:
	bl OmegaMEtroidFalling
	b _0805610C
_0805609E:
	bl OmegaMetroidLandingInit
_080560A2:
	bl OmegaMetroidLanding
	b _0805610C
_080560A8:
	bl OmegaMetroidSwipingInit
_080560AC:
	bl OmegaMetroidSwiping
	b _0805610C
_080560B2:
	bl OmegaMetroidVerticalJumpInit
_080560B6:
	bl OmegaMetroidVerticalJump
	b _0805610C
_080560BC:
	bl OmegaMetroidWaitingForSaXInit
_080560C0:
	bl OmegaMetroidWaitingForSaX
	b _0805610C
_080560C6:
	bl OmegaMetroidWatchingSaX
	b _0805610C
_080560CC:
	bl OmegaMetroidDamagedBySaX
	b _0805610C
_080560D2:
	bl OmegaMetroidWalkingBackwardsFromSaX
	b _0805610C
_080560D8:
	bl OmegaMetroidDamagedBySaX2
	b _0805610C
_080560DE:
	bl OmegaMetroidWaitingToSwipeSaX
	b _0805610C
_080560E4:
	bl OmegaMEtroidSwipingSaX
	b _0805610C
_080560EA:
	bl OmegaMetroidKilledSaX
	b _0805610C
_080560F0:
	bl OmegaMetroidScreamingAfterIceBeamObtained
	b _0805610C
_080560F6:
	bl OmegaMetroidDyingInit
	b _0805610C
_080560FC:
	bl OmegaMetroidDying1
	b _0805610C
_08056102:
	bl OmegaMetroidDying2
	b _0805610C
_08056108:
	bl OmegaMetroidDying3
_0805610C:
	bl SpriteUtilUpdateSubSpriteData1Animation
	bl OmagaMetroidSyncSubSPrites
	bl OmegaMetroidUpdatePalette
	pop {r0}
	bx r0

	thumb_func_start OmegaMetroidPart
OmegaMetroidPart: @ 0x0805611C
	push {lr}
	ldr r0, _08056130 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _08056134
	bl OmegaMetroidPartInit
	b _0805613C
	.align 2, 0
_08056130: .4byte gCurrentSprite
_08056134:
	bl OmegaMetroidPartIdle
	bl OmagaMetroidSyncSubSPrites
_0805613C:
	pop {r0}
	bx r0

	thumb_func_start GunshipEndSpawnBeams
GunshipEndSpawnBeams: @ 0x08056140
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, _08056170 @ =gCurrentSprite
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r2, [r0, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldrh r5, [r0, #4]
	adds r1, r0, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	subs r1, #6
	adds r3, r0, #0
	cmp r1, #0xf
	bls _08056166
	b _08056270
_08056166:
	lsls r0, r1, #2
	ldr r1, _08056174 @ =_08056178
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056170: .4byte gCurrentSprite
_08056174: .4byte _08056178
_08056178: @ jump table
	.4byte _080561B8 @ case 0
	.4byte _08056270 @ case 1
	.4byte _08056270 @ case 2
	.4byte _080561DC @ case 3
	.4byte _08056270 @ case 4
	.4byte _08056270 @ case 5
	.4byte _080561FA @ case 6
	.4byte _08056270 @ case 7
	.4byte _08056270 @ case 8
	.4byte _08056218 @ case 9
	.4byte _08056270 @ case 10
	.4byte _08056270 @ case 11
	.4byte _08056236 @ case 12
	.4byte _08056270 @ case 13
	.4byte _08056270 @ case 14
	.4byte _08056254 @ case 15
_080561B8:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0xcc
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x79
	movs r1, #0
	bl SpriteSpawnSecondary
	movs r0, #0xfd
	bl SoundPlay
	b _08056270
_080561DC:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0xb0
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x79
	movs r1, #1
	bl SpriteSpawnSecondary
	b _08056270
_080561FA:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x98
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x79
	movs r1, #3
	bl SpriteSpawnSecondary
	b _08056270
_08056218:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x80
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x79
	movs r1, #5
	bl SpriteSpawnSecondary
	b _08056270
_08056236:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x68
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x79
	movs r1, #7
	bl SpriteSpawnSecondary
	b _08056270
_08056254:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r4, #0
	subs r0, #0x50
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x79
	movs r1, #9
	bl SpriteSpawnSecondary
_08056270:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start GunshipEndInit
GunshipEndInit: @ 0x08056278
	push {r4, lr}
	ldr r0, _080562F4 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0]
	ldr r1, _080562F8 @ =0x0000FFFB
	ands r1, r0
	movs r2, #0
	movs r3, #0
	mov r4, ip
	adds r4, #0x22
	movs r0, #0xc
	strb r0, [r4]
	subs r4, #1
	movs r0, #3
	strb r0, [r4]
	movs r0, #8
	orrs r1, r0
	mov r4, ip
	strh r1, [r4]
	movs r0, #0x90
	strh r0, [r4, #0x12]
	mov r0, ip
	adds r0, #0x2b
	strb r2, [r0]
	adds r0, #6
	strb r2, [r0]
	subs r0, #1
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	subs r1, #7
	movs r0, #0x7f
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x40
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xb0
	strb r0, [r1]
	ldr r1, _080562FC @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08056300 @ =0x0839EC68
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080562F4: .4byte gCurrentSprite
_080562F8: .4byte 0x0000FFFB
_080562FC: .4byte 0x0000FFFC
_08056300: .4byte 0x0839EC68

	thumb_func_start GunshipEndWaiting
GunshipEndWaiting: @ 0x08056304
	push {r4, lr}
	ldr r1, _08056334 @ =gCurrentSprite
	adds r4, r1, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805632C
	adds r0, r1, #0
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	movs r0, #0x5b
	movs r1, #0xe
	bl PlayMusic
	movs r0, #0x1e
	strb r0, [r4]
_0805632C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056334: .4byte gCurrentSprite

	thumb_func_start GunshipEndMovingUp
GunshipEndMovingUp: @ 0x08056338
	push {r4, lr}
	ldr r0, _08056374 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _08056356
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08056356
	ldr r0, _08056378 @ =0x00000249
	bl SoundPlay_3b1c
_08056356:
	movs r4, #0
	ldr r3, _08056374 @ =gCurrentSprite
	ldrh r2, [r3, #4]
	lsrs r0, r2, #2
	ldr r1, _0805637C @ =gBg1XPosition
	ldrh r1, [r1]
	lsrs r1, r1, #2
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x6f
	bhi _08056380
	adds r0, r2, #1
	strh r0, [r3, #4]
	b _0805638C
	.align 2, 0
_08056374: .4byte gCurrentSprite
_08056378: .4byte 0x00000249
_0805637C: .4byte gBg1XPosition
_08056380:
	cmp r0, #0x80
	bls _0805638A
	subs r0, r2, #1
	strh r0, [r3, #4]
	b _0805638C
_0805638A:
	movs r4, #1
_0805638C:
	ldrh r2, [r3, #2]
	lsrs r0, r2, #2
	ldr r1, _080563A8 @ =gBg1YPosition
	ldrh r1, [r1]
	lsrs r1, r1, #2
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2b
	bhi _080563AC
	adds r0, r2, #1
	strh r0, [r3, #2]
	b _080563BC
	.align 2, 0
_080563A8: .4byte gBg1YPosition
_080563AC:
	cmp r0, #0x3c
	bls _080563B6
	subs r0, r2, #1
	strh r0, [r3, #2]
	b _080563BC
_080563B6:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080563BC:
	cmp r4, #1
	bls _080563E0
	adds r1, r3, #0
	adds r1, #0x21
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	adds r1, #3
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x3c
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	subs r0, #1
	strb r2, [r0]
_080563E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GunshipEndWaitingToEnter
GunshipEndWaitingToEnter: @ 0x080563E8
	push {r4, r5, r6, lr}
	ldr r3, _08056438 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _0805643C @ =0x0839AAE0
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08056440 @ =0x00007FFF
	cmp r1, r0
	bne _0805640A
	ldrh r4, [r5]
	movs r2, #0
_0805640A:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	adds r2, r3, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08056432
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0x18
	strb r1, [r0]
	movs r0, #0
	strb r0, [r2]
_08056432:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08056438: .4byte gCurrentSprite
_0805643C: .4byte 0x0839AAE0
_08056440: .4byte 0x00007FFF

	thumb_func_start GunshipEndEntering
GunshipEndEntering: @ 0x08056444
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r0, _080564B0 @ =gCurrentSprite
	mov ip, r0
	movs r1, #0x31
	add r1, ip
	mov r8, r1
	ldrb r2, [r1]
	ldr r4, _080564B4 @ =0x0839AAE0
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _080564B8 @ =0x00007FFF
	cmp r1, r0
	bne _0805646E
	ldrh r3, [r4]
	movs r2, #0
_0805646E:
	adds r0, r2, #1
	movs r7, #0
	mov r6, r8
	strb r0, [r6]
	mov r1, ip
	ldrh r0, [r1, #2]
	adds r4, r0, r3
	movs r5, #0
	strh r4, [r1, #2]
	ldr r2, _080564BC @ =0x0839AC90
	mov r6, ip
	adds r6, #0x2e
	ldrb r3, [r6]
	lsls r1, r3, #0x18
	lsrs r0, r1, #0x1a
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r2, ip
	strh r0, [r2, #0x12]
	lsrs r1, r1, #0x18
	cmp r1, #0x6f
	bhi _080564C0
	adds r0, r3, #1
	strb r0, [r6]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08056576
	adds r0, r4, #1
	strh r0, [r2, #2]
	b _08056576
	.align 2, 0
_080564B0: .4byte gCurrentSprite
_080564B4: .4byte 0x0839AAE0
_080564B8: .4byte 0x00007FFF
_080564BC: .4byte 0x0839AC90
_080564C0:
	mov r3, ip
	ldrh r1, [r3]
	ldr r0, _08056584 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r3]
	mov r1, ip
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldr r0, _08056588 @ =0x0839EB48
	str r0, [r3, #0x18]
	strb r5, [r3, #0x1c]
	strh r7, [r3, #0x16]
	mov r0, ip
	adds r0, #0x2f
	strb r5, [r0]
	adds r1, #0x10
	ldrb r0, [r1]
	movs r4, #1
	orrs r0, r4
	strb r0, [r1]
	ldrb r1, [r3, #0x1e]
	ldrb r2, [r3, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	mov r6, ip
	ldrh r0, [r6, #2]
	str r0, [sp]
	ldrh r0, [r6, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x7a
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	strb r0, [r1]
	ldr r2, _0805658C @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r3, r1, r2
	mov ip, r3
	ldrh r3, [r3]
	ldr r0, _08056590 @ =0x0000FFFB
	ands r0, r3
	mov r6, ip
	strh r0, [r6]
	adds r2, #0x18
	adds r1, r1, r2
	ldr r0, _08056594 @ =0x0839EC30
	str r0, [r1]
	strb r5, [r6, #0x1c]
	strh r7, [r6, #0x16]
	mov r1, ip
	adds r1, #0x34
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	subs r1, #0x12
	movs r0, #0xe
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r5, [r0]
	adds r0, #2
	movs r2, #4
	strb r2, [r0]
	adds r1, #6
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x30
	strb r0, [r1]
	ldr r0, _08056598 @ =0x0000FFFC
	strh r0, [r6, #0xa]
	strh r2, [r6, #0xc]
	strh r0, [r6, #0xe]
	strh r2, [r6, #0x10]
	subs r1, #5
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2e
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_08056576:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056584: .4byte 0x0000FFF7
_08056588: .4byte 0x0839EB48
_0805658C: .4byte gSpriteData
_08056590: .4byte 0x0000FFFB
_08056594: .4byte 0x0839EC30
_08056598: .4byte 0x0000FFFC

	thumb_func_start GunshipEndWaitingForSamus
GunshipEndWaitingForSamus: @ 0x0805659C
	push {r4, r5, lr}
	ldr r4, _080565B4 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0x23
	bhi _080565B8
	adds r0, #1
	strb r0, [r1]
	bl GunshipEndSpawnBeams
	b _08056638
	.align 2, 0
_080565B4: .4byte gCurrentSprite
_080565B8:
	ldrh r2, [r4, #4]
	adds r0, r2, #0
	subs r0, #0x20
	ldr r5, _08056624 @ =gSamusData
	ldrh r1, [r5, #0x16]
	cmp r0, r1
	bge _08056630
	adds r0, #0x40
	cmp r0, r1
	ble _08056630
	ldrh r1, [r5, #0x18]
	ldr r0, _08056628 @ =0x000002BF
	cmp r1, r0
	bne _08056630
	bl SpriteUtilCheckSamusMorphed
	adds r1, r0, #0
	cmp r1, #0
	bne _08056630
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _080565E6
	strb r1, [r5, #5]
_080565E6:
	ldr r1, _0805662C @ =sSamusSetPoseFunctionPointer
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x20
	bl _call_via_r1
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldrh r0, [r4, #4]
	strh r0, [r5, #0x16]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	subs r1, #0xc
	movs r0, #4
	strb r0, [r1]
	movs r0, #0x6d
	bl EventCheckAdvance
	b _08056638
	.align 2, 0
_08056624: .4byte gSamusData
_08056628: .4byte 0x000002BF
_0805662C: .4byte sSamusSetPoseFunctionPointer
_08056630:
	ldr r0, _08056640 @ =gCurrentSprite
	adds r0, #0x22
	movs r1, #0xc
	strb r1, [r0]
_08056638:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08056640: .4byte gCurrentSprite

	thumb_func_start GunshipEndLockingSamus
GunshipEndLockingSamus: @ 0x08056644
	push {lr}
	ldr r1, _08056668 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08056664
	adds r0, r1, #0
	adds r0, #0x24
	movs r1, #0x38
	strb r1, [r0]
	movs r0, #0x3b
	strb r0, [r2]
_08056664:
	pop {r0}
	bx r0
	.align 2, 0
_08056668: .4byte gCurrentSprite

	thumb_func_start GunshipEndMovingSamusUp
GunshipEndMovingSamusUp: @ 0x0805666C
	push {lr}
	ldr r1, _08056690 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08056698
	adds r1, #0x24
	movs r0, #0x39
	strb r0, [r1]
	ldr r1, _08056694 @ =gDisableDrawingSamusAndScrollingFlag
	movs r0, #1
	strb r0, [r1]
	b _080566A0
	.align 2, 0
_08056690: .4byte gCurrentSprite
_08056694: .4byte gDisableDrawingSamusAndScrollingFlag
_08056698:
	ldr r1, _080566A4 @ =gSamusData
	ldrh r0, [r1, #0x18]
	subs r0, #4
	strh r0, [r1, #0x18]
_080566A0:
	pop {r0}
	bx r0
	.align 2, 0
_080566A4: .4byte gSamusData

	thumb_func_start GunshipEndStartingEngine1
GunshipEndStartingEngine1: @ 0x080566A8
	push {r4, r5, r6, lr}
	ldr r4, _08056718 @ =gCurrentSprite
	adds r6, r4, #0
	adds r6, #0x31
	ldrb r5, [r6]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08056712
	adds r1, r4, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x3a
	strb r0, [r1]
	ldr r0, _0805671C @ =0x0839EC68
	str r0, [r4, #0x18]
	strb r3, [r4, #0x1c]
	movs r2, #0
	strh r3, [r4, #0x16]
	adds r1, #0xa
	movs r0, #0x3c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2f
	strb r2, [r0]
	strb r2, [r6]
	ldrh r0, [r4]
	movs r1, #8
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x12]
	adds r0, r4, #0
	adds r0, #0x2b
	strb r2, [r0]
	ldr r1, _08056720 @ =gSpriteData
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r3, [r0]
	ldr r0, _08056724 @ =0x082F474E
	ldr r1, _08056728 @ =0x040000D4
	str r0, [r1]
	ldr r0, _0805672C @ =0x05000336
	str r0, [r1, #4]
	ldr r0, _08056730 @ =0x80000005
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08056734 @ =0x0000024A
	bl SoundPlay_3b1c
_08056712:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08056718: .4byte gCurrentSprite
_0805671C: .4byte 0x0839EC68
_08056720: .4byte gSpriteData
_08056724: .4byte 0x082F474E
_08056728: .4byte 0x040000D4
_0805672C: .4byte 0x05000336
_08056730: .4byte 0x80000005
_08056734: .4byte 0x0000024A

	thumb_func_start GunshipEndStartingEngine2
GunshipEndStartingEngine2: @ 0x08056738
	push {r4, r5, r6, lr}
	ldr r2, _08056794 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r3, [r0]
	ldr r5, _08056798 @ =0x0839ABC4
	lsls r0, r3, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0805679C @ =0x00007FFF
	cmp r1, r0
	bne _0805675A
	ldrh r4, [r5]
	movs r3, #0
_0805675A:
	adds r0, r3, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r4
	movs r4, #0
	strh r0, [r2, #2]
	adds r5, r2, #0
	adds r5, #0x2f
	ldrb r1, [r5]
	cmp r1, #0
	bne _080567A4
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080567FE
	ldr r0, _080567A0 @ =0x0839EC08
	str r0, [r2, #0x18]
	strb r4, [r2, #0x1c]
	strh r1, [r2, #0x16]
	movs r0, #0x3c
	strb r0, [r3]
	movs r0, #1
	strb r0, [r5]
	b _080567FE
	.align 2, 0
_08056794: .4byte gCurrentSprite
_08056798: .4byte 0x0839ABC4
_0805679C: .4byte 0x00007FFF
_080567A0: .4byte 0x0839EC08
_080567A4:
	cmp r1, #1
	bne _080567D0
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _080567FE
	ldr r0, _080567CC @ =0x0839EC78
	str r0, [r2, #0x18]
	strb r4, [r2, #0x1c]
	strh r1, [r2, #0x16]
	movs r0, #0x5a
	strb r0, [r3]
	movs r0, #2
	strb r0, [r5]
	b _080567FE
	.align 2, 0
_080567CC: .4byte 0x0839EC78
_080567D0:
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080567FE
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
	strb r4, [r3]
	strb r4, [r5]
	adds r0, r2, #0
	adds r0, #0x30
	strb r4, [r0]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
_080567FE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start GunshipEndTakingOff
GunshipEndTakingOff: @ 0x08056804
	push {lr}
	ldr r1, _08056828 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x2e
	ldrb r2, [r3]
	adds r0, r2, #0
	cmp r0, #0x3f
	bls _0805682C
	ldrh r0, [r1, #2]
	subs r0, #8
	strh r0, [r1, #2]
	adds r1, #0x24
	movs r0, #0x3c
	strb r0, [r1]
	bl unk_6df04
	b _0805685A
	.align 2, 0
_08056828: .4byte gCurrentSprite
_0805682C:
	cmp r0, #0x37
	bls _0805683A
	ldrh r0, [r1, #2]
	subs r0, #8
	strh r0, [r1, #2]
	adds r0, r2, #4
	b _08056858
_0805683A:
	cmp r0, #0x2f
	bls _08056848
	ldrh r0, [r1, #2]
	subs r0, #2
	strh r0, [r1, #2]
	adds r0, r2, #4
	b _08056858
_08056848:
	cmp r0, #0x1f
	bls _08056856
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
	adds r0, r2, #2
	b _08056858
_08056856:
	adds r0, r2, #1
_08056858:
	strb r0, [r3]
_0805685A:
	ldr r3, _0805688C @ =gCurrentSprite
	ldr r1, _08056890 @ =0x0839ACD0
	adds r2, r3, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0x12]
	ldrb r0, [r2]
	cmp r0, #0x1f
	bls _08056886
	subs r0, #0x20
	asrs r0, r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08056894 @ =0x0839AC84
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x2b
	strb r1, [r0]
_08056886:
	pop {r0}
	bx r0
	.align 2, 0
_0805688C: .4byte gCurrentSprite
_08056890: .4byte 0x0839ACD0
_08056894: .4byte 0x0839AC84

	thumb_func_start GunshipEndDone
GunshipEndDone: @ 0x08056898
	bx lr
	.align 2, 0

	thumb_func_start GunshipEndBottomIdle
GunshipEndBottomIdle: @ 0x0805689C
	push {lr}
	ldr r2, _080568E0 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _0805690C
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	lsls r0, r0, #5
	ldr r1, _080568E4 @ =0x082F474E
	adds r0, r0, r1
	ldr r1, _080568E8 @ =0x040000D4
	str r0, [r1]
	ldr r0, _080568EC @ =0x05000336
	str r0, [r1, #4]
	ldr r0, _080568F0 @ =0x80000005
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r2, #0x2f
	ldrb r0, [r2]
	cmp r0, #0
	beq _080568FA
	ldrb r0, [r3]
	adds r1, r0, #0
	cmp r1, #0
	beq _080568F4
	subs r0, #1
	b _0805690A
	.align 2, 0
_080568E0: .4byte gCurrentSprite
_080568E4: .4byte 0x082F474E
_080568E8: .4byte 0x040000D4
_080568EC: .4byte 0x05000336
_080568F0: .4byte 0x80000005
_080568F4:
	strb r1, [r2]
	movs r0, #1
	b _0805690A
_080568FA:
	ldrb r0, [r3]
	cmp r0, #5
	bls _08056908
	movs r0, #1
	strb r0, [r2]
	movs r0, #5
	b _0805690A
_08056908:
	adds r0, #1
_0805690A:
	strb r0, [r3]
_0805690C:
	pop {r0}
	bx r0

	thumb_func_start GunshiEndpBeamInit
GunshiEndpBeamInit: @ 0x08056910
	push {r4, lr}
	ldr r0, _08056974 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08056978 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	adds r0, #2
	movs r1, #4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	subs r2, #0xb
	movs r0, #0x10
	strb r0, [r2]
	ldr r0, _0805697C @ =0x0000FFFC
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _08056980 @ =0x0839EBB8
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	subs r1, #2
	movs r0, #0xd
	strb r0, [r1]
	adds r1, #0xc
	movs r0, #9
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056974: .4byte gCurrentSprite
_08056978: .4byte 0x0000FFFB
_0805697C: .4byte 0x0000FFFC
_08056980: .4byte 0x0839EBB8

	thumb_func_start GunshipEndBeamMovingDown
GunshipEndBeamMovingDown: @ 0x08056984
	push {lr}
	ldr r1, _080569A4 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrb r0, [r1, #0x1e]
	adds r2, r1, #0
	cmp r0, #0
	beq _080569A8
	subs r0, #1
	strb r0, [r2, #0x1e]
	ldrh r0, [r2, #2]
	adds r0, #4
	strh r0, [r2, #2]
	b _080569EA
	.align 2, 0
_080569A4: .4byte gCurrentSprite
_080569A8:
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080569C0
	ldrh r0, [r2, #2]
	adds r0, #4
	strh r0, [r2, #2]
	b _080569CA
_080569C0:
	ldrh r0, [r2, #2]
	subs r0, #0x20
	strh r0, [r2, #2]
	movs r0, #9
	strb r0, [r1]
_080569CA:
	ldr r0, _080569F0 @ =gSpriteData
	lsls r1, r3, #3
	subs r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x37
	bne _080569EA
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	subs r1, #2
	movs r0, #5
	strb r0, [r1]
_080569EA:
	pop {r0}
	bx r0
	.align 2, 0
_080569F0: .4byte gSpriteData

	thumb_func_start GunshipEndBeamMovingUp
GunshipEndBeamMovingUp: @ 0x080569F4
	push {r4, lr}
	ldr r1, _08056A1C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r4, [r0]
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #8
	bls _08056A20
	movs r0, #0
	strb r0, [r2]
	ldrh r0, [r3, #2]
	adds r0, #0x20
	b _08056A24
	.align 2, 0
_08056A1C: .4byte gCurrentSprite
_08056A20:
	ldrh r0, [r3, #2]
	subs r0, #4
_08056A24:
	strh r0, [r3, #2]
	ldr r0, _08056A44 @ =gSpriteData
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x39
	bne _08056A3C
	movs r0, #0
	strh r0, [r3]
_08056A3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056A44: .4byte gSpriteData

	thumb_func_start GunshipEnd
GunshipEnd: @ 0x08056A48
	push {lr}
	ldr r0, _08056A68 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _08056A5E
	b _08056BAA
_08056A5E:
	lsls r0, r0, #2
	ldr r1, _08056A6C @ =_08056A70
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056A68: .4byte gCurrentSprite
_08056A6C: .4byte _08056A70
_08056A70: @ jump table
	.4byte _08056B64 @ case 0
	.4byte _08056B6A @ case 1
	.4byte _08056B70 @ case 2
	.4byte _08056BAA @ case 3
	.4byte _08056BAA @ case 4
	.4byte _08056BAA @ case 5
	.4byte _08056BAA @ case 6
	.4byte _08056BAA @ case 7
	.4byte _08056BAA @ case 8
	.4byte _08056BAA @ case 9
	.4byte _08056BAA @ case 10
	.4byte _08056BAA @ case 11
	.4byte _08056BAA @ case 12
	.4byte _08056BAA @ case 13
	.4byte _08056BAA @ case 14
	.4byte _08056BAA @ case 15
	.4byte _08056BAA @ case 16
	.4byte _08056BAA @ case 17
	.4byte _08056BAA @ case 18
	.4byte _08056BAA @ case 19
	.4byte _08056BAA @ case 20
	.4byte _08056BAA @ case 21
	.4byte _08056BAA @ case 22
	.4byte _08056B76 @ case 23
	.4byte _08056B7C @ case 24
	.4byte _08056BAA @ case 25
	.4byte _08056B82 @ case 26
	.4byte _08056BAA @ case 27
	.4byte _08056BAA @ case 28
	.4byte _08056BAA @ case 29
	.4byte _08056BAA @ case 30
	.4byte _08056BAA @ case 31
	.4byte _08056BAA @ case 32
	.4byte _08056BAA @ case 33
	.4byte _08056BAA @ case 34
	.4byte _08056BAA @ case 35
	.4byte _08056BAA @ case 36
	.4byte _08056BAA @ case 37
	.4byte _08056BAA @ case 38
	.4byte _08056BAA @ case 39
	.4byte _08056BAA @ case 40
	.4byte _08056BAA @ case 41
	.4byte _08056BAA @ case 42
	.4byte _08056BAA @ case 43
	.4byte _08056BAA @ case 44
	.4byte _08056BAA @ case 45
	.4byte _08056BAA @ case 46
	.4byte _08056BAA @ case 47
	.4byte _08056BAA @ case 48
	.4byte _08056BAA @ case 49
	.4byte _08056BAA @ case 50
	.4byte _08056BAA @ case 51
	.4byte _08056BAA @ case 52
	.4byte _08056BAA @ case 53
	.4byte _08056BAA @ case 54
	.4byte _08056B88 @ case 55
	.4byte _08056B8E @ case 56
	.4byte _08056B94 @ case 57
	.4byte _08056B9A @ case 58
	.4byte _08056BA0 @ case 59
	.4byte _08056BA6 @ case 60
_08056B64:
	bl GunshipEndInit
	b _08056BAA
_08056B6A:
	bl GunshipEndWaiting
	b _08056BAA
_08056B70:
	bl GunshipEndMovingUp
	b _08056BAA
_08056B76:
	bl GunshipEndWaitingToEnter
	b _08056BAA
_08056B7C:
	bl GunshipEndEntering
	b _08056BAA
_08056B82:
	bl GunshipEndWaitingForSamus
	b _08056BAA
_08056B88:
	bl GunshipEndLockingSamus
	b _08056BAA
_08056B8E:
	bl GunshipEndMovingSamusUp
	b _08056BAA
_08056B94:
	bl GunshipEndStartingEngine1
	b _08056BAA
_08056B9A:
	bl GunshipEndStartingEngine2
	b _08056BAA
_08056BA0:
	bl GunshipEndTakingOff
	b _08056BAA
_08056BA6:
	bl GunshipEndDone
_08056BAA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GunshipEndBottom
GunshipEndBottom: @ 0x08056BB0
	push {lr}
	ldr r0, _08056BCC @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	bne _08056BC8
	bl GunshipEndBottomIdle
_08056BC8:
	pop {r0}
	bx r0
	.align 2, 0
_08056BCC: .4byte gCurrentSprite

	thumb_func_start GunshipEndBeam
GunshipEndBeam: @ 0x08056BD0
	push {lr}
	ldr r0, _08056BF0 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08056BFE
	cmp r0, #2
	bgt _08056BF4
	cmp r0, #0
	beq _08056BFA
	b _08056C08
	.align 2, 0
_08056BF0: .4byte gCurrentSprite
_08056BF4:
	cmp r0, #0x18
	beq _08056C04
	b _08056C08
_08056BFA:
	bl GunshiEndpBeamInit
_08056BFE:
	bl GunshipEndBeamMovingDown
	b _08056C08
_08056C04:
	bl GunshipEndBeamMovingUp
_08056C08:
	ldr r1, _08056C20 @ =gCurrentSprite
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _08056C1C
	ldrh r0, [r1]
	cmp r0, #0
	bne _08056C1C
	movs r0, #0xfd
	bl SoundStop
_08056C1C:
	pop {r0}
	bx r0
	.align 2, 0
_08056C20: .4byte gCurrentSprite
