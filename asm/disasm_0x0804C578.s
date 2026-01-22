    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start BigFlashingNumber
BigFlashingNumber: @ 0x0804C578
	push {r4, r5, r6, r7, lr}
	ldr r4, _0804C5FC @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x24
	ldrb r6, [r3]
	cmp r6, #0
	bne _0804C65A
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	strb r6, [r0]
	adds r1, #2
	movs r0, #8
	strb r0, [r1]
	movs r2, #0
	ldr r1, _0804C600 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x25
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0x10
	strb r0, [r1]
	strb r2, [r4, #0x1c]
	strh r6, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	movs r5, #0xf
	ands r5, r0
	adds r7, r5, #0
	bl GetFlashingSectorNumber
	lsls r0, r0, #0x18
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	cmp r5, r0
	bne _0804C658
	cmp r5, #7
	bne _0804C608
	ldr r0, _0804C604 @ =0x0837EDFC
	str r0, [r4, #0x18]
	b _0804C65A
	.align 2, 0
_0804C5FC: .4byte gCurrentSprite
_0804C600: .4byte 0x0000FFFC
_0804C604: .4byte 0x0837EDFC
_0804C608:
	cmp r5, #8
	bne _0804C618
	ldr r0, _0804C614 @ =0x0837EE44
	str r0, [r4, #0x18]
	b _0804C65A
	.align 2, 0
_0804C614: .4byte 0x0837EE44
_0804C618:
	cmp r5, #9
	bne _0804C628
	ldr r0, _0804C624 @ =0x0837EE8C
	str r0, [r4, #0x18]
	b _0804C65A
	.align 2, 0
_0804C624: .4byte 0x0837EE8C
_0804C628:
	cmp r5, #0xa
	bne _0804C638
	ldr r0, _0804C634 @ =0x0837EED4
	str r0, [r4, #0x18]
	b _0804C65A
	.align 2, 0
_0804C634: .4byte 0x0837EED4
_0804C638:
	cmp r5, #0xb
	bne _0804C648
	ldr r0, _0804C644 @ =0x0837EF1C
	str r0, [r4, #0x18]
	b _0804C65A
	.align 2, 0
_0804C644: .4byte 0x0837EF1C
_0804C648:
	cmp r7, #0xc
	bne _0804C658
	ldr r0, _0804C654 @ =0x0837EF64
	str r0, [r4, #0x18]
	b _0804C65A
	.align 2, 0
_0804C654: .4byte 0x0837EF64
_0804C658:
	strh r6, [r4]
_0804C65A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FlashingNumber
FlashingNumber: @ 0x0804C660
	push {r4, r5, r6, r7, lr}
	ldr r4, _0804C6E0 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r0, #1
	strb r0, [r1]
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r6, [r5]
	cmp r6, #0
	bne _0804C73E
	ldrh r0, [r4, #4]
	adds r0, #0x20
	movs r3, #0
	strh r0, [r4, #4]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r0, r4, #0
	adds r0, #0x27
	movs r2, #0x10
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0804C6E4 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	subs r0, #3
	strb r2, [r0]
	strb r3, [r4, #0x1c]
	strh r6, [r4, #0x16]
	adds r0, #8
	ldrb r0, [r0]
	movs r5, #7
	ands r5, r0
	adds r7, r5, #0
	bl GetFlashingSectorNumber
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, r0
	bne _0804C73C
	cmp r5, #1
	bne _0804C6EC
	ldr r0, _0804C6E8 @ =0x0837F948
	str r0, [r4, #0x18]
	b _0804C73E
	.align 2, 0
_0804C6E0: .4byte gCurrentSprite
_0804C6E4: .4byte 0x0000FFFC
_0804C6E8: .4byte 0x0837F948
_0804C6EC:
	cmp r5, #2
	bne _0804C6FC
	ldr r0, _0804C6F8 @ =0x0837F990
	str r0, [r4, #0x18]
	b _0804C73E
	.align 2, 0
_0804C6F8: .4byte 0x0837F990
_0804C6FC:
	cmp r5, #3
	bne _0804C70C
	ldr r0, _0804C708 @ =0x0837F9D8
	str r0, [r4, #0x18]
	b _0804C73E
	.align 2, 0
_0804C708: .4byte 0x0837F9D8
_0804C70C:
	cmp r5, #4
	bne _0804C71C
	ldr r0, _0804C718 @ =0x0837FA20
	str r0, [r4, #0x18]
	b _0804C73E
	.align 2, 0
_0804C718: .4byte 0x0837FA20
_0804C71C:
	cmp r5, #5
	bne _0804C72C
	ldr r0, _0804C728 @ =0x0837FA68
	str r0, [r4, #0x18]
	b _0804C73E
	.align 2, 0
_0804C728: .4byte 0x0837FA68
_0804C72C:
	cmp r7, #6
	bne _0804C73C
	ldr r0, _0804C738 @ =0x0837FAB0
	str r0, [r4, #0x18]
	b _0804C73E
	.align 2, 0
_0804C738: .4byte 0x0837FAB0
_0804C73C:
	strh r6, [r4]
_0804C73E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start ZebesianAquaXMovement
ZebesianAquaXMovement: @ 0x0804C744
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r2, _0804C768 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0804C790
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0804C76C
	ldrh r0, [r4, #4]
	adds r0, #0x38
	b _0804C770
	.align 2, 0
_0804C768: .4byte gCurrentSprite
_0804C76C:
	ldrh r0, [r4, #4]
	adds r0, #0x28
_0804C770:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r4, #2]
	subs r0, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804C78C @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _0804C7B8
	ldrh r0, [r4, #4]
	adds r0, r5, r0
	b _0804C7C4
	.align 2, 0
_0804C78C: .4byte gPreviousCollisionCheck
_0804C790:
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #2
	bne _0804C7A0
	ldrh r0, [r4, #4]
	subs r0, #0x38
	b _0804C7A4
_0804C7A0:
	ldrh r0, [r4, #4]
	subs r0, #0x28
_0804C7A4:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r4, #2]
	subs r0, #0x20
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804C7BC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0x11
	bne _0804C7C0
_0804C7B8:
	movs r0, #1
	b _0804C7C8
	.align 2, 0
_0804C7BC: .4byte gPreviousCollisionCheck
_0804C7C0:
	ldrh r0, [r4, #4]
	subs r0, r0, r5
_0804C7C4:
	strh r0, [r4, #4]
	movs r0, #0
_0804C7C8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start ZebesianAquaTurningIntoX
ZebesianAquaTurningIntoX: @ 0x0804C7D0
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _0804C80C @ =gCurrentSprite
	ldrb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r3, [r0]
	adds r0, #7
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4, #2]
	subs r0, #0x50
	str r0, [sp, #4]
	ldrh r0, [r4, #4]
	subs r0, #0x10
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	movs r0, #0x38
	movs r2, #0
	bl SpriteSpawnNewXParasite
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C80C: .4byte gCurrentSprite

	thumb_func_start ZebesianAquaInit
ZebesianAquaInit: @ 0x0804C810
	push {lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r2, _0804C83C @ =gCurrentSprite
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804C840
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0804C840
	strh r0, [r2]
	b _0804C8B0
	.align 2, 0
_0804C83C: .4byte gCurrentSprite
_0804C840:
	ldr r3, _0804C89C @ =gCurrentSprite
	adds r2, r3, #0
	adds r2, #0x25
	movs r1, #0
	movs r0, #2
	strb r0, [r2]
	strb r1, [r3, #0x1c]
	strh r1, [r3, #0x16]
	ldr r0, _0804C8A0 @ =0x08381764
	str r0, [r3, #0x18]
	adds r1, r3, #0
	adds r1, #0x27
	movs r0, #0x28
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _0804C8A4 @ =0x0000FF90
	strh r0, [r3, #0xa]
	adds r0, #0x68
	strh r0, [r3, #0xc]
	subs r0, #0x38
	strh r0, [r3, #0xe]
	movs r0, #0x40
	strh r0, [r3, #0x10]
	ldr r2, _0804C8A8 @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0804C8AC
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r3, #6]
	b _0804C8B0
	.align 2, 0
_0804C89C: .4byte gCurrentSprite
_0804C8A0: .4byte 0x08381764
_0804C8A4: .4byte 0x0000FF90
_0804C8A8: .4byte sPrimarySpriteStats
_0804C8AC:
	movs r0, #1
	strb r0, [r1]
_0804C8B0:
	pop {r0}
	bx r0

	thumb_func_start ZebesianAquaIdleInit
ZebesianAquaIdleInit: @ 0x0804C8B4
	push {r4, lr}
	ldr r1, _0804C8D8 @ =gCurrentSprite
	ldrh r0, [r1, #4]
	movs r3, #0
	movs r4, #0
	strh r0, [r1, #8]
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #2
	strb r0, [r2]
	strb r3, [r1, #0x1c]
	strh r4, [r1, #0x16]
	ldr r0, _0804C8DC @ =0x08381764
	str r0, [r1, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804C8D8: .4byte gCurrentSprite
_0804C8DC: .4byte 0x08381764

	thumb_func_start ZebesianAquaIdle
ZebesianAquaIdle: @ 0x0804C8E0
	push {r4, r5, lr}
	movs r0, #6
	bl ZebesianAquaXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804C900
	ldr r2, _0804C8FC @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
	adds r5, r2, #0
	b _0804C938
	.align 2, 0
_0804C8FC: .4byte gCurrentSprite
_0804C900:
	ldr r2, _0804C920 @ =gCurrentSprite
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _0804C924
	ldrh r0, [r5, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r5, #4]
	cmp r0, r1
	bge _0804C938
	b _0804C930
	.align 2, 0
_0804C920: .4byte gCurrentSprite
_0804C924:
	ldrh r0, [r5, #8]
	ldr r1, _0804C98C @ =0xFFFFFE00
	adds r0, r0, r1
	ldrh r1, [r5, #4]
	cmp r0, r1
	ble _0804C938
_0804C930:
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
_0804C938:
	ldr r0, _0804C990 @ =gEquipment
	ldrb r1, [r0, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _0804C9BE
	ldr r2, _0804C994 @ =gSamusData
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r4, r5, #0
	ldrh r0, [r4, #2]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, r2
	ble _0804C9A0
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804C998 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804C9BE
	ldr r0, _0804C99C @ =gCurrentAffectingClipdata
	ldrh r0, [r0, #2]
	cmp r0, #1
	bne _0804C9BE
	ldrh r0, [r4, #2]
	subs r0, #2
	strh r0, [r4, #2]
	b _0804C9BE
	.align 2, 0
_0804C98C: .4byte 0xFFFFFE00
_0804C990: .4byte gEquipment
_0804C994: .4byte gSamusData
_0804C998: .4byte gPreviousCollisionCheck
_0804C99C: .4byte gCurrentAffectingClipdata
_0804C9A0:
	adds r0, r1, #0
	adds r0, #0x40
	cmp r0, r2
	bge _0804C9BE
	ldrh r0, [r5, #2]
	ldrh r1, [r5, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804CA04 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804C9BE
	ldrh r0, [r5, #2]
	adds r0, #2
	strh r0, [r5, #2]
_0804C9BE:
	ldr r0, _0804CA08 @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804CA5C
	movs r0, #0xa0
	movs r1, #0xc8
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	bne _0804CA5C
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #0xa0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	adds r1, r0, #0
	ldr r3, _0804CA0C @ =gCurrentSprite
	ldrh r2, [r3]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0804CA22
	cmp r1, #8
	bne _0804CA1C
	ldr r0, _0804CA10 @ =gEquipment
	ldrb r1, [r0, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804CA14
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x29
	b _0804CA5A
	.align 2, 0
_0804CA04: .4byte gPreviousCollisionCheck
_0804CA08: .4byte 0x03001346
_0804CA0C: .4byte gCurrentSprite
_0804CA10: .4byte gEquipment
_0804CA14:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x2b
	b _0804CA5A
_0804CA1C:
	cmp r1, #4
	bne _0804CA5C
	b _0804CA4C
_0804CA22:
	cmp r1, #4
	bne _0804CA48
	ldr r0, _0804CA3C @ =gEquipment
	ldrb r1, [r0, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804CA40
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x29
	b _0804CA5A
	.align 2, 0
_0804CA3C: .4byte gEquipment
_0804CA40:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x2b
	b _0804CA5A
_0804CA48:
	cmp r1, #8
	bne _0804CA5C
_0804CA4C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	bne _0804CA5C
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #3
_0804CA5A:
	strb r0, [r1]
_0804CA5C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianAquaLungeInit
ZebesianAquaLungeInit: @ 0x0804CA64
	ldr r1, _0804CA78 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x2c
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x1e
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804CA78: .4byte gCurrentSprite

	thumb_func_start ZebesianAquaLunge
ZebesianAquaLunge: @ 0x0804CA7C
	push {r4, r5, lr}
	ldr r4, _0804CAF8 @ =gCurrentSprite
	ldrb r0, [r4, #0x1c]
	adds r0, #4
	strb r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804CAA0
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804CB14
	ldr r0, _0804CAFC @ =0x000001BD
	bl SoundPlayNotAlreadyPlaying
_0804CAA0:
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804CB00 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804CAB6
	ldrh r0, [r4, #2]
	adds r0, #2
	strh r0, [r4, #2]
_0804CAB6:
	movs r0, #0x10
	bl ZebesianAquaXMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804CB0C
	ldr r0, _0804CB04 @ =0x03001346
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804CB14
	movs r5, #0xa0
	lsls r5, r5, #1
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	cmp r0, #0
	bne _0804CB14
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r5, #0
	bl SpriteUtilCheckSamusNearSpriteLeftRight
	adds r2, r0, #0
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804CB08
	cmp r2, #4
	bne _0804CB14
	b _0804CB0C
	.align 2, 0
_0804CAF8: .4byte gCurrentSprite
_0804CAFC: .4byte 0x000001BD
_0804CB00: .4byte gPreviousCollisionCheck
_0804CB04: .4byte 0x03001346
_0804CB08:
	cmp r2, #8
	bne _0804CB14
_0804CB0C:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
_0804CB14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianAquaShootingInit
ZebesianAquaShootingInit: @ 0x0804CB1C
	ldr r1, _0804CB34 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #0x2a
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0804CB38 @ =0x083817C4
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_0804CB34: .4byte gCurrentSprite
_0804CB38: .4byte 0x083817C4

	thumb_func_start ZebesianAquaShooting
ZebesianAquaShooting: @ 0x0804CB3C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r2, _0804CB88 @ =gSamusData
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r4, _0804CB8C @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, r2
	ble _0804CB98
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804CB90 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804CBB6
	ldr r0, _0804CB94 @ =gCurrentAffectingClipdata
	ldrh r0, [r0, #2]
	cmp r0, #1
	bne _0804CBB6
	ldrh r0, [r4, #2]
	subs r0, #1
	b _0804CBB4
	.align 2, 0
_0804CB88: .4byte gSamusData
_0804CB8C: .4byte gCurrentSprite
_0804CB90: .4byte gPreviousCollisionCheck
_0804CB94: .4byte gCurrentAffectingClipdata
_0804CB98:
	adds r0, r1, #0
	adds r0, #0x20
	cmp r0, r2
	bge _0804CBB6
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804CBD0 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804CBB6
	ldrh r0, [r4, #2]
	adds r0, #1
_0804CBB4:
	strh r0, [r4, #2]
_0804CBB6:
	movs r0, #8
	bl ZebesianAquaXMovement
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804CBD8
	ldr r0, _0804CBD4 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
	b _0804CC6C
	.align 2, 0
_0804CBD0: .4byte gPreviousCollisionCheck
_0804CBD4: .4byte gCurrentSprite
_0804CBD8:
	ldr r4, _0804CC30 @ =gCurrentSprite
	ldrh r0, [r4, #0x16]
	cmp r0, #7
	bne _0804CC6C
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	bne _0804CC6C
	ldrh r1, [r4]
	movs r6, #0x40
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0804CC34
	ldrb r2, [r4, #0x1f]
	adds r5, r4, #0
	adds r5, #0x23
	ldrb r3, [r5]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x70
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x66
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r5]
	ldrh r0, [r4, #2]
	subs r0, #0x2c
	str r0, [sp]
	ldrh r0, [r4, #4]
	adds r0, #0x20
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0x66
	movs r1, #1
	bl SpriteSpawnSecondary
	b _0804CC6C
	.align 2, 0
_0804CC30: .4byte gCurrentSprite
_0804CC34:
	ldrb r2, [r4, #0x1f]
	adds r6, r4, #0
	adds r6, #0x23
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x40
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x70
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x66
	movs r1, #0
	bl SpriteSpawnSecondary
	ldrb r2, [r4, #0x1f]
	ldrb r3, [r6]
	ldrh r0, [r4, #2]
	subs r0, #0x2c
	str r0, [sp]
	ldrh r0, [r4, #4]
	subs r0, #0x20
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x66
	movs r1, #1
	bl SpriteSpawnSecondary
_0804CC6C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ZebesianAquaTurningAroundInit
ZebesianAquaTurningAroundInit: @ 0x0804CC74
	ldr r1, _0804CC8C @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x24
	movs r2, #0
	movs r0, #4
	strb r0, [r3]
	strb r2, [r1, #0x1c]
	strh r2, [r1, #0x16]
	ldr r0, _0804CC90 @ =0x0838179C
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_0804CC8C: .4byte gCurrentSprite
_0804CC90: .4byte 0x0838179C

	thumb_func_start ZebesianAquaTurningAround
ZebesianAquaTurningAround: @ 0x0804CC94
	push {r4, lr}
	ldr r0, _0804CCE0 @ =gEquipment
	ldrb r1, [r0, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _0804CD18
	ldr r2, _0804CCE4 @ =gSamusData
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	ldrh r2, [r2, #0x18]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r4, _0804CCE8 @ =gCurrentSprite
	ldrh r0, [r4, #2]
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, r2
	ble _0804CCF0
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804CCEC @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804CD18
	ldrh r0, [r4, #2]
	adds r0, #2
	b _0804CD16
	.align 2, 0
_0804CCE0: .4byte gEquipment
_0804CCE4: .4byte gSamusData
_0804CCE8: .4byte gCurrentSprite
_0804CCEC: .4byte gPreviousCollisionCheck
_0804CCF0:
	adds r0, r1, #0
	adds r0, #0x20
	cmp r0, r2
	bge _0804CD18
	ldrh r0, [r4, #2]
	subs r0, #0x60
	ldrh r1, [r4, #4]
	bl SpriteUtilCheckCollisionAtPosition
	ldr r0, _0804CD44 @ =gPreviousCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804CD18
	ldr r0, _0804CD48 @ =gCurrentAffectingClipdata
	ldrh r0, [r0, #2]
	cmp r0, #1
	bne _0804CD18
	ldrh r0, [r4, #2]
	subs r0, #2
_0804CD16:
	strh r0, [r4, #2]
_0804CD18:
	ldr r2, _0804CD4C @ =gCurrentSprite
	ldrh r0, [r2, #0x16]
	cmp r0, #1
	bne _0804CD2E
	ldrb r0, [r2, #0x1c]
	cmp r0, #4
	bne _0804CD2E
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_0804CD2E:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804CD3E
	ldr r0, _0804CD4C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0804CD3E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CD44: .4byte gPreviousCollisionCheck
_0804CD48: .4byte gCurrentAffectingClipdata
_0804CD4C: .4byte gCurrentSprite

	thumb_func_start ZebesianAquaProjectileInit
ZebesianAquaProjectileInit: @ 0x0804CD50
	push {r4, r5, lr}
	ldr r0, _0804CDC4 @ =gCurrentSprite
	mov ip, r0
	ldrh r0, [r0]
	ldr r3, _0804CDC8 @ =0x0000FFFB
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
	strb r1, [r0]
	ldr r0, _0804CDCC @ =0x0000FFF4
	mov r1, ip
	strh r0, [r1, #0xa]
	movs r0, #0xc
	strh r0, [r1, #0xc]
	ldr r0, _0804CDD0 @ =0x0838182C
	str r0, [r1, #0x18]
	strb r5, [r1, #0x1c]
	strh r4, [r1, #0x16]
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
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r1, ip
	cmp r2, #0
	beq _0804CDD4
	strh r4, [r1, #0xe]
	movs r0, #0x18
	strh r0, [r1, #0x10]
	b _0804CDDA
	.align 2, 0
_0804CDC4: .4byte gCurrentSprite
_0804CDC8: .4byte 0x0000FFFB
_0804CDCC: .4byte 0x0000FFF4
_0804CDD0: .4byte 0x0838182C
_0804CDD4:
	ldr r0, _0804CDF0 @ =0x0000FFE8
	strh r0, [r1, #0xe]
	strh r2, [r1, #0x10]
_0804CDDA:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _0804CDE8
	movs r0, #0xde
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0804CDE8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804CDF0: .4byte 0x0000FFE8

	thumb_func_start ZebesianAqua
ZebesianAqua: @ 0x0804CDF4
	push {r4, lr}
	ldr r4, _0804CE20 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0804CE0E
	movs r0, #0xaf
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0804CE0E:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804CE24
	bl SpriteUtilUpdateFreezeTimer
	b _0804CFFC
	.align 2, 0
_0804CE20: .4byte gCurrentSprite
_0804CE24:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0804CE30
	b _0804CFFC
_0804CE30:
	lsls r0, r0, #2
	ldr r1, _0804CE3C @ =_0804CE40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804CE3C: .4byte _0804CE40
_0804CE40: @ jump table
	.4byte _0804CFB0 @ case 0
	.4byte _0804CFB6 @ case 1
	.4byte _0804CFBC @ case 2
	.4byte _0804CFC2 @ case 3
	.4byte _0804CFC6 @ case 4
	.4byte _0804CFFC @ case 5
	.4byte _0804CFFC @ case 6
	.4byte _0804CFFC @ case 7
	.4byte _0804CFFC @ case 8
	.4byte _0804CFFC @ case 9
	.4byte _0804CFFC @ case 10
	.4byte _0804CFFC @ case 11
	.4byte _0804CFFC @ case 12
	.4byte _0804CFFC @ case 13
	.4byte _0804CFFC @ case 14
	.4byte _0804CFFC @ case 15
	.4byte _0804CFFC @ case 16
	.4byte _0804CFFC @ case 17
	.4byte _0804CFFC @ case 18
	.4byte _0804CFFC @ case 19
	.4byte _0804CFFC @ case 20
	.4byte _0804CFFC @ case 21
	.4byte _0804CFFC @ case 22
	.4byte _0804CFFC @ case 23
	.4byte _0804CFFC @ case 24
	.4byte _0804CFFC @ case 25
	.4byte _0804CFFC @ case 26
	.4byte _0804CFFC @ case 27
	.4byte _0804CFFC @ case 28
	.4byte _0804CFFC @ case 29
	.4byte _0804CFFC @ case 30
	.4byte _0804CFFC @ case 31
	.4byte _0804CFFC @ case 32
	.4byte _0804CFFC @ case 33
	.4byte _0804CFFC @ case 34
	.4byte _0804CFFC @ case 35
	.4byte _0804CFFC @ case 36
	.4byte _0804CFFC @ case 37
	.4byte _0804CFFC @ case 38
	.4byte _0804CFFC @ case 39
	.4byte _0804CFFC @ case 40
	.4byte _0804CFCC @ case 41
	.4byte _0804CFD0 @ case 42
	.4byte _0804CFD6 @ case 43
	.4byte _0804CFDA @ case 44
	.4byte _0804CFFC @ case 45
	.4byte _0804CFFC @ case 46
	.4byte _0804CFFC @ case 47
	.4byte _0804CFFC @ case 48
	.4byte _0804CFFC @ case 49
	.4byte _0804CFFC @ case 50
	.4byte _0804CFFC @ case 51
	.4byte _0804CFFC @ case 52
	.4byte _0804CFFC @ case 53
	.4byte _0804CFFC @ case 54
	.4byte _0804CFFC @ case 55
	.4byte _0804CFFC @ case 56
	.4byte _0804CFFC @ case 57
	.4byte _0804CFFC @ case 58
	.4byte _0804CFFC @ case 59
	.4byte _0804CFFC @ case 60
	.4byte _0804CFFC @ case 61
	.4byte _0804CFFC @ case 62
	.4byte _0804CFFC @ case 63
	.4byte _0804CFFC @ case 64
	.4byte _0804CFFC @ case 65
	.4byte _0804CFFC @ case 66
	.4byte _0804CFFC @ case 67
	.4byte _0804CFFC @ case 68
	.4byte _0804CFFC @ case 69
	.4byte _0804CFFC @ case 70
	.4byte _0804CFFC @ case 71
	.4byte _0804CFFC @ case 72
	.4byte _0804CFFC @ case 73
	.4byte _0804CFFC @ case 74
	.4byte _0804CFFC @ case 75
	.4byte _0804CFFC @ case 76
	.4byte _0804CFFC @ case 77
	.4byte _0804CFFC @ case 78
	.4byte _0804CFFC @ case 79
	.4byte _0804CFFC @ case 80
	.4byte _0804CFFC @ case 81
	.4byte _0804CFFC @ case 82
	.4byte _0804CFFC @ case 83
	.4byte _0804CFFC @ case 84
	.4byte _0804CFFC @ case 85
	.4byte _0804CFFC @ case 86
	.4byte _0804CFE0 @ case 87
	.4byte _0804CFE4 @ case 88
	.4byte _0804CFEA @ case 89
	.4byte _0804CFEE @ case 90
	.4byte _0804CFF4 @ case 91
_0804CFB0:
	bl ZebesianAquaInit
	b _0804CFFC
_0804CFB6:
	bl ZebesianAquaIdleInit
	b _0804CFFC
_0804CFBC:
	bl ZebesianAquaIdle
	b _0804CFFC
_0804CFC2:
	bl ZebesianAquaTurningAroundInit
_0804CFC6:
	bl ZebesianAquaTurningAround
	b _0804CFFC
_0804CFCC:
	bl ZebesianAquaShootingInit
_0804CFD0:
	bl ZebesianAquaShooting
	b _0804CFFC
_0804CFD6:
	bl ZebesianAquaLungeInit
_0804CFDA:
	bl ZebesianAquaLunge
	b _0804CFFC
_0804CFE0:
	bl SpriteDyingInit
_0804CFE4:
	bl SpriteDying
	b _0804CFFC
_0804CFEA:
	bl ZebesianAquaInit
_0804CFEE:
	bl SpriteSpawningFromX
	b _0804CFFC
_0804CFF4:
	bl ZebesianAquaTurningIntoX
	bl XParasiteInit
_0804CFFC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ZebesianAquaProjectile
ZebesianAquaProjectile: @ 0x0804D004
	push {r4, lr}
	ldr r4, _0804D028 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804D016
	bl ZebesianAquaProjectileInit
_0804D016:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804D02C
	ldrh r0, [r4, #4]
	adds r0, #0x10
	b _0804D030
	.align 2, 0
_0804D028: .4byte gCurrentSprite
_0804D02C:
	ldrh r0, [r4, #4]
	subs r0, #0x10
_0804D030:
	strh r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start DachoraCheckDoHeadMovement
DachoraCheckDoHeadMovement: @ 0x0804D038
	push {r4, lr}
	movs r4, #1
	ldr r0, _0804D050 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #0xc
	bhi _0804D0EC
	lsls r0, r0, #2
	ldr r1, _0804D054 @ =_0804D058
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804D050: .4byte gSpriteRandomNumber
_0804D054: .4byte _0804D058
_0804D058: @ jump table
	.4byte _0804D08C @ case 0
	.4byte _0804D08C @ case 1
	.4byte _0804D08C @ case 2
	.4byte _0804D08C @ case 3
	.4byte _0804D0A4 @ case 4
	.4byte _0804D0A4 @ case 5
	.4byte _0804D0A4 @ case 6
	.4byte _0804D0A4 @ case 7
	.4byte _0804D0BC @ case 8
	.4byte _0804D0BC @ case 9
	.4byte _0804D0D4 @ case 10
	.4byte _0804D0D4 @ case 11
	.4byte _0804D0D4 @ case 12
_0804D08C:
	ldr r1, _0804D0A0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	strb r3, [r1]
	b _0804D0EE
	.align 2, 0
_0804D0A0: .4byte gCurrentSprite
_0804D0A4:
	ldr r1, _0804D0B8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	b _0804D0EE
	.align 2, 0
_0804D0B8: .4byte gCurrentSprite
_0804D0BC:
	ldr r1, _0804D0D0 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #2
	strb r0, [r1]
	b _0804D0EE
	.align 2, 0
_0804D0D0: .4byte gCurrentSprite
_0804D0D4:
	ldr r1, _0804D0E8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #3
	strb r0, [r1]
	b _0804D0EE
	.align 2, 0
_0804D0E8: .4byte gCurrentSprite
_0804D0EC:
	movs r4, #0
_0804D0EE:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start DachoraInit
DachoraInit: @ 0x0804D0F8
	push {r4, r5, r6, lr}
	bl EventCheckAfter_AnimalsReleased
	adds r6, r0, #0
	cmp r6, #0
	beq _0804D110
	ldr r1, _0804D10C @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	b _0804D17C
	.align 2, 0
_0804D10C: .4byte gCurrentSprite
_0804D110:
	ldr r5, _0804D184 @ =gCurrentSprite
	adds r2, r5, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x25
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x22
	movs r0, #0xe
	strb r0, [r1]
	subs r1, #1
	movs r0, #3
	strb r0, [r1]
	adds r1, #6
	movs r0, #0x30
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x20
	strb r0, [r1]
	movs r4, #0
	ldr r1, _0804D188 @ =0x0000FFFC
	strh r1, [r5, #0xa]
	movs r0, #4
	strh r0, [r5, #0xc]
	strh r1, [r5, #0xe]
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #2]
	subs r0, #0x20
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	strh r0, [r5, #8]
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0804D18C @ =0x0838451C
	str r0, [r5, #0x18]
	strb r4, [r5, #0x1c]
	strh r6, [r5, #0x16]
	adds r0, r5, #0
	adds r0, #0x30
	strb r4, [r0]
	adds r1, #0xa
	movs r0, #0xb4
	strb r0, [r1]
_0804D17C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D184: .4byte gCurrentSprite
_0804D188: .4byte 0x0000FFFC
_0804D18C: .4byte 0x0838451C

	thumb_func_start DachoraIdleInit
DachoraIdleInit: @ 0x0804D190
	ldr r3, _0804D1BC @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0804D1C0 @ =0x0838451C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x30
	strb r1, [r0]
	ldr r0, _0804D1C4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x3c
	adds r1, r3, #0
	adds r1, #0x2e
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804D1BC: .4byte gCurrentSprite
_0804D1C0: .4byte 0x0838451C
_0804D1C4: .4byte gSpriteRandomNumber

	thumb_func_start DachoraIdle
DachoraIdle: @ 0x0804D1C8
	push {r4, r5, r6, lr}
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _0804D228
	ldr r2, _0804D214 @ =gSpriteData
	ldr r0, _0804D218 @ =gBossWork2
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _0804D276
	ldr r0, _0804D21C @ =gAbilityRestingXPosition
	ldr r2, _0804D220 @ =0xFFFFFF00
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0804D224 @ =gCurrentSprite
	ldrh r2, [r3, #4]
	adds r0, r1, #0
	subs r0, #0x20
	cmp r2, r0
	ble _0804D276
	adds r0, #0x40
	cmp r2, r0
	bge _0804D276
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	b _0804D2D4
	.align 2, 0
_0804D214: .4byte gSpriteData
_0804D218: .4byte gBossWork2
_0804D21C: .4byte gAbilityRestingXPosition
_0804D220: .4byte 0xFFFFFF00
_0804D224: .4byte gCurrentSprite
_0804D228:
	ldr r3, _0804D254 @ =gCurrentSprite
	ldrh r2, [r3, #4]
	ldr r0, _0804D258 @ =gAbilityRestingXPosition
	ldrh r1, [r0]
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r1, r4
	cmp r2, r0
	bgt _0804D242
	ldr r4, _0804D25C @ =0xFFFFFE40
	adds r0, r1, r4
	cmp r2, r0
	bge _0804D276
_0804D242:
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D260
	subs r0, #1
	strb r0, [r1]
	b _0804D276
	.align 2, 0
_0804D254: .4byte gCurrentSprite
_0804D258: .4byte gAbilityRestingXPosition
_0804D25C: .4byte 0xFFFFFE40
_0804D260:
	ldr r0, _0804D2AC @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _0804D276
	bl DachoraCheckDoHeadMovement
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804D2D4
_0804D276:
	ldr r2, _0804D2B0 @ =gCurrentSprite
	adds r5, r2, #0
	adds r5, #0x30
	ldrb r3, [r5]
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
	lsrs r4, r0, #0x1a
	adds r6, r4, #0
	cmp r1, #0xf
	bhi _0804D28E
	adds r0, r3, #1
	strb r0, [r5]
_0804D28E:
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804D2B4
	ldrh r0, [r2, #8]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r2, #4]
	cmp r0, r1
	blt _0804D2C0
	adds r0, r1, r4
	b _0804D2D2
	.align 2, 0
_0804D2AC: .4byte gFrameCounter8Bit
_0804D2B0: .4byte gCurrentSprite
_0804D2B4:
	ldrh r0, [r2, #8]
	ldr r4, _0804D2CC @ =0xFFFFFC80
	adds r0, r0, r4
	ldrh r1, [r2, #4]
	cmp r0, r1
	ble _0804D2D0
_0804D2C0:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #3
	strb r0, [r1]
	b _0804D2D4
	.align 2, 0
_0804D2CC: .4byte 0xFFFFFC80
_0804D2D0:
	subs r0, r1, r6
_0804D2D2:
	strh r0, [r2, #4]
_0804D2D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DachoraStandingInit
DachoraStandingInit: @ 0x0804D2DC
	ldr r0, _0804D2F8 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r3, #0
	movs r1, #8
	strb r1, [r2]
	ldr r1, _0804D2FC @ =0x0838450C
	str r1, [r0, #0x18]
	strb r3, [r0, #0x1c]
	strh r3, [r0, #0x16]
	adds r0, #0x2e
	movs r1, #0xb
	strb r1, [r0]
	bx lr
	.align 2, 0
_0804D2F8: .4byte gCurrentSprite
_0804D2FC: .4byte 0x0838450C

	thumb_func_start DachoraStanding
DachoraStanding: @ 0x0804D300
	push {lr}
	ldr r1, _0804D320 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804D31A
	adds r1, #0x24
	movs r0, #9
	strb r0, [r1]
_0804D31A:
	pop {r0}
	bx r0
	.align 2, 0
_0804D320: .4byte gCurrentSprite

	thumb_func_start DachoraHeadMovementInit
DachoraHeadMovementInit: @ 0x0804D324
	push {lr}
	ldr r0, _0804D340 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0xa
	strb r1, [r2]
	adds r1, r0, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #1
	bne _0804D348
	ldr r0, _0804D344 @ =0x083845C4
	b _0804D362
	.align 2, 0
_0804D340: .4byte gCurrentSprite
_0804D344: .4byte 0x083845C4
_0804D348:
	cmp r1, #2
	bne _0804D354
	ldr r0, _0804D350 @ =0x083845E4
	b _0804D362
	.align 2, 0
_0804D350: .4byte 0x083845E4
_0804D354:
	cmp r1, #3
	bne _0804D360
	ldr r0, _0804D35C @ =0x083845FC
	b _0804D362
	.align 2, 0
_0804D35C: .4byte 0x083845FC
_0804D360:
	ldr r0, _0804D370 @ =0x08384584
_0804D362:
	str r0, [r2, #0x18]
	movs r0, #0
	strb r0, [r2, #0x1c]
	strh r0, [r2, #0x16]
	pop {r0}
	bx r0
	.align 2, 0
_0804D370: .4byte 0x08384584

	thumb_func_start DachoraHeadMovement
DachoraHeadMovement: @ 0x0804D374
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804D3AE
	ldr r1, _0804D3A0 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	ldr r2, _0804D3A4 @ =gFrameCounter8Bit
	cmp r0, #1
	bne _0804D392
	ldrb r0, [r2]
	cmp r0, #0xc
	bhi _0804D3AE
_0804D392:
	ldrb r0, [r2]
	cmp r0, #2
	bhi _0804D3A8
	adds r1, #0x24
	movs r0, #3
	b _0804D3AC
	.align 2, 0
_0804D3A0: .4byte gCurrentSprite
_0804D3A4: .4byte gSpriteRandomNumber
_0804D3A8:
	adds r1, #0x24
	movs r0, #1
_0804D3AC:
	strb r0, [r1]
_0804D3AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DachoraTurningAroundInit
DachoraTurningAroundInit: @ 0x0804D3B4
	ldr r1, _0804D3CC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r0, _0804D3D0 @ =0x08384554
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804D3CC: .4byte gCurrentSprite
_0804D3D0: .4byte 0x08384554

	thumb_func_start DachoraTurningAround
DachoraTurningAround: @ 0x0804D3D4
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804D414
	ldr r2, _0804D408 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0804D40C @ =0x0838456C
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
	adds r2, #0x22
	ldrb r0, [r2]
	cmp r0, #0xe
	bne _0804D410
	movs r0, #0xf
	b _0804D412
	.align 2, 0
_0804D408: .4byte gCurrentSprite
_0804D40C: .4byte 0x0838456C
_0804D410:
	movs r0, #0xe
_0804D412:
	strb r0, [r2]
_0804D414:
	pop {r0}
	bx r0

	thumb_func_start DachoraTurningAroundSecondPart
DachoraTurningAroundSecondPart: @ 0x0804D418
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804D42A
	ldr r0, _0804D430 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0804D42A:
	pop {r0}
	bx r0
	.align 2, 0
_0804D430: .4byte gCurrentSprite

	thumb_func_start DachoraTurningAroundWhileLeavingInit
DachoraTurningAroundWhileLeavingInit: @ 0x0804D434
	ldr r1, _0804D44C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x38
	strb r0, [r2]
	ldr r0, _0804D450 @ =0x08384554
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804D44C: .4byte gCurrentSprite
_0804D450: .4byte 0x08384554

	thumb_func_start DachoraTurningAroundWhileLeaving
DachoraTurningAroundWhileLeaving: @ 0x0804D454
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804D47A
	ldr r2, _0804D480 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x3a
	strb r0, [r1]
	ldr r0, _0804D484 @ =0x0838456C
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_0804D47A:
	pop {r0}
	bx r0
	.align 2, 0
_0804D480: .4byte gCurrentSprite
_0804D484: .4byte 0x0838456C

	thumb_func_start DachoraTurningAroundWhileLeavingSecondPart
DachoraTurningAroundWhileLeavingSecondPart: @ 0x0804D488
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804D49A
	ldr r0, _0804D4A0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x19
	strb r1, [r0]
_0804D49A:
	pop {r0}
	bx r0
	.align 2, 0
_0804D4A0: .4byte gCurrentSprite

	thumb_func_start DachoraLeavingEnclosureInit
DachoraLeavingEnclosureInit: @ 0x0804D4A4
	ldr r3, _0804D4C4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	subs r1, #3
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804D4C4: .4byte gCurrentSprite

	thumb_func_start DachoraLeavingEnclosure
DachoraLeavingEnclosure: @ 0x0804D4C8
	push {r4, r5, lr}
	ldr r2, _0804D4FC @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r3, [r0]
	ldr r1, _0804D500 @ =0x0838188C
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _0804D504 @ =0x00007FFF
	cmp r1, r0
	bne _0804D512
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804D508
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	b _0804D534
	.align 2, 0
_0804D4FC: .4byte gCurrentSprite
_0804D500: .4byte 0x0838188C
_0804D504: .4byte 0x00007FFF
_0804D508:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x37
	strb r0, [r1]
	b _0804D534
_0804D512:
	adds r0, r3, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804D52E
	ldrh r0, [r2, #4]
	adds r0, #4
	b _0804D532
_0804D52E:
	ldrh r0, [r2, #4]
	subs r0, #4
_0804D532:
	strh r0, [r2, #4]
_0804D534:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DachoraWalkingToWaitingSpotInit
DachoraWalkingToWaitingSpotInit: @ 0x0804D53C
	ldr r1, _0804D550 @ =gCurrentSprite
	ldr r0, _0804D554 @ =0x0838451C
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804D550: .4byte gCurrentSprite
_0804D554: .4byte 0x0838451C

	thumb_func_start DachoraWalkingToWaitingSpot
DachoraWalkingToWaitingSpot: @ 0x0804D558
	push {lr}
	ldr r1, _0804D570 @ =gCurrentSprite
	ldrh r2, [r1, #4]
	ldr r0, _0804D574 @ =gAbilityRestingXPosition
	ldrh r0, [r0]
	subs r0, #0xc0
	cmp r2, r0
	bge _0804D578
	adds r0, r2, #4
	strh r0, [r1, #4]
	b _0804D588
	.align 2, 0
_0804D570: .4byte gCurrentSprite
_0804D574: .4byte gAbilityRestingXPosition
_0804D578:
	ldr r0, _0804D58C @ =0x083846CC
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1b
	strb r0, [r1]
_0804D588:
	pop {r0}
	bx r0
	.align 2, 0
_0804D58C: .4byte 0x083846CC

	thumb_func_start DachorawaitingForOthers
DachorawaitingForOthers: @ 0x0804D590
	push {r4, r5, lr}
	ldr r1, _0804D608 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0804D5A8
	ldrb r0, [r1, #0x1c]
	cmp r0, #1
	bne _0804D5A8
	movs r0, #0x91
	lsls r0, r0, #1
	bl SoundPlay
_0804D5A8:
	movs r4, #0
	movs r3, #0
	ldr r5, _0804D60C @ =gSpriteData
_0804D5AE:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #3
	adds r2, r0, r5
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804D5E4
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0804D5E4
	ldrb r0, [r2, #0x1d]
	cmp r0, #0xb6
	bne _0804D5E4
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1c
	bne _0804D5E4
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0804D5E4:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x17
	bls _0804D5AE
	cmp r4, #3
	bne _0804D602
	ldr r1, _0804D608 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #0x1c
	strb r0, [r2]
	adds r1, #0x2e
	movs r0, #0x3c
	strb r0, [r1]
_0804D602:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D608: .4byte gCurrentSprite
_0804D60C: .4byte gSpriteData

	thumb_func_start DachoraWaitingToSpawnBaby
DachoraWaitingToSpawnBaby: @ 0x0804D610
	push {r4, lr}
	sub sp, #0xc
	ldr r1, _0804D674 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0804D62A
	ldrb r0, [r1, #0x1c]
	cmp r0, #1
	bne _0804D62A
	movs r0, #0x91
	lsls r0, r0, #1
	bl SoundPlay
_0804D62A:
	ldr r0, _0804D674 @ =gCurrentSprite
	mov ip, r0
	mov r4, ip
	adds r4, #0x2e
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804D66C
	mov r1, ip
	adds r1, #0x24
	movs r0, #0x1d
	strb r0, [r1]
	mov r1, ip
	ldrb r2, [r1, #0x1f]
	mov r0, ip
	adds r0, #0x23
	ldrb r3, [r0]
	ldrh r0, [r1, #2]
	subs r0, #0x20
	str r0, [sp]
	ldrh r0, [r1, #4]
	subs r0, #0xc0
	str r0, [sp, #4]
	movs r0, #0x40
	str r0, [sp, #8]
	movs r0, #0x69
	movs r1, #0
	bl SpriteSpawnSecondary
	movs r0, #0x78
	strb r0, [r4]
_0804D66C:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D674: .4byte gCurrentSprite

	thumb_func_start DachoraWaitingForBaby
DachoraWaitingForBaby: @ 0x0804D678
	push {r4, r5, lr}
	ldr r1, _0804D6D4 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0804D690
	ldrb r0, [r1, #0x1c]
	cmp r0, #1
	bne _0804D690
	movs r0, #0x91
	lsls r0, r0, #1
	bl SoundPlay
_0804D690:
	ldr r4, _0804D6D4 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0804D6CE
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1e
	strb r0, [r1]
	ldr r0, _0804D6D8 @ =gPreventMovementTimer
	strh r2, [r0]
	ldr r1, _0804D6DC @ =sSamusSetPoseFunctionPointer
	ldr r0, _0804D6E0 @ =gSamusData
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x3b
	bl _call_via_r1
	movs r0, #0x3c
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
_0804D6CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D6D4: .4byte gCurrentSprite
_0804D6D8: .4byte gPreventMovementTimer
_0804D6DC: .4byte sSamusSetPoseFunctionPointer
_0804D6E0: .4byte gSamusData

	thumb_func_start DachoraBowing
DachoraBowing: @ 0x0804D6E4
	push {r4, r5, lr}
	ldr r4, _0804D710 @ =gCurrentSprite
	adds r5, r4, #0
	adds r5, #0x2e
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804D732
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804D71C
	ldr r0, _0804D714 @ =0x08384584
	str r0, [r4, #0x18]
	strb r1, [r4, #0x1c]
	strh r1, [r4, #0x16]
	ldr r0, _0804D718 @ =0x00000123
	bl SoundPlay
	b _0804D75E
	.align 2, 0
_0804D710: .4byte gCurrentSprite
_0804D714: .4byte 0x08384584
_0804D718: .4byte 0x00000123
_0804D71C:
	ldrh r0, [r4, #0x16]
	cmp r0, #0
	bne _0804D75E
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	bne _0804D75E
	movs r0, #0x91
	lsls r0, r0, #1
	bl SoundPlay
	b _0804D75E
_0804D732:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804D75E
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0804D75E
	subs r1, #0xb
	movs r0, #0x1f
	strb r0, [r1]
	movs r0, #0x3c
	strb r0, [r5]
	ldr r0, _0804D764 @ =0x083846CC
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r2, [r4, #0x16]
_0804D75E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D764: .4byte 0x083846CC

	thumb_func_start DachoraWaitingToRun
DachoraWaitingToRun: @ 0x0804D768
	push {lr}
	ldr r3, _0804D798 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0804D794
	subs r1, #0xa
	movs r0, #0x20
	strb r0, [r1]
	ldr r0, _0804D79C @ =0x0838451C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	movs r0, #0x92
	lsls r0, r0, #1
	bl SoundPlay_3b1c
_0804D794:
	pop {r0}
	bx r0
	.align 2, 0
_0804D798: .4byte gCurrentSprite
_0804D79C: .4byte 0x0838451C

	thumb_func_start DachoraRunning
DachoraRunning: @ 0x0804D7A0
	push {lr}
	ldr r2, _0804D7C4 @ =gCurrentSprite
	ldrh r0, [r2, #4]
	adds r0, #0xe
	strh r0, [r2, #4]
	ldrb r0, [r2, #0x1c]
	adds r0, #2
	strb r0, [r2, #0x1c]
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0804D7C0
	strh r0, [r2]
_0804D7C0:
	pop {r0}
	bx r0
	.align 2, 0
_0804D7C4: .4byte gCurrentSprite

	thumb_func_start BabyDachoraInit
BabyDachoraInit: @ 0x0804D7C8
	push {r4, lr}
	ldr r0, _0804D838 @ =gCurrentSprite
	mov ip, r0
	ldrh r1, [r0]
	ldr r0, _0804D83C @ =0x0000FFFB
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
	mov r1, ip
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	subs r1, #1
	movs r0, #3
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x25
	strb r3, [r0]
	adds r1, #6
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r3, [r0]
	adds r1, #2
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0804D840 @ =0x0000FFFC
	mov r2, ip
	strh r1, [r2, #0xa]
	movs r0, #4
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	strh r0, [r2, #0x10]
	ldr r0, _0804D844 @ =0x0838462C
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r4, [r2, #0x16]
	mov r1, ip
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x20
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D838: .4byte gCurrentSprite
_0804D83C: .4byte 0x0000FFFB
_0804D840: .4byte 0x0000FFFC
_0804D844: .4byte 0x0838462C

	thumb_func_start BabyDachoraWalkingToGate
BabyDachoraWalkingToGate: @ 0x0804D848
	push {lr}
	ldr r2, _0804D868 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0804D86C
	ldrh r0, [r2, #4]
	adds r0, #4
	strh r0, [r2, #4]
	b _0804D878
	.align 2, 0
_0804D868: .4byte gCurrentSprite
_0804D86C:
	adds r0, r2, #0
	adds r0, #0x24
	movs r1, #2
	strb r1, [r0]
	adds r0, #0xd
	strb r3, [r0]
_0804D878:
	pop {r0}
	bx r0

	thumb_func_start BabyDachoraLeavingEnclosure
BabyDachoraLeavingEnclosure: @ 0x0804D87C
	push {r4, r5, lr}
	ldr r2, _0804D8B0 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r3, [r0]
	ldr r1, _0804D8B4 @ =0x0838188C
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _0804D8B8 @ =0x00007FFF
	cmp r1, r0
	bne _0804D8BC
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #0xa
	movs r0, #0x28
	strb r0, [r1]
	subs r1, #0xd
	movs r0, #2
	strb r0, [r1]
	b _0804D8CE
	.align 2, 0
_0804D8B0: .4byte gCurrentSprite
_0804D8B4: .4byte 0x0838188C
_0804D8B8: .4byte 0x00007FFF
_0804D8BC:
	adds r0, r3, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	adds r0, #4
	strh r0, [r2, #4]
_0804D8CE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start BabyDachoraWalkingToWaitingSpot
BabyDachoraWalkingToWaitingSpot: @ 0x0804D8D4
	push {lr}
	ldr r2, _0804D8F4 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0804D8F8
	ldrh r0, [r2, #4]
	adds r0, #2
	strh r0, [r2, #4]
	b _0804D90E
	.align 2, 0
_0804D8F4: .4byte gCurrentSprite
_0804D8F8:
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	subs r1, #2
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0804D914 @ =0x083846F4
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
_0804D90E:
	pop {r0}
	bx r0
	.align 2, 0
_0804D914: .4byte 0x083846F4

	thumb_func_start BabyDachoraWaitingToRun
BabyDachoraWaitingToRun: @ 0x0804D918
	push {r4, r5, lr}
	movs r3, #0
	ldr r5, _0804D974 @ =gSpriteData
	ldr r4, _0804D978 @ =0x030006EA
	movs r0, #0xa
	rsbs r0, r0, #0
	adds r0, r0, r4
	mov ip, r0
_0804D928:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #3
	adds r2, r0, r5
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804D962
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0804D962
	ldrb r0, [r2, #0x1d]
	cmp r0, #0xb8
	bne _0804D962
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x20
	bne _0804D962
	movs r0, #0x19
	mov r1, ip
	strb r0, [r1]
	movs r0, #0x5a
	strb r0, [r4]
_0804D962:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x17
	bls _0804D928
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D974: .4byte gSpriteData
_0804D978: .4byte 0x030006EA

	thumb_func_start BabyDachoraRunning
BabyDachoraRunning: @ 0x0804D97C
	push {lr}
	ldr r2, _0804D9A0 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804D9A8
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804D9CE
	ldr r0, _0804D9A4 @ =0x0838462C
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	b _0804D9CE
	.align 2, 0
_0804D9A0: .4byte gCurrentSprite
_0804D9A4: .4byte 0x0838462C
_0804D9A8:
	ldrh r0, [r2, #4]
	adds r0, #8
	strh r0, [r2, #4]
	ldrb r0, [r2, #0x1c]
	adds r0, #4
	strb r0, [r2, #0x1c]
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0804D9CE
	ldr r1, _0804D9D4 @ =gSamusData
	adds r1, #0x22
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	strh r3, [r2]
_0804D9CE:
	pop {r0}
	bx r0
	.align 2, 0
_0804D9D4: .4byte gSamusData

	thumb_func_start EtecoonCheckGrabTireSwing
EtecoonCheckGrabTireSwing: @ 0x0804D9D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r2, _0804DA98 @ =gCurrentSprite
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
	mov sl, r1
	ldrh r0, [r2, #0xe]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldrh r0, [r2, #0x10]
	adds r3, r3, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	movs r6, #0
_0804DA14:
	ldr r0, _0804DA9C @ =gSpriteData
	lsls r1, r6, #3
	subs r1, r1, r6
	lsls r1, r1, #3
	adds r5, r1, r0
	ldrh r2, [r5]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0804DAA0
	adds r0, r5, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0804DAA0
	ldrb r0, [r5, #0x1d]
	cmp r0, #0xb7
	bne _0804DAA0
	movs r7, #0x80
	lsls r7, r7, #3
	adds r0, r7, #0
	ands r0, r2
	cmp r0, #0
	bne _0804DAA0
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
	mov r1, sl
	mov r2, sb
	mov r3, r8
	bl SpriteUtilCheckObjectsTouching
	cmp r0, #0
	beq _0804DAA0
	ldrh r0, [r5]
	adds r1, r7, #0
	orrs r1, r0
	strh r1, [r5]
	ldr r0, _0804DA98 @ =gCurrentSprite
	adds r0, #0x2d
	strb r6, [r0]
	movs r0, #1
	b _0804DAAC
	.align 2, 0
_0804DA98: .4byte gCurrentSprite
_0804DA9C: .4byte gSpriteData
_0804DAA0:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x17
	bls _0804DA14
	movs r0, #0
_0804DAAC:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EtecoonCheckFaceForeground
EtecoonCheckFaceForeground: @ 0x0804DABC
	push {r4, lr}
	movs r4, #1
	ldr r0, _0804DAD4 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #0xc
	bhi _0804DB58
	lsls r0, r0, #2
	ldr r1, _0804DAD8 @ =_0804DADC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804DAD4: .4byte gSpriteRandomNumber
_0804DAD8: .4byte _0804DADC
_0804DADC: @ jump table
	.4byte _0804DB10 @ case 0
	.4byte _0804DB10 @ case 1
	.4byte _0804DB10 @ case 2
	.4byte _0804DB10 @ case 3
	.4byte _0804DB28 @ case 4
	.4byte _0804DB28 @ case 5
	.4byte _0804DB28 @ case 6
	.4byte _0804DB28 @ case 7
	.4byte _0804DB28 @ case 8
	.4byte _0804DB40 @ case 9
	.4byte _0804DB40 @ case 10
	.4byte _0804DB40 @ case 11
	.4byte _0804DB40 @ case 12
_0804DB10:
	ldr r1, _0804DB24 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	strb r3, [r1]
	b _0804DB5A
	.align 2, 0
_0804DB24: .4byte gCurrentSprite
_0804DB28:
	ldr r1, _0804DB3C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	b _0804DB5A
	.align 2, 0
_0804DB3C: .4byte gCurrentSprite
_0804DB40:
	ldr r1, _0804DB54 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r0, #7
	strb r0, [r2]
	adds r1, #0x2f
	movs r0, #2
	strb r0, [r1]
	b _0804DB5A
	.align 2, 0
_0804DB54: .4byte gCurrentSprite
_0804DB58:
	movs r4, #0
_0804DB5A:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EtecoonInit
EtecoonInit: @ 0x0804DB64
	push {r4, lr}
	bl EventCheckAfter_AnimalsReleased
	adds r3, r0, #0
	cmp r3, #0
	beq _0804DB7C
	ldr r1, _0804DB78 @ =gCurrentSprite
	movs r0, #0
	strh r0, [r1]
	b _0804DC2E
	.align 2, 0
_0804DB78: .4byte gCurrentSprite
_0804DB7C:
	ldr r4, _0804DBF4 @ =gCurrentSprite
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x25
	strb r3, [r0]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xf
	strb r0, [r1]
	subs r1, #1
	movs r0, #3
	strb r0, [r1]
	adds r1, #6
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0804DBF8 @ =0x0000FFC0
	strh r0, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	ldr r0, _0804DBFC @ =0x0000FFF4
	strh r0, [r4, #0xe]
	movs r0, #0xc
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	strh r0, [r4, #8]
	bl SpriteUtilMakeSpriteFaceSamusXFlip
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _0804DC00 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804DC04
	bl EtecoonCheckFaceForeground
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804DC04
	bl EtecoonFacingForegroundInit
	b _0804DC2E
	.align 2, 0
_0804DBF4: .4byte gCurrentSprite
_0804DBF8: .4byte 0x0000FFC0
_0804DBFC: .4byte 0x0000FFF4
_0804DC00: .4byte gSpriteRandomNumber
_0804DC04:
	ldr r3, _0804DC34 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0804DC38 @ =0x0838429C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	movs r1, #0
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x30
	strb r1, [r0]
	ldr r0, _0804DC3C @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, #0x65
	adds r1, r3, #0
	adds r1, #0x2e
	strb r0, [r1]
_0804DC2E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804DC34: .4byte gCurrentSprite
_0804DC38: .4byte 0x0838429C
_0804DC3C: .4byte gSpriteRandomNumber

	thumb_func_start EtecoonIdleInit
EtecoonIdleInit: @ 0x0804DC40
	push {r4, lr}
	ldr r3, _0804DC84 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0804DC88 @ =0x0838429C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	movs r4, #0
	strh r2, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x30
	strb r4, [r0]
	ldr r0, _0804DC8C @ =gFrameCounter8Bit
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, #0x1d
	adds r2, r3, #0
	adds r2, #0x2e
	strb r0, [r2]
	subs r2, #1
	movs r0, #0xff
	strb r0, [r2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #8
	bls _0804DC90
	adds r0, r3, #0
	adds r0, #0x31
	strb r4, [r0]
	b _0804DC98
	.align 2, 0
_0804DC84: .4byte gCurrentSprite
_0804DC88: .4byte 0x0838429C
_0804DC8C: .4byte gSpriteRandomNumber
_0804DC90:
	adds r1, r3, #0
	adds r1, #0x31
	movs r0, #1
	strb r0, [r1]
_0804DC98:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EtecoonIdle
EtecoonIdle: @ 0x0804DCA0
	push {r4, r5, lr}
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _0804DD08
	ldr r3, _0804DCF4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x31
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0804DCF8 @ =gSpriteData
	ldr r0, _0804DCFC @ =gBossWork2
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _0804DD6C
	ldr r0, _0804DD00 @ =gAbilityRestingXPosition
	ldr r2, _0804DD04 @ =0xFFFFFF00
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r3, #4]
	adds r0, r1, #0
	subs r0, #0x20
	cmp r2, r0
	ble _0804DD6C
	adds r0, #0x40
	cmp r2, r0
	bge _0804DD6C
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
	b _0804DDF4
	.align 2, 0
_0804DCF4: .4byte gCurrentSprite
_0804DCF8: .4byte gSpriteData
_0804DCFC: .4byte gBossWork2
_0804DD00: .4byte gAbilityRestingXPosition
_0804DD04: .4byte 0xFFFFFF00
_0804DD08:
	ldr r4, _0804DD34 @ =gCurrentSprite
	ldrh r2, [r4, #4]
	ldr r0, _0804DD38 @ =gAbilityRestingXPosition
	ldrh r1, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r1, r3
	cmp r2, r0
	bgt _0804DD22
	ldr r3, _0804DD3C @ =0xFFFFFE40
	adds r0, r1, r3
	cmp r2, r0
	bge _0804DD6C
_0804DD22:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DD40
	subs r0, #1
	strb r0, [r1]
	b _0804DD6C
	.align 2, 0
_0804DD34: .4byte gCurrentSprite
_0804DD38: .4byte gAbilityRestingXPosition
_0804DD3C: .4byte 0xFFFFFE40
_0804DD40:
	bl EtecoonCheckGrabTireSwing
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804DD56
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #7
	strb r0, [r1]
	adds r1, #0xb
	b _0804DDE4
_0804DD56:
	ldr r0, _0804DD98 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _0804DD6C
	bl EtecoonCheckFaceForeground
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804DDF4
_0804DD6C:
	ldr r0, _0804DD9C @ =gCurrentSprite
	adds r1, r0, #0
	adds r1, #0x31
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	beq _0804DDA0
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r2, [r5]
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x18
	lsrs r3, r0, #0x1a
	cmp r1, #0x1f
	bhi _0804DD8E
	adds r0, r2, #2
	strb r0, [r5]
_0804DD8E:
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
	b _0804DDB4
	.align 2, 0
_0804DD98: .4byte gFrameCounter8Bit
_0804DD9C: .4byte gCurrentSprite
_0804DDA0:
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r2, [r5]
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x18
	lsrs r3, r0, #0x1a
	cmp r1, #0xf
	bhi _0804DDB4
	adds r0, r2, #1
	strb r0, [r5]
_0804DDB4:
	adds r2, r4, #0
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804DDD4
	ldrh r0, [r2, #8]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r2, #4]
	cmp r0, r1
	blt _0804DDE0
	adds r0, r1, r3
	strh r0, [r2, #4]
	b _0804DDF4
_0804DDD4:
	ldrh r0, [r2, #8]
	ldr r1, _0804DDEC @ =0xFFFFFC80
	adds r0, r0, r1
	ldrh r1, [r2, #4]
	cmp r0, r1
	ble _0804DDF0
_0804DDE0:
	adds r1, r2, #0
	adds r1, #0x24
_0804DDE4:
	movs r0, #3
	strb r0, [r1]
	b _0804DDF4
	.align 2, 0
_0804DDEC: .4byte 0xFFFFFC80
_0804DDF0:
	subs r0, r1, r3
	strh r0, [r4, #4]
_0804DDF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EtecoonStandingInit
EtecoonStandingInit: @ 0x0804DDFC
	ldr r0, _0804DE18 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r3, #0
	movs r1, #8
	strb r1, [r2]
	ldr r1, _0804DE1C @ =0x0838428C
	str r1, [r0, #0x18]
	strb r3, [r0, #0x1c]
	strh r3, [r0, #0x16]
	adds r0, #0x2e
	movs r1, #0xb
	strb r1, [r0]
	bx lr
	.align 2, 0
_0804DE18: .4byte gCurrentSprite
_0804DE1C: .4byte 0x0838428C

	thumb_func_start EtecoonStanding
EtecoonStanding: @ 0x0804DE20
	push {r4, lr}
	ldr r4, _0804DE40 @ =gCurrentSprite
	ldr r1, [r4, #0x18]
	ldr r0, _0804DE44 @ =0x0838428C
	cmp r1, r0
	bne _0804DE4C
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804DE62
	ldr r0, _0804DE48 @ =0x08384254
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	b _0804DE62
	.align 2, 0
_0804DE40: .4byte gCurrentSprite
_0804DE44: .4byte 0x0838428C
_0804DE48: .4byte 0x08384254
_0804DE4C:
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804DE62
	subs r1, #0xa
	movs r0, #9
	strb r0, [r1]
_0804DE62:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start EtecoonFacingForegroundInit
EtecoonFacingForegroundInit: @ 0x0804DE68
	push {lr}
	ldr r0, _0804DE84 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x24
	movs r1, #0xa
	strb r1, [r2]
	adds r1, r0, #0
	adds r1, #0x2f
	ldrb r2, [r1]
	adds r1, r0, #0
	cmp r2, #1
	bne _0804DE8C
	ldr r0, _0804DE88 @ =0x083842D4
	b _0804DEA6
	.align 2, 0
_0804DE84: .4byte gCurrentSprite
_0804DE88: .4byte 0x083842D4
_0804DE8C:
	cmp r2, #2
	bne _0804DE98
	ldr r0, _0804DE94 @ =0x0838431C
	b _0804DEA6
	.align 2, 0
_0804DE94: .4byte 0x0838431C
_0804DE98:
	cmp r2, #3
	bne _0804DEA4
	ldr r0, _0804DEA0 @ =0x08384374
	b _0804DEA6
	.align 2, 0
_0804DEA0: .4byte 0x08384374
_0804DEA4:
	ldr r0, _0804DEBC @ =0x08384264
_0804DEA6:
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	ldr r0, _0804DEC0 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsrs r0, r0, #2
	adds r1, #0x2e
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804DEBC: .4byte 0x08384264
_0804DEC0: .4byte gSpriteRandomNumber

	thumb_func_start EtecoonFacingForeground
EtecoonFacingForeground: @ 0x0804DEC4
	push {r4, lr}
	ldr r0, _0804DF20 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x2d
	ldrb r2, [r0]
	mov r0, ip
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #3
	bne _0804DF30
	cmp r2, #0xff
	beq _0804DF30
	mov r1, ip
	ldrh r0, [r1, #0x16]
	cmp r0, #3
	bne _0804DF30
	ldrb r0, [r1, #0x1c]
	cmp r0, #6
	bne _0804DF30
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x38
	strb r0, [r1]
	mov r0, ip
	strb r3, [r0, #0x1c]
	movs r4, #0
	strh r3, [r0, #0x16]
	ldr r0, _0804DF24 @ =0x083843CC
	mov r1, ip
	str r0, [r1, #0x18]
	ldr r1, _0804DF28 @ =gSpriteData
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #3
	adds r2, r0, r1
	strb r4, [r2, #0x1c]
	strh r3, [r2, #0x16]
	adds r1, #0x18
	adds r0, r0, r1
	ldr r1, _0804DF2C @ =0x0838447C
	str r1, [r0]
	ldrh r0, [r2, #4]
	mov r1, ip
	strh r0, [r1, #4]
	b _0804DF82
	.align 2, 0
_0804DF20: .4byte gCurrentSprite
_0804DF24: .4byte 0x083843CC
_0804DF28: .4byte gSpriteData
_0804DF2C: .4byte 0x0838447C
_0804DF30:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804DF82
	ldr r1, _0804DF5C @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #2
	beq _0804DF4A
	cmp r0, #0
	bne _0804DF60
_0804DF4A:
	adds r1, r3, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DF60
	subs r0, #1
	strb r0, [r1]
	b _0804DF82
	.align 2, 0
_0804DF5C: .4byte gCurrentSprite
_0804DF60:
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0804DF88 @ =0x0838428C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0804DF8C @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #6
	bhi _0804DF82
	ldrh r0, [r3]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r3]
_0804DF82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804DF88: .4byte 0x0838428C
_0804DF8C: .4byte gSpriteRandomNumber

	thumb_func_start EtecoonTurningAroundInit
EtecoonTurningAroundInit: @ 0x0804DF90
	ldr r1, _0804DFA8 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r0, _0804DFAC @ =0x083842C4
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804DFA8: .4byte gCurrentSprite
_0804DFAC: .4byte 0x083842C4

	thumb_func_start EtecoonTurningAround
EtecoonTurningAround: @ 0x0804DFB0
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804DFF0
	ldr r2, _0804DFE4 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0804DFE8 @ =0x083842C4
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
	adds r2, #0x22
	ldrb r0, [r2]
	cmp r0, #0xe
	bne _0804DFEC
	movs r0, #0xf
	b _0804DFEE
	.align 2, 0
_0804DFE4: .4byte gCurrentSprite
_0804DFE8: .4byte 0x083842C4
_0804DFEC:
	movs r0, #0xe
_0804DFEE:
	strb r0, [r2]
_0804DFF0:
	pop {r0}
	bx r0

	thumb_func_start EtecoonTurningAroundSecondPart
EtecoonTurningAroundSecondPart: @ 0x0804DFF4
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804E006
	ldr r0, _0804E00C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0804E006:
	pop {r0}
	bx r0
	.align 2, 0
_0804E00C: .4byte gCurrentSprite

	thumb_func_start EtecoonJumpingToTire
EtecoonJumpingToTire: @ 0x0804E010
	push {r4, r5, r6, lr}
	ldr r5, _0804E05C @ =gCurrentSprite
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r6, [r0]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804E056
	adds r1, r5, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x3a
	strb r0, [r1]
	strb r3, [r5, #0x1c]
	movs r4, #0
	strh r3, [r5, #0x16]
	ldr r0, _0804E060 @ =0x083843F4
	str r0, [r5, #0x18]
	ldr r0, _0804E064 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, #0xa
	strb r0, [r1]
	ldr r2, _0804E068 @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r1, r0, r2
	strb r4, [r1, #0x1c]
	strh r3, [r1, #0x16]
	adds r2, #0x18
	adds r0, r0, r2
	ldr r1, _0804E06C @ =0x0838449C
	str r1, [r0]
_0804E056:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804E05C: .4byte gCurrentSprite
_0804E060: .4byte 0x083843F4
_0804E064: .4byte gSpriteRandomNumber
_0804E068: .4byte gSpriteData
_0804E06C: .4byte 0x0838449C

	thumb_func_start EtecoonSwingingFromTire
EtecoonSwingingFromTire: @ 0x0804E070
	push {r4, r5, r6, lr}
	ldr r4, _0804E0A4 @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r6, [r0]
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804E0F0
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	adds r5, r0, #0
	cmp r5, #0
	beq _0804E0C8
	subs r0, #1
	strb r0, [r1]
	ldr r0, _0804E0A8 @ =gFrameCounter8Bit
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804E0B0
	ldr r0, _0804E0AC @ =0x083843F4
	b _0804E0B2
	.align 2, 0
_0804E0A4: .4byte gCurrentSprite
_0804E0A8: .4byte gSpriteRandomNumber
_0804E0AC: .4byte 0x083843F4
_0804E0B0:
	ldr r0, _0804E0C0 @ =0x0838441C
_0804E0B2:
	str r0, [r4, #0x18]
	ldr r1, _0804E0C4 @ =gCurrentSprite
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	b _0804E0F0
	.align 2, 0
_0804E0C0: .4byte 0x0838441C
_0804E0C4: .4byte gCurrentSprite
_0804E0C8:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3c
	strb r0, [r1]
	strb r5, [r4, #0x1c]
	movs r3, #0
	strh r5, [r4, #0x16]
	ldr r0, _0804E0F8 @ =0x08384444
	str r0, [r4, #0x18]
	ldr r2, _0804E0FC @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r1, r0, r2
	strb r3, [r1, #0x1c]
	strh r5, [r1, #0x16]
	adds r2, #0x18
	adds r0, r0, r2
	ldr r1, _0804E100 @ =0x083844BC
	str r1, [r0]
_0804E0F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804E0F8: .4byte 0x08384444
_0804E0FC: .4byte gSpriteData
_0804E100: .4byte 0x083844BC

	thumb_func_start EtecoonFallingFromTire
EtecoonFallingFromTire: @ 0x0804E104
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804E132
	ldr r3, _0804E138 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0804E13C @ =0x0838428C
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r2, [r3, #0x16]
	ldr r0, _0804E140 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #6
	bhi _0804E132
	ldrh r0, [r3]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r3]
_0804E132:
	pop {r0}
	bx r0
	.align 2, 0
_0804E138: .4byte gCurrentSprite
_0804E13C: .4byte 0x0838428C
_0804E140: .4byte gSpriteRandomNumber

	thumb_func_start EtecoonTurningAroundWhileLeavingInit
EtecoonTurningAroundWhileLeavingInit: @ 0x0804E144
	ldr r1, _0804E15C @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x3e
	strb r0, [r2]
	ldr r0, _0804E160 @ =0x083842C4
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804E15C: .4byte gCurrentSprite
_0804E160: .4byte 0x083842C4

	thumb_func_start EtecoonTurningAroundWhileLeaving
EtecoonTurningAroundWhileLeaving: @ 0x0804E164
	push {lr}
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804E18A
	ldr r2, _0804E190 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	movs r3, #0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _0804E194 @ =0x083842C4
	str r0, [r2, #0x18]
	strb r3, [r2, #0x1c]
	strh r3, [r2, #0x16]
	ldrh r0, [r2]
	movs r1, #0x40
	eors r0, r1
	strh r0, [r2]
_0804E18A:
	pop {r0}
	bx r0
	.align 2, 0
_0804E190: .4byte gCurrentSprite
_0804E194: .4byte 0x083842C4

	thumb_func_start EtecoonTurningAroundWhileLeavingSecondPart
EtecoonTurningAroundWhileLeavingSecondPart: @ 0x0804E198
	push {lr}
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804E1AA
	ldr r0, _0804E1B0 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x19
	strb r1, [r0]
_0804E1AA:
	pop {r0}
	bx r0
	.align 2, 0
_0804E1B0: .4byte gCurrentSprite

	thumb_func_start EtecoonLeavingEnclosureInit
EtecoonLeavingEnclosureInit: @ 0x0804E1B4
	ldr r3, _0804E1D4 @ =gCurrentSprite
	adds r1, r3, #0
	adds r1, #0x24
	movs r2, #0
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x31
	strb r2, [r0]
	subs r1, #3
	movs r0, #2
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804E1D4: .4byte gCurrentSprite

	thumb_func_start EtecoonLeavingEnclosure
EtecoonLeavingEnclosure: @ 0x0804E1D8
	push {r4, r5, lr}
	ldr r2, _0804E210 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r4, [r0]
	ldr r1, _0804E214 @ =0x0838188C
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _0804E218 @ =0x00007FFF
	adds r3, r2, #0
	cmp r1, r0
	bne _0804E296
	ldrh r0, [r2, #4]
	ldr r4, _0804E21C @ =0x0000FFF8
	ands r4, r0
	ldrh r1, [r2, #8]
	ldr r0, _0804E220 @ =gAbilityRestingXPosition
	ldrh r2, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	cmp r1, r0
	bne _0804E228
	ldr r5, _0804E224 @ =0xFFFFFF00
	b _0804E23E
	.align 2, 0
_0804E210: .4byte gCurrentSprite
_0804E214: .4byte 0x0838188C
_0804E218: .4byte 0x00007FFF
_0804E21C: .4byte 0x0000FFF8
_0804E220: .4byte gAbilityRestingXPosition
_0804E224: .4byte 0xFFFFFF00
_0804E228:
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r0, r2, r5
	cmp r1, r0
	bne _0804E23C
	ldr r1, _0804E238 @ =0xFFFFFEC0
	adds r0, r2, r1
	b _0804E240
	.align 2, 0
_0804E238: .4byte 0xFFFFFEC0
_0804E23C:
	ldr r5, _0804E25C @ =0xFFFFFE80
_0804E23E:
	adds r0, r2, r5
_0804E240:
	movs r2, #8
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, r0
	bhs _0804E260
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0804E26E
	b _0804E28C
	.align 2, 0
_0804E25C: .4byte 0xFFFFFE80
_0804E260:
	cmp r4, r0
	bls _0804E278
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0804E28C
_0804E26E:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	b _0804E2B8
_0804E278:
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804E28C
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x1b
	strb r0, [r1]
	b _0804E2B8
_0804E28C:
	adds r1, r3, #0
	adds r1, #0x24
	movs r0, #0x3d
	strb r0, [r1]
	b _0804E2B8
_0804E296:
	adds r0, r4, #1
	mov r3, ip
	strb r0, [r3]
	ldrh r0, [r2, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804E2B2
	ldrh r0, [r2, #4]
	adds r0, #4
	b _0804E2B6
_0804E2B2:
	ldrh r0, [r2, #4]
	subs r0, #4
_0804E2B6:
	strh r0, [r2, #4]
_0804E2B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EtecoonWalkingToWaitingSpotInit
EtecoonWalkingToWaitingSpotInit: @ 0x0804E2C0
	ldr r1, _0804E2D4 @ =gCurrentSprite
	ldr r0, _0804E2D8 @ =0x0838429C
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804E2D4: .4byte gCurrentSprite
_0804E2D8: .4byte 0x0838429C

	thumb_func_start EtecoonWalkingToWaitingSpot
EtecoonWalkingToWaitingSpot: @ 0x0804E2DC
	push {r4, r5, lr}
	ldr r1, _0804E2FC @ =gCurrentSprite
	ldrh r0, [r1, #4]
	ldr r5, _0804E300 @ =0x0000FFF8
	ands r5, r0
	ldrh r3, [r1, #8]
	ldr r0, _0804E304 @ =gAbilityRestingXPosition
	ldrh r2, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	adds r4, r1, #0
	cmp r3, r0
	bne _0804E30C
	ldr r1, _0804E308 @ =0xFFFFFF00
	b _0804E322
	.align 2, 0
_0804E2FC: .4byte gCurrentSprite
_0804E300: .4byte 0x0000FFF8
_0804E304: .4byte gAbilityRestingXPosition
_0804E308: .4byte 0xFFFFFF00
_0804E30C:
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r2, r1
	cmp r3, r0
	bne _0804E320
	ldr r1, _0804E31C @ =0xFFFFFEC0
	b _0804E322
	.align 2, 0
_0804E31C: .4byte 0xFFFFFEC0
_0804E320:
	ldr r1, _0804E348 @ =0xFFFFFE80
_0804E322:
	adds r0, r2, r1
	movs r2, #8
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r5, r0
	bhs _0804E34C
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804E374
	ldrh r0, [r4, #4]
	adds r0, #4
	strh r0, [r4, #4]
	b _0804E37C
	.align 2, 0
_0804E348: .4byte 0xFFFFFE80
_0804E34C:
	cmp r5, r0
	bls _0804E362
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0804E374
	ldrh r0, [r4, #4]
	subs r0, #4
	strh r0, [r4, #4]
	b _0804E37C
_0804E362:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804E374
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x1b
	b _0804E37A
_0804E374:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x3d
_0804E37A:
	strb r0, [r1]
_0804E37C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EtecoonWaitingForOthersInit
EtecoonWaitingForOthersInit: @ 0x0804E384
	ldr r1, _0804E398 @ =gCurrentSprite
	ldr r0, _0804E39C @ =0x0838471C
	str r0, [r1, #0x18]
	movs r0, #0
	strb r0, [r1, #0x1c]
	strh r0, [r1, #0x16]
	adds r1, #0x24
	movs r0, #0x1c
	strb r0, [r1]
	bx lr
	.align 2, 0
_0804E398: .4byte gCurrentSprite
_0804E39C: .4byte 0x0838471C

	thumb_func_start EtecoonWaitingForOthers
EtecoonWaitingForOthers: @ 0x0804E3A0
	push {r4, r5, lr}
	ldr r1, _0804E410 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0804E3B6
	ldrb r0, [r1, #0x1c]
	cmp r0, #1
	bne _0804E3B6
	ldr r0, _0804E414 @ =0x00000121
	bl SoundPlayNotAlreadyPlaying
_0804E3B6:
	movs r3, #0
	ldr r5, _0804E418 @ =gSpriteData
	ldr r4, _0804E41C @ =0x030006EA
	movs r0, #0xa
	rsbs r0, r0, #0
	adds r0, r0, r4
	mov ip, r0
_0804E3C4:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #3
	adds r2, r0, r5
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804E3FE
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0804E3FE
	ldrb r0, [r2, #0x1d]
	cmp r0, #0xb8
	bne _0804E3FE
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x20
	bne _0804E3FE
	movs r0, #0x1d
	mov r1, ip
	strb r0, [r1]
	movs r0, #0x14
	strb r0, [r4]
_0804E3FE:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x17
	bls _0804E3C4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804E410: .4byte gCurrentSprite
_0804E414: .4byte 0x00000121
_0804E418: .4byte gSpriteData
_0804E41C: .4byte 0x030006EA

	thumb_func_start EtecoonRunning
EtecoonRunning: @ 0x0804E420
	push {lr}
	ldr r2, _0804E444 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804E44C
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0804E468
	ldr r0, _0804E448 @ =0x0838429C
	str r0, [r2, #0x18]
	strb r1, [r2, #0x1c]
	strh r1, [r2, #0x16]
	b _0804E468
	.align 2, 0
_0804E444: .4byte gCurrentSprite
_0804E448: .4byte 0x0838429C
_0804E44C:
	ldrh r0, [r2, #4]
	adds r0, #0x10
	strh r0, [r2, #4]
	ldrb r0, [r2, #0x1c]
	adds r0, #2
	strb r0, [r2, #0x1c]
	ldrh r1, [r2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0804E468
	strh r0, [r2]
_0804E468:
	pop {r0}
	bx r0

	thumb_func_start TireSwingInit
TireSwingInit: @ 0x0804E46C
	ldr r0, _0804E4C8 @ =gCurrentSprite
	mov ip, r0
	mov r1, ip
	adds r1, #0x22
	movs r3, #0
	movs r0, #0xd
	strb r0, [r1]
	subs r1, #1
	movs r0, #3
	strb r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #2]
	subs r0, #0x20
	movs r2, #0
	strh r0, [r1, #2]
	mov r0, ip
	adds r0, #0x25
	strb r2, [r0]
	adds r1, #0x27
	movs r0, #0x38
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, _0804E4CC @ =0x0000FFC0
	mov r1, ip
	strh r0, [r1, #0xa]
	movs r0, #0x20
	strh r0, [r1, #0xc]
	ldr r0, _0804E4D0 @ =0x0000FFFC
	strh r0, [r1, #0xe]
	movs r0, #4
	strh r0, [r1, #0x10]
	adds r1, #0x24
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0804E4D4 @ =0x0838446C
	mov r1, ip
	str r0, [r1, #0x18]
	strb r2, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804E4C8: .4byte gCurrentSprite
_0804E4CC: .4byte 0x0000FFC0
_0804E4D0: .4byte 0x0000FFFC
_0804E4D4: .4byte 0x0838446C

	thumb_func_start TireSwingIdle
TireSwingIdle: @ 0x0804E4D8
	push {r4, lr}
	ldr r4, _0804E510 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804E50A
	ldr r1, [r4, #0x18]
	ldr r0, _0804E514 @ =0x083844BC
	cmp r1, r0
	bne _0804E50A
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804E50A
	ldr r0, _0804E518 @ =0x0838446C
	str r0, [r4, #0x18]
	movs r0, #0
	strb r0, [r4, #0x1c]
	strh r0, [r4, #0x16]
	ldrh r1, [r4]
	ldr r0, _0804E51C @ =0x0000FBFF
	ands r0, r1
	strh r0, [r4]
_0804E50A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804E510: .4byte gCurrentSprite
_0804E514: .4byte 0x083844BC
_0804E518: .4byte 0x0838446C
_0804E51C: .4byte 0x0000FBFF

	thumb_func_start Dachora
Dachora: @ 0x0804E520
	push {lr}
	ldr r0, _0804E540 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x3a
	bls _0804E536
	b _0804E6AE
_0804E536:
	lsls r0, r0, #2
	ldr r1, _0804E544 @ =_0804E548
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E540: .4byte gCurrentSprite
_0804E544: .4byte _0804E548
_0804E548: @ jump table
	.4byte _0804E634 @ case 0
	.4byte _0804E63A @ case 1
	.4byte _0804E63E @ case 2
	.4byte _0804E644 @ case 3
	.4byte _0804E648 @ case 4
	.4byte _0804E64E @ case 5
	.4byte _0804E6AE @ case 6
	.4byte _0804E654 @ case 7
	.4byte _0804E658 @ case 8
	.4byte _0804E65E @ case 9
	.4byte _0804E662 @ case 10
	.4byte _0804E6AE @ case 11
	.4byte _0804E6AE @ case 12
	.4byte _0804E6AE @ case 13
	.4byte _0804E6AE @ case 14
	.4byte _0804E6AE @ case 15
	.4byte _0804E6AE @ case 16
	.4byte _0804E6AE @ case 17
	.4byte _0804E6AE @ case 18
	.4byte _0804E6AE @ case 19
	.4byte _0804E6AE @ case 20
	.4byte _0804E6AE @ case 21
	.4byte _0804E6AE @ case 22
	.4byte _0804E678 @ case 23
	.4byte _0804E67C @ case 24
	.4byte _0804E682 @ case 25
	.4byte _0804E686 @ case 26
	.4byte _0804E68C @ case 27
	.4byte _0804E692 @ case 28
	.4byte _0804E698 @ case 29
	.4byte _0804E69E @ case 30
	.4byte _0804E6A4 @ case 31
	.4byte _0804E6AA @ case 32
	.4byte _0804E6AE @ case 33
	.4byte _0804E6AE @ case 34
	.4byte _0804E6AE @ case 35
	.4byte _0804E6AE @ case 36
	.4byte _0804E6AE @ case 37
	.4byte _0804E6AE @ case 38
	.4byte _0804E6AE @ case 39
	.4byte _0804E6AE @ case 40
	.4byte _0804E6AE @ case 41
	.4byte _0804E6AE @ case 42
	.4byte _0804E6AE @ case 43
	.4byte _0804E6AE @ case 44
	.4byte _0804E6AE @ case 45
	.4byte _0804E6AE @ case 46
	.4byte _0804E6AE @ case 47
	.4byte _0804E6AE @ case 48
	.4byte _0804E6AE @ case 49
	.4byte _0804E6AE @ case 50
	.4byte _0804E6AE @ case 51
	.4byte _0804E6AE @ case 52
	.4byte _0804E6AE @ case 53
	.4byte _0804E6AE @ case 54
	.4byte _0804E668 @ case 55
	.4byte _0804E66C @ case 56
	.4byte _0804E6AE @ case 57
	.4byte _0804E672 @ case 58
_0804E634:
	bl DachoraInit
	b _0804E6AE
_0804E63A:
	bl DachoraIdleInit
_0804E63E:
	bl DachoraIdle
	b _0804E6AE
_0804E644:
	bl DachoraTurningAroundInit
_0804E648:
	bl DachoraTurningAround
	b _0804E6AE
_0804E64E:
	bl DachoraTurningAroundSecondPart
	b _0804E6AE
_0804E654:
	bl DachoraStandingInit
_0804E658:
	bl DachoraStanding
	b _0804E6AE
_0804E65E:
	bl DachoraHeadMovementInit
_0804E662:
	bl DachoraHeadMovement
	b _0804E6AE
_0804E668:
	bl DachoraTurningAroundWhileLeavingInit
_0804E66C:
	bl DachoraTurningAroundWhileLeaving
	b _0804E6AE
_0804E672:
	bl DachoraTurningAroundWhileLeavingSecondPart
	b _0804E6AE
_0804E678:
	bl DachoraLeavingEnclosureInit
_0804E67C:
	bl DachoraLeavingEnclosure
	b _0804E6AE
_0804E682:
	bl DachoraWalkingToWaitingSpotInit
_0804E686:
	bl DachoraWalkingToWaitingSpot
	b _0804E6AE
_0804E68C:
	bl DachorawaitingForOthers
	b _0804E6AE
_0804E692:
	bl DachoraWaitingToSpawnBaby
	b _0804E6AE
_0804E698:
	bl DachoraWaitingForBaby
	b _0804E6AE
_0804E69E:
	bl DachoraBowing
	b _0804E6AE
_0804E6A4:
	bl DachoraWaitingToRun
	b _0804E6AE
_0804E6AA:
	bl DachoraRunning
_0804E6AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start BabyDachora
BabyDachora: @ 0x0804E6B4
	push {lr}
	ldr r0, _0804E6D4 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x19
	bhi _0804E766
	lsls r0, r0, #2
	ldr r1, _0804E6D8 @ =_0804E6DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E6D4: .4byte gCurrentSprite
_0804E6D8: .4byte _0804E6DC
_0804E6DC: @ jump table
	.4byte _0804E744 @ case 0
	.4byte _0804E74A @ case 1
	.4byte _0804E750 @ case 2
	.4byte _0804E766 @ case 3
	.4byte _0804E766 @ case 4
	.4byte _0804E766 @ case 5
	.4byte _0804E766 @ case 6
	.4byte _0804E766 @ case 7
	.4byte _0804E766 @ case 8
	.4byte _0804E766 @ case 9
	.4byte _0804E766 @ case 10
	.4byte _0804E766 @ case 11
	.4byte _0804E766 @ case 12
	.4byte _0804E766 @ case 13
	.4byte _0804E766 @ case 14
	.4byte _0804E766 @ case 15
	.4byte _0804E766 @ case 16
	.4byte _0804E766 @ case 17
	.4byte _0804E766 @ case 18
	.4byte _0804E766 @ case 19
	.4byte _0804E766 @ case 20
	.4byte _0804E766 @ case 21
	.4byte _0804E766 @ case 22
	.4byte _0804E756 @ case 23
	.4byte _0804E75C @ case 24
	.4byte _0804E762 @ case 25
_0804E744:
	bl BabyDachoraInit
	b _0804E766
_0804E74A:
	bl BabyDachoraWalkingToGate
	b _0804E766
_0804E750:
	bl BabyDachoraLeavingEnclosure
	b _0804E766
_0804E756:
	bl BabyDachoraWalkingToWaitingSpot
	b _0804E766
_0804E75C:
	bl BabyDachoraWaitingToRun
	b _0804E766
_0804E762:
	bl BabyDachoraRunning
_0804E766:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Etecoon
Etecoon: @ 0x0804E76C
	push {lr}
	ldr r0, _0804E78C @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x40
	bls _0804E782
	b _0804E910
_0804E782:
	lsls r0, r0, #2
	ldr r1, _0804E790 @ =_0804E794
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804E78C: .4byte gCurrentSprite
_0804E790: .4byte _0804E794
_0804E794: @ jump table
	.4byte _0804E898 @ case 0
	.4byte _0804E89E @ case 1
	.4byte _0804E8A2 @ case 2
	.4byte _0804E8A8 @ case 3
	.4byte _0804E8AC @ case 4
	.4byte _0804E8B2 @ case 5
	.4byte _0804E910 @ case 6
	.4byte _0804E8B8 @ case 7
	.4byte _0804E8BC @ case 8
	.4byte _0804E8C2 @ case 9
	.4byte _0804E8C6 @ case 10
	.4byte _0804E910 @ case 11
	.4byte _0804E910 @ case 12
	.4byte _0804E910 @ case 13
	.4byte _0804E910 @ case 14
	.4byte _0804E910 @ case 15
	.4byte _0804E910 @ case 16
	.4byte _0804E910 @ case 17
	.4byte _0804E910 @ case 18
	.4byte _0804E910 @ case 19
	.4byte _0804E910 @ case 20
	.4byte _0804E910 @ case 21
	.4byte _0804E910 @ case 22
	.4byte _0804E8EE @ case 23
	.4byte _0804E8F2 @ case 24
	.4byte _0804E8F8 @ case 25
	.4byte _0804E8FC @ case 26
	.4byte _0804E902 @ case 27
	.4byte _0804E906 @ case 28
	.4byte _0804E90C @ case 29
	.4byte _0804E910 @ case 30
	.4byte _0804E910 @ case 31
	.4byte _0804E910 @ case 32
	.4byte _0804E910 @ case 33
	.4byte _0804E910 @ case 34
	.4byte _0804E910 @ case 35
	.4byte _0804E910 @ case 36
	.4byte _0804E910 @ case 37
	.4byte _0804E910 @ case 38
	.4byte _0804E910 @ case 39
	.4byte _0804E910 @ case 40
	.4byte _0804E910 @ case 41
	.4byte _0804E910 @ case 42
	.4byte _0804E910 @ case 43
	.4byte _0804E910 @ case 44
	.4byte _0804E910 @ case 45
	.4byte _0804E910 @ case 46
	.4byte _0804E910 @ case 47
	.4byte _0804E910 @ case 48
	.4byte _0804E910 @ case 49
	.4byte _0804E910 @ case 50
	.4byte _0804E910 @ case 51
	.4byte _0804E910 @ case 52
	.4byte _0804E910 @ case 53
	.4byte _0804E910 @ case 54
	.4byte _0804E910 @ case 55
	.4byte _0804E8CC @ case 56
	.4byte _0804E910 @ case 57
	.4byte _0804E8D2 @ case 58
	.4byte _0804E910 @ case 59
	.4byte _0804E8D8 @ case 60
	.4byte _0804E8DE @ case 61
	.4byte _0804E8E2 @ case 62
	.4byte _0804E910 @ case 63
	.4byte _0804E8E8 @ case 64
_0804E898:
	bl EtecoonInit
	b _0804E910
_0804E89E:
	bl EtecoonIdleInit
_0804E8A2:
	bl EtecoonIdle
	b _0804E910
_0804E8A8:
	bl EtecoonTurningAroundInit
_0804E8AC:
	bl EtecoonTurningAround
	b _0804E910
_0804E8B2:
	bl EtecoonTurningAroundSecondPart
	b _0804E910
_0804E8B8:
	bl EtecoonStandingInit
_0804E8BC:
	bl EtecoonStanding
	b _0804E910
_0804E8C2:
	bl EtecoonFacingForegroundInit
_0804E8C6:
	bl EtecoonFacingForeground
	b _0804E910
_0804E8CC:
	bl EtecoonJumpingToTire
	b _0804E910
_0804E8D2:
	bl EtecoonSwingingFromTire
	b _0804E910
_0804E8D8:
	bl EtecoonFallingFromTire
	b _0804E910
_0804E8DE:
	bl EtecoonTurningAroundWhileLeavingInit
_0804E8E2:
	bl EtecoonTurningAroundWhileLeaving
	b _0804E910
_0804E8E8:
	bl EtecoonTurningAroundWhileLeavingSecondPart
	b _0804E910
_0804E8EE:
	bl EtecoonLeavingEnclosureInit
_0804E8F2:
	bl EtecoonLeavingEnclosure
	b _0804E910
_0804E8F8:
	bl EtecoonWalkingToWaitingSpotInit
_0804E8FC:
	bl EtecoonWalkingToWaitingSpot
	b _0804E910
_0804E902:
	bl EtecoonWaitingForOthersInit
_0804E906:
	bl EtecoonWaitingForOthers
	b _0804E910
_0804E90C:
	bl EtecoonRunning
_0804E910:
	pop {r0}
	bx r0

	thumb_func_start TireSwing
TireSwing: @ 0x0804E914
	push {lr}
	ldr r0, _0804E930 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E934
	cmp r0, #2
	beq _0804E93A
	b _0804E93E
	.align 2, 0
_0804E930: .4byte gCurrentSprite
_0804E934:
	bl TireSwingInit
	b _0804E93E
_0804E93A:
	bl TireSwingIdle
_0804E93E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start HabitationGateLight
HabitationGateLight: @ 0x0804E944
	push {r4, r5, r6, lr}
	ldr r4, _0804E964 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r6, #0
	movs r0, #1
	strb r0, [r1]
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804E968
	cmp r0, #2
	beq _0804E9F4
	b _0804EA08
	.align 2, 0
_0804E964: .4byte gCurrentSprite
_0804E968:
	ldrh r0, [r4]
	ldr r1, _0804E980 @ =0x0000FFFB
	ands r1, r0
	strh r1, [r4]
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _0804E988
	ldr r0, _0804E984 @ =0x08384744
	str r0, [r4, #0x18]
	b _0804E998
	.align 2, 0
_0804E980: .4byte 0x0000FFFB
_0804E984: .4byte 0x08384744
_0804E988:
	ldr r0, _0804E9E8 @ =0x08384674
	str r0, [r4, #0x18]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
_0804E998:
	ldr r3, _0804E9EC @ =gCurrentSprite
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r1, #0
	strh r0, [r3, #0x16]
	adds r2, r3, #0
	adds r2, #0x22
	movs r0, #0xc
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x21
	movs r2, #2
	strb r2, [r0]
	ldrh r0, [r3, #2]
	subs r0, #0x20
	strh r0, [r3, #2]
	adds r0, r3, #0
	adds r0, #0x25
	strb r1, [r0]
	adds r4, r3, #0
	adds r4, #0x27
	movs r0, #0x40
	strb r0, [r4]
	adds r0, r3, #0
	adds r0, #0x28
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0x29
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0804E9F0 @ =0x0000FFFC
	strh r1, [r3, #0xa]
	movs r0, #4
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r0, [r3, #0x10]
	adds r0, r3, #0
	adds r0, #0x24
	strb r2, [r0]
	b _0804EA08
	.align 2, 0
_0804E9E8: .4byte 0x08384674
_0804E9EC: .4byte gCurrentSprite
_0804E9F0: .4byte 0x0000FFFC
_0804E9F4:
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _0804EA08
	ldr r0, _0804EA10 @ =0x08384744
	str r0, [r4, #0x18]
	strb r6, [r4, #0x1c]
	strh r6, [r4, #0x16]
	movs r0, #0x18
	strb r0, [r5]
_0804EA08:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804EA10: .4byte 0x08384744

	thumb_func_start HabitationGate
HabitationGate: @ 0x0804EA14
	push {r4, r5, r6, lr}
	ldr r4, _0804EA38 @ =gCurrentSprite
	adds r1, r4, #0
	adds r1, #0x26
	movs r5, #0
	movs r0, #1
	strb r0, [r1]
	adds r6, r4, #0
	adds r6, #0x24
	ldrb r0, [r6]
	cmp r0, #2
	beq _0804EAB8
	cmp r0, #2
	bgt _0804EA3C
	cmp r0, #0
	beq _0804EA42
	b _0804EAE4
	.align 2, 0
_0804EA38: .4byte gCurrentSprite
_0804EA3C:
	cmp r0, #0x18
	beq _0804EAD0
	b _0804EAE4
_0804EA42:
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xd
	strb r0, [r1]
	subs r1, #1
	movs r0, #3
	strb r0, [r1]
	ldrh r0, [r4, #2]
	subs r0, #0x20
	movs r2, #0
	strh r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x25
	strb r2, [r0]
	adds r1, #6
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x18
	strb r0, [r1]
	ldr r1, _0804EA90 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	ldr r0, _0804EA94 @ =0x08384684
	str r0, [r4, #0x18]
	strb r2, [r4, #0x1c]
	strh r5, [r4, #0x16]
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _0804EA98
	strh r5, [r4]
	b _0804EAE4
	.align 2, 0
_0804EA90: .4byte 0x0000FFFC
_0804EA94: .4byte 0x08384684
_0804EA98:
	ldrh r1, [r4]
	ldr r0, _0804EAB4 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r4]
	movs r0, #2
	strb r0, [r6]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	b _0804EAE4
	.align 2, 0
_0804EAB4: .4byte 0x0000FFFB
_0804EAB8:
	bl EventCheckAfter_AnimalsReleased
	cmp r0, #0
	beq _0804EAE4
	ldr r0, _0804EACC @ =0x08384694
	str r0, [r4, #0x18]
	strb r5, [r4, #0x1c]
	strh r5, [r4, #0x16]
	movs r0, #0x18
	b _0804EAE2
	.align 2, 0
_0804EACC: .4byte 0x08384694
_0804EAD0:
	bl SpriteUtilHasCurrentAnimationEnded
	cmp r0, #0
	beq _0804EAE4
	ldrh r0, [r4]
	movs r1, #4
	orrs r1, r0
	strh r1, [r4]
	movs r0, #0x1a
_0804EAE2:
	strb r0, [r6]
_0804EAE4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MetroidInit
MetroidInit: @ 0x0804EAEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0804EBAC @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x27
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	mov sb, r0
	ldr r1, _0804EBB0 @ =0x0000FFFC
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, sb
	strb r1, [r4, #0x1c]
	ldr r2, _0804EBB4 @ =gFrameCounter8Bit
	mov r8, r2
	ldrb r1, [r2]
	movs r6, #3
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r4, #0x16]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	movs r5, #0xf0
	ands r5, r0
	bl EventCheckOn_RestrictedLabExplosion
	cmp r0, #0
	bne _0804EB3E
	b _0804EC38
_0804EB3E:
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #5
	strb r0, [r1]
	ldr r2, _0804EBB8 @ =sPrimarySpriteStats
	ldrb r1, [r4, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0x22
	strb r6, [r0]
	subs r0, #1
	movs r7, #1
	strb r7, [r0]
	movs r5, #0x24
	adds r5, r5, r4
	mov ip, r5
	movs r0, #0x18
	strb r0, [r5]
	ldr r0, _0804EBBC @ =0x083852BC
	str r0, [r4, #0x18]
	movs r0, #0xb4
	strh r0, [r4, #6]
	ldr r0, _0804EBC0 @ =gSamusData
	ldrh r0, [r0, #0x18]
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov sl, r2
	ldrh r1, [r4, #2]
	adds r3, r1, #0
	ldr r5, _0804EBC4 @ =0xFFFFFEC0
	adds r0, r2, r5
	cmp r0, r1
	bge _0804EBC8
	adds r0, r4, #0
	adds r0, #0x2d
	strb r7, [r0]
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x30
	mov r1, sb
	strb r1, [r0]
	ldrh r0, [r4, #4]
	subs r0, #0xc0
	strh r0, [r4, #4]
	b _0804ED06
	.align 2, 0
_0804EBAC: .4byte gCurrentSprite
_0804EBB0: .4byte 0x0000FFFC
_0804EBB4: .4byte gSpriteRandomNumber
_0804EBB8: .4byte sPrimarySpriteStats
_0804EBBC: .4byte 0x083852BC
_0804EBC0: .4byte gSamusData
_0804EBC4: .4byte 0xFFFFFEC0
_0804EBC8:
	ldr r5, _0804EBF0 @ =0xFFFFFE80
	adds r0, r2, r5
	cmp r0, r1
	bge _0804EBF4
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sb
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x30
	movs r0, #0x3c
	strb r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0xc0
	strh r0, [r4, #4]
	b _0804ED06
	.align 2, 0
_0804EBF0: .4byte 0xFFFFFE80
_0804EBF4:
	ldr r0, _0804EC14 @ =0xFFFFFE40
	add r0, sl
	cmp r0, r3
	bge _0804EC18
	adds r0, r4, #0
	adds r0, #0x2d
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0x31
	movs r0, #0x30
	strb r0, [r1]
	subs r1, #1
	movs r0, #0x28
	strb r0, [r1]
	b _0804ED06
	.align 2, 0
_0804EC14: .4byte 0xFFFFFE40
_0804EC18:
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #0x1a
	lsrs r1, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	subs r0, #4
	mov r5, sb
	strb r5, [r0]
	movs r0, #0x1c
	mov r1, ip
	strb r0, [r1]
	b _0804ED06
_0804EC38:
	adds r0, r4, #0
	adds r0, #0x25
	mov r2, sb
	strb r2, [r0]
	subs r0, #4
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	strb r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #0x19
	lsrs r1, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bl SpriteUtilChooseRandomXDirection
	mov r2, r8
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804EC80
	ldrh r1, [r4]
	ldr r0, _0804EC7C @ =0x0000FBFF
	ands r0, r1
	b _0804EC8A
	.align 2, 0
_0804EC7C: .4byte 0x0000FBFF
_0804EC80:
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
_0804EC8A:
	strh r0, [r4]
	cmp r5, #0x10
	bne _0804ECA8
	ldr r0, _0804ECA0 @ =gCurrentSprite
	ldrh r1, [r0, #2]
	subs r1, #0x20
	strh r1, [r0, #2]
	ldr r1, _0804ECA4 @ =0x083852E4
	str r1, [r0, #0x18]
	b _0804ED06
	.align 2, 0
_0804ECA0: .4byte gCurrentSprite
_0804ECA4: .4byte 0x083852E4
_0804ECA8:
	ldr r1, _0804ECCC @ =gCurrentSprite
	ldr r0, _0804ECD0 @ =0x083852BC
	str r0, [r1, #0x18]
	ldrh r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0804ECD8
	ldr r1, _0804ECD4 @ =gFrameCounter8Bit
	ldrh r0, [r3, #2]
	ldrb r5, [r1]
	adds r0, r0, r5
	strh r0, [r3, #2]
	adds r2, r1, #0
	b _0804ECE2
	.align 2, 0
_0804ECCC: .4byte gCurrentSprite
_0804ECD0: .4byte 0x083852BC
_0804ECD4: .4byte gSpriteRandomNumber
_0804ECD8:
	ldr r2, _0804ECF8 @ =gFrameCounter8Bit
	ldrb r1, [r2]
	ldrh r0, [r3, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
_0804ECE2:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804ECFC
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	b _0804ED04
	.align 2, 0
_0804ECF8: .4byte gSpriteRandomNumber
_0804ECFC:
	ldrb r1, [r2]
	lsls r1, r1, #1
	ldrh r0, [r3, #4]
	subs r0, r0, r1
_0804ED04:
	strh r0, [r3, #4]
_0804ED06:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start MetroidSwaying
MetroidSwaying: @ 0x0804ED14
	push {r4, r5, r6, r7, lr}
	ldr r2, _0804ED68 @ =gCurrentSprite
	adds r5, r2, #0
	adds r5, #0x31
	ldrb r1, [r5]
	ldr r4, _0804ED6C @ =0x0838487C
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r6, _0804ED70 @ =0x00007FFF
	cmp r0, r6
	bne _0804ED34
	ldrh r3, [r4]
	movs r1, #0
_0804ED34:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	adds r5, r2, #0
	adds r5, #0x30
	ldrb r1, [r5]
	ldr r4, _0804ED74 @ =0x083848FC
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	bne _0804ED58
	ldrh r3, [r4]
	movs r1, #0
_0804ED58:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804ED68: .4byte gCurrentSprite
_0804ED6C: .4byte 0x0838487C
_0804ED70: .4byte 0x00007FFF
_0804ED74: .4byte 0x083848FC

	thumb_func_start MetroidFloatingInTube
MetroidFloatingInTube: @ 0x0804ED78
	push {r4, r5, r6, r7, lr}
	ldr r1, _0804ED90 @ =gCurrentSprite
	ldrh r5, [r1]
	movs r0, #2
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r3, r1, #0
	cmp r0, #0
	bne _0804ED94
	strh r0, [r3]
	b _0804F054
	.align 2, 0
_0804ED90: .4byte gCurrentSprite
_0804ED94:
	movs r4, #0
	adds r0, r3, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0x10
	beq _0804EDA6
	b _0804EEF8
_0804EDA6:
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r1, _0804EDD8 @ =0x0838475C
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _0804EDDC @ =0x00007FFF
	cmp r1, r0
	bne _0804EDE4
	ldr r0, _0804EDE0 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0804EDD2
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r1, #0
	eors r0, r5
	strh r0, [r3]
_0804EDD2:
	mov r2, ip
	strb r4, [r2]
	b _0804EE50
	.align 2, 0
_0804EDD8: .4byte 0x0838475C
_0804EDDC: .4byte 0x00007FFF
_0804EDE0: .4byte gSpriteRandomNumber
_0804EDE4:
	adds r0, r2, #1
	mov r7, ip
	strb r0, [r7]
	ldrh r1, [r3, #2]
	lsrs r1, r1, #2
	ldr r0, _0804EE0C @ =gBg1YPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r5
	cmp r0, #0
	beq _0804EE10
	cmp r1, #0x58
	bls _0804EE16
	movs r4, #1
	b _0804EE1A
	.align 2, 0
_0804EE0C: .4byte gBg1YPosition
_0804EE10:
	cmp r1, #0x3b
	bhi _0804EE16
	movs r4, #1
_0804EE16:
	cmp r4, #0
	beq _0804EE38
_0804EE1A:
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xc
	bne _0804EE34
	movs r0, #0xd
	b _0804EE36
_0804EE34:
	movs r0, #0xc
_0804EE36:
	strb r0, [r1]
_0804EE38:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804EE4A
	ldrh r0, [r3, #2]
	adds r0, r0, r6
	b _0804EE4E
_0804EE4A:
	ldrh r0, [r3, #2]
	subs r0, r0, r6
_0804EE4E:
	strh r0, [r3, #2]
_0804EE50:
	adds r5, r3, #0
	adds r5, #0x30
	ldrb r2, [r5]
	ldr r1, _0804EE94 @ =0x0838479C
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _0804EE98 @ =0x00007FFF
	cmp r1, r0
	bne _0804EE6A
	b _0804EFBC
_0804EE6A:
	adds r0, r2, #1
	strb r0, [r5]
	ldrh r1, [r3, #4]
	lsrs r1, r1, #2
	ldr r0, _0804EE9C @ =gBg1XPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r2, #0x77
	bhi _0804EEA6
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804EEA0
	cmp r2, #0x40
	bls _0804EEC2
	b _0804EEBC
	.align 2, 0
_0804EE94: .4byte 0x0838479C
_0804EE98: .4byte 0x00007FFF
_0804EE9C: .4byte gBg1XPosition
_0804EEA0:
	cmp r2, #0x27
	bhi _0804EEC2
	b _0804EEBC
_0804EEA6:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804EEB8
	cmp r2, #0xc8
	bls _0804EEC2
	b _0804EEBC
_0804EEB8:
	cmp r2, #0xaf
	bhi _0804EEC2
_0804EEBC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0804EEC2:
	cmp r4, #0
	beq _0804EEE4
	ldrh r0, [r3]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r1, r7, #0
	eors r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xc
	bne _0804EEE0
	movs r0, #0xd
	b _0804EEE2
_0804EEE0:
	movs r0, #0xc
_0804EEE2:
	strb r0, [r1]
_0804EEE4:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804EEF2
	b _0804F04E
_0804EEF2:
	ldrh r0, [r3, #4]
	adds r0, r0, r6
	b _0804F052
_0804EEF8:
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r1, _0804EF2C @ =0x083847EC
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _0804EF30 @ =0x00007FFF
	cmp r1, r0
	bne _0804EF38
	ldr r0, _0804EF34 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0804EF24
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r1, #0
	eors r0, r5
	strh r0, [r3]
_0804EF24:
	mov r2, ip
	strb r4, [r2]
	b _0804EFA4
	.align 2, 0
_0804EF2C: .4byte 0x083847EC
_0804EF30: .4byte 0x00007FFF
_0804EF34: .4byte gSpriteRandomNumber
_0804EF38:
	adds r0, r2, #1
	mov r7, ip
	strb r0, [r7]
	ldrh r1, [r3, #2]
	lsrs r1, r1, #2
	ldr r0, _0804EF60 @ =gBg1YPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r5
	cmp r0, #0
	beq _0804EF64
	cmp r1, #0x64
	bls _0804EF6A
	movs r4, #1
	b _0804EF6E
	.align 2, 0
_0804EF60: .4byte gBg1YPosition
_0804EF64:
	cmp r1, #0x1d
	bhi _0804EF6A
	movs r4, #1
_0804EF6A:
	cmp r4, #0
	beq _0804EF8C
_0804EF6E:
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xc
	bne _0804EF88
	movs r0, #0xd
	b _0804EF8A
_0804EF88:
	movs r0, #0xc
_0804EF8A:
	strb r0, [r1]
_0804EF8C:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804EF9E
	ldrh r0, [r3, #2]
	adds r0, r0, r6
	b _0804EFA2
_0804EF9E:
	ldrh r0, [r3, #2]
	subs r0, r0, r6
_0804EFA2:
	strh r0, [r3, #2]
_0804EFA4:
	adds r5, r3, #0
	adds r5, #0x30
	ldrb r2, [r5]
	ldr r1, _0804EFD8 @ =0x0838482C
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r0, _0804EFDC @ =0x00007FFF
	cmp r1, r0
	bne _0804EFE4
_0804EFBC:
	ldr r0, _0804EFE0 @ =gFrameCounter8Bit
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0804EFD0
	ldrh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	eors r0, r1
	strh r0, [r3]
_0804EFD0:
	movs r0, #0
	strb r0, [r5]
	b _0804F054
	.align 2, 0
_0804EFD8: .4byte 0x0838482C
_0804EFDC: .4byte 0x00007FFF
_0804EFE0: .4byte gSpriteRandomNumber
_0804EFE4:
	adds r0, r2, #1
	strb r0, [r5]
	ldrh r1, [r3, #4]
	lsrs r1, r1, #2
	ldr r0, _0804F00C @ =gBg1XPosition
	ldrh r0, [r0]
	lsrs r0, r0, #2
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F010
	cmp r2, #0x8c
	bls _0804F01A
	b _0804F014
	.align 2, 0
_0804F00C: .4byte gBg1XPosition
_0804F010:
	cmp r2, #0x63
	bhi _0804F01A
_0804F014:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0804F01A:
	cmp r4, #0
	beq _0804F03C
	ldrh r0, [r3]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r1, r7, #0
	eors r0, r1
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0xc
	bne _0804F038
	movs r0, #0xd
	b _0804F03A
_0804F038:
	movs r0, #0xc
_0804F03A:
	strb r0, [r1]
_0804F03C:
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F04E
	ldrh r0, [r3, #4]
	adds r0, r0, r6
	b _0804F052
_0804F04E:
	ldrh r0, [r3, #4]
	subs r0, r0, r6
_0804F052:
	strh r0, [r3, #4]
_0804F054:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MetroidFloatingNearSaX
MetroidFloatingNearSaX: @ 0x0804F05C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _0804F104 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	ldr r4, _0804F108 @ =0x0838487C
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r6, _0804F10C @ =0x00007FFF
	cmp r0, r6
	bne _0804F082
	ldrh r3, [r4]
	movs r1, #0
_0804F082:
	adds r0, r1, #1
	mov r7, ip
	strb r0, [r7]
	ldrh r0, [r2, #2]
	adds r0, r0, r3
	movs r1, #0
	mov r8, r1
	strh r0, [r2, #2]
	adds r5, r2, #0
	adds r5, #0x30
	ldrb r1, [r5]
	ldr r4, _0804F110 @ =0x083848FC
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r6
	bne _0804F0AC
	ldrh r3, [r4]
	movs r1, #0
_0804F0AC:
	adds r0, r1, #1
	strb r0, [r5]
	ldrh r0, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r2, #6]
	subs r0, #1
	strh r0, [r2, #6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804F0FA
	adds r1, r2, #0
	adds r1, #0x24
	movs r0, #0x1a
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x2f
	mov r1, r8
	strb r1, [r0]
	movs r0, #1
	strb r0, [r5]
	adds r1, r2, #0
	adds r1, #0x2e
	mov r3, r8
	strb r3, [r1]
	mov r5, ip
	strb r0, [r5]
	ldrh r1, [r2]
	ldr r0, _0804F114 @ =0x0000F7FF
	ands r0, r1
	strh r0, [r2]
	adds r0, r2, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F0FA
	ldr r0, _0804F118 @ =0x0000023A
	bl SoundPlay
_0804F0FA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F104: .4byte gCurrentSprite
_0804F108: .4byte 0x0838487C
_0804F10C: .4byte 0x00007FFF
_0804F110: .4byte 0x083848FC
_0804F114: .4byte 0x0000F7FF
_0804F118: .4byte 0x0000023A

	thumb_func_start MetroidFloatingTowardsSaX
MetroidFloatingTowardsSaX: @ 0x0804F11C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r2, _0804F21C @ =gCurrentSprite
	ldrh r0, [r2, #2]
	mov sl, r0
	ldrh r1, [r2, #4]
	mov sb, r1
	movs r3, #0x10
	mov r8, r3
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _0804F1E6
	movs r6, #0
	adds r5, r4, #0
_0804F146:
	ldr r1, _0804F220 @ =gSpriteData
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804F1DC
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0804F1DC
	ldrb r0, [r2, #0x1d]
	cmp r0, #0xbc
	bne _0804F1DC
	ldrh r7, [r2, #2]
	ldrh r3, [r2, #4]
	mov r1, sl
	add r1, r8
	adds r0, r7, #0
	subs r0, #0x78
	cmp r1, r0
	ble _0804F1DC
	mov r0, sl
	mov r1, r8
	subs r0, r0, r1
	mov ip, r0
	cmp ip, r7
	bge _0804F1DC
	mov r1, sb
	add r1, r8
	adds r0, r3, #0
	subs r0, #0x14
	cmp r1, r0
	ble _0804F1DC
	mov r7, sb
	mov r0, r8
	subs r1, r7, r0
	adds r0, r3, #0
	adds r0, #0x14
	cmp r1, r0
	bge _0804F1DC
	ldrh r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r5]
	adds r0, r5, #0
	adds r0, #0x2f
	movs r7, #0
	strb r7, [r0]
	adds r0, #1
	movs r1, #1
	strb r1, [r0]
	subs r0, #2
	movs r3, #0
	strb r3, [r0]
	ldr r7, _0804F224 @ =0x030006ED
	strb r1, [r7]
	adds r1, r2, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #2
	bne _0804F1DC
	movs r0, #0x18
	strb r0, [r1]
	ldr r0, _0804F228 @ =0x0000023B
	bl SoundPlay
_0804F1DC:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x17
	bls _0804F146
_0804F1E6:
	ldr r0, _0804F22C @ =gFrameCounter8Bit
	ldrb r2, [r0]
	adds r3, r2, #0
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0804F28C
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F23C
	ldr r0, _0804F230 @ =gXParasiteTargetYPosition
	adds r1, r2, #0
	adds r1, #0x50
	ldrh r0, [r0]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, _0804F234 @ =gXParasiteTargetXPosition
	ldr r3, _0804F238 @ =0x0000FFE0
	adds r0, r2, r3
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0804F274
	.align 2, 0
_0804F21C: .4byte gCurrentSprite
_0804F220: .4byte gSpriteData
_0804F224: .4byte 0x030006ED
_0804F228: .4byte 0x0000023B
_0804F22C: .4byte gSpriteRandomNumber
_0804F230: .4byte gXParasiteTargetYPosition
_0804F234: .4byte gXParasiteTargetXPosition
_0804F238: .4byte 0x0000FFE0
_0804F23C:
	cmp r0, #2
	bne _0804F25C
	ldr r0, _0804F254 @ =gXParasiteTargetYPosition
	adds r1, r2, #0
	adds r1, #0x32
	ldrh r0, [r0]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _0804F258 @ =gXParasiteTargetXPosition
	subs r1, #0x3a
	b _0804F270
	.align 2, 0
_0804F254: .4byte gXParasiteTargetYPosition
_0804F258: .4byte gXParasiteTargetXPosition
_0804F25C:
	ldr r1, _0804F280 @ =gXParasiteTargetYPosition
	ldr r7, _0804F284 @ =0x0000FF88
	adds r0, r3, r7
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _0804F288 @ =gXParasiteTargetXPosition
	adds r1, r3, #0
	subs r1, #0x20
_0804F270:
	ldrh r0, [r0]
	subs r0, r0, r1
_0804F274:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0xa
	mov r8, r0
	movs r5, #0xa
	b _0804F2EA
	.align 2, 0
_0804F280: .4byte gXParasiteTargetYPosition
_0804F284: .4byte 0x0000FF88
_0804F288: .4byte gXParasiteTargetXPosition
_0804F28C:
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804F2B0
	ldr r0, _0804F2A8 @ =gXParasiteTargetYPosition
	ldrh r0, [r0]
	subs r0, #0x48
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _0804F2AC @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	subs r0, #0x24
	b _0804F2E0
	.align 2, 0
_0804F2A8: .4byte gXParasiteTargetYPosition
_0804F2AC: .4byte gXParasiteTargetXPosition
_0804F2B0:
	cmp r0, #2
	bne _0804F2D0
	ldr r0, _0804F2C8 @ =gXParasiteTargetYPosition
	ldrh r0, [r0]
	subs r0, #0x32
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _0804F2CC @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	adds r0, #8
	b _0804F2E0
	.align 2, 0
_0804F2C8: .4byte gXParasiteTargetYPosition
_0804F2CC: .4byte gXParasiteTargetXPosition
_0804F2D0:
	ldr r0, _0804F324 @ =gXParasiteTargetYPosition
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _0804F328 @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	adds r0, #0x1e
_0804F2E0:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r1, #0x14
	mov r8, r1
	movs r5, #0x1e
_0804F2EA:
	ldrh r1, [r4]
	movs r6, #0x80
	lsls r6, r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804F34C
	adds r2, r4, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	cmp r0, #0
	bne _0804F32C
	ldrh r1, [r4, #4]
	subs r0, r3, #4
	cmp r1, r0
	bgt _0804F35E
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, r5
	bhs _0804F318
	adds r0, #1
	strb r0, [r1]
_0804F318:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	b _0804F3A2
	.align 2, 0
_0804F324: .4byte gXParasiteTargetYPosition
_0804F328: .4byte gXParasiteTargetXPosition
_0804F32C:
	subs r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0804F340
	lsrs r0, r0, #0x1a
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	b _0804F3A2
_0804F340:
	ldrh r1, [r4]
	ldr r0, _0804F348 @ =0x0000FDFF
	ands r0, r1
	b _0804F398
	.align 2, 0
_0804F348: .4byte 0x0000FDFF
_0804F34C:
	adds r2, r4, #0
	adds r2, #0x2f
	ldrb r0, [r2]
	cmp r0, #0
	bne _0804F37C
	ldrh r1, [r4, #4]
	adds r0, r3, #4
	cmp r1, r0
	bge _0804F368
_0804F35E:
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	strb r0, [r2]
	b _0804F3A2
_0804F368:
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, r5
	bhs _0804F376
	adds r0, #1
	strb r0, [r1]
_0804F376:
	ldrb r1, [r1]
	lsrs r1, r1, #2
	b _0804F38A
_0804F37C:
	subs r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0804F392
	adds r1, r0, #0
	lsrs r1, r1, #0x1a
_0804F38A:
	ldrh r0, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	b _0804F3A2
_0804F392:
	ldrh r1, [r4]
	adds r0, r6, #0
	orrs r0, r1
_0804F398:
	strh r0, [r4]
	adds r1, r4, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
_0804F3A2:
	adds r2, r4, #0
	ldrh r5, [r2]
	movs r6, #0x80
	lsls r6, r6, #3
	adds r0, r6, #0
	ands r0, r5
	cmp r0, #0
	beq _0804F400
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	cmp r0, #0
	bne _0804F3DE
	ldrh r1, [r2, #2]
	subs r0, r7, #4
	cmp r1, r0
	bgt _0804F412
	adds r1, r2, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, r8
	bhs _0804F3D2
	adds r0, #1
	strb r0, [r1]
_0804F3D2:
	ldrb r0, [r1]
	lsrs r0, r0, #2
	ldrh r7, [r2, #2]
	adds r0, r0, r7
	strh r0, [r2, #2]
	b _0804F456
_0804F3DE:
	subs r1, r0, #1
	strb r1, [r3]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0804F3F2
	lsrs r0, r0, #0x1a
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	b _0804F456
_0804F3F2:
	ldr r0, _0804F3FC @ =0x0000FBFF
	ands r0, r5
	strh r0, [r2]
	adds r1, r2, #0
	b _0804F450
	.align 2, 0
_0804F3FC: .4byte 0x0000FBFF
_0804F400:
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r0, [r3]
	cmp r0, #0
	bne _0804F430
	ldrh r1, [r2, #2]
	adds r0, r7, #4
	cmp r1, r0
	bge _0804F41C
_0804F412:
	adds r0, r2, #0
	adds r0, #0x31
	ldrb r0, [r0]
	strb r0, [r3]
	b _0804F456
_0804F41C:
	adds r1, r2, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, r8
	bhs _0804F42A
	adds r0, #1
	strb r0, [r1]
_0804F42A:
	ldrb r1, [r1]
	lsrs r1, r1, #2
	b _0804F43E
_0804F430:
	subs r1, r0, #1
	strb r1, [r3]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0804F446
	adds r1, r0, #0
	lsrs r1, r1, #0x1a
_0804F43E:
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	b _0804F456
_0804F446:
	ldrh r1, [r4]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r4]
	adds r1, r4, #0
_0804F450:
	adds r1, #0x31
	movs r0, #1
	strb r0, [r1]
_0804F456:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Metroid
Metroid: @ 0x0804F464
	push {lr}
	ldr r0, _0804F47C @ =gCurrentSprite
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x1c
	bhi _0804F514
	lsls r0, r0, #2
	ldr r1, _0804F480 @ =_0804F484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F47C: .4byte gCurrentSprite
_0804F480: .4byte _0804F484
_0804F484: @ jump table
	.4byte _0804F4F8 @ case 0
	.4byte _0804F514 @ case 1
	.4byte _0804F4FE @ case 2
	.4byte _0804F514 @ case 3
	.4byte _0804F514 @ case 4
	.4byte _0804F514 @ case 5
	.4byte _0804F514 @ case 6
	.4byte _0804F514 @ case 7
	.4byte _0804F514 @ case 8
	.4byte _0804F514 @ case 9
	.4byte _0804F514 @ case 10
	.4byte _0804F514 @ case 11
	.4byte _0804F514 @ case 12
	.4byte _0804F514 @ case 13
	.4byte _0804F514 @ case 14
	.4byte _0804F514 @ case 15
	.4byte _0804F514 @ case 16
	.4byte _0804F514 @ case 17
	.4byte _0804F514 @ case 18
	.4byte _0804F514 @ case 19
	.4byte _0804F514 @ case 20
	.4byte _0804F514 @ case 21
	.4byte _0804F514 @ case 22
	.4byte _0804F514 @ case 23
	.4byte _0804F504 @ case 24
	.4byte _0804F514 @ case 25
	.4byte _0804F50A @ case 26
	.4byte _0804F514 @ case 27
	.4byte _0804F510 @ case 28
_0804F4F8:
	bl MetroidInit
	b _0804F514
_0804F4FE:
	bl MetroidFloatingInTube
	b _0804F514
_0804F504:
	bl MetroidFloatingNearSaX
	b _0804F514
_0804F50A:
	bl MetroidFloatingTowardsSaX
	b _0804F514
_0804F510:
	bl MetroidSwaying
_0804F514:
	pop {r0}
	bx r0

	thumb_func_start LabDebrisSetCollision
LabDebrisSetCollision: @ 0x0804F518
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _0804F570 @ =gCurrentSprite
	ldrh r1, [r0, #2]
	ldrh r6, [r0, #4]
	adds r0, #0x2a
	ldrb r4, [r0]
	ldr r0, _0804F574 @ =gCurrentClipdataAffectingAction
	mov r8, r0
	strb r7, [r0]
	adds r5, r1, #0
	subs r5, #0x20
	adds r0, r5, #0
	adds r1, r6, #0
	bl ClipdataProcess
	mov r0, r8
	strb r7, [r0]
	adds r1, r6, #0
	adds r1, #0x40
	adds r0, r5, #0
	bl ClipdataProcess
	subs r4, #0x14
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	cmp r4, #1
	bhi _0804F564
	mov r0, r8
	strb r7, [r0]
	adds r1, r6, #0
	adds r1, #0x80
	adds r0, r5, #0
	bl ClipdataProcess
_0804F564:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F570: .4byte gCurrentSprite
_0804F574: .4byte gCurrentClipdataAffectingAction

	thumb_func_start LabDebrisInit
LabDebrisInit: @ 0x0804F578
	push {r4, lr}
	bl EventCheckOn_RestrictedLabExplosion
	adds r1, r0, #0
	cmp r1, #0
	bne _0804F590
	ldr r0, _0804F58C @ =gCurrentSprite
	strh r1, [r0]
	b _0804F60E
	.align 2, 0
_0804F58C: .4byte gCurrentSprite
_0804F590:
	ldr r0, _0804F5E4 @ =gCurrentSprite
	mov ip, r0
	adds r0, #0x25
	movs r2, #0
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x27
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x30
	strb r0, [r1]
	movs r3, #0
	ldr r1, _0804F5E8 @ =0x0000FFFC
	mov r4, ip
	strh r1, [r4, #0xa]
	movs r0, #4
	strh r0, [r4, #0xc]
	strh r1, [r4, #0xe]
	strh r0, [r4, #0x10]
	mov r1, ip
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2f
	strb r3, [r0]
	ldr r1, _0804F5EC @ =0x08385C1C
	str r1, [r4, #0x18]
	strb r3, [r4, #0x1c]
	strh r2, [r4, #0x16]
	subs r0, #5
	ldrb r0, [r0]
	cmp r0, #0x14
	bne _0804F5F4
	ldr r0, _0804F5F0 @ =0x08385C2C
	str r0, [r4, #0x18]
	b _0804F608
	.align 2, 0
_0804F5E4: .4byte gCurrentSprite
_0804F5E8: .4byte 0x0000FFFC
_0804F5EC: .4byte 0x08385C1C
_0804F5F0: .4byte 0x08385C2C
_0804F5F4:
	cmp r0, #0x15
	bne _0804F604
	ldr r0, _0804F600 @ =0x08385C3C
	mov r1, ip
	str r0, [r1, #0x18]
	b _0804F608
	.align 2, 0
_0804F600: .4byte 0x08385C3C
_0804F604:
	mov r4, ip
	str r1, [r4, #0x18]
_0804F608:
	movs r0, #2
	bl LabDebrisSetCollision
_0804F60E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start LabDebrisIdle
LabDebrisIdle: @ 0x0804F614
	push {lr}
	bl EventCheckOn_Escape
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bne _0804F66A
	ldr r1, _0804F640 @ =gCurrentSprite
	adds r3, r1, #0
	adds r3, #0x31
	movs r0, #0
	strb r0, [r3]
	adds r0, r1, #0
	adds r0, #0x24
	strb r2, [r0]
	adds r0, #6
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _0804F644
	adds r1, #0x2e
	movs r0, #0x30
	b _0804F668
	.align 2, 0
_0804F640: .4byte gCurrentSprite
_0804F644:
	cmp r0, #0x15
	bne _0804F64E
	adds r1, #0x2e
	movs r0, #0x22
	b _0804F668
_0804F64E:
	ldr r0, _0804F660 @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	ldrh r2, [r1, #4]
	cmp r0, r2
	bls _0804F664
	adds r1, #0x2e
	movs r0, #0xa
	b _0804F668
	.align 2, 0
_0804F660: .4byte gXParasiteTargetXPosition
_0804F664:
	adds r1, #0x2e
	movs r0, #0x18
_0804F668:
	strb r0, [r1]
_0804F66A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start LabDebrisFalling
LabDebrisFalling: @ 0x0804F670
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0804F6BC @ =gCurrentSprite
	ldrh r6, [r4, #2]
	mov r8, r6
	ldrh r5, [r4, #4]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r7, [r0]
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804F6DC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F69A
	b _0804F83A
_0804F69A:
	movs r0, #1
	bl LabDebrisSetCollision
	adds r0, r6, #0
	adds r0, #0x20
	adds r1, r5, #0
	movs r2, #0x2f
	bl ParticleSet
	ldr r0, _0804F6C0 @ =0x0000023D
	bl SoundPlay
	cmp r7, #0x13
	bne _0804F6C4
	adds r4, r6, #0
	b _0804F786
	.align 2, 0
_0804F6BC: .4byte gCurrentSprite
_0804F6C0: .4byte 0x0000023D
_0804F6C4:
	cmp r7, #0x15
	beq _0804F738
	ldr r0, _0804F6D8 @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	ldrh r4, [r4, #4]
	cmp r0, r4
	bhi _0804F762
	adds r4, r6, #0
	b _0804F786
	.align 2, 0
_0804F6D8: .4byte gXParasiteTargetXPosition
_0804F6DC:
	adds r0, r6, #0
	adds r1, r5, #0
	bl SpriteUtilCheckVerticalCollisionAtPositionSlopes
	adds r1, r0, #0
	ldr r0, _0804F728 @ =gPreviousVerticalCollisionCheck
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804F7A6
	movs r2, #0
	strh r1, [r4, #2]
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x18
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x31
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0x34
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0804F72C @ =gIoRegisters
	ldrb r1, [r0, #0xa]
	movs r0, #3
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x21
	strb r0, [r1]
	ldr r0, _0804F730 @ =0x0000023E
	bl SoundPlay
	cmp r7, #0x13
	bne _0804F734
	adds r4, r6, #0
	b _0804F786
	.align 2, 0
_0804F728: .4byte gPreviousVerticalCollisionCheck
_0804F72C: .4byte gIoRegisters
_0804F730: .4byte 0x0000023E
_0804F734:
	cmp r7, #0x15
	bne _0804F758
_0804F738:
	adds r4, r6, #0
	subs r4, #0x40
	adds r3, r5, #0
	subs r3, #0x10
	movs r0, #0
	movs r1, #0x13
	adds r2, r4, #0
	bl SpriteDebrisInit
	movs r0, #0
	movs r1, #4
	adds r2, r4, #0
	adds r3, r5, #0
	bl SpriteDebrisInit
	b _0804F83A
_0804F758:
	ldr r0, _0804F780 @ =gXParasiteTargetXPosition
	ldrh r0, [r0]
	ldrh r4, [r4, #4]
	cmp r0, r4
	bls _0804F784
_0804F762:
	adds r3, r5, #0
	subs r3, #8
	movs r0, #0
	movs r1, #0x13
	adds r2, r6, #0
	bl SpriteDebrisInit
	adds r3, r5, #0
	adds r3, #0x10
	movs r0, #0
	movs r1, #4
	adds r2, r6, #0
	bl SpriteDebrisInit
	b _0804F83A
	.align 2, 0
_0804F780: .4byte gXParasiteTargetXPosition
_0804F784:
	mov r4, r8
_0804F786:
	subs r4, #0x20
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0
	movs r1, #0x11
	adds r2, r4, #0
	bl SpriteDebrisInit
	adds r3, r5, #0
	subs r3, #0x10
	movs r0, #0
	movs r1, #0x12
	adds r2, r4, #0
	bl SpriteDebrisInit
	b _0804F83A
_0804F7A6:
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0x31
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ldr r6, _0804F7DC @ =sSpritesFallingSpeed
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	mov r8, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, _0804F7E0 @ =0x00007FFF
	cmp r1, r0
	bne _0804F7E4
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r4, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0804F7EE
	.align 2, 0
_0804F7DC: .4byte sSpritesFallingSpeed
_0804F7E0: .4byte 0x00007FFF
_0804F7E4:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r4, #2]
	add r0, r8
_0804F7EE:
	strh r0, [r4, #2]
	ldr r1, _0804F818 @ =gCurrentSprite
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0804F83A
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0804F81C
	ldrh r0, [r1, #2]
	subs r0, #0x20
	adds r1, r5, #0
	movs r2, #0x27
	bl ParticleSet
	b _0804F83A
	.align 2, 0
_0804F818: .4byte gCurrentSprite
_0804F81C:
	cmp r7, #0x13
	bne _0804F826
	adds r0, r5, #0
	subs r0, #0xc
	b _0804F82A
_0804F826:
	adds r0, r5, #0
	adds r0, #0xc
_0804F82A:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r0, [r1, #2]
	subs r0, #0x20
	adds r1, r5, #0
	movs r2, #0x27
	bl ParticleSet
_0804F83A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start LabDebrisCrumbling
LabDebrisCrumbling: @ 0x0804F844
	push {r4, r5, r6, lr}
	ldr r3, _0804F870 @ =gCurrentSprite
	movs r0, #0x31
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	ldr r5, _0804F874 @ =sSpritesFallingSpeedHovering
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r4, [r0]
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0804F878 @ =0x00007FFF
	cmp r1, r0
	bne _0804F87C
	subs r1, r2, #1
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r3, #2]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _0804F886
	.align 2, 0
_0804F870: .4byte gCurrentSprite
_0804F874: .4byte sSpritesFallingSpeedHovering
_0804F878: .4byte 0x00007FFF
_0804F87C:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, r0, r4
_0804F886:
	strh r0, [r3, #2]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start LabDebris
LabDebris: @ 0x0804F890
	push {lr}
	ldr r0, _0804F8B0 @ =gCurrentSprite
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804F8C4
	cmp r0, #1
	bgt _0804F8B4
	cmp r0, #0
	beq _0804F8BE
	b _0804F8D4
	.align 2, 0
_0804F8B0: .4byte gCurrentSprite
_0804F8B4:
	cmp r0, #2
	beq _0804F8CA
	cmp r0, #0x18
	beq _0804F8D0
	b _0804F8D4
_0804F8BE:
	bl LabDebrisInit
	b _0804F8D4
_0804F8C4:
	bl LabDebrisIdle
	b _0804F8D4
_0804F8CA:
	bl LabDebrisFalling
	b _0804F8D4
_0804F8D0:
	bl LabDebrisCrumbling
_0804F8D4:
	pop {r0}
	bx r0

	thumb_func_start PowampInit
PowampInit: @ 0x0804F8D8
	push {r4, r5, lr}
	bl SpriteUtilTrySetAbsorbXFlag
	ldr r3, _0804F938 @ =gCurrentSprite
	adds r0, r3, #0
	adds r0, #0x27
	movs r4, #0
	movs r5, #0x30
	strb r5, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r1, r3, #0
	adds r1, #0x29
	movs r0, #0x10
	strb r0, [r1]
	ldr r2, _0804F93C @ =sPrimarySpriteStats
	ldrb r1, [r3, #0x1d]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	strh r0, [r3, #0x14]
	adds r1, r3, #0
	adds r1, #0x25
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _0804F940 @ =0x08386638
	str r0, [r3, #0x18]
	strb r2, [r3, #0x1c]
	strh r4, [r3, #0x16]
	adds r0, r3, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F958
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0804F944
	strh r4, [r3]
	b _0804F98C
	.align 2, 0
_0804F938: .4byte gCurrentSprite
_0804F93C: .4byte sPrimarySpriteStats
_0804F940: .4byte 0x08386638
_0804F944:
	ldr r0, _0804F954 @ =0x0000FFB8
	strh r0, [r3, #0xa]
	strh r4, [r3, #0xc]
	adds r0, #0x18
	strh r0, [r3, #0xe]
	strh r5, [r3, #0x10]
	b _0804F968
	.align 2, 0
_0804F954: .4byte 0x0000FFB8
_0804F958:
	ldr r0, _0804F980 @ =0x0000FFCC
	strh r0, [r3, #0xa]
	adds r0, #0x20
	strh r0, [r3, #0xc]
	subs r0, #0x14
	strh r0, [r3, #0xe]
	movs r0, #0x28
	strh r0, [r3, #0x10]
_0804F968:
	ldr r2, _0804F984 @ =gCurrentSprite
	adds r1, r2, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0x59
	bne _0804F988
	movs r0, #0x5a
	strb r0, [r1]
	movs r0, #0x2c
	strh r0, [r2, #6]
	b _0804F98C
	.align 2, 0
_0804F980: .4byte 0x0000FFCC
_0804F984: .4byte gCurrentSprite
_0804F988:
	movs r0, #2
	strb r0, [r1]
_0804F98C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PowampIdleInit
PowampIdleInit: @ 0x0804F994
	ldr r1, _0804F9AC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #2
	strb r0, [r2]
	ldr r0, _0804F9B0 @ =0x08386638
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804F9AC: .4byte gCurrentSprite
_0804F9B0: .4byte 0x08386638

	thumb_func_start PowampIdle
PowampIdle: @ 0x0804F9B4
	push {r4, lr}
	ldr r4, _0804F9E4 @ =gCurrentSprite
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0804F9DC
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r2, #0
	movs r1, #0xc0
	bl SpriteUtilCheckSamusNearSpriteAboveBelowSeparateRanges
	cmp r0, #0
	beq _0804F9DC
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0x17
	strb r0, [r1]
_0804F9DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F9E4: .4byte gCurrentSprite

	thumb_func_start PowampExtendingInit
PowampExtendingInit: @ 0x0804F9E8
	push {lr}
	ldr r1, _0804FA14 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x18
	strb r0, [r2]
	ldr r0, _0804FA18 @ =0x08386678
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804FA10
	movs r0, #0xe7
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0804FA10:
	pop {r0}
	bx r0
	.align 2, 0
_0804FA14: .4byte gCurrentSprite
_0804FA18: .4byte 0x08386678

	thumb_func_start PowampExtending
PowampExtending: @ 0x0804FA1C
	push {lr}
	ldr r1, _0804FA44 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	cmp r0, #0
	bne _0804FA30
	ldrb r0, [r1, #0x1c]
	cmp r0, #4
	bne _0804FA30
	ldr r0, _0804FA48 @ =0x0000FF74
	strh r0, [r1, #0xa]
_0804FA30:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804FA40
	ldr r0, _0804FA44 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x19
	strb r1, [r0]
_0804FA40:
	pop {r0}
	bx r0
	.align 2, 0
_0804FA44: .4byte gCurrentSprite
_0804FA48: .4byte 0x0000FF74

	thumb_func_start PowampExtendedInit
PowampExtendedInit: @ 0x0804FA4C
	ldr r1, _0804FA64 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1a
	strb r0, [r2]
	ldr r0, _0804FA68 @ =0x08386658
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	bx lr
	.align 2, 0
_0804FA64: .4byte gCurrentSprite
_0804FA68: .4byte 0x08386658

	thumb_func_start PowampExtended
PowampExtended: @ 0x0804FA6C
	push {lr}
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r2, #0
	movs r1, #0xc0
	bl SpriteUtilCheckSamusNearSpriteAboveBelowSeparateRanges
	cmp r0, #0
	bne _0804FA86
	ldr r0, _0804FA8C @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #0x1b
	strb r1, [r0]
_0804FA86:
	pop {r0}
	bx r0
	.align 2, 0
_0804FA8C: .4byte gCurrentSprite

	thumb_func_start PowampRetractingInit
PowampRetractingInit: @ 0x0804FA90
	push {lr}
	ldr r1, _0804FABC @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1c
	strb r0, [r2]
	ldr r0, _0804FAC0 @ =0x083866B0
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804FAB6
	ldr r0, _0804FAC4 @ =0x000001CF
	bl SoundPlayNotAlreadyPlaying
_0804FAB6:
	pop {r0}
	bx r0
	.align 2, 0
_0804FABC: .4byte gCurrentSprite
_0804FAC0: .4byte 0x083866B0
_0804FAC4: .4byte 0x000001CF

	thumb_func_start PowampRetracting
PowampRetracting: @ 0x0804FAC8
	push {lr}
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r2, #0
	movs r1, #0xc0
	bl SpriteUtilCheckSamusNearSpriteAboveBelowSeparateRanges
	cmp r0, #0
	beq _0804FB00
	ldr r1, _0804FAF4 @ =gCurrentSprite
	adds r2, r1, #0
	adds r2, #0x24
	movs r3, #0
	movs r0, #0x1a
	strb r0, [r2]
	ldr r0, _0804FAF8 @ =0x08386658
	str r0, [r1, #0x18]
	strb r3, [r1, #0x1c]
	strh r3, [r1, #0x16]
	ldr r0, _0804FAFC @ =0x0000FF74
	strh r0, [r1, #0xa]
	b _0804FB22
	.align 2, 0
_0804FAF4: .4byte gCurrentSprite
_0804FAF8: .4byte 0x08386658
_0804FAFC: .4byte 0x0000FF74
_0804FB00:
	ldr r1, _0804FB28 @ =gCurrentSprite
	ldrh r0, [r1, #0x16]
	cmp r0, #2
	bne _0804FB12
	ldrb r0, [r1, #0x1c]
	cmp r0, #4
	bne _0804FB12
	ldr r0, _0804FB2C @ =0x0000FFCC
	strh r0, [r1, #0xa]
_0804FB12:
	bl SpriteUtilHasCurrentAnimationNearlyEnded
	cmp r0, #0
	beq _0804FB22
	ldr r0, _0804FB28 @ =gCurrentSprite
	adds r0, #0x24
	movs r1, #1
	strb r1, [r0]
_0804FB22:
	pop {r0}
	bx r0
	.align 2, 0
_0804FB28: .4byte gCurrentSprite
_0804FB2C: .4byte 0x0000FFCC

	thumb_func_start Powamp
Powamp: @ 0x0804FB30
	push {r4, lr}
	ldr r4, _0804FB5C @ =gCurrentSprite
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #4
	bne _0804FB4A
	movs r0, #0xe8
	lsls r0, r0, #1
	bl SoundPlayNotAlreadyPlaying
_0804FB4A:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804FB60
	bl SpriteUtilUpdateFreezeTimer
	b _0804FD3A
	.align 2, 0
_0804FB5C: .4byte gCurrentSprite
_0804FB60:
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0x5b
	bls _0804FB6C
	b _0804FD3A
_0804FB6C:
	lsls r0, r0, #2
	ldr r1, _0804FB78 @ =_0804FB7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804FB78: .4byte _0804FB7C
_0804FB7C: @ jump table
	.4byte _0804FCEC @ case 0
	.4byte _0804FCF2 @ case 1
	.4byte _0804FCF6 @ case 2
	.4byte _0804FD3A @ case 3
	.4byte _0804FD3A @ case 4
	.4byte _0804FD3A @ case 5
	.4byte _0804FD3A @ case 6
	.4byte _0804FD3A @ case 7
	.4byte _0804FD3A @ case 8
	.4byte _0804FD3A @ case 9
	.4byte _0804FD3A @ case 10
	.4byte _0804FD3A @ case 11
	.4byte _0804FD3A @ case 12
	.4byte _0804FD3A @ case 13
	.4byte _0804FD3A @ case 14
	.4byte _0804FD3A @ case 15
	.4byte _0804FD3A @ case 16
	.4byte _0804FD3A @ case 17
	.4byte _0804FD3A @ case 18
	.4byte _0804FD3A @ case 19
	.4byte _0804FD3A @ case 20
	.4byte _0804FD3A @ case 21
	.4byte _0804FD3A @ case 22
	.4byte _0804FCFC @ case 23
	.4byte _0804FD00 @ case 24
	.4byte _0804FD06 @ case 25
	.4byte _0804FD0A @ case 26
	.4byte _0804FD10 @ case 27
	.4byte _0804FD14 @ case 28
	.4byte _0804FD3A @ case 29
	.4byte _0804FD3A @ case 30
	.4byte _0804FD3A @ case 31
	.4byte _0804FD3A @ case 32
	.4byte _0804FD3A @ case 33
	.4byte _0804FD3A @ case 34
	.4byte _0804FD3A @ case 35
	.4byte _0804FD3A @ case 36
	.4byte _0804FD3A @ case 37
	.4byte _0804FD3A @ case 38
	.4byte _0804FD3A @ case 39
	.4byte _0804FD3A @ case 40
	.4byte _0804FD3A @ case 41
	.4byte _0804FD3A @ case 42
	.4byte _0804FD3A @ case 43
	.4byte _0804FD3A @ case 44
	.4byte _0804FD3A @ case 45
	.4byte _0804FD3A @ case 46
	.4byte _0804FD3A @ case 47
	.4byte _0804FD3A @ case 48
	.4byte _0804FD3A @ case 49
	.4byte _0804FD3A @ case 50
	.4byte _0804FD3A @ case 51
	.4byte _0804FD3A @ case 52
	.4byte _0804FD3A @ case 53
	.4byte _0804FD3A @ case 54
	.4byte _0804FD3A @ case 55
	.4byte _0804FD3A @ case 56
	.4byte _0804FD3A @ case 57
	.4byte _0804FD3A @ case 58
	.4byte _0804FD3A @ case 59
	.4byte _0804FD3A @ case 60
	.4byte _0804FD3A @ case 61
	.4byte _0804FD3A @ case 62
	.4byte _0804FD3A @ case 63
	.4byte _0804FD3A @ case 64
	.4byte _0804FD3A @ case 65
	.4byte _0804FD3A @ case 66
	.4byte _0804FD3A @ case 67
	.4byte _0804FD3A @ case 68
	.4byte _0804FD3A @ case 69
	.4byte _0804FD3A @ case 70
	.4byte _0804FD3A @ case 71
	.4byte _0804FD3A @ case 72
	.4byte _0804FD3A @ case 73
	.4byte _0804FD3A @ case 74
	.4byte _0804FD3A @ case 75
	.4byte _0804FD3A @ case 76
	.4byte _0804FD3A @ case 77
	.4byte _0804FD3A @ case 78
	.4byte _0804FD3A @ case 79
	.4byte _0804FD3A @ case 80
	.4byte _0804FD3A @ case 81
	.4byte _0804FD3A @ case 82
	.4byte _0804FD3A @ case 83
	.4byte _0804FD3A @ case 84
	.4byte _0804FD3A @ case 85
	.4byte _0804FD3A @ case 86
	.4byte _0804FD1A @ case 87
	.4byte _0804FD1E @ case 88
	.4byte _0804FD24 @ case 89
	.4byte _0804FD28 @ case 90
	.4byte _0804FD2E @ case 91
_0804FCEC:
	bl PowampInit
	b _0804FD3A
_0804FCF2:
	bl PowampIdleInit
_0804FCF6:
	bl PowampIdle
	b _0804FD3A
_0804FCFC:
	bl PowampExtendingInit
_0804FD00:
	bl PowampExtending
	b _0804FD3A
_0804FD06:
	bl PowampExtendedInit
_0804FD0A:
	bl PowampExtended
	b _0804FD3A
_0804FD10:
	bl PowampRetractingInit
_0804FD14:
	bl PowampRetracting
	b _0804FD3A
_0804FD1A:
	bl SpriteDyingInit
_0804FD1E:
	bl SpriteDying
	b _0804FD3A
_0804FD24:
	bl PowampInit
_0804FD28:
	bl SpriteSpawningFromX
	b _0804FD3A
_0804FD2E:
	bl XParasiteInit
	ldr r1, _0804FD40 @ =gCurrentSprite
	ldrh r0, [r1, #2]
	subs r0, #0x30
	strh r0, [r1, #2]
_0804FD3A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804FD40: .4byte gCurrentSprite
