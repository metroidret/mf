    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start IntroProcessBslShipSpawning
IntroProcessBslShipSpawning: @ 0x080930C0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0x14]
	cmp r5, #0
	bne _0809311C
	ldrh r1, [r4, #0xc]
	adds r1, #0x7a
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xe
	ldrsh r2, [r4, r0]
	movs r0, #0xc
	movs r3, #0
	bl TitleIntroSetupOam
	ldrh r1, [r4, #0xc]
	adds r1, #0x32
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4, #0xe]
	adds r2, #1
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0xd
	movs r3, #0
	bl TitleIntroSetupOam
	ldrh r1, [r4, #0xc]
	adds r1, #0x24
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xe
	ldrsh r2, [r4, r0]
	movs r0, #0xe
	movs r3, #0
	bl TitleIntroSetupOam
	movs r0, #0xc
	ldrsh r1, [r4, r0]
	movs r0, #0xe
	ldrsh r2, [r4, r0]
	movs r0, #0xf
	movs r3, #0
	bl TitleIntroSetupOam
	strb r5, [r4, #0x10]
_0809311C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessBslShipBack
IntroProcessBslShipBack: @ 0x08093124
	push {r4, lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x14]
	cmp r3, #0
	bne _0809317E
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bne _080931F0
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	strb r1, [r2, #0x13]
	ldrh r0, [r2, #0xa]
	cmp r0, #4
	bne _0809314E
	strh r3, [r2, #0xa]
_0809314E:
	ldrh r0, [r2, #0xa]
	adds r1, r0, #0
	adds r3, r0, #0
	cmp r1, #1
	bhi _0809315E
	ldrh r0, [r2, #0xe]
	adds r0, #1
	b _08093166
_0809315E:
	cmp r1, #3
	bhi _08093168
	ldrh r0, [r2, #0xe]
	subs r0, #1
_08093166:
	strh r0, [r2, #0xe]
_08093168:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x1e
	bne _08093178
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0x14]
	strb r1, [r2, #0x13]
_08093178:
	adds r0, r3, #1
	strh r0, [r2, #0xa]
	b _080931F0
_0809317E:
	cmp r3, #1
	bne _08093192
	ldrh r0, [r2, #0xc]
	movs r1, #0
	strh r0, [r2]
	ldrh r0, [r2, #0xe]
	strh r0, [r2, #2]
	strh r1, [r2, #0xa]
	movs r0, #2
	b _080931EE
_08093192:
	cmp r3, #2
	bne _080931F0
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _080931AE
	ldrh r0, [r2, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r2, #0xa]
	strb r1, [r2, #0x13]
_080931AE:
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r0, #0xe1
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r1, [r2, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r2]
	adds r3, r0, r1
	strh r3, [r2, #0xc]
	movs r4, #4
	ldrsh r0, [r2, r4]
	movs r4, #2
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	ldrh r1, [r2, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #0xb
	ldrh r1, [r2, #2]
	adds r4, r0, r1
	strh r4, [r2, #0xe]
	lsls r1, r3, #0x10
	movs r0, #0xa0
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _080931F0
	movs r0, #0
	strh r0, [r2, #0xa]
	strh r3, [r2]
	strh r4, [r2, #2]
	movs r0, #3
_080931EE:
	strb r0, [r2, #0x14]
_080931F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessDepthParticle
IntroProcessDepthParticle: @ 0x080931F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrh r1, [r6, #0xa]
	strh r1, [r6, #4]
	ldrb r0, [r6, #0x14]
	cmp r0, #0
	bne _08093222
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r0, #0x78
	movs r1, #0x64
	muls r0, r1, r0
	strh r0, [r6]
	movs r2, #0xe
	ldrsh r0, [r6, r2]
	subs r0, #0x50
	muls r0, r1, r0
	strh r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #0x14]
	b _080932AE
_08093222:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	bgt _080932A0
	cmp r0, #0x19
	bne _08093238
	ldr r0, _08093234 @ =0x0860AC18
	b _0809324A
	.align 2, 0
_08093234: .4byte 0x0860AC18
_08093238:
	cmp r0, #0x32
	bne _08093244
	ldr r0, _08093240 @ =0x0860AC28
	b _0809324A
	.align 2, 0
_08093240: .4byte 0x0860AC28
_08093244:
	cmp r0, #0x46
	bne _0809324C
	ldr r0, _0809329C @ =0x0860AC38
_0809324A:
	str r0, [r6, #0x1c]
_0809324C:
	movs r0, #4
	ldrsh r4, [r6, r0]
	rsbs r4, r4, #0
	adds r4, #0x64
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	adds r0, #0x78
	strh r0, [r6, #0xc]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r4, #0
	bl __divsi3
	adds r1, r0, #0
	adds r1, #0x50
	strh r1, [r6, #0xe]
	adds r5, #0x80
	lsls r5, r5, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r5, r0
	bhi _08093290
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa8
	bgt _08093290
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080932AE
_08093290:
	movs r0, #0
	strb r0, [r6, #0x10]
	ldrb r1, [r6, #0x18]
	subs r0, #2
	b _080932AA
	.align 2, 0
_0809329C: .4byte 0x0860AC38
_080932A0:
	movs r0, #0
	strb r0, [r6, #0x10]
	ldrb r1, [r6, #0x18]
	movs r0, #2
	rsbs r0, r0, #0
_080932AA:
	ands r0, r1
	strb r0, [r6, #0x18]
_080932AE:
	ldrh r0, [r6, #0xa]
	adds r0, #1
	strh r0, [r6, #0xa]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessTimeAndDistanceOam
IntroProcessTimeAndDistanceOam: @ 0x080932BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne _080932D6
	ldrb r5, [r4, #0x11]
	cmp r5, #1
	bne _080932D6
	movs r0, #0xf7
	lsls r0, r0, #1
	bl SoundPlay
	strb r5, [r4, #0x14]
_080932D6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start IntroProcessAsteroidsPopUp
IntroProcessAsteroidsPopUp: @ 0x080932DC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne _080932F4
	ldrb r5, [r4, #0x11]
	cmp r5, #1
	bne _080932F4
	ldr r0, _080932FC @ =0x000001EF
	bl SoundPlay
	strb r5, [r4, #0x14]
_080932F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080932FC: .4byte 0x000001EF

	thumb_func_start unk_93300
unk_93300: @ 0x08093300
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _0809332C
	ldrh r0, [r2, #0xa]
	adds r0, #1
	strh r0, [r2, #0xa]
	ldrh r1, [r2, #0xa]
	movs r3, #8
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _0809332C
	ldrb r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0x18]
	movs r0, #1
	strb r0, [r2, #0x14]
	ldr r0, _08093330 @ =0x000001F1
	bl SoundPlay
_0809332C:
	pop {r0}
	bx r0
	.align 2, 0
_08093330: .4byte 0x000001F1

	thumb_func_start unk_93334
unk_93334: @ 0x08093334
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x10]
	ldr r1, _08093374 @ =0x00FFFF00
	ands r0, r1
	ldr r1, _08093378 @ =0x00010100
	cmp r0, r1
	bne _0809334C
	movs r0, #0xf8
	lsls r0, r0, #1
	bl SoundPlay
_0809334C:
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #3
	ldr r1, [r4, #0x1c]
	adds r1, r1, r0
	ldrb r0, [r1, #4]
	ldrb r2, [r4, #0x12]
	cmp r0, r2
	bne _0809336E
	ldrb r1, [r1, #0xc]
	cmp r1, #0
	bne _0809336E
	strb r1, [r4, #0x10]
	ldrb r1, [r4, #0x18]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #0x18]
_0809336E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093374: .4byte 0x00FFFF00
_08093378: .4byte 0x00010100

	thumb_func_start IntroOamProcessBigChangingNumber
IntroOamProcessBigChangingNumber: @ 0x0809337C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _080933A2
	ldrh r0, [r2, #0xa]
	adds r0, #1
	strh r0, [r2, #0xa]
	ldrh r1, [r2, #0xa]
	movs r3, #8
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _080933A2
	ldrb r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0x18]
	movs r0, #1
	strb r0, [r2, #0x14]
_080933A2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start TitleIntroSetupOam
TitleIntroSetupOam: @ 0x080933A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	lsls r3, r3, #0x18
	cmp r3, #0
	bne _08093410
	movs r2, #0
	ldr r0, _0809340C @ =gNonGameplayRam
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #0
	beq _080933FE
	mov r4, r8
_080933DE:
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0x13
	bgt _08093450
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080933DE
_080933FE:
	lsls r0, r2, #0x18
	asrs r1, r0, #0x18
	mov ip, r0
	cmp r1, #0x13
	ble _08093458
	b _08093450
	.align 2, 0
_0809340C: .4byte gNonGameplayRam
_08093410:
	movs r2, #0x13
	ldr r0, _08093454 @ =gNonGameplayRam
	movs r3, #0x9b
	lsls r3, r3, #3
	adds r1, r0, r3
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #0
	beq _08093448
	mov r3, r8
	movs r4, #0x8b
	lsls r4, r4, #2
_08093428:
	lsls r0, r2, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _08093450
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08093428
_08093448:
	lsls r0, r2, #0x18
	mov ip, r0
	cmp r0, #0
	bge _08093458
_08093450:
	movs r0, #0x14
	b _0809382E
	.align 2, 0
_08093454: .4byte gNonGameplayRam
_08093458:
	movs r0, #0
	str r0, [sp]
	ldr r2, _080934C0 @ =0x040000D4
	mov r3, sp
	str r3, [r2]
	mov r0, ip
	asrs r1, r0, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r4, r0, #2
	ldr r3, _080934C4 @ =0x030016A0
	adds r0, r4, r3
	str r0, [r2, #4]
	ldr r0, _080934C8 @ =0x85000009
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _080934CC @ =0xFFFFFDE4
	adds r0, r3, r1
	adds r2, r4, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r7, #0
	mov r1, sb
	strh r1, [r0]
	ldr r1, _080934D0 @ =0x0000022A
	adds r0, r2, r1
	mov r1, sl
	strh r1, [r0]
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r5, [r0]
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r6, r2, r0
	ldrb r1, [r6]
	movs r0, #1
	orrs r1, r0
	strb r1, [r6]
	cmp r5, #1
	bne _080934D8
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r6]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _080934D4 @ =unk_92d0c
	str r1, [r0]
	b _0809382A
	.align 2, 0
_080934C0: .4byte 0x040000D4
_080934C4: .4byte 0x030016A0
_080934C8: .4byte 0x85000009
_080934CC: .4byte 0xFFFFFDE4
_080934D0: .4byte 0x0000022A
_080934D4: .4byte unk_92d0c
_080934D8:
	cmp r5, #0xa
	bne _0809352C
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r2, r1
	mov r1, sb
	strh r1, [r0]
	ldr r1, _0809351C @ =0x0000021E
	adds r0, r2, r1
	mov r1, sl
	strh r1, [r0]
	ldr r0, _08093520 @ =0x00000222
	adds r1, r2, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldrb r1, [r6]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093524 @ =0x0860ACD0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08093528 @ =TitleIntroProcessDriftingShip
	str r1, [r0]
	b _0809382A
	.align 2, 0
_0809351C: .4byte 0x0000021E
_08093520: .4byte 0x00000222
_08093524: .4byte 0x0860ACD0
_08093528: .4byte TitleIntroProcessDriftingShip
_0809352C:
	cmp r5, #0xb
	bne _08093558
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r6]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093550 @ =0x0860ACD0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08093554 @ =IntroProcessBslShipSpawning
	str r1, [r0]
	b _0809382A
	.align 2, 0
_08093550: .4byte 0x0860ACD0
_08093554: .4byte IntroProcessBslShipSpawning
_08093558:
	cmp r5, #0xc
	bne _08093578
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08093570 @ =0x0000FFD8
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093574 @ =0x0860AD28
	b _080935CE
	.align 2, 0
_08093570: .4byte 0x0000FFD8
_08093574: .4byte 0x0860AD28
_08093578:
	cmp r5, #0xd
	bne _08093598
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08093590 @ =0x0000FFE2
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093594 @ =0x0860AD18
	b _080935CE
	.align 2, 0
_08093590: .4byte 0x0000FFE2
_08093594: .4byte 0x0860AD18
_08093598:
	cmp r5, #0xe
	bne _080935B8
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _080935B0 @ =0x0000FFEC
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _080935B4 @ =0x0860AD08
	b _080935CE
	.align 2, 0
_080935B0: .4byte 0x0000FFEC
_080935B4: .4byte 0x0860AD08
_080935B8:
	cmp r5, #0xf
	bne _080935E8
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _080935DC @ =0x0000FFF6
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _080935E0 @ =0x0860ACF8
_080935CE:
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _080935E4 @ =IntroProcessBslShipBack
	str r1, [r0]
	b _0809382A
	.align 2, 0
_080935DC: .4byte 0x0000FFF6
_080935E0: .4byte 0x0860ACF8
_080935E4: .4byte IntroProcessBslShipBack
_080935E8:
	cmp r5, #0x10
	bne _0809360C
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093604 @ =0x0860AC08
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08093608 @ =IntroProcessDepthParticle
	str r1, [r0]
	b _0809382A
	.align 2, 0
_08093604: .4byte 0x0860AC08
_08093608: .4byte IntroProcessDepthParticle
_0809360C:
	cmp r5, #0x13
	bne _08093630
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093628 @ =0x0865BB38
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809362C @ =IntroProcessTimeAndDistanceOam
	str r1, [r0]
	b _0809382A
	.align 2, 0
_08093628: .4byte 0x0865BB38
_0809362C: .4byte IntroProcessTimeAndDistanceOam
_08093630:
	cmp r5, #0x14
	bne _0809364C
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08093648 @ =0x0865BD00
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	b _0809366E
	.align 2, 0
_08093648: .4byte 0x0865BD00
_0809364C:
	cmp r5, #0x15
	bne _0809367C
	mov r3, ip
	asrs r1, r3, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x8e
	lsls r1, r1, #2
	add r1, r8
	adds r1, r0, r1
	ldr r2, _08093674 @ =0x0865BD48
	str r2, [r1]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
_0809366E:
	ldr r1, _08093678 @ =unk_9397c
	str r1, [r0]
	b _0809382A
	.align 2, 0
_08093674: .4byte 0x0865BD48
_08093678: .4byte unk_9397c
_0809367C:
	cmp r5, #0x16
	bne _080936AC
	mov r0, ip
	asrs r1, r0, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x8e
	lsls r1, r1, #2
	add r1, r8
	adds r1, r0, r1
	ldr r2, _080936A4 @ =0x0865BD60
	str r2, [r1]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	ldr r1, _080936A8 @ =IntroProcessAsteroidsPopUp
	str r1, [r0]
	b _0809382A
	.align 2, 0
_080936A4: .4byte 0x0865BD60
_080936A8: .4byte IntroProcessAsteroidsPopUp
_080936AC:
	cmp r5, #0x17
	bne _080936DC
	mov r3, ip
	asrs r1, r3, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x8e
	lsls r1, r1, #2
	add r1, r8
	adds r1, r0, r1
	ldr r2, _080936D4 @ =0x0865BE00
	str r2, [r1]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	adds r0, r0, r1
	ldr r1, _080936D8 @ =unk_93334
	str r1, [r0]
	b _0809382A
	.align 2, 0
_080936D4: .4byte 0x0865BE00
_080936D8: .4byte unk_93334
_080936DC:
	cmp r5, #0x18
	bne _08093710
	mov r1, ip
	asrs r0, r1, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _0809370C @ =0x0865BF10
	b _0809381C
	.align 2, 0
_0809370C: .4byte 0x0865BF10
_08093710:
	cmp r5, #0x19
	bne _08093754
	mov r1, ip
	asrs r0, r1, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _0809374C @ =0x0865C0D0
	str r1, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	add r0, r8
	adds r2, r2, r0
	ldr r0, _08093750 @ =unk_93300
	b _08093828
	.align 2, 0
_0809374C: .4byte 0x0865C0D0
_08093750: .4byte unk_93300
_08093754:
	cmp r5, #0x1a
	bne _08093788
	mov r1, ip
	asrs r0, r1, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _08093784 @ =0x0865C128
	b _0809381C
	.align 2, 0
_08093784: .4byte 0x0865C128
_08093788:
	cmp r5, #0x1b
	bne _080937BC
	mov r1, ip
	asrs r0, r1, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _080937B8 @ =0x0865C180
	b _0809381C
	.align 2, 0
_080937B8: .4byte 0x0865C180
_080937BC:
	cmp r5, #0x1c
	bne _080937F0
	mov r1, ip
	asrs r0, r1, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _080937EC @ =0x0865C1D8
	b _0809381C
	.align 2, 0
_080937EC: .4byte 0x0865C1D8
_080937F0:
	cmp r5, #0x1d
	bne _0809382A
	mov r1, ip
	asrs r0, r1, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _08093840 @ =0x0865C230
_0809381C:
	str r1, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	add r0, r8
	adds r2, r2, r0
	ldr r0, _08093844 @ =IntroOamProcessBigChangingNumber
_08093828:
	str r0, [r2]
_0809382A:
	mov r1, ip
	lsrs r0, r1, #0x18
_0809382E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08093840: .4byte 0x0865C230
_08093844: .4byte IntroOamProcessBigChangingNumber

	thumb_func_start IntroSetupBigNumberOam
IntroSetupBigNumberOam: @ 0x08093848
	push {r4, lr}
	adds r4, r3, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #0
	bl TitleIntroSetupOam
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08093880 @ =gNonGameplayRam
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	strh r4, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093880: .4byte gNonGameplayRam

	thumb_func_start unk_93884
unk_93884: @ 0x08093884
	ldr r1, _080938D0 @ =0x040000D4
	ldr r0, _080938D4 @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080938D8 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _080938DC @ =0x04000052
	ldr r0, _080938E0 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _080938E4 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080938E8 @ =0x04000054
	ldr r0, _080938EC @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #0x3c
	ldr r0, _080938F0 @ =0x0300122C
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080938F4 @ =0x0300122E
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080938F8 @ =0x03001230
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080938FC @ =0x03001232
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_080938D0: .4byte 0x040000D4
_080938D4: .4byte gOamData
_080938D8: .4byte 0x84000100
_080938DC: .4byte 0x04000052
_080938E0: .4byte gWrittenToBldalpha_Evb
_080938E4: .4byte gWrittenToBldalpha_Eva
_080938E8: .4byte 0x04000054
_080938EC: .4byte gWrittenToBldy
_080938F0: .4byte 0x0300122C
_080938F4: .4byte 0x0300122E
_080938F8: .4byte 0x03001230
_080938FC: .4byte 0x03001232

	thumb_func_start TitleIntroShipAlertAndDraftingVblank
TitleIntroShipAlertAndDraftingVblank: @ 0x08093900
	ldr r1, _0809394C @ =0x040000D4
	ldr r0, _08093950 @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08093954 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _08093958 @ =0x04000052
	ldr r0, _0809395C @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08093960 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08093964 @ =0x04000054
	ldr r0, _08093968 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #0x3c
	ldr r0, _0809396C @ =0x0300122C
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08093970 @ =0x0300122E
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08093974 @ =0x03001230
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08093978 @ =0x03001232
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_0809394C: .4byte 0x040000D4
_08093950: .4byte gOamData
_08093954: .4byte 0x84000100
_08093958: .4byte 0x04000052
_0809395C: .4byte gWrittenToBldalpha_Evb
_08093960: .4byte gWrittenToBldalpha_Eva
_08093964: .4byte 0x04000054
_08093968: .4byte gWrittenToBldy
_0809396C: .4byte 0x0300122C
_08093970: .4byte 0x0300122E
_08093974: .4byte 0x03001230
_08093978: .4byte 0x03001232

	thumb_func_start unk_9397c
unk_9397c: @ 0x0809397C
	bx lr
	.align 2, 0

	thumb_func_start IntroSpaceViewInit
IntroSpaceViewInit: @ 0x08093980
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r3, _08093B10 @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08093B14 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _08093B18 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08093B1C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08093B20 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _08093B24 @ =unk_99940
	bl CallbackSetVBlank
	movs r0, #0x80
	lsls r0, r0, #0x11
	bl DoSoundAction
	bl StopAllMusicAndSounds
	movs r6, #0
	str r6, [sp]
	ldr r4, _08093B28 @ =0x040000D4
	mov r0, sp
	str r0, [r4]
	ldr r0, _08093B2C @ =gNonGameplayRam
	str r0, [r4, #4]
	ldr r0, _08093B30 @ =0x85000150
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08093B34 @ =0x086101B8
	ldr r1, _08093B38 @ =0x06010000
	bl LZ77UncompVram
	ldr r0, _08093B3C @ =0x08612F48
	str r0, [r4]
	ldr r0, _08093B40 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _08093B44 @ =0x84000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08093B48 @ =0x0860BCA4
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldr r0, _08093B4C @ =0x0860B670
	ldr r5, _08093B50 @ =0x02010000
	adds r1, r5, #0
	bl LZ77UncompWram
	str r5, [r4]
	ldr r0, _08093B54 @ =0x0600E800
	str r0, [r4, #4]
	ldr r0, _08093B58 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	add r1, sp, #4
	ldr r2, _08093B5C @ =0x000001FF
	adds r0, r2, #0
	strh r0, [r1]
	str r1, [r4]
	ldr r0, _08093B60 @ =0x0600F000
	str r0, [r4, #4]
	ldr r0, _08093B64 @ =0x81000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08093B68 @ =0x0860B148
	ldr r1, _08093B6C @ =0x0600F800
	bl LZ77UncompVram
	ldr r0, _08093B70 @ =0x08612E48
	str r0, [r4]
	ldr r0, _08093B74 @ =0x05000100
	str r0, [r4, #4]
	ldr r0, _08093B78 @ =0x84000040
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	strh r6, [r0]
	ldr r0, _08093B7C @ =0x08598898
	ldr r1, _08093B80 @ =0x0600E000
	bl LZ77UncompVram
	ldr r0, _08093B84 @ =0x04000010
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	ldr r0, _08093B88 @ =gBg1XPosition
	strh r6, [r0]
	ldr r0, _08093B8C @ =gBg1YPosition
	strh r6, [r0]
	ldr r0, _08093B90 @ =0x0300122C
	strh r6, [r0]
	ldr r0, _08093B94 @ =0x0300122E
	strh r6, [r0]
	ldr r0, _08093B98 @ =0x03001230
	strh r6, [r0]
	ldr r0, _08093B9C @ =0x03001232
	strh r6, [r0]
	ldr r1, _08093BA0 @ =0x04000008
	ldr r2, _08093BA4 @ =0x00001C08
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r2, _08093BA8 @ =0x00005D02
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08093BAC @ =0x00001F03
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl IntroSpaceViewSetupOam
	movs r1, #0xf0
	rsbs r1, r1, #0
	movs r2, #0x6e
	rsbs r2, r2, #0
	movs r0, #2
	movs r3, #1
	bl IntroSpaceViewSetupOam
	movs r5, #0
_08093AA4:
	bl SpecialCutsceneGetRandomNumber
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl SpecialCutsceneGetRandomNumber
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #5
	adds r1, r4, #0
	movs r3, #1
	bl IntroSpaceViewSetupOam
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #9
	bls _08093AA4
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
	ldr r1, _08093B2C @ =gNonGameplayRam
	ldr r0, _08093BB0 @ =0x0863A19C
	str r0, [r1]
	movs r0, #0
	str r0, [sp]
	ldr r1, _08093B28 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08093BB4 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08093BB8 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xd4
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08093BBC @ =IntroSpaceViewVblank
	bl CallbackSetVBlank
	movs r0, #0x60
	movs r1, #0xf
	bl PlayMusic
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093B10: .4byte 0x04000208
_08093B14: .4byte 0x04000004
_08093B18: .4byte 0x0000FFEF
_08093B1C: .4byte 0x04000200
_08093B20: .4byte 0x0000FFFD
_08093B24: .4byte unk_99940
_08093B28: .4byte 0x040000D4
_08093B2C: .4byte gNonGameplayRam
_08093B30: .4byte 0x85000150
_08093B34: .4byte 0x086101B8
_08093B38: .4byte 0x06010000
_08093B3C: .4byte 0x08612F48
_08093B40: .4byte 0x05000200
_08093B44: .4byte 0x84000080
_08093B48: .4byte 0x0860BCA4
_08093B4C: .4byte 0x0860B670
_08093B50: .4byte 0x02010000
_08093B54: .4byte 0x0600E800
_08093B58: .4byte 0x84000200
_08093B5C: .4byte 0x000001FF
_08093B60: .4byte 0x0600F000
_08093B64: .4byte 0x81000400
_08093B68: .4byte 0x0860B148
_08093B6C: .4byte 0x0600F800
_08093B70: .4byte 0x08612E48
_08093B74: .4byte 0x05000100
_08093B78: .4byte 0x84000040
_08093B7C: .4byte 0x08598898
_08093B80: .4byte 0x0600E000
_08093B84: .4byte 0x04000010
_08093B88: .4byte gBg1XPosition
_08093B8C: .4byte gBg1YPosition
_08093B90: .4byte 0x0300122C
_08093B94: .4byte 0x0300122E
_08093B98: .4byte 0x03001230
_08093B9C: .4byte 0x03001232
_08093BA0: .4byte 0x04000008
_08093BA4: .4byte 0x00001C08
_08093BA8: .4byte 0x00005D02
_08093BAC: .4byte 0x00001F03
_08093BB0: .4byte 0x0863A19C
_08093BB4: .4byte 0x0600D000
_08093BB8: .4byte 0x85000400
_08093BBC: .4byte IntroSpaceViewVblank

	thumb_func_start IntroSpaceViewPartProcess
IntroSpaceViewPartProcess: @ 0x08093BC0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r7, #0
	ldr r2, _08093BF0 @ =gNonGameplayRam
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r4, r2, #0
	cmp r0, #7
	bls _08093BE4
	b _08093F38
_08093BE4:
	lsls r0, r0, #2
	ldr r1, _08093BF4 @ =_08093BF8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08093BF0: .4byte gNonGameplayRam
_08093BF4: .4byte _08093BF8
_08093BF8: @ jump table
	.4byte _08093C18 @ case 0
	.4byte _08093C7C @ case 1
	.4byte _08093CB8 @ case 2
	.4byte _08093CEC @ case 3
	.4byte _08093D54 @ case 4
	.4byte _08093D98 @ case 5
	.4byte _08093E5C @ case 6
	.4byte _08093F18 @ case 7
_08093C18:
	ldr r2, _08093C28 @ =gWrittenToBldy
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _08093C2C
	subs r0, #1
	strh r0, [r2]
	b _08093C3E
	.align 2, 0
_08093C28: .4byte gWrittenToBldy
_08093C2C:
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08093C3E:
	bl SpecialCutsceneGetRandomNumber
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bls _08093C4C
	b _08093F00
_08093C4C:
	ldr r0, _08093C74 @ =gNonGameplayRam
	ldr r1, _08093C78 @ =0x00000215
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bls _08093C5A
	b _08093F00
_08093C5A:
	bl SpecialCutsceneGetRandomNumber
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl SpecialCutsceneGetRandomNumber
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #5
	adds r1, r4, #0
	b _08093D40
	.align 2, 0
_08093C74: .4byte gNonGameplayRam
_08093C78: .4byte 0x00000215
_08093C7C:
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x1e
	bne _08093CA2
	movs r0, #0
	strh r0, [r1]
	movs r0, #4
	movs r1, #0x78
	movs r2, #0x4a
	movs r3, #0
	bl IntroSpaceViewSetupOam
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #2
	strb r0, [r1]
_08093CA2:
	bl SpecialCutsceneGetRandomNumber
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08093CAE
	b _08093F00
_08093CAE:
	ldr r5, _08093CB4 @ =0x00000215
	adds r0, r4, r5
	b _08093D2A
	.align 2, 0
_08093CB4: .4byte 0x00000215
_08093CB8:
	movs r0, #0x84
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r1, [r2]
	subs r0, #0x30
	cmp r1, r0
	bne _08093CD4
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x85
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
_08093CD4:
	bl SpecialCutsceneGetRandomNumber
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08093CE0
	b _08093F00
_08093CE0:
	ldr r3, _08093CE8 @ =0x00000215
	adds r0, r4, r3
	b _08093D2A
	.align 2, 0
_08093CE8: .4byte 0x00000215
_08093CEC:
	movs r5, #0x84
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrh r1, [r2]
	cmp r1, #0x1e
	bne _08093D04
	ldr r0, _08093D00 @ =0x000001E9
	bl SoundPlay
	b _08093D18
	.align 2, 0
_08093D00: .4byte 0x000001E9
_08093D04:
	ldr r0, _08093D48 @ =0x0000041A
	cmp r1, r0
	bne _08093D18
	movs r0, #0
	strh r0, [r2]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #5
	strb r0, [r1]
_08093D18:
	bl SpecialCutsceneGetRandomNumber
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08093D24
	b _08093F00
_08093D24:
	ldr r0, _08093D4C @ =gNonGameplayRam
	ldr r1, _08093D50 @ =0x00000215
	adds r0, r0, r1
_08093D2A:
	ldrb r0, [r0]
	cmp r0, #0xb
	bls _08093D32
	b _08093F00
_08093D32:
	bl SpecialCutsceneGetRandomNumber
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #5
	movs r1, #0
_08093D40:
	movs r3, #1
	bl IntroSpaceViewSetupOam
	b _08093F00
	.align 2, 0
_08093D48: .4byte 0x0000041A
_08093D4C: .4byte gNonGameplayRam
_08093D50: .4byte 0x00000215
_08093D54:
	ldr r4, _08093D84 @ =gWrittenToBldy
	ldrh r0, [r4]
	cmp r0, #0xf
	bhi _08093D94
	cmp r0, #0
	bne _08093D7A
	ldr r2, _08093D88 @ =0x080A8CDC
	ldr r0, _08093D8C @ =0x080A8D3C
	ldr r3, _08093D90 @ =0x00000F5C
	adds r0, r0, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #0xa
	bl ApplyMusicSoundFading
_08093D7A:
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4]
	b _08093F00
	.align 2, 0
_08093D84: .4byte gWrittenToBldy
_08093D88: .4byte 0x080A8CDC
_08093D8C: .4byte 0x080A8D3C
_08093D90: .4byte 0x00000F5C
_08093D94:
	movs r7, #1
	b _08093F00
_08093D98:
	movs r5, #0x84
	lsls r5, r5, #2
	adds r3, r4, r5
	ldrh r0, [r3]
	cmp r0, #5
	bhi _08093DC4
	ldr r2, _08093DBC @ =0x0879C41C
	adds r1, r0, #0
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0xc
	ldr r2, _08093DC0 @ =0x06008000
	adds r1, r1, r2
	bl LZ77UncompVram
	b _08093F00
	.align 2, 0
_08093DBC: .4byte 0x0879C41C
_08093DC0: .4byte 0x06008000
_08093DC4:
	cmp r0, #6
	bne _08093E28
	ldr r0, _08093E00 @ =0x08658BE0
	ldr r1, _08093E04 @ =0x0600E000
	bl LZ77UncompVram
	ldr r1, _08093E08 @ =0x040000D4
	ldr r0, _08093E0C @ =0x086591E4
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08093E10 @ =0x84000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08093E14 @ =gWrittenToBldalpha_Eva
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08093E18 @ =gWrittenToBldalpha_Evb
	movs r0, #0x10
	strh r0, [r2]
	ldr r0, _08093E1C @ =0x04000014
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _08093E20 @ =0x0400000A
	ldr r3, _08093E24 @ =0x00001C08
	adds r0, r3, #0
	strh r0, [r1]
	b _08093F00
	.align 2, 0
_08093E00: .4byte 0x08658BE0
_08093E04: .4byte 0x0600E000
_08093E08: .4byte 0x040000D4
_08093E0C: .4byte 0x086591E4
_08093E10: .4byte 0x84000040
_08093E14: .4byte gWrittenToBldalpha_Eva
_08093E18: .4byte gWrittenToBldalpha_Evb
_08093E1C: .4byte 0x04000014
_08093E20: .4byte 0x0400000A
_08093E24: .4byte 0x00001C08
_08093E28:
	cmp r0, #7
	bne _08093F00
	ldr r1, _08093E54 @ =0x04000050
	ldr r5, _08093E58 @ =0x00003C42
	adds r0, r5, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	strh r0, [r3]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	b _08093F00
	.align 2, 0
_08093E54: .4byte 0x04000050
_08093E58: .4byte 0x00003C42
_08093E5C:
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #4
	bne _08093F00
	movs r2, #0
	strh r2, [r1]
	ldr r6, _08093EC0 @ =gWrittenToBldalpha_Eva
	ldrh r0, [r6]
	cmp r0, #0xf
	bhi _08093EDC
	cmp r0, #0
	bne _08093EB0
	ldr r5, _08093EC4 @ =0x080A8CDC
	ldr r4, _08093EC8 @ =0x080A8D3C
	ldr r3, _08093ECC @ =0x00000F4C
	adds r0, r4, r3
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0x3c
	bl ApplyMusicSoundFading
	ldr r0, _08093ED0 @ =0x00000F54
	adds r4, r4, r0
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0x3c
	bl ApplyMusicSoundFading
	ldr r0, _08093ED4 @ =0x000001EB
	movs r1, #0x3c
	bl PlayFadingSound
_08093EB0:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	ldr r1, _08093ED8 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _08093F00
	.align 2, 0
_08093EC0: .4byte gWrittenToBldalpha_Eva
_08093EC4: .4byte 0x080A8CDC
_08093EC8: .4byte 0x080A8D3C
_08093ECC: .4byte 0x00000F4C
_08093ED0: .4byte 0x00000F54
_08093ED4: .4byte 0x000001EB
_08093ED8: .4byte gWrittenToBldalpha_Evb
_08093EDC:
	str r2, [sp]
	ldr r1, _08093F0C @ =0x040000D4
	mov r3, sp
	str r3, [r1]
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r4, r5
	str r0, [r1, #4]
	ldr r0, _08093F10 @ =0x850000B4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08093F14 @ =gWrittenToBldy
	strh r2, [r0]
_08093F00:
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
	b _08093F38
	.align 2, 0
_08093F0C: .4byte 0x040000D4
_08093F10: .4byte 0x850000B4
_08093F14: .4byte gWrittenToBldy
_08093F18:
	movs r2, #0x84
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x96
	bne _08093F38
	movs r0, #0
	strh r0, [r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #4
	strb r0, [r1]
	ldr r1, _08093F48 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
_08093F38:
	bl IntroProcessText
	adds r0, r7, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08093F48: .4byte 0x04000050

	thumb_func_start IntroFlyingViewInit
IntroFlyingViewInit: @ 0x08093F4C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	ldr r3, _0809407C @ =0x04000208
	movs r0, #0
	strh r0, [r3]
	ldr r2, _08094080 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _08094084 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08094088 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0809408C @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _08094090 @ =unk_99940
	bl CallbackSetVBlank
	movs r5, #0
	str r5, [sp]
	ldr r4, _08094094 @ =0x040000D4
	mov r0, sp
	str r0, [r4]
	ldr r1, _08094098 @ =0x030016A0
	mov r8, r1
	str r1, [r4, #4]
	ldr r0, _0809409C @ =0x850000B4
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080940A0 @ =0x086101B8
	ldr r1, _080940A4 @ =0x06010000
	bl LZ77UncompVram
	ldr r0, _080940A8 @ =0x08612F48
	str r0, [r4]
	ldr r0, _080940AC @ =0x05000200
	str r0, [r4, #4]
	ldr r6, _080940B0 @ =0x84000080
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080940B4 @ =0x08605D08
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldr r0, _080940B8 @ =0x08609220
	ldr r1, _080940BC @ =0x0600F800
	bl LZ77UncompVram
	ldr r0, _080940C0 @ =0x08598898
	ldr r1, _080940C4 @ =0x0600E000
	bl LZ77UncompVram
	ldr r0, _080940C8 @ =0x08609020
	str r0, [r4]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080940CC @ =0x08598A8C
	str r0, [r4]
	ldr r0, _080940D0 @ =0x050001E0
	str r0, [r4, #4]
	ldr r0, _080940D4 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	strh r5, [r1]
	ldr r0, _080940D8 @ =0x04000010
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	ldr r0, _080940DC @ =gBg1XPosition
	strh r5, [r0]
	ldr r0, _080940E0 @ =gBg1YPosition
	strh r5, [r0]
	ldr r0, _080940E4 @ =0x0300122C
	strh r5, [r0]
	ldr r0, _080940E8 @ =0x0300122E
	strh r5, [r0]
	ldr r0, _080940EC @ =0x03001230
	strh r5, [r0]
	ldr r0, _080940F0 @ =0x03001232
	strh r5, [r0]
	ldr r1, _080940F4 @ =0x04000008
	ldr r2, _080940F8 @ =0x00001C08
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #6
	ldr r2, _080940FC @ =0x00001F03
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0xa
	movs r1, #0x91
	movs r2, #0x8c
	movs r3, #0
	bl IntroSpaceViewSetupOam
	movs r0, #0xb
	movs r1, #0x8c
	movs r2, #0x50
	movs r3, #0
	bl IntroSpaceViewSetupOam
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
	ldr r0, _08094100 @ =0xFFFFFDE4
	add r8, r0
	ldr r0, _08094104 @ =0x0863A19C
	mov r1, r8
	str r0, [r1]
	str r5, [sp]
	mov r2, sp
	str r2, [r4]
	ldr r0, _08094108 @ =0x0600D000
	str r0, [r4, #4]
	ldr r0, _0809410C @ =0x85000400
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xc8
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08094110 @ =IntroSpaceViewVblank
	bl CallbackSetVBlank
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809407C: .4byte 0x04000208
_08094080: .4byte 0x04000004
_08094084: .4byte 0x0000FFEF
_08094088: .4byte 0x04000200
_0809408C: .4byte 0x0000FFFD
_08094090: .4byte unk_99940
_08094094: .4byte 0x040000D4
_08094098: .4byte 0x030016A0
_0809409C: .4byte 0x850000B4
_080940A0: .4byte 0x086101B8
_080940A4: .4byte 0x06010000
_080940A8: .4byte 0x08612F48
_080940AC: .4byte 0x05000200
_080940B0: .4byte 0x84000080
_080940B4: .4byte 0x08605D08
_080940B8: .4byte 0x08609220
_080940BC: .4byte 0x0600F800
_080940C0: .4byte 0x08598898
_080940C4: .4byte 0x0600E000
_080940C8: .4byte 0x08609020
_080940CC: .4byte 0x08598A8C
_080940D0: .4byte 0x050001E0
_080940D4: .4byte 0x84000008
_080940D8: .4byte 0x04000010
_080940DC: .4byte gBg1XPosition
_080940E0: .4byte gBg1YPosition
_080940E4: .4byte 0x0300122C
_080940E8: .4byte 0x0300122E
_080940EC: .4byte 0x03001230
_080940F0: .4byte 0x03001232
_080940F4: .4byte 0x04000008
_080940F8: .4byte 0x00001C08
_080940FC: .4byte 0x00001F03
_08094100: .4byte 0xFFFFFDE4
_08094104: .4byte 0x0863A19C
_08094108: .4byte 0x0600D000
_0809410C: .4byte 0x85000400
_08094110: .4byte IntroSpaceViewVblank

	thumb_func_start IntroFlyingViewProcess
IntroFlyingViewProcess: @ 0x08094114
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _0809413C @ =gNonGameplayRam
	movs r0, #0x84
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #1
	beq _0809417C
	cmp r0, #1
	bgt _08094140
	cmp r0, #0
	beq _08094146
	b _080941F6
	.align 2, 0
_0809413C: .4byte gNonGameplayRam
_08094140:
	cmp r0, #2
	beq _080941D8
	b _080941F6
_08094146:
	ldr r4, _0809416C @ =gWrittenToBldy
	ldrh r0, [r4]
	cmp r0, #0
	beq _08094174
	cmp r0, #0x10
	bne _08094164
	movs r0, #0xf6
	lsls r0, r0, #1
	movs r1, #0
	bl PlayFadingSound
	ldr r0, _08094170 @ =0x000001ED
	movs r1, #0
	bl PlayFadingSound
_08094164:
	ldrh r0, [r4]
	subs r0, #2
	strh r0, [r4]
	b _080941C6
	.align 2, 0
_0809416C: .4byte gWrittenToBldy
_08094170: .4byte 0x000001ED
_08094174:
	strh r5, [r1]
	movs r0, #1
	strb r0, [r2]
	b _080941C6
_0809417C:
	bl SpecialCutsceneGetRandomNumber
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080941AE
	ldr r1, _080941D0 @ =0x00000215
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	bhi _080941AE
	bl SpecialCutsceneGetRandomNumber
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl SpecialCutsceneGetRandomNumber
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x10
	adds r1, r4, #0
	movs r3, #0
	bl IntroSpaceViewSetupOam
_080941AE:
	ldr r0, _080941D4 @ =gNonGameplayRam
	movs r1, #0x84
	lsls r1, r1, #2
	adds r2, r0, r1
	ldrh r1, [r2]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080941C6
	movs r0, #0
	strh r0, [r2]
	movs r5, #1
_080941C6:
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
	b _080941F6
	.align 2, 0
_080941D0: .4byte 0x00000215
_080941D4: .4byte gNonGameplayRam
_080941D8:
	ldr r1, _080941E8 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _080941EC
	adds r0, #1
	strh r0, [r1]
	b _080941EE
	.align 2, 0
_080941E8: .4byte gWrittenToBldy
_080941EC:
	movs r5, #1
_080941EE:
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
_080941F6:
	bl IntroProcessText
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start IntroSpaceView
IntroSpaceView: @ 0x08094204
	push {r4, lr}
	movs r4, #0
	ldr r0, _08094220 @ =gNonGameplayRam
	ldrh r1, [r0, #8]
	adds r2, r0, #0
	cmp r1, #7
	bls _08094214
	b _0809431E
_08094214:
	lsls r0, r1, #2
	ldr r1, _08094224 @ =_08094228
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08094220: .4byte gNonGameplayRam
_08094224: .4byte _08094228
_08094228: @ jump table
	.4byte _08094248 @ case 0
	.4byte _08094258 @ case 1
	.4byte _08094274 @ case 2
	.4byte _0809429C @ case 3
	.4byte _080942BC @ case 4
	.4byte _080942CC @ case 5
	.4byte _080942D2 @ case 6
	.4byte _080942FC @ case 7
_08094248:
	bl IntroSpaceViewInit
	ldr r1, _08094254 @ =gNonGameplayRam
	movs r0, #1
	strh r0, [r1, #8]
	b _0809431E
	.align 2, 0
_08094254: .4byte gNonGameplayRam
_08094258:
	bl SpecialCutsceneFadeIn
	ldr r0, _0809426C @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809431E
	ldr r1, _08094270 @ =gNonGameplayRam
	movs r0, #2
	strh r0, [r1, #8]
	b _0809431E
	.align 2, 0
_0809426C: .4byte gWrittenToBldy
_08094270: .4byte gNonGameplayRam
_08094274:
	bl IntroSpaceViewPartProcess
	cmp r0, #0
	beq _0809431E
	ldr r1, _08094294 @ =gNonGameplayRam
	movs r2, #0x85
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08094298 @ =0x00000213
	adds r0, r1, r3
	strb r2, [r0]
	movs r0, #3
	strh r0, [r1, #8]
	b _0809431E
	.align 2, 0
_08094294: .4byte gNonGameplayRam
_08094298: .4byte 0x00000213
_0809429C:
	ldr r1, _080942AC @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _080942B0
	adds r0, #1
	strh r0, [r1]
	b _080942B4
	.align 2, 0
_080942AC: .4byte gWrittenToBldy
_080942B0:
	movs r0, #4
	strh r0, [r2, #8]
_080942B4:
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
_080942BC:
	bl IntroFlyingViewInit
	ldr r1, _080942C8 @ =gNonGameplayRam
	movs r0, #6
	strh r0, [r1, #8]
	b _0809431E
	.align 2, 0
_080942C8: .4byte gNonGameplayRam
_080942CC:
	movs r0, #6
	strh r0, [r2, #8]
	b _0809431E
_080942D2:
	bl IntroFlyingViewProcess
	cmp r0, #0
	beq _0809431E
	ldr r2, _080942F4 @ =gNonGameplayRam
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	ldr r3, _080942F8 @ =0x00000213
	adds r1, r2, r3
	strb r0, [r1]
	strh r0, [r2, #8]
	movs r4, #1
	b _0809431E
	.align 2, 0
_080942F4: .4byte gNonGameplayRam
_080942F8: .4byte 0x00000213
_080942FC:
	ldr r1, _0809430C @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _08094310
	adds r0, #1
	strh r0, [r1]
	b _08094316
	.align 2, 0
_0809430C: .4byte gWrittenToBldy
_08094310:
	movs r0, #0
	strh r0, [r2, #8]
	movs r4, #1
_08094316:
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
_0809431E:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start IntroProcessSpaceViewScrolling
IntroProcessSpaceViewScrolling: @ 0x08094328
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x12]
	adds r0, #1
	strb r0, [r1, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bne _08094346
	movs r0, #0
	strb r0, [r1, #0x12]
	ldr r1, _0809434C @ =0x03001230
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_08094346:
	pop {r0}
	bx r0
	.align 2, 0
_0809434C: .4byte 0x03001230

	thumb_func_start IntroProcessBslShipSideways
IntroProcessBslShipSideways: @ 0x08094350
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r1, [r5, #0xc]
	movs r6, #0
	strh r1, [r5, #4]
	ldrb r0, [r5, #0x14]
	cmp r0, #0
	bne _08094380
	strh r1, [r5]
	ldrh r0, [r5, #0xe]
	strh r0, [r5, #2]
	ldr r0, _0809437C @ =gNonGameplayRam
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08094376
	b _080944D6
_08094376:
	movs r0, #1
	b _080944D4
	.align 2, 0
_0809437C: .4byte gNonGameplayRam
_08094380:
	cmp r0, #1
	bne _080943E2
	ldrh r0, [r5, #0xa]
	adds r0, #1
	strh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	movs r1, #0xc3
	lsls r1, r1, #0x12
	cmp r0, r1
	bne _080943A2
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #3
	movs r2, #0x6e
	movs r3, #0
	bl IntroSpaceViewSetupOam
_080943A2:
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0x3c
	subs r1, r1, r0
	ldrh r0, [r5, #0xa]
	lsls r0, r0, #1
	muls r0, r1, r0
	asrs r0, r0, #0xb
	ldrh r3, [r5]
	adds r2, r0, r3
	strh r2, [r5, #0xc]
	movs r4, #2
	ldrsh r0, [r5, r4]
	movs r1, #0xa
	subs r1, r1, r0
	ldrh r0, [r5, #0xa]
	lsls r0, r0, #1
	muls r0, r1, r0
	asrs r0, r0, #0xb
	ldrh r7, [r5, #2]
	adds r1, r0, r7
	strh r1, [r5, #0xe]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1d
	bgt _080943D8
	b _080944D6
_080943D8:
	strh r6, [r5, #0xa]
	strh r2, [r5]
	strh r1, [r5, #2]
	movs r0, #2
	b _080944D4
_080943E2:
	cmp r0, #2
	bne _08094408
	ldrh r0, [r5, #0xa]
	adds r0, #1
	strh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080944D6
	strh r6, [r5, #0xa]
	movs r0, #4
	strh r0, [r5, #2]
	strh r1, [r5, #4]
	ldrh r0, [r5, #0xe]
	strh r0, [r5, #8]
	movs r0, #0
	strb r0, [r5, #0x13]
	movs r0, #3
	b _080944D4
_08094408:
	cmp r0, #3
	bne _08094480
	movs r0, #0
	ldrsh r3, [r5, r0]
	ldr r2, _08094478 @ =0x080A4FA4
	ldrb r1, [r5, #0x13]
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r4, r3, #0
	muls r4, r0, r4
	movs r7, #2
	ldrsh r3, [r5, r7]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r7, #0
	ldrsh r0, [r1, r7]
	muls r3, r0, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	adds r2, #0x80
	movs r4, #0
	ldrsh r0, [r2, r4]
	muls r0, r3, r0
	adds r1, r1, r0
	ldrh r0, [r5, #0xa]
	lsrs r0, r0, #2
	ldrh r7, [r5]
	adds r0, r0, r7
	strh r0, [r5, #0xc]
	asrs r1, r1, #0x10
	ldrh r0, [r5, #8]
	adds r1, r1, r0
	strh r1, [r5, #0xe]
	ldrb r0, [r5, #0x13]
	adds r0, #1
	strb r0, [r5, #0x13]
	ldrh r0, [r5, #0xa]
	adds r0, #1
	strh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x3c
	beq _080944D6
	ldr r0, _0809447C @ =0x00007530
	cmp r1, r0
	bne _080944D6
	strh r6, [r5, #0xa]
	movs r0, #4
	b _080944D4
	.align 2, 0
_08094478: .4byte 0x080A4FA4
_0809447C: .4byte 0x00007530
_08094480:
	cmp r0, #4
	bne _08094490
	movs r0, #5
	strb r0, [r5, #0x14]
	strh r1, [r5]
	ldrh r0, [r5, #0xe]
	strh r0, [r5, #2]
	b _080944D6
_08094490:
	cmp r0, #5
	bne _080944D6
	ldrh r0, [r5, #0xa]
	adds r0, #1
	strh r0, [r5, #0xa]
	movs r2, #0
	ldrsh r1, [r5, r2]
	movs r0, #0x82
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r1, [r5, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #0xa
	ldrh r3, [r5]
	adds r2, r0, r3
	strh r2, [r5, #0xc]
	movs r4, #2
	ldrsh r1, [r5, r4]
	movs r0, #0x64
	subs r0, r0, r1
	ldrh r1, [r5, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #0xa
	ldrh r7, [r5, #2]
	adds r3, r0, r7
	strh r3, [r5, #0xe]
	lsls r1, r2, #0x10
	ldr r0, _08094544 @ =0x02070000
	cmp r1, r0
	ble _080944D6
	strh r6, [r5, #0xa]
	strh r2, [r5]
	strh r3, [r5, #2]
	movs r0, #6
_080944D4:
	strb r0, [r5, #0x14]
_080944D6:
	ldr r0, _08094548 @ =0x0300122C
	ldrh r2, [r5, #0xc]
	strh r2, [r0]
	ldr r1, _0809454C @ =0x0300122E
	ldrh r0, [r5, #0xe]
	strh r0, [r1]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	blt _08094584
	ldrb r0, [r5, #4]
	subs r0, r2, r0
	ldrb r2, [r5, #0x11]
	adds r1, r0, r2
	movs r4, #0
	strb r1, [r5, #0x11]
	ldrb r2, [r5, #0x1a]
	lsrs r0, r2, #4
	cmp r0, #0
	bne _08094558
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08094584
	adds r0, r1, #0
	subs r0, #8
	strb r0, [r5, #0x11]
	ldrb r1, [r5, #0x12]
	lsls r1, r1, #1
	ldr r0, _08094550 @ =0x02010800
	adds r0, r1, r0
	ldr r2, _08094554 @ =0x0600F000
	adds r1, r1, r2
	movs r2, #1
	movs r3, #0x14
	bl Dma3Transfer_Unused2
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bne _08094584
	strb r4, [r5, #0x12]
	ldrb r0, [r5, #0x1a]
	movs r1, #0xf
	ands r1, r0
	movs r0, #0x10
	orrs r1, r0
	strb r1, [r5, #0x1a]
	b _08094584
	.align 2, 0
_08094544: .4byte 0x02070000
_08094548: .4byte 0x0300122C
_0809454C: .4byte 0x0300122E
_08094550: .4byte 0x02010800
_08094554: .4byte 0x0600F000
_08094558:
	cmp r0, #1
	bne _08094584
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08094584
	adds r0, r1, #0
	subs r0, #8
	strb r0, [r5, #0x11]
	ldrb r0, [r5, #0x12]
	adds r0, #1
	strb r0, [r5, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bne _08094584
	strb r4, [r5, #0x12]
	movs r0, #0xf
	ands r0, r2
	movs r1, #0xa0
	orrs r0, r1
	strb r0, [r5, #0x1a]
_08094584:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessSamusSHipEntering
IntroProcessSamusSHipEntering: @ 0x0809458C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r4, #0
	ldrb r0, [r6, #0x14]
	cmp r0, #0
	bne _080945BC
	movs r0, #0x64
	strh r0, [r6]
	movs r0, #0x1e
	strh r0, [r6, #2]
	ldrh r0, [r6, #0xc]
	strh r0, [r6, #4]
	ldrh r0, [r6, #0xe]
	subs r0, #0x1e
	strh r0, [r6, #8]
	movs r0, #0x40
	strb r0, [r6, #0x13]
	movs r0, #1
	strb r0, [r6, #0x14]
	movs r0, #0xf5
	lsls r0, r0, #1
	bl SoundPlay
	b _08094676
_080945BC:
	cmp r0, #1
	bne _080945DE
	ldrb r1, [r6, #0x13]
	adds r1, #1
	strb r1, [r6, #0x13]
	ldrh r0, [r6, #6]
	subs r0, #2
	strh r0, [r6, #6]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x80
	bne _08094676
	movs r0, #2
	strb r0, [r6, #0x14]
	adds r0, #0xfe
	strh r0, [r6, #6]
	b _08094676
_080945DE:
	cmp r0, #2
	bne _080945FA
	strh r4, [r6]
	movs r0, #8
	strh r0, [r6, #2]
	ldrh r0, [r6, #0xc]
	strh r0, [r6, #4]
	ldrh r0, [r6, #0xe]
	strh r0, [r6, #8]
	movs r0, #0x80
	strb r0, [r6, #0x13]
	movs r0, #3
	strb r0, [r6, #0x14]
	b _08094676
_080945FA:
	cmp r0, #3
	bne _08094612
	ldrb r0, [r6, #0x13]
	adds r0, #2
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc0
	bne _08094676
	movs r0, #4
	strb r0, [r6, #0x14]
	b _08094676
_08094612:
	cmp r0, #4
	bne _08094634
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldrh r0, [r6, #0xa]
	adds r0, #1
	strh r0, [r6, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _08094676
	strh r4, [r6, #0xa]
	ldrh r0, [r6, #4]
	subs r0, #1
	strh r0, [r6, #4]
	b _08094676
_08094634:
	cmp r0, #5
	bne _0809465A
	ldrh r2, [r6, #0xc]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r1, #0
	subs r0, r0, r2
	strh r0, [r6]
	movs r1, #0x3c
	strh r1, [r6, #2]
	adds r2, r2, r0
	strh r2, [r6, #4]
	ldrh r0, [r6, #0xe]
	strh r0, [r6, #8]
	movs r0, #0x80
	strb r0, [r6, #0x13]
	movs r0, #6
	strb r0, [r6, #0x14]
	b _08094676
_0809465A:
	cmp r0, #6
	bne _08094676
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094676
	strb r4, [r6, #0x10]
	ldrb r1, [r6, #0x18]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r6, #0x18]
_08094676:
	movs r2, #0
	ldrsh r3, [r6, r2]
	ldr r2, _080946D4 @ =0x080A4FA4
	ldrb r1, [r6, #0x13]
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r5, r3, #0
	muls r5, r0, r5
	movs r0, #2
	ldrsh r3, [r6, r0]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r4, r3, #0
	muls r4, r0, r4
	adds r0, r2, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r3, [r0, r1]
	adds r1, r5, #0
	muls r1, r3, r1
	movs r0, #0
	ldrsh r2, [r2, r0]
	adds r0, r4, #0
	muls r0, r2, r0
	subs r1, r1, r0
	adds r0, r5, #0
	muls r0, r2, r0
	adds r2, r4, #0
	muls r2, r3, r2
	adds r0, r0, r2
	asrs r1, r1, #0x10
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #0xc]
	asrs r0, r0, #0x10
	ldrh r4, [r6, #8]
	adds r0, r0, r4
	strh r0, [r6, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080946D4: .4byte 0x080A4FA4

	thumb_func_start IntroProcessSplashText
IntroProcessSplashText: @ 0x080946D8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x11]
	lsls r0, r0, #3
	ldr r1, [r2, #0x1c]
	adds r1, r1, r0
	ldrb r0, [r1, #4]
	ldrb r3, [r2, #0x12]
	cmp r0, r3
	bne _080946FE
	ldrb r1, [r1, #0xc]
	cmp r1, #0
	bne _080946FE
	strb r1, [r2, #0x10]
	ldrb r1, [r2, #0x18]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #0x18]
_080946FE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessSpaceViewParticle
IntroProcessSpaceViewParticle: @ 0x08094704
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne _08094740
	bl SpecialCutsceneGetRandomNumber
	movs r1, #7
	ands r1, r0
	adds r1, #1
	strh r1, [r4, #8]
	bl SpecialCutsceneGetRandomNumber
	movs r1, #3
	ands r1, r0
	strh r1, [r4, #4]
	ldr r1, _0809473C @ =0x0879C394
	movs r2, #4
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0xc]
	strh r0, [r4]
	movs r0, #1
	strb r0, [r4, #0x14]
	b _08094792
	.align 2, 0
_0809473C: .4byte 0x0879C394
_08094740:
	cmp r0, #1
	bne _08094792
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldrh r0, [r4, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #4
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _08094792
	movs r0, #0
	strb r0, [r4, #0x13]
	ldrh r1, [r4, #4]
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmp r0, #4
	bgt _0809477A
	adds r0, r1, #1
	b _0809477C
_0809477A:
	movs r0, #0
_0809477C:
	strh r0, [r4, #4]
	ldr r1, _080947B4 @ =0x0879C394
	movs r2, #4
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	movs r0, #0
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x11]
_08094792:
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	cmp r0, #0xef
	bgt _080947A2
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	cmp r0, #0x9f
	ble _080947AE
_080947A2:
	movs r0, #0
	strb r0, [r4, #0x10]
	ldrb r1, [r4, #0x18]
	subs r0, #2
	ands r0, r1
	strb r0, [r4, #0x18]
_080947AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080947B4: .4byte 0x0879C394

	thumb_func_start IntroProcessIdleShipBackview
IntroProcessIdleShipBackview: @ 0x080947B8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _080947D2
	strh r0, [r2, #0xa]
	ldrh r0, [r2, #0xc]
	strh r0, [r2]
	ldrh r0, [r2, #0xe]
	strh r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _080947F0
_080947D2:
	cmp r0, #1
	bne _080947F0
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	ldr r1, _080947F4 @ =0x080A4FA4
	ldrb r0, [r2, #0x13]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x15
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #0xe]
_080947F0:
	pop {r0}
	bx r0
	.align 2, 0
_080947F4: .4byte 0x080A4FA4

	thumb_func_start IntroProcessBslShipSpawning_2
IntroProcessBslShipSpawning_2: @ 0x080947F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0x14]
	cmp r5, #0
	bne _08094854
	ldrh r1, [r4, #0xc]
	adds r1, #0x7a
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xe
	ldrsh r2, [r4, r0]
	movs r0, #0xc
	movs r3, #0
	bl IntroSpaceViewSetupOam
	ldrh r1, [r4, #0xc]
	adds r1, #0x32
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4, #0xe]
	adds r2, #1
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0xd
	movs r3, #0
	bl IntroSpaceViewSetupOam
	ldrh r1, [r4, #0xc]
	adds r1, #0x24
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xe
	ldrsh r2, [r4, r0]
	movs r0, #0xe
	movs r3, #0
	bl IntroSpaceViewSetupOam
	movs r0, #0xc
	ldrsh r1, [r4, r0]
	movs r0, #0xe
	ldrsh r2, [r4, r0]
	movs r0, #0xf
	movs r3, #0
	bl IntroSpaceViewSetupOam
	strb r5, [r4, #0x10]
_08094854:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessBslShipBackview
IntroProcessBslShipBackview: @ 0x0809485C
	push {r4, lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x14]
	cmp r3, #0
	bne _080948BA
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bne _0809492C
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	strb r1, [r2, #0x13]
	ldrh r0, [r2, #0xa]
	cmp r0, #4
	bne _08094886
	strh r3, [r2, #0xa]
_08094886:
	ldrh r0, [r2, #0xa]
	adds r1, r0, #0
	adds r3, r0, #0
	cmp r1, #1
	bhi _08094896
	ldrh r0, [r2, #0xe]
	adds r0, #1
	b _0809489E
_08094896:
	cmp r1, #3
	bhi _080948A0
	ldrh r0, [r2, #0xe]
	subs r0, #1
_0809489E:
	strh r0, [r2, #0xe]
_080948A0:
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080948B4
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #0x14]
	strb r1, [r2, #0x13]
_080948B4:
	adds r0, r3, #1
	strh r0, [r2, #0xa]
	b _0809492C
_080948BA:
	cmp r3, #1
	bne _080948CE
	ldrh r0, [r2, #0xc]
	movs r1, #0
	strh r0, [r2]
	ldrh r0, [r2, #0xe]
	strh r0, [r2, #2]
	strh r1, [r2, #0xa]
	movs r0, #2
	b _0809492A
_080948CE:
	cmp r3, #2
	bne _0809492C
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _080948EA
	ldrh r0, [r2, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r2, #0xa]
	strb r1, [r2, #0x13]
_080948EA:
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r0, #0xe1
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r1, [r2, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r2]
	adds r3, r0, r1
	strh r3, [r2, #0xc]
	movs r4, #4
	ldrsh r0, [r2, r4]
	movs r4, #2
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	ldrh r1, [r2, #0xa]
	muls r0, r1, r0
	asrs r0, r0, #0xb
	ldrh r1, [r2, #2]
	adds r4, r0, r1
	strh r4, [r2, #0xe]
	lsls r1, r3, #0x10
	movs r0, #0xa0
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0809492C
	movs r0, #0
	strh r0, [r2, #0xa]
	strh r3, [r2]
	strh r4, [r2, #2]
	movs r0, #3
_0809492A:
	strb r0, [r2, #0x14]
_0809492C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroProcessIdleDepthParticle
IntroProcessIdleDepthParticle: @ 0x08094934
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrh r1, [r6, #0xa]
	strh r1, [r6, #4]
	ldrb r0, [r6, #0x14]
	cmp r0, #0
	bne _0809495E
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r0, #0x78
	movs r1, #0x64
	muls r0, r1, r0
	strh r0, [r6]
	movs r2, #0xe
	ldrsh r0, [r6, r2]
	subs r0, #0x50
	muls r0, r1, r0
	strh r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #0x14]
	b _080949EA
_0809495E:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x63
	bgt _080949DC
	cmp r0, #0x19
	bne _08094974
	ldr r0, _08094970 @ =0x0860AC18
	b _08094986
	.align 2, 0
_08094970: .4byte 0x0860AC18
_08094974:
	cmp r0, #0x32
	bne _08094980
	ldr r0, _0809497C @ =0x0860AC28
	b _08094986
	.align 2, 0
_0809497C: .4byte 0x0860AC28
_08094980:
	cmp r0, #0x46
	bne _08094988
	ldr r0, _080949D8 @ =0x0860AC38
_08094986:
	str r0, [r6, #0x1c]
_08094988:
	movs r0, #4
	ldrsh r4, [r6, r0]
	rsbs r4, r4, #0
	adds r4, #0x64
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	adds r0, #0x78
	strh r0, [r6, #0xc]
	movs r2, #2
	ldrsh r0, [r6, r2]
	adds r1, r4, #0
	bl __divsi3
	adds r1, r0, #0
	adds r1, #0x50
	strh r1, [r6, #0xe]
	adds r5, #0x80
	lsls r5, r5, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r5, r0
	bhi _080949CC
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa8
	bgt _080949CC
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080949EA
_080949CC:
	movs r0, #0
	strb r0, [r6, #0x10]
	ldrb r1, [r6, #0x18]
	subs r0, #2
	b _080949E6
	.align 2, 0
_080949D8: .4byte 0x0860AC38
_080949DC:
	movs r0, #0
	strb r0, [r6, #0x10]
	ldrb r1, [r6, #0x18]
	movs r0, #2
	rsbs r0, r0, #0
_080949E6:
	ands r0, r1
	strb r0, [r6, #0x18]
_080949EA:
	ldrh r0, [r6, #0xa]
	adds r0, #1
	strh r0, [r6, #0xa]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IntroSpaceViewSetupOam
IntroSpaceViewSetupOam: @ 0x080949F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sl, r2
	lsls r3, r3, #0x18
	cmp r3, #0
	bne _08094A60
	movs r2, #0
	ldr r0, _08094A5C @ =gNonGameplayRam
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #0
	beq _08094A4E
	mov r4, r8
_08094A2E:
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0x13
	bgt _08094AA0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094A2E
_08094A4E:
	lsls r0, r2, #0x18
	asrs r1, r0, #0x18
	mov ip, r0
	cmp r1, #0x13
	ble _08094AA8
	b _08094AA0
	.align 2, 0
_08094A5C: .4byte gNonGameplayRam
_08094A60:
	movs r2, #0x13
	ldr r0, _08094AA4 @ =gNonGameplayRam
	movs r3, #0x9b
	lsls r3, r3, #3
	adds r1, r0, r3
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #0
	beq _08094A98
	mov r4, r8
	movs r3, #0x8b
	lsls r3, r3, #2
_08094A78:
	lsls r0, r2, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _08094AA0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094A78
_08094A98:
	lsls r0, r2, #0x18
	mov ip, r0
	cmp r0, #0
	bge _08094AA8
_08094AA0:
	movs r0, #0x14
	b _08094DD0
	.align 2, 0
_08094AA4: .4byte gNonGameplayRam
_08094AA8:
	movs r0, #0
	str r0, [sp]
	ldr r2, _08094B10 @ =0x040000D4
	mov r3, sp
	str r3, [r2]
	mov r0, ip
	asrs r1, r0, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r4, r0, #2
	ldr r3, _08094B14 @ =0x030016A0
	adds r0, r4, r3
	str r0, [r2, #4]
	ldr r0, _08094B18 @ =0x85000009
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _08094B1C @ =0xFFFFFDE4
	adds r0, r3, r1
	adds r2, r4, r0
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r7, #0
	mov r1, sb
	strh r1, [r0]
	ldr r1, _08094B20 @ =0x0000022A
	adds r0, r2, r1
	mov r1, sl
	strh r1, [r0]
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r6, [r0]
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r5, r2, r0
	ldrb r1, [r5]
	movs r0, #1
	orrs r1, r0
	strb r1, [r5]
	cmp r6, #1
	bne _08094B28
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r5]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094B24 @ =IntroProcessSpaceViewScrolling
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094B10: .4byte 0x040000D4
_08094B14: .4byte 0x030016A0
_08094B18: .4byte 0x85000009
_08094B1C: .4byte 0xFFFFFDE4
_08094B20: .4byte 0x0000022A
_08094B24: .4byte IntroProcessSpaceViewScrolling
_08094B28:
	cmp r6, #2
	bne _08094B44
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r5]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094B40 @ =IntroProcessBslShipSideways
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094B40: .4byte IntroProcessBslShipSideways
_08094B44:
	cmp r6, #3
	bne _08094B90
	ldr r0, _08094B80 @ =0x00000222
	adds r1, r2, r0
	subs r0, #0xa2
	strh r0, [r1]
	ldr r1, _08094B84 @ =0x00000236
	adds r2, r2, r1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r5]
	movs r1, #6
	orrs r0, r1
	strb r0, [r5]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094B88 @ =0x0860AC98
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094B8C @ =IntroProcessSamusSHipEntering
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094B80: .4byte 0x00000222
_08094B84: .4byte 0x00000236
_08094B88: .4byte 0x0860AC98
_08094B8C: .4byte IntroProcessSamusSHipEntering
_08094B90:
	cmp r6, #4
	bne _08094BB4
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094BAC @ =0x0860AF10
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094BB0 @ =IntroProcessSplashText
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094BAC: .4byte 0x0860AF10
_08094BB0: .4byte IntroProcessSplashText
_08094BB4:
	cmp r6, #5
	bne _08094BE8
	ldr r0, _08094BDC @ =0x00000236
	adds r2, r2, r0
	ldrb r0, [r2]
	movs r1, #0xc
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094BE0 @ =0x0860AC38
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094BE4 @ =IntroProcessSpaceViewParticle
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094BDC: .4byte 0x00000236
_08094BE0: .4byte 0x0860AC38
_08094BE4: .4byte IntroProcessSpaceViewParticle
_08094BE8:
	cmp r6, #0xa
	bne _08094C54
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r2, r1
	mov r1, sb
	strh r1, [r0]
	ldr r1, _08094C40 @ =0x0000021E
	adds r0, r2, r1
	mov r1, sl
	strh r1, [r0]
	ldr r0, _08094C44 @ =0x00000222
	adds r1, r2, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08094C48 @ =0x00000236
	adds r2, r2, r1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldrb r1, [r5]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r5]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094C4C @ =0x0860ACD0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094C50 @ =IntroProcessIdleShipBackview
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094C40: .4byte 0x0000021E
_08094C44: .4byte 0x00000222
_08094C48: .4byte 0x00000236
_08094C4C: .4byte 0x0860ACD0
_08094C50: .4byte IntroProcessIdleShipBackview
_08094C54:
	cmp r6, #0xb
	bne _08094C80
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r5]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094C78 @ =0x0860ACD0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094C7C @ =IntroProcessBslShipSpawning_2
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094C78: .4byte 0x0860ACD0
_08094C7C: .4byte IntroProcessBslShipSpawning_2
_08094C80:
	cmp r6, #0xc
	bne _08094CB8
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08094CAC @ =0x0000FFD8
	strh r0, [r1]
	ldr r1, _08094CB0 @ =0x00000236
	adds r2, r2, r1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094CB4 @ =0x0860AD28
	b _08094D18
	.align 2, 0
_08094CAC: .4byte 0x0000FFD8
_08094CB0: .4byte 0x00000236
_08094CB4: .4byte 0x0860AD28
_08094CB8:
	cmp r6, #0xd
	bne _08094CF0
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08094CE4 @ =0x0000FFE2
	strh r0, [r1]
	ldr r1, _08094CE8 @ =0x00000236
	adds r2, r2, r1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094CEC @ =0x0860AD18
	b _08094D18
	.align 2, 0
_08094CE4: .4byte 0x0000FFE2
_08094CE8: .4byte 0x00000236
_08094CEC: .4byte 0x0860AD18
_08094CF0:
	cmp r6, #0xe
	bne _08094D38
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r0, _08094D28 @ =0x0000FFEC
	strh r0, [r1]
	ldr r1, _08094D2C @ =0x00000236
	adds r2, r2, r1
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _08094D30 @ =0x0860AD08
_08094D18:
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _08094D34 @ =IntroProcessBslShipBackview
	str r1, [r0]
	b _08094DCC
	.align 2, 0
_08094D28: .4byte 0x0000FFEC
_08094D2C: .4byte 0x00000236
_08094D30: .4byte 0x0860AD08
_08094D34: .4byte IntroProcessBslShipBackview
_08094D38:
	cmp r6, #0xf
	bne _08094D90
	mov r3, ip
	asrs r0, r3, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r0, r8
	adds r3, r2, r0
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, _08094D80 @ =0x0000FFF6
	strh r0, [r1]
	ldr r1, _08094D84 @ =0x00000236
	adds r3, r3, r1
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _08094D88 @ =0x0860ACF8
	str r1, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	add r0, r8
	adds r2, r2, r0
	ldr r0, _08094D8C @ =IntroProcessBslShipBackview
	b _08094DCA
	.align 2, 0
_08094D80: .4byte 0x0000FFF6
_08094D84: .4byte 0x00000236
_08094D88: .4byte 0x0860ACF8
_08094D8C: .4byte IntroProcessBslShipBackview
_08094D90:
	cmp r6, #0x10
	bne _08094DCC
	mov r3, ip
	asrs r0, r3, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r0, r8
	adds r3, r2, r0
	ldr r1, _08094DE0 @ =0x00000236
	adds r3, r3, r1
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r3]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	adds r0, r2, r0
	ldr r1, _08094DE4 @ =0x0860AC08
	str r1, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	add r0, r8
	adds r2, r2, r0
	ldr r0, _08094DE8 @ =IntroProcessIdleDepthParticle
_08094DCA:
	str r0, [r2]
_08094DCC:
	mov r3, ip
	lsrs r0, r3, #0x18
_08094DD0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08094DE0: .4byte 0x00000236
_08094DE4: .4byte 0x0860AC08
_08094DE8: .4byte IntroProcessIdleDepthParticle

	thumb_func_start IntroSpaceViewVblank
IntroSpaceViewVblank: @ 0x08094DEC
	ldr r1, _08094E48 @ =0x040000D4
	ldr r0, _08094E4C @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08094E50 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _08094E54 @ =0x04000052
	ldr r0, _08094E58 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08094E5C @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08094E60 @ =0x04000054
	ldr r0, _08094E64 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #0x40
	ldr r0, _08094E68 @ =gBg1XPosition
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08094E6C @ =gBg1YPosition
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08094E70 @ =0x0300122C
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08094E74 @ =0x0300122E
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08094E78 @ =0x03001230
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08094E7C @ =0x03001232
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_08094E48: .4byte 0x040000D4
_08094E4C: .4byte gOamData
_08094E50: .4byte 0x84000100
_08094E54: .4byte 0x04000052
_08094E58: .4byte gWrittenToBldalpha_Evb
_08094E5C: .4byte gWrittenToBldalpha_Eva
_08094E60: .4byte 0x04000054
_08094E64: .4byte gWrittenToBldy
_08094E68: .4byte gBg1XPosition
_08094E6C: .4byte gBg1YPosition
_08094E70: .4byte 0x0300122C
_08094E74: .4byte 0x0300122E
_08094E78: .4byte 0x03001230
_08094E7C: .4byte 0x03001232

	thumb_func_start unk_94e80
unk_94e80: @ 0x08094E80
	bx lr
	.align 2, 0

