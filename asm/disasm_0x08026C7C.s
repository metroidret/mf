    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start WaverCheckSamusInRange
WaverCheckSamusInRange: @ 0x08026C7C
	push {r4, lr}
	movs r4, #0
	ldr r0, _08026CA4 @ =gCurrentSprite
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	beq _08026C9A
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #0x28
	movs r2, #0x40
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	cmp r0, #3
	bne _08026C9A
	movs r4, #1
_08026C9A:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08026CA4: .4byte gCurrentSprite

	thumb_func_start WaverSetFlyingGFX
WaverSetFlyingGFX: @ 0x08026CA8
	push {lr}
	ldr r2, _08026CC4 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08026CCC
	ldr r0, _08026CC8 @ =0x08317590
	b _08026CCE
	.align 2, 0
_08026CC4: .4byte gCurrentSprite
_08026CC8: .4byte 0x08317590
_08026CCC:
	ldr r0, _08026CD4 @ =0x08317580
_08026CCE:
	str r0, [r2, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_08026CD4: .4byte 0x08317580

	thumb_func_start WaverInit
WaverInit: @ 0x08026CD8
	push {lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08026D04 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08026D08
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08026D08
	strh r0, [r2]
	b _08026D88
	.align 2, 0
_08026D04: .4byte gCurrentSprite
_08026D08:
	ldr r1, _08026D20 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	ldrb r0, [r2]
	adds r3, r1, #0
	cmp r0, #0x59
	bne _08026D24
	movs r0, #0x5a
	strb r0, [r2]
	movs r0, #0x2c
	strh r0, [r3, #6]
	b _08026D40
	.align 2, 0
_08026D20: .4byte gCurrentSprite
_08026D24:
	movs r0, #2
	strb r0, [r2]
	ldr r0, _08026D8C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08026D40
	ldrh r1, [r3]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r3]
_08026D40:
	adds r0, r3, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08026D90 @ =0x0000FFE0
	strh r1, [r3, #0xa]
	movs r0, #0x20
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	ldr r2, _08026D94 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x35
	movs r0, #1
	strb r0, [r1]
	subs r1, #0x10
	movs r0, #2
	strb r0, [r1]
	adds r1, #0xc
	movs r0, #0x30
	strb r0, [r1]
	bl WaverSetFlyingGFX
	bl SpriteUtilChooseRandomXFlip
_08026D88:
	pop {r0}
	bx r0
	.align 2, 0
_08026D8C: .4byte gSpriteRandomNumber
_08026D90: .4byte 0x0000FFE0
_08026D94: .4byte sPrimarySpriteStats

	thumb_func_start WaverFlyingInit
WaverFlyingInit: @ 0x08026D98
	push {lr}
	ldr r0, _08026DAC @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	bl WaverSetFlyingGFX
	pop {r0}
	bx r0
	.align 2, 0
_08026DAC: .4byte gCurrentSprite

	thumb_func_start WaverFlying
WaverFlying: @ 0x08026DB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _08026DDC @ =gCurrentSprite
	ldrh r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _08026DC6
	b _08026F56
_08026DC6:
	movs r0, #0
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	cmp r0, #0
	beq _08026DE0
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	b _08026DE4
	.align 2, 0
_08026DDC: .4byte gCurrentSprite
_08026DE0:
	movs r2, #0xa
	ldrsh r0, [r1, r2]
_08026DE4:
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	ldrh r1, [r1, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08026E34 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08026DFA
	movs r0, #1
	mov r8, r0
_08026DFA:
	bl WaverCheckSamusInRange
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08026E40
	ldr r3, _08026E38 @ =gCurrentSprite
	ldr r0, _08026E3C @ =0x083175D8
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r2, #0
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	adds r1, #0xa
	movs r0, #0x14
	strb r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _08026F56
	.align 2, 0
_08026E34: .4byte gPreviousCollisionCheck
_08026E38: .4byte gCurrentSprite
_08026E3C: .4byte 0x083175D8
_08026E40:
	ldr r1, _08026E84 @ =0x08316450
	ldr r2, _08026E88 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x31
	ldrb r0, [r3]
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r2, #0
	cmp r4, #0
	beq _08026E90
	mov r2, r8
	cmp r2, #0
	bne _08026E70
	ldrh r0, [r5, #2]
	adds r0, r0, r6
	strh r0, [r5, #2]
_08026E70:
	ldrb r0, [r3]
	cmp r0, #0x5e
	bls _08026EDA
	strb r7, [r3]
	ldrh r1, [r5]
	ldr r0, _08026E8C @ =0x0000FBFF
	ands r0, r1
	strh r0, [r5]
	b _08026EDA
	.align 2, 0
_08026E84: .4byte 0x08316450
_08026E88: .4byte gCurrentSprite
_08026E8C: .4byte 0x0000FBFF
_08026E90:
	ldr r1, [r5, #0x18]
	ldr r0, _08026F10 @ =0x08317590
	cmp r1, r0
	bne _08026EA8
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08026EA8
	ldr r0, _08026F14 @ =0x08317580
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
_08026EA8:
	ldr r5, _08026F18 @ =gCurrentSprite
	mov r0, r8
	cmp r0, #0
	bne _08026EB6
	ldrh r0, [r5, #2]
	subs r0, r0, r6
	strh r0, [r5, #2]
_08026EB6:
	adds r1, r5, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, #0x5e
	bls _08026EDA
	movs r3, #0
	strb r3, [r1]
	ldrh r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	movs r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _08026F10 @ =0x08317590
	str r0, [r5, #0x18]
	strb r2, [r5, #0x1c]
	strh r3, [r5, #0x16]
_08026EDA:
	adds r4, r5, #0
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08026F2C
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08026F1C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08026F24
	ldrh r1, [r4]
	ldr r0, _08026F20 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r4]
	b _08026F56
	.align 2, 0
_08026F10: .4byte 0x08317590
_08026F14: .4byte 0x08317580
_08026F18: .4byte gCurrentSprite
_08026F1C: .4byte gPreviousCollisionCheck
_08026F20: .4byte 0x0000FFBF
_08026F24:
	ldrh r0, [r4, #4]
	adds r0, #4
	strh r0, [r4, #4]
	b _08026F56
_08026F2C:
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08026F4C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08026F50
	ldrh r0, [r4]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r4]
	b _08026F56
	.align 2, 0
_08026F4C: .4byte gPreviousCollisionCheck
_08026F50:
	ldrh r0, [r5, #4]
	subs r0, #4
	strh r0, [r5, #4]
_08026F56:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start WaverCharging
WaverCharging: @ 0x08026F60
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r5, _08026FBC @ =gCurrentSprite
	adds r3, r5, #0
	adds r3, #0x30
	ldrb r2, [r3]
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x18
	lsrs r0, r0, #0x1b
	adds r4, r0, #6
	adds r6, r4, #0
	cmp r1, #0x27
	bhi _08026F7E
	adds r0, r2, #1
	strb r0, [r3]
_08026F7E:
	ldrh r1, [r5]
	movs r7, #0x40
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _08026FCA
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08026FC0 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08026FC4
	adds r1, r5, #0
	adds r1, #0x24
	movs r4, #0
	movs r0, #0x2b
	strb r0, [r1]
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	b _08026FF6
	.align 2, 0
_08026FBC: .4byte gCurrentSprite
_08026FC0: .4byte gPreviousCollisionCheck
_08026FC4:
	ldrh r0, [r5, #4]
	adds r0, r4, r0
	b _0802701C
_08026FCA:
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08027010 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08027018
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x2b
	strb r0, [r1]
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
_08026FF6:
	movs r0, #0x37
	bl SpriteSpawnSecondary
	ldrh r1, [r5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027046
	ldr r0, _08027014 @ =0x000001A7
	bl SoundPlayNotAlreadyPlaying
	b _08027046
	.align 2, 0
_08027010: .4byte gPreviousCollisionCheck
_08027014: .4byte 0x000001A7
_08027018:
	ldrh r0, [r5, #4]
	subs r0, r0, r6
_0802701C:
	strh r0, [r5, #4]
	ldr r1, _08027050 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08027046
	movs r0, #0x14
	strb r0, [r2]
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027046
	movs r0, #0xd3
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08027046:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027050: .4byte gCurrentSprite

	thumb_func_start WaverCrashingInit
WaverCrashingInit: @ 0x08027054
	ldr r1, _08027068 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x2c
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	bx lr
	.align 2, 0
_08027068: .4byte gCurrentSprite

	thumb_func_start WaverCrashing
WaverCrashing: @ 0x0802706C
	push {lr}
	ldr r1, _08027098 @ =gCurrentSprite
	ldrb r0, [r1, #0x1c]
	subs r0, #1
	strb r0, [r1, #0x1c]
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08027092
	adds r0, r1, #0
	adds r0, #0x24
	movs r1, #0x2e
	strb r1, [r0]
	movs r0, #0x44
	strb r0, [r2]
_08027092:
	pop {r0}
	bx r0
	.align 2, 0
_08027098: .4byte gCurrentSprite

	thumb_func_start WaverBackingOut
WaverBackingOut: @ 0x0802709C
	push {lr}
	ldr r2, _080270CC @ =gCurrentSprite
	ldrb r0, [r2, #0x1c]
	subs r0, #1
	strb r0, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080270D4
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0x30
	strb r1, [r0]
	ldr r0, _080270D0 @ =0x083175C0
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	b _080270EA
	.align 2, 0
_080270CC: .4byte gCurrentSprite
_080270D0: .4byte 0x083175C0
_080270D4:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080270E4
	ldrh r0, [r2, #4]
	subs r0, #1
	b _080270E8
_080270E4:
	ldrh r0, [r2, #4]
	adds r0, #1
_080270E8:
	strh r0, [r2, #4]
_080270EA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start WaverCheckBackingOutAnimEnded
WaverCheckBackingOutAnimEnded: @ 0x080270F0
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08027116
	ldr r2, _0802711C @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x32
	strb r0, [r1]
	ldr r0, _08027120 @ =0x083175C0
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_08027116:
	pop {r0}
	bx r0
	.align 2, 0
_0802711C: .4byte gCurrentSprite
_08027120: .4byte 0x083175C0

	thumb_func_start WaverCheckTurningAnimNearEnded
WaverCheckTurningAnimNearEnded: @ 0x08027124
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _08027136
	ldr r0, _0802713C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_08027136:
	pop {r0}
	bx r0
	.align 2, 0
_0802713C: .4byte gCurrentSprite

	thumb_func_start WaverDebrisInit
WaverDebrisInit: @ 0x08027140
	push {r4, lr}
	ldr r0, _080271B0 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _080271B4 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _080271B8 @ =0x0000FFE0
	mov r2, ip
	strh r0, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	ldr r0, _080271BC @ =0x0000FFD8
	strh r0, [r2, #0xe]
	movs r0, #0x28
	strh r0, [r2, #0x10]
	ldr r0, _080271C0 @ =0x08317608
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r0, ip
	adds r0, #0x2e
	strb r1, [r0]
	adds r0, #3
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	subs r1, #2
	movs r0, #3
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080271B0: .4byte gCurrentSprite
_080271B4: .4byte 0x0000FFFB
_080271B8: .4byte 0x0000FFE0
_080271BC: .4byte 0x0000FFD8
_080271C0: .4byte 0x08317608

	thumb_func_start WaverDebrisFalling
WaverDebrisFalling: @ 0x080271C4
	push {r4, r5, r6, lr}
	ldr r4, _080271F4 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r5, r0, #0
	cmp r5, #0
	bne _080271FC
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	ldr r0, _080271F8 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027200
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #0x27
	bl ParticleSet
	strh r5, [r4]
	b _0802725A
	.align 2, 0
_080271F4: .4byte gCurrentSprite
_080271F8: .4byte gPreviousVerticalCollisionCheck
_080271FC:
	subs r0, #1
	strb r0, [r1]
_08027200:
	ldr r2, _0802722C @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r3, [r0]
	ldr r5, _08027230 @ =0x08316414
	lsls r0, r3, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08027234 @ =0x00007FFF
	cmp r1, r0
	bne _08027238
	subs r1, r3, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r2, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08027242
	.align 2, 0
_0802722C: .4byte gCurrentSprite
_08027230: .4byte 0x08316414
_08027234: .4byte 0x00007FFF
_08027238:
	adds r0, r3, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r4
_08027242:
	strh r0, [r2, #2]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08027254
	ldrh r0, [r2, #4]
	adds r0, #4
	b _08027258
_08027254:
	ldrh r0, [r2, #4]
	subs r0, #4
_08027258:
	strh r0, [r2, #4]
_0802725A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start WaverDebrisExploding
WaverDebrisExploding: @ 0x08027260
	push {r4, lr}
	ldr r4, _08027278 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #0x25
	bl ParticleSet
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027278: .4byte gCurrentSprite

	thumb_func_start Waver
Waver: @ 0x0802727C
	push {r4, lr}
	ldr r4, _080272A8 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08027296
	movs r0, #0xd4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08027296:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080272AC
	bl SpriteUtilUpdateFreezeTimer
	b _08027482
	.align 2, 0
_080272A8: .4byte gCurrentSprite
_080272AC:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _080272B8
	b _08027482
_080272B8:
	lsls r0, r0, #2
	ldr r1, _080272C4 @ =_080272C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080272C4: .4byte _080272C8
_080272C8: @ jump table
	.4byte _08027438 @ case 0
	.4byte _0802743E @ case 1
	.4byte _08027442 @ case 2
	.4byte _08027482 @ case 3
	.4byte _08027482 @ case 4
	.4byte _08027482 @ case 5
	.4byte _08027482 @ case 6
	.4byte _08027482 @ case 7
	.4byte _08027482 @ case 8
	.4byte _08027482 @ case 9
	.4byte _08027482 @ case 10
	.4byte _08027482 @ case 11
	.4byte _08027482 @ case 12
	.4byte _08027482 @ case 13
	.4byte _08027482 @ case 14
	.4byte _08027482 @ case 15
	.4byte _08027482 @ case 16
	.4byte _08027482 @ case 17
	.4byte _08027482 @ case 18
	.4byte _08027482 @ case 19
	.4byte _08027482 @ case 20
	.4byte _08027482 @ case 21
	.4byte _08027482 @ case 22
	.4byte _08027482 @ case 23
	.4byte _08027482 @ case 24
	.4byte _08027482 @ case 25
	.4byte _08027482 @ case 26
	.4byte _08027482 @ case 27
	.4byte _08027482 @ case 28
	.4byte _08027482 @ case 29
	.4byte _08027482 @ case 30
	.4byte _08027482 @ case 31
	.4byte _08027482 @ case 32
	.4byte _08027482 @ case 33
	.4byte _08027482 @ case 34
	.4byte _08027482 @ case 35
	.4byte _08027482 @ case 36
	.4byte _08027482 @ case 37
	.4byte _08027482 @ case 38
	.4byte _08027482 @ case 39
	.4byte _08027482 @ case 40
	.4byte _08027482 @ case 41
	.4byte _08027448 @ case 42
	.4byte _0802744E @ case 43
	.4byte _08027452 @ case 44
	.4byte _08027482 @ case 45
	.4byte _08027458 @ case 46
	.4byte _08027482 @ case 47
	.4byte _0802745E @ case 48
	.4byte _08027482 @ case 49
	.4byte _08027464 @ case 50
	.4byte _08027482 @ case 51
	.4byte _08027482 @ case 52
	.4byte _08027482 @ case 53
	.4byte _08027482 @ case 54
	.4byte _08027482 @ case 55
	.4byte _08027482 @ case 56
	.4byte _08027482 @ case 57
	.4byte _08027482 @ case 58
	.4byte _08027482 @ case 59
	.4byte _08027482 @ case 60
	.4byte _08027482 @ case 61
	.4byte _08027482 @ case 62
	.4byte _08027482 @ case 63
	.4byte _08027482 @ case 64
	.4byte _08027482 @ case 65
	.4byte _08027482 @ case 66
	.4byte _08027482 @ case 67
	.4byte _08027482 @ case 68
	.4byte _08027482 @ case 69
	.4byte _08027482 @ case 70
	.4byte _08027482 @ case 71
	.4byte _08027482 @ case 72
	.4byte _08027482 @ case 73
	.4byte _08027482 @ case 74
	.4byte _08027482 @ case 75
	.4byte _08027482 @ case 76
	.4byte _08027482 @ case 77
	.4byte _08027482 @ case 78
	.4byte _08027482 @ case 79
	.4byte _08027482 @ case 80
	.4byte _08027482 @ case 81
	.4byte _08027482 @ case 82
	.4byte _08027482 @ case 83
	.4byte _08027482 @ case 84
	.4byte _08027482 @ case 85
	.4byte _08027482 @ case 86
	.4byte _0802746A @ case 87
	.4byte _0802746E @ case 88
	.4byte _08027474 @ case 89
	.4byte _08027478 @ case 90
	.4byte _0802747E @ case 91
_08027438:
	bl WaverInit
	b _08027482
_0802743E:
	bl WaverFlyingInit
_08027442:
	bl WaverFlying
	b _08027482
_08027448:
	bl WaverCharging
	b _08027482
_0802744E:
	bl WaverCrashingInit
_08027452:
	bl WaverCrashing
	b _08027482
_08027458:
	bl WaverBackingOut
	b _08027482
_0802745E:
	bl WaverCheckBackingOutAnimEnded
	b _08027482
_08027464:
	bl WaverCheckTurningAnimNearEnded
	b _08027482
_0802746A:
	bl SpriteDyingInit
_0802746E:
	bl SpriteDying
	b _08027482
_08027474:
	bl WaverInit
_08027478:
	bl SpriteSpawningFromX
	b _08027482
_0802747E:
	bl XParasiteInit
_08027482:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start WaverExplosion
WaverExplosion: @ 0x08027488
	push {lr}
	ldr r0, _080274A8 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _080274AC
	cmp r0, #2
	beq _080274B0
	bl WaverDebrisExploding
	b _080274B4
	.align 2, 0
_080274A8: .4byte gCurrentSprite
_080274AC:
	bl WaverDebrisInit
_080274B0:
	bl WaverDebrisFalling
_080274B4:
	pop {r0}
	bx r0

	thumb_func_start SciserCheckCollisions
SciserCheckCollisions: @ 0x080274B8
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _080274EC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027518
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080274F4
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _080274F0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08027568
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	b _0802755C
	.align 2, 0
_080274EC: .4byte gCurrentSprite
_080274F0: .4byte gPreviousCollisionCheck
_080274F4:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027514 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08027568
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0802755C
	.align 2, 0
_08027514: .4byte gPreviousCollisionCheck
_08027518:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027544
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027540 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08027568
	ldrh r0, [r4, #2]
	subs r0, #4
	b _08027558
	.align 2, 0
_08027540: .4byte gPreviousCollisionCheck
_08027544:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027570 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08027568
	ldrh r0, [r4, #2]
_08027558:
	ldrh r1, [r4, #4]
	adds r1, #0x20
_0802755C:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _08027568
	movs r6, #1
_08027568:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08027570: .4byte gPreviousCollisionCheck

	thumb_func_start SciserUpdateHitbox
SciserUpdateHitbox: @ 0x08027574
	push {lr}
	ldr r2, _0802759C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080275C0
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080275A8
	ldr r0, _080275A0 @ =0x0000FFD0
	strh r0, [r2, #0xa]
	movs r0, #0x30
	strh r0, [r2, #0xc]
	ldr r0, _080275A4 @ =0x0000FFB8
	strh r0, [r2, #0xe]
	movs r0, #0x10
	b _080275E2
	.align 2, 0
_0802759C: .4byte gCurrentSprite
_080275A0: .4byte 0x0000FFD0
_080275A4: .4byte 0x0000FFB8
_080275A8:
	ldr r0, _080275B8 @ =0x0000FFD0
	strh r0, [r2, #0xa]
	movs r0, #0x30
	strh r0, [r2, #0xc]
	ldr r0, _080275BC @ =0x0000FFF0
	strh r0, [r2, #0xe]
	movs r0, #0x48
	b _080275E2
	.align 2, 0
_080275B8: .4byte 0x0000FFD0
_080275BC: .4byte 0x0000FFF0
_080275C0:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080275D4
	movs r0, #0x10
	strh r0, [r2, #0xa]
	movs r0, #0x48
	b _080275DA
_080275D4:
	ldr r0, _080275E8 @ =0x0000FFB8
	strh r0, [r2, #0xa]
	movs r0, #0x10
_080275DA:
	strh r0, [r2, #0xc]
	ldr r0, _080275EC @ =0x0000FFD0
	strh r0, [r2, #0xe]
	movs r0, #0x30
_080275E2:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_080275E8: .4byte 0x0000FFB8
_080275EC: .4byte 0x0000FFD0

	thumb_func_start SciserSetCrawlingGFX
SciserSetCrawlingGFX: @ 0x080275F0
	push {lr}
	ldr r2, _08027614 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r1, r2, #0
	cmp r0, #0
	beq _08027624
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802761C
	ldr r0, _08027618 @ =0x083190A0
	b _0802763A
	.align 2, 0
_08027614: .4byte gCurrentSprite
_08027618: .4byte 0x083190A0
_0802761C:
	ldr r0, _08027620 @ =0x08319078
	b _0802763A
	.align 2, 0
_08027620: .4byte 0x08319078
_08027624:
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027638
	ldr r0, _08027634 @ =0x08318FC0
	b _0802763A
	.align 2, 0
_08027634: .4byte 0x08318FC0
_08027638:
	ldr r0, _08027648 @ =0x08318F08
_0802763A:
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_08027648: .4byte 0x08318F08

	thumb_func_start SciserSetIdleGFX
SciserSetIdleGFX: @ 0x0802764C
	push {lr}
	ldr r2, _08027670 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r1, r2, #0
	cmp r0, #0
	beq _08027680
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027678
	ldr r0, _08027674 @ =0x083190A0
	b _08027696
	.align 2, 0
_08027670: .4byte gCurrentSprite
_08027674: .4byte 0x083190A0
_08027678:
	ldr r0, _0802767C @ =0x08319078
	b _08027696
	.align 2, 0
_0802767C: .4byte 0x08319078
_08027680:
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027694
	ldr r0, _08027690 @ =0x08318FE8
	b _08027696
	.align 2, 0
_08027690: .4byte 0x08318FE8
_08027694:
	ldr r0, _080276A4 @ =0x08318F30
_08027696:
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_080276A4: .4byte 0x08318F30

	thumb_func_start SciserCheckSamusInRange
SciserCheckSamusInRange: @ 0x080276A8
	push {r4, lr}
	ldr r4, _080276C8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802770C
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _080276CC
	subs r0, #1
	strb r0, [r1]
	b _0802770C
	.align 2, 0
_080276C8: .4byte gCurrentSprite
_080276CC:
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	beq _0802770C
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #0x2a
	strb r1, [r0]
	adds r0, #9
	ldrb r0, [r0]
	cmp r0, #0
	beq _080276F4
	ldr r0, _080276F0 @ =0x08319030
	b _080276F6
	.align 2, 0
_080276F0: .4byte 0x08319030
_080276F4:
	ldr r0, _08027714 @ =0x08318F78
_080276F6:
	str r0, [r4, #0x18]
	ldr r0, _08027718 @ =gCurrentSprite
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
	adds r0, #0x2e
	movs r1, #0x1e
	strb r1, [r0]
	ldr r0, _0802771C @ =0x00000161
	bl SoundPlayNotAlreadyPlaying
_0802770C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027714: .4byte 0x08318F78
_08027718: .4byte gCurrentSprite
_0802771C: .4byte 0x00000161

	thumb_func_start SciserShooting
SciserShooting: @ 0x08027720
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r2, _08027750 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802775C
	ldr r1, [r2, #0x18]
	ldr r0, _08027754 @ =0x08319030
	cmp r1, r0
	bne _08027798
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0802774C
	b _080278CA
_0802774C:
	ldr r0, _08027758 @ =0x08319000
	b _0802777A
	.align 2, 0
_08027750: .4byte gCurrentSprite
_08027754: .4byte 0x08319030
_08027758: .4byte 0x08319000
_0802775C:
	ldr r1, [r2, #0x18]
	ldr r0, _08027790 @ =0x08318F78
	cmp r1, r0
	bne _08027798
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08027778
	b _080278CA
_08027778:
	ldr r0, _08027794 @ =0x08318F48
_0802777A:
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	movs r0, #0x3c
	strb r0, [r3]
	movs r0, #0xb1
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _080278CA
	.align 2, 0
_08027790: .4byte 0x08318F78
_08027794: .4byte 0x08318F48
_08027798:
	ldr r5, _080277F0 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0x32
	beq _080277A6
	b _080278AC
_080277A6:
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r4, [r0]
	cmp r4, #0
	beq _08027826
	ldrh r1, [r5]
	movs r4, #0x40
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080277F4
	ldrb r2, [r5, #0x1f]
	adds r6, r5, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	subs r0, #0x30
	str r0, [sp]
	ldrh r0, [r5, #4]
	subs r0, #0x40
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #4
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r5, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	adds r0, #0x30
	str r0, [sp]
	ldrh r0, [r5, #4]
	subs r0, #0x40
	str r0, [sp, #4]
	str r4, [sp, #8]
	b _08027868
	.align 2, 0
_080277F0: .4byte gCurrentSprite
_080277F4:
	ldrb r2, [r5, #0x1f]
	adds r6, r5, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	subs r0, #0x30
	str r0, [sp]
	ldrh r0, [r5, #4]
	adds r0, #0x40
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #4
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r5, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	adds r0, #0x30
	str r0, [sp]
	ldrh r0, [r5, #4]
	adds r0, #0x40
	str r0, [sp, #4]
	str r4, [sp, #8]
	b _08027868
_08027826:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08027872
	ldrb r2, [r5, #0x1f]
	adds r6, r5, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	adds r0, #0x40
	str r0, [sp]
	ldrh r0, [r5, #4]
	subs r0, #0x30
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #4
	movs r1, #1
	bl SpriteSpawnSecondary
	ldrb r2, [r5, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	adds r0, #0x40
	str r0, [sp]
	ldrh r0, [r5, #4]
	adds r0, #0x30
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
_08027868:
	movs r0, #4
	movs r1, #1
	bl SpriteSpawnSecondary
	b _080278AC
_08027872:
	ldrb r2, [r5, #0x1f]
	adds r4, r5, #0
	adds r4, #0x23
	ldrb r3, [r4]
	ldrh r0, [r5, #2]
	subs r0, #0x40
	str r0, [sp]
	ldrh r0, [r5, #4]
	subs r0, #0x30
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #4
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r5, #0x1f]
	ldrb r3, [r4]
	ldrh r0, [r5, #2]
	subs r0, #0x40
	str r0, [sp]
	ldrh r0, [r5, #4]
	adds r0, #0x30
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
	movs r0, #4
	movs r1, #0
	bl SpriteSpawnSecondary
_080278AC:
	ldr r1, _080278D4 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080278CA
	adds r0, r1, #0
	adds r0, #0x24
	movs r1, #7
	strb r1, [r0]
	movs r0, #0x78
	strb r0, [r2]
_080278CA:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080278D4: .4byte gCurrentSprite

	thumb_func_start SciserTurningIntoX
SciserTurningIntoX: @ 0x080278D8
	push {lr}
	ldr r2, _080278F8 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027904
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080278FC
	ldrh r0, [r2, #4]
	subs r0, #0x28
	strh r0, [r2, #4]
	b _0802791C
	.align 2, 0
_080278F8: .4byte gCurrentSprite
_080278FC:
	ldrh r0, [r2, #4]
	adds r0, #0x28
	strh r0, [r2, #4]
	b _0802791C
_08027904:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027916
	ldrh r0, [r2, #2]
	adds r0, #0x28
	b _0802791A
_08027916:
	ldrh r0, [r2, #2]
	subs r0, #0x28
_0802791A:
	strh r0, [r2, #2]
_0802791C:
	pop {r0}
	bx r0

	thumb_func_start SciserInit
SciserInit: @ 0x08027920
	push {r4, r5, r6, r7, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r4, _0802793C @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0x59
	bne _08027940
	movs r0, #0x5a
	strb r0, [r5]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _080279FE
	.align 2, 0
_0802793C: .4byte gCurrentSprite
_08027940:
	bl SpriteUtilChooseRandomXDirection
	movs r0, #2
	strb r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08027968 @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	movs r7, #0xf0
	adds r5, r7, #0
	ands r5, r0
	cmp r5, #0
	beq _0802796C
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	b _080279FE
	.align 2, 0
_08027968: .4byte gPreviousCollisionCheck
_0802796C:
	ldrh r0, [r4, #2]
	subs r0, #0x44
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0802799A
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
	b _080279FE
_0802799A:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080279C6
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	strh r0, [r4, #4]
	b _080279FE
_080279C6:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r6]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0
	beq _080279FA
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	adds r0, #0x20
	strh r0, [r4, #4]
	b _080279FE
_080279FA:
	strh r2, [r4]
	b _08027A90
_080279FE:
	ldr r3, _08027A34 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08027A38
	ldrh r1, [r3]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	subs r1, #1
	movs r0, #3
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	b _08027A58
	.align 2, 0
_08027A34: .4byte gCurrentSprite
_08027A38:
	ldrh r1, [r3]
	ldr r0, _08027A98 @ =0x00007FFF
	ands r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x21
	strb r2, [r0]
	adds r0, #4
	strb r2, [r0]
	adds r1, #0x13
	movs r0, #1
	strb r0, [r1]
_08027A58:
	bl SciserSetCrawlingGFX
	bl SciserUpdateHitbox
	ldr r3, _08027A9C @ =gCurrentSprite
	ldr r2, _08027AA0 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r3, #0x14]
	adds r0, r3, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	subs r0, #9
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08027A90:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027A98: .4byte 0x00007FFF
_08027A9C: .4byte gCurrentSprite
_08027AA0: .4byte sPrimarySpriteStats

	thumb_func_start SciserCrawlingInit
SciserCrawlingInit: @ 0x08027AA4
	push {lr}
	bl SciserSetCrawlingGFX
	ldr r0, _08027AB8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08027AB8: .4byte gCurrentSprite

	thumb_func_start SciserCrawling
SciserCrawling: @ 0x08027ABC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r4, _08027AEC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r2, r4, #0
	cmp r0, #0
	beq _08027B38
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027AF4
	ldr r1, _08027AF0 @ =0x08317648
	b _08027AF6
	.align 2, 0
_08027AEC: .4byte gCurrentSprite
_08027AF0: .4byte 0x08317648
_08027AF4:
	ldr r1, _08027B18 @ =0x08317630
_08027AF6:
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsrs r0, r0, #3
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027B1C
	ldrh r0, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _08027B22
	.align 2, 0
_08027B18: .4byte 0x08317630
_08027B1C:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
_08027B22:
	adds r1, r2, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #0x5e
	bhi _08027B32
	adds r0, #1
	strb r0, [r1]
	b _08027E70
_08027B32:
	movs r0, #0
	strb r0, [r1]
	b _08027E70
_08027B38:
	movs r7, #0
	bl SciserCheckCollisions
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08027B4E
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x15
	strb r0, [r1]
	b _08027E70
_08027B4E:
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0
	bne _08027C30
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r4, #0xa]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldrh r0, [r4, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	ldrh r0, [r4, #0xe]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldrh r0, [r4, #0x10]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	movs r6, #0
	mov r8, r4
_08027B88:
	mov r0, r8
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r6, r0
	beq _08027BFA
	ldr r1, _08027C08 @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r5, r0, r1
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027BFA
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x82
	ands r0, r1
	cmp r0, #0
	bne _08027BFA
	ldrb r0, [r5, #0x1d]
	cmp r0, #0x3c
	beq _08027BBE
	cmp r0, #0x8b
	bne _08027BFA
_08027BBE:
	ldrh r3, [r5, #2]
	ldrh r4, [r5, #4]
	ldrh r2, [r5, #0xa]
	adds r2, r3, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r0, [r5, #0xc]
	adds r3, r3, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldrh r1, [r5, #0xe]
	adds r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r5, #0x10]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r2, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	mov r2, sl
	mov r3, sb
	bl SpriteUtilCheckObjectsTouching
	cmp r0, #0
	bne _08027C0C
_08027BFA:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x17
	bls _08027B88
	b _08027C34
	.align 2, 0
_08027C08: .4byte gSpriteData
_08027C0C:
	ldrh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r2, r1, #0
	eors r0, r2
	strh r0, [r5]
	adds r0, r5, #0
	adds r0, #0x2f
	movs r1, #0x78
	strb r1, [r0]
	mov r3, r8
	ldrh r0, [r3]
	eors r0, r2
	strh r0, [r3]
	mov r0, r8
	adds r0, #0x2f
	strb r1, [r0]
	b _08027C34
_08027C30:
	subs r0, #1
	strb r0, [r1]
_08027C34:
	ldr r4, _08027C78 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _08027C42
	b _08027D48
_08027C42:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08027CC0
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027C80
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027C7C @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _08027C6E
	b _08027E40
_08027C6E:
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	b _08027CEA
	.align 2, 0
_08027C78: .4byte gCurrentSprite
_08027C7C: .4byte gPreviousCollisionCheck
_08027C80:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027CBC @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _08027C98
	b _08027E40
_08027C98:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08027CB0
	b _08027E40
_08027CB0:
	ldrh r0, [r4, #2]
	movs r1, #1
	subs r0, r0, r1
	strh r0, [r4, #2]
	b _08027E54
	.align 2, 0
_08027CBC: .4byte gPreviousCollisionCheck
_08027CC0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027D08
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027D04 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _08027CE4
	b _08027E40
_08027CE4:
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
_08027CEA:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08027CFA
	b _08027E40
_08027CFA:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	b _08027E54
	.align 2, 0
_08027D04: .4byte gPreviousCollisionCheck
_08027D08:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027D44 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _08027D22
	b _08027E40
_08027D22:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08027D38
	b _08027E40
_08027D38:
	ldrh r0, [r4, #2]
	movs r2, #1
	subs r0, r0, r2
	strh r0, [r4, #2]
	b _08027E54
	.align 2, 0
_08027D44: .4byte gPreviousCollisionCheck
_08027D48:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027DD4
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027D98
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027D94 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08027E40
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08027E40
	ldrh r0, [r4, #4]
	adds r0, #1
	b _08027E52
	.align 2, 0
_08027D94: .4byte gPreviousCollisionCheck
_08027D98:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027DD0 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08027E40
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08027E40
	ldrh r0, [r4, #4]
	movs r3, #1
	subs r0, r0, r3
	b _08027E52
	.align 2, 0
_08027DD0: .4byte gPreviousCollisionCheck
_08027DD4:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08027E14
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027E10 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _08027E40
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08027E40
	ldrh r0, [r4, #4]
	adds r0, #1
	b _08027E52
	.align 2, 0
_08027E10: .4byte gPreviousCollisionCheck
_08027E14:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08027E48 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _08027E40
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08027E4C
_08027E40:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	b _08027E54
	.align 2, 0
_08027E48: .4byte gPreviousCollisionCheck
_08027E4C:
	ldrh r0, [r4, #4]
	movs r1, #1
	subs r0, r0, r1
_08027E52:
	strh r0, [r4, #4]
_08027E54:
	cmp r7, #0
	beq _08027E6C
	ldr r2, _08027E80 @ =gCurrentSprite
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
_08027E6C:
	bl SciserCheckSamusInRange
_08027E70:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027E80: .4byte gCurrentSprite

	thumb_func_start SciserIdleInit
SciserIdleInit: @ 0x08027E84
	push {lr}
	ldr r0, _08027E98 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #8
	strb r1, [r0]
	bl SciserSetIdleGFX
	pop {r0}
	bx r0
	.align 2, 0
_08027E98: .4byte gCurrentSprite

	thumb_func_start SciserIdle
SciserIdle: @ 0x08027E9C
	push {lr}
	bl SciserCheckCollisions
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08027EB4
	ldr r0, _08027EB0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	b _08027EC2
	.align 2, 0
_08027EB0: .4byte gCurrentSprite
_08027EB4:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _08027EC4
	ldr r0, _08027EC8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
_08027EC2:
	strb r1, [r0]
_08027EC4:
	pop {r0}
	bx r0
	.align 2, 0
_08027EC8: .4byte gCurrentSprite

	thumb_func_start SciserFallingInit
SciserFallingInit: @ 0x08027ECC
	push {lr}
	ldr r1, _08027EE8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r1, #0x31
	strb r3, [r1]
	bl SciserSetIdleGFX
	pop {r0}
	bx r0
	.align 2, 0
_08027EE8: .4byte gCurrentSprite

	thumb_func_start SciserFalling
SciserFalling: @ 0x08027EEC
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r2, _08027F14 @ =gCurrentSprite
	ldrh r3, [r2, #2]
	ldrh r4, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027F18
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08027F24
	subs r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08027F24
	.align 2, 0
_08027F14: .4byte gCurrentSprite
_08027F18:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027F2C
_08027F24:
	ldrh r0, [r2, #0xc]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08027F2C:
	adds r0, r3, #0
	adds r1, r4, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08027F78 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027FBE
	ldr r4, _08027F7C @ =gCurrentSprite
	strh r1, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x2d
	ldrb r0, [r2]
	cmp r0, #0
	beq _08027F52
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08027F52:
	ldrh r0, [r4]
	ldr r1, _08027F80 @ =0x0000FEFF
	ands r1, r0
	strh r1, [r4]
	movs r0, #0
	strb r0, [r2]
	bl SciserUpdateHitbox
	cmp r5, #0
	beq _08027F8C
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08027F84
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0x10]
	b _08027F88
	.align 2, 0
_08027F78: .4byte gPreviousVerticalCollisionCheck
_08027F7C: .4byte gCurrentSprite
_08027F80: .4byte 0x0000FEFF
_08027F84:
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0xe]
_08027F88:
	subs r0, r0, r1
	strh r0, [r4, #4]
_08027F8C:
	ldr r2, _08027FAC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08027FB0
	adds r0, r2, #0
	adds r0, #0x24
	strb r3, [r0]
	bl SciserSetCrawlingGFX
	b _08028000
	.align 2, 0
_08027FAC: .4byte gCurrentSprite
_08027FB0:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	bl SciserSetIdleGFX
	b _08028000
_08027FBE:
	ldr r3, _08027FE8 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _08027FEC @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08027FF0 @ =0x00007FFF
	cmp r1, r0
	bne _08027FF4
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08027FFE
	.align 2, 0
_08027FE8: .4byte gCurrentSprite
_08027FEC: .4byte sSpritesFallingSpeed
_08027FF0: .4byte 0x00007FFF
_08027FF4:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_08027FFE:
	strh r0, [r3, #2]
_08028000:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SciserProjectileInit
SciserProjectileInit: @ 0x08028008
	push {r4, lr}
	ldr r0, _0802806C @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08028070 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _08028074 @ =0x0000FFF8
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _08028078 @ =0x08318EF0
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r0, ip
	adds r0, #0x31
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r1, #3
	movs r0, #3
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802806C: .4byte gCurrentSprite
_08028070: .4byte 0x0000FFFB
_08028074: .4byte 0x0000FFF8
_08028078: .4byte 0x08318EF0

	thumb_func_start SciserProjectileFalling
SciserProjectileFalling: @ 0x0802807C
	push {r4, r5, r6, lr}
	ldr r1, _080280A4 @ =gCurrentClipdataAffectingAction
	movs r0, #5
	strb r0, [r1]
	ldr r4, _080280A8 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080280AC @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080280B0
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _08028152
	.align 2, 0
_080280A4: .4byte gCurrentClipdataAffectingAction
_080280A8: .4byte gCurrentSprite
_080280AC: .4byte gPreviousCollisionCheck
_080280B0:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080280F8
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _080280E0 @ =0x08317692
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _080280E4 @ =0x00007FFF
	cmp r1, r0
	bne _080280E8
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _080280F2
	.align 2, 0
_080280E0: .4byte 0x08317692
_080280E4: .4byte 0x00007FFF
_080280E8:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
_080280F2:
	strh r0, [r4, #2]
	movs r3, #8
	b _08028136
_080280F8:
	movs r6, #0x31
	adds r6, r6, r4
	mov ip, r6
	ldrb r2, [r6]
	ldr r5, _08028120 @ =0x08317660
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08028124 @ =0x00007FFF
	cmp r1, r0
	bne _08028128
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08028132
	.align 2, 0
_08028120: .4byte 0x08317660
_08028124: .4byte 0x00007FFF
_08028128:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
_08028132:
	strh r0, [r4, #2]
	movs r3, #4
_08028136:
	ldr r2, _08028148 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802814C
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	b _08028150
	.align 2, 0
_08028148: .4byte gCurrentSprite
_0802814C:
	ldrh r0, [r2, #4]
	subs r0, r0, r3
_08028150:
	strh r0, [r2, #4]
_08028152:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start SciserProjectileExplodingInit
SciserProjectileExplodingInit: @ 0x08028158
	push {lr}
	ldr r3, _08028188 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x21
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0802818C @ =gFrameCounter8Bit
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08028194
	ldr r0, _08028190 @ =0x083190C8
	b _08028196
	.align 2, 0
_08028188: .4byte gCurrentSprite
_0802818C: .4byte gSpriteRandomNumber
_08028190: .4byte 0x083190C8
_08028194:
	ldr r0, _0802819C @ =0x083190F0
_08028196:
	str r0, [r3, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_0802819C: .4byte 0x083190F0

	thumb_func_start SciserProjectileExploding
SciserProjectileExploding: @ 0x080281A0
	push {r4, lr}
	ldr r4, _080281C0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080281B8
	movs r0, #0
	strh r0, [r4]
_080281B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080281C0: .4byte gCurrentSprite

	thumb_func_start Sciser
Sciser: @ 0x080281C4
	push {lr}
	ldr r2, _080281E4 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _080281F2
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x8b
	bne _080281EC
	ldr r0, _080281E8 @ =0x000001B1
	bl SoundPlayNotAlreadyPlaying
	b _080281F2
	.align 2, 0
_080281E4: .4byte gCurrentSprite
_080281E8: .4byte 0x000001B1
_080281EC:
	ldr r0, _08028204 @ =0x00000163
	bl SoundPlayNotAlreadyPlaying
_080281F2:
	ldr r1, _08028208 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802820C
	bl SpriteUtilUpdateFreezeTimer
	b _080283DE
	.align 2, 0
_08028204: .4byte 0x00000163
_08028208: .4byte gCurrentSprite
_0802820C:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08028218
	b _080283DE
_08028218:
	lsls r0, r0, #2
	ldr r1, _08028224 @ =_08028228
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028224: .4byte _08028228
_08028228: @ jump table
	.4byte _08028398 @ case 0
	.4byte _0802839E @ case 1
	.4byte _080283A2 @ case 2
	.4byte _080283DE @ case 3
	.4byte _080283DE @ case 4
	.4byte _080283DE @ case 5
	.4byte _080283DE @ case 6
	.4byte _080283A8 @ case 7
	.4byte _080283AC @ case 8
	.4byte _080283DE @ case 9
	.4byte _080283DE @ case 10
	.4byte _080283DE @ case 11
	.4byte _080283DE @ case 12
	.4byte _080283DE @ case 13
	.4byte _080283DE @ case 14
	.4byte _080283DE @ case 15
	.4byte _080283DE @ case 16
	.4byte _080283DE @ case 17
	.4byte _080283DE @ case 18
	.4byte _080283DE @ case 19
	.4byte _080283DE @ case 20
	.4byte _080283B2 @ case 21
	.4byte _080283B6 @ case 22
	.4byte _080283DE @ case 23
	.4byte _080283DE @ case 24
	.4byte _080283DE @ case 25
	.4byte _080283DE @ case 26
	.4byte _080283DE @ case 27
	.4byte _080283DE @ case 28
	.4byte _080283DE @ case 29
	.4byte _080283DE @ case 30
	.4byte _080283DE @ case 31
	.4byte _080283DE @ case 32
	.4byte _080283DE @ case 33
	.4byte _080283DE @ case 34
	.4byte _080283DE @ case 35
	.4byte _080283DE @ case 36
	.4byte _080283DE @ case 37
	.4byte _080283DE @ case 38
	.4byte _080283DE @ case 39
	.4byte _080283DE @ case 40
	.4byte _080283DE @ case 41
	.4byte _080283BC @ case 42
	.4byte _080283DE @ case 43
	.4byte _080283DE @ case 44
	.4byte _080283DE @ case 45
	.4byte _080283DE @ case 46
	.4byte _080283DE @ case 47
	.4byte _080283DE @ case 48
	.4byte _080283DE @ case 49
	.4byte _080283DE @ case 50
	.4byte _080283DE @ case 51
	.4byte _080283DE @ case 52
	.4byte _080283DE @ case 53
	.4byte _080283DE @ case 54
	.4byte _080283DE @ case 55
	.4byte _080283DE @ case 56
	.4byte _080283DE @ case 57
	.4byte _080283DE @ case 58
	.4byte _080283DE @ case 59
	.4byte _080283DE @ case 60
	.4byte _080283DE @ case 61
	.4byte _080283DE @ case 62
	.4byte _080283DE @ case 63
	.4byte _080283DE @ case 64
	.4byte _080283DE @ case 65
	.4byte _080283DE @ case 66
	.4byte _080283DE @ case 67
	.4byte _080283DE @ case 68
	.4byte _080283DE @ case 69
	.4byte _080283DE @ case 70
	.4byte _080283DE @ case 71
	.4byte _080283DE @ case 72
	.4byte _080283DE @ case 73
	.4byte _080283DE @ case 74
	.4byte _080283DE @ case 75
	.4byte _080283DE @ case 76
	.4byte _080283DE @ case 77
	.4byte _080283DE @ case 78
	.4byte _080283DE @ case 79
	.4byte _080283DE @ case 80
	.4byte _080283DE @ case 81
	.4byte _080283DE @ case 82
	.4byte _080283DE @ case 83
	.4byte _080283DE @ case 84
	.4byte _080283DE @ case 85
	.4byte _080283DE @ case 86
	.4byte _080283C2 @ case 87
	.4byte _080283C6 @ case 88
	.4byte _080283CC @ case 89
	.4byte _080283D0 @ case 90
	.4byte _080283D6 @ case 91
_08028398:
	bl SciserInit
	b _080283DE
_0802839E:
	bl SciserCrawlingInit
_080283A2:
	bl SciserCrawling
	b _080283DE
_080283A8:
	bl SciserIdleInit
_080283AC:
	bl SciserIdle
	b _080283DE
_080283B2:
	bl SciserFallingInit
_080283B6:
	bl SciserFalling
	b _080283DE
_080283BC:
	bl SciserShooting
	b _080283DE
_080283C2:
	bl SpriteDyingInit
_080283C6:
	bl SpriteDying
	b _080283DE
_080283CC:
	bl SciserInit
_080283D0:
	bl SpriteSpawningFromX
	b _080283DE
_080283D6:
	bl SciserTurningIntoX
	bl XParasiteInit
_080283DE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SciserProjectile
SciserProjectile: @ 0x080283E4
	push {lr}
	ldr r0, _080283FC @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0802840A
	cmp r0, #2
	bgt _08028400
	cmp r0, #0
	beq _08028406
	b _08028416
	.align 2, 0
_080283FC: .4byte gCurrentSprite
_08028400:
	cmp r0, #0x38
	beq _08028410
	b _08028416
_08028406:
	bl SciserProjectileInit
_0802840A:
	bl SciserProjectileFalling
	b _0802841A
_08028410:
	bl SciserProjectileExploding
	b _0802841A
_08028416:
	bl SciserProjectileExplodingInit
_0802841A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SidehopperCheckSamusInRange
SidehopperCheckSamusInRange: @ 0x08028420
	push {r4, lr}
	movs r4, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	beq _08028438
	movs r4, #1
	bl SpriteUtilMakeSpriteFaceSamusDirection
_08028438:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start SidehopperInit
SidehopperInit: @ 0x08028440
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0802846C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08028470
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08028470
	strh r0, [r2]
	b _0802853A
	.align 2, 0
_0802846C: .4byte gCurrentSprite
_08028470:
	ldr r1, _08028488 @ =gCurrentSprite
	adds r5, r1, #0
	adds r5, #0x24
	ldrb r0, [r5]
	adds r4, r1, #0
	cmp r0, #0x59
	bne _0802848C
	movs r0, #0x5a
	strb r0, [r5]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _080284C0
	.align 2, 0
_08028488: .4byte gCurrentSprite
_0802848C:
	ldrh r0, [r4, #2]
	subs r0, #0x44
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080284E4 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080284B4
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
_080284B4:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0
	strb r0, [r1]
	movs r0, #8
	strb r0, [r5]
_080284C0:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080284EC
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	movs r0, #0x58
	strh r0, [r4, #0xc]
	ldr r0, _080284E8 @ =0x0000FFE0
	strh r0, [r4, #0xa]
	b _08028502
	.align 2, 0
_080284E4: .4byte gPreviousCollisionCheck
_080284E8: .4byte 0x0000FFE0
_080284EC:
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08028540 @ =0x0000FFA8
	strh r0, [r4, #0xa]
	movs r0, #0x20
	strh r0, [r4, #0xc]
_08028502:
	adds r1, r4, #0
	adds r1, #0x29
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0
	ldr r0, _08028544 @ =0x0000FFC0
	strh r0, [r4, #0xe]
	movs r0, #0x40
	strh r0, [r4, #0x10]
	ldr r0, _08028548 @ =0x0831ACA0
	str r0, [r4, #0x18]
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	ldr r2, _0802854C @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	bl SpriteUtilChooseRandomXDirection
_0802853A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08028540: .4byte 0x0000FFA8
_08028544: .4byte 0x0000FFC0
_08028548: .4byte 0x0831ACA0
_0802854C: .4byte sPrimarySpriteStats

	thumb_func_start SidehopperPreparingtoJumpInit
SidehopperPreparingtoJumpInit: @ 0x08028550
	ldr r1, _08028568 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0802856C @ =0x0831AD10
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_08028568: .4byte gCurrentSprite
_0802856C: .4byte 0x0831AD10

	thumb_func_start SidehopperJumpingInit
SidehopperJumpingInit: @ 0x08028570
	push {r4, lr}
	ldr r3, _080285A4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r4, #0
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x31
	strb r4, [r0]
	ldr r0, _080285A8 @ =0x0831AD30
	str r0, [r3, #0x18]
	ldr r0, _080285AC @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080285B0
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	b _080285B6
	.align 2, 0
_080285A4: .4byte gCurrentSprite
_080285A8: .4byte 0x0831AD30
_080285AC: .4byte gSpriteRandomNumber
_080285B0:
	adds r0, r3, #0
	adds r0, #0x30
	strb r4, [r0]
_080285B6:
	movs r0, #0xbd
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start SidehopperLandingInit
SidehopperLandingInit: @ 0x080285C4
	push {lr}
	ldr r1, _080285E4 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x1a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _080285E8 @ =0x0831AD50
	str r0, [r1, #0x18]
	ldr r0, _080285EC @ =0x0000017B
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_080285E4: .4byte gCurrentSprite
_080285E8: .4byte 0x0831AD50
_080285EC: .4byte 0x0000017B

	thumb_func_start SidehopperIdle
SidehopperIdle: @ 0x080285F0
	push {lr}
	bl SidehopperCheckSamusInRange
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08028604
	bl SidehopperPreparingtoJumpInit
	b _0802864C
_08028604:
	ldr r2, _0802863C @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	strb r3, [r2, #0x1c]
	movs r0, #0
	strh r3, [r2, #0x16]
	adds r1, #0xa
	strb r0, [r1]
	ldr r0, _08028640 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r3, r2, #0
	adds r3, #0x2f
	strb r0, [r3]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #7
	bls _08028648
	ldr r0, _08028644 @ =0x0831ACC8
	str r0, [r2, #0x18]
	movs r0, #0xbe
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0802864C
	.align 2, 0
_0802863C: .4byte gCurrentSprite
_08028640: .4byte gSpriteRandomNumber
_08028644: .4byte 0x0831ACC8
_08028648:
	ldr r0, _08028650 @ =0x0831ACA0
	str r0, [r2, #0x18]
_0802864C:
	pop {r0}
	bx r0
	.align 2, 0
_08028650: .4byte 0x0831ACA0

	thumb_func_start SidehopperFallingInit
SidehopperFallingInit: @ 0x08028654
	ldr r3, _08028670 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x16
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r0, #0
	strh r2, [r3, #0x16]
	adds r1, #0xd
	strb r0, [r1]
	ldr r0, _08028674 @ =0x0831AD30
	str r0, [r3, #0x18]
	bx lr
	.align 2, 0
_08028670: .4byte gCurrentSprite
_08028674: .4byte 0x0831AD30

	thumb_func_start SidehopperPreparingToJumpGround
SidehopperPreparingToJumpGround: @ 0x08028678
	push {r4, r5, lr}
	ldr r4, _080286B8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _080286CC
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _080286BC @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _080286C0
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _080286C0
	bl SidehopperFallingInit
	b _080286CC
	.align 2, 0
_080286B8: .4byte gCurrentSprite
_080286BC: .4byte gPreviousCollisionCheck
_080286C0:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080286CC
	bl SidehopperJumpingInit
_080286CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SidehopperPreparingToJumpCeiling
SidehopperPreparingToJumpCeiling: @ 0x080286D4
	push {lr}
	ldr r0, _080286F4 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _080286F0
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080286F0
	bl SidehopperJumpingInit
_080286F0:
	pop {r0}
	bx r0
	.align 2, 0
_080286F4: .4byte gCurrentSprite

	thumb_func_start SidehopperJumpingGround
SidehopperJumpingGround: @ 0x080286F8
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r2, _0802870C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _08028714
	ldr r1, _08028710 @ =0x0831A16C
	b _08028716
	.align 2, 0
_0802870C: .4byte gCurrentSprite
_08028710: .4byte 0x0831A16C
_08028714:
	ldr r1, _08028758 @ =0x0831A158
_08028716:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	ldr r4, _0802875C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08028778
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	adds r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08028760 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08028764
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	b _0802879C
	.align 2, 0
_08028758: .4byte 0x0831A158
_0802875C: .4byte gCurrentSprite
_08028760: .4byte gPreviousCollisionCheck
_08028764:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _08028772
	ldrh r0, [r4, #4]
	adds r0, #4
	b _080287BA
_08028772:
	ldrh r0, [r4, #4]
	adds r0, #5
	b _080287BA
_08028778:
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080287A4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080287A8
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
_0802879C:
	strh r0, [r4, #4]
	lsls r1, r5, #0x10
	b _080287BC
	.align 2, 0
_080287A4: .4byte gPreviousCollisionCheck
_080287A8:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _080287B6
	ldrh r0, [r4, #4]
	subs r0, #4
	b _080287BA
_080287B6:
	ldrh r0, [r4, #4]
	subs r0, #5
_080287BA:
	strh r0, [r4, #4]
_080287BC:
	ldr r4, _08028800 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r0, [r2]
	cmp r0, #0x26
	bhi _080287D2
	adds r0, #1
	strb r0, [r2]
_080287D2:
	cmp r1, #0
	ble _0802884C
	cmp r6, #0
	beq _080287E6
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r4]
_080287E6:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _08028804 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	beq _08028808
	strh r1, [r4, #2]
	bl SidehopperLandingInit
	b _080288CA
	.align 2, 0
_08028800: .4byte gCurrentSprite
_08028804: .4byte gPreviousVerticalCollisionCheck
_08028808:
	cmp r6, #0
	bne _080288CA
	ldrh r0, [r4, #2]
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802883E
	ldrh r0, [r4, #2]
	movs r3, #0xe
	ldrsh r1, [r4, r3]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802883A
	movs r6, #1
_0802883A:
	cmp r6, #0
	beq _080288CA
_0802883E:
	ldr r0, _08028848 @ =gCurrentSprite
	strh r1, [r0, #2]
	bl SidehopperLandingInit
	b _080288CA
	.align 2, 0
_08028848: .4byte gCurrentSprite
_0802884C:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802888C
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08028888 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080288B8
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	strh r0, [r4, #4]
	bl SidehopperFallingInit
	b _080288B8
	.align 2, 0
_08028888: .4byte gPreviousCollisionCheck
_0802888C:
	movs r3, #0xa
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080288D0 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080288B8
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
	strh r0, [r4, #4]
	bl SidehopperFallingInit
_080288B8:
	cmp r6, #0
	beq _080288CA
	ldr r0, _080288D4 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	eors r1, r2
	strh r1, [r0]
_080288CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080288D0: .4byte gPreviousCollisionCheck
_080288D4: .4byte gCurrentSprite

	thumb_func_start SidehopperJumpingCeiling
SidehopperJumpingCeiling: @ 0x080288D8
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r2, _080288EC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _080288F4
	ldr r1, _080288F0 @ =0x0831A16C
	b _080288F6
	.align 2, 0
_080288EC: .4byte gCurrentSprite
_080288F0: .4byte 0x0831A16C
_080288F4:
	ldr r1, _08028938 @ =0x0831A158
_080288F6:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	ldr r4, _0802893C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08028958
	ldrh r0, [r4, #2]
	adds r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	adds r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08028940 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08028944
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	b _0802897C
	.align 2, 0
_08028938: .4byte 0x0831A158
_0802893C: .4byte gCurrentSprite
_08028940: .4byte gPreviousCollisionCheck
_08028944:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _08028952
	ldrh r0, [r4, #4]
	adds r0, #4
	b _0802899A
_08028952:
	ldrh r0, [r4, #4]
	adds r0, #5
	b _0802899A
_08028958:
	ldrh r0, [r4, #2]
	adds r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08028984 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08028988
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
_0802897C:
	strh r0, [r4, #4]
	lsls r1, r5, #0x10
	b _0802899C
	.align 2, 0
_08028984: .4byte gPreviousCollisionCheck
_08028988:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _08028996
	ldrh r0, [r4, #4]
	subs r0, #4
	b _0802899A
_08028996:
	ldrh r0, [r4, #4]
	subs r0, #5
_0802899A:
	strh r0, [r4, #4]
_0802899C:
	ldr r4, _080289F0 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, r0, r5
	strh r0, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r0, [r2]
	cmp r0, #0x26
	bhi _080289B2
	adds r0, #1
	strb r0, [r2]
_080289B2:
	cmp r1, #0
	bge _08028A40
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080289F8
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080289F4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08028A24
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	strh r0, [r4, #4]
	bl SidehopperFallingInit
	b _08028A24
	.align 2, 0
_080289F0: .4byte gCurrentSprite
_080289F4: .4byte gPreviousCollisionCheck
_080289F8:
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08028A38 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08028A24
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
	strh r0, [r4, #4]
	bl SidehopperFallingInit
_08028A24:
	cmp r7, #0
	beq _08028AC2
	ldr r0, _08028A3C @ =gCurrentSprite
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	eors r1, r2
	strh r1, [r0]
	b _08028AC2
	.align 2, 0
_08028A38: .4byte gPreviousCollisionCheck
_08028A3C: .4byte gCurrentSprite
_08028A40:
	cmp r7, #0
	beq _08028A50
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r4]
_08028A50:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r5, _08028A74 @ =gPreviousVerticalCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08028A78
	adds r0, r2, #0
	adds r0, #0x40
	strh r0, [r4, #2]
	bl SidehopperLandingInit
	b _08028AC2
	.align 2, 0
_08028A74: .4byte gPreviousVerticalCollisionCheck
_08028A78:
	cmp r7, #0
	bne _08028AC2
	ldrh r0, [r4, #2]
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08028AB6
	ldrh r0, [r4, #2]
	movs r3, #0xe
	ldrsh r1, [r4, r3]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08028AB2
	movs r7, #1
_08028AB2:
	cmp r7, #0
	beq _08028AC2
_08028AB6:
	ldr r1, _08028AC8 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x40
	strh r0, [r1, #2]
	bl SidehopperLandingInit
_08028AC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028AC8: .4byte gCurrentSprite

	thumb_func_start SidehopperLanding
SidehopperLanding: @ 0x08028ACC
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08028ADA
	bl SidehopperIdle
_08028ADA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SidehopperFallingGround
SidehopperFallingGround: @ 0x08028AE0
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r4, _08028B34 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _08028B38 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08028B2A
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08028B2A
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08028B26
	movs r6, #1
_08028B26:
	cmp r6, #0
	beq _08028B3C
_08028B2A:
	ldr r0, _08028B34 @ =gCurrentSprite
	strh r1, [r0, #2]
	bl SidehopperLandingInit
	b _08028B7C
	.align 2, 0
_08028B34: .4byte gCurrentSprite
_08028B38: .4byte gPreviousVerticalCollisionCheck
_08028B3C:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _08028B68 @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08028B6C @ =0x00007FFF
	cmp r1, r0
	bne _08028B70
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _08028B7C
	.align 2, 0
_08028B68: .4byte sSpritesFallingSpeed
_08028B6C: .4byte 0x00007FFF
_08028B70:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_08028B7C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SidehopperFallingCeiling
SidehopperFallingCeiling: @ 0x08028B84
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r4, _08028BDC @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r5, _08028BE0 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08028BCE
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08028BCE
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08028BCA
	movs r6, #1
_08028BCA:
	cmp r6, #0
	beq _08028BE4
_08028BCE:
	ldr r1, _08028BDC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x40
	strh r0, [r1, #2]
	bl SidehopperLandingInit
	b _08028C24
	.align 2, 0
_08028BDC: .4byte gCurrentSprite
_08028BE0: .4byte gPreviousVerticalCollisionCheck
_08028BE4:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _08028C10 @ =sSpritesFallingSpeedCeiling
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08028C14 @ =0x00007FFF
	cmp r1, r0
	bne _08028C18
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _08028C24
	.align 2, 0
_08028C10: .4byte sSpritesFallingSpeedCeiling
_08028C14: .4byte 0x00007FFF
_08028C18:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_08028C24:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SidehopperIdleGround
SidehopperIdleGround: @ 0x08028C2C
	push {r4, r5, lr}
	bl SidehopperCheckSamusInRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08028C96
	ldr r4, _08028C6C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08028C70 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08028C74
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _08028C74
	bl SidehopperFallingInit
	b _08028CB0
	.align 2, 0
_08028C6C: .4byte gCurrentSprite
_08028C70: .4byte gPreviousCollisionCheck
_08028C74:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08028CB0
	ldr r2, _08028C9C @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	adds r1, r2, #0
	adds r1, #0x2f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _08028CA0
_08028C96:
	bl SidehopperPreparingtoJumpInit
	b _08028CB0
	.align 2, 0
_08028C9C: .4byte gCurrentSprite
_08028CA0:
	ldr r1, [r2, #0x18]
	ldr r0, _08028CB8 @ =0x0831ACC8
	cmp r1, r0
	bne _08028CB0
	movs r0, #0xbe
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08028CB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08028CB8: .4byte 0x0831ACC8

	thumb_func_start SidehopperIdleCeiling
SidehopperIdleCeiling: @ 0x08028CBC
	push {lr}
	bl SidehopperCheckSamusInRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08028CEA
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08028D04
	ldr r2, _08028CF0 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	adds r1, r2, #0
	adds r1, #0x2f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _08028CF4
_08028CEA:
	bl SidehopperPreparingtoJumpInit
	b _08028D04
	.align 2, 0
_08028CF0: .4byte gCurrentSprite
_08028CF4:
	ldr r1, [r2, #0x18]
	ldr r0, _08028D08 @ =0x0831ACC8
	cmp r1, r0
	bne _08028D04
	movs r0, #0xbe
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08028D04:
	pop {r0}
	bx r0
	.align 2, 0
_08028D08: .4byte 0x0831ACC8

	thumb_func_start Sidehopper
Sidehopper: @ 0x08028D0C
	push {r4, lr}
	ldr r4, _08028D34 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08028D24
	ldr r0, _08028D38 @ =0x0000017D
	bl SoundPlayNotAlreadyPlaying
_08028D24:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08028D3C
	bl SpriteUtilUpdateFreezeTimer
	b _08028F8E
	.align 2, 0
_08028D34: .4byte gCurrentSprite
_08028D38: .4byte 0x0000017D
_08028D3C:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08028D48
	b _08028F8E
_08028D48:
	lsls r0, r0, #2
	ldr r1, _08028D54 @ =_08028D58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028D54: .4byte _08028D58
_08028D58: @ jump table
	.4byte _08028EC8 @ case 0
	.4byte _08028ECE @ case 1
	.4byte _08028ED2 @ case 2
	.4byte _08028F8E @ case 3
	.4byte _08028F8E @ case 4
	.4byte _08028F8E @ case 5
	.4byte _08028F8E @ case 6
	.4byte _08028F8E @ case 7
	.4byte _08028F18 @ case 8
	.4byte _08028F8E @ case 9
	.4byte _08028F8E @ case 10
	.4byte _08028F8E @ case 11
	.4byte _08028F8E @ case 12
	.4byte _08028F8E @ case 13
	.4byte _08028F8E @ case 14
	.4byte _08028F8E @ case 15
	.4byte _08028F8E @ case 16
	.4byte _08028F8E @ case 17
	.4byte _08028F8E @ case 18
	.4byte _08028F8E @ case 19
	.4byte _08028F8E @ case 20
	.4byte _08028F8E @ case 21
	.4byte _08028F36 @ case 22
	.4byte _08028F8E @ case 23
	.4byte _08028EF2 @ case 24
	.4byte _08028F8E @ case 25
	.4byte _08028F12 @ case 26
	.4byte _08028F8E @ case 27
	.4byte _08028F8E @ case 28
	.4byte _08028F8E @ case 29
	.4byte _08028F8E @ case 30
	.4byte _08028F8E @ case 31
	.4byte _08028F8E @ case 32
	.4byte _08028F8E @ case 33
	.4byte _08028F8E @ case 34
	.4byte _08028F8E @ case 35
	.4byte _08028F8E @ case 36
	.4byte _08028F8E @ case 37
	.4byte _08028F8E @ case 38
	.4byte _08028F8E @ case 39
	.4byte _08028F8E @ case 40
	.4byte _08028F8E @ case 41
	.4byte _08028F8E @ case 42
	.4byte _08028F8E @ case 43
	.4byte _08028F8E @ case 44
	.4byte _08028F8E @ case 45
	.4byte _08028F8E @ case 46
	.4byte _08028F8E @ case 47
	.4byte _08028F8E @ case 48
	.4byte _08028F8E @ case 49
	.4byte _08028F8E @ case 50
	.4byte _08028F8E @ case 51
	.4byte _08028F8E @ case 52
	.4byte _08028F8E @ case 53
	.4byte _08028F8E @ case 54
	.4byte _08028F8E @ case 55
	.4byte _08028F8E @ case 56
	.4byte _08028F8E @ case 57
	.4byte _08028F8E @ case 58
	.4byte _08028F8E @ case 59
	.4byte _08028F8E @ case 60
	.4byte _08028F8E @ case 61
	.4byte _08028F8E @ case 62
	.4byte _08028F8E @ case 63
	.4byte _08028F8E @ case 64
	.4byte _08028F8E @ case 65
	.4byte _08028F8E @ case 66
	.4byte _08028F8E @ case 67
	.4byte _08028F8E @ case 68
	.4byte _08028F8E @ case 69
	.4byte _08028F8E @ case 70
	.4byte _08028F8E @ case 71
	.4byte _08028F8E @ case 72
	.4byte _08028F8E @ case 73
	.4byte _08028F8E @ case 74
	.4byte _08028F8E @ case 75
	.4byte _08028F8E @ case 76
	.4byte _08028F8E @ case 77
	.4byte _08028F8E @ case 78
	.4byte _08028F8E @ case 79
	.4byte _08028F8E @ case 80
	.4byte _08028F8E @ case 81
	.4byte _08028F8E @ case 82
	.4byte _08028F8E @ case 83
	.4byte _08028F8E @ case 84
	.4byte _08028F8E @ case 85
	.4byte _08028F8E @ case 86
	.4byte _08028F56 @ case 87
	.4byte _08028F5A @ case 88
	.4byte _08028F60 @ case 89
	.4byte _08028F64 @ case 90
	.4byte _08028F6A @ case 91
_08028EC8:
	bl SidehopperInit
	b _08028F8E
_08028ECE:
	bl SidehopperPreparingtoJumpInit
_08028ED2:
	ldr r0, _08028EE8 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028EEC
	bl SidehopperPreparingToJumpCeiling
	b _08028F8E
	.align 2, 0
_08028EE8: .4byte gCurrentSprite
_08028EEC:
	bl SidehopperPreparingToJumpGround
	b _08028F8E
_08028EF2:
	ldr r0, _08028F08 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028F0C
	bl SidehopperJumpingCeiling
	b _08028F8E
	.align 2, 0
_08028F08: .4byte gCurrentSprite
_08028F0C:
	bl SidehopperJumpingGround
	b _08028F8E
_08028F12:
	bl SidehopperLanding
	b _08028F8E
_08028F18:
	ldr r0, _08028F2C @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028F30
	bl SidehopperIdleCeiling
	b _08028F8E
	.align 2, 0
_08028F2C: .4byte gCurrentSprite
_08028F30:
	bl SidehopperIdleGround
	b _08028F8E
_08028F36:
	ldr r0, _08028F4C @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028F50
	bl SidehopperFallingCeiling
	b _08028F8E
	.align 2, 0
_08028F4C: .4byte gCurrentSprite
_08028F50:
	bl SidehopperFallingGround
	b _08028F8E
_08028F56:
	bl SpriteDyingInit
_08028F5A:
	bl SpriteDying
	b _08028F8E
_08028F60:
	bl SidehopperInit
_08028F64:
	bl SpriteSpawningFromX
	b _08028F8E
_08028F6A:
	ldr r2, _08028F80 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08028F84
	ldrh r0, [r2, #2]
	adds r0, #0x40
	b _08028F88
	.align 2, 0
_08028F80: .4byte gCurrentSprite
_08028F84:
	ldrh r0, [r2, #2]
	subs r0, #0x40
_08028F88:
	strh r0, [r2, #2]
	bl XParasiteInit
_08028F8E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start DessgeegaCheckSamusInRange
DessgeegaCheckSamusInRange: @ 0x08028F94
	push {r4, lr}
	movs r4, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	beq _08028FAC
	movs r4, #1
	bl SpriteUtilMakeSpriteFaceSamusDirection
_08028FAC:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start DesgeegaInit
DesgeegaInit: @ 0x08028FB4
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08028FE0 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08028FE4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08028FE4
	strh r0, [r2]
	b _080290AE
	.align 2, 0
_08028FE0: .4byte gCurrentSprite
_08028FE4:
	ldr r1, _08028FFC @ =gCurrentSprite
	adds r5, r1, #0
	adds r5, #0x24
	ldrb r0, [r5]
	adds r4, r1, #0
	cmp r0, #0x59
	bne _08029000
	movs r0, #0x5a
	strb r0, [r5]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _08029034
	.align 2, 0
_08028FFC: .4byte gCurrentSprite
_08029000:
	ldrh r0, [r4, #2]
	subs r0, #0x44
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08029058 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _08029028
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
_08029028:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0
	strb r0, [r1]
	movs r0, #8
	strb r0, [r5]
_08029034:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029060
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x30
	strb r0, [r1]
	ldr r0, _0802905C @ =0x0000FFE0
	strh r0, [r4, #0xa]
	movs r0, #0x54
	strh r0, [r4, #0xc]
	b _08029076
	.align 2, 0
_08029058: .4byte gPreviousCollisionCheck
_0802905C: .4byte 0x0000FFE0
_08029060:
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	movs r1, #0x20
	strb r1, [r0]
	ldr r0, _080290B4 @ =0x0000FFAC
	strh r0, [r4, #0xa]
	strh r1, [r4, #0xc]
_08029076:
	adds r1, r4, #0
	adds r1, #0x29
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0
	ldr r0, _080290B8 @ =0x0000FFC0
	strh r0, [r4, #0xe]
	movs r0, #0x40
	strh r0, [r4, #0x10]
	ldr r0, _080290BC @ =0x0831B8F0
	str r0, [r4, #0x18]
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	ldr r2, _080290C0 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	bl SpriteUtilChooseRandomXDirection
_080290AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080290B4: .4byte 0x0000FFAC
_080290B8: .4byte 0x0000FFC0
_080290BC: .4byte 0x0831B8F0
_080290C0: .4byte sPrimarySpriteStats

	thumb_func_start DessgeegaPreparingToJumpInit
DessgeegaPreparingToJumpInit: @ 0x080290C4
	ldr r1, _080290DC @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _080290E0 @ =0x0831B960
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_080290DC: .4byte gCurrentSprite
_080290E0: .4byte 0x0831B960

	thumb_func_start DesgeegaJumpingGroundInit
DesgeegaJumpingGroundInit: @ 0x080290E4
	push {r4, lr}
	ldr r3, _08029118 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r4, #0
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x31
	strb r4, [r0]
	ldr r0, _0802911C @ =0x0831B980
	str r0, [r3, #0x18]
	ldr r0, _08029120 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08029124
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	b _0802912A
	.align 2, 0
_08029118: .4byte gCurrentSprite
_0802911C: .4byte 0x0831B980
_08029120: .4byte gSpriteRandomNumber
_08029124:
	adds r0, r3, #0
	adds r0, #0x30
	strb r4, [r0]
_0802912A:
	movs r0, #0xbf
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start DesgeegaLandingInit
DesgeegaLandingInit: @ 0x08029138
	push {lr}
	ldr r1, _08029158 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x1a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0802915C @ =0x0831B9A0
	str r0, [r1, #0x18]
	ldr r0, _08029160 @ =0x0000017F
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_08029158: .4byte gCurrentSprite
_0802915C: .4byte 0x0831B9A0
_08029160: .4byte 0x0000017F

	thumb_func_start DessgeegaIdleInit
DessgeegaIdleInit: @ 0x08029164
	push {lr}
	bl DessgeegaCheckSamusInRange
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08029178
	bl DessgeegaPreparingToJumpInit
	b _080291C0
_08029178:
	ldr r2, _080291A8 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	strb r3, [r2, #0x1c]
	movs r0, #0
	strh r3, [r2, #0x16]
	adds r1, #0xa
	strb r0, [r1]
	ldr r0, _080291AC @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r3, r2, #0
	adds r3, #0x2f
	strb r0, [r3]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #7
	bls _080291B4
	ldr r0, _080291B0 @ =0x0831B8F0
	str r0, [r2, #0x18]
	b _080291C0
	.align 2, 0
_080291A8: .4byte gCurrentSprite
_080291AC: .4byte gSpriteRandomNumber
_080291B0: .4byte 0x0831B8F0
_080291B4:
	ldr r0, _080291C4 @ =0x0831B918
	str r0, [r2, #0x18]
	movs r0, #0xc0
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080291C0:
	pop {r0}
	bx r0
	.align 2, 0
_080291C4: .4byte 0x0831B918

	thumb_func_start DessgeegaFallingInit
DessgeegaFallingInit: @ 0x080291C8
	ldr r3, _080291E4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x16
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r0, #0
	strh r2, [r3, #0x16]
	adds r1, #0xd
	strb r0, [r1]
	ldr r0, _080291E8 @ =0x0831B980
	str r0, [r3, #0x18]
	bx lr
	.align 2, 0
_080291E4: .4byte gCurrentSprite
_080291E8: .4byte 0x0831B980

	thumb_func_start DessgeegaJumpWarningGround
DessgeegaJumpWarningGround: @ 0x080291EC
	push {r4, r5, lr}
	ldr r4, _0802922C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08029240
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08029230 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08029234
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _08029234
	bl DessgeegaFallingInit
	b _08029240
	.align 2, 0
_0802922C: .4byte gCurrentSprite
_08029230: .4byte gPreviousCollisionCheck
_08029234:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08029240
	bl DesgeegaJumpingGroundInit
_08029240:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DessgeegaJumpWarningCeiling
DessgeegaJumpWarningCeiling: @ 0x08029248
	push {lr}
	ldr r0, _08029268 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08029264
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08029264
	bl DesgeegaJumpingGroundInit
_08029264:
	pop {r0}
	bx r0
	.align 2, 0
_08029268: .4byte gCurrentSprite

	thumb_func_start DessgeegaJumpingGround
DessgeegaJumpingGround: @ 0x0802926C
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r2, _08029280 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029288
	ldr r1, _08029284 @ =0x0831AD84
	b _0802928A
	.align 2, 0
_08029280: .4byte gCurrentSprite
_08029284: .4byte 0x0831AD84
_08029288:
	ldr r1, _080292CC @ =0x0831AD70
_0802928A:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	ldr r4, _080292D0 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080292EC
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	adds r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080292D4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080292D8
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	b _08029310
	.align 2, 0
_080292CC: .4byte 0x0831AD70
_080292D0: .4byte gCurrentSprite
_080292D4: .4byte gPreviousCollisionCheck
_080292D8:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _080292E6
	ldrh r0, [r4, #4]
	adds r0, #4
	b _0802932E
_080292E6:
	ldrh r0, [r4, #4]
	adds r0, #5
	b _0802932E
_080292EC:
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08029318 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0802931C
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
_08029310:
	strh r0, [r4, #4]
	lsls r1, r5, #0x10
	b _08029330
	.align 2, 0
_08029318: .4byte gPreviousCollisionCheck
_0802931C:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _0802932A
	ldrh r0, [r4, #4]
	subs r0, #4
	b _0802932E
_0802932A:
	ldrh r0, [r4, #4]
	subs r0, #5
_0802932E:
	strh r0, [r4, #4]
_08029330:
	ldr r4, _08029374 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r0, [r2]
	cmp r0, #0x26
	bhi _08029346
	adds r0, #1
	strb r0, [r2]
_08029346:
	cmp r1, #0
	ble _080293C0
	cmp r6, #0
	beq _0802935A
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r4]
_0802935A:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _08029378 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802937C
	strh r1, [r4, #2]
	bl DesgeegaLandingInit
	b _0802943E
	.align 2, 0
_08029374: .4byte gCurrentSprite
_08029378: .4byte gPreviousVerticalCollisionCheck
_0802937C:
	cmp r6, #0
	bne _0802943E
	ldrh r0, [r4, #2]
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080293B2
	ldrh r0, [r4, #2]
	movs r3, #0xe
	ldrsh r1, [r4, r3]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _080293AE
	movs r6, #1
_080293AE:
	cmp r6, #0
	beq _0802943E
_080293B2:
	ldr r0, _080293BC @ =gCurrentSprite
	strh r1, [r0, #2]
	bl DesgeegaLandingInit
	b _0802943E
	.align 2, 0
_080293BC: .4byte gCurrentSprite
_080293C0:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08029400
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080293FC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0802942C
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	strh r0, [r4, #4]
	bl DessgeegaFallingInit
	b _0802942C
	.align 2, 0
_080293FC: .4byte gPreviousCollisionCheck
_08029400:
	movs r3, #0xa
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08029444 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0802942C
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
	strh r0, [r4, #4]
	bl DessgeegaFallingInit
_0802942C:
	cmp r6, #0
	beq _0802943E
	ldr r0, _08029448 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	eors r1, r2
	strh r1, [r0]
_0802943E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08029444: .4byte gPreviousCollisionCheck
_08029448: .4byte gCurrentSprite

	thumb_func_start DessgeegaJumpingCeiling
DessgeegaJumpingCeiling: @ 0x0802944C
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r2, _08029460 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029468
	ldr r1, _08029464 @ =0x0831AD84
	b _0802946A
	.align 2, 0
_08029460: .4byte gCurrentSprite
_08029464: .4byte 0x0831AD84
_08029468:
	ldr r1, _080294AC @ =0x0831AD70
_0802946A:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	ldr r4, _080294B0 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080294CC
	ldrh r0, [r4, #2]
	adds r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	adds r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080294B4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080294B8
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	b _080294F0
	.align 2, 0
_080294AC: .4byte 0x0831AD70
_080294B0: .4byte gCurrentSprite
_080294B4: .4byte gPreviousCollisionCheck
_080294B8:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _080294C6
	ldrh r0, [r4, #4]
	adds r0, #4
	b _0802950E
_080294C6:
	ldrh r0, [r4, #4]
	adds r0, #5
	b _0802950E
_080294CC:
	ldrh r0, [r4, #2]
	adds r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080294F8 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080294FC
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
_080294F0:
	strh r0, [r4, #4]
	lsls r1, r5, #0x10
	b _08029510
	.align 2, 0
_080294F8: .4byte gPreviousCollisionCheck
_080294FC:
	lsls r0, r5, #0x10
	adds r1, r0, #0
	cmp r1, #0
	ble _0802950A
	ldrh r0, [r4, #4]
	subs r0, #4
	b _0802950E
_0802950A:
	ldrh r0, [r4, #4]
	subs r0, #5
_0802950E:
	strh r0, [r4, #4]
_08029510:
	ldr r4, _08029564 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, r0, r5
	strh r0, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r0, [r2]
	cmp r0, #0x26
	bhi _08029526
	adds r0, #1
	strb r0, [r2]
_08029526:
	cmp r1, #0
	bge _080295B4
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802956C
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08029568 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08029598
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #6
	strh r0, [r4, #4]
	bl DessgeegaFallingInit
	b _08029598
	.align 2, 0
_08029564: .4byte gCurrentSprite
_08029568: .4byte gPreviousCollisionCheck
_0802956C:
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r3, [r4, #4]
	adds r1, r1, r3
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080295AC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08029598
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #6
	strh r0, [r4, #4]
	bl DessgeegaFallingInit
_08029598:
	cmp r7, #0
	beq _08029636
	ldr r0, _080295B0 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	eors r1, r2
	strh r1, [r0]
	b _08029636
	.align 2, 0
_080295AC: .4byte gPreviousCollisionCheck
_080295B0: .4byte gCurrentSprite
_080295B4:
	cmp r7, #0
	beq _080295C4
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r4]
_080295C4:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r5, _080295E8 @ =gPreviousVerticalCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080295EC
	adds r0, r2, #0
	adds r0, #0x40
	strh r0, [r4, #2]
	bl DesgeegaLandingInit
	b _08029636
	.align 2, 0
_080295E8: .4byte gPreviousVerticalCollisionCheck
_080295EC:
	cmp r7, #0
	bne _08029636
	ldrh r0, [r4, #2]
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0802962A
	ldrh r0, [r4, #2]
	movs r3, #0xe
	ldrsh r1, [r4, r3]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08029626
	movs r7, #1
_08029626:
	cmp r7, #0
	beq _08029636
_0802962A:
	ldr r1, _0802963C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x40
	strh r0, [r1, #2]
	bl DesgeegaLandingInit
_08029636:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802963C: .4byte gCurrentSprite

	thumb_func_start DessgeegaLanding
DessgeegaLanding: @ 0x08029640
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802964E
	bl DessgeegaIdleInit
_0802964E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DessgeegaFallingGround
DessgeegaFallingGround: @ 0x08029654
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r4, _080296A8 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _080296AC @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802969E
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802969E
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802969A
	movs r6, #1
_0802969A:
	cmp r6, #0
	beq _080296B0
_0802969E:
	ldr r0, _080296A8 @ =gCurrentSprite
	strh r1, [r0, #2]
	bl DesgeegaLandingInit
	b _080296F0
	.align 2, 0
_080296A8: .4byte gCurrentSprite
_080296AC: .4byte gPreviousVerticalCollisionCheck
_080296B0:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _080296DC @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _080296E0 @ =0x00007FFF
	cmp r1, r0
	bne _080296E4
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _080296F0
	.align 2, 0
_080296DC: .4byte sSpritesFallingSpeed
_080296E0: .4byte 0x00007FFF
_080296E4:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_080296F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DessgeegaFallingCeiling
DessgeegaFallingCeiling: @ 0x080296F8
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r4, _08029750 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r5, _08029754 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08029742
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08029742
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802973E
	movs r6, #1
_0802973E:
	cmp r6, #0
	beq _08029758
_08029742:
	ldr r1, _08029750 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x40
	strh r0, [r1, #2]
	bl DesgeegaLandingInit
	b _08029798
	.align 2, 0
_08029750: .4byte gCurrentSprite
_08029754: .4byte gPreviousVerticalCollisionCheck
_08029758:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _08029784 @ =sSpritesFallingSpeedCeiling
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08029788 @ =0x00007FFF
	cmp r1, r0
	bne _0802978C
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _08029798
	.align 2, 0
_08029784: .4byte sSpritesFallingSpeedCeiling
_08029788: .4byte 0x00007FFF
_0802978C:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_08029798:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DessgeegaIdleGround
DessgeegaIdleGround: @ 0x080297A0
	push {r4, r5, lr}
	bl DessgeegaCheckSamusInRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802980A
	ldr r4, _080297E0 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _080297E4 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _080297E8
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _080297E8
	bl DessgeegaFallingInit
	b _08029824
	.align 2, 0
_080297E0: .4byte gCurrentSprite
_080297E4: .4byte gPreviousCollisionCheck
_080297E8:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08029824
	ldr r2, _08029810 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	adds r1, r2, #0
	adds r1, #0x2f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _08029814
_0802980A:
	bl DessgeegaPreparingToJumpInit
	b _08029824
	.align 2, 0
_08029810: .4byte gCurrentSprite
_08029814:
	ldr r1, [r2, #0x18]
	ldr r0, _0802982C @ =0x0831B918
	cmp r1, r0
	bne _08029824
	movs r0, #0xc0
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08029824:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802982C: .4byte 0x0831B918

	thumb_func_start DessgeegaIdleCeiling
DessgeegaIdleCeiling: @ 0x08029830
	push {lr}
	bl DessgeegaCheckSamusInRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802985E
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08029878
	ldr r2, _08029864 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	adds r1, r2, #0
	adds r1, #0x2f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _08029868
_0802985E:
	bl DessgeegaPreparingToJumpInit
	b _08029878
	.align 2, 0
_08029864: .4byte gCurrentSprite
_08029868:
	ldr r1, [r2, #0x18]
	ldr r0, _0802987C @ =0x0831B918
	cmp r1, r0
	bne _08029878
	movs r0, #0xc0
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08029878:
	pop {r0}
	bx r0
	.align 2, 0
_0802987C: .4byte 0x0831B918

	thumb_func_start DessgeegaSpikeInit
DessgeegaSpikeInit: @ 0x08029880
	push {r4, r5, lr}
	ldr r0, _080298E4 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _080298E8 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _080298EC @ =0x0000FFFC
	mov r5, ip
	strh r1, [r5, #0xa]
	movs r2, #4
	movs r0, #4
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	ldr r0, _080298F0 @ =0x0831B9C0
	str r0, [r5, #0x18]
	strb r3, [r5, #0x1c]
	strh r4, [r5, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	subs r1, #2
	movs r0, #3
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080298E4: .4byte gCurrentSprite
_080298E8: .4byte 0x0000FFFB
_080298EC: .4byte 0x0000FFFC
_080298F0: .4byte 0x0831B9C0

	thumb_func_start DessgeegaSpikeMove
DessgeegaSpikeMove: @ 0x080298F4
	push {r4, lr}
	ldr r4, _0802990C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08029910
	strh r0, [r4]
	b _08029946
	.align 2, 0
_0802990C: .4byte gCurrentSprite
_08029910:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	ldr r0, _0802992C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029930
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _08029946
	.align 2, 0
_0802992C: .4byte gPreviousVerticalCollisionCheck
_08029930:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08029940
	ldrh r0, [r4, #4]
	adds r0, #0xa
	b _08029944
_08029940:
	ldrh r0, [r4, #4]
	subs r0, #0xa
_08029944:
	strh r0, [r4, #4]
_08029946:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start DessgeegaSpikeExplodingInit
DessgeegaSpikeExplodingInit: @ 0x0802994C
	ldr r3, _08029968 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	ldr r0, _0802996C @ =0x0831B9D0
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	bx lr
	.align 2, 0
_08029968: .4byte gCurrentSprite
_0802996C: .4byte 0x0831B9D0

	thumb_func_start DessgeegaSpikeExploding
DessgeegaSpikeExploding: @ 0x08029970
	push {r4, r5, lr}
	ldr r4, _08029998 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08029990
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08029992
_08029990:
	strh r5, [r4]
_08029992:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029998: .4byte gCurrentSprite

	thumb_func_start Dessgeega
Dessgeega: @ 0x0802999C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r4, _080299B4 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r7, [r0]
	cmp r7, #0
	beq _080299B8
	bl SpriteUtilUpdateFreezeTimer
	b _08029CAC
	.align 2, 0
_080299B4: .4byte gCurrentSprite
_080299B8:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5a
	bhi _08029A72
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08029A72
	ldr r0, _08029A38 @ =0x00000181
	bl SoundPlayNotAlreadyPlaying
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08029A72
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r1, [r6]
	movs r0, #0x32
	bl SpriteUtilFindSecondaryWithRamSlot
	cmp r0, #2
	bgt _08029A72
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08029A3C
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	adds r0, #0x4c
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x40
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x32
	bl SpriteSpawnSecondary
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	adds r0, #0x4c
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x40
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
	movs r0, #0x32
	bl SpriteSpawnSecondary
	b _08029A72
	.align 2, 0
_08029A38: .4byte 0x00000181
_08029A3C:
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x4c
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x40
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x32
	bl SpriteSpawnSecondary
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x4c
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x40
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
	movs r0, #0x32
	bl SpriteSpawnSecondary
_08029A72:
	ldr r1, _08029A8C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x5b
	bls _08029A82
	b _08029CAC
_08029A82:
	lsls r0, r0, #2
	ldr r1, _08029A90 @ =_08029A94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08029A8C: .4byte gCurrentSprite
_08029A90: .4byte _08029A94
_08029A94: @ jump table
	.4byte _08029C04 @ case 0
	.4byte _08029C0A @ case 1
	.4byte _08029C0E @ case 2
	.4byte _08029CAC @ case 3
	.4byte _08029CAC @ case 4
	.4byte _08029CAC @ case 5
	.4byte _08029CAC @ case 6
	.4byte _08029CAC @ case 7
	.4byte _08029C4C @ case 8
	.4byte _08029CAC @ case 9
	.4byte _08029CAC @ case 10
	.4byte _08029CAC @ case 11
	.4byte _08029CAC @ case 12
	.4byte _08029CAC @ case 13
	.4byte _08029CAC @ case 14
	.4byte _08029CAC @ case 15
	.4byte _08029CAC @ case 16
	.4byte _08029CAC @ case 17
	.4byte _08029CAC @ case 18
	.4byte _08029CAC @ case 19
	.4byte _08029CAC @ case 20
	.4byte _08029CAC @ case 21
	.4byte _08029C64 @ case 22
	.4byte _08029CAC @ case 23
	.4byte _08029C2E @ case 24
	.4byte _08029CAC @ case 25
	.4byte _08029C46 @ case 26
	.4byte _08029CAC @ case 27
	.4byte _08029CAC @ case 28
	.4byte _08029CAC @ case 29
	.4byte _08029CAC @ case 30
	.4byte _08029CAC @ case 31
	.4byte _08029CAC @ case 32
	.4byte _08029CAC @ case 33
	.4byte _08029CAC @ case 34
	.4byte _08029CAC @ case 35
	.4byte _08029CAC @ case 36
	.4byte _08029CAC @ case 37
	.4byte _08029CAC @ case 38
	.4byte _08029CAC @ case 39
	.4byte _08029CAC @ case 40
	.4byte _08029CAC @ case 41
	.4byte _08029CAC @ case 42
	.4byte _08029CAC @ case 43
	.4byte _08029CAC @ case 44
	.4byte _08029CAC @ case 45
	.4byte _08029CAC @ case 46
	.4byte _08029CAC @ case 47
	.4byte _08029CAC @ case 48
	.4byte _08029CAC @ case 49
	.4byte _08029CAC @ case 50
	.4byte _08029CAC @ case 51
	.4byte _08029CAC @ case 52
	.4byte _08029CAC @ case 53
	.4byte _08029CAC @ case 54
	.4byte _08029CAC @ case 55
	.4byte _08029CAC @ case 56
	.4byte _08029CAC @ case 57
	.4byte _08029CAC @ case 58
	.4byte _08029CAC @ case 59
	.4byte _08029CAC @ case 60
	.4byte _08029CAC @ case 61
	.4byte _08029CAC @ case 62
	.4byte _08029CAC @ case 63
	.4byte _08029CAC @ case 64
	.4byte _08029CAC @ case 65
	.4byte _08029CAC @ case 66
	.4byte _08029CAC @ case 67
	.4byte _08029CAC @ case 68
	.4byte _08029CAC @ case 69
	.4byte _08029CAC @ case 70
	.4byte _08029CAC @ case 71
	.4byte _08029CAC @ case 72
	.4byte _08029CAC @ case 73
	.4byte _08029CAC @ case 74
	.4byte _08029CAC @ case 75
	.4byte _08029CAC @ case 76
	.4byte _08029CAC @ case 77
	.4byte _08029CAC @ case 78
	.4byte _08029CAC @ case 79
	.4byte _08029CAC @ case 80
	.4byte _08029CAC @ case 81
	.4byte _08029CAC @ case 82
	.4byte _08029CAC @ case 83
	.4byte _08029CAC @ case 84
	.4byte _08029CAC @ case 85
	.4byte _08029CAC @ case 86
	.4byte _08029C7C @ case 87
	.4byte _08029C80 @ case 88
	.4byte _08029C86 @ case 89
	.4byte _08029C8A @ case 90
	.4byte _08029C90 @ case 91
_08029C04:
	bl DesgeegaInit
	b _08029CAC
_08029C0A:
	bl DessgeegaPreparingToJumpInit
_08029C0E:
	ldr r0, _08029C24 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029C28
	bl DessgeegaJumpWarningCeiling
	b _08029CAC
	.align 2, 0
_08029C24: .4byte gCurrentSprite
_08029C28:
	bl DessgeegaJumpWarningGround
	b _08029CAC
_08029C2E:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029C40
	bl DessgeegaJumpingCeiling
	b _08029CAC
_08029C40:
	bl DessgeegaJumpingGround
	b _08029CAC
_08029C46:
	bl DessgeegaLanding
	b _08029CAC
_08029C4C:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029C5E
	bl DessgeegaIdleCeiling
	b _08029CAC
_08029C5E:
	bl DessgeegaIdleGround
	b _08029CAC
_08029C64:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029C76
	bl DessgeegaFallingCeiling
	b _08029CAC
_08029C76:
	bl DessgeegaFallingGround
	b _08029CAC
_08029C7C:
	bl SpriteDyingInit
_08029C80:
	bl SpriteDying
	b _08029CAC
_08029C86:
	bl DesgeegaInit
_08029C8A:
	bl SpriteSpawningFromX
	b _08029CAC
_08029C90:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029CA2
	ldrh r0, [r2, #2]
	adds r0, #0x40
	b _08029CA6
_08029CA2:
	ldrh r0, [r2, #2]
	subs r0, #0x40
_08029CA6:
	strh r0, [r2, #2]
	bl XParasiteInit
_08029CAC:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start DessgeegaSpike
DessgeegaSpike: @ 0x08029CB4
	push {lr}
	ldr r0, _08029CCC @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08029CDC
	cmp r0, #2
	bgt _08029CD0
	cmp r0, #0
	beq _08029CD6
	b _08029CE8
	.align 2, 0
_08029CCC: .4byte gCurrentSprite
_08029CD0:
	cmp r0, #0x38
	beq _08029CE2
	b _08029CE8
_08029CD6:
	bl DessgeegaSpikeInit
	b _08029CEC
_08029CDC:
	bl DessgeegaSpikeMove
	b _08029CEC
_08029CE2:
	bl DessgeegaSpikeExploding
	b _08029CEC
_08029CE8:
	bl DessgeegaSpikeExplodingInit
_08029CEC:
	pop {r0}
	bx r0

	thumb_func_start XBarrierSetCollision
XBarrierSetCollision: @ 0x08029CF0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08029D44 @ =gCurrentSprite
	ldrh r4, [r0, #2]
	subs r4, #0x20
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r0, [r0, #4]
	mov r8, r0
	ldr r6, _08029D48 @ =gCurrentClipdataAffectingAction
	strb r5, [r6]
	adds r0, r4, #0
	subs r0, #0x40
	mov r1, r8
	bl ClipdataProcess
	strb r5, [r6]
	adds r0, r4, #0
	mov r1, r8
	bl ClipdataProcess
	strb r5, [r6]
	adds r0, r4, #0
	adds r0, #0x40
	mov r1, r8
	bl ClipdataProcess
	strb r5, [r6]
	adds r4, #0x80
	adds r0, r4, #0
	mov r1, r8
	bl ClipdataProcess
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08029D44: .4byte gCurrentSprite
_08029D48: .4byte gCurrentClipdataAffectingAction

	thumb_func_start XBarrierCoreInit
XBarrierCoreInit: @ 0x08029D4C
	push {r4, r5, lr}
	sub sp, #0xc
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08029D6C @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x24
	ldrb r0, [r3]
	cmp r0, #0x59
	bne _08029D70
	movs r0, #0x5a
	strb r0, [r3]
	movs r0, #0x2c
	strh r0, [r2, #6]
	b _08029D9C
	.align 2, 0
_08029D6C: .4byte gCurrentSprite
_08029D70:
	ldrb r1, [r2, #0x1d]
	adds r0, r1, #0
	subs r0, #0x41
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, _08029D94 @ =gNormalXBarrierCoresDestroyed
	ldrh r0, [r0]
	asrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08029D98
	movs r0, #0
	strh r0, [r2]
	b _08029E6E
	.align 2, 0
_08029D94: .4byte gNormalXBarrierCoresDestroyed
_08029D98:
	movs r0, #2
	strb r0, [r3]
_08029D9C:
	ldr r4, _08029E00 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x27
	movs r3, #0
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r2, _08029E04 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	strh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	adds r1, #3
	movs r0, #0xd
	strb r0, [r1]
	ldr r0, _08029E08 @ =0x0831C348
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08029E28
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08029E0C
	strh r0, [r4]
	b _08029E6E
	.align 2, 0
_08029E00: .4byte gCurrentSprite
_08029E04: .4byte sPrimarySpriteStats
_08029E08: .4byte 0x0831C348
_08029E0C:
	ldr r0, _08029E20 @ =0x0000FFC0
	strh r0, [r4, #0xa]
	movs r0, #0x40
	strh r0, [r4, #0xc]
	ldr r0, _08029E24 @ =0x0000FFD0
	strh r0, [r4, #0xe]
	movs r0, #0x30
	strh r0, [r4, #0x10]
	b _08029E6E
	.align 2, 0
_08029E20: .4byte 0x0000FFC0
_08029E24: .4byte 0x0000FFD0
_08029E28:
	ldr r0, _08029E60 @ =0x0000FFD0
	strh r0, [r4, #0xa]
	movs r0, #0x30
	strh r0, [r4, #0xc]
	ldr r0, _08029E64 @ =0x0000FFD8
	strh r0, [r4, #0xe]
	movs r0, #0x28
	strh r0, [r4, #0x10]
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x1d
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	bne _08029E68
	strh r5, [r4]
	b _08029E6E
	.align 2, 0
_08029E60: .4byte 0x0000FFD0
_08029E64: .4byte 0x0000FFD8
_08029E68:
	movs r0, #3
	bl XBarrierSetCollision
_08029E6E:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start XBarrierCoreIdleInit
XBarrierCoreIdleInit: @ 0x08029E78
	ldr r1, _08029E90 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #2
	strb r0, [r2]
	ldr r0, _08029E94 @ =0x0831C348
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_08029E90: .4byte gCurrentSprite
_08029E94: .4byte 0x0831C348

	thumb_func_start XBarrierCoreIdle
XBarrierCoreIdle: @ 0x08029E98
	bx lr
	.align 2, 0

	thumb_func_start XBarrierCoreDeath
XBarrierCoreDeath: @ 0x08029E9C
	push {lr}
	ldr r0, _08029EC4 @ =gCurrentSprite
	ldrb r0, [r0, #0x1d]
	subs r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #9
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _08029EC8 @ =gNormalXBarrierCoresDestroyed
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	movs r0, #1
	bl XBarrierSetCollision
	pop {r0}
	bx r0
	.align 2, 0
_08029EC4: .4byte gCurrentSprite
_08029EC8: .4byte gNormalXBarrierCoresDestroyed

	thumb_func_start XBarrierCore
XBarrierCore: @ 0x08029ECC
	push {r4, lr}
	ldr r4, _08029F04 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08029EE6
	movs r0, #0xb0
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08029EE6:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029F08
	bl SpriteUtilUpdateFreezeTimer
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x1d
	bl SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent
	b _08029F74
	.align 2, 0
_08029F04: .4byte gCurrentSprite
_08029F08:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x57
	beq _08029F4C
	cmp r0, #0x57
	bgt _08029F2A
	cmp r0, #1
	beq _08029F42
	cmp r0, #1
	bgt _08029F24
	cmp r0, #0
	beq _08029F3C
	b _08029F74
_08029F24:
	cmp r0, #2
	beq _08029F46
	b _08029F74
_08029F2A:
	cmp r0, #0x59
	beq _08029F66
	cmp r0, #0x59
	blt _08029F60
	cmp r0, #0x5a
	beq _08029F6A
	cmp r0, #0x5b
	beq _08029F70
	b _08029F74
_08029F3C:
	bl XBarrierCoreInit
	b _08029F74
_08029F42:
	bl XBarrierCoreIdleInit
_08029F46:
	bl XBarrierCoreIdle
	b _08029F74
_08029F4C:
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x1d
	bl SpriteUtilUnfreezeSecondarySprites
	bl XBarrierCoreDeath
	bl SpriteDyingInit
_08029F60:
	bl SpriteDying
	b _08029F74
_08029F66:
	bl XBarrierCoreInit
_08029F6A:
	bl SpriteSpawningFromX
	b _08029F74
_08029F70:
	bl XParasiteInit
_08029F74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start XBarrierStem
XBarrierStem: @ 0x08029F7C
	push {r4, r5, r6, lr}
	ldr r4, _08029F94 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r6, [r0]
	cmp r6, #0
	beq _08029F98
	bl SpriteUtilUpdateFreezeTimer
	bl SpriteUtilUpdatePrimarySpriteFreezeTimerOfCurrent
	b _0802A0AA
	.align 2, 0
_08029F94: .4byte gCurrentSprite
_08029F98:
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r5, [r0]
	adds r3, r4, #0
	adds r3, #0x24
	ldrb r0, [r3]
	cmp r0, #2
	beq _0802A028
	cmp r0, #2
	bgt _08029FB4
	cmp r0, #0
	beq _08029FBC
	lsls r2, r5, #3
	b _0802A070
_08029FB4:
	cmp r0, #0x18
	beq _0802A05C
	lsls r2, r5, #3
	b _0802A070
_08029FBC:
	ldrh r1, [r4]
	ldr r0, _0802A014 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	strh r0, [r4]
	movs r0, #2
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0802A018 @ =0x0000FF80
	strh r0, [r4, #0xa]
	movs r0, #0x80
	strh r0, [r4, #0xc]
	ldr r0, _0802A01C @ =0x0000FFF0
	strh r0, [r4, #0xe]
	movs r0, #0x10
	strh r0, [r4, #0x10]
	ldr r1, _0802A020 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #6
	strb r0, [r1]
	adds r1, #3
	movs r0, #0xd
	strb r0, [r1]
	ldr r0, _0802A024 @ =0x0831C2F8
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r6, [r4, #0x16]
	lsls r2, r5, #3
	b _0802A070
	.align 2, 0
_0802A014: .4byte 0x0000FFFB
_0802A018: .4byte 0x0000FF80
_0802A01C: .4byte 0x0000FFF0
_0802A020: .4byte sSecondarySpriteStats
_0802A024: .4byte 0x0831C2F8
_0802A028:
	ldr r2, _0802A054 @ =gSpriteData
	lsls r1, r5, #3
	subs r0, r1, r5
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0, #0x14]
	adds r2, r1, #0
	cmp r0, #0
	bne _0802A070
	movs r0, #0x18
	strb r0, [r3]
	ldr r0, _0802A058 @ =0x0831C320
	str r0, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r6, [r4, #0x16]
	strh r6, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	b _0802A070
	.align 2, 0
_0802A054: .4byte gSpriteData
_0802A058: .4byte 0x0831C320
_0802A05C:
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	lsls r2, r5, #3
	cmp r0, #0
	beq _0802A070
	strh r6, [r4]
_0802A070:
	ldr r1, _0802A098 @ =gSpriteData
	subs r0, r2, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802A0A0
	ldr r1, _0802A09C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x26
	movs r0, #1
	strb r0, [r2]
	ldrh r2, [r1]
	movs r0, #0x20
	orrs r0, r2
	strh r0, [r1]
	b _0802A0AA
	.align 2, 0
_0802A098: .4byte gSpriteData
_0802A09C: .4byte gCurrentSprite
_0802A0A0:
	ldr r2, _0802A0B0 @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _0802A0B4 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2]
_0802A0AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802A0B0: .4byte gCurrentSprite
_0802A0B4: .4byte 0x0000FFDF

	thumb_func_start NavPadDetectSamus
NavPadDetectSamus: @ 0x0802A0B8
	push {r4, lr}
	movs r4, #0
	ldr r0, _0802A0E8 @ =gSamusData
	ldrh r2, [r0, #0x18]
	ldrh r3, [r0, #0x16]
	ldr r1, _0802A0EC @ =gCurrentSprite
	ldrh r0, [r1, #2]
	ldrh r1, [r1, #4]
	subs r0, #1
	cmp r2, r0
	bne _0802A0DE
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, r3
	bge _0802A0DE
	adds r0, #0x80
	cmp r0, r3
	ble _0802A0DE
	movs r4, #1
_0802A0DE:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802A0E8: .4byte gSamusData
_0802A0EC: .4byte gCurrentSprite

	thumb_func_start NavPadDetectSamus_Unused
NavPadDetectSamus_Unused: @ 0x0802A0F0
	push {lr}
	movs r3, #0
	ldr r0, _0802A114 @ =gSamusData
	ldrh r2, [r0, #0x16]
	ldr r0, _0802A118 @ =gCurrentSprite
	ldrh r1, [r0, #4]
	adds r0, r1, #0
	subs r0, #0xa0
	cmp r0, r2
	bge _0802A10E
	adds r0, r1, #0
	adds r0, #0xa0
	cmp r0, r2
	ble _0802A10E
	movs r3, #1
_0802A10E:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_0802A114: .4byte gSamusData
_0802A118: .4byte gCurrentSprite

	thumb_func_start NavPadInit
NavPadInit: @ 0x0802A11C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r5, _0802A18C @ =gCurrentSprite
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x25
	strb r4, [r0]
	adds r1, r5, #0
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0802A190 @ =0x0000FFFC
	strh r1, [r5, #0xa]
	movs r0, #4
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	adds r0, r5, #0
	adds r0, #0x21
	movs r7, #1
	strb r7, [r0]
	ldrb r2, [r5, #0x1f]
	adds r6, r5, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #7
	movs r1, #0
	bl SpriteSpawnSecondary
	bl EventCheckWith_NavigationDisabled
	adds r4, r0, #0
	cmp r4, #0
	beq _0802A194
	adds r0, r5, #0
	adds r0, #0x2f
	strb r7, [r0]
	b _0802A1B2
	.align 2, 0
_0802A18C: .4byte gCurrentSprite
_0802A190: .4byte 0x0000FFFC
_0802A194:
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	ldrb r2, [r5, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #8
	movs r1, #0
	bl SpriteSpawnSecondary
_0802A1B2:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NavPadIdleInit
NavPadIdleInit: @ 0x0802A1BC
	push {lr}
	ldr r1, _0802A1E4 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A1EC
	ldr r0, _0802A1E8 @ =0x0831E380
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x46
	b _0802A1F4
	.align 2, 0
_0802A1E4: .4byte gCurrentSprite
_0802A1E8: .4byte 0x0831E380
_0802A1EC:
	ldr r0, _0802A1FC @ =0x0831E318
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #2
_0802A1F4:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802A1FC: .4byte 0x0831E318

	thumb_func_start NavPadIdle
NavPadIdle: @ 0x0802A200
	push {lr}
	bl NavPadDetectSamus
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802A244
	ldr r3, _0802A238 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802A24C
	subs r1, #0xa
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802A23C @ =0x0831E278
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0802A240 @ =0x00000101
	bl SoundPlay
	b _0802A24C
	.align 2, 0
_0802A238: .4byte gCurrentSprite
_0802A23C: .4byte 0x0831E278
_0802A240: .4byte 0x00000101
_0802A244:
	ldr r0, _0802A250 @ =gCurrentSprite
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
_0802A24C:
	pop {r0}
	bx r0
	.align 2, 0
_0802A250: .4byte gCurrentSprite

	thumb_func_start NavPadPressingSwitch
NavPadPressingSwitch: @ 0x0802A254
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802A272
	ldr r1, _0802A278 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1a
	strb r0, [r2]
	ldr r0, _0802A27C @ =0x0831E380
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
_0802A272:
	pop {r0}
	bx r0
	.align 2, 0
_0802A278: .4byte gCurrentSprite
_0802A27C: .4byte 0x0831E380

	thumb_func_start NavPadSwitchPressed
NavPadSwitchPressed: @ 0x0802A280
	push {r4, lr}
	bl NavPadDetectSamus
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0802A2D4
	bl SpriteUtilCheckSamusMorphed
	cmp r0, #0
	bne _0802A2EE
	ldr r2, _0802A2C8 @ =gSamusData
	ldr r4, _0802A2CC @ =gCurrentSprite
	ldrh r0, [r4, #4]
	strh r0, [r2, #0x16]
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _0802A2A8
	movs r0, #0
	strb r0, [r2, #5]
_0802A2A8:
	ldr r1, _0802A2D0 @ =sSamusSetPoseFunctionPointer
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x36
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x14
	strb r0, [r1]
	b _0802A2EE
	.align 2, 0
_0802A2C8: .4byte gSamusData
_0802A2CC: .4byte gCurrentSprite
_0802A2D0: .4byte sSamusSetPoseFunctionPointer
_0802A2D4:
	ldr r1, _0802A2F4 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _0802A2F8 @ =0x0831E2F0
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	movs r0, #0x81
	lsls r0, r0, #1
	bl SoundPlay
_0802A2EE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A2F4: .4byte gCurrentSprite
_0802A2F8: .4byte 0x0831E2F0

	thumb_func_start NavPadReleasingSwitch
NavPadReleasingSwitch: @ 0x0802A2FC
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802A30A
	bl NavPadIdleInit
_0802A30A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NavPadAfterConversationInit
NavPadAfterConversationInit: @ 0x0802A310
	push {lr}
	bl EventCheckOn_Escape
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0802A332
	ldr r0, _0802A340 @ =gEscapeStatus
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802A332
	bl EscapeStart
	movs r0, #0x35
	movs r1, #0xa
	bl PlayMusic
_0802A332:
	ldr r0, _0802A344 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x1e
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0802A340: .4byte gEscapeStatus
_0802A344: .4byte gCurrentSprite

	thumb_func_start NavPadAfterConversation
NavPadAfterConversation: @ 0x0802A348
	push {lr}
	bl NavPadDetectSamus
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0802A370
	ldr r1, _0802A374 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _0802A378 @ =0x0831E2F0
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	movs r0, #0x81
	lsls r0, r0, #1
	bl SoundPlay
_0802A370:
	pop {r0}
	bx r0
	.align 2, 0
_0802A374: .4byte gCurrentSprite
_0802A378: .4byte 0x0831E2F0

	thumb_func_start NavPadUsingConsole
NavPadUsingConsole: @ 0x0802A37C
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _0802A3E4 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802A39C
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A39C
	ldr r0, _0802A3E8 @ =0x00000103
	bl SoundPlay
_0802A39C:
	ldr r1, _0802A3EC @ =gSamusData
	ldrb r0, [r1, #1]
	cmp r0, #0x36
	bne _0802A3DC
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _0802A3DC
	ldr r4, _0802A3E4 @ =gCurrentSprite
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0xf0
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #9
	movs r1, #0
	bl SpriteSpawnSecondary
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3a
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
_0802A3DC:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A3E4: .4byte gCurrentSprite
_0802A3E8: .4byte 0x00000103
_0802A3EC: .4byte gSamusData

	thumb_func_start NavPadStartConversation
NavPadStartConversation: @ 0x0802A3F0
	push {lr}
	ldr r2, _0802A420 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A41A
	ldr r1, _0802A424 @ =gPauseScreenFlag
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0802A428 @ =gSubGameMode1
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1d
	strb r0, [r1]
_0802A41A:
	pop {r0}
	bx r0
	.align 2, 0
_0802A420: .4byte gCurrentSprite
_0802A424: .4byte gPauseScreenFlag
_0802A428: .4byte gSubGameMode1

	thumb_func_start NavConsoleInit
NavConsoleInit: @ 0x0802A42C
	push {r4, lr}
	ldr r0, _0802A480 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0802A484 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r0, #2
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802A488 @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xd
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802A48C @ =0x0831E268
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A480: .4byte gCurrentSprite
_0802A484: .4byte 0x0000FFFB
_0802A488: .4byte 0x0000FFFC
_0802A48C: .4byte 0x0831E268

	thumb_func_start NavConsoleIdle
NavConsoleIdle: @ 0x0802A490
	bx lr
	.align 2, 0

	thumb_func_start NavConsoleScreenInit
NavConsoleScreenInit: @ 0x0802A494
	push {r4, lr}
	ldr r0, _0802A4F4 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0802A4F8 @ =0x0000FFFB
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
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802A4FC @ =0x0000FFFC
	mov r2, ip
	strh r1, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802A500 @ =0x0831E2C8
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A4F4: .4byte gCurrentSprite
_0802A4F8: .4byte 0x0000FFFB
_0802A4FC: .4byte 0x0000FFFC
_0802A500: .4byte 0x0831E2C8

	thumb_func_start NavConsoleScreenIdle
NavConsoleScreenIdle: @ 0x0802A504
	push {lr}
	ldr r3, _0802A528 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	ldr r2, _0802A52C @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x1c
	beq _0802A534
	cmp r0, #0x38
	bne _0802A538
	ldr r0, _0802A530 @ =0x0831E2A0
	b _0802A536
	.align 2, 0
_0802A528: .4byte gCurrentSprite
_0802A52C: .4byte gSpriteData
_0802A530: .4byte 0x0831E2A0
_0802A534:
	ldr r0, _0802A53C @ =0x0831E2C8
_0802A536:
	str r0, [r3, #0x18]
_0802A538:
	pop {r0}
	bx r0
	.align 2, 0
_0802A53C: .4byte 0x0831E2C8

	thumb_func_start NavScreenInit
NavScreenInit: @ 0x0802A540
	push {r4, lr}
	ldr r0, _0802A5A4 @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	mov r4, ip
	ldrh r1, [r4]
	ldr r0, _0802A5A8 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r0, #2
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802A5AC @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802A5B0 @ =0x0831E340
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	movs r0, #0x82
	lsls r0, r0, #1
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A5A4: .4byte gCurrentSprite
_0802A5A8: .4byte 0x0000FFFB
_0802A5AC: .4byte 0x0000FFFC
_0802A5B0: .4byte 0x0831E340

	thumb_func_start NavScreenTurningOn
NavScreenTurningOn: @ 0x0802A5B4
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802A5D0
	ldr r1, _0802A5D4 @ =gCurrentSprite
	ldr r0, _0802A5D8 @ =0x0831E328
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
_0802A5D0:
	pop {r0}
	bx r0
	.align 2, 0
_0802A5D4: .4byte gCurrentSprite
_0802A5D8: .4byte 0x0831E328

	thumb_func_start NavScreenIdle
NavScreenIdle: @ 0x0802A5DC
	push {lr}
	ldr r3, _0802A614 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0802A618 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0802A610
	ldr r0, _0802A61C @ =0x0831E390
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, #0xeb
	bl SoundPlay
_0802A610:
	pop {r0}
	bx r0
	.align 2, 0
_0802A614: .4byte gCurrentSprite
_0802A618: .4byte gSpriteData
_0802A61C: .4byte 0x0831E390

	thumb_func_start NavScreenTurningOff
NavScreenTurningOff: @ 0x0802A620
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802A630
	ldr r1, _0802A634 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_0802A630:
	pop {r0}
	bx r0
	.align 2, 0
_0802A634: .4byte gCurrentSprite

	thumb_func_start NavPad
NavPad: @ 0x0802A638
	push {lr}
	ldr r0, _0802A658 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bls _0802A64E
	b _0802A782
_0802A64E:
	lsls r0, r0, #2
	ldr r1, _0802A65C @ =_0802A660
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A658: .4byte gCurrentSprite
_0802A65C: .4byte _0802A660
_0802A660: @ jump table
	.4byte _0802A74C @ case 0
	.4byte _0802A750 @ case 1
	.4byte _0802A756 @ case 2
	.4byte _0802A782 @ case 3
	.4byte _0802A782 @ case 4
	.4byte _0802A782 @ case 5
	.4byte _0802A782 @ case 6
	.4byte _0802A782 @ case 7
	.4byte _0802A782 @ case 8
	.4byte _0802A782 @ case 9
	.4byte _0802A782 @ case 10
	.4byte _0802A782 @ case 11
	.4byte _0802A782 @ case 12
	.4byte _0802A782 @ case 13
	.4byte _0802A782 @ case 14
	.4byte _0802A782 @ case 15
	.4byte _0802A782 @ case 16
	.4byte _0802A782 @ case 17
	.4byte _0802A782 @ case 18
	.4byte _0802A782 @ case 19
	.4byte _0802A782 @ case 20
	.4byte _0802A782 @ case 21
	.4byte _0802A782 @ case 22
	.4byte _0802A782 @ case 23
	.4byte _0802A75C @ case 24
	.4byte _0802A782 @ case 25
	.4byte _0802A762 @ case 26
	.4byte _0802A782 @ case 27
	.4byte _0802A768 @ case 28
	.4byte _0802A76E @ case 29
	.4byte _0802A772 @ case 30
	.4byte _0802A782 @ case 31
	.4byte _0802A782 @ case 32
	.4byte _0802A782 @ case 33
	.4byte _0802A782 @ case 34
	.4byte _0802A782 @ case 35
	.4byte _0802A782 @ case 36
	.4byte _0802A782 @ case 37
	.4byte _0802A782 @ case 38
	.4byte _0802A782 @ case 39
	.4byte _0802A782 @ case 40
	.4byte _0802A782 @ case 41
	.4byte _0802A782 @ case 42
	.4byte _0802A782 @ case 43
	.4byte _0802A782 @ case 44
	.4byte _0802A782 @ case 45
	.4byte _0802A782 @ case 46
	.4byte _0802A782 @ case 47
	.4byte _0802A782 @ case 48
	.4byte _0802A782 @ case 49
	.4byte _0802A782 @ case 50
	.4byte _0802A782 @ case 51
	.4byte _0802A782 @ case 52
	.4byte _0802A782 @ case 53
	.4byte _0802A782 @ case 54
	.4byte _0802A782 @ case 55
	.4byte _0802A778 @ case 56
	.4byte _0802A782 @ case 57
	.4byte _0802A77E @ case 58
_0802A74C:
	bl NavPadInit
_0802A750:
	bl NavPadIdleInit
	b _0802A782
_0802A756:
	bl NavPadIdle
	b _0802A782
_0802A75C:
	bl NavPadPressingSwitch
	b _0802A782
_0802A762:
	bl NavPadSwitchPressed
	b _0802A782
_0802A768:
	bl NavPadReleasingSwitch
	b _0802A782
_0802A76E:
	bl NavPadAfterConversationInit
_0802A772:
	bl NavPadAfterConversation
	b _0802A782
_0802A778:
	bl NavPadUsingConsole
	b _0802A782
_0802A77E:
	bl NavPadStartConversation
_0802A782:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NavConsole
NavConsole: @ 0x0802A788
	push {lr}
	ldr r0, _0802A7A4 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A7A8
	cmp r0, #2
	beq _0802A7AC
	b _0802A7B0
	.align 2, 0
_0802A7A4: .4byte gCurrentSprite
_0802A7A8:
	bl NavConsoleInit
_0802A7AC:
	bl NavConsoleIdle
_0802A7B0:
	pop {r0}
	bx r0

	thumb_func_start NavConsoleScreen
NavConsoleScreen: @ 0x0802A7B4
	push {lr}
	ldr r0, _0802A7D0 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A7D4
	cmp r0, #2
	beq _0802A7D8
	b _0802A7DC
	.align 2, 0
_0802A7D0: .4byte gCurrentSprite
_0802A7D4:
	bl NavConsoleScreenInit
_0802A7D8:
	bl NavConsoleScreenIdle
_0802A7DC:
	pop {r0}
	bx r0

	thumb_func_start NavScreen
NavScreen: @ 0x0802A7E0
	push {lr}
	ldr r0, _0802A800 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0802A812
	cmp r0, #2
	bgt _0802A804
	cmp r0, #0
	beq _0802A80E
	b _0802A822
	.align 2, 0
_0802A800: .4byte gCurrentSprite
_0802A804:
	cmp r0, #0x18
	beq _0802A818
	cmp r0, #0x1a
	beq _0802A81E
	b _0802A822
_0802A80E:
	bl NavScreenInit
_0802A812:
	bl NavScreenTurningOn
	b _0802A822
_0802A818:
	bl NavScreenIdle
	b _0802A822
_0802A81E:
	bl NavScreenTurningOff
_0802A822:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start TrySpawnMessageBanner
TrySpawnMessageBanner: @ 0x0802A828
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r2, #0x80
	movs r3, #0
	ldr r0, _0802A844 @ =gSpritesetSpriteIds
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x21
	bne _0802A84C
	ldr r0, _0802A848 @ =gSpritesetSpriteGfxSlots
	b _0802A862
	.align 2, 0
_0802A844: .4byte gSpritesetSpriteIds
_0802A848: .4byte gSpritesetSpriteGfxSlots
_0802A84C:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xe
	bhi _0802A864
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _0802A84C
	ldr r0, _0802A888 @ =gSpritesetSpriteGfxSlots
	adds r0, r3, r0
_0802A862:
	ldrb r2, [r0]
_0802A864:
	cmp r2, #7
	bhi _0802A890
	ldr r1, _0802A88C @ =gSamusData
	ldrh r0, [r1, #0x18]
	str r0, [sp]
	ldrh r0, [r1, #0x16]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x21
	adds r1, r5, #0
	movs r3, #0x10
	bl SpriteSpawnPrimary
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _0802A892
	.align 2, 0
_0802A888: .4byte gSpritesetSpriteGfxSlots
_0802A88C: .4byte gSamusData
_0802A890:
	movs r3, #0x18
_0802A892:
	adds r0, r3, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start MessageBannerInit
MessageBannerInit: @ 0x0802A89C
	push {r4, r5, r6, lr}
	ldr r1, _0802A920 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r0, #2
	ands r0, r2
	mov ip, r1
	cmp r0, #0
	bne _0802A8B6
	movs r0, #2
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #0x1e]
_0802A8B6:
	mov r0, ip
	ldrb r6, [r0, #0x1e]
	ldrh r0, [r0]
	movs r3, #0x10
	movs r5, #0
	movs r4, #0
	orrs r0, r3
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x21
	strb r5, [r0]
	adds r0, #4
	strb r5, [r0]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x29
	movs r0, #0x80
	strb r0, [r1]
	ldr r1, _0802A924 @ =0x0000FFFC
	mov r2, ip
	strh r1, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldr r0, _0802A928 @ =0x0831F758
	str r0, [r2, #0x18]
	strb r5, [r2, #0x1c]
	strh r4, [r2, #0x16]
	movs r0, #9
	strh r0, [r2, #6]
	mov r1, ip
	adds r1, #0x2e
	movs r0, #8
	strb r0, [r1]
	cmp r6, #0xc
	bne _0802A92C
	adds r1, #1
	movs r0, #1
	strb r0, [r1]
	b _0802A932
	.align 2, 0
_0802A920: .4byte gCurrentSprite
_0802A924: .4byte 0x0000FFFC
_0802A928: .4byte 0x0831F758
_0802A92C:
	mov r0, ip
	adds r0, #0x2f
	strb r5, [r0]
_0802A932:
	adds r0, r6, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0802A9A2
	movs r3, #0x80
	movs r2, #0
	ldr r0, _0802A954 @ =gSpritesetSpriteIds
	ldrb r1, [r0]
	adds r4, r0, #0
	ldr r5, _0802A958 @ =gPreventMovementTimer
	cmp r1, #0x21
	bne _0802A960
	ldr r0, _0802A95C @ =gSpritesetSpriteGfxSlots
	b _0802A976
	.align 2, 0
_0802A954: .4byte gSpritesetSpriteIds
_0802A958: .4byte gPreventMovementTimer
_0802A95C: .4byte gSpritesetSpriteGfxSlots
_0802A960:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xe
	bhi _0802A978
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _0802A960
	ldr r0, _0802A98C @ =gSpritesetSpriteGfxSlots
	adds r0, r2, r0
_0802A976:
	ldrb r3, [r0]
_0802A978:
	cmp r3, #7
	bhi _0802A990
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	strb r3, [r0, #0x1f]
	b _0802A998
	.align 2, 0
_0802A98C: .4byte gSpritesetSpriteGfxSlots
_0802A990:
	mov r1, ip
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_0802A998:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r1, #0
	strh r0, [r5]
	b _0802A9AA
_0802A9A2:
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
_0802A9AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start MessageBannerGfxInit
MessageBannerGfxInit: @ 0x0802A9B0
	push {lr}
	ldr r2, _0802A9D0 @ =gCurrentSprite
	ldrh r0, [r2, #6]
	subs r0, #1
	strh r0, [r2, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0802A9D4
	ldrb r1, [r2, #0x1f]
	ldrh r2, [r2, #6]
	movs r0, #0x21
	bl SpriteLoadGfx
	b _0802A9E2
	.align 2, 0
_0802A9D0: .4byte gCurrentSprite
_0802A9D4:
	cmp r0, #8
	bne _0802A9E2
	ldrb r1, [r2, #0x1f]
	movs r0, #0x21
	movs r2, #2
	bl SpriteLoadPal
_0802A9E2:
	ldr r3, _0802A9FC @ =gCurrentSprite
	ldrh r2, [r3, #6]
	cmp r2, #0
	bne _0802A9F6
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
_0802A9F6:
	pop {r0}
	bx r0
	.align 2, 0
_0802A9FC: .4byte gCurrentSprite

	thumb_func_start MessageBannerPopUp
MessageBannerPopUp: @ 0x0802AA00
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, _0802AA34 @ =gCurrentSprite
	ldrb r6, [r4, #0x1e]
	adds r2, r4, #0
	adds r2, #0x2e
	ldrb r1, [r2]
	adds r5, r1, #0
	cmp r5, #0
	beq _0802AA92
	ldrb r0, [r4, #0x1c]
	subs r0, #1
	strb r0, [r4, #0x1c]
	subs r0, r1, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802AA66
	ldrh r1, [r4]
	ldr r0, _0802AA38 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
	cmp r6, #0
	bne _0802AA3C
	movs r0, #0x10
	b _0802AA54
	.align 2, 0
_0802AA34: .4byte gCurrentSprite
_0802AA38: .4byte 0x0000FFFB
_0802AA3C:
	subs r0, r6, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0802AA5C
	cmp r6, #7
	bne _0802AA52
	movs r0, #3
	movs r1, #0xa
	bl PlayMusic
_0802AA52:
	movs r0, #0x3b
_0802AA54:
	movs r1, #0
	bl unk_38a8
	b _0802AA66
_0802AA5C:
	cmp r0, #7
	bls _0802AA66
	movs r0, #0x14
	bl SoundPlay_3b1c
_0802AA66:
	ldr r1, _0802AA84 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #7
	bhi _0802AB0A
	cmp r6, #0
	beq _0802AA88
	ldrb r1, [r1, #0x1f]
	adds r2, r0, #0
	adds r0, r6, #0
	bl TextDrawMessageBanner
	b _0802AB0A
	.align 2, 0
_0802AA84: .4byte gCurrentSprite
_0802AA88:
	ldrb r0, [r1, #0x1f]
	ldrb r1, [r2]
	bl DisplayMessage
	b _0802AB0A
_0802AA92:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802AB0A
	ldr r0, _0802AAB8 @ =0x0831F808
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r5, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	cmp r6, #0
	bne _0802AABC
	movs r0, #0xb9
	lsls r0, r0, #1
	strh r0, [r4, #6]
	b _0802AB0A
	.align 2, 0
_0802AAB8: .4byte 0x0831F808
_0802AABC:
	cmp r6, #0xc
	beq _0802AAC4
	cmp r6, #0xe
	bne _0802AAE0
_0802AAC4:
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	movs r0, #0x3f
	str r0, [sp]
	movs r0, #0x96
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x26
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0802AAF0
_0802AAE0:
	adds r0, r6, #0
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0802AAF0
	bl EscapeStart
_0802AAF0:
	subs r0, r6, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0802AB04
	ldr r1, _0802AB00 @ =gCurrentSprite
	movs r0, #0xb4
	b _0802AB08
	.align 2, 0
_0802AB00: .4byte gCurrentSprite
_0802AB04:
	ldr r1, _0802AB14 @ =gCurrentSprite
	movs r0, #0x5a
_0802AB08:
	strh r0, [r1, #6]
_0802AB0A:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802AB14: .4byte gCurrentSprite

	thumb_func_start MessageBannerStatic
MessageBannerStatic: @ 0x0802AB18
	push {r4, r5, lr}
	ldr r1, _0802AB38 @ =gCurrentSprite
	ldrb r2, [r1, #0x1e]
	adds r4, r2, #0
	ldr r5, _0802AB3C @ =gPreventMovementTimer
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r0, r3, #0
	strh r0, [r5]
	ldrh r0, [r1, #6]
	cmp r0, #0
	beq _0802AB40
	subs r0, #1
	strh r0, [r1, #6]
	b _0802AB96
	.align 2, 0
_0802AB38: .4byte gCurrentSprite
_0802AB3C: .4byte gPreventMovementTimer
_0802AB40:
	cmp r2, #0xc
	beq _0802AB96
	cmp r2, #0xe
	beq _0802AB96
	ldr r0, _0802AB68 @ =gButtonInput
	ldrh r0, [r0]
	movs r3, #0xf3
	ands r3, r0
	cmp r3, #0
	beq _0802AB82
	adds r1, #0x24
	movs r0, #0x19
	strb r0, [r1]
	cmp r2, #0
	bne _0802AB6C
	bl ProjectileLoadBeamGraphics
	bl ProjectileLoadMissileGraphics
	b _0802AB96
	.align 2, 0
_0802AB68: .4byte gButtonInput
_0802AB6C:
	cmp r2, #0xa
	bne _0802AB74
	movs r0, #0x17
	b _0802AB7A
_0802AB74:
	cmp r2, #0xb
	bne _0802AB96
	movs r0, #0x38
_0802AB7A:
	movs r1, #0xa
	bl PlayMusic
	b _0802AB96
_0802AB82:
	cmp r4, #8
	bne _0802AB96
	ldr r0, _0802AB9C @ =gSamusData
	ldrb r0, [r0, #1]
	cmp r0, #0x3b
	bne _0802AB96
	strh r3, [r5]
	adds r1, #0x24
	movs r0, #0x19
	strb r0, [r1]
_0802AB96:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802AB9C: .4byte gSamusData

	thumb_func_start MessageBannerRemovalInit
MessageBannerRemovalInit: @ 0x0802ABA0
	push {lr}
	ldr r0, _0802ABD8 @ =gCurrentSprite
	ldrb r2, [r0, #0x1e]
	cmp r2, #8
	beq _0802ABC0
	ldr r1, _0802ABDC @ =gPreventMovementTimer
	movs r0, #0
	strh r0, [r1]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _0802ABC0
	bl FinishCollectingTank
_0802ABC0:
	ldr r1, _0802ABD8 @ =gCurrentSprite
	ldr r0, _0802ABE0 @ =0x0831F7B0
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802ABD8: .4byte gCurrentSprite
_0802ABDC: .4byte gPreventMovementTimer
_0802ABE0: .4byte 0x0831F7B0

	thumb_func_start MesageBannerRemoval
MesageBannerRemoval: @ 0x0802ABE4
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802AC12
	ldr r1, _0802AC18 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r1, #0x1e]
	cmp r0, #0xe
	bne _0802AC12
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #1
	bne _0802AC12
	ldr r1, _0802AC1C @ =gPauseScreenFlag
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0802AC20 @ =gSubGameMode1
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0802AC12:
	pop {r0}
	bx r0
	.align 2, 0
_0802AC18: .4byte gCurrentSprite
_0802AC1C: .4byte gPauseScreenFlag
_0802AC20: .4byte gSubGameMode1

	thumb_func_start MessageBanner
MessageBanner: @ 0x0802AC24
	push {lr}
	ldr r0, _0802AC44 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi _0802ACDA
	lsls r0, r0, #2
	ldr r1, _0802AC48 @ =_0802AC4C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802AC44: .4byte gCurrentSprite
_0802AC48: .4byte _0802AC4C
_0802AC4C: @ jump table
	.4byte _0802ACB8 @ case 0
	.4byte _0802ACBE @ case 1
	.4byte _0802ACC4 @ case 2
	.4byte _0802ACDA @ case 3
	.4byte _0802ACDA @ case 4
	.4byte _0802ACDA @ case 5
	.4byte _0802ACDA @ case 6
	.4byte _0802ACDA @ case 7
	.4byte _0802ACDA @ case 8
	.4byte _0802ACDA @ case 9
	.4byte _0802ACDA @ case 10
	.4byte _0802ACDA @ case 11
	.4byte _0802ACDA @ case 12
	.4byte _0802ACDA @ case 13
	.4byte _0802ACDA @ case 14
	.4byte _0802ACDA @ case 15
	.4byte _0802ACDA @ case 16
	.4byte _0802ACDA @ case 17
	.4byte _0802ACDA @ case 18
	.4byte _0802ACDA @ case 19
	.4byte _0802ACDA @ case 20
	.4byte _0802ACDA @ case 21
	.4byte _0802ACDA @ case 22
	.4byte _0802ACDA @ case 23
	.4byte _0802ACCA @ case 24
	.4byte _0802ACD0 @ case 25
	.4byte _0802ACD6 @ case 26
_0802ACB8:
	bl MessageBannerInit
	b _0802ACDA
_0802ACBE:
	bl MessageBannerGfxInit
	b _0802ACDA
_0802ACC4:
	bl MessageBannerPopUp
	b _0802ACDA
_0802ACCA:
	bl MessageBannerStatic
	b _0802ACDA
_0802ACD0:
	bl MessageBannerRemovalInit
	b _0802ACDA
_0802ACD6:
	bl MesageBannerRemoval
_0802ACDA:
	ldr r0, _0802ACE8 @ =gCurrentSprite
	movs r1, #0x36
	strh r1, [r0, #2]
	movs r1, #0x78
	strh r1, [r0, #4]
	pop {r0}
	bx r0
	.align 2, 0
_0802ACE8: .4byte gCurrentSprite

	thumb_func_start SaveYesNoCursor
SaveYesNoCursor: @ 0x0802ACEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r5, _0802AD20 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x26
	movs r1, #0
	mov r8, r1
	movs r2, #1
	strb r2, [r0]
	subs r0, #3
	ldrb r6, [r0]
	adds r7, r5, #0
	adds r7, #0x24
	ldrb r0, [r7]
	cmp r0, #0x38
	bne _0802AD10
	b _0802AE50
_0802AD10:
	cmp r0, #0x38
	bgt _0802AD24
	cmp r0, #0
	beq _0802AD32
	cmp r0, #2
	beq _0802ADB0
	b _0802AE72
	.align 2, 0
_0802AD20: .4byte gCurrentSprite
_0802AD24:
	cmp r0, #0x3a
	bne _0802AD2A
	b _0802AE5C
_0802AD2A:
	cmp r0, #0x3c
	bne _0802AD30
	b _0802AE68
_0802AD30:
	b _0802AE72
_0802AD32:
	ldrh r0, [r5]
	movs r3, #0x10
	movs r4, #0
	orrs r0, r3
	ldr r1, _0802ADA0 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r5]
	adds r0, r5, #0
	adds r0, #0x21
	strb r4, [r0]
	adds r1, r5, #0
	adds r1, #0x22
	movs r0, #3
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x25
	strb r4, [r0]
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #0x21
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x27
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	ldr r1, _0802ADA4 @ =0x0000FFFC
	strh r1, [r5, #0xa]
	movs r0, #4
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	ldr r0, _0802ADA8 @ =0x0831F730
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	mov r0, r8
	strh r0, [r5, #0x16]
	movs r0, #2
	strb r0, [r7]
	movs r0, #0x3f
	strh r0, [r5, #2]
	ldr r1, _0802ADAC @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0, #0x1e]
	cmp r0, #0xc
	beq _0802ADCA
	b _0802ADEA
	.align 2, 0
_0802ADA0: .4byte 0x0000FFFB
_0802ADA4: .4byte 0x0000FFFC
_0802ADA8: .4byte 0x0831F730
_0802ADAC: .4byte gSpriteData
_0802ADB0:
	ldr r0, _0802ADD0 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802ADD4
	ldrh r0, [r5, #4]
	cmp r0, #0x36
	beq _0802AE72
	movs r0, #0xfd
	lsls r0, r0, #1
	bl SoundPlay
_0802ADCA:
	movs r0, #0x36
	strh r0, [r5, #4]
	b _0802AE72
	.align 2, 0
_0802ADD0: .4byte gChangedInput
_0802ADD4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802ADF0
	ldrh r0, [r5, #4]
	cmp r0, #0x96
	beq _0802AE72
	movs r0, #0xfd
	lsls r0, r0, #1
	bl SoundPlay
_0802ADEA:
	movs r0, #0x96
	strh r0, [r5, #4]
	b _0802AE72
_0802ADF0:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0802AE72
	ldr r0, _0802AE28 @ =0x000001FB
	bl SoundPlay
	ldr r1, _0802AE2C @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r2, r0, r1
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x19
	strb r0, [r1]
	ldrh r0, [r5, #4]
	cmp r0, #0x36
	bne _0802AE3A
	ldrb r0, [r2, #0x1e]
	cmp r0, #0xc
	bne _0802AE30
	movs r0, #0
	bl Sram_QuickSave
	movs r0, #0x38
	strb r0, [r7]
	b _0802AE72
	.align 2, 0
_0802AE28: .4byte 0x000001FB
_0802AE2C: .4byte gSpriteData
_0802AE30:
	adds r1, r2, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	b _0802AE42
_0802AE3A:
	adds r0, r2, #0
	adds r0, #0x2f
	mov r1, r8
	strb r1, [r0]
_0802AE42:
	ldr r1, _0802AE4C @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	b _0802AE72
	.align 2, 0
_0802AE4C: .4byte gCurrentSprite
_0802AE50:
	movs r0, #1
	bl Sram_QuickSave
	movs r0, #0x3a
	strb r0, [r7]
	b _0802AE72
_0802AE5C:
	movs r0, #2
	bl Sram_QuickSave
	movs r0, #0x3c
	strb r0, [r7]
	b _0802AE72
_0802AE68:
	movs r0, #3
	bl Sram_QuickSave
	mov r0, r8
	strh r0, [r5]
_0802AE72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start DataPadInit
DataPadInit: @ 0x0802AE7C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, _0802AED0 @ =gCurrentSprite
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0802AED4 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x21
	movs r5, #1
	strb r5, [r0]
	movs r0, #0
	bl CheckDownloadedDataItem
	cmp r0, #0
	beq _0802AED8
	adds r0, r4, #0
	adds r0, #0x2f
	strb r5, [r0]
	b _0802AEE0
	.align 2, 0
_0802AED0: .4byte gCurrentSprite
_0802AED4: .4byte 0x0000FFFC
_0802AED8:
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
_0802AEE0:
	ldr r4, _0802AF1C @ =gCurrentSprite
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #0x1e
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x1f
	movs r1, #0
	bl SpriteSpawnSecondary
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802AF1C: .4byte gCurrentSprite

	thumb_func_start DataPadIdleInit
DataPadIdleInit: @ 0x0802AF20
	push {lr}
	ldr r1, _0802AF48 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802AF50
	ldr r0, _0802AF4C @ =0x083219C4
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #2
	b _0802AF58
	.align 2, 0
_0802AF48: .4byte gCurrentSprite
_0802AF4C: .4byte 0x083219C4
_0802AF50:
	ldr r0, _0802AF60 @ =0x083219D4
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x1e
_0802AF58:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802AF60: .4byte 0x083219D4

	thumb_func_start DataPadIdle
DataPadIdle: @ 0x0802AF64
	push {lr}
	bl NavPadDetectSamus
	cmp r0, #0
	beq _0802AFA4
	ldr r3, _0802AF98 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802AFAC
	subs r1, #0xa
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802AF9C @ =0x083219E4
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0802AFA0 @ =0x00000101
	bl SoundPlay
	b _0802AFAC
	.align 2, 0
_0802AF98: .4byte gCurrentSprite
_0802AF9C: .4byte 0x083219E4
_0802AFA0: .4byte 0x00000101
_0802AFA4:
	ldr r0, _0802AFB0 @ =gCurrentSprite
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
_0802AFAC:
	pop {r0}
	bx r0
	.align 2, 0
_0802AFB0: .4byte gCurrentSprite

	thumb_func_start DataPadPressingSwitch
DataPadPressingSwitch: @ 0x0802AFB4
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802AFD2
	ldr r1, _0802AFD8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1a
	strb r0, [r2]
	ldr r0, _0802AFDC @ =0x083219D4
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
_0802AFD2:
	pop {r0}
	bx r0
	.align 2, 0
_0802AFD8: .4byte gCurrentSprite
_0802AFDC: .4byte 0x083219D4

	thumb_func_start DataPadSwitchPressed
DataPadSwitchPressed: @ 0x0802AFE0
	push {r4, lr}
	bl NavPadDetectSamus
	adds r3, r0, #0
	cmp r3, #0
	beq _0802B034
	bl SpriteUtilCheckSamusMorphed
	cmp r0, #0
	bne _0802B04E
	ldr r2, _0802B028 @ =gSamusData
	ldr r4, _0802B02C @ =gCurrentSprite
	ldrh r0, [r4, #4]
	strh r0, [r2, #0x16]
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _0802B006
	movs r0, #0
	strb r0, [r2, #5]
_0802B006:
	ldr r1, _0802B030 @ =sSamusSetPoseFunctionPointer
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x20
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	b _0802B04E
	.align 2, 0
_0802B028: .4byte gSamusData
_0802B02C: .4byte gCurrentSprite
_0802B030: .4byte sSamusSetPoseFunctionPointer
_0802B034:
	ldr r1, _0802B054 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _0802B058 @ =0x08321A0C
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	movs r0, #0x81
	lsls r0, r0, #1
	bl SoundPlay
_0802B04E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B054: .4byte gCurrentSprite
_0802B058: .4byte 0x08321A0C

	thumb_func_start DataPadReleasingSwitch
DataPadReleasingSwitch: @ 0x0802B05C
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802B06A
	bl DataPadIdleInit
_0802B06A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DataPadLockingSamus
DataPadLockingSamus: @ 0x0802B070
	push {lr}
	ldr r1, _0802B0B0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802B0AC
	adds r1, #0x24
	movs r0, #0x3a
	strb r0, [r1]
	movs r0, #0x78
	strb r0, [r2]
	movs r0, #1
	bl CheckDownloadedDataItem
	ldr r1, _0802B0B4 @ =gDoorUnlockTimer
	movs r0, #0x3c
	strb r0, [r1]
	ldr r1, _0802B0B8 @ =sSamusSetPoseFunctionPointer
	ldr r0, _0802B0BC @ =gSamusData
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x37
	bl _call_via_r1
_0802B0AC:
	pop {r0}
	bx r0
	.align 2, 0
_0802B0B0: .4byte gCurrentSprite
_0802B0B4: .4byte gDoorUnlockTimer
_0802B0B8: .4byte sSamusSetPoseFunctionPointer
_0802B0BC: .4byte gSamusData

	thumb_func_start DataPadDownloadingData
DataPadDownloadingData: @ 0x0802B0C0
	push {lr}
	ldr r1, _0802B0E0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802B0DA
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
_0802B0DA:
	pop {r0}
	bx r0
	.align 2, 0
_0802B0E0: .4byte gCurrentSprite

	thumb_func_start DataPadCenterInit
DataPadCenterInit: @ 0x0802B0E4
	push {r4, lr}
	ldr r0, _0802B160 @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	mov r4, ip
	ldrh r1, [r4]
	ldr r0, _0802B164 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x28
	strb r0, [r1]
	ldr r1, _0802B168 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	ldr r2, _0802B16C @ =gSpriteData
	mov r0, ip
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B174
	ldr r0, _0802B170 @ =0x08321A44
	str r0, [r4, #0x18]
	b _0802B17A
	.align 2, 0
_0802B160: .4byte gCurrentSprite
_0802B164: .4byte 0x0000FFFB
_0802B168: .4byte 0x0000FFFC
_0802B16C: .4byte gSpriteData
_0802B170: .4byte 0x08321A44
_0802B174:
	ldr r0, _0802B180 @ =0x08321A34
	mov r1, ip
	str r0, [r1, #0x18]
_0802B17A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B180: .4byte 0x08321A34

	thumb_func_start DataPadCenterIdle
DataPadCenterIdle: @ 0x0802B184
	push {lr}
	ldr r2, _0802B1CC @ =gSpriteData
	ldr r3, _0802B1D0 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x38
	bne _0802B1C8
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802B1C8
	subs r1, #0xa
	movs r0, #0x18
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0802B1D4 @ =0x08321A64
	str r0, [r3, #0x18]
	movs r0, #0x85
	lsls r0, r0, #1
	bl SoundPlay
_0802B1C8:
	pop {r0}
	bx r0
	.align 2, 0
_0802B1CC: .4byte gSpriteData
_0802B1D0: .4byte gCurrentSprite
_0802B1D4: .4byte 0x08321A64

	thumb_func_start DataPadCenterEngaging
DataPadCenterEngaging: @ 0x0802B1D8
	push {lr}
	ldr r2, _0802B214 @ =gSpriteData
	ldr r3, _0802B218 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0802B20E
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x1a
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	ldr r0, _0802B21C @ =0x08321A44
	str r0, [r3, #0x18]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #0x14
	strb r0, [r1]
_0802B20E:
	pop {r0}
	bx r0
	.align 2, 0
_0802B214: .4byte gSpriteData
_0802B218: .4byte gCurrentSprite
_0802B21C: .4byte 0x08321A44

	thumb_func_start DataPadCenterDownloadingData
DataPadCenterDownloadingData: @ 0x0802B220
	push {lr}
	ldr r3, _0802B24C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802B246
	adds r0, r3, #0
	adds r0, #0x24
	movs r1, #0x1c
	strb r1, [r0]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0802B250 @ =0x08321A34
	str r0, [r3, #0x18]
_0802B246:
	pop {r0}
	bx r0
	.align 2, 0
_0802B24C: .4byte gCurrentSprite
_0802B250: .4byte 0x08321A34

	thumb_func_start DataPadSidesInit
DataPadSidesInit: @ 0x0802B254
	push {r4, lr}
	ldr r0, _0802B2B8 @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	mov r4, ip
	ldrh r1, [r4]
	ldr r0, _0802B2BC @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x28
	strb r0, [r1]
	ldr r1, _0802B2C0 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xd
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802B2C4 @ =0x08321A8C
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B2B8: .4byte gCurrentSprite
_0802B2BC: .4byte 0x0000FFFB
_0802B2C0: .4byte 0x0000FFFC
_0802B2C4: .4byte 0x08321A8C

	thumb_func_start DataPadSidesIdle
DataPadSidesIdle: @ 0x0802B2C8
	push {lr}
	ldr r2, _0802B304 @ =gSpriteData
	ldr r3, _0802B308 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x38
	bne _0802B2FE
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x18
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	ldr r0, _0802B30C @ =0x08321A9C
	str r0, [r3, #0x18]
	movs r0, #0x84
	lsls r0, r0, #1
	bl SoundPlay
_0802B2FE:
	pop {r0}
	bx r0
	.align 2, 0
_0802B304: .4byte gSpriteData
_0802B308: .4byte gCurrentSprite
_0802B30C: .4byte 0x08321A9C

	thumb_func_start DataPadSidesEngaging
DataPadSidesEngaging: @ 0x0802B310
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802B32E
	ldr r1, _0802B334 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x1a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0802B338 @ =0x08321ADC
	str r0, [r1, #0x18]
_0802B32E:
	pop {r0}
	bx r0
	.align 2, 0
_0802B334: .4byte gCurrentSprite
_0802B338: .4byte 0x08321ADC

	thumb_func_start DataPadSidesDownloadingData
DataPadSidesDownloadingData: @ 0x0802B33C
	push {r4, lr}
	ldr r2, _0802B38C @ =gSpriteData
	ldr r3, _0802B390 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0802B386
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #0x14
	strb r0, [r1]
	subs r1, #0xa
	movs r0, #0x1c
	strb r0, [r1]
	ldr r1, _0802B394 @ =sSamusSetPoseFunctionPointer
	ldr r4, _0802B398 @ =gSamusData
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x39
	bl _call_via_r1
	movs r0, #0xa
	strh r0, [r4, #0x10]
	ldr r1, _0802B39C @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
_0802B386:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802B38C: .4byte gSpriteData
_0802B390: .4byte gCurrentSprite
_0802B394: .4byte sSamusSetPoseFunctionPointer
_0802B398: .4byte gSamusData
_0802B39C: .4byte gPreventMovementTimer

	thumb_func_start DataPadSidesDoneDownloadingData
DataPadSidesDoneDownloadingData: @ 0x0802B3A0
	push {lr}
	ldr r3, _0802B3D0 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802B3CA
	subs r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0802B3D4 @ =0x08321ABC
	str r0, [r3, #0x18]
	ldr r0, _0802B3D8 @ =0x00000109
	bl SoundPlay
_0802B3CA:
	pop {r0}
	bx r0
	.align 2, 0
_0802B3D0: .4byte gCurrentSprite
_0802B3D4: .4byte 0x08321ABC
_0802B3D8: .4byte 0x00000109

	thumb_func_start DataPadSidesDisengaging
DataPadSidesDisengaging: @ 0x0802B3DC
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802B400
	ldr r1, _0802B404 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x46
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0802B408 @ =0x08321A8C
	str r0, [r1, #0x18]
	movs r0, #0
	bl TrySpawnMessageBanner
_0802B400:
	pop {r0}
	bx r0
	.align 2, 0
_0802B404: .4byte gCurrentSprite
_0802B408: .4byte 0x08321A8C

	thumb_func_start DataPad
DataPad: @ 0x0802B40C
	push {lr}
	ldr r0, _0802B42C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bls _0802B422
	b _0802B54C
_0802B422:
	lsls r0, r0, #2
	ldr r1, _0802B430 @ =_0802B434
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B42C: .4byte gCurrentSprite
_0802B430: .4byte _0802B434
_0802B434: @ jump table
	.4byte _0802B520 @ case 0
	.4byte _0802B524 @ case 1
	.4byte _0802B52A @ case 2
	.4byte _0802B54C @ case 3
	.4byte _0802B54C @ case 4
	.4byte _0802B54C @ case 5
	.4byte _0802B54C @ case 6
	.4byte _0802B54C @ case 7
	.4byte _0802B54C @ case 8
	.4byte _0802B54C @ case 9
	.4byte _0802B54C @ case 10
	.4byte _0802B54C @ case 11
	.4byte _0802B54C @ case 12
	.4byte _0802B54C @ case 13
	.4byte _0802B54C @ case 14
	.4byte _0802B54C @ case 15
	.4byte _0802B54C @ case 16
	.4byte _0802B54C @ case 17
	.4byte _0802B54C @ case 18
	.4byte _0802B54C @ case 19
	.4byte _0802B54C @ case 20
	.4byte _0802B54C @ case 21
	.4byte _0802B54C @ case 22
	.4byte _0802B54C @ case 23
	.4byte _0802B530 @ case 24
	.4byte _0802B54C @ case 25
	.4byte _0802B536 @ case 26
	.4byte _0802B54C @ case 27
	.4byte _0802B53C @ case 28
	.4byte _0802B54C @ case 29
	.4byte _0802B54C @ case 30
	.4byte _0802B54C @ case 31
	.4byte _0802B54C @ case 32
	.4byte _0802B54C @ case 33
	.4byte _0802B54C @ case 34
	.4byte _0802B54C @ case 35
	.4byte _0802B54C @ case 36
	.4byte _0802B54C @ case 37
	.4byte _0802B54C @ case 38
	.4byte _0802B54C @ case 39
	.4byte _0802B54C @ case 40
	.4byte _0802B54C @ case 41
	.4byte _0802B54C @ case 42
	.4byte _0802B54C @ case 43
	.4byte _0802B54C @ case 44
	.4byte _0802B54C @ case 45
	.4byte _0802B54C @ case 46
	.4byte _0802B54C @ case 47
	.4byte _0802B54C @ case 48
	.4byte _0802B54C @ case 49
	.4byte _0802B54C @ case 50
	.4byte _0802B54C @ case 51
	.4byte _0802B54C @ case 52
	.4byte _0802B54C @ case 53
	.4byte _0802B54C @ case 54
	.4byte _0802B54C @ case 55
	.4byte _0802B542 @ case 56
	.4byte _0802B54C @ case 57
	.4byte _0802B548 @ case 58
_0802B520:
	bl DataPadInit
_0802B524:
	bl DataPadIdleInit
	b _0802B54C
_0802B52A:
	bl DataPadIdle
	b _0802B54C
_0802B530:
	bl DataPadPressingSwitch
	b _0802B54C
_0802B536:
	bl DataPadSwitchPressed
	b _0802B54C
_0802B53C:
	bl DataPadReleasingSwitch
	b _0802B54C
_0802B542:
	bl DataPadLockingSamus
	b _0802B54C
_0802B548:
	bl DataPadDownloadingData
_0802B54C:
	pop {r0}
	bx r0

	thumb_func_start DataPadCenter
DataPadCenter: @ 0x0802B550
	push {lr}
	ldr r0, _0802B570 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0802B582
	cmp r0, #2
	bgt _0802B574
	cmp r0, #0
	beq _0802B57E
	b _0802B592
	.align 2, 0
_0802B570: .4byte gCurrentSprite
_0802B574:
	cmp r0, #0x18
	beq _0802B588
	cmp r0, #0x1a
	beq _0802B58E
	b _0802B592
_0802B57E:
	bl DataPadCenterInit
_0802B582:
	bl DataPadCenterIdle
	b _0802B592
_0802B588:
	bl DataPadCenterEngaging
	b _0802B592
_0802B58E:
	bl DataPadCenterDownloadingData
_0802B592:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DataPadSides
DataPadSides: @ 0x0802B598
	push {lr}
	ldr r0, _0802B5B8 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1e
	bhi _0802B65C
	lsls r0, r0, #2
	ldr r1, _0802B5BC @ =_0802B5C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B5B8: .4byte gCurrentSprite
_0802B5BC: .4byte _0802B5C0
_0802B5C0: @ jump table
	.4byte _0802B63C @ case 0
	.4byte _0802B65C @ case 1
	.4byte _0802B640 @ case 2
	.4byte _0802B65C @ case 3
	.4byte _0802B65C @ case 4
	.4byte _0802B65C @ case 5
	.4byte _0802B65C @ case 6
	.4byte _0802B65C @ case 7
	.4byte _0802B65C @ case 8
	.4byte _0802B65C @ case 9
	.4byte _0802B65C @ case 10
	.4byte _0802B65C @ case 11
	.4byte _0802B65C @ case 12
	.4byte _0802B65C @ case 13
	.4byte _0802B65C @ case 14
	.4byte _0802B65C @ case 15
	.4byte _0802B65C @ case 16
	.4byte _0802B65C @ case 17
	.4byte _0802B65C @ case 18
	.4byte _0802B65C @ case 19
	.4byte _0802B65C @ case 20
	.4byte _0802B65C @ case 21
	.4byte _0802B65C @ case 22
	.4byte _0802B65C @ case 23
	.4byte _0802B646 @ case 24
	.4byte _0802B65C @ case 25
	.4byte _0802B64C @ case 26
	.4byte _0802B65C @ case 27
	.4byte _0802B652 @ case 28
	.4byte _0802B65C @ case 29
	.4byte _0802B658 @ case 30
_0802B63C:
	bl DataPadSidesInit
_0802B640:
	bl DataPadSidesIdle
	b _0802B65C
_0802B646:
	bl DataPadSidesEngaging
	b _0802B65C
_0802B64C:
	bl DataPadSidesDownloadingData
	b _0802B65C
_0802B652:
	bl DataPadSidesDoneDownloadingData
	b _0802B65C
_0802B658:
	bl DataPadSidesDisengaging
_0802B65C:
	pop {r0}
	bx r0

	thumb_func_start ZebesianWallSetSideHitboxs
ZebesianWallSetSideHitboxs: @ 0x0802B660
	push {lr}
	ldr r2, _0802B678 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802B680
	ldr r0, _0802B67C @ =0x0000FFB0
	strh r0, [r2, #0xe]
	movs r0, #4
	b _0802B686
	.align 2, 0
_0802B678: .4byte gCurrentSprite
_0802B67C: .4byte 0x0000FFB0
_0802B680:
	ldr r0, _0802B68C @ =0x0000FFFC
	strh r0, [r2, #0xe]
	movs r0, #0x50
_0802B686:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_0802B68C: .4byte 0x0000FFFC

	thumb_func_start unk_2b690
unk_2b690: @ 0x0802B690
	push {lr}
	ldr r0, _0802B6A4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #0xc
	bhi _0802B728
	lsls r0, r0, #2
	ldr r1, _0802B6A8 @ =_0802B6AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B6A4: .4byte gSpriteRandomNumber
_0802B6A8: .4byte _0802B6AC
_0802B6AC: @ jump table
	.4byte _0802B6E0 @ case 0
	.4byte _0802B6E0 @ case 1
	.4byte _0802B6E0 @ case 2
	.4byte _0802B6E0 @ case 3
	.4byte _0802B6F4 @ case 4
	.4byte _0802B6F4 @ case 5
	.4byte _0802B6F4 @ case 6
	.4byte _0802B6F4 @ case 7
	.4byte _0802B710 @ case 8
	.4byte _0802B710 @ case 9
	.4byte _0802B71C @ case 10
	.4byte _0802B71C @ case 11
	.4byte _0802B71C @ case 12
_0802B6E0:
	ldr r1, _0802B6EC @ =gCurrentSprite
	ldrh r2, [r1]
	ldr r0, _0802B6F0 @ =0x0000FDFF
	ands r0, r2
	b _0802B700
	.align 2, 0
_0802B6EC: .4byte gCurrentSprite
_0802B6F0: .4byte 0x0000FDFF
_0802B6F4:
	ldr r1, _0802B70C @ =gCurrentSprite
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r0, r2
_0802B700:
	strh r0, [r1]
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	b _0802B730
	.align 2, 0
_0802B70C: .4byte gCurrentSprite
_0802B710:
	ldr r0, _0802B718 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x19
	b _0802B72E
	.align 2, 0
_0802B718: .4byte gCurrentSprite
_0802B71C:
	ldr r0, _0802B724 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x29
	b _0802B72E
	.align 2, 0
_0802B724: .4byte gCurrentSprite
_0802B728:
	ldr r0, _0802B734 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #7
_0802B72E:
	strb r1, [r0]
_0802B730:
	pop {r0}
	bx r0
	.align 2, 0
_0802B734: .4byte gCurrentSprite

	thumb_func_start ZebesianWallInit
ZebesianWallInit: @ 0x0802B738
	push {r4, r5, r6, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r4, _0802B78C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x25
	movs r3, #0
	movs r5, #2
	strb r5, [r0]
	ldr r2, _0802B790 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r6, #0
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _0802B794 @ =0x083236E0
	str r0, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r3, [r4, #0x16]
	subs r1, #5
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0802B798
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r4, #8]
	b _0802B7DA
	.align 2, 0
_0802B78C: .4byte gCurrentSprite
_0802B790: .4byte sPrimarySpriteStats
_0802B794: .4byte 0x083236E0
_0802B798:
	adds r2, r4, #0
	adds r2, #0x21
	movs r0, #1
	strb r0, [r2]
	strb r5, [r1]
	ldrh r0, [r4, #2]
	strh r0, [r4, #6]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0802B7CC @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0802B7D0
	ldrh r0, [r4]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #4]
	adds r0, #0x20
	b _0802B7D4
	.align 2, 0
_0802B7CC: .4byte gPreviousCollisionCheck
_0802B7D0:
	ldrh r0, [r4, #4]
	subs r0, #0x20
_0802B7D4:
	strh r0, [r4, #4]
	bl SpriteUtilChooseRandomXDirection
_0802B7DA:
	ldr r2, _0802B800 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0802B814
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0802B804
	strh r0, [r2]
	b _0802B820
	.align 2, 0
_0802B800: .4byte gCurrentSprite
_0802B804:
	adds r0, r2, #0
	adds r0, #0x36
	strb r3, [r0]
	ldr r0, _0802B810 @ =0x0000FF90
	b _0802B816
	.align 2, 0
_0802B810: .4byte 0x0000FF90
_0802B814:
	ldr r0, _0802B828 @ =0x0000FFA0
_0802B816:
	strh r0, [r2, #0xa]
	movs r0, #0x50
	strh r0, [r2, #0xc]
	bl ZebesianWallSetSideHitboxs
_0802B820:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802B828: .4byte 0x0000FFA0

	thumb_func_start ZebesianWallFormingFromX
ZebesianWallFormingFromX: @ 0x0802B82C
	push {lr}
	ldr r3, _0802B854 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r3, #8]
	subs r0, #1
	strh r0, [r3, #8]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B860
	ldr r2, _0802B858 @ =gWrittenToMosaic_H
	ldr r1, _0802B85C @ =sXParasiteMosaicValues
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	b _0802B874
	.align 2, 0
_0802B854: .4byte gCurrentSprite
_0802B858: .4byte gWrittenToMosaic_H
_0802B85C: .4byte sXParasiteMosaicValues
_0802B860:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldrh r1, [r3]
	ldr r0, _0802B878 @ =0x0000FFDF
	ands r0, r1
	ldr r1, _0802B87C @ =0x00007FFF
	ands r0, r1
	strh r0, [r3]
_0802B874:
	pop {r0}
	bx r0
	.align 2, 0
_0802B878: .4byte 0x0000FFDF
_0802B87C: .4byte 0x00007FFF

	thumb_func_start ZebesianWallDeath
ZebesianWallDeath: @ 0x0802B880
	push {lr}
	sub sp, #0x10
	ldr r2, _0802B89C @ =gCurrentSprite
	ldrh r0, [r2, #2]
	adds r0, #8
	strh r0, [r2, #2]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802B8A0
	ldrh r0, [r2, #4]
	subs r0, #0x28
	b _0802B8A4
	.align 2, 0
_0802B89C: .4byte gCurrentSprite
_0802B8A0:
	ldrh r0, [r2, #4]
	adds r0, #0x28
_0802B8A4:
	strh r0, [r2, #4]
	ldrb r1, [r2, #0x1d]
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r2, #2]
	subs r0, #0x38
	str r0, [sp, #4]
	ldrh r0, [r2, #4]
	str r0, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	add sp, #0x10
	pop {r0}
	bx r0

	thumb_func_start ZebesianWallMovingVerticallyInit
ZebesianWallMovingVerticallyInit: @ 0x0802B8D0
	ldr r0, _0802B8EC @ =gCurrentSprite
	ldr r1, _0802B8F0 @ =0x083236E0
	str r1, [r0, #0x18]
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
	adds r2, r0, #0
	adds r2, #0x2e
	movs r1, #0x40
	strb r1, [r2]
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	bx lr
	.align 2, 0
_0802B8EC: .4byte gCurrentSprite
_0802B8F0: .4byte 0x083236E0

	thumb_func_start ZebesianWallMoveVertically
ZebesianWallMoveVertically: @ 0x0802B8F4
	push {lr}
	movs r3, #0
	ldr r2, _0802B92C @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	adds r1, r2, #0
	cmp r0, #0
	beq _0802B930
	ldrh r0, [r1, #6]
	adds r0, #0x80
	ldrh r2, [r1, #2]
	cmp r0, r2
	ble _0802B952
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802B952
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	b _0802B954
	.align 2, 0
_0802B92C: .4byte gCurrentSprite
_0802B930:
	ldrh r0, [r1, #6]
	subs r0, #0xc0
	ldrh r2, [r1, #2]
	cmp r0, r2
	bge _0802B952
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802B952
	ldrh r0, [r1, #2]
	subs r0, #1
	strh r0, [r1, #2]
	b _0802B954
_0802B952:
	movs r3, #1
_0802B954:
	ldrh r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _0802B970
	cmp r3, #0
	beq _0802B978
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	eors r0, r2
	strh r0, [r1]
	b _0802B978
_0802B970:
	cmp r3, #0
	beq _0802B978
	bl unk_2b690
_0802B978:
	pop {r0}
	bx r0

	thumb_func_start ZebesianWallTurningAroundInit
ZebesianWallTurningAroundInit: @ 0x0802B97C
	ldr r1, _0802B990 @ =gCurrentSprite
	ldr r0, _0802B994 @ =0x083237D0
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	bx lr
	.align 2, 0
_0802B990: .4byte gCurrentSprite
_0802B994: .4byte 0x083237D0

	thumb_func_start ZebesianWallTurningAround
ZebesianWallTurningAround: @ 0x0802B998
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802B9F0
	ldr r3, _0802B9D8 @ =gCurrentSprite
	ldr r0, _0802B9DC @ =0x08323850
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r2, #0
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1c
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldrh r0, [r3]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r3]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802B9E0
	ldrh r0, [r3, #4]
	adds r0, #0x80
	b _0802B9E4
	.align 2, 0
_0802B9D8: .4byte gCurrentSprite
_0802B9DC: .4byte 0x08323850
_0802B9E0:
	ldrh r0, [r3, #4]
	subs r0, #0x80
_0802B9E4:
	strh r0, [r3, #4]
	bl ZebesianWallSetSideHitboxs
	ldr r0, _0802B9F4 @ =0x0000015B
	bl SoundPlayNotAlreadyPlaying
_0802B9F0:
	pop {r0}
	bx r0
	.align 2, 0
_0802B9F4: .4byte 0x0000015B

	thumb_func_start ZebesianWallJumping
ZebesianWallJumping: @ 0x0802B9F8
	push {r4, r5, r6, lr}
	ldr r2, _0802BA28 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r5, [r0]
	ldr r4, _0802BA2C @ =0x08321B64
	lsls r0, r5, #1
	adds r3, r0, r4
	ldr r1, _0802BA30 @ =0x08321BA8
	adds r0, r0, r1
	ldrh r6, [r0]
	ldrh r0, [r2, #2]
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802BA34
	ldrh r0, [r2, #4]
	adds r0, r0, r6
	b _0802BA38
	.align 2, 0
_0802BA28: .4byte gCurrentSprite
_0802BA2C: .4byte 0x08321B64
_0802BA30: .4byte 0x08321BA8
_0802BA34:
	ldrh r0, [r2, #4]
	subs r0, r0, r6
_0802BA38:
	strh r0, [r2, #4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r2, #0
	adds r0, #0x31
	strb r5, [r0]
	lsls r0, r5, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0802BA60 @ =0x00007FFF
	cmp r1, r0
	bne _0802BA58
	bl unk_2b690
_0802BA58:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802BA60: .4byte 0x00007FFF

	thumb_func_start ZebesianWallIdleInit
ZebesianWallIdleInit: @ 0x0802BA64
	ldr r1, _0802BA78 @ =gCurrentSprite
	ldr r0, _0802BA7C @ =0x08323728
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	bx lr
	.align 2, 0
_0802BA78: .4byte gCurrentSprite
_0802BA7C: .4byte 0x08323728

	thumb_func_start ZebesianWallIdle
ZebesianWallIdle: @ 0x0802BA80
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802BA8E
	bl unk_2b690
_0802BA8E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianWallShootingInit
ZebesianWallShootingInit: @ 0x0802BA94
	ldr r1, _0802BAA8 @ =gCurrentSprite
	ldr r0, _0802BAAC @ =0x08323890
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bx lr
	.align 2, 0
_0802BAA8: .4byte gCurrentSprite
_0802BAAC: .4byte 0x08323890

	thumb_func_start ZebesianWallShooting
ZebesianWallShooting: @ 0x0802BAB0
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _0802BAF8 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0, #0x16]
	cmp r0, #0x13
	bne _0802BB1A
	mov r1, ip
	ldrb r0, [r1, #0x1c]
	cmp r0, #1
	bne _0802BB1A
	ldrh r1, [r1]
	movs r4, #0x40
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0802BAFC
	mov r0, ip
	ldrb r2, [r0, #0x1f]
	adds r0, #0x23
	ldrb r3, [r0]
	mov r1, ip
	ldrh r0, [r1, #2]
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x88
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #5
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0802BB1A
	.align 2, 0
_0802BAF8: .4byte gCurrentSprite
_0802BAFC:
	mov r4, ip
	ldrb r2, [r4, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x88
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #5
	movs r1, #0
	bl SpriteSpawnSecondary
_0802BB1A:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802BB26
	bl unk_2b690
_0802BB26:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianBeamInit
ZebesianBeamInit: @ 0x0802BB30
	push {r4, r5, r6, lr}
	ldr r0, _0802BBA0 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0]
	ldr r3, _0802BBA4 @ =0x0000FFFB
	ands r3, r0
	movs r5, #0
	movs r4, #0
	mov r1, ip
	strh r3, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	movs r2, #0x30
	strb r2, [r0]
	ldr r0, _0802BBA8 @ =0x0000FFF8
	mov r6, ip
	strh r0, [r6, #0xa]
	strh r1, [r6, #0xc]
	ldr r0, _0802BBAC @ =0x08323998
	str r0, [r6, #0x18]
	strb r5, [r6, #0x1c]
	strh r4, [r6, #0x16]
	mov r0, ip
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r1, ip
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	subs r1, #1
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _0802BBB4
	ldr r0, _0802BBB0 @ =0x0000FFD0
	strh r0, [r6, #0xe]
	adds r0, #0x20
	strh r0, [r6, #0x10]
	b _0802BBBC
	.align 2, 0
_0802BBA0: .4byte gCurrentSprite
_0802BBA4: .4byte 0x0000FFFB
_0802BBA8: .4byte 0x0000FFF8
_0802BBAC: .4byte 0x08323998
_0802BBB0: .4byte 0x0000FFD0
_0802BBB4:
	movs r0, #0x10
	mov r1, ip
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x10]
_0802BBBC:
	ldr r0, _0802BBC8 @ =0x0000015D
	bl SoundPlayNotAlreadyPlaying
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802BBC8: .4byte 0x0000015D

	thumb_func_start ZebesianBeamSpawning
ZebesianBeamSpawning: @ 0x0802BBCC
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802BC10
	ldr r2, _0802BBFC @ =gCurrentSprite
	ldr r0, _0802BC00 @ =0x083239C0
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802BC08
	ldr r0, _0802BC04 @ =0x0000FFA0
	strh r0, [r2, #0xe]
	adds r0, #0x40
	b _0802BC0E
	.align 2, 0
_0802BBFC: .4byte gCurrentSprite
_0802BC00: .4byte 0x083239C0
_0802BC04: .4byte 0x0000FFA0
_0802BC08:
	movs r0, #0x20
	strh r0, [r2, #0xe]
	movs r0, #0x60
_0802BC0E:
	strh r0, [r2, #0x10]
_0802BC10:
	pop {r0}
	bx r0

	thumb_func_start ZebesianBeamExtending
ZebesianBeamExtending: @ 0x0802BC14
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802BC58
	ldr r2, _0802BC44 @ =gCurrentSprite
	ldr r0, _0802BC48 @ =0x08323968
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802BC50
	ldr r0, _0802BC4C @ =0x0000FF60
	strh r0, [r2, #0xe]
	adds r0, #0x80
	b _0802BC56
	.align 2, 0
_0802BC44: .4byte gCurrentSprite
_0802BC48: .4byte 0x08323968
_0802BC4C: .4byte 0x0000FF60
_0802BC50:
	movs r0, #0x20
	strh r0, [r2, #0xe]
	movs r0, #0xa0
_0802BC56:
	strh r0, [r2, #0x10]
_0802BC58:
	pop {r0}
	bx r0

	thumb_func_start ZebesianWall
ZebesianWall: @ 0x0802BC5C
	push {r4, lr}
	ldr r4, _0802BC88 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0802BC76
	movs r0, #0xaf
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0802BC76:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BC8C
	bl SpriteUtilUpdateFreezeTimer
	b _0802BE68
	.align 2, 0
_0802BC88: .4byte gCurrentSprite
_0802BC8C:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0802BC98
	b _0802BE68
_0802BC98:
	lsls r0, r0, #2
	ldr r1, _0802BCA4 @ =_0802BCA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802BCA4: .4byte _0802BCA8
_0802BCA8: @ jump table
	.4byte _0802BE18 @ case 0
	.4byte _0802BE1E @ case 1
	.4byte _0802BE22 @ case 2
	.4byte _0802BE68 @ case 3
	.4byte _0802BE68 @ case 4
	.4byte _0802BE68 @ case 5
	.4byte _0802BE68 @ case 6
	.4byte _0802BE38 @ case 7
	.4byte _0802BE3C @ case 8
	.4byte _0802BE68 @ case 9
	.4byte _0802BE68 @ case 10
	.4byte _0802BE68 @ case 11
	.4byte _0802BE68 @ case 12
	.4byte _0802BE68 @ case 13
	.4byte _0802BE68 @ case 14
	.4byte _0802BE68 @ case 15
	.4byte _0802BE68 @ case 16
	.4byte _0802BE68 @ case 17
	.4byte _0802BE68 @ case 18
	.4byte _0802BE68 @ case 19
	.4byte _0802BE68 @ case 20
	.4byte _0802BE68 @ case 21
	.4byte _0802BE68 @ case 22
	.4byte _0802BE68 @ case 23
	.4byte _0802BE68 @ case 24
	.4byte _0802BE28 @ case 25
	.4byte _0802BE2C @ case 26
	.4byte _0802BE68 @ case 27
	.4byte _0802BE32 @ case 28
	.4byte _0802BE68 @ case 29
	.4byte _0802BE68 @ case 30
	.4byte _0802BE68 @ case 31
	.4byte _0802BE68 @ case 32
	.4byte _0802BE68 @ case 33
	.4byte _0802BE68 @ case 34
	.4byte _0802BE68 @ case 35
	.4byte _0802BE68 @ case 36
	.4byte _0802BE68 @ case 37
	.4byte _0802BE68 @ case 38
	.4byte _0802BE68 @ case 39
	.4byte _0802BE68 @ case 40
	.4byte _0802BE42 @ case 41
	.4byte _0802BE46 @ case 42
	.4byte _0802BE68 @ case 43
	.4byte _0802BE68 @ case 44
	.4byte _0802BE68 @ case 45
	.4byte _0802BE68 @ case 46
	.4byte _0802BE68 @ case 47
	.4byte _0802BE68 @ case 48
	.4byte _0802BE68 @ case 49
	.4byte _0802BE68 @ case 50
	.4byte _0802BE68 @ case 51
	.4byte _0802BE68 @ case 52
	.4byte _0802BE68 @ case 53
	.4byte _0802BE68 @ case 54
	.4byte _0802BE68 @ case 55
	.4byte _0802BE68 @ case 56
	.4byte _0802BE68 @ case 57
	.4byte _0802BE68 @ case 58
	.4byte _0802BE68 @ case 59
	.4byte _0802BE68 @ case 60
	.4byte _0802BE68 @ case 61
	.4byte _0802BE68 @ case 62
	.4byte _0802BE68 @ case 63
	.4byte _0802BE68 @ case 64
	.4byte _0802BE68 @ case 65
	.4byte _0802BE68 @ case 66
	.4byte _0802BE68 @ case 67
	.4byte _0802BE68 @ case 68
	.4byte _0802BE68 @ case 69
	.4byte _0802BE68 @ case 70
	.4byte _0802BE68 @ case 71
	.4byte _0802BE68 @ case 72
	.4byte _0802BE68 @ case 73
	.4byte _0802BE68 @ case 74
	.4byte _0802BE68 @ case 75
	.4byte _0802BE68 @ case 76
	.4byte _0802BE68 @ case 77
	.4byte _0802BE68 @ case 78
	.4byte _0802BE68 @ case 79
	.4byte _0802BE68 @ case 80
	.4byte _0802BE68 @ case 81
	.4byte _0802BE68 @ case 82
	.4byte _0802BE68 @ case 83
	.4byte _0802BE68 @ case 84
	.4byte _0802BE68 @ case 85
	.4byte _0802BE68 @ case 86
	.4byte _0802BE4C @ case 87
	.4byte _0802BE50 @ case 88
	.4byte _0802BE56 @ case 89
	.4byte _0802BE5A @ case 90
	.4byte _0802BE60 @ case 91
_0802BE18:
	bl ZebesianWallInit
	b _0802BE68
_0802BE1E:
	bl ZebesianWallMovingVerticallyInit
_0802BE22:
	bl ZebesianWallMoveVertically
	b _0802BE68
_0802BE28:
	bl ZebesianWallTurningAroundInit
_0802BE2C:
	bl ZebesianWallTurningAround
	b _0802BE68
_0802BE32:
	bl ZebesianWallJumping
	b _0802BE68
_0802BE38:
	bl ZebesianWallIdleInit
_0802BE3C:
	bl ZebesianWallIdle
	b _0802BE68
_0802BE42:
	bl ZebesianWallShootingInit
_0802BE46:
	bl ZebesianWallShooting
	b _0802BE68
_0802BE4C:
	bl SpriteDyingInit
_0802BE50:
	bl SpriteDying
	b _0802BE68
_0802BE56:
	bl ZebesianWallInit
_0802BE5A:
	bl ZebesianWallFormingFromX
	b _0802BE68
_0802BE60:
	bl ZebesianWallDeath
	bl XParasiteInit
_0802BE68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianBeam
ZebesianBeam: @ 0x0802BE70
	push {lr}
	ldr r0, _0802BE88 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0802BE98
	cmp r0, #2
	bgt _0802BE8C
	cmp r0, #0
	beq _0802BE92
	b _0802BEA2
	.align 2, 0
_0802BE88: .4byte gCurrentSprite
_0802BE8C:
	cmp r0, #0x18
	beq _0802BE9E
	b _0802BEA2
_0802BE92:
	bl ZebesianBeamInit
	b _0802BEA2
_0802BE98:
	bl ZebesianBeamSpawning
	b _0802BEA2
_0802BE9E:
	bl ZebesianBeamExtending
_0802BEA2:
	ldr r2, _0802BEB4 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802BEB8
	ldrh r0, [r2, #4]
	subs r0, #0xa
	b _0802BEBC
	.align 2, 0
_0802BEB4: .4byte gCurrentSprite
_0802BEB8:
	ldrh r0, [r2, #4]
	adds r0, #0xa
_0802BEBC:
	strh r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start RechargePadInit
RechargePadInit: @ 0x0802BEC4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r4, _0802BF18 @ =gCurrentSprite
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0802BF1C @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x21
	movs r5, #1
	strb r5, [r0]
	bl EventCheckWith_RechargeDisabled
	cmp r0, #0
	beq _0802BF20
	adds r0, r4, #0
	adds r0, #0x31
	strb r5, [r0]
	b _0802BF28
	.align 2, 0
_0802BF18: .4byte gCurrentSprite
_0802BF1C: .4byte 0x0000FFFC
_0802BF20:
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
_0802BF28:
	ldr r4, _0802BF94 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	movs r7, #1
	ands r7, r0
	cmp r7, #0
	beq _0802BF98
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x90
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x21
	movs r1, #0
	bl SpriteSpawnSecondary
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r5, [r0]
	cmp r5, #0
	bne _0802BFF0
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x90
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x22
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x90
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x22
	movs r1, #1
	bl SpriteSpawnSecondary
	b _0802BFF0
	.align 2, 0
_0802BF94: .4byte gCurrentSprite
_0802BF98:
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x90
	str r0, [sp, #4]
	movs r5, #0x40
	str r5, [sp, #8]
	movs r0, #0x21
	movs r1, #0
	bl SpriteSpawnSecondary
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802BFF0
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x90
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x22
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x90
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x22
	movs r1, #1
	bl SpriteSpawnSecondary
_0802BFF0:
	ldr r0, _0802C000 @ =gCurrentSprite
	adds r0, #0x2f
	strb r7, [r0]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C000: .4byte gCurrentSprite

	thumb_func_start RechargePadIdleInit
RechargePadIdleInit: @ 0x0802C004
	push {lr}
	ldr r1, _0802C02C @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C034
	ldr r0, _0802C030 @ =0x083257E0
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x46
	b _0802C03C
	.align 2, 0
_0802C02C: .4byte gCurrentSprite
_0802C030: .4byte 0x083257E0
_0802C034:
	ldr r0, _0802C044 @ =0x083257D0
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #2
_0802C03C:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802C044: .4byte 0x083257D0

	thumb_func_start RechargePadIdle
RechargePadIdle: @ 0x0802C048
	push {lr}
	bl NavPadDetectSamus
	cmp r0, #0
	beq _0802C088
	ldr r3, _0802C07C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802C090
	subs r1, #0xa
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802C080 @ =0x08325780
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0802C084 @ =0x00000101
	bl SoundPlay
	b _0802C090
	.align 2, 0
_0802C07C: .4byte gCurrentSprite
_0802C080: .4byte 0x08325780
_0802C084: .4byte 0x00000101
_0802C088:
	ldr r0, _0802C094 @ =gCurrentSprite
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
_0802C090:
	pop {r0}
	bx r0
	.align 2, 0
_0802C094: .4byte gCurrentSprite

	thumb_func_start RechargePadOpening
RechargePadOpening: @ 0x0802C098
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802C0B6
	ldr r1, _0802C0BC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1a
	strb r0, [r2]
	ldr r0, _0802C0C0 @ =0x083257E0
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
_0802C0B6:
	pop {r0}
	bx r0
	.align 2, 0
_0802C0BC: .4byte gCurrentSprite
_0802C0C0: .4byte 0x083257E0

	thumb_func_start RechargePadOpened
RechargePadOpened: @ 0x0802C0C4
	push {r4, lr}
	movs r4, #0
	bl NavPadDetectSamus
	adds r3, r0, #0
	cmp r3, #0
	beq _0802C168
	bl SpriteUtilCheckSamusMorphed
	cmp r0, #0
	bne _0802C182
	ldr r0, _0802C10C @ =gSamusData
	ldrb r1, [r0, #2]
	adds r2, r0, #0
	cmp r1, #0
	bne _0802C182
	ldr r1, _0802C110 @ =gCurrentSprite
	ldrh r0, [r1, #4]
	strh r0, [r2, #0x16]
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _0802C0F4
	movs r0, #0
	strb r0, [r2, #5]
_0802C0F4:
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C114
	ldrh r1, [r2, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802C120
	b _0802C124
	.align 2, 0
_0802C10C: .4byte gSamusData
_0802C110: .4byte gCurrentSprite
_0802C114:
	ldrh r1, [r2, #0x12]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802C120
	movs r4, #1
_0802C120:
	cmp r4, #0
	beq _0802C13C
_0802C124:
	ldr r0, _0802C138 @ =sSamusSetPoseFunctionPointer
	ldrb r1, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #0x22
	bl _call_via_r1
	b _0802C14C
	.align 2, 0
_0802C138: .4byte sSamusSetPoseFunctionPointer
_0802C13C:
	ldr r0, _0802C160 @ =sSamusSetPoseFunctionPointer
	ldrb r1, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #0x21
	bl _call_via_r1
_0802C14C:
	ldr r1, _0802C164 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x38
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x10
	strb r0, [r1]
	b _0802C182
	.align 2, 0
_0802C160: .4byte sSamusSetPoseFunctionPointer
_0802C164: .4byte gCurrentSprite
_0802C168:
	ldr r1, _0802C188 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _0802C18C @ =0x083257A8
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	movs r0, #0x81
	lsls r0, r0, #1
	bl SoundPlay
_0802C182:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C188: .4byte gCurrentSprite
_0802C18C: .4byte 0x083257A8

	thumb_func_start RechargePadClosing
RechargePadClosing: @ 0x0802C190
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802C19E
	bl RechargePadIdleInit
_0802C19E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start RechargePadExtending
RechargePadExtending: @ 0x0802C1A4
	push {lr}
	ldr r2, _0802C1D0 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802C1CA
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x3a
	strb r0, [r1]
	movs r0, #0x3c
	strb r0, [r3]
	adds r1, #0xc
	movs r0, #0xa
	strb r0, [r1]
_0802C1CA:
	pop {r0}
	bx r0
	.align 2, 0
_0802C1D0: .4byte gCurrentSprite

	thumb_func_start RechargePadRefilling
RechargePadRefilling: @ 0x0802C1D4
	push {lr}
	ldr r1, _0802C1E8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #0
	beq _0802C1EC
	subs r0, #1
	strb r0, [r2]
	b _0802C236
	.align 2, 0
_0802C1E8: .4byte gCurrentSprite
_0802C1EC:
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x28
	bne _0802C1F8
	bl SpriteUtilRefillEnergy
	b _0802C214
_0802C1F8:
	cmp r0, #0x29
	beq _0802C208
	cmp r0, #0x2a
	bne _0802C218
	bl SpriteUtilRefillEnergy
	cmp r0, #0
	bne _0802C236
_0802C208:
	bl SpriteUtilRefillMissiles
	cmp r0, #0
	bne _0802C236
	bl SpriteUtilRefillPowerBombs
_0802C214:
	cmp r0, #0
	bne _0802C236
_0802C218:
	ldr r2, _0802C23C @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x30
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802C236
	subs r1, #0xc
	movs r0, #0x3c
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x14
	strb r0, [r1]
_0802C236:
	pop {r0}
	bx r0
	.align 2, 0
_0802C23C: .4byte gCurrentSprite

	thumb_func_start RechargePadRetracting
RechargePadRetracting: @ 0x0802C240
	push {r4, lr}
	ldr r4, _0802C284 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802C2C2
	subs r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _0802C288 @ =sSamusSetPoseFunctionPointer
	ldr r0, _0802C28C @ =gSamusData
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0
	bl _call_via_r1
	ldr r1, _0802C290 @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	ldrb r1, [r4, #0x1d]
	cmp r1, #0x28
	bne _0802C294
	movs r0, #0x10
	bl TrySpawnMessageBanner
	b _0802C2C2
	.align 2, 0
_0802C284: .4byte gCurrentSprite
_0802C288: .4byte sSamusSetPoseFunctionPointer
_0802C28C: .4byte gSamusData
_0802C290: .4byte gPreventMovementTimer
_0802C294:
	cmp r1, #0x29
	bne _0802C2A0
	movs r0, #0xf
	bl TrySpawnMessageBanner
	b _0802C2C2
_0802C2A0:
	cmp r1, #0x2a
	bne _0802C2C2
	ldr r0, _0802C2B8 @ =gEquipment
	ldrb r1, [r0, #0xb]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0802C2BC
	movs r0, #0x11
	bl TrySpawnMessageBanner
	b _0802C2C2
	.align 2, 0
_0802C2B8: .4byte gEquipment
_0802C2BC:
	movs r0, #0x10
	bl TrySpawnMessageBanner
_0802C2C2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start RechargePadMonitorInit
RechargePadMonitorInit: @ 0x0802C2C8
	push {r4, r5, lr}
	ldr r0, _0802C32C @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r4, #0
	orrs r0, r1
	strb r0, [r2]
	mov r5, ip
	ldrh r1, [r5]
	ldr r0, _0802C330 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	strh r0, [r5]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r3, [r0]
	adds r1, #2
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0802C334 @ =0x0000FFFC
	strh r1, [r5, #0xa]
	movs r2, #4
	movs r0, #4
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	mov r0, ip
	adds r0, #0x22
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802C338 @ =0x08325700
	str r0, [r5, #0x18]
	strb r3, [r5, #0x1c]
	strh r4, [r5, #0x16]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C32C: .4byte gCurrentSprite
_0802C330: .4byte 0x0000FFFB
_0802C334: .4byte 0x0000FFFC
_0802C338: .4byte 0x08325700

	thumb_func_start RechargePadMonitorIdle
RechargePadMonitorIdle: @ 0x0802C33C
	push {lr}
	ldr r2, _0802C374 @ =gSpriteData
	ldr r3, _0802C378 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bne _0802C370
	ldr r0, _0802C37C @ =0x08325710
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	adds r0, #0xfa
	bl SoundPlay
_0802C370:
	pop {r0}
	bx r0
	.align 2, 0
_0802C374: .4byte gSpriteData
_0802C378: .4byte gCurrentSprite
_0802C37C: .4byte 0x08325710

	thumb_func_start RechargePadMonitorExtended
RechargePadMonitorExtended: @ 0x0802C380
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802C3B4
	ldr r1, _0802C3B8 @ =gCurrentSprite
	ldr r0, _0802C3BC @ =0x08325738
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldr r1, _0802C3C0 @ =sSamusSetPoseFunctionPointer
	ldr r0, _0802C3C4 @ =gSamusData
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x38
	bl _call_via_r1
	ldr r0, _0802C3C8 @ =0x00000111
	bl SoundPlay
_0802C3B4:
	pop {r0}
	bx r0
	.align 2, 0
_0802C3B8: .4byte gCurrentSprite
_0802C3BC: .4byte 0x08325738
_0802C3C0: .4byte sSamusSetPoseFunctionPointer
_0802C3C4: .4byte gSamusData
_0802C3C8: .4byte 0x00000111

	thumb_func_start RechargePadMonitorRetractingInit
RechargePadMonitorRetractingInit: @ 0x0802C3CC
	push {lr}
	ldr r2, _0802C404 @ =gSpriteData
	ldr r3, _0802C408 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _0802C400
	ldr r0, _0802C40C @ =0x08325758
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1c
	strb r0, [r1]
	adds r0, #0xf7
	bl SoundPlay
_0802C400:
	pop {r0}
	bx r0
	.align 2, 0
_0802C404: .4byte gSpriteData
_0802C408: .4byte gCurrentSprite
_0802C40C: .4byte 0x08325758

	thumb_func_start RechargePadMonitorRetracting
RechargePadMonitorRetracting: @ 0x0802C410
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802C42C
	ldr r1, _0802C430 @ =gCurrentSprite
	ldr r0, _0802C434 @ =0x08325700
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
_0802C42C:
	pop {r0}
	bx r0
	.align 2, 0
_0802C430: .4byte gCurrentSprite
_0802C434: .4byte 0x08325700

	thumb_func_start RechargePadScreenInit
RechargePadScreenInit: @ 0x0802C438
	push {r4, r5, lr}
	ldr r0, _0802C4A4 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x23
	ldrb r4, [r0]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	mov r2, ip
	ldrh r1, [r2]
	ldr r0, _0802C4A8 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	mov r5, ip
	strh r0, [r5]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0802C4AC @ =0x0000FFFC
	strh r1, [r5, #0xa]
	movs r0, #4
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	mov r0, ip
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	strb r2, [r5, #0x1c]
	strh r3, [r5, #0x16]
	ldrb r2, [r5, #0x1e]
	cmp r2, #0
	beq _0802C4B4
	ldr r0, _0802C4B0 @ =0x083256B8
	str r0, [r5, #0x18]
	mov r0, ip
	adds r0, #0x22
	strb r1, [r0]
	b _0802C500
	.align 2, 0
_0802C4A4: .4byte gCurrentSprite
_0802C4A8: .4byte 0x0000FFFB
_0802C4AC: .4byte 0x0000FFFC
_0802C4B0: .4byte 0x083256B8
_0802C4B4:
	mov r1, ip
	adds r1, #0x22
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0802C4D4 @ =gSpriteData
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0, #0x1d]
	cmp r0, #0x28
	bne _0802C4DC
	ldr r0, _0802C4D8 @ =0x08325640
	mov r1, ip
	str r0, [r1, #0x18]
	b _0802C500
	.align 2, 0
_0802C4D4: .4byte gSpriteData
_0802C4D8: .4byte 0x08325640
_0802C4DC:
	cmp r0, #0x29
	bne _0802C4EC
	ldr r0, _0802C4E8 @ =0x08325668
	mov r2, ip
	str r0, [r2, #0x18]
	b _0802C500
	.align 2, 0
_0802C4E8: .4byte 0x08325668
_0802C4EC:
	cmp r0, #0x2a
	bne _0802C4FC
	ldr r0, _0802C4F8 @ =0x08325690
	mov r5, ip
	str r0, [r5, #0x18]
	b _0802C500
	.align 2, 0
_0802C4F8: .4byte 0x08325690
_0802C4FC:
	mov r0, ip
	strh r2, [r0]
_0802C500:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start RechargePad
RechargePad: @ 0x0802C508
	push {lr}
	ldr r0, _0802C528 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _0802C51E
	b _0802C656
_0802C51E:
	lsls r0, r0, #2
	ldr r1, _0802C52C @ =_0802C530
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C528: .4byte gCurrentSprite
_0802C52C: .4byte _0802C530
_0802C530: @ jump table
	.4byte _0802C624 @ case 0
	.4byte _0802C628 @ case 1
	.4byte _0802C62E @ case 2
	.4byte _0802C656 @ case 3
	.4byte _0802C656 @ case 4
	.4byte _0802C656 @ case 5
	.4byte _0802C656 @ case 6
	.4byte _0802C656 @ case 7
	.4byte _0802C656 @ case 8
	.4byte _0802C656 @ case 9
	.4byte _0802C656 @ case 10
	.4byte _0802C656 @ case 11
	.4byte _0802C656 @ case 12
	.4byte _0802C656 @ case 13
	.4byte _0802C656 @ case 14
	.4byte _0802C656 @ case 15
	.4byte _0802C656 @ case 16
	.4byte _0802C656 @ case 17
	.4byte _0802C656 @ case 18
	.4byte _0802C656 @ case 19
	.4byte _0802C656 @ case 20
	.4byte _0802C656 @ case 21
	.4byte _0802C656 @ case 22
	.4byte _0802C656 @ case 23
	.4byte _0802C634 @ case 24
	.4byte _0802C656 @ case 25
	.4byte _0802C63A @ case 26
	.4byte _0802C656 @ case 27
	.4byte _0802C640 @ case 28
	.4byte _0802C656 @ case 29
	.4byte _0802C656 @ case 30
	.4byte _0802C656 @ case 31
	.4byte _0802C656 @ case 32
	.4byte _0802C656 @ case 33
	.4byte _0802C656 @ case 34
	.4byte _0802C656 @ case 35
	.4byte _0802C656 @ case 36
	.4byte _0802C656 @ case 37
	.4byte _0802C656 @ case 38
	.4byte _0802C656 @ case 39
	.4byte _0802C656 @ case 40
	.4byte _0802C656 @ case 41
	.4byte _0802C656 @ case 42
	.4byte _0802C656 @ case 43
	.4byte _0802C656 @ case 44
	.4byte _0802C656 @ case 45
	.4byte _0802C656 @ case 46
	.4byte _0802C656 @ case 47
	.4byte _0802C656 @ case 48
	.4byte _0802C656 @ case 49
	.4byte _0802C656 @ case 50
	.4byte _0802C656 @ case 51
	.4byte _0802C656 @ case 52
	.4byte _0802C656 @ case 53
	.4byte _0802C656 @ case 54
	.4byte _0802C656 @ case 55
	.4byte _0802C646 @ case 56
	.4byte _0802C656 @ case 57
	.4byte _0802C64C @ case 58
	.4byte _0802C656 @ case 59
	.4byte _0802C652 @ case 60
_0802C624:
	bl RechargePadInit
_0802C628:
	bl RechargePadIdleInit
	b _0802C656
_0802C62E:
	bl RechargePadIdle
	b _0802C656
_0802C634:
	bl RechargePadOpening
	b _0802C656
_0802C63A:
	bl RechargePadOpened
	b _0802C656
_0802C640:
	bl RechargePadClosing
	b _0802C656
_0802C646:
	bl RechargePadExtending
	b _0802C656
_0802C64C:
	bl RechargePadRefilling
	b _0802C656
_0802C652:
	bl RechargePadRetracting
_0802C656:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start RechargePadMonitor
RechargePadMonitor: @ 0x0802C65C
	push {lr}
	ldr r0, _0802C67C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1c
	bhi _0802C714
	lsls r0, r0, #2
	ldr r1, _0802C680 @ =_0802C684
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C67C: .4byte gCurrentSprite
_0802C680: .4byte _0802C684
_0802C684: @ jump table
	.4byte _0802C6F8 @ case 0
	.4byte _0802C714 @ case 1
	.4byte _0802C6FE @ case 2
	.4byte _0802C714 @ case 3
	.4byte _0802C714 @ case 4
	.4byte _0802C714 @ case 5
	.4byte _0802C714 @ case 6
	.4byte _0802C714 @ case 7
	.4byte _0802C714 @ case 8
	.4byte _0802C714 @ case 9
	.4byte _0802C714 @ case 10
	.4byte _0802C714 @ case 11
	.4byte _0802C714 @ case 12
	.4byte _0802C714 @ case 13
	.4byte _0802C714 @ case 14
	.4byte _0802C714 @ case 15
	.4byte _0802C714 @ case 16
	.4byte _0802C714 @ case 17
	.4byte _0802C714 @ case 18
	.4byte _0802C714 @ case 19
	.4byte _0802C714 @ case 20
	.4byte _0802C714 @ case 21
	.4byte _0802C714 @ case 22
	.4byte _0802C714 @ case 23
	.4byte _0802C704 @ case 24
	.4byte _0802C714 @ case 25
	.4byte _0802C70A @ case 26
	.4byte _0802C714 @ case 27
	.4byte _0802C710 @ case 28
_0802C6F8:
	bl RechargePadMonitorInit
	b _0802C714
_0802C6FE:
	bl RechargePadMonitorIdle
	b _0802C714
_0802C704:
	bl RechargePadMonitorExtended
	b _0802C714
_0802C70A:
	bl RechargePadMonitorRetractingInit
	b _0802C714
_0802C710:
	bl RechargePadMonitorRetracting
_0802C714:
	pop {r0}
	bx r0

	thumb_func_start RechargePadScreen
RechargePadScreen: @ 0x0802C718
	push {lr}
	ldr r0, _0802C734 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802C730
	bl RechargePadScreenInit
_0802C730:
	pop {r0}
	bx r0
	.align 2, 0
_0802C734: .4byte gCurrentSprite

	thumb_func_start AtmosphericSbabilizerCheckIsInfected
AtmosphericSbabilizerCheckIsInfected: @ 0x0802C738
	push {r4, r5, lr}
	movs r3, #0
	ldr r5, _0802C784 @ =gSpriteData
	movs r4, #1
_0802C740:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #3
	adds r2, r0, r5
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0802C78C
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0802C78C
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x30
	bgt _0802C78C
	cmp r0, #0x2c
	blt _0802C78C
	adds r1, r0, #0
	subs r1, #0x2c
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0802C788 @ =gAtmosphericStabilizersOnline
	ldrh r0, [r0]
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	bne _0802C796
	movs r0, #1
	b _0802C798
	.align 2, 0
_0802C784: .4byte gSpriteData
_0802C788: .4byte gAtmosphericStabilizersOnline
_0802C78C:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x17
	bls _0802C740
_0802C796:
	movs r0, #0
_0802C798:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start AtmosphericSbabilizerInit
AtmosphericSbabilizerInit: @ 0x0802C7A0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, _0802C800 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x22
	movs r5, #0
	movs r0, #0xc
	strb r0, [r1]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	movs r3, #0
	strh r0, [r4, #2]
	ldr r2, _0802C804 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	strb r3, [r4, #0x1c]
	strh r5, [r4, #0x16]
	adds r0, #5
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	bl SpriteUtilChooseRandomXDirection
	ldrb r0, [r4, #0x1d]
	subs r0, #0x2c
	cmp r0, #4
	bls _0802C7F6
	b _0802CA18
_0802C7F6:
	lsls r0, r0, #2
	ldr r1, _0802C808 @ =_0802C80C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802C800: .4byte gCurrentSprite
_0802C804: .4byte sPrimarySpriteStats
_0802C808: .4byte _0802C80C
_0802C80C: @ jump table
	.4byte _0802C820 @ case 0
	.4byte _0802C86C @ case 1
	.4byte _0802C820 @ case 2
	.4byte _0802C840 @ case 3
	.4byte _0802C840 @ case 4
_0802C820:
	movs r6, #0x23
	ldr r1, _0802C838 @ =gCurrentSprite
	movs r3, #0
	ldr r2, _0802C83C @ =0x0000FFA0
	strh r2, [r1, #0xa]
	movs r0, #0x60
	strh r0, [r1, #0xc]
	strh r2, [r1, #0xe]
	movs r0, #0x20
	strh r0, [r1, #0x10]
	b _0802C854
	.align 2, 0
_0802C838: .4byte gCurrentSprite
_0802C83C: .4byte 0x0000FFA0
_0802C840:
	movs r6, #0x24
	ldr r1, _0802C860 @ =gCurrentSprite
	movs r3, #0
	ldr r0, _0802C864 @ =0x0000FFA0
	strh r0, [r1, #0xa]
	movs r2, #0x60
	strh r2, [r1, #0xc]
	adds r0, #0x40
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x10]
_0802C854:
	adds r0, r1, #0
	adds r0, #0x2f
	strb r3, [r0]
	ldr r0, _0802C868 @ =0x083277F8
	b _0802C888
	.align 2, 0
_0802C860: .4byte gCurrentSprite
_0802C864: .4byte 0x0000FFA0
_0802C868: .4byte 0x083277F8
_0802C86C:
	movs r6, #0x13
	ldr r1, _0802C8C0 @ =gCurrentSprite
	ldr r2, _0802C8C4 @ =0x0000FFA0
	strh r2, [r1, #0xa]
	movs r0, #0x20
	strh r0, [r1, #0xc]
	strh r2, [r1, #0xe]
	movs r0, #0x60
	strh r0, [r1, #0x10]
	adds r2, r1, #0
	adds r2, #0x2f
	movs r0, #1
	strb r0, [r2]
	ldr r0, _0802C8C8 @ =0x08327660
_0802C888:
	str r0, [r1, #0x18]
	adds r4, r1, #0
	ldrb r2, [r4, #0x1d]
	adds r0, r2, #0
	subs r0, #0x2c
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _0802C8CC @ =gAtmosphericStabilizersOnline
	ldrh r0, [r0]
	asrs r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	beq _0802C8E4
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C8D4
	ldr r0, _0802C8D0 @ =0x08327640
	b _0802C8D6
	.align 2, 0
_0802C8C0: .4byte gCurrentSprite
_0802C8C4: .4byte 0x0000FFA0
_0802C8C8: .4byte 0x08327660
_0802C8CC: .4byte gAtmosphericStabilizersOnline
_0802C8D0: .4byte 0x08327640
_0802C8D4:
	ldr r0, _0802C8E0 @ =0x083277D8
_0802C8D6:
	str r0, [r4, #0x18]
	movs r0, #0xfe
	bl SoundPlay
	b _0802CA26
	.align 2, 0
_0802C8E0: .4byte 0x083277D8
_0802C8E4:
	adds r2, r4, #0
	adds r2, #0x25
	movs r0, #2
	strb r0, [r2]
	cmp r6, #0x23
	bne _0802C94E
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x23
	movs r1, #0
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	bne _0802C914
	b _0802CA18
_0802C914:
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x23
	movs r1, #1
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _0802CA18
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0x2b
	movs r1, #1
	b _0802CA0C
_0802C94E:
	cmp r6, #0x24
	bne _0802C9AE
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x24
	movs r1, #2
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _0802CA18
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x24
	movs r1, #3
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _0802CA18
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0x2b
	movs r1, #2
	b _0802CA0C
_0802C9AE:
	cmp r6, #0x13
	bne _0802CA1C
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x13
	movs r1, #4
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _0802CA18
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x13
	movs r1, #5
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _0802CA18
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0x2b
	movs r1, #3
_0802CA0C:
	bl SpriteSpawnNewXParasite
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	bne _0802CA20
_0802CA18:
	strh r5, [r4]
	b _0802CA2E
_0802CA1C:
	strh r5, [r1]
	b _0802CA2E
_0802CA20:
	movs r0, #0xff
	bl SoundPlay
_0802CA26:
	ldr r0, _0802CA38 @ =gCurrentSprite
	adds r0, #0x2a
	movs r1, #0x10
	strb r1, [r0]
_0802CA2E:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802CA38: .4byte gCurrentSprite

	thumb_func_start AtmosphericStabilizerBackOnlineInit
AtmosphericStabilizerBackOnlineInit: @ 0x0802CA3C
	push {lr}
	ldr r3, _0802CA64 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x18
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	movs r0, #0
	strh r1, [r3, #0x16]
	adds r2, #1
	strb r0, [r2]
	strh r1, [r3, #0x14]
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CA6C
	ldr r0, _0802CA68 @ =0x083276E0
	b _0802CA6E
	.align 2, 0
_0802CA64: .4byte gCurrentSprite
_0802CA68: .4byte 0x083276E0
_0802CA6C:
	ldr r0, _0802CA7C @ =0x08327878
_0802CA6E:
	str r0, [r3, #0x18]
	movs r0, #0x80
	lsls r0, r0, #1
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_0802CA7C: .4byte 0x08327878

	thumb_func_start AtmosphericStabilizerBackOnline
AtmosphericStabilizerBackOnline: @ 0x0802CA80
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802CABA
	ldr r3, _0802CAA8 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #2
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CAB0
	ldr r0, _0802CAAC @ =0x08327640
	b _0802CAB2
	.align 2, 0
_0802CAA8: .4byte gCurrentSprite
_0802CAAC: .4byte 0x08327640
_0802CAB0:
	ldr r0, _0802CAC0 @ =0x083277D8
_0802CAB2:
	str r0, [r3, #0x18]
	movs r0, #1
	bl StartStopEventBasedEffect
_0802CABA:
	pop {r0}
	bx r0
	.align 2, 0
_0802CAC0: .4byte 0x083277D8

	thumb_func_start AtmosphericStabilizerCoverInit
AtmosphericStabilizerCoverInit: @ 0x0802CAC4
	push {r4, lr}
	ldr r0, _0802CB1C @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x25
	movs r4, #0
	movs r3, #2
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	ldr r1, _0802CB20 @ =sSecondarySpriteStats
	mov r2, ip
	ldrb r0, [r2, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0
	mov r1, ip
	strh r0, [r1, #0x14]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r0, ip
	strb r2, [r0, #0x1c]
	strh r4, [r0, #0x16]
	adds r0, #0x24
	strb r3, [r0]
	mov r1, ip
	ldrb r0, [r1, #0x1e]
	mov r2, ip
	cmp r0, #7
	bls _0802CB12
	b _0802CC34
_0802CB12:
	lsls r0, r0, #2
	ldr r1, _0802CB24 @ =_0802CB28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CB1C: .4byte gCurrentSprite
_0802CB20: .4byte sSecondarySpriteStats
_0802CB24: .4byte _0802CB28
_0802CB28: @ jump table
	.4byte _0802CB48 @ case 0
	.4byte _0802CB74 @ case 1
	.4byte _0802CB84 @ case 2
	.4byte _0802CBA8 @ case 3
	.4byte _0802CBC0 @ case 4
	.4byte _0802CBE4 @ case 5
	.4byte _0802CBF4 @ case 6
	.4byte _0802CC1C @ case 7
_0802CB48:
	ldrh r1, [r2]
	ldr r0, _0802CB68 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0802CB6C @ =0x08327A30
	str r0, [r2, #0x18]
	ldr r0, _0802CB70 @ =0x0000FFA0
	strh r0, [r2, #0xa]
	adds r0, #0x40
	strh r0, [r2, #0xc]
	movs r0, #0x20
	strh r0, [r2, #0xe]
	movs r0, #0x60
	strh r0, [r2, #0x10]
	b _0802CC38
	.align 2, 0
_0802CB68: .4byte 0x0000FFFB
_0802CB6C: .4byte 0x08327A30
_0802CB70: .4byte 0x0000FFA0
_0802CB74:
	ldr r0, _0802CB80 @ =0x08327A30
	str r0, [r2, #0x18]
	movs r1, #0x20
	strh r1, [r2, #0xa]
	b _0802CC26
	.align 2, 0
_0802CB80: .4byte 0x08327A30
_0802CB84:
	ldrh r1, [r2]
	ldr r0, _0802CB9C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0802CBA0 @ =0x08327A40
	str r0, [r2, #0x18]
	movs r0, #0x20
	strh r0, [r2, #0xa]
	movs r0, #0x60
	strh r0, [r2, #0xc]
	ldr r0, _0802CBA4 @ =0x0000FFA0
	b _0802CC08
	.align 2, 0
_0802CB9C: .4byte 0x0000FFFB
_0802CBA0: .4byte 0x08327A40
_0802CBA4: .4byte 0x0000FFA0
_0802CBA8:
	ldr r0, _0802CBB4 @ =0x08327A40
	str r0, [r2, #0x18]
	ldr r1, _0802CBB8 @ =0x0000FFA0
	strh r1, [r2, #0xa]
	ldr r0, _0802CBBC @ =0x0000FFE0
	b _0802CC28
	.align 2, 0
_0802CBB4: .4byte 0x08327A40
_0802CBB8: .4byte 0x0000FFA0
_0802CBBC: .4byte 0x0000FFE0
_0802CBC0:
	ldrh r1, [r2]
	ldr r0, _0802CBD8 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0802CBDC @ =0x08327A20
	str r0, [r2, #0x18]
	movs r0, #0x20
	strh r0, [r2, #0xa]
	movs r0, #0x60
	strh r0, [r2, #0xc]
	ldr r0, _0802CBE0 @ =0x0000FFA0
	b _0802CC08
	.align 2, 0
_0802CBD8: .4byte 0x0000FFFB
_0802CBDC: .4byte 0x08327A20
_0802CBE0: .4byte 0x0000FFA0
_0802CBE4:
	ldr r0, _0802CBF0 @ =0x08327A20
	str r0, [r2, #0x18]
	movs r1, #0x20
	strh r1, [r2, #0xa]
	b _0802CC26
	.align 2, 0
_0802CBF0: .4byte 0x08327A20
_0802CBF4:
	ldrh r1, [r2]
	ldr r0, _0802CC10 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r0, _0802CC14 @ =0x08327A60
	str r0, [r2, #0x18]
	ldr r0, _0802CC18 @ =0x0000FFA0
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
_0802CC08:
	strh r0, [r2, #0xe]
	adds r0, #0x40
	strh r0, [r2, #0x10]
	b _0802CC38
	.align 2, 0
_0802CC10: .4byte 0x0000FFFB
_0802CC14: .4byte 0x08327A60
_0802CC18: .4byte 0x0000FFA0
_0802CC1C:
	ldr r0, _0802CC30 @ =0x08327A60
	str r0, [r2, #0x18]
	movs r1, #0
	movs r0, #0x20
	strh r0, [r2, #0xa]
_0802CC26:
	movs r0, #0x60
_0802CC28:
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	b _0802CC38
	.align 2, 0
_0802CC30: .4byte 0x08327A60
_0802CC34:
	mov r2, ip
	strh r4, [r2]
_0802CC38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start AtmosphericStabilizerCoverIdle
AtmosphericStabilizerCoverIdle: @ 0x0802CC40
	push {lr}
	ldr r3, _0802CC74 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0802CC78 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	strh r1, [r3, #2]
	ldrh r1, [r0, #4]
	strh r1, [r3, #4]
	adds r0, #0x24
	ldrb r2, [r0]
	cmp r2, #0x18
	bne _0802CC8A
	ldrh r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802CC7C
	movs r0, #0
	strh r0, [r3]
	b _0802CC8A
	.align 2, 0
_0802CC74: .4byte gCurrentSprite
_0802CC78: .4byte gSpriteData
_0802CC7C:
	adds r0, r3, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #0
	strb r0, [r1]
_0802CC8A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start AtmosphericStabilizerCoverExploding
AtmosphericStabilizerCoverExploding: @ 0x0802CC90
	push {r4, r5, r6, r7, lr}
	ldr r6, _0802CCCC @ =gCurrentSprite
	ldrh r4, [r6, #2]
	ldrh r5, [r6, #4]
	ldrh r0, [r6]
	movs r1, #4
	eors r0, r1
	strh r0, [r6]
	adds r7, r6, #0
	adds r7, #0x2e
	ldrb r1, [r7]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0802CCB4
	ldr r0, _0802CCD0 @ =0x000001BF
	bl SoundPlay
_0802CCB4:
	ldrb r0, [r6, #0x1e]
	cmp r0, #0
	bne _0802CDAA
	ldrb r0, [r7]
	cmp r0, #0x18
	bls _0802CCC2
	b _0802D096
_0802CCC2:
	lsls r0, r0, #2
	ldr r1, _0802CCD4 @ =_0802CCD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CCCC: .4byte gCurrentSprite
_0802CCD0: .4byte 0x000001BF
_0802CCD4: .4byte _0802CCD8
_0802CCD8: @ jump table
	.4byte _0802CD3C @ case 0
	.4byte _0802D096 @ case 1
	.4byte _0802CD44 @ case 2
	.4byte _0802D096 @ case 3
	.4byte _0802CD4C @ case 4
	.4byte _0802D096 @ case 5
	.4byte _0802CD56 @ case 6
	.4byte _0802D024 @ case 7
	.4byte _0802CD5C @ case 8
	.4byte _0802CD66 @ case 9
	.4byte _0802CD70 @ case 10
	.4byte _0802D096 @ case 11
	.4byte _0802CD78 @ case 12
	.4byte _0802D096 @ case 13
	.4byte _0802CD82 @ case 14
	.4byte _0802D096 @ case 15
	.4byte _0802CD8C @ case 16
	.4byte _0802CD96 @ case 17
	.4byte _0802CDA0 @ case 18
	.4byte _0802D080 @ case 19
	.4byte _0802D096 @ case 20
	.4byte _0802D096 @ case 21
	.4byte _0802D096 @ case 22
	.4byte _0802D096 @ case 23
	.4byte _0802D090 @ case 24
_0802CD3C:
	adds r0, r4, #0
	subs r0, #0x30
	adds r1, r5, #4
	b _0802D088
_0802CD44:
	adds r0, r4, #0
	adds r0, #0x40
	subs r1, r5, #4
	b _0802D088
_0802CD4C:
	adds r0, r4, #0
	subs r0, #8
	adds r1, r5, #0
	subs r1, #0x40
	b _0802D088
_0802CD56:
	adds r0, r4, #0
	subs r0, #0x26
	b _0802D028
_0802CD5C:
	adds r0, r4, #0
	subs r0, #0x3c
	adds r1, r5, #0
	adds r1, #0x3c
	b _0802D088
_0802CD66:
	adds r0, r4, #0
	adds r0, #0x32
	adds r1, r5, #0
	adds r1, #0x32
	b _0802D088
_0802CD70:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	b _0802D02C
_0802CD78:
	adds r0, r4, #0
	adds r0, #0x50
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802CD82:
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r5, #0
	subs r1, #0x44
	b _0802D088
_0802CD8C:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802CD96:
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x10
	b _0802D088
_0802CDA0:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	adds r1, #0x50
	b _0802D088
_0802CDAA:
	cmp r0, #2
	bne _0802CE96
	ldrb r0, [r7]
	cmp r0, #0x18
	bls _0802CDB6
	b _0802D096
_0802CDB6:
	lsls r0, r0, #2
	ldr r1, _0802CDC0 @ =_0802CDC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CDC0: .4byte _0802CDC4
_0802CDC4: @ jump table
	.4byte _0802CE28 @ case 0
	.4byte _0802D096 @ case 1
	.4byte _0802CE30 @ case 2
	.4byte _0802D096 @ case 3
	.4byte _0802CE38 @ case 4
	.4byte _0802D096 @ case 5
	.4byte _0802CE42 @ case 6
	.4byte _0802D024 @ case 7
	.4byte _0802CE48 @ case 8
	.4byte _0802CE52 @ case 9
	.4byte _0802CE5C @ case 10
	.4byte _0802D096 @ case 11
	.4byte _0802CE64 @ case 12
	.4byte _0802D096 @ case 13
	.4byte _0802CE6E @ case 14
	.4byte _0802D096 @ case 15
	.4byte _0802CE78 @ case 16
	.4byte _0802CE82 @ case 17
	.4byte _0802CE8C @ case 18
	.4byte _0802D080 @ case 19
	.4byte _0802D096 @ case 20
	.4byte _0802D096 @ case 21
	.4byte _0802D096 @ case 22
	.4byte _0802D096 @ case 23
	.4byte _0802D090 @ case 24
_0802CE28:
	adds r0, r4, #0
	subs r0, #0x30
	adds r1, r5, #4
	b _0802D088
_0802CE30:
	adds r0, r4, #0
	adds r0, #0x40
	subs r1, r5, #4
	b _0802D088
_0802CE38:
	adds r0, r4, #0
	subs r0, #8
	adds r1, r5, #0
	adds r1, #0x40
	b _0802D088
_0802CE42:
	adds r0, r4, #0
	subs r0, #0x26
	b _0802D028
_0802CE48:
	adds r0, r4, #0
	subs r0, #0x3c
	adds r1, r5, #0
	adds r1, #0x3c
	b _0802D088
_0802CE52:
	adds r0, r4, #0
	adds r0, #0x32
	adds r1, r5, #0
	adds r1, #0x32
	b _0802D088
_0802CE5C:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	b _0802D02C
_0802CE64:
	adds r0, r4, #0
	adds r0, #0x50
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802CE6E:
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r5, #0
	adds r1, #0x44
	b _0802D088
_0802CE78:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802CE82:
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r5, #0
	subs r1, #8
	b _0802D088
_0802CE8C:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	adds r1, #0x50
	b _0802D088
_0802CE96:
	cmp r0, #4
	bne _0802CF82
	ldrb r0, [r7]
	cmp r0, #0x18
	bls _0802CEA2
	b _0802D096
_0802CEA2:
	lsls r0, r0, #2
	ldr r1, _0802CEAC @ =_0802CEB0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CEAC: .4byte _0802CEB0
_0802CEB0: @ jump table
	.4byte _0802CF14 @ case 0
	.4byte _0802D096 @ case 1
	.4byte _0802CF1C @ case 2
	.4byte _0802D096 @ case 3
	.4byte _0802CF24 @ case 4
	.4byte _0802D096 @ case 5
	.4byte _0802CF2E @ case 6
	.4byte _0802D024 @ case 7
	.4byte _0802CF34 @ case 8
	.4byte _0802CF3E @ case 9
	.4byte _0802CF48 @ case 10
	.4byte _0802D096 @ case 11
	.4byte _0802CF50 @ case 12
	.4byte _0802D096 @ case 13
	.4byte _0802CF5A @ case 14
	.4byte _0802D096 @ case 15
	.4byte _0802CF64 @ case 16
	.4byte _0802CF6E @ case 17
	.4byte _0802CF78 @ case 18
	.4byte _0802D080 @ case 19
	.4byte _0802D096 @ case 20
	.4byte _0802D096 @ case 21
	.4byte _0802D096 @ case 22
	.4byte _0802D096 @ case 23
	.4byte _0802D090 @ case 24
_0802CF14:
	adds r0, r4, #0
	subs r0, #0x30
	adds r1, r5, #4
	b _0802D088
_0802CF1C:
	adds r1, r5, #0
	subs r1, #0x48
	adds r0, r4, #0
	b _0802D088
_0802CF24:
	adds r0, r4, #0
	subs r0, #8
	adds r1, r5, #0
	adds r1, #0x40
	b _0802D088
_0802CF2E:
	adds r0, r4, #0
	subs r0, #0x26
	b _0802D028
_0802CF34:
	adds r0, r4, #0
	subs r0, #0x3c
	adds r1, r5, #0
	adds r1, #0x3c
	b _0802D088
_0802CF3E:
	adds r0, r4, #0
	adds r0, #0x32
	adds r1, r5, #0
	adds r1, #0x32
	b _0802D088
_0802CF48:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	b _0802D088
_0802CF50:
	adds r0, r4, #0
	adds r0, #0x50
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802CF5A:
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r5, #0
	adds r1, #0x44
	b _0802D088
_0802CF64:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802CF6E:
	adds r0, r4, #0
	adds r0, #8
	adds r1, r5, #0
	subs r1, #0x40
	b _0802D088
_0802CF78:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	adds r1, #0x50
	b _0802D088
_0802CF82:
	cmp r0, #6
	beq _0802CF88
	b _0802D0A8
_0802CF88:
	ldrb r0, [r7]
	cmp r0, #0x18
	bls _0802CF90
	b _0802D096
_0802CF90:
	lsls r0, r0, #2
	ldr r1, _0802CF9C @ =_0802CFA0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802CF9C: .4byte _0802CFA0
_0802CFA0: @ jump table
	.4byte _0802D004 @ case 0
	.4byte _0802D096 @ case 1
	.4byte _0802D00C @ case 2
	.4byte _0802D096 @ case 3
	.4byte _0802D014 @ case 4
	.4byte _0802D096 @ case 5
	.4byte _0802D01E @ case 6
	.4byte _0802D024 @ case 7
	.4byte _0802D034 @ case 8
	.4byte _0802D03E @ case 9
	.4byte _0802D048 @ case 10
	.4byte _0802D096 @ case 11
	.4byte _0802D050 @ case 12
	.4byte _0802D096 @ case 13
	.4byte _0802D058 @ case 14
	.4byte _0802D096 @ case 15
	.4byte _0802D062 @ case 16
	.4byte _0802D06C @ case 17
	.4byte _0802D076 @ case 18
	.4byte _0802D080 @ case 19
	.4byte _0802D096 @ case 20
	.4byte _0802D096 @ case 21
	.4byte _0802D096 @ case 22
	.4byte _0802D096 @ case 23
	.4byte _0802D090 @ case 24
_0802D004:
	adds r0, r4, #0
	subs r0, #0x30
	adds r1, r5, #4
	b _0802D088
_0802D00C:
	adds r1, r5, #0
	subs r1, #0x48
	adds r0, r4, #0
	b _0802D088
_0802D014:
	adds r0, r4, #0
	subs r0, #8
	adds r1, r5, #0
	adds r1, #0x40
	b _0802D088
_0802D01E:
	adds r0, r4, #0
	subs r0, #0x26
	b _0802D028
_0802D024:
	adds r0, r4, #0
	adds r0, #0x26
_0802D028:
	adds r1, r5, #0
	subs r1, #0x30
_0802D02C:
	movs r2, #0x26
	bl ParticleSet
	b _0802D096
_0802D034:
	adds r0, r4, #0
	subs r0, #0x3c
	adds r1, r5, #0
	adds r1, #0x3c
	b _0802D088
_0802D03E:
	adds r0, r4, #0
	adds r0, #0x32
	adds r1, r5, #0
	adds r1, #0x32
	b _0802D088
_0802D048:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	b _0802D088
_0802D050:
	adds r0, r4, #0
	adds r0, #0x50
	adds r1, r5, #0
	b _0802D088
_0802D058:
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r5, #0
	adds r1, #0x44
	b _0802D088
_0802D062:
	adds r0, r4, #0
	subs r0, #0x40
	adds r1, r5, #0
	subs r1, #0x34
	b _0802D088
_0802D06C:
	adds r0, r4, #0
	adds r0, #8
	adds r1, r5, #0
	subs r1, #0x40
	b _0802D088
_0802D076:
	adds r0, r4, #0
	subs r0, #0x48
	adds r1, r5, #0
	adds r1, #0x50
	b _0802D088
_0802D080:
	adds r0, r4, #0
	adds r0, #0x4e
	adds r1, r5, #0
	adds r1, #0x48
_0802D088:
	movs r2, #0x25
	bl ParticleSet
	b _0802D096
_0802D090:
	ldr r1, _0802D0A4 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_0802D096:
	ldr r1, _0802D0A4 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0802D0AE
	.align 2, 0
_0802D0A4: .4byte gCurrentSprite
_0802D0A8:
	movs r0, #0
	strh r0, [r6]
	adds r1, r6, #0
_0802D0AE:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0x19
	bne _0802D136
	ldr r0, _0802D100 @ =gAtmosphericStabilizersOnline
	ldrh r2, [r0]
	adds r3, r2, #0
	movs r0, #1
	ands r0, r2
	movs r1, #2
	ands r1, r2
	cmp r1, #0
	beq _0802D0CC
	adds r0, #1
_0802D0CC:
	movs r1, #4
	ands r1, r2
	cmp r1, #0
	beq _0802D0DA
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0802D0DA:
	movs r1, #8
	ands r2, r1
	cmp r2, #0
	beq _0802D0E8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0802D0E8:
	movs r1, #0x10
	ands r3, r1
	cmp r3, #0
	beq _0802D0F6
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0802D0F6:
	cmp r0, #1
	bne _0802D104
	movs r1, #1
	b _0802D122
	.align 2, 0
_0802D100: .4byte gAtmosphericStabilizersOnline
_0802D104:
	cmp r0, #2
	bne _0802D10C
	movs r1, #2
	b _0802D122
_0802D10C:
	cmp r0, #3
	bne _0802D114
	movs r1, #3
	b _0802D122
_0802D114:
	cmp r0, #4
	bne _0802D11C
	movs r1, #4
	b _0802D122
_0802D11C:
	cmp r0, #5
	bne _0802D136
	movs r1, #5
_0802D122:
	cmp r0, #0
	beq _0802D136
	adds r0, r1, #0
	bl TrySpawnMessageBanner
	ldr r1, _0802D13C @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
_0802D136:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D13C: .4byte gPreventMovementTimer

	thumb_func_start AtmosphericStabilizerParasiteInit
AtmosphericStabilizerParasiteInit: @ 0x0802D140
	push {r4, lr}
	ldr r3, _0802D194 @ =gCurrentSprite
	ldrh r1, [r3]
	ldr r0, _0802D198 @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	subs r1, #3
	movs r0, #5
	strb r0, [r1]
	adds r1, #0x13
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0802D19C @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r0, r3, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldrb r0, [r3, #0x1e]
	adds r1, r3, #0
	cmp r0, #2
	beq _0802D1C4
	cmp r0, #2
	bgt _0802D1A0
	cmp r0, #1
	beq _0802D1AA
	b _0802D208
	.align 2, 0
_0802D194: .4byte gCurrentSprite
_0802D198: .4byte 0x0000FFFB
_0802D19C: .4byte sPrimarySpriteStats
_0802D1A0:
	cmp r0, #3
	beq _0802D1D0
	cmp r0, #4
	beq _0802D1EC
	b _0802D208
_0802D1AA:
	ldr r0, _0802D1BC @ =0x0000FFE0
	strh r0, [r1, #0xa]
	movs r0, #0x20
	strh r0, [r1, #0xc]
	ldr r0, _0802D1C0 @ =0x0000FFE8
	strh r0, [r1, #0xe]
	movs r0, #0x30
	strh r0, [r1, #0x10]
	b _0802D20C
	.align 2, 0
_0802D1BC: .4byte 0x0000FFE0
_0802D1C0: .4byte 0x0000FFE8
_0802D1C4:
	ldr r0, _0802D1CC @ =0x0000FFE0
	strh r0, [r1, #0xa]
	movs r0, #0x20
	b _0802D1F2
	.align 2, 0
_0802D1CC: .4byte 0x0000FFE0
_0802D1D0:
	ldr r0, _0802D1E4 @ =0x0000FFE8
	strh r0, [r1, #0xa]
	movs r0, #0x30
	strh r0, [r1, #0xc]
	ldr r0, _0802D1E8 @ =0x0000FFE0
	strh r0, [r1, #0xe]
	movs r0, #0x20
	strh r0, [r1, #0x10]
	b _0802D20C
	.align 2, 0
_0802D1E4: .4byte 0x0000FFE8
_0802D1E8: .4byte 0x0000FFE0
_0802D1EC:
	ldr r0, _0802D200 @ =0x0000FFE8
	strh r0, [r1, #0xa]
	movs r0, #0x30
_0802D1F2:
	strh r0, [r1, #0xc]
	ldr r0, _0802D204 @ =0x0000FFD0
	strh r0, [r1, #0xe]
	movs r0, #0x18
	strh r0, [r1, #0x10]
	b _0802D20C
	.align 2, 0
_0802D200: .4byte 0x0000FFE8
_0802D204: .4byte 0x0000FFD0
_0802D208:
	movs r0, #0
	strh r0, [r1]
_0802D20C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start AtmosphericStabilizerParasiteIdleInit
AtmosphericStabilizerParasiteIdleInit: @ 0x0802D214
	ldr r0, _0802D230 @ =gCurrentSprite
	ldr r1, _0802D234 @ =0x08327970
	str r1, [r0, #0x18]
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
	adds r2, r0, #0
	adds r2, #0x2e
	movs r1, #0x78
	strb r1, [r2]
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	bx lr
	.align 2, 0
_0802D230: .4byte gCurrentSprite
_0802D234: .4byte 0x08327970

	thumb_func_start AtmosphericStabilizerParasiteIdle
AtmosphericStabilizerParasiteIdle: @ 0x0802D238
	push {r4, lr}
	ldr r4, _0802D268 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0802D26C @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	strh r1, [r4, #2]
	ldrh r0, [r0, #4]
	strh r0, [r4, #4]
	bl CountPrimarySpritesThatCantAbsorbX
	cmp r0, #4
	ble _0802D270
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0x78
	strb r0, [r1]
	b _0802D2AA
	.align 2, 0
_0802D268: .4byte gCurrentSprite
_0802D26C: .4byte gSpriteData
_0802D270:
	adds r3, r4, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802D2AA
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802D2B0 @ =0x083279F8
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldrh r0, [r4]
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x2c
	strb r0, [r3]
	ldr r1, _0802D2B4 @ =gWrittenToMosaic_H
	ldr r0, _0802D2B8 @ =sXParasiteMosaicValues
	adds r0, #0x58
	ldrh r0, [r0]
	strh r0, [r1]
_0802D2AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D2B0: .4byte 0x083279F8
_0802D2B4: .4byte gWrittenToMosaic_H
_0802D2B8: .4byte sXParasiteMosaicValues

	thumb_func_start AtmosphericStabilizerParasiteSpawnX
AtmosphericStabilizerParasiteSpawnX: @ 0x0802D2BC
	push {r4, lr}
	sub sp, #0x10
	ldr r0, _0802D330 @ =gCurrentSprite
	mov ip, r0
	mov r4, ip
	adds r4, #0x23
	ldrb r1, [r4]
	ldr r2, _0802D334 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	mov r2, ip
	strh r1, [r2, #2]
	ldrh r0, [r0, #4]
	strh r0, [r2, #4]
	mov r0, ip
	adds r0, #0x2e
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
	ldr r3, _0802D338 @ =gWrittenToMosaic_H
	ldr r2, _0802D33C @ =sXParasiteMosaicValues
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3]
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	bne _0802D328
	mov r0, ip
	ldrh r1, [r0]
	ldr r0, _0802D340 @ =0x0000FFDF
	ands r0, r1
	mov r1, ip
	strh r0, [r1]
	ldrb r3, [r4]
	movs r0, #0x20
	str r0, [sp]
	ldrh r0, [r1, #2]
	str r0, [sp, #4]
	ldrh r0, [r1, #4]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x32
	movs r1, #0
	movs r2, #0
	bl SpriteSpawnNewXParasite
	bl AtmosphericStabilizerParasiteIdleInit
_0802D328:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D330: .4byte gCurrentSprite
_0802D334: .4byte gSpriteData
_0802D338: .4byte gWrittenToMosaic_H
_0802D33C: .4byte sXParasiteMosaicValues
_0802D340: .4byte 0x0000FFDF

	thumb_func_start AtmosphericStabilizerParasiteDeath
AtmosphericStabilizerParasiteDeath: @ 0x0802D344
	push {lr}
	ldr r1, _0802D390 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r2, [r0]
	ldr r0, _0802D394 @ =0x08327970
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	ldr r1, _0802D398 @ =gSpriteData
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x17
	strb r1, [r2]
	ldrb r0, [r0, #0x1d]
	subs r0, #0x2c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #9
	lsls r1, r0
	lsrs r1, r1, #0x10
	ldr r2, _0802D39C @ =gAtmosphericStabilizersOnline
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	cmp r1, #0x1f
	bne _0802D38C
	movs r0, #0x10
	bl EventCheckAdvance
_0802D38C:
	pop {r0}
	bx r0
	.align 2, 0
_0802D390: .4byte gCurrentSprite
_0802D394: .4byte 0x08327970
_0802D398: .4byte gSpriteData
_0802D39C: .4byte gAtmosphericStabilizersOnline

	thumb_func_start AtmosphericStabilizer
AtmosphericStabilizer: @ 0x0802D3A0
	push {lr}
	ldr r1, _0802D3B8 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0
	beq _0802D3BC
	bl SpriteUtilUpdateFreezeTimer
	b _0802D464
	.align 2, 0
_0802D3B8: .4byte gCurrentSprite
_0802D3BC:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x17
	beq _0802D3DC
	cmp r0, #0x17
	bgt _0802D3D0
	cmp r0, #0
	beq _0802D3D6
	b _0802D3F4
_0802D3D0:
	cmp r0, #0x18
	beq _0802D3E0
	b _0802D3F4
_0802D3D6:
	bl AtmosphericSbabilizerInit
	b _0802D464
_0802D3DC:
	bl AtmosphericStabilizerBackOnlineInit
_0802D3E0:
	ldr r0, _0802D3F0 @ =gCurrentSprite
	adds r0, #0x26
	movs r1, #1
	strb r1, [r0]
	bl AtmosphericStabilizerBackOnline
	b _0802D464
	.align 2, 0
_0802D3F0: .4byte gCurrentSprite
_0802D3F4:
	ldr r0, _0802D420 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802D464
	adds r0, r2, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D42C
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802D424
	ldrh r0, [r2, #4]
	adds r0, #1
	strh r0, [r2, #4]
	b _0802D444
	.align 2, 0
_0802D420: .4byte gFrameCounter8Bit
_0802D424:
	ldrh r0, [r2, #4]
	subs r0, #1
	strh r0, [r2, #4]
	b _0802D444
_0802D42C:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802D43E
	ldrh r0, [r2, #2]
	adds r0, #1
	b _0802D442
_0802D43E:
	ldrh r0, [r2, #2]
	subs r0, #1
_0802D442:
	strh r0, [r2, #2]
_0802D444:
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D464
	movs r0, #0x40
	strb r0, [r1]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
_0802D464:
	pop {r0}
	bx r0

	thumb_func_start AtmosphericStabilizerCover
AtmosphericStabilizerCover: @ 0x0802D468
	push {lr}
	ldr r0, _0802D480 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0802D48E
	cmp r0, #2
	bgt _0802D484
	cmp r0, #0
	beq _0802D48A
	b _0802D498
	.align 2, 0
_0802D480: .4byte gCurrentSprite
_0802D484:
	cmp r0, #0x18
	beq _0802D494
	b _0802D498
_0802D48A:
	bl AtmosphericStabilizerCoverInit
_0802D48E:
	bl AtmosphericStabilizerCoverIdle
	b _0802D498
_0802D494:
	bl AtmosphericStabilizerCoverExploding
_0802D498:
	pop {r0}
	bx r0

	thumb_func_start AtmosphericStabilizerParasite
AtmosphericStabilizerParasite: @ 0x0802D49C
	push {r4, lr}
	ldr r4, _0802D4D4 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0802D4B6
	movs r0, #0xb0
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0802D4B6:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0802D500
	cmp r0, #0x18
	bgt _0802D4DE
	cmp r0, #1
	beq _0802D4F6
	cmp r0, #1
	bgt _0802D4D8
	cmp r0, #0
	beq _0802D4F2
	b _0802D518
	.align 2, 0
_0802D4D4: .4byte gCurrentSprite
_0802D4D8:
	cmp r0, #2
	beq _0802D4FA
	b _0802D518
_0802D4DE:
	cmp r0, #0x58
	beq _0802D50E
	cmp r0, #0x58
	bgt _0802D4EC
	cmp r0, #0x57
	beq _0802D506
	b _0802D518
_0802D4EC:
	cmp r0, #0x5b
	beq _0802D514
	b _0802D518
_0802D4F2:
	bl AtmosphericStabilizerParasiteInit
_0802D4F6:
	bl AtmosphericStabilizerParasiteIdleInit
_0802D4FA:
	bl AtmosphericStabilizerParasiteIdle
	b _0802D518
_0802D500:
	bl AtmosphericStabilizerParasiteSpawnX
	b _0802D518
_0802D506:
	bl AtmosphericStabilizerParasiteDeath
	bl SpriteDyingInit
_0802D50E:
	bl SpriteDying
	b _0802D518
_0802D514:
	bl XParasiteInit
_0802D518:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ChozoStatueSetCollision
ChozoStatueSetCollision: @ 0x0802D520
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _0802D5A0 @ =gCurrentSprite
	ldrh r5, [r4, #2]
	ldrh r7, [r4, #4]
	ldr r0, _0802D5A4 @ =gCurrentClipdataAffectingAction
	mov r8, r0
	strb r6, [r0]
	movs r0, #0x20
	rsbs r0, r0, #0
	adds r0, r0, r5
	mov sb, r0
	adds r1, r7, #0
	bl ClipdataProcess
	mov r0, r8
	strb r6, [r0]
	movs r0, #0x60
	rsbs r0, r0, #0
	adds r0, r0, r5
	mov sl, r0
	adds r1, r7, #0
	bl ClipdataProcess
	mov r0, r8
	strb r6, [r0]
	subs r5, #0xa0
	adds r0, r5, #0
	adds r1, r7, #0
	bl ClipdataProcess
	adds r4, #0x2a
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802D5A8
	mov r0, r8
	strb r6, [r0]
	adds r4, r7, #0
	adds r4, #0x40
	mov r0, sb
	adds r1, r4, #0
	bl ClipdataProcess
	mov r0, r8
	strb r6, [r0]
	mov r0, sl
	adds r1, r4, #0
	bl ClipdataProcess
	mov r0, r8
	strb r6, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl ClipdataProcess
	b _0802D5D0
	.align 2, 0
_0802D5A0: .4byte gCurrentSprite
_0802D5A4: .4byte gCurrentClipdataAffectingAction
_0802D5A8:
	mov r0, r8
	strb r6, [r0]
	adds r4, r7, #0
	subs r4, #0x40
	mov r0, sb
	adds r1, r4, #0
	bl ClipdataProcess
	mov r0, r8
	strb r6, [r0]
	mov r0, sl
	adds r1, r4, #0
	bl ClipdataProcess
	mov r0, r8
	strb r6, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl ClipdataProcess
_0802D5D0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ChozoStatueInit
ChozoStatueInit: @ 0x0802D5E0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r1, _0802D604 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x26
	movs r5, #1
	strb r5, [r0]
	ldr r0, _0802D608 @ =gEquipment
	ldrb r0, [r0, #0xa]
	adds r3, r5, #0
	ands r3, r0
	adds r4, r1, #0
	cmp r3, #0
	beq _0802D60C
	movs r0, #0
	strh r0, [r4]
	b _0802D6BC
	.align 2, 0
_0802D604: .4byte gCurrentSprite
_0802D608: .4byte gEquipment
_0802D60C:
	ldr r2, _0802D664 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x25
	strb r2, [r0]
	ldrh r0, [r4]
	movs r6, #0x80
	lsls r6, r6, #8
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802D668 @ =0x0000FF40
	strh r0, [r4, #0xa]
	strh r3, [r4, #0xc]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _0802D670
	ldr r0, _0802D66C @ =0x0000FFE0
	strh r0, [r4, #0xe]
	movs r0, #0x60
	strh r0, [r4, #0x10]
	b _0802D680
	.align 2, 0
_0802D664: .4byte sPrimarySpriteStats
_0802D668: .4byte 0x0000FF40
_0802D66C: .4byte 0x0000FFE0
_0802D670:
	ldr r0, _0802D6C4 @ =0x0000FFA0
	strh r0, [r4, #0xe]
	movs r0, #0x20
	strh r0, [r4, #0x10]
	ldrh r0, [r4]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r4]
_0802D680:
	adds r1, r4, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802D6C8 @ =0x08328380
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	ldrh r4, [r4]
	movs r0, #0x40
	ands r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0x27
	bl SpriteSpawnSecondary
	movs r0, #2
	bl ChozoStatueSetCollision
_0802D6BC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802D6C4: .4byte 0x0000FFA0
_0802D6C8: .4byte 0x08328380

	thumb_func_start ChozoStatueIdle
ChozoStatueIdle: @ 0x0802D6CC
	bx lr
	.align 2, 0

	thumb_func_start ChozoStatueTransformingInit
ChozoStatueTransformingInit: @ 0x0802D6D0
	push {lr}
	ldr r3, _0802D704 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x46
	strb r0, [r1]
	ldrh r1, [r3]
	ldr r2, _0802D708 @ =0x00008020
	adds r0, r2, #0
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	movs r0, #0x2c
	strh r0, [r3, #6]
	movs r0, #1
	bl ChozoStatueSetCollision
	movs r0, #0x43
	movs r1, #7
	bl PlayMusic
	pop {r0}
	bx r0
	.align 2, 0
_0802D704: .4byte gCurrentSprite
_0802D708: .4byte 0x00008020

	thumb_func_start ChozoStatueTransforming
ChozoStatueTransforming: @ 0x0802D70C
	push {r4, lr}
	ldr r2, _0802D754 @ =gWrittenToMosaic_H
	ldr r1, _0802D758 @ =sXParasiteMosaicValues
	ldr r4, _0802D75C @ =gCurrentSprite
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
	bhi _0802D760
	ldrh r2, [r4, #6]
	movs r0, #0x56
	movs r1, #0
	bl SpriteLoadGfx
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0802D76E
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x59
	strb r0, [r1]
	movs r0, #0x56
	strb r0, [r4, #0x1d]
	ldrh r0, [r4]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4]
	b _0802D76E
	.align 2, 0
_0802D754: .4byte gWrittenToMosaic_H
_0802D758: .4byte sXParasiteMosaicValues
_0802D75C: .4byte gCurrentSprite
_0802D760:
	cmp r0, #0x14
	bne _0802D76E
	movs r0, #0x56
	movs r1, #0
	movs r2, #5
	bl SpriteLoadPal
_0802D76E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FakeChozoBallInit
FakeChozoBallInit: @ 0x0802D774
	push {r4, lr}
	ldr r3, _0802D7DC @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r2, [r0]
	ldrh r1, [r3]
	ldr r0, _0802D7E0 @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	ldr r1, _0802D7E4 @ =sSecondarySpriteStats
	ldrb r0, [r3, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	adds r1, #2
	movs r0, #0x30
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x28
	strb r4, [r0]
	adds r1, #2
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802D7E8 @ =0x0000FF4C
	strh r0, [r3, #0xa]
	adds r0, #0x40
	strh r0, [r3, #0xc]
	ldr r1, _0802D7EC @ =gSpriteData
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0802D7F4
	ldr r0, _0802D7F0 @ =0x0000FFA0
	strh r0, [r3, #0xe]
	adds r0, #0x40
	strh r0, [r3, #0x10]
	b _0802D804
	.align 2, 0
_0802D7DC: .4byte gCurrentSprite
_0802D7E0: .4byte 0x0000FFFB
_0802D7E4: .4byte sSecondarySpriteStats
_0802D7E8: .4byte 0x0000FF4C
_0802D7EC: .4byte gSpriteData
_0802D7F0: .4byte 0x0000FFA0
_0802D7F4:
	movs r0, #0x20
	strh r0, [r3, #0xe]
	movs r0, #0x60
	strh r0, [r3, #0x10]
	ldrh r0, [r3]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r3]
_0802D804:
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0802D81C @ =0x08328390
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D81C: .4byte 0x08328390

	thumb_func_start FakeChozoBallIdle
FakeChozoBallIdle: @ 0x0802D820
	push {lr}
	ldr r1, _0802D834 @ =gCurrentSprite
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	bne _0802D830
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
_0802D830:
	pop {r0}
	bx r0
	.align 2, 0
_0802D834: .4byte gCurrentSprite

	thumb_func_start FakeChozoBallExposedInit
FakeChozoBallExposedInit: @ 0x0802D838
	push {r4, r5, lr}
	ldr r2, _0802D870 @ =gCurrentSprite
	ldrh r0, [r2, #0x14]
	adds r0, #1
	movs r3, #0
	movs r4, #0
	strh r0, [r2, #0x14]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #8
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0802D874 @ =0x083283A0
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	adds r2, #0x24
	movs r0, #0x38
	strb r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D870: .4byte gCurrentSprite
_0802D874: .4byte 0x083283A0

	thumb_func_start FakeChozoBallExposed
FakeChozoBallExposed: @ 0x0802D878
	push {lr}
	ldr r3, _0802D8BC @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r1, #8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D8B6
	subs r1, #0xa
	movs r0, #0x3a
	strb r0, [r1]
	ldrh r1, [r3]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r3]
	ldr r2, _0802D8C0 @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	movs r1, #0x45
	strb r1, [r0]
_0802D8B6:
	pop {r0}
	bx r0
	.align 2, 0
_0802D8BC: .4byte gCurrentSprite
_0802D8C0: .4byte gSpriteData

	thumb_func_start FakeChozoBallTransformation
FakeChozoBallTransformation: @ 0x0802D8C4
	push {lr}
	ldr r3, _0802D8F8 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0802D8FC @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x46
	bne _0802D8F4
	ldrh r0, [r1, #6]
	cmp r0, #0x14
	bhi _0802D8F4
	movs r0, #0
	strh r0, [r3]
_0802D8F4:
	pop {r0}
	bx r0
	.align 2, 0
_0802D8F8: .4byte gCurrentSprite
_0802D8FC: .4byte gSpriteData

	thumb_func_start ChozoStatue
ChozoStatue: @ 0x0802D900
	push {lr}
	ldr r0, _0802D920 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0802D934
	cmp r0, #2
	bgt _0802D924
	cmp r0, #0
	beq _0802D92E
	b _0802D942
	.align 2, 0
_0802D920: .4byte gCurrentSprite
_0802D924:
	cmp r0, #0x45
	beq _0802D93A
	cmp r0, #0x46
	beq _0802D93E
	b _0802D942
_0802D92E:
	bl ChozoStatueInit
	b _0802D942
_0802D934:
	bl ChozoStatueIdle
	b _0802D942
_0802D93A:
	bl ChozoStatueTransformingInit
_0802D93E:
	bl ChozoStatueTransforming
_0802D942:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FakeChozoBall
FakeChozoBall: @ 0x0802D948
	push {lr}
	ldr r0, _0802D964 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x37
	beq _0802D97E
	cmp r0, #0x37
	bgt _0802D968
	cmp r0, #0
	beq _0802D972
	cmp r0, #2
	beq _0802D978
	b _0802D98E
	.align 2, 0
_0802D964: .4byte gCurrentSprite
_0802D968:
	cmp r0, #0x38
	beq _0802D984
	cmp r0, #0x3a
	beq _0802D98A
	b _0802D98E
_0802D972:
	bl FakeChozoBallInit
	b _0802D98E
_0802D978:
	bl FakeChozoBallIdle
	b _0802D98E
_0802D97E:
	bl FakeChozoBallExposedInit
	b _0802D98E
_0802D984:
	bl FakeChozoBallExposed
	b _0802D98E
_0802D98A:
	bl FakeChozoBallTransformation
_0802D98E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BeamCoreXTransformation
BeamCoreXTransformation: @ 0x0802D994
	push {lr}
	ldr r3, _0802D9BC @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r3, #6]
	subs r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802D9C8
	ldr r2, _0802D9C0 @ =gWrittenToMosaic_H
	ldr r1, _0802D9C4 @ =sXParasiteMosaicValues
	ldrh r0, [r3, #6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	b _0802D9DC
	.align 2, 0
_0802D9BC: .4byte gCurrentSprite
_0802D9C0: .4byte gWrittenToMosaic_H
_0802D9C4: .4byte sXParasiteMosaicValues
_0802D9C8:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1b
	strb r0, [r1]
	ldrh r1, [r3]
	ldr r0, _0802D9E0 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r3]
	bl ProjectileLoadEyeCoreXGraphics
_0802D9DC:
	pop {r0}
	bx r0
	.align 2, 0
_0802D9E0: .4byte 0x0000FFDF

	thumb_func_start BeamCoreXTransformationInit
BeamCoreXTransformationInit: @ 0x0802D9E4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	movs r5, #0
	ldr r0, _0802DA9C @ =gCurrentSprite
	mov ip, r0
	mov r1, ip
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #2]
	subs r0, #0x5c
	strh r0, [r1, #2]
	adds r1, #0x24
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	mov r2, ip
	strh r0, [r2, #6]
	ldrh r2, [r2]
	movs r0, #0x20
	orrs r2, r0
	movs r4, #0
	ldr r0, _0802DAA0 @ =0x0000F3FB
	ands r2, r0
	mov r0, ip
	strh r2, [r0]
	ldr r3, _0802DAA4 @ =sPrimarySpriteStats
	ldrb r1, [r0, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1, #0x14]
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	mov r3, ip
	adds r3, #0x21
	movs r0, #2
	strb r0, [r3]
	mov r0, ip
	adds r0, #0x25
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	orrs r2, r0
	mov r0, ip
	strh r2, [r0]
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802DAA8 @ =0x0000FFE0
	mov r2, ip
	strh r1, [r2, #0xa]
	movs r0, #0x20
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldr r0, _0802DAAC @ =0x0832AF80
	str r0, [r2, #0x18]
	strb r4, [r2, #0x1c]
	strh r5, [r2, #0x16]
	mov r0, ip
	adds r0, #0x30
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	subs r0, #4
	strb r4, [r0]
	ldrb r0, [r2, #0x1d]
	mov r6, ip
	cmp r0, #0x58
	beq _0802DACA
	cmp r0, #0x58
	bgt _0802DAB0
	cmp r0, #0x56
	beq _0802DABA
	cmp r0, #0x57
	beq _0802DAC2
	b _0802DAF0
	.align 2, 0
_0802DA9C: .4byte gCurrentSprite
_0802DAA0: .4byte 0x0000F3FB
_0802DAA4: .4byte sPrimarySpriteStats
_0802DAA8: .4byte 0x0000FFE0
_0802DAAC: .4byte 0x0832AF80
_0802DAB0:
	cmp r0, #0x59
	beq _0802DAD2
	cmp r0, #0xc2
	beq _0802DADA
	b _0802DAF0
_0802DABA:
	movs r5, #0x28
	movs r0, #0x29
	mov r8, r0
	b _0802DAF6
_0802DAC2:
	movs r5, #0x54
	movs r1, #0x55
	mov r8, r1
	b _0802DAF6
_0802DACA:
	movs r5, #0x56
	movs r2, #0x57
	mov r8, r2
	b _0802DAF6
_0802DAD2:
	movs r5, #0x58
	movs r0, #0x59
	mov r8, r0
	b _0802DAF6
_0802DADA:
	movs r5, #0x75
	movs r1, #0x76
	mov r8, r1
	ldr r0, _0802DAEC @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	strb r0, [r3]
	b _0802DAF6
	.align 2, 0
_0802DAEC: .4byte gIoRegisters
_0802DAF0:
	movs r0, #0
	strh r0, [r6]
	b _0802DB52
_0802DAF6:
	adds r4, r6, #0
	ldrb r2, [r4, #0x1f]
	movs r0, #0x23
	adds r0, r0, r4
	mov sb, r0
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r7, #0
	str r7, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xff
	bne _0802DB22
	strh r7, [r4]
	b _0802DB52
_0802DB22:
	ldrb r2, [r6, #0x1f]
	mov r1, sb
	ldrb r3, [r1]
	ldrh r0, [r6, #2]
	str r0, [sp]
	ldrh r0, [r6, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	bne _0802DB46
	strh r7, [r6]
	b _0802DB52
_0802DB46:
	ldr r1, _0802DB60 @ =gSpriteData
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	strb r2, [r0, #0x1e]
_0802DB52:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DB60: .4byte gSpriteData

	thumb_func_start BeamCoreXMovingInit
BeamCoreXMovingInit: @ 0x0802DB64
	ldr r3, _0802DB88 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x1c
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x2f
	strb r2, [r0]
	adds r0, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #2
	strb r2, [r0]
	adds r0, #3
	strb r1, [r0]
	bx lr
	.align 2, 0
_0802DB88: .4byte gCurrentSprite

	thumb_func_start BeamCoreXMoving
BeamCoreXMoving: @ 0x0802DB8C
	push {lr}
	sub sp, #8
	ldr r0, _0802DBBC @ =gCurrentSprite
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802DBB6
	ldr r1, _0802DBC0 @ =gSamusData
	ldrh r0, [r1, #0x18]
	subs r0, #0x48
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #0x16]
	movs r2, #2
	str r2, [sp]
	movs r2, #0xc0
	str r2, [sp, #4]
	movs r2, #0xa
	movs r3, #0x10
	bl SpriteUtilMoveBeamCoreX
_0802DBB6:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0802DBBC: .4byte gCurrentSprite
_0802DBC0: .4byte gSamusData

	thumb_func_start BeamCoreXMovingToTargetInit
BeamCoreXMovingToTargetInit: @ 0x0802DBC4
	push {lr}
	ldr r0, _0802DC18 @ =gCurrentSprite
	mov ip, r0
	mov r1, ip
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x5d
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc
	strb r0, [r1]
	movs r2, #0
	mov r0, ip
	strh r3, [r0, #0x14]
	subs r1, #3
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0802DC1C @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	mov r1, ip
	adds r1, #0x21
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x20
	strb r2, [r0]
	adds r0, #0xf
	strb r2, [r0]
	adds r0, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #2
	strb r2, [r0]
	adds r0, #3
	strb r1, [r0]
	subs r0, #0xb
	strb r1, [r0]
	bl CoreXMakeXParasitesFlee
	pop {r0}
	bx r0
	.align 2, 0
_0802DC18: .4byte gCurrentSprite
_0802DC1C: .4byte gIoRegisters

	thumb_func_start BeamCoreXMovingToTarget
BeamCoreXMovingToTarget: @ 0x0802DC20
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0802DC8C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	ldr r6, _0802DC90 @ =gCurrentSprite
	cmp r0, #0
	bne _0802DC3A
	ldrh r0, [r6]
	movs r1, #4
	eors r0, r1
	strh r0, [r6]
_0802DC3A:
	adds r5, r6, #0
	adds r1, r5, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldr r4, _0802DC94 @ =gAbilityRestingYPosition
	ldrh r0, [r4]
	ldr r7, _0802DC98 @ =gAbilityRestingXPosition
	ldrh r1, [r7]
	movs r2, #2
	str r2, [sp]
	ldr r2, _0802DC9C @ =0x00000141
	str r2, [sp, #4]
	movs r2, #0x10
	movs r3, #0x18
	bl XParasiteMoveWithSound
	ldrh r2, [r5, #2]
	ldrh r1, [r4]
	adds r0, r1, #6
	cmp r2, r0
	bge _0802DCBE
	subs r0, r1, #6
	cmp r2, r0
	ble _0802DCBE
	ldrh r2, [r5, #4]
	ldrh r1, [r7]
	adds r0, r1, #6
	cmp r2, r0
	bge _0802DCBE
	subs r0, r1, #6
	cmp r2, r0
	ble _0802DCBE
	ldrb r0, [r5, #0x1d]
	cmp r0, #0xc2
	bne _0802DCA0
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x37
	b _0802DCA6
	.align 2, 0
_0802DC8C: .4byte gFrameCounter8Bit
_0802DC90: .4byte gCurrentSprite
_0802DC94: .4byte gAbilityRestingYPosition
_0802DC98: .4byte gAbilityRestingXPosition
_0802DC9C: .4byte 0x00000141
_0802DCA0:
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x5e
_0802DCA6:
	strb r0, [r1]
	ldr r1, _0802DCC8 @ =gCurrentSprite
	ldrh r2, [r1]
	ldr r0, _0802DCCC @ =0x0000FFFB
	ands r0, r2
	movs r2, #0
	strh r0, [r1]
	adds r0, r1, #0
	adds r0, #0x30
	strb r2, [r0]
	adds r1, #0x31
	strb r2, [r1]
_0802DCBE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DCC8: .4byte gCurrentSprite
_0802DCCC: .4byte 0x0000FFFB

	thumb_func_start BeamCoreXRestingAtTarget
BeamCoreXRestingAtTarget: @ 0x0802DCD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0802DDB0 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	ldr r3, _0802DDB4 @ =0x083031E0
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r7, _0802DDB8 @ =0x00007FFF
	mov r8, r7
	cmp r0, r8
	bne _0802DCF8
	ldrh r2, [r3]
	movs r1, #0
_0802DCF8:
	adds r0, r1, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r2
	movs r6, #0
	strh r0, [r4, #2]
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r1, [r5]
	ldr r3, _0802DDBC @ =0x08303262
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r8
	bne _0802DD20
	ldrh r2, [r3]
	movs r1, #0
_0802DD20:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	ldrh r3, [r4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r3
	cmp r0, #0
	beq _0802DE14
	ldr r1, _0802DDC0 @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x5f
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	adds r1, #9
	strb r6, [r1]
	strb r0, [r5]
	subs r1, #1
	strb r6, [r1]
	mov r5, ip
	strb r0, [r5]
	movs r0, #0x80
	orrs r0, r3
	strh r0, [r4]
	adds r0, r4, #0
	adds r0, #0x2b
	strb r6, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x12]
	movs r0, #0x14
	strh r0, [r4, #6]
	strb r6, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x16]
	ldr r0, _0802DDC4 @ =0x0832AFC8
	str r0, [r4, #0x18]
	ldr r2, _0802DDC8 @ =gSamusData
	movs r7, #0x26
	ldrsh r0, [r2, r7]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	ldrh r1, [r2, #0x16]
	movs r2, #0x1d
	bl ParticleSet
	ldrb r1, [r4, #0x1d]
	cmp r1, #0x57
	beq _0802DDDE
	cmp r1, #0x57
	bgt _0802DDCC
	cmp r1, #0x56
	beq _0802DDD6
	b _0802DDF4
	.align 2, 0
_0802DDB0: .4byte gCurrentSprite
_0802DDB4: .4byte 0x083031E0
_0802DDB8: .4byte 0x00007FFF
_0802DDBC: .4byte 0x08303262
_0802DDC0: .4byte gPreventMovementTimer
_0802DDC4: .4byte 0x0832AFC8
_0802DDC8: .4byte gSamusData
_0802DDCC:
	cmp r1, #0x58
	beq _0802DDE6
	cmp r1, #0x59
	beq _0802DDEE
	b _0802DDF4
_0802DDD6:
	movs r0, #0xf
	bl EventCheckAdvance
	b _0802DDF4
_0802DDDE:
	movs r0, #0x3c
	bl EventCheckAdvance
	b _0802DDF4
_0802DDE6:
	movs r0, #0x4e
	bl EventCheckAdvance
	b _0802DDF4
_0802DDEE:
	movs r0, #0x5b
	bl EventCheckAdvance
_0802DDF4:
	movs r0, #0xc8
	lsls r0, r0, #1
	movs r1, #0x32
	movs r2, #0xa
	bl SpriteUtilRefillSamus
	ldr r1, _0802DE10 @ =0x030012F0
	movs r0, #0x30
	strb r0, [r1, #3]
	movs r0, #0x92
	bl SoundPlay
	b _0802DE26
	.align 2, 0
_0802DE10: .4byte 0x030012F0
_0802DE14:
	ldr r0, _0802DE30 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _0802DE26
	movs r0, #0xc3
	bl SoundPlay
_0802DE26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DE30: .4byte gFrameCounter8Bit

	thumb_func_start BeamCoreXAbsorbed
BeamCoreXAbsorbed: @ 0x0802DE34
	push {r4, lr}
	ldr r4, _0802DE50 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl XParasiteStickToSamus
	ldrh r0, [r4, #6]
	cmp r0, #0
	beq _0802DE54
	subs r0, #1
	b _0802DE72
	.align 2, 0
_0802DE50: .4byte gCurrentSprite
_0802DE54:
	ldrh r0, [r4, #0x12]
	cmp r0, #0x50
	bls _0802DE60
	subs r0, #8
	strh r0, [r4, #0x12]
	b _0802DE74
_0802DE60:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x60
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4]
	movs r0, #9
_0802DE72:
	strh r0, [r4, #6]
_0802DE74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BeamCoreXDisplayingMessage
BeamCoreXDisplayingMessage: @ 0x0802DE7C
	push {lr}
	sub sp, #0xc
	ldr r2, _0802DEAC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r2, #6]
	adds r1, r0, #0
	cmp r1, #0
	beq _0802DEC0
	subs r0, #1
	strh r0, [r2, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0802DEB0
	ldrh r2, [r2, #6]
	movs r0, #0x21
	movs r1, #0
	bl SpriteLoadGfx
	b _0802DEDC
	.align 2, 0
_0802DEAC: .4byte gCurrentSprite
_0802DEB0:
	cmp r0, #8
	bne _0802DEDC
	movs r0, #0x21
	movs r1, #0
	movs r2, #2
	bl SpriteLoadPal
	b _0802DEDC
_0802DEC0:
	strh r1, [r2]
	ldr r0, _0802DEE4 @ =gAbilityRestingYPosition
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0802DEE8 @ =gAbilityRestingXPosition
	ldrh r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0x21
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl SpriteSpawnPrimary
_0802DEDC:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_0802DEE4: .4byte gAbilityRestingYPosition
_0802DEE8: .4byte gAbilityRestingXPosition

	thumb_func_start BeamCoreXWaitToFlee
BeamCoreXWaitToFlee: @ 0x0802DEEC
	push {r4, lr}
	ldr r0, _0802DF2C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	ldr r4, _0802DF30 @ =gCurrentSprite
	cmp r0, #0
	bne _0802DF04
	ldrh r0, [r4]
	movs r1, #4
	eors r0, r1
	strh r0, [r4]
_0802DF04:
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xc0
	movs r1, #0xc0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	beq _0802DF26
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0xb4
	strb r0, [r1]
_0802DF26:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DF2C: .4byte gFrameCounter8Bit
_0802DF30: .4byte gCurrentSprite

	thumb_func_start BeamCoreXFlee
BeamCoreXFlee: @ 0x0802DF34
	push {r4, r5, r6, lr}
	ldr r0, _0802DFA8 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	ldr r5, _0802DFAC @ =gCurrentSprite
	cmp r0, #0
	bne _0802DF4C
	ldrh r0, [r5]
	movs r1, #4
	eors r0, r1
	strh r0, [r5]
_0802DF4C:
	movs r0, #0x31
	adds r0, r0, r5
	mov ip, r0
	ldrb r2, [r0]
	ldr r4, _0802DFB0 @ =0x08328480
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0802DFB4 @ =0x00007FFF
	cmp r1, r0
	bne _0802DF6A
	ldrh r3, [r4]
	movs r2, #0
_0802DF6A:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r1, [r5, #2]
	adds r1, r1, r3
	ldrh r0, [r5, #4]
	adds r0, #8
	strh r0, [r5, #4]
	adds r1, #1
	strh r1, [r5, #2]
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0802DFA2
	movs r0, #0x66
	bl EventCheckAdvance
	strh r4, [r5]
	movs r0, #0x3c
	movs r1, #0x2e
	movs r2, #0xa
	bl unk_372c
_0802DFA2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DFA8: .4byte gFrameCounter8Bit
_0802DFAC: .4byte gCurrentSprite
_0802DFB0: .4byte 0x08328480
_0802DFB4: .4byte 0x00007FFF

	thumb_func_start BeamCoreXShellInit
BeamCoreXShellInit: @ 0x0802DFB8
	push {r4, r5, r6, lr}
	ldr r0, _0802E044 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r2, r1, #0
	movs r5, #0
	movs r4, #0
	orrs r2, r0
	mov r0, ip
	adds r0, #0x35
	movs r3, #1
	strb r3, [r0]
	ldr r0, _0802E048 @ =0x0000FFFB
	ands r2, r0
	mov r6, ip
	strh r2, [r6]
	mov r1, ip
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	ldr r1, _0802E04C @ =sSecondarySpriteStats
	ldrb r0, [r6, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #0x14]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802E050 @ =0x0000FFC0
	strh r1, [r6, #0xa]
	movs r0, #0x40
	strh r0, [r6, #0xc]
	strh r1, [r6, #0xe]
	strh r0, [r6, #0x10]
	ldr r0, _0802E054 @ =0x0832B0A8
	str r0, [r6, #0x18]
	strb r5, [r6, #0x1c]
	strh r4, [r6, #0x16]
	mov r1, ip
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x24
	strb r3, [r0]
	movs r0, #0x80
	orrs r2, r0
	strh r2, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r6, #0x12]
	ldr r1, _0802E058 @ =gSamusData
	ldrh r0, [r6, #4]
	mov r2, ip
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _0802E05C
	adds r1, r2, #0
	adds r1, #0x2b
	movs r0, #0x80
	strb r0, [r1]
	b _0802E062
	.align 2, 0
_0802E044: .4byte gCurrentSprite
_0802E048: .4byte 0x0000FFFB
_0802E04C: .4byte sSecondarySpriteStats
_0802E050: .4byte 0x0000FFC0
_0802E054: .4byte 0x0832B0A8
_0802E058: .4byte gSamusData
_0802E05C:
	adds r0, r2, #0
	adds r0, #0x2b
	strb r5, [r0]
_0802E062:
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x75
	bne _0802E076
	ldr r0, _0802E07C @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x21
	strb r0, [r1]
_0802E076:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E07C: .4byte gIoRegisters

	thumb_func_start BeamCoreXShellTransformation
BeamCoreXShellTransformation: @ 0x0802E080
	push {lr}
	ldr r2, _0802E0B0 @ =gSpriteData
	ldr r3, _0802E0B4 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1b
	bne _0802E0AC
	ldrh r1, [r3]
	ldr r0, _0802E0B8 @ =0x00007FFF
	ands r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
_0802E0AC:
	pop {r0}
	bx r0
	.align 2, 0
_0802E0B0: .4byte gSpriteData
_0802E0B4: .4byte gCurrentSprite
_0802E0B8: .4byte 0x00007FFF

	thumb_func_start BeamCoreXShellIdle
BeamCoreXShellIdle: @ 0x0802E0BC
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _0802E120 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #1
	bne _0802E0FE
	movs r0, #0x32
	bl SpriteUtilCountPrimarySprites
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #5
	bhi _0802E0FE
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #2]
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	movs r0, #0x32
	movs r1, #0
	movs r2, #0
	bl SpriteSpawnNewXParasite
_0802E0FE:
	ldr r3, _0802E120 @ =gCurrentSprite
	ldrb r2, [r3, #0x1e]
	ldr r1, _0802E124 @ =gSpriteData
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	adds r2, r0, #0
	cmp r2, #0
	beq _0802E128
	adds r1, r0, #2
	adds r0, r3, #0
	adds r0, #0x20
	strb r1, [r0]
	b _0802E12E
	.align 2, 0
_0802E120: .4byte gCurrentSprite
_0802E124: .4byte gSpriteData
_0802E128:
	adds r0, r3, #0
	adds r0, #0x20
	strb r2, [r0]
_0802E12E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BeamCoreXEyeInit
BeamCoreXEyeInit: @ 0x0802E138
	push {r4, lr}
	ldr r0, _0802E1C8 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	movs r4, #0
	movs r3, #0
	orrs r1, r0
	mov r0, ip
	adds r0, #0x35
	movs r2, #3
	strb r2, [r0]
	movs r0, #0x80
	orrs r1, r0
	mov r0, ip
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	mov r1, ip
	strh r0, [r1, #0x12]
	mov r0, ip
	adds r0, #0x22
	strb r2, [r0]
	ldr r1, _0802E1CC @ =sSecondarySpriteStats
	mov r2, ip
	ldrb r0, [r2, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #0x14]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802E1D0 @ =0x0000FFD8
	strh r1, [r2, #0xa]
	movs r0, #0x28
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldr r0, _0802E1D4 @ =0x0832B0B8
	str r0, [r2, #0x18]
	strb r4, [r2, #0x1c]
	strh r3, [r2, #0x16]
	mov r0, ip
	adds r0, #0x25
	strb r4, [r0]
	mov r1, ip
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	adds r1, #0xb
	movs r0, #0x78
	strb r0, [r1]
	ldr r1, _0802E1D8 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _0802E1DC
	adds r1, r2, #0
	adds r1, #0x2b
	movs r0, #0x80
	strb r0, [r1]
	adds r1, #3
	strb r0, [r1]
	b _0802E1E6
	.align 2, 0
_0802E1C8: .4byte gCurrentSprite
_0802E1CC: .4byte sSecondarySpriteStats
_0802E1D0: .4byte 0x0000FFD8
_0802E1D4: .4byte 0x0832B0B8
_0802E1D8: .4byte gSamusData
_0802E1DC:
	adds r0, r2, #0
	adds r0, #0x2b
	strb r4, [r0]
	adds r0, #3
	strb r4, [r0]
_0802E1E6:
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x76
	bne _0802E1FA
	ldr r0, _0802E200 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x21
	strb r0, [r1]
_0802E1FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E200: .4byte gIoRegisters

	thumb_func_start BeamCoreXEyeTransformation
BeamCoreXEyeTransformation: @ 0x0802E204
	push {lr}
	ldr r3, _0802E22C @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0802E230 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802E234
	ldrh r1, [r3]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r3]
	b _0802E244
	.align 2, 0
_0802E22C: .4byte gCurrentSprite
_0802E230: .4byte gSpriteData
_0802E234:
	ldrh r1, [r3]
	ldr r0, _0802E248 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
_0802E244:
	pop {r0}
	bx r0
	.align 2, 0
_0802E248: .4byte 0x0000FFDF

	thumb_func_start BeamCoreXEyeHandleRotation
BeamCoreXEyeHandleRotation: @ 0x0802E24C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r0, #2
	mov ip, r0
	ldr r4, _0802E2C8 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	str r0, [sp]
	ldrb r1, [r4, #0x1e]
	str r1, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r3, [r0]
	ldr r0, _0802E2CC @ =gSamusData
	ldrh r1, [r0, #0x18]
	subs r1, #0x48
	lsls r1, r1, #0x10
	ldrh r0, [r0, #0x16]
	mov sb, r0
	ldr r2, _0802E2D0 @ =gSpriteData
	ldr r5, [sp]
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r6, [r0, #2]
	ldrh r0, [r0, #4]
	lsrs r7, r1, #0x10
	lsls r5, r6, #0x10
	mov r8, r5
	mov sl, r4
	cmp r1, r8
	bge _0802E2EA
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	adds r2, r5, #0
	subs r2, #0x40
	mov r4, sb
	lsls r1, r4, #0x10
	asrs r4, r1, #0x10
	mov sb, r0
	cmp r2, r4
	bge _0802E2B0
	adds r0, r5, #0
	adds r0, #0x40
_0802E2B0:
	cmp r1, sb
	ble _0802E2D4
	lsls r2, r6, #0x10
	asrs r1, r2, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	movs r4, #0xe0
	adds r5, r2, #0
	cmp r1, #0x3f
	bgt _0802E338
	b _0802E33C
	.align 2, 0
_0802E2C8: .4byte gCurrentSprite
_0802E2CC: .4byte gSamusData
_0802E2D0: .4byte gSpriteData
_0802E2D4:
	lsls r2, r6, #0x10
	asrs r1, r2, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	movs r4, #0xa0
	adds r5, r2, #0
	cmp r1, #0x3f
	bgt _0802E338
	movs r4, #0x80
	b _0802E360
_0802E2EA:
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	adds r2, r5, #0
	subs r2, #0x40
	mov r4, sb
	lsls r1, r4, #0x10
	asrs r4, r1, #0x10
	mov sb, r0
	cmp r2, r4
	bge _0802E30C
	adds r0, r5, #0
	adds r0, #0x40
	cmp r0, r4
	ble _0802E30C
	movs r4, #0x40
	mov r5, r8
	b _0802E360
_0802E30C:
	cmp r1, sb
	ble _0802E324
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r2, r6, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	movs r4, #0x20
	adds r5, r2, #0
	cmp r0, #0x3f
	bgt _0802E338
	b _0802E33C
_0802E324:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r2, r6, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	movs r4, #0x60
	adds r5, r2, #0
	cmp r0, #0x3f
	bgt _0802E338
	movs r4, #0x80
_0802E338:
	cmp r4, #0
	bne _0802E360
_0802E33C:
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	ldr r2, _0802E350 @ =0xFFFF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E354
	mov r4, ip
	subs r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E350: .4byte 0xFFFF0000
_0802E354:
	cmp r1, #0x7f
	bgt _0802E35A
	b _0802E470
_0802E35A:
	mov r1, ip
	adds r0, r3, r1
	b _0802E46C
_0802E360:
	cmp r4, #0x20
	bne _0802E38E
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	ldr r2, _0802E378 @ =0xFFDF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E37C
	mov r4, ip
	subs r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E378: .4byte 0xFFDF0000
_0802E37C:
	adds r0, r1, #0
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0802E470
	mov r1, ip
	adds r0, r3, r1
	b _0802E46C
_0802E38E:
	cmp r4, #0x40
	bne _0802E3BE
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	ldr r2, _0802E3A8 @ =0xFFBF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E3AC
	mov r4, ip
	subs r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E3A8: .4byte 0xFFBF0000
_0802E3AC:
	adds r0, r1, #0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0802E470
	mov r1, ip
	adds r0, r3, r1
	b _0802E46C
_0802E3BE:
	cmp r4, #0x60
	bne _0802E3EE
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	ldr r2, _0802E3D8 @ =0xFF9F0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E3DC
	mov r4, ip
	subs r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E3D8: .4byte 0xFF9F0000
_0802E3DC:
	adds r0, r1, #0
	subs r0, #0x60
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0802E470
	mov r1, ip
	adds r0, r3, r1
	b _0802E46C
_0802E3EE:
	cmp r4, #0x80
	bne _0802E412
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	ldr r2, _0802E408 @ =0xFFFF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E40C
	mov r4, ip
	adds r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E408: .4byte 0xFFFF0000
_0802E40C:
	cmp r1, #0x80
	ble _0802E470
	b _0802E468
_0802E412:
	cmp r4, #0xa0
	bne _0802E42C
	lsls r0, r3, #0x10
	ldr r2, _0802E428 @ =0xFFDF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E464
	mov r4, ip
	adds r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E428: .4byte 0xFFDF0000
_0802E42C:
	cmp r4, #0xc0
	bne _0802E448
	lsls r0, r3, #0x10
	ldr r2, _0802E444 @ =0xFFBF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E464
	mov r4, ip
	adds r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E444: .4byte 0xFFBF0000
_0802E448:
	cmp r4, #0xe0
	bne _0802E470
	lsls r0, r3, #0x10
	ldr r2, _0802E460 @ =0xFF9F0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	cmp r0, #0x7e
	bhi _0802E464
	mov r4, ip
	adds r0, r3, r4
	b _0802E46C
	.align 2, 0
_0802E460: .4byte 0xFF9F0000
_0802E464:
	cmp r0, #0x7f
	bls _0802E470
_0802E468:
	mov r1, ip
	subs r0, r3, r1
_0802E46C:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0802E470:
	mov r0, sl
	adds r0, #0x2e
	strb r3, [r0]
	ldr r4, [sp, #4]
	lsls r2, r4, #3
	subs r0, r2, r4
	lsls r0, r0, #3
	ldr r1, _0802E4B8 @ =gSpriteData
	adds r0, r0, r1
	adds r0, #0x2b
	strb r3, [r0]
	mov r0, sl
	adds r0, #0x2b
	strb r3, [r0]
	movs r0, #0xff
	ands r3, r0
	movs r6, #0x20
	ldr r1, _0802E4BC @ =0x080A4FA4
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r4, r1, #0
	cmp r0, #0
	bge _0802E4C0
	rsbs r0, r0, #0
	lsls r1, r0, #5
	cmp r1, #0
	bge _0802E4AC
	adds r1, #0xff
_0802E4AC:
	asrs r0, r5, #0x10
	asrs r1, r1, #8
	subs r0, r0, r1
	mov r5, sl
	strh r0, [r5, #2]
	b _0802E4D2
	.align 2, 0
_0802E4B8: .4byte gSpriteData
_0802E4BC: .4byte 0x080A4FA4
_0802E4C0:
	lsls r1, r0, #5
	cmp r1, #0
	bge _0802E4C8
	adds r1, #0xff
_0802E4C8:
	asrs r0, r5, #0x10
	asrs r1, r1, #8
	adds r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
_0802E4D2:
	lsls r0, r3, #0x10
	asrs r0, r0, #0xf
	adds r0, #0x80
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _0802E4FC
	rsbs r0, r0, #0
	adds r1, r0, #0
	muls r1, r6, r1
	cmp r1, #0
	bge _0802E4EE
	adds r1, #0xff
_0802E4EE:
	mov r4, sb
	asrs r0, r4, #0x10
	asrs r1, r1, #8
	subs r0, r0, r1
	mov r5, sl
	strh r0, [r5, #4]
	b _0802E512
_0802E4FC:
	adds r1, r0, #0
	muls r1, r6, r1
	cmp r1, #0
	bge _0802E506
	adds r1, #0xff
_0802E506:
	mov r3, sb
	asrs r0, r3, #0x10
	asrs r1, r1, #8
	adds r0, r0, r1
	mov r4, sl
	strh r0, [r4, #4]
_0802E512:
	mov r5, sl
	ldrh r1, [r5, #0x14]
	cmp r1, #0
	bne _0802E574
	strh r1, [r5]
	ldr r3, [sp, #4]
	subs r0, r2, r3
	lsls r0, r0, #3
	ldr r4, _0802E558 @ =gSpriteData
	adds r0, r0, r4
	strh r1, [r0]
	ldr r5, [sp]
	lsls r4, r5, #3
	subs r4, r4, r5
	lsls r4, r4, #3
	ldr r0, _0802E558 @ =gSpriteData
	adds r4, r4, r0
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x5c
	strb r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #0x2f
	bl ParticleSet
	ldrb r0, [r4, #0x1d]
	cmp r0, #0x58
	beq _0802E562
	cmp r0, #0x58
	bgt _0802E55C
	cmp r0, #0x56
	beq _0802E562
	b _0802E574
	.align 2, 0
_0802E558: .4byte gSpriteData
_0802E55C:
	cmp r0, #0x59
	beq _0802E56C
	b _0802E574
_0802E562:
	movs r0, #0x18
	movs r1, #6
	bl PlayMusic
	b _0802E574
_0802E56C:
	movs r0, #0xa
	movs r1, #0
	bl PlayMusic
_0802E574:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start BeamCoreXEyeClosed
BeamCoreXEyeClosed: @ 0x0802E584
	push {lr}
	bl BeamCoreXEyeHandleRotation
	ldr r2, _0802E5BC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0802E5B8
	ldrh r1, [r2]
	ldr r0, _0802E5C0 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r0, _0802E5C4 @ =0x0832B0C8
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r3, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
_0802E5B8:
	pop {r0}
	bx r0
	.align 2, 0
_0802E5BC: .4byte gCurrentSprite
_0802E5C0: .4byte 0x0000FFFB
_0802E5C4: .4byte 0x0832B0C8

	thumb_func_start BeamCoreXEyeOpening
BeamCoreXEyeOpening: @ 0x0802E5C8
	push {lr}
	bl BeamCoreXEyeHandleRotation
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802E5FA
	ldr r1, _0802E600 @ =gCurrentSprite
	ldrh r2, [r1]
	ldr r0, _0802E604 @ =0x00007FFF
	ands r0, r2
	movs r2, #0
	movs r3, #0
	strh r0, [r1]
	ldr r0, _0802E608 @ =0x0832B100
	str r0, [r1, #0x18]
	strb r2, [r1, #0x1c]
	strh r3, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1a
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #0xa0
	strb r0, [r1]
_0802E5FA:
	pop {r0}
	bx r0
	.align 2, 0
_0802E600: .4byte gCurrentSprite
_0802E604: .4byte 0x00007FFF
_0802E608: .4byte 0x0832B100

	thumb_func_start BeamCoreXEyeOpened
BeamCoreXEyeOpened: @ 0x0802E60C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	ldr r5, _0802E660 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bls _0802E644
	ldrh r0, [r5, #2]
	adds r0, #0x20
	ldrh r1, [r5, #4]
	movs r2, #0x2f
	bl ParticleSet
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
_0802E644:
	bl BeamCoreXEyeHandleRotation
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	adds r0, r1, #0
	cmp r0, #0x6e
	bne _0802E668
	ldr r0, _0802E664 @ =0x0832B110
	str r0, [r5, #0x18]
	movs r0, #0
	strb r0, [r5, #0x1c]
	strh r0, [r5, #0x16]
	b _0802E6E0
	.align 2, 0
_0802E660: .4byte gCurrentSprite
_0802E664: .4byte 0x0832B110
_0802E668:
	cmp r0, #0x3c
	bne _0802E6A0
	ldr r0, _0802E698 @ =0x0832B160
	str r0, [r5, #0x18]
	movs r4, #0
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	ldr r3, _0802E69C @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrb r3, [r0, #0x1e]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x4d
	bl SpriteSpawnSecondary
	b _0802E6E0
	.align 2, 0
_0802E698: .4byte 0x0832B160
_0802E69C: .4byte gSpriteData
_0802E6A0:
	cmp r0, #0x3b
	bhi _0802E6E0
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0802E6E0
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0802E6D0
	ldr r0, _0802E6CC @ =gSpriteData
	mov r2, r8
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	adds r1, #0x20
	movs r0, #2
	strb r0, [r1]
	b _0802E6E0
	.align 2, 0
_0802E6CC: .4byte gSpriteData
_0802E6D0:
	ldr r1, _0802E724 @ =gSpriteData
	mov r3, r8
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x20
	strb r2, [r0]
_0802E6E0:
	ldr r2, _0802E728 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2f
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov ip, r2
	cmp r1, #0
	beq _0802E6F8
	b _0802E8DE
_0802E6F8:
	ldr r0, _0802E72C @ =0x0832B100
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	mov r0, ip
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #5
	bne _0802E730
	movs r0, #1
	strb r0, [r3]
	mov r5, ip
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	b _0802E734
	.align 2, 0
_0802E724: .4byte gSpriteData
_0802E728: .4byte gCurrentSprite
_0802E72C: .4byte 0x0832B100
_0802E730:
	movs r0, #0x1e
	strb r0, [r3]
_0802E734:
	mov r1, ip
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x1c
	strb r0, [r1]
	ldr r3, _0802E79C @ =gSpriteData
	mov r5, r8
	lsls r4, r5, #3
	subs r1, r4, r5
	lsls r1, r1, #3
	adds r1, r1, r3
	adds r5, r1, #0
	adds r5, #0x2d
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r1, #0x20
	strb r2, [r1]
	mov r0, ip
	ldrh r0, [r0, #2]
	str r0, [sp, #0x10]
	mov r1, ip
	ldrh r1, [r1, #4]
	str r1, [sp, #0x14]
	mov r0, ip
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r2, r1, #0
	adds r0, r1, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	asrs r0, r0, #0x1f
	mov sb, r0
	movs r0, #0x40
	mov r5, sb
	ands r5, r0
	mov sb, r5
	adds r0, r1, #0
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _0802E7AC
	adds r0, r1, #0
	subs r0, #0x31
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _0802E7A0
	movs r7, #5
	b _0802E7EC
	.align 2, 0
_0802E79C: .4byte gSpriteData
_0802E7A0:
	adds r0, r1, #0
	subs r0, #0x51
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _0802E7B0
_0802E7AC:
	movs r7, #3
	b _0802E7EC
_0802E7B0:
	adds r0, r1, #0
	subs r0, #0x71
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _0802E7C0
	movs r7, #1
	b _0802E7EC
_0802E7C0:
	adds r0, r1, #0
	adds r0, #0x6f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _0802E7EA
	adds r0, r1, #0
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _0802E7DC
	movs r7, #4
	b _0802E7EC
_0802E7DC:
	adds r0, r2, #0
	adds r0, #0x2f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r7, #1
	cmp r0, #0x1f
	bhi _0802E7EC
_0802E7EA:
	movs r7, #2
_0802E7EC:
	mov r1, r8
	subs r0, r4, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrb r0, [r0, #0x1d]
	cmp r0, #0x58
	beq _0802E81A
	cmp r0, #0x58
	bgt _0802E808
	cmp r0, #0x56
	beq _0802E812
	cmp r0, #0x57
	beq _0802E816
	b _0802E8DE
_0802E808:
	cmp r0, #0x59
	beq _0802E81E
	cmp r0, #0xc2
	beq _0802E822
	b _0802E8DE
_0802E812:
	movs r6, #0x4e
	b _0802E824
_0802E816:
	movs r6, #0x4f
	b _0802E824
_0802E81A:
	movs r6, #0x50
	b _0802E824
_0802E81E:
	movs r6, #0x51
	b _0802E824
_0802E822:
	movs r6, #0x74
_0802E824:
	ldr r2, [sp, #0x10]
	str r2, [sp]
	ldr r3, [sp, #0x14]
	str r3, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xa
	mov r3, r8
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	str r3, [sp, #0xc]
	cmp r3, #0xff
	beq _0802E8DE
	ldr r0, _0802E888 @ =gSpriteData
	mov sl, r0
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #3
	mov r1, sl
	adds r5, r0, r1
	adds r0, r5, #0
	adds r0, #0x2d
	movs r2, #0
	mov r8, r2
	strb r7, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	ldr r2, [sp, #0x10]
	str r2, [sp]
	ldr r0, [sp, #0x14]
	str r0, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0xa
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	bne _0802E88C
	mov r2, r8
	strh r2, [r5]
	b _0802E8DE
	.align 2, 0
_0802E888: .4byte gSpriteData
_0802E88C:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	mov r3, sl
	adds r4, r0, r3
	adds r0, r4, #0
	adds r0, #0x2d
	strb r7, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	ldr r2, [sp, #0x10]
	str r2, [sp]
	ldr r3, [sp, #0x14]
	str r3, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r1, #2
	movs r2, #0xa
	ldr r3, [sp, #0xc]
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	bne _0802E8CA
	mov r1, r8
	strh r1, [r5]
	strh r1, [r4]
	b _0802E8DE
_0802E8CA:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	add r0, sl
	adds r1, r0, #0
	adds r1, #0x2d
	strb r7, [r1]
	adds r0, #0x2e
	mov r2, r8
	strb r2, [r0]
_0802E8DE:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BeamCoreXEyeShooting
BeamCoreXEyeShooting: @ 0x0802E8F0
	push {r4, lr}
	ldr r4, _0802E974 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0802E922
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bls _0802E922
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	movs r2, #0x2f
	bl ParticleSet
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
_0802E922:
	ldr r0, _0802E974 @ =gCurrentSprite
	mov ip, r0
	mov r1, ip
	adds r1, #0x2f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0802E96C
	mov r3, ip
	ldrh r1, [r3]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	ldr r0, _0802E978 @ =0x0832B1B0
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r2, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
	ldr r2, _0802E97C @ =gSpriteData
	mov r0, ip
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2d
	strb r3, [r0]
_0802E96C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E974: .4byte gCurrentSprite
_0802E978: .4byte 0x0832B1B0
_0802E97C: .4byte gSpriteData

	thumb_func_start BeamCoreXEyeClosing
BeamCoreXEyeClosing: @ 0x0802E980
	push {lr}
	bl BeamCoreXEyeHandleRotation
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802E9B0
	ldr r3, _0802E9B4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	adds r1, #0xb
	movs r0, #0x64
	strb r0, [r1]
	ldr r0, _0802E9B8 @ =0x0832B0B8
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	strh r0, [r3]
_0802E9B0:
	pop {r0}
	bx r0
	.align 2, 0
_0802E9B4: .4byte gCurrentSprite
_0802E9B8: .4byte 0x0832B0B8

	thumb_func_start BeamCoreXGlowingInit
BeamCoreXGlowingInit: @ 0x0802E9BC
	push {r4, r5, r6, lr}
	ldr r0, _0802EA3C @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0802EA40 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x22
	movs r2, #2
	strb r2, [r0]
	adds r0, #0x13
	movs r5, #3
	strb r5, [r0]
	subs r0, #0xe
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802EA44 @ =0x0000FFFC
	mov r6, ip
	strh r1, [r6, #0xa]
	movs r0, #4
	strh r0, [r6, #0xc]
	strh r1, [r6, #0xe]
	strh r0, [r6, #0x10]
	ldr r0, _0802EA48 @ =0x0832AFE0
	str r0, [r6, #0x18]
	strb r3, [r6, #0x1c]
	strh r4, [r6, #0x16]
	mov r1, ip
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	subs r0, #1
	strb r2, [r0]
	ldr r2, _0802EA4C @ =gSpriteData
	subs r0, #1
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #0x1d]
	cmp r0, #0x76
	bne _0802EA36
	ldr r0, _0802EA50 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	adds r0, r5, #0
	ands r0, r1
	mov r1, ip
	adds r1, #0x21
	strb r0, [r1]
_0802EA36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802EA3C: .4byte gCurrentSprite
_0802EA40: .4byte 0x0000FFFB
_0802EA44: .4byte 0x0000FFFC
_0802EA48: .4byte 0x0832AFE0
_0802EA4C: .4byte gSpriteData
_0802EA50: .4byte gIoRegisters

	thumb_func_start BeamCoreXGlowingIdle
BeamCoreXGlowingIdle: @ 0x0802EA54
	push {lr}
	ldr r3, _0802EA78 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0802EA7C @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r2, r0, r2
	ldrh r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _0802EA80
	strh r1, [r3]
	b _0802EA9C
	.align 2, 0
_0802EA78: .4byte gCurrentSprite
_0802EA7C: .4byte gSpriteData
_0802EA80:
	ldrh r0, [r2, #2]
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	strh r0, [r3, #4]
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0802EA9C
	strh r0, [r3]
_0802EA9C:
	pop {r0}
	bx r0

	thumb_func_start BeamCoreX
BeamCoreX: @ 0x0802EAA0
	push {lr}
	ldr r0, _0802EABC @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #0x1b
	cmp r0, #0x45
	bls _0802EAB0
	b _0802EC18
_0802EAB0:
	lsls r0, r0, #2
	ldr r1, _0802EAC0 @ =_0802EAC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EABC: .4byte gCurrentSprite
_0802EAC0: .4byte _0802EAC4
_0802EAC4: @ jump table
	.4byte _0802EBE6 @ case 0
	.4byte _0802EBEA @ case 1
	.4byte _0802EC18 @ case 2
	.4byte _0802EC18 @ case 3
	.4byte _0802EC18 @ case 4
	.4byte _0802EC18 @ case 5
	.4byte _0802EC18 @ case 6
	.4byte _0802EC18 @ case 7
	.4byte _0802EC18 @ case 8
	.4byte _0802EC18 @ case 9
	.4byte _0802EC18 @ case 10
	.4byte _0802EC18 @ case 11
	.4byte _0802EC18 @ case 12
	.4byte _0802EC18 @ case 13
	.4byte _0802EC18 @ case 14
	.4byte _0802EC18 @ case 15
	.4byte _0802EC18 @ case 16
	.4byte _0802EC18 @ case 17
	.4byte _0802EC18 @ case 18
	.4byte _0802EC18 @ case 19
	.4byte _0802EC18 @ case 20
	.4byte _0802EC18 @ case 21
	.4byte _0802EC18 @ case 22
	.4byte _0802EC18 @ case 23
	.4byte _0802EC18 @ case 24
	.4byte _0802EC18 @ case 25
	.4byte _0802EC18 @ case 26
	.4byte _0802EC18 @ case 27
	.4byte _0802EC0E @ case 28
	.4byte _0802EC14 @ case 29
	.4byte _0802EC18 @ case 30
	.4byte _0802EC18 @ case 31
	.4byte _0802EC18 @ case 32
	.4byte _0802EC18 @ case 33
	.4byte _0802EC18 @ case 34
	.4byte _0802EC18 @ case 35
	.4byte _0802EC18 @ case 36
	.4byte _0802EC18 @ case 37
	.4byte _0802EC18 @ case 38
	.4byte _0802EC18 @ case 39
	.4byte _0802EC18 @ case 40
	.4byte _0802EC18 @ case 41
	.4byte _0802EC18 @ case 42
	.4byte _0802EC18 @ case 43
	.4byte _0802EC18 @ case 44
	.4byte _0802EC18 @ case 45
	.4byte _0802EC18 @ case 46
	.4byte _0802EC18 @ case 47
	.4byte _0802EC18 @ case 48
	.4byte _0802EC18 @ case 49
	.4byte _0802EC18 @ case 50
	.4byte _0802EC18 @ case 51
	.4byte _0802EC18 @ case 52
	.4byte _0802EC18 @ case 53
	.4byte _0802EC18 @ case 54
	.4byte _0802EC18 @ case 55
	.4byte _0802EC18 @ case 56
	.4byte _0802EC18 @ case 57
	.4byte _0802EC18 @ case 58
	.4byte _0802EC18 @ case 59
	.4byte _0802EC18 @ case 60
	.4byte _0802EC18 @ case 61
	.4byte _0802EBDC @ case 62
	.4byte _0802EBE0 @ case 63
	.4byte _0802EC18 @ case 64
	.4byte _0802EBF0 @ case 65
	.4byte _0802EBF6 @ case 66
	.4byte _0802EBFC @ case 67
	.4byte _0802EC02 @ case 68
	.4byte _0802EC08 @ case 69
_0802EBDC:
	bl BeamCoreXTransformationInit
_0802EBE0:
	bl BeamCoreXTransformation
	b _0802EC18
_0802EBE6:
	bl BeamCoreXMovingInit
_0802EBEA:
	bl BeamCoreXMoving
	b _0802EC18
_0802EBF0:
	bl BeamCoreXMovingToTargetInit
	b _0802EC18
_0802EBF6:
	bl BeamCoreXMovingToTarget
	b _0802EC18
_0802EBFC:
	bl BeamCoreXRestingAtTarget
	b _0802EC18
_0802EC02:
	bl BeamCoreXAbsorbed
	b _0802EC18
_0802EC08:
	bl BeamCoreXDisplayingMessage
	b _0802EC18
_0802EC0E:
	bl BeamCoreXWaitToFlee
	b _0802EC18
_0802EC14:
	bl BeamCoreXFlee
_0802EC18:
	pop {r0}
	bx r0

	thumb_func_start BeamCoreXShell
BeamCoreXShell: @ 0x0802EC1C
	push {lr}
	ldr r2, _0802EC4C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r3, _0802EC50 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
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
	beq _0802EC54
	ldrh r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	b _0802EC5A
	.align 2, 0
_0802EC4C: .4byte gCurrentSprite
_0802EC50: .4byte gSpriteData
_0802EC54:
	ldrh r1, [r2]
	ldr r0, _0802EC70 @ =0x0000FFDF
	ands r0, r1
_0802EC5A:
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	beq _0802EC80
	cmp r0, #1
	bgt _0802EC74
	cmp r0, #0
	beq _0802EC7A
	b _0802EC8A
	.align 2, 0
_0802EC70: .4byte 0x0000FFDF
_0802EC74:
	cmp r0, #2
	beq _0802EC86
	b _0802EC8A
_0802EC7A:
	bl BeamCoreXShellInit
	b _0802EC8A
_0802EC80:
	bl BeamCoreXShellTransformation
	b _0802EC8A
_0802EC86:
	bl BeamCoreXShellIdle
_0802EC8A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BeamCoreXEye
BeamCoreXEye: @ 0x0802EC90
	push {lr}
	ldr r0, _0802ECB0 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1e
	bhi _0802ED5A
	lsls r0, r0, #2
	ldr r1, _0802ECB4 @ =_0802ECB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802ECB0: .4byte gCurrentSprite
_0802ECB4: .4byte _0802ECB8
_0802ECB8: @ jump table
	.4byte _0802ED34 @ case 0
	.4byte _0802ED38 @ case 1
	.4byte _0802ED3E @ case 2
	.4byte _0802ED5A @ case 3
	.4byte _0802ED5A @ case 4
	.4byte _0802ED5A @ case 5
	.4byte _0802ED5A @ case 6
	.4byte _0802ED5A @ case 7
	.4byte _0802ED5A @ case 8
	.4byte _0802ED5A @ case 9
	.4byte _0802ED5A @ case 10
	.4byte _0802ED5A @ case 11
	.4byte _0802ED5A @ case 12
	.4byte _0802ED5A @ case 13
	.4byte _0802ED5A @ case 14
	.4byte _0802ED5A @ case 15
	.4byte _0802ED5A @ case 16
	.4byte _0802ED5A @ case 17
	.4byte _0802ED5A @ case 18
	.4byte _0802ED5A @ case 19
	.4byte _0802ED5A @ case 20
	.4byte _0802ED5A @ case 21
	.4byte _0802ED5A @ case 22
	.4byte _0802ED5A @ case 23
	.4byte _0802ED44 @ case 24
	.4byte _0802ED5A @ case 25
	.4byte _0802ED4A @ case 26
	.4byte _0802ED5A @ case 27
	.4byte _0802ED50 @ case 28
	.4byte _0802ED5A @ case 29
	.4byte _0802ED56 @ case 30
_0802ED34:
	bl BeamCoreXEyeInit
_0802ED38:
	bl BeamCoreXEyeTransformation
	b _0802ED5A
_0802ED3E:
	bl BeamCoreXEyeClosed
	b _0802ED5A
_0802ED44:
	bl BeamCoreXEyeOpening
	b _0802ED5A
_0802ED4A:
	bl BeamCoreXEyeOpened
	b _0802ED5A
_0802ED50:
	bl BeamCoreXEyeShooting
	b _0802ED5A
_0802ED56:
	bl BeamCoreXEyeClosing
_0802ED5A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BeamCoreXGlowing
BeamCoreXGlowing: @ 0x0802ED60
	push {lr}
	ldr r0, _0802ED7C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802ED80
	cmp r0, #2
	beq _0802ED84
	b _0802ED88
	.align 2, 0
_0802ED7C: .4byte gCurrentSprite
_0802ED80:
	bl BeamCoreXGlowingInit
_0802ED84:
	bl BeamCoreXGlowingIdle
_0802ED88:
	pop {r0}
	bx r0

	thumb_func_start CoreXChargeBeamInit
CoreXChargeBeamInit: @ 0x0802ED8C
	push {r4, lr}
	ldr r2, _0802EDD8 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x25
	movs r1, #0
	movs r0, #4
	strb r0, [r3]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802EDDC @ =0x0000FFF4
	strh r1, [r2, #0xa]
	movs r0, #0xc
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldrb r0, [r2, #0x1e]
	adds r4, r2, #0
	cmp r0, #0
	beq _0802EE34
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _0802EE28
	lsls r0, r0, #2
	ldr r1, _0802EDE0 @ =_0802EDE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EDD8: .4byte gCurrentSprite
_0802EDDC: .4byte 0x0000FFF4
_0802EDE0: .4byte _0802EDE4
_0802EDE4: @ jump table
	.4byte _0802EE28 @ case 0
	.4byte _0802EE04 @ case 1
	.4byte _0802EDF8 @ case 2
	.4byte _0802EE1C @ case 3
	.4byte _0802EE10 @ case 4
_0802EDF8:
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
_0802EE04:
	ldr r0, _0802EE0C @ =0x0858D9E8
	str r0, [r4, #0x18]
	b _0802EEBA
	.align 2, 0
_0802EE0C: .4byte 0x0858D9E8
_0802EE10:
	ldrh r1, [r4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r4]
_0802EE1C:
	ldr r0, _0802EE24 @ =0x0858D9F8
	str r0, [r4, #0x18]
	b _0802EEBA
	.align 2, 0
_0802EE24: .4byte 0x0858D9F8
_0802EE28:
	ldr r0, _0802EE30 @ =0x0858D9D8
	str r0, [r4, #0x18]
	b _0802EEBA
	.align 2, 0
_0802EE30: .4byte 0x0858D9D8
_0802EE34:
	movs r0, #0xca
	bl SoundPlay
	ldrh r0, [r4]
	ldr r1, _0802EE58 @ =0x0000FFFB
	ands r1, r0
	strh r1, [r4]
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _0802EEB4
	lsls r0, r0, #2
	ldr r1, _0802EE5C @ =_0802EE60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EE58: .4byte 0x0000FFFB
_0802EE5C: .4byte _0802EE60
_0802EE60: @ jump table
	.4byte _0802EEB4 @ case 0
	.4byte _0802EE84 @ case 1
	.4byte _0802EE74 @ case 2
	.4byte _0802EEA4 @ case 3
	.4byte _0802EE94 @ case 4
_0802EE74:
	ldr r0, _0802EE8C @ =gCurrentSprite
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	adds r4, r0, #0
_0802EE84:
	ldr r0, _0802EE90 @ =0x0858D9A8
	str r0, [r4, #0x18]
	b _0802EEBA
	.align 2, 0
_0802EE8C: .4byte gCurrentSprite
_0802EE90: .4byte 0x0858D9A8
_0802EE94:
	ldr r0, _0802EEAC @ =gCurrentSprite
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	adds r4, r0, #0
_0802EEA4:
	ldr r0, _0802EEB0 @ =0x0858D9C0
	str r0, [r4, #0x18]
	b _0802EEBA
	.align 2, 0
_0802EEAC: .4byte gCurrentSprite
_0802EEB0: .4byte 0x0858D9C0
_0802EEB4:
	ldr r1, _0802EEC0 @ =gCurrentSprite
	ldr r0, _0802EEC4 @ =0x0858D990
	str r0, [r1, #0x18]
_0802EEBA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802EEC0: .4byte gCurrentSprite
_0802EEC4: .4byte 0x0858D990

	thumb_func_start CoreXChargeBeam
CoreXChargeBeam: @ 0x0802EEC8
	push {r4, lr}
	ldr r3, _0802EF4C @ =gCurrentSprite
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _0802EF6E
	ldrh r4, [r3]
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0802EEFA
	ldr r2, _0802EF50 @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x36
	bls _0802EEFA
	ldr r0, _0802EF54 @ =0x0000FFFB
	ands r0, r4
	strh r0, [r3]
_0802EEFA:
	ldr r1, _0802EF58 @ =gCurrentClipdataAffectingAction
	movs r0, #6
	strb r0, [r1]
	ldr r4, _0802EF4C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0802EF5C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EF60
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802EF3A
	ldr r2, _0802EF50 @ =gSpriteData
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r1, r0, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x36
	bhi _0802EF3A
	movs r0, #0x37
	strb r0, [r1]
_0802EF3A:
	ldr r4, _0802EF4C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #4
	bl ParticleSet
	movs r0, #0
	strh r0, [r4]
	b _0802EFC4
	.align 2, 0
_0802EF4C: .4byte gCurrentSprite
_0802EF50: .4byte gSpriteData
_0802EF54: .4byte 0x0000FFFB
_0802EF58: .4byte gCurrentClipdataAffectingAction
_0802EF5C: .4byte gPreviousCollisionCheck
_0802EF60:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0802EF6E
	bl SpriteUtilMoveEyeCoreXBeamPart
_0802EF6E:
	ldr r0, _0802EF8C @ =gCurrentSprite
	adds r4, r0, #0
	adds r4, #0x24
	ldrb r1, [r4]
	adds r2, r0, #0
	cmp r1, #2
	beq _0802EFAE
	cmp r1, #2
	bgt _0802EF90
	cmp r1, #0
	beq _0802EF9A
	cmp r1, #1
	beq _0802EFA0
	b _0802EFC0
	.align 2, 0
_0802EF8C: .4byte gCurrentSprite
_0802EF90:
	cmp r1, #3
	beq _0802EFB2
	cmp r1, #0x37
	beq _0802EFBA
	b _0802EFC0
_0802EF9A:
	bl CoreXChargeBeamInit
	b _0802EFA6
_0802EFA0:
	movs r0, #0x10
	bl SpriteUtilMoveEyeCoreXBeam
_0802EFA6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0802EFC4
_0802EFAE:
	movs r0, #3
	strb r0, [r4]
_0802EFB2:
	movs r0, #0x18
	bl SpriteUtilMoveEyeCoreXBeam
	b _0802EFC4
_0802EFBA:
	movs r0, #0x38
	strb r0, [r4]
	b _0802EFC4
_0802EFC0:
	movs r0, #0
	strh r0, [r2]
_0802EFC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CoreXWideBeamInit
CoreXWideBeamInit: @ 0x0802EFCC
	push {lr}
	movs r0, #0xc9
	bl SoundPlay
	ldr r2, _0802F020 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x25
	movs r1, #0
	movs r0, #4
	strb r0, [r3]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _0802F024 @ =0x0000FFF0
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldrh r1, [r2]
	adds r0, #0xb
	ands r0, r1
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _0802F088
	lsls r0, r0, #2
	ldr r1, _0802F028 @ =_0802F02C
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	mov pc, r0
	.align 2, 0
_0802F020: .4byte gCurrentSprite
_0802F024: .4byte 0x0000FFF0
_0802F028: .4byte _0802F02C
_0802F02C: @ jump table
	.4byte _0802F088 @ case 0
	.4byte _0802F05C @ case 1
	.4byte _0802F040 @ case 2
	.4byte _0802F07C @ case 3
	.4byte _0802F06C @ case 4
_0802F040:
	ldr r1, _0802F054 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _0802F058 @ =0x0858DBFC
	b _0802F08C
	.align 2, 0
_0802F054: .4byte gCurrentSprite
_0802F058: .4byte 0x0858DBFC
_0802F05C:
	ldr r1, _0802F064 @ =gCurrentSprite
	ldr r0, _0802F068 @ =0x0858DBFC
	b _0802F08C
	.align 2, 0
_0802F064: .4byte gCurrentSprite
_0802F068: .4byte 0x0858DBFC
_0802F06C:
	ldr r0, _0802F080 @ =gCurrentSprite
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	adds r1, r0, #0
_0802F07C:
	ldr r0, _0802F084 @ =0x0858DC1C
	b _0802F08C
	.align 2, 0
_0802F080: .4byte gCurrentSprite
_0802F084: .4byte 0x0858DC1C
_0802F088:
	ldr r1, _0802F094 @ =gCurrentSprite
	ldr r0, _0802F098 @ =0x0858DBDC
_0802F08C:
	str r0, [r1, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_0802F094: .4byte gCurrentSprite
_0802F098: .4byte 0x0858DBDC

	thumb_func_start CoreXWideBeam
CoreXWideBeam: @ 0x0802F09C
	push {r4, lr}
	ldr r1, _0802F0DC @ =gCurrentSprite
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	beq _0802F0B4
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #8
	bhi _0802F0B4
	bl SpriteUtilMoveEyeCoreXBeamPart
_0802F0B4:
	ldr r1, _0802F0E0 @ =gCurrentClipdataAffectingAction
	movs r0, #6
	strb r0, [r1]
	ldr r4, _0802F0DC @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0802F0E4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F0E8
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #5
	bl ParticleSet
	movs r0, #0
	strh r0, [r4]
	b _0802F118
	.align 2, 0
_0802F0DC: .4byte gCurrentSprite
_0802F0E0: .4byte gCurrentClipdataAffectingAction
_0802F0E4: .4byte gPreviousCollisionCheck
_0802F0E8:
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802F0FE
	cmp r0, #1
	beq _0802F104
	cmp r0, #8
	bhi _0802F112
	adds r0, #1
	strb r0, [r4]
	b _0802F112
_0802F0FE:
	bl CoreXWideBeamInit
	b _0802F10A
_0802F104:
	movs r0, #0x10
	bl SpriteUtilMoveEyeCoreXBeam
_0802F10A:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0802F118
_0802F112:
	movs r0, #0x18
	bl SpriteUtilMoveEyeCoreXBeam
_0802F118:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CoreXPlasmaBeaminit
CoreXPlasmaBeaminit: @ 0x0802F120
	push {lr}
	movs r0, #0xcb
	bl SoundPlay
	ldr r2, _0802F174 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x25
	movs r1, #0
	movs r0, #2
	strb r0, [r3]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802F178 @ =0x0000FFF4
	strh r1, [r2, #0xa]
	movs r0, #0xc
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldrh r1, [r2]
	ldr r0, _0802F17C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _0802F1E0
	lsls r0, r0, #2
	ldr r1, _0802F180 @ =_0802F184
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	mov pc, r0
	.align 2, 0
_0802F174: .4byte gCurrentSprite
_0802F178: .4byte 0x0000FFF4
_0802F17C: .4byte 0x0000FFFB
_0802F180: .4byte _0802F184
_0802F184: @ jump table
	.4byte _0802F1E0 @ case 0
	.4byte _0802F1B4 @ case 1
	.4byte _0802F198 @ case 2
	.4byte _0802F1D4 @ case 3
	.4byte _0802F1C4 @ case 4
_0802F198:
	ldr r1, _0802F1AC @ =gCurrentSprite
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _0802F1B0 @ =0x0858DE0C
	b _0802F1E4
	.align 2, 0
_0802F1AC: .4byte gCurrentSprite
_0802F1B0: .4byte 0x0858DE0C
_0802F1B4:
	ldr r1, _0802F1BC @ =gCurrentSprite
	ldr r0, _0802F1C0 @ =0x0858DE0C
	b _0802F1E4
	.align 2, 0
_0802F1BC: .4byte gCurrentSprite
_0802F1C0: .4byte 0x0858DE0C
_0802F1C4:
	ldr r0, _0802F1D8 @ =gCurrentSprite
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	adds r1, r0, #0
_0802F1D4:
	ldr r0, _0802F1DC @ =0x0858DE24
	b _0802F1E4
	.align 2, 0
_0802F1D8: .4byte gCurrentSprite
_0802F1DC: .4byte 0x0858DE24
_0802F1E0:
	ldr r1, _0802F1EC @ =gCurrentSprite
	ldr r0, _0802F1F0 @ =0x0858DDF4
_0802F1E4:
	str r0, [r1, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_0802F1EC: .4byte gCurrentSprite
_0802F1F0: .4byte 0x0858DDF4

	thumb_func_start CoreXPlasmaBeam
CoreXPlasmaBeam: @ 0x0802F1F4
	push {r4, lr}
	ldr r1, _0802F234 @ =gCurrentSprite
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	beq _0802F20C
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #8
	bhi _0802F20C
	bl SpriteUtilMoveEyeCoreXBeamPart
_0802F20C:
	ldr r1, _0802F238 @ =gCurrentClipdataAffectingAction
	movs r0, #6
	strb r0, [r1]
	ldr r4, _0802F234 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0802F23C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F240
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #6
	bl ParticleSet
	movs r0, #0
	strh r0, [r4]
	b _0802F270
	.align 2, 0
_0802F234: .4byte gCurrentSprite
_0802F238: .4byte gCurrentClipdataAffectingAction
_0802F23C: .4byte gPreviousCollisionCheck
_0802F240:
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802F256
	cmp r0, #1
	beq _0802F25C
	cmp r0, #8
	bhi _0802F26A
	adds r0, #1
	strb r0, [r4]
	b _0802F26A
_0802F256:
	bl CoreXPlasmaBeaminit
	b _0802F262
_0802F25C:
	movs r0, #0x10
	bl SpriteUtilMoveEyeCoreXBeam
_0802F262:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0802F270
_0802F26A:
	movs r0, #0x18
	bl SpriteUtilMoveEyeCoreXBeam
_0802F270:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CoreXWaveIceBeamInit
CoreXWaveIceBeamInit: @ 0x0802F278
	push {lr}
	ldr r0, _0802F28C @ =gCurrentSprite
	ldrb r0, [r0, #0x1d]
	cmp r0, #0x74
	bne _0802F290
	movs r0, #0xcd
	bl SoundPlay
	b _0802F296
	.align 2, 0
_0802F28C: .4byte gCurrentSprite
_0802F290:
	movs r0, #0xcc
	bl SoundPlay
_0802F296:
	ldr r0, _0802F304 @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0802F308 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	mov r1, ip
	adds r1, #0x21
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	strb r0, [r1]
	adds r1, #3
	movs r0, #2
	strb r0, [r1]
	mov r1, ip
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _0802F30C @ =0x0000FFF0
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldrh r1, [r2]
	adds r0, #0xb
	ands r0, r1
	strh r0, [r2]
	mov r0, ip
	adds r0, #0x2d
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _0802F388
	lsls r0, r0, #2
	ldr r1, _0802F310 @ =_0802F314
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802F304: .4byte gCurrentSprite
_0802F308: .4byte gIoRegisters
_0802F30C: .4byte 0x0000FFF0
_0802F310: .4byte _0802F314
_0802F314: @ jump table
	.4byte _0802F388 @ case 0
	.4byte _0802F34C @ case 1
	.4byte _0802F328 @ case 2
	.4byte _0802F370 @ case 3
	.4byte _0802F364 @ case 4
_0802F328:
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r1, r0
	strh r1, [r2]
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x74
	bne _0802F344
	ldr r0, _0802F340 @ =0x0858E1E8
	b _0802F39A
	.align 2, 0
_0802F340: .4byte 0x0858E1E8
_0802F344:
	ldr r0, _0802F348 @ =0x0858DF74
	b _0802F39A
	.align 2, 0
_0802F348: .4byte 0x0858DF74
_0802F34C:
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x74
	bne _0802F35C
	ldr r0, _0802F358 @ =0x0858E1E8
	b _0802F39A
	.align 2, 0
_0802F358: .4byte 0x0858E1E8
_0802F35C:
	ldr r0, _0802F360 @ =0x0858DF74
	b _0802F39A
	.align 2, 0
_0802F360: .4byte 0x0858DF74
_0802F364:
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
_0802F370:
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x74
	bne _0802F380
	ldr r0, _0802F37C @ =0x0858E1F8
	b _0802F39A
	.align 2, 0
_0802F37C: .4byte 0x0858E1F8
_0802F380:
	ldr r0, _0802F384 @ =0x0858DF84
	b _0802F39A
	.align 2, 0
_0802F384: .4byte 0x0858DF84
_0802F388:
	ldrb r0, [r2, #0x1d]
	cmp r0, #0x74
	bne _0802F398
	ldr r0, _0802F394 @ =0x0858E1D8
	b _0802F39A
	.align 2, 0
_0802F394: .4byte 0x0858E1D8
_0802F398:
	ldr r0, _0802F3A0 @ =0x0858DF64
_0802F39A:
	str r0, [r2, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_0802F3A0: .4byte 0x0858DF64

	thumb_func_start CoreXWaveIceBeam
CoreXWaveIceBeam: @ 0x0802F3A4
	push {r4, lr}
	ldr r4, _0802F3D4 @ =gCurrentSprite
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _0802F3B2
	bl SpriteUtilMoveEyeCoreXWaveBeamPart
_0802F3B2:
	ldr r1, _0802F3D8 @ =gCurrentClipdataAffectingAction
	movs r0, #6
	strb r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #0
	beq _0802F3DC
	cmp r0, #1
	beq _0802F3E2
	movs r0, #0x18
	bl SpriteUtilMoveEyeCoreXBeam
	b _0802F3EE
	.align 2, 0
_0802F3D4: .4byte gCurrentSprite
_0802F3D8: .4byte gCurrentClipdataAffectingAction
_0802F3DC:
	bl CoreXWaveIceBeamInit
	b _0802F3E8
_0802F3E2:
	movs r0, #0x10
	bl SpriteUtilMoveEyeCoreXBeam
_0802F3E8:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0802F3EE:
	ldr r1, _0802F400 @ =gCurrentSprite
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F400: .4byte gCurrentSprite

	thumb_func_start ToxicGasInit
ToxicGasInit: @ 0x0802F404
	push {r4, lr}
	ldr r3, _0802F484 @ =gCurrentSprite
	ldr r2, _0802F488 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	movs r1, #0
	strh r0, [r3, #0x14]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	ldr r0, _0802F48C @ =0x08336828
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x27
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x28
	movs r1, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802F490 @ =0x0000FFD0
	strh r1, [r3, #0xa]
	movs r0, #0xb0
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldrh r0, [r3]
	movs r4, #0x81
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0802F494 @ =0x000001FF
	strh r0, [r3, #0x12]
	adds r0, r3, #0
	adds r0, #0x2e
	strb r2, [r0]
	adds r1, r3, #0
	adds r1, #0x21
	movs r0, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F484: .4byte gCurrentSprite
_0802F488: .4byte sPrimarySpriteStats
_0802F48C: .4byte 0x08336828
_0802F490: .4byte 0x0000FFD0
_0802F494: .4byte 0x000001FF

	thumb_func_start ToxicGasIdle
ToxicGasIdle: @ 0x0802F498
	push {r4, lr}
	sub sp, #0xc
	ldr r2, _0802F4C8 @ =gCurrentSprite
	ldrh r0, [r2]
	movs r1, #4
	eors r0, r1
	strh r0, [r2]
	adds r4, r2, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	adds r3, r2, #0
	cmp r0, #0
	beq _0802F4CC
	ldrh r0, [r3, #0x12]
	adds r0, #2
	strh r0, [r3, #0x12]
	lsls r0, r0, #0x10
	movs r1, #0xff
	lsls r1, r1, #0x11
	cmp r0, r1
	bls _0802F4E0
	ldrb r0, [r4]
	subs r0, #1
	b _0802F4DE
	.align 2, 0
_0802F4C8: .4byte gCurrentSprite
_0802F4CC:
	ldrh r0, [r3, #0x12]
	subs r0, #2
	strh r0, [r3, #0x12]
	lsls r0, r0, #0x10
	ldr r1, _0802F524 @ =0x01CB0000
	cmp r0, r1
	bhi _0802F4E0
	ldrb r0, [r4]
	adds r0, #1
_0802F4DE:
	strb r0, [r4]
_0802F4E0:
	adds r0, r3, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #1
	bne _0802F51C
	ldrh r4, [r3, #2]
	adds r4, #0x40
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r0, [r3, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #0x1e]
	ldrb r2, [r3, #0x1f]
	adds r3, #0x23
	ldrb r3, [r3]
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x2a
	bl SpriteSpawnSecondary
	movs r0, #0xad
	lsls r0, r0, #1
	bl SoundPlay
_0802F51C:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F524: .4byte 0x01CB0000

	thumb_func_start ToxicGas
ToxicGas: @ 0x0802F528
	push {lr}
	ldr r0, _0802F548 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802F540
	bl ToxicGasInit
_0802F540:
	bl ToxicGasIdle
	pop {r0}
	bx r0
	.align 2, 0
_0802F548: .4byte gCurrentSprite

	thumb_func_start ToxicGasExplosion
ToxicGasExplosion: @ 0x0802F54C
	push {r4, r5, r6, lr}
	ldr r3, _0802F5C8 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r4, [r0]
	adds r6, r3, #0
	adds r6, #0x24
	ldrb r5, [r6]
	cmp r5, #0
	bne _0802F5DC
	ldrh r1, [r3]
	ldr r0, _0802F5CC @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r3]
	adds r2, r3, #0
	adds r2, #0x21
	movs r0, #1
	strb r0, [r2]
	adds r2, #1
	movs r0, #3
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	movs r2, #2
	strb r2, [r0]
	ldr r0, _0802F5D0 @ =0x083367D0
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r5, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x27
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0802F5D4 @ =0x0000FF80
	strh r1, [r3, #0xa]
	movs r0, #0x80
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	strb r2, [r6]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _0802F5D8 @ =gSpriteData
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0]
	b _0802F612
	.align 2, 0
_0802F5C8: .4byte gCurrentSprite
_0802F5CC: .4byte 0x0000FFFB
_0802F5D0: .4byte 0x083367D0
_0802F5D4: .4byte 0x0000FF80
_0802F5D8: .4byte gSpriteData
_0802F5DC:
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802F5EA
	subs r0, #1
	b _0802F5F0
_0802F5EA:
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
_0802F5F0:
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802F612
	ldr r1, _0802F618 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0802F61C @ =gSpriteData
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, _0802F620 @ =0x00007FFF
	ands r0, r2
	strh r0, [r1]
_0802F612:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802F618: .4byte gCurrentSprite
_0802F61C: .4byte gSpriteData
_0802F620: .4byte 0x00007FFF

	thumb_func_start KagoSetCollision
KagoSetCollision: @ 0x0802F624
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _0802F678 @ =gCurrentSprite
	ldrh r1, [r0, #2]
	ldrh r5, [r0, #4]
	adds r6, r1, #0
	subs r6, #0x60
	adds r1, r5, #0
	adds r1, #0x60
	adds r0, r6, #0
	bl SpriteUtilCheckCollisionAtPosition
	ldr r4, _0802F67C @ =gPreviousCollisionCheck
	ldrb r0, [r4]
	cmp r0, #0x11
	bne _0802F670
	adds r1, r5, #0
	subs r1, #0x60
	adds r0, r6, #0
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r4]
	cmp r0, #0x11
	bne _0802F670
	ldr r4, _0802F680 @ =gCurrentClipdataAffectingAction
	strb r7, [r4]
	adds r1, r5, #0
	adds r1, #0x20
	adds r0, r6, #0
	bl ClipdataProcess
	strb r7, [r4]
	adds r1, r5, #0
	subs r1, #0x20
	adds r0, r6, #0
	bl ClipdataProcess
_0802F670:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F678: .4byte gCurrentSprite
_0802F67C: .4byte gPreviousCollisionCheck
_0802F680: .4byte gCurrentClipdataAffectingAction

	thumb_func_start KagoPlaySound
KagoPlaySound: @ 0x0802F684
	push {r4, lr}
	ldr r4, _0802F6A4 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802F6AC
	ldr r0, _0802F6A8 @ =0x0000016B
	bl SoundPlayNotAlreadyPlaying
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0x28
	b _0802F714
	.align 2, 0
_0802F6A4: .4byte gCurrentSprite
_0802F6A8: .4byte 0x0000016B
_0802F6AC:
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #4
	bne _0802F6C8
	ldr r0, _0802F6C4 @ =0x0000016D
	bl SoundPlayNotAlreadyPlaying
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0x48
	b _0802F714
	.align 2, 0
_0802F6C4: .4byte 0x0000016D
_0802F6C8:
	cmp r0, #3
	bne _0802F6DC
	movs r0, #0xb7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0x38
	b _0802F714
_0802F6DC:
	cmp r0, #2
	bne _0802F6F4
	ldr r0, _0802F6F0 @ =0x0000016F
	bl SoundPlayNotAlreadyPlaying
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0x1e
	b _0802F714
	.align 2, 0
_0802F6F0: .4byte 0x0000016F
_0802F6F4:
	cmp r0, #1
	bne _0802F708
	movs r0, #0xb8
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0x12
	b _0802F714
_0802F708:
	ldr r0, _0802F71C @ =0x00000171
	bl SoundPlayNotAlreadyPlaying
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0xc
_0802F714:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F71C: .4byte 0x00000171

	thumb_func_start KagoTurningIntoX
KagoTurningIntoX: @ 0x0802F720
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _0802F760 @ =gCurrentSprite
	ldrb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	adds r0, #0x5c
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	subs r0, #0xc
	str r0, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r4, #2]
	subs r0, #0x1c
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	adds r0, #0xc
	strh r0, [r4, #4]
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F760: .4byte gCurrentSprite

	thumb_func_start KagoInit
KagoInit: @ 0x0802F764
	push {r4, r5, r6, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0802F798 @ =gCurrentSprite
	adds r4, r2, #0
	adds r4, #0x34
	ldrb r3, [r4]
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _0802F7A0
	movs r0, #8
	movs r1, #0
	orrs r0, r3
	strb r0, [r4]
	adds r3, r2, #0
	adds r3, #0x25
	movs r0, #1
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x28
	strb r1, [r0]
	movs r0, #0x10
	strh r0, [r2, #0xc]
	ldr r0, _0802F79C @ =0x08337B24
	b _0802F7C0
	.align 2, 0
_0802F798: .4byte gCurrentSprite
_0802F79C: .4byte 0x08337B24
_0802F7A0:
	movs r0, #0xf7
	ands r0, r3
	strb r0, [r4]
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0xd
	strb r0, [r1]
	adds r1, #0x10
	movs r0, #1
	strb r0, [r1]
	subs r1, #0xd
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #0xc0
	strh r0, [r2, #0xc]
	ldr r0, _0802F830 @ =0x08337B4C
_0802F7C0:
	str r0, [r2, #0x18]
	ldr r6, _0802F834 @ =gCurrentSprite
	ldr r2, _0802F838 @ =sPrimarySpriteStats
	ldrb r1, [r6, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r4, #0
	movs r5, #0
	strh r0, [r6, #0x14]
	adds r1, r6, #0
	adds r1, #0x2e
	movs r0, #4
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x30
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	bl KagoPlaySound
	adds r1, r6, #0
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	strb r4, [r6, #0x1c]
	strh r5, [r6, #0x16]
	adds r1, #5
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0802F83C @ =0x0000FF88
	strh r0, [r6, #0xa]
	adds r0, #0x48
	strh r0, [r6, #0xe]
	movs r0, #0x30
	strh r0, [r6, #0x10]
	adds r2, r6, #0
	adds r2, #0x24
	ldrb r0, [r2]
	cmp r0, #0x59
	bne _0802F840
	movs r0, #0x5a
	strb r0, [r2]
	movs r0, #0x2c
	strh r0, [r6, #6]
	movs r0, #0xb6
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0802F864
	.align 2, 0
_0802F830: .4byte 0x08337B4C
_0802F834: .4byte gCurrentSprite
_0802F838: .4byte sPrimarySpriteStats
_0802F83C: .4byte 0x0000FF88
_0802F840:
	ldrh r0, [r6, #4]
	adds r0, #0x20
	strh r0, [r6, #4]
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0802F85A
	strb r3, [r2]
	b _0802F864
_0802F85A:
	movs r0, #0x18
	strb r0, [r2]
	ldrh r0, [r6, #2]
	subs r0, #0xc0
	strh r0, [r6, #2]
_0802F864:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KagoSpawningFromX
KagoSpawningFromX: @ 0x0802F86C
	push {r4, lr}
	ldr r4, _0802F8A4 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #6]
	subs r3, r0, #1
	strh r3, [r4, #6]
	lsls r0, r3, #0x10
	cmp r0, #0
	beq _0802F8B0
	ldr r2, _0802F8A8 @ =gWrittenToMosaic_H
	ldr r1, _0802F8AC @ =sXParasiteMosaicValues
	ldrh r0, [r4, #6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bhi _0802F8C4
	ldrh r0, [r4, #2]
	subs r0, #8
	strh r0, [r4, #2]
	b _0802F8C4
	.align 2, 0
_0802F8A4: .4byte gCurrentSprite
_0802F8A8: .4byte gWrittenToMosaic_H
_0802F8AC: .4byte sXParasiteMosaicValues
_0802F8B0:
	ldrh r1, [r4]
	ldr r0, _0802F8CC @ =0x00007FFF
	ands r0, r1
	ldr r1, _0802F8D0 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
_0802F8C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F8CC: .4byte 0x00007FFF
_0802F8D0: .4byte 0x0000FFDF

	thumb_func_start KagoIdleShort
KagoIdleShort: @ 0x0802F8D4
	push {lr}
	ldr r1, _0802F8F0 @ =gCurrentSprite
	adds r1, #0x2f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F8EA
	bl KagoPlaySound
_0802F8EA:
	pop {r0}
	bx r0
	.align 2, 0
_0802F8F0: .4byte gCurrentSprite

	thumb_func_start KagoIdleTall
KagoIdleTall: @ 0x0802F8F4
	push {lr}
	ldr r1, _0802F910 @ =gCurrentSprite
	adds r1, #0x2f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802F90A
	bl KagoPlaySound
_0802F90A:
	pop {r0}
	bx r0
	.align 2, 0
_0802F910: .4byte gCurrentSprite

	thumb_func_start KagoDyingInit
KagoDyingInit: @ 0x0802F914
	push {r4, lr}
	ldr r4, _0802F950 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F928
	movs r0, #1
	bl KagoSetCollision
_0802F928:
	ldrh r1, [r4]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x58
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x2c
	strb r0, [r1]
	movs r0, #0xa1
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	bl SpriteDying
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F950: .4byte gCurrentSprite

	thumb_func_start KagoInsectExplodingInit
KagoInsectExplodingInit: @ 0x0802F954
	push {lr}
	ldr r0, _0802F97C @ =gCurrentSprite
	ldr r1, _0802F980 @ =0x08337DC4
	str r1, [r0, #0x18]
	movs r1, #0
	strb r1, [r0, #0x1c]
	movs r3, #0
	strh r1, [r0, #0x16]
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x38
	strb r1, [r2]
	adds r0, #0x25
	strb r3, [r0]
	movs r0, #0xb9
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_0802F97C: .4byte gCurrentSprite
_0802F980: .4byte 0x08337DC4

	thumb_func_start KagoInsectExploding
KagoInsectExploding: @ 0x0802F984
	push {r4, lr}
	ldr r4, _0802F9A4 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802F99C
	movs r0, #0
	strh r0, [r4]
_0802F99C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802F9A4: .4byte gCurrentSprite

	thumb_func_start KagoInsectInit
KagoInsectInit: @ 0x0802F9A8
	push {r4, r5, lr}
	ldr r3, _0802FA24 @ =gCurrentSprite
	ldrh r1, [r3]
	ldr r0, _0802FA28 @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r2, #0
	strh r0, [r3]
	ldr r1, _0802FA2C @ =sSecondarySpriteStats
	ldrb r0, [r3, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #4
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x35
	movs r5, #1
	strb r5, [r0]
	ldr r0, _0802FA30 @ =0x08337DA4
	str r0, [r3, #0x18]
	strb r4, [r3, #0x1c]
	strh r2, [r3, #0x16]
	adds r1, #2
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x28
	strb r4, [r0]
	adds r1, #2
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0802FA34 @ =0x0000FFD8
	strh r0, [r3, #0xa]
	adds r0, #0x20
	strh r0, [r3, #0xc]
	subs r0, #0xc
	strh r0, [r3, #0xe]
	movs r0, #0x14
	strh r0, [r3, #0x10]
	subs r1, #5
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802FA38 @ =gFrameCounter8Bit
	ldrb r2, [r0]
	lsls r2, r2, #0x18
	lsrs r0, r2, #0x1a
	adds r0, #5
	adds r1, #0xc
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r4, [r0]
	lsrs r2, r2, #0x18
	cmp r2, #7
	bls _0802FA3C
	subs r0, #2
	strb r5, [r0]
	b _0802FA42
	.align 2, 0
_0802FA24: .4byte gCurrentSprite
_0802FA28: .4byte 0x0000FFFB
_0802FA2C: .4byte sSecondarySpriteStats
_0802FA30: .4byte 0x08337DA4
_0802FA34: .4byte 0x0000FFD8
_0802FA38: .4byte gSpriteRandomNumber
_0802FA3C:
	adds r0, r3, #0
	adds r0, #0x2f
	strb r4, [r0]
_0802FA42:
	bl SpriteUtilChooseRandomXFlip
	ldr r1, _0802FA60 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x14
	strh r0, [r1, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802FA60: .4byte gCurrentSprite

	thumb_func_start KagoInsectJumpWarningInit
KagoInsectJumpWarningInit: @ 0x0802FA64
	ldr r1, _0802FA7C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #2
	strb r0, [r2]
	ldr r0, _0802FA80 @ =0x08337D84
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0802FA7C: .4byte gCurrentSprite
_0802FA80: .4byte 0x08337D84

	thumb_func_start KagoInsectJumpingInit
KagoInsectJumpingInit: @ 0x0802FA84
	push {r4, lr}
	ldr r3, _0802FAC0 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0802FAC4 @ =0x08337DA4
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	movs r4, #0
	strh r2, [r3, #0x16]
	adds r1, #0xc
	movs r0, #5
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r4, [r0]
	ldr r0, _0802FAC8 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0802FACC
	adds r0, r3, #0
	adds r0, #0x2f
	strb r2, [r0]
	b _0802FAD2
	.align 2, 0
_0802FAC0: .4byte gCurrentSprite
_0802FAC4: .4byte 0x08337DA4
_0802FAC8: .4byte gSpriteRandomNumber
_0802FACC:
	adds r0, r3, #0
	adds r0, #0x2f
	strb r4, [r0]
_0802FAD2:
	adds r2, r3, #0
	ldr r1, _0802FAF4 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _0802FAF8
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802FB0C
	adds r1, r2, #0
	adds r1, #0x30
	movs r0, #0
	strb r0, [r1]
	b _0802FB0C
	.align 2, 0
_0802FAF4: .4byte gSamusData
_0802FAF8:
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0802FB0C
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
_0802FB0C:
	ldr r0, _0802FB18 @ =0x00000173
	bl SoundPlayNotAlreadyPlaying
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802FB18: .4byte 0x00000173

	thumb_func_start KagoInsectFallingInit
KagoInsectFallingInit: @ 0x0802FB1C
	ldr r0, _0802FB38 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r3, #0
	movs r1, #0x16
	strb r1, [r2]
	ldr r1, _0802FB3C @ =0x08337DA4
	str r1, [r0, #0x18]
	strb r3, [r0, #0x1c]
	movs r1, #0
	strh r3, [r0, #0x16]
	adds r0, #0x31
	strb r1, [r0]
	bx lr
	.align 2, 0
_0802FB38: .4byte gCurrentSprite
_0802FB3C: .4byte 0x08337DA4

	thumb_func_start KagoInsectJumpWarning
KagoInsectJumpWarning: @ 0x0802FB40
	push {r4, r5, lr}
	ldr r4, _0802FB54 @ =gCurrentSprite
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _0802FB58
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _0802FB98
	.align 2, 0
_0802FB54: .4byte gCurrentSprite
_0802FB58:
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0802FB88 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802FB8C
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802FB8C
	bl KagoInsectFallingInit
	b _0802FB98
	.align 2, 0
_0802FB88: .4byte gPreviousCollisionCheck
_0802FB8C:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0802FB98
	bl KagoInsectJumpingInit
_0802FB98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KagoInsectJumping
KagoInsectJumping: @ 0x0802FBA0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _0802FBB8 @ =gCurrentSprite
	ldrh r1, [r0, #0x14]
	adds r3, r0, #0
	cmp r1, #0
	bne _0802FBBC
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _0802FDBA
	.align 2, 0
_0802FBB8: .4byte gCurrentSprite
_0802FBBC:
	movs r7, #0
	adds r0, r3, #0
	adds r0, #0x30
	ldrb r5, [r0]
	adds r4, r5, #0
	cmp r4, #0
	bne _0802FC10
	adds r0, #1
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _0802FBE8
	ldrh r0, [r3]
	movs r1, #0x40
	eors r0, r1
	movs r1, #0
	strh r0, [r3]
	ldr r0, _0802FBE4 @ =0x08337DB4
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	b _0802FBF2
	.align 2, 0
_0802FBE4: .4byte 0x08337DB4
_0802FBE8:
	cmp r0, #0x16
	bne _0802FBF4
	ldr r0, _0802FC08 @ =0x08337DA4
	str r0, [r3, #0x18]
	strb r7, [r3, #0x1c]
_0802FBF2:
	strh r7, [r3, #0x16]
_0802FBF4:
	ldr r1, _0802FC0C @ =0x08336878
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	b _0802FCD4
	.align 2, 0
_0802FC08: .4byte 0x08337DA4
_0802FC0C: .4byte 0x08336878
_0802FC10:
	ldr r1, _0802FC58 @ =0x08336864
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802FC7E
	ldrh r0, [r3, #2]
	subs r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r3, r2]
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	adds r1, #4
	str r3, [sp]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0802FC5C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	ldr r3, [sp]
	cmp r0, #0x11
	bne _0802FC64
	ldrh r0, [r3, #4]
	subs r0, #4
	movs r2, #0
	strh r0, [r3, #4]
	ldrh r1, [r3]
	ldr r0, _0802FC60 @ =0x0000FFBF
	ands r0, r1
	b _0802FCAA
	.align 2, 0
_0802FC58: .4byte 0x08336864
_0802FC5C: .4byte gPreviousCollisionCheck
_0802FC60: .4byte 0x0000FFBF
_0802FC64:
	lsls r0, r6, #0x10
	cmp r0, #0
	ble _0802FC78
	ldr r1, _0802FC74 @ =0x0000FFFD
	adds r0, r4, r1
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	b _0802FCD2
	.align 2, 0
_0802FC74: .4byte 0x0000FFFD
_0802FC78:
	ldrh r0, [r3, #4]
	adds r0, r0, r5
	b _0802FCD2
_0802FC7E:
	ldrh r0, [r3, #2]
	subs r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r3, r2]
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	subs r1, #4
	str r3, [sp]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0802FCB8 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	ldr r3, [sp]
	cmp r0, #0x11
	bne _0802FCC0
	ldrh r0, [r3, #4]
	adds r0, #4
	movs r2, #0
	strh r0, [r3, #4]
	ldrh r0, [r3]
	movs r1, #0x40
	orrs r0, r1
_0802FCAA:
	strh r0, [r3]
	ldr r0, _0802FCBC @ =0x08337DB4
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r7, [r3, #0x16]
	b _0802FCD4
	.align 2, 0
_0802FCB8: .4byte gPreviousCollisionCheck
_0802FCBC: .4byte 0x08337DB4
_0802FCC0:
	lsls r0, r6, #0x10
	cmp r0, #0
	ble _0802FCCE
	subs r1, r4, #3
	ldrh r0, [r3, #4]
	subs r0, r0, r1
	b _0802FCD2
_0802FCCE:
	ldrh r0, [r3, #4]
	subs r0, r0, r5
_0802FCD2:
	strh r0, [r3, #4]
_0802FCD4:
	adds r4, r3, #0
	ldrh r0, [r4, #2]
	adds r0, r0, r6
	strh r0, [r4, #2]
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, #0x26
	bhi _0802FCEA
	adds r0, #1
	strb r0, [r1]
_0802FCEA:
	lsls r0, r6, #0x10
	cmp r0, #0
	ble _0802FD54
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _0802FD0C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802FD10
	strh r1, [r4, #2]
	bl KagoInsectJumpWarningInit
	b _0802FDBA
	.align 2, 0
_0802FD0C: .4byte gPreviousVerticalCollisionCheck
_0802FD10:
	cmp r7, #0
	bne _0802FDBA
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802FD46
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802FD42
	movs r7, #1
_0802FD42:
	cmp r7, #0
	beq _0802FDBA
_0802FD46:
	ldr r0, _0802FD50 @ =gCurrentSprite
	strh r1, [r0, #2]
	bl KagoInsectJumpWarningInit
	b _0802FDBA
	.align 2, 0
_0802FD50: .4byte gCurrentSprite
_0802FD54:
	movs r7, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	str r3, [sp]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r4, _0802FDA8 @ =gPreviousCollisionCheck
	ldrb r0, [r4]
	ldr r3, [sp]
	cmp r0, #0x11
	beq _0802FD96
	movs r1, #0xa
	ldrsh r0, [r3, r1]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	movs r2, #0xe
	ldrsh r1, [r3, r2]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r4]
	cmp r0, #0x11
	bne _0802FD92
	movs r7, #1
_0802FD92:
	cmp r7, #0
	beq _0802FDBA
_0802FD96:
	ldr r2, _0802FDAC @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0802FDB0
	ldrh r0, [r2, #4]
	subs r0, #4
	b _0802FDB4
	.align 2, 0
_0802FDA8: .4byte gPreviousCollisionCheck
_0802FDAC: .4byte gCurrentSprite
_0802FDB0:
	ldrh r0, [r2, #4]
	adds r0, #4
_0802FDB4:
	strh r0, [r2, #4]
	bl KagoInsectFallingInit
_0802FDBA:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KagoInsectFalling
KagoInsectFalling: @ 0x0802FDC4
	push {r4, r5, r6, r7, lr}
	ldr r4, _0802FDD8 @ =gCurrentSprite
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _0802FDDC
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _0802FE74
	.align 2, 0
_0802FDD8: .4byte gCurrentSprite
_0802FDDC:
	movs r6, #0
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _0802FE2C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802FE22
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0802FE22
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802FE1E
	movs r6, #1
_0802FE1E:
	cmp r6, #0
	beq _0802FE34
_0802FE22:
	ldr r0, _0802FE30 @ =gCurrentSprite
	strh r1, [r0, #2]
	bl KagoInsectJumpWarningInit
	b _0802FE74
	.align 2, 0
_0802FE2C: .4byte gPreviousVerticalCollisionCheck
_0802FE30: .4byte gCurrentSprite
_0802FE34:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _0802FE60 @ =sSpritesFallingSpeedQuickAcceleration
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _0802FE64 @ =0x00007FFF
	cmp r1, r0
	bne _0802FE68
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _0802FE74
	.align 2, 0
_0802FE60: .4byte sSpritesFallingSpeedQuickAcceleration
_0802FE64: .4byte 0x00007FFF
_0802FE68:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_0802FE74:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Kago
Kago: @ 0x0802FE7C
	push {lr}
	ldr r2, _0802FEAC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802FEB4
	ldr r0, _0802FEB0 @ =0x0000FF88
	strh r0, [r2, #0xa]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #1
	bne _0802FEFA
	movs r0, #0xb5
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0802FEFA
	.align 2, 0
_0802FEAC: .4byte gCurrentSprite
_0802FEB0: .4byte 0x0000FF88
_0802FEB4:
	ldr r0, _0802FED4 @ =0x0000FF78
	strh r0, [r2, #0xa]
	adds r3, r2, #0
	adds r3, #0x31
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802FEDC
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802FEFA
	ldr r0, _0802FED8 @ =0x08337B4C
	str r0, [r2, #0x18]
	b _0802FEFA
	.align 2, 0
_0802FED4: .4byte 0x0000FF78
_0802FED8: .4byte 0x08337B4C
_0802FEDC:
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #1
	bne _0802FEFA
	ldr r1, [r2, #0x18]
	ldr r0, _0802FF58 @ =0x08337B4C
	cmp r1, r0
	bne _0802FEFA
	ldr r0, _0802FF5C @ =0x08337CA4
	str r0, [r2, #0x18]
	movs r0, #0x3c
	strb r0, [r3]
_0802FEFA:
	ldr r1, _0802FF60 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802FF68
	ldr r0, _0802FF64 @ =0x0000FF88
	strh r0, [r1, #0xa]
	adds r2, r1, #0
	adds r2, #0x30
	ldrb r0, [r2]
	cmp r0, #0
	bne _0802FF28
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _0802FF28
	movs r0, #1
	strb r0, [r2]
	movs r0, #2
	bl KagoSetCollision
_0802FF28:
	bl SpriteUtilUpdateFreezeTimer
	ldr r1, _0802FF60 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r2, [r0]
	cmp r2, #0
	bne _0802FFE6
	adds r3, r1, #0
	adds r3, #0x30
	ldrb r0, [r3]
	cmp r0, #0
	beq _0802FFE6
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _0802FFE6
	strb r2, [r3]
	movs r0, #1
	bl KagoSetCollision
	b _0802FFE6
	.align 2, 0
_0802FF58: .4byte 0x08337B4C
_0802FF5C: .4byte 0x08337CA4
_0802FF60: .4byte gCurrentSprite
_0802FF64: .4byte 0x0000FF88
_0802FF68:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x57
	beq _0802FFAE
	cmp r0, #0x57
	bgt _0802FF8A
	cmp r0, #2
	beq _0802FFA2
	cmp r0, #2
	bgt _0802FF84
	cmp r0, #0
	beq _0802FF9C
	b _0802FFCC
_0802FF84:
	cmp r0, #0x18
	beq _0802FFA8
	b _0802FFCC
_0802FF8A:
	cmp r0, #0x59
	beq _0802FFBA
	cmp r0, #0x59
	blt _0802FFB4
	cmp r0, #0x5a
	beq _0802FFBE
	cmp r0, #0x5b
	beq _0802FFC4
	b _0802FFCC
_0802FF9C:
	bl KagoInit
	b _0802FFCC
_0802FFA2:
	bl KagoIdleShort
	b _0802FFCC
_0802FFA8:
	bl KagoIdleTall
	b _0802FFCC
_0802FFAE:
	bl KagoDyingInit
	b _0802FFCC
_0802FFB4:
	bl SpriteDying
	b _0802FFCC
_0802FFBA:
	bl KagoInit
_0802FFBE:
	bl KagoSpawningFromX
	b _0802FFCC
_0802FFC4:
	bl KagoTurningIntoX
	bl XParasiteInit
_0802FFCC:
	ldr r2, _0802FFEC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0802FFE6
	ldrh r0, [r2, #2]
	subs r0, #0x1e
	ldrh r1, [r2, #4]
	bl unk_120ac
_0802FFE6:
	pop {r0}
	bx r0
	.align 2, 0
_0802FFEC: .4byte gCurrentSprite

	thumb_func_start KagoInsect
KagoInsect: @ 0x0802FFF0
	push {lr}
	ldr r0, _08030008 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x38
	bls _0802FFFE
	b _08030114
_0802FFFE:
	lsls r0, r0, #2
	ldr r1, _0803000C @ =_08030010
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030008: .4byte gCurrentSprite
_0803000C: .4byte _08030010
_08030010: @ jump table
	.4byte _080300F4 @ case 0
	.4byte _08030114 @ case 1
	.4byte _080300FA @ case 2
	.4byte _08030114 @ case 3
	.4byte _08030114 @ case 4
	.4byte _08030114 @ case 5
	.4byte _08030114 @ case 6
	.4byte _08030114 @ case 7
	.4byte _08030114 @ case 8
	.4byte _08030114 @ case 9
	.4byte _08030114 @ case 10
	.4byte _08030114 @ case 11
	.4byte _08030114 @ case 12
	.4byte _08030114 @ case 13
	.4byte _08030114 @ case 14
	.4byte _08030114 @ case 15
	.4byte _08030114 @ case 16
	.4byte _08030114 @ case 17
	.4byte _08030114 @ case 18
	.4byte _08030114 @ case 19
	.4byte _08030114 @ case 20
	.4byte _08030114 @ case 21
	.4byte _08030106 @ case 22
	.4byte _08030114 @ case 23
	.4byte _08030100 @ case 24
	.4byte _08030114 @ case 25
	.4byte _08030114 @ case 26
	.4byte _08030114 @ case 27
	.4byte _08030114 @ case 28
	.4byte _08030114 @ case 29
	.4byte _08030114 @ case 30
	.4byte _08030114 @ case 31
	.4byte _08030114 @ case 32
	.4byte _08030114 @ case 33
	.4byte _08030114 @ case 34
	.4byte _08030114 @ case 35
	.4byte _08030114 @ case 36
	.4byte _08030114 @ case 37
	.4byte _08030114 @ case 38
	.4byte _08030114 @ case 39
	.4byte _08030114 @ case 40
	.4byte _08030114 @ case 41
	.4byte _08030114 @ case 42
	.4byte _08030114 @ case 43
	.4byte _08030114 @ case 44
	.4byte _08030114 @ case 45
	.4byte _08030114 @ case 46
	.4byte _08030114 @ case 47
	.4byte _08030114 @ case 48
	.4byte _08030114 @ case 49
	.4byte _08030114 @ case 50
	.4byte _08030114 @ case 51
	.4byte _08030114 @ case 52
	.4byte _08030114 @ case 53
	.4byte _08030114 @ case 54
	.4byte _0803010C @ case 55
	.4byte _08030110 @ case 56
_080300F4:
	bl KagoInsectInit
	b _08030114
_080300FA:
	bl KagoInsectJumpWarning
	b _08030114
_08030100:
	bl KagoInsectJumping
	b _08030114
_08030106:
	bl KagoInsectFalling
	b _08030114
_0803010C:
	bl KagoInsectExplodingInit
_08030110:
	bl KagoInsectExploding
_08030114:
	ldr r1, _0803013C @ =gCurrentSprite
	ldrh r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08030138
	ldrh r0, [r1, #6]
	cmp r0, #0
	beq _08030138
	subs r0, #1
	strh r0, [r1, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08030138
	ldr r0, _08030140 @ =0x00007FFF
	ands r0, r2
	strh r0, [r1]
_08030138:
	pop {r0}
	bx r0
	.align 2, 0
_0803013C: .4byte gCurrentSprite
_08030140: .4byte 0x00007FFF

	thumb_func_start ShakeTriggerStartScreenShake
ShakeTriggerStartScreenShake: @ 0x08030144
	push {lr}
	movs r2, #0
	ldr r1, _08030164 @ =gCurrentSprite
	ldrb r0, [r1, #0x1c]
	cmp r0, #2
	bne _08030226
	movs r2, #1
	ldrh r0, [r1, #0x16]
	subs r0, #2
	cmp r0, #0x2d
	bhi _08030224
	lsls r0, r0, #2
	ldr r1, _08030168 @ =_0803016C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08030164: .4byte gCurrentSprite
_08030168: .4byte _0803016C
_0803016C: @ jump table
	.4byte _08030226 @ case 0
	.4byte _08030224 @ case 1
	.4byte _08030224 @ case 2
	.4byte _08030226 @ case 3
	.4byte _08030224 @ case 4
	.4byte _08030224 @ case 5
	.4byte _08030226 @ case 6
	.4byte _08030224 @ case 7
	.4byte _08030224 @ case 8
	.4byte _08030226 @ case 9
	.4byte _08030224 @ case 10
	.4byte _08030224 @ case 11
	.4byte _08030226 @ case 12
	.4byte _08030224 @ case 13
	.4byte _08030224 @ case 14
	.4byte _08030226 @ case 15
	.4byte _08030224 @ case 16
	.4byte _08030224 @ case 17
	.4byte _08030226 @ case 18
	.4byte _08030224 @ case 19
	.4byte _08030224 @ case 20
	.4byte _08030226 @ case 21
	.4byte _08030224 @ case 22
	.4byte _08030224 @ case 23
	.4byte _08030226 @ case 24
	.4byte _08030224 @ case 25
	.4byte _08030224 @ case 26
	.4byte _08030226 @ case 27
	.4byte _08030224 @ case 28
	.4byte _08030224 @ case 29
	.4byte _08030226 @ case 30
	.4byte _08030224 @ case 31
	.4byte _08030224 @ case 32
	.4byte _08030226 @ case 33
	.4byte _08030224 @ case 34
	.4byte _08030224 @ case 35
	.4byte _08030226 @ case 36
	.4byte _08030224 @ case 37
	.4byte _08030224 @ case 38
	.4byte _08030226 @ case 39
	.4byte _08030224 @ case 40
	.4byte _08030224 @ case 41
	.4byte _08030226 @ case 42
	.4byte _08030224 @ case 43
	.4byte _08030224 @ case 44
	.4byte _08030226 @ case 45
_08030224:
	movs r2, #0
_08030226:
	cmp r2, #0
	beq _0803023A
	movs r0, #0x14
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	movs r0, #0x14
	movs r1, #0x81
	bl ScreenShakeStartVertical
_0803023A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PreBoxCeilingDebrisCheckSamusInRange
PreBoxCeilingDebrisCheckSamusInRange: @ 0x08030240
	push {r4, r5, r6, lr}
	ldr r3, _08030274 @ =gSamusData
	ldrh r2, [r3, #0x18]
	subs r2, #4
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldrh r3, [r3, #0x16]
	ldr r2, _08030278 @ =gCurrentSprite
	ldrh r4, [r2, #2]
	ldrh r2, [r2, #4]
	lsls r0, r0, #0x16
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x16
	lsrs r0, r1, #0x10
	cmp r2, r3
	bhs _0803027C
	adds r0, r2, r0
	cmp r3, r0
	bge _0803027C
	cmp r4, r6
	bhs _0803027C
	adds r0, r4, r5
	cmp r6, r0
	bge _0803027C
	movs r0, #1
	b _0803027E
	.align 2, 0
_08030274: .4byte gSamusData
_08030278: .4byte gCurrentSprite
_0803027C:
	movs r0, #0
_0803027E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start ShakeTrigger
ShakeTrigger: @ 0x08030284
	push {r4, r5, lr}
	ldr r1, _080302AC @ =gCurrentSprite
	ldrb r4, [r1, #0x1e]
	adds r2, r1, #0
	adds r2, #0x26
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x1c
	bls _080302A0
	b _08030560
_080302A0:
	lsls r0, r0, #2
	ldr r1, _080302B0 @ =_080302B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080302AC: .4byte gCurrentSprite
_080302B0: .4byte _080302B4
_080302B4: @ jump table
	.4byte _08030328 @ case 0
	.4byte _08030560 @ case 1
	.4byte _080303CC @ case 2
	.4byte _08030560 @ case 3
	.4byte _08030560 @ case 4
	.4byte _08030560 @ case 5
	.4byte _08030560 @ case 6
	.4byte _08030560 @ case 7
	.4byte _08030560 @ case 8
	.4byte _08030560 @ case 9
	.4byte _08030560 @ case 10
	.4byte _08030560 @ case 11
	.4byte _08030560 @ case 12
	.4byte _08030560 @ case 13
	.4byte _08030560 @ case 14
	.4byte _08030560 @ case 15
	.4byte _08030560 @ case 16
	.4byte _08030560 @ case 17
	.4byte _08030560 @ case 18
	.4byte _08030560 @ case 19
	.4byte _08030560 @ case 20
	.4byte _08030560 @ case 21
	.4byte _08030560 @ case 22
	.4byte _08030560 @ case 23
	.4byte _080304C8 @ case 24
	.4byte _08030560 @ case 25
	.4byte _08030520 @ case 26
	.4byte _08030560 @ case 27
	.4byte _0803055C @ case 28
_08030328:
	bl EventCheckOn_EnteredSuperMissileDataRoom
	cmp r0, #0
	beq _08030334
	movs r4, #0
	b _0803036E
_08030334:
	bl EventCheckOn_BombsDownloaded
	cmp r0, #0
	beq _08030340
	movs r4, #1
	b _0803036E
_08030340:
	bl EventCheckOn_WaveBeamRecovered
	cmp r0, #0
	beq _0803034C
	movs r4, #2
	b _0803036E
_0803034C:
	bl EventCheckOn_RestrictedLabExplosion
	cmp r0, #0
	beq _08030358
	movs r4, #3
	b _0803036E
_08030358:
	bl EventCheckOn_RestrictedZoneWarning
	adds r1, r0, #0
	cmp r1, #0
	bne _0803036C
	ldr r0, _08030368 @ =gCurrentSprite
	strh r1, [r0]
	b _08030560
	.align 2, 0
_08030368: .4byte gCurrentSprite
_0803036C:
	movs r4, #4
_0803036E:
	ldr r3, _080303BC @ =gCurrentSprite
	movs r2, #0
	strb r4, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x27
	movs r1, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r4, #0
	ldr r1, _080303C0 @ =0x0000FFFC
	strh r1, [r3, #0xa]
	movs r0, #4
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	ldr r0, _080303C4 @ =0x08337E0C
	str r0, [r3, #0x18]
	strb r4, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _080303C8 @ =gDebugFlag
	ldrb r0, [r0]
	cmp r0, #0
	beq _080303B2
	b _08030560
_080303B2:
	ldrh r0, [r3]
	movs r1, #4
	orrs r0, r1
	strh r0, [r3]
	b _08030560
	.align 2, 0
_080303BC: .4byte gCurrentSprite
_080303C0: .4byte 0x0000FFFC
_080303C4: .4byte 0x08337E0C
_080303C8: .4byte gDebugFlag
_080303CC:
	cmp r4, #0
	bne _08030404
	bl EventCheckOn_SuperMissileDownloaded
	cmp r0, #0
	bne _080303DA
	b _08030560
_080303DA:
	ldr r5, _080303FC @ =gCurrentSprite
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x14
	strb r0, [r1]
	movs r0, #0x8b
	lsls r0, r0, #2
	bl SoundPlay_3b1c
	ldr r0, _08030400 @ =0x08337DF4
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
	b _08030560
	.align 2, 0
_080303FC: .4byte gCurrentSprite
_08030400: .4byte 0x08337DF4
_08030404:
	cmp r4, #1
	bne _08030430
	bl EventCheckOn_BombsQuake
	cmp r0, #0
	bne _08030412
	b _08030560
_08030412:
	ldr r3, _08030428 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0803042C @ =0x08337DF4
	b _08030484
	.align 2, 0
_08030428: .4byte gCurrentSprite
_0803042C: .4byte 0x08337DF4
_08030430:
	cmp r4, #4
	bne _0803045C
	bl EventCheckOn_TriggeredBox2Rumble
	cmp r0, #0
	bne _0803043E
	b _08030560
_0803043E:
	ldr r3, _08030454 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #8
	strb r0, [r1]
	ldr r0, _08030458 @ =0x08337DF4
	b _08030484
	.align 2, 0
_08030454: .4byte gCurrentSprite
_08030458: .4byte 0x08337DF4
_0803045C:
	cmp r4, #2
	bne _08030494
	bl EventCheckOn_RestrictedLabExplosion
	cmp r0, #0
	bne _0803046A
	b _08030560
_0803046A:
	ldr r3, _0803048C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x1a
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x14
	strb r0, [r1]
	ldr r0, _08030490 @ =0x08337E1C
_08030484:
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	b _08030560
	.align 2, 0
_0803048C: .4byte gCurrentSprite
_08030490: .4byte 0x08337E1C
_08030494:
	cmp r4, #3
	bne _08030560
	bl EventCheckOn_RestrictedLabExplosion
	cmp r0, #0
	beq _08030560
	ldr r1, _080304BC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _080304C0 @ =0x08337E1C
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	ldr r0, _080304C4 @ =0x00000239
	bl SoundPlay
	b _08030560
	.align 2, 0
_080304BC: .4byte gCurrentSprite
_080304C0: .4byte 0x08337E1C
_080304C4: .4byte 0x00000239
_080304C8:
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08030560
	subs r1, #0xa
	movs r0, #0x4e
	strb r0, [r1]
	movs r0, #0x3c
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	movs r0, #0x3c
	movs r1, #0x81
	bl ScreenShakeStartVertical
	cmp r4, #0
	bne _08030500
	ldr r0, _080304FC @ =0x0000022D
	bl SoundPlay
	b _08030560
	.align 2, 0
_080304FC: .4byte 0x0000022D
_08030500:
	cmp r4, #1
	bne _08030510
	ldr r0, _0803050C @ =0x0000022B
	bl SoundPlay_3b1c
	b _08030560
	.align 2, 0
_0803050C: .4byte 0x0000022B
_08030510:
	cmp r4, #4
	bne _08030560
	ldr r0, _0803051C @ =0x00000237
	bl SoundPlay_3b1c
	b _08030560
	.align 2, 0
_0803051C: .4byte 0x00000237
_08030520:
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _08030530
	subs r0, #1
	strb r0, [r1]
	b _08030560
_08030530:
	adds r1, r2, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803055C
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08030560
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	movs r0, #0x27
	movs r1, #0xa
	bl PlayMusic
	movs r0, #0x8e
	lsls r0, r0, #2
	bl SoundPlay
	b _08030560
_0803055C:
	bl ShakeTriggerStartScreenShake
_08030560:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PreBoxCeilingDebris
PreBoxCeilingDebris: @ 0x08030568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08030590 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x26
	movs r1, #1
	strb r1, [r0]
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #2
	beq _0803060C
	cmp r0, #2
	bgt _08030594
	cmp r0, #0
	beq _0803059E
	b _08030808
	.align 2, 0
_08030590: .4byte gCurrentSprite
_08030594:
	cmp r0, #0x18
	beq _08030644
	cmp r0, #0x1a
	beq _08030668
	b _08030808
_0803059E:
	bl EventCheckOn_SuperMissileDownloaded
	cmp r0, #0
	bne _080305A8
	b _080306B8
_080305A8:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	movs r2, #0
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	strh r0, [r4, #4]
	adds r0, r4, #0
	adds r0, #0x21
	movs r1, #1
	strb r1, [r0]
	adds r0, #4
	strb r2, [r0]
	movs r0, #2
	strb r0, [r5]
	adds r0, r4, #0
	adds r0, #0x27
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #0x70
	strb r0, [r1]
	ldr r1, _08030600 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _08030604 @ =0x08337E0C
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldr r0, _08030608 @ =gDebugFlag
	ldrb r0, [r0]
	cmp r0, #0
	beq _080305F6
	b _08030808
_080305F6:
	ldrh r0, [r4]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4]
	b _08030808
	.align 2, 0
_08030600: .4byte 0x0000FFFC
_08030604: .4byte 0x08337E0C
_08030608: .4byte gDebugFlag
_0803060C:
	movs r0, #6
	movs r1, #6
	bl PreBoxCeilingDebrisCheckSamusInRange
	cmp r0, #0
	bne _0803061A
	b _08030808
_0803061A:
	bl EventCheckOn_BoxRumble
	cmp r0, #0
	bne _08030624
	b _08030808
_08030624:
	movs r0, #0x18
	strb r0, [r5]
	ldr r0, _08030640 @ =0x08337DF4
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	movs r1, #0
	strh r1, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	b _08030808
	.align 2, 0
_08030640: .4byte 0x08337DF4
_08030644:
	adds r2, r4, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r1, r0, #1
	strb r1, [r2]
	movs r3, #0xff
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _08030658
	b _08030808
_08030658:
	movs r0, #0x1a
	strb r0, [r5]
	orrs r1, r3
	strb r1, [r2]
	movs r0, #0xd2
	lsls r0, r0, #1
	strh r0, [r4, #6]
	b _08030808
_08030668:
	movs r0, #0x2e
	adds r0, r0, r4
	mov sb, r0
	ldrb r0, [r0]
	adds r0, #1
	mov r1, sb
	strb r0, [r1]
	ldr r0, _080306C0 @ =gXParasiteTargetXPosition
	ldrb r0, [r0]
	movs r1, #0xf
	mov sl, r1
	ands r1, r0
	mov sl, r1
	ldr r0, _080306C4 @ =gXParasiteTargetYPosition
	ldrb r0, [r0]
	movs r1, #0x1f
	mov r8, r1
	ands r1, r0
	mov r8, r1
	ldr r0, _080306C8 @ =gFrameCounter8Bit
	ldrb r5, [r0]
	cmp r5, #7
	bhi _0803069E
	adds r0, r5, #0
	adds r0, #8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0803069E:
	ldrh r7, [r4, #2]
	ldrh r6, [r4, #4]
	adds r0, r6, #4
	strh r0, [r4, #4]
	adds r0, r7, #0
	adds r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080306CC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080306D0
_080306B8:
	movs r0, #0
	strh r0, [r4]
	b _08030808
	.align 2, 0
_080306C0: .4byte gXParasiteTargetXPosition
_080306C4: .4byte gXParasiteTargetYPosition
_080306C8: .4byte gSpriteRandomNumber
_080306CC: .4byte gPreviousCollisionCheck
_080306D0:
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	beq _080306DE
	b _08030808
_080306DE:
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	ldr r0, _08030718 @ =0x0000022E
	bl SoundPlay_3b1c
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080306F8
	b _08030808
_080306F8:
	adds r0, r5, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803071C
	adds r2, r5, #0
	subs r2, #0x6c
	adds r2, r7, r2
	lsls r3, r5, #5
	adds r3, #0x14
	adds r3, r6, r3
	movs r0, #0
	movs r1, #5
	bl SpriteDebrisInit
	b _08030730
	.align 2, 0
_08030718: .4byte 0x0000022E
_0803071C:
	adds r2, r5, #0
	subs r2, #0x64
	adds r2, r7, r2
	lsls r3, r5, #4
	adds r3, #0x1a
	adds r3, r6, r3
	movs r0, #0
	movs r1, #7
	bl SpriteDebrisInit
_08030730:
	ldr r0, _08030750 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #7
	bls _08030754
	adds r2, r5, #0
	subs r2, #0x50
	adds r2, r7, r2
	lsls r3, r5, #1
	adds r3, #0x12
	subs r3, r6, r3
	movs r0, #0
	movs r1, #8
	bl SpriteDebrisInit
	b _0803077C
	.align 2, 0
_08030750: .4byte gSpriteRandomNumber
_08030754:
	adds r2, r5, #0
	subs r2, #0x5a
	adds r2, r7, r2
	lsls r3, r5, #2
	adds r3, #0x12
	subs r3, r6, r3
	movs r0, #0
	movs r1, #6
	bl SpriteDebrisInit
	mov r2, r8
	subs r2, #0x78
	adds r2, r7, r2
	mov r0, sl
	lsls r3, r0, #3
	subs r3, r6, r3
	movs r0, #0
	movs r1, #5
	bl SpriteDebrisInit
_0803077C:
	ldr r0, _080307A8 @ =gCurrentSprite
	adds r0, #0x2e
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08030808
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _080307AC
	mov r2, r8
	subs r2, #0x78
	adds r2, r7, r2
	mov r1, sl
	lsls r3, r1, #6
	subs r3, r6, r3
	movs r0, #0
	movs r1, #6
	bl SpriteDebrisInit
	b _080307C0
	.align 2, 0
_080307A8: .4byte gCurrentSprite
_080307AC:
	mov r2, r8
	subs r2, #0x50
	adds r2, r7, r2
	mov r0, sl
	lsls r3, r0, #4
	subs r3, r6, r3
	movs r0, #0
	movs r1, #8
	bl SpriteDebrisInit
_080307C0:
	ldr r0, _080307F0 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #0xb
	bls _080307F4
	mov r2, r8
	subs r2, #0x58
	adds r2, r7, r2
	mov r1, sl
	lsls r3, r1, #2
	adds r3, r6, r3
	movs r0, #0
	movs r1, #5
	bl SpriteDebrisInit
	adds r2, r5, #0
	subs r2, #0x64
	adds r2, r7, r2
	lsls r3, r5, #3
	subs r3, r6, r3
	movs r0, #0
	movs r1, #6
	bl SpriteDebrisInit
	b _08030808
	.align 2, 0
_080307F0: .4byte gSpriteRandomNumber
_080307F4:
	mov r2, r8
	subs r2, #0x6e
	adds r2, r7, r2
	mov r0, sl
	lsls r3, r0, #1
	adds r3, r6, r3
	movs r0, #0
	movs r1, #7
	bl SpriteDebrisInit
_08030808:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GateSetCollision
GateSetCollision: @ 0x08030818
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08030860 @ =gCurrentSprite
	ldrh r7, [r0, #2]
	ldrh r6, [r0, #4]
	ldr r5, _08030864 @ =gCurrentClipdataAffectingAction
	strb r4, [r5]
	adds r0, r7, #0
	subs r0, #0x20
	adds r1, r6, #0
	bl ClipdataProcess
	strb r4, [r5]
	adds r0, r7, #0
	subs r0, #0x60
	adds r1, r6, #0
	bl ClipdataProcess
	strb r4, [r5]
	adds r0, r7, #0
	subs r0, #0xa0
	adds r1, r6, #0
	bl ClipdataProcess
	strb r4, [r5]
	adds r0, r7, #0
	subs r0, #0xe0
	adds r1, r6, #0
	bl ClipdataProcess
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030860: .4byte gCurrentSprite
_08030864: .4byte gCurrentClipdataAffectingAction

	thumb_func_start GateInit
GateInit: @ 0x08030868
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r0, _080308D8 @ =gCurrentSprite
	mov ip, r0
	ldr r2, _080308DC @ =sPrimarySpriteStats
	ldrb r1, [r0, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1, #0x14]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	ldrh r0, [r1]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r1, r4, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	adds r1, #0x27
	movs r0, #0x40
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _080308E0 @ =0x0000FFFC
	mov r4, ip
	strh r0, [r4, #0xa]
	strh r3, [r4, #0xc]
	strh r0, [r4, #0xe]
	movs r0, #4
	strh r0, [r4, #0x10]
	subs r1, #5
	movs r0, #2
	strb r0, [r1]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	mov r0, ip
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _080308F8
	cmp r0, #0x12
	bgt _080308E4
	cmp r0, #0x11
	beq _080308EE
	b _08030924
	.align 2, 0
_080308D8: .4byte gCurrentSprite
_080308DC: .4byte sPrimarySpriteStats
_080308E0: .4byte 0x0000FFFC
_080308E4:
	cmp r0, #0x13
	beq _08030904
	cmp r0, #0x14
	beq _08030914
	b _08030924
_080308EE:
	movs r5, #1
	ldr r0, _080308F4 @ =0x08339084
	b _08030908
	.align 2, 0
_080308F4: .4byte 0x08339084
_080308F8:
	movs r5, #2
	ldr r0, _08030900 @ =0x08339084
	b _08030918
	.align 2, 0
_08030900: .4byte 0x08339084
_08030904:
	movs r5, #3
	ldr r0, _08030910 @ =0x083391F4
_08030908:
	mov r1, ip
	str r0, [r1, #0x18]
	b _0803095E
	.align 2, 0
_08030910: .4byte 0x083391F4
_08030914:
	movs r5, #4
	ldr r0, _08030920 @ =0x083391F4
_08030918:
	mov r4, ip
	str r0, [r4, #0x18]
	b _0803095E
	.align 2, 0
_08030920: .4byte 0x083391F4
_08030924:
	movs r5, #5
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _08030948
	ldr r2, _08030940 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldr r0, _08030944 @ =0x08338F84
	str r0, [r2, #0x18]
	b _08030990
	.align 2, 0
_08030940: .4byte gCurrentSprite
_08030944: .4byte 0x08338F84
_08030948:
	ldr r2, _08030998 @ =gCurrentSprite
	ldr r0, _0803099C @ =0x08339084
	str r0, [r2, #0x18]
	adds r3, r2, #0
	adds r3, #0x34
	ldrb r1, [r3]
	movs r0, #1
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0xd2
	strh r0, [r2, #6]
_0803095E:
	movs r0, #2
	bl GateSetCollision
	cmp r5, #4
	bhi _08030990
	ldr r4, _08030998 @ =gCurrentSprite
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r6, #0
	str r6, [sp, #8]
	movs r0, #0xf
	adds r1, r5, #0
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xff
	bne _08030990
	strh r6, [r4]
_08030990:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08030998: .4byte gCurrentSprite
_0803099C: .4byte 0x08339084

	thumb_func_start GateClosed
GateClosed: @ 0x080309A0
	push {r4, lr}
	ldr r4, _080309D4 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0x14
	bgt _080309B2
	cmp r0, #0x11
	bge _080309CE
_080309B2:
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _080309CE
	ldrh r0, [r4, #6]
	subs r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080309CE
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
_080309CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080309D4: .4byte gCurrentSprite

	thumb_func_start GateOpeningInit
GateOpeningInit: @ 0x080309D8
	push {lr}
	movs r0, #1
	bl GateSetCollision
	ldr r3, _08030A0C @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x18
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0x11
	blt _08030A2C
	cmp r0, #0x12
	bgt _08030A14
	ldr r0, _08030A10 @ =0x0833900C
	str r0, [r3, #0x18]
	movs r0, #0x8a
	lsls r0, r0, #1
	bl SoundPlay
	b _08030A3A
	.align 2, 0
_08030A0C: .4byte gCurrentSprite
_08030A10: .4byte 0x0833900C
_08030A14:
	cmp r0, #0x14
	bgt _08030A2C
	ldr r0, _08030A24 @ =0x0833917C
	str r0, [r3, #0x18]
	ldr r0, _08030A28 @ =0x00000115
	bl SoundPlay
	b _08030A3A
	.align 2, 0
_08030A24: .4byte 0x0833917C
_08030A28: .4byte 0x00000115
_08030A2C:
	ldr r0, _08030A40 @ =gCurrentSprite
	ldr r1, _08030A44 @ =0x0833900C
	str r1, [r0, #0x18]
	movs r0, #0x8a
	lsls r0, r0, #1
	bl SoundPlay
_08030A3A:
	pop {r0}
	bx r0
	.align 2, 0
_08030A40: .4byte gCurrentSprite
_08030A44: .4byte 0x0833900C

	thumb_func_start GateOpening
GateOpening: @ 0x08030A48
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08030A84
	ldr r1, _08030A78 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x1a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0x11
	blt _08030A80
	cmp r0, #0x12
	ble _08030A80
	cmp r0, #0x14
	bgt _08030A80
	ldr r0, _08030A7C @ =0x083390F4
	b _08030A82
	.align 2, 0
_08030A78: .4byte gCurrentSprite
_08030A7C: .4byte 0x083390F4
_08030A80:
	ldr r0, _08030A88 @ =0x08338F84
_08030A82:
	str r0, [r1, #0x18]
_08030A84:
	pop {r0}
	bx r0
	.align 2, 0
_08030A88: .4byte 0x08338F84

	thumb_func_start GateSwitchInit
GateSwitchInit: @ 0x08030A8C
	push {r4, lr}
	ldr r0, _08030AF4 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08030AF8 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	adds r1, #0x22
	movs r0, #3
	strb r0, [r1]
	ldr r1, _08030AFC @ =sSecondarySpriteStats
	mov r4, ip
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	mov r1, ip
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	adds r1, #2
	movs r0, #0x40
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x28
	strb r0, [r1]
	movs r0, #0xff
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
	adds r0, #0x40
	strh r0, [r4, #0xc]
	subs r1, #5
	movs r0, #2
	strb r0, [r1]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	ldrb r0, [r4, #0x1e]
	mov r1, ip
	cmp r0, #2
	beq _08030B20
	cmp r0, #2
	bgt _08030B00
	cmp r0, #1
	beq _08030B0A
	b _08030B34
	.align 2, 0
_08030AF4: .4byte gCurrentSprite
_08030AF8: .4byte 0x0000FFFB
_08030AFC: .4byte sSecondarySpriteStats
_08030B00:
	cmp r0, #3
	beq _08030B0A
	cmp r0, #4
	beq _08030B20
	b _08030B34
_08030B0A:
	ldr r0, _08030B18 @ =0x0000FF6C
	strh r0, [r1, #0xe]
	adds r0, #0x20
	strh r0, [r1, #0x10]
	ldr r0, _08030B1C @ =0x0833928C
	str r0, [r1, #0x18]
	b _08030B38
	.align 2, 0
_08030B18: .4byte 0x0000FF6C
_08030B1C: .4byte 0x0833928C
_08030B20:
	movs r0, #0x74
	strh r0, [r1, #0xe]
	movs r0, #0x94
	strh r0, [r1, #0x10]
	ldr r0, _08030B30 @ =0x083392C4
	str r0, [r1, #0x18]
	b _08030B38
	.align 2, 0
_08030B30: .4byte 0x083392C4
_08030B34:
	movs r0, #0
	strh r0, [r1]
_08030B38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GateSwitchIdle
GateSwitchIdle: @ 0x08030B40
	push {lr}
	ldr r0, _08030B70 @ =gCurrentSprite
	ldrh r3, [r0, #0x14]
	adds r2, r0, #0
	cmp r3, #0
	bne _08030B98
	adds r0, #0x24
	movs r1, #0x18
	strb r1, [r0]
	strb r3, [r2, #0x1c]
	movs r0, #0
	strh r3, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x25
	strb r0, [r1]
	ldrb r0, [r2, #0x1e]
	cmp r0, #2
	beq _08030B88
	cmp r0, #2
	bgt _08030B74
	cmp r0, #1
	beq _08030B7E
	b _08030B94
	.align 2, 0
_08030B70: .4byte gCurrentSprite
_08030B74:
	cmp r0, #3
	beq _08030B7E
	cmp r0, #4
	beq _08030B88
	b _08030B94
_08030B7E:
	ldr r0, _08030B84 @ =0x083392AC
	str r0, [r2, #0x18]
	b _08030B98
	.align 2, 0
_08030B84: .4byte 0x083392AC
_08030B88:
	ldr r0, _08030B90 @ =0x083392E4
	str r0, [r2, #0x18]
	b _08030B98
	.align 2, 0
_08030B90: .4byte 0x083392E4
_08030B94:
	movs r0, #0
	strh r0, [r2]
_08030B98:
	pop {r0}
	bx r0

	thumb_func_start GateSwitchPressing
GateSwitchPressing: @ 0x08030B9C
	push {r4, r5, lr}
	ldr r4, _08030BE4 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08030C1E
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	strb r5, [r4, #0x1c]
	strh r5, [r4, #0x16]
	ldr r2, _08030BE8 @ =gSpriteData
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	movs r1, #0x17
	strb r1, [r0]
	ldrb r1, [r4, #0x1e]
	cmp r1, #2
	beq _08030C08
	cmp r1, #2
	bgt _08030BEC
	cmp r1, #1
	beq _08030BF6
	b _08030C18
	.align 2, 0
_08030BE4: .4byte gCurrentSprite
_08030BE8: .4byte gSpriteData
_08030BEC:
	cmp r1, #3
	beq _08030BF6
	cmp r1, #4
	beq _08030C08
	b _08030C18
_08030BF6:
	ldr r1, _08030C00 @ =gCurrentSprite
	ldr r0, _08030C04 @ =0x083392FC
	str r0, [r1, #0x18]
	b _08030C1E
	.align 2, 0
_08030C00: .4byte gCurrentSprite
_08030C04: .4byte 0x083392FC
_08030C08:
	ldr r1, _08030C10 @ =gCurrentSprite
	ldr r0, _08030C14 @ =0x0833930C
	str r0, [r1, #0x18]
	b _08030C1E
	.align 2, 0
_08030C10: .4byte gCurrentSprite
_08030C14: .4byte 0x0833930C
_08030C18:
	ldr r1, _08030C24 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_08030C1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030C24: .4byte gCurrentSprite

	thumb_func_start GateSwitchPressed
GateSwitchPressed: @ 0x08030C28
	ldr r0, _08030C34 @ =gCurrentSprite
	adds r0, #0x26
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08030C34: .4byte gCurrentSprite

	thumb_func_start Gate
Gate: @ 0x08030C38
	push {lr}
	ldr r0, _08030C58 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08030C6C
	cmp r0, #2
	bgt _08030C5C
	cmp r0, #0
	beq _08030C66
	b _08030C7C
	.align 2, 0
_08030C58: .4byte gCurrentSprite
_08030C5C:
	cmp r0, #0x17
	beq _08030C72
	cmp r0, #0x18
	beq _08030C78
	b _08030C7C
_08030C66:
	bl GateInit
	b _08030C7C
_08030C6C:
	bl GateClosed
	b _08030C7C
_08030C72:
	bl GateOpeningInit
	b _08030C7C
_08030C78:
	bl GateOpening
_08030C7C:
	pop {r0}
	bx r0

	thumb_func_start GateSwitch
GateSwitch: @ 0x08030C80
	push {lr}
	ldr r0, _08030C98 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08030CAC
	cmp r0, #2
	bgt _08030C9C
	cmp r0, #0
	beq _08030CA6
	b _08030CBC
	.align 2, 0
_08030C98: .4byte gCurrentSprite
_08030C9C:
	cmp r0, #0x18
	beq _08030CB2
	cmp r0, #0x1a
	beq _08030CB8
	b _08030CBC
_08030CA6:
	bl GateSwitchInit
	b _08030CBC
_08030CAC:
	bl GateSwitchIdle
	b _08030CBC
_08030CB2:
	bl GateSwitchPressing
	b _08030CBC
_08030CB8:
	bl GateSwitchPressed
_08030CBC:
	pop {r0}
	bx r0

	thumb_func_start ElectricWaterDamageInit
ElectricWaterDamageInit: @ 0x08030CC0
	push {r4, lr}
	ldr r0, _08030D14 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	movs r0, #4
	movs r2, #0
	movs r3, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _08030D18 @ =0x0000FF80
	mov r4, ip
	strh r0, [r4, #0xa]
	movs r1, #0x20
	strh r1, [r4, #0xc]
	adds r0, #0x60
	strh r0, [r4, #0xe]
	strh r1, [r4, #0x10]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _08030D1C @ =0x0833AB94
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030D14: .4byte gCurrentSprite
_08030D18: .4byte 0x0000FF80
_08030D1C: .4byte 0x0833AB94

	thumb_func_start ElectricWaterDamageIdle
ElectricWaterDamageIdle: @ 0x08030D20
	push {lr}
	ldr r2, _08030D44 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08030D48 @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030D40
	subs r1, #2
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0
	strb r0, [r1]
_08030D40:
	pop {r0}
	bx r0
	.align 2, 0
_08030D44: .4byte gCurrentSprite
_08030D48: .4byte 0x03001346

	thumb_func_start ElectricWaterDamageDamagingSamus
ElectricWaterDamageDamagingSamus: @ 0x08030D4C
	push {lr}
	ldr r2, _08030D78 @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _08030D7C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08030D80 @ =gSamusData
	ldrh r0, [r1, #0x18]
	strh r0, [r2, #2]
	ldrh r0, [r1, #0x16]
	strh r0, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08030D84
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0xb
	b _08030D8A
	.align 2, 0
_08030D78: .4byte gCurrentSprite
_08030D7C: .4byte 0x0000FFFB
_08030D80: .4byte gSamusData
_08030D84:
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #0
_08030D8A:
	strb r0, [r1]
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08030DB8 @ =0x03001346
	ldrb r3, [r0]
	cmp r3, #0
	bne _08030DB4
	subs r1, #0xa
	movs r0, #0x1a
	strb r0, [r1]
	ldr r0, _08030DBC @ =0x0833AC04
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	movs r1, #0
	strh r3, [r2, #0x16]
	adds r0, r2, #0
	adds r0, #0x25
	strb r1, [r0]
_08030DB4:
	pop {r0}
	bx r0
	.align 2, 0
_08030DB8: .4byte 0x03001346
_08030DBC: .4byte 0x0833AC04

	thumb_func_start ElectricWaterDamageStopping
ElectricWaterDamageStopping: @ 0x08030DC0
	push {r4, r5, lr}
	ldr r4, _08030E08 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08030E0C @ =gSamusData
	ldrh r0, [r1, #0x18]
	movs r5, #0
	strh r0, [r4, #2]
	ldrh r0, [r1, #0x16]
	strh r0, [r4, #4]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08030E00
	ldrh r0, [r4]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _08030E10 @ =0x0833AB94
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x25
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
_08030E00:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030E08: .4byte gCurrentSprite
_08030E0C: .4byte gSamusData
_08030E10: .4byte 0x0833AB94

	thumb_func_start ElectricWireInit
ElectricWireInit: @ 0x08030E14
	push {r4, r5, r6, r7, lr}
	ldr r4, _08030E7C @ =gCurrentSprite
	adds r2, r4, #0
	adds r2, #0x25
	movs r1, #0
	movs r0, #2
	strb r0, [r2]
	adds r2, #2
	movs r0, #8
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x28
	movs r7, #0x30
	strb r7, [r0]
	adds r2, #2
	movs r0, #0x18
	strb r0, [r2]
	movs r5, #0
	ldr r6, _08030E80 @ =0x0000FFD0
	strh r6, [r4, #0xa]
	movs r0, #0x60
	strh r0, [r4, #0xc]
	strb r5, [r4, #0x1c]
	strh r1, [r4, #0x16]
	ldr r0, _08030E84 @ =0x0833AC54
	str r0, [r4, #0x18]
	ldr r0, _08030E88 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x21
	strb r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x80
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08030E8C @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _08030E90
	ldrh r0, [r4]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r4]
	strh r6, [r4, #0xe]
	movs r0, #0x20
	strh r0, [r4, #0x10]
	b _08030E96
	.align 2, 0
_08030E7C: .4byte gCurrentSprite
_08030E80: .4byte 0x0000FFD0
_08030E84: .4byte 0x0833AC54
_08030E88: .4byte gIoRegisters
_08030E8C: .4byte gPreviousCollisionCheck
_08030E90:
	ldr r0, _08030EAC @ =0x0000FFE0
	strh r0, [r4, #0xe]
	strh r7, [r4, #0x10]
_08030E96:
	bl EventCheckAfter_WaterLowered
	cmp r0, #0
	beq _08030EB8
	ldr r0, _08030EB0 @ =0x00000117
	bl SoundPlay
	ldr r0, _08030EB4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x18
	b _08030EBE
	.align 2, 0
_08030EAC: .4byte 0x0000FFE0
_08030EB0: .4byte 0x00000117
_08030EB4: .4byte gCurrentSprite
_08030EB8:
	ldr r0, _08030EC8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
_08030EBE:
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030EC8: .4byte gCurrentSprite

	thumb_func_start ElectricWireIdle
ElectricWireIdle: @ 0x08030ECC
	push {r4, lr}
	ldr r0, _08030EF4 @ =gWaterLowered
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030EEC
	ldr r4, _08030EF8 @ =gCurrentSprite
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	bne _08030EEC
	ldr r0, _08030EFC @ =0x00000117
	bl SoundPlay
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
_08030EEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030EF4: .4byte gWaterLowered
_08030EF8: .4byte gCurrentSprite
_08030EFC: .4byte 0x00000117

	thumb_func_start ElectricWaterInit
ElectricWaterInit: @ 0x08030F00
	push {r4, lr}
	ldr r0, _08030F6C @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0, #4]
	adds r0, #0x20
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1, #4]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r3, [r0]
	adds r1, #2
	movs r0, #0x80
	strb r0, [r1]
	ldr r0, _08030F70 @ =0x0000FFC0
	mov r1, ip
	strh r0, [r1, #0xa]
	strh r4, [r1, #0xc]
	ldr r0, _08030F74 @ =0x0000FE20
	strh r0, [r1, #0xe]
	movs r0, #0xf0
	lsls r0, r0, #1
	strh r0, [r1, #0x10]
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	strb r3, [r0, #0x1c]
	strh r4, [r0, #0x16]
	ldr r0, _08030F78 @ =0x0833ADCC
	mov r1, ip
	str r0, [r1, #0x18]
	movs r0, #0x8b
	lsls r0, r0, #1
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030F6C: .4byte gCurrentSprite
_08030F70: .4byte 0x0000FFC0
_08030F74: .4byte 0x0000FE20
_08030F78: .4byte 0x0833ADCC

	thumb_func_start ElectricWaterIdle
ElectricWaterIdle: @ 0x08030F7C
	ldr r1, _08030F88 @ =gCurrentSprite
	ldr r0, _08030F8C @ =gEffectYPosition
	ldrh r0, [r0]
	adds r0, #0x20
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
_08030F88: .4byte gCurrentSprite
_08030F8C: .4byte gEffectYPosition

	thumb_func_start ElectricWaterDamage
ElectricWaterDamage: @ 0x08030F90
	push {lr}
	ldr r0, _08030FA8 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08030FBC
	cmp r0, #2
	bgt _08030FAC
	cmp r0, #0
	beq _08030FB6
	b _08030FCC
	.align 2, 0
_08030FA8: .4byte gCurrentSprite
_08030FAC:
	cmp r0, #0x18
	beq _08030FC2
	cmp r0, #0x1a
	beq _08030FC8
	b _08030FCC
_08030FB6:
	bl ElectricWaterDamageInit
	b _08030FCC
_08030FBC:
	bl ElectricWaterDamageIdle
	b _08030FCC
_08030FC2:
	bl ElectricWaterDamageDamagingSamus
	b _08030FCC
_08030FC8:
	bl ElectricWaterDamageStopping
_08030FCC:
	ldr r0, _08030FE0 @ =gWaterLowered
	ldrb r0, [r0]
	cmp r0, #0
	beq _08030FDA
	ldr r1, _08030FE4 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_08030FDA:
	pop {r0}
	bx r0
	.align 2, 0
_08030FE0: .4byte gWaterLowered
_08030FE4: .4byte gCurrentSprite

	thumb_func_start ElectricWire
ElectricWire: @ 0x08030FE8
	push {lr}
	ldr r0, _08030FFC @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031000
	cmp r0, #2
	beq _08031006
	b _0803100A
	.align 2, 0
_08030FFC: .4byte gCurrentSprite
_08031000:
	bl ElectricWireInit
	b _0803100A
_08031006:
	bl ElectricWireIdle
_0803100A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ElectricWater
ElectricWater: @ 0x08031010
	push {lr}
	ldr r0, _0803102C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031030
	cmp r0, #2
	beq _08031034
	b _08031038
	.align 2, 0
_0803102C: .4byte gCurrentSprite
_08031030:
	bl ElectricWaterInit
_08031034:
	bl ElectricWaterIdle
_08031038:
	ldr r0, _0803104C @ =gWaterLowered
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031046
	ldr r1, _08031050 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_08031046:
	pop {r0}
	bx r0
	.align 2, 0
_0803104C: .4byte gWaterLowered
_08031050: .4byte gCurrentSprite

	thumb_func_start ZoroCheckCollidingWithAir
ZoroCheckCollidingWithAir: @ 0x08031054
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _08031088 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080310B4
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08031090
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803108C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08031104
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	b _080310F8
	.align 2, 0
_08031088: .4byte gCurrentSprite
_0803108C: .4byte gPreviousCollisionCheck
_08031090:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _080310B0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08031104
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	b _080310F8
	.align 2, 0
_080310B0: .4byte gPreviousCollisionCheck
_080310B4:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080310E0
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _080310DC @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08031104
	ldrh r0, [r4, #2]
	subs r0, #4
	b _080310F4
	.align 2, 0
_080310DC: .4byte gPreviousCollisionCheck
_080310E0:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803110C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08031104
	ldrh r0, [r4, #2]
_080310F4:
	ldrh r1, [r4, #4]
	adds r1, #0x20
_080310F8:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _08031104
	movs r6, #1
_08031104:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0803110C: .4byte gPreviousCollisionCheck

	thumb_func_start ZoroSetHitboxAndDrawDistance
ZoroSetHitboxAndDrawDistance: @ 0x08031110
	push {lr}
	ldr r1, _08031138 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0
	beq _08031150
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08031140
	ldr r0, _0803113C @ =0x0000FFC4
	strh r0, [r2, #0xa]
	movs r1, #0x3c
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	movs r0, #0x10
	b _0803117C
	.align 2, 0
_08031138: .4byte gCurrentSprite
_0803113C: .4byte 0x0000FFC4
_08031140:
	ldr r0, _0803114C @ =0x0000FFC4
	strh r0, [r2, #0xa]
	movs r1, #0x3c
	strh r1, [r2, #0xc]
	adds r0, #0x2c
	b _08031166
	.align 2, 0
_0803114C: .4byte 0x0000FFC4
_08031150:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08031170
	movs r0, #0x10
	strh r0, [r2, #0xa]
	movs r1, #0x3c
	strh r1, [r2, #0xc]
	ldr r0, _0803116C @ =0x0000FFC4
_08031166:
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	b _0803117E
	.align 2, 0
_0803116C: .4byte 0x0000FFC4
_08031170:
	ldr r0, _08031194 @ =0x0000FFC4
	strh r0, [r2, #0xa]
	movs r1, #0x10
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	movs r0, #0x3c
_0803117C:
	strh r0, [r2, #0x10]
_0803117E:
	adds r1, r2, #0
	adds r1, #0x27
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08031194: .4byte 0x0000FFC4

	thumb_func_start ZoroSetCrawlingOam
ZoroSetCrawlingOam: @ 0x08031198
	push {lr}
	ldr r0, _080311AC @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _080311B4
	ldr r0, _080311B0 @ =0x0833C09C
	b _080311B6
	.align 2, 0
_080311AC: .4byte gCurrentSprite
_080311B0: .4byte 0x0833C09C
_080311B4:
	ldr r0, _080311C4 @ =0x0833C034
_080311B6:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_080311C4: .4byte 0x0833C034

	thumb_func_start ZoroSetTurningOam
ZoroSetTurningOam: @ 0x080311C8
	push {lr}
	ldr r0, _080311DC @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _080311E4
	ldr r0, _080311E0 @ =0x0833C0D4
	b _080311E6
	.align 2, 0
_080311DC: .4byte gCurrentSprite
_080311E0: .4byte 0x0833C0D4
_080311E4:
	ldr r0, _080311F4 @ =0x0833C06C
_080311E6:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_080311F4: .4byte 0x0833C06C

	thumb_func_start ZoroSetTurningAroundSecondPartOam
ZoroSetTurningAroundSecondPartOam: @ 0x080311F8
	push {lr}
	ldr r0, _08031218 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _08031220
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	ldr r0, _0803121C @ =0x0833C0EC
	b _0803122A
	.align 2, 0
_08031218: .4byte gCurrentSprite
_0803121C: .4byte 0x0833C0EC
_08031220:
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
	ldr r0, _08031238 @ =0x0833C084
_0803122A:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_08031238: .4byte 0x0833C084

	thumb_func_start ZoroSetDeathPosition
ZoroSetDeathPosition: @ 0x0803123C
	push {lr}
	ldr r2, _0803125C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031268
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08031260
	ldrh r0, [r2, #4]
	subs r0, #0x20
	strh r0, [r2, #4]
	b _08031280
	.align 2, 0
_0803125C: .4byte gCurrentSprite
_08031260:
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	b _08031280
_08031268:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803127A
	ldrh r0, [r2, #2]
	adds r0, #0x20
	b _0803127E
_0803127A:
	ldrh r0, [r2, #2]
	subs r0, #0x20
_0803127E:
	strh r0, [r2, #2]
_08031280:
	pop {r0}
	bx r0

	thumb_func_start ZoroInit
ZoroInit: @ 0x08031284
	push {r4, r5, r6, r7, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _080312B0 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080312B4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080312B4
	strh r0, [r2]
	b _080313F6
	.align 2, 0
_080312B0: .4byte gCurrentSprite
_080312B4:
	ldr r0, _080312CC @ =gCurrentSprite
	adds r4, r0, #0
	adds r4, #0x24
	ldrb r1, [r4]
	adds r7, r0, #0
	cmp r1, #0x59
	bne _080312D0
	movs r0, #0x5a
	strb r0, [r4]
	movs r0, #0x2c
	strh r0, [r7, #6]
	b _080313D6
	.align 2, 0
_080312CC: .4byte gCurrentSprite
_080312D0:
	bl SpriteUtilChooseRandomXDirection
	movs r0, #2
	strb r0, [r4]
	ldrh r0, [r7, #2]
	ldrh r1, [r7, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08031308 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	movs r6, #0xf0
	adds r4, r6, #0
	ands r4, r0
	cmp r4, #0
	beq _0803130C
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080313D6
	movs r0, #0x40
	b _08031384
	.align 2, 0
_08031308: .4byte gPreviousCollisionCheck
_0803130C:
	ldrh r0, [r7, #2]
	subs r0, #0x44
	ldrh r1, [r7, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08031348
	adds r0, r7, #0
	adds r0, #0x2d
	strb r4, [r0]
	ldrh r1, [r7]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	movs r2, #0
	orrs r1, r0
	strh r1, [r7]
	ldrh r0, [r7, #2]
	subs r0, #0x40
	strh r0, [r7, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080313D6
	movs r0, #0x40
	b _080313D2
_08031348:
	ldrh r0, [r7, #2]
	subs r0, #0x20
	ldrh r1, [r7, #4]
	subs r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803138A
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r7, #2]
	subs r0, #0x20
	strh r0, [r7, #2]
	ldrh r0, [r7, #4]
	subs r0, #0x20
	strh r0, [r7, #4]
	ldrh r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080313D6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
_08031384:
	orrs r0, r1
	strh r0, [r7]
	b _080313D6
_0803138A:
	ldrh r0, [r7, #2]
	subs r0, #0x20
	ldrh r1, [r7, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	adds r2, r6, #0
	ands r2, r0
	cmp r2, #0
	bne _080313A4
	strh r2, [r7]
	b _080313F6
_080313A4:
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #0x40
	movs r2, #0
	orrs r1, r0
	strh r1, [r7]
	ldrh r0, [r7, #2]
	subs r0, #0x20
	strh r0, [r7, #2]
	ldrh r0, [r7, #4]
	adds r0, #0x20
	strh r0, [r7, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080313D6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
_080313D2:
	orrs r1, r0
	strh r1, [r7]
_080313D6:
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	bl ZoroSetCrawlingOam
	bl ZoroSetHitboxAndDrawDistance
	ldr r2, _080313FC @ =sPrimarySpriteStats
	ldrb r1, [r7, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x14]
_080313F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080313FC: .4byte sPrimarySpriteStats

	thumb_func_start ZoroCrawlingInit
ZoroCrawlingInit: @ 0x08031400
	push {lr}
	bl ZoroSetCrawlingOam
	ldr r2, _08031424 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08031420
	movs r0, #0xb4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08031420:
	pop {r0}
	bx r0
	.align 2, 0
_08031424: .4byte gCurrentSprite

	thumb_func_start ZoroRedGetSpeed
ZoroRedGetSpeed: @ 0x08031428
	push {lr}
	ldr r2, _0803145C @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r3, r0, #0x1f
	ldr r0, _08031460 @ =sPrimarySpriteStats
	ldr r1, _08031464 @ =0x000004EC
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r2, #0x14]
	lsrs r0, r0, #1
	cmp r1, r0
	bhs _080314D0
	ldrh r0, [r2, #0x16]
	cmp r0, #5
	bhi _080314C0
	lsls r0, r0, #2
	ldr r1, _08031468 @ =_0803146C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803145C: .4byte gCurrentSprite
_08031460: .4byte sPrimarySpriteStats
_08031464: .4byte 0x000004EC
_08031468: .4byte _0803146C
_0803146C: @ jump table
	.4byte _080314AC @ case 0
	.4byte _08031484 @ case 1
	.4byte _08031484 @ case 2
	.4byte _0803148C @ case 3
	.4byte _08031488 @ case 4
	.4byte _08031488 @ case 5
_08031484:
	movs r1, #1
	b _080314C4
_08031488:
	movs r1, #2
	b _080314C4
_0803148C:
	ldr r0, _080314A4 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _0803149E
	cmp r3, #0
	beq _0803149E
	ldr r0, _080314A8 @ =0x00000169
	bl SoundPlayNotAlreadyPlaying
_0803149E:
	movs r1, #4
	b _080314C2
	.align 2, 0
_080314A4: .4byte gCurrentSprite
_080314A8: .4byte 0x00000169
_080314AC:
	ldr r0, _080314CC @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _080314C0
	cmp r3, #0
	beq _080314C0
	movs r0, #0xb4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080314C0:
	movs r1, #0
_080314C2:
	ldr r2, _080314CC @ =gCurrentSprite
_080314C4:
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
	b _0803152C
	.align 2, 0
_080314CC: .4byte gCurrentSprite
_080314D0:
	ldrh r0, [r2, #0x16]
	cmp r0, #5
	bhi _0803152A
	lsls r0, r0, #2
	ldr r1, _080314E0 @ =_080314E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080314E0: .4byte _080314E4
_080314E4: @ jump table
	.4byte _08031518 @ case 0
	.4byte _080314FC @ case 1
	.4byte _080314FC @ case 2
	.4byte _08031500 @ case 3
	.4byte _080314FC @ case 4
	.4byte _080314FC @ case 5
_080314FC:
	movs r1, #1
	b _0803152C
_08031500:
	ldrb r0, [r2, #0x1c]
	cmp r0, #1
	bne _08031510
	cmp r3, #0
	beq _08031510
	ldr r0, _08031514 @ =0x00000169
	bl SoundPlayNotAlreadyPlaying
_08031510:
	movs r1, #2
	b _0803152C
	.align 2, 0
_08031514: .4byte 0x00000169
_08031518:
	ldrb r0, [r2, #0x1c]
	cmp r0, #1
	bne _0803152A
	cmp r3, #0
	beq _0803152A
	movs r0, #0xb4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803152A:
	movs r1, #0
_0803152C:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ZoroBlueGetSpeed
ZoroBlueGetSpeed: @ 0x08031534
	push {r4, r5, r6, r7, lr}
	ldr r4, _08031574 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r6, r0, #0x1f
	ldr r0, _08031578 @ =sPrimarySpriteStats
	ldr r1, _0803157C @ =0x0000056A
	adds r0, r0, r1
	ldrh r5, [r0]
	adds r0, r5, #0
	movs r1, #3
	bl __udivsi3
	ldrh r1, [r4, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r7, r4, #0
	cmp r1, r0
	bhs _080315E8
	ldrh r0, [r7, #0x16]
	cmp r0, #5
	bhi _080315D8
	lsls r0, r0, #2
	ldr r1, _08031580 @ =_08031584
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031574: .4byte gCurrentSprite
_08031578: .4byte sPrimarySpriteStats
_0803157C: .4byte 0x0000056A
_08031580: .4byte _08031584
_08031584: @ jump table
	.4byte _080315C4 @ case 0
	.4byte _0803159C @ case 1
	.4byte _0803159C @ case 2
	.4byte _080315A4 @ case 3
	.4byte _080315A0 @ case 4
	.4byte _080315A0 @ case 5
_0803159C:
	movs r1, #2
	b _080315DC
_080315A0:
	movs r1, #4
	b _080315DC
_080315A4:
	ldr r0, _080315BC @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _080315B6
	cmp r6, #0
	beq _080315B6
	ldr r0, _080315C0 @ =0x00000169
	bl SoundPlayNotAlreadyPlaying
_080315B6:
	movs r1, #6
	b _080315DA
	.align 2, 0
_080315BC: .4byte gCurrentSprite
_080315C0: .4byte 0x00000169
_080315C4:
	ldr r0, _080315E4 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _080315D8
	cmp r6, #0
	beq _080315D8
	movs r0, #0xb4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080315D8:
	movs r1, #0
_080315DA:
	ldr r7, _080315E4 @ =gCurrentSprite
_080315DC:
	ldrb r0, [r7, #0x1c]
	adds r0, #2
	strb r0, [r7, #0x1c]
	b _080316CC
	.align 2, 0
_080315E4: .4byte gCurrentSprite
_080315E8:
	ldrh r4, [r7, #0x14]
	lsls r0, r5, #1
	movs r1, #3
	bl __divsi3
	cmp r4, r0
	bge _08031670
	ldrh r0, [r7, #0x16]
	cmp r0, #5
	bhi _08031660
	lsls r0, r0, #2
	ldr r1, _08031608 @ =_0803160C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031608: .4byte _0803160C
_0803160C: @ jump table
	.4byte _0803164C @ case 0
	.4byte _08031624 @ case 1
	.4byte _08031624 @ case 2
	.4byte _0803162C @ case 3
	.4byte _08031628 @ case 4
	.4byte _08031628 @ case 5
_08031624:
	movs r1, #1
	b _08031664
_08031628:
	movs r1, #2
	b _08031664
_0803162C:
	ldr r0, _08031644 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _0803163E
	cmp r6, #0
	beq _0803163E
	ldr r0, _08031648 @ =0x00000169
	bl SoundPlayNotAlreadyPlaying
_0803163E:
	movs r1, #4
	b _08031662
	.align 2, 0
_08031644: .4byte gCurrentSprite
_08031648: .4byte 0x00000169
_0803164C:
	ldr r0, _0803166C @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _08031660
	cmp r6, #0
	beq _08031660
	movs r0, #0xb4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08031660:
	movs r1, #0
_08031662:
	ldr r7, _0803166C @ =gCurrentSprite
_08031664:
	ldrb r0, [r7, #0x1c]
	adds r0, #1
	strb r0, [r7, #0x1c]
	b _080316CC
	.align 2, 0
_0803166C: .4byte gCurrentSprite
_08031670:
	ldrh r0, [r7, #0x16]
	cmp r0, #5
	bhi _080316CA
	lsls r0, r0, #2
	ldr r1, _08031680 @ =_08031684
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031680: .4byte _08031684
_08031684: @ jump table
	.4byte _080316B8 @ case 0
	.4byte _0803169C @ case 1
	.4byte _0803169C @ case 2
	.4byte _080316A0 @ case 3
	.4byte _0803169C @ case 4
	.4byte _0803169C @ case 5
_0803169C:
	movs r1, #1
	b _080316CC
_080316A0:
	ldrb r0, [r7, #0x1c]
	cmp r0, #1
	bne _080316B0
	cmp r6, #0
	beq _080316B0
	ldr r0, _080316B4 @ =0x00000169
	bl SoundPlayNotAlreadyPlaying
_080316B0:
	movs r1, #2
	b _080316CC
	.align 2, 0
_080316B4: .4byte 0x00000169
_080316B8:
	ldrb r0, [r7, #0x1c]
	cmp r0, #1
	bne _080316CA
	cmp r6, #0
	beq _080316CA
	movs r0, #0xb4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080316CA:
	movs r1, #0
_080316CC:
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start ZoroCrawl
ZoroCrawl: @ 0x080316D4
	push {r4, r5, r6, r7, lr}
	ldr r0, _080316E4 @ =gCurrentSprite
	ldrb r0, [r0, #0x1d]
	cmp r0, #0x63
	bne _080316E8
	bl ZoroBlueGetSpeed
	b _080316EC
	.align 2, 0
_080316E4: .4byte gCurrentSprite
_080316E8:
	bl ZoroRedGetSpeed
_080316EC:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl ZoroCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031708
	ldr r0, _08031704 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	b _080318FA
	.align 2, 0
_08031704: .4byte gCurrentSprite
_08031708:
	ldr r4, _0803174C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031800
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803177C
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08031754
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08031750 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _08031740
	b _080318F4
_08031740:
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #4
	b _080317A6
	.align 2, 0
_0803174C: .4byte gCurrentSprite
_08031750: .4byte gPreviousCollisionCheck
_08031754:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08031778 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803176C
	b _080318F4
_0803176C:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #4
	b _080317E4
	.align 2, 0
_08031778: .4byte gPreviousCollisionCheck
_0803177C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080317C4
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _080317C0 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _080317A0
	b _080318F4
_080317A0:
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
_080317A6:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080317B6
	b _080318F4
_080317B6:
	ldrh r0, [r4, #2]
	adds r0, r5, r0
	strh r0, [r4, #2]
	b _080318EE
	.align 2, 0
_080317C0: .4byte gPreviousCollisionCheck
_080317C4:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _080317FC @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _080317DE
	b _080318F4
_080317DE:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
_080317E4:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080317F4
	b _080318F4
_080317F4:
	ldrh r0, [r4, #2]
	subs r0, r0, r5
	strh r0, [r4, #2]
	b _080318EE
	.align 2, 0
_080317FC: .4byte gPreviousCollisionCheck
_08031800:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803187C
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803184C
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08031848 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080318F4
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _080318F4
	ldrh r0, [r4, #4]
	adds r0, r5, r0
	b _080318EC
	.align 2, 0
_08031848: .4byte gPreviousCollisionCheck
_0803184C:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08031878 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080318F4
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	b _080318E2
	.align 2, 0
_08031878: .4byte gPreviousCollisionCheck
_0803187C:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080318BC
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _080318B8 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080318F4
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080318F4
	ldrh r0, [r4, #4]
	adds r0, r5, r0
	b _080318EC
	.align 2, 0
_080318B8: .4byte gPreviousCollisionCheck
_080318BC:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08031904 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080318F4
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
_080318E2:
	ands r0, r1
	cmp r0, #0
	bne _080318F4
	ldrh r0, [r4, #4]
	subs r0, r0, r5
_080318EC:
	strh r0, [r4, #4]
_080318EE:
	movs r0, #0
	cmp r0, #0
	beq _080318FC
_080318F4:
	ldr r0, _08031908 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #3
_080318FA:
	strb r1, [r0]
_080318FC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031904: .4byte gPreviousCollisionCheck
_08031908: .4byte gCurrentSprite

	thumb_func_start ZoroTurningInit
ZoroTurningInit: @ 0x0803190C
	push {lr}
	ldr r0, _08031920 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #4
	strb r1, [r0]
	bl ZoroSetTurningOam
	pop {r0}
	bx r0
	.align 2, 0
_08031920: .4byte gCurrentSprite

	thumb_func_start ZoroTurningAround
ZoroTurningAround: @ 0x08031924
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803193A
	ldr r0, _08031940 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #5
	strb r1, [r0]
	bl ZoroSetTurningAroundSecondPartOam
_0803193A:
	pop {r0}
	bx r0
	.align 2, 0
_08031940: .4byte gCurrentSprite

	thumb_func_start ZoroTurningAroundSecondPart
ZoroTurningAroundSecondPart: @ 0x08031944
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _08031956
	ldr r0, _0803195C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_08031956:
	pop {r0}
	bx r0
	.align 2, 0
_0803195C: .4byte gCurrentSprite

	thumb_func_start ZoroFallingInit
ZoroFallingInit: @ 0x08031960
	push {lr}
	ldr r1, _0803197C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r1, #0x31
	strb r3, [r1]
	bl ZoroSetCrawlingOam
	pop {r0}
	bx r0
	.align 2, 0
_0803197C: .4byte gCurrentSprite

	thumb_func_start ZoroFalling
ZoroFalling: @ 0x08031980
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r2, _080319A8 @ =gCurrentSprite
	ldrh r3, [r2, #2]
	ldrh r4, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080319AC
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080319B8
	subs r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _080319B8
	.align 2, 0
_080319A8: .4byte gCurrentSprite
_080319AC:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080319C0
_080319B8:
	ldrh r0, [r2, #0xc]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_080319C0:
	adds r0, r3, #0
	adds r1, r4, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08031A0C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031A34
	ldr r4, _08031A10 @ =gCurrentSprite
	strh r1, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x2d
	ldrb r0, [r2]
	cmp r0, #0
	beq _080319E6
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080319E6:
	ldrh r0, [r4]
	ldr r1, _08031A14 @ =0x0000FEFF
	ands r1, r0
	strh r1, [r4]
	movs r0, #0
	strb r0, [r2]
	bl ZoroSetHitboxAndDrawDistance
	cmp r5, #0
	beq _08031A20
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08031A18
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0x10]
	b _08031A1C
	.align 2, 0
_08031A0C: .4byte gPreviousVerticalCollisionCheck
_08031A10: .4byte gCurrentSprite
_08031A14: .4byte 0x0000FEFF
_08031A18:
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0xe]
_08031A1C:
	subs r0, r0, r1
	strh r0, [r4, #4]
_08031A20:
	ldr r0, _08031A30 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	bl ZoroSetCrawlingOam
	b _08031A78
	.align 2, 0
_08031A30: .4byte gCurrentSprite
_08031A34:
	ldr r3, _08031A60 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _08031A64 @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08031A68 @ =0x00007FFF
	cmp r1, r0
	bne _08031A6C
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08031A76
	.align 2, 0
_08031A60: .4byte gCurrentSprite
_08031A64: .4byte sSpritesFallingSpeed
_08031A68: .4byte 0x00007FFF
_08031A6C:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_08031A76:
	strh r0, [r3, #2]
_08031A78:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Zoro
Zoro: @ 0x08031A80
	push {lr}
	ldr r1, _08031AA0 @ =gCurrentSprite
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x63
	bne _08031AA8
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08031ABC
	ldr r0, _08031AA4 @ =0x000001A5
	bl SoundPlayNotAlreadyPlaying
	b _08031ABC
	.align 2, 0
_08031AA0: .4byte gCurrentSprite
_08031AA4: .4byte 0x000001A5
_08031AA8:
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08031ABC
	ldr r0, _08031AD0 @ =0x00000167
	bl SoundPlayNotAlreadyPlaying
_08031ABC:
	ldr r1, _08031AD4 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031AD8
	bl SpriteUtilUpdateFreezeTimer
	b _08031CAA
	.align 2, 0
_08031AD0: .4byte 0x00000167
_08031AD4: .4byte gCurrentSprite
_08031AD8:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08031AE4
	b _08031CAA
_08031AE4:
	lsls r0, r0, #2
	ldr r1, _08031AF0 @ =_08031AF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08031AF0: .4byte _08031AF4
_08031AF4: @ jump table
	.4byte _08031C64 @ case 0
	.4byte _08031C6A @ case 1
	.4byte _08031C6E @ case 2
	.4byte _08031C74 @ case 3
	.4byte _08031C78 @ case 4
	.4byte _08031C7E @ case 5
	.4byte _08031CAA @ case 6
	.4byte _08031CAA @ case 7
	.4byte _08031CAA @ case 8
	.4byte _08031CAA @ case 9
	.4byte _08031CAA @ case 10
	.4byte _08031CAA @ case 11
	.4byte _08031CAA @ case 12
	.4byte _08031CAA @ case 13
	.4byte _08031CAA @ case 14
	.4byte _08031CAA @ case 15
	.4byte _08031CAA @ case 16
	.4byte _08031CAA @ case 17
	.4byte _08031CAA @ case 18
	.4byte _08031CAA @ case 19
	.4byte _08031CAA @ case 20
	.4byte _08031C84 @ case 21
	.4byte _08031C88 @ case 22
	.4byte _08031CAA @ case 23
	.4byte _08031CAA @ case 24
	.4byte _08031CAA @ case 25
	.4byte _08031CAA @ case 26
	.4byte _08031CAA @ case 27
	.4byte _08031CAA @ case 28
	.4byte _08031CAA @ case 29
	.4byte _08031CAA @ case 30
	.4byte _08031CAA @ case 31
	.4byte _08031CAA @ case 32
	.4byte _08031CAA @ case 33
	.4byte _08031CAA @ case 34
	.4byte _08031CAA @ case 35
	.4byte _08031CAA @ case 36
	.4byte _08031CAA @ case 37
	.4byte _08031CAA @ case 38
	.4byte _08031CAA @ case 39
	.4byte _08031CAA @ case 40
	.4byte _08031CAA @ case 41
	.4byte _08031CAA @ case 42
	.4byte _08031CAA @ case 43
	.4byte _08031CAA @ case 44
	.4byte _08031CAA @ case 45
	.4byte _08031CAA @ case 46
	.4byte _08031CAA @ case 47
	.4byte _08031CAA @ case 48
	.4byte _08031CAA @ case 49
	.4byte _08031CAA @ case 50
	.4byte _08031CAA @ case 51
	.4byte _08031CAA @ case 52
	.4byte _08031CAA @ case 53
	.4byte _08031CAA @ case 54
	.4byte _08031CAA @ case 55
	.4byte _08031CAA @ case 56
	.4byte _08031CAA @ case 57
	.4byte _08031CAA @ case 58
	.4byte _08031CAA @ case 59
	.4byte _08031CAA @ case 60
	.4byte _08031CAA @ case 61
	.4byte _08031CAA @ case 62
	.4byte _08031CAA @ case 63
	.4byte _08031CAA @ case 64
	.4byte _08031CAA @ case 65
	.4byte _08031CAA @ case 66
	.4byte _08031CAA @ case 67
	.4byte _08031CAA @ case 68
	.4byte _08031CAA @ case 69
	.4byte _08031CAA @ case 70
	.4byte _08031CAA @ case 71
	.4byte _08031CAA @ case 72
	.4byte _08031CAA @ case 73
	.4byte _08031CAA @ case 74
	.4byte _08031CAA @ case 75
	.4byte _08031CAA @ case 76
	.4byte _08031CAA @ case 77
	.4byte _08031CAA @ case 78
	.4byte _08031CAA @ case 79
	.4byte _08031CAA @ case 80
	.4byte _08031CAA @ case 81
	.4byte _08031CAA @ case 82
	.4byte _08031CAA @ case 83
	.4byte _08031CAA @ case 84
	.4byte _08031CAA @ case 85
	.4byte _08031CAA @ case 86
	.4byte _08031C8E @ case 87
	.4byte _08031C92 @ case 88
	.4byte _08031C98 @ case 89
	.4byte _08031C9C @ case 90
	.4byte _08031CA2 @ case 91
_08031C64:
	bl ZoroInit
	b _08031CAA
_08031C6A:
	bl ZoroCrawlingInit
_08031C6E:
	bl ZoroCrawl
	b _08031CAA
_08031C74:
	bl ZoroTurningInit
_08031C78:
	bl ZoroTurningAround
	b _08031CAA
_08031C7E:
	bl ZoroTurningAroundSecondPart
	b _08031CAA
_08031C84:
	bl ZoroFallingInit
_08031C88:
	bl ZoroFalling
	b _08031CAA
_08031C8E:
	bl SpriteDyingInit
_08031C92:
	bl SpriteDying
	b _08031CAA
_08031C98:
	bl ZoroInit
_08031C9C:
	bl SpriteSpawningFromX
	b _08031CAA
_08031CA2:
	bl ZoroSetDeathPosition
	bl XParasiteInit
_08031CAA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterGroundCheckInSpittingrange
KihunterGroundCheckInSpittingrange: @ 0x08031CB0
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08031CC8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _08031CCC
	movs r0, #0
	b _08031CFE
	.align 2, 0
_08031CC8: .4byte gCurrentSprite
_08031CCC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08031CFC
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	beq _08031CFC
	movs r1, #0xb4
	lsls r1, r1, #1
	movs r0, #0x78
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	adds r2, r0, #0
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08031CF6
	cmp r2, #8
	bne _08031CFC
	b _08031CFA
_08031CF6:
	cmp r2, #4
	bne _08031CFC
_08031CFA:
	movs r5, #1
_08031CFC:
	adds r0, r5, #0
_08031CFE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start KihunterGroundDetectSamus
KihunterGroundDetectSamus: @ 0x08031D04
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08031D1C @ =gCurrentSprite
	ldrh r2, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	beq _08031D20
	movs r0, #0
	b _08031DB0
	.align 2, 0
_08031D1C: .4byte gCurrentSprite
_08031D20:
	movs r3, #0xf0
	movs r1, #0xfa
	lsls r1, r1, #1
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	cmp r0, #0
	beq _08031D3A
	adds r1, #0xc8
	adds r3, #0xc8
	ldr r0, _08031D60 @ =0x0000FBFF
	ands r0, r2
	strh r0, [r4]
_08031D3A:
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	beq _08031DAE
	adds r0, r3, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	adds r2, r0, #0
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08031D72
	cmp r2, #8
	bne _08031D64
	ldrh r0, [r4, #2]
	subs r0, #0x80
	ldrh r1, [r4, #4]
	adds r1, #0x48
	b _08031D7E
	.align 2, 0
_08031D60: .4byte 0x0000FBFF
_08031D64:
	cmp r2, #4
	bne _08031DAE
	ldrh r0, [r4, #2]
	subs r0, #0x80
	ldrh r1, [r4, #4]
	subs r1, #0x48
	b _08031DA0
_08031D72:
	cmp r2, #4
	bne _08031D94
	ldrh r0, [r4, #2]
	subs r0, #0x80
	ldrh r1, [r4, #4]
	subs r1, #0x48
_08031D7E:
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08031D90 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08031DAE
	movs r5, #1
	b _08031DAE
	.align 2, 0
_08031D90: .4byte gPreviousCollisionCheck
_08031D94:
	cmp r2, #8
	bne _08031DAE
	ldrh r0, [r4, #2]
	subs r0, #0x80
	ldrh r1, [r4, #4]
	adds r1, #0x48
_08031DA0:
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08031DB8 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08031DAE
	movs r5, #2
_08031DAE:
	adds r0, r5, #0
_08031DB0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08031DB8: .4byte gPreviousCollisionCheck

	thumb_func_start KihunterTurningIntoX
KihunterTurningIntoX: @ 0x08031DBC
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _08031E00 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08031E04
	ldrb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x1c
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	subs r0, #0x18
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	adds r0, #0x18
	b _08031E32
	.align 2, 0
_08031E00: .4byte gCurrentSprite
_08031E04:
	ldrb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x1c
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	adds r0, #0x18
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	subs r0, #0x18
_08031E32:
	strh r0, [r4, #4]
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start KihunterGroundInit
KihunterGroundInit: @ 0x08031E3C
	push {r4, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r4, _08031E60 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08031E64
	movs r0, #0
	strh r0, [r4]
	b _08031EDC
	.align 2, 0
_08031E60: .4byte gCurrentSprite
_08031E64:
	adds r0, r4, #0
	adds r0, #0x2f
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0
	ldr r0, _08031ECC @ =0x0000FFA0
	strh r0, [r4, #0xa]
	strh r2, [r4, #0xc]
	adds r0, #0x38
	strh r0, [r4, #0xe]
	movs r0, #0x28
	strh r0, [r4, #0x10]
	ldr r0, _08031ED0 @ =0x0833E5B4
	str r0, [r4, #0x18]
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _08031EAC
	ldr r2, _08031ED4 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
_08031EAC:
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _08031ED8
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _08031EDC
	.align 2, 0
_08031ECC: .4byte 0x0000FFA0
_08031ED0: .4byte 0x0833E5B4
_08031ED4: .4byte sPrimarySpriteStats
_08031ED8:
	movs r0, #1
	strb r0, [r1]
_08031EDC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterGroundJumpWarningInit
KihunterGroundJumpWarningInit: @ 0x08031EE4
	push {lr}
	ldr r3, _08031F1C @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #2
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _08031F20 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08031F28
	adds r0, r3, #0
	adds r0, #0x30
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08031F24 @ =0x0833E554
	b _08031F30
	.align 2, 0
_08031F1C: .4byte gCurrentSprite
_08031F20: .4byte gSpriteRandomNumber
_08031F24: .4byte 0x0833E554
_08031F28:
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	ldr r0, _08031F38 @ =0x0833E57C
_08031F30:
	str r0, [r3, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_08031F38: .4byte 0x0833E57C

	thumb_func_start KihhunterGroundJumpInit
KihhunterGroundJumpInit: @ 0x08031F3C
	push {lr}
	ldr r3, _08031F68 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r0, #0
	strh r2, [r3, #0x16]
	adds r1, #0xd
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	beq _08031F70
	ldrh r0, [r3, #2]
	subs r0, #0x30
	strh r0, [r3, #2]
	ldr r0, _08031F6C @ =0x0833E70C
	b _08031F78
	.align 2, 0
_08031F68: .4byte gCurrentSprite
_08031F6C: .4byte 0x0833E70C
_08031F70:
	ldrh r0, [r3, #2]
	subs r0, #0x20
	strh r0, [r3, #2]
	ldr r0, _08031F84 @ =0x0833E6FC
_08031F78:
	str r0, [r3, #0x18]
	ldr r0, _08031F88 @ =0x00000175
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_08031F84: .4byte 0x0833E6FC
_08031F88: .4byte 0x00000175

	thumb_func_start KihunterGroundLandingInit
KihunterGroundLandingInit: @ 0x08031F8C
	ldr r1, _08031FA4 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x1a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _08031FA8 @ =0x0833E5A4
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_08031FA4: .4byte gCurrentSprite
_08031FA8: .4byte 0x0833E5A4

	thumb_func_start KihunterIdleInit
KihunterIdleInit: @ 0x08031FAC
	ldr r1, _08031FC4 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #8
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _08031FC8 @ =0x0833E5B4
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_08031FC4: .4byte gCurrentSprite
_08031FC8: .4byte 0x0833E5B4

	thumb_func_start KihunterFallingInit
KihunterFallingInit: @ 0x08031FCC
	ldr r3, _08031FE8 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x31
	strb r1, [r0]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	ldr r0, _08031FEC @ =0x0833E70C
	str r0, [r3, #0x18]
	bx lr
	.align 2, 0
_08031FE8: .4byte gCurrentSprite
_08031FEC: .4byte 0x0833E70C

	thumb_func_start KihunterGroundTurningAroundInit
KihunterGroundTurningAroundInit: @ 0x08031FF0
	ldr r3, _0803200C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #4
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r0, #0
	strh r2, [r3, #0x16]
	adds r1, #0xb
	strb r0, [r1]
	ldr r0, _08032010 @ =0x0833E5EC
	str r0, [r3, #0x18]
	bx lr
	.align 2, 0
_0803200C: .4byte gCurrentSprite
_08032010: .4byte 0x0833E5EC

	thumb_func_start KihunterGroundSpittingInit
KihunterGroundSpittingInit: @ 0x08032014
	push {lr}
	ldr r3, _08032040 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x2a
	strb r0, [r1]
	ldr r0, _08032044 @ =0x0833E684
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _08032048 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803204C
	adds r0, r3, #0
	adds r0, #0x30
	strb r2, [r0]
	b _08032054
	.align 2, 0
_08032040: .4byte gCurrentSprite
_08032044: .4byte 0x0833E684
_08032048: .4byte gSpriteRandomNumber
_0803204C:
	adds r1, r3, #0
	adds r1, #0x30
	movs r0, #2
	strb r0, [r1]
_08032054:
	pop {r0}
	bx r0

	thumb_func_start kihunterGroundJumpWarning
kihunterGroundJumpWarning: @ 0x08032058
	push {r4, r5, lr}
	ldr r4, _0803208C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08032090 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08032094
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _08032094
	bl KihunterFallingInit
	b _080320A0
	.align 2, 0
_0803208C: .4byte gCurrentSprite
_08032090: .4byte gPreviousCollisionCheck
_08032094:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080320A0
	bl KihhunterGroundJumpInit
_080320A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterGroundJumping
KihunterGroundJumping: @ 0x080320A8
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r2, _080320BC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	bne _080320C4
	ldr r1, _080320C0 @ =0x0833C266
	b _080320C6
	.align 2, 0
_080320BC: .4byte gCurrentSprite
_080320C0: .4byte 0x0833C266
_080320C4:
	ldr r1, _08032108 @ =0x0833C252
_080320C6:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	ldr r4, _0803210C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803211A
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	adds r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08032110 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08032114
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	subs r0, #4
	b _08032148
	.align 2, 0
_08032108: .4byte 0x0833C252
_0803210C: .4byte gCurrentSprite
_08032110: .4byte gPreviousCollisionCheck
_08032114:
	ldrh r0, [r4, #4]
	adds r0, #2
	b _08032148
_0803211A:
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08032140 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08032144
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #4]
	adds r0, #4
	b _08032148
	.align 2, 0
_08032140: .4byte gPreviousCollisionCheck
_08032144:
	ldrh r0, [r4, #4]
	subs r0, #2
_08032148:
	strh r0, [r4, #4]
	ldr r4, _08032180 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
	adds r1, r4, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, #0x26
	bhi _08032160
	adds r0, #1
	strb r0, [r1]
_08032160:
	lsls r0, r5, #0x10
	cmp r0, #0
	ble _080321CC
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _08032184 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	beq _08032188
	strh r1, [r4, #2]
	bl KihunterGroundLandingInit
	b _0803222E
	.align 2, 0
_08032180: .4byte gCurrentSprite
_08032184: .4byte gPreviousVerticalCollisionCheck
_08032188:
	cmp r6, #0
	bne _0803222E
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080321BE
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _080321BA
	movs r6, #1
_080321BA:
	cmp r6, #0
	beq _0803222E
_080321BE:
	ldr r0, _080321C8 @ =gCurrentSprite
	strh r1, [r0, #2]
	bl KihunterGroundLandingInit
	b _0803222E
	.align 2, 0
_080321C8: .4byte gCurrentSprite
_080321CC:
	movs r6, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803221C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803220A
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _08032206
	movs r6, #1
_08032206:
	cmp r6, #0
	beq _0803222E
_0803220A:
	ldr r2, _08032220 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032224
	ldrh r0, [r2, #4]
	subs r0, #4
	b _08032228
	.align 2, 0
_0803221C: .4byte gPreviousCollisionCheck
_08032220: .4byte gCurrentSprite
_08032224:
	ldrh r0, [r2, #4]
	adds r0, #4
_08032228:
	strh r0, [r2, #4]
	bl KihunterFallingInit
_0803222E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start KihunterGroundLanding
KihunterGroundLanding: @ 0x08032234
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08032284
	bl KihunterGroundCheckInSpittingrange
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803224E
	bl KihunterGroundSpittingInit
	b _08032284
_0803224E:
	bl KihunterGroundDetectSamus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08032260
	bl KihhunterGroundJumpInit
	b _08032284
_08032260:
	cmp r0, #2
	bne _0803226A
	bl KihunterGroundTurningAroundInit
	b _08032284
_0803226A:
	ldr r0, _0803227C @ =gCurrentSprite
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #2
	bls _08032280
	bl KihunterIdleInit
	b _08032284
	.align 2, 0
_0803227C: .4byte gCurrentSprite
_08032280:
	bl KihunterGroundJumpWarningInit
_08032284:
	pop {r0}
	bx r0

	thumb_func_start KihunterGroundFalling
KihunterGroundFalling: @ 0x08032288
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r4, _080322DC @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _080322E0 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _080322D2
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080322D2
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _080322CE
	movs r6, #1
_080322CE:
	cmp r6, #0
	beq _080322E4
_080322D2:
	ldr r0, _080322DC @ =gCurrentSprite
	strh r1, [r0, #2]
	bl KihunterGroundLandingInit
	b _08032324
	.align 2, 0
_080322DC: .4byte gCurrentSprite
_080322E0: .4byte gPreviousVerticalCollisionCheck
_080322E4:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _08032310 @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08032314 @ =0x00007FFF
	cmp r1, r0
	bne _08032318
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _08032324
	.align 2, 0
_08032310: .4byte sSpritesFallingSpeed
_08032314: .4byte 0x00007FFF
_08032318:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_08032324:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterGroundIdle
KihunterGroundIdle: @ 0x0803232C
	push {r4, r5, lr}
	ldr r4, _08032360 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08032364 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08032368
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r4, [r4, #4]
	adds r1, r1, r4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _08032368
	bl KihunterFallingInit
	b _080323A0
	.align 2, 0
_08032360: .4byte gCurrentSprite
_08032364: .4byte gPreviousCollisionCheck
_08032368:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080323A0
	bl KihunterGroundDetectSamus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08032382
	bl KihunterGroundJumpWarningInit
	b _080323A0
_08032382:
	cmp r0, #2
	beq _08032390
	ldr r0, _08032398 @ =gCurrentSprite
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #2
	bls _0803239C
_08032390:
	bl KihunterGroundTurningAroundInit
	b _080323A0
	.align 2, 0
_08032398: .4byte gCurrentSprite
_0803239C:
	bl KihunterGroundJumpWarningInit
_080323A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterGroundTurningAround
KihunterGroundTurningAround: @ 0x080323A8
	push {r4, lr}
	ldr r4, _080323E4 @ =gCurrentSprite
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	beq _080323B8
	ldrh r0, [r4, #2]
	subs r0, #4
	strh r0, [r4, #2]
_080323B8:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080323DC
	ldrh r1, [r4]
	movs r0, #0x40
	eors r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r4]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #5
	strb r0, [r1]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	ldr r0, _080323E8 @ =0x0833E604
	str r0, [r4, #0x18]
_080323DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080323E4: .4byte gCurrentSprite
_080323E8: .4byte 0x0833E604

	thumb_func_start KihunterGroundTurningAroundSecondPart
KihunterGroundTurningAroundSecondPart: @ 0x080323EC
	push {r4, lr}
	ldr r4, _08032428 @ =gCurrentSprite
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	beq _080323FC
	ldrh r0, [r4, #2]
	adds r0, #4
	strh r0, [r4, #2]
_080323FC:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032430
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	adds r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803242C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08032450
	ldrh r0, [r4, #4]
	subs r0, #4
	b _0803244E
	.align 2, 0
_08032428: .4byte gCurrentSprite
_0803242C: .4byte gPreviousCollisionCheck
_08032430:
	ldrh r0, [r4, #2]
	subs r0, #0x10
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08032464 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08032450
	ldrh r0, [r4, #4]
	adds r0, #4
_0803244E:
	strh r0, [r4, #4]
_08032450:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803245C
	bl KihunterIdleInit
_0803245C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032464: .4byte gPreviousCollisionCheck

	thumb_func_start KihunterGroundSpitting
KihunterGroundSpitting: @ 0x08032468
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, _080324B0 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0, #0x16]
	cmp r0, #0xb
	bne _080324DC
	mov r1, ip
	ldrb r0, [r1, #0x1c]
	cmp r0, #3
	bne _080324DC
	ldrh r1, [r1]
	movs r5, #0x40
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080324B4
	mov r4, ip
	ldrb r1, [r4, #0x1e]
	ldrb r2, [r4, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0x58
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x60
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x11
	bl SpriteSpawnSecondary
	b _080324D4
	.align 2, 0
_080324B0: .4byte gCurrentSprite
_080324B4:
	mov r5, ip
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	subs r0, #0x58
	str r0, [sp]
	ldrh r0, [r5, #4]
	subs r0, #0x60
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x11
	bl SpriteSpawnSecondary
_080324D4:
	movs r0, #0xbc
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080324DC:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080324F8
	ldr r1, _08032500 @ =gCurrentSprite
	adds r1, #0x30
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080324F8
	bl KihunterGroundJumpWarningInit
_080324F8:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08032500: .4byte gCurrentSprite

	thumb_func_start KihunterFlyingXMovement
KihunterFlyingXMovement: @ 0x08032504
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r5, #0
	ldr r4, _08032534 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803253C
	ldrh r0, [r4, #2]
	subs r0, #0x10
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08032538 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08032550
	ldrh r0, [r4, #4]
	adds r0, r5, r0
	b _0803255C
	.align 2, 0
_08032534: .4byte gCurrentSprite
_08032538: .4byte gPreviousCollisionCheck
_0803253C:
	ldrh r0, [r4, #2]
	subs r0, #0x10
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08032554 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08032558
_08032550:
	movs r0, #1
	b _08032560
	.align 2, 0
_08032554: .4byte gPreviousCollisionCheck
_08032558:
	ldrh r0, [r4, #4]
	subs r0, r0, r6
_0803255C:
	strh r0, [r4, #4]
	movs r0, #0
_08032560:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start KihunterFlyingInit
KihunterFlyingInit: @ 0x08032568
	push {r4, r5, lr}
	sub sp, #0xc
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r4, _0803258C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08032590
	movs r0, #0
	strh r0, [r4]
	b _08032646
	.align 2, 0
_0803258C: .4byte gCurrentSprite
_08032590:
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0
	ldr r0, _080325FC @ =0x0000FFA0
	strh r0, [r4, #0xa]
	strh r2, [r4, #0xc]
	adds r0, #0x38
	strh r0, [r4, #0xe]
	movs r0, #0x28
	strh r0, [r4, #0x10]
	ldr r0, _08032600 @ =0x0833E454
	str r0, [r4, #0x18]
	strb r1, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r0, #3
	strb r1, [r0]
	ldr r2, _08032604 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803260C
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r4, #6]
	ldrh r1, [r4]
	ldr r0, _08032608 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
	b _08032610
	.align 2, 0
_080325FC: .4byte 0x0000FFA0
_08032600: .4byte 0x0833E454
_08032604: .4byte sPrimarySpriteStats
_08032608: .4byte 0x0000FFFB
_0803260C:
	movs r0, #1
	strb r0, [r1]
_08032610:
	ldr r5, _08032650 @ =gCurrentSprite
	ldrh r0, [r5, #2]
	strh r0, [r5, #8]
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	ldrh r4, [r5]
	movs r0, #0x40
	ands r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0x10
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08032646
	movs r0, #0
	strh r0, [r5]
_08032646:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08032650: .4byte gCurrentSprite

	thumb_func_start KihunterFlyingIdleInit
KihunterFlyingIdleInit: @ 0x08032654
	ldr r3, _08032678 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	ldr r0, _0803267C @ =0x0833E454
	str r0, [r3, #0x18]
	adds r0, r3, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r0, #3
	strb r1, [r0]
	bx lr
	.align 2, 0
_08032678: .4byte gCurrentSprite
_0803267C: .4byte 0x0833E454

	thumb_func_start KihunterFlyingTurningAroundInit
KihunterFlyingTurningAroundInit: @ 0x08032680
	ldr r1, _08032698 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #4
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803269C @ =0x0833E5EC
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_08032698: .4byte gCurrentSprite
_0803269C: .4byte 0x0833E5EC

	thumb_func_start KihunterFlyingIdle
KihunterFlyingIdle: @ 0x080326A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r3, _080326D8 @ =gCurrentSprite
	adds r6, r3, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _080326DC @ =0x0833C27A
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _080326E0 @ =0x00007FFF
	cmp r1, r0
	bne _080326C4
	ldrh r4, [r5]
	movs r2, #0
_080326C4:
	adds r0, r2, #1
	strb r0, [r6]
	lsls r0, r4, #0x10
	cmp r0, #0
	ble _080326E4
	ldrh r0, [r3, #2]
	ldrh r1, [r3, #4]
	bl SpriteUtilCheckCollisionAtPosition
	b _080326EE
	.align 2, 0
_080326D8: .4byte gCurrentSprite
_080326DC: .4byte 0x0833C27A
_080326E0: .4byte 0x00007FFF
_080326E4:
	ldrh r0, [r3, #2]
	subs r0, #0x60
	ldrh r1, [r3, #4]
	bl SpriteUtilCheckCollisionAtPosition
_080326EE:
	ldr r0, _08032714 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _080326FE
	ldr r1, _08032718 @ =gCurrentSprite
	ldrh r0, [r1, #2]
	adds r0, r0, r4
	strh r0, [r1, #2]
_080326FE:
	movs r0, #2
	bl KihunterFlyingXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803271C
	ldr r0, _08032718 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	b _080327A8
	.align 2, 0
_08032714: .4byte gPreviousCollisionCheck
_08032718: .4byte gCurrentSprite
_0803271C:
	ldr r6, _08032780 @ =gCurrentSprite
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x2f
	bne _080327A8
	movs r0, #0x2e
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	adds r0, #1
	mov r1, r8
	strb r0, [r1]
	ldr r7, _08032784 @ =gSamusData
	ldrh r5, [r7, #0x18]
	ldrh r4, [r6, #2]
	subs r4, #0x60
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xa0
	lsls r0, r0, #2
	movs r1, #0xf0
	lsls r1, r1, #2
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, r4
	bhs _08032758
	movs r0, #0
_08032758:
	cmp r0, #0
	beq _080327A8
	ldrh r1, [r6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032788
	ldrh r0, [r6, #4]
	ldrh r7, [r7, #0x16]
	cmp r0, r7
	bls _080327A0
	mov r7, r8
	ldrb r0, [r7]
	cmp r0, #1
	bls _080327A8
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #3
	b _080327A6
	.align 2, 0
_08032780: .4byte gCurrentSprite
_08032784: .4byte gSamusData
_08032788:
	ldrh r0, [r6, #4]
	ldrh r7, [r7, #0x16]
	cmp r0, r7
	bhs _080327A0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #1
	bls _080327A8
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #3
	b _080327A6
_080327A0:
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #0x29
_080327A6:
	strb r0, [r1]
_080327A8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterTurningAround
KihunterTurningAround: @ 0x080327B4
	push {r4, lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080327DC
	ldr r2, _080327E4 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	eors r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #5
	strb r0, [r1]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	ldr r0, _080327E8 @ =0x0833E604
	str r0, [r2, #0x18]
_080327DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080327E4: .4byte gCurrentSprite
_080327E8: .4byte 0x0833E604

	thumb_func_start KihunterFlyingTurningAroundSecondPart
KihunterFlyingTurningAroundSecondPart: @ 0x080327EC
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080327FA
	bl KihunterFlyingIdleInit
_080327FA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterFlyingUpdateSwipeAnimation
KihunterFlyingUpdateSwipeAnimation: @ 0x08032800
	push {r4, lr}
	ldr r4, _08032830 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803287E
	movs r0, #0xa0
	movs r1, #0x80
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803284E
	ldr r0, [r4, #0x18]
	ldr r1, _08032834 @ =0x0833E50C
	cmp r0, r1
	beq _08032838
	str r1, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	b _0803287E
	.align 2, 0
_08032830: .4byte gCurrentSprite
_08032834: .4byte 0x0833E50C
_08032838:
	ldrh r0, [r4, #0x16]
	cmp r0, #2
	bne _0803287E
	ldrb r0, [r4, #0x1c]
	cmp r0, #4
	bne _0803287E
	movs r0, #0xbb
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0803287E
_0803284E:
	ldr r1, [r4, #0x18]
	ldr r0, _08032884 @ =0x0833E50C
	cmp r1, r0
	bne _0803287E
	ldrh r0, [r4, #0x16]
	cmp r0, #2
	bne _0803286A
	ldrb r0, [r4, #0x1c]
	cmp r0, #4
	bne _0803286A
	movs r0, #0xbb
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803286A:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803287E
	ldr r0, _08032888 @ =gCurrentSprite
	ldr r1, _0803288C @ =0x0833E454
	str r1, [r0, #0x18]
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
_0803287E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032884: .4byte 0x0833E50C
_08032888: .4byte gCurrentSprite
_0803288C: .4byte 0x0833E454

	thumb_func_start KihunterFlyingSwoopingDownInit
KihunterFlyingSwoopingDownInit: @ 0x08032890
	push {r4, lr}
	ldr r3, _080328EC @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	movs r4, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r4, [r0]
	subs r1, #0xa
	movs r0, #0x2a
	strb r0, [r1]
	ldr r2, _080328F0 @ =gSamusData
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	movs r1, #0xb4
	lsls r1, r1, #1
	cmp r0, r1
	bgt _080328D2
	ldr r0, _080328F4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #0xa
	bls _08032900
_080328D2:
	ldr r0, _080328F8 @ =0x0833E4A4
	str r0, [r3, #0x18]
	strb r4, [r3, #0x1c]
	strh r4, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #3
	strb r0, [r1]
	ldr r0, _080328FC @ =0x00000177
	bl SoundPlayNotAlreadyPlaying
	b _08032906
	.align 2, 0
_080328EC: .4byte gCurrentSprite
_080328F0: .4byte gSamusData
_080328F4: .4byte gSpriteRandomNumber
_080328F8: .4byte 0x0833E4A4
_080328FC: .4byte 0x00000177
_08032900:
	ldr r0, _0803290C @ =0x00000179
	bl SoundPlayNotAlreadyPlaying
_08032906:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803290C: .4byte 0x00000179

	thumb_func_start KihunterFlyingSwoopingDown
KihunterFlyingSwoopingDown: @ 0x08032910
	push {r4, r5, r6, lr}
	bl KihunterFlyingUpdateSwipeAnimation
	ldr r4, _08032958 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, #0x10
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803295C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08032960
	movs r0, #6
	bl KihunterFlyingXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803293E
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2d
	strb r0, [r1]
_0803293E:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080329EC
	subs r1, #0xa
	movs r0, #0x2d
	strb r0, [r1]
	b _080329EC
	.align 2, 0
_08032958: .4byte gCurrentSprite
_0803295C: .4byte gPreviousCollisionCheck
_08032960:
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r0, [r0]
	cmp r0, #3
	bne _08032978
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #2
	cmp r0, #4
	bls _08032986
	b _08032984
_08032978:
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsrs r0, r0, #1
	cmp r0, #8
	bls _08032986
_08032984:
	movs r0, #8
_08032986:
	bl KihunterFlyingXMovement
	ldr r4, _080329A8 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080329AC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _080329B0
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2b
	strb r0, [r1]
	b _080329EC
	.align 2, 0
_080329A8: .4byte gCurrentSprite
_080329AC: .4byte gPreviousCollisionCheck
_080329B0:
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _080329D8 @ =0x0833C2DC
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _080329DC @ =0x00007FFF
	cmp r1, r0
	bne _080329E0
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _080329EA
	.align 2, 0
_080329D8: .4byte 0x0833C2DC
_080329DC: .4byte 0x00007FFF
_080329E0:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
_080329EA:
	strh r0, [r4, #2]
_080329EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterFlyingSwoopingAcrossInit
KihunterFlyingSwoopingAcrossInit: @ 0x080329F4
	ldr r2, _08032A10 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	movs r1, #0
	movs r0, #0x14
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x31
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	bx lr
	.align 2, 0
_08032A10: .4byte gCurrentSprite

	thumb_func_start KihunterFlyingSwoopingAcross
KihunterFlyingSwoopingAcross: @ 0x08032A14
	push {r4, r5, r6, r7, lr}
	bl KihunterFlyingUpdateSwipeAnimation
	movs r0, #8
	bl KihunterFlyingXMovement
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r4, _08032A5C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, #0x10
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _08032A60 @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	cmp r0, #0x11
	bne _08032A64
	cmp r5, #0
	beq _08032A44
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2d
	strb r0, [r1]
_08032A44:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08032AC2
	subs r1, #0xa
	movs r0, #0x2d
	b _08032AC0
	.align 2, 0
_08032A5C: .4byte gCurrentSprite
_08032A60: .4byte gPreviousCollisionCheck
_08032A64:
	ldrh r0, [r4, #2]
	adds r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r6]
	cmp r0, #0x11
	bne _08032AB0
	adds r6, r4, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _08032A9C @ =0x0833C2FC
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08032AA0 @ =0x00007FFF
	cmp r1, r0
	bne _08032AA4
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #2]
	b _08032AC2
	.align 2, 0
_08032A9C: .4byte 0x0833C2FC
_08032AA0: .4byte 0x00007FFF
_08032AA4:
	adds r0, r2, #1
	strb r0, [r6]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	b _08032AC2
_08032AB0:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0
	strb r0, [r1]
	adds r1, #3
	strb r0, [r1]
	subs r1, #0xd
	movs r0, #0x2a
_08032AC0:
	strb r0, [r1]
_08032AC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start KihunterFlyingAfterSwoopingInit
KihunterFlyingAfterSwoopingInit: @ 0x08032AC8
	push {lr}
	ldr r2, _08032AF8 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2e
	movs r3, #0
	strb r3, [r0]
	adds r0, #3
	strb r3, [r0]
	subs r0, #0xd
	movs r1, #0x2e
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x25
	ldrb r0, [r1]
	cmp r0, #3
	bne _08032AF4
	ldr r0, _08032AFC @ =0x0833E454
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	movs r0, #2
	strb r0, [r1]
_08032AF4:
	pop {r0}
	bx r0
	.align 2, 0
_08032AF8: .4byte gCurrentSprite
_08032AFC: .4byte 0x0833E454

	thumb_func_start KihunterFlyingAfterSwooping
KihunterFlyingAfterSwooping: @ 0x08032B00
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08032B24
	ldr r2, _08032B7C @ =gCurrentSprite
	ldr r1, [r2, #0x18]
	ldr r0, _08032B80 @ =0x0833E50C
	cmp r1, r0
	bne _08032B24
	ldr r0, _08032B84 @ =0x0833E454
	str r0, [r2, #0x18]
	strb r7, [r2, #0x1c]
	strh r7, [r2, #0x16]
_08032B24:
	movs r0, #6
	bl KihunterFlyingXMovement
	ldr r4, _08032B7C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08032B88 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08032BFA
	adds r2, r4, #0
	adds r2, #0x2e
	ldrb r1, [r2]
	cmp r1, #0
	bne _08032BAE
	ldrh r0, [r4, #8]
	adds r0, #0x40
	ldrh r5, [r4, #2]
	cmp r0, r5
	bge _08032BA2
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r1, _08032B8C @ =0x0833C30C
	mov r8, r1
	lsls r0, r2, #1
	add r0, r8
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08032B90 @ =0x00007FFF
	cmp r1, r0
	bne _08032B94
	subs r0, r2, #1
	lsls r0, r0, #1
	add r0, r8
	ldrh r3, [r0]
	adds r0, r5, r3
	strh r0, [r4, #2]
	b _08032C00
	.align 2, 0
_08032B7C: .4byte gCurrentSprite
_08032B80: .4byte 0x0833E50C
_08032B84: .4byte 0x0833E454
_08032B88: .4byte gPreviousCollisionCheck
_08032B8C: .4byte 0x0833C30C
_08032B90: .4byte 0x00007FFF
_08032B94:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	b _08032C00
_08032BA2:
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x31
	strb r1, [r0]
	b _08032C00
_08032BAE:
	ldrh r3, [r4, #2]
	ldrh r0, [r4, #8]
	mov ip, r3
	cmp r0, r3
	bhs _08032BFA
	movs r5, #0x31
	adds r5, r5, r4
	mov r8, r5
	ldrb r2, [r5]
	ldr r6, _08032BE4 @ =0x0833C324
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	mov sb, r1
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _08032BE8 @ =0x00007FFF
	cmp r1, r0
	bne _08032BEC
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	add r0, ip
	strh r0, [r4, #2]
	b _08032C00
	.align 2, 0
_08032BE4: .4byte 0x0833C324
_08032BE8: .4byte 0x00007FFF
_08032BEC:
	adds r0, r2, #1
	mov r6, r8
	strb r0, [r6]
	mov r1, sb
	adds r0, r3, r1
	strh r0, [r4, #2]
	b _08032C00
_08032BFA:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_08032C00:
	cmp r7, #0
	beq _08032C54
	ldr r2, _08032C2C @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032C34
	ldr r1, _08032C30 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _08032C4C
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #3
	b _08032C52
	.align 2, 0
_08032C2C: .4byte gCurrentSprite
_08032C30: .4byte gSamusData
_08032C34:
	ldr r1, _08032C48 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bhs _08032C4C
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #3
	b _08032C52
	.align 2, 0
_08032C48: .4byte gSamusData
_08032C4C:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #1
_08032C52:
	strb r0, [r1]
_08032C54:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start KihunterWingsInit
KihunterWingsInit: @ 0x08032C60
	push {r4, lr}
	ldr r0, _08032CDC @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _08032CE0 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08032C88
	mov r4, ip
	ldrh r1, [r4]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r4]
_08032C88:
	mov r0, ip
	ldrh r1, [r0]
	ldr r0, _08032CE4 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r1, #0x27
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08032CE8 @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	subs r1, #2
	movs r0, #3
	strb r0, [r1]
	ldr r0, _08032CEC @ =0x0833E474
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032CDC: .4byte gCurrentSprite
_08032CE0: .4byte gSpriteData
_08032CE4: .4byte 0x0000FFFB
_08032CE8: .4byte 0x0000FFFC
_08032CEC: .4byte 0x0833E474

	thumb_func_start KihunterWingsIdle
KihunterWingsIdle: @ 0x08032CF0
	push {r4, r5, lr}
	ldr r3, _08032D28 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r4, [r0]
	ldr r1, _08032D2C @ =gSpriteData
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r2, r0, r1
	ldrh r0, [r2, #2]
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	strh r0, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #0x57
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r1, #0
	cmp r0, #1
	bhi _08032D30
	bl SpriteDyingInit
	bl SpriteDying
	b _08032DBA
	.align 2, 0
_08032D28: .4byte gCurrentSprite
_08032D2C: .4byte gSpriteData
_08032D30:
	ldrh r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08032D42
	ldrh r0, [r3]
	movs r1, #0x20
	orrs r0, r1
	b _08032D48
_08032D42:
	ldrh r1, [r3]
	ldr r0, _08032D64 @ =0x0000FFDF
	ands r0, r1
_08032D48:
	strh r0, [r3]
	lsls r2, r4, #3
	subs r0, r2, r4
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032D68
	ldrh r1, [r3]
	movs r0, #0x40
	orrs r0, r1
	b _08032D6E
	.align 2, 0
_08032D64: .4byte 0x0000FFDF
_08032D68:
	ldrh r1, [r3]
	ldr r0, _08032DAC @ =0x0000FFBF
	ands r0, r1
_08032D6E:
	strh r0, [r3]
	subs r0, r2, r4
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrh r0, [r0, #0x14]
	cmp r0, #6
	bhi _08032DBA
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x38
	strb r0, [r1]
	ldr r0, _08032DB0 @ =0x0833E4C4
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x20
	strb r1, [r0]
	ldrh r0, [r3, #2]
	subs r0, #0x60
	strh r0, [r3, #2]
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032DB4
	ldrh r0, [r3, #4]
	subs r0, #0x20
	b _08032DB8
	.align 2, 0
_08032DAC: .4byte 0x0000FFBF
_08032DB0: .4byte 0x0833E4C4
_08032DB4:
	ldrh r0, [r3, #4]
	adds r0, #0x20
_08032DB8:
	strh r0, [r3, #4]
_08032DBA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start KihunterWingsFalling
KihunterWingsFalling: @ 0x08032DC0
	push {r4, lr}
	ldr r4, _08032DE8 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08032DEC @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032DF0
	strh r1, [r4, #2]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3a
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x28
	strb r0, [r1]
	b _08032DF6
	.align 2, 0
_08032DE8: .4byte gCurrentSprite
_08032DEC: .4byte gPreviousVerticalCollisionCheck
_08032DF0:
	ldrh r0, [r4, #2]
	adds r0, #2
	strh r0, [r4, #2]
_08032DF6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start KihunterWingsDisappearing
KihunterWingsDisappearing: @ 0x08032DFC
	push {lr}
	ldr r0, _08032E2C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	ldr r2, _08032E30 @ =gCurrentSprite
	cmp r0, #0
	bne _08032E14
	ldrh r0, [r2]
	movs r1, #4
	eors r0, r1
	strh r0, [r2]
_08032E14:
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08032E28
	strh r0, [r2]
_08032E28:
	pop {r0}
	bx r0
	.align 2, 0
_08032E2C: .4byte gFrameCounter8Bit
_08032E30: .4byte gCurrentSprite

	thumb_func_start KihunterSpitInit
KihunterSpitInit: @ 0x08032E34
	push {r4, lr}
	ldr r0, _08032E94 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08032E98 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _08032E9C @ =0x0000FFF8
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _08032EA0 @ =0x0833E64C
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r0, ip
	adds r0, #0x31
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032E94: .4byte gCurrentSprite
_08032E98: .4byte 0x0000FFFB
_08032E9C: .4byte 0x0000FFF8
_08032EA0: .4byte 0x0833E64C

	thumb_func_start KihunterSpitMoving
KihunterSpitMoving: @ 0x08032EA4
	push {r4, r5, r6, lr}
	ldr r4, _08032EC8 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08032ECC @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08032ED0
	strh r1, [r4, #2]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _08032F2A
	.align 2, 0
_08032EC8: .4byte gCurrentSprite
_08032ECC: .4byte gPreviousVerticalCollisionCheck
_08032ED0:
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _08032EF8 @ =0x0833C228
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _08032EFC @ =0x00007FFF
	cmp r1, r0
	bne _08032F00
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08032F0A
	.align 2, 0
_08032EF8: .4byte 0x0833C228
_08032EFC: .4byte 0x00007FFF
_08032F00:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
_08032F0A:
	strh r0, [r4, #2]
	ldr r2, _08032F20 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08032F24
	ldrh r0, [r2, #4]
	adds r0, #0xc
	b _08032F28
	.align 2, 0
_08032F20: .4byte gCurrentSprite
_08032F24:
	ldrh r0, [r2, #4]
	subs r0, #0xc
_08032F28:
	strh r0, [r2, #4]
_08032F2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start KihunterSpitExplodingInit
KihunterSpitExplodingInit: @ 0x08032F30
	ldr r3, _08032F4C @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	ldr r0, _08032F50 @ =0x0833E664
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	bx lr
	.align 2, 0
_08032F4C: .4byte gCurrentSprite
_08032F50: .4byte 0x0833E664

	thumb_func_start KihunterSpitExploding
KihunterSpitExploding: @ 0x08032F54
	push {r4, lr}
	ldr r4, _08032F74 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08032F6C
	movs r0, #0
	strh r0, [r4]
_08032F6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032F74: .4byte gCurrentSprite

	thumb_func_start KihunterHiveInit
KihunterHiveInit: @ 0x08032F78
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r5, _08032F9C @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08032FA0
	strh r0, [r5]
	b _08033032
	.align 2, 0
_08032F9C: .4byte gCurrentSprite
_08032FA0:
	adds r0, r5, #0
	adds r0, #0x27
	movs r4, #0
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r2, #0
	ldr r0, _0803303C @ =0x0000FFC0
	strh r0, [r5, #0xa]
	movs r1, #0x30
	strh r1, [r5, #0xc]
	adds r0, #0x10
	strh r0, [r5, #0xe]
	strh r1, [r5, #0x10]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x10
	strb r0, [r1]
	subs r1, #0x13
	movs r0, #0xd
	strb r0, [r1]
	ldr r0, _08033040 @ =0x0833E61C
	str r0, [r5, #0x18]
	strb r2, [r5, #0x1c]
	strh r4, [r5, #0x16]
	ldr r2, _08033044 @ =sPrimarySpriteStats
	ldrb r1, [r5, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	adds r0, r5, #0
	adds r0, #0x24
	strb r3, [r0]
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	adds r6, r5, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	adds r0, #0x60
	str r0, [sp]
	ldrh r0, [r5, #4]
	subs r0, #0x20
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x2b
	bl SpriteSpawnSecondary
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r5, #2]
	adds r0, #0x60
	str r0, [sp]
	ldrh r0, [r5, #4]
	adds r0, #0x20
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x2b
	bl SpriteSpawnSecondary
	movs r0, #0x8c
	lsls r0, r0, #1
	bl SoundPlay_2894
_08033032:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803303C: .4byte 0x0000FFC0
_08033040: .4byte 0x0833E61C
_08033044: .4byte sPrimarySpriteStats

	thumb_func_start KihunterHiveSpawnKihunter
KihunterHiveSpawnKihunter: @ 0x08033048
	push {r4, lr}
	sub sp, #0xc
	ldr r3, _080330D0 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x36
	movs r0, #1
	strb r0, [r1]
	subs r1, #0xc
	movs r0, #0x10
	strb r0, [r1]
	ldrh r1, [r3]
	ldr r0, _080330D4 @ =0x00007FDF
	ands r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r3, #6]
	ldr r1, _080330D8 @ =gSamusData
	ldrh r0, [r3, #4]
	movs r4, #0x40
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _0803307E
	movs r4, #0
_0803307E:
	ldrb r2, [r3, #0x1f]
	ldrh r0, [r3, #2]
	adds r0, #0x80
	str r0, [sp]
	ldrh r0, [r3, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x5b
	movs r1, #0
	movs r3, #0x20
	bl SpriteSpawnPrimary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080330DC @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x59
	strb r0, [r2]
	ldrh r0, [r1]
	ldr r3, _080330E0 @ =0x00008020
	adds r2, r3, #0
	orrs r0, r2
	movs r2, #0
	orrs r0, r2
	ldr r2, _080330E4 @ =0x0000DFFF
	ands r0, r2
	strh r0, [r1]
	adds r1, #0x34
	ldrb r2, [r1]
	movs r0, #0xfd
	ands r0, r2
	strb r0, [r1]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080330D0: .4byte gCurrentSprite
_080330D4: .4byte 0x00007FDF
_080330D8: .4byte gSamusData
_080330DC: .4byte gSpriteData
_080330E0: .4byte 0x00008020
_080330E4: .4byte 0x0000DFFF

	thumb_func_start KihunterHiveSpawnCooldown
KihunterHiveSpawnCooldown: @ 0x080330E8
	push {lr}
	ldr r3, _08033110 @ =gCurrentSprite
	ldrh r0, [r3, #6]
	subs r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803310A
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #2
	movs r0, #2
	strb r0, [r2]
	adds r2, #0x10
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
_0803310A:
	pop {r0}
	bx r0
	.align 2, 0
_08033110: .4byte gCurrentSprite

	thumb_func_start KihunterBugInit
KihunterBugInit: @ 0x08033114
	push {r4, lr}
	ldr r0, _08033180 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08033184 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08033188 @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _0803318C @ =0x0833E62C
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	mov r3, ip
	adds r3, #0x31
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	subs r1, #2
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _08033190 @ =gFrameCounter8Bit
	ldrb r0, [r1]
	lsls r0, r0, #2
	strb r0, [r3]
	ldrb r1, [r1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08033194
	mov r1, ip
	adds r1, #0x30
	movs r0, #0x14
	b _0803319A
	.align 2, 0
_08033180: .4byte gCurrentSprite
_08033184: .4byte 0x0000FFFB
_08033188: .4byte 0x0000FFFC
_0803318C: .4byte 0x0833E62C
_08033190: .4byte gSpriteRandomNumber
_08033194:
	mov r1, ip
	adds r1, #0x30
	movs r0, #0x3c
_0803319A:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterBugIdle
KihunterBugIdle: @ 0x080331A4
	push {r4, r5, r6, r7, lr}
	ldr r3, _0803321C @ =gCurrentSprite
	adds r5, r3, #0
	adds r5, #0x31
	ldrb r1, [r5]
	ldr r4, _08033220 @ =0x0833C104
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r6, _08033224 @ =0x00007FFF
	cmp r0, r6
	bne _080331C4
	ldrh r2, [r4]
	movs r1, #0
_080331C4:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	adds r5, r3, #0
	adds r5, #0x30
	ldrb r1, [r5]
	ldr r4, _08033228 @ =0x0833C186
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	bne _080331E8
	ldrh r2, [r4]
	movs r1, #0
_080331E8:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	ldr r2, _0803322C @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	bne _08033216
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	subs r1, #2
	movs r0, #4
	strb r0, [r1]
_08033216:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803321C: .4byte gCurrentSprite
_08033220: .4byte 0x0833C104
_08033224: .4byte 0x00007FFF
_08033228: .4byte 0x0833C186
_0803322C: .4byte gSpriteData

	thumb_func_start KihunterBugChasingSamusInit
KihunterBugChasingSamusInit: @ 0x08033230
	push {r4, lr}
	ldr r4, _08033270 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2f
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	movs r2, #1
	strb r2, [r0]
	subs r0, #2
	strb r1, [r0]
	adds r0, #3
	strb r2, [r0]
	strh r1, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldrh r2, [r4, #2]
	ldr r1, _08033274 @ =gSamusData
	movs r3, #0x26
	ldrsh r0, [r1, r3]
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	cmp r2, r0
	ble _0803327C
	ldrh r1, [r4]
	ldr r0, _08033278 @ =0x0000FBFF
	ands r0, r1
	b _08033286
	.align 2, 0
_08033270: .4byte gCurrentSprite
_08033274: .4byte gSamusData
_08033278: .4byte 0x0000FBFF
_0803327C:
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
_08033286:
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterBugChasingSamus
KihunterBugChasingSamus: @ 0x08033290
	push {r4, r5, r6, r7, lr}
	ldr r1, _080332B4 @ =gSamusData
	ldrh r0, [r1, #0x26]
	ldrh r2, [r1, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r3, [r1, #0x16]
	movs r7, #0x1e
	movs r6, #0x28
	ldr r0, _080332B8 @ =gCurrentSprite
	ldrh r1, [r0, #8]
	adds r2, r0, #0
	cmp r1, #1
	beq _080332BC
	cmp r1, #3
	beq _080332D6
	b _080332F8
	.align 2, 0
_080332B4: .4byte gSamusData
_080332B8: .4byte gCurrentSprite
_080332BC:
	adds r0, r5, #0
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080332F0
	adds r0, r3, #0
	subs r0, #0x30
	b _080332F4
_080332D6:
	adds r0, r5, #0
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080332F0
	adds r0, r3, #0
	subs r0, #0x30
	b _080332F4
_080332F0:
	adds r0, r3, #0
	adds r0, #0x30
_080332F4:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_080332F8:
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08033354
	movs r0, #0x2f
	adds r0, r0, r2
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803332E
	ldrh r1, [r2, #4]
	subs r0, r3, #4
	cmp r1, r0
	bgt _08033368
	adds r1, r2, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, r6
	bhs _08033328
	adds r0, #1
	strb r0, [r1]
_08033328:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	b _0803333E
_0803332E:
	subs r1, r0, #1
	mov r0, ip
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08033346
	lsrs r0, r0, #0x1a
_0803333E:
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	b _080333C2
_08033346:
	ldrh r1, [r2]
	ldr r0, _08033350 @ =0x0000FDFF
	ands r0, r1
	b _080333A8
	.align 2, 0
_08033350: .4byte 0x0000FDFF
_08033354:
	movs r0, #0x2f
	adds r0, r0, r2
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08033388
	ldrh r1, [r2, #4]
	adds r0, r3, #4
	cmp r1, r0
	bge _08033374
_08033368:
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	mov r1, ip
	strb r0, [r1]
	b _080333C2
_08033374:
	adds r1, r2, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, r6
	bhs _08033382
	adds r0, #1
	strb r0, [r1]
_08033382:
	ldrb r1, [r1]
	lsrs r1, r1, #2
	b _0803339A
_08033388:
	subs r1, r0, #1
	mov r0, ip
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080333A2
	adds r1, r0, #0
	lsrs r1, r1, #0x1a
_0803339A:
	ldrh r0, [r2, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	b _080333C2
_080333A2:
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
_080333A8:
	strh r0, [r2]
	adds r1, r2, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080333C2
	strh r3, [r2, #8]
_080333C2:
	adds r3, r2, #0
	ldrh r4, [r3]
	movs r6, #0x80
	lsls r6, r6, #3
	adds r0, r6, #0
	ands r0, r4
	cmp r0, #0
	beq _08033428
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #0
	bne _08033406
	ldrh r1, [r3, #2]
	subs r0, r5, #4
	cmp r1, r0
	ble _080333EC
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r0, [r0]
	strb r0, [r2]
	b _08033482
_080333EC:
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, r7
	bhs _080333FA
	adds r0, #1
	strb r0, [r1]
_080333FA:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _08033482
_08033406:
	subs r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0803341A
	lsrs r0, r0, #0x1a
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	b _08033482
_0803341A:
	ldr r0, _08033424 @ =0x0000FBFF
	ands r0, r4
	strh r0, [r3]
	adds r1, r3, #0
	b _0803347C
	.align 2, 0
_08033424: .4byte 0x0000FBFF
_08033428:
	movs r0, #0x2e
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803345A
	ldrh r1, [r3, #2]
	adds r0, r5, #4
	cmp r1, r0
	bge _08033446
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r0, [r0]
	mov r1, ip
	b _08033480
_08033446:
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, r7
	bhs _08033454
	adds r0, #1
	strb r0, [r1]
_08033454:
	ldrb r1, [r1]
	lsrs r1, r1, #2
	b _0803346A
_0803345A:
	subs r1, r0, #1
	mov r0, ip
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _08033472
	adds r1, r0, #0
	lsrs r1, r1, #0x1a
_0803346A:
	ldrh r0, [r3, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	b _08033482
_08033472:
	ldrh r1, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	adds r1, r2, #0
_0803347C:
	adds r1, #0x31
	movs r0, #1
_08033480:
	strb r0, [r1]
_08033482:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start KihunterGround
KihunterGround: @ 0x08033488
	push {r4, r5, r6, lr}
	ldr r4, _080334B4 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2c
	ldrb r1, [r5]
	movs r6, #0x7f
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #4
	bne _080334A4
	movs r0, #0xba
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080334A4:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080334B8
	bl SpriteUtilUpdateFreezeTimer
	b _080336C6
	.align 2, 0
_080334B4: .4byte gCurrentSprite
_080334B8:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5a
	bhi _080334E0
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080334E0
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080334E0
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
_080334E0:
	ldr r0, _080334F8 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _080334EC
	b _080336C6
_080334EC:
	lsls r0, r0, #2
	ldr r1, _080334FC @ =_08033500
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080334F8: .4byte gCurrentSprite
_080334FC: .4byte _08033500
_08033500: @ jump table
	.4byte _08033670 @ case 0
	.4byte _08033676 @ case 1
	.4byte _0803367A @ case 2
	.4byte _080336C6 @ case 3
	.4byte _08033692 @ case 4
	.4byte _08033698 @ case 5
	.4byte _080336C6 @ case 6
	.4byte _080336C6 @ case 7
	.4byte _0803368C @ case 8
	.4byte _080336C6 @ case 9
	.4byte _080336C6 @ case 10
	.4byte _080336C6 @ case 11
	.4byte _080336C6 @ case 12
	.4byte _080336C6 @ case 13
	.4byte _080336C6 @ case 14
	.4byte _080336C6 @ case 15
	.4byte _080336C6 @ case 16
	.4byte _080336C6 @ case 17
	.4byte _080336C6 @ case 18
	.4byte _080336C6 @ case 19
	.4byte _080336C6 @ case 20
	.4byte _080336C6 @ case 21
	.4byte _080336A4 @ case 22
	.4byte _080336C6 @ case 23
	.4byte _08033680 @ case 24
	.4byte _080336C6 @ case 25
	.4byte _08033686 @ case 26
	.4byte _080336C6 @ case 27
	.4byte _080336C6 @ case 28
	.4byte _080336C6 @ case 29
	.4byte _080336C6 @ case 30
	.4byte _080336C6 @ case 31
	.4byte _080336C6 @ case 32
	.4byte _080336C6 @ case 33
	.4byte _080336C6 @ case 34
	.4byte _080336C6 @ case 35
	.4byte _080336C6 @ case 36
	.4byte _080336C6 @ case 37
	.4byte _080336C6 @ case 38
	.4byte _080336C6 @ case 39
	.4byte _080336C6 @ case 40
	.4byte _080336C6 @ case 41
	.4byte _0803369E @ case 42
	.4byte _080336C6 @ case 43
	.4byte _080336C6 @ case 44
	.4byte _080336C6 @ case 45
	.4byte _080336C6 @ case 46
	.4byte _080336C6 @ case 47
	.4byte _080336C6 @ case 48
	.4byte _080336C6 @ case 49
	.4byte _080336C6 @ case 50
	.4byte _080336C6 @ case 51
	.4byte _080336C6 @ case 52
	.4byte _080336C6 @ case 53
	.4byte _080336C6 @ case 54
	.4byte _080336C6 @ case 55
	.4byte _080336C6 @ case 56
	.4byte _080336C6 @ case 57
	.4byte _080336C6 @ case 58
	.4byte _080336C6 @ case 59
	.4byte _080336C6 @ case 60
	.4byte _080336C6 @ case 61
	.4byte _080336C6 @ case 62
	.4byte _080336C6 @ case 63
	.4byte _080336C6 @ case 64
	.4byte _080336C6 @ case 65
	.4byte _080336C6 @ case 66
	.4byte _080336C6 @ case 67
	.4byte _080336C6 @ case 68
	.4byte _080336C6 @ case 69
	.4byte _080336C6 @ case 70
	.4byte _080336C6 @ case 71
	.4byte _080336C6 @ case 72
	.4byte _080336C6 @ case 73
	.4byte _080336C6 @ case 74
	.4byte _080336C6 @ case 75
	.4byte _080336C6 @ case 76
	.4byte _080336C6 @ case 77
	.4byte _080336C6 @ case 78
	.4byte _080336C6 @ case 79
	.4byte _080336C6 @ case 80
	.4byte _080336C6 @ case 81
	.4byte _080336C6 @ case 82
	.4byte _080336C6 @ case 83
	.4byte _080336C6 @ case 84
	.4byte _080336C6 @ case 85
	.4byte _080336C6 @ case 86
	.4byte _080336AA @ case 87
	.4byte _080336AE @ case 88
	.4byte _080336B4 @ case 89
	.4byte _080336B8 @ case 90
	.4byte _080336BE @ case 91
_08033670:
	bl KihunterGroundInit
	b _080336C6
_08033676:
	bl KihunterGroundJumpWarningInit
_0803367A:
	bl kihunterGroundJumpWarning
	b _080336C6
_08033680:
	bl KihunterGroundJumping
	b _080336C6
_08033686:
	bl KihunterGroundLanding
	b _080336C6
_0803368C:
	bl KihunterGroundIdle
	b _080336C6
_08033692:
	bl KihunterGroundTurningAround
	b _080336C6
_08033698:
	bl KihunterGroundTurningAroundSecondPart
	b _080336C6
_0803369E:
	bl KihunterGroundSpitting
	b _080336C6
_080336A4:
	bl KihunterGroundFalling
	b _080336C6
_080336AA:
	bl SpriteDyingInit
_080336AE:
	bl SpriteDying
	b _080336C6
_080336B4:
	bl KihunterGroundInit
_080336B8:
	bl SpriteSpawningFromX
	b _080336C6
_080336BE:
	bl KihunterTurningIntoX
	bl XParasiteInit
_080336C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start KihunterFlying
KihunterFlying: @ 0x080336CC
	push {r4, lr}
	ldr r4, _08033704 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _080336E6
	movs r0, #0xba
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080336E6:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033708
	bl SpriteUtilUpdateFreezeTimer
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x10
	bl SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent
	b _08033918
	.align 2, 0
_08033704: .4byte gCurrentSprite
_08033708:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08033714
	b _080338FE
_08033714:
	lsls r0, r0, #2
	ldr r1, _08033720 @ =_08033724
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08033720: .4byte _08033724
_08033724: @ jump table
	.4byte _08033894 @ case 0
	.4byte _0803389A @ case 1
	.4byte _0803389E @ case 2
	.4byte _080338A4 @ case 3
	.4byte _080338A8 @ case 4
	.4byte _080338AE @ case 5
	.4byte _080338FE @ case 6
	.4byte _080338FE @ case 7
	.4byte _080338FE @ case 8
	.4byte _080338FE @ case 9
	.4byte _080338FE @ case 10
	.4byte _080338FE @ case 11
	.4byte _080338FE @ case 12
	.4byte _080338FE @ case 13
	.4byte _080338FE @ case 14
	.4byte _080338FE @ case 15
	.4byte _080338FE @ case 16
	.4byte _080338FE @ case 17
	.4byte _080338FE @ case 18
	.4byte _080338FE @ case 19
	.4byte _080338FE @ case 20
	.4byte _080338FE @ case 21
	.4byte _080338FE @ case 22
	.4byte _080338FE @ case 23
	.4byte _080338FE @ case 24
	.4byte _080338FE @ case 25
	.4byte _080338FE @ case 26
	.4byte _080338FE @ case 27
	.4byte _080338FE @ case 28
	.4byte _080338FE @ case 29
	.4byte _080338FE @ case 30
	.4byte _080338FE @ case 31
	.4byte _080338FE @ case 32
	.4byte _080338FE @ case 33
	.4byte _080338FE @ case 34
	.4byte _080338FE @ case 35
	.4byte _080338FE @ case 36
	.4byte _080338FE @ case 37
	.4byte _080338FE @ case 38
	.4byte _080338FE @ case 39
	.4byte _080338FE @ case 40
	.4byte _080338B4 @ case 41
	.4byte _080338B8 @ case 42
	.4byte _080338BE @ case 43
	.4byte _080338C2 @ case 44
	.4byte _080338C8 @ case 45
	.4byte _080338CC @ case 46
	.4byte _080338FE @ case 47
	.4byte _080338FE @ case 48
	.4byte _080338FE @ case 49
	.4byte _080338FE @ case 50
	.4byte _080338FE @ case 51
	.4byte _080338FE @ case 52
	.4byte _080338FE @ case 53
	.4byte _080338FE @ case 54
	.4byte _080338FE @ case 55
	.4byte _080338FE @ case 56
	.4byte _080338FE @ case 57
	.4byte _080338FE @ case 58
	.4byte _080338FE @ case 59
	.4byte _080338FE @ case 60
	.4byte _080338FE @ case 61
	.4byte _080338FE @ case 62
	.4byte _080338FE @ case 63
	.4byte _080338FE @ case 64
	.4byte _080338FE @ case 65
	.4byte _080338FE @ case 66
	.4byte _080338FE @ case 67
	.4byte _080338FE @ case 68
	.4byte _080338FE @ case 69
	.4byte _080338FE @ case 70
	.4byte _080338FE @ case 71
	.4byte _080338FE @ case 72
	.4byte _080338FE @ case 73
	.4byte _080338FE @ case 74
	.4byte _080338FE @ case 75
	.4byte _080338FE @ case 76
	.4byte _080338FE @ case 77
	.4byte _080338FE @ case 78
	.4byte _080338FE @ case 79
	.4byte _080338FE @ case 80
	.4byte _080338FE @ case 81
	.4byte _080338FE @ case 82
	.4byte _080338FE @ case 83
	.4byte _080338FE @ case 84
	.4byte _080338FE @ case 85
	.4byte _080338FE @ case 86
	.4byte _080338D2 @ case 87
	.4byte _080338E2 @ case 88
	.4byte _080338EC @ case 89
	.4byte _080338F0 @ case 90
	.4byte _080338F6 @ case 91
_08033894:
	bl KihunterFlyingInit
	b _080338FE
_0803389A:
	bl KihunterFlyingIdleInit
_0803389E:
	bl KihunterFlyingIdle
	b _080338FE
_080338A4:
	bl KihunterFlyingTurningAroundInit
_080338A8:
	bl KihunterTurningAround
	b _080338FE
_080338AE:
	bl KihunterFlyingTurningAroundSecondPart
	b _080338FE
_080338B4:
	bl KihunterFlyingSwoopingDownInit
_080338B8:
	bl KihunterFlyingSwoopingDown
	b _080338FE
_080338BE:
	bl KihunterFlyingSwoopingAcrossInit
_080338C2:
	bl KihunterFlyingSwoopingAcross
	b _080338FE
_080338C8:
	bl KihunterFlyingAfterSwoopingInit
_080338CC:
	bl KihunterFlyingAfterSwooping
	b _080338FE
_080338D2:
	ldr r0, _080338E8 @ =gCurrentSprite
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x10
	bl SpriteUtilUnfreezeSecondarySprites
	bl SpriteDyingInit
_080338E2:
	bl SpriteDying
	b _080338FE
	.align 2, 0
_080338E8: .4byte gCurrentSprite
_080338EC:
	bl KihunterFlyingInit
_080338F0:
	bl SpriteSpawningFromX
	b _080338FE
_080338F6:
	bl KihunterTurningIntoX
	bl XParasiteInit
_080338FE:
	ldr r2, _08033920 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x24
	ldrb r0, [r3]
	cmp r0, #0x56
	bhi _08033918
	ldrh r0, [r2, #0x14]
	cmp r0, #6
	bhi _08033918
	movs r1, #0
	movs r0, #0x5c
	strb r0, [r2, #0x1d]
	strb r1, [r3]
_08033918:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033920: .4byte gCurrentSprite

	thumb_func_start KihunterWings
KihunterWings: @ 0x08033924
	push {lr}
	ldr r1, _08033940 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x26
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033944
	bl SpriteUtilUpdateFreezeTimer
	b _0803397A
	.align 2, 0
_08033940: .4byte gCurrentSprite
_08033944:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	beq _0803396C
	cmp r0, #0x3a
	bgt _0803395C
	cmp r0, #0
	beq _08033972
	cmp r0, #0x38
	beq _08033966
	b _08033976
_0803395C:
	cmp r0, #0x58
	bne _08033976
	bl SpriteDying
	b _0803397A
_08033966:
	bl KihunterWingsFalling
	b _0803397A
_0803396C:
	bl KihunterWingsDisappearing
	b _0803397A
_08033972:
	bl KihunterWingsInit
_08033976:
	bl KihunterWingsIdle
_0803397A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterSpit
KihunterSpit: @ 0x08033980
	push {lr}
	ldr r0, _08033998 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _080339A6
	cmp r0, #2
	bgt _0803399C
	cmp r0, #0
	beq _080339A2
	b _080339B2
	.align 2, 0
_08033998: .4byte gCurrentSprite
_0803399C:
	cmp r0, #0x38
	beq _080339AC
	b _080339B2
_080339A2:
	bl KihunterSpitInit
_080339A6:
	bl KihunterSpitMoving
	b _080339B6
_080339AC:
	bl KihunterSpitExploding
	b _080339B6
_080339B2:
	bl KihunterSpitExplodingInit
_080339B6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start KihunterHive
KihunterHive: @ 0x080339BC
	push {lr}
	ldr r0, _080339D4 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x59
	beq _080339E4
	cmp r0, #0x59
	bgt _080339D8
	cmp r0, #0
	beq _080339DE
	b _080339EE
	.align 2, 0
_080339D4: .4byte gCurrentSprite
_080339D8:
	cmp r0, #0x5a
	beq _080339EA
	b _080339EE
_080339DE:
	bl KihunterHiveInit
	b _080339EE
_080339E4:
	bl KihunterHiveSpawnKihunter
	b _080339EE
_080339EA:
	bl KihunterHiveSpawnCooldown
_080339EE:
	ldr r1, _080339FC @ =gCurrentSprite
	ldrh r0, [r1, #2]
	ldrh r1, [r1, #4]
	bl unk_120ac
	pop {r0}
	bx r0
	.align 2, 0
_080339FC: .4byte gCurrentSprite

	thumb_func_start KihunterBug
KihunterBug: @ 0x08033A00
	push {lr}
	ldr r0, _08033A20 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08033A32
	cmp r0, #2
	bgt _08033A24
	cmp r0, #0
	beq _08033A2E
	b _08033A40
	.align 2, 0
_08033A20: .4byte gCurrentSprite
_08033A24:
	cmp r0, #0x17
	beq _08033A38
	cmp r0, #0x18
	beq _08033A3C
	b _08033A40
_08033A2E:
	bl KihunterBugInit
_08033A32:
	bl KihunterBugIdle
	b _08033A40
_08033A38:
	bl KihunterBugChasingSamusInit
_08033A3C:
	bl KihunterBugChasingSamus
_08033A40:
	pop {r0}
	bx r0

	thumb_func_start ReoPlaySound
ReoPlaySound: @ 0x08033A44
	push {lr}
	ldr r0, _08033A60 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08033A5A
	movs r0, #0xc1
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08033A5A:
	pop {r0}
	bx r0
	.align 2, 0
_08033A60: .4byte gFrameCounter8Bit

	thumb_func_start ReoCheckFall
ReoCheckFall: @ 0x08033A64
	push {lr}
	ldr r2, _08033A8C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bls _08033A90
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08033A90
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	movs r0, #1
	b _08033A92
	.align 2, 0
_08033A8C: .4byte gCurrentSprite
_08033A90:
	movs r0, #0
_08033A92:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ReoXMovement
ReoXMovement: @ 0x08033A98
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r5, #0
	ldr r4, _08033AC8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08033AD0
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08033ACC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08033AE4
	ldrh r0, [r4, #4]
	adds r0, r5, r0
	b _08033AF0
	.align 2, 0
_08033AC8: .4byte gCurrentSprite
_08033ACC: .4byte gPreviousCollisionCheck
_08033AD0:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08033AE8 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08033AEC
_08033AE4:
	movs r0, #1
	b _08033AF4
	.align 2, 0
_08033AE8: .4byte gPreviousCollisionCheck
_08033AEC:
	ldrh r0, [r4, #4]
	subs r0, r0, r6
_08033AF0:
	strh r0, [r4, #4]
	movs r0, #0
_08033AF4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ReoInit
ReoInit: @ 0x08033AFC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08033B28 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08033B40
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08033B2C
	strh r0, [r2]
	b _08033BFC
	.align 2, 0
_08033B28: .4byte gCurrentSprite
_08033B2C:
	ldr r0, _08033B3C @ =0x0000FFC0
	strh r0, [r2, #0xa]
	movs r1, #0x28
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	movs r0, #0x40
	b _08033B4E
	.align 2, 0
_08033B3C: .4byte 0x0000FFC0
_08033B40:
	ldr r0, _08033BAC @ =0x0000FFC8
	strh r0, [r2, #0xa]
	movs r0, #0x18
	strh r0, [r2, #0xc]
	ldr r0, _08033BB0 @ =0x0000FFD8
	strh r0, [r2, #0xe]
	movs r0, #0x28
_08033B4E:
	strh r0, [r2, #0x10]
	ldr r5, _08033BB4 @ =gCurrentSprite
	adds r1, r5, #0
	adds r1, #0x27
	movs r6, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08033BB8 @ =0x0833F128
	str r0, [r5, #0x18]
	strb r6, [r5, #0x1c]
	movs r0, #0
	strh r6, [r5, #0x16]
	adds r1, #5
	strb r0, [r1]
	adds r1, #3
	strb r0, [r1]
	ldr r2, _08033BBC @ =sPrimarySpriteStats
	ldrb r1, [r5, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	bl SpriteUtilMakeSpriteFaceSamusDirection
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _08033BC0
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r5, #6]
	b _08033BFC
	.align 2, 0
_08033BAC: .4byte 0x0000FFC8
_08033BB0: .4byte 0x0000FFD8
_08033BB4: .4byte gCurrentSprite
_08033BB8: .4byte 0x0833F128
_08033BBC: .4byte sPrimarySpriteStats
_08033BC0:
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r5, #2]
	strh r0, [r5, #8]
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	ldrh r4, [r5]
	movs r0, #0x40
	ands r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0x2c
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	bne _08033BF6
	strh r6, [r5]
_08033BF6:
	adds r0, r5, #0
	adds r0, #0x2f
	strb r2, [r0]
_08033BFC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ReoFallInit
ReoFallInit: @ 0x08033C04
	ldr r3, _08033C38 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x38
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	ldr r0, _08033C3C @ =0x0833F178
	str r0, [r3, #0x18]
	adds r0, r3, #0
	adds r0, #0x31
	strb r1, [r0]
	ldr r2, _08033C40 @ =gSpriteData
	subs r0, #2
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r2, #4
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08033C38: .4byte gCurrentSprite
_08033C3C: .4byte 0x0833F178
_08033C40: .4byte gSpriteData

	thumb_func_start ReoFalling
ReoFalling: @ 0x08033C44
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r4, _08033CA4 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldr r5, _08033CA8 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _08033C8E
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08033C8E
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r7, [r4, #4]
	adds r1, r1, r7
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r2, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08033C8A
	movs r6, #1
_08033C8A:
	cmp r6, #0
	beq _08033CAC
_08033C8E:
	ldr r1, _08033CA4 @ =gCurrentSprite
	strh r2, [r1, #2]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x3a
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	b _08033CEC
	.align 2, 0
_08033CA4: .4byte gCurrentSprite
_08033CA8: .4byte gPreviousVerticalCollisionCheck
_08033CAC:
	adds r3, r4, #0
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _08033CD8 @ =sSpritesFallingSpeedQuickAcceleration
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08033CDC @ =0x00007FFF
	cmp r1, r0
	bne _08033CE0
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #2]
	b _08033CEC
	.align 2, 0
_08033CD8: .4byte sSpritesFallingSpeedQuickAcceleration
_08033CDC: .4byte 0x00007FFF
_08033CE0:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
_08033CEC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ReoLanding
ReoLanding: @ 0x08033CF4
	push {lr}
	ldr r3, _08033D34 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08033D30
	subs r1, #0xa
	movs r0, #0x2d
	strb r0, [r1]
	ldr r0, _08033D38 @ =0x0833F128
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r2, _08033D3C @ =gSpriteData
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r2, [r1]
	ldr r0, _08033D40 @ =0x0000FFFB
	ands r0, r2
	strh r0, [r1]
_08033D30:
	pop {r0}
	bx r0
	.align 2, 0
_08033D34: .4byte gCurrentSprite
_08033D38: .4byte 0x0833F128
_08033D3C: .4byte gSpriteData
_08033D40: .4byte 0x0000FFFB

	thumb_func_start ReoIdleInit
ReoIdleInit: @ 0x08033D44
	ldr r3, _08033D68 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	ldr r0, _08033D6C @ =0x0833F128
	str r0, [r3, #0x18]
	adds r0, r3, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08033D68: .4byte gCurrentSprite
_08033D6C: .4byte 0x0833F128

	thumb_func_start ReoIdle
ReoIdle: @ 0x08033D70
	push {r4, r5, r6, r7, lr}
	ldr r4, _08033E2C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08033E52
	bl ReoCheckFall
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033E52
	adds r6, r4, #0
	adds r6, #0x30
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _08033E30 @ =0x0833E724
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08033E34 @ =0x00007FFF
	cmp r1, r0
	bne _08033DB2
	ldrh r3, [r5]
	movs r2, #0
_08033DB2:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	movs r0, #2
	bl ReoXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033DD0
	ldrb r0, [r6]
	cmp r0, #0x20
	bls _08033DE0
_08033DD0:
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r4]
	movs r0, #0
	strb r0, [r6]
_08033DE0:
	ldr r6, _08033E2C @ =gCurrentSprite
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x2f
	bne _08033E52
	ldr r7, _08033E38 @ =gSamusData
	ldrh r5, [r7, #0x18]
	ldrh r4, [r6, #2]
	subs r4, #0x60
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0xa0
	lsls r0, r0, #2
	movs r1, #0xf0
	lsls r1, r1, #2
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, r4
	bhs _08033E0E
	movs r0, #0
_08033E0E:
	cmp r0, #0
	beq _08033E52
	ldrh r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08033E3C
	ldrh r0, [r6, #4]
	ldrh r7, [r7, #0x16]
	cmp r0, r7
	bls _08033E4A
	b _08033E44
	.align 2, 0
_08033E2C: .4byte gCurrentSprite
_08033E30: .4byte 0x0833E724
_08033E34: .4byte 0x00007FFF
_08033E38: .4byte gSamusData
_08033E3C:
	ldrh r0, [r6, #4]
	ldrh r7, [r7, #0x16]
	cmp r0, r7
	bhs _08033E4A
_08033E44:
	adds r0, r2, #0
	eors r0, r1
	strh r0, [r6]
_08033E4A:
	ldr r0, _08033E58 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x29
	strb r1, [r0]
_08033E52:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033E58: .4byte gCurrentSprite

	thumb_func_start ReoGoingDownInit
ReoGoingDownInit: @ 0x08033E5C
	ldr r2, _08033E78 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	movs r1, #0
	movs r0, #8
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x31
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bx lr
	.align 2, 0
_08033E78: .4byte gCurrentSprite

	thumb_func_start ReoGoingDown
ReoGoingDown: @ 0x08033E7C
	push {r4, r5, r6, r7, lr}
	bl ReoCheckFall
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033F36
	bl ReoPlaySound
	ldr r4, _08033ECC @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08033ED0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _08033ED4
	movs r0, #3
	bl ReoXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08033EB4
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2d
	strb r0, [r1]
_08033EB4:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033F36
	subs r1, #0xa
	movs r0, #0x2d
	strb r0, [r1]
	b _08033F36
	.align 2, 0
_08033ECC: .4byte gCurrentSprite
_08033ED0: .4byte gPreviousCollisionCheck
_08033ED4:
	adds r6, r4, #0
	adds r6, #0x31
	ldrb r0, [r6]
	lsrs r0, r0, #2
	cmp r0, #4
	bls _08033EE2
	movs r0, #6
_08033EE2:
	bl ReoXMovement
	ldrh r0, [r4, #2]
	adds r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _08033F00
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2b
	strb r0, [r1]
	b _08033F36
_08033F00:
	ldrb r2, [r6]
	ldr r5, _08033F24 @ =0x0833E786
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08033F28 @ =0x00007FFF
	cmp r1, r0
	bne _08033F2C
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08033F34
	.align 2, 0
_08033F24: .4byte 0x0833E786
_08033F28: .4byte 0x00007FFF
_08033F2C:
	adds r0, r2, #1
	strb r0, [r6]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
_08033F34:
	strh r0, [r4, #2]
_08033F36:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ReoSlidingInit
ReoSlidingInit: @ 0x08033F3C
	ldr r2, _08033F58 @ =gCurrentSprite
	adds r3, r2, #0
	adds r3, #0x2e
	movs r1, #0
	movs r0, #8
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x31
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	bx lr
	.align 2, 0
_08033F58: .4byte gCurrentSprite

	thumb_func_start ReoSliding
ReoSliding: @ 0x08033F5C
	push {r4, r5, r6, r7, lr}
	bl ReoCheckFall
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08034016
	bl ReoPlaySound
	movs r0, #6
	bl ReoXMovement
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _08033FB0 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _08033FB4 @ =gPreviousCollisionCheck
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _08033FB8
	cmp r6, #0
	beq _08033F98
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2d
	strb r0, [r1]
_08033F98:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034016
	subs r1, #0xa
	movs r0, #0x2d
	b _08034014
	.align 2, 0
_08033FB0: .4byte gCurrentSprite
_08033FB4: .4byte gPreviousCollisionCheck
_08033FB8:
	ldrh r0, [r4, #2]
	adds r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _08034004
	adds r6, r4, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _08033FF0 @ =0x0833E79E
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08033FF4 @ =0x00007FFF
	cmp r1, r0
	bne _08033FF8
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #2]
	b _08034016
	.align 2, 0
_08033FF0: .4byte 0x0833E79E
_08033FF4: .4byte 0x00007FFF
_08033FF8:
	adds r0, r2, #1
	strb r0, [r6]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	b _08034016
_08034004:
	adds r0, r4, #0
	adds r0, #0x2e
	strb r5, [r0]
	adds r0, #3
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2a
_08034014:
	strb r0, [r1]
_08034016:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ReoGoingUpInit
ReoGoingUpInit: @ 0x0803401C
	ldr r1, _08034034 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #0
	strb r0, [r2]
	adds r2, #3
	strb r0, [r2]
	adds r1, #0x24
	movs r0, #0x2e
	strb r0, [r1]
	bx lr
	.align 2, 0
_08034034: .4byte gCurrentSprite

	thumb_func_start ReoGoingUp
ReoGoingUp: @ 0x08034038
	push {r4, r5, r6, r7, lr}
	bl ReoCheckFall
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803411C
	bl ReoPlaySound
	ldr r4, _080340A0 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080340A4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08034114
	adds r7, r4, #0
	adds r7, #0x2e
	ldrb r5, [r7]
	cmp r5, #0
	bne _080340CA
	movs r0, #6
	bl ReoXMovement
	ldrh r0, [r4, #8]
	adds r0, #0x60
	ldrh r6, [r4, #2]
	cmp r0, r6
	bge _080340BE
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _080340A8 @ =0x0833E7BE
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _080340AC @ =0x00007FFF
	cmp r1, r0
	bne _080340B0
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	adds r0, r6, r3
	strh r0, [r4, #2]
	b _0803411C
	.align 2, 0
_080340A0: .4byte gCurrentSprite
_080340A4: .4byte gPreviousCollisionCheck
_080340A8: .4byte 0x0833E7BE
_080340AC: .4byte 0x00007FFF
_080340B0:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	b _0803411C
_080340BE:
	movs r0, #1
	strb r0, [r7]
	adds r0, r4, #0
	adds r0, #0x31
	strb r5, [r0]
	b _0803411C
_080340CA:
	movs r0, #3
	bl ReoXMovement
	ldrh r3, [r4, #2]
	ldrh r0, [r4, #8]
	cmp r0, r3
	bhs _08034114
	adds r7, r4, #0
	adds r7, #0x31
	ldrb r2, [r7]
	ldr r6, _08034100 @ =0x0833E7D6
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	mov ip, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _08034104 @ =0x00007FFF
	cmp r1, r0
	bne _08034108
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	adds r0, r3, r0
	strh r0, [r4, #2]
	b _0803411C
	.align 2, 0
_08034100: .4byte 0x0833E7D6
_08034104: .4byte 0x00007FFF
_08034108:
	adds r0, r2, #1
	strb r0, [r7]
	mov r7, ip
	adds r0, r3, r7
	strh r0, [r4, #2]
	b _0803411C
_08034114:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_0803411C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ReoWingsInit
ReoWingsInit: @ 0x08034124
	push {r4, lr}
	ldr r0, _080341A0 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _080341A4 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803414C
	mov r4, ip
	ldrh r1, [r4]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r4]
_0803414C:
	mov r0, ip
	ldrh r1, [r0]
	ldr r0, _080341A8 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r1, #0x27
	movs r0, #0x18
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x10
	strb r0, [r1]
	ldr r1, _080341AC @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	subs r1, #2
	movs r0, #5
	strb r0, [r1]
	ldr r0, _080341B0 @ =0x0833F150
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080341A0: .4byte gCurrentSprite
_080341A4: .4byte gSpriteData
_080341A8: .4byte 0x0000FFFB
_080341AC: .4byte 0x0000FFFC
_080341B0: .4byte 0x0833F150

	thumb_func_start ReoWingsIdle
ReoWingsIdle: @ 0x080341B4
	push {r4, r5, r6, lr}
	ldr r1, _080341F0 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r5, [r0]
	ldr r2, _080341F4 @ =gSpriteData
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r3, r0, r2
	ldrh r0, [r3, #2]
	strh r0, [r1, #2]
	ldrh r0, [r3, #4]
	strh r0, [r1, #4]
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #0x57
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r1, #0
	adds r6, r2, #0
	cmp r0, #1
	bhi _080341F8
	bl SpriteDyingInit
	bl SpriteDying
	b _08034260
	.align 2, 0
_080341F0: .4byte gCurrentSprite
_080341F4: .4byte gSpriteData
_080341F8:
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803420A
	ldrh r0, [r4]
	movs r1, #0x20
	orrs r0, r1
	b _08034210
_0803420A:
	ldrh r1, [r4]
	ldr r0, _0803422C @ =0x0000FFDF
	ands r0, r1
_08034210:
	strh r0, [r4]
	lsls r2, r5, #3
	subs r0, r2, r5
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08034230
	ldrh r1, [r4]
	movs r0, #0x40
	orrs r0, r1
	b _08034236
	.align 2, 0
_0803422C: .4byte 0x0000FFDF
_08034230:
	ldrh r1, [r4]
	ldr r0, _08034254 @ =0x0000FFBF
	ands r0, r1
_08034236:
	strh r0, [r4]
	subs r0, r2, r5
	lsls r0, r0, #3
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08034258
	ldrh r1, [r4]
	adds r0, r2, #0
	orrs r0, r1
	b _0803425E
	.align 2, 0
_08034254: .4byte 0x0000FFBF
_08034258:
	ldrh r1, [r4]
	ldr r0, _08034268 @ =0x0000DFFF
	ands r0, r1
_0803425E:
	strh r0, [r4]
_08034260:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034268: .4byte 0x0000DFFF

	thumb_func_start Reo
Reo: @ 0x0803426C
	push {r4, lr}
	ldr r4, _080342A0 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08034284
	ldr r0, _080342A4 @ =0x00000183
	bl SoundPlayNotAlreadyPlaying
_08034284:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080342A8
	bl SpriteUtilUpdateFreezeTimer
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x2c
	bl SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent
	b _080344A2
	.align 2, 0
_080342A0: .4byte gCurrentSprite
_080342A4: .4byte 0x00000183
_080342A8:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _080342B4
	b _080344A2
_080342B4:
	lsls r0, r0, #2
	ldr r1, _080342C0 @ =_080342C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080342C0: .4byte _080342C4
_080342C4: @ jump table
	.4byte _08034434 @ case 0
	.4byte _0803443A @ case 1
	.4byte _0803443E @ case 2
	.4byte _080344A2 @ case 3
	.4byte _080344A2 @ case 4
	.4byte _080344A2 @ case 5
	.4byte _080344A2 @ case 6
	.4byte _080344A2 @ case 7
	.4byte _080344A2 @ case 8
	.4byte _080344A2 @ case 9
	.4byte _080344A2 @ case 10
	.4byte _080344A2 @ case 11
	.4byte _080344A2 @ case 12
	.4byte _080344A2 @ case 13
	.4byte _080344A2 @ case 14
	.4byte _080344A2 @ case 15
	.4byte _080344A2 @ case 16
	.4byte _080344A2 @ case 17
	.4byte _080344A2 @ case 18
	.4byte _080344A2 @ case 19
	.4byte _080344A2 @ case 20
	.4byte _080344A2 @ case 21
	.4byte _080344A2 @ case 22
	.4byte _080344A2 @ case 23
	.4byte _080344A2 @ case 24
	.4byte _080344A2 @ case 25
	.4byte _080344A2 @ case 26
	.4byte _080344A2 @ case 27
	.4byte _080344A2 @ case 28
	.4byte _080344A2 @ case 29
	.4byte _080344A2 @ case 30
	.4byte _080344A2 @ case 31
	.4byte _080344A2 @ case 32
	.4byte _080344A2 @ case 33
	.4byte _080344A2 @ case 34
	.4byte _080344A2 @ case 35
	.4byte _080344A2 @ case 36
	.4byte _080344A2 @ case 37
	.4byte _080344A2 @ case 38
	.4byte _080344A2 @ case 39
	.4byte _080344A2 @ case 40
	.4byte _08034454 @ case 41
	.4byte _08034458 @ case 42
	.4byte _0803445E @ case 43
	.4byte _08034462 @ case 44
	.4byte _08034468 @ case 45
	.4byte _0803446C @ case 46
	.4byte _080344A2 @ case 47
	.4byte _080344A2 @ case 48
	.4byte _080344A2 @ case 49
	.4byte _080344A2 @ case 50
	.4byte _080344A2 @ case 51
	.4byte _080344A2 @ case 52
	.4byte _080344A2 @ case 53
	.4byte _080344A2 @ case 54
	.4byte _08034444 @ case 55
	.4byte _08034448 @ case 56
	.4byte _080344A2 @ case 57
	.4byte _0803444E @ case 58
	.4byte _080344A2 @ case 59
	.4byte _080344A2 @ case 60
	.4byte _080344A2 @ case 61
	.4byte _080344A2 @ case 62
	.4byte _080344A2 @ case 63
	.4byte _080344A2 @ case 64
	.4byte _080344A2 @ case 65
	.4byte _080344A2 @ case 66
	.4byte _080344A2 @ case 67
	.4byte _080344A2 @ case 68
	.4byte _080344A2 @ case 69
	.4byte _080344A2 @ case 70
	.4byte _080344A2 @ case 71
	.4byte _080344A2 @ case 72
	.4byte _080344A2 @ case 73
	.4byte _080344A2 @ case 74
	.4byte _080344A2 @ case 75
	.4byte _080344A2 @ case 76
	.4byte _080344A2 @ case 77
	.4byte _080344A2 @ case 78
	.4byte _080344A2 @ case 79
	.4byte _080344A2 @ case 80
	.4byte _080344A2 @ case 81
	.4byte _080344A2 @ case 82
	.4byte _080344A2 @ case 83
	.4byte _080344A2 @ case 84
	.4byte _080344A2 @ case 85
	.4byte _080344A2 @ case 86
	.4byte _08034472 @ case 87
	.4byte _08034482 @ case 88
	.4byte _0803448C @ case 89
	.4byte _08034490 @ case 90
	.4byte _08034496 @ case 91
_08034434:
	bl ReoInit
	b _080344A2
_0803443A:
	bl ReoIdleInit
_0803443E:
	bl ReoIdle
	b _080344A2
_08034444:
	bl ReoFallInit
_08034448:
	bl ReoFalling
	b _080344A2
_0803444E:
	bl ReoLanding
	b _080344A2
_08034454:
	bl ReoGoingDownInit
_08034458:
	bl ReoGoingDown
	b _080344A2
_0803445E:
	bl ReoSlidingInit
_08034462:
	bl ReoSliding
	b _080344A2
_08034468:
	bl ReoGoingUpInit
_0803446C:
	bl ReoGoingUp
	b _080344A2
_08034472:
	ldr r0, _08034488 @ =gCurrentSprite
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x2c
	bl SpriteUtilUnfreezeSecondarySprites
	bl SpriteDyingInit
_08034482:
	bl SpriteDying
	b _080344A2
	.align 2, 0
_08034488: .4byte gCurrentSprite
_0803448C:
	bl ReoInit
_08034490:
	bl SpriteSpawningFromX
	b _080344A2
_08034496:
	bl XParasiteInit
	ldr r1, _080344A8 @ =gCurrentSprite
	ldrh r0, [r1, #2]
	subs r0, #0x20
	strh r0, [r1, #2]
_080344A2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080344A8: .4byte gCurrentSprite

	thumb_func_start ReoWings
ReoWings: @ 0x080344AC
	push {lr}
	ldr r1, _080344C8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x26
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080344CC
	bl SpriteUtilUpdateFreezeTimer
	b _080344E8
	.align 2, 0
_080344C8: .4byte gCurrentSprite
_080344CC:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _080344E0
	cmp r0, #0x58
	bne _080344E4
	bl SpriteDying
	b _080344E8
_080344E0:
	bl ReoWingsInit
_080344E4:
	bl ReoWingsIdle
_080344E8:
	pop {r0}
	bx r0

	thumb_func_start LavaPlumeInit
LavaPlumeInit: @ 0x080344EC
	ldr r0, _08034574 @ =gCurrentSprite
	mov ip, r0
	ldr r2, _08034578 @ =sPrimarySpriteStats
	ldrb r1, [r0, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0
	mov r1, ip
	strh r0, [r1, #0x14]
	adds r1, #0x25
	movs r0, #4
	strb r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x68
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x29
	movs r1, #0x10
	strb r1, [r0]
	mov r2, ip
	strh r3, [r2, #0xa]
	movs r0, #0xa0
	strh r0, [r2, #0xc]
	ldr r0, _0803457C @ =0x0000FFF0
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldrh r0, [r2, #2]
	adds r0, #0x1c
	strh r0, [r2, #2]
	strh r0, [r2, #6]
	ldrh r0, [r2, #4]
	strh r0, [r2, #8]
	mov r1, ip
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldrh r1, [r2]
	ldr r2, _08034580 @ =0x00008004
	adds r0, r2, #0
	movs r2, #0
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	ldr r0, _08034584 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x78
	adds r1, #0x2f
	strb r0, [r1]
	ldr r0, _08034588 @ =0x0833FEB8
	mov r1, ip
	str r0, [r1, #0x18]
	strb r2, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_08034574: .4byte gCurrentSprite
_08034578: .4byte sPrimarySpriteStats
_0803457C: .4byte 0x0000FFF0
_08034580: .4byte 0x00008004
_08034584: .4byte gSpriteRandomNumber
_08034588: .4byte 0x0833FEB8

	thumb_func_start LavaPlumeGoUpInit
LavaPlumeGoUpInit: @ 0x0803458C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, _080345D4 @ =gCurrentSprite
	mov ip, r0
	ldr r0, _080345D8 @ =0x0833FE38
	mov r1, ip
	str r0, [r1, #0x18]
	movs r4, #0
	strb r4, [r1, #0x1c]
	strh r4, [r1, #0x16]
	adds r1, #0x2e
	movs r0, #0x1e
	strb r0, [r1]
	subs r1, #0xa
	movs r0, #2
	strb r0, [r1]
	mov r5, ip
	ldrb r1, [r5, #0x1e]
	ldrb r2, [r5, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r5, #2]
	subs r0, #0x1c
	str r0, [sp]
	ldrh r0, [r5, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x2d
	bl SpriteSpawnSecondary
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080345D4: .4byte gCurrentSprite
_080345D8: .4byte 0x0833FE38

	thumb_func_start LavaPlumeGoUp
LavaPlumeGoUp: @ 0x080345DC
	push {r4, lr}
	ldr r4, _08034614 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803461C
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0803464E
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	ldrh r0, [r4]
	ldr r1, _08034618 @ =0x00007FFB
	ands r1, r0
	strh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803464E
	movs r0, #0xc2
	lsls r0, r0, #1
	bl SoundPlay
	b _0803464E
	.align 2, 0
_08034614: .4byte gCurrentSprite
_08034618: .4byte 0x00007FFB
_0803461C:
	ldrh r0, [r4, #6]
	subs r0, #0x40
	ldrh r2, [r4, #2]
	cmp r0, r2
	ble _08034636
	ldrh r1, [r4, #4]
	adds r0, r2, #0
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08034654 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08034646
_08034636:
	ldr r4, _08034658 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0xe
	strh r0, [r4, #2]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803464E
_08034646:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
_0803464E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034654: .4byte gPreviousCollisionCheck
_08034658: .4byte gCurrentSprite

	thumb_func_start LavaPlumeStopFromSamusContact
LavaPlumeStopFromSamusContact: @ 0x0803465C
	push {lr}
	movs r0, #0xc2
	lsls r0, r0, #1
	bl SoundStop
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start LavaPlumeStopInit
LavaPlumeStopInit: @ 0x0803466C
	push {lr}
	ldr r1, _080346A0 @ =gCurrentSprite
	ldr r0, _080346A4 @ =0x0833FEC8
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x18
	strb r0, [r2]
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0803469C
	ldr r0, _080346A8 @ =0x00000185
	bl SoundPlay
_0803469C:
	pop {r0}
	bx r0
	.align 2, 0
_080346A0: .4byte gCurrentSprite
_080346A4: .4byte 0x0833FEC8
_080346A8: .4byte 0x00000185

	thumb_func_start LavaPlumeStop
LavaPlumeStop: @ 0x080346AC
	push {r4, lr}
	ldr r4, _080346F0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _080346EA
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _080346F4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x78
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
	ldr r0, _080346F8 @ =0x0833FEB8
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x16]
_080346EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080346F0: .4byte gCurrentSprite
_080346F4: .4byte gSpriteRandomNumber
_080346F8: .4byte 0x0833FEB8

	thumb_func_start LavaPlumeIdle
LavaPlumeIdle: @ 0x080346FC
	push {lr}
	ldr r1, _0803472C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x26
	movs r3, #1
	strb r3, [r0]
	adds r2, r1, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034726
	adds r0, r1, #0
	adds r0, #0x24
	strb r3, [r0]
	ldrh r0, [r1, #6]
	strh r0, [r1, #2]
	ldrh r0, [r1, #8]
	strh r0, [r1, #4]
_08034726:
	pop {r0}
	bx r0
	.align 2, 0
_0803472C: .4byte gCurrentSprite

	thumb_func_start LavaPlumeWarningInit
LavaPlumeWarningInit: @ 0x08034730
	push {r4, lr}
	ldr r0, _08034788 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0803478C @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	adds r1, #0x22
	movs r0, #3
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r1, #5
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08034790 @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _08034794 @ =0x0833FDE0
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034788: .4byte gCurrentSprite
_0803478C: .4byte 0x0000FFFB
_08034790: .4byte 0x0000FFFC
_08034794: .4byte 0x0833FDE0

	thumb_func_start LavaPlumeWarningIdle
LavaPlumeWarningIdle: @ 0x08034798
	push {lr}
	ldr r2, _080347BC @ =gSpriteData
	ldr r3, _080347C0 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _080347C4
	movs r0, #0
	strh r0, [r3]
	b _080347FA
	.align 2, 0
_080347BC: .4byte gSpriteData
_080347C0: .4byte gCurrentSprite
_080347C4:
	ldr r0, _080347E0 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	bne _080347FA
	ldr r0, _080347E4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #7
	bls _080347EC
	ldr r0, [r3, #0x18]
	ldr r2, _080347E8 @ =0x0833FE08
	b _080347F0
	.align 2, 0
_080347E0: .4byte gFrameCounter8Bit
_080347E4: .4byte gSpriteRandomNumber
_080347E8: .4byte 0x0833FE08
_080347EC:
	ldr r0, [r3, #0x18]
	ldr r2, _08034800 @ =0x0833FDE0
_080347F0:
	cmp r0, r2
	beq _080347FA
	str r2, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
_080347FA:
	pop {r0}
	bx r0
	.align 2, 0
_08034800: .4byte 0x0833FDE0

	thumb_func_start LavaPlume
LavaPlume: @ 0x08034804
	push {lr}
	ldr r0, _0803481C @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x37
	bls _08034812
	b _08034928
_08034812:
	lsls r0, r0, #2
	ldr r1, _08034820 @ =_08034824
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803481C: .4byte gCurrentSprite
_08034820: .4byte _08034824
_08034824: @ jump table
	.4byte _08034904 @ case 0
	.4byte _0803490A @ case 1
	.4byte _08034910 @ case 2
	.4byte _08034928 @ case 3
	.4byte _08034928 @ case 4
	.4byte _08034928 @ case 5
	.4byte _08034928 @ case 6
	.4byte _08034928 @ case 7
	.4byte _08034928 @ case 8
	.4byte _08034928 @ case 9
	.4byte _08034928 @ case 10
	.4byte _08034928 @ case 11
	.4byte _08034928 @ case 12
	.4byte _08034928 @ case 13
	.4byte _08034928 @ case 14
	.4byte _08034928 @ case 15
	.4byte _08034928 @ case 16
	.4byte _08034928 @ case 17
	.4byte _08034928 @ case 18
	.4byte _08034928 @ case 19
	.4byte _08034928 @ case 20
	.4byte _08034928 @ case 21
	.4byte _08034928 @ case 22
	.4byte _0803491A @ case 23
	.4byte _0803491E @ case 24
	.4byte _08034928 @ case 25
	.4byte _08034924 @ case 26
	.4byte _08034928 @ case 27
	.4byte _08034928 @ case 28
	.4byte _08034928 @ case 29
	.4byte _08034928 @ case 30
	.4byte _08034928 @ case 31
	.4byte _08034928 @ case 32
	.4byte _08034928 @ case 33
	.4byte _08034928 @ case 34
	.4byte _08034928 @ case 35
	.4byte _08034928 @ case 36
	.4byte _08034928 @ case 37
	.4byte _08034928 @ case 38
	.4byte _08034928 @ case 39
	.4byte _08034928 @ case 40
	.4byte _08034928 @ case 41
	.4byte _08034928 @ case 42
	.4byte _08034928 @ case 43
	.4byte _08034928 @ case 44
	.4byte _08034928 @ case 45
	.4byte _08034928 @ case 46
	.4byte _08034928 @ case 47
	.4byte _08034928 @ case 48
	.4byte _08034928 @ case 49
	.4byte _08034928 @ case 50
	.4byte _08034928 @ case 51
	.4byte _08034928 @ case 52
	.4byte _08034928 @ case 53
	.4byte _08034928 @ case 54
	.4byte _08034916 @ case 55
_08034904:
	bl LavaPlumeInit
	b _08034928
_0803490A:
	bl LavaPlumeGoUpInit
	b _08034928
_08034910:
	bl LavaPlumeGoUp
	b _08034928
_08034916:
	bl LavaPlumeStopFromSamusContact
_0803491A:
	bl LavaPlumeStopInit
_0803491E:
	bl LavaPlumeStop
	b _08034928
_08034924:
	bl LavaPlumeIdle
_08034928:
	pop {r0}
	bx r0

	thumb_func_start LavaPlumeWarning
LavaPlumeWarning: @ 0x0803492C
	push {lr}
	ldr r0, _08034948 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803494C
	cmp r0, #2
	beq _08034950
	b _08034954
	.align 2, 0
_08034948: .4byte gCurrentSprite
_0803494C:
	bl LavaPlumeWarningInit
_08034950:
	bl LavaPlumeWarningIdle
_08034954:
	pop {r0}
	bx r0

	thumb_func_start FuneInit
FuneInit: @ 0x08034958
	push {r4, r5, r6, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08034984 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034988
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08034988
	strh r0, [r2]
	b _08034A44
	.align 2, 0
_08034984: .4byte gCurrentSprite
_08034988:
	ldr r1, _080349A0 @ =gCurrentSprite
	adds r5, r1, #0
	adds r5, #0x24
	ldrb r0, [r5]
	adds r4, r1, #0
	cmp r0, #0x59
	bne _080349A4
	movs r0, #0x5a
	strb r0, [r5]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _080349C6
	.align 2, 0
_080349A0: .4byte gCurrentSprite
_080349A4:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08034A2C @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080349C2
	ldrh r1, [r4]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4]
_080349C2:
	movs r0, #1
	strb r0, [r5]
_080349C6:
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r3, _08034A30 @ =0x0000FFD8
	strh r3, [r4, #0xa]
	movs r5, #0x28
	strh r5, [r4, #0xc]
	ldr r0, _08034A34 @ =0x08341568
	str r0, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r2, [r4, #0x16]
	subs r1, #7
	movs r0, #3
	strb r0, [r1]
	adds r1, #0x13
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #4]
	strh r0, [r4, #8]
	ldr r2, _08034A38 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	ldrh r1, [r4]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08034A40
	ldr r0, _08034A3C @ =0x0000FFC0
	strh r0, [r4, #0xe]
	strh r5, [r4, #0x10]
	b _08034A44
	.align 2, 0
_08034A2C: .4byte gPreviousCollisionCheck
_08034A30: .4byte 0x0000FFD8
_08034A34: .4byte 0x08341568
_08034A38: .4byte sPrimarySpriteStats
_08034A3C: .4byte 0x0000FFC0
_08034A40:
	strh r3, [r4, #0xe]
	strh r2, [r4, #0x10]
_08034A44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FuneDying
FuneDying: @ 0x08034A4C
	ldr r1, _08034A58 @ =gCurrentSprite
	ldrb r0, [r1, #0x1c]
	subs r0, #1
	strb r0, [r1, #0x1c]
	bx lr
	.align 2, 0
_08034A58: .4byte gCurrentSprite

	thumb_func_start FuneTurningIntoX
FuneTurningIntoX: @ 0x08034A5C
	push {r4, lr}
	sub sp, #0x10
	ldr r1, _08034A78 @ =gCurrentSprite
	ldrh r0, [r1, #2]
	subs r0, #0x14
	strh r0, [r1, #2]
	ldrh r0, [r1, #8]
	adds r2, r1, #0
	ldrh r1, [r2, #4]
	cmp r0, r1
	bls _08034A7C
	ldrh r0, [r2, #8]
	ldrh r1, [r2, #4]
	b _08034A80
	.align 2, 0
_08034A78: .4byte gCurrentSprite
_08034A7C:
	ldrh r0, [r2, #4]
	ldrh r1, [r2, #8]
_08034A80:
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldrb r1, [r2, #0x1d]
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r2, #2]
	adds r0, #0x14
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FuneCheckSamusInFront
FuneCheckSamusInFront: @ 0x08034AB4
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0x48
	movs r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	beq _08034ACE
	movs r0, #0
	b _08034AD8
_08034ACE:
	ldr r0, _08034ADC @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2b
	strb r1, [r0]
	movs r0, #1
_08034AD8:
	pop {r1}
	bx r1
	.align 2, 0
_08034ADC: .4byte gCurrentSprite

	thumb_func_start FuneIdleInit
FuneIdleInit: @ 0x08034AE0
	ldr r1, _08034AF4 @ =gCurrentSprite
	ldr r0, _08034AF8 @ =0x08341568
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	bx lr
	.align 2, 0
_08034AF4: .4byte gCurrentSprite
_08034AF8: .4byte 0x08341568

	thumb_func_start FuneIdle
FuneIdle: @ 0x08034AFC
	push {r4, r5, lr}
	ldr r5, _08034B28 @ =gCurrentSprite
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08034BDE
	bl FuneCheckSamusInFront
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08034BDE
	movs r4, #0
	ldrh r0, [r5, #0x16]
	cmp r0, #7
	bhi _08034BAE
	lsls r0, r0, #2
	ldr r1, _08034B2C @ =_08034B30
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034B28: .4byte gCurrentSprite
_08034B2C: .4byte _08034B30
_08034B30: @ jump table
	.4byte _08034B50 @ case 0
	.4byte _08034B7C @ case 1
	.4byte _08034B8C @ case 2
	.4byte _08034BA0 @ case 3
	.4byte _08034BAE @ case 4
	.4byte _08034B7C @ case 5
	.4byte _08034B8C @ case 6
	.4byte _08034BA0 @ case 7
_08034B50:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08034BAE
	ldr r0, _08034B78 @ =gCurrentSprite
	ldrb r1, [r0, #0x1c]
	subs r1, #1
	strb r1, [r0, #0x1c]
	adds r0, #0x24
	movs r1, #0x29
	strb r1, [r0]
	b _08034BDE
	.align 2, 0
_08034B78: .4byte gCurrentSprite
_08034B7C:
	ldr r0, _08034B88 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #8
	beq _08034BAC
	b _08034B94
	.align 2, 0
_08034B88: .4byte gCurrentSprite
_08034B8C:
	ldr r0, _08034B9C @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #8
	beq _08034B98
_08034B94:
	cmp r0, #0xf
	bne _08034BAE
_08034B98:
	movs r4, #4
	b _08034BAE
	.align 2, 0
_08034B9C: .4byte gCurrentSprite
_08034BA0:
	ldr r0, _08034BC8 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #8
	beq _08034B98
	cmp r0, #0xf
	bne _08034BAE
_08034BAC:
	movs r4, #2
_08034BAE:
	ldr r2, _08034BC8 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08034BCC
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bhi _08034BD8
	ldrh r0, [r2, #4]
	adds r0, r4, r0
	b _08034BDC
	.align 2, 0
_08034BC8: .4byte gCurrentSprite
_08034BCC:
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bls _08034BD8
	ldrh r0, [r2, #4]
	adds r0, r4, r0
	b _08034BDC
_08034BD8:
	ldrh r0, [r2, #4]
	subs r0, r0, r4
_08034BDC:
	strh r0, [r2, #4]
_08034BDE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FuneSpittingInit
FuneSpittingInit: @ 0x08034BE4
	ldr r1, _08034BF8 @ =gCurrentSprite
	ldr r0, _08034BFC @ =0x083415B0
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bx lr
	.align 2, 0
_08034BF8: .4byte gCurrentSprite
_08034BFC: .4byte 0x083415B0

	thumb_func_start FuneSpitting
FuneSpitting: @ 0x08034C00
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl FuneCheckSamusInFront
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08034C10
	b _08034D0E
_08034C10:
	movs r5, #0
	ldr r0, _08034C28 @ =gCurrentSprite
	ldrh r2, [r0, #0x16]
	adds r3, r0, #0
	cmp r2, #7
	bhi _08034CDE
	lsls r0, r2, #2
	ldr r1, _08034C2C @ =_08034C30
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034C28: .4byte gCurrentSprite
_08034C2C: .4byte _08034C30
_08034C30: @ jump table
	.4byte _08034C50 @ case 0
	.4byte _08034C50 @ case 1
	.4byte _08034C50 @ case 2
	.4byte _08034C78 @ case 3
	.4byte _08034C50 @ case 4
	.4byte _08034C50 @ case 5
	.4byte _08034C50 @ case 6
	.4byte _08034C5C @ case 7
_08034C50:
	ldr r0, _08034C58 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	b _08034C6C
	.align 2, 0
_08034C58: .4byte gCurrentSprite
_08034C5C:
	ldrb r0, [r3, #0x1c]
	cmp r0, #0x28
	bne _08034C6C
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	b _08034D0E
_08034C6C:
	cmp r0, #1
	beq _08034C74
	cmp r0, #2
	bne _08034CDE
_08034C74:
	movs r5, #4
	b _08034CDE
_08034C78:
	ldr r0, _08034CBC @ =gCurrentSprite
	mov ip, r0
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	beq _08034C74
	cmp r0, #2
	beq _08034C74
	cmp r0, #4
	bne _08034CDE
	mov r4, ip
	ldrh r1, [r4]
	movs r6, #0x40
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08034CC0
	mov r0, ip
	ldrb r1, [r0, #0x1e]
	ldrb r2, [r0, #0x1f]
	adds r0, #0x23
	ldrb r3, [r0]
	mov r4, ip
	ldrh r0, [r4, #2]
	adds r0, #0x10
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x2f
	bl SpriteSpawnSecondary
	b _08034CDE
	.align 2, 0
_08034CBC: .4byte gCurrentSprite
_08034CC0:
	mov r6, ip
	ldrb r1, [r6, #0x1e]
	ldrb r2, [r6, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r6, #2]
	adds r0, #0x10
	str r0, [sp]
	ldrh r0, [r6, #4]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x2f
	bl SpriteSpawnSecondary
_08034CDE:
	ldr r2, _08034CF8 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08034CFC
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bhi _08034D08
	ldrh r0, [r2, #4]
	adds r0, r5, r0
	b _08034D0C
	.align 2, 0
_08034CF8: .4byte gCurrentSprite
_08034CFC:
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bls _08034D08
	ldrh r0, [r2, #4]
	adds r0, r5, r0
	b _08034D0C
_08034D08:
	ldrh r0, [r2, #4]
	subs r0, r0, r5
_08034D0C:
	strh r0, [r2, #4]
_08034D0E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FuneLungingInit
FuneLungingInit: @ 0x08034D18
	push {lr}
	ldr r1, _08034D38 @ =gCurrentSprite
	ldr r0, _08034D3C @ =0x083415F8
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	ldr r0, _08034D40 @ =0x00000187
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_08034D38: .4byte gCurrentSprite
_08034D3C: .4byte 0x083415F8
_08034D40: .4byte 0x00000187

	thumb_func_start FuneLunging
FuneLunging: @ 0x08034D44
	push {r4, lr}
	movs r3, #0
	ldr r1, _08034D60 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	subs r0, #4
	adds r4, r1, #0
	cmp r0, #0x15
	bhi _08034DF6
	lsls r0, r0, #2
	ldr r1, _08034D64 @ =_08034D68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08034D60: .4byte gCurrentSprite
_08034D64: .4byte _08034D68
_08034D68: @ jump table
	.4byte _08034DC0 @ case 0
	.4byte _08034DC0 @ case 1
	.4byte _08034DC0 @ case 2
	.4byte _08034DC0 @ case 3
	.4byte _08034DC0 @ case 4
	.4byte _08034DC0 @ case 5
	.4byte _08034DCE @ case 6
	.4byte _08034DDC @ case 7
	.4byte _08034DDC @ case 8
	.4byte _08034DDC @ case 9
	.4byte _08034DDC @ case 10
	.4byte _08034DDC @ case 11
	.4byte _08034DDC @ case 12
	.4byte _08034DDC @ case 13
	.4byte _08034DDC @ case 14
	.4byte _08034DDC @ case 15
	.4byte _08034DDC @ case 16
	.4byte _08034DF6 @ case 17
	.4byte _08034DF6 @ case 18
	.4byte _08034DF6 @ case 19
	.4byte _08034DF6 @ case 20
	.4byte _08034DE8 @ case 21
_08034DC0:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08034DCA
	cmp r0, #3
	bne _08034DF6
_08034DCA:
	movs r3, #0x18
	b _08034DF6
_08034DCE:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08034DD8
	cmp r0, #3
	bne _08034DF6
_08034DD8:
	movs r3, #0x10
	b _08034DF6
_08034DDC:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08034DD8
	cmp r0, #2
	bne _08034DF6
	b _08034DD8
_08034DE8:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0x28
	bne _08034DF6
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2e
	strb r0, [r1]
_08034DF6:
	adds r2, r4, #0
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08034E24
	ldrh r0, [r2, #0x16]
	cmp r0, #0xa
	bls _08034E16
	ldrh r0, [r2, #4]
	subs r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r2, #0xe]
	adds r0, r3, r0
	strh r0, [r2, #0xe]
	b _08034E44
_08034E16:
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	strh r0, [r2, #4]
	ldrh r0, [r2, #0xe]
	subs r0, r0, r3
	strh r0, [r2, #0xe]
	b _08034E44
_08034E24:
	ldrh r0, [r2, #0x16]
	cmp r0, #0xa
	bls _08034E38
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	strh r0, [r2, #4]
	ldrh r0, [r2, #0x10]
	subs r0, r0, r3
	strh r0, [r2, #0x10]
	b _08034E44
_08034E38:
	ldrh r0, [r4, #4]
	subs r0, r0, r3
	strh r0, [r4, #4]
	ldrh r0, [r4, #0x10]
	adds r0, r3, r0
	strh r0, [r4, #0x10]
_08034E44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FuneLungingEnd
FuneLungingEnd: @ 0x08034E4C
	push {lr}
	ldr r1, _08034E68 @ =gCurrentSprite
	ldrb r0, [r1, #0x1c]
	subs r0, #1
	strb r0, [r1, #0x1c]
	ldrh r0, [r1, #4]
	adds r3, r0, #0
	ldrh r2, [r1, #8]
	cmp r3, r2
	bhs _08034E6C
	adds r0, #1
	strh r0, [r1, #4]
	b _08034E7C
	.align 2, 0
_08034E68: .4byte gCurrentSprite
_08034E6C:
	cmp r3, r2
	bls _08034E76
	subs r0, #1
	strh r0, [r1, #4]
	b _08034E7C
_08034E76:
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_08034E7C:
	pop {r0}
	bx r0

	thumb_func_start FuneSpitInit
FuneSpitInit: @ 0x08034E80
	push {r4, lr}
	ldr r0, _08034EE8 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08034EEC @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _08034EF0 @ =0x0000FFF0
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _08034EF4 @ =0x083416D0
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	adds r1, #0x10
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034EE8: .4byte gCurrentSprite
_08034EEC: .4byte 0x0000FFFB
_08034EF0: .4byte 0x0000FFF0
_08034EF4: .4byte 0x083416D0

	thumb_func_start FuneSpitMoving
FuneSpitMoving: @ 0x08034EF8
	push {r4, lr}
	ldr r4, _08034F18 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	ldr r0, _08034F1C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034F20
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _08034F36
	.align 2, 0
_08034F18: .4byte gCurrentSprite
_08034F1C: .4byte gPreviousVerticalCollisionCheck
_08034F20:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08034F30
	ldrh r0, [r4, #4]
	adds r0, #0xa
	b _08034F34
_08034F30:
	ldrh r0, [r4, #4]
	subs r0, #0xa
_08034F34:
	strh r0, [r4, #4]
_08034F36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FuneSpitExplodingInit
FuneSpitExplodingInit: @ 0x08034F3C
	ldr r3, _08034F58 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	ldr r0, _08034F5C @ =0x083416F0
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	bx lr
	.align 2, 0
_08034F58: .4byte gCurrentSprite
_08034F5C: .4byte 0x083416F0

	thumb_func_start FuneSpitExploding
FuneSpitExploding: @ 0x08034F60
	push {r4, lr}
	ldr r4, _08034F80 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08034F78
	movs r0, #0
	strh r0, [r4]
_08034F78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034F80: .4byte gCurrentSprite

	thumb_func_start NamiheInit
NamiheInit: @ 0x08034F84
	push {r4, r5, r6, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08034FB0 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08034FB4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08034FB4
	strh r0, [r2]
	b _08035068
	.align 2, 0
_08034FB0: .4byte gCurrentSprite
_08034FB4:
	ldr r1, _08034FCC @ =gCurrentSprite
	adds r5, r1, #0
	adds r5, #0x24
	ldrb r0, [r5]
	adds r4, r1, #0
	cmp r0, #0x59
	bne _08034FD0
	movs r0, #0x5a
	strb r0, [r5]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _08034FF2
	.align 2, 0
_08034FCC: .4byte gCurrentSprite
_08034FD0:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08035050 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _08034FEE
	ldrh r1, [r4]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4]
_08034FEE:
	movs r0, #1
	strb r0, [r5]
_08034FF2:
	adds r1, r4, #0
	adds r1, #0x25
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #0x60
	strb r0, [r1]
	movs r6, #0
	ldr r3, _08035054 @ =0x0000FFD8
	strh r3, [r4, #0xa]
	movs r5, #0x28
	strh r5, [r4, #0xc]
	ldr r0, _08035058 @ =0x08341E6C
	str r0, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r2, [r4, #0x16]
	subs r1, #7
	movs r0, #3
	strb r0, [r1]
	ldrh r0, [r4, #4]
	strh r0, [r4, #8]
	ldr r2, _0803505C @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	ldrh r1, [r4]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08035064
	ldr r0, _08035060 @ =0x0000FFC0
	strh r0, [r4, #0xe]
	strh r5, [r4, #0x10]
	b _08035068
	.align 2, 0
_08035050: .4byte gPreviousCollisionCheck
_08035054: .4byte 0x0000FFD8
_08035058: .4byte 0x08341E6C
_0803505C: .4byte sPrimarySpriteStats
_08035060: .4byte 0x0000FFC0
_08035064:
	strh r3, [r4, #0xe]
	strh r2, [r4, #0x10]
_08035068:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NamiheDying
NamiheDying: @ 0x08035070
	ldr r1, _0803507C @ =gCurrentSprite
	ldrb r0, [r1, #0x1c]
	subs r0, #1
	strb r0, [r1, #0x1c]
	bx lr
	.align 2, 0
_0803507C: .4byte gCurrentSprite

	thumb_func_start NamiheTurningIntoX
NamiheTurningIntoX: @ 0x08035080
	push {r4, lr}
	sub sp, #0x10
	ldr r1, _0803509C @ =gCurrentSprite
	ldrh r0, [r1, #2]
	subs r0, #0x14
	strh r0, [r1, #2]
	ldrh r0, [r1, #8]
	adds r2, r1, #0
	ldrh r1, [r2, #4]
	cmp r0, r1
	bls _080350A0
	ldrh r0, [r2, #8]
	ldrh r1, [r2, #4]
	b _080350A4
	.align 2, 0
_0803509C: .4byte gCurrentSprite
_080350A0:
	ldrh r0, [r2, #4]
	ldrh r1, [r2, #8]
_080350A4:
	subs r0, r0, r1
	asrs r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldrb r1, [r2, #0x1d]
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r2, #2]
	adds r0, #0x14
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NamiheCheckSamusInFront
NamiheCheckSamusInFront: @ 0x080350D8
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0x48
	movs r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	beq _080350F2
	movs r0, #0
	b _080350FC
_080350F2:
	ldr r0, _08035100 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2b
	strb r1, [r0]
	movs r0, #1
_080350FC:
	pop {r1}
	bx r1
	.align 2, 0
_08035100: .4byte gCurrentSprite

	thumb_func_start NamiheIdleInit
NamiheIdleInit: @ 0x08035104
	ldr r1, _08035118 @ =gCurrentSprite
	ldr r0, _0803511C @ =0x08341E6C
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	bx lr
	.align 2, 0
_08035118: .4byte gCurrentSprite
_0803511C: .4byte 0x08341E6C

	thumb_func_start NamiheIdle
NamiheIdle: @ 0x08035120
	push {r4, r5, lr}
	ldr r5, _0803514C @ =gCurrentSprite
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08035202
	bl NamiheCheckSamusInFront
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035202
	movs r4, #0
	ldrh r0, [r5, #0x16]
	cmp r0, #7
	bhi _080351D2
	lsls r0, r0, #2
	ldr r1, _08035150 @ =_08035154
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803514C: .4byte gCurrentSprite
_08035150: .4byte _08035154
_08035154: @ jump table
	.4byte _08035174 @ case 0
	.4byte _080351A0 @ case 1
	.4byte _080351B0 @ case 2
	.4byte _080351C4 @ case 3
	.4byte _080351D2 @ case 4
	.4byte _080351A0 @ case 5
	.4byte _080351B0 @ case 6
	.4byte _080351C4 @ case 7
_08035174:
	movs r0, #0xa0
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _080351D2
	ldr r0, _0803519C @ =gCurrentSprite
	ldrb r1, [r0, #0x1c]
	subs r1, #1
	strb r1, [r0, #0x1c]
	adds r0, #0x24
	movs r1, #0x29
	strb r1, [r0]
	b _08035202
	.align 2, 0
_0803519C: .4byte gCurrentSprite
_080351A0:
	ldr r0, _080351AC @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #8
	beq _080351D0
	b _080351B8
	.align 2, 0
_080351AC: .4byte gCurrentSprite
_080351B0:
	ldr r0, _080351C0 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #8
	beq _080351BC
_080351B8:
	cmp r0, #0xf
	bne _080351D2
_080351BC:
	movs r4, #4
	b _080351D2
	.align 2, 0
_080351C0: .4byte gCurrentSprite
_080351C4:
	ldr r0, _080351EC @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #8
	beq _080351BC
	cmp r0, #0xf
	bne _080351D2
_080351D0:
	movs r4, #2
_080351D2:
	ldr r2, _080351EC @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080351F0
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bhi _080351FC
	ldrh r0, [r2, #4]
	adds r0, r4, r0
	b _08035200
	.align 2, 0
_080351EC: .4byte gCurrentSprite
_080351F0:
	ldrh r0, [r2, #0x16]
	cmp r0, #3
	bls _080351FC
	ldrh r0, [r2, #4]
	adds r0, r4, r0
	b _08035200
_080351FC:
	ldrh r0, [r2, #4]
	subs r0, r0, r4
_08035200:
	strh r0, [r2, #4]
_08035202:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start NamiheSpittingInit
NamiheSpittingInit: @ 0x08035208
	ldr r1, _0803521C @ =gCurrentSprite
	ldr r0, _08035220 @ =0x08341EB4
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803521C: .4byte gCurrentSprite
_08035220: .4byte 0x08341EB4

	thumb_func_start NamiheSpitting
NamiheSpitting: @ 0x08035224
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl NamiheCheckSamusInFront
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08035234
	b _0803533E
_08035234:
	movs r5, #0
	ldr r1, _0803524C @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	subs r0, #4
	adds r2, r1, #0
	cmp r0, #0xb
	bhi _0803530E
	lsls r0, r0, #2
	ldr r1, _08035250 @ =_08035254
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803524C: .4byte gCurrentSprite
_08035250: .4byte _08035254
_08035254: @ jump table
	.4byte _08035284 @ case 0
	.4byte _08035284 @ case 1
	.4byte _08035284 @ case 2
	.4byte _08035298 @ case 3
	.4byte _08035284 @ case 4
	.4byte _08035284 @ case 5
	.4byte _08035284 @ case 6
	.4byte _08035284 @ case 7
	.4byte _0803530E @ case 8
	.4byte _0803530E @ case 9
	.4byte _0803530E @ case 10
	.4byte _080352FE @ case 11
_08035284:
	ldr r0, _08035294 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	beq _08035290
	cmp r0, #2
	bne _0803530E
_08035290:
	movs r5, #4
	b _0803530E
	.align 2, 0
_08035294: .4byte gCurrentSprite
_08035298:
	ldr r0, _080352D8 @ =gCurrentSprite
	mov ip, r0
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	beq _08035290
	cmp r0, #2
	beq _08035290
	cmp r0, #4
	bne _0803530E
	mov r4, ip
	ldrh r1, [r4]
	movs r6, #0x40
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080352DC
	mov r0, ip
	ldrb r1, [r0, #0x1e]
	ldrb r2, [r0, #0x1f]
	adds r0, #0x23
	ldrb r3, [r0]
	mov r4, ip
	ldrh r0, [r4, #2]
	adds r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x10
	str r0, [sp, #4]
	str r6, [sp, #8]
	b _080352F6
	.align 2, 0
_080352D8: .4byte gCurrentSprite
_080352DC:
	mov r6, ip
	ldrb r1, [r6, #0x1e]
	ldrb r2, [r6, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r6, #2]
	adds r0, #0x20
	str r0, [sp]
	ldrh r0, [r6, #4]
	subs r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
_080352F6:
	movs r0, #0x2e
	bl SpriteSpawnSecondary
	b _0803530E
_080352FE:
	ldrb r0, [r2, #0x1c]
	cmp r0, #0x28
	bne _0803530E
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	b _0803533E
_0803530E:
	ldr r2, _08035328 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803532C
	ldrh r0, [r2, #0x16]
	cmp r0, #7
	bhi _08035338
	ldrh r0, [r2, #4]
	adds r0, r5, r0
	b _0803533C
	.align 2, 0
_08035328: .4byte gCurrentSprite
_0803532C:
	ldrh r0, [r2, #0x16]
	cmp r0, #7
	bls _08035338
	ldrh r0, [r2, #4]
	adds r0, r5, r0
	b _0803533C
_08035338:
	ldrh r0, [r2, #4]
	subs r0, r0, r5
_0803533C:
	strh r0, [r2, #4]
_0803533E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NamiheLungingInit
NamiheLungingInit: @ 0x08035348
	push {lr}
	ldr r1, _08035368 @ =gCurrentSprite
	ldr r0, _0803536C @ =0x08341F3C
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_08035368: .4byte gCurrentSprite
_0803536C: .4byte 0x08341F3C

	thumb_func_start NamiheLunging
NamiheLunging: @ 0x08035370
	push {r4, lr}
	movs r3, #0
	ldr r1, _0803538C @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	subs r0, #0xc
	adds r4, r1, #0
	cmp r0, #0x19
	bhi _08035432
	lsls r0, r0, #2
	ldr r1, _08035390 @ =_08035394
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803538C: .4byte gCurrentSprite
_08035390: .4byte _08035394
_08035394: @ jump table
	.4byte _080353FC @ case 0
	.4byte _080353FC @ case 1
	.4byte _080353FC @ case 2
	.4byte _080353FC @ case 3
	.4byte _080353FC @ case 4
	.4byte _080353FC @ case 5
	.4byte _0803540A @ case 6
	.4byte _08035418 @ case 7
	.4byte _08035418 @ case 8
	.4byte _08035418 @ case 9
	.4byte _08035418 @ case 10
	.4byte _08035418 @ case 11
	.4byte _08035418 @ case 12
	.4byte _08035418 @ case 13
	.4byte _08035418 @ case 14
	.4byte _08035418 @ case 15
	.4byte _08035418 @ case 16
	.4byte _08035432 @ case 17
	.4byte _08035432 @ case 18
	.4byte _08035432 @ case 19
	.4byte _08035432 @ case 20
	.4byte _08035432 @ case 21
	.4byte _08035432 @ case 22
	.4byte _08035432 @ case 23
	.4byte _08035432 @ case 24
	.4byte _08035424 @ case 25
_080353FC:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08035406
	cmp r0, #3
	bne _08035432
_08035406:
	movs r3, #0x18
	b _08035432
_0803540A:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08035414
	cmp r0, #3
	bne _08035432
_08035414:
	movs r3, #0x10
	b _08035432
_08035418:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08035414
	cmp r0, #2
	bne _08035432
	b _08035414
_08035424:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0x28
	bne _08035432
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2e
	strb r0, [r1]
_08035432:
	adds r2, r4, #0
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08035460
	ldrh r0, [r2, #0x16]
	cmp r0, #0x12
	bls _08035452
	ldrh r0, [r2, #4]
	subs r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r2, #0xe]
	adds r0, r3, r0
	strh r0, [r2, #0xe]
	b _08035480
_08035452:
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	strh r0, [r2, #4]
	ldrh r0, [r2, #0xe]
	subs r0, r0, r3
	strh r0, [r2, #0xe]
	b _08035480
_08035460:
	ldrh r0, [r2, #0x16]
	cmp r0, #0x12
	bls _08035474
	ldrh r0, [r2, #4]
	adds r0, r3, r0
	strh r0, [r2, #4]
	ldrh r0, [r2, #0x10]
	subs r0, r0, r3
	strh r0, [r2, #0x10]
	b _08035480
_08035474:
	ldrh r0, [r4, #4]
	subs r0, r0, r3
	strh r0, [r4, #4]
	ldrh r0, [r4, #0x10]
	adds r0, r3, r0
	strh r0, [r4, #0x10]
_08035480:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NamiheLungingEnd
NamiheLungingEnd: @ 0x08035488
	push {lr}
	ldr r1, _080354A4 @ =gCurrentSprite
	ldrb r0, [r1, #0x1c]
	subs r0, #1
	strb r0, [r1, #0x1c]
	ldrh r0, [r1, #4]
	adds r3, r0, #0
	ldrh r2, [r1, #8]
	cmp r3, r2
	bhs _080354A8
	adds r0, #1
	strh r0, [r1, #4]
	b _080354B8
	.align 2, 0
_080354A4: .4byte gCurrentSprite
_080354A8:
	cmp r3, r2
	bls _080354B2
	subs r0, #1
	strh r0, [r1, #4]
	b _080354B8
_080354B2:
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_080354B8:
	pop {r0}
	bx r0

	thumb_func_start NamiheSpitInit
NamiheSpitInit: @ 0x080354BC
	push {r4, lr}
	ldr r0, _08035538 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0803553C @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _08035540 @ =0x0000FFF0
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _08035544 @ =0x08342074
	str r0, [r2, #0x18]
	strb r4, [r2, #0x1c]
	strh r3, [r2, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	adds r1, #9
	movs r0, #6
	strb r0, [r1]
	ldr r2, _08035548 @ =gSamusData
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r0, ip
	ldrh r1, [r0, #2]
	cmp r1, r2
	bls _0803554C
	adds r0, #0x2f
	strb r4, [r0]
	subs r0, r1, r2
	b _08035556
	.align 2, 0
_08035538: .4byte gCurrentSprite
_0803553C: .4byte 0x0000FFFB
_08035540: .4byte 0x0000FFF0
_08035544: .4byte 0x08342074
_08035548: .4byte gSamusData
_0803554C:
	mov r3, ip
	adds r3, #0x2f
	movs r0, #1
	strb r0, [r3]
	subs r0, r2, r1
_08035556:
	cmp r0, #0
	bge _0803555C
	adds r0, #0x1f
_0803555C:
	lsls r0, r0, #0xb
	lsrs r3, r0, #0x10
	mov r0, ip
	adds r0, #0x31
	strb r3, [r0]
	ldr r0, _08035574 @ =0x00000189
	bl SoundPlayNotAlreadyPlaying
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035574: .4byte 0x00000189

	thumb_func_start NamiheSpitMoving
NamiheSpitMoving: @ 0x08035578
	push {r4, lr}
	ldr r4, _08035598 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	ldr r0, _0803559C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080355A0
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _080355EE
	.align 2, 0
_08035598: .4byte gCurrentSprite
_0803559C: .4byte gPreviousVerticalCollisionCheck
_080355A0:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080355B0
	ldrh r0, [r4, #4]
	adds r0, #0xa
	b _080355B4
_080355B0:
	ldrh r0, [r4, #4]
	subs r0, #0xa
_080355B4:
	strh r0, [r4, #4]
	ldr r2, _080355C8 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _080355CC
	subs r0, #1
	strb r0, [r1]
	b _080355EE
	.align 2, 0
_080355C8: .4byte gCurrentSprite
_080355CC:
	adds r0, r2, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _080355E2
	adds r1, r2, #0
	adds r1, #0x31
	ldrh r0, [r2, #2]
	ldrb r1, [r1]
	adds r0, r0, r1
	b _080355EC
_080355E2:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r1, [r0]
	ldrh r0, [r2, #2]
	subs r0, r0, r1
_080355EC:
	strh r0, [r2, #2]
_080355EE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NamiheSpitExplodingInit
NamiheSpitExplodingInit: @ 0x080355F4
	ldr r3, _08035610 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	ldr r0, _08035614 @ =0x08342094
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	bx lr
	.align 2, 0
_08035610: .4byte gCurrentSprite
_08035614: .4byte 0x08342094

	thumb_func_start NamiheSpitExploding
NamiheSpitExploding: @ 0x08035618
	push {r4, lr}
	ldr r4, _08035638 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08035630
	movs r0, #0
	strh r0, [r4]
_08035630:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035638: .4byte gCurrentSprite

	thumb_func_start Fune
Fune: @ 0x0803563C
	push {r4, lr}
	ldr r4, _08035668 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08035656
	movs r0, #0xc4
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08035656:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803566C
	bl SpriteUtilUpdateFreezeTimer
	b _08035842
	.align 2, 0
_08035668: .4byte gCurrentSprite
_0803566C:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08035678
	b _08035842
_08035678:
	lsls r0, r0, #2
	ldr r1, _08035684 @ =_08035688
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035684: .4byte _08035688
_08035688: @ jump table
	.4byte _080357F8 @ case 0
	.4byte _080357FE @ case 1
	.4byte _08035802 @ case 2
	.4byte _08035842 @ case 3
	.4byte _08035842 @ case 4
	.4byte _08035842 @ case 5
	.4byte _08035842 @ case 6
	.4byte _08035842 @ case 7
	.4byte _08035842 @ case 8
	.4byte _08035842 @ case 9
	.4byte _08035842 @ case 10
	.4byte _08035842 @ case 11
	.4byte _08035842 @ case 12
	.4byte _08035842 @ case 13
	.4byte _08035842 @ case 14
	.4byte _08035842 @ case 15
	.4byte _08035842 @ case 16
	.4byte _08035842 @ case 17
	.4byte _08035842 @ case 18
	.4byte _08035842 @ case 19
	.4byte _08035842 @ case 20
	.4byte _08035842 @ case 21
	.4byte _08035842 @ case 22
	.4byte _08035842 @ case 23
	.4byte _08035842 @ case 24
	.4byte _08035842 @ case 25
	.4byte _08035842 @ case 26
	.4byte _08035842 @ case 27
	.4byte _08035842 @ case 28
	.4byte _08035842 @ case 29
	.4byte _08035842 @ case 30
	.4byte _08035842 @ case 31
	.4byte _08035842 @ case 32
	.4byte _08035842 @ case 33
	.4byte _08035842 @ case 34
	.4byte _08035842 @ case 35
	.4byte _08035842 @ case 36
	.4byte _08035842 @ case 37
	.4byte _08035842 @ case 38
	.4byte _08035842 @ case 39
	.4byte _08035842 @ case 40
	.4byte _08035808 @ case 41
	.4byte _0803580C @ case 42
	.4byte _08035812 @ case 43
	.4byte _08035816 @ case 44
	.4byte _08035842 @ case 45
	.4byte _0803581C @ case 46
	.4byte _08035842 @ case 47
	.4byte _08035842 @ case 48
	.4byte _08035842 @ case 49
	.4byte _08035842 @ case 50
	.4byte _08035842 @ case 51
	.4byte _08035842 @ case 52
	.4byte _08035842 @ case 53
	.4byte _08035842 @ case 54
	.4byte _08035842 @ case 55
	.4byte _08035842 @ case 56
	.4byte _08035842 @ case 57
	.4byte _08035842 @ case 58
	.4byte _08035842 @ case 59
	.4byte _08035842 @ case 60
	.4byte _08035842 @ case 61
	.4byte _08035842 @ case 62
	.4byte _08035842 @ case 63
	.4byte _08035842 @ case 64
	.4byte _08035842 @ case 65
	.4byte _08035842 @ case 66
	.4byte _08035842 @ case 67
	.4byte _08035842 @ case 68
	.4byte _08035842 @ case 69
	.4byte _08035842 @ case 70
	.4byte _08035842 @ case 71
	.4byte _08035842 @ case 72
	.4byte _08035842 @ case 73
	.4byte _08035842 @ case 74
	.4byte _08035842 @ case 75
	.4byte _08035842 @ case 76
	.4byte _08035842 @ case 77
	.4byte _08035842 @ case 78
	.4byte _08035842 @ case 79
	.4byte _08035842 @ case 80
	.4byte _08035842 @ case 81
	.4byte _08035842 @ case 82
	.4byte _08035842 @ case 83
	.4byte _08035842 @ case 84
	.4byte _08035842 @ case 85
	.4byte _08035842 @ case 86
	.4byte _08035822 @ case 87
	.4byte _08035826 @ case 88
	.4byte _08035830 @ case 89
	.4byte _08035834 @ case 90
	.4byte _0803583A @ case 91
_080357F8:
	bl FuneInit
	b _08035842
_080357FE:
	bl FuneIdleInit
_08035802:
	bl FuneIdle
	b _08035842
_08035808:
	bl FuneSpittingInit
_0803580C:
	bl FuneSpitting
	b _08035842
_08035812:
	bl FuneLungingInit
_08035816:
	bl FuneLunging
	b _08035842
_0803581C:
	bl FuneLungingEnd
	b _08035842
_08035822:
	bl SpriteDyingInit
_08035826:
	bl FuneDying
	bl SpriteDying
	b _08035842
_08035830:
	bl FuneInit
_08035834:
	bl SpriteSpawningFromX
	b _08035842
_0803583A:
	bl FuneTurningIntoX
	bl XParasiteInit
_08035842:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FuneSpit
FuneSpit: @ 0x08035848
	push {lr}
	ldr r0, _08035860 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803586E
	cmp r0, #2
	bgt _08035864
	cmp r0, #0
	beq _0803586A
	b _0803587A
	.align 2, 0
_08035860: .4byte gCurrentSprite
_08035864:
	cmp r0, #0x38
	beq _08035874
	b _0803587A
_0803586A:
	bl FuneSpitInit
_0803586E:
	bl FuneSpitMoving
	b _0803587E
_08035874:
	bl FuneSpitExploding
	b _0803587E
_0803587A:
	bl FuneSpitExplodingInit
_0803587E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Namihe
Namihe: @ 0x08035884
	push {r4, lr}
	ldr r4, _080358AC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803589C
	ldr r0, _080358B0 @ =0x0000018B
	bl SoundPlayNotAlreadyPlaying
_0803589C:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _080358B4
	bl SpriteUtilUpdateFreezeTimer
	b _08035A8A
	.align 2, 0
_080358AC: .4byte gCurrentSprite
_080358B0: .4byte 0x0000018B
_080358B4:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _080358C0
	b _08035A8A
_080358C0:
	lsls r0, r0, #2
	ldr r1, _080358CC @ =_080358D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080358CC: .4byte _080358D0
_080358D0: @ jump table
	.4byte _08035A40 @ case 0
	.4byte _08035A46 @ case 1
	.4byte _08035A4A @ case 2
	.4byte _08035A8A @ case 3
	.4byte _08035A8A @ case 4
	.4byte _08035A8A @ case 5
	.4byte _08035A8A @ case 6
	.4byte _08035A8A @ case 7
	.4byte _08035A8A @ case 8
	.4byte _08035A8A @ case 9
	.4byte _08035A8A @ case 10
	.4byte _08035A8A @ case 11
	.4byte _08035A8A @ case 12
	.4byte _08035A8A @ case 13
	.4byte _08035A8A @ case 14
	.4byte _08035A8A @ case 15
	.4byte _08035A8A @ case 16
	.4byte _08035A8A @ case 17
	.4byte _08035A8A @ case 18
	.4byte _08035A8A @ case 19
	.4byte _08035A8A @ case 20
	.4byte _08035A8A @ case 21
	.4byte _08035A8A @ case 22
	.4byte _08035A8A @ case 23
	.4byte _08035A8A @ case 24
	.4byte _08035A8A @ case 25
	.4byte _08035A8A @ case 26
	.4byte _08035A8A @ case 27
	.4byte _08035A8A @ case 28
	.4byte _08035A8A @ case 29
	.4byte _08035A8A @ case 30
	.4byte _08035A8A @ case 31
	.4byte _08035A8A @ case 32
	.4byte _08035A8A @ case 33
	.4byte _08035A8A @ case 34
	.4byte _08035A8A @ case 35
	.4byte _08035A8A @ case 36
	.4byte _08035A8A @ case 37
	.4byte _08035A8A @ case 38
	.4byte _08035A8A @ case 39
	.4byte _08035A8A @ case 40
	.4byte _08035A50 @ case 41
	.4byte _08035A54 @ case 42
	.4byte _08035A5A @ case 43
	.4byte _08035A5E @ case 44
	.4byte _08035A8A @ case 45
	.4byte _08035A64 @ case 46
	.4byte _08035A8A @ case 47
	.4byte _08035A8A @ case 48
	.4byte _08035A8A @ case 49
	.4byte _08035A8A @ case 50
	.4byte _08035A8A @ case 51
	.4byte _08035A8A @ case 52
	.4byte _08035A8A @ case 53
	.4byte _08035A8A @ case 54
	.4byte _08035A8A @ case 55
	.4byte _08035A8A @ case 56
	.4byte _08035A8A @ case 57
	.4byte _08035A8A @ case 58
	.4byte _08035A8A @ case 59
	.4byte _08035A8A @ case 60
	.4byte _08035A8A @ case 61
	.4byte _08035A8A @ case 62
	.4byte _08035A8A @ case 63
	.4byte _08035A8A @ case 64
	.4byte _08035A8A @ case 65
	.4byte _08035A8A @ case 66
	.4byte _08035A8A @ case 67
	.4byte _08035A8A @ case 68
	.4byte _08035A8A @ case 69
	.4byte _08035A8A @ case 70
	.4byte _08035A8A @ case 71
	.4byte _08035A8A @ case 72
	.4byte _08035A8A @ case 73
	.4byte _08035A8A @ case 74
	.4byte _08035A8A @ case 75
	.4byte _08035A8A @ case 76
	.4byte _08035A8A @ case 77
	.4byte _08035A8A @ case 78
	.4byte _08035A8A @ case 79
	.4byte _08035A8A @ case 80
	.4byte _08035A8A @ case 81
	.4byte _08035A8A @ case 82
	.4byte _08035A8A @ case 83
	.4byte _08035A8A @ case 84
	.4byte _08035A8A @ case 85
	.4byte _08035A8A @ case 86
	.4byte _08035A6A @ case 87
	.4byte _08035A6E @ case 88
	.4byte _08035A78 @ case 89
	.4byte _08035A7C @ case 90
	.4byte _08035A82 @ case 91
_08035A40:
	bl NamiheInit
	b _08035A8A
_08035A46:
	bl NamiheIdleInit
_08035A4A:
	bl NamiheIdle
	b _08035A8A
_08035A50:
	bl NamiheSpittingInit
_08035A54:
	bl NamiheSpitting
	b _08035A8A
_08035A5A:
	bl NamiheLungingInit
_08035A5E:
	bl NamiheLunging
	b _08035A8A
_08035A64:
	bl NamiheLungingEnd
	b _08035A8A
_08035A6A:
	bl SpriteDyingInit
_08035A6E:
	bl NamiheDying
	bl SpriteDying
	b _08035A8A
_08035A78:
	bl NamiheInit
_08035A7C:
	bl SpriteSpawningFromX
	b _08035A8A
_08035A82:
	bl NamiheTurningIntoX
	bl XParasiteInit
_08035A8A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NamiheSpit
NamiheSpit: @ 0x08035A90
	push {lr}
	ldr r0, _08035AA8 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08035AB6
	cmp r0, #2
	bgt _08035AAC
	cmp r0, #0
	beq _08035AB2
	b _08035AC2
	.align 2, 0
_08035AA8: .4byte gCurrentSprite
_08035AAC:
	cmp r0, #0x38
	beq _08035ABC
	b _08035AC2
_08035AB2:
	bl NamiheSpitInit
_08035AB6:
	bl NamiheSpitMoving
	b _08035AC6
_08035ABC:
	bl NamiheSpitExploding
	b _08035AC6
_08035AC2:
	bl NamiheSpitExplodingInit
_08035AC6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SpriteUtilUpdateSubSpriteData1Animation
SpriteUtilUpdateSubSpriteData1Animation: @ 0x08035ACC
	push {lr}
	ldr r2, _08035B04 @ =gSubSpriteData1
	ldrb r0, [r2, #6]
	adds r0, #1
	strb r0, [r2, #6]
	ldrh r1, [r2, #4]
	ldr r3, [r2]
	lsls r1, r1, #3
	adds r1, r1, r3
	ldrb r1, [r1, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	bhs _08035B00
	movs r0, #1
	strb r0, [r2, #6]
	ldrh r0, [r2, #4]
	adds r0, #1
	strh r0, [r2, #4]
	ldrh r0, [r2, #4]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08035B00
	strh r0, [r2, #4]
_08035B00:
	pop {r0}
	bx r0
	.align 2, 0
_08035B04: .4byte gSubSpriteData1

	thumb_func_start SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position: @ 0x08035B08
	push {r4, lr}
	ldr r3, _08035B44 @ =gSubSpriteData1
	ldrh r0, [r3, #4]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r2, _08035B48 @ =gCurrentSprite
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	ldrh r1, [r3, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	ldrh r3, [r3, #0xa]
	adds r0, r0, r3
	strh r0, [r2, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035B44: .4byte gSubSpriteData1
_08035B48: .4byte gCurrentSprite

	thumb_func_start BoxSyncSubSprites
BoxSyncSubSprites: @ 0x08035B4C
	push {r4, lr}
	ldr r4, _08035BA8 @ =gSubSpriteData1
	ldrh r0, [r4, #4]
	ldr r1, [r4]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r2, _08035BAC @ =gCurrentSprite
	ldrb r1, [r2, #0x1e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, _08035BB0 @ =0x0879AFE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r2, #0x18]
	ldr r0, [r0]
	cmp r1, r0
	beq _08035B7E
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
_08035B7E:
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
_08035BA8: .4byte gSubSpriteData1
_08035BAC: .4byte gCurrentSprite
_08035BB0: .4byte 0x0879AFE0

	thumb_func_start BoxXMovement
BoxXMovement: @ 0x08035BB4
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
	ldr r6, _08035C00 @ =gCurrentSprite
	ldrh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035C12
	ldr r4, _08035C04 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	adds r1, #0x6e
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08035C08 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035C0C
	adds r0, r6, #0
	adds r0, #0x24
	strb r5, [r0]
	movs r1, #1
	mov r8, r1
	b _08035C48
	.align 2, 0
_08035C00: .4byte gCurrentSprite
_08035C04: .4byte gSubSpriteData1
_08035C08: .4byte gPreviousCollisionCheck
_08035C0C:
	ldrh r0, [r4, #0xa]
	adds r0, r7, r0
	b _08035C46
_08035C12:
	ldr r4, _08035C38 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	subs r0, #0x10
	ldrh r1, [r4, #0xa]
	subs r1, #0x6e
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08035C3C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08035C40
	adds r0, r6, #0
	adds r0, #0x24
	mov r1, sb
	strb r1, [r0]
	movs r0, #1
	mov r8, r0
	b _08035C48
	.align 2, 0
_08035C38: .4byte gSubSpriteData1
_08035C3C: .4byte gPreviousCollisionCheck
_08035C40:
	ldrh r0, [r4, #0xa]
	mov r1, sl
	subs r0, r0, r1
_08035C46:
	strh r0, [r4, #0xa]
_08035C48:
	mov r0, r8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start BoxInit
BoxInit: @ 0x08035C58
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	bl EventCheckOn_BoxRumble
	adds r1, r0, #0
	cmp r1, #0
	bne _08035C70
	ldr r0, _08035C6C @ =gCurrentSprite
	strh r1, [r0]
	b _08035E02
	.align 2, 0
_08035C6C: .4byte gCurrentSprite
_08035C70:
	ldr r7, _08035E0C @ =gCurrentSprite
	adds r0, r7, #0
	adds r0, #0x25
	movs r5, #0
	strb r5, [r0]
	ldrh r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #8
	adds r3, r1, #0
	movs r6, #0
	orrs r3, r0
	strh r3, [r7]
	adds r0, r7, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _08035E10 @ =0x0000FFD8
	strh r0, [r7, #0xa]
	movs r0, #0x40
	strh r0, [r7, #0xc]
	ldr r0, _08035E14 @ =0x0000FFD0
	strh r0, [r7, #0xe]
	movs r0, #0x30
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #7
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x22
	movs r0, #0xc
	strb r0, [r2]
	adds r2, #0x13
	movs r0, #2
	strb r0, [r2]
	strb r1, [r7, #0x1e]
	ldr r2, _08035E18 @ =sPrimarySpriteStats
	ldrb r1, [r7, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x14]
	adds r2, r7, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08035E1C @ =0x08347BD8
	str r0, [r7, #0x18]
	strb r6, [r7, #0x1c]
	strh r5, [r7, #0x16]
	ldr r4, _08035E20 @ =gSubSpriteData1
	ldrh r0, [r7, #2]
	strh r0, [r4, #8]
	ldrh r0, [r7, #4]
	strh r0, [r4, #0xa]
	ldr r0, _08035E24 @ =0x08342DF0
	str r0, [r4]
	strb r6, [r4, #6]
	strh r5, [r4, #4]
	strb r6, [r4, #0xe]
	adds r0, r7, #0
	adds r0, #0x2f
	strb r6, [r0]
	ldr r0, _08035E28 @ =0x0000FDFF
	ands r3, r0
	strh r3, [r7]
	adds r1, r7, #0
	adds r1, #0x24
	movs r0, #0x3f
	strb r0, [r1]
	ldrb r2, [r7, #0x1f]
	adds r6, r7, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #1
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #2
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #3
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #4
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #5
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #6
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #8
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #9
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #0xa
	bl SpriteSpawnSecondary
	ldrb r2, [r7, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #8]
	str r0, [sp]
	ldrh r0, [r4, #0xa]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x31
	movs r1, #0xb
	bl SpriteSpawnSecondary
_08035E02:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035E0C: .4byte gCurrentSprite
_08035E10: .4byte 0x0000FFD8
_08035E14: .4byte 0x0000FFD0
_08035E18: .4byte sPrimarySpriteStats
_08035E1C: .4byte 0x08347BD8
_08035E20: .4byte gSubSpriteData1
_08035E24: .4byte 0x08342DF0
_08035E28: .4byte 0x0000FDFF

	thumb_func_start BoxWaitingToEmergeInit
BoxWaitingToEmergeInit: @ 0x08035E2C
	push {r4, r5, lr}
	ldr r1, _08035E74 @ =gSubSpriteData1
	ldr r0, _08035E78 @ =0x08342F38
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r4, #0
	strh r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1, #0xa]
	adds r0, r0, r2
	strh r0, [r1, #0xa]
	ldr r5, _08035E7C @ =gCurrentSprite
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2e
	strb r4, [r0]
	ldr r0, _08035E80 @ =0x0000026D
	bl SoundPlay_3b1c
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	adds r0, r5, #0
	adds r0, #0x31
	strb r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08035E74: .4byte gSubSpriteData1
_08035E78: .4byte 0x08342F38
_08035E7C: .4byte gCurrentSprite
_08035E80: .4byte 0x0000026D

	thumb_func_start BoxWaitingToEmerge
BoxWaitingToEmerge: @ 0x08035E84
	push {r4, r5, r6, lr}
	ldr r6, _08035EC8 @ =gCurrentSprite
	adds r4, r6, #0
	adds r4, #0x31
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bls _08035EAC
	ldr r0, _08035ECC @ =0x0000026D
	bl SoundPlay_3b1c
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	movs r0, #0
	strb r0, [r4]
_08035EAC:
	ldrh r5, [r6, #2]
	ldrh r4, [r6, #4]
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0x24
	bls _08035EBC
	b _08035FC2
_08035EBC:
	lsls r0, r0, #2
	ldr r1, _08035ED0 @ =_08035ED4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035EC8: .4byte gCurrentSprite
_08035ECC: .4byte 0x0000026D
_08035ED0: .4byte _08035ED4
_08035ED4: @ jump table
	.4byte _08035F68 @ case 0
	.4byte _08035FC2 @ case 1
	.4byte _08035FC2 @ case 2
	.4byte _08035FC2 @ case 3
	.4byte _08035F6E @ case 4
	.4byte _08035FC2 @ case 5
	.4byte _08035FC2 @ case 6
	.4byte _08035FC2 @ case 7
	.4byte _08035F74 @ case 8
	.4byte _08035FC2 @ case 9
	.4byte _08035FC2 @ case 10
	.4byte _08035FC2 @ case 11
	.4byte _08035FC2 @ case 12
	.4byte _08035FC2 @ case 13
	.4byte _08035FC2 @ case 14
	.4byte _08035FC2 @ case 15
	.4byte _08035F7E @ case 16
	.4byte _08035FC2 @ case 17
	.4byte _08035FC2 @ case 18
	.4byte _08035FC2 @ case 19
	.4byte _08035F88 @ case 20
	.4byte _08035FC2 @ case 21
	.4byte _08035FC2 @ case 22
	.4byte _08035FC2 @ case 23
	.4byte _08035F98 @ case 24
	.4byte _08035FC2 @ case 25
	.4byte _08035FC2 @ case 26
	.4byte _08035FC2 @ case 27
	.4byte _08035FA2 @ case 28
	.4byte _08035FC2 @ case 29
	.4byte _08035FC2 @ case 30
	.4byte _08035FC2 @ case 31
	.4byte _08035FAA @ case 32
	.4byte _08035FC2 @ case 33
	.4byte _08035FC2 @ case 34
	.4byte _08035FC2 @ case 35
	.4byte _08035FBA @ case 36
_08035F68:
	adds r0, r5, #0
	adds r1, r4, #0
	b _08035F90
_08035F6E:
	adds r0, r5, #0
	adds r1, r4, #0
	b _08035FB2
_08035F74:
	adds r0, r5, #0
	subs r0, #0x1c
	adds r1, r4, #0
	adds r1, #0x1c
	b _08035F90
_08035F7E:
	adds r0, r5, #0
	adds r0, #0x20
	adds r1, r4, #0
	subs r1, #0x20
	b _08035FB2
_08035F88:
	adds r0, r5, #0
	subs r0, #0x1c
	adds r1, r4, #0
	subs r1, #0x2e
_08035F90:
	movs r2, #0x2e
	bl ParticleSet
	b _08035FC2
_08035F98:
	adds r0, r5, #0
	adds r0, #0x40
	adds r1, r4, #0
	subs r1, #0x40
	b _08035FB2
_08035FA2:
	adds r0, r5, #0
	adds r0, #0x58
	adds r1, r4, #0
	b _08035FB2
_08035FAA:
	adds r0, r5, #0
	subs r0, #0x5a
	adds r1, r4, #0
	adds r1, #0x10
_08035FB2:
	movs r2, #0x2f
	bl ParticleSet
	b _08035FC2
_08035FBA:
	ldr r0, _08036000 @ =gCurrentSprite
	adds r0, #0x2e
	movs r1, #0xff
	strb r1, [r0]
_08035FC2:
	ldr r6, _08036000 @ =gCurrentSprite
	adds r1, r6, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #4
	bne _08035FF8
	adds r0, r6, #0
	adds r0, #0x24
	movs r1, #0x41
	strb r1, [r0]
	adds r1, r4, #0
	subs r1, #0xa0
	adds r0, r5, #0
	movs r2, #0x2f
	bl ParticleSet
	movs r0, #0x1b
	movs r1, #7
	bl PlayMusic
_08035FF8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036000: .4byte gCurrentSprite

	thumb_func_start BoxFirstJumpInit
BoxFirstJumpInit: @ 0x08036004
	push {lr}
	ldr r1, _08036038 @ =gSubSpriteData1
	ldr r0, _0803603C @ =0x08342D98
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _08036040 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x42
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	ldrh r1, [r3]
	ldr r0, _08036044 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r3]
	ldr r0, _08036048 @ =0x00000265
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036038: .4byte gSubSpriteData1
_0803603C: .4byte 0x08342D98
_08036040: .4byte gCurrentSprite
_08036044: .4byte 0x0000FDFF
_08036048: .4byte 0x00000265

	thumb_func_start BoxFirstJump
BoxFirstJump: @ 0x0803604C
	push {r4, r5, lr}
	ldr r4, _08036090 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r1, _08036094 @ =0x083420B4
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _08036098 @ =0x00007FFF
	cmp r1, r0
	bne _080360A4
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x19
	strb r0, [r1]
	ldr r1, _0803609C @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	ldrh r1, [r1, #0xa]
	adds r1, #0xb4
	movs r2, #0x35
	bl ParticleSet
	ldr r0, _080360A0 @ =0x00000266
	bl SoundPlay
	movs r0, #0x3c
	movs r1, #0x81
	bl ScreenShakeStartVertical
	b _080360B8
	.align 2, 0
_08036090: .4byte gCurrentSprite
_08036094: .4byte 0x083420B4
_08036098: .4byte 0x00007FFF
_0803609C: .4byte gSubSpriteData1
_080360A0: .4byte 0x00000266
_080360A4:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldr r1, _080360C0 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	adds r0, r0, r3
	strh r0, [r1, #8]
	ldrh r0, [r1, #0xa]
	subs r0, #0xa
	strh r0, [r1, #0xa]
_080360B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080360C0: .4byte gSubSpriteData1

	thumb_func_start BoxWaitingToRunInit
BoxWaitingToRunInit: @ 0x080360C4
	push {lr}
	ldr r1, _080360EC @ =gSubSpriteData1
	ldr r0, _080360F0 @ =0x08342F60
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r0, _080360F4 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x18
	strb r1, [r2]
	adds r0, #0x2e
	strb r3, [r0]
	ldr r0, _080360F8 @ =0x0000026A
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_080360EC: .4byte gSubSpriteData1
_080360F0: .4byte 0x08342F60
_080360F4: .4byte gCurrentSprite
_080360F8: .4byte 0x0000026A

	thumb_func_start BoxWaitingToRun
BoxWaitingToRun: @ 0x080360FC
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08036120
	ldr r1, _08036138 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08036120
	adds r1, #0x24
	movs r0, #0x19
	strb r0, [r1]
_08036120:
	ldr r1, _08036138 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08036132
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
_08036132:
	pop {r0}
	bx r0
	.align 2, 0
_08036138: .4byte gCurrentSprite

	thumb_func_start BoxSlowRunningInit
BoxSlowRunningInit: @ 0x0803613C
	push {lr}
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldr r0, _08036158 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036164
	ldr r1, _0803615C @ =gSubSpriteData1
	ldr r0, _08036160 @ =0x08342ED8
	b _08036168
	.align 2, 0
_08036158: .4byte gCurrentSprite
_0803615C: .4byte gSubSpriteData1
_08036160: .4byte 0x08342ED8
_08036164:
	ldr r1, _08036184 @ =gSubSpriteData1
	ldr r0, _08036188 @ =0x08342E48
_08036168:
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r0, _0803618C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x1a
	strb r1, [r2]
	adds r0, #0x2e
	strb r3, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08036184: .4byte gSubSpriteData1
_08036188: .4byte 0x08342E48
_0803618C: .4byte gCurrentSprite

	thumb_func_start BoxSlowRun
BoxSlowRun: @ 0x08036190
	push {r4, r5, lr}
	ldr r0, _080361F0 @ =gSubSpriteData1
	ldr r0, [r0, #4]
	ldr r1, _080361F4 @ =0x00FFFFFF
	ands r0, r1
	ldr r1, _080361F8 @ =0x00010003
	cmp r0, r1
	bne _080361A6
	ldr r0, _080361FC @ =0x00000262
	bl SoundPlay
_080361A6:
	ldr r5, _08036200 @ =gCurrentSprite
	adds r4, r5, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	movs r1, #0x37
	bl BoxXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080361EA
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080361D8
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _080361D8
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x1b
	strb r0, [r1]
_080361D8:
	ldr r1, _08036200 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _080361EA
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
_080361EA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080361F0: .4byte gSubSpriteData1
_080361F4: .4byte 0x00FFFFFF
_080361F8: .4byte 0x00010003
_080361FC: .4byte 0x00000262
_08036200: .4byte gCurrentSprite

	thumb_func_start BoxFastRunInit
BoxFastRunInit: @ 0x08036204
	push {lr}
	ldr r2, _0803621C @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036228
	ldr r1, _08036220 @ =gSubSpriteData1
	ldr r0, _08036224 @ =0x08342F08
	b _0803622C
	.align 2, 0
_0803621C: .4byte gCurrentSprite
_08036220: .4byte gSubSpriteData1
_08036224: .4byte 0x08342F08
_08036228:
	ldr r1, _08036248 @ =gSubSpriteData1
	ldr r0, _0803624C @ =0x08342E78
_0803622C:
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
_08036248: .4byte gSubSpriteData1
_0803624C: .4byte 0x08342E78

	thumb_func_start BoxFastRun
BoxFastRun: @ 0x08036250
	push {r4, lr}
	ldr r4, _08036284 @ =gSubSpriteData1
	ldr r0, [r4, #4]
	ldr r1, _08036288 @ =0x00FFFFFF
	ands r0, r1
	ldr r1, _0803628C @ =0x00010003
	cmp r0, r1
	bne _08036266
	ldr r0, _08036290 @ =0x00000262
	bl SoundPlay
_08036266:
	movs r0, #8
	movs r1, #0x37
	bl BoxXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080362CC
	ldr r2, _08036294 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _08036298
	subs r0, #1
	b _080362DC
	.align 2, 0
_08036284: .4byte gSubSpriteData1
_08036288: .4byte 0x00FFFFFF
_0803628C: .4byte 0x00010003
_08036290: .4byte 0x00000262
_08036294: .4byte gCurrentSprite
_08036298:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080362B8
	ldrh r0, [r4, #0xa]
	subs r0, #0xc8
	ldr r1, _080362B4 @ =gSamusData
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	ble _080362CC
	b _080362C4
	.align 2, 0
_080362B4: .4byte gSamusData
_080362B8:
	ldrh r0, [r4, #0xa]
	adds r0, #0xc8
	ldr r1, _080362E4 @ =gSamusData
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bge _080362CC
_080362C4:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1d
	strb r0, [r1]
_080362CC:
	ldr r1, _080362E8 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _080362DE
	adds r1, #0x24
	movs r0, #0x3b
_080362DC:
	strb r0, [r1]
_080362DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080362E4: .4byte gSamusData
_080362E8: .4byte gCurrentSprite

	thumb_func_start BoxSkiddingInit
BoxSkiddingInit: @ 0x080362EC
	push {lr}
	ldr r2, _08036304 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036310
	ldr r1, _08036308 @ =gSubSpriteData1
	ldr r0, _0803630C @ =0x08342FC8
	b _08036314
	.align 2, 0
_08036304: .4byte gCurrentSprite
_08036308: .4byte gSubSpriteData1
_0803630C: .4byte 0x08342FC8
_08036310:
	ldr r1, _08036334 @ =gSubSpriteData1
	ldr r0, _08036338 @ =0x08342FA8
_08036314:
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
	ldr r0, _0803633C @ =0x00000263
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036334: .4byte gSubSpriteData1
_08036338: .4byte 0x08342FA8
_0803633C: .4byte 0x00000263

	thumb_func_start BoxSkidding
BoxSkidding: @ 0x08036340
	push {r4, r5, lr}
	ldr r4, _0803638C @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	lsrs r0, r0, #2
	movs r1, #0x1f
	cmp r0, #5
	bls _08036354
	movs r1, #0x37
_08036354:
	bl BoxXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08036384
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08036372
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1f
	strb r0, [r1]
_08036372:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08036384
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3b
	strb r0, [r1]
_08036384:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803638C: .4byte gCurrentSprite

	thumb_func_start BoxStopSkiddingInit
BoxStopSkiddingInit: @ 0x08036390
	push {lr}
	ldr r2, _080363A8 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080363B4
	ldr r1, _080363AC @ =gSubSpriteData1
	ldr r0, _080363B0 @ =0x08342FD8
	b _080363B8
	.align 2, 0
_080363A8: .4byte gCurrentSprite
_080363AC: .4byte gSubSpriteData1
_080363B0: .4byte 0x08342FD8
_080363B4:
	ldr r1, _080363CC @ =gSubSpriteData1
	ldr r0, _080363D0 @ =0x08342FB8
_080363B8:
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
_080363CC: .4byte gSubSpriteData1
_080363D0: .4byte 0x08342FB8

	thumb_func_start BoxStopSkidding
BoxStopSkidding: @ 0x080363D4
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080363F4
	ldr r1, _080363F0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x3b
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #3
	b _08036404
	.align 2, 0
_080363F0: .4byte gCurrentSprite
_080363F4:
	ldr r1, _0803640C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08036406
	adds r1, #0x24
	movs r0, #0x3b
_08036404:
	strb r0, [r1]
_08036406:
	pop {r0}
	bx r0
	.align 2, 0
_0803640C: .4byte gCurrentSprite

	thumb_func_start BoxBonkingInit
BoxBonkingInit: @ 0x08036410
	push {lr}
	ldr r1, _08036454 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	subs r0, #0x10
	movs r3, #0
	movs r2, #0
	strh r0, [r1, #8]
	ldr r0, _08036458 @ =0x08342D98
	str r0, [r1]
	strb r3, [r1, #6]
	strh r2, [r1, #4]
	ldr r2, _0803645C @ =gCurrentSprite
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
	ldr r0, _08036460 @ =0x00000267
	bl SoundPlay
	movs r0, #0x14
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	pop {r0}
	bx r0
	.align 2, 0
_08036454: .4byte gSubSpriteData1
_08036458: .4byte 0x08342D98
_0803645C: .4byte gCurrentSprite
_08036460: .4byte 0x00000267

	thumb_func_start BoxBonking
BoxBonking: @ 0x08036464
	push {r4, r5, r6, r7, lr}
	ldr r4, _08036488 @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _0803648C @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08036494
	strh r1, [r4, #8]
	ldr r0, _08036490 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x4b
	strb r1, [r0]
	b _080364F8
	.align 2, 0
_08036488: .4byte gSubSpriteData1
_0803648C: .4byte gPreviousVerticalCollisionCheck
_08036490: .4byte gCurrentSprite
_08036494:
	ldr r2, _080364C0 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r3, [r0]
	ldr r6, _080364C4 @ =0x0834210C
	lsls r0, r3, #1
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _080364C8 @ =0x00007FFF
	cmp r1, r0
	bne _080364CC
	subs r1, r3, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r4, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _080364D6
	.align 2, 0
_080364C0: .4byte gCurrentSprite
_080364C4: .4byte 0x0834210C
_080364C8: .4byte 0x00007FFF
_080364CC:
	adds r0, r3, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #8]
	adds r0, r0, r5
_080364D6:
	strh r0, [r4, #8]
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080364F0
	ldr r1, _080364EC @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	adds r0, #6
	b _080364F6
	.align 2, 0
_080364EC: .4byte gSubSpriteData1
_080364F0:
	ldr r1, _08036500 @ =gSubSpriteData1
	ldrh r0, [r1, #0xa]
	subs r0, #6
_080364F6:
	strh r0, [r1, #0xa]
_080364F8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036500: .4byte gSubSpriteData1

	thumb_func_start BoxLandingFromBonkInit
BoxLandingFromBonkInit: @ 0x08036504
	push {lr}
	ldr r1, _08036534 @ =gSubSpriteData1
	ldr r0, _08036538 @ =0x08342DA8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _0803653C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x4c
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x2f
	strb r2, [r0]
	adds r0, #2
	strb r2, [r0]
	ldr r0, _08036540 @ =0x00000266
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036534: .4byte gSubSpriteData1
_08036538: .4byte 0x08342DA8
_0803653C: .4byte gCurrentSprite
_08036540: .4byte 0x00000266

	thumb_func_start BoxLandingFromBonk
BoxLandingFromBonk: @ 0x08036544
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08036556
	ldr r0, _0803655C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x17
	strb r1, [r0]
_08036556:
	pop {r0}
	bx r0
	.align 2, 0
_0803655C: .4byte gCurrentSprite

	thumb_func_start BoxLandingInit
BoxLandingInit: @ 0x08036560
	push {lr}
	ldr r1, _08036588 @ =gSubSpriteData1
	ldr r0, _0803658C @ =0x08342DA8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r3, #0
	strh r0, [r1, #4]
	ldr r0, _08036590 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x3a
	strb r1, [r2]
	adds r0, #0x31
	strb r3, [r0]
	ldr r0, _08036594 @ =0x00000266
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036588: .4byte gSubSpriteData1
_0803658C: .4byte 0x08342DA8
_08036590: .4byte gCurrentSprite
_08036594: .4byte 0x00000266

	thumb_func_start BoxLanding
BoxLanding: @ 0x08036598
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080365CC
	ldr r1, _080365B4 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x2f
	ldrb r0, [r3]
	cmp r0, #0
	bne _080365B8
	adds r1, #0x24
	movs r0, #0x27
	b _080365CA
	.align 2, 0
_080365B4: .4byte gCurrentSprite
_080365B8:
	subs r0, #1
	strb r0, [r3]
	movs r2, #0x7f
	ands r2, r0
	cmp r2, #0
	bne _080365C6
	strb r2, [r3]
_080365C6:
	adds r1, #0x24
	movs r0, #0x3b
_080365CA:
	strb r0, [r1]
_080365CC:
	pop {r0}
	bx r0

	thumb_func_start BoxFinishedCrawlingInit
BoxFinishedCrawlingInit: @ 0x080365D0
	push {r4, lr}
	ldr r2, _08036600 @ =gSubSpriteData1
	ldr r0, _08036604 @ =0x08342F38
	str r0, [r2]
	ldr r1, _08036608 @ =gCurrentSprite
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
_08036600: .4byte gSubSpriteData1
_08036604: .4byte 0x08342F38
_08036608: .4byte gCurrentSprite

	thumb_func_start BoxFinishedCrawling
BoxFinishedCrawling: @ 0x0803660C
	push {r4, r5, lr}
	ldr r4, _0803662C @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	cmp r0, #1
	bls _08036630
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _08036662
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	b _08036662
	.align 2, 0
_0803662C: .4byte gCurrentSprite
_08036630:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08036662
	bl SpriteUtilCheckSamusOnCeilingLadder
	cmp r0, #0
	beq _08036648
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3b
	b _08036660
_08036648:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803665A
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3b
	b _08036660
_0803665A:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x19
_08036660:
	strb r0, [r1]
_08036662:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start BoxJumpWarningInit
BoxJumpWarningInit: @ 0x08036668
	push {r4, lr}
	ldr r0, _0803668C @ =gSamusData
	ldrh r4, [r0, #0x16]
	ldr r0, _08036690 @ =gSubSpriteData1
	ldrh r2, [r0, #0xa]
	adds r1, r2, #0
	subs r1, #0x78
	adds r3, r0, #0
	cmp r1, r4
	bge _08036694
	adds r0, r2, #0
	adds r0, #0x78
	cmp r0, r4
	ble _08036694
	bl BoxStoppingToFireBombInit
	b _080366A6
	.align 2, 0
_0803668C: .4byte gSamusData
_08036690: .4byte gSubSpriteData1
_08036694:
	ldr r0, _080366AC @ =0x08342DC8
	str r0, [r3]
	movs r0, #0
	strb r0, [r3, #6]
	strh r0, [r3, #4]
	ldr r0, _080366B0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x3c
	strb r1, [r0]
_080366A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080366AC: .4byte 0x08342DC8
_080366B0: .4byte gCurrentSprite

	thumb_func_start BoxJumpWarning
BoxJumpWarning: @ 0x080366B4
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _080366C6
	ldr r0, _080366CC @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x3d
	strb r1, [r0]
_080366C6:
	pop {r0}
	bx r0
	.align 2, 0
_080366CC: .4byte gCurrentSprite

	thumb_func_start BoxJumpingInit
BoxJumpingInit: @ 0x080366D0
	push {r4, r5, lr}
	ldr r1, _0803670C @ =gSubSpriteData1
	ldr r0, _08036710 @ =0x08342D98
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	movs r2, #0
	strh r0, [r1, #4]
	ldr r3, _08036714 @ =gCurrentSprite
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
	bne _0803678C
	bl SpriteUtilCheckSamusOnCeilingLadder
	cmp r0, #0
	beq _08036718
	bl SpriteUtilMakeSpriteFaceSamusDirection
	b _0803671C
	.align 2, 0
_0803670C: .4byte gSubSpriteData1
_08036710: .4byte 0x08342D98
_08036714: .4byte gCurrentSprite
_08036718:
	bl SpriteUtilMakeSpriteFaceAwayFromSamusDirection
_0803671C:
	ldr r4, _08036750 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08036764
	ldr r1, _08036754 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	ldr r2, _08036758 @ =0xFFFFFED4
	adds r0, r0, r2
	ldrh r1, [r1, #0xa]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803675C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803678C
	ldrh r1, [r4]
	ldr r0, _08036760 @ =0x0000FDFF
	ands r0, r1
	b _08036782
	.align 2, 0
_08036750: .4byte gCurrentSprite
_08036754: .4byte gSubSpriteData1
_08036758: .4byte 0xFFFFFED4
_0803675C: .4byte gPreviousCollisionCheck
_08036760: .4byte 0x0000FDFF
_08036764:
	ldr r1, _08036798 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	ldr r2, _0803679C @ =0xFFFFFED4
	adds r0, r0, r2
	ldrh r1, [r1, #0xa]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _080367A0 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803678C
	ldrh r1, [r4]
	adds r0, r5, #0
	orrs r0, r1
_08036782:
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0x83
	strb r0, [r1]
_0803678C:
	ldr r0, _080367A4 @ =0x00000265
	bl SoundPlay
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036798: .4byte gSubSpriteData1
_0803679C: .4byte 0xFFFFFED4
_080367A0: .4byte gPreviousCollisionCheck
_080367A4: .4byte 0x00000265

	thumb_func_start BoxJumping
BoxJumping: @ 0x080367A8
	push {r4, r5, lr}
	ldr r4, _080367D0 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r1, _080367D4 @ =0x083420E4
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _080367D8 @ =0x00007FFF
	cmp r1, r0
	bne _080367DC
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x39
	strb r0, [r1]
	b _080367F2
	.align 2, 0
_080367D0: .4byte gCurrentSprite
_080367D4: .4byte 0x083420E4
_080367D8: .4byte 0x00007FFF
_080367DC:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldr r1, _080367F8 @ =gSubSpriteData1
	ldrh r0, [r1, #8]
	adds r0, r0, r3
	strh r0, [r1, #8]
	movs r0, #0xc
	movs r1, #0x37
	bl BoxXMovement
_080367F2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080367F8: .4byte gSubSpriteData1

	thumb_func_start BoxStoppingToFireBombInit
BoxStoppingToFireBombInit: @ 0x080367FC
	push {r4, lr}
	ldr r2, _0803682C @ =gSubSpriteData1
	ldr r0, _08036830 @ =0x08342F38
	str r0, [r2]
	ldr r1, _08036834 @ =gCurrentSprite
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
_0803682C: .4byte gSubSpriteData1
_08036830: .4byte 0x08342F38
_08036834: .4byte gCurrentSprite

	thumb_func_start BoxStoppingToFireBomb
BoxStoppingToFireBomb: @ 0x08036838
	push {r4, r5, lr}
	ldr r5, _08036858 @ =gCurrentSprite
	adds r4, r5, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	cmp r0, #1
	bls _0803685C
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _0803686C
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0803686C
	.align 2, 0
_08036858: .4byte gCurrentSprite
_0803685C:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _0803686C
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
_0803686C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxLoweringToFireBombInit
BoxLoweringToFireBombInit: @ 0x08036874
	push {lr}
	ldr r1, _08036898 @ =gSubSpriteData1
	ldr r0, _0803689C @ =0x08342FE8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _080368A0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2a
	strb r1, [r0]
	movs r0, #0x9a
	lsls r0, r0, #2
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036898: .4byte gSubSpriteData1
_0803689C: .4byte 0x08342FE8
_080368A0: .4byte gCurrentSprite

	thumb_func_start BoxLoweringToFireBomb
BoxLoweringToFireBomb: @ 0x080368A4
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationEnded
	cmp r0, #0
	beq _080368C2
	ldr r0, _080368C8 @ =gCurrentSprite
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x2c
	strb r1, [r0]
	ldr r0, _080368CC @ =gSubSpriteData1
	ldr r1, _080368D0 @ =0x08343028
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
_080368C2:
	pop {r0}
	bx r0
	.align 2, 0
_080368C8: .4byte gCurrentSprite
_080368CC: .4byte gSubSpriteData1
_080368D0: .4byte 0x08343028

	thumb_func_start BoxFiringBomb
BoxFiringBomb: @ 0x080368D4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	bl SpriteUtilHasSubSprite1AnimationEnded
	adds r6, r0, #0
	cmp r6, #0
	beq _08036910
	ldr r0, _08036900 @ =gCurrentSprite
	adds r0, #0x24
	movs r2, #0
	movs r1, #0x2e
	strb r1, [r0]
	ldr r0, _08036904 @ =gSubSpriteData1
	ldr r1, _08036908 @ =0x08343048
	str r1, [r0]
	strb r2, [r0, #6]
	strh r2, [r0, #4]
	ldr r0, _0803690C @ =0x00000269
	bl SoundPlay
	b _0803697A
	.align 2, 0
_08036900: .4byte gCurrentSprite
_08036904: .4byte gSubSpriteData1
_08036908: .4byte 0x08343048
_0803690C: .4byte 0x00000269
_08036910:
	ldr r3, _08036948 @ =gCurrentSprite
	ldrh r5, [r3, #2]
	ldrh r4, [r3, #4]
	ldr r0, _0803694C @ =gSubSpriteData1
	ldr r0, [r0, #4]
	ldr r1, _08036950 @ =0x00FFFFFF
	ands r0, r1
	ldr r1, _08036954 @ =0x00020001
	cmp r0, r1
	bne _0803697A
	ldr r0, _08036958 @ =gSamusData
	ldrh r0, [r0, #0x16]
	cmp r4, r0
	bls _0803695C
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r5, #0
	subs r0, #0x64
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x71
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0803697A
	.align 2, 0
_08036948: .4byte gCurrentSprite
_0803694C: .4byte gSubSpriteData1
_08036950: .4byte 0x00FFFFFF
_08036954: .4byte 0x00020001
_08036958: .4byte gSamusData
_0803695C:
	ldrb r2, [r3, #0x1f]
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, r5, #0
	subs r0, #0x64
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0x71
	movs r1, #0
	bl SpriteSpawnSecondary
_0803697A:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxDoneFiringBomb
BoxDoneFiringBomb: @ 0x08036984
	push {lr}
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08036996
	ldr r0, _0803699C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x17
	strb r1, [r0]
_08036996:
	pop {r0}
	bx r0
	.align 2, 0
_0803699C: .4byte gCurrentSprite

	thumb_func_start BoxDyingInit
BoxDyingInit: @ 0x080369A0
	ldr r1, _080369CC @ =gCurrentSprite
	ldr r0, _080369D0 @ =0x08347BD8
	str r0, [r1, #0x18]
	movs r3, #0
	strb r3, [r1, #0x1c]
	movs r2, #0
	strh r3, [r1, #0x16]
	adds r0, r1, #0
	adds r0, #0x2e
	strb r2, [r0]
	adds r0, #3
	strb r2, [r0]
	adds r1, #0x24
	movs r0, #0x44
	strb r0, [r1]
	ldr r0, _080369D4 @ =gSubSpriteData1
	ldr r1, _080369D8 @ =0x08342DF0
	str r1, [r0]
	strb r2, [r0, #6]
	strh r3, [r0, #4]
	bx lr
	.align 2, 0
_080369CC: .4byte gCurrentSprite
_080369D0: .4byte 0x08347BD8
_080369D4: .4byte gSubSpriteData1
_080369D8: .4byte 0x08342DF0

	thumb_func_start BoxDying
BoxDying: @ 0x080369DC
	push {r4, r5, lr}
	ldr r1, _08036A08 @ =gCurrentSprite
	adds r5, r1, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	cmp r0, #0
	bne _08036A1C
	ldr r4, _08036A0C @ =gSubSpriteData1
	ldrh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08036A10 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08036A14
	strh r1, [r4, #8]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08036A2E
	.align 2, 0
_08036A08: .4byte gCurrentSprite
_08036A0C: .4byte gSubSpriteData1
_08036A10: .4byte gPreviousVerticalCollisionCheck
_08036A14:
	ldrh r0, [r4, #8]
	adds r0, #0x10
	strh r0, [r4, #8]
	b _08036A2E
_08036A1C:
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _08036A2E
	adds r1, #0x24
	movs r0, #0x45
	strb r0, [r1]
_08036A2E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start BoxMovingToFinalJumpInit
BoxMovingToFinalJumpInit: @ 0x08036A34
	push {r4, lr}
	ldr r4, _08036A80 @ =gCurrentSprite
	ldr r0, _08036A84 @ =0x08347BD8
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x46
	strb r0, [r1]
	movs r0, #0x77
	bl SpriteUtilFindPrimary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08036A88 @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r1, [r1, #4]
	strh r1, [r4, #8]
	adds r2, r4, #0
	adds r2, #0x2f
	strb r0, [r2]
	ldr r2, _08036A8C @ =gSubSpriteData1
	ldrh r0, [r2, #0xa]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, r1
	bls _08036A98
	ldr r0, _08036A90 @ =0x08342E18
	str r0, [r2]
	ldrh r1, [r4]
	ldr r0, _08036A94 @ =0x0000FDFF
	ands r0, r1
	b _08036AA6
	.align 2, 0
_08036A80: .4byte gCurrentSprite
_08036A84: .4byte 0x08347BD8
_08036A88: .4byte gSpriteData
_08036A8C: .4byte gSubSpriteData1
_08036A90: .4byte 0x08342E18
_08036A94: .4byte 0x0000FDFF
_08036A98:
	ldr r0, _08036AB8 @ =0x08342EA8
	str r0, [r2]
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
_08036AA6:
	strh r0, [r4]
	ldr r1, _08036ABC @ =gSubSpriteData1
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036AB8: .4byte 0x08342EA8
_08036ABC: .4byte gSubSpriteData1

	thumb_func_start BoxMovingToFinalJump
BoxMovingToFinalJump: @ 0x08036AC0
	push {r4, r5, lr}
	ldr r0, _08036AFC @ =gSubSpriteData1
	ldr r0, [r0, #4]
	ldr r1, _08036B00 @ =0x00FFFFFF
	ands r0, r1
	ldr r1, _08036B04 @ =0x00010003
	cmp r0, r1
	bne _08036AD6
	ldr r0, _08036B08 @ =0x00000262
	bl SoundPlay
_08036AD6:
	ldr r0, _08036B0C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	ldr r5, _08036B10 @ =gCurrentSprite
	cmp r0, #0
	bne _08036B1A
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08036B14
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0xb
	strb r0, [r1]
	b _08036B1A
	.align 2, 0
_08036AFC: .4byte gSubSpriteData1
_08036B00: .4byte 0x00FFFFFF
_08036B04: .4byte 0x00010003
_08036B08: .4byte 0x00000262
_08036B0C: .4byte gFrameCounter8Bit
_08036B10: .4byte gCurrentSprite
_08036B14:
	adds r0, r5, #0
	adds r0, #0x20
	strb r1, [r0]
_08036B1A:
	ldr r4, _08036B38 @ =gSubSpriteData1
	ldrh r3, [r4, #0xa]
	ldr r0, _08036B3C @ =0x0000FFF8
	ldrh r2, [r5, #8]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _08036B40
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x47
	strb r0, [r1]
	b _08036B54
	.align 2, 0
_08036B38: .4byte gSubSpriteData1
_08036B3C: .4byte 0x0000FFF8
_08036B40:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036B50
	adds r0, r3, #2
	b _08036B52
_08036B50:
	subs r0, r3, #2
_08036B52:
	strh r0, [r4, #0xa]
_08036B54:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxWaitingForFinalJumpInit
BoxWaitingForFinalJumpInit: @ 0x08036B5C
	push {lr}
	ldr r1, _08036B7C @ =gSubSpriteData1
	ldr r0, _08036B80 @ =0x08342DF0
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08036B84 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x48
	strb r1, [r0]
	ldr r0, _08036B88 @ =0x00000276
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036B7C: .4byte gSubSpriteData1
_08036B80: .4byte 0x08342DF0
_08036B84: .4byte gCurrentSprite
_08036B88: .4byte 0x00000276

	thumb_func_start BoxWaitingForFinalJump
BoxWaitingForFinalJump: @ 0x08036B8C
	push {r4, lr}
	ldr r0, _08036BB4 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	ldr r4, _08036BB8 @ =gCurrentSprite
	cmp r0, #0
	bne _08036BC2
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08036BBC
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #0xb
	strb r0, [r1]
	b _08036BC2
	.align 2, 0
_08036BB4: .4byte gFrameCounter8Bit
_08036BB8: .4byte gCurrentSprite
_08036BBC:
	adds r0, r4, #0
	adds r0, #0x20
	strb r1, [r0]
_08036BC2:
	ldrh r0, [r4, #4]
	lsrs r0, r0, #2
	ldr r1, _08036BF0 @ =gBg1XPosition
	ldrh r1, [r1]
	lsrs r1, r1, #2
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08036BF4 @ =0xFFE70000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0xbe
	bhi _08036BEA
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08036BEA
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x49
	strb r0, [r1]
_08036BEA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036BF0: .4byte gBg1XPosition
_08036BF4: .4byte 0xFFE70000

	thumb_func_start BoxCrouchingForFinalJumpInit
BoxCrouchingForFinalJumpInit: @ 0x08036BF8
	ldr r1, _08036C10 @ =gSubSpriteData1
	ldr r0, _08036C14 @ =0x08342DC8
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r0, _08036C18 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x4a
	strb r1, [r0]
	bx lr
	.align 2, 0
_08036C10: .4byte gSubSpriteData1
_08036C14: .4byte 0x08342DC8
_08036C18: .4byte gCurrentSprite

	thumb_func_start BoxCrouchingForFinalJump
BoxCrouchingForFinalJump: @ 0x08036C1C
	push {lr}
	ldr r0, _08036C40 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08036C4E
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08036C48
	ldr r0, _08036C44 @ =gCurrentSprite
	adds r0, #0x20
	movs r1, #0xb
	b _08036C4C
	.align 2, 0
_08036C40: .4byte gFrameCounter8Bit
_08036C44: .4byte gCurrentSprite
_08036C48:
	ldr r0, _08036C68 @ =gCurrentSprite
	adds r0, #0x20
_08036C4C:
	strb r1, [r0]
_08036C4E:
	bl SpriteUtilHasSubSprite1AnimationNearlyEnded
	cmp r0, #0
	beq _08036C62
	ldr r0, _08036C68 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x4d
	strb r1, [r0]
	bl unk_36c4
_08036C62:
	pop {r0}
	bx r0
	.align 2, 0
_08036C68: .4byte gCurrentSprite

	thumb_func_start BoxFinalJumpInit
BoxFinalJumpInit: @ 0x08036C6C
	push {lr}
	ldr r1, _08036C94 @ =gSubSpriteData1
	ldr r0, _08036C98 @ =0x08342D98
	str r0, [r1]
	movs r0, #0
	strb r0, [r1, #6]
	strh r0, [r1, #4]
	ldr r1, _08036C9C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x4e
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x1e
	strb r0, [r1]
	ldr r0, _08036CA0 @ =0x00000277
	bl SoundPlay
	pop {r0}
	bx r0
	.align 2, 0
_08036C94: .4byte gSubSpriteData1
_08036C98: .4byte 0x08342D98
_08036C9C: .4byte gCurrentSprite
_08036CA0: .4byte 0x00000277

	thumb_func_start BoxFinalJump
BoxFinalJump: @ 0x08036CA4
	push {r4, lr}
	ldr r0, _08036CCC @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	ldr r4, _08036CD0 @ =gCurrentSprite
	cmp r0, #0
	bne _08036CDA
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08036CD4
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #0xb
	strb r0, [r1]
	b _08036CDA
	.align 2, 0
_08036CCC: .4byte gFrameCounter8Bit
_08036CD0: .4byte gCurrentSprite
_08036CD4:
	adds r0, r4, #0
	adds r0, #0x20
	strb r1, [r0]
_08036CDA:
	ldr r0, _08036D14 @ =gSubSpriteData1
	ldrh r1, [r0, #8]
	subs r1, #0x28
	strh r1, [r0, #8]
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08036D0C
	ldr r2, _08036D18 @ =gSpriteData
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	movs r1, #0x18
	strb r1, [r0]
	strh r3, [r4]
_08036D0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036D14: .4byte gSubSpriteData1
_08036D18: .4byte gSpriteData

	thumb_func_start BoxCrawlingInit
BoxCrawlingInit: @ 0x08036D1C
	push {lr}
	ldr r2, _08036D34 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036D40
	ldr r1, _08036D38 @ =gSubSpriteData1
	ldr r0, _08036D3C @ =0x08342EA8
	b _08036D44
	.align 2, 0
_08036D34: .4byte gCurrentSprite
_08036D38: .4byte gSubSpriteData1
_08036D3C: .4byte 0x08342EA8
_08036D40:
	ldr r1, _08036D58 @ =gSubSpriteData1
	ldr r0, _08036D5C @ =0x08342E18
_08036D44:
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
_08036D58: .4byte gSubSpriteData1
_08036D5C: .4byte 0x08342E18

	thumb_func_start BoxCrawling
BoxCrawling: @ 0x08036D60
	push {lr}
	movs r0, #1
	movs r1, #7
	bl BoxXMovement
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxPartSetBoxWorkVar2
BoxPartSetBoxWorkVar2: @ 0x08036D70
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	ldr r2, _08036D94 @ =gSpriteData
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, r3
	bhs _08036D8E
	strb r3, [r1]
_08036D8E:
	pop {r0}
	bx r0
	.align 2, 0
_08036D94: .4byte gSpriteData

	thumb_func_start BoxPartCenterSetImmunity
BoxPartCenterSetImmunity: @ 0x08036D98
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _08036DC0 @ =gSpriteData
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #0x29
	adds r3, r1, #0
	cmp r0, #0x19
	bhi _08036E64
	lsls r0, r0, #2
	ldr r1, _08036DC4 @ =_08036DC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036DC0: .4byte gSpriteData
_08036DC4: .4byte _08036DC8
_08036DC8: @ jump table
	.4byte _08036E30 @ case 0
	.4byte _08036E30 @ case 1
	.4byte _08036E64 @ case 2
	.4byte _08036E30 @ case 3
	.4byte _08036E64 @ case 4
	.4byte _08036E64 @ case 5
	.4byte _08036E64 @ case 6
	.4byte _08036E64 @ case 7
	.4byte _08036E64 @ case 8
	.4byte _08036E64 @ case 9
	.4byte _08036E64 @ case 10
	.4byte _08036E64 @ case 11
	.4byte _08036E64 @ case 12
	.4byte _08036E64 @ case 13
	.4byte _08036E64 @ case 14
	.4byte _08036E64 @ case 15
	.4byte _08036E64 @ case 16
	.4byte _08036E64 @ case 17
	.4byte _08036E64 @ case 18
	.4byte _08036E64 @ case 19
	.4byte _08036E64 @ case 20
	.4byte _08036E64 @ case 21
	.4byte _08036E54 @ case 22
	.4byte _08036E54 @ case 23
	.4byte _08036E54 @ case 24
	.4byte _08036E54 @ case 25
_08036E30:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08036E64
	ldr r0, _08036E50 @ =gCurrentSprite
	adds r0, #0x34
	ldrb r2, [r0]
	movs r1, #0x40
	orrs r1, r2
	b _08036E6E
	.align 2, 0
_08036E50: .4byte gCurrentSprite
_08036E54:
	ldr r0, _08036E60 @ =gCurrentSprite
	adds r0, #0x34
	ldrb r2, [r0]
	movs r1, #0x40
	orrs r1, r2
	b _08036E6E
	.align 2, 0
_08036E60: .4byte gCurrentSprite
_08036E64:
	ldr r0, _08036E74 @ =gCurrentSprite
	adds r0, #0x34
	ldrb r2, [r0]
	movs r1, #0xbf
	ands r1, r2
_08036E6E:
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08036E74: .4byte gCurrentSprite

	thumb_func_start BoxPartRemoveIgnoreProjectiles
BoxPartRemoveIgnoreProjectiles: @ 0x08036E78
	ldr r2, _08036E84 @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _08036E88 @ =0x00007FFF
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08036E84: .4byte gCurrentSprite
_08036E88: .4byte 0x00007FFF

	thumb_func_start BoxPartInit
BoxPartInit: @ 0x08036E8C
	push {lr}
	ldr r2, _08036EC4 @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _08036EC8 @ =0x0000FFFB
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
	adds r3, r2, #0
	cmp r0, #6
	bhi _08036ECC
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #0xb
	b _08036ED2
	.align 2, 0
_08036EC4: .4byte gCurrentSprite
_08036EC8: .4byte 0x0000FFFB
_08036ECC:
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #0xd
_08036ED2:
	strb r0, [r1]
	ldrb r0, [r3, #0x1e]
	cmp r0, #0xb
	bls _08036EDC
	b _08036FE0
_08036EDC:
	lsls r0, r0, #2
	ldr r1, _08036EE8 @ =_08036EEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08036EE8: .4byte _08036EEC
_08036EEC: @ jump table
	.4byte _08036F1C @ case 0
	.4byte _08036FA8 @ case 1
	.4byte _08036F1C @ case 2
	.4byte _08036FA8 @ case 3
	.4byte _08036FA8 @ case 4
	.4byte _08036FA8 @ case 5
	.4byte _08036F40 @ case 6
	.4byte _08036FE0 @ case 7
	.4byte _08036FA8 @ case 8
	.4byte _08036F68 @ case 9
	.4byte _08036FA8 @ case 10
	.4byte _08036FA8 @ case 11
_08036F1C:
	ldr r0, _08036F38 @ =0x0000FFB8
	strh r0, [r3, #0xa]
	movs r0, #0x48
	strh r0, [r3, #0xc]
	ldr r0, _08036F3C @ =0x0000FFE0
	strh r0, [r3, #0xe]
	movs r0, #0x20
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x35
	movs r0, #2
	strb r0, [r1]
	subs r1, #0x10
	b _08036F7E
	.align 2, 0
_08036F38: .4byte 0x0000FFB8
_08036F3C: .4byte 0x0000FFE0
_08036F40:
	ldr r0, _08036F60 @ =0x0000FFD0
	strh r0, [r3, #0xa]
	movs r0, #0x40
	strh r0, [r3, #0xc]
	ldr r0, _08036F64 @ =0x0000FFE0
	strh r0, [r3, #0xe]
	movs r0, #0x20
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x35
	movs r0, #1
	strb r0, [r1]
	subs r1, #0x10
	movs r0, #2
	strb r0, [r1]
	b _08036FC8
	.align 2, 0
_08036F60: .4byte 0x0000FFD0
_08036F64: .4byte 0x0000FFE0
_08036F68:
	ldr r0, _08036F9C @ =0x0000FFE0
	strh r0, [r3, #0xa]
	movs r0, #0x20
	strh r0, [r3, #0xc]
	ldr r0, _08036FA0 @ =0x0000FFC0
	strh r0, [r3, #0xe]
	movs r0, #0x40
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #2
_08036F7E:
	strb r0, [r1]
	ldr r1, _08036FA4 @ =sSecondarySpriteStats
	ldrb r0, [r3, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r2, r3, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	b _08036FE4
	.align 2, 0
_08036F9C: .4byte 0x0000FFE0
_08036FA0: .4byte 0x0000FFC0
_08036FA4: .4byte sSecondarySpriteStats
_08036FA8:
	movs r2, #0
	ldr r1, _08036FD8 @ =0x0000FFFC
	strh r1, [r3, #0xa]
	movs r0, #4
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
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
_08036FC8:
	ldr r1, _08036FDC @ =sSecondarySpriteStats
	ldrb r0, [r3, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	b _08036FE4
	.align 2, 0
_08036FD8: .4byte 0x0000FFFC
_08036FDC: .4byte sSecondarySpriteStats
_08036FE0:
	movs r0, #0
	strh r0, [r3]
_08036FE4:
	bl BoxSyncSubSprites
	pop {r0}
	bx r0

	thumb_func_start BoxPartFrontLeftLeg
BoxPartFrontLeftLeg: @ 0x08036FEC
	push {r4, r5, r6, r7, lr}
	ldr r5, _08037010 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r6, [r0]
	ldr r0, _08037014 @ =gSpriteData
	lsls r1, r6, #3
	subs r1, r1, r6
	lsls r1, r1, #3
	adds r2, r1, r0
	ldrh r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08037018
	strh r1, [r5]
	b _0803709A
	.align 2, 0
_08037010: .4byte gCurrentSprite
_08037014: .4byte gSpriteData
_08037018:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0803709A
	ldrh r3, [r5, #2]
	ldrh r1, [r5, #4]
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x44
	bne _0803704E
	ldr r0, [r5, #0x18]
	ldr r7, _08037084 @ =0x083479F0
	cmp r0, r7
	beq _0803704E
	adds r0, r3, #0
	adds r0, #0x3c
	movs r2, #0x30
	bl ParticleSet
	str r7, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
_0803704E:
	ldr r1, _08037088 @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0803709A
	ldr r0, _0803708C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803709A
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08037094
	ldr r0, _08037090 @ =gCurrentSprite
	adds r0, #0x20
	movs r1, #0xb
	b _08037098
	.align 2, 0
_08037084: .4byte 0x083479F0
_08037088: .4byte gSpriteData
_0803708C: .4byte gFrameCounter8Bit
_08037090: .4byte gCurrentSprite
_08037094:
	ldr r0, _080370A0 @ =gCurrentSprite
	adds r0, #0x20
_08037098:
	strb r1, [r0]
_0803709A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080370A0: .4byte gCurrentSprite

	thumb_func_start BoxPartFrontRightLeg
BoxPartFrontRightLeg: @ 0x080370A4
	push {r4, r5, r6, r7, lr}
	ldr r5, _080370C8 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r6, [r0]
	ldr r0, _080370CC @ =gSpriteData
	lsls r1, r6, #3
	subs r1, r1, r6
	lsls r1, r1, #3
	adds r2, r1, r0
	ldrh r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080370D0
	strh r1, [r5]
	b _08037152
	.align 2, 0
_080370C8: .4byte gCurrentSprite
_080370CC: .4byte gSpriteData
_080370D0:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _08037152
	ldrh r3, [r5, #2]
	ldrh r1, [r5, #4]
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x44
	bne _08037106
	ldr r0, [r5, #0x18]
	ldr r7, _0803713C @ =0x08347AE8
	cmp r0, r7
	beq _08037106
	adds r0, r3, #0
	adds r0, #0x3c
	movs r2, #0x30
	bl ParticleSet
	str r7, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
_08037106:
	ldr r1, _08037140 @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08037152
	ldr r0, _08037144 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08037152
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0803714C
	ldr r0, _08037148 @ =gCurrentSprite
	adds r0, #0x20
	movs r1, #0xb
	b _08037150
	.align 2, 0
_0803713C: .4byte 0x08347AE8
_08037140: .4byte gSpriteData
_08037144: .4byte gFrameCounter8Bit
_08037148: .4byte gCurrentSprite
_0803714C:
	ldr r0, _08037158 @ =gCurrentSprite
	adds r0, #0x20
_08037150:
	strb r1, [r0]
_08037152:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037158: .4byte gCurrentSprite

	thumb_func_start BoxPartCenter
BoxPartCenter: @ 0x0803715C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r4, _0803718C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	mov sb, r0
	ldr r0, _08037190 @ =gSpriteData
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
	bne _08037194
	strh r1, [r4]
	b _080372A0
	.align 2, 0
_0803718C: .4byte gCurrentSprite
_08037190: .4byte gSpriteData
_08037194:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _080371A6
	b _080372A0
_080371A6:
	mov r7, r8
	adds r7, #0x2d
	ldrb r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080371E0
	ldr r0, _080371D4 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080372A0
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080371D8
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #0xc
	strb r0, [r1]
	b _080372A0
	.align 2, 0
_080371D4: .4byte gFrameCounter8Bit
_080371D8:
	adds r0, r4, #0
	adds r0, #0x20
	strb r6, [r0]
	b _080372A0
_080371E0:
	ldr r1, _08037220 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r5, [r0]
	ldrh r2, [r4, #2]
	ldrh r3, [r4, #4]
	mov r0, sb
	str r2, [sp]
	str r3, [sp, #4]
	bl BoxPartCenterSetImmunity
	ldrh r1, [r4, #0x14]
	ldr r2, [sp]
	ldr r3, [sp, #4]
	cmp r1, #0
	bne _08037224
	ldrb r1, [r7]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7]
	adds r0, r2, #0
	adds r0, #0x32
	adds r1, r3, #0
	movs r2, #0x2f
	bl ParticleSet
	mov r1, r8
	adds r1, #0x24
	movs r0, #0x43
	strb r0, [r1]
	b _08037282
	.align 2, 0
_08037220: .4byte sSecondarySpriteStats
_08037224:
	lsrs r0, r5, #2
	cmp r1, r0
	bhs _08037234
	ldr r0, [r4, #0x18]
	ldr r1, _08037230 @ =0x08347BC8
	b _0803723E
	.align 2, 0
_08037230: .4byte 0x08347BC8
_08037234:
	lsrs r0, r5, #1
	cmp r1, r0
	bhs _0803725C
	ldr r0, [r4, #0x18]
	ldr r1, _08037258 @ =0x08347BB8
_0803723E:
	cmp r0, r1
	beq _08037282
	str r1, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r6, [r4, #0x16]
	adds r0, r2, #0
	adds r0, #0x24
	adds r1, r3, #0
	movs r2, #0x30
	bl ParticleSet
	b _08037282
	.align 2, 0
_08037258: .4byte 0x08347BB8
_0803725C:
	ldrh r1, [r4, #0x14]
	lsls r0, r5, #1
	adds r0, r0, r5
	asrs r0, r0, #2
	cmp r1, r0
	bge _08037282
	ldr r0, [r4, #0x18]
	ldr r1, _080372B0 @ =0x08347BA8
	cmp r0, r1
	beq _08037282
	str r1, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r6, [r4, #0x16]
	adds r0, r2, #0
	adds r0, #0x24
	adds r1, r3, #0
	movs r2, #0x30
	bl ParticleSet
_08037282:
	ldr r0, _080372B4 @ =gCurrentSprite
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _080372A0
	mov r0, sb
	movs r1, #2
	bl BoxPartSetBoxWorkVar2
	movs r0, #0x9e
	lsls r0, r0, #2
	bl SoundPlay
_080372A0:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080372B0: .4byte 0x08347BA8
_080372B4: .4byte gCurrentSprite

	thumb_func_start BoxPartCenterBottom
BoxPartCenterBottom: @ 0x080372B8
	push {lr}
	ldr r3, _080372DC @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _080372E0 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r2, r0, r2
	ldrh r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080372E4
	strh r1, [r3]
	b _0803748C
	.align 2, 0
_080372DC: .4byte gCurrentSprite
_080372E0: .4byte gSpriteData
_080372E4:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _080372F2
	b _0803748C
_080372F2:
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #8
	cmp r0, #0x46
	bls _08037300
	b _0803747C
_08037300:
	lsls r0, r0, #2
	ldr r1, _0803730C @ =_08037310
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803730C: .4byte _08037310
_08037310: @ jump table
	.4byte _0803742C @ case 0
	.4byte _0803747C @ case 1
	.4byte _0803747C @ case 2
	.4byte _0803747C @ case 3
	.4byte _0803747C @ case 4
	.4byte _0803747C @ case 5
	.4byte _0803747C @ case 6
	.4byte _0803747C @ case 7
	.4byte _0803747C @ case 8
	.4byte _0803747C @ case 9
	.4byte _0803747C @ case 10
	.4byte _0803747C @ case 11
	.4byte _0803747C @ case 12
	.4byte _0803747C @ case 13
	.4byte _0803747C @ case 14
	.4byte _0803747C @ case 15
	.4byte _0803742C @ case 16
	.4byte _0803747C @ case 17
	.4byte _0803747C @ case 18
	.4byte _0803747C @ case 19
	.4byte _0803747C @ case 20
	.4byte _0803747C @ case 21
	.4byte _0803747C @ case 22
	.4byte _0803747C @ case 23
	.4byte _0803747C @ case 24
	.4byte _0803747C @ case 25
	.4byte _0803747C @ case 26
	.4byte _0803747C @ case 27
	.4byte _0803747C @ case 28
	.4byte _0803747C @ case 29
	.4byte _0803747C @ case 30
	.4byte _0803747C @ case 31
	.4byte _0803747C @ case 32
	.4byte _0803747C @ case 33
	.4byte _0803747C @ case 34
	.4byte _0803747C @ case 35
	.4byte _0803747C @ case 36
	.4byte _0803747C @ case 37
	.4byte _0803747C @ case 38
	.4byte _0803747C @ case 39
	.4byte _0803747C @ case 40
	.4byte _0803747C @ case 41
	.4byte _0803747C @ case 42
	.4byte _0803747C @ case 43
	.4byte _0803747C @ case 44
	.4byte _0803747C @ case 45
	.4byte _0803747C @ case 46
	.4byte _0803747C @ case 47
	.4byte _0803747C @ case 48
	.4byte _0803747C @ case 49
	.4byte _0803747C @ case 50
	.4byte _0803747C @ case 51
	.4byte _0803742C @ case 52
	.4byte _0803747C @ case 53
	.4byte _0803747C @ case 54
	.4byte _0803747C @ case 55
	.4byte _0803747C @ case 56
	.4byte _0803747C @ case 57
	.4byte _0803747C @ case 58
	.4byte _0803747C @ case 59
	.4byte _08037438 @ case 60
	.4byte _08037438 @ case 61
	.4byte _08037438 @ case 62
	.4byte _08037438 @ case 63
	.4byte _08037438 @ case 64
	.4byte _08037438 @ case 65
	.4byte _08037438 @ case 66
	.4byte _0803747C @ case 67
	.4byte _0803747C @ case 68
	.4byte _08037438 @ case 69
	.4byte _08037438 @ case 70
_0803742C:
	ldr r0, [r3, #0x18]
	ldr r1, _08037434 @ =0x08347CA8
	b _08037480
	.align 2, 0
_08037434: .4byte 0x08347CA8
_08037438:
	ldr r0, [r3, #0x18]
	ldr r1, _0803746C @ =0x08347CA8
	cmp r0, r1
	beq _08037448
	str r1, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
_08037448:
	ldr r0, _08037470 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803748C
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08037474
	adds r1, r3, #0
	adds r1, #0x20
	movs r0, #0xc
	strb r0, [r1]
	b _0803748C
	.align 2, 0
_0803746C: .4byte 0x08347CA8
_08037470: .4byte gFrameCounter8Bit
_08037474:
	adds r0, r3, #0
	adds r0, #0x20
	strb r2, [r0]
	b _0803748C
_0803747C:
	ldr r0, [r3, #0x18]
	ldr r1, _08037490 @ =0x08347C98
_08037480:
	cmp r0, r1
	beq _0803748C
	str r1, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
_0803748C:
	pop {r0}
	bx r0
	.align 2, 0
_08037490: .4byte 0x08347C98

	thumb_func_start BoxPartDefault
BoxPartDefault: @ 0x08037494
	push {lr}
	ldr r3, _080374B8 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _080374BC @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r2, r0, r2
	ldrh r0, [r2]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _080374C0
	strh r1, [r3]
	b _0803750E
	.align 2, 0
_080374B8: .4byte gCurrentSprite
_080374BC: .4byte gSpriteData
_080374C0:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0803750E
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x44
	blt _0803750E
	cmp r0, #0x4a
	ble _080374E2
	cmp r0, #0x4e
	bgt _0803750E
	cmp r0, #0x4d
	blt _0803750E
_080374E2:
	ldr r0, _08037504 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803750E
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08037508
	adds r1, r3, #0
	adds r1, #0x20
	movs r0, #0xd
	strb r0, [r1]
	b _0803750E
	.align 2, 0
_08037504: .4byte gFrameCounter8Bit
_08037508:
	adds r0, r3, #0
	adds r0, #0x20
	strb r2, [r0]
_0803750E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxMissileInit
BoxMissileInit: @ 0x08037514
	push {r4, lr}
	ldr r0, _0803759C @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _080375A0 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	movs r1, #0x80
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	ldr r0, _080375A4 @ =gIoRegisters
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
	ldr r1, _080375A8 @ =0x0000FFF8
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #8
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _080375AC @ =0x08347D68
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	ldr r1, _080375B0 @ =sSecondarySpriteStats
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
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080375B4 @ =0x0000026B
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803759C: .4byte gCurrentSprite
_080375A0: .4byte 0x0000FFFB
_080375A4: .4byte gIoRegisters
_080375A8: .4byte 0x0000FFF8
_080375AC: .4byte 0x08347D68
_080375B0: .4byte sSecondarySpriteStats
_080375B4: .4byte 0x0000026B

	thumb_func_start BoxMissileSpawning
BoxMissileSpawning: @ 0x080375B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r5, _08037638 @ =gCurrentSprite
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	bne _080375D0
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
_080375D0:
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
	bhi _08037600
	adds r7, r5, #0
	adds r7, #0x2b
	ldrb r0, [r7]
	ldr r2, _0803763C @ =gSamusData
	ldrh r1, [r2, #0x18]
	subs r1, #0x40
	ldrh r2, [r2, #0x16]
	ldrh r3, [r5, #2]
	ldrh r4, [r5, #4]
	str r4, [sp]
	bl SpriteUtilMakeSpriteRotateTowardsTarget
	strb r0, [r7]
_08037600:
	ldrb r0, [r6]
	subs r0, #2
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0803762C
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
_0803762C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037638: .4byte gCurrentSprite
_0803763C: .4byte gSamusData

	thumb_func_start BoxMissileMoving
BoxMissileMoving: @ 0x08037640
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _080376C0 @ =gCurrentSprite
	ldrh r0, [r1, #6]
	subs r0, #1
	strh r0, [r1, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080376B2
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	beq _080376B2
	ldrb r1, [r1, #0x1e]
	movs r2, #8
	cmp r1, #3
	beq _0803766E
	movs r2, #0x28
	cmp r1, #2
	beq _0803766E
	movs r2, #0x68
	cmp r1, #1
	bne _0803766E
	movs r2, #0x48
_0803766E:
	ldr r4, _080376C4 @ =gSamusData
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
	ldr r5, _080376C0 @ =gCurrentSprite
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
	ldr r0, _080376C8 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080376B8
	adds r1, r5, #0
_080376B2:
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
_080376B8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080376C0: .4byte gCurrentSprite
_080376C4: .4byte gSamusData
_080376C8: .4byte gPreviousCollisionCheck

	thumb_func_start BoxMissileExploding
BoxMissileExploding: @ 0x080376CC
	push {lr}
	ldr r1, _080376EC @ =gCurrentSprite
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
_080376EC: .4byte gCurrentSprite

	thumb_func_start BoxBombInit
BoxBombInit: @ 0x080376F0
	push {r4, lr}
	ldr r0, _08037780 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08037784 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	movs r1, #0x80
	orrs r0, r1
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08037788 @ =0x0000FFE4
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #0x1c
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _0803778C @ =0x08347E58
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	ldr r1, _08037790 @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	mov r0, ip
	adds r0, #0x2b
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x12]
	mov r0, ip
	adds r0, #0x2f
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x30
	movs r0, #7
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x31
	strb r2, [r0]
	subs r0, #0xd
	movs r3, #2
	strb r3, [r0]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	movs r0, #0x9c
	lsls r0, r0, #2
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037780: .4byte gCurrentSprite
_08037784: .4byte 0x0000FFFB
_08037788: .4byte 0x0000FFE4
_0803778C: .4byte 0x08347E58
_08037790: .4byte sSecondarySpriteStats

	thumb_func_start BoxBombMoving
BoxBombMoving: @ 0x08037794
	push {r4, r5, r6, lr}
	ldr r1, _080377A8 @ =gCurrentSprite
	ldrh r0, [r1, #0x14]
	adds r5, r1, #0
	cmp r0, #0
	bne _080377AC
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _08037958
	.align 2, 0
_080377A8: .4byte gCurrentSprite
_080377AC:
	movs r0, #0x2f
	adds r0, r0, r5
	mov ip, r0
	ldrb r6, [r0]
	adds r0, r6, #0
	cmp r0, #0
	bne _080377FC
	adds r3, r5, #0
	adds r3, #0x31
	ldrb r2, [r3]
	ldr r0, _080377DC @ =0x0834214A
	lsls r1, r2, #1
	adds r1, r1, r0
	ldrh r4, [r1]
	ldr r0, _080377E0 @ =0x00007FFF
	cmp r4, r0
	bne _080377E4
	movs r4, #0
	adds r0, r6, #1
	mov r1, ip
	strb r0, [r1]
	strb r4, [r3]
	b _080377E8
	.align 2, 0
_080377DC: .4byte 0x0834214A
_080377E0: .4byte 0x00007FFF
_080377E4:
	adds r0, r2, #1
	strb r0, [r3]
_080377E8:
	adds r0, r5, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #3
	bne _080378D4
	adds r1, r5, #0
	adds r1, #0x30
	movs r0, #7
	strb r0, [r1]
	b _080378D4
_080377FC:
	cmp r0, #2
	bne _08037828
	adds r3, r5, #0
	adds r3, #0x31
	ldrb r2, [r3]
	ldr r0, _08037820 @ =0x0834213E
_08037808:
	lsls r1, r2, #1
	adds r1, r1, r0
	ldrh r4, [r1]
	ldr r0, _08037824 @ =0x00007FFF
	cmp r4, r0
	bne _0803783C
	movs r4, #0
	adds r0, r6, #1
	mov r1, ip
	strb r0, [r1]
	strb r4, [r3]
	b _080378D4
	.align 2, 0
_08037820: .4byte 0x0834213E
_08037824: .4byte 0x00007FFF
_08037828:
	cmp r0, #4
	bne _08037842
	adds r3, r5, #0
	adds r3, #0x31
	ldrb r2, [r3]
	ldr r0, _08037838 @ =0x08342134
	b _08037808
	.align 2, 0
_08037838: .4byte 0x08342134
_0803783C:
	adds r0, r2, #1
	strb r0, [r3]
	b _080378D4
_08037842:
	cmp r0, #6
	bne _08037858
	adds r0, r5, #0
	adds r0, #0x24
	movs r1, #0x18
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
	b _080378DA
_08037858:
	adds r3, r5, #0
	adds r3, #0x31
	ldrb r2, [r3]
	ldr r1, _08037878 @ =0x08342160
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r0, _0803787C @ =0x00007FFF
	cmp r4, r0
	bne _08037880
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	b _08037884
	.align 2, 0
_08037878: .4byte 0x08342160
_0803787C: .4byte 0x00007FFF
_08037880:
	adds r0, r2, #1
	strb r0, [r3]
_08037884:
	ldr r5, _080378C8 @ =gCurrentSprite
	ldrh r0, [r5, #2]
	adds r0, #0x20
	ldrh r1, [r5, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _080378CC @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080378D4
	adds r0, r1, #0
	subs r0, #0x20
	strh r0, [r5, #2]
	adds r4, r5, #0
	adds r4, #0x2f
	ldrb r0, [r4]
	cmp r0, #1
	bne _080378B0
	ldr r0, _080378D0 @ =0x00000271
	bl SoundPlay
_080378B0:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	b _080378DA
	.align 2, 0
_080378C8: .4byte gCurrentSprite
_080378CC: .4byte gPreviousVerticalCollisionCheck
_080378D0: .4byte 0x00000271
_080378D4:
	ldrh r0, [r5, #2]
	adds r0, r4, r0
	strh r0, [r5, #2]
_080378DA:
	adds r4, r5, #0
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08037924
	adds r2, r4, #0
	adds r2, #0x2b
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	movs r0, #6
	subs r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08037920 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037958
	adds r1, r4, #0
	adds r1, #0x30
	ldrh r0, [r4, #4]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #4]
	b _08037958
	.align 2, 0
_08037920: .4byte gPreviousCollisionCheck
_08037924:
	adds r2, r5, #0
	adds r2, #0x2b
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	movs r1, #6
	subs r1, r1, r0
	lsls r1, r1, #3
	ldrb r0, [r2]
	subs r0, r0, r1
	strb r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08037960 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037958
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	ldrh r0, [r5, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
_08037958:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037960: .4byte gPreviousCollisionCheck

	thumb_func_start BoxBombLanded
BoxBombLanded: @ 0x08037964
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, _0803797C @ =gCurrentSprite
	ldrh r0, [r4, #0x14]
	cmp r0, #0
	bne _08037980
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _080379DC
	.align 2, 0
_0803797C: .4byte gCurrentSprite
_08037980:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080379DC
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	adds r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x72
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	adds r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0x72
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	movs r2, #0x22
	bl ParticleSet
	strh r5, [r4]
	ldr r0, _080379E4 @ =0x00000272
	bl SoundPlay
_080379DC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080379E4: .4byte 0x00000272

	thumb_func_start BoxBombExploding
BoxBombExploding: @ 0x080379E8
	push {r4, lr}
	ldr r4, _08037A08 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	movs r2, #0x32
	bl ParticleSet
	movs r0, #0
	strh r0, [r4]
	ldr r0, _08037A0C @ =0x00000273
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037A08: .4byte gCurrentSprite
_08037A0C: .4byte 0x00000273

	thumb_func_start BoxFireInit
BoxFireInit: @ 0x08037A10
	push {r4, lr}
	ldr r0, _08037A6C @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08037A70 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r2, #0
	mov r1, ip
	strh r0, [r1]
	adds r1, #0x27
	movs r0, #0x68
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x29
	movs r1, #0x10
	strb r1, [r0]
	ldr r0, _08037A74 @ =0x0000FFE0
	mov r4, ip
	strh r0, [r4, #0xa]
	strh r2, [r4, #0xc]
	adds r0, #0x10
	strh r0, [r4, #0xe]
	strh r1, [r4, #0x10]
	ldr r0, _08037A78 @ =0x08347E80
	str r0, [r4, #0x18]
	strb r3, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldr r1, _08037A7C @ =sSecondarySpriteStats
	ldrb r0, [r4, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	mov r0, ip
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037A6C: .4byte gCurrentSprite
_08037A70: .4byte 0x0000FFFB
_08037A74: .4byte 0x0000FFE0
_08037A78: .4byte 0x08347E80
_08037A7C: .4byte sSecondarySpriteStats

	thumb_func_start BoxFireMovingHigh
BoxFireMovingHigh: @ 0x08037A80
	push {r4, r5, r6, lr}
	ldr r0, _08037A98 @ =gCurrentSprite
	ldrh r0, [r0, #0x16]
	cmp r0, #0x23
	bls _08037A8C
	b _08037BB4
_08037A8C:
	lsls r0, r0, #2
	ldr r1, _08037A9C @ =_08037AA0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037A98: .4byte gCurrentSprite
_08037A9C: .4byte _08037AA0
_08037AA0: @ jump table
	.4byte _08037B30 @ case 0
	.4byte _08037B30 @ case 1
	.4byte _08037B30 @ case 2
	.4byte _08037B38 @ case 3
	.4byte _08037B40 @ case 4
	.4byte _08037BA4 @ case 5
	.4byte _08037B5C @ case 6
	.4byte _08037B94 @ case 7
	.4byte _08037B84 @ case 8
	.4byte _08037BB4 @ case 9
	.4byte _08037BB4 @ case 10
	.4byte _08037BB4 @ case 11
	.4byte _08037BB4 @ case 12
	.4byte _08037BB4 @ case 13
	.4byte _08037BB4 @ case 14
	.4byte _08037BB4 @ case 15
	.4byte _08037BB4 @ case 16
	.4byte _08037BB4 @ case 17
	.4byte _08037BB4 @ case 18
	.4byte _08037BB4 @ case 19
	.4byte _08037BB4 @ case 20
	.4byte _08037BB4 @ case 21
	.4byte _08037BB4 @ case 22
	.4byte _08037BB4 @ case 23
	.4byte _08037BB4 @ case 24
	.4byte _08037BB4 @ case 25
	.4byte _08037BB4 @ case 26
	.4byte _08037B64 @ case 27
	.4byte _08037B72 @ case 28
	.4byte _08037B84 @ case 29
	.4byte _08037B84 @ case 30
	.4byte _08037B8C @ case 31
	.4byte _08037B94 @ case 32
	.4byte _08037B9A @ case 33
	.4byte _08037BA4 @ case 34
	.4byte _08037BAC @ case 35
_08037B30:
	ldr r5, _08037B34 @ =0x0000FFE0
	b _08037BB6
	.align 2, 0
_08037B34: .4byte 0x0000FFE0
_08037B38:
	ldr r5, _08037B3C @ =0x0000FFC0
	b _08037BB6
	.align 2, 0
_08037B3C: .4byte 0x0000FFC0
_08037B40:
	ldr r5, _08037B54 @ =0x0000FFA0
	ldr r0, _08037B58 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _08037BB6
	movs r0, #0x9d
	lsls r0, r0, #2
	bl SoundPlay
	b _08037BB6
	.align 2, 0
_08037B54: .4byte 0x0000FFA0
_08037B58: .4byte gCurrentSprite
_08037B5C:
	ldr r5, _08037B60 @ =0x0000FF40
	b _08037BB6
	.align 2, 0
_08037B60: .4byte 0x0000FF40
_08037B64:
	ldr r0, _08037B78 @ =gCurrentSprite
	ldrb r0, [r0, #0x1c]
	cmp r0, #1
	bne _08037B72
	ldr r0, _08037B7C @ =0x00000275
	bl SoundPlay
_08037B72:
	ldr r5, _08037B80 @ =0x0000FEA0
	b _08037BB6
	.align 2, 0
_08037B78: .4byte gCurrentSprite
_08037B7C: .4byte 0x00000275
_08037B80: .4byte 0x0000FEA0
_08037B84:
	ldr r5, _08037B88 @ =0x0000FEC0
	b _08037BB6
	.align 2, 0
_08037B88: .4byte 0x0000FEC0
_08037B8C:
	ldr r5, _08037B90 @ =0x0000FEE0
	b _08037BB6
	.align 2, 0
_08037B90: .4byte 0x0000FEE0
_08037B94:
	movs r5, #0xff
	lsls r5, r5, #8
	b _08037BB6
_08037B9A:
	ldr r5, _08037BA0 @ =0x0000FF20
	b _08037BB6
	.align 2, 0
_08037BA0: .4byte 0x0000FF20
_08037BA4:
	ldr r5, _08037BA8 @ =0x0000FF80
	b _08037BB6
	.align 2, 0
_08037BA8: .4byte 0x0000FF80
_08037BAC:
	ldr r5, _08037BB0 @ =0x0000FFA0
	b _08037BB6
	.align 2, 0
_08037BB0: .4byte 0x0000FFA0
_08037BB4:
	ldr r5, _08037C08 @ =0x0000FE80
_08037BB6:
	ldr r4, _08037C0C @ =gCurrentSprite
	movs r6, #0
	strh r5, [r4, #0xa]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08037BE0
	ldr r0, _08037C10 @ =0x083480A8
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r6, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x3c
	strb r0, [r1]
	ldr r0, _08037C14 @ =0x0000FFD0
	strh r0, [r4, #0xa]
_08037BE0:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08037C1C
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08037C18 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037C30
	ldrh r0, [r4, #4]
	adds r0, #3
	b _08037C3C
	.align 2, 0
_08037C08: .4byte 0x0000FE80
_08037C0C: .4byte gCurrentSprite
_08037C10: .4byte 0x083480A8
_08037C14: .4byte 0x0000FFD0
_08037C18: .4byte gPreviousCollisionCheck
_08037C1C:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08037C34 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037C38
_08037C30:
	strh r6, [r4]
	b _08037C3E
	.align 2, 0
_08037C34: .4byte gPreviousCollisionCheck
_08037C38:
	ldrh r0, [r4, #4]
	subs r0, #3
_08037C3C:
	strh r0, [r4, #4]
_08037C3E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start BoxFireMovingLow
BoxFireMovingLow: @ 0x08037C44
	push {r4, r5, lr}
	ldr r4, _08037C94 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	movs r5, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08037C6C
	ldr r0, _08037C98 @ =0x08347E80
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r5, [r4, #0x16]
	subs r1, #0xa
	movs r0, #2
	strb r0, [r1]
	ldr r0, _08037C9C @ =0x0000FFE0
	strh r0, [r4, #0xa]
_08037C6C:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08037CA4
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08037CA0 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037CB8
	ldrh r0, [r4, #4]
	adds r0, #3
	b _08037CC4
	.align 2, 0
_08037C94: .4byte gCurrentSprite
_08037C98: .4byte 0x08347E80
_08037C9C: .4byte 0x0000FFE0
_08037CA0: .4byte gPreviousCollisionCheck
_08037CA4:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08037CBC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037CC0
_08037CB8:
	strh r5, [r4]
	b _08037CC6
	.align 2, 0
_08037CBC: .4byte gPreviousCollisionCheck
_08037CC0:
	ldrh r0, [r4, #4]
	subs r0, #3
_08037CC4:
	strh r0, [r4, #4]
_08037CC6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start BoxSpawnFallingDebris
BoxSpawnFallingDebris: @ 0x08037CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r4, _08037DC4 @ =gCurrentSprite
	ldrh r6, [r4, #2]
	ldrh r7, [r4, #4]
	ldrb r2, [r4, #0x1f]
	movs r0, #0x23
	adds r0, r0, r4
	mov r8, r0
	ldrb r3, [r0]
	str r6, [sp]
	adds r0, r7, #0
	subs r0, #0xe8
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r1, r8
	ldrb r3, [r1]
	str r6, [sp]
	adds r0, r7, #0
	adds r0, #0xbe
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #1
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	ldr r1, _08037DC8 @ =0xFFFFFEAA
	adds r0, r7, r1
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #2
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	adds r0, r7, #0
	subs r0, #0xa0
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #3
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r1, r8
	ldrb r3, [r1]
	str r6, [sp]
	ldr r1, _08037DCC @ =0xFFFFFEFA
	adds r0, r7, r1
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #4
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	adds r0, r7, #0
	adds r0, #0xdc
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #5
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r1, r8
	ldrb r3, [r1]
	str r6, [sp]
	adds r0, r7, #0
	subs r0, #0x50
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #6
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	ldr r1, _08037DD0 @ =0xFFFFFEDC
	adds r0, r7, r1
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #7
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	mov r0, r8
	ldrb r3, [r0]
	str r6, [sp]
	adds r0, r7, #0
	adds r0, #0x8c
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x4b
	movs r1, #8
	bl SpriteSpawnSecondary
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037DC4: .4byte gCurrentSprite
_08037DC8: .4byte 0xFFFFFEAA
_08037DCC: .4byte 0xFFFFFEFA
_08037DD0: .4byte 0xFFFFFEDC

	thumb_func_start BoxSetDebrisClipdata
BoxSetDebrisClipdata: @ 0x08037DD4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08037E10 @ =gCurrentSprite
	ldrh r5, [r0, #2]
	ldrh r6, [r0, #4]
	ldr r0, _08037E14 @ =gCurrentClipdataAffectingAction
	mov r8, r0
	strb r4, [r0]
	subs r5, #0xe0
	adds r1, r6, #0
	adds r1, #0x20
	adds r0, r5, #0
	bl ClipdataProcess
	mov r0, r8
	strb r4, [r0]
	subs r6, #0x20
	adds r0, r5, #0
	adds r1, r6, #0
	bl ClipdataProcess
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037E10: .4byte gCurrentSprite
_08037E14: .4byte gCurrentClipdataAffectingAction

	thumb_func_start BoxDebrisInit
BoxDebrisInit: @ 0x08037E18
	push {r4, r5, lr}
	ldr r4, _08037EAC @ =gCurrentSprite
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	movs r1, #0x10
	strb r1, [r0]
	movs r5, #0x29
	movs r0, #0x18
	strb r0, [r5, r4]
	ldr r0, _08037EB0 @ =0x0000FF10
	strh r0, [r4, #0xa]
	strh r1, [r4, #0xc]
	adds r0, #0xc0
	strh r0, [r4, #0xe]
	movs r0, #0x30
	strh r0, [r4, #0x10]
	ldr r0, _08037EB4 @ =0x08347FA8
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	movs r3, #1
	movs r0, #1
	strh r0, [r4, #0x14]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrh r0, [r4, #4]
	subs r0, #0x20
	strh r0, [r4, #4]
	bl EventCheckAfter_BoxDefeated
	adds r2, r0, #0
	cmp r2, #0
	beq _08037ECC
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
	ldrh r1, [r4]
	ldr r0, _08037EB8 @ =0x0000DFFF
	ands r0, r1
	strh r0, [r4]
	ldr r0, _08037EBC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037EC0
	strh r0, [r4]
	b _08037EDE
	.align 2, 0
_08037EAC: .4byte gCurrentSprite
_08037EB0: .4byte 0x0000FF10
_08037EB4: .4byte 0x08347FA8
_08037EB8: .4byte 0x0000DFFF
_08037EBC: .4byte gPreviousCollisionCheck
_08037EC0:
	movs r0, #2
	bl BoxSetDebrisClipdata
	bl BoxSpawnFallingDebris
	b _08037EDE
_08037ECC:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _08037EE4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037EDE
	strh r2, [r4]
_08037EDE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08037EE4: .4byte gPreviousCollisionCheck

	thumb_func_start BoxDebrisIdle
BoxDebrisIdle: @ 0x08037EE8
	ldr r0, _08037EF4 @ =gCurrentSprite
	adds r0, #0x26
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08037EF4: .4byte gCurrentSprite

	thumb_func_start BoxDebrisFallingInit
BoxDebrisFallingInit: @ 0x08037EF8
	ldr r1, _08037F14 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x26
	movs r0, #1
	strb r0, [r2]
	ldrh r2, [r1]
	ldr r0, _08037F18 @ =0x0000DFFF
	ands r0, r2
	strh r0, [r1]
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	bx lr
	.align 2, 0
_08037F14: .4byte gCurrentSprite
_08037F18: .4byte 0x0000DFFF

	thumb_func_start BoxDebrisWaitToFall
BoxDebrisWaitToFall: @ 0x08037F1C
	push {lr}
	ldr r2, _08037F74 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x26
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r2, #4]
	lsrs r0, r0, #2
	ldr r1, _08037F78 @ =gBg1XPosition
	ldrh r1, [r1]
	lsrs r1, r1, #2
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08037F7C @ =0xFFDF0000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0xae
	bhi _08037F6E
	adds r0, r2, #0
	adds r0, #0x2e
	strb r3, [r0]
	adds r0, #3
	strb r3, [r0]
	subs r0, #0xd
	movs r1, #0x1c
	strb r1, [r0]
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartHorizontal
	movs r0, #0x28
	movs r1, #0x81
	bl ScreenShakeStartVertical
	bl BoxSpawnFallingDebris
	movs r0, #0x8c
	lsls r0, r0, #2
	bl SoundPlay_3b1c
_08037F6E:
	pop {r0}
	bx r0
	.align 2, 0
_08037F74: .4byte gCurrentSprite
_08037F78: .4byte gBg1XPosition
_08037F7C: .4byte 0xFFDF0000

	thumb_func_start BoxDebrisFalling
BoxDebrisFalling: @ 0x08037F80
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _08037FF0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r1, #8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r7, [r1]
	ldrh r5, [r4, #2]
	ldrh r6, [r4, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08037FF4 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037FF8
	strh r1, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #0x1e
	strb r1, [r0]
	movs r0, #0x1e
	movs r1, #0x81
	bl ScreenShakeStartVertical
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x31
	bl ParticleSet
	adds r1, r6, #0
	adds r1, #0x20
	adds r0, r5, #0
	movs r2, #0x31
	bl ParticleSet
	movs r0, #0x28
	bl EventCheckAdvance
	movs r0, #2
	bl BoxSetDebrisClipdata
	movs r0, #0x18
	movs r1, #6
	bl PlayMusic
	b _0803807E
	.align 2, 0
_08037FF0: .4byte gCurrentSprite
_08037FF4: .4byte gPreviousVerticalCollisionCheck
_08037FF8:
	movs r0, #0x31
	adds r0, r0, r4
	mov r8, r0
	ldrb r2, [r0]
	ldr r1, _08038024 @ =sSpritesFallingSpeedFast
	mov ip, r1
	lsls r0, r2, #1
	add r0, ip
	ldrh r3, [r0]
	mov sb, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _08038028 @ =0x00007FFF
	cmp r1, r0
	bne _0803802C
	subs r1, r2, #1
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08038036
	.align 2, 0
_08038024: .4byte sSpritesFallingSpeedFast
_08038028: .4byte 0x00007FFF
_0803802C:
	adds r0, r2, #1
	mov r1, r8
	strb r0, [r1]
	ldrh r0, [r4, #2]
	add r0, sb
_08038036:
	strh r0, [r4, #2]
	movs r1, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0803804E
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x34
	bl ParticleSet
	b _0803807E
_0803804E:
	adds r0, r7, #4
	ands r0, r1
	cmp r0, #0
	bne _08038066
	adds r0, r5, #0
	subs r0, #0xa0
	adds r1, r6, #0
	adds r1, #0x28
	movs r2, #0x33
	bl ParticleSet
	b _0803807E
_08038066:
	adds r0, r7, #0
	adds r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0803807E
	adds r0, r5, #0
	subs r0, #0x82
	adds r1, r6, #0
	subs r1, #0x28
	movs r2, #0x33
	bl ParticleSet
_0803807E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxFallingDebrisInit
BoxFallingDebrisInit: @ 0x0803808C
	push {r4, lr}
	ldr r3, _080380D0 @ =gCurrentSprite
	ldrh r1, [r3]
	ldr r0, _080380D4 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r4, #0
	strh r0, [r3]
	ldr r1, _080380D8 @ =0x0000FFFC
	strh r1, [r3, #0xa]
	movs r0, #4
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	adds r0, #0xa
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	strb r2, [r3, #0x1c]
	strh r4, [r3, #0x16]
	ldrb r0, [r3, #0x1e]
	cmp r0, #8
	bls _080380C6
	b _080382E8
_080380C6:
	lsls r0, r0, #2
	ldr r1, _080380DC @ =_080380E0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080380D0: .4byte gCurrentSprite
_080380D4: .4byte 0x0000FFFB
_080380D8: .4byte 0x0000FFFC
_080380DC: .4byte _080380E0
_080380E0: @ jump table
	.4byte _08038104 @ case 0
	.4byte _08038160 @ case 1
	.4byte _0803818C @ case 2
	.4byte _080381BC @ case 3
	.4byte _080381EC @ case 4
	.4byte _0803821C @ case 5
	.4byte _0803824C @ case 6
	.4byte _08038280 @ case 7
	.4byte _080382A8 @ case 8
_08038104:
	ldr r3, _08038154 @ =gCurrentSprite
	ldr r0, _08038158 @ =0x08347FB8
	str r0, [r3, #0x18]
	adds r1, r3, #0
	adds r1, #0x27
	movs r0, #0x30
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x28
	movs r1, #0x10
	strb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x29
	movs r0, #0x18
	strb r0, [r2]
	ldr r0, _0803815C @ =0x0000FF78
	strh r0, [r3, #0xa]
	strh r1, [r3, #0xc]
	adds r0, #0x84
	strh r0, [r3, #0xe]
	movs r0, #0x44
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #0xb
	strb r0, [r1]
	adds r1, #3
	movs r0, #1
	strb r0, [r1]
	strh r0, [r3, #0x14]
	adds r2, #0xb
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #0x1e
	strb r0, [r1]
	b _080382EA
	.align 2, 0
_08038154: .4byte gCurrentSprite
_08038158: .4byte 0x08347FB8
_0803815C: .4byte 0x0000FF78
_08038160:
	ldr r4, _08038184 @ =gCurrentSprite
	ldr r0, _08038188 @ =0x08347FC8
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xa
	strb r0, [r1]
	adds r1, #5
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	adds r1, #5
	b _080382CA
	.align 2, 0
_08038184: .4byte gCurrentSprite
_08038188: .4byte 0x08347FC8
_0803818C:
	ldr r2, _080381B4 @ =gCurrentSprite
	ldr r0, _080381B8 @ =0x08347FD8
	str r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0x22
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0x28
	strb r0, [r1]
	b _080382EA
	.align 2, 0
_080381B4: .4byte gCurrentSprite
_080381B8: .4byte 0x08347FD8
_080381BC:
	ldr r2, _080381E4 @ =gCurrentSprite
	ldr r0, _080381E8 @ =0x08347FE8
	str r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0x22
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0x50
	strb r0, [r1]
	b _080382EA
	.align 2, 0
_080381E4: .4byte gCurrentSprite
_080381E8: .4byte 0x08347FE8
_080381EC:
	ldr r2, _08038214 @ =gCurrentSprite
	ldr r0, _08038218 @ =0x08347FF8
	str r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0x22
	movs r0, #9
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0x64
	strb r0, [r1]
	b _080382EA
	.align 2, 0
_08038214: .4byte gCurrentSprite
_08038218: .4byte 0x08347FF8
_0803821C:
	ldr r4, _08038244 @ =gCurrentSprite
	ldr r0, _08038248 @ =0x08348008
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #9
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0x78
	b _080382CC
	.align 2, 0
_08038244: .4byte gCurrentSprite
_08038248: .4byte 0x08348008
_0803824C:
	ldr r2, _08038278 @ =gCurrentSprite
	ldr r0, _0803827C @ =0x08348018
	str r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	adds r1, #5
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x28
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0xa
	strb r0, [r1]
	b _080382EA
	.align 2, 0
_08038278: .4byte gCurrentSprite
_0803827C: .4byte 0x08348018
_08038280:
	ldr r2, _080382A0 @ =gCurrentSprite
	ldr r0, _080382A4 @ =0x08348028
	str r0, [r2, #0x18]
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	movs r0, #0x14
	strb r0, [r1]
	b _080382EA
	.align 2, 0
_080382A0: .4byte gCurrentSprite
_080382A4: .4byte 0x08348028
_080382A8:
	ldr r4, _080382E0 @ =gCurrentSprite
	ldr r0, _080382E4 @ =0x08348038
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2e
_080382CA:
	movs r0, #0x3c
_080382CC:
	strb r0, [r1]
	bl EventCheckAfter_BoxDefeated
	cmp r0, #0
	bne _080382EA
	ldrh r0, [r4, #2]
	adds r0, #0xc0
	strh r0, [r4, #2]
	b _080382EA
	.align 2, 0
_080382E0: .4byte gCurrentSprite
_080382E4: .4byte 0x08348038
_080382E8:
	strh r4, [r3]
_080382EA:
	bl EventCheckAfter_BoxDefeated
	cmp r0, #0
	beq _08038300
	ldr r0, _080382FC @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x1e
	b _08038306
	.align 2, 0
_080382FC: .4byte gCurrentSprite
_08038300:
	ldr r0, _08038310 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
_08038306:
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038310: .4byte gCurrentSprite

	thumb_func_start BoxFallingDebrisFalling
BoxFallingDebrisFalling: @ 0x08038314
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08038334 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r1, #8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08038338
	subs r0, #1
	strb r0, [r1]
	b _08038542
	.align 2, 0
_08038334: .4byte gCurrentSprite
_08038338:
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r6, [r1]
	ldrh r7, [r4, #2]
	ldrh r0, [r4, #4]
	mov r8, r0
	ldrb r5, [r4, #0x1e]
	adds r1, #1
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _08038358
	adds r0, #1
	strb r0, [r1]
_08038358:
	ldrb r0, [r1]
	cmp r0, #0x32
	bls _080383DE
	adds r0, r7, #0
	mov r1, r8
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _08038398 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _080383DE
	strh r1, [r4, #2]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
	cmp r5, #0
	bne _0803839C
	movs r1, #0x81
	bl ScreenShakeStartVertical
	mov r1, r8
	subs r1, #0x20
	adds r0, r7, #0
	movs r2, #0x31
	bl ParticleSet
	mov r1, r8
	adds r1, #0x20
	adds r0, r7, #0
	b _080383A8
	.align 2, 0
_08038398: .4byte gPreviousVerticalCollisionCheck
_0803839C:
	cmp r5, #1
	beq _080383A4
	cmp r5, #6
	bne _080383B0
_080383A4:
	adds r0, r7, #0
	mov r1, r8
_080383A8:
	movs r2, #0x31
	bl ParticleSet
	b _08038542
_080383B0:
	subs r0, r5, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080383BE
	cmp r5, #7
	bne _080383D2
_080383BE:
	mov r1, r8
	subs r1, #0x10
	adds r0, r7, #0
	movs r2, #0x27
	bl ParticleSet
	mov r1, r8
	adds r1, #0x10
	adds r0, r7, #0
	b _080383D6
_080383D2:
	adds r0, r7, #0
	mov r1, r8
_080383D6:
	movs r2, #0x27
	bl ParticleSet
	b _08038542
_080383DE:
	cmp r5, #0
	bne _0803845C
	movs r1, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080383F8
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x31
	bl ParticleSet
	b _08038426
_080383F8:
	adds r0, r6, #4
	ands r0, r1
	cmp r0, #0
	bne _08038410
	adds r0, r7, #0
	subs r0, #0xa0
	mov r1, r8
	adds r1, #0x32
	movs r2, #0x2e
	bl ParticleSet
	b _08038426
_08038410:
	adds r0, r6, #0
	adds r0, #8
	ands r0, r1
	cmp r0, #0
	bne _08038426
	mov r1, r8
	subs r1, #0x20
	adds r0, r7, #0
	movs r2, #0x33
	bl ParticleSet
_08038426:
	ldr r3, _08038450 @ =gCurrentSprite
	adds r6, r3, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _08038454 @ =sSpritesFallingSpeedFast
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08038458 @ =0x00007FFF
	cmp r1, r0
	beq _08038442
	b _08038538
_08038442:
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08038540
	.align 2, 0
_08038450: .4byte gCurrentSprite
_08038454: .4byte sSpritesFallingSpeedFast
_08038458: .4byte 0x00007FFF
_0803845C:
	cmp r5, #1
	beq _08038464
	cmp r5, #6
	bne _080384AC
_08038464:
	movs r0, #0x1f
	ands r6, r0
	cmp r6, #0
	bne _08038476
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x27
	bl ParticleSet
_08038476:
	ldr r3, _080384A0 @ =gCurrentSprite
	adds r6, r3, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _080384A4 @ =sSpritesFallingSpeedQuickAcceleration
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _080384A8 @ =0x00007FFF
	cmp r1, r0
	bne _08038538
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08038540
	.align 2, 0
_080384A0: .4byte gCurrentSprite
_080384A4: .4byte sSpritesFallingSpeedQuickAcceleration
_080384A8: .4byte 0x00007FFF
_080384AC:
	subs r0, r5, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080384BA
	cmp r5, #7
	bne _08038504
_080384BA:
	adds r0, r6, #7
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080384CE
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x33
	bl ParticleSet
_080384CE:
	ldr r3, _080384F8 @ =gCurrentSprite
	adds r6, r3, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _080384FC @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08038500 @ =0x00007FFF
	cmp r1, r0
	bne _08038538
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08038540
	.align 2, 0
_080384F8: .4byte gCurrentSprite
_080384FC: .4byte sSpritesFallingSpeed
_08038500: .4byte 0x00007FFF
_08038504:
	ldr r3, _0803852C @ =gCurrentSprite
	adds r6, r3, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _08038530 @ =sSpritesFallingSpeedSlow
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08038534 @ =0x00007FFF
	cmp r1, r0
	bne _08038538
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _08038540
	.align 2, 0
_0803852C: .4byte gCurrentSprite
_08038530: .4byte sSpritesFallingSpeedSlow
_08038534: .4byte 0x00007FFF
_08038538:
	adds r0, r2, #1
	strb r0, [r6]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_08038540:
	strh r0, [r3, #2]
_08038542:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Box
Box: @ 0x0803854C
	push {lr}
	ldr r0, _08038564 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x4e
	bls _0803855A
	b _0803878A
_0803855A:
	lsls r0, r0, #2
	ldr r1, _08038568 @ =_0803856C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038564: .4byte gCurrentSprite
_08038568: .4byte _0803856C
_0803856C: @ jump table
	.4byte _080386A8 @ case 0
	.4byte _080386AE @ case 1
	.4byte _080386B2 @ case 2
	.4byte _0803878A @ case 3
	.4byte _0803878A @ case 4
	.4byte _0803878A @ case 5
	.4byte _0803878A @ case 6
	.4byte _080386EA @ case 7
	.4byte _080386EE @ case 8
	.4byte _0803878A @ case 9
	.4byte _0803878A @ case 10
	.4byte _0803878A @ case 11
	.4byte _0803878A @ case 12
	.4byte _0803878A @ case 13
	.4byte _0803878A @ case 14
	.4byte _0803878A @ case 15
	.4byte _0803878A @ case 16
	.4byte _0803878A @ case 17
	.4byte _0803878A @ case 18
	.4byte _0803878A @ case 19
	.4byte _0803878A @ case 20
	.4byte _0803878A @ case 21
	.4byte _0803878A @ case 22
	.4byte _080386B8 @ case 23
	.4byte _080386BC @ case 24
	.4byte _080386C2 @ case 25
	.4byte _080386C6 @ case 26
	.4byte _080386CC @ case 27
	.4byte _080386D0 @ case 28
	.4byte _080386D6 @ case 29
	.4byte _080386DA @ case 30
	.4byte _080386E0 @ case 31
	.4byte _080386E4 @ case 32
	.4byte _0803878A @ case 33
	.4byte _0803878A @ case 34
	.4byte _0803878A @ case 35
	.4byte _0803878A @ case 36
	.4byte _0803878A @ case 37
	.4byte _0803878A @ case 38
	.4byte _08038726 @ case 39
	.4byte _0803872A @ case 40
	.4byte _08038730 @ case 41
	.4byte _08038734 @ case 42
	.4byte _0803878A @ case 43
	.4byte _0803873A @ case 44
	.4byte _0803878A @ case 45
	.4byte _08038740 @ case 46
	.4byte _0803878A @ case 47
	.4byte _0803878A @ case 48
	.4byte _0803878A @ case 49
	.4byte _0803878A @ case 50
	.4byte _0803878A @ case 51
	.4byte _0803878A @ case 52
	.4byte _0803878A @ case 53
	.4byte _0803878A @ case 54
	.4byte _080386F4 @ case 55
	.4byte _080386F8 @ case 56
	.4byte _08038708 @ case 57
	.4byte _0803870C @ case 58
	.4byte _08038712 @ case 59
	.4byte _08038716 @ case 60
	.4byte _0803871C @ case 61
	.4byte _08038720 @ case 62
	.4byte _08038746 @ case 63
	.4byte _0803874A @ case 64
	.4byte _08038750 @ case 65
	.4byte _08038754 @ case 66
	.4byte _0803875A @ case 67
	.4byte _0803875E @ case 68
	.4byte _08038764 @ case 69
	.4byte _08038768 @ case 70
	.4byte _0803876E @ case 71
	.4byte _08038772 @ case 72
	.4byte _08038778 @ case 73
	.4byte _0803877C @ case 74
	.4byte _080386FE @ case 75
	.4byte _08038702 @ case 76
	.4byte _08038782 @ case 77
	.4byte _08038786 @ case 78
_080386A8:
	bl BoxInit
	b _0803878A
_080386AE:
	bl BoxCrawlingInit
_080386B2:
	bl BoxCrawling
	b _0803878A
_080386B8:
	bl BoxWaitingToRunInit
_080386BC:
	bl BoxWaitingToRun
	b _0803878A
_080386C2:
	bl BoxSlowRunningInit
_080386C6:
	bl BoxSlowRun
	b _0803878A
_080386CC:
	bl BoxFastRunInit
_080386D0:
	bl BoxFastRun
	b _0803878A
_080386D6:
	bl BoxSkiddingInit
_080386DA:
	bl BoxSkidding
	b _0803878A
_080386E0:
	bl BoxStopSkiddingInit
_080386E4:
	bl BoxStopSkidding
	b _0803878A
_080386EA:
	bl BoxFinishedCrawlingInit
_080386EE:
	bl BoxFinishedCrawling
	b _0803878A
_080386F4:
	bl BoxBonkingInit
_080386F8:
	bl BoxBonking
	b _0803878A
_080386FE:
	bl BoxLandingFromBonkInit
_08038702:
	bl BoxLandingFromBonk
	b _0803878A
_08038708:
	bl BoxLandingInit
_0803870C:
	bl BoxLanding
	b _0803878A
_08038712:
	bl BoxJumpWarningInit
_08038716:
	bl BoxJumpWarning
	b _0803878A
_0803871C:
	bl BoxJumpingInit
_08038720:
	bl BoxJumping
	b _0803878A
_08038726:
	bl BoxStoppingToFireBombInit
_0803872A:
	bl BoxStoppingToFireBomb
	b _0803878A
_08038730:
	bl BoxLoweringToFireBombInit
_08038734:
	bl BoxLoweringToFireBomb
	b _0803878A
_0803873A:
	bl BoxFiringBomb
	b _0803878A
_08038740:
	bl BoxDoneFiringBomb
	b _0803878A
_08038746:
	bl BoxWaitingToEmergeInit
_0803874A:
	bl BoxWaitingToEmerge
	b _0803878A
_08038750:
	bl BoxFirstJumpInit
_08038754:
	bl BoxFirstJump
	b _0803878A
_0803875A:
	bl BoxDyingInit
_0803875E:
	bl BoxDying
	b _0803878A
_08038764:
	bl BoxMovingToFinalJumpInit
_08038768:
	bl BoxMovingToFinalJump
	b _0803878A
_0803876E:
	bl BoxWaitingForFinalJumpInit
_08038772:
	bl BoxWaitingForFinalJump
	b _0803878A
_08038778:
	bl BoxCrouchingForFinalJumpInit
_0803877C:
	bl BoxCrouchingForFinalJump
	b _0803878A
_08038782:
	bl BoxFinalJumpInit
_08038786:
	bl BoxFinalJump
_0803878A:
	bl SpriteUtilUpdateSubSpriteData1Animation
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BoxPart
BoxPart: @ 0x08038798
	push {r4, lr}
	ldr r0, _080387B0 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x24
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	bne _080387B4
	bl BoxPartInit
	b _0803887C
	.align 2, 0
_080387B0: .4byte gCurrentSprite
_080387B4:
	ldrb r0, [r2, #0x1e]
	cmp r0, #2
	beq _080387F4
	cmp r0, #2
	bgt _080387C4
	cmp r0, #0
	beq _080387CE
	b _0803885C
_080387C4:
	cmp r0, #6
	beq _0803881C
	cmp r0, #8
	beq _08038834
	b _0803885C
_080387CE:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _080387F0 @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _080387E6
	strb r3, [r4]
_080387E6:
	bl BoxPartFrontLeftLeg
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _0803887C
	.align 2, 0
_080387F0: .4byte gSubSpriteData1
_080387F4:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08038818 @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _0803880C
	strb r3, [r4]
_0803880C:
	bl BoxPartFrontRightLeg
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _0803887C
	.align 2, 0
_08038818: .4byte gSubSpriteData1
_0803881C:
	ldr r0, _08038830 @ =gSubSpriteData1
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r1, [r1]
	strb r1, [r0, #0xe]
	bl BoxPartCenter
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _0803887C
	.align 2, 0
_08038830: .4byte gSubSpriteData1
_08038834:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08038858 @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _0803884C
	strb r3, [r4]
_0803884C:
	bl BoxPartCenterBottom
	bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position
	b _0803887C
	.align 2, 0
_08038858: .4byte gSubSpriteData1
_0803885C:
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r2, [r4]
	movs r0, #0x7f
	ldr r1, _08038884 @ =gSubSpriteData1
	ldrb r3, [r1, #0xe]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bhs _08038874
	strb r3, [r4]
_08038874:
	bl BoxPartDefault
	bl BoxSyncSubSprites
_0803887C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038884: .4byte gSubSpriteData1

	thumb_func_start BoxMissile
BoxMissile: @ 0x08038888
	push {lr}
	ldr r0, _080388A0 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _080388B4
	cmp r0, #2
	bgt _080388A4
	cmp r0, #0
	beq _080388AE
	b _080388C4
	.align 2, 0
_080388A0: .4byte gCurrentSprite
_080388A4:
	cmp r0, #0x18
	beq _080388BA
	cmp r0, #0x37
	beq _080388C0
	b _080388C4
_080388AE:
	bl BoxMissileInit
	b _080388C4
_080388B4:
	bl BoxMissileSpawning
	b _080388C4
_080388BA:
	bl BoxMissileMoving
	b _080388C4
_080388C0:
	bl BoxMissileExploding
_080388C4:
	pop {r0}
	bx r0

	thumb_func_start BoxBomb
BoxBomb: @ 0x080388C8
	push {lr}
	ldr r0, _080388E0 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _080388F4
	cmp r0, #2
	bgt _080388E4
	cmp r0, #0
	beq _080388EE
	b _08038904
	.align 2, 0
_080388E0: .4byte gCurrentSprite
_080388E4:
	cmp r0, #0x18
	beq _080388FA
	cmp r0, #0x37
	beq _08038900
	b _08038904
_080388EE:
	bl BoxBombInit
	b _08038904
_080388F4:
	bl BoxBombMoving
	b _08038904
_080388FA:
	bl BoxBombLanded
	b _08038904
_08038900:
	bl BoxBombExploding
_08038904:
	pop {r0}
	bx r0

	thumb_func_start BoxFire
BoxFire: @ 0x08038908
	push {lr}
	ldr r0, _08038920 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803892E
	cmp r0, #2
	bgt _08038924
	cmp r0, #0
	beq _0803892A
	b _08038938
	.align 2, 0
_08038920: .4byte gCurrentSprite
_08038924:
	cmp r0, #0x18
	beq _08038934
	b _08038938
_0803892A:
	bl BoxFireInit
_0803892E:
	bl BoxFireMovingHigh
	b _08038938
_08038934:
	bl BoxFireMovingLow
_08038938:
	pop {r0}
	bx r0

	thumb_func_start BoxDebris
BoxDebris: @ 0x0803893C
	push {lr}
	ldr r0, _08038954 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1c
	bhi _080389EC
	lsls r0, r0, #2
	ldr r1, _08038958 @ =_0803895C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038954: .4byte gCurrentSprite
_08038958: .4byte _0803895C
_0803895C: @ jump table
	.4byte _080389D0 @ case 0
	.4byte _080389EC @ case 1
	.4byte _080389D6 @ case 2
	.4byte _080389EC @ case 3
	.4byte _080389EC @ case 4
	.4byte _080389EC @ case 5
	.4byte _080389EC @ case 6
	.4byte _080389EC @ case 7
	.4byte _080389EC @ case 8
	.4byte _080389EC @ case 9
	.4byte _080389EC @ case 10
	.4byte _080389EC @ case 11
	.4byte _080389EC @ case 12
	.4byte _080389EC @ case 13
	.4byte _080389EC @ case 14
	.4byte _080389EC @ case 15
	.4byte _080389EC @ case 16
	.4byte _080389EC @ case 17
	.4byte _080389EC @ case 18
	.4byte _080389EC @ case 19
	.4byte _080389EC @ case 20
	.4byte _080389EC @ case 21
	.4byte _080389EC @ case 22
	.4byte _080389EC @ case 23
	.4byte _080389DC @ case 24
	.4byte _080389EC @ case 25
	.4byte _080389E2 @ case 26
	.4byte _080389EC @ case 27
	.4byte _080389E8 @ case 28
_080389D0:
	bl BoxDebrisInit
	b _080389EC
_080389D6:
	bl BoxDebrisIdle
	b _080389EC
_080389DC:
	bl BoxDebrisFallingInit
	b _080389EC
_080389E2:
	bl BoxDebrisWaitToFall
	b _080389EC
_080389E8:
	bl BoxDebrisFalling
_080389EC:
	pop {r0}
	bx r0

	thumb_func_start BoxFallingDebris
BoxFallingDebris: @ 0x080389F0
	push {lr}
	ldr r0, _08038A04 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08038A08
	cmp r0, #2
	beq _08038A0E
	b _08038A12
	.align 2, 0
_08038A04: .4byte gCurrentSprite
_08038A08:
	bl BoxFallingDebrisInit
	b _08038A12
_08038A0E:
	bl BoxFallingDebrisFalling
_08038A12:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GerudaYMovement
GerudaYMovement: @ 0x08038A18
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r5, #0
	ldr r4, _08038A48 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08038A50
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08038A4C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _08038A62
	ldrh r0, [r4, #2]
	adds r0, r5, r0
	b _08038A70
	.align 2, 0
_08038A48: .4byte gCurrentSprite
_08038A4C: .4byte gPreviousCollisionCheck
_08038A50:
	ldrh r0, [r4, #2]
	subs r0, #0x40
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08038A68 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _08038A6C
_08038A62:
	movs r0, #1
	b _08038A74
	.align 2, 0
_08038A68: .4byte gPreviousCollisionCheck
_08038A6C:
	ldrh r0, [r4, #2]
	subs r0, r0, r6
_08038A70:
	strh r0, [r4, #2]
	movs r0, #0
_08038A74:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GerudaXMovement
GerudaXMovement: @ 0x08038A7C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r7, r6, #0
	ldr r4, _08038ABC @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08038AC4
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08038AC0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08038AEA
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08038AEA
	ldrh r0, [r4, #4]
	adds r0, r6, r0
	b _08038AF8
	.align 2, 0
_08038ABC: .4byte gCurrentSprite
_08038AC0: .4byte gPreviousCollisionCheck
_08038AC4:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08038AF0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08038AEA
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _08038AF4
_08038AEA:
	movs r0, #1
	b _08038AFC
	.align 2, 0
_08038AF0: .4byte gPreviousCollisionCheck
_08038AF4:
	ldrh r0, [r4, #4]
	subs r0, r0, r7
_08038AF8:
	strh r0, [r4, #4]
	movs r0, #0
_08038AFC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GerudaSetIdleSideHitboxes
GerudaSetIdleSideHitboxes: @ 0x08038B04
	push {lr}
	ldr r2, _08038B20 @ =gCurrentSprite
	ldr r3, _08038B24 @ =0x0000FFE0
	strh r3, [r2, #0xa]
	movs r0, #0x40
	strh r0, [r2, #0xc]
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08038B28
	strh r3, [r2, #0xe]
	movs r0, #0x30
	b _08038B2E
	.align 2, 0
_08038B20: .4byte gCurrentSprite
_08038B24: .4byte 0x0000FFE0
_08038B28:
	ldr r0, _08038B34 @ =0x0000FFD0
	strh r0, [r2, #0xe]
	movs r0, #0x20
_08038B2E:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_08038B34: .4byte 0x0000FFD0

	thumb_func_start GerudaSetAttackingSideHitboxes
GerudaSetAttackingSideHitboxes: @ 0x08038B38
	push {lr}
	ldr r2, _08038B54 @ =gCurrentSprite
	ldr r3, _08038B58 @ =0x0000FFE0
	strh r3, [r2, #0xa]
	movs r0, #0x28
	strh r0, [r2, #0xc]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08038B5C
	strh r3, [r2, #0xe]
	movs r0, #0x50
	b _08038B62
	.align 2, 0
_08038B54: .4byte gCurrentSprite
_08038B58: .4byte 0x0000FFE0
_08038B5C:
	ldr r0, _08038B68 @ =0x0000FFB0
	strh r0, [r2, #0xe]
	movs r0, #0x20
_08038B62:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_08038B68: .4byte 0x0000FFB0

	thumb_func_start GerudaUpdateLungingAnimation
GerudaUpdateLungingAnimation: @ 0x08038B6C
	push {lr}
	movs r0, #0xe0
	movs r1, #0xc0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08038BAE
	ldr r1, _08038B90 @ =gCurrentSprite
	ldr r0, [r1, #0x18]
	ldr r2, _08038B94 @ =0x08348C64
	cmp r0, r2
	beq _08038B98
	str r2, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	b _08038BE0
	.align 2, 0
_08038B90: .4byte gCurrentSprite
_08038B94: .4byte 0x08348C64
_08038B98:
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _08038BE0
	ldrb r0, [r1, #0x1c]
	cmp r0, #4
	bne _08038BE0
	movs r0, #0xc6
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _08038BE0
_08038BAE:
	ldr r2, _08038BE4 @ =gCurrentSprite
	ldr r1, [r2, #0x18]
	ldr r0, _08038BE8 @ =0x08348C64
	cmp r1, r0
	bne _08038BE0
	ldrh r0, [r2, #0x16]
	cmp r0, #0
	bne _08038BCC
	ldrb r0, [r2, #0x1c]
	cmp r0, #4
	bne _08038BCC
	movs r0, #0xc6
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08038BCC:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08038BE0
	ldr r0, _08038BE4 @ =gCurrentSprite
	ldr r1, _08038BEC @ =0x08348C54
	str r1, [r0, #0x18]
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
_08038BE0:
	pop {r0}
	bx r0
	.align 2, 0
_08038BE4: .4byte gCurrentSprite
_08038BE8: .4byte 0x08348C64
_08038BEC: .4byte 0x08348C54

	thumb_func_start GerudaInit
GerudaInit: @ 0x08038BF0
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _08038C1C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08038C20
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08038C20
	strh r0, [r2]
	b _08038C84
	.align 2, 0
_08038C1C: .4byte gCurrentSprite
_08038C20:
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	ldr r5, _08038C74 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x27
	movs r4, #0
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0x20
	strb r0, [r1]
	bl GerudaSetIdleSideHitboxes
	ldr r0, _08038C78 @ =0x08348C1C
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
	ldr r2, _08038C7C @ =sPrimarySpriteStats
	ldrb r1, [r5, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _08038C80
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r5, #6]
	b _08038C84
	.align 2, 0
_08038C74: .4byte gCurrentSprite
_08038C78: .4byte 0x08348C1C
_08038C7C: .4byte sPrimarySpriteStats
_08038C80:
	movs r0, #1
	strb r0, [r1]
_08038C84:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GerudaIdleInit
GerudaIdleInit: @ 0x08038C8C
	ldr r3, _08038CB0 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	ldr r0, _08038CB4 @ =0x08348C1C
	str r0, [r3, #0x18]
	adds r0, r3, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_08038CB0: .4byte gCurrentSprite
_08038CB4: .4byte 0x08348C1C

	thumb_func_start GerudaIdle
GerudaIdle: @ 0x08038CB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _08038D28 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _08038CCE
	b _08038E98
_08038CCE:
	adds r4, r2, #0
	adds r4, #0x31
	ldrb r0, [r4]
	cmp r0, #0x23
	bhi _08038CEE
	ldrh r0, [r2, #2]
	adds r0, #0x40
	ldrh r1, [r2, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _08038D2C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _08038CEE
	movs r0, #0x24
	strb r0, [r4]
_08038CEE:
	ldr r4, _08038D28 @ =gCurrentSprite
	adds r6, r4, #0
	adds r6, #0x31
	ldrb r2, [r6]
	ldr r5, _08038D30 @ =0x083480C8
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _08038D34 @ =0x00007FFF
	cmp r1, r0
	bne _08038D0C
	ldrh r3, [r5]
	movs r2, #0
_08038D0C:
	adds r0, r2, #1
	strb r0, [r6]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	movs r0, #1
	bl GerudaXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08038D38
	adds r1, r4, #0
	b _08038E92
	.align 2, 0
_08038D28: .4byte gCurrentSprite
_08038D2C: .4byte gPreviousCollisionCheck
_08038D30: .4byte 0x083480C8
_08038D34: .4byte 0x00007FFF
_08038D38:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08038D56
	cmp r2, #8
	beq _08038D5C
	b _08038E86
_08038D56:
	cmp r2, #4
	beq _08038D5C
	movs r2, #0
_08038D5C:
	cmp r2, #0
	bne _08038D62
	b _08038E86
_08038D62:
	ldr r2, _08038DA4 @ =gCurrentSprite
	ldrh r1, [r2]
	ldr r0, _08038DA8 @ =0x0000F7FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08038DAC @ =gSamusData
	ldrh r0, [r1, #0x18]
	subs r0, #0x48
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r5, [r2, #2]
	adds r0, r5, #0
	adds r0, #0x64
	adds r4, r2, #0
	mov r8, r1
	cmp r6, r0
	ble _08038DE8
	subs r0, #0x24
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _08038DB0 @ =gPreviousCollisionCheck
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _08038DB4
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x3d
	bls _08038E98
	adds r1, r4, #0
	b _08038E92
	.align 2, 0
_08038DA4: .4byte gCurrentSprite
_08038DA8: .4byte 0x0000F7FF
_08038DAC: .4byte gSamusData
_08038DB0: .4byte gPreviousCollisionCheck
_08038DB4:
	ldrh r0, [r4, #2]
	adds r0, #0x60
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _08038DD2
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x3d
	bls _08038E98
	adds r1, r4, #0
	b _08038E92
_08038DD2:
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
	b _08038E42
_08038DE8:
	adds r0, r5, #0
	subs r0, #0x64
	cmp r6, r0
	bge _08038E3A
	adds r0, #0x24
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _08038E10 @ =gPreviousCollisionCheck
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _08038E14
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x3d
	bls _08038E98
	adds r1, r4, #0
	b _08038E92
	.align 2, 0
_08038E10: .4byte gPreviousCollisionCheck
_08038E14:
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r7]
	cmp r0, #0x11
	bne _08038E32
	adds r0, r4, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x3d
	bls _08038E98
	adds r1, r4, #0
	b _08038E92
_08038E32:
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #1
	b _08038E40
_08038E3A:
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #2
_08038E40:
	strb r0, [r1]
_08038E42:
	strh r5, [r4, #6]
	strh r6, [r4, #8]
	mov r7, r8
	ldrh r6, [r7, #0x16]
	ldrh r5, [r4, #4]
	cmp r5, r6
	bls _08038E54
	subs r0, r5, r6
	b _08038E56
_08038E54:
	subs r0, r6, r5
_08038E56:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r5, r0
	bls _08038E6A
	adds r1, r4, #0
	adds r1, #0x30
	movs r0, #8
	b _08038E7C
_08038E6A:
	cmp r5, #0xa0
	bls _08038E76
	adds r1, r4, #0
	adds r1, #0x30
	movs r0, #6
	b _08038E7C
_08038E76:
	adds r1, r4, #0
	adds r1, #0x30
	movs r0, #4
_08038E7C:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	b _08038E96
_08038E86:
	ldr r1, _08038EA4 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0x3d
	bls _08038E98
_08038E92:
	adds r1, #0x24
	movs r0, #3
_08038E96:
	strb r0, [r1]
_08038E98:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038EA4: .4byte gCurrentSprite

	thumb_func_start GerudaTurningAroundInit
GerudaTurningAroundInit: @ 0x08038EA8
	ldr r1, _08038EC0 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #4
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _08038EC4 @ =0x08348C94
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_08038EC0: .4byte gCurrentSprite
_08038EC4: .4byte 0x08348C94

	thumb_func_start GerudaTurningAround
GerudaTurningAround: @ 0x08038EC8
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _08038EE4
	ldr r2, _08038EE8 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_08038EE4:
	pop {r0}
	bx r0
	.align 2, 0
_08038EE8: .4byte gCurrentSprite

	thumb_func_start GerudaAttackWarningInit
GerudaAttackWarningInit: @ 0x08038EEC
	push {lr}
	ldr r1, _08038F08 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	ldr r0, _08038F0C @ =0x08348C44
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bl GerudaSetAttackingSideHitboxes
	pop {r0}
	bx r0
	.align 2, 0
_08038F08: .4byte gCurrentSprite
_08038F0C: .4byte 0x08348C44

	thumb_func_start GerudaAttackWarning
GerudaAttackWarning: @ 0x08038F10
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08038F34
	ldr r0, _08038F38 @ =gCurrentSprite
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
	ldr r1, _08038F3C @ =0x08348C54
	str r1, [r0, #0x18]
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x2c
	strb r1, [r2]
	adds r0, #0x2e
	movs r1, #0xb4
	strb r1, [r0]
_08038F34:
	pop {r0}
	bx r0
	.align 2, 0
_08038F38: .4byte gCurrentSprite
_08038F3C: .4byte 0x08348C54

	thumb_func_start GerudaAttacking
GerudaAttacking: @ 0x08038F40
	push {r4, r5, lr}
	bl GerudaUpdateLungingAnimation
	movs r5, #0
	ldr r4, _08038F84 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne _08038F92
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	bl GerudaXMovement
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r5, r1, #0x1f
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08038F8C
	ldrh r0, [r4, #2]
	ldrh r2, [r4, #8]
	cmp r0, r2
	blo _08038FB6
	ldr r0, _08038F88 @ =0x0000F7FF
	ands r0, r1
	strh r0, [r4]
	b _08038FB6
	.align 2, 0
_08038F84: .4byte gCurrentSprite
_08038F88: .4byte 0x0000F7FF
_08038F8C:
	ldrh r0, [r4, #2]
	ldrh r4, [r4, #6]
	b _08038FAC
_08038F92:
	cmp r0, #1
	bne _08038FCA
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	bl GerudaXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08038FA8
	movs r5, #1
_08038FA8:
	ldrh r0, [r4, #2]
	ldrh r4, [r4, #8]
_08038FAC:
	cmp r0, r4
	bhi _08038FB6
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08038FB6:
	movs r0, #4
	bl GerudaYMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08038FD8
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08038FD8
_08038FCA:
	movs r0, #8
	bl GerudaXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08038FD8
	movs r5, #1
_08038FD8:
	ldr r2, _08039010 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08038FF0
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08038FF0:
	cmp r5, #0
	beq _0803903C
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08039018
	ldr r1, _08039014 @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bls _08039030
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #3
	b _08039036
	.align 2, 0
_08039010: .4byte gCurrentSprite
_08039014: .4byte gSamusData
_08039018:
	ldr r1, _0803902C @ =gSamusData
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #0x16]
	cmp r0, r1
	bhs _08039030
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #3
	b _08039036
	.align 2, 0
_0803902C: .4byte gSamusData
_08039030:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #1
_08039036:
	strb r0, [r1]
	bl GerudaSetIdleSideHitboxes
_0803903C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Geruda
Geruda: @ 0x08039044
	push {r4, lr}
	ldr r4, _0803906C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803905C
	ldr r0, _08039070 @ =0x0000018D
	bl SoundPlayNotAlreadyPlaying
_0803905C:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08039074
	bl SpriteUtilUpdateFreezeTimer
	b _08039242
	.align 2, 0
_0803906C: .4byte gCurrentSprite
_08039070: .4byte 0x0000018D
_08039074:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08039080
	b _08039242
_08039080:
	lsls r0, r0, #2
	ldr r1, _0803908C @ =_08039090
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803908C: .4byte _08039090
_08039090: @ jump table
	.4byte _08039200 @ case 0
	.4byte _08039206 @ case 1
	.4byte _0803920A @ case 2
	.4byte _08039210 @ case 3
	.4byte _08039214 @ case 4
	.4byte _08039242 @ case 5
	.4byte _08039242 @ case 6
	.4byte _08039242 @ case 7
	.4byte _08039242 @ case 8
	.4byte _08039242 @ case 9
	.4byte _08039242 @ case 10
	.4byte _08039242 @ case 11
	.4byte _08039242 @ case 12
	.4byte _08039242 @ case 13
	.4byte _08039242 @ case 14
	.4byte _08039242 @ case 15
	.4byte _08039242 @ case 16
	.4byte _08039242 @ case 17
	.4byte _08039242 @ case 18
	.4byte _08039242 @ case 19
	.4byte _08039242 @ case 20
	.4byte _08039242 @ case 21
	.4byte _08039242 @ case 22
	.4byte _08039242 @ case 23
	.4byte _08039242 @ case 24
	.4byte _08039242 @ case 25
	.4byte _08039242 @ case 26
	.4byte _08039242 @ case 27
	.4byte _08039242 @ case 28
	.4byte _08039242 @ case 29
	.4byte _08039242 @ case 30
	.4byte _08039242 @ case 31
	.4byte _08039242 @ case 32
	.4byte _08039242 @ case 33
	.4byte _08039242 @ case 34
	.4byte _08039242 @ case 35
	.4byte _08039242 @ case 36
	.4byte _08039242 @ case 37
	.4byte _08039242 @ case 38
	.4byte _08039242 @ case 39
	.4byte _08039242 @ case 40
	.4byte _0803921A @ case 41
	.4byte _0803921E @ case 42
	.4byte _08039242 @ case 43
	.4byte _08039224 @ case 44
	.4byte _08039242 @ case 45
	.4byte _08039242 @ case 46
	.4byte _08039242 @ case 47
	.4byte _08039242 @ case 48
	.4byte _08039242 @ case 49
	.4byte _08039242 @ case 50
	.4byte _08039242 @ case 51
	.4byte _08039242 @ case 52
	.4byte _08039242 @ case 53
	.4byte _08039242 @ case 54
	.4byte _08039242 @ case 55
	.4byte _08039242 @ case 56
	.4byte _08039242 @ case 57
	.4byte _08039242 @ case 58
	.4byte _08039242 @ case 59
	.4byte _08039242 @ case 60
	.4byte _08039242 @ case 61
	.4byte _08039242 @ case 62
	.4byte _08039242 @ case 63
	.4byte _08039242 @ case 64
	.4byte _08039242 @ case 65
	.4byte _08039242 @ case 66
	.4byte _08039242 @ case 67
	.4byte _08039242 @ case 68
	.4byte _08039242 @ case 69
	.4byte _08039242 @ case 70
	.4byte _08039242 @ case 71
	.4byte _08039242 @ case 72
	.4byte _08039242 @ case 73
	.4byte _08039242 @ case 74
	.4byte _08039242 @ case 75
	.4byte _08039242 @ case 76
	.4byte _08039242 @ case 77
	.4byte _08039242 @ case 78
	.4byte _08039242 @ case 79
	.4byte _08039242 @ case 80
	.4byte _08039242 @ case 81
	.4byte _08039242 @ case 82
	.4byte _08039242 @ case 83
	.4byte _08039242 @ case 84
	.4byte _08039242 @ case 85
	.4byte _08039242 @ case 86
	.4byte _0803922A @ case 87
	.4byte _0803922E @ case 88
	.4byte _08039234 @ case 89
	.4byte _08039238 @ case 90
	.4byte _0803923E @ case 91
_08039200:
	bl GerudaInit
	b _08039242
_08039206:
	bl GerudaIdleInit
_0803920A:
	bl GerudaIdle
	b _08039242
_08039210:
	bl GerudaTurningAroundInit
_08039214:
	bl GerudaTurningAround
	b _08039242
_0803921A:
	bl GerudaAttackWarningInit
_0803921E:
	bl GerudaAttackWarning
	b _08039242
_08039224:
	bl GerudaAttacking
	b _08039242
_0803922A:
	bl SpriteDyingInit
_0803922E:
	bl SpriteDying
	b _08039242
_08039234:
	bl GerudaInit
_08039238:
	bl SpriteSpawningFromX
	b _08039242
_0803923E:
	bl XParasiteInit
_08039242:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start MiscPadInit
MiscPadInit: @ 0x08039248
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	movs r5, #0
	ldr r3, _0803929C @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r5, [r0]
	adds r1, r3, #0
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _080392A0 @ =0x0000FFFC
	strh r1, [r3, #0xa]
	movs r0, #4
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	adds r1, r3, #0
	adds r1, #0x21
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r3, #0x1d]
	adds r4, r3, #0
	cmp r0, #0x66
	beq _080392B4
	cmp r0, #0x66
	bgt _080392A4
	cmp r0, #0x65
	beq _080392AE
	b _080392FC
	.align 2, 0
_0803929C: .4byte gCurrentSprite
_080392A0: .4byte 0x0000FFFC
_080392A4:
	cmp r0, #0x67
	beq _080392DC
	cmp r0, #0x68
	beq _080392E6
	b _080392FC
_080392AE:
	bl EventCheckOn_EnteredPumpControlUnit
	b _080392E0
_080392B4:
	bl EventCheckOn_Meltdown
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #1
	bne _08039302
	ldrb r1, [r4, #0x1e]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x53
	movs r2, #0
	movs r3, #0x10
	bl SpriteSpawnPrimary
	movs r5, #0
	b _08039302
_080392DC:
	bl EventCheckOn_SpaceJumpRecovered
_080392E0:
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08039302
_080392E6:
	bl EventCheckOn_NavigationRoomLeavingPyr2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080392F8 @ =gAbilityRestingXPosition
	ldrh r0, [r4, #4]
	strh r0, [r1]
	b _08039302
	.align 2, 0
_080392F8: .4byte gAbilityRestingXPosition
_080392FC:
	movs r0, #0
	strh r0, [r4]
	b _0803937E
_08039302:
	ldr r4, _08039330 @ =gCurrentSprite
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x33
	movs r1, #0
	bl SpriteSpawnSecondary
	cmp r5, #0
	beq _08039334
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	b _0803933A
	.align 2, 0
_08039330: .4byte gCurrentSprite
_08039334:
	adds r0, r4, #0
	adds r0, #0x2f
	strb r5, [r0]
_0803933A:
	ldr r6, _08039388 @ =gCurrentSprite
	ldrb r0, [r6, #0x1d]
	cmp r0, #0x68
	bne _0803937E
	adds r7, r6, #0
	adds r7, #0x23
	ldrb r3, [r7]
	ldrh r0, [r6, #2]
	str r0, [sp]
	ldrh r0, [r6, #4]
	ldr r5, _0803938C @ =0xFFFFFF00
	adds r0, r0, r5
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #0x68
	movs r1, #0
	movs r2, #4
	bl SpriteSpawnSecondary
	ldrb r3, [r7]
	ldrh r0, [r6, #2]
	str r0, [sp]
	ldrh r0, [r6, #4]
	adds r0, r0, r5
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x67
	movs r1, #0
	movs r2, #4
	bl SpriteSpawnSecondary
	ldr r1, _08039390 @ =gBossWork2
	strb r0, [r1]
_0803937E:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039388: .4byte gCurrentSprite
_0803938C: .4byte 0xFFFFFF00
_08039390: .4byte gBossWork2

	thumb_func_start MiscPadIdleInit
MiscPadIdleInit: @ 0x08039394
	push {lr}
	ldr r1, _080393BC @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne _080393D4
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x68
	bne _080393C4
	ldr r0, _080393C0 @ =0x0834AD8C
	b _080393C6
	.align 2, 0
_080393BC: .4byte gCurrentSprite
_080393C0: .4byte 0x0834AD8C
_080393C4:
	ldr r0, _080393D0 @ =0x0834A0F4
_080393C6:
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x46
	b _080393EC
	.align 2, 0
_080393D0: .4byte 0x0834A0F4
_080393D4:
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x68
	bne _080393E4
	ldr r0, _080393E0 @ =0x0834AD7C
	b _080393E6
	.align 2, 0
_080393E0: .4byte 0x0834AD7C
_080393E4:
	ldr r0, _080393F4 @ =0x0834A0E4
_080393E6:
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #2
_080393EC:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080393F4: .4byte 0x0834A0E4

	thumb_func_start MiscPadIdle
MiscPadIdle: @ 0x080393F8
	push {lr}
	bl NavPadDetectSamus
	cmp r0, #0
	beq _08039448
	ldr r1, _08039420 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #0
	bne _08039450
	ldrb r0, [r3, #0x1d]
	cmp r0, #0x68
	bne _08039428
	ldr r0, _08039424 @ =0x0834AD2C
	b _0803942A
	.align 2, 0
_08039420: .4byte gCurrentSprite
_08039424: .4byte 0x0834AD2C
_08039428:
	ldr r0, _08039444 @ =0x0834A094
_0803942A:
	str r0, [r3, #0x18]
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x18
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r0, #0xe9
	bl SoundPlay
	b _08039450
	.align 2, 0
_08039444: .4byte 0x0834A094
_08039448:
	ldr r0, _08039454 @ =gCurrentSprite
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
_08039450:
	pop {r0}
	bx r0
	.align 2, 0
_08039454: .4byte gCurrentSprite

	thumb_func_start MiscPadPressingSwitch
MiscPadPressingSwitch: @ 0x08039458
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803948A
	ldr r0, _08039470 @ =gCurrentSprite
	ldrb r1, [r0, #0x1d]
	adds r3, r0, #0
	cmp r1, #0x68
	bne _08039478
	ldr r0, _08039474 @ =0x0834AD8C
	b _0803947A
	.align 2, 0
_08039470: .4byte gCurrentSprite
_08039474: .4byte 0x0834AD8C
_08039478:
	ldr r0, _08039490 @ =0x0834A0F4
_0803947A:
	str r0, [r3, #0x18]
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x1a
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
_0803948A:
	pop {r0}
	bx r0
	.align 2, 0
_08039490: .4byte 0x0834A0F4

	thumb_func_start MiscPadSwitchPressed
MiscPadSwitchPressed: @ 0x08039494
	push {r4, lr}
	bl NavPadDetectSamus
	cmp r0, #0
	beq _080394E4
	bl SpriteUtilCheckSamusMorphed
	cmp r0, #0
	bne _08039514
	ldr r2, _080394D8 @ =gSamusData
	ldr r4, _080394DC @ =gCurrentSprite
	ldrh r0, [r4, #4]
	strh r0, [r2, #0x16]
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _080394B8
	movs r0, #0
	strb r0, [r2, #5]
_080394B8:
	ldr r1, _080394E0 @ =sSamusSetPoseFunctionPointer
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x36
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x14
	strb r0, [r1]
	b _08039514
	.align 2, 0
_080394D8: .4byte gSamusData
_080394DC: .4byte gCurrentSprite
_080394E0: .4byte sSamusSetPoseFunctionPointer
_080394E4:
	ldr r0, _080394F4 @ =gCurrentSprite
	ldrb r1, [r0, #0x1d]
	adds r3, r0, #0
	cmp r1, #0x68
	bne _080394FC
	ldr r0, _080394F8 @ =0x0834AD54
	b _080394FE
	.align 2, 0
_080394F4: .4byte gCurrentSprite
_080394F8: .4byte 0x0834AD54
_080394FC:
	ldr r0, _0803951C @ =0x0834A0BC
_080394FE:
	str r0, [r3, #0x18]
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x1c
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r0, #0xe6
	bl SoundPlay
_08039514:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803951C: .4byte 0x0834A0BC

	thumb_func_start MiscPadReleasingSwitch
MiscPadReleasingSwitch: @ 0x08039520
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803952E
	bl MiscPadIdleInit
_0803952E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MiscPadSamusInteracting
MiscPadSamusInteracting: @ 0x08039534
	push {r4, lr}
	ldr r2, _08039564 @ =gCurrentSprite
	adds r4, r2, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803957C
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08039552
	ldr r0, _08039568 @ =0x00000103
	bl SoundPlay
_08039552:
	ldrb r0, [r4]
	cmp r0, #7
	bhi _0803956C
	adds r2, r0, #0
	movs r0, #0x21
	movs r1, #2
	bl SpriteLoadGfx
	b _0803959A
	.align 2, 0
_08039564: .4byte gCurrentSprite
_08039568: .4byte 0x00000103
_0803956C:
	cmp r0, #8
	bne _0803959A
	movs r0, #0x21
	movs r1, #2
	movs r2, #2
	bl SpriteLoadPal
	b _0803959A
_0803957C:
	ldr r1, _080395A0 @ =gSamusData
	ldrb r0, [r1, #1]
	cmp r0, #0x36
	bne _0803959A
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xd
	bls _0803959A
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #0x3a
	strb r1, [r0]
	movs r0, #0x1e
	strb r0, [r4]
_0803959A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080395A0: .4byte gSamusData

	thumb_func_start MiscPadSpawnMessageBanner
MiscPadSpawnMessageBanner: @ 0x080395A4
	push {lr}
	sub sp, #0xc
	movs r3, #0
	ldr r2, _080395D4 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08039632
	subs r1, #0xa
	movs r0, #0x1e
	strb r0, [r1]
	ldrb r1, [r2, #0x1d]
	cmp r1, #0x66
	beq _080395EC
	cmp r1, #0x66
	bgt _080395D8
	cmp r1, #0x65
	beq _080395E2
	b _08039608
	.align 2, 0
_080395D4: .4byte gCurrentSprite
_080395D8:
	cmp r1, #0x67
	beq _080395F6
	cmp r1, #0x68
	beq _08039600
	b _08039608
_080395E2:
	movs r0, #0x20
	bl EventCheckAdvance
	movs r3, #6
	b _0803960C
_080395EC:
	movs r0, #0x3d
	bl EventCheckAdvance
	movs r3, #7
	b _0803960C
_080395F6:
	movs r0, #0x4a
	bl EventCheckAdvance
	movs r3, #9
	b _0803960C
_08039600:
	movs r0, #0x3f
	bl EventCheckAdvance
	movs r3, #8
_08039608:
	cmp r3, #0
	beq _08039632
_0803960C:
	ldr r1, _08039638 @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0803963C @ =gXParasiteTargetYPosition
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08039640 @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0x21
	adds r1, r3, #0
	movs r2, #2
	movs r3, #0x10
	bl SpriteSpawnPrimary
_08039632:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08039638: .4byte gPreventMovementTimer
_0803963C: .4byte gXParasiteTargetYPosition
_08039640: .4byte gXParasiteTargetXPosition

	thumb_func_start MiscPadAfterInteraction
MiscPadAfterInteraction: @ 0x08039644
	push {lr}
	ldr r1, _08039660 @ =gCurrentSprite
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x68
	bne _08039672
	ldr r0, _08039664 @ =gSamusData
	ldrb r0, [r0, #1]
	cmp r0, #0x3b
	bne _08039668
	adds r1, #0x24
	movs r0, #0x20
	strb r0, [r1]
	b _08039672
	.align 2, 0
_08039660: .4byte gCurrentSprite
_08039664: .4byte gSamusData
_08039668:
	ldr r1, _08039678 @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
_08039672:
	pop {r0}
	bx r0
	.align 2, 0
_08039678: .4byte gPreventMovementTimer

	thumb_func_start MiscPadInactive
MiscPadInactive: @ 0x0803967C
	bx lr
	.align 2, 0

	thumb_func_start MiscPadWaitForWideBeamCoreX
MiscPadWaitForWideBeamCoreX: @ 0x08039680
	push {r4, lr}
	ldr r4, _080396C8 @ =gCurrentSprite
	ldrb r0, [r4, #0x1d]
	cmp r0, #0x66
	bne _080396C2
	bl EventCheckOn_Meltdown
	cmp r0, #2
	bne _080396C2
	movs r0, #0x57
	bl SpriteUtilCountPrimarySprites
	cmp r0, #0
	bne _080396C2
	ldr r0, _080396CC @ =gPreventMovementTimer
	ldrh r2, [r0]
	cmp r2, #0
	bne _080396C2
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	subs r1, #0xb
	movs r0, #0x1c
	strb r0, [r1]
	ldr r0, _080396D0 @ =0x0834A0BC
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
	movs r0, #0x81
	lsls r0, r0, #1
	bl SoundPlay
_080396C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080396C8: .4byte gCurrentSprite
_080396CC: .4byte gPreventMovementTimer
_080396D0: .4byte 0x0834A0BC

	thumb_func_start MiscPadConsoleInit
MiscPadConsoleInit: @ 0x080396D4
	push {r4, r5, lr}
	ldr r0, _0803974C @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x23
	ldrb r4, [r0]
	mov r2, ip
	ldrh r1, [r2]
	ldr r0, _08039750 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r5, #0
	strh r0, [r2]
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	adds r0, #2
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08039754 @ =0x0000FFFC
	mov r0, ip
	strh r1, [r0, #0xa]
	movs r0, #4
	mov r2, ip
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xd
	strb r0, [r1]
	strb r3, [r2, #0x1c]
	strh r5, [r2, #0x16]
	ldr r1, _08039758 @ =gSpriteData
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r1, [r0, #0x1d]
	mov r4, ip
	cmp r1, #0x66
	bne _08039760
	bl EventCheckOn_Meltdown
	cmp r0, #0
	beq _08039790
	ldr r0, _0803975C @ =0x0834A044
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	b _0803979A
	.align 2, 0
_0803974C: .4byte gCurrentSprite
_08039750: .4byte 0x0000FFFB
_08039754: .4byte 0x0000FFFC
_08039758: .4byte gSpriteData
_0803975C: .4byte 0x0834A044
_08039760:
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08039784
	cmp r1, #0x68
	bne _08039774
	ldr r0, _08039770 @ =0x0834ACDC
	b _08039776
	.align 2, 0
_08039770: .4byte 0x0834ACDC
_08039774:
	ldr r0, _08039780 @ =0x0834A044
_08039776:
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	b _0803979A
	.align 2, 0
_08039780: .4byte 0x0834A044
_08039784:
	cmp r1, #0x68
	bne _08039790
	ldr r0, _0803978C @ =0x0834AD04
	b _08039792
	.align 2, 0
_0803978C: .4byte 0x0834AD04
_08039790:
	ldr r0, _080397A4 @ =0x0834A06C
_08039792:
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
_0803979A:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080397A4: .4byte 0x0834A06C

	thumb_func_start MiscPadConsoleIdle
MiscPadConsoleIdle: @ 0x080397A8
	push {lr}
	ldr r3, _080397D0 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _080397D4 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bne _080397EE
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x68
	bne _080397DC
	ldr r0, _080397D8 @ =0x0834AD04
	b _080397DE
	.align 2, 0
_080397D0: .4byte gCurrentSprite
_080397D4: .4byte gSpriteData
_080397D8: .4byte 0x0834AD04
_080397DC:
	ldr r0, _080397F4 @ =0x0834A06C
_080397DE:
	str r0, [r3, #0x18]
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x18
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
_080397EE:
	pop {r0}
	bx r0
	.align 2, 0
_080397F4: .4byte 0x0834A06C

	thumb_func_start MiscPad
MiscPad: @ 0x080397F8
	push {lr}
	ldr r0, _08039818 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x46
	bls _0803980E
	b _0803997A
_0803980E:
	lsls r0, r0, #2
	ldr r1, _0803981C @ =_08039820
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039818: .4byte gCurrentSprite
_0803981C: .4byte _08039820
_08039820: @ jump table
	.4byte _0803993C @ case 0
	.4byte _08039940 @ case 1
	.4byte _08039946 @ case 2
	.4byte _0803997A @ case 3
	.4byte _0803997A @ case 4
	.4byte _0803997A @ case 5
	.4byte _0803997A @ case 6
	.4byte _0803997A @ case 7
	.4byte _0803997A @ case 8
	.4byte _0803997A @ case 9
	.4byte _0803997A @ case 10
	.4byte _0803997A @ case 11
	.4byte _0803997A @ case 12
	.4byte _0803997A @ case 13
	.4byte _0803997A @ case 14
	.4byte _0803997A @ case 15
	.4byte _0803997A @ case 16
	.4byte _0803997A @ case 17
	.4byte _0803997A @ case 18
	.4byte _0803997A @ case 19
	.4byte _0803997A @ case 20
	.4byte _0803997A @ case 21
	.4byte _0803997A @ case 22
	.4byte _0803997A @ case 23
	.4byte _0803994C @ case 24
	.4byte _0803997A @ case 25
	.4byte _08039952 @ case 26
	.4byte _0803997A @ case 27
	.4byte _08039958 @ case 28
	.4byte _0803997A @ case 29
	.4byte _0803995E @ case 30
	.4byte _0803997A @ case 31
	.4byte _08039964 @ case 32
	.4byte _0803997A @ case 33
	.4byte _0803997A @ case 34
	.4byte _0803997A @ case 35
	.4byte _0803997A @ case 36
	.4byte _0803997A @ case 37
	.4byte _0803997A @ case 38
	.4byte _0803997A @ case 39
	.4byte _0803997A @ case 40
	.4byte _0803997A @ case 41
	.4byte _0803997A @ case 42
	.4byte _0803997A @ case 43
	.4byte _0803997A @ case 44
	.4byte _0803997A @ case 45
	.4byte _0803997A @ case 46
	.4byte _0803997A @ case 47
	.4byte _0803997A @ case 48
	.4byte _0803997A @ case 49
	.4byte _0803997A @ case 50
	.4byte _0803997A @ case 51
	.4byte _0803997A @ case 52
	.4byte _0803997A @ case 53
	.4byte _0803997A @ case 54
	.4byte _0803997A @ case 55
	.4byte _0803996A @ case 56
	.4byte _0803997A @ case 57
	.4byte _08039970 @ case 58
	.4byte _0803997A @ case 59
	.4byte _0803997A @ case 60
	.4byte _0803997A @ case 61
	.4byte _0803997A @ case 62
	.4byte _0803997A @ case 63
	.4byte _0803997A @ case 64
	.4byte _0803997A @ case 65
	.4byte _0803997A @ case 66
	.4byte _0803997A @ case 67
	.4byte _0803997A @ case 68
	.4byte _0803997A @ case 69
	.4byte _08039976 @ case 70
_0803993C:
	bl MiscPadInit
_08039940:
	bl MiscPadIdleInit
	b _0803997A
_08039946:
	bl MiscPadIdle
	b _0803997A
_0803994C:
	bl MiscPadPressingSwitch
	b _0803997A
_08039952:
	bl MiscPadSwitchPressed
	b _0803997A
_08039958:
	bl MiscPadReleasingSwitch
	b _0803997A
_0803995E:
	bl MiscPadAfterInteraction
	b _0803997A
_08039964:
	bl MiscPadInactive
	b _0803997A
_0803996A:
	bl MiscPadSamusInteracting
	b _0803997A
_08039970:
	bl MiscPadSpawnMessageBanner
	b _0803997A
_08039976:
	bl MiscPadWaitForWideBeamCoreX
_0803997A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MiscPadConsole
MiscPadConsole: @ 0x08039980
	push {lr}
	ldr r0, _0803999C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _080399A0
	cmp r0, #2
	beq _080399A6
	b _080399AA
	.align 2, 0
_0803999C: .4byte gCurrentSprite
_080399A0:
	bl MiscPadConsoleInit
	b _080399AA
_080399A6:
	bl MiscPadConsoleIdle
_080399AA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OperationsRoomPadInit
OperationsRoomPadInit: @ 0x080399B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r4, _08039A38 @ =gCurrentSprite
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r7, #0
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x25
	strb r7, [r0]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _08039A3C @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x21
	movs r1, #1
	mov r8, r1
	mov r1, r8
	strb r1, [r0]
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x34
	movs r1, #0
	bl SpriteSpawnSecondary
	bl EventCheckOn_SaXDefeated
	adds r5, r0, #0
	cmp r5, #0
	beq _08039A40
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
	b _08039A5E
	.align 2, 0
_08039A38: .4byte gCurrentSprite
_08039A3C: .4byte 0x0000FFFC
_08039A40:
	bl EventCheckAfter_OrbitChange
	cmp r0, #0
	beq _08039A68
	adds r0, r4, #0
	adds r0, #0x2f
	mov r1, r8
	strb r1, [r0]
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
_08039A5E:
	movs r0, #0x35
	movs r1, #0
	bl SpriteSpawnSecondary
	b _08039A70
_08039A68:
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #2
	strb r0, [r1]
_08039A70:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start OperationsRoomPadIdleInit
OperationsRoomPadIdleInit: @ 0x08039A7C
	push {lr}
	ldr r1, _08039AA4 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08039AAC
	ldr r0, _08039AA8 @ =0x0834C344
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x46
	b _08039AB4
	.align 2, 0
_08039AA4: .4byte gCurrentSprite
_08039AA8: .4byte 0x0834C344
_08039AAC:
	ldr r0, _08039ABC @ =0x0834C2F4
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #2
_08039AB4:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08039ABC: .4byte 0x0834C2F4

	thumb_func_start OperationsRoomPadIdle
OperationsRoomPadIdle: @ 0x08039AC0
	push {lr}
	bl NavPadDetectSamus
	cmp r0, #0
	beq _08039B00
	ldr r3, _08039AF4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08039B08
	subs r1, #0xa
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08039AF8 @ =0x0834C254
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _08039AFC @ =0x00000101
	bl SoundPlay
	b _08039B08
	.align 2, 0
_08039AF4: .4byte gCurrentSprite
_08039AF8: .4byte 0x0834C254
_08039AFC: .4byte 0x00000101
_08039B00:
	ldr r0, _08039B0C @ =gCurrentSprite
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
_08039B08:
	pop {r0}
	bx r0
	.align 2, 0
_08039B0C: .4byte gCurrentSprite

	thumb_func_start OperationsRoomPadPressingSwitch
OperationsRoomPadPressingSwitch: @ 0x08039B10
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08039B2E
	ldr r1, _08039B34 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1a
	strb r0, [r2]
	ldr r0, _08039B38 @ =0x0834C344
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
_08039B2E:
	pop {r0}
	bx r0
	.align 2, 0
_08039B34: .4byte gCurrentSprite
_08039B38: .4byte 0x0834C344

	thumb_func_start OperationsRoomPadSwitchPressed
OperationsRoomPadSwitchPressed: @ 0x08039B3C
	push {r4, lr}
	bl NavPadDetectSamus
	adds r3, r0, #0
	cmp r3, #0
	beq _08039B90
	bl SpriteUtilCheckSamusMorphed
	cmp r0, #0
	bne _08039BAA
	ldr r2, _08039B84 @ =gSamusData
	ldr r4, _08039B88 @ =gCurrentSprite
	ldrh r0, [r4, #4]
	strh r0, [r2, #0x16]
	ldrb r0, [r2, #5]
	cmp r0, #0
	beq _08039B62
	movs r0, #0
	strb r0, [r2, #5]
_08039B62:
	ldr r1, _08039B8C @ =sSamusSetPoseFunctionPointer
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x36
	bl _call_via_r1
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x14
	strb r0, [r1]
	b _08039BAA
	.align 2, 0
_08039B84: .4byte gSamusData
_08039B88: .4byte gCurrentSprite
_08039B8C: .4byte sSamusSetPoseFunctionPointer
_08039B90:
	ldr r1, _08039BB0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _08039BB4 @ =0x0834C2CC
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	movs r0, #0x81
	lsls r0, r0, #1
	bl SoundPlay
_08039BAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039BB0: .4byte gCurrentSprite
_08039BB4: .4byte 0x0834C2CC

	thumb_func_start OperationsRoomPadReleasing
OperationsRoomPadReleasing: @ 0x08039BB8
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08039BC6
	bl OperationsRoomPadIdleInit
_08039BC6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OperationsRoomPadSamusInteracting
OperationsRoomPadSamusInteracting: @ 0x08039BCC
	push {lr}
	ldr r0, _08039C10 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039BEA
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08039BEA
	ldr r0, _08039C14 @ =0x00000103
	bl SoundPlay
_08039BEA:
	ldr r1, _08039C18 @ =gSamusData
	ldrb r0, [r1, #1]
	cmp r0, #0x36
	bne _08039C0C
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _08039C0C
	ldr r1, _08039C10 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x3a
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x1e
	strb r0, [r1]
_08039C0C:
	pop {r0}
	bx r0
	.align 2, 0
_08039C10: .4byte gCurrentSprite
_08039C14: .4byte 0x00000103
_08039C18: .4byte gSamusData

	thumb_func_start OperationsRoomPadStartEscape
OperationsRoomPadStartEscape: @ 0x08039C1C
	push {lr}
	ldr r1, _08039C58 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08039C52
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
	ldr r1, _08039C5C @ =gPreventMovementTimer
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0x67
	bl EventCheckAdvance
	movs r0, #0xb
	bl TrySpawnMessageBanner
	movs r0, #0
	bl FadeMusic
_08039C52:
	pop {r0}
	bx r0
	.align 2, 0
_08039C58: .4byte gCurrentSprite
_08039C5C: .4byte gPreventMovementTimer

	thumb_func_start OperationsRoomPadConsoleInit
OperationsRoomPadConsoleInit: @ 0x08039C60
	push {r4, lr}
	ldr r0, _08039CB4 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08039CB8 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r0, #2
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08039CBC @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xd
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _08039CC0 @ =0x0834C244
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039CB4: .4byte gCurrentSprite
_08039CB8: .4byte 0x0000FFFB
_08039CBC: .4byte 0x0000FFFC
_08039CC0: .4byte 0x0834C244

	thumb_func_start OperationsRoomPadConsoleIdle
OperationsRoomPadConsoleIdle: @ 0x08039CC4
	bx lr
	.align 2, 0

	thumb_func_start OperationsRoomPadConsoleScreenInit
OperationsRoomPadConsoleScreenInit: @ 0x08039CC8
	push {r4, lr}
	ldr r0, _08039D3C @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _08039D40 @ =0x0000FFFB
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
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08039D44 @ =0x0000FFFC
	mov r2, ip
	strh r1, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	ldr r2, _08039D48 @ =gSpriteData
	mov r0, ip
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08039D50
	ldr r0, _08039D4C @ =0x0834C27C
	mov r1, ip
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x18
	b _08039D5C
	.align 2, 0
_08039D3C: .4byte gCurrentSprite
_08039D40: .4byte 0x0000FFFB
_08039D44: .4byte 0x0000FFFC
_08039D48: .4byte gSpriteData
_08039D4C: .4byte 0x0834C27C
_08039D50:
	ldr r0, _08039D64 @ =0x0834C2A4
	mov r2, ip
	str r0, [r2, #0x18]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
_08039D5C:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039D64: .4byte 0x0834C2A4

	thumb_func_start OperationsRoomPadConsoleScreenIdle
OperationsRoomPadConsoleScreenIdle: @ 0x08039D68
	push {lr}
	ldr r2, _08039D9C @ =gSpriteData
	ldr r3, _08039DA0 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bne _08039D96
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _08039DA4 @ =0x0834C27C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
_08039D96:
	pop {r0}
	bx r0
	.align 2, 0
_08039D9C: .4byte gSpriteData
_08039DA0: .4byte gCurrentSprite
_08039DA4: .4byte 0x0834C27C

	thumb_func_start OperationsRoomPadScreenInit
OperationsRoomPadScreenInit: @ 0x08039DA8
	push {r4, lr}
	ldr r0, _08039E0C @ =gCurrentSprite
	mov ip, r0
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	mov r4, ip
	ldrh r1, [r4]
	ldr r0, _08039E10 @ =0x0000FFFB
	ands r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r0, #2
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _08039E14 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _08039E18 @ =0x0834C31C
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r3, [r4, #0x16]
	movs r0, #0x82
	lsls r0, r0, #1
	bl SoundPlay
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039E0C: .4byte gCurrentSprite
_08039E10: .4byte 0x0000FFFB
_08039E14: .4byte 0x0000FFFC
_08039E18: .4byte 0x0834C31C

	thumb_func_start OperationsRoomPadScreenTurningOn
OperationsRoomPadScreenTurningOn: @ 0x08039E1C
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08039E38
	ldr r1, _08039E3C @ =gCurrentSprite
	ldr r0, _08039E40 @ =0x0834C304
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
_08039E38:
	pop {r0}
	bx r0
	.align 2, 0
_08039E3C: .4byte gCurrentSprite
_08039E40: .4byte 0x0834C304

	thumb_func_start OperationsRoomPadScreenIdle
OperationsRoomPadScreenIdle: @ 0x08039E44
	push {lr}
	ldr r3, _08039E7C @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _08039E80 @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _08039E78
	ldr r0, _08039E84 @ =0x0834C354
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, #0xeb
	bl SoundPlay
_08039E78:
	pop {r0}
	bx r0
	.align 2, 0
_08039E7C: .4byte gCurrentSprite
_08039E80: .4byte gSpriteData
_08039E84: .4byte 0x0834C354

	thumb_func_start OperationsRoomPadScreenTurningOff
OperationsRoomPadScreenTurningOff: @ 0x08039E88
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08039E98
	ldr r1, _08039E9C @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
_08039E98:
	pop {r0}
	bx r0
	.align 2, 0
_08039E9C: .4byte gCurrentSprite

	thumb_func_start OperationsRoomPad
OperationsRoomPad: @ 0x08039EA0
	push {lr}
	ldr r0, _08039EC0 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bls _08039EB6
	b _08039FE0
_08039EB6:
	lsls r0, r0, #2
	ldr r1, _08039EC4 @ =_08039EC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08039EC0: .4byte gCurrentSprite
_08039EC4: .4byte _08039EC8
_08039EC8: @ jump table
	.4byte _08039FB4 @ case 0
	.4byte _08039FB8 @ case 1
	.4byte _08039FBE @ case 2
	.4byte _08039FE0 @ case 3
	.4byte _08039FE0 @ case 4
	.4byte _08039FE0 @ case 5
	.4byte _08039FE0 @ case 6
	.4byte _08039FE0 @ case 7
	.4byte _08039FE0 @ case 8
	.4byte _08039FE0 @ case 9
	.4byte _08039FE0 @ case 10
	.4byte _08039FE0 @ case 11
	.4byte _08039FE0 @ case 12
	.4byte _08039FE0 @ case 13
	.4byte _08039FE0 @ case 14
	.4byte _08039FE0 @ case 15
	.4byte _08039FE0 @ case 16
	.4byte _08039FE0 @ case 17
	.4byte _08039FE0 @ case 18
	.4byte _08039FE0 @ case 19
	.4byte _08039FE0 @ case 20
	.4byte _08039FE0 @ case 21
	.4byte _08039FE0 @ case 22
	.4byte _08039FE0 @ case 23
	.4byte _08039FC4 @ case 24
	.4byte _08039FE0 @ case 25
	.4byte _08039FCA @ case 26
	.4byte _08039FE0 @ case 27
	.4byte _08039FD0 @ case 28
	.4byte _08039FE0 @ case 29
	.4byte _08039FE0 @ case 30
	.4byte _08039FE0 @ case 31
	.4byte _08039FE0 @ case 32
	.4byte _08039FE0 @ case 33
	.4byte _08039FE0 @ case 34
	.4byte _08039FE0 @ case 35
	.4byte _08039FE0 @ case 36
	.4byte _08039FE0 @ case 37
	.4byte _08039FE0 @ case 38
	.4byte _08039FE0 @ case 39
	.4byte _08039FE0 @ case 40
	.4byte _08039FE0 @ case 41
	.4byte _08039FE0 @ case 42
	.4byte _08039FE0 @ case 43
	.4byte _08039FE0 @ case 44
	.4byte _08039FE0 @ case 45
	.4byte _08039FE0 @ case 46
	.4byte _08039FE0 @ case 47
	.4byte _08039FE0 @ case 48
	.4byte _08039FE0 @ case 49
	.4byte _08039FE0 @ case 50
	.4byte _08039FE0 @ case 51
	.4byte _08039FE0 @ case 52
	.4byte _08039FE0 @ case 53
	.4byte _08039FE0 @ case 54
	.4byte _08039FE0 @ case 55
	.4byte _08039FD6 @ case 56
	.4byte _08039FE0 @ case 57
	.4byte _08039FDC @ case 58
_08039FB4:
	bl OperationsRoomPadInit
_08039FB8:
	bl OperationsRoomPadIdleInit
	b _08039FE0
_08039FBE:
	bl OperationsRoomPadIdle
	b _08039FE0
_08039FC4:
	bl OperationsRoomPadPressingSwitch
	b _08039FE0
_08039FCA:
	bl OperationsRoomPadSwitchPressed
	b _08039FE0
_08039FD0:
	bl OperationsRoomPadReleasing
	b _08039FE0
_08039FD6:
	bl OperationsRoomPadSamusInteracting
	b _08039FE0
_08039FDC:
	bl OperationsRoomPadStartEscape
_08039FE0:
	pop {r0}
	bx r0

	thumb_func_start OperationsRoomPadConsole
OperationsRoomPadConsole: @ 0x08039FE4
	push {lr}
	ldr r0, _0803A000 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803A004
	cmp r0, #2
	beq _0803A008
	b _0803A00C
	.align 2, 0
_0803A000: .4byte gCurrentSprite
_0803A004:
	bl OperationsRoomPadConsoleInit
_0803A008:
	bl OperationsRoomPadConsoleIdle
_0803A00C:
	pop {r0}
	bx r0

	thumb_func_start OperationsRoomPadConsoleScreen
OperationsRoomPadConsoleScreen: @ 0x0803A010
	push {lr}
	ldr r0, _0803A02C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803A030
	cmp r0, #2
	beq _0803A036
	b _0803A03A
	.align 2, 0
_0803A02C: .4byte gCurrentSprite
_0803A030:
	bl OperationsRoomPadConsoleScreenInit
	b _0803A03A
_0803A036:
	bl OperationsRoomPadConsoleScreenIdle
_0803A03A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start OperationsRoomPadScreen
OperationsRoomPadScreen: @ 0x0803A040
	push {lr}
	ldr r0, _0803A060 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803A072
	cmp r0, #2
	bgt _0803A064
	cmp r0, #0
	beq _0803A06E
	b _0803A082
	.align 2, 0
_0803A060: .4byte gCurrentSprite
_0803A064:
	cmp r0, #0x18
	beq _0803A078
	cmp r0, #0x1a
	beq _0803A07E
	b _0803A082
_0803A06E:
	bl OperationsRoomPadScreenInit
_0803A072:
	bl OperationsRoomPadScreenTurningOn
	b _0803A082
_0803A078:
	bl OperationsRoomPadScreenIdle
	b _0803A082
_0803A07E:
	bl OperationsRoomPadScreenTurningOff
_0803A082:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ScientistInit
ScientistInit: @ 0x0803A088
	push {r4, r5, lr}
	ldr r2, _0803A0AC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0803A0B0 @ =gEquipment
	ldrb r1, [r0, #0xa]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803A0B4
	movs r0, #0
	strh r0, [r2]
	b _0803A0FC
	.align 2, 0
_0803A0AC: .4byte gCurrentSprite
_0803A0B0: .4byte gEquipment
_0803A0B4:
	adds r1, r2, #0
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	ldrh r1, [r2]
	ldr r0, _0803A104 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x25
	strb r5, [r0]
	adds r3, r2, #0
	adds r3, #0x27
	movs r0, #0x28
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r3, #2
	movs r0, #0x10
	strb r0, [r3]
	ldr r0, _0803A108 @ =0x0000FF88
	strh r0, [r2, #0xa]
	strh r4, [r2, #0xc]
	adds r0, #0x64
	strh r0, [r2, #0xe]
	movs r0, #0x14
	strh r0, [r2, #0x10]
	adds r0, r2, #0
	adds r0, #0x24
	strb r5, [r0]
	ldr r0, _0803A10C @ =0x0834D9EC
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r4, [r2, #0x16]
_0803A0FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803A104: .4byte 0x0000FFFB
_0803A108: .4byte 0x0000FF88
_0803A10C: .4byte 0x0834D9EC

	thumb_func_start ScientistIdle
ScientistIdle: @ 0x0803A110
	push {lr}
	ldr r3, _0803A144 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bls _0803A13E
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0803A148 @ =0x0834DAC4
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	adds r1, #0xa
	movs r0, #0x3c
	strb r0, [r1]
	bl SpriteUtilMakeSpriteFaceSamusXFlip
_0803A13E:
	pop {r0}
	bx r0
	.align 2, 0
_0803A144: .4byte gCurrentSprite
_0803A148: .4byte 0x0834DAC4

	thumb_func_start ScientistTurning
ScientistTurning: @ 0x0803A14C
	push {lr}
	ldr r1, _0803A16C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A166
	adds r1, #0x24
	movs r0, #0x45
	strb r0, [r1]
_0803A166:
	pop {r0}
	bx r0
	.align 2, 0
_0803A16C: .4byte gCurrentSprite

	thumb_func_start ScientistTransformingInit
ScientistTransformingInit: @ 0x0803A170
	ldr r3, _0803A194 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x46
	strb r0, [r1]
	ldrh r1, [r3]
	ldr r2, _0803A198 @ =0x00008020
	adds r0, r2, #0
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	movs r0, #0x2c
	strh r0, [r3, #6]
	bx lr
	.align 2, 0
_0803A194: .4byte gCurrentSprite
_0803A198: .4byte 0x00008020

	thumb_func_start ScientistTransforming
ScientistTransforming: @ 0x0803A19C
	push {r4, lr}
	ldr r2, _0803A1E4 @ =gWrittenToMosaic_H
	ldr r1, _0803A1E8 @ =sXParasiteMosaicValues
	ldr r4, _0803A1EC @ =gCurrentSprite
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
	bhi _0803A1F0
	ldrh r2, [r4, #6]
	movs r0, #0x57
	movs r1, #0
	bl SpriteLoadGfx
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0803A1FE
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x59
	strb r0, [r1]
	movs r0, #0x57
	strb r0, [r4, #0x1d]
	ldrh r0, [r4]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4]
	b _0803A1FE
	.align 2, 0
_0803A1E4: .4byte gWrittenToMosaic_H
_0803A1E8: .4byte sXParasiteMosaicValues
_0803A1EC: .4byte gCurrentSprite
_0803A1F0:
	cmp r0, #0x14
	bne _0803A1FE
	movs r0, #0x57
	movs r1, #0
	movs r2, #5
	bl SpriteLoadPal
_0803A1FE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Scientist
Scientist: @ 0x0803A204
	push {lr}
	ldr r0, _0803A224 @ =gCurrentSprite
	movs r1, #1
	strh r1, [r0, #0x14]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _0803A23E
	cmp r0, #0x18
	bgt _0803A228
	cmp r0, #0
	beq _0803A232
	cmp r0, #2
	beq _0803A238
	b _0803A24C
	.align 2, 0
_0803A224: .4byte gCurrentSprite
_0803A228:
	cmp r0, #0x45
	beq _0803A244
	cmp r0, #0x46
	beq _0803A248
	b _0803A24C
_0803A232:
	bl ScientistInit
	b _0803A24C
_0803A238:
	bl ScientistIdle
	b _0803A24C
_0803A23E:
	bl ScientistTurning
	b _0803A24C
_0803A244:
	bl ScientistTransformingInit
_0803A248:
	bl ScientistTransforming
_0803A24C:
	pop {r0}
	bx r0

	thumb_func_start SkulteraSetSidesHitboxes
SkulteraSetSidesHitboxes: @ 0x0803A250
	push {lr}
	ldr r2, _0803A270 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803A284
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A278
	ldr r0, _0803A274 @ =0x0000FFE8
	strh r0, [r2, #0xe]
	movs r0, #0x28
	b _0803A2A2
	.align 2, 0
_0803A270: .4byte gCurrentSprite
_0803A274: .4byte 0x0000FFE8
_0803A278:
	ldr r0, _0803A280 @ =0x0000FFF0
	strh r0, [r2, #0xe]
	movs r0, #0x20
	b _0803A2A2
	.align 2, 0
_0803A280: .4byte 0x0000FFF0
_0803A284:
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A29C
	ldr r0, _0803A298 @ =0x0000FFD8
	strh r0, [r2, #0xe]
	movs r0, #0x18
	b _0803A2A2
	.align 2, 0
_0803A298: .4byte 0x0000FFD8
_0803A29C:
	ldr r0, _0803A2A8 @ =0x0000FFE0
	strh r0, [r2, #0xe]
	movs r0, #0x10
_0803A2A2:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_0803A2A8: .4byte 0x0000FFE0

	thumb_func_start SkulteraXMovement
SkulteraXMovement: @ 0x0803A2AC
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r2, _0803A2D0 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0803A2F8
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A2D4
	ldrh r0, [r4, #4]
	adds r0, #0x38
	b _0803A2D8
	.align 2, 0
_0803A2D0: .4byte gCurrentSprite
_0803A2D4:
	ldrh r0, [r4, #4]
	adds r0, #0x28
_0803A2D8:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r4, #2]
	subs r0, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803A2F4 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _0803A320
	ldrh r0, [r4, #4]
	adds r0, r5, r0
	b _0803A32C
	.align 2, 0
_0803A2F4: .4byte gPreviousCollisionCheck
_0803A2F8:
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A308
	ldrh r0, [r4, #4]
	subs r0, #0x38
	b _0803A30C
_0803A308:
	ldrh r0, [r4, #4]
	subs r0, #0x28
_0803A30C:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r4, #2]
	subs r0, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803A324 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0803A328
_0803A320:
	movs r0, #1
	b _0803A330
	.align 2, 0
_0803A324: .4byte gPreviousCollisionCheck
_0803A328:
	ldrh r0, [r4, #4]
	subs r0, r0, r5
_0803A32C:
	strh r0, [r4, #4]
	movs r0, #0
_0803A330:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start SkulteraTurningIntoX
SkulteraTurningIntoX: @ 0x0803A338
	push {lr}
	sub sp, #0x10
	ldr r2, _0803A370 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A374
	ldrb r1, [r2, #0x1d]
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r2, #2]
	subs r0, #0x30
	str r0, [sp, #4]
	ldrh r0, [r2, #4]
	subs r0, #0x10
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	b _0803A37A
	.align 2, 0
_0803A370: .4byte gCurrentSprite
_0803A374:
	ldrh r0, [r2, #2]
	subs r0, #0x20
	strh r0, [r2, #2]
_0803A37A:
	add sp, #0x10
	pop {r0}
	bx r0

	thumb_func_start SkulteraInit
SkulteraInit: @ 0x0803A380
	push {r4, r5, lr}
	ldr r2, _0803A3B4 @ =gCurrentSprite
	adds r4, r2, #0
	adds r4, #0x24
	ldrb r3, [r4]
	cmp r3, #0
	bne _0803A3D8
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x2f
	bhi _0803A3C2
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _0803A3B8
	adds r0, r2, #0
	adds r0, #0x2d
	strb r3, [r0]
	b _0803A3C6
	.align 2, 0
_0803A3B4: .4byte gCurrentSprite
_0803A3B8:
	adds r1, r2, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	b _0803A3C6
_0803A3C2:
	strh r3, [r2]
	b _0803A498
_0803A3C6:
	bl SpriteUtilChooseRandomXFlip
	ldr r0, _0803A3D4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
	b _0803A3EA
	.align 2, 0
_0803A3D4: .4byte gCurrentSprite
_0803A3D8:
	adds r1, r2, #0
	adds r1, #0x2d
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x5a
	strb r0, [r4]
	movs r0, #0x2c
	strh r0, [r2, #6]
_0803A3EA:
	ldr r1, _0803A440 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x25
	movs r4, #0
	movs r0, #2
	strb r0, [r2]
	strb r4, [r1, #0x1c]
	movs r5, #0
	strh r4, [r1, #0x16]
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #2
	bne _0803A44C
	adds r2, r3, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	ldr r0, _0803A444 @ =0x0834F074
	str r0, [r3, #0x18]
	adds r1, r3, #0
	adds r1, #0x27
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0803A448 @ =0x0000FF80
	strh r0, [r3, #0xa]
	strh r4, [r3, #0xc]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x6a
	strb r0, [r3, #0x1d]
	b _0803A484
	.align 2, 0
_0803A440: .4byte gCurrentSprite
_0803A444: .4byte 0x0834F074
_0803A448: .4byte 0x0000FF80
_0803A44C:
	ldr r0, _0803A4A0 @ =0x0834EFEC
	str r0, [r3, #0x18]
	ldrb r0, [r3, #0x1d]
	cmp r0, #0xb5
	beq _0803A462
	adds r0, r3, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
_0803A462:
	adds r0, r3, #0
	adds r0, #0x27
	movs r2, #0x18
	strb r2, [r0]
	adds r1, r3, #0
	adds r1, #0x28
	movs r0, #8
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x29
	strb r2, [r0]
	ldr r0, _0803A4A4 @ =0x0000FFC0
	strh r0, [r3, #0xa]
	strh r4, [r3, #0xc]
	adds r1, #0xe
	movs r0, #1
	strb r0, [r1]
_0803A484:
	ldr r2, _0803A4A8 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	bl SkulteraSetSidesHitboxes
_0803A498:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803A4A0: .4byte 0x0834EFEC
_0803A4A4: .4byte 0x0000FFC0
_0803A4A8: .4byte sPrimarySpriteStats

	thumb_func_start SkulteraIdleInit
SkulteraIdleInit: @ 0x0803A4AC
	push {lr}
	ldr r0, _0803A4DC @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0, #4]
	movs r2, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1, #8]
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	mov r0, ip
	strb r2, [r0, #0x1c]
	strh r3, [r0, #0x16]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A4E4
	ldr r0, _0803A4E0 @ =0x0834F074
	mov r1, ip
	str r0, [r1, #0x18]
	adds r1, #0x2e
	movs r0, #3
	b _0803A4EE
	.align 2, 0
_0803A4DC: .4byte gCurrentSprite
_0803A4E0: .4byte 0x0834F074
_0803A4E4:
	ldr r0, _0803A4F4 @ =0x0834EFEC
	mov r1, ip
	str r0, [r1, #0x18]
	adds r1, #0x2e
	movs r0, #4
_0803A4EE:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803A4F4: .4byte 0x0834EFEC

	thumb_func_start SkulteraIdle
SkulteraIdle: @ 0x0803A4F8
	push {r4, lr}
	ldr r4, _0803A520 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A572
	movs r0, #4
	bl SkulteraXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A524
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #3
	b _0803A570
	.align 2, 0
_0803A520: .4byte gCurrentSprite
_0803A524:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803A53E
	ldrh r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r4, #4]
	cmp r0, r1
	bge _0803A552
	b _0803A54A
_0803A53E:
	ldrh r0, [r4, #8]
	ldr r1, _0803A564 @ =0xFFFFFE00
	adds r0, r0, r1
	ldrh r1, [r4, #4]
	cmp r0, r1
	ble _0803A552
_0803A54A:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
_0803A552:
	ldr r1, _0803A568 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A56C
	adds r1, #0x2e
	movs r0, #3
	b _0803A570
	.align 2, 0
_0803A564: .4byte 0xFFFFFE00
_0803A568: .4byte gCurrentSprite
_0803A56C:
	adds r1, #0x2e
	movs r0, #4
_0803A570:
	strb r0, [r1]
_0803A572:
	ldr r0, _0803A5AC @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803A5D2
	movs r0, #0xa0
	lsls r0, r0, #2
	movs r1, #0x40
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	bne _0803A5D2
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r0, #0xc0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	adds r2, r0, #0
	ldr r3, _0803A5B0 @ =gCurrentSprite
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803A5BA
	cmp r2, #8
	bne _0803A5B4
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x29
	b _0803A5D0
	.align 2, 0
_0803A5AC: .4byte 0x03001346
_0803A5B0: .4byte gCurrentSprite
_0803A5B4:
	cmp r2, #4
	bne _0803A5D2
	b _0803A5CA
_0803A5BA:
	cmp r2, #4
	bne _0803A5C6
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x29
	b _0803A5D0
_0803A5C6:
	cmp r2, #8
	bne _0803A5D2
_0803A5CA:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #3
_0803A5D0:
	strb r0, [r1]
_0803A5D2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start SkulteraChasingSamusInit
SkulteraChasingSamusInit: @ 0x0803A5D8
	push {lr}
	ldr r3, _0803A5F8 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x2a
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A600
	ldr r0, _0803A5FC @ =0x0834F0E4
	b _0803A602
	.align 2, 0
_0803A5F8: .4byte gCurrentSprite
_0803A5FC: .4byte 0x0834F0E4
_0803A600:
	ldr r0, _0803A608 @ =0x0834F054
_0803A602:
	str r0, [r3, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_0803A608: .4byte 0x0834F054

	thumb_func_start SkulteraChasingSamus
SkulteraChasingSamus: @ 0x0803A60C
	push {r4, r5, lr}
	ldr r2, _0803A654 @ =gSamusData
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r4, _0803A658 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, r2
	ble _0803A664
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803A65C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803A682
	ldr r0, _0803A660 @ =gCurrentAffectingClipdata
	ldrh r0, [r0, #2]
	cmp r0, #1
	bne _0803A682
	ldrh r0, [r4, #2]
	subs r0, #2
	b _0803A680
	.align 2, 0
_0803A654: .4byte gSamusData
_0803A658: .4byte gCurrentSprite
_0803A65C: .4byte gPreviousCollisionCheck
_0803A660: .4byte gCurrentAffectingClipdata
_0803A664:
	adds r0, r1, #0
	adds r0, #0x40
	cmp r0, r2
	bge _0803A682
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803A6AC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803A682
	ldrh r0, [r4, #2]
	adds r0, #2
_0803A680:
	strh r0, [r4, #2]
_0803A682:
	ldr r4, _0803A6B0 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A6C2
	movs r0, #4
	bl SkulteraXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A6B4
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
	b _0803A6C2
	.align 2, 0
_0803A6AC: .4byte gPreviousCollisionCheck
_0803A6B0: .4byte gCurrentSprite
_0803A6B4:
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803A6C0
	movs r0, #3
_0803A6C0:
	strb r0, [r5]
_0803A6C2:
	ldr r0, _0803A6D4 @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803A6DC
	ldr r0, _0803A6D8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
	b _0803A730
	.align 2, 0
_0803A6D4: .4byte 0x03001346
_0803A6D8: .4byte gCurrentSprite
_0803A6DC:
	movs r0, #0xa0
	lsls r0, r0, #2
	movs r1, #0x40
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	bne _0803A730
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r0, #0xc0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	adds r2, r0, #0
	ldr r3, _0803A714 @ =gCurrentSprite
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803A718
	cmp r2, #8
	beq _0803A730
	cmp r2, #4
	bne _0803A728
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #3
	b _0803A72E
	.align 2, 0
_0803A714: .4byte gCurrentSprite
_0803A718:
	cmp r2, #4
	beq _0803A730
	cmp r2, #8
	bne _0803A728
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #3
	b _0803A72E
_0803A728:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #1
_0803A72E:
	strb r0, [r1]
_0803A730:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SkulteraTurningAroundInit
SkulteraTurningAroundInit: @ 0x0803A738
	push {lr}
	ldr r3, _0803A77C @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #4
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	cmp r1, #2
	bne _0803A78C
	ldr r0, _0803A780 @ =0x0834F09C
	str r0, [r3, #0x18]
	ldrh r2, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	bne _0803A7B2
	ldr r0, _0803A784 @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803A7B2
	ands r1, r2
	cmp r1, #0
	beq _0803A7B2
	ldr r0, _0803A788 @ =0x00000193
	bl SoundPlayNotAlreadyPlaying
	b _0803A7B2
	.align 2, 0
_0803A77C: .4byte gCurrentSprite
_0803A780: .4byte 0x0834F09C
_0803A784: .4byte 0x03001346
_0803A788: .4byte 0x00000193
_0803A78C:
	ldr r0, _0803A7B8 @ =0x0834F00C
	str r0, [r3, #0x18]
	ldrh r2, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r2
	cmp r0, #0
	bne _0803A7B2
	ldr r0, _0803A7BC @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803A7B2
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0803A7B2
	ldr r0, _0803A7C0 @ =0x00000191
	bl SoundPlayNotAlreadyPlaying
_0803A7B2:
	pop {r0}
	bx r0
	.align 2, 0
_0803A7B8: .4byte 0x0834F00C
_0803A7BC: .4byte 0x03001346
_0803A7C0: .4byte 0x00000191

	thumb_func_start SkulteraTurningAround
SkulteraTurningAround: @ 0x0803A7C4
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803A7E0
	bl SkulteraIdleInit
	ldr r0, _0803A7E4 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r2, #0x40
	eors r1, r2
	strh r1, [r0]
	bl SkulteraSetSidesHitboxes
_0803A7E0:
	pop {r0}
	bx r0
	.align 2, 0
_0803A7E4: .4byte gCurrentSprite

	thumb_func_start Skultera
Skultera: @ 0x0803A7E8
	push {lr}
	ldr r1, _0803A810 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803A814
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803A82A
	movs r0, #0xca
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0803A82A
	.align 2, 0
_0803A810: .4byte gCurrentSprite
_0803A814:
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803A82A
	movs r0, #0xc9
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803A82A:
	ldr r1, _0803A83C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803A840
	bl SpriteUtilUpdateFreezeTimer
	b _0803AA0E
	.align 2, 0
_0803A83C: .4byte gCurrentSprite
_0803A840:
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803A84C
	b _0803AA0E
_0803A84C:
	lsls r0, r0, #2
	ldr r1, _0803A858 @ =_0803A85C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803A858: .4byte _0803A85C
_0803A85C: @ jump table
	.4byte _0803A9CC @ case 0
	.4byte _0803A9D2 @ case 1
	.4byte _0803A9D8 @ case 2
	.4byte _0803A9DE @ case 3
	.4byte _0803A9E2 @ case 4
	.4byte _0803AA0E @ case 5
	.4byte _0803AA0E @ case 6
	.4byte _0803AA0E @ case 7
	.4byte _0803AA0E @ case 8
	.4byte _0803AA0E @ case 9
	.4byte _0803AA0E @ case 10
	.4byte _0803AA0E @ case 11
	.4byte _0803AA0E @ case 12
	.4byte _0803AA0E @ case 13
	.4byte _0803AA0E @ case 14
	.4byte _0803AA0E @ case 15
	.4byte _0803AA0E @ case 16
	.4byte _0803AA0E @ case 17
	.4byte _0803AA0E @ case 18
	.4byte _0803AA0E @ case 19
	.4byte _0803AA0E @ case 20
	.4byte _0803AA0E @ case 21
	.4byte _0803AA0E @ case 22
	.4byte _0803AA0E @ case 23
	.4byte _0803AA0E @ case 24
	.4byte _0803AA0E @ case 25
	.4byte _0803AA0E @ case 26
	.4byte _0803AA0E @ case 27
	.4byte _0803AA0E @ case 28
	.4byte _0803AA0E @ case 29
	.4byte _0803AA0E @ case 30
	.4byte _0803AA0E @ case 31
	.4byte _0803AA0E @ case 32
	.4byte _0803AA0E @ case 33
	.4byte _0803AA0E @ case 34
	.4byte _0803AA0E @ case 35
	.4byte _0803AA0E @ case 36
	.4byte _0803AA0E @ case 37
	.4byte _0803AA0E @ case 38
	.4byte _0803AA0E @ case 39
	.4byte _0803AA0E @ case 40
	.4byte _0803A9E8 @ case 41
	.4byte _0803A9EC @ case 42
	.4byte _0803AA0E @ case 43
	.4byte _0803AA0E @ case 44
	.4byte _0803AA0E @ case 45
	.4byte _0803AA0E @ case 46
	.4byte _0803AA0E @ case 47
	.4byte _0803AA0E @ case 48
	.4byte _0803AA0E @ case 49
	.4byte _0803AA0E @ case 50
	.4byte _0803AA0E @ case 51
	.4byte _0803AA0E @ case 52
	.4byte _0803AA0E @ case 53
	.4byte _0803AA0E @ case 54
	.4byte _0803AA0E @ case 55
	.4byte _0803AA0E @ case 56
	.4byte _0803AA0E @ case 57
	.4byte _0803AA0E @ case 58
	.4byte _0803AA0E @ case 59
	.4byte _0803AA0E @ case 60
	.4byte _0803AA0E @ case 61
	.4byte _0803AA0E @ case 62
	.4byte _0803AA0E @ case 63
	.4byte _0803AA0E @ case 64
	.4byte _0803AA0E @ case 65
	.4byte _0803AA0E @ case 66
	.4byte _0803AA0E @ case 67
	.4byte _0803AA0E @ case 68
	.4byte _0803AA0E @ case 69
	.4byte _0803AA0E @ case 70
	.4byte _0803AA0E @ case 71
	.4byte _0803AA0E @ case 72
	.4byte _0803AA0E @ case 73
	.4byte _0803AA0E @ case 74
	.4byte _0803AA0E @ case 75
	.4byte _0803AA0E @ case 76
	.4byte _0803AA0E @ case 77
	.4byte _0803AA0E @ case 78
	.4byte _0803AA0E @ case 79
	.4byte _0803AA0E @ case 80
	.4byte _0803AA0E @ case 81
	.4byte _0803AA0E @ case 82
	.4byte _0803AA0E @ case 83
	.4byte _0803AA0E @ case 84
	.4byte _0803AA0E @ case 85
	.4byte _0803AA0E @ case 86
	.4byte _0803A9F2 @ case 87
	.4byte _0803A9F6 @ case 88
	.4byte _0803A9FC @ case 89
	.4byte _0803AA00 @ case 90
	.4byte _0803AA06 @ case 91
_0803A9CC:
	bl SkulteraInit
	b _0803AA0E
_0803A9D2:
	bl SkulteraIdleInit
	b _0803AA0E
_0803A9D8:
	bl SkulteraIdle
	b _0803AA0E
_0803A9DE:
	bl SkulteraTurningAroundInit
_0803A9E2:
	bl SkulteraTurningAround
	b _0803AA0E
_0803A9E8:
	bl SkulteraChasingSamusInit
_0803A9EC:
	bl SkulteraChasingSamus
	b _0803AA0E
_0803A9F2:
	bl SpriteDyingInit
_0803A9F6:
	bl SpriteDying
	b _0803AA0E
_0803A9FC:
	bl SkulteraInit
_0803AA00:
	bl SpriteSpawningFromX
	b _0803AA0E
_0803AA06:
	bl SkulteraTurningIntoX
	bl XParasiteInit
_0803AA0E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZeelaCheckCollidingWithAir
ZeelaCheckCollidingWithAir: @ 0x0803AA14
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _0803AA48 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803AA74
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803AA50
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AA4C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803AAC4
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	b _0803AAB8
	.align 2, 0
_0803AA48: .4byte gCurrentSprite
_0803AA4C: .4byte gPreviousCollisionCheck
_0803AA50:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AA70 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803AAC4
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803AAB8
	.align 2, 0
_0803AA70: .4byte gPreviousCollisionCheck
_0803AA74:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803AAA0
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AA9C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803AAC4
	ldrh r0, [r4, #2]
	subs r0, #4
	b _0803AAB4
	.align 2, 0
_0803AA9C: .4byte gPreviousCollisionCheck
_0803AAA0:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AACC @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803AAC4
	ldrh r0, [r4, #2]
_0803AAB4:
	ldrh r1, [r4, #4]
	adds r1, #0x20
_0803AAB8:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803AAC4
	movs r6, #1
_0803AAC4:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0803AACC: .4byte gPreviousCollisionCheck

	thumb_func_start ZeelaUpdateHitbox
ZeelaUpdateHitbox: @ 0x0803AAD0
	push {lr}
	ldr r2, _0803AAFC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803AB20
	ldrh r1, [r2]
	movs r3, #0x40
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0803AB08
	ldr r0, _0803AB00 @ =0x0000FFD8
	strh r0, [r2, #0xa]
	movs r0, #0x28
	strh r0, [r2, #0xc]
	ldr r0, _0803AB04 @ =0x0000FFC0
	strh r0, [r2, #0xe]
	movs r0, #0x10
	b _0803AB42
	.align 2, 0
_0803AAFC: .4byte gCurrentSprite
_0803AB00: .4byte 0x0000FFD8
_0803AB04: .4byte 0x0000FFC0
_0803AB08:
	ldr r0, _0803AB18 @ =0x0000FFD8
	strh r0, [r2, #0xa]
	movs r0, #0x28
	strh r0, [r2, #0xc]
	ldr r0, _0803AB1C @ =0x0000FFF0
	strh r0, [r2, #0xe]
	strh r3, [r2, #0x10]
	b _0803AB44
	.align 2, 0
_0803AB18: .4byte 0x0000FFD8
_0803AB1C: .4byte 0x0000FFF0
_0803AB20:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803AB34
	movs r0, #0x10
	strh r0, [r2, #0xa]
	movs r0, #0x40
	b _0803AB3A
_0803AB34:
	ldr r0, _0803AB48 @ =0x0000FFC0
	strh r0, [r2, #0xa]
	movs r0, #0x10
_0803AB3A:
	strh r0, [r2, #0xc]
	ldr r0, _0803AB4C @ =0x0000FFD8
	strh r0, [r2, #0xe]
	movs r0, #0x28
_0803AB42:
	strh r0, [r2, #0x10]
_0803AB44:
	pop {r0}
	bx r0
	.align 2, 0
_0803AB48: .4byte 0x0000FFC0
_0803AB4C: .4byte 0x0000FFD8

	thumb_func_start ZeelaSetCrawlingOam
ZeelaSetCrawlingOam: @ 0x0803AB50
	push {lr}
	ldr r0, _0803AB64 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803AB6C
	ldr r0, _0803AB68 @ =0x083505DC
	b _0803AB6E
	.align 2, 0
_0803AB64: .4byte gCurrentSprite
_0803AB68: .4byte 0x083505DC
_0803AB6C:
	ldr r0, _0803AB7C @ =0x08350584
_0803AB6E:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803AB7C: .4byte 0x08350584

	thumb_func_start ZeelaSetFallingOam
ZeelaSetFallingOam: @ 0x0803AB80
	push {lr}
	ldr r0, _0803AB94 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803AB9C
	ldr r0, _0803AB98 @ =0x0835060C
	b _0803AB9E
	.align 2, 0
_0803AB94: .4byte gCurrentSprite
_0803AB98: .4byte 0x0835060C
_0803AB9C:
	ldr r0, _0803ABAC @ =0x083505B4
_0803AB9E:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803ABAC: .4byte 0x083505B4

	thumb_func_start ZeelaShootProjectiles
ZeelaShootProjectiles: @ 0x0803ABB0
	push {r4, r5, lr}
	sub sp, #0xc
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803ABDC
	ldr r0, _0803ABD8 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0803ABD2
	b _0803AD6C
_0803ABD2:
	movs r0, #0
	strb r0, [r1]
	b _0803AD6C
	.align 2, 0
_0803ABD8: .4byte gCurrentSprite
_0803ABDC:
	ldr r1, _0803AC44 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803ABEA
	b _0803AD6C
_0803ABEA:
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0803AC06
	ldrb r0, [r1, #0x1c]
	cmp r0, #1
	bne _0803AC06
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803AC06
	ldr r0, _0803AC48 @ =0x000001CB
	bl SoundPlayNotAlreadyPlaying
_0803AC06:
	ldr r1, _0803AC44 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	adds r4, r1, #0
	cmp r0, #1
	bne _0803ACAC
	ldrb r0, [r4, #0x1c]
	cmp r0, #8
	bne _0803ACAC
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803AC64
	ldrh r1, [r4]
	movs r5, #0x40
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803AC4C
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x34
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x3c
	str r0, [sp, #4]
	str r5, [sp, #8]
	b _0803ACEE
	.align 2, 0
_0803AC44: .4byte gCurrentSprite
_0803AC48: .4byte 0x000001CB
_0803AC4C:
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x34
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x3c
	str r0, [sp, #4]
	str r5, [sp, #8]
	b _0803AD10
_0803AC64:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803AC8A
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x3c
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x34
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
	b _0803AD44
_0803AC8A:
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0x3c
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x34
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
	movs r0, #0x38
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0803AD6C
_0803ACAC:
	mov ip, r4
	ldrh r0, [r4, #0x16]
	cmp r0, #2
	bne _0803AD6C
	ldrb r0, [r4, #0x1c]
	cmp r0, #8
	bne _0803AD6C
	mov r0, ip
	adds r0, #0x2d
	ldrb r5, [r0]
	cmp r5, #0
	beq _0803AD1A
	mov r0, ip
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803ACF8
	mov r1, ip
	ldrb r2, [r1, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	subs r0, #0x34
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x3c
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
_0803ACEE:
	movs r0, #0x38
	movs r1, #3
	bl SpriteSpawnSecondary
	b _0803AD6C
_0803ACF8:
	mov r4, ip
	ldrb r2, [r4, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0x34
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x3c
	str r0, [sp, #4]
	str r1, [sp, #8]
_0803AD10:
	movs r0, #0x38
	movs r1, #2
	bl SpriteSpawnSecondary
	b _0803AD6C
_0803AD1A:
	mov r0, ip
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803AD4E
	mov r1, ip
	ldrb r2, [r1, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0x3c
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x34
	str r0, [sp, #4]
	str r5, [sp, #8]
_0803AD44:
	movs r0, #0x38
	movs r1, #1
	bl SpriteSpawnSecondary
	b _0803AD6C
_0803AD4E:
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0x3c
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x34
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0x38
	movs r1, #0
	bl SpriteSpawnSecondary
_0803AD6C:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start ZeelaTurningIntoX
ZeelaTurningIntoX: @ 0x0803AD74
	push {lr}
	ldr r2, _0803AD94 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803ADA0
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803AD98
	ldrh r0, [r2, #4]
	subs r0, #0x20
	strh r0, [r2, #4]
	b _0803ADB8
	.align 2, 0
_0803AD94: .4byte gCurrentSprite
_0803AD98:
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	b _0803ADB8
_0803ADA0:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803ADB2
	ldrh r0, [r2, #2]
	adds r0, #0x20
	b _0803ADB6
_0803ADB2:
	ldrh r0, [r2, #2]
	subs r0, #0x20
_0803ADB6:
	strh r0, [r2, #2]
_0803ADB8:
	pop {r0}
	bx r0

	thumb_func_start ZeelaInit
ZeelaInit: @ 0x0803ADBC
	push {r4, r5, r6, r7, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0803ADE8 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803ADEC
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803ADEC
	strh r0, [r2]
	b _0803AEFC
	.align 2, 0
_0803ADE8: .4byte gCurrentSprite
_0803ADEC:
	ldr r0, _0803AE04 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	ldrb r1, [r2]
	adds r7, r0, #0
	cmp r1, #0x59
	bne _0803AE08
	movs r0, #0x5a
	strb r0, [r2]
	movs r0, #0x2c
	strh r0, [r7, #6]
	b _0803AEC2
	.align 2, 0
_0803AE04: .4byte gCurrentSprite
_0803AE08:
	movs r0, #2
	strb r0, [r2]
	ldrh r0, [r7, #2]
	ldrh r1, [r7, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AE2C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	movs r6, #0xf0
	adds r4, r6, #0
	ands r4, r0
	cmp r4, #0
	beq _0803AE30
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	b _0803AEC2
	.align 2, 0
_0803AE2C: .4byte gPreviousCollisionCheck
_0803AE30:
	ldrh r0, [r7, #2]
	subs r0, #0x44
	ldrh r1, [r7, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803AE5E
	adds r0, r7, #0
	adds r0, #0x2d
	strb r4, [r0]
	ldrh r0, [r7]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r1, r0
	strh r1, [r7]
	ldrh r0, [r7, #2]
	subs r0, #0x40
	strh r0, [r7, #2]
	b _0803AEC2
_0803AE5E:
	ldrh r0, [r7, #2]
	subs r0, #0x20
	ldrh r1, [r7, #4]
	subs r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803AE8A
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r7, #2]
	subs r0, #0x20
	strh r0, [r7, #2]
	ldrh r0, [r7, #4]
	subs r0, #0x20
	strh r0, [r7, #4]
	b _0803AEC2
_0803AE8A:
	ldrh r0, [r7, #2]
	subs r0, #0x20
	ldrh r1, [r7, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	adds r2, r6, #0
	ands r2, r0
	cmp r2, #0
	beq _0803AEBE
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r7]
	ldrh r0, [r7, #2]
	subs r0, #0x20
	strh r0, [r7, #2]
	ldrh r0, [r7, #4]
	adds r0, #0x20
	strh r0, [r7, #4]
	b _0803AEC2
_0803AEBE:
	strh r2, [r7]
	b _0803AEFC
_0803AEC2:
	adds r1, r7, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	bl ZeelaSetCrawlingOam
	bl ZeelaUpdateHitbox
	ldr r2, _0803AF04 @ =sPrimarySpriteStats
	ldrb r1, [r7, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r7, #0x14]
	adds r0, r7, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	subs r0, #8
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0803AEFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF04: .4byte sPrimarySpriteStats

	thumb_func_start ZeelaIdleInit
ZeelaIdleInit: @ 0x0803AF08
	push {lr}
	bl ZeelaSetCrawlingOam
	ldr r0, _0803AF1C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0803AF1C: .4byte gCurrentSprite

	thumb_func_start ZeelaIdle
ZeelaIdle: @ 0x0803AF20
	push {r4, r5, r6, lr}
	ldr r4, _0803AF4C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _0803AF32
	b _0803B14C
_0803AF32:
	bl ZeelaShootProjectiles
	bl ZeelaCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803AF50
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x15
	strb r0, [r1]
	b _0803B14C
	.align 2, 0
_0803AF4C: .4byte gCurrentSprite
_0803AF50:
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B040
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803AFBC
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803AF94
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AF90 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803AF86
	b _0803B138
_0803AF86:
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803AFE6
	.align 2, 0
_0803AF90: .4byte gPreviousCollisionCheck
_0803AF94:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803AFB8 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803AFAC
	b _0803B138
_0803AFAC:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803B024
	.align 2, 0
_0803AFB8: .4byte gPreviousCollisionCheck
_0803AFBC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B004
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B000 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803AFE0
	b _0803B138
_0803AFE0:
	ldrh r0, [r4, #2]
	adds r0, #0x38
	ldrh r1, [r4, #4]
_0803AFE6:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803AFF6
	b _0803B138
_0803AFF6:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	b _0803B132
	.align 2, 0
_0803B000: .4byte gPreviousCollisionCheck
_0803B004:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B03C @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803B01E
	b _0803B138
_0803B01E:
	ldrh r0, [r4, #2]
	subs r0, #0x38
	ldrh r1, [r4, #4]
_0803B024:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803B034
	b _0803B138
_0803B034:
	ldrh r0, [r4, #2]
	subs r0, #1
	strh r0, [r4, #2]
	b _0803B132
	.align 2, 0
_0803B03C: .4byte gPreviousCollisionCheck
_0803B040:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803B0C0
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B090
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B08C @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803B138
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0803B138
	ldrh r0, [r4, #4]
	adds r0, #1
	b _0803B130
	.align 2, 0
_0803B08C: .4byte gPreviousCollisionCheck
_0803B090:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B0BC @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803B138
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	b _0803B126
	.align 2, 0
_0803B0BC: .4byte gPreviousCollisionCheck
_0803B0C0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B100
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B0FC @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803B138
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803B138
	ldrh r0, [r4, #4]
	adds r0, #1
	b _0803B130
	.align 2, 0
_0803B0FC: .4byte gPreviousCollisionCheck
_0803B100:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B154 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803B138
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x38
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
_0803B126:
	ands r0, r1
	cmp r0, #0
	bne _0803B138
	ldrh r0, [r4, #4]
	subs r0, #1
_0803B130:
	strh r0, [r4, #4]
_0803B132:
	movs r0, #0
	cmp r0, #0
	beq _0803B14C
_0803B138:
	ldr r2, _0803B158 @ =gCurrentSprite
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
_0803B14C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B154: .4byte gPreviousCollisionCheck
_0803B158: .4byte gCurrentSprite

	thumb_func_start ZeelaTurningAroundInit
ZeelaTurningAroundInit: @ 0x0803B15C
	push {lr}
	ldr r0, _0803B170 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #8
	strb r1, [r0]
	bl ZeelaSetFallingOam
	pop {r0}
	bx r0
	.align 2, 0
_0803B170: .4byte gCurrentSprite

	thumb_func_start ZeelaTurningAround
ZeelaTurningAround: @ 0x0803B174
	push {lr}
	bl ZeelaCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B18C
	ldr r0, _0803B188 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	b _0803B19A
	.align 2, 0
_0803B188: .4byte gCurrentSprite
_0803B18C:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803B19C
	ldr r0, _0803B1A0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
_0803B19A:
	strb r1, [r0]
_0803B19C:
	pop {r0}
	bx r0
	.align 2, 0
_0803B1A0: .4byte gCurrentSprite

	thumb_func_start ZeelaFallingInit
ZeelaFallingInit: @ 0x0803B1A4
	push {lr}
	ldr r1, _0803B1C0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r1, #0x31
	strb r3, [r1]
	bl ZeelaSetFallingOam
	pop {r0}
	bx r0
	.align 2, 0
_0803B1C0: .4byte gCurrentSprite

	thumb_func_start ZeelaFalling
ZeelaFalling: @ 0x0803B1C4
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r2, _0803B1EC @ =gCurrentSprite
	ldrh r3, [r2, #2]
	ldrh r4, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B1F0
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803B1FC
	subs r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0803B1FC
	.align 2, 0
_0803B1EC: .4byte gCurrentSprite
_0803B1F0:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803B204
_0803B1FC:
	ldrh r0, [r2, #0xc]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0803B204:
	adds r0, r3, #0
	adds r1, r4, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _0803B250 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B278
	ldr r4, _0803B254 @ =gCurrentSprite
	strh r1, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x2d
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803B22A
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0803B22A:
	ldrh r0, [r4]
	ldr r1, _0803B258 @ =0x0000FEFF
	ands r1, r0
	strh r1, [r4]
	movs r0, #0
	strb r0, [r2]
	bl ZeelaUpdateHitbox
	cmp r5, #0
	beq _0803B264
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803B25C
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0x10]
	b _0803B260
	.align 2, 0
_0803B250: .4byte gPreviousVerticalCollisionCheck
_0803B254: .4byte gCurrentSprite
_0803B258: .4byte 0x0000FEFF
_0803B25C:
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0xe]
_0803B260:
	subs r0, r0, r1
	strh r0, [r4, #4]
_0803B264:
	ldr r0, _0803B274 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #8
	strb r1, [r0]
	bl ZeelaSetFallingOam
	b _0803B2BC
	.align 2, 0
_0803B274: .4byte gCurrentSprite
_0803B278:
	ldr r3, _0803B2A4 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _0803B2A8 @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0803B2AC @ =0x00007FFF
	cmp r1, r0
	bne _0803B2B0
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0803B2BA
	.align 2, 0
_0803B2A4: .4byte gCurrentSprite
_0803B2A8: .4byte sSpritesFallingSpeed
_0803B2AC: .4byte 0x00007FFF
_0803B2B0:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_0803B2BA:
	strh r0, [r3, #2]
_0803B2BC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZeelaProjectileInit
ZeelaProjectileInit: @ 0x0803B2C4
	push {r4, lr}
	ldr r0, _0803B328 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0803B32C @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _0803B330 @ =0x0000FFF8
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _0803B334 @ =0x08350634
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r0, ip
	adds r0, #0x31
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r1, #3
	movs r0, #3
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B328: .4byte gCurrentSprite
_0803B32C: .4byte 0x0000FFFB
_0803B330: .4byte 0x0000FFF8
_0803B334: .4byte 0x08350634

	thumb_func_start ZeelaProjectileMoving
ZeelaProjectileMoving: @ 0x0803B338
	push {r4, r5, r6, lr}
	ldr r1, _0803B360 @ =gCurrentClipdataAffectingAction
	movs r0, #5
	strb r0, [r1]
	ldr r4, _0803B364 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803B368 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803B36C
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _0803B3FA
	.align 2, 0
_0803B360: .4byte gCurrentClipdataAffectingAction
_0803B364: .4byte gCurrentSprite
_0803B368: .4byte gPreviousCollisionCheck
_0803B36C:
	adds r5, r4, #0
	adds r5, #0x31
	ldrb r2, [r5]
	ldr r3, _0803B390 @ =0x0834F10C
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0803B394 @ =0x00007FFF
	cmp r1, r0
	bne _0803B398
	subs r0, r2, #1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r4, [r0]
	b _0803B39C
	.align 2, 0
_0803B390: .4byte 0x0834F10C
_0803B394: .4byte 0x00007FFF
_0803B398:
	adds r0, r2, #1
	strb r0, [r5]
_0803B39C:
	ldr r0, _0803B3B0 @ =gCurrentSprite
	ldrb r2, [r0, #0x1e]
	adds r3, r0, #0
	cmp r2, #1
	bls _0803B3D4
	cmp r2, #3
	bne _0803B3B4
	ldrh r0, [r3, #4]
	adds r0, r0, r4
	b _0803B3B8
	.align 2, 0
_0803B3B0: .4byte gCurrentSprite
_0803B3B4:
	ldrh r0, [r3, #4]
	subs r0, r0, r4
_0803B3B8:
	strh r0, [r3, #4]
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803B3CC
	ldrh r0, [r3, #2]
	adds r0, #6
	strh r0, [r3, #2]
	b _0803B3FA
_0803B3CC:
	ldrh r0, [r3, #2]
	subs r0, #6
	strh r0, [r3, #2]
	b _0803B3FA
_0803B3D4:
	cmp r2, #0
	beq _0803B3DE
	ldrh r0, [r3, #2]
	subs r0, r0, r4
	b _0803B3E2
_0803B3DE:
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_0803B3E2:
	strh r0, [r3, #2]
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803B3F4
	ldrh r0, [r3, #4]
	adds r0, #6
	b _0803B3F8
_0803B3F4:
	ldrh r0, [r3, #4]
	subs r0, #6
_0803B3F8:
	strh r0, [r3, #4]
_0803B3FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ZeelaProjectileExplodingInit
ZeelaProjectileExplodingInit: @ 0x0803B400
	push {lr}
	ldr r3, _0803B430 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x21
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803B434 @ =gFrameCounter8Bit
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0803B43C
	ldr r0, _0803B438 @ =0x0835066C
	b _0803B43E
	.align 2, 0
_0803B430: .4byte gCurrentSprite
_0803B434: .4byte gSpriteRandomNumber
_0803B438: .4byte 0x0835066C
_0803B43C:
	ldr r0, _0803B444 @ =0x08350694
_0803B43E:
	str r0, [r3, #0x18]
	pop {r0}
	bx r0
	.align 2, 0
_0803B444: .4byte 0x08350694

	thumb_func_start ZeelaProjectileExploding
ZeelaProjectileExploding: @ 0x0803B448
	push {r4, lr}
	ldr r4, _0803B468 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803B460
	movs r0, #0
	strh r0, [r4]
_0803B460:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803B468: .4byte gCurrentSprite

	thumb_func_start Zeela
Zeela: @ 0x0803B46C
	push {r4, lr}
	ldr r4, _0803B498 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803B486
	movs r0, #0xe6
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803B486:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B49C
	bl SpriteUtilUpdateFreezeTimer
	b _0803B668
	.align 2, 0
_0803B498: .4byte gCurrentSprite
_0803B49C:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803B4A8
	b _0803B668
_0803B4A8:
	lsls r0, r0, #2
	ldr r1, _0803B4B4 @ =_0803B4B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803B4B4: .4byte _0803B4B8
_0803B4B8: @ jump table
	.4byte _0803B628 @ case 0
	.4byte _0803B62E @ case 1
	.4byte _0803B632 @ case 2
	.4byte _0803B668 @ case 3
	.4byte _0803B668 @ case 4
	.4byte _0803B668 @ case 5
	.4byte _0803B668 @ case 6
	.4byte _0803B638 @ case 7
	.4byte _0803B63C @ case 8
	.4byte _0803B668 @ case 9
	.4byte _0803B668 @ case 10
	.4byte _0803B668 @ case 11
	.4byte _0803B668 @ case 12
	.4byte _0803B668 @ case 13
	.4byte _0803B668 @ case 14
	.4byte _0803B668 @ case 15
	.4byte _0803B668 @ case 16
	.4byte _0803B668 @ case 17
	.4byte _0803B668 @ case 18
	.4byte _0803B668 @ case 19
	.4byte _0803B668 @ case 20
	.4byte _0803B642 @ case 21
	.4byte _0803B646 @ case 22
	.4byte _0803B668 @ case 23
	.4byte _0803B668 @ case 24
	.4byte _0803B668 @ case 25
	.4byte _0803B668 @ case 26
	.4byte _0803B668 @ case 27
	.4byte _0803B668 @ case 28
	.4byte _0803B668 @ case 29
	.4byte _0803B668 @ case 30
	.4byte _0803B668 @ case 31
	.4byte _0803B668 @ case 32
	.4byte _0803B668 @ case 33
	.4byte _0803B668 @ case 34
	.4byte _0803B668 @ case 35
	.4byte _0803B668 @ case 36
	.4byte _0803B668 @ case 37
	.4byte _0803B668 @ case 38
	.4byte _0803B668 @ case 39
	.4byte _0803B668 @ case 40
	.4byte _0803B668 @ case 41
	.4byte _0803B668 @ case 42
	.4byte _0803B668 @ case 43
	.4byte _0803B668 @ case 44
	.4byte _0803B668 @ case 45
	.4byte _0803B668 @ case 46
	.4byte _0803B668 @ case 47
	.4byte _0803B668 @ case 48
	.4byte _0803B668 @ case 49
	.4byte _0803B668 @ case 50
	.4byte _0803B668 @ case 51
	.4byte _0803B668 @ case 52
	.4byte _0803B668 @ case 53
	.4byte _0803B668 @ case 54
	.4byte _0803B668 @ case 55
	.4byte _0803B668 @ case 56
	.4byte _0803B668 @ case 57
	.4byte _0803B668 @ case 58
	.4byte _0803B668 @ case 59
	.4byte _0803B668 @ case 60
	.4byte _0803B668 @ case 61
	.4byte _0803B668 @ case 62
	.4byte _0803B668 @ case 63
	.4byte _0803B668 @ case 64
	.4byte _0803B668 @ case 65
	.4byte _0803B668 @ case 66
	.4byte _0803B668 @ case 67
	.4byte _0803B668 @ case 68
	.4byte _0803B668 @ case 69
	.4byte _0803B668 @ case 70
	.4byte _0803B668 @ case 71
	.4byte _0803B668 @ case 72
	.4byte _0803B668 @ case 73
	.4byte _0803B668 @ case 74
	.4byte _0803B668 @ case 75
	.4byte _0803B668 @ case 76
	.4byte _0803B668 @ case 77
	.4byte _0803B668 @ case 78
	.4byte _0803B668 @ case 79
	.4byte _0803B668 @ case 80
	.4byte _0803B668 @ case 81
	.4byte _0803B668 @ case 82
	.4byte _0803B668 @ case 83
	.4byte _0803B668 @ case 84
	.4byte _0803B668 @ case 85
	.4byte _0803B668 @ case 86
	.4byte _0803B64C @ case 87
	.4byte _0803B650 @ case 88
	.4byte _0803B656 @ case 89
	.4byte _0803B65A @ case 90
	.4byte _0803B660 @ case 91
_0803B628:
	bl ZeelaInit
	b _0803B668
_0803B62E:
	bl ZeelaIdleInit
_0803B632:
	bl ZeelaIdle
	b _0803B668
_0803B638:
	bl ZeelaTurningAroundInit
_0803B63C:
	bl ZeelaTurningAround
	b _0803B668
_0803B642:
	bl ZeelaFallingInit
_0803B646:
	bl ZeelaFalling
	b _0803B668
_0803B64C:
	bl SpriteDyingInit
_0803B650:
	bl SpriteDying
	b _0803B668
_0803B656:
	bl ZeelaInit
_0803B65A:
	bl SpriteSpawningFromX
	b _0803B668
_0803B660:
	bl ZeelaTurningIntoX
	bl XParasiteInit
_0803B668:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZeelaProjectile
ZeelaProjectile: @ 0x0803B670
	push {lr}
	ldr r0, _0803B688 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803B696
	cmp r0, #2
	bgt _0803B68C
	cmp r0, #0
	beq _0803B692
	b _0803B6A2
	.align 2, 0
_0803B688: .4byte gCurrentSprite
_0803B68C:
	cmp r0, #0x38
	beq _0803B69C
	b _0803B6A2
_0803B692:
	bl ZeelaProjectileInit
_0803B696:
	bl ZeelaProjectileMoving
	b _0803B6A6
_0803B69C:
	bl ZeelaProjectileExploding
	b _0803B6A6
_0803B6A2:
	bl ZeelaProjectileExplodingInit
_0803B6A6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SovaCheckCollidingWithAir
SovaCheckCollidingWithAir: @ 0x0803B6AC
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _0803B6E0 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B70C
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803B6E8
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B6E4 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803B758
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	b _0803B74C
	.align 2, 0
_0803B6E0: .4byte gCurrentSprite
_0803B6E4: .4byte gPreviousCollisionCheck
_0803B6E8:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B708 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803B758
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803B74C
	.align 2, 0
_0803B708: .4byte gPreviousCollisionCheck
_0803B70C:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B734
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B730 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803B758
	ldrh r0, [r4, #2]
	subs r0, #4
	b _0803B748
	.align 2, 0
_0803B730: .4byte gPreviousCollisionCheck
_0803B734:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803B760 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803B758
	ldrh r0, [r4, #2]
_0803B748:
	ldrh r1, [r4, #4]
	adds r1, #0x20
_0803B74C:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803B758
	movs r6, #1
_0803B758:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0803B760: .4byte gPreviousCollisionCheck

	thumb_func_start SovaUpdateHitbox
SovaUpdateHitbox: @ 0x0803B764
	push {lr}
	ldr r2, _0803B790 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B7B4
	ldrh r1, [r2]
	movs r3, #0x40
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0803B79C
	ldr r0, _0803B794 @ =0x0000FFE4
	strh r0, [r2, #0xa]
	movs r0, #0x1c
	strh r0, [r2, #0xc]
	ldr r0, _0803B798 @ =0x0000FFC0
	strh r0, [r2, #0xe]
	movs r0, #0x10
	b _0803B7D4
	.align 2, 0
_0803B790: .4byte gCurrentSprite
_0803B794: .4byte 0x0000FFE4
_0803B798: .4byte 0x0000FFC0
_0803B79C:
	ldr r0, _0803B7AC @ =0x0000FFE4
	strh r0, [r2, #0xa]
	movs r0, #0x1c
	strh r0, [r2, #0xc]
	ldr r0, _0803B7B0 @ =0x0000FFF0
	strh r0, [r2, #0xe]
	strh r3, [r2, #0x10]
	b _0803B7D6
	.align 2, 0
_0803B7AC: .4byte 0x0000FFE4
_0803B7B0: .4byte 0x0000FFF0
_0803B7B4:
	adds r0, r2, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B7C6
	movs r0, #0x10
	strh r0, [r2, #0xa]
	movs r0, #0x40
	b _0803B7CC
_0803B7C6:
	ldr r0, _0803B7DC @ =0x0000FFC0
	strh r0, [r2, #0xa]
	movs r0, #0x10
_0803B7CC:
	strh r0, [r2, #0xc]
	ldr r0, _0803B7E0 @ =0x0000FFE4
	strh r0, [r2, #0xe]
	movs r0, #0x1c
_0803B7D4:
	strh r0, [r2, #0x10]
_0803B7D6:
	pop {r0}
	bx r0
	.align 2, 0
_0803B7DC: .4byte 0x0000FFC0
_0803B7E0: .4byte 0x0000FFE4

	thumb_func_start SovaSetCrawlingOam
SovaSetCrawlingOam: @ 0x0803B7E4
	push {lr}
	ldr r0, _0803B7F8 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803B800
	ldr r0, _0803B7FC @ =0x0835335C
	b _0803B816
	.align 2, 0
_0803B7F8: .4byte gCurrentSprite
_0803B7FC: .4byte 0x0835335C
_0803B800:
	adds r0, r2, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B814
	ldr r0, _0803B810 @ =0x08353384
	b _0803B816
	.align 2, 0
_0803B810: .4byte 0x08353384
_0803B814:
	ldr r0, _0803B824 @ =0x08353334
_0803B816:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803B824: .4byte 0x08353334

	thumb_func_start SovaTurningIntoX
SovaTurningIntoX: @ 0x0803B828
	push {lr}
	ldr r2, _0803B848 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B854
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803B84C
	ldrh r0, [r2, #4]
	subs r0, #0x20
	strh r0, [r2, #4]
	b _0803B86A
	.align 2, 0
_0803B848: .4byte gCurrentSprite
_0803B84C:
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	b _0803B86A
_0803B854:
	adds r0, r2, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B864
	ldrh r0, [r2, #2]
	adds r0, #0x20
	b _0803B868
_0803B864:
	ldrh r0, [r2, #2]
	subs r0, #0x20
_0803B868:
	strh r0, [r2, #2]
_0803B86A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SovaInit
SovaInit: @ 0x0803B870
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0803B8A0 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B8A4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803B8A4
	strh r0, [r2]
	b _0803B9E4
	.align 2, 0
_0803B8A0: .4byte gCurrentSprite
_0803B8A4:
	ldr r1, _0803B8BC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	ldrb r0, [r2]
	adds r4, r1, #0
	cmp r0, #0x59
	bne _0803B8C0
	movs r0, #0x5a
	strb r0, [r2]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _0803B9B4
	.align 2, 0
_0803B8BC: .4byte gCurrentSprite
_0803B8C0:
	movs r0, #0
	mov r8, r0
	movs r0, #2
	strb r0, [r2]
	movs r1, #0x2f
	adds r1, r1, r4
	mov sb, r1
	mov r0, r8
	strb r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803B8FC @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	movs r7, #0xf0
	adds r5, r7, #0
	ands r5, r0
	cmp r5, #0
	beq _0803B904
	adds r0, r4, #0
	adds r0, #0x2d
	mov r1, r8
	strb r1, [r0]
	ldr r0, _0803B900 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x46
	b _0803B9A2
	.align 2, 0
_0803B8FC: .4byte gPreviousCollisionCheck
_0803B900: .4byte gSpriteRandomNumber
_0803B904:
	ldrh r0, [r4, #2]
	subs r0, #0x44
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803B92C
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
	b _0803B99A
_0803B92C:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803B968
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	strh r0, [r4, #4]
	ldr r0, _0803B964 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x1e
	adds r1, #3
	strb r0, [r1]
	b _0803B9B4
	.align 2, 0
_0803B964: .4byte gSpriteRandomNumber
_0803B968:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r6]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0
	beq _0803B9B0
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	adds r0, #0x20
	strh r0, [r4, #4]
_0803B99A:
	ldr r0, _0803B9AC @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x1e
_0803B9A2:
	adds r1, r4, #0
	adds r1, #0x30
	strb r0, [r1]
	b _0803B9B4
	.align 2, 0
_0803B9AC: .4byte gSpriteRandomNumber
_0803B9B0:
	strh r2, [r4]
	b _0803B9E4
_0803B9B4:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	bl SovaSetCrawlingOam
	bl SovaUpdateHitbox
	ldr r2, _0803B9F0 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0803B9E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B9F0: .4byte sPrimarySpriteStats

	thumb_func_start SovaIdleInit
SovaIdleInit: @ 0x0803B9F4
	push {lr}
	bl SovaSetCrawlingOam
	ldr r0, _0803BA08 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0803BA08: .4byte gCurrentSprite

	thumb_func_start SovaIdle
SovaIdle: @ 0x0803BA0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r4, _0803BAC0 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _0803BA24
	b _0803BE98
_0803BA24:
	movs r0, #1
	mov r8, r0
	movs r5, #0
	adds r6, r4, #0
	adds r6, #0x30
	ldrb r0, [r6]
	subs r1, r0, #1
	strb r1, [r6]
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803BA40
	b _0803BBCC
_0803BA40:
	bl SovaCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BA4C
	b _0803BD70
_0803BA4C:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803BB08
	ldrb r0, [r6]
	cmp r0, #0
	bne _0803BA90
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x14
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x14
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x39
	movs r1, #1
	bl SpriteSpawnSecondary
	movs r0, #0xa0
	strb r0, [r6]
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BA90
	movs r0, #0xc7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803BA90:
	ldr r4, _0803BAC0 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BAC8
	ldrh r0, [r4, #2]
	adds r0, #0x28
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BAC4 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803BAB6
	b _0803BC9E
_0803BAB6:
	ldrh r0, [r4, #2]
	adds r0, #0x28
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803BB70
	.align 2, 0
_0803BAC0: .4byte gCurrentSprite
_0803BAC4: .4byte gPreviousCollisionCheck
_0803BAC8:
	ldrh r0, [r4, #2]
	subs r0, #0x28
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BB04 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803BAE0
	b _0803BC9E
_0803BAE0:
	ldrh r0, [r4, #2]
	subs r0, #0x28
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803BAF8
	b _0803BC9E
_0803BAF8:
	ldrh r0, [r4, #2]
	mov r1, r8
	subs r0, r0, r1
	strh r0, [r4, #2]
	b _0803BE80
	.align 2, 0
_0803BB04: .4byte gPreviousCollisionCheck
_0803BB08:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0803BB42
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x14
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x14
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x39
	movs r1, #1
	bl SpriteSpawnSecondary
	movs r0, #0xa0
	strb r0, [r6]
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BB42
	movs r0, #0xc7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803BB42:
	ldr r4, _0803BB88 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BB90
	ldrh r0, [r4, #2]
	adds r0, #0x28
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BB8C @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803BB6A
	b _0803BC9E
_0803BB6A:
	ldrh r0, [r4, #2]
	adds r0, #0x28
	ldrh r1, [r4, #4]
_0803BB70:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803BB80
	b _0803BC9E
_0803BB80:
	ldrh r0, [r4, #2]
	add r0, r8
	strh r0, [r4, #2]
	b _0803BE80
	.align 2, 0
_0803BB88: .4byte gCurrentSprite
_0803BB8C: .4byte gPreviousCollisionCheck
_0803BB90:
	ldrh r0, [r4, #2]
	subs r0, #0x28
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BBC8 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803BC9E
	ldrh r0, [r4, #2]
	subs r0, #0x28
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803BC9E
	ldrh r0, [r4, #2]
	mov r3, r8
	subs r0, r0, r3
	strh r0, [r4, #2]
	b _0803BE80
	.align 2, 0
_0803BBC8: .4byte gPreviousCollisionCheck
_0803BBCC:
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803BCB6
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _0803BC0E
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x14
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x39
	movs r1, #1
	bl SpriteSpawnSecondary
	movs r0, #0xa0
	strb r0, [r6]
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BC0E
	movs r0, #0xc7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803BC0E:
	bl SovaCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BC28
	ldr r0, _0803BC24 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	strb r1, [r0]
	b _0803BE98
	.align 2, 0
_0803BC24: .4byte gCurrentSprite
_0803BC28:
	ldr r4, _0803BC68 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BC70
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x28
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BC6C @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803BC9E
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x28
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0803BC9E
	b _0803BD4E
	.align 2, 0
_0803BC68: .4byte gCurrentSprite
_0803BC6C: .4byte gPreviousCollisionCheck
_0803BC70:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x28
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BCA8 @ =gPreviousCollisionCheck
	ldrb r1, [r6]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803BC9E
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x28
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803BCAC
_0803BC9E:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0803BE80
	.align 2, 0
_0803BCA8: .4byte gPreviousCollisionCheck
_0803BCAC:
	ldrh r0, [r4, #4]
	mov r1, r8
	subs r0, r0, r1
	strh r0, [r4, #4]
	b _0803BE80
_0803BCB6:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _0803BCC2
	cmp r0, #0x20
	bne _0803BCF0
_0803BCC2:
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x39
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BD24
	movs r0, #0xc7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0803BD24
_0803BCF0:
	cmp r0, #0
	bne _0803BD24
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x39
	movs r1, #0
	bl SpriteSpawnSecondary
	movs r0, #0xd2
	strb r0, [r6]
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BD24
	movs r0, #0xc7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803BD24:
	bl SpriteUtilAlignYPositionOnSlopeAtOrigin
	ldr r6, _0803BD58 @ =gPreviousVerticalCollisionCheck
	ldrb r2, [r6]
	adds r1, r2, #0
	cmp r1, #0
	bne _0803BD84
	ldr r4, _0803BD5C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803BD60
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckVerticalCollisionAtPosition
	ldrb r0, [r6]
	cmp r0, #0
	beq _0803BD70
_0803BD4E:
	ldrh r0, [r4, #4]
	add r0, r8
	strh r0, [r4, #4]
	b _0803BE80
	.align 2, 0
_0803BD58: .4byte gPreviousVerticalCollisionCheck
_0803BD5C: .4byte gCurrentSprite
_0803BD60:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckVerticalCollisionAtPosition
	ldrb r0, [r6]
	cmp r0, #0
	bne _0803BD7A
_0803BD70:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x15
	strb r0, [r1]
	b _0803BE98
_0803BD7A:
	ldrh r0, [r4, #4]
	mov r3, r8
	subs r0, r0, r3
	strh r0, [r4, #4]
	b _0803BE80
_0803BD84:
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _0803BE18
	ldr r2, _0803BDD4 @ =gCurrentSprite
	ldr r1, [r2, #0x18]
	ldr r0, _0803BDD8 @ =0x083533AC
	cmp r1, r0
	bne _0803BDAA
	ldr r0, _0803BDDC @ =0x08353334
	str r0, [r2, #0x18]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803BDAA
	ldr r0, _0803BDE0 @ =0x0000FFBF
	ands r0, r1
	strh r0, [r2]
_0803BDAA:
	ldr r4, _0803BDD4 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BDE8
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x28
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BDE4 @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	cmp r0, #0
	beq _0803BE0C
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x28
	b _0803BE02
	.align 2, 0
_0803BDD4: .4byte gCurrentSprite
_0803BDD8: .4byte 0x083533AC
_0803BDDC: .4byte 0x08353334
_0803BDE0: .4byte 0x0000FFBF
_0803BDE4: .4byte gPreviousCollisionCheck
_0803BDE8:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x28
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803BE14 @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	cmp r0, #0
	beq _0803BE0C
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x28
_0803BE02:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r6]
	cmp r0, #0x11
	bne _0803BE50
_0803BE0C:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0803BE50
	.align 2, 0
_0803BE14: .4byte gPreviousCollisionCheck
_0803BE18:
	cmp r1, #2
	beq _0803BE20
	cmp r1, #4
	bne _0803BE2E
_0803BE20:
	ldr r2, _0803BE68 @ =gCurrentSprite
	ldr r1, [r2, #0x18]
	ldr r0, _0803BE6C @ =0x08353334
	cmp r1, r0
	bne _0803BE2E
	ldr r0, _0803BE70 @ =0x083533AC
	str r0, [r2, #0x18]
_0803BE2E:
	ldr r0, _0803BE74 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #3
	beq _0803BE3A
	cmp r0, #5
	bne _0803BE50
_0803BE3A:
	ldr r2, _0803BE68 @ =gCurrentSprite
	ldr r1, [r2, #0x18]
	ldr r0, _0803BE6C @ =0x08353334
	cmp r1, r0
	bne _0803BE50
	ldr r0, _0803BE70 @ =0x083533AC
	str r0, [r2, #0x18]
	ldrh r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strh r0, [r2]
_0803BE50:
	cmp r5, #0
	bne _0803BE84
	ldr r2, _0803BE68 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803BE78
	ldrh r0, [r2, #4]
	add r0, r8
	b _0803BE7E
	.align 2, 0
_0803BE68: .4byte gCurrentSprite
_0803BE6C: .4byte 0x08353334
_0803BE70: .4byte 0x083533AC
_0803BE74: .4byte gPreviousVerticalCollisionCheck
_0803BE78:
	ldrh r0, [r2, #4]
	mov r1, r8
	subs r0, r0, r1
_0803BE7E:
	strh r0, [r2, #4]
_0803BE80:
	cmp r5, #0
	beq _0803BE98
_0803BE84:
	ldr r2, _0803BEA4 @ =gCurrentSprite
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
_0803BE98:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803BEA4: .4byte gCurrentSprite

	thumb_func_start SovaTurningAroundInit
SovaTurningAroundInit: @ 0x0803BEA8
	ldr r1, _0803BEBC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #8
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x1e
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803BEBC: .4byte gCurrentSprite

	thumb_func_start SovaTurningAround
SovaTurningAround: @ 0x0803BEC0
	push {lr}
	bl SovaCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BEDC
	ldr r0, _0803BED8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	strb r1, [r0]
	b _0803BEF4
	.align 2, 0
_0803BED8: .4byte gCurrentSprite
_0803BEDC:
	ldr r1, _0803BEF8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803BEF4
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_0803BEF4:
	pop {r0}
	bx r0
	.align 2, 0
_0803BEF8: .4byte gCurrentSprite

	thumb_func_start SovaFallingInit
SovaFallingInit: @ 0x0803BEFC
	ldr r1, _0803BF10 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r1, #0x31
	strb r3, [r1]
	bx lr
	.align 2, 0
_0803BF10: .4byte gCurrentSprite

	thumb_func_start SovaFalling
SovaFalling: @ 0x0803BF14
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r2, _0803BF3C @ =gCurrentSprite
	ldrh r3, [r2, #2]
	ldrh r4, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803BF40
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803BF4C
	subs r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0803BF4C
	.align 2, 0
_0803BF3C: .4byte gCurrentSprite
_0803BF40:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803BF54
_0803BF4C:
	ldrh r0, [r2, #0xc]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0803BF54:
	adds r0, r3, #0
	adds r1, r4, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _0803BFB0 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803BFC6
	ldr r4, _0803BFB4 @ =gCurrentSprite
	movs r3, #0
	strh r1, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x2d
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803BF7C
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0803BF7C:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #7
	strb r0, [r1]
	strb r3, [r2]
	ldrh r1, [r4]
	ldr r0, _0803BFB8 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r4]
	adds r0, r4, #0
	adds r0, #0x2f
	strb r3, [r0]
	bl SovaSetCrawlingOam
	bl SovaUpdateHitbox
	cmp r5, #0
	beq _0803C008
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803BFBC
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0x10]
	b _0803BFC0
	.align 2, 0
_0803BFB0: .4byte gPreviousVerticalCollisionCheck
_0803BFB4: .4byte gCurrentSprite
_0803BFB8: .4byte 0x0000FEFF
_0803BFBC:
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0xe]
_0803BFC0:
	subs r0, r0, r1
	strh r0, [r4, #4]
	b _0803C008
_0803BFC6:
	ldr r3, _0803BFF0 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _0803BFF4 @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0803BFF8 @ =0x00007FFF
	cmp r1, r0
	bne _0803BFFC
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0803C006
	.align 2, 0
_0803BFF0: .4byte gCurrentSprite
_0803BFF4: .4byte sSpritesFallingSpeed
_0803BFF8: .4byte 0x00007FFF
_0803BFFC:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_0803C006:
	strh r0, [r3, #2]
_0803C008:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SovaFireInit
SovaFireInit: @ 0x0803C010
	push {r4, lr}
	ldr r0, _0803C084 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0803C088 @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r3, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x20
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	movs r1, #8
	strb r1, [r0]
	subs r2, #0xb
	movs r0, #0x10
	strb r0, [r2]
	ldr r0, _0803C08C @ =0x0000FFD8
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r3, [r2, #0xc]
	adds r0, #0x20
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	strb r4, [r2, #0x1c]
	strh r3, [r2, #0x16]
	mov r0, ip
	adds r0, #0x25
	movs r2, #2
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	mov r1, ip
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	beq _0803C094
	ldr r0, _0803C090 @ =0x0835346C
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x16
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x31
	strb r4, [r0]
	b _0803C0A6
	.align 2, 0
_0803C084: .4byte gCurrentSprite
_0803C088: .4byte 0x0000FFFB
_0803C08C: .4byte 0x0000FFD8
_0803C090: .4byte 0x0835346C
_0803C094:
	ldr r0, _0803C0AC @ =0x083533D4
	mov r1, ip
	str r0, [r1, #0x18]
	mov r0, ip
	adds r0, #0x24
	strb r2, [r0]
	adds r1, #0x2e
	movs r0, #0x32
	strb r0, [r1]
_0803C0A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C0AC: .4byte 0x083533D4

	thumb_func_start SovaFireBig
SovaFireBig: @ 0x0803C0B0
	push {lr}
	ldr r2, _0803C0EC @ =gCurrentSprite
	movs r0, #0x2e
	adds r0, r0, r2
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803C0E6
	movs r1, #0
	ldr r0, _0803C0F0 @ =0x0000FFE4
	strh r0, [r2, #0xa]
	ldr r0, _0803C0F4 @ =0x083533FC
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r3, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0x32
	mov r1, ip
	strb r0, [r1]
_0803C0E6:
	pop {r0}
	bx r0
	.align 2, 0
_0803C0EC: .4byte gCurrentSprite
_0803C0F0: .4byte 0x0000FFE4
_0803C0F4: .4byte 0x083533FC

	thumb_func_start SovaFireSmall
SovaFireSmall: @ 0x0803C0F8
	push {lr}
	ldr r2, _0803C134 @ =gCurrentSprite
	movs r0, #0x2e
	adds r0, r0, r2
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803C12E
	movs r1, #0
	ldr r0, _0803C138 @ =0x0000FFF0
	strh r0, [r2, #0xa]
	ldr r0, _0803C13C @ =0x08353424
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r3, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	movs r0, #0x1e
	mov r1, ip
	strb r0, [r1]
_0803C12E:
	pop {r0}
	bx r0
	.align 2, 0
_0803C134: .4byte gCurrentSprite
_0803C138: .4byte 0x0000FFF0
_0803C13C: .4byte 0x08353424

	thumb_func_start SovaFireDisappearing
SovaFireDisappearing: @ 0x0803C140
	push {lr}
	ldr r2, _0803C174 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r1, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0803C160
	ldrh r0, [r2]
	movs r1, #4
	eors r0, r1
	strh r0, [r2]
_0803C160:
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0803C170
	strh r0, [r2]
_0803C170:
	pop {r0}
	bx r0
	.align 2, 0
_0803C174: .4byte gCurrentSprite

	thumb_func_start SovaFireExplodingInit
SovaFireExplodingInit: @ 0x0803C178
	push {lr}
	ldr r1, _0803C1A4 @ =gCurrentSprite
	ldr r0, _0803C1A8 @ =0x08353494
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #8
	strb r0, [r2]
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803C19E
	ldr r0, _0803C1AC @ =0x0000018F
	bl SoundPlayNotAlreadyPlaying
_0803C19E:
	pop {r0}
	bx r0
	.align 2, 0
_0803C1A4: .4byte gCurrentSprite
_0803C1A8: .4byte 0x08353494
_0803C1AC: .4byte 0x0000018F

	thumb_func_start SovaFireExploding
SovaFireExploding: @ 0x0803C1B0
	push {r4, lr}
	ldr r4, _0803C1D0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803C1C8
	movs r0, #0
	strh r0, [r4]
_0803C1C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C1D0: .4byte gCurrentSprite

	thumb_func_start Sova
Sova: @ 0x0803C1D4
	push {r4, lr}
	ldr r4, _0803C200 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803C1EE
	movs r0, #0xc8
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803C1EE:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C204
	bl SpriteUtilUpdateFreezeTimer
	b _0803C3D0
	.align 2, 0
_0803C200: .4byte gCurrentSprite
_0803C204:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803C210
	b _0803C3D0
_0803C210:
	lsls r0, r0, #2
	ldr r1, _0803C21C @ =_0803C220
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803C21C: .4byte _0803C220
_0803C220: @ jump table
	.4byte _0803C390 @ case 0
	.4byte _0803C396 @ case 1
	.4byte _0803C39A @ case 2
	.4byte _0803C3D0 @ case 3
	.4byte _0803C3D0 @ case 4
	.4byte _0803C3D0 @ case 5
	.4byte _0803C3D0 @ case 6
	.4byte _0803C3A0 @ case 7
	.4byte _0803C3A4 @ case 8
	.4byte _0803C3D0 @ case 9
	.4byte _0803C3D0 @ case 10
	.4byte _0803C3D0 @ case 11
	.4byte _0803C3D0 @ case 12
	.4byte _0803C3D0 @ case 13
	.4byte _0803C3D0 @ case 14
	.4byte _0803C3D0 @ case 15
	.4byte _0803C3D0 @ case 16
	.4byte _0803C3D0 @ case 17
	.4byte _0803C3D0 @ case 18
	.4byte _0803C3D0 @ case 19
	.4byte _0803C3D0 @ case 20
	.4byte _0803C3AA @ case 21
	.4byte _0803C3AE @ case 22
	.4byte _0803C3D0 @ case 23
	.4byte _0803C3D0 @ case 24
	.4byte _0803C3D0 @ case 25
	.4byte _0803C3D0 @ case 26
	.4byte _0803C3D0 @ case 27
	.4byte _0803C3D0 @ case 28
	.4byte _0803C3D0 @ case 29
	.4byte _0803C3D0 @ case 30
	.4byte _0803C3D0 @ case 31
	.4byte _0803C3D0 @ case 32
	.4byte _0803C3D0 @ case 33
	.4byte _0803C3D0 @ case 34
	.4byte _0803C3D0 @ case 35
	.4byte _0803C3D0 @ case 36
	.4byte _0803C3D0 @ case 37
	.4byte _0803C3D0 @ case 38
	.4byte _0803C3D0 @ case 39
	.4byte _0803C3D0 @ case 40
	.4byte _0803C3D0 @ case 41
	.4byte _0803C3D0 @ case 42
	.4byte _0803C3D0 @ case 43
	.4byte _0803C3D0 @ case 44
	.4byte _0803C3D0 @ case 45
	.4byte _0803C3D0 @ case 46
	.4byte _0803C3D0 @ case 47
	.4byte _0803C3D0 @ case 48
	.4byte _0803C3D0 @ case 49
	.4byte _0803C3D0 @ case 50
	.4byte _0803C3D0 @ case 51
	.4byte _0803C3D0 @ case 52
	.4byte _0803C3D0 @ case 53
	.4byte _0803C3D0 @ case 54
	.4byte _0803C3D0 @ case 55
	.4byte _0803C3D0 @ case 56
	.4byte _0803C3D0 @ case 57
	.4byte _0803C3D0 @ case 58
	.4byte _0803C3D0 @ case 59
	.4byte _0803C3D0 @ case 60
	.4byte _0803C3D0 @ case 61
	.4byte _0803C3D0 @ case 62
	.4byte _0803C3D0 @ case 63
	.4byte _0803C3D0 @ case 64
	.4byte _0803C3D0 @ case 65
	.4byte _0803C3D0 @ case 66
	.4byte _0803C3D0 @ case 67
	.4byte _0803C3D0 @ case 68
	.4byte _0803C3D0 @ case 69
	.4byte _0803C3D0 @ case 70
	.4byte _0803C3D0 @ case 71
	.4byte _0803C3D0 @ case 72
	.4byte _0803C3D0 @ case 73
	.4byte _0803C3D0 @ case 74
	.4byte _0803C3D0 @ case 75
	.4byte _0803C3D0 @ case 76
	.4byte _0803C3D0 @ case 77
	.4byte _0803C3D0 @ case 78
	.4byte _0803C3D0 @ case 79
	.4byte _0803C3D0 @ case 80
	.4byte _0803C3D0 @ case 81
	.4byte _0803C3D0 @ case 82
	.4byte _0803C3D0 @ case 83
	.4byte _0803C3D0 @ case 84
	.4byte _0803C3D0 @ case 85
	.4byte _0803C3D0 @ case 86
	.4byte _0803C3B4 @ case 87
	.4byte _0803C3B8 @ case 88
	.4byte _0803C3BE @ case 89
	.4byte _0803C3C2 @ case 90
	.4byte _0803C3C8 @ case 91
_0803C390:
	bl SovaInit
	b _0803C3D0
_0803C396:
	bl SovaIdleInit
_0803C39A:
	bl SovaIdle
	b _0803C3D0
_0803C3A0:
	bl SovaTurningAroundInit
_0803C3A4:
	bl SovaTurningAround
	b _0803C3D0
_0803C3AA:
	bl SovaFallingInit
_0803C3AE:
	bl SovaFalling
	b _0803C3D0
_0803C3B4:
	bl SpriteDyingInit
_0803C3B8:
	bl SpriteDying
	b _0803C3D0
_0803C3BE:
	bl SovaInit
_0803C3C2:
	bl SpriteSpawningFromX
	b _0803C3D0
_0803C3C8:
	bl SovaTurningIntoX
	bl XParasiteInit
_0803C3D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SovaFire
SovaFire: @ 0x0803C3D8
	push {lr}
	ldr r0, _0803C3F0 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1a
	bhi _0803C48A
	lsls r0, r0, #2
	ldr r1, _0803C3F4 @ =_0803C3F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803C3F0: .4byte gCurrentSprite
_0803C3F4: .4byte _0803C3F8
_0803C3F8: @ jump table
	.4byte _0803C464 @ case 0
	.4byte _0803C48A @ case 1
	.4byte _0803C46A @ case 2
	.4byte _0803C48A @ case 3
	.4byte _0803C48A @ case 4
	.4byte _0803C48A @ case 5
	.4byte _0803C48A @ case 6
	.4byte _0803C482 @ case 7
	.4byte _0803C486 @ case 8
	.4byte _0803C48A @ case 9
	.4byte _0803C48A @ case 10
	.4byte _0803C48A @ case 11
	.4byte _0803C48A @ case 12
	.4byte _0803C48A @ case 13
	.4byte _0803C48A @ case 14
	.4byte _0803C48A @ case 15
	.4byte _0803C48A @ case 16
	.4byte _0803C48A @ case 17
	.4byte _0803C48A @ case 18
	.4byte _0803C48A @ case 19
	.4byte _0803C48A @ case 20
	.4byte _0803C48A @ case 21
	.4byte _0803C47C @ case 22
	.4byte _0803C48A @ case 23
	.4byte _0803C470 @ case 24
	.4byte _0803C48A @ case 25
	.4byte _0803C476 @ case 26
_0803C464:
	bl SovaFireInit
	b _0803C48A
_0803C46A:
	bl SovaFireBig
	b _0803C48A
_0803C470:
	bl SovaFireSmall
	b _0803C48A
_0803C476:
	bl SovaFireDisappearing
	b _0803C48A
_0803C47C:
	bl SpriteUtilCurrentSpriteFall
	b _0803C48A
_0803C482:
	bl SovaFireExplodingInit
_0803C486:
	bl SovaFireExploding
_0803C48A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start YardCheckShouldStartle
YardCheckShouldStartle: @ 0x0803C490
	push {lr}
	ldr r0, _0803C4B4 @ =gCurrentPowerBomb
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C4D8
	ldr r1, _0803C4B8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x18
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C4C0
	ldr r0, _0803C4BC @ =0x08355490
	b _0803C4C2
	.align 2, 0
_0803C4B4: .4byte gCurrentPowerBomb
_0803C4B8: .4byte gCurrentSprite
_0803C4BC: .4byte 0x08355490
_0803C4C0:
	ldr r0, _0803C4D4 @ =0x08355370
_0803C4C2:
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x30
	movs r0, #0xb4
	strb r0, [r1]
	movs r0, #1
	b _0803C4DA
	.align 2, 0
_0803C4D4: .4byte 0x08355370
_0803C4D8:
	movs r0, #0
_0803C4DA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start YardCheckCollidingWithAir
YardCheckCollidingWithAir: @ 0x0803C4E0
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _0803C514 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C540
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803C51C
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803C518 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803C590
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	b _0803C584
	.align 2, 0
_0803C514: .4byte gCurrentSprite
_0803C518: .4byte gPreviousCollisionCheck
_0803C51C:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803C53C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803C590
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803C584
	.align 2, 0
_0803C53C: .4byte gPreviousCollisionCheck
_0803C540:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C56C
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803C568 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803C590
	ldrh r0, [r4, #2]
	subs r0, #4
	b _0803C580
	.align 2, 0
_0803C568: .4byte gPreviousCollisionCheck
_0803C56C:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803C598 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803C590
	ldrh r0, [r4, #2]
_0803C580:
	ldrh r1, [r4, #4]
	adds r1, #0x20
_0803C584:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803C590
	movs r6, #1
_0803C590:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0803C598: .4byte gPreviousCollisionCheck

	thumb_func_start YardUpdateHitbox
YardUpdateHitbox: @ 0x0803C59C
	push {lr}
	ldr r2, _0803C5D4 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803C630
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C5F8
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803C5E0
	ldr r0, _0803C5D8 @ =0x0000FFE4
	strh r0, [r2, #0xa]
	movs r0, #0x1c
	strh r0, [r2, #0xc]
	ldr r0, _0803C5DC @ =0x0000FFC8
	strh r0, [r2, #0xe]
	movs r0, #0x10
	b _0803C69A
	.align 2, 0
_0803C5D4: .4byte gCurrentSprite
_0803C5D8: .4byte 0x0000FFE4
_0803C5DC: .4byte 0x0000FFC8
_0803C5E0:
	ldr r0, _0803C5F0 @ =0x0000FFE4
	strh r0, [r2, #0xa]
	movs r0, #0x1c
	strh r0, [r2, #0xc]
	ldr r0, _0803C5F4 @ =0x0000FFF0
	strh r0, [r2, #0xe]
	movs r0, #0x38
	b _0803C69A
	.align 2, 0
_0803C5F0: .4byte 0x0000FFE4
_0803C5F4: .4byte 0x0000FFF0
_0803C5F8:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C618
	movs r0, #0x10
	strh r0, [r2, #0xa]
	movs r0, #0x38
	strh r0, [r2, #0xc]
	ldr r0, _0803C614 @ =0x0000FFE4
	strh r0, [r2, #0xe]
	movs r0, #0x1c
	b _0803C69A
	.align 2, 0
_0803C614: .4byte 0x0000FFE4
_0803C618:
	ldr r0, _0803C628 @ =0x0000FFC8
	strh r0, [r2, #0xa]
	movs r0, #0x10
	strh r0, [r2, #0xc]
	ldr r0, _0803C62C @ =0x0000FFE4
	strh r0, [r2, #0xe]
	movs r0, #0x1c
	b _0803C69A
	.align 2, 0
_0803C628: .4byte 0x0000FFC8
_0803C62C: .4byte 0x0000FFE4
_0803C630:
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C678
	ldrh r1, [r2]
	movs r3, #0x40
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0803C660
	ldr r0, _0803C658 @ =0x0000FFE0
	strh r0, [r2, #0xa]
	movs r0, #0x20
	strh r0, [r2, #0xc]
	ldr r0, _0803C65C @ =0x0000FFC0
	strh r0, [r2, #0xe]
	movs r0, #0x10
	b _0803C69A
	.align 2, 0
_0803C658: .4byte 0x0000FFE0
_0803C65C: .4byte 0x0000FFC0
_0803C660:
	ldr r0, _0803C670 @ =0x0000FFE0
	strh r0, [r2, #0xa]
	movs r0, #0x20
	strh r0, [r2, #0xc]
	ldr r0, _0803C674 @ =0x0000FFF0
	strh r0, [r2, #0xe]
	strh r3, [r2, #0x10]
	b _0803C69C
	.align 2, 0
_0803C670: .4byte 0x0000FFE0
_0803C674: .4byte 0x0000FFF0
_0803C678:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803C68C
	movs r0, #0x10
	strh r0, [r2, #0xa]
	movs r0, #0x40
	b _0803C692
_0803C68C:
	ldr r0, _0803C6A0 @ =0x0000FFC0
	strh r0, [r2, #0xa]
	movs r0, #0x10
_0803C692:
	strh r0, [r2, #0xc]
	ldr r0, _0803C6A4 @ =0x0000FFE0
	strh r0, [r2, #0xe]
	movs r0, #0x20
_0803C69A:
	strh r0, [r2, #0x10]
_0803C69C:
	pop {r0}
	bx r0
	.align 2, 0
_0803C6A0: .4byte 0x0000FFC0
_0803C6A4: .4byte 0x0000FFE0

	thumb_func_start YardSetCrawlingOam
YardSetCrawlingOam: @ 0x0803C6A8
	push {lr}
	ldr r2, _0803C6CC @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r1, r2, #0
	cmp r0, #0
	beq _0803C6DC
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C6D4
	ldr r0, _0803C6D0 @ =0x08355540
	b _0803C6F2
	.align 2, 0
_0803C6CC: .4byte gCurrentSprite
_0803C6D0: .4byte 0x08355540
_0803C6D4:
	ldr r0, _0803C6D8 @ =0x08355530
	b _0803C6F2
	.align 2, 0
_0803C6D8: .4byte 0x08355530
_0803C6DC:
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C6F0
	ldr r0, _0803C6EC @ =0x083553E8
	b _0803C6F2
	.align 2, 0
_0803C6EC: .4byte 0x083553E8
_0803C6F0:
	ldr r0, _0803C700 @ =0x083552C8
_0803C6F2:
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803C700: .4byte 0x083552C8

	thumb_func_start YardSetTurningAroundOam
YardSetTurningAroundOam: @ 0x0803C704
	push {lr}
	ldr r0, _0803C718 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803C720
	ldr r0, _0803C71C @ =0x083554C8
	b _0803C722
	.align 2, 0
_0803C718: .4byte gCurrentSprite
_0803C71C: .4byte 0x083554C8
_0803C720:
	ldr r0, _0803C730 @ =0x083553A8
_0803C722:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803C730: .4byte 0x083553A8

	thumb_func_start YardSetTurningAroundSecondPartOam
YardSetTurningAroundSecondPartOam: @ 0x0803C734
	push {lr}
	ldr r0, _0803C748 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803C750
	ldr r0, _0803C74C @ =0x083554E8
	b _0803C752
	.align 2, 0
_0803C748: .4byte gCurrentSprite
_0803C74C: .4byte 0x083554E8
_0803C750:
	ldr r0, _0803C760 @ =0x083553C8
_0803C752:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803C760: .4byte 0x083553C8

	thumb_func_start YardSetChargingOam
YardSetChargingOam: @ 0x0803C764
	push {lr}
	ldr r0, _0803C778 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803C780
	ldr r0, _0803C77C @ =0x08355408
	b _0803C782
	.align 2, 0
_0803C778: .4byte gCurrentSprite
_0803C77C: .4byte 0x08355408
_0803C780:
	ldr r0, _0803C790 @ =0x083552E8
_0803C782:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803C790: .4byte 0x083552E8

	thumb_func_start YardSetShootingOam
YardSetShootingOam: @ 0x0803C794
	push {lr}
	ldr r0, _0803C7A8 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803C7B0
	ldr r0, _0803C7AC @ =0x08355438
	b _0803C7B2
	.align 2, 0
_0803C7A8: .4byte gCurrentSprite
_0803C7AC: .4byte 0x08355438
_0803C7B0:
	ldr r0, _0803C7C0 @ =0x08355318
_0803C7B2:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803C7C0: .4byte 0x08355318

	thumb_func_start YardSetRecoilOam
YardSetRecoilOam: @ 0x0803C7C4
	push {lr}
	ldr r0, _0803C7D8 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803C7E0
	ldr r0, _0803C7DC @ =0x08355470
	b _0803C7E2
	.align 2, 0
_0803C7D8: .4byte gCurrentSprite
_0803C7DC: .4byte 0x08355470
_0803C7E0:
	ldr r0, _0803C7F0 @ =0x08355350
_0803C7E2:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0803C7F0: .4byte 0x08355350

	thumb_func_start YardCheckShoot
YardCheckShoot: @ 0x0803C7F4
	push {r4, lr}
	ldr r1, _0803C808 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803C80C
	subs r0, #1
	strb r0, [r2]
	b _0803C866
	.align 2, 0
_0803C808: .4byte gCurrentSprite
_0803C80C:
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C824
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r2, #0
	adds r1, r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehindY
	b _0803C830
_0803C824:
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r2, #0
	adds r1, r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
_0803C830:
	adds r1, r0, #0
	cmp r1, #3
	bne _0803C844
	ldr r0, _0803C840 @ =gCurrentSprite
	adds r0, #0x24
	strb r1, [r0]
	b _0803C866
	.align 2, 0
_0803C840: .4byte gCurrentSprite
_0803C844:
	cmp r1, #0xc
	bne _0803C866
	ldr r4, _0803C86C @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bl YardSetChargingOam
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803C866
	ldr r0, _0803C870 @ =0x00000195
	bl SoundPlayNotAlreadyPlaying
_0803C866:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C86C: .4byte gCurrentSprite
_0803C870: .4byte 0x00000195

	thumb_func_start YardCharging
YardCharging: @ 0x0803C874
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803C892
	ldr r0, _0803C898 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x2e
	movs r1, #0x1e
	strb r1, [r2]
	adds r0, #0x24
	movs r1, #0x2c
	strb r1, [r0]
	bl YardSetShootingOam
_0803C892:
	pop {r0}
	bx r0
	.align 2, 0
_0803C898: .4byte gCurrentSprite

	thumb_func_start YardShooting
YardShooting: @ 0x0803C89C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	bl YardCheckShouldStartle
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0803C8AE
	b _0803CA2C
_0803C8AE:
	ldr r1, _0803C8CC @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	subs r2, r0, #1
	strb r2, [r3]
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _0803C8D0
	adds r1, #0x24
	movs r0, #0x2e
	strb r0, [r1]
	bl YardSetRecoilOam
	b _0803CA2C
	.align 2, 0
_0803C8CC: .4byte gCurrentSprite
_0803C8D0:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	beq _0803C8DA
	b _0803CA2C
_0803C8DA:
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r6, [r0]
	cmp r6, #0
	beq _0803C972
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0803C930
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0803C918
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	subs r0, #0x40
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x54
	str r0, [sp, #4]
	str r7, [sp, #8]
	b _0803C9F0
_0803C918:
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0x40
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x54
	str r0, [sp, #4]
	str r4, [sp, #8]
	b _0803C9A4
_0803C930:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0803C95E
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	subs r0, #0x40
	str r0, [sp]
	ldrh r0, [r1, #4]
	adds r0, #0x54
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x3a
	movs r1, #3
	bl SpriteSpawnSecondary
	b _0803CA18
_0803C95E:
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0x40
	str r0, [sp]
	ldrh r0, [r1, #4]
	adds r0, #0x54
	b _0803C9C0
_0803C972:
	ldrh r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0803C9CE
	movs r0, #0x40
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0803C9AE
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0x54
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x40
	str r0, [sp, #4]
	str r6, [sp, #8]
_0803C9A4:
	movs r0, #0x3a
	movs r1, #1
	bl SpriteSpawnSecondary
	b _0803CA18
_0803C9AE:
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0x54
	str r0, [sp]
	ldrh r0, [r1, #4]
	adds r0, #0x40
_0803C9C0:
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x3a
	movs r1, #2
	bl SpriteSpawnSecondary
	b _0803CA18
_0803C9CE:
	movs r0, #0x40
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0803C9FA
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	subs r0, #0x54
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0x40
	str r0, [sp, #4]
	str r5, [sp, #8]
_0803C9F0:
	movs r0, #0x3a
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0803CA18
_0803C9FA:
	ldrb r2, [r1, #0x1f]
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	subs r0, #0x54
	str r0, [sp]
	ldrh r0, [r1, #4]
	adds r0, #0x40
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0x3a
	movs r1, #3
	bl SpriteSpawnSecondary
_0803CA18:
	ldr r0, _0803CA34 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CA2C
	movs r0, #0xcb
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803CA2C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CA34: .4byte gCurrentSprite

	thumb_func_start YardRecoil
YardRecoil: @ 0x0803CA38
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803CA52
	ldr r1, _0803CA58 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #3
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x78
	strb r0, [r1]
_0803CA52:
	pop {r0}
	bx r0
	.align 2, 0
_0803CA58: .4byte gCurrentSprite

	thumb_func_start YardTurningIntoX
YardTurningIntoX: @ 0x0803CA5C
	push {lr}
	ldr r2, _0803CA7C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803CA88
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803CA80
	ldrh r0, [r2, #4]
	subs r0, #0x20
	strh r0, [r2, #4]
	b _0803CAA0
	.align 2, 0
_0803CA7C: .4byte gCurrentSprite
_0803CA80:
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	b _0803CAA0
_0803CA88:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803CA9A
	ldrh r0, [r2, #2]
	adds r0, #0x20
	b _0803CA9E
_0803CA9A:
	ldrh r0, [r2, #2]
	subs r0, #0x20
_0803CA9E:
	strh r0, [r2, #2]
_0803CAA0:
	pop {r0}
	bx r0

	thumb_func_start YardInit
YardInit: @ 0x0803CAA4
	push {r4, r5, r6, r7, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r4, _0803CAF0 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0x59
	bne _0803CB04
	ldrh r0, [r4]
	ldr r2, _0803CAF4 @ =0x0000FF7F
	ands r2, r0
	strh r2, [r4]
	movs r0, #0x5a
	strb r0, [r5]
	movs r0, #0x2c
	strh r0, [r4, #6]
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803CAD2
	b _0803CC0A
_0803CAD2:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0803CADE
	b _0803CC0A
_0803CADE:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0803CAF8
	movs r1, #0x40
	adds r0, r2, #0
	b _0803CBB8
	.align 2, 0
_0803CAF0: .4byte gCurrentSprite
_0803CAF4: .4byte 0x0000FF7F
_0803CAF8:
	ldr r0, _0803CB00 @ =0x0000FFBF
	ands r0, r2
	strh r0, [r4]
	b _0803CC0A
	.align 2, 0
_0803CB00: .4byte 0x0000FFBF
_0803CB04:
	bl SpriteUtilChooseRandomXDirection
	movs r0, #2
	strb r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803CB3C @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	movs r7, #0xf0
	adds r5, r7, #0
	ands r5, r0
	cmp r5, #0
	beq _0803CB40
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CC0A
	movs r0, #0x40
	b _0803CBB8
	.align 2, 0
_0803CB3C: .4byte gPreviousCollisionCheck
_0803CB40:
	ldrh r0, [r4, #2]
	subs r0, #0x44
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803CB7C
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	movs r2, #0
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	strh r0, [r4, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CC0A
	movs r0, #0x40
	b _0803CC06
_0803CB7C:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803CBBE
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	strh r0, [r4, #4]
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CC0A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
_0803CBB8:
	orrs r0, r1
	strh r0, [r4]
	b _0803CC0A
_0803CBBE:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r6]
	adds r2, r7, #0
	ands r2, r0
	cmp r2, #0
	bne _0803CBD8
	strh r2, [r4]
	b _0803CC74
_0803CBD8:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r4]
	movs r0, #0x40
	movs r2, #0
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	adds r0, #0x20
	strh r0, [r4, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CC0A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
_0803CC06:
	orrs r1, r0
	strh r1, [r4]
_0803CC0A:
	ldr r1, _0803CC28 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x34
	ldrb r2, [r3]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0803CC2C
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #8
	orrs r0, r2
	b _0803CC36
	.align 2, 0
_0803CC28: .4byte gCurrentSprite
_0803CC2C:
	adds r1, #0x22
	movs r0, #4
	strb r0, [r1]
	movs r0, #0xf7
	ands r0, r2
_0803CC36:
	strb r0, [r3]
	bl YardSetCrawlingOam
	bl YardUpdateHitbox
	ldr r3, _0803CC7C @ =gCurrentSprite
	ldr r2, _0803CC80 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	strh r0, [r3, #0x14]
	adds r2, r3, #0
	adds r2, #0x25
	movs r0, #2
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	subs r0, #8
	movs r1, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0803CC74:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC7C: .4byte gCurrentSprite
_0803CC80: .4byte sPrimarySpriteStats

	thumb_func_start YardCheckRoll
YardCheckRoll: @ 0x0803CC84
	push {r4, r5, lr}
	ldr r4, _0803CCC0 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #1
	bne _0803CCF0
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CCF0
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803CCB6
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803CCC4
_0803CCB6:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x15
	strb r0, [r1]
	b _0803CCF0
	.align 2, 0
_0803CCC0: .4byte gCurrentSprite
_0803CCC4:
	bl SpriteUtilMakeSpriteFaceAwayFromSamusDirection
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x3c
	strb r0, [r1]
	ldrh r2, [r4]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	bne _0803CCF0
	movs r1, #0
	movs r0, #0x80
	orrs r0, r2
	strh r0, [r4]
	adds r0, r4, #0
	adds r0, #0x2b
	strb r1, [r0]
	strh r5, [r4, #0x12]
_0803CCF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start YardRolling
YardRolling: @ 0x0803CCF8
	push {r4, r5, r6, r7, lr}
	bl YardCheckRoll
	movs r7, #0
	bl SpriteUtilAlignYPositionOnSlopeAtOrigin
	ldr r5, _0803CD38 @ =gPreviousVerticalCollisionCheck
	ldrb r2, [r5]
	adds r1, r2, #0
	cmp r1, #0
	bne _0803CD72
	ldr r4, _0803CD3C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CD40
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckVerticalCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803CD50
	cmp r0, #4
	beq _0803CD64
	cmp r0, #2
	beq _0803CD36
	b _0803CE5E
_0803CD36:
	b _0803CD64
	.align 2, 0
_0803CD38: .4byte gPreviousVerticalCollisionCheck
_0803CD3C: .4byte gCurrentSprite
_0803CD40:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckVerticalCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803CD5A
_0803CD50:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x15
	strb r0, [r1]
	b _0803CED0
_0803CD5A:
	cmp r0, #5
	beq _0803CD64
	cmp r0, #3
	beq _0803CD64
	b _0803CE5E
_0803CD64:
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPosition
	strh r0, [r4, #2]
	b _0803CE5E
_0803CD72:
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _0803CDF8
	ldr r4, _0803CDB8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803CDC4
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803CDBC @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803CDAE
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803CE5E
_0803CDAE:
	ldrh r1, [r4]
	ldr r0, _0803CDC0 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r4]
	b _0803CED0
	.align 2, 0
_0803CDB8: .4byte gCurrentSprite
_0803CDBC: .4byte gPreviousCollisionCheck
_0803CDC0: .4byte 0x0000FDFF
_0803CDC4:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r6, _0803CDF4 @ =gPreviousCollisionCheck
	ldrb r0, [r6]
	cmp r0, #0
	beq _0803CDE8
	ldrh r0, [r4, #2]
	subs r0, #0x10
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r6]
	cmp r0, #0x11
	bne _0803CE5E
_0803CDE8:
	ldrh r1, [r4]
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r4]
	b _0803CED0
	.align 2, 0
_0803CDF4: .4byte gPreviousCollisionCheck
_0803CDF8:
	cmp r1, #4
	beq _0803CE00
	cmp r1, #2
	bne _0803CE28
_0803CE00:
	ldr r1, _0803CE24 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	bne _0803CE80
	adds r0, r5, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803CE5E
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r5]
	b _0803CE80
	.align 2, 0
_0803CE24: .4byte gCurrentSprite
_0803CE28:
	cmp r1, #5
	beq _0803CE30
	cmp r1, #3
	bne _0803CE5E
_0803CE30:
	ldr r1, _0803CE54 @ =gCurrentSprite
	ldrh r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _0803CE5C
	adds r0, r5, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803CE5E
	ldr r0, _0803CE58 @ =0x0000FDFF
	ands r0, r2
	strh r0, [r5]
	b _0803CE80
	.align 2, 0
_0803CE54: .4byte gCurrentSprite
_0803CE58: .4byte 0x0000FDFF
_0803CE5C:
	movs r7, #1
_0803CE5E:
	ldr r5, _0803CE7C @ =gCurrentSprite
	cmp r7, #0
	bne _0803CE80
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803CE8E
	subs r1, #0xa
	movs r0, #1
	strb r0, [r1]
	b _0803CED0
	.align 2, 0
_0803CE7C: .4byte gCurrentSprite
_0803CE80:
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _0803CE8E
	movs r0, #0x10
	strb r0, [r1]
_0803CE8E:
	adds r0, r5, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsrs r4, r0, #3
	adds r0, r4, #0
	bl SpriteUtilMoveXPosForwardOnSlopeDirection
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CEB2
	adds r1, r5, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	adds r0, r0, r4
	b _0803CEBA
_0803CEB2:
	adds r1, r5, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	subs r0, r0, r4
_0803CEBA:
	strb r0, [r1]
	ldr r0, _0803CED8 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _0803CED0
	movs r0, #0xcc
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803CED0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CED8: .4byte gFrameCounter8Bit

	thumb_func_start YardStartled
YardStartled: @ 0x0803CEDC
	push {lr}
	bl YardCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803CEF8
	ldr r0, _0803CEF4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	strb r1, [r0]
	b _0803CF10
	.align 2, 0
_0803CEF4: .4byte gCurrentSprite
_0803CEF8:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803CF10
	ldr r1, _0803CF14 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #1
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x78
	strb r0, [r1]
_0803CF10:
	pop {r0}
	bx r0
	.align 2, 0
_0803CF14: .4byte gCurrentSprite

	thumb_func_start YardIdleInit
YardIdleInit: @ 0x0803CF18
	push {lr}
	bl YardSetCrawlingOam
	ldr r0, _0803CF2C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0803CF2C: .4byte gCurrentSprite

	thumb_func_start YardIdle
YardIdle: @ 0x0803CF30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	movs r0, #1
	mov sb, r0
	movs r6, #0
	bl YardCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803CF5C
	ldr r0, _0803CF58 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x15
	strb r1, [r0]
	b _0803D2C0
	.align 2, 0
_0803CF58: .4byte gCurrentSprite
_0803CF5C:
	ldr r4, _0803CF74 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803CF78
	bl YardCheckRoll
	b _0803D2C0
	.align 2, 0
_0803CF74: .4byte gCurrentSprite
_0803CF78:
	bl YardCheckShouldStartle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803CF84
	b _0803D2C0
_0803CF84:
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803D050
	ldrh r1, [r4, #2]
	ldrh r2, [r4, #4]
	ldrh r0, [r4, #0xa]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	ldrh r0, [r4, #0xc]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	ldrh r0, [r4, #0xe]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldrh r0, [r4, #0x10]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r5, #0
	str r4, [sp, #0x18]
_0803CFBE:
	ldr r0, [sp, #0x18]
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r5, r0
	beq _0803D03E
	ldr r1, _0803D04C @ =gSpriteData
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	mov ip, r0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803D03E
	mov r1, ip
	ldrb r0, [r1, #0x1d]
	cmp r0, #0x6d
	bne _0803D03E
	mov r0, ip
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x82
	ands r0, r1
	cmp r0, #0
	bne _0803D03E
	mov r0, ip
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5a
	bhi _0803D03E
	mov r7, ip
	ldrh r3, [r7, #2]
	ldrh r4, [r7, #4]
	ldrh r2, [r7, #0xa]
	adds r2, r3, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r0, [r7, #0xc]
	adds r3, r3, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldrh r1, [r7, #0xe]
	adds r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r7, #0x10]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r2, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	mov r2, sl
	mov r3, r8
	bl SpriteUtilCheckObjectsTouching
	cmp r0, #0
	beq _0803D03E
	b _0803D296
_0803D03E:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x17
	bls _0803CFBE
	b _0803D054
	.align 2, 0
_0803D04C: .4byte gSpriteData
_0803D050:
	subs r0, #1
	strb r0, [r1]
_0803D054:
	ldr r4, _0803D098 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803D062
	b _0803D168
_0803D062:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803D0E0
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D0A0
	ldrh r0, [r4, #2]
	adds r0, #0x30
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803D09C @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803D08E
	b _0803D270
_0803D08E:
	ldrh r0, [r4, #2]
	adds r0, #0x30
	ldrh r1, [r4, #4]
	subs r1, #4
	b _0803D10A
	.align 2, 0
_0803D098: .4byte gCurrentSprite
_0803D09C: .4byte gPreviousCollisionCheck
_0803D0A0:
	ldrh r0, [r4, #2]
	subs r0, #0x30
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803D0DC @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803D0B8
	b _0803D270
_0803D0B8:
	ldrh r0, [r4, #2]
	subs r0, #0x30
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803D0D0
	b _0803D270
_0803D0D0:
	ldrh r0, [r4, #2]
	mov r1, sb
	subs r0, r0, r1
	strh r0, [r4, #2]
	b _0803D2B0
	.align 2, 0
_0803D0DC: .4byte gPreviousCollisionCheck
_0803D0E0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D128
	ldrh r0, [r4, #2]
	adds r0, #0x30
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803D124 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803D104
	b _0803D270
_0803D104:
	ldrh r0, [r4, #2]
	adds r0, #0x30
	ldrh r1, [r4, #4]
_0803D10A:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803D11A
	b _0803D270
_0803D11A:
	ldrh r0, [r4, #2]
	add r0, sb
	strh r0, [r4, #2]
	b _0803D2B0
	.align 2, 0
_0803D124: .4byte gPreviousCollisionCheck
_0803D128:
	ldrh r0, [r4, #2]
	subs r0, #0x30
	ldrh r1, [r4, #4]
	subs r1, #4
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803D164 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	bne _0803D142
	b _0803D270
_0803D142:
	ldrh r0, [r4, #2]
	subs r0, #0x30
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803D158
	b _0803D270
_0803D158:
	ldrh r0, [r4, #2]
	mov r7, sb
	subs r0, r0, r7
	strh r0, [r4, #2]
	b _0803D2B0
	.align 2, 0
_0803D164: .4byte gPreviousCollisionCheck
_0803D168:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803D1EC
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D1B8
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803D1B4 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D270
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0803D270
	ldrh r0, [r4, #4]
	add r0, sb
	b _0803D2AE
	.align 2, 0
_0803D1B4: .4byte gPreviousCollisionCheck
_0803D1B8:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803D1E8 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r7, #0xf
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D270
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _0803D270
	b _0803D2A8
	.align 2, 0
_0803D1E8: .4byte gPreviousCollisionCheck
_0803D1EC:
	bl SpriteUtilAlignYPositionOnSlopeAtOrigin
	ldr r0, _0803D23C @ =gPreviousVerticalCollisionCheck
	ldrb r1, [r0]
	movs r5, #0xf0
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D284
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D244
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _0803D240 @ =gPreviousCollisionCheck
	ldrb r1, [r7]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D270
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r7]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803D270
	ldrh r0, [r4, #4]
	add r0, sb
	b _0803D2AE
	.align 2, 0
_0803D23C: .4byte gPreviousVerticalCollisionCheck
_0803D240: .4byte gPreviousCollisionCheck
_0803D244:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r7, _0803D278 @ =gPreviousCollisionCheck
	ldrb r1, [r7]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D270
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r7]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803D27C
_0803D270:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _0803D2B0
	.align 2, 0
_0803D278: .4byte gPreviousCollisionCheck
_0803D27C:
	ldrh r0, [r4, #4]
	mov r7, sb
	subs r0, r0, r7
	b _0803D2AE
_0803D284:
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D2A8
	ldrh r0, [r4, #4]
	add r0, sb
	b _0803D2AE
_0803D296:
	ldr r1, [sp, #0x18]
	adds r1, #0x2f
	movs r0, #0x78
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
	b _0803D2C0
_0803D2A8:
	ldrh r0, [r4, #4]
	mov r1, sb
	subs r0, r0, r1
_0803D2AE:
	strh r0, [r4, #4]
_0803D2B0:
	cmp r6, #0
	beq _0803D2BC
	ldr r0, _0803D2D0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
_0803D2BC:
	bl YardCheckShoot
_0803D2C0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D2D0: .4byte gCurrentSprite

	thumb_func_start YardTurningAroundInit
YardTurningAroundInit: @ 0x0803D2D4
	push {lr}
	ldr r0, _0803D2E8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #4
	strb r1, [r0]
	bl YardSetTurningAroundOam
	pop {r0}
	bx r0
	.align 2, 0
_0803D2E8: .4byte gCurrentSprite

	thumb_func_start YardTurningAround
YardTurningAround: @ 0x0803D2EC
	push {r4, lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803D332
	ldr r4, _0803D318 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #5
	strb r1, [r0]
	bl YardSetTurningAroundSecondPartOam
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D31C
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	b _0803D320
	.align 2, 0
_0803D318: .4byte gCurrentSprite
_0803D31C:
	ldrh r0, [r4]
	movs r1, #0x40
_0803D320:
	eors r0, r1
	strh r0, [r4]
	ldr r0, _0803D338 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r3, #0
	eors r1, r2
	strh r1, [r0]
_0803D332:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D338: .4byte gCurrentSprite

	thumb_func_start YardTurningAroundSecondPart
YardTurningAroundSecondPart: @ 0x0803D33C
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803D34E
	ldr r0, _0803D354 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0803D34E:
	pop {r0}
	bx r0
	.align 2, 0
_0803D354: .4byte gCurrentSprite

	thumb_func_start YardFallingInit
YardFallingInit: @ 0x0803D358
	push {lr}
	ldr r1, _0803D374 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r1, #0x31
	strb r3, [r1]
	bl YardSetCrawlingOam
	pop {r0}
	bx r0
	.align 2, 0
_0803D374: .4byte gCurrentSprite

	thumb_func_start YardFalling
YardFalling: @ 0x0803D378
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r2, _0803D3A0 @ =gCurrentSprite
	ldrh r3, [r2, #2]
	ldrh r4, [r2, #4]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D3A4
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803D3B0
	subs r0, r4, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _0803D3B0
	.align 2, 0
_0803D3A0: .4byte gCurrentSprite
_0803D3A4:
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803D3B8
_0803D3B0:
	ldrh r0, [r2, #0xc]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_0803D3B8:
	adds r0, r3, #0
	adds r1, r4, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _0803D410 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D444
	ldr r4, _0803D414 @ =gCurrentSprite
	strh r1, [r4, #2]
	adds r2, r4, #0
	adds r2, #0x2d
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803D3DE
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0803D3DE:
	ldrh r1, [r4]
	ldr r0, _0803D418 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r4]
	movs r0, #0
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	bl YardUpdateHitbox
	bl YardSetCrawlingOam
	cmp r5, #0
	beq _0803D424
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803D41C
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0x10]
	b _0803D420
	.align 2, 0
_0803D410: .4byte gPreviousVerticalCollisionCheck
_0803D414: .4byte gCurrentSprite
_0803D418: .4byte 0x0000FEFF
_0803D41C:
	ldrh r0, [r4, #4]
	ldrh r1, [r4, #0xe]
_0803D420:
	subs r0, r0, r1
	strh r0, [r4, #4]
_0803D424:
	ldr r2, _0803D440 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D488
	ldrh r0, [r2, #2]
	ldrh r1, [r2, #4]
	movs r2, #0x28
	bl ParticleSet
	b _0803D488
	.align 2, 0
_0803D440: .4byte gCurrentSprite
_0803D444:
	ldr r3, _0803D470 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _0803D474 @ =sSpritesFallingSpeedSlow
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0803D478 @ =0x00007FFF
	cmp r1, r0
	bne _0803D47C
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0803D486
	.align 2, 0
_0803D470: .4byte gCurrentSprite
_0803D474: .4byte sSpritesFallingSpeedSlow
_0803D478: .4byte 0x00007FFF
_0803D47C:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_0803D486:
	strh r0, [r3, #2]
_0803D488:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start YardProjectileInit
YardProjectileInit: @ 0x0803D490
	push {r4, lr}
	ldr r0, _0803D4FC @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0803D500 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	subs r2, #0xb
	movs r0, #0x10
	strb r0, [r2]
	ldr r0, _0803D504 @ =0x0000FFF8
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	ldr r0, _0803D508 @ =0x08355508
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r1, #3
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0803D50C @ =gIoRegisters
	ldrb r1, [r1, #0xa]
	ands r0, r1
	mov r1, ip
	adds r1, #0x21
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4FC: .4byte gCurrentSprite
_0803D500: .4byte 0x0000FFFB
_0803D504: .4byte 0x0000FFF8
_0803D508: .4byte 0x08355508
_0803D50C: .4byte gIoRegisters

	thumb_func_start YardProjectileMoving
YardProjectileMoving: @ 0x0803D510
	push {lr}
	ldr r1, _0803D528 @ =gCurrentSprite
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _0803D52C
	ldrh r0, [r1, #2]
	subs r0, #3
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	subs r0, #3
	b _0803D554
	.align 2, 0
_0803D528: .4byte gCurrentSprite
_0803D52C:
	cmp r0, #1
	bne _0803D53C
	ldrh r0, [r1, #2]
	adds r0, #3
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	subs r0, #3
	b _0803D554
_0803D53C:
	cmp r0, #2
	bne _0803D546
	ldrh r0, [r1, #2]
	adds r0, #3
	b _0803D54E
_0803D546:
	cmp r0, #3
	bne _0803D556
	ldrh r0, [r1, #2]
	subs r0, #3
_0803D54E:
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	adds r0, #3
_0803D554:
	strh r0, [r1, #4]
_0803D556:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start YardProjectileExplodingInit
YardProjectileExplodingInit: @ 0x0803D55C
	ldr r3, _0803D578 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x38
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	ldr r0, _0803D57C @ =0x08355550
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	bx lr
	.align 2, 0
_0803D578: .4byte gCurrentSprite
_0803D57C: .4byte 0x08355550

	thumb_func_start YardProjectileExploding
YardProjectileExploding: @ 0x0803D580
	push {r4, lr}
	ldr r4, _0803D5A0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803D598
	movs r0, #0
	strh r0, [r4]
_0803D598:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D5A0: .4byte gCurrentSprite

	thumb_func_start Yard
Yard: @ 0x0803D5A4
	push {r4, lr}
	ldr r4, _0803D5CC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803D5BC
	ldr r0, _0803D5D0 @ =0x00000197
	bl SoundPlayNotAlreadyPlaying
_0803D5BC:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D5D4
	bl SpriteUtilUpdateFreezeTimer
	b _0803D7C4
	.align 2, 0
_0803D5CC: .4byte gCurrentSprite
_0803D5D0: .4byte 0x00000197
_0803D5D4:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803D5E0
	b _0803D7C4
_0803D5E0:
	lsls r0, r0, #2
	ldr r1, _0803D5EC @ =_0803D5F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803D5EC: .4byte _0803D5F0
_0803D5F0: @ jump table
	.4byte _0803D760 @ case 0
	.4byte _0803D766 @ case 1
	.4byte _0803D76A @ case 2
	.4byte _0803D776 @ case 3
	.4byte _0803D77A @ case 4
	.4byte _0803D780 @ case 5
	.4byte _0803D7C4 @ case 6
	.4byte _0803D7C4 @ case 7
	.4byte _0803D7C4 @ case 8
	.4byte _0803D7C4 @ case 9
	.4byte _0803D7C4 @ case 10
	.4byte _0803D7C4 @ case 11
	.4byte _0803D7C4 @ case 12
	.4byte _0803D7C4 @ case 13
	.4byte _0803D7C4 @ case 14
	.4byte _0803D7C4 @ case 15
	.4byte _0803D7C4 @ case 16
	.4byte _0803D7C4 @ case 17
	.4byte _0803D7C4 @ case 18
	.4byte _0803D7C4 @ case 19
	.4byte _0803D7C4 @ case 20
	.4byte _0803D786 @ case 21
	.4byte _0803D78A @ case 22
	.4byte _0803D7C4 @ case 23
	.4byte _0803D770 @ case 24
	.4byte _0803D7C4 @ case 25
	.4byte _0803D7C4 @ case 26
	.4byte _0803D7C4 @ case 27
	.4byte _0803D7C4 @ case 28
	.4byte _0803D7C4 @ case 29
	.4byte _0803D7C4 @ case 30
	.4byte _0803D7C4 @ case 31
	.4byte _0803D7C4 @ case 32
	.4byte _0803D7C4 @ case 33
	.4byte _0803D7C4 @ case 34
	.4byte _0803D7C4 @ case 35
	.4byte _0803D7C4 @ case 36
	.4byte _0803D7C4 @ case 37
	.4byte _0803D7C4 @ case 38
	.4byte _0803D7C4 @ case 39
	.4byte _0803D7C4 @ case 40
	.4byte _0803D7C4 @ case 41
	.4byte _0803D790 @ case 42
	.4byte _0803D7C4 @ case 43
	.4byte _0803D796 @ case 44
	.4byte _0803D7C4 @ case 45
	.4byte _0803D79C @ case 46
	.4byte _0803D7C4 @ case 47
	.4byte _0803D7C4 @ case 48
	.4byte _0803D7C4 @ case 49
	.4byte _0803D7C4 @ case 50
	.4byte _0803D7C4 @ case 51
	.4byte _0803D7C4 @ case 52
	.4byte _0803D7C4 @ case 53
	.4byte _0803D7C4 @ case 54
	.4byte _0803D7C4 @ case 55
	.4byte _0803D7A2 @ case 56
	.4byte _0803D7C4 @ case 57
	.4byte _0803D7C4 @ case 58
	.4byte _0803D7C4 @ case 59
	.4byte _0803D7C4 @ case 60
	.4byte _0803D7C4 @ case 61
	.4byte _0803D7C4 @ case 62
	.4byte _0803D7C4 @ case 63
	.4byte _0803D7C4 @ case 64
	.4byte _0803D7C4 @ case 65
	.4byte _0803D7C4 @ case 66
	.4byte _0803D7C4 @ case 67
	.4byte _0803D7C4 @ case 68
	.4byte _0803D7C4 @ case 69
	.4byte _0803D7C4 @ case 70
	.4byte _0803D7C4 @ case 71
	.4byte _0803D7C4 @ case 72
	.4byte _0803D7C4 @ case 73
	.4byte _0803D7C4 @ case 74
	.4byte _0803D7C4 @ case 75
	.4byte _0803D7C4 @ case 76
	.4byte _0803D7C4 @ case 77
	.4byte _0803D7C4 @ case 78
	.4byte _0803D7C4 @ case 79
	.4byte _0803D7C4 @ case 80
	.4byte _0803D7C4 @ case 81
	.4byte _0803D7C4 @ case 82
	.4byte _0803D7C4 @ case 83
	.4byte _0803D7C4 @ case 84
	.4byte _0803D7C4 @ case 85
	.4byte _0803D7C4 @ case 86
	.4byte _0803D7A8 @ case 87
	.4byte _0803D7AC @ case 88
	.4byte _0803D7B2 @ case 89
	.4byte _0803D7B6 @ case 90
	.4byte _0803D7BC @ case 91
_0803D760:
	bl YardInit
	b _0803D7C4
_0803D766:
	bl YardIdleInit
_0803D76A:
	bl YardIdle
	b _0803D7C4
_0803D770:
	bl YardStartled
	b _0803D7C4
_0803D776:
	bl YardTurningAroundInit
_0803D77A:
	bl YardTurningAround
	b _0803D7C4
_0803D780:
	bl YardTurningAroundSecondPart
	b _0803D7C4
_0803D786:
	bl YardFallingInit
_0803D78A:
	bl YardFalling
	b _0803D7C4
_0803D790:
	bl YardCharging
	b _0803D7C4
_0803D796:
	bl YardShooting
	b _0803D7C4
_0803D79C:
	bl YardRecoil
	b _0803D7C4
_0803D7A2:
	bl YardRolling
	b _0803D7C4
_0803D7A8:
	bl SpriteDyingInit
_0803D7AC:
	bl SpriteDying
	b _0803D7C4
_0803D7B2:
	bl YardInit
_0803D7B6:
	bl SpriteSpawningFromX
	b _0803D7C4
_0803D7BC:
	bl YardTurningIntoX
	bl XParasiteInit
_0803D7C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start YardProjectile
YardProjectile: @ 0x0803D7CC
	push {lr}
	ldr r0, _0803D7E4 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803D7F2
	cmp r0, #2
	bgt _0803D7E8
	cmp r0, #0
	beq _0803D7EE
	b _0803D7FE
	.align 2, 0
_0803D7E4: .4byte gCurrentSprite
_0803D7E8:
	cmp r0, #0x38
	beq _0803D7F8
	b _0803D7FE
_0803D7EE:
	bl YardProjectileInit
_0803D7F2:
	bl YardProjectileMoving
	b _0803D802
_0803D7F8:
	bl YardProjectileExploding
	b _0803D802
_0803D7FE:
	bl YardProjectileExplodingInit
_0803D802:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EvirCheckInShootingRange
EvirCheckInShootingRange: @ 0x0803D808
	push {r4, lr}
	movs r4, #0
	ldr r3, _0803D820 @ =gCurrentSprite
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _0803D824
	movs r0, #0
	b _0803D854
	.align 2, 0
_0803D820: .4byte gCurrentSprite
_0803D824:
	adds r2, r3, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803D836
	subs r0, #1
	strb r0, [r2]
	movs r0, #0
	b _0803D854
_0803D836:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D852
	ldrh r0, [r3, #0x14]
	cmp r0, #0
	beq _0803D852
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0803D852:
	adds r0, r4, #0
_0803D854:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EvirSpawningFromX
EvirSpawningFromX: @ 0x0803D85C
	push {lr}
	ldr r3, _0803D884 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldrh r0, [r3, #6]
	subs r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803D890
	ldr r2, _0803D888 @ =gWrittenToMosaic_H
	ldr r1, _0803D88C @ =sXParasiteMosaicValues
	ldrh r0, [r3, #6]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	b _0803D8A4
	.align 2, 0
_0803D884: .4byte gCurrentSprite
_0803D888: .4byte gWrittenToMosaic_H
_0803D88C: .4byte sXParasiteMosaicValues
_0803D890:
	ldrh r0, [r3]
	ldr r1, _0803D8A8 @ =0x00007FFF
	ands r1, r0
	adds r2, r3, #0
	adds r2, #0x24
	movs r0, #2
	strb r0, [r2]
	ldr r0, _0803D8AC @ =0x0000FFDF
	ands r1, r0
	strh r1, [r3]
_0803D8A4:
	pop {r0}
	bx r0
	.align 2, 0
_0803D8A8: .4byte 0x00007FFF
_0803D8AC: .4byte 0x0000FFDF

	thumb_func_start EvirTurningIntoX
EvirTurningIntoX: @ 0x0803D8B0
	push {r4, lr}
	sub sp, #0x10
	ldr r2, _0803D8F0 @ =gCurrentSprite
	ldrh r0, [r2, #2]
	subs r0, #0x5c
	strh r0, [r2, #2]
	ldrh r1, [r2]
	movs r4, #0x40
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D8F4
	ldrb r1, [r2, #0x1d]
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r2, #2]
	subs r0, #0x28
	str r0, [sp, #4]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	b _0803D918
	.align 2, 0
_0803D8F0: .4byte gCurrentSprite
_0803D8F4:
	ldrb r1, [r2, #0x1d]
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r2, #2]
	subs r0, #0x28
	str r0, [sp, #4]
	ldrh r0, [r2, #4]
	subs r0, #0x20
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
_0803D918:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start EvirInit
EvirInit: @ 0x0803D920
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r3, _0803D98C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x27
	movs r5, #0
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	ldr r2, _0803D990 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r4, #0
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x25
	movs r2, #2
	strb r2, [r0]
	ldr r0, _0803D994 @ =0x08356ABC
	str r0, [r3, #0x18]
	strb r4, [r3, #0x1c]
	strh r5, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x2e
	strb r4, [r0]
	adds r0, #6
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803D9B0
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0803D998
	strh r5, [r3]
	b _0803DA6A
	.align 2, 0
_0803D98C: .4byte gCurrentSprite
_0803D990: .4byte sPrimarySpriteStats
_0803D994: .4byte 0x08356ABC
_0803D998:
	adds r0, r3, #0
	adds r0, #0x36
	strb r2, [r0]
	ldr r0, _0803D9AC @ =0x0000FF80
	strh r0, [r3, #0xa]
	strh r5, [r3, #0xc]
	adds r0, #0x40
	strh r0, [r3, #0xe]
	movs r0, #0x40
	b _0803D9BE
	.align 2, 0
_0803D9AC: .4byte 0x0000FF80
_0803D9B0:
	ldr r0, _0803D9D8 @ =0x0000FFC0
	strh r0, [r3, #0xa]
	adds r0, #0x28
	strh r0, [r3, #0xc]
	subs r0, #8
	strh r0, [r3, #0xe]
	movs r0, #0x20
_0803D9BE:
	strh r0, [r3, #0x10]
	ldr r4, _0803D9DC @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803D9E0
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _0803DA6A
	.align 2, 0
_0803D9D8: .4byte 0x0000FFC0
_0803D9DC: .4byte gCurrentSprite
_0803D9E0:
	movs r7, #0
	movs r0, #2
	strb r0, [r1]
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	bl SpriteUtilChooseRandomXDirection
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x60
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x3b
	movs r1, #0
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _0803DA42
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0803DA46
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x18
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0x3b
	movs r1, #1
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0803DA6A
_0803DA42:
	strh r7, [r4]
	b _0803DA6A
_0803DA46:
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x18
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x3b
	movs r1, #1
	bl SpriteSpawnSecondary
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0803DA6A
	strh r5, [r4]
_0803DA6A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EvirShootingInit
EvirShootingInit: @ 0x0803DA74
	ldr r0, _0803DA90 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r3, #0
	movs r1, #0x2a
	strb r1, [r2]
	ldr r1, _0803DA94 @ =0x08356B04
	str r1, [r0, #0x18]
	strb r3, [r0, #0x1c]
	strh r3, [r0, #0x16]
	adds r0, #0x2e
	movs r1, #0x5a
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803DA90: .4byte gCurrentSprite
_0803DA94: .4byte 0x08356B04

	thumb_func_start EvirShooting
EvirShooting: @ 0x0803DA98
	push {r4, lr}
	sub sp, #0xc
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803DAB4
	ldr r0, _0803DAB0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
	b _0803DB36
	.align 2, 0
_0803DAB0: .4byte gCurrentSprite
_0803DAB4:
	ldr r1, _0803DAF0 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	mov ip, r1
	cmp r0, #4
	bne _0803DB16
	ldrb r0, [r1, #0x1c]
	cmp r0, #8
	bne _0803DB16
	ldrh r1, [r1]
	movs r4, #0x40
	adds r0, r4, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _0803DAF4
	mov r0, ip
	ldrb r2, [r0, #0x1f]
	adds r0, #0x23
	ldrb r3, [r0]
	mov r1, ip
	ldrh r0, [r1, #2]
	subs r0, #0x48
	str r0, [sp]
	ldrh r0, [r1, #4]
	adds r0, #0x1c
	str r0, [sp, #4]
	str r4, [sp, #8]
	b _0803DB0C
	.align 2, 0
_0803DAF0: .4byte gCurrentSprite
_0803DAF4:
	mov r4, ip
	ldrb r2, [r4, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	subs r0, #0x48
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x1c
	str r0, [sp, #4]
	str r1, [sp, #8]
_0803DB0C:
	movs r0, #0x3c
	movs r1, #0
	bl SpriteSpawnSecondary
	b _0803DB36
_0803DB16:
	mov r1, ip
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0803DB36
	ldrb r0, [r1, #0x1c]
	cmp r0, #8
	bne _0803DB36
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803DB36
	movs r0, #0xd5
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803DB36:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EvirIdleInit
EvirIdleInit: @ 0x0803DB40
	ldr r1, _0803DB58 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #2
	strb r0, [r2]
	ldr r0, _0803DB5C @ =0x08356ABC
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0803DB58: .4byte gCurrentSprite
_0803DB5C: .4byte 0x08356ABC

	thumb_func_start EvirIdle
EvirIdle: @ 0x0803DB60
	push {r4, r5, r6, lr}
	bl EvirCheckInShootingRange
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803DB72
	bl EvirShootingInit
	b _0803DC90
_0803DB72:
	movs r6, #0
	ldr r4, _0803DBB8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803DBC4
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803DBBC @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803DBEA
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803DBEA
	ldr r0, _0803DBC0 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803DC06
	ldrh r0, [r4, #4]
	adds r0, #4
	b _0803DC04
	.align 2, 0
_0803DBB8: .4byte gCurrentSprite
_0803DBBC: .4byte gPreviousCollisionCheck
_0803DBC0: .4byte gFrameCounter8Bit
_0803DBC4:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803DBF0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803DBEA
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803DBF4
_0803DBEA:
	movs r6, #1
	b _0803DC06
	.align 2, 0
_0803DBF0: .4byte gPreviousCollisionCheck
_0803DBF4:
	ldr r0, _0803DC30 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803DC06
	ldrh r0, [r4, #4]
	subs r0, #4
_0803DC04:
	strh r0, [r4, #4]
_0803DC06:
	ldr r4, _0803DC34 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803DC3C
	ldrh r0, [r4, #2]
	adds r0, #8
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803DC38 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _0803DC4E
	ldrh r0, [r4, #2]
	adds r0, #2
	b _0803DC60
	.align 2, 0
_0803DC30: .4byte gFrameCounter8Bit
_0803DC34: .4byte gCurrentSprite
_0803DC38: .4byte gPreviousCollisionCheck
_0803DC3C:
	ldrh r0, [r4, #2]
	subs r0, #0x80
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803DC58 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0803DC5C
_0803DC4E:
	ldrh r1, [r4]
	adds r0, r5, #0
	eors r0, r1
	strh r0, [r4]
	b _0803DC62
	.align 2, 0
_0803DC58: .4byte gPreviousCollisionCheck
_0803DC5C:
	ldrh r0, [r4, #2]
	subs r0, #2
_0803DC60:
	strh r0, [r4, #2]
_0803DC62:
	cmp r6, #0
	beq _0803DC74
	ldr r0, _0803DC70 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #3
	strb r1, [r0]
	b _0803DC90
	.align 2, 0
_0803DC70: .4byte gCurrentSprite
_0803DC74:
	ldr r2, _0803DC98 @ =gCurrentSprite
	ldrh r1, [r2, #0x16]
	cmp r1, #2
	bne _0803DC90
	ldrb r0, [r2, #0x1c]
	cmp r0, #1
	bne _0803DC90
	ldrh r0, [r2]
	ands r1, r0
	cmp r1, #0
	beq _0803DC90
	ldr r0, _0803DC9C @ =0x000001A9
	bl SoundPlayNotAlreadyPlaying
_0803DC90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DC98: .4byte gCurrentSprite
_0803DC9C: .4byte 0x000001A9

	thumb_func_start EvirTurningAroundInit
EvirTurningAroundInit: @ 0x0803DCA0
	ldr r1, _0803DCB8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r0, _0803DCBC @ =0x08356B44
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0803DCB8: .4byte gCurrentSprite
_0803DCBC: .4byte 0x08356B44

	thumb_func_start EvirTurningAround
EvirTurningAround: @ 0x0803DCC0
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803DCE6
	ldr r2, _0803DCEC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0803DCF0 @ =0x08356B64
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_0803DCE6:
	pop {r0}
	bx r0
	.align 2, 0
_0803DCEC: .4byte gCurrentSprite
_0803DCF0: .4byte 0x08356B64

	thumb_func_start EvirTurningAroundSecondPart
EvirTurningAroundSecondPart: @ 0x0803DCF4
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803DD06
	ldr r0, _0803DD0C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0803DD06:
	pop {r0}
	bx r0
	.align 2, 0
_0803DD0C: .4byte gCurrentSprite

	thumb_func_start EvirCollisionInit
EvirCollisionInit: @ 0x0803DD10
	push {r4, r5, lr}
	ldr r0, _0803DD98 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x23
	ldrb r1, [r0]
	ldr r2, _0803DD9C @ =gSpriteData
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803DD3C
	mov r5, ip
	ldrh r1, [r5]
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r5]
_0803DD3C:
	mov r0, ip
	adds r0, #0x25
	movs r3, #0
	movs r2, #2
	strb r2, [r0]
	adds r0, #2
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r1, ip
	adds r1, #0x29
	movs r0, #0x10
	strb r0, [r1]
	movs r4, #0
	ldr r0, _0803DDA0 @ =0x0000FFE0
	mov r1, ip
	strh r0, [r1, #0xa]
	movs r0, #0x20
	strh r0, [r1, #0xc]
	ldr r1, _0803DDA4 @ =sSecondarySpriteStats
	mov r5, ip
	ldrb r0, [r5, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	mov r0, ip
	adds r0, #0x24
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x22
	movs r0, #3
	strb r0, [r1]
	ldr r0, _0803DDA8 @ =0x08356B84
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r3, [r5, #0x16]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0803DDB0
	ldr r0, _0803DDAC @ =0x0000FFE8
	strh r0, [r5, #0xe]
	movs r0, #0x18
	strh r0, [r5, #0x10]
	b _0803DDBA
	.align 2, 0
_0803DD98: .4byte gCurrentSprite
_0803DD9C: .4byte gSpriteData
_0803DDA0: .4byte 0x0000FFE0
_0803DDA4: .4byte sSecondarySpriteStats
_0803DDA8: .4byte 0x08356B84
_0803DDAC: .4byte 0x0000FFE8
_0803DDB0:
	ldr r0, _0803DDC0 @ =0x0000FFC8
	mov r1, ip
	strh r0, [r1, #0xe]
	movs r0, #0x38
	strh r0, [r1, #0x10]
_0803DDBA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803DDC0: .4byte 0x0000FFC8

	thumb_func_start EvirCollisionIdle
EvirCollisionIdle: @ 0x0803DDC4
	push {r4, r5, r6, r7, lr}
	ldr r3, _0803DDF4 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r5, [r0]
	ldr r2, _0803DDF8 @ =gSpriteData
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r6, #0x80
	lsls r6, r6, #6
	adds r0, r6, #0
	ands r0, r1
	adds r4, r3, #0
	adds r7, r2, #0
	cmp r0, #0
	beq _0803DDFC
	ldrh r1, [r4]
	adds r0, r6, #0
	orrs r0, r1
	b _0803DE02
	.align 2, 0
_0803DDF4: .4byte gCurrentSprite
_0803DDF8: .4byte gSpriteData
_0803DDFC:
	ldrh r1, [r4]
	ldr r0, _0803DE48 @ =0x0000DFFF
	ands r0, r1
_0803DE02:
	strh r0, [r4]
	ldrh r6, [r4, #0x14]
	lsls r3, r5, #3
	cmp r6, #0
	bne _0803DE4C
	subs r0, r3, r5
	lsls r0, r0, #3
	adds r0, r0, r7
	mov ip, r0
	mov r1, ip
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x56
	bhi _0803DE4C
	movs r0, #0x57
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0
	mov r0, ip
	strh r6, [r0, #0x14]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x10
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x32
	strb r3, [r0]
	subs r0, #0x12
	strb r3, [r0]
	strh r6, [r4]
	b _0803DEC6
	.align 2, 0
_0803DE48: .4byte 0x0000DFFF
_0803DE4C:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _0803DE74
	subs r0, r3, r5
	lsls r0, r0, #3
	adds r2, r0, r7
	ldrh r0, [r2, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803DE6E
	ldrh r0, [r2, #4]
	subs r0, #0x18
	b _0803DE82
_0803DE6E:
	ldrh r0, [r2, #4]
	adds r0, #0x18
	b _0803DE82
_0803DE74:
	subs r0, r3, r5
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrh r1, [r0, #2]
	subs r1, #0x60
	strh r1, [r4, #2]
	ldrh r0, [r0, #4]
_0803DE82:
	strh r0, [r4, #4]
	subs r0, r3, r5
	lsls r0, r0, #3
	adds r0, r0, r7
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x58
	bgt _0803DE9A
	cmp r0, #0x57
	blt _0803DE9A
	movs r0, #0
	b _0803DEC4
_0803DE9A:
	subs r0, r3, r5
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0803DEBE
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	orrs r0, r1
	b _0803DEC4
_0803DEBE:
	ldrh r1, [r4]
	ldr r0, _0803DECC @ =0x00007FFF
	ands r0, r1
_0803DEC4:
	strh r0, [r4]
_0803DEC6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DECC: .4byte 0x00007FFF

	thumb_func_start EvirProjectileInit
EvirProjectileInit: @ 0x0803DED0
	push {r4, r5, lr}
	ldr r0, _0803DF44 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x26
	movs r4, #0
	movs r3, #1
	strb r3, [r0]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r2, #0
	ldr r1, _0803DF48 @ =0x0000FFF4
	mov r5, ip
	strh r1, [r5, #0xa]
	movs r0, #0xc
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	ldr r0, _0803DF4C @ =0x08356B84
	str r0, [r5, #0x18]
	strb r2, [r5, #0x1c]
	strh r4, [r5, #0x16]
	movs r1, #0x40
	movs r0, #0x40
	strh r0, [r5, #0x12]
	mov r0, ip
	adds r0, #0x2f
	strb r1, [r0]
	subs r0, #0xb
	strb r3, [r0]
	mov r1, ip
	adds r1, #0x25
	movs r0, #4
	strb r0, [r1]
	subs r1, #3
	movs r0, #3
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x21
	strb r3, [r0]
	ldrh r0, [r5, #2]
	strh r0, [r5, #6]
	ldrh r0, [r5, #4]
	strh r0, [r5, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803DF44: .4byte gCurrentSprite
_0803DF48: .4byte 0x0000FFF4
_0803DF4C: .4byte 0x08356B84

	thumb_func_start EvirProjectileMovingInit
EvirProjectileMovingInit: @ 0x0803DF50
	ldr r1, _0803DF70 @ =gCurrentSprite
	ldr r2, _0803DF74 @ =sSecondarySpriteStats
	ldrb r0, [r1, #0x1d]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1, #0x14]
	ldrh r2, [r1]
	ldr r0, _0803DF78 @ =0x0000FFFB
	ands r0, r2
	strh r0, [r1]
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803DF70: .4byte gCurrentSprite
_0803DF74: .4byte sSecondarySpriteStats
_0803DF78: .4byte 0x0000FFFB

	thumb_func_start EvirProjectileMoving
EvirProjectileMoving: @ 0x0803DF7C
	push {r4, r5, r6, lr}
	ldr r1, _0803DF90 @ =gCurrentSprite
	ldrh r0, [r1, #0x14]
	adds r3, r1, #0
	cmp r0, #0
	bne _0803DF94
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _0803E062
	.align 2, 0
_0803DF90: .4byte gCurrentSprite
_0803DF94:
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803DFA6
	strh r0, [r3]
	b _0803E062
_0803DFA6:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803DFB8
	adds r1, r3, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	subs r0, #4
	b _0803DFC0
_0803DFB8:
	adds r1, r3, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #4
_0803DFC0:
	strb r0, [r1]
	ldr r0, _0803E008 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803DFD4
	ldrh r0, [r3, #0x12]
	adds r0, #1
	strh r0, [r3, #0x12]
_0803DFD4:
	ldrh r4, [r3, #0x12]
	adds r0, r3, #0
	adds r0, #0x2f
	ldrb r5, [r0]
	ldr r1, _0803E00C @ =0x080A4FA4
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	adds r6, r1, #0
	cmp r2, #0
	bge _0803E010
	rsbs r2, r2, #0
	lsls r1, r4, #0x10
	asrs r0, r1, #0x10
	muls r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	bge _0803DFFC
	adds r0, #0xff
_0803DFFC:
	lsls r0, r0, #8
	lsrs r2, r0, #0x10
	ldrh r0, [r3, #6]
	subs r0, r0, r2
	b _0803E026
	.align 2, 0
_0803E008: .4byte gFrameCounter8Bit
_0803E00C: .4byte 0x080A4FA4
_0803E010:
	lsls r1, r4, #0x10
	asrs r0, r1, #0x10
	muls r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	bge _0803E01E
	adds r0, #0xff
_0803E01E:
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	ldrh r1, [r3, #6]
	adds r0, r0, r1
_0803E026:
	strh r0, [r3, #2]
	adds r0, r5, #0
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bge _0803E04E
	rsbs r1, r1, #0
	asrs r0, r4, #0x10
	muls r0, r1, r0
	cmp r0, #0
	bge _0803E044
	adds r0, #0xff
_0803E044:
	lsls r0, r0, #8
	lsrs r1, r0, #0x10
	ldrh r0, [r3, #8]
	subs r0, r0, r1
	b _0803E060
_0803E04E:
	asrs r0, r4, #0x10
	muls r0, r1, r0
	cmp r0, #0
	bge _0803E058
	adds r0, #0xff
_0803E058:
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	ldrh r6, [r3, #8]
	adds r0, r0, r6
_0803E060:
	strh r0, [r3, #4]
_0803E062:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start EvirProjectileExplodingInit
EvirProjectileExplodingInit: @ 0x0803E068
	ldr r3, _0803E09C @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	subs r1, #2
	movs r0, #0x38
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x25
	strb r2, [r0]
	ldr r0, _0803E0A0 @ =0x08356BAC
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x27
	movs r1, #0x18
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803E09C: .4byte gCurrentSprite
_0803E0A0: .4byte 0x08356BAC

	thumb_func_start EvirProjectileExploding
EvirProjectileExploding: @ 0x0803E0A4
	push {r4, lr}
	ldr r4, _0803E0C4 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803E0BC
	movs r0, #0
	strh r0, [r4]
_0803E0BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E0C4: .4byte gCurrentSprite

	thumb_func_start Evir
Evir: @ 0x0803E0C8
	push {r4, lr}
	ldr r4, _0803E100 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803E0E2
	movs r0, #0xd6
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803E0E2:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E104
	bl SpriteUtilUpdateFreezeTimer
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x3b
	bl SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent
	b _0803E2E6
	.align 2, 0
_0803E100: .4byte gCurrentSprite
_0803E104:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803E110
	b _0803E2E6
_0803E110:
	lsls r0, r0, #2
	ldr r1, _0803E11C @ =_0803E120
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803E11C: .4byte _0803E120
_0803E120: @ jump table
	.4byte _0803E290 @ case 0
	.4byte _0803E296 @ case 1
	.4byte _0803E29A @ case 2
	.4byte _0803E2AA @ case 3
	.4byte _0803E2AE @ case 4
	.4byte _0803E2B4 @ case 5
	.4byte _0803E2E6 @ case 6
	.4byte _0803E2E6 @ case 7
	.4byte _0803E2E6 @ case 8
	.4byte _0803E2E6 @ case 9
	.4byte _0803E2E6 @ case 10
	.4byte _0803E2E6 @ case 11
	.4byte _0803E2E6 @ case 12
	.4byte _0803E2E6 @ case 13
	.4byte _0803E2E6 @ case 14
	.4byte _0803E2E6 @ case 15
	.4byte _0803E2E6 @ case 16
	.4byte _0803E2E6 @ case 17
	.4byte _0803E2E6 @ case 18
	.4byte _0803E2E6 @ case 19
	.4byte _0803E2E6 @ case 20
	.4byte _0803E2E6 @ case 21
	.4byte _0803E2E6 @ case 22
	.4byte _0803E2E6 @ case 23
	.4byte _0803E2E6 @ case 24
	.4byte _0803E2E6 @ case 25
	.4byte _0803E2E6 @ case 26
	.4byte _0803E2E6 @ case 27
	.4byte _0803E2E6 @ case 28
	.4byte _0803E2E6 @ case 29
	.4byte _0803E2E6 @ case 30
	.4byte _0803E2E6 @ case 31
	.4byte _0803E2E6 @ case 32
	.4byte _0803E2E6 @ case 33
	.4byte _0803E2E6 @ case 34
	.4byte _0803E2E6 @ case 35
	.4byte _0803E2E6 @ case 36
	.4byte _0803E2E6 @ case 37
	.4byte _0803E2E6 @ case 38
	.4byte _0803E2E6 @ case 39
	.4byte _0803E2E6 @ case 40
	.4byte _0803E2A0 @ case 41
	.4byte _0803E2A4 @ case 42
	.4byte _0803E2E6 @ case 43
	.4byte _0803E2E6 @ case 44
	.4byte _0803E2E6 @ case 45
	.4byte _0803E2E6 @ case 46
	.4byte _0803E2E6 @ case 47
	.4byte _0803E2E6 @ case 48
	.4byte _0803E2E6 @ case 49
	.4byte _0803E2E6 @ case 50
	.4byte _0803E2E6 @ case 51
	.4byte _0803E2E6 @ case 52
	.4byte _0803E2E6 @ case 53
	.4byte _0803E2E6 @ case 54
	.4byte _0803E2E6 @ case 55
	.4byte _0803E2E6 @ case 56
	.4byte _0803E2E6 @ case 57
	.4byte _0803E2E6 @ case 58
	.4byte _0803E2E6 @ case 59
	.4byte _0803E2E6 @ case 60
	.4byte _0803E2E6 @ case 61
	.4byte _0803E2E6 @ case 62
	.4byte _0803E2E6 @ case 63
	.4byte _0803E2E6 @ case 64
	.4byte _0803E2E6 @ case 65
	.4byte _0803E2E6 @ case 66
	.4byte _0803E2E6 @ case 67
	.4byte _0803E2E6 @ case 68
	.4byte _0803E2E6 @ case 69
	.4byte _0803E2E6 @ case 70
	.4byte _0803E2E6 @ case 71
	.4byte _0803E2E6 @ case 72
	.4byte _0803E2E6 @ case 73
	.4byte _0803E2E6 @ case 74
	.4byte _0803E2E6 @ case 75
	.4byte _0803E2E6 @ case 76
	.4byte _0803E2E6 @ case 77
	.4byte _0803E2E6 @ case 78
	.4byte _0803E2E6 @ case 79
	.4byte _0803E2E6 @ case 80
	.4byte _0803E2E6 @ case 81
	.4byte _0803E2E6 @ case 82
	.4byte _0803E2E6 @ case 83
	.4byte _0803E2E6 @ case 84
	.4byte _0803E2E6 @ case 85
	.4byte _0803E2E6 @ case 86
	.4byte _0803E2BA @ case 87
	.4byte _0803E2CA @ case 88
	.4byte _0803E2D4 @ case 89
	.4byte _0803E2D8 @ case 90
	.4byte _0803E2DE @ case 91
_0803E290:
	bl EvirInit
	b _0803E2E6
_0803E296:
	bl EvirIdleInit
_0803E29A:
	bl EvirIdle
	b _0803E2E6
_0803E2A0:
	bl EvirShootingInit
_0803E2A4:
	bl EvirShooting
	b _0803E2E6
_0803E2AA:
	bl EvirTurningAroundInit
_0803E2AE:
	bl EvirTurningAround
	b _0803E2E6
_0803E2B4:
	bl EvirTurningAroundSecondPart
	b _0803E2E6
_0803E2BA:
	ldr r0, _0803E2D0 @ =gCurrentSprite
	adds r0, #0x23
	ldrb r1, [r0]
	movs r0, #0x3b
	bl SpriteUtilUnfreezeSecondarySprites
	bl SpriteDyingInit
_0803E2CA:
	bl SpriteDying
	b _0803E2E6
	.align 2, 0
_0803E2D0: .4byte gCurrentSprite
_0803E2D4:
	bl EvirInit
_0803E2D8:
	bl EvirSpawningFromX
	b _0803E2E6
_0803E2DE:
	bl EvirTurningIntoX
	bl XParasiteInit
_0803E2E6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start EvirCollision
EvirCollision: @ 0x0803E2EC
	push {r4, r5, r6, r7, lr}
	ldr r7, _0803E350 @ =gSpriteData
	ldr r3, _0803E354 @ =gCurrentSprite
	movs r0, #0x23
	adds r0, r0, r3
	mov ip, r0
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	adds r5, r0, #0
	adds r5, #0x2c
	ldrb r4, [r5]
	movs r0, #0x7f
	adds r6, r3, #0
	adds r6, #0x2c
	ldrb r2, [r6]
	adds r1, r0, #0
	ands r1, r4
	ands r0, r2
	cmp r1, r0
	bhs _0803E33C
	movs r0, #0x80
	ands r0, r4
	strb r0, [r5]
	mov r1, ip
	ldrb r0, [r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r7
	adds r1, #0x2c
	ldrb r0, [r6]
	adds r0, #1
	movs r2, #0x7f
	ands r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
_0803E33C:
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E358
	bl SpriteUtilUpdateFreezeTimer
	bl SpriteUtilUpdatePrimarySpriteFreezeTimerOfCurrent
	b _0803E36A
	.align 2, 0
_0803E350: .4byte gSpriteData
_0803E354: .4byte gCurrentSprite
_0803E358:
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803E366
	bl EvirCollisionInit
_0803E366:
	bl EvirCollisionIdle
_0803E36A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start EvirProjectile
EvirProjectile: @ 0x0803E370
	push {lr}
	ldr r0, _0803E388 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	beq _0803E39C
	cmp r0, #1
	bgt _0803E38C
	cmp r0, #0
	beq _0803E396
	b _0803E3AC
	.align 2, 0
_0803E388: .4byte gCurrentSprite
_0803E38C:
	cmp r0, #2
	beq _0803E3A0
	cmp r0, #0x38
	beq _0803E3A6
	b _0803E3AC
_0803E396:
	bl EvirProjectileInit
	b _0803E3B0
_0803E39C:
	bl EvirProjectileMovingInit
_0803E3A0:
	bl EvirProjectileMoving
	b _0803E3B0
_0803E3A6:
	bl EvirProjectileExploding
	b _0803E3B0
_0803E3AC:
	bl EvirProjectileExplodingInit
_0803E3B0:
	pop {r0}
	bx r0

	thumb_func_start BullInit
BullInit: @ 0x0803E3B4
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0803E3E0 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803E3E4
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803E3E4
	strh r0, [r2]
	b _0803E474
	.align 2, 0
_0803E3E0: .4byte gCurrentSprite
_0803E3E4:
	ldr r4, _0803E45C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x27
	movs r2, #0
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r5, #0
	ldr r1, _0803E460 @ =0x0000FFE0
	strh r1, [r4, #0xa]
	movs r0, #0x20
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _0803E464 @ =0x08357540
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r2, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x2f
	strb r5, [r0]
	ldr r2, _0803E468 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	bl SpriteUtilChooseRandomXFlip
	bl SpriteUtilChooseRandomXDirection
	ldr r0, _0803E46C @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #8
	bls _0803E448
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
_0803E448:
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803E470
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _0803E474
	.align 2, 0
_0803E45C: .4byte gCurrentSprite
_0803E460: .4byte 0x0000FFE0
_0803E464: .4byte 0x08357540
_0803E468: .4byte sPrimarySpriteStats
_0803E46C: .4byte gSpriteRandomNumber
_0803E470:
	movs r0, #1
	strb r0, [r1]
_0803E474:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BullIdleInit
BullIdleInit: @ 0x0803E47C
	ldr r0, _0803E498 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r3, #0
	movs r1, #2
	strb r1, [r2]
	ldr r1, _0803E49C @ =0x08357540
	str r1, [r0, #0x18]
	strb r3, [r0, #0x1c]
	strh r3, [r0, #0x16]
	adds r0, #0x2e
	movs r1, #3
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803E498: .4byte gCurrentSprite
_0803E49C: .4byte 0x08357540

	thumb_func_start BullIdle
BullIdle: @ 0x0803E4A0
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r4, _0803E4EC @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E4B8
	b _0803E5BC
_0803E4B8:
	movs r0, #3
	strb r0, [r1]
	ldrh r1, [r4]
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803E4FE
	ldrh r0, [r4, #2]
	movs r2, #0x10
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803E4F0 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803E4F8
	ldrh r1, [r4]
	ldr r0, _0803E4F4 @ =0x0000FDFF
	ands r0, r1
	b _0803E51E
	.align 2, 0
_0803E4EC: .4byte gCurrentSprite
_0803E4F0: .4byte gPreviousCollisionCheck
_0803E4F4: .4byte 0x0000FDFF
_0803E4F8:
	ldrh r0, [r4, #4]
	adds r0, #4
	b _0803E52C
_0803E4FE:
	ldrh r0, [r4, #2]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803E524 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803E528
	ldrh r1, [r4]
	adds r0, r6, #0
	orrs r0, r1
_0803E51E:
	strh r0, [r4]
	movs r5, #1
	b _0803E52E
	.align 2, 0
_0803E524: .4byte gPreviousCollisionCheck
_0803E528:
	ldrh r0, [r4, #4]
	subs r0, #4
_0803E52C:
	strh r0, [r4, #4]
_0803E52E:
	ldr r4, _0803E560 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r6, #0x80
	lsls r6, r6, #3
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803E572
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803E564 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803E56C
	ldrh r0, [r4]
	ldr r1, _0803E568 @ =0x0000FBFF
	ands r1, r0
	b _0803E592
	.align 2, 0
_0803E560: .4byte gCurrentSprite
_0803E564: .4byte gPreviousCollisionCheck
_0803E568: .4byte 0x0000FBFF
_0803E56C:
	ldrh r0, [r4, #2]
	subs r0, #4
	b _0803E5A4
_0803E572:
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803E59C @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803E5A0
	ldrh r0, [r4]
	adds r1, r6, #0
	orrs r1, r0
_0803E592:
	strh r1, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0803E5A6
	.align 2, 0
_0803E59C: .4byte gPreviousCollisionCheck
_0803E5A0:
	ldrh r0, [r4, #2]
	adds r0, #4
_0803E5A4:
	strh r0, [r4, #2]
_0803E5A6:
	cmp r5, #0
	beq _0803E5BC
	ldr r0, _0803E5C4 @ =gCurrentSprite
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803E5BC
	ldr r0, _0803E5C8 @ =0x00000199
	bl SoundPlayNotAlreadyPlaying
_0803E5BC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803E5C4: .4byte gCurrentSprite
_0803E5C8: .4byte 0x00000199

	thumb_func_start Bull
Bull: @ 0x0803E5CC
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _0803E5E4 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E5E8
	bl SpriteUtilUpdateFreezeTimer
	b _0803E68E
	.align 2, 0
_0803E5E4: .4byte gCurrentSprite
_0803E5E8:
	mov r0, ip
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803E62C
	mov r0, ip
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E62C
	mov r0, ip
	adds r0, #0x2f
	ldrb r1, [r0]
	cmp r1, #0
	bne _0803E62C
	mov r4, ip
	ldrb r2, [r4, #0x1f]
	subs r0, #0xc
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0x3d
	movs r1, #0
	bl SpriteSpawnSecondary
	movs r0, #0xcd
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803E62C:
	ldr r0, _0803E648 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x57
	beq _0803E676
	cmp r0, #0x57
	bgt _0803E652
	cmp r0, #1
	beq _0803E66A
	cmp r0, #1
	bgt _0803E64C
	cmp r0, #0
	beq _0803E664
	b _0803E68E
	.align 2, 0
_0803E648: .4byte gCurrentSprite
_0803E64C:
	cmp r0, #2
	beq _0803E670
	b _0803E68E
_0803E652:
	cmp r0, #0x59
	beq _0803E680
	cmp r0, #0x59
	blt _0803E67A
	cmp r0, #0x5a
	beq _0803E684
	cmp r0, #0x5b
	beq _0803E68A
	b _0803E68E
_0803E664:
	bl BullInit
	b _0803E68E
_0803E66A:
	bl BullIdleInit
	b _0803E68E
_0803E670:
	bl BullIdle
	b _0803E68E
_0803E676:
	bl SpriteDyingInit
_0803E67A:
	bl SpriteDying
	b _0803E68E
_0803E680:
	bl BullInit
_0803E684:
	bl SpriteSpawningFromX
	b _0803E68E
_0803E68A:
	bl XParasiteInit
_0803E68E:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BullSmoke
BullSmoke: @ 0x0803E698
	push {r4, r5, r6, r7, lr}
	ldr r4, _0803E70C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r5, [r0]
	adds r7, r5, #0
	movs r0, #0x24
	adds r0, r0, r4
	mov ip, r0
	ldrb r6, [r0]
	cmp r6, #0
	bne _0803E720
	ldrh r1, [r4]
	ldr r0, _0803E710 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r4]
	adds r0, r4, #0
	adds r0, #0x21
	movs r3, #1
	strb r3, [r0]
	adds r2, r4, #0
	adds r2, #0x22
	movs r0, #3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x25
	movs r2, #2
	strb r2, [r0]
	ldr r0, _0803E714 @ =0x08357568
	str r0, [r4, #0x18]
	strb r1, [r4, #0x1c]
	strh r6, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #0x28
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _0803E718 @ =0x0000FF80
	strh r1, [r4, #0xa]
	movs r0, #0x80
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r0, ip
	strb r2, [r0]
	ldr r1, _0803E71C @ =gSpriteData
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x2f
	strb r3, [r0]
	b _0803E750
	.align 2, 0
_0803E70C: .4byte gCurrentSprite
_0803E710: .4byte 0x0000FFFB
_0803E714: .4byte 0x08357568
_0803E718: .4byte 0x0000FF80
_0803E71C: .4byte gSpriteData
_0803E720:
	ldrh r0, [r4, #0x16]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0803E734
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
_0803E734:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803E750
	movs r2, #0
	movs r0, #0
	strh r0, [r4]
	ldr r1, _0803E758 @ =gSpriteData
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0x2f
	strb r2, [r0]
_0803E750:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E758: .4byte gSpriteData

	thumb_func_start MemuInit
MemuInit: @ 0x0803E75C
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0803E788 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803E78C
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803E78C
	strh r0, [r2]
	b _0803E814
	.align 2, 0
_0803E788: .4byte gCurrentSprite
_0803E78C:
	ldr r4, _0803E7FC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x27
	movs r2, #0
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r5, #0
	ldr r1, _0803E800 @ =0x0000FFE0
	strh r1, [r4, #0xa]
	movs r0, #0x20
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _0803E804 @ =0x08357F14
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r2, [r4, #0x16]
	ldr r2, _0803E808 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	bl SpriteUtilChooseRandomXDirection
	ldr r0, _0803E80C @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #8
	bls _0803E7E6
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
_0803E7E6:
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803E810
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r4, #6]
	b _0803E814
	.align 2, 0
_0803E7FC: .4byte gCurrentSprite
_0803E800: .4byte 0x0000FFE0
_0803E804: .4byte 0x08357F14
_0803E808: .4byte sPrimarySpriteStats
_0803E80C: .4byte gSpriteRandomNumber
_0803E810:
	movs r0, #1
	strb r0, [r1]
_0803E814:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MemuIdleInit
MemuIdleInit: @ 0x0803E81C
	ldr r2, _0803E838 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0803E83C @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x18
	adds r1, #0xc
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803E838: .4byte gCurrentSprite
_0803E83C: .4byte gSpriteRandomNumber

	thumb_func_start MemuIdle
MemuIdle: @ 0x0803E840
	push {r4, r5, r6, r7, lr}
	ldr r4, _0803E8B8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0803E8B0
	adds r5, r4, #0
	adds r5, #0x31
	ldrb r1, [r5]
	ldr r3, _0803E8BC @ =0x083575B0
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r6, _0803E8C0 @ =0x00007FFF
	cmp r0, r6
	bne _0803E86C
	ldrh r2, [r3]
	movs r1, #0
_0803E86C:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r1, [r5]
	ldr r3, _0803E8C4 @ =0x08357632
	lsls r0, r1, #1
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	bne _0803E890
	ldrh r2, [r3]
	movs r1, #0
_0803E890:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r1, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	beq _0803E8B0
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
_0803E8B0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E8B8: .4byte gCurrentSprite
_0803E8BC: .4byte 0x083575B0
_0803E8C0: .4byte 0x00007FFF
_0803E8C4: .4byte 0x08357632

	thumb_func_start MemuChasingSamusInit
MemuChasingSamusInit: @ 0x0803E8C8
	push {r4, r5, lr}
	ldr r4, _0803E920 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2f
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #2
	strb r2, [r0]
	adds r0, #3
	strb r1, [r0]
	ldr r0, _0803E924 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	movs r5, #0
	strh r0, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0xc
	strh r0, [r4, #0x12]
	ldr r0, _0803E928 @ =0x08357F3C
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r2, [r4, #0x16]
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldrh r2, [r4, #2]
	ldr r1, _0803E92C @ =gSamusData
	movs r3, #0x26
	ldrsh r0, [r1, r3]
	ldrh r1, [r1, #0x18]
	adds r0, r0, r1
	cmp r2, r0
	ble _0803E934
	ldrh r1, [r4]
	ldr r0, _0803E930 @ =0x0000FBFF
	ands r0, r1
	b _0803E93E
	.align 2, 0
_0803E920: .4byte gCurrentSprite
_0803E924: .4byte gSpriteRandomNumber
_0803E928: .4byte 0x08357F3C
_0803E92C: .4byte gSamusData
_0803E930: .4byte 0x0000FBFF
_0803E934:
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
_0803E93E:
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MemuChasingSamus
MemuChasingSamus: @ 0x0803E948
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0803E9D4 @ =gCurrentSprite
	ldrh r1, [r0, #2]
	mov ip, r1
	ldrh r3, [r0, #4]
	mov r8, r3
	movs r5, #0x18
	adds r0, #0x23
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x17
	bhi _0803EA22
	ldr r0, _0803E9D8 @ =gSpriteData
	mov sb, r0
_0803E96E:
	lsls r2, r4, #3
	subs r0, r2, r4
	lsls r0, r0, #3
	mov r1, sb
	adds r3, r0, r1
	ldrh r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803EA18
	adds r0, r3, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0803EA18
	ldrb r0, [r3, #0x1d]
	cmp r0, #0x70
	bne _0803EA18
	ldrh r7, [r3, #2]
	ldrh r6, [r3, #4]
	mov r0, ip
	adds r1, r0, r5
	subs r0, r7, r5
	cmp r1, r0
	ble _0803EA18
	mov r0, ip
	subs r1, r0, r5
	adds r0, r7, r5
	cmp r1, r0
	bge _0803EA18
	mov r0, r8
	adds r1, r0, r5
	subs r0, r6, r5
	cmp r1, r0
	ble _0803EA18
	mov r0, r8
	subs r1, r0, r5
	adds r0, r6, r5
	cmp r1, r0
	bge _0803EA18
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803EA22
	cmp ip, r7
	bls _0803E9DC
	subs r0, r7, #4
	b _0803E9DE
	.align 2, 0
_0803E9D4: .4byte gCurrentSprite
_0803E9D8: .4byte gSpriteData
_0803E9DC:
	adds r0, r7, #4
_0803E9DE:
	strh r0, [r3, #2]
	cmp r8, r6
	bls _0803E9F0
	subs r1, r2, r4
	lsls r1, r1, #3
	add r1, sb
	ldrh r0, [r1, #4]
	subs r0, #4
	b _0803E9FA
_0803E9F0:
	subs r1, r2, r4
	lsls r1, r1, #3
	add r1, sb
	ldrh r0, [r1, #4]
	adds r0, #4
_0803E9FA:
	strh r0, [r1, #4]
	subs r2, r2, r4
	lsls r2, r2, #3
	add r2, sb
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r3, #0
	eors r1, r0
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	eors r1, r0
	strh r1, [r2]
	b _0803EA22
_0803EA18:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x17
	bls _0803E96E
_0803EA22:
	ldr r4, _0803EA3C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803EA40
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	b _0803EA46
	.align 2, 0
_0803EA3C: .4byte gCurrentSprite
_0803EA40:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
_0803EA46:
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803EA70 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0803EA5A
	ldrh r1, [r4]
	adds r0, r5, #0
	eors r0, r1
	strh r0, [r4]
_0803EA5A:
	ldr r4, _0803EA74 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0803EA78
	ldrh r0, [r4, #2]
	adds r0, #0x20
	b _0803EA7C
	.align 2, 0
_0803EA70: .4byte gPreviousCollisionCheck
_0803EA74: .4byte gCurrentSprite
_0803EA78:
	ldrh r0, [r4, #2]
	subs r0, #0x20
_0803EA7C:
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803EAE0 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0803EA92
	ldrh r1, [r4]
	adds r0, r5, #0
	eors r0, r1
	strh r0, [r4]
_0803EA92:
	ldr r0, _0803EAE4 @ =gSamusData
	ldrh r1, [r0, #0x18]
	subs r1, #0x48
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldrh r6, [r0, #0x16]
	movs r0, #4
	mov r8, r0
	ldr r1, _0803EAE8 @ =gCurrentSprite
	ldrh r4, [r1]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ands r0, r4
	adds r2, r1, #0
	cmp r0, #0
	beq _0803EB0C
	adds r3, r2, #0
	adds r3, #0x2f
	ldrb r0, [r3]
	cmp r0, #0
	bne _0803EAEC
	ldrh r1, [r2, #4]
	subs r0, r6, #4
	cmp r1, r0
	bgt _0803EB1E
	adds r1, r2, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #3
	bhi _0803EAD4
	adds r0, #1
	strb r0, [r1]
_0803EAD4:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	b _0803EB60
	.align 2, 0
_0803EAE0: .4byte gPreviousCollisionCheck
_0803EAE4: .4byte gSamusData
_0803EAE8: .4byte gCurrentSprite
_0803EAEC:
	subs r1, r0, #1
	strb r1, [r3]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0803EB00
	lsrs r0, r0, #0x1a
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	b _0803EB60
_0803EB00:
	ldr r0, _0803EB08 @ =0x0000FDFF
	ands r0, r4
	b _0803EB56
	.align 2, 0
_0803EB08: .4byte 0x0000FDFF
_0803EB0C:
	adds r3, r2, #0
	adds r3, #0x2f
	ldrb r0, [r3]
	cmp r0, #0
	bne _0803EB3C
	ldrh r1, [r2, #4]
	adds r0, r6, #4
	cmp r1, r0
	bge _0803EB28
_0803EB1E:
	adds r0, r2, #0
	adds r0, #0x30
	ldrb r0, [r0]
	strb r0, [r3]
	b _0803EB60
_0803EB28:
	adds r1, r2, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #3
	bhi _0803EB36
	adds r0, #1
	strb r0, [r1]
_0803EB36:
	ldrb r1, [r1]
	lsrs r1, r1, #2
	b _0803EB4A
_0803EB3C:
	subs r1, r0, #1
	strb r1, [r3]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0803EB52
	adds r1, r0, #0
	lsrs r1, r1, #0x1a
_0803EB4A:
	ldrh r0, [r2, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	b _0803EB60
_0803EB52:
	adds r0, r5, #0
	orrs r0, r4
_0803EB56:
	strh r0, [r2]
	adds r1, r2, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
_0803EB60:
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0803EBBC
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	cmp r0, #0
	bne _0803EB9A
	ldrh r1, [r2, #2]
	subs r0, r7, #4
	cmp r1, r0
	bgt _0803EBCE
	adds r1, r2, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, r8
	bhs _0803EB8E
	adds r0, #1
	strb r0, [r1]
_0803EB8E:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _0803EC12
_0803EB9A:
	subs r1, r0, #1
	strb r1, [r3]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0803EBAE
	lsrs r0, r0, #0x1a
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	b _0803EC12
_0803EBAE:
	ldrh r0, [r2]
	ldr r1, _0803EBB8 @ =0x0000FBFF
	ands r1, r0
	b _0803EC08
	.align 2, 0
_0803EBB8: .4byte 0x0000FBFF
_0803EBBC:
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	cmp r0, #0
	bne _0803EBEC
	ldrh r1, [r2, #2]
	adds r0, r7, #4
	cmp r1, r0
	bge _0803EBD8
_0803EBCE:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	strb r0, [r3]
	b _0803EC12
_0803EBD8:
	adds r1, r2, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, r8
	bhs _0803EBE6
	adds r0, #1
	strb r0, [r1]
_0803EBE6:
	ldrb r1, [r1]
	lsrs r1, r1, #2
	b _0803EBFA
_0803EBEC:
	subs r1, r0, #1
	strb r1, [r3]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0803EC02
	adds r1, r0, #0
	lsrs r1, r1, #0x1a
_0803EBFA:
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	b _0803EC12
_0803EC02:
	ldrh r0, [r2]
	adds r1, r4, #0
	orrs r1, r0
_0803EC08:
	strh r1, [r2]
	adds r1, r2, #0
	adds r1, #0x31
	movs r0, #1
	strb r0, [r1]
_0803EC12:
	ldrh r0, [r2, #0x12]
	subs r0, #1
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803EC32
	movs r0, #0xc
	strh r0, [r2, #0x12]
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803EC32
	ldr r0, _0803EC40 @ =0x0000019B
	bl SoundPlayNotAlreadyPlaying
_0803EC32:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EC40: .4byte 0x0000019B

	thumb_func_start Memu
Memu: @ 0x0803EC44
	push {r4, lr}
	ldr r4, _0803EC70 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803EC5E
	movs r0, #0xce
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803EC5E:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803EC74
	bl SpriteUtilUpdateFreezeTimer
	b _0803EE34
	.align 2, 0
_0803EC70: .4byte gCurrentSprite
_0803EC74:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803EC80
	b _0803EE34
_0803EC80:
	lsls r0, r0, #2
	ldr r1, _0803EC8C @ =_0803EC90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803EC8C: .4byte _0803EC90
_0803EC90: @ jump table
	.4byte _0803EE00 @ case 0
	.4byte _0803EE06 @ case 1
	.4byte _0803EE0C @ case 2
	.4byte _0803EE34 @ case 3
	.4byte _0803EE34 @ case 4
	.4byte _0803EE34 @ case 5
	.4byte _0803EE34 @ case 6
	.4byte _0803EE34 @ case 7
	.4byte _0803EE34 @ case 8
	.4byte _0803EE34 @ case 9
	.4byte _0803EE34 @ case 10
	.4byte _0803EE34 @ case 11
	.4byte _0803EE34 @ case 12
	.4byte _0803EE34 @ case 13
	.4byte _0803EE34 @ case 14
	.4byte _0803EE34 @ case 15
	.4byte _0803EE34 @ case 16
	.4byte _0803EE34 @ case 17
	.4byte _0803EE34 @ case 18
	.4byte _0803EE34 @ case 19
	.4byte _0803EE34 @ case 20
	.4byte _0803EE34 @ case 21
	.4byte _0803EE34 @ case 22
	.4byte _0803EE12 @ case 23
	.4byte _0803EE16 @ case 24
	.4byte _0803EE34 @ case 25
	.4byte _0803EE34 @ case 26
	.4byte _0803EE34 @ case 27
	.4byte _0803EE34 @ case 28
	.4byte _0803EE34 @ case 29
	.4byte _0803EE34 @ case 30
	.4byte _0803EE34 @ case 31
	.4byte _0803EE34 @ case 32
	.4byte _0803EE34 @ case 33
	.4byte _0803EE34 @ case 34
	.4byte _0803EE34 @ case 35
	.4byte _0803EE34 @ case 36
	.4byte _0803EE34 @ case 37
	.4byte _0803EE34 @ case 38
	.4byte _0803EE34 @ case 39
	.4byte _0803EE34 @ case 40
	.4byte _0803EE34 @ case 41
	.4byte _0803EE34 @ case 42
	.4byte _0803EE34 @ case 43
	.4byte _0803EE34 @ case 44
	.4byte _0803EE34 @ case 45
	.4byte _0803EE34 @ case 46
	.4byte _0803EE34 @ case 47
	.4byte _0803EE34 @ case 48
	.4byte _0803EE34 @ case 49
	.4byte _0803EE34 @ case 50
	.4byte _0803EE34 @ case 51
	.4byte _0803EE34 @ case 52
	.4byte _0803EE34 @ case 53
	.4byte _0803EE34 @ case 54
	.4byte _0803EE34 @ case 55
	.4byte _0803EE34 @ case 56
	.4byte _0803EE34 @ case 57
	.4byte _0803EE34 @ case 58
	.4byte _0803EE34 @ case 59
	.4byte _0803EE34 @ case 60
	.4byte _0803EE34 @ case 61
	.4byte _0803EE34 @ case 62
	.4byte _0803EE34 @ case 63
	.4byte _0803EE34 @ case 64
	.4byte _0803EE34 @ case 65
	.4byte _0803EE34 @ case 66
	.4byte _0803EE34 @ case 67
	.4byte _0803EE34 @ case 68
	.4byte _0803EE34 @ case 69
	.4byte _0803EE34 @ case 70
	.4byte _0803EE34 @ case 71
	.4byte _0803EE34 @ case 72
	.4byte _0803EE34 @ case 73
	.4byte _0803EE34 @ case 74
	.4byte _0803EE34 @ case 75
	.4byte _0803EE34 @ case 76
	.4byte _0803EE34 @ case 77
	.4byte _0803EE34 @ case 78
	.4byte _0803EE34 @ case 79
	.4byte _0803EE34 @ case 80
	.4byte _0803EE34 @ case 81
	.4byte _0803EE34 @ case 82
	.4byte _0803EE34 @ case 83
	.4byte _0803EE34 @ case 84
	.4byte _0803EE34 @ case 85
	.4byte _0803EE34 @ case 86
	.4byte _0803EE1C @ case 87
	.4byte _0803EE20 @ case 88
	.4byte _0803EE26 @ case 89
	.4byte _0803EE2A @ case 90
	.4byte _0803EE30 @ case 91
_0803EE00:
	bl MemuInit
	b _0803EE34
_0803EE06:
	bl MemuIdleInit
	b _0803EE34
_0803EE0C:
	bl MemuIdle
	b _0803EE34
_0803EE12:
	bl MemuChasingSamusInit
_0803EE16:
	bl MemuChasingSamus
	b _0803EE34
_0803EE1C:
	bl SpriteDyingInit
_0803EE20:
	bl SpriteDying
	b _0803EE34
_0803EE26:
	bl MemuInit
_0803EE2A:
	bl SpriteSpawningFromX
	b _0803EE34
_0803EE30:
	bl XParasiteInit
_0803EE34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GerubossYMovement
GerubossYMovement: @ 0x0803EE3C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r7, r6, #0
	ldr r4, _0803EE80 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803EE88
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803EE84 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803EEAE
	ldrh r0, [r4, #2]
	adds r0, #0x40
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803EEAE
	ldrh r0, [r4, #2]
	adds r0, r6, r0
	b _0803EEBC
	.align 2, 0
_0803EE80: .4byte gCurrentSprite
_0803EE84: .4byte gPreviousCollisionCheck
_0803EE88:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803EEB4 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803EEAE
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803EEB8
_0803EEAE:
	movs r0, #1
	b _0803EEC0
	.align 2, 0
_0803EEB4: .4byte gPreviousCollisionCheck
_0803EEB8:
	ldrh r0, [r4, #2]
	subs r0, r0, r7
_0803EEBC:
	strh r0, [r4, #2]
	movs r0, #0
_0803EEC0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GerubossXMovement
GerubossXMovement: @ 0x0803EEC8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r7, r6, #0
	ldr r4, _0803EF0C @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803EF14
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803EF10 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803EF3A
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803EF3A
	ldrh r0, [r4, #4]
	adds r0, r6, r0
	b _0803EF48
	.align 2, 0
_0803EF0C: .4byte gCurrentSprite
_0803EF10: .4byte gPreviousCollisionCheck
_0803EF14:
	ldrh r0, [r4, #2]
	subs r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803EF40 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803EF3A
	ldrh r0, [r4, #2]
	adds r0, #0x20
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803EF44
_0803EF3A:
	movs r0, #1
	b _0803EF4C
	.align 2, 0
_0803EF40: .4byte gPreviousCollisionCheck
_0803EF44:
	ldrh r0, [r4, #4]
	subs r0, r0, r7
_0803EF48:
	strh r0, [r4, #4]
	movs r0, #0
_0803EF4C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start GerubossTurningIntoX
GerubossTurningIntoX: @ 0x0803EF54
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _0803EF94 @ =gCurrentSprite
	ldrb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #8
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	adds r0, #0x24
	str r0, [sp, #8]
	movs r0, #0x40
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	subs r0, #0x24
	strh r0, [r4, #4]
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EF94: .4byte gCurrentSprite

	thumb_func_start GerubossInit
GerubossInit: @ 0x0803EF98
	push {lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0803EFC4 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803EFC8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803EFC8
	strh r0, [r2]
	b _0803F05A
	.align 2, 0
_0803EFC4: .4byte gCurrentSprite
_0803EFC8:
	bl SpriteUtilMakeSpriteFaceSamusDirection
	ldr r3, _0803F038 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x27
	movs r2, #0
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0
	ldr r0, _0803F03C @ =0x0000FFE0
	strh r0, [r3, #0xa]
	movs r0, #0x30
	strh r0, [r3, #0xc]
	ldr r0, _0803F040 @ =0x0000FFC8
	strh r0, [r3, #0xe]
	movs r0, #0x38
	strh r0, [r3, #0x10]
	ldr r0, _0803F044 @ =0x08358E14
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0803F048 @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	adds r1, r3, #0
	adds r1, #0x21
	strb r0, [r1]
	ldr r2, _0803F04C @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803F050
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r3, #6]
	b _0803F05A
	.align 2, 0
_0803F038: .4byte gCurrentSprite
_0803F03C: .4byte 0x0000FFE0
_0803F040: .4byte 0x0000FFC8
_0803F044: .4byte 0x08358E14
_0803F048: .4byte gIoRegisters
_0803F04C: .4byte sPrimarySpriteStats
_0803F050:
	ldrh r0, [r3, #2]
	subs r0, #0x20
	strh r0, [r3, #2]
	movs r0, #1
	strb r0, [r1]
_0803F05A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start GerubossIdleInit
GerubossIdleInit: @ 0x0803F060
	ldr r0, _0803F07C @ =gCurrentSprite
	adds r3, r0, #0
	adds r3, #0x24
	movs r2, #0
	movs r1, #2
	strb r1, [r3]
	strb r2, [r0, #0x1c]
	strh r2, [r0, #0x16]
	ldr r1, _0803F080 @ =0x08358E14
	str r1, [r0, #0x18]
	adds r0, #0x2e
	movs r1, #0x30
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803F07C: .4byte gCurrentSprite
_0803F080: .4byte 0x08358E14

	thumb_func_start GerubossIdle
GerubossIdle: @ 0x0803F084
	push {r4, r5, lr}
	ldr r4, _0803F0C0 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0803F154
	ldrh r0, [r4, #2]
	subs r0, #0x24
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803F0C4 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803F0C8
	ldrh r0, [r4, #2]
	subs r0, #0x24
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803F0C8
	bl SpriteUtilMakeSpriteFaceSamusDirection
	b _0803F14C
	.align 2, 0
_0803F0C0: .4byte gCurrentSprite
_0803F0C4: .4byte gPreviousCollisionCheck
_0803F0C8:
	ldr r4, _0803F0FC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	beq _0803F104
	adds r2, r4, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #8
	strb r0, [r2]
	strb r1, [r4, #0x1c]
	strh r1, [r4, #0x16]
	ldr r0, _0803F100 @ =0x08358DF4
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0xd0
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
	b _0803F154
	.align 2, 0
_0803F0FC: .4byte gCurrentSprite
_0803F100: .4byte 0x08358DF4
_0803F104:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F112
	subs r0, #1
	b _0803F152
_0803F112:
	ldr r0, _0803F13C @ =gSamusData
	ldrh r0, [r0, #0x18]
	subs r0, #0x48
	ldrh r1, [r4, #2]
	cmp r0, r1
	blt _0803F154
	movs r5, #0x80
	lsls r5, r5, #2
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _0803F140
	ldrh r1, [r4]
	adds r0, r5, #0
	orrs r0, r1
	b _0803F14A
	.align 2, 0
_0803F13C: .4byte gSamusData
_0803F140:
	cmp r0, #4
	bne _0803F154
	ldrh r1, [r4]
	ldr r0, _0803F15C @ =0x0000FDFF
	ands r0, r1
_0803F14A:
	strh r0, [r4]
_0803F14C:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
_0803F152:
	strb r0, [r1]
_0803F154:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F15C: .4byte 0x0000FDFF

	thumb_func_start GerubossStalling
GerubossStalling: @ 0x0803F160
	push {lr}
	ldr r1, _0803F180 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803F17A
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_0803F17A:
	pop {r0}
	bx r0
	.align 2, 0
_0803F180: .4byte gCurrentSprite

	thumb_func_start GerubossLaunchingInit
GerubossLaunchingInit: @ 0x0803F184
	push {lr}
	ldr r1, _0803F1A4 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x2a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803F1A8 @ =0x08358E3C
	str r0, [r1, #0x18]
	ldr r0, _0803F1AC @ =0x0000019D
	bl SoundPlayNotAlreadyPlaying
	pop {r0}
	bx r0
	.align 2, 0
_0803F1A4: .4byte gCurrentSprite
_0803F1A8: .4byte 0x08358E3C
_0803F1AC: .4byte 0x0000019D

	thumb_func_start GerubossCharging
GerubossCharging: @ 0x0803F1B0
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803F1E8
	ldr r1, _0803F1EC @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x2c
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803F1F0 @ =0x08358E6C
	str r0, [r1, #0x18]
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	adds r1, #0x2e
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803F1E8:
	pop {r0}
	bx r0
	.align 2, 0
_0803F1EC: .4byte gCurrentSprite
_0803F1F0: .4byte 0x08358E6C

	thumb_func_start GerubossGoingDown
GerubossGoingDown: @ 0x0803F1F4
	push {r4, lr}
	ldr r2, _0803F220 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F228
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0803F242
	strb r1, [r2, #0x1c]
	movs r0, #0
	strh r1, [r2, #0x16]
	ldr r1, _0803F224 @ =0x08358E8C
	str r1, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0x2f
	strb r0, [r1]
	b _0803F242
	.align 2, 0
_0803F220: .4byte gCurrentSprite
_0803F224: .4byte 0x08358E8C
_0803F228:
	adds r4, r2, #0
	adds r4, #0x2f
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803F23C
	ldr r0, _0803F270 @ =0x0000019F
	bl SoundPlay
_0803F23C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0803F242:
	movs r0, #2
	bl GerubossXMovement
	movs r0, #0xc
	bl GerubossYMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F268
	ldr r1, _0803F274 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x2e
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803F278 @ =0x08358EEC
	str r0, [r1, #0x18]
_0803F268:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F270: .4byte 0x0000019F
_0803F274: .4byte gCurrentSprite
_0803F278: .4byte 0x08358EEC

	thumb_func_start GerubossChagningDirection
GerubossChagningDirection: @ 0x0803F27C
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803F2B0
	ldr r1, _0803F2B4 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x30
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803F2B8 @ =0x08358EAC
	str r0, [r1, #0x18]
	ldrh r2, [r1]
	ldr r0, _0803F2BC @ =0x0000F7FF
	ands r0, r2
	strh r0, [r1]
	adds r1, #0x2e
	movs r0, #0x18
	strb r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803F2B0:
	pop {r0}
	bx r0
	.align 2, 0
_0803F2B4: .4byte gCurrentSprite
_0803F2B8: .4byte 0x08358EAC
_0803F2BC: .4byte 0x0000F7FF

	thumb_func_start GerubossGoingUp
GerubossGoingUp: @ 0x0803F2C0
	push {r4, lr}
	ldr r2, _0803F2EC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803F2F4
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0803F30E
	strb r1, [r2, #0x1c]
	movs r0, #0
	strh r1, [r2, #0x16]
	ldr r1, _0803F2F0 @ =0x08358ECC
	str r1, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0x2f
	strb r0, [r1]
	b _0803F30E
	.align 2, 0
_0803F2EC: .4byte gCurrentSprite
_0803F2F0: .4byte 0x08358ECC
_0803F2F4:
	adds r4, r2, #0
	adds r4, #0x2f
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0803F308
	ldr r0, _0803F33C @ =0x0000019F
	bl SoundPlay
_0803F308:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0803F30E:
	movs r0, #2
	bl GerubossXMovement
	movs r0, #0xc
	bl GerubossYMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F334
	ldr r1, _0803F340 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x32
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803F344 @ =0x08358F3C
	str r0, [r1, #0x18]
_0803F334:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F33C: .4byte 0x0000019F
_0803F340: .4byte gCurrentSprite
_0803F344: .4byte 0x08358F3C

	thumb_func_start GerubossGrabbingCeiling
GerubossGrabbingCeiling: @ 0x0803F348
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803F35A
	ldr r0, _0803F360 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0803F35A:
	pop {r0}
	bx r0
	.align 2, 0
_0803F360: .4byte gCurrentSprite

	thumb_func_start Geruboss
Geruboss: @ 0x0803F364
	push {r4, lr}
	ldr r4, _0803F38C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803F37C
	ldr r0, _0803F390 @ =0x000001A1
	bl SoundPlayNotAlreadyPlaying
_0803F37C:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803F394
	bl SpriteUtilUpdateFreezeTimer
	b _0803F574
	.align 2, 0
_0803F38C: .4byte gCurrentSprite
_0803F390: .4byte 0x000001A1
_0803F394:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803F3A0
	b _0803F574
_0803F3A0:
	lsls r0, r0, #2
	ldr r1, _0803F3AC @ =_0803F3B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803F3AC: .4byte _0803F3B0
_0803F3B0: @ jump table
	.4byte _0803F520 @ case 0
	.4byte _0803F526 @ case 1
	.4byte _0803F52A @ case 2
	.4byte _0803F574 @ case 3
	.4byte _0803F574 @ case 4
	.4byte _0803F574 @ case 5
	.4byte _0803F574 @ case 6
	.4byte _0803F574 @ case 7
	.4byte _0803F530 @ case 8
	.4byte _0803F574 @ case 9
	.4byte _0803F574 @ case 10
	.4byte _0803F574 @ case 11
	.4byte _0803F574 @ case 12
	.4byte _0803F574 @ case 13
	.4byte _0803F574 @ case 14
	.4byte _0803F574 @ case 15
	.4byte _0803F574 @ case 16
	.4byte _0803F574 @ case 17
	.4byte _0803F574 @ case 18
	.4byte _0803F574 @ case 19
	.4byte _0803F574 @ case 20
	.4byte _0803F574 @ case 21
	.4byte _0803F574 @ case 22
	.4byte _0803F574 @ case 23
	.4byte _0803F574 @ case 24
	.4byte _0803F574 @ case 25
	.4byte _0803F574 @ case 26
	.4byte _0803F574 @ case 27
	.4byte _0803F574 @ case 28
	.4byte _0803F574 @ case 29
	.4byte _0803F574 @ case 30
	.4byte _0803F574 @ case 31
	.4byte _0803F574 @ case 32
	.4byte _0803F574 @ case 33
	.4byte _0803F574 @ case 34
	.4byte _0803F574 @ case 35
	.4byte _0803F574 @ case 36
	.4byte _0803F574 @ case 37
	.4byte _0803F574 @ case 38
	.4byte _0803F574 @ case 39
	.4byte _0803F574 @ case 40
	.4byte _0803F536 @ case 41
	.4byte _0803F53A @ case 42
	.4byte _0803F574 @ case 43
	.4byte _0803F540 @ case 44
	.4byte _0803F574 @ case 45
	.4byte _0803F546 @ case 46
	.4byte _0803F574 @ case 47
	.4byte _0803F54C @ case 48
	.4byte _0803F574 @ case 49
	.4byte _0803F552 @ case 50
	.4byte _0803F574 @ case 51
	.4byte _0803F574 @ case 52
	.4byte _0803F574 @ case 53
	.4byte _0803F574 @ case 54
	.4byte _0803F574 @ case 55
	.4byte _0803F574 @ case 56
	.4byte _0803F574 @ case 57
	.4byte _0803F574 @ case 58
	.4byte _0803F574 @ case 59
	.4byte _0803F574 @ case 60
	.4byte _0803F574 @ case 61
	.4byte _0803F574 @ case 62
	.4byte _0803F574 @ case 63
	.4byte _0803F574 @ case 64
	.4byte _0803F574 @ case 65
	.4byte _0803F574 @ case 66
	.4byte _0803F574 @ case 67
	.4byte _0803F574 @ case 68
	.4byte _0803F574 @ case 69
	.4byte _0803F574 @ case 70
	.4byte _0803F574 @ case 71
	.4byte _0803F574 @ case 72
	.4byte _0803F574 @ case 73
	.4byte _0803F574 @ case 74
	.4byte _0803F574 @ case 75
	.4byte _0803F574 @ case 76
	.4byte _0803F574 @ case 77
	.4byte _0803F574 @ case 78
	.4byte _0803F574 @ case 79
	.4byte _0803F574 @ case 80
	.4byte _0803F574 @ case 81
	.4byte _0803F574 @ case 82
	.4byte _0803F574 @ case 83
	.4byte _0803F574 @ case 84
	.4byte _0803F574 @ case 85
	.4byte _0803F574 @ case 86
	.4byte _0803F558 @ case 87
	.4byte _0803F55C @ case 88
	.4byte _0803F562 @ case 89
	.4byte _0803F566 @ case 90
	.4byte _0803F56C @ case 91
_0803F520:
	bl GerubossInit
	b _0803F574
_0803F526:
	bl GerubossIdleInit
_0803F52A:
	bl GerubossIdle
	b _0803F574
_0803F530:
	bl GerubossStalling
	b _0803F574
_0803F536:
	bl GerubossLaunchingInit
_0803F53A:
	bl GerubossCharging
	b _0803F574
_0803F540:
	bl GerubossGoingDown
	b _0803F574
_0803F546:
	bl GerubossChagningDirection
	b _0803F574
_0803F54C:
	bl GerubossGoingUp
	b _0803F574
_0803F552:
	bl GerubossGrabbingCeiling
	b _0803F574
_0803F558:
	bl SpriteDyingInit
_0803F55C:
	bl SpriteDying
	b _0803F574
_0803F562:
	bl GerubossInit
_0803F566:
	bl SpriteSpawningFromX
	b _0803F574
_0803F56C:
	bl GerubossTurningIntoX
	bl XParasiteInit
_0803F574:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ChootSetOpenHitbox
ChootSetOpenHitbox: @ 0x0803F57C
	ldr r1, _0803F590 @ =gCurrentSprite
	ldr r0, _0803F594 @ =0x0000FFE0
	strh r0, [r1, #0xa]
	movs r0, #4
	strh r0, [r1, #0xc]
	ldr r0, _0803F598 @ =0x0000FFC4
	strh r0, [r1, #0xe]
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	bx lr
	.align 2, 0
_0803F590: .4byte gCurrentSprite
_0803F594: .4byte 0x0000FFE0
_0803F598: .4byte 0x0000FFC4

	thumb_func_start ChootSetClosedHitbox
ChootSetClosedHitbox: @ 0x0803F59C
	ldr r1, _0803F5B0 @ =gCurrentSprite
	ldr r0, _0803F5B4 @ =0x0000FFD0
	strh r0, [r1, #0xa]
	movs r0, #0xc
	strh r0, [r1, #0xc]
	ldr r0, _0803F5B8 @ =0x0000FFE0
	strh r0, [r1, #0xe]
	movs r0, #0x20
	strh r0, [r1, #0x10]
	bx lr
	.align 2, 0
_0803F5B0: .4byte gCurrentSprite
_0803F5B4: .4byte 0x0000FFD0
_0803F5B8: .4byte 0x0000FFE0

	thumb_func_start ChootInit
ChootInit: @ 0x0803F5BC
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0803F5E8 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F5EC
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803F5EC
	strh r0, [r2]
	b _0803F650
	.align 2, 0
_0803F5E8: .4byte gCurrentSprite
_0803F5EC:
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	ldr r5, _0803F640 @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x27
	movs r4, #0
	movs r2, #0x10
	strb r2, [r0]
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x29
	strb r2, [r0]
	bl ChootSetOpenHitbox
	ldr r0, _0803F644 @ =0x083598FC
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r4, [r5, #0x16]
	ldr r2, _0803F648 @ =sPrimarySpriteStats
	ldrb r1, [r5, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #2
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803F64C
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r5, #6]
	b _0803F650
	.align 2, 0
_0803F640: .4byte gCurrentSprite
_0803F644: .4byte 0x083598FC
_0803F648: .4byte sPrimarySpriteStats
_0803F64C:
	movs r0, #1
	strb r0, [r1]
_0803F650:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ChootIdleInit
ChootIdleInit: @ 0x0803F658
	ldr r1, _0803F670 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0803F674 @ =0x083598FC
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_0803F670: .4byte gCurrentSprite
_0803F674: .4byte 0x083598FC

	thumb_func_start ChootIdle
ChootIdle: @ 0x0803F678
	push {r4, r5, lr}
	ldr r4, _0803F6D8 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0803F6D2
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803F6DC @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803F6AA
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803F6CA
_0803F6AA:
	ldr r0, _0803F6E0 @ =gSamusData
	ldrh r0, [r0, #0x18]
	subs r0, #0x48
	ldr r4, _0803F6D8 @ =gCurrentSprite
	ldrh r1, [r4, #2]
	cmp r0, r1
	bgt _0803F6D2
	movs r0, #0xa0
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803F6D2
_0803F6CA:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	strb r0, [r1]
_0803F6D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F6D8: .4byte gCurrentSprite
_0803F6DC: .4byte gPreviousCollisionCheck
_0803F6E0: .4byte gSamusData

	thumb_func_start ChootLaunchingInit
ChootLaunchingInit: @ 0x0803F6E4
	ldr r1, _0803F6F8 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	ldr r0, _0803F6FC @ =0x0835990C
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803F6F8: .4byte gCurrentSprite
_0803F6FC: .4byte 0x0835990C

	thumb_func_start ChootLaunching
ChootLaunching: @ 0x0803F700
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803F712
	ldr r0, _0803F718 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2b
	strb r1, [r0]
_0803F712:
	pop {r0}
	bx r0
	.align 2, 0
_0803F718: .4byte gCurrentSprite

	thumb_func_start ChootGoingUpInit
ChootGoingUpInit: @ 0x0803F71C
	push {r4, lr}
	ldr r4, _0803F758 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r4, #0x1c]
	movs r2, #0
	strh r0, [r4, #0x16]
	ldr r0, _0803F75C @ =0x08359924
	str r0, [r4, #0x18]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x31
	strb r2, [r0]
	bl ChootSetClosedHitbox
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F750
	movs r0, #0xd1
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803F750:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F758: .4byte gCurrentSprite
_0803F75C: .4byte 0x08359924

	thumb_func_start ShootGoingUp
ShootGoingUp: @ 0x0803F760
	push {r4, r5, r6, lr}
	ldr r4, _0803F7AC @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0x30
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803F7B0 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803F7A2
	ldrh r0, [r4, #2]
	subs r0, #0x30
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _0803F7A2
	adds r5, r4, #0
	adds r5, #0x31
	ldrb r2, [r5]
	ldr r1, _0803F7B4 @ =0x08358F64
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0803F7B8 @ =0x00007FFF
	cmp r1, r0
	bne _0803F7BC
_0803F7A2:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2d
	strb r0, [r1]
	b _0803F7C6
	.align 2, 0
_0803F7AC: .4byte gCurrentSprite
_0803F7B0: .4byte gPreviousCollisionCheck
_0803F7B4: .4byte 0x08358F64
_0803F7B8: .4byte 0x00007FFF
_0803F7BC:
	adds r0, r2, #1
	strb r0, [r5]
	ldrh r0, [r4, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
_0803F7C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ChootOpeningInit
ChootOpeningInit: @ 0x0803F7CC
	push {lr}
	ldr r1, _0803F7E8 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	ldr r0, _0803F7EC @ =0x08359934
	str r0, [r1, #0x18]
	adds r1, #0x24
	movs r0, #0x2e
	strb r0, [r1]
	bl ChootSetOpenHitbox
	pop {r0}
	bx r0
	.align 2, 0
_0803F7E8: .4byte gCurrentSprite
_0803F7EC: .4byte 0x08359934

	thumb_func_start ChootOpening
ChootOpening: @ 0x0803F7F0
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0803F802
	ldr r0, _0803F808 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2f
	strb r1, [r0]
_0803F802:
	pop {r0}
	bx r0
	.align 2, 0
_0803F808: .4byte gCurrentSprite

	thumb_func_start ChootGoingDownInit
ChootGoingDownInit: @ 0x0803F80C
	ldr r0, _0803F828 @ =gCurrentSprite
	movs r1, #0
	strb r1, [r0, #0x1c]
	movs r3, #0
	strh r1, [r0, #0x16]
	ldr r1, _0803F82C @ =0x0835995C
	str r1, [r0, #0x18]
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0x30
	strb r1, [r2]
	adds r0, #0x2e
	strb r3, [r0]
	bx lr
	.align 2, 0
_0803F828: .4byte gCurrentSprite
_0803F82C: .4byte 0x0835995C

	thumb_func_start ChootGoingDown
ChootGoingDown: @ 0x0803F830
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, _0803F850 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803F854 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803F858
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #1
	b _0803F8B8
	.align 2, 0
_0803F850: .4byte gCurrentSprite
_0803F854: .4byte gPreviousCollisionCheck
_0803F858:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x30
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _0803F870
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #1
	b _0803F8B8
_0803F870:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	movs r1, #0x3f
	ands r1, r0
	cmp r1, #0
	bne _0803F8B0
	ldrb r2, [r4, #0x1f]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r4, #2]
	adds r0, #0x20
	str r0, [sp]
	ldrh r0, [r4, #4]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0x3e
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrh r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803F8B0
	ldr r0, _0803F8C4 @ =0x000001A3
	bl SoundPlayNotAlreadyPlaying
_0803F8B0:
	ldr r1, _0803F8C8 @ =gCurrentSprite
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r0, #1
_0803F8B8:
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F8C4: .4byte 0x000001A3
_0803F8C8: .4byte gCurrentSprite

	thumb_func_start ChootSpitInit
ChootSpitInit: @ 0x0803F8CC
	push {r4, lr}
	ldr r0, _0803F934 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0803F938 @ =0x0000FFFB
	ands r0, r1
	movs r3, #0
	movs r4, #0
	mov r1, ip
	strh r0, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _0803F93C @ =0x0000FFE0
	mov r2, ip
	strh r0, [r2, #0xa]
	strh r4, [r2, #0xc]
	adds r0, #0x10
	strh r0, [r2, #0xe]
	strh r1, [r2, #0x10]
	mov r1, ip
	adds r1, #0x25
	movs r0, #4
	strb r0, [r1]
	subs r1, #3
	movs r0, #3
	strb r0, [r1]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	ldr r0, _0803F940 @ =0x08359984
	str r0, [r2, #0x18]
	adds r1, #0xc
	movs r0, #8
	strb r0, [r1]
	subs r1, #0xa
	movs r0, #2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F934: .4byte gCurrentSprite
_0803F938: .4byte 0x0000FFFB
_0803F93C: .4byte 0x0000FFE0
_0803F940: .4byte 0x08359984

	thumb_func_start ChootSpitSpawning
ChootSpitSpawning: @ 0x0803F944
	push {lr}
	ldr r2, _0803F97C @ =gCurrentSprite
	ldrh r0, [r2, #2]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #2]
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0803F976
	strb r3, [r2, #0x1c]
	strh r0, [r2, #0x16]
	ldr r0, _0803F980 @ =0x08359994
	str r0, [r2, #0x18]
	subs r1, #0xa
	movs r0, #0x16
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x31
	strb r3, [r0]
_0803F976:
	pop {r0}
	bx r0
	.align 2, 0
_0803F97C: .4byte gCurrentSprite
_0803F980: .4byte 0x08359994

	thumb_func_start ChootSpitExplodingInit
ChootSpitExplodingInit: @ 0x0803F984
	push {r4, lr}
	ldr r4, _0803F9A4 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0803F9A8 @ =gPreviousCollisionCheck
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _0803F9B0
	ldr r0, _0803F9AC @ =0x083599CC
	b _0803F9B2
	.align 2, 0
_0803F9A4: .4byte gCurrentSprite
_0803F9A8: .4byte gPreviousCollisionCheck
_0803F9AC: .4byte 0x083599CC
_0803F9B0:
	ldr r0, _0803F9C8 @ =0x083599A4
_0803F9B2:
	str r0, [r4, #0x18]
	ldr r0, _0803F9CC @ =gCurrentSprite
	movs r1, #0
	strb r1, [r0, #0x1c]
	strh r1, [r0, #0x16]
	adds r0, #0x24
	movs r1, #8
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F9C8: .4byte 0x083599A4
_0803F9CC: .4byte gCurrentSprite

	thumb_func_start ChootSpitExploding
ChootSpitExploding: @ 0x0803F9D0
	push {r4, lr}
	ldr r4, _0803F9F0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0803F9E8
	movs r0, #0
	strh r0, [r4]
_0803F9E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F9F0: .4byte gCurrentSprite

	thumb_func_start Choot
Choot: @ 0x0803F9F4
	push {r4, lr}
	ldr r4, _0803FA20 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0803FA0E
	movs r0, #0xd2
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0803FA0E:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803FA24
	bl SpriteUtilUpdateFreezeTimer
	b _0803FC00
	.align 2, 0
_0803FA20: .4byte gCurrentSprite
_0803FA24:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0803FA30
	b _0803FC00
_0803FA30:
	lsls r0, r0, #2
	ldr r1, _0803FA3C @ =_0803FA40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803FA3C: .4byte _0803FA40
_0803FA40: @ jump table
	.4byte _0803FBB0 @ case 0
	.4byte _0803FBB6 @ case 1
	.4byte _0803FBBA @ case 2
	.4byte _0803FC00 @ case 3
	.4byte _0803FC00 @ case 4
	.4byte _0803FC00 @ case 5
	.4byte _0803FC00 @ case 6
	.4byte _0803FC00 @ case 7
	.4byte _0803FC00 @ case 8
	.4byte _0803FC00 @ case 9
	.4byte _0803FC00 @ case 10
	.4byte _0803FC00 @ case 11
	.4byte _0803FC00 @ case 12
	.4byte _0803FC00 @ case 13
	.4byte _0803FC00 @ case 14
	.4byte _0803FC00 @ case 15
	.4byte _0803FC00 @ case 16
	.4byte _0803FC00 @ case 17
	.4byte _0803FC00 @ case 18
	.4byte _0803FC00 @ case 19
	.4byte _0803FC00 @ case 20
	.4byte _0803FC00 @ case 21
	.4byte _0803FC00 @ case 22
	.4byte _0803FC00 @ case 23
	.4byte _0803FC00 @ case 24
	.4byte _0803FC00 @ case 25
	.4byte _0803FC00 @ case 26
	.4byte _0803FC00 @ case 27
	.4byte _0803FC00 @ case 28
	.4byte _0803FC00 @ case 29
	.4byte _0803FC00 @ case 30
	.4byte _0803FC00 @ case 31
	.4byte _0803FC00 @ case 32
	.4byte _0803FC00 @ case 33
	.4byte _0803FC00 @ case 34
	.4byte _0803FC00 @ case 35
	.4byte _0803FC00 @ case 36
	.4byte _0803FC00 @ case 37
	.4byte _0803FC00 @ case 38
	.4byte _0803FC00 @ case 39
	.4byte _0803FC00 @ case 40
	.4byte _0803FBC0 @ case 41
	.4byte _0803FBC4 @ case 42
	.4byte _0803FBCA @ case 43
	.4byte _0803FBCE @ case 44
	.4byte _0803FBD4 @ case 45
	.4byte _0803FBD8 @ case 46
	.4byte _0803FBDE @ case 47
	.4byte _0803FBE2 @ case 48
	.4byte _0803FC00 @ case 49
	.4byte _0803FC00 @ case 50
	.4byte _0803FC00 @ case 51
	.4byte _0803FC00 @ case 52
	.4byte _0803FC00 @ case 53
	.4byte _0803FC00 @ case 54
	.4byte _0803FC00 @ case 55
	.4byte _0803FC00 @ case 56
	.4byte _0803FC00 @ case 57
	.4byte _0803FC00 @ case 58
	.4byte _0803FC00 @ case 59
	.4byte _0803FC00 @ case 60
	.4byte _0803FC00 @ case 61
	.4byte _0803FC00 @ case 62
	.4byte _0803FC00 @ case 63
	.4byte _0803FC00 @ case 64
	.4byte _0803FC00 @ case 65
	.4byte _0803FC00 @ case 66
	.4byte _0803FC00 @ case 67
	.4byte _0803FC00 @ case 68
	.4byte _0803FC00 @ case 69
	.4byte _0803FC00 @ case 70
	.4byte _0803FC00 @ case 71
	.4byte _0803FC00 @ case 72
	.4byte _0803FC00 @ case 73
	.4byte _0803FC00 @ case 74
	.4byte _0803FC00 @ case 75
	.4byte _0803FC00 @ case 76
	.4byte _0803FC00 @ case 77
	.4byte _0803FC00 @ case 78
	.4byte _0803FC00 @ case 79
	.4byte _0803FC00 @ case 80
	.4byte _0803FC00 @ case 81
	.4byte _0803FC00 @ case 82
	.4byte _0803FC00 @ case 83
	.4byte _0803FC00 @ case 84
	.4byte _0803FC00 @ case 85
	.4byte _0803FC00 @ case 86
	.4byte _0803FBE8 @ case 87
	.4byte _0803FBEC @ case 88
	.4byte _0803FBF2 @ case 89
	.4byte _0803FBF6 @ case 90
	.4byte _0803FBFC @ case 91
_0803FBB0:
	bl ChootInit
	b _0803FC00
_0803FBB6:
	bl ChootIdleInit
_0803FBBA:
	bl ChootIdle
	b _0803FC00
_0803FBC0:
	bl ChootLaunchingInit
_0803FBC4:
	bl ChootLaunching
	b _0803FC00
_0803FBCA:
	bl ChootGoingUpInit
_0803FBCE:
	bl ShootGoingUp
	b _0803FC00
_0803FBD4:
	bl ChootOpeningInit
_0803FBD8:
	bl ChootOpening
	b _0803FC00
_0803FBDE:
	bl ChootGoingDownInit
_0803FBE2:
	bl ChootGoingDown
	b _0803FC00
_0803FBE8:
	bl SpriteDyingInit
_0803FBEC:
	bl SpriteDying
	b _0803FC00
_0803FBF2:
	bl ChootInit
_0803FBF6:
	bl SpriteSpawningFromX
	b _0803FC00
_0803FBFC:
	bl XParasiteInit
_0803FC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ChootSpit
ChootSpit: @ 0x0803FC08
	push {lr}
	ldr r0, _0803FC20 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x37
	bls _0803FC16
	b _0803FD22
_0803FC16:
	lsls r0, r0, #2
	ldr r1, _0803FC24 @ =_0803FC28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803FC20: .4byte gCurrentSprite
_0803FC24: .4byte _0803FC28
_0803FC28: @ jump table
	.4byte _0803FD08 @ case 0
	.4byte _0803FD22 @ case 1
	.4byte _0803FD0E @ case 2
	.4byte _0803FD22 @ case 3
	.4byte _0803FD22 @ case 4
	.4byte _0803FD22 @ case 5
	.4byte _0803FD22 @ case 6
	.4byte _0803FD14 @ case 7
	.4byte _0803FD18 @ case 8
	.4byte _0803FD22 @ case 9
	.4byte _0803FD22 @ case 10
	.4byte _0803FD22 @ case 11
	.4byte _0803FD22 @ case 12
	.4byte _0803FD22 @ case 13
	.4byte _0803FD22 @ case 14
	.4byte _0803FD22 @ case 15
	.4byte _0803FD22 @ case 16
	.4byte _0803FD22 @ case 17
	.4byte _0803FD22 @ case 18
	.4byte _0803FD22 @ case 19
	.4byte _0803FD22 @ case 20
	.4byte _0803FD22 @ case 21
	.4byte _0803FD1E @ case 22
	.4byte _0803FD22 @ case 23
	.4byte _0803FD22 @ case 24
	.4byte _0803FD22 @ case 25
	.4byte _0803FD22 @ case 26
	.4byte _0803FD22 @ case 27
	.4byte _0803FD22 @ case 28
	.4byte _0803FD22 @ case 29
	.4byte _0803FD22 @ case 30
	.4byte _0803FD22 @ case 31
	.4byte _0803FD22 @ case 32
	.4byte _0803FD22 @ case 33
	.4byte _0803FD22 @ case 34
	.4byte _0803FD22 @ case 35
	.4byte _0803FD22 @ case 36
	.4byte _0803FD22 @ case 37
	.4byte _0803FD22 @ case 38
	.4byte _0803FD22 @ case 39
	.4byte _0803FD22 @ case 40
	.4byte _0803FD22 @ case 41
	.4byte _0803FD22 @ case 42
	.4byte _0803FD22 @ case 43
	.4byte _0803FD22 @ case 44
	.4byte _0803FD22 @ case 45
	.4byte _0803FD22 @ case 46
	.4byte _0803FD22 @ case 47
	.4byte _0803FD22 @ case 48
	.4byte _0803FD22 @ case 49
	.4byte _0803FD22 @ case 50
	.4byte _0803FD22 @ case 51
	.4byte _0803FD22 @ case 52
	.4byte _0803FD22 @ case 53
	.4byte _0803FD22 @ case 54
	.4byte _0803FD14 @ case 55
_0803FD08:
	bl ChootSpitInit
	b _0803FD22
_0803FD0E:
	bl ChootSpitSpawning
	b _0803FD22
_0803FD14:
	bl ChootSpitExplodingInit
_0803FD18:
	bl ChootSpitExploding
	b _0803FD22
_0803FD1E:
	bl SpriteUtilCurrentSpriteFall
_0803FD22:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianGroundCheckInShootingRange
ZebesianGroundCheckInShootingRange: @ 0x0803FD28
	push {r4, lr}
	ldr r0, _0803FD70 @ =gSamusData
	movs r2, #0x26
	ldrsh r1, [r0, r2]
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	ldrh r0, [r0, #0x18]
	adds r1, r1, r0
	ldr r4, _0803FD74 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	cmp r1, r0
	bgt _0803FD8C
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xd0
	lsls r2, r2, #2
	movs r0, #0xc0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	adds r3, r0, #0
	cmp r3, #3
	bne _0803FD78
	adds r1, r4, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x17
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2f
	strb r2, [r0]
	subs r0, #1
	strb r2, [r0]
	movs r0, #3
	b _0803FDCC
	.align 2, 0
_0803FD70: .4byte gSamusData
_0803FD74: .4byte gCurrentSprite
_0803FD78:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803FD90
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803FD90
_0803FD8C:
	movs r0, #0
	b _0803FDCC
_0803FD90:
	movs r0, #0xc0
	lsls r0, r0, #1
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r1, r2, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	adds r3, r0, #0
	cmp r3, #3
	bne _0803FDB4
	ldr r0, _0803FDB0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x29
	strb r1, [r0]
	b _0803FDC8
	.align 2, 0
_0803FDB0: .4byte gCurrentSprite
_0803FDB4:
	cmp r3, #0xc
	bne _0803FDC8
	ldr r1, _0803FDD4 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #3
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
_0803FDC8:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
_0803FDCC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803FDD4: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundCheckCollidingWithAir
ZebesianGroundCheckCollidingWithAir: @ 0x0803FDD8
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _0803FE0C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0803FE10 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803FE02
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x24
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0
	bne _0803FE02
	movs r6, #1
_0803FE02:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0803FE0C: .4byte gCurrentSprite
_0803FE10: .4byte gPreviousCollisionCheck

	thumb_func_start ZebesianGroundSetIdleHitbox
ZebesianGroundSetIdleHitbox: @ 0x0803FE14
	push {lr}
	ldr r2, _0803FE34 @ =gCurrentSprite
	movs r3, #0
	movs r1, #0
	ldr r0, _0803FE38 @ =0x0000FF40
	strh r0, [r2, #0xa]
	strh r1, [r2, #0xc]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803FE40
	ldr r0, _0803FE3C @ =0x0000FFE0
	strh r0, [r2, #0xe]
	movs r0, #0x38
	b _0803FE46
	.align 2, 0
_0803FE34: .4byte gCurrentSprite
_0803FE38: .4byte 0x0000FF40
_0803FE3C: .4byte 0x0000FFE0
_0803FE40:
	ldr r0, _0803FE4C @ =0x0000FFC8
	strh r0, [r2, #0xe]
	movs r0, #0x20
_0803FE46:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_0803FE4C: .4byte 0x0000FFC8

	thumb_func_start ZebesianGroundSetShootingHitbox
ZebesianGroundSetShootingHitbox: @ 0x0803FE50
	push {lr}
	ldr r0, _0803FE64 @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	beq _0803FE6C
	ldr r0, _0803FE68 @ =0x0000FF80
	b _0803FE6E
	.align 2, 0
_0803FE64: .4byte gCurrentSprite
_0803FE68: .4byte 0x0000FF80
_0803FE6C:
	ldr r0, _0803FE88 @ =0x0000FF40
_0803FE6E:
	strh r0, [r2, #0xa]
	movs r3, #0
	movs r0, #0
	strh r0, [r2, #0xc]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803FE90
	ldr r0, _0803FE8C @ =0x0000FFE0
	strh r0, [r2, #0xe]
	movs r0, #0x70
	b _0803FE96
	.align 2, 0
_0803FE88: .4byte 0x0000FF40
_0803FE8C: .4byte 0x0000FFE0
_0803FE90:
	ldr r0, _0803FE9C @ =0x0000FF90
	strh r0, [r2, #0xe]
	movs r0, #0x20
_0803FE96:
	strh r0, [r2, #0x10]
	pop {r0}
	bx r0
	.align 2, 0
_0803FE9C: .4byte 0x0000FF90

	thumb_func_start ZebesianGroundInit
ZebesianGroundInit: @ 0x0803FEA0
	push {r4, lr}
	ldr r4, _0803FEB8 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0803FEBC
	movs r0, #0x5a
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x2c
	b _0803FF22
	.align 2, 0
_0803FEB8: .4byte gCurrentSprite
_0803FEBC:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0xb4
	bne _0803FEE2
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _0803FED4
	movs r0, #0
	strh r0, [r4]
	b _0803FF6E
_0803FED4:
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	b _0803FF10
_0803FEE2:
	bl SpriteUtilTrySetAbsorbXFlag
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803FF10
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0803FF0A
	strh r0, [r4]
	b _0803FF6E
_0803FF0A:
	adds r0, r4, #0
	adds r0, #0x36
	strb r2, [r0]
_0803FF10:
	bl SpriteUtilChooseRandomXFlip
	ldr r1, _0803FF74 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #2
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x1e
_0803FF22:
	strb r0, [r1]
	ldr r0, _0803FF74 @ =gCurrentSprite
	mov ip, r0
	mov r1, ip
	adds r1, #0x25
	movs r3, #0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _0803FF78 @ =sPrimarySpriteStats
	mov r0, ip
	ldrb r1, [r0, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0
	mov r2, ip
	strh r0, [r2, #0x14]
	adds r2, #0x27
	movs r0, #0x38
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x28
	strb r1, [r0]
	adds r2, #2
	movs r0, #0x20
	strb r0, [r2]
	ldr r0, _0803FF7C @ =0x0835C190
	mov r2, ip
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r3, [r2, #0x16]
	mov r0, ip
	adds r0, #0x2f
	strb r1, [r0]
	bl ZebesianGroundSetIdleHitbox
_0803FF6E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FF74: .4byte gCurrentSprite
_0803FF78: .4byte sPrimarySpriteStats
_0803FF7C: .4byte 0x0835C190

	thumb_func_start ZebesianGroundSpawningFromX
ZebesianGroundSpawningFromX: @ 0x0803FF80
	push {lr}
	ldr r3, _0803FFB4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x2e
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	subs r0, #1
	mov r1, ip
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0803FFC0
	ldr r2, _0803FFB8 @ =gWrittenToMosaic_H
	ldr r1, _0803FFBC @ =sXParasiteMosaicValues
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	b _0803FFFC
	.align 2, 0
_0803FFB4: .4byte gCurrentSprite
_0803FFB8: .4byte gWrittenToMosaic_H
_0803FFBC: .4byte sXParasiteMosaicValues
_0803FFC0:
	ldrb r0, [r3, #0x1d]
	cmp r0, #0xb4
	bne _0803FFE8
	strb r1, [r3, #0x1f]
	movs r0, #0xb3
	strb r0, [r3, #0x1d]
	adds r2, r3, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x59
	strb r0, [r1]
	ldrh r0, [r3, #2]
	subs r0, #0x40
	strh r0, [r3, #2]
	b _0803FFFC
_0803FFE8:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldrh r1, [r3]
	ldr r0, _08040000 @ =0x0000FFDF
	ands r0, r1
	ldr r1, _08040004 @ =0x00007FFF
	ands r0, r1
	strh r0, [r3]
_0803FFFC:
	pop {r0}
	bx r0
	.align 2, 0
_08040000: .4byte 0x0000FFDF
_08040004: .4byte 0x00007FFF

	thumb_func_start ZebesianPreAquaTurningintoX
ZebesianPreAquaTurningintoX: @ 0x08040008
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r4, _08040068 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0804006C
	ldrb r1, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	adds r5, r4, #0
	adds r5, #0x2a
	ldrb r0, [r5]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x60
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	adds r0, #0x20
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0xb9
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrb r1, [r4, #0x1d]
	ldrb r3, [r6]
	ldrb r0, [r5]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x98
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	subs r0, #0x10
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	movs r0, #0xb9
	movs r2, #0
	bl SpriteSpawnNewXParasite
	b _080400B0
	.align 2, 0
_08040068: .4byte gCurrentSprite
_0804006C:
	ldrb r1, [r4, #0x1d]
	adds r7, r4, #0
	adds r7, #0x23
	ldrb r3, [r7]
	adds r6, r4, #0
	adds r6, #0x2a
	ldrb r0, [r6]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x60
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0xb9
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrb r1, [r4, #0x1d]
	ldrb r3, [r7]
	ldrb r0, [r6]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x98
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	adds r0, #0x10
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0xb9
	movs r2, #0
	bl SpriteSpawnNewXParasite
_080400B0:
	ldr r1, _080400C0 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080400C0: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundTurningIntoX
ZebesianGroundTurningIntoX: @ 0x080400C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r6, _08040168 @ =gCurrentSprite
	ldrb r0, [r6, #0x1d]
	cmp r0, #0xa2
	bne _0804016C
	adds r1, r0, #0
	movs r0, #0x23
	adds r0, r0, r6
	mov r8, r0
	ldrb r3, [r0]
	adds r7, r6, #0
	adds r7, #0x2a
	ldrb r0, [r7]
	str r0, [sp]
	ldrh r0, [r6, #2]
	subs r0, #0x1c
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	subs r0, #0x18
	str r0, [sp, #8]
	movs r5, #0x40
	str r5, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrb r1, [r6, #0x1d]
	mov r0, r8
	ldrb r3, [r0]
	ldrb r0, [r7]
	str r0, [sp]
	ldrh r0, [r6, #2]
	subs r0, #0x38
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	adds r0, #0x18
	str r0, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrb r1, [r6, #0x1d]
	mov r0, r8
	ldrb r3, [r0]
	ldrb r0, [r7]
	str r0, [sp]
	ldrh r0, [r6, #2]
	subs r0, #0x54
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	subs r0, #0xc
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrb r1, [r6, #0x1d]
	mov r0, r8
	ldrb r3, [r0]
	ldrb r0, [r7]
	str r0, [sp]
	ldrh r0, [r6, #2]
	subs r0, #0x70
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	adds r0, #0xc
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r6, #2]
	subs r0, #0x8c
	strh r0, [r6, #2]
	b _080401D4
	.align 2, 0
_08040168: .4byte gCurrentSprite
_0804016C:
	ldrh r1, [r6]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080401A2
	ldrb r1, [r6, #0x1d]
	adds r0, r6, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r6, #2]
	subs r0, #0x60
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	adds r0, #0x20
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r6, #4]
	subs r0, #0x10
	b _080401CA
_080401A2:
	ldrb r1, [r6, #0x1d]
	adds r0, r6, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r6, #2]
	subs r0, #0x60
	str r0, [sp, #4]
	ldrh r0, [r6, #4]
	subs r0, #0x20
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r6, #4]
	adds r0, #0x10
_080401CA:
	strh r0, [r6, #4]
	ldr r1, _080401E0 @ =gCurrentSprite
	ldrh r0, [r1, #2]
	subs r0, #0x98
	strh r0, [r1, #2]
_080401D4:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080401E0: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundFallingInit
ZebesianGroundFallingInit: @ 0x080401E4
	push {lr}
	ldr r3, _08040208 @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x24
	movs r1, #0
	movs r0, #0x16
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x31
	strb r1, [r0]
	ldr r0, _0804020C @ =0x0835C200
	str r0, [r3, #0x18]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	bl ZebesianGroundSetIdleHitbox
	pop {r0}
	bx r0
	.align 2, 0
_08040208: .4byte gCurrentSprite
_0804020C: .4byte 0x0835C200

	thumb_func_start ZebesianGroundIdleInit
ZebesianGroundIdleInit: @ 0x08040210
	push {r4, lr}
	ldr r4, _08040234 @ =gCurrentSprite
	ldr r0, _08040238 @ =0x0835C190
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	bl ZebesianGroundSetIdleHitbox
	ldrh r0, [r4, #4]
	strh r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040234: .4byte gCurrentSprite
_08040238: .4byte 0x0835C190

	thumb_func_start ZebesianGroundIdle
ZebesianGroundIdle: @ 0x0804023C
	push {r4, r5, r6, r7, lr}
	ldr r4, _08040264 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	beq _0804024E
	b _08040410
_0804024E:
	movs r7, #0
	bl ZebesianGroundCheckCollidingWithAir
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040268
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x15
	b _0804040E
	.align 2, 0
_08040264: .4byte gCurrentSprite
_08040268:
	bl SpriteUtilAlignYPositionOnSlopeAtOrigin
	ldr r0, _080402A4 @ =gPreviousVerticalCollisionCheck
	ldrb r1, [r0]
	movs r6, #0xf0
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08040344
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080402E0
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _080402A8 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080402AC
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x60
	b _080402FC
	.align 2, 0
_080402A4: .4byte gPreviousVerticalCollisionCheck
_080402A8: .4byte gPreviousCollisionCheck
_080402AC:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0804030C
	ldrh r0, [r4, #2]
	subs r0, #0xa0
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0804030C
	ldrh r0, [r4, #4]
	adds r0, #4
	b _08040358
_080402E0:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08040310 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08040314
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x60
_080402FC:
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	movs r7, #2
	cmp r0, #0
	bne _0804035A
_0804030C:
	movs r7, #1
	b _0804035A
	.align 2, 0
_08040310: .4byte gPreviousCollisionCheck
_08040314:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0804030C
	ldrh r0, [r4, #2]
	subs r0, #0xa0
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0804030C
	b _08040354
_08040344:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08040354
	ldrh r0, [r4, #4]
	adds r0, #4
	b _08040358
_08040354:
	ldrh r0, [r4, #4]
	subs r0, #4
_08040358:
	strh r0, [r4, #4]
_0804035A:
	ldr r2, _0804037C @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08040396
	ldrh r0, [r2, #0x16]
	cmp r0, #2
	bne _08040384
	ldrb r0, [r2, #0x1c]
	cmp r0, #1
	bne _08040384
	ldr r0, _08040380 @ =0x000001AF
	bl SoundPlay
	b _08040396
	.align 2, 0
_0804037C: .4byte gCurrentSprite
_08040380: .4byte 0x000001AF
_08040384:
	ldrh r0, [r2, #0x16]
	cmp r0, #6
	bne _08040396
	ldrb r0, [r2, #0x1c]
	cmp r0, #1
	bne _08040396
	ldr r0, _080403B0 @ =0x000001AF
	bl SoundPlay
_08040396:
	bl ZebesianGroundCheckInShootingRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040410
	cmp r7, #1
	bne _080403B8
	ldr r0, _080403B4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #9
	strb r1, [r0]
	b _08040410
	.align 2, 0
_080403B0: .4byte 0x000001AF
_080403B4: .4byte gCurrentSprite
_080403B8:
	cmp r7, #2
	bne _080403D0
	ldr r1, _080403CC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x17
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #1
	b _0804040E
	.align 2, 0
_080403CC: .4byte gCurrentSprite
_080403D0:
	ldr r2, _080403F8 @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	bne _08040410
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080403FC
	ldrh r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r2, #4]
	cmp r0, r1
	bge _08040410
	b _08040408
	.align 2, 0
_080403F8: .4byte gCurrentSprite
_080403FC:
	ldrh r0, [r2, #8]
	ldr r1, _08040418 @ =0xFFFFFF00
	adds r0, r0, r1
	ldrh r1, [r2, #4]
	cmp r0, r1
	ble _08040410
_08040408:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #9
_0804040E:
	strb r0, [r1]
_08040410:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040418: .4byte 0xFFFFFF00

	thumb_func_start ZebesianGroundTurningAroundInit
ZebesianGroundTurningAroundInit: @ 0x0804041C
	ldr r1, _08040434 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r0, _08040438 @ =0x0835C328
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_08040434: .4byte gCurrentSprite
_08040438: .4byte 0x0835C328

	thumb_func_start ZebesianGroundTurningAround
ZebesianGroundTurningAround: @ 0x0804043C
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08040462
	ldr r2, _08040468 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0804046C @ =0x0835C348
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_08040462:
	pop {r0}
	bx r0
	.align 2, 0
_08040468: .4byte gCurrentSprite
_0804046C: .4byte 0x0835C348

	thumb_func_start ZebesianGroundTurningAroundSecondPart
ZebesianGroundTurningAroundSecondPart: @ 0x08040470
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804049A
	ldr r1, _08040490 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	cmp r0, #0
	beq _08040494
	movs r0, #0
	strb r0, [r2]
	adds r1, #0x24
	movs r0, #0x29
	b _08040498
	.align 2, 0
_08040490: .4byte gCurrentSprite
_08040494:
	adds r1, #0x24
	movs r0, #1
_08040498:
	strb r0, [r1]
_0804049A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianGroundJumpWarningInit
ZebesianGroundJumpWarningInit: @ 0x080404A0
	ldr r1, _080404B4 @ =gCurrentSprite
	ldr r0, _080404B8 @ =0x0835C2D8
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	bx lr
	.align 2, 0
_080404B4: .4byte gCurrentSprite
_080404B8: .4byte 0x0835C2D8

	thumb_func_start ZebesianGroundJumpWarning
ZebesianGroundJumpWarning: @ 0x080404BC
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _080404F6
	ldr r3, _080404FC @ =gCurrentSprite
	ldr r0, _08040500 @ =0x0835C300
	str r0, [r3, #0x18]
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r2, #0
	strh r0, [r3, #0x16]
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	ldr r0, _08040504 @ =0x0000FF60
	strh r0, [r3, #0xa]
	ldrh r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080404F6
	ldr r0, _08040508 @ =0x000001AD
	bl SoundPlayNotAlreadyPlaying
_080404F6:
	pop {r0}
	bx r0
	.align 2, 0
_080404FC: .4byte gCurrentSprite
_08040500: .4byte 0x0835C300
_08040504: .4byte 0x0000FF60
_08040508: .4byte 0x000001AD

	thumb_func_start ZebesianGroundJumping
ZebesianGroundJumping: @ 0x0804050C
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _08040548 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08040550
	ldrh r0, [r4, #2]
	subs r0, #0x10
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0804054C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08040576
	ldrh r0, [r4, #2]
	subs r0, #0x50
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08040576
	ldrh r0, [r4, #4]
	adds r0, #0xa
	b _08040584
	.align 2, 0
_08040548: .4byte gCurrentSprite
_0804054C: .4byte gPreviousCollisionCheck
_08040550:
	ldrh r0, [r4, #2]
	subs r0, #0x10
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0804057C @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08040576
	ldrh r0, [r4, #2]
	subs r0, #0x50
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _08040580
_08040576:
	movs r6, #1
	b _08040586
	.align 2, 0
_0804057C: .4byte gPreviousCollisionCheck
_08040580:
	ldrh r0, [r4, #4]
	subs r0, #0xa
_08040584:
	strh r0, [r4, #4]
_08040586:
	ldr r1, _080405B4 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0
	beq _080405BC
	ldr r0, _080405B8 @ =0x08359A10
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r1, [r2]
	lsrs r1, r1, #1
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrb r0, [r2]
	cmp r0, #0x12
	bhi _080405DC
	b _080405D8
	.align 2, 0
_080405B4: .4byte gCurrentSprite
_080405B8: .4byte 0x08359A10
_080405BC:
	ldr r0, _080405FC @ =0x083599FC
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r1, [r2]
	lsrs r1, r1, #2
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrb r0, [r2]
	cmp r0, #0x26
	bhi _080405DC
_080405D8:
	adds r0, #1
	strb r0, [r2]
_080405DC:
	lsls r0, r1, #0x10
	cmp r0, #0
	ble _08040640
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r5, _08040600 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0
	beq _08040604
	strh r1, [r4, #2]
	bl ZebesianGroundLandingInit
	b _0804067A
	.align 2, 0
_080405FC: .4byte 0x083599FC
_08040600: .4byte gPreviousVerticalCollisionCheck
_08040604:
	cmp r6, #0
	bne _0804067A
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08040632
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804062E
	movs r6, #1
_0804062E:
	cmp r6, #0
	beq _0804067A
_08040632:
	ldr r0, _0804063C @ =gCurrentSprite
	strh r1, [r0, #2]
	bl ZebesianGroundLandingInit
	b _0804067A
	.align 2, 0
_0804063C: .4byte gCurrentSprite
_08040640:
	movs r6, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	ldrh r1, [r4, #4]
	adds r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08040680 @ =gPreviousCollisionCheck
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _08040676
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	ldrh r1, [r4, #4]
	subs r1, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r0, [r5]
	cmp r0, #0x11
	bne _08040672
	movs r6, #1
_08040672:
	cmp r6, #0
	beq _0804067A
_08040676:
	bl ZebesianGroundFallingInit
_0804067A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040680: .4byte gPreviousCollisionCheck

	thumb_func_start ZebesianGroundLandingInit
ZebesianGroundLandingInit: @ 0x08040684
	push {lr}
	ldr r1, _080406B0 @ =gCurrentSprite
	ldr r0, _080406B4 @ =0x0835C310
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080406AC
	movs r0, #0xd7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_080406AC:
	pop {r0}
	bx r0
	.align 2, 0
_080406B0: .4byte gCurrentSprite
_080406B4: .4byte 0x0835C310

	thumb_func_start ZebesianGroundLanding
ZebesianGroundLanding: @ 0x080406B8
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804077C
	ldr r4, _080406DC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _080406E0
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	b _0804077C
	.align 2, 0
_080406DC: .4byte gCurrentSprite
_080406E0:
	bl ZebesianGroundCheckInShootingRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804077C
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804072C
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _08040728 @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08040762
	ldrh r0, [r4, #2]
	subs r0, #0xa0
	ldrh r1, [r4, #4]
	adds r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804075E
	b _08040762
	.align 2, 0
_08040728: .4byte gPreviousCollisionCheck
_0804072C:
	ldrh r0, [r4, #2]
	subs r0, #4
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldr r5, _0804076C @ =gPreviousCollisionCheck
	ldrb r1, [r5]
	movs r6, #0xf
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _08040762
	ldrh r0, [r4, #2]
	subs r0, #0xa0
	ldrh r1, [r4, #4]
	subs r1, #0x40
	bl SpriteUtilCheckCollisionAtPosition
	ldrb r1, [r5]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804075E
	movs r7, #1
_0804075E:
	cmp r7, #0
	beq _08040774
_08040762:
	ldr r0, _08040770 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #3
	b _0804077A
	.align 2, 0
_0804076C: .4byte gPreviousCollisionCheck
_08040770: .4byte gCurrentSprite
_08040774:
	ldr r0, _08040784 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
_0804077A:
	strb r1, [r0]
_0804077C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040784: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundWaitingInit
ZebesianGroundWaitingInit: @ 0x08040788
	push {lr}
	ldr r1, _080407A4 @ =gCurrentSprite
	ldr r0, _080407A8 @ =0x0835C1D8
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #8
	strb r0, [r1]
	bl ZebesianGroundSetIdleHitbox
	pop {r0}
	bx r0
	.align 2, 0
_080407A4: .4byte gCurrentSprite
_080407A8: .4byte 0x0835C1D8

	thumb_func_start ZebesianGroundWaiting
ZebesianGroundWaiting: @ 0x080407AC
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _080407BE
	ldr r0, _080407C4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_080407BE:
	pop {r0}
	bx r0
	.align 2, 0
_080407C4: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundStandingInit
ZebesianGroundStandingInit: @ 0x080407C8
	ldr r1, _080407EC @ =gCurrentSprite
	ldr r0, _080407F0 @ =0x0835C1D8
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0xa
	strb r0, [r2]
	ldr r0, _080407F4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsrs r0, r0, #2
	adds r0, #2
	adds r1, #0x2f
	strb r0, [r1]
	bx lr
	.align 2, 0
_080407EC: .4byte gCurrentSprite
_080407F0: .4byte 0x0835C1D8
_080407F4: .4byte gSpriteRandomNumber

	thumb_func_start ZebesianGroundStanding
ZebesianGroundStanding: @ 0x080407F8
	push {lr}
	bl ZebesianGroundCheckInShootingRange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040824
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _08040824
	ldr r1, _08040828 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040824
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
_08040824:
	pop {r0}
	bx r0
	.align 2, 0
_08040828: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundShootingInit
ZebesianGroundShootingInit: @ 0x0804082C
	push {r4, lr}
	ldr r4, _08040858 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x2a
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x46
	strb r0, [r1]
	bl SpriteUtilCheckSamusCrouchingOrMorphed
	cmp r0, #0
	beq _08040860
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0804085C @ =0x0835C278
	b _0804086A
	.align 2, 0
_08040858: .4byte gCurrentSprite
_0804085C: .4byte 0x0835C278
_08040860:
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08040878 @ =0x0835C210
_0804086A:
	str r0, [r4, #0x18]
	bl ZebesianGroundSetShootingHitbox
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040878: .4byte 0x0835C210

	thumb_func_start ZebesianGroundShooting
ZebesianGroundShooting: @ 0x0804087C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, _080408DC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040912
	ldrh r0, [r4, #0x16]
	cmp r0, #6
	beq _08040894
	b _080409A0
_08040894:
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _0804089C
	b _080409A0
_0804089C:
	ldrh r1, [r4]
	movs r6, #0x40
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080408E0
	ldrb r2, [r4, #0x1f]
	adds r5, r4, #0
	adds r5, #0x23
	ldrb r3, [r5]
	ldrh r0, [r4, #2]
	subs r0, #0x50
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x58
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x3f
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #2]
	subs r0, #0x30
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x18
	b _0804095A
	.align 2, 0
_080408DC: .4byte gCurrentSprite
_080408E0:
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x50
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x58
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x3f
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x30
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x18
	str r0, [sp, #4]
	str r5, [sp, #8]
	b _0804095E
_08040912:
	ldrh r0, [r4, #0x16]
	cmp r0, #7
	bne _080409A0
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	bne _080409A0
	ldrh r1, [r4]
	movs r6, #0x40
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08040968
	ldrb r2, [r4, #0x1f]
	adds r5, r4, #0
	adds r5, #0x23
	ldrb r3, [r5]
	ldrh r0, [r4, #2]
	subs r0, #0x78
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x60
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x3f
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #2]
	subs r0, #0x68
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x10
_0804095A:
	str r0, [sp, #4]
	str r6, [sp, #8]
_0804095E:
	movs r0, #0x3f
	movs r1, #0
	bl SpriteSpawnSecondary
	b _080409A0
_08040968:
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x78
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x60
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x3f
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x68
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x10
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x3f
	movs r1, #0
	bl SpriteSpawnSecondary
_080409A0:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _080409B0
	ldr r0, _080409B8 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x2b
	strb r1, [r0]
_080409B0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080409B8: .4byte gCurrentSprite

	thumb_func_start ZebesianGroundShootingEndInit
ZebesianGroundShootingEndInit: @ 0x080409BC
	push {lr}
	ldr r1, _080409D8 @ =gCurrentSprite
	ldr r0, _080409DC @ =0x0835C1D8
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x2c
	strb r0, [r1]
	bl ZebesianGroundSetIdleHitbox
	pop {r0}
	bx r0
	.align 2, 0
_080409D8: .4byte gCurrentSprite
_080409DC: .4byte 0x0835C1D8

	thumb_func_start ZebesianGroundShootingEnd
ZebesianGroundShootingEnd: @ 0x080409E0
	push {r4, r5, r6, lr}
	ldr r0, _08040A24 @ =gSamusData
	movs r2, #0x26
	ldrsh r1, [r0, r2]
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	ldrh r0, [r0, #0x18]
	adds r1, r1, r0
	ldr r4, _08040A28 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	cmp r1, r0
	bgt _08040A6E
	movs r1, #0x80
	lsls r1, r1, #1
	movs r6, #0xd0
	lsls r6, r6, #2
	movs r0, #0xc0
	adds r2, r6, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	cmp r0, #3
	bne _08040A2C
	adds r1, r4, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x17
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2f
	strb r2, [r0]
	subs r0, #1
	strb r2, [r0]
	b _08040A76
	.align 2, 0
_08040A24: .4byte gSamusData
_08040A28: .4byte gCurrentSprite
_08040A2C:
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	cmp r0, #0
	beq _08040A3A
	subs r0, #1
	strb r0, [r5]
_08040A3A:
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, #0
	adds r2, r6, #0
	bl SpriteUtilCheckSamusNearSpriteFrontBehind
	cmp r0, #3
	bne _08040A58
	ldrb r0, [r5]
	cmp r0, #0
	bne _08040A76
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x29
	b _08040A74
_08040A58:
	cmp r0, #0xc
	bne _08040A6E
	ldrb r0, [r5]
	cmp r0, #0
	bne _08040A76
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
	adds r1, #0xb
	b _08040A72
_08040A6E:
	adds r1, r4, #0
	adds r1, #0x24
_08040A72:
	movs r0, #1
_08040A74:
	strb r0, [r1]
_08040A76:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ZebesianGroundBeamInit
ZebesianGroundBeamInit: @ 0x08040A7C
	push {r4, r5, r6, lr}
	ldr r0, _08040AEC @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0]
	ldr r3, _08040AF0 @ =0x0000FFFB
	ands r3, r0
	movs r5, #0
	movs r4, #0
	mov r1, ip
	strh r3, [r1]
	mov r2, ip
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	movs r2, #0x30
	strb r2, [r0]
	ldr r0, _08040AF4 @ =0x0000FFF8
	mov r6, ip
	strh r0, [r6, #0xa]
	strh r1, [r6, #0xc]
	ldr r0, _08040AF8 @ =0x0835C398
	str r0, [r6, #0x18]
	strb r5, [r6, #0x1c]
	strh r4, [r6, #0x16]
	mov r0, ip
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	mov r1, ip
	adds r1, #0x22
	movs r0, #5
	strb r0, [r1]
	subs r1, #1
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x40
	ands r0, r3
	mov r1, ip
	cmp r0, #0
	beq _08040AFC
	movs r0, #0x10
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x10]
	b _08040B04
	.align 2, 0
_08040AEC: .4byte gCurrentSprite
_08040AF0: .4byte 0x0000FFFB
_08040AF4: .4byte 0x0000FFF8
_08040AF8: .4byte 0x0835C398
_08040AFC:
	ldr r0, _08040B1C @ =0x0000FFD0
	strh r0, [r1, #0xe]
	adds r0, #0x20
	strh r0, [r1, #0x10]
_08040B04:
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08040B14
	ldr r0, _08040B20 @ =0x0000015D
	bl SoundPlayNotAlreadyPlaying
_08040B14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040B1C: .4byte 0x0000FFD0
_08040B20: .4byte 0x0000015D

	thumb_func_start ZebesianGroundBeamSpawning
ZebesianGroundBeamSpawning: @ 0x08040B24
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08040B64
	ldr r2, _08040B54 @ =gCurrentSprite
	ldr r0, _08040B58 @ =0x0835C3C0
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08040B5C
	movs r0, #0x20
	strh r0, [r2, #0xe]
	movs r0, #0x60
	b _08040B62
	.align 2, 0
_08040B54: .4byte gCurrentSprite
_08040B58: .4byte 0x0835C3C0
_08040B5C:
	ldr r0, _08040B68 @ =0x0000FFA0
	strh r0, [r2, #0xe]
	adds r0, #0x40
_08040B62:
	strh r0, [r2, #0x10]
_08040B64:
	pop {r0}
	bx r0
	.align 2, 0
_08040B68: .4byte 0x0000FFA0

	thumb_func_start ZebesianGroundBeamFired
ZebesianGroundBeamFired: @ 0x08040B6C
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _08040BAC
	ldr r2, _08040B9C @ =gCurrentSprite
	ldr r0, _08040BA0 @ =0x0835C368
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08040BA4
	movs r0, #0x20
	strh r0, [r2, #0xe]
	movs r0, #0xa0
	b _08040BAA
	.align 2, 0
_08040B9C: .4byte gCurrentSprite
_08040BA0: .4byte 0x0835C368
_08040BA4:
	ldr r0, _08040BB0 @ =0x0000FF60
	strh r0, [r2, #0xe]
	adds r0, #0x80
_08040BAA:
	strh r0, [r2, #0x10]
_08040BAC:
	pop {r0}
	bx r0
	.align 2, 0
_08040BB0: .4byte 0x0000FF60

	thumb_func_start ZebesianGroundCheckSkipMovement
ZebesianGroundCheckSkipMovement: @ 0x08040BB4
	push {lr}
	ldr r2, _08040BD4 @ =gCurrentSprite
	ldrb r0, [r2, #0x1d]
	cmp r0, #0xb4
	bne _08040BDC
	ldr r0, _08040BD8 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08040BDC
	ldrb r0, [r2, #0x1c]
	subs r0, #1
	strb r0, [r2, #0x1c]
	movs r0, #1
	b _08040BDE
	.align 2, 0
_08040BD4: .4byte gCurrentSprite
_08040BD8: .4byte gFrameCounter8Bit
_08040BDC:
	movs r0, #0
_08040BDE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ZebesianGround
ZebesianGround: @ 0x08040BE4
	push {r4, lr}
	ldr r4, _08040C1C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _08040BFE
	movs r0, #0xaf
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_08040BFE:
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040C20
	bl SpriteUtilUpdateFreezeTimer
	b _08040EF6
	.align 2, 0
_08040C1C: .4byte gCurrentSprite
_08040C20:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _08040C2C
	b _08040EB8
_08040C2C:
	lsls r0, r0, #2
	ldr r1, _08040C38 @ =_08040C3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08040C38: .4byte _08040C3C
_08040C3C: @ jump table
	.4byte _08040DAC @ case 0
	.4byte _08040DB2 @ case 1
	.4byte _08040DB6 @ case 2
	.4byte _08040DF4 @ case 3
	.4byte _08040DF8 @ case 4
	.4byte _08040E08 @ case 5
	.4byte _08040EB8 @ case 6
	.4byte _08040DC8 @ case 7
	.4byte _08040DCC @ case 8
	.4byte _08040DDE @ case 9
	.4byte _08040DE2 @ case 10
	.4byte _08040EB8 @ case 11
	.4byte _08040EB8 @ case 12
	.4byte _08040EB8 @ case 13
	.4byte _08040EB8 @ case 14
	.4byte _08040EB8 @ case 15
	.4byte _08040EB8 @ case 16
	.4byte _08040EB8 @ case 17
	.4byte _08040EB8 @ case 18
	.4byte _08040EB8 @ case 19
	.4byte _08040EB8 @ case 20
	.4byte _08040E18 @ case 21
	.4byte _08040E1C @ case 22
	.4byte _08040E2C @ case 23
	.4byte _08040E30 @ case 24
	.4byte _08040EB8 @ case 25
	.4byte _08040E40 @ case 26
	.4byte _08040EB8 @ case 27
	.4byte _08040E50 @ case 28
	.4byte _08040EB8 @ case 29
	.4byte _08040EB8 @ case 30
	.4byte _08040EB8 @ case 31
	.4byte _08040EB8 @ case 32
	.4byte _08040EB8 @ case 33
	.4byte _08040EB8 @ case 34
	.4byte _08040EB8 @ case 35
	.4byte _08040EB8 @ case 36
	.4byte _08040EB8 @ case 37
	.4byte _08040EB8 @ case 38
	.4byte _08040EB8 @ case 39
	.4byte _08040EB8 @ case 40
	.4byte _08040E60 @ case 41
	.4byte _08040E64 @ case 42
	.4byte _08040E74 @ case 43
	.4byte _08040E78 @ case 44
	.4byte _08040EB8 @ case 45
	.4byte _08040EB8 @ case 46
	.4byte _08040EB8 @ case 47
	.4byte _08040EB8 @ case 48
	.4byte _08040EB8 @ case 49
	.4byte _08040EB8 @ case 50
	.4byte _08040EB8 @ case 51
	.4byte _08040EB8 @ case 52
	.4byte _08040EB8 @ case 53
	.4byte _08040EB8 @ case 54
	.4byte _08040EB8 @ case 55
	.4byte _08040EB8 @ case 56
	.4byte _08040EB8 @ case 57
	.4byte _08040EB8 @ case 58
	.4byte _08040EB8 @ case 59
	.4byte _08040EB8 @ case 60
	.4byte _08040EB8 @ case 61
	.4byte _08040EB8 @ case 62
	.4byte _08040EB8 @ case 63
	.4byte _08040EB8 @ case 64
	.4byte _08040EB8 @ case 65
	.4byte _08040EB8 @ case 66
	.4byte _08040EB8 @ case 67
	.4byte _08040EB8 @ case 68
	.4byte _08040EB8 @ case 69
	.4byte _08040EB8 @ case 70
	.4byte _08040EB8 @ case 71
	.4byte _08040EB8 @ case 72
	.4byte _08040EB8 @ case 73
	.4byte _08040EB8 @ case 74
	.4byte _08040EB8 @ case 75
	.4byte _08040EB8 @ case 76
	.4byte _08040EB8 @ case 77
	.4byte _08040EB8 @ case 78
	.4byte _08040EB8 @ case 79
	.4byte _08040EB8 @ case 80
	.4byte _08040EB8 @ case 81
	.4byte _08040EB8 @ case 82
	.4byte _08040EB8 @ case 83
	.4byte _08040EB8 @ case 84
	.4byte _08040EB8 @ case 85
	.4byte _08040EB8 @ case 86
	.4byte _08040E88 @ case 87
	.4byte _08040E8C @ case 88
	.4byte _08040E92 @ case 89
	.4byte _08040E96 @ case 90
	.4byte _08040E9C @ case 91
_08040DAC:
	bl ZebesianGroundInit
	b _08040EB8
_08040DB2:
	bl ZebesianGroundIdleInit
_08040DB6:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040DC2
	b _08040EF6
_08040DC2:
	bl ZebesianGroundIdle
	b _08040EB8
_08040DC8:
	bl ZebesianGroundWaitingInit
_08040DCC:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040DD8
	b _08040EF6
_08040DD8:
	bl ZebesianGroundWaiting
	b _08040EB8
_08040DDE:
	bl ZebesianGroundStandingInit
_08040DE2:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08040DEE
	b _08040EF6
_08040DEE:
	bl ZebesianGroundStanding
	b _08040EB8
_08040DF4:
	bl ZebesianGroundTurningAroundInit
_08040DF8:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundTurningAround
	b _08040EB8
_08040E08:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundTurningAroundSecondPart
	b _08040EB8
_08040E18:
	bl ZebesianGroundFallingInit
_08040E1C:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl SpriteUtilCurrentSpriteFall
	b _08040EB8
_08040E2C:
	bl ZebesianGroundJumpWarningInit
_08040E30:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundJumpWarning
	b _08040EB8
_08040E40:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundJumping
	b _08040EB8
_08040E50:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundLanding
	b _08040EB8
_08040E60:
	bl ZebesianGroundShootingInit
_08040E64:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundShooting
	b _08040EB8
_08040E74:
	bl ZebesianGroundShootingEndInit
_08040E78:
	bl ZebesianGroundCheckSkipMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08040EF6
	bl ZebesianGroundShootingEnd
	b _08040EB8
_08040E88:
	bl SpriteDyingInit
_08040E8C:
	bl SpriteDying
	b _08040EB8
_08040E92:
	bl ZebesianGroundInit
_08040E96:
	bl ZebesianGroundSpawningFromX
	b _08040EB8
_08040E9C:
	ldr r0, _08040EAC @ =gCurrentSprite
	ldrb r0, [r0, #0x1d]
	cmp r0, #0xb4
	bne _08040EB0
	bl ZebesianPreAquaTurningintoX
	b _08040EB8
	.align 2, 0
_08040EAC: .4byte gCurrentSprite
_08040EB0:
	bl ZebesianGroundTurningIntoX
	bl XParasiteInit
_08040EB8:
	ldr r2, _08040ED8 @ =gCurrentSprite
	ldrb r0, [r2, #0x1d]
	cmp r0, #0xa2
	bne _08040EF6
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08040EE0
	ldr r0, _08040EDC @ =gSamusData
	ldrh r1, [r0, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08040EF6
	b _08040EEC
	.align 2, 0
_08040ED8: .4byte gCurrentSprite
_08040EDC: .4byte gSamusData
_08040EE0:
	ldr r0, _08040EFC @ =gSamusData
	ldrh r1, [r0, #0x12]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08040EF6
_08040EEC:
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
_08040EF6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040EFC: .4byte gSamusData

	thumb_func_start ZebesianGroundBeam
ZebesianGroundBeam: @ 0x08040F00
	push {lr}
	ldr r0, _08040F18 @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #2
	beq _08040F28
	cmp r0, #2
	bgt _08040F1C
	cmp r0, #0
	beq _08040F22
	b _08040F32
	.align 2, 0
_08040F18: .4byte gCurrentSprite
_08040F1C:
	cmp r0, #0x18
	beq _08040F2E
	b _08040F32
_08040F22:
	bl ZebesianGroundBeamInit
	b _08040F32
_08040F28:
	bl ZebesianGroundBeamSpawning
	b _08040F32
_08040F2E:
	bl ZebesianGroundBeamFired
_08040F32:
	ldr r2, _08040F44 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08040F48
	ldrh r0, [r2, #4]
	adds r0, #0xa
	b _08040F4C
	.align 2, 0
_08040F44: .4byte gCurrentSprite
_08040F48:
	ldrh r0, [r2, #4]
	subs r0, #0xa
_08040F4C:
	strh r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0
