    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start DrawCharacter
DrawCharacter: @ 0x0807913C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r4, [sp, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #8]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0
	mov r8, r0
	adds r0, r2, #0
	subs r0, #8
	lsls r0, r0, #2
	str r0, [sp, #0x14]
_08079170:
	ldr r6, _080791D4 @ =0x02035DA0
	mov r1, r8
	cmp r1, #0
	beq _0807917A
	adds r6, #0x40
_0807917A:
	ldr r2, [sp]
	lsls r1, r2, #5
	mov r3, r8
	lsls r0, r3, #0xa
	adds r3, r1, r0
	movs r1, #0x20
	ldr r4, [sp, #4]
	cmp r4, #8
	bls _0807918E
	movs r1, #0x40
_0807918E:
	mov r0, r8
	lsls r0, r0, #8
	mov sb, r0
	mov r2, r8
	adds r2, #1
	str r2, [sp, #0x18]
	cmp r1, #0
	beq _080791E8
	ldr r7, _080791D8 @ =0x08682FAC
	adds r5, r1, #0
_080791A2:
	adds r0, r3, r7
	ldrb r4, [r0]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _080791DC
	movs r2, #0xf
	ands r2, r4
	movs r1, #0xf0
	ands r1, r4
	subs r0, r2, #2
	cmp r0, #1
	bhi _080791C0
	ldr r4, [sp, #0xc]
	lsls r0, r4, #1
	adds r2, r2, r0
_080791C0:
	cmp r1, #0x20
	beq _080791C8
	cmp r1, #0x30
	bne _080791CE
_080791C8:
	ldr r4, [sp, #0xc]
	lsls r0, r4, #5
	adds r1, r1, r0
_080791CE:
	orrs r1, r2
	strb r1, [r6]
	b _080791DE
	.align 2, 0
_080791D4: .4byte 0x02035DA0
_080791D8: .4byte 0x08682FAC
_080791DC:
	strb r4, [r6]
_080791DE:
	subs r5, #1
	adds r6, #1
	adds r3, #1
	cmp r5, #0
	bne _080791A2
_080791E8:
	ldr r0, _08079290 @ =0x02035DA0
	mov sl, r0
	mov r1, r8
	cmp r1, #0
	beq _080791F6
	ldr r2, _08079294 @ =0x02035DE0
	mov sl, r2
_080791F6:
	ldr r3, [sp, #4]
	cmp r3, #8
	bls _08079216
	ldr r0, _08079298 @ =0x0879C128
	ldr r4, [sp, #0x14]
	adds r5, r4, r0
	mov r2, sl
	adds r2, #0x20
	movs r3, #7
_08079208:
	ldr r0, [r2]
	ldr r1, [r5]
	ands r0, r1
	stm r2!, {r0}
	subs r3, #1
	cmp r3, #0
	bge _08079208
_08079216:
	mov r4, sb
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _080792C4
	lsls r6, r0, #2
	ldr r1, [sp, #4]
	adds r1, r1, r0
	mov sb, r1
	mov ip, r6
	movs r0, #0x20
	subs r7, r0, r6
	mov r2, r8
	lsls r0, r2, #0xa
	ldr r3, [sp, #0x10]
	adds r2, r0, r3
	mov r5, sl
	movs r3, #7
_08079238:
	ldr r1, [r5]
	mov r0, ip
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldm r5!, {r1}
	lsrs r1, r7
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08079238
	mov r1, sb
	cmp r1, #0x10
	ble _0807929C
	adds r5, r6, #0
	movs r0, #0x20
	subs r6, r0, r5
	lsls r0, r4, #2
	ldr r2, [sp, #0x10]
	adds r0, r0, r2
	adds r2, r0, #0
	adds r2, #0x20
	mov r4, sl
	adds r4, #0x20
	movs r3, #7
_08079272:
	ldr r1, [r4]
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldm r4!, {r1}
	lsrs r1, r6
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08079272
	b _080792EC
	.align 2, 0
_08079290: .4byte 0x02035DA0
_08079294: .4byte 0x02035DE0
_08079298: .4byte 0x0879C128
_0807929C:
	ldr r3, [sp, #4]
	cmp r3, #8
	bls _080792EC
	lsls r0, r4, #2
	ldr r4, [sp, #0x10]
	adds r0, r0, r4
	adds r2, r0, #0
	adds r2, #0x20
	mov r5, sl
	adds r5, #0x20
	movs r3, #7
_080792B2:
	ldm r5!, {r1}
	lsls r1, r6
	ldr r0, [r2]
	orrs r0, r1
	stm r2!, {r0}
	subs r3, #1
	cmp r3, #0
	bge _080792B2
	b _080792EC
_080792C4:
	movs r1, #8
	ldr r0, [sp, #4]
	cmp r0, #8
	bls _080792CE
	movs r1, #0x10
_080792CE:
	cmp r1, #0
	beq _080792EC
	mov r2, r8
	lsls r0, r2, #0xa
	ldr r3, [sp, #0x10]
	adds r2, r0, r3
	mov r5, sl
	adds r3, r1, #0
_080792DE:
	ldr r0, [r2]
	ldm r5!, {r1}
	orrs r0, r1
	stm r2!, {r0}
	subs r3, #1
	cmp r3, #0
	bne _080792DE
_080792EC:
	ldr r4, [sp, #0x18]
	mov r8, r4
	cmp r4, #1
	bgt _080792F6
	b _08079170
_080792F6:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DrawCharacterPauseDebug
DrawCharacterPauseDebug: @ 0x08079308
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r1, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	cmp r6, #0
	beq _080793B4
	movs r3, #0
	lsls r0, r0, #5
	mov sb, r0
	ldr r0, _08079354 @ =0x08682FAC
	mov sl, r0
	ldr r1, _08079358 @ =0x040000D4
	mov r8, r1
_08079330:
	lsls r0, r3, #0xa
	mov r1, sb
	adds r2, r1, r0
	ldr r5, _0807935C @ =0x02035DA0
	adds r7, r0, #0
	adds r3, #1
	mov ip, r3
	movs r4, #0x1f
	add r2, sl
_08079342:
	ldrb r0, [r2]
	movs r1, #0xf
	ands r1, r0
	subs r0, r1, #2
	cmp r0, #1
	bhi _08079360
	lsls r0, r6, #1
	adds r1, r1, r0
	b _08079366
	.align 2, 0
_08079354: .4byte 0x08682FAC
_08079358: .4byte 0x040000D4
_0807935C: .4byte 0x02035DA0
_08079360:
	cmp r1, #0
	bne _08079366
	movs r1, #0xf
_08079366:
	ldrb r0, [r2]
	movs r3, #0xf0
	ands r3, r0
	cmp r3, #0x20
	beq _08079374
	cmp r3, #0x30
	bne _0807937A
_08079374:
	lsls r0, r6, #5
	adds r3, r3, r0
	b _08079380
_0807937A:
	cmp r3, #0
	bne _08079380
	movs r3, #0xf0
_08079380:
	orrs r3, r1
	strb r3, [r5]
	subs r4, #1
	adds r5, #1
	adds r2, #1
	cmp r4, #0
	bge _08079342
	ldr r0, _080793AC @ =0x02035DA0
	mov r1, r8
	str r0, [r1]
	ldr r1, [sp]
	adds r0, r1, r7
	mov r1, r8
	str r0, [r1, #4]
	ldr r0, _080793B0 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r3, ip
	cmp r3, #1
	ble _08079330
	b _08079416
	.align 2, 0
_080793AC: .4byte 0x02035DA0
_080793B0: .4byte 0x84000008
_080793B4:
	movs r3, #0
	lsls r0, r0, #5
	str r0, [sp, #4]
	ldr r0, _08079428 @ =0x08682FAC
	mov sl, r0
	ldr r6, _0807942C @ =0x040000D4
	movs r1, #0xf
	mov sb, r1
	movs r0, #0xf0
	mov r8, r0
_080793C8:
	lsls r0, r3, #0xa
	ldr r1, [sp, #4]
	adds r2, r1, r0
	ldr r5, _08079430 @ =0x02035DA0
	adds r7, r0, #0
	adds r3, #1
	mov ip, r3
	movs r4, #0x1f
_080793D8:
	mov r1, sl
	adds r0, r2, r1
	ldrb r0, [r0]
	mov r1, sb
	ands r1, r0
	cmp r1, #0
	bne _080793E8
	movs r1, #0xf
_080793E8:
	mov r3, r8
	ands r3, r0
	cmp r3, #0
	bne _080793F2
	movs r3, #0xf0
_080793F2:
	orrs r3, r1
	strb r3, [r5]
	subs r4, #1
	adds r5, #1
	adds r2, #1
	cmp r4, #0
	bge _080793D8
	ldr r0, _08079430 @ =0x02035DA0
	str r0, [r6]
	ldr r1, [sp]
	adds r0, r1, r7
	str r0, [r6, #4]
	ldr r0, _08079434 @ =0x84000008
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	mov r3, ip
	cmp r3, #1
	ble _080793C8
_08079416:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08079428: .4byte 0x08682FAC
_0807942C: .4byte 0x040000D4
_08079430: .4byte 0x02035DA0
_08079434: .4byte 0x84000008

	thumb_func_start DrawCharacterForMessage
DrawCharacterForMessage: @ 0x08079438
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r4, [sp, #0x48]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #8]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0xc]
	str r1, [sp, #0x14]
	movs r0, #0
	mov ip, r0
	movs r0, #8
	subs r0, r0, r3
	lsls r0, r0, #2
	str r0, [sp, #0x18]
_0807946C:
	ldr r6, _080794C8 @ =0x02035DA0
	mov r1, ip
	cmp r1, #0
	beq _08079476
	adds r6, #0x40
_08079476:
	ldr r2, [sp]
	lsls r1, r2, #5
	mov r3, ip
	lsls r0, r3, #0xa
	adds r3, r1, r0
	movs r1, #0x20
	ldr r4, [sp, #4]
	cmp r4, #8
	bls _0807948A
	movs r1, #0x40
_0807948A:
	mov r7, ip
	lsls r7, r7, #8
	mov sb, r7
	mov r0, ip
	adds r0, #1
	str r0, [sp, #0x20]
	cmp r1, #0
	beq _08079508
	movs r7, #0xf
	movs r2, #0xf0
	mov r8, r2
	ldr r4, _080794CC @ =0x08682FAC
	mov sl, r4
	adds r5, r1, #0
_080794A6:
	mov r1, sl
	adds r0, r3, r1
	ldrb r4, [r0]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	beq _080794E6
	adds r2, r4, #0
	ands r2, r7
	mov r1, r8
	ands r1, r4
	subs r0, r2, #2
	cmp r0, #1
	bhi _080794D0
	ldr r4, [sp, #0xc]
	lsls r0, r4, #1
	adds r2, r2, r0
	b _080794D6
	.align 2, 0
_080794C8: .4byte 0x02035DA0
_080794CC: .4byte 0x08682FAC
_080794D0:
	cmp r2, #0
	bne _080794D6
	movs r2, #0xf
_080794D6:
	cmp r1, #0x20
	beq _080794DE
	cmp r1, #0x30
	bne _080794F4
_080794DE:
	ldr r4, [sp, #0xc]
	lsls r0, r4, #5
	adds r1, r1, r0
	b _080794FA
_080794E6:
	adds r2, r4, #0
	ands r2, r7
	mov r1, r8
	ands r1, r4
	cmp r2, #0
	bne _080794F4
	movs r2, #0xf
_080794F4:
	cmp r1, #0
	bne _080794FA
	movs r1, #0xf0
_080794FA:
	orrs r1, r2
	strb r1, [r6]
	subs r5, #1
	adds r6, #1
	adds r3, #1
	cmp r5, #0
	bne _080794A6
_08079508:
	ldr r7, _080795C8 @ =0x02035DA0
	str r7, [sp, #0x10]
	mov r0, ip
	cmp r0, #0
	beq _08079516
	ldr r1, _080795CC @ =0x02035DE0
	str r1, [sp, #0x10]
_08079516:
	mov r4, sb
	ldr r2, [sp, #8]
	cmp r2, #0
	beq _08079610
	lsls r6, r2, #2
	ldr r3, [sp, #4]
	adds r3, r3, r2
	str r3, [sp, #0x1c]
	mov sl, r6
	ldr r7, _080795D0 @ =0x0879C128
	adds r7, r7, r6
	mov sb, r7
	movs r0, #0x20
	subs r0, r0, r6
	mov r8, r0
	ldr r0, [sp, #0x18]
	ldr r1, _080795D4 @ =0x0879C14C
	adds r0, r0, r1
	str r0, [sp, #0x24]
	mov r2, ip
	lsls r0, r2, #0xa
	ldr r3, [sp, #0x14]
	adds r2, r0, r3
	ldr r5, [sp, #0x10]
	movs r3, #7
_08079548:
	ldr r1, [r5]
	mov r7, sl
	lsls r1, r7
	mov r7, sb
	ldr r0, [r7]
	orrs r1, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldm r5!, {r1}
	mov r0, r8
	lsrs r1, r0
	ldr r7, [sp, #0x24]
	ldr r0, [r7]
	orrs r1, r0
	ldr r0, [r2, #0x20]
	ands r0, r1
	str r0, [r2, #0x20]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08079548
	ldr r0, [sp, #0x1c]
	cmp r0, #0x10
	ble _080795D8
	adds r5, r6, #0
	ldr r1, _080795D0 @ =0x0879C128
	adds r1, r1, r5
	mov r8, r1
	movs r0, #0x20
	subs r0, r0, r5
	mov sb, r0
	ldr r2, [sp, #0x18]
	ldr r3, _080795D4 @ =0x0879C14C
	adds r6, r2, r3
	lsls r0, r4, #2
	ldr r4, [sp, #0x14]
	adds r0, r0, r4
	adds r2, r0, #0
	adds r2, #0x20
	ldr r4, [sp, #0x10]
	adds r4, #0x20
	movs r3, #7
_0807959E:
	ldr r1, [r4]
	lsls r1, r5
	mov r7, r8
	ldr r0, [r7]
	orrs r1, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldm r4!, {r1}
	mov r0, sb
	lsrs r1, r0
	ldr r0, [r6]
	orrs r1, r0
	ldr r0, [r2, #0x20]
	ands r0, r1
	str r0, [r2, #0x20]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _0807959E
	b _08079638
	.align 2, 0
_080795C8: .4byte 0x02035DA0
_080795CC: .4byte 0x02035DE0
_080795D0: .4byte 0x0879C128
_080795D4: .4byte 0x0879C14C
_080795D8:
	ldr r1, [sp, #4]
	cmp r1, #8
	bls _08079638
	adds r5, r6, #0
	ldr r2, _0807960C @ =0x0879C128
	adds r7, r5, r2
	lsls r0, r4, #2
	ldr r3, [sp, #0x14]
	adds r0, r0, r3
	adds r2, r0, #0
	adds r2, #0x20
	ldr r6, [sp, #0x10]
	adds r6, #0x20
	movs r3, #7
_080795F4:
	ldm r6!, {r0}
	lsls r0, r5
	ldr r1, [r7]
	orrs r0, r1
	ldr r1, [r2]
	ands r1, r0
	stm r2!, {r1}
	subs r3, #1
	cmp r3, #0
	bge _080795F4
	b _08079638
	.align 2, 0
_0807960C: .4byte 0x0879C128
_08079610:
	movs r1, #8
	ldr r4, [sp, #4]
	cmp r4, #8
	bls _0807961A
	movs r1, #0x10
_0807961A:
	cmp r1, #0
	beq _08079638
	mov r7, ip
	lsls r0, r7, #0xa
	ldr r3, [sp, #0x14]
	adds r2, r0, r3
	ldr r5, [sp, #0x10]
	adds r3, r1, #0
_0807962A:
	ldr r0, [r2]
	ldm r5!, {r1}
	ands r0, r1
	stm r2!, {r0}
	subs r3, #1
	cmp r3, #0
	bne _0807962A
_08079638:
	ldr r4, [sp, #0x20]
	mov ip, r4
	cmp r4, #1
	bgt _08079642
	b _0807946C
_08079642:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start DrawLocationTextCharacters
DrawLocationTextCharacters: @ 0x08079654
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08079672
	movs r0, #0x80
	lsls r0, r0, #0x12
	mov sb, r0
	b _0807969C
_08079672:
	cmp r0, #2
	bne _08079730
	ldr r1, _080796D4 @ =0x02000800
	mov sb, r1
	ldr r2, [r5]
	ldrh r0, [r2]
	movs r1, #0xfe
	lsls r1, r1, #8
	cmp r0, r1
	beq _08079696
	adds r3, r1, #0
_08079688:
	adds r0, r2, #0
	adds r1, r0, #2
	adds r2, r1, #0
	ldrh r0, [r0, #2]
	cmp r0, r3
	bne _08079688
	str r1, [r5]
_08079696:
	ldr r0, [r5]
	adds r0, #2
	str r0, [r5]
_0807969C:
	movs r6, #0
	ldr r3, [r5]
	movs r2, #0xff
	lsls r2, r2, #8
	adds r7, r2, #0
	ldrh r1, [r3]
	cmp r1, r7
	beq _08079730
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r1, r0
	beq _08079730
	movs r4, #0x80
	lsls r4, r4, #8
	mov sl, r4
_080796BA:
	movs r4, #1
	ldrh r2, [r3]
	adds r1, r7, #0
	ands r1, r2
	cmp r1, sl
	bne _080796D8
	movs r0, #0xff
	mov r8, r0
	mov r1, r8
	ands r1, r2
	mov r8, r1
	b _08079712
	.align 2, 0
_080796D4: .4byte 0x02000800
_080796D8:
	movs r0, #0x83
	lsls r0, r0, #8
	cmp r1, r0
	bne _080796E8
	movs r4, #0
	mov r8, r4
	movs r6, #0xff
	ands r6, r2
_080796E8:
	cmp r4, #0
	beq _08079712
	ldrh r0, [r3]
	bl GetCharacterWidth
	mov r8, r0
	asrs r0, r6, #3
	lsls r4, r0, #5
	movs r3, #7
	ldr r0, [r5]
	ldrh r0, [r0]
	mov r2, sb
	adds r1, r2, r4
	mov r4, r8
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	ands r3, r6
	movs r4, #0
	str r4, [sp]
	bl DrawCharacterForMessage
_08079712:
	ldr r0, [r5]
	adds r2, r0, #2
	str r2, [r5]
	add r6, r8
	movs r1, #0xff
	lsls r1, r1, #8
	adds r7, r1, #0
	ldrh r1, [r0, #2]
	cmp r1, r7
	beq _08079730
	adds r3, r2, #0
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r1, r0
	bne _080796BA
_08079730:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
