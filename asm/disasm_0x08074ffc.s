    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start LoadInitialMinimap
LoadInitialMinimap: @ 0x08074FFC
	push {r4, r5, lr}
	ldr r5, _08075060 @ =gPreviousArea
	ldrb r0, [r5]
	ldr r4, _08075064 @ =0x02034000
	adds r1, r4, #0
	bl GetMinimapData
	ldr r1, _08075068 @ =0x040000D4
	str r4, [r1]
	ldr r0, _0807506C @ =0x02034800
	str r0, [r1, #4]
	ldr r0, _08075070 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r5]
	bl MinimapSetVisitedTilesAndCollectedItems
	ldr r1, _08075074 @ =gSamusData
	ldrh r0, [r1, #0x16]
	subs r0, #0x80
	asrs r0, r0, #6
	ldrh r4, [r1, #0x18]
	subs r4, #0x80
	asrs r4, r4, #6
	movs r1, #0xf
	bl __divsi3
	adds r5, r0, #0
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	ldr r3, _08075078 @ =0x03000031
	ldr r1, _0807507C @ =0x0879B8BC
	ldr r2, [r1]
	adds r1, r2, #0
	adds r1, #0x35
	ldrb r1, [r1]
	adds r1, r1, r5
	strb r1, [r3]
	ldr r3, _08075080 @ =0x03000032
	adds r2, #0x36
	ldrb r1, [r2]
	adds r1, r1, r0
	strb r1, [r3]
	bl MinimapSetTileAsExplored
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08075060: .4byte gPreviousArea
_08075064: .4byte 0x02034000
_08075068: .4byte 0x040000D4
_0807506C: .4byte 0x02034800
_08075070: .4byte 0x80000400
_08075074: .4byte gSamusData
_08075078: .4byte 0x03000031
_0807507C: .4byte 0x0879B8BC
_08075080: .4byte 0x03000032

	thumb_func_start MinimapUpdate
MinimapUpdate: @ 0x08075084
	push {lr}
	bl MinimapCheckForUnexploredTile
	ldr r0, _080750A4 @ =gMinimapUpdateFlag
	ldrb r0, [r0]
	cmp r0, #3
	bne _0807509A
	bl MinimapSetTileAsExplored
	bl MinimapUpdateForExploredTiles
_0807509A:
	bl MinimapDraw
	pop {r0}
	bx r0
	.align 2, 0
_080750A4: .4byte gMinimapUpdateFlag

	thumb_func_start MinimapSetTileAsExplored
MinimapSetTileAsExplored: @ 0x080750A8
	push {lr}
	ldr r1, _080750D8 @ =gCurrentArea
	ldrb r0, [r1]
	cmp r0, #6
	bhi _080750D4
	adds r2, r0, #0
	ldr r0, _080750DC @ =0x03000032
	lsls r2, r2, #5
	ldrb r0, [r0]
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _080750E0 @ =0x02037C00
	adds r2, r2, r0
	ldr r1, _080750E4 @ =0x0879BDDC
	ldr r0, _080750E8 @ =0x03000031
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r2]
_080750D4:
	pop {r0}
	bx r0
	.align 2, 0
_080750D8: .4byte gCurrentArea
_080750DC: .4byte 0x03000032
_080750E0: .4byte 0x02037C00
_080750E4: .4byte 0x0879BDDC
_080750E8: .4byte 0x03000031

	thumb_func_start MinimapCheckForUnexploredTile
MinimapCheckForUnexploredTile: @ 0x080750EC
	push {r4, r5, r6, lr}
	ldr r0, _0807511C @ =gMinimapUpdateFlag
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _080751AC
	ldr r1, _08075120 @ =gSamusData
	ldrh r3, [r1, #0x16]
	adds r0, r3, #0
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrh r0, [r1, #0x18]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r4
	cmp r0, #0
	beq _08075124
	movs r4, #0
	b _0807513C
	.align 2, 0
_0807511C: .4byte gMinimapUpdateFlag
_08075120: .4byte gSamusData
_08075124:
	ldr r0, _0807514C @ =gBackgroundsData
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x16
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	cmp r3, r2
	blo _0807513C
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0807513C:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r5
	cmp r0, #0
	beq _08075150
	movs r5, #0
	b _0807516A
	.align 2, 0
_0807514C: .4byte gBackgroundsData
_08075150:
	ldr r0, _080751B4 @ =gBackgroundsData
	ldrh r0, [r0, #0x1e]
	lsls r0, r0, #0x16
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	ldrh r0, [r1, #0x18]
	cmp r0, r2
	blo _0807516A
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0807516A:
	lsrs r4, r4, #6
	lsrs r5, r5, #6
	adds r0, r4, #0
	movs r1, #0xf
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r2, _080751B8 @ =0x03000031
	ldrb r1, [r2]
	ldr r3, _080751BC @ =gCurrentRoomEntry
	ldrb r0, [r3, #0xe]
	adds r0, r4, r0
	cmp r1, r0
	beq _0807519A
	strb r0, [r2]
	movs r0, #3
	strb r0, [r6]
_0807519A:
	ldr r2, _080751C0 @ =0x03000032
	ldrb r1, [r2]
	ldrb r0, [r3, #0xf]
	adds r0, r5, r0
	cmp r1, r0
	beq _080751AC
	strb r0, [r2]
	movs r0, #3
	strb r0, [r6]
_080751AC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080751B4: .4byte gBackgroundsData
_080751B8: .4byte 0x03000031
_080751BC: .4byte gCurrentRoomEntry
_080751C0: .4byte 0x03000032

	thumb_func_start MinimapCheckOnTransition
MinimapCheckOnTransition: @ 0x080751C4
	push {r4, r5, lr}
	ldr r0, _0807524C @ =gCurrentArea
	ldrb r1, [r0]
	adds r2, r0, #0
	ldr r5, _08075250 @ =gPreviousArea
	cmp r1, #0
	bne _080751E2
	ldr r0, _08075254 @ =gCurrentCutscene
	ldrb r0, [r0]
	cmp r0, #0
	beq _080751E2
	cmp r0, #0xa
	bne _080751E2
	movs r0, #0x80
	strb r0, [r5]
_080751E2:
	ldrb r1, [r2]
	ldrb r0, [r5]
	cmp r0, r1
	beq _08075214
	strb r1, [r5]
	ldrb r0, [r5]
	ldr r4, _08075258 @ =0x02034000
	adds r1, r4, #0
	bl GetMinimapData
	ldr r1, _0807525C @ =0x040000D4
	str r4, [r1]
	ldr r0, _08075260 @ =0x02034800
	str r0, [r1, #4]
	ldr r0, _08075264 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r5]
	bl MinimapSetVisitedTilesAndCollectedItems
	ldr r0, _08075268 @ =0x03000031
	movs r1, #0xff
	strb r1, [r0]
	ldr r0, _0807526C @ =0x03000032
	strb r1, [r0]
_08075214:
	ldr r4, _08075270 @ =gMinimapUpdateFlag
	movs r0, #0
	strb r0, [r4]
	bl MinimapCheckForUnexploredTile
	ldrb r0, [r4]
	cmp r0, #3
	bne _0807522C
	bl MinimapSetTileAsExplored
	bl MinimapUpdateForExploredTiles
_0807522C:
	movs r0, #1
	strb r0, [r4]
	bl MinimapDraw
	movs r0, #2
	strb r0, [r4]
	bl MinimapDraw
	movs r0, #3
	strb r0, [r4]
	bl MinimapDraw
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807524C: .4byte gCurrentArea
_08075250: .4byte gPreviousArea
_08075254: .4byte gCurrentCutscene
_08075258: .4byte 0x02034000
_0807525C: .4byte 0x040000D4
_08075260: .4byte 0x02034800
_08075264: .4byte 0x80000400
_08075268: .4byte 0x03000031
_0807526C: .4byte 0x03000032
_08075270: .4byte gMinimapUpdateFlag

	thumb_func_start MinimapDraw
MinimapDraw: @ 0x08075274
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, _08075298 @ =gMinimapUpdateFlag
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0807535A
	ldr r0, _0807529C @ =0x02034000
	mov r8, r0
	ldr r0, _080752A0 @ =0x02035C00
	str r0, [sp]
	adds r0, r1, #0
	cmp r0, #3
	bne _080752A4
	movs r6, #1
	b _080752B4
	.align 2, 0
_08075298: .4byte gMinimapUpdateFlag
_0807529C: .4byte 0x02034000
_080752A0: .4byte 0x02035C00
_080752A4:
	cmp r0, #2
	bne _080752AC
	movs r6, #0
	b _080752B4
_080752AC:
	cmp r1, #1
	bne _080752B4
	movs r6, #1
	rsbs r6, r6, #0
_080752B4:
	ldrb r0, [r2]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, [sp]
	adds r0, r0, r1
	str r0, [sp]
	movs r5, #1
	rsbs r5, r5, #0
	add r4, sp, #4
_080752CA:
	ldr r0, _0807531C @ =0x03000031
	ldrb r0, [r0]
	adds r1, r0, r5
	cmp r1, #0x1f
	bls _080752D6
	movs r1, #0xff
_080752D6:
	ldr r0, _08075320 @ =0x03000032
	ldrb r0, [r0]
	adds r0, r0, r6
	cmp r0, #0x1f
	bls _080752E2
	movs r0, #0xff
_080752E2:
	cmp r0, #0xff
	beq _080752EA
	cmp r1, #0xff
	bne _080752EE
_080752EA:
	movs r1, #0x1f
	movs r0, #0x1f
_080752EE:
	lsls r0, r0, #5
	adds r0, r0, r1
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r2, #0
	adds r3, r0, #0
	ands r3, r1
	lsrs r2, r1, #0xc
	ldr r7, _08075324 @ =0x000003FF
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #5
	str r0, [sp, #4]
	cmp r3, #0
	bne _08075328
	mov r0, sp
	adds r1, r4, #0
	bl MinimapCopyTileGfx
	b _08075354
	.align 2, 0
_0807531C: .4byte 0x03000031
_08075320: .4byte 0x03000032
_08075324: .4byte 0x000003FF
_08075328:
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r3, r0
	bne _0807533A
	mov r0, sp
	adds r1, r4, #0
	bl MinimapCopyTileXFlippedGfx
	b _08075354
_0807533A:
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r3, r0
	bne _0807534C
	mov r0, sp
	adds r1, r4, #0
	bl MinimapCopyTileYFlippedGfx
	b _08075354
_0807534C:
	mov r0, sp
	adds r1, r4, #0
	bl MinimapCopyTileXYFlippedGfx
_08075354:
	adds r5, #1
	cmp r5, #1
	ble _080752CA
_0807535A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MinimapCopyTileGfx
MinimapCopyTileGfx: @ 0x08075368
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	ldr r0, _080753C0 @ =0x08561FA8
	mov r8, r0
	ldr r0, _080753C4 @ =0x085761C0
	mov ip, r0
	lsrs r2, r2, #0x14
	ldr r7, _080753C8 @ =0x08576190
	movs r6, #0x1f
_08075382:
	ldr r0, [r4]
	add r0, r8
	ldrb r3, [r0]
	adds r1, r3, #0
	lsrs r0, r1, #4
	adds r0, r0, r2
	add r0, ip
	ldrb r3, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r0, r0, r2
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r1, [r5]
	orrs r3, r0
	strb r3, [r1]
	subs r6, #1
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	cmp r6, #0
	bge _08075382
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080753C0: .4byte 0x08561FA8
_080753C4: .4byte 0x085761C0
_080753C8: .4byte 0x08576190

	thumb_func_start MinimapCopyTileXFlippedGfx
MinimapCopyTileXFlippedGfx: @ 0x080753CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	movs r1, #0
	lsrs r6, r2, #0x14
	ldr r0, _0807543C @ =0x08561FA8
	mov sb, r0
	ldr r0, _08075440 @ =0x085761C0
	mov r8, r0
	ldr r0, _08075444 @ =0x08576190
	mov ip, r0
_080753EA:
	ldr r0, [r4]
	adds r0, #3
	str r0, [r4]
	adds r7, r1, #1
	movs r2, #3
_080753F4:
	ldr r0, [r4]
	add r0, sb
	ldrb r3, [r0]
	adds r1, r3, #0
	movs r0, #0xf
	ands r0, r1
	adds r0, r0, r6
	add r0, r8
	ldrb r3, [r0]
	lsrs r1, r1, #4
	adds r1, r1, r6
	add r1, ip
	ldrb r0, [r1]
	ldr r1, [r5]
	orrs r3, r0
	strb r3, [r1]
	subs r2, #1
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	ldr r1, [r4]
	subs r0, r1, #1
	str r0, [r4]
	cmp r2, #0
	bge _080753F4
	adds r0, r1, #4
	str r0, [r4]
	adds r1, r7, #0
	cmp r1, #7
	ble _080753EA
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807543C: .4byte 0x08561FA8
_08075440: .4byte 0x085761C0
_08075444: .4byte 0x08576190

	thumb_func_start MinimapCopyTileYFlippedGfx
MinimapCopyTileYFlippedGfx: @ 0x08075448
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	ldr r0, [r4]
	adds r0, #0x1c
	str r0, [r4]
	movs r0, #0
	lsrs r6, r2, #0x14
	ldr r1, _080754B8 @ =0x08561FA8
	mov sb, r1
	ldr r1, _080754BC @ =0x085761C0
	mov r8, r1
	ldr r1, _080754C0 @ =0x08576190
	mov ip, r1
_0807546C:
	adds r7, r0, #1
	movs r2, #3
_08075470:
	ldr r0, [r4]
	add r0, sb
	ldrb r3, [r0]
	adds r1, r3, #0
	lsrs r0, r1, #4
	adds r0, r0, r6
	add r0, r8
	ldrb r3, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r0, r0, r6
	add r0, ip
	ldrb r0, [r0]
	ldr r1, [r5]
	orrs r3, r0
	strb r3, [r1]
	subs r2, #1
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	ldr r1, [r4]
	adds r0, r1, #1
	str r0, [r4]
	cmp r2, #0
	bge _08075470
	subs r0, r1, #7
	str r0, [r4]
	adds r0, r7, #0
	cmp r0, #7
	ble _0807546C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080754B8: .4byte 0x08561FA8
_080754BC: .4byte 0x085761C0
_080754C0: .4byte 0x08576190

	thumb_func_start MinimapCopyTileXYFlippedGfx
MinimapCopyTileXYFlippedGfx: @ 0x080754C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	ldr r0, [r4]
	adds r0, #0x1f
	str r0, [r4]
	ldr r0, _08075520 @ =0x08561FA8
	mov r8, r0
	ldr r0, _08075524 @ =0x085761C0
	mov ip, r0
	lsrs r2, r2, #0x14
	ldr r7, _08075528 @ =0x08576190
	movs r6, #0x1f
_080754E4:
	ldr r0, [r4]
	add r0, r8
	ldrb r3, [r0]
	adds r1, r3, #0
	movs r0, #0xf
	ands r0, r1
	adds r0, r0, r2
	add r0, ip
	ldrb r3, [r0]
	lsrs r1, r1, #4
	adds r1, r1, r2
	adds r1, r1, r7
	ldrb r0, [r1]
	ldr r1, [r5]
	orrs r3, r0
	strb r3, [r1]
	subs r6, #1
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r6, #0
	bge _080754E4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075520: .4byte 0x08561FA8
_08075524: .4byte 0x085761C0
_08075528: .4byte 0x08576190

	thumb_func_start MapScreenHandler
MapScreenHandler: @ 0x0807552C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	movs r7, #0
	ldr r0, _080755F8 @ =gButtonInput
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08075548
	b _080756CA
_08075548:
	ldr r2, _080755FC @ =gNonGameplayRam
	ldr r0, _08075600 @ =0x00000259
	adds r0, r0, r2
	mov r8, r0
	ldr r1, _08075604 @ =0x00000256
	adds r0, r2, r1
	mov r3, r8
	ldrb r1, [r3]
	mov r3, sp
	strb r1, [r3, #0x10]
	mov r1, r8
	movs r3, #0
	ldrsb r3, [r1, r3]
	movs r1, #0
	ldrsb r1, [r0, r1]
	eors r1, r3
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	mov sl, r0
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r2, r1
	mov r1, sl
	strb r1, [r0]
	movs r0, #0
	mov ip, r0
	ldr r1, _08075608 @ =0x00000257
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r6, r2, #0
	cmp r0, r3
	ble _08075592
	movs r3, #1
	mov ip, r3
_08075592:
	ldr r1, _0807560C @ =0x00000261
	adds r0, r6, r1
	mov r3, ip
	strb r3, [r0]
	movs r4, #0
	subs r1, #0xd
	adds r0, r6, r1
	movs r3, #0x96
	lsls r3, r3, #2
	adds r5, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r1, [r5]
	mov sb, r1
	movs r2, #0
	ldrsb r2, [r5, r2]
	cmp r0, r2
	ble _080755BA
	movs r4, #1
_080755BA:
	ldr r3, _08075610 @ =0x0000025E
	adds r0, r6, r3
	strb r4, [r0]
	ldr r1, _08075614 @ =0x00000255
	adds r0, r6, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	eors r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r3, r0, #0x1f
	ldr r1, _08075618 @ =0x0000025F
	adds r0, r6, r1
	strb r3, [r0]
	ldr r0, _0807561C @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #0x40
	ands r0, r1
	mov r2, sb
	cmp r0, #0
	beq _08075620
	mov r1, sl
	cmp r1, #0
	beq _0807565E
	mov r3, sp
	ldrb r0, [r3, #0x10]
	subs r0, #1
	mov r1, r8
	strb r0, [r1]
	b _0807565C
	.align 2, 0
_080755F8: .4byte gButtonInput
_080755FC: .4byte gNonGameplayRam
_08075600: .4byte 0x00000259
_08075604: .4byte 0x00000256
_08075608: .4byte 0x00000257
_0807560C: .4byte 0x00000261
_08075610: .4byte 0x0000025E
_08075614: .4byte 0x00000255
_08075618: .4byte 0x0000025F
_0807561C: .4byte gChangedInput
_08075620:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807563A
	mov r3, ip
	cmp r3, #0
	beq _0807565E
	mov r1, sp
	ldrb r0, [r1, #0x10]
	adds r0, #1
	mov r3, r8
	strb r0, [r3]
	b _0807565C
_0807563A:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807564A
	cmp r4, #0
	beq _0807565E
	adds r0, r2, #1
	b _0807565A
_0807564A:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807565E
	cmp r3, #0
	beq _0807565E
	mov r0, sb
	subs r0, #1
_0807565A:
	strb r0, [r5]
_0807565C:
	movs r7, #1
_0807565E:
	ldr r2, _080756AC @ =gBackgroundPositions
	adds r4, r6, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x80
	lsls r1, r1, #2
	adds r3, r1, #0
	subs r0, r3, r0
	movs r5, #0
	strh r0, [r2, #0xc]
	adds r1, #0x59
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0xa
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, r3, r0
	strh r0, [r2, #0xe]
	ldr r0, _080756B0 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080756B4
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #6
	strb r0, [r1]
	strb r5, [r4, #6]
	strb r5, [r4, #7]
	b _080756C8
	.align 2, 0
_080756AC: .4byte gBackgroundPositions
_080756B0: .4byte gChangedInput
_080756B4:
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080756CA
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #0xb
	strb r0, [r1]
	strb r5, [r6, #6]
	strb r5, [r6, #7]
_080756C8:
	movs r7, #3
_080756CA:
	ldr r3, _080756E8 @ =gChangedInput
	ldrh r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080756D8
	movs r7, #2
_080756D8:
	cmp r7, #0
	beq _08075710
	cmp r7, #1
	bne _080756EC
	movs r0, #1
	bl unk_77840
	b _0807572C
	.align 2, 0
_080756E8: .4byte gChangedInput
_080756EC:
	cmp r7, #2
	bne _0807572C
	ldr r0, _0807570C @ =gNonGameplayRam
	ldrb r0, [r0, #1]
	cmp r0, #4
	beq _08075700
	cmp r0, #5
	beq _08075702
	cmp r0, #9
	bne _08075702
_08075700:
	movs r7, #1
_08075702:
	adds r0, r7, #0
	bl unk_77840
	b _0807572C
	.align 2, 0
_0807570C: .4byte gNonGameplayRam
_08075710:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0807572C
	ldr r0, _0807573C @ =gNonGameplayRam
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807572C
	movs r0, #1
	bl PauseScreenDrawIgtAndTanks
_0807572C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807573C: .4byte gNonGameplayRam

	thumb_func_start SetMapScreenSamusHeadPosition
SetMapScreenSamusHeadPosition: @ 0x08075740
	ldr r2, _08075760 @ =gNonGameplayRam
	ldr r0, _08075764 @ =0x03000031
	ldrb r0, [r0]
	lsls r0, r0, #3
	movs r3, #0xd7
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	ldr r0, _08075768 @ =0x03000032
	ldrb r0, [r0]
	lsls r0, r0, #3
	subs r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	bx lr
	.align 2, 0
_08075760: .4byte gNonGameplayRam
_08075764: .4byte 0x03000031
_08075768: .4byte 0x03000032

	thumb_func_start MinimapSetVisitedTilesAndCollectedItems
MinimapSetVisitedTilesAndCollectedItems: @ 0x0807576C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #7
	bls _0807577A
	movs r4, #7
_0807577A:
	adds r0, r4, #0
	bl MinimapSetVisitedTiles
	adds r0, r4, #0
	bl MinimapSetCollectedItems
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start MinimapSetVisitedTiles
MinimapSetVisitedTiles: @ 0x0807578C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #7
	cmp r0, #6
	bhi _080757A2
	adds r1, r0, #0
_080757A2:
	lsls r0, r1, #7
	ldr r3, _080757F0 @ =0x02037C00
	adds r2, r0, r3
	ldr r3, _080757F4 @ =0x02034000
	ldr r0, _080757F8 @ =gEquipment
	ldrb r0, [r0, #0xe]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08075822
	movs r1, #0
	ldr r5, _080757FC @ =0x0879BDDC
	mov r8, r5
	movs r0, #0x80
	lsls r0, r0, #6
	mov ip, r0
_080757C4:
	ldm r2!, {r0}
	adds r6, r1, #1
	adds r7, r2, #0
	mov sb, r0
	mov r2, r8
	movs r4, #0x1f
_080757D0:
	ldr r0, [r2]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _08075800
	ldrh r1, [r3]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	bne _0807580E
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r0, r1
	b _0807580C
	.align 2, 0
_080757F0: .4byte 0x02037C00
_080757F4: .4byte 0x02034000
_080757F8: .4byte gEquipment
_080757FC: .4byte 0x0879BDDC
_08075800:
	ldrh r1, [r3]
	mov r0, ip
	ands r0, r1
	cmp r0, #0
	beq _0807580E
	movs r0, #0xa0
_0807580C:
	strh r0, [r3]
_0807580E:
	adds r2, #4
	subs r4, #1
	adds r3, #2
	cmp r4, #0
	bge _080757D0
	adds r1, r6, #0
	adds r2, r7, #0
	cmp r1, #0x1f
	ble _080757C4
	b _08075876
_08075822:
	movs r1, #0
	ldr r0, _0807585C @ =0x0879BDDC
	mov sl, r0
	movs r5, #0x80
	lsls r5, r5, #6
	mov sb, r5
	movs r0, #0x80
	lsls r0, r0, #5
	mov r8, r0
	movs r5, #0xa0
	mov ip, r5
_08075838:
	ldm r2!, {r0}
	adds r6, r1, #1
	adds r7, r2, #0
	adds r5, r0, #0
	mov r2, sl
	movs r4, #0x1f
_08075844:
	ldr r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _08075860
	ldrh r1, [r3]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	bne _08075864
	mov r0, r8
	orrs r0, r1
	b _08075862
	.align 2, 0
_0807585C: .4byte 0x0879BDDC
_08075860:
	mov r0, ip
_08075862:
	strh r0, [r3]
_08075864:
	adds r2, #4
	subs r4, #1
	adds r3, #2
	cmp r4, #0
	bge _08075844
	adds r1, r6, #0
	adds r2, r7, #0
	cmp r1, #0x1f
	ble _08075838
_08075876:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start MinimapSetCollectedItems
MinimapSetCollectedItems: @ 0x08075884
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r6, #7
	cmp r2, #6
	bhi _08075898
	adds r6, r2, #0
_08075898:
	ldr r0, _080758A8 @ =0x02034000
	mov sb, r0
	movs r7, #0x40
	cmp r6, #0
	beq _080758AC
	adds r6, #1
	b _080758AE
	.align 2, 0
_080758A8: .4byte 0x02034000
_080758AC:
	movs r7, #0x80
_080758AE:
	lsls r0, r6, #8
	ldr r1, _08075920 @ =0x02037200
	adds r5, r0, r1
	movs r6, #0
	cmp r6, r7
	bge _08075914
	ldrb r0, [r5]
	cmp r0, #0xff
	beq _08075914
	ldr r1, _08075924 @ =0x0879B8BC
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
_080758CA:
	ldrb r0, [r5, #2]
	subs r0, #2
	movs r1, #0xf
	bl __divsi3
	adds r4, r0, #0
	ldrb r0, [r5, #3]
	subs r0, #2
	movs r1, #0xa
	bl __divsi3
	ldrb r2, [r5]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #2
	add r1, r8
	adds r2, r1, #0
	adds r2, #0x35
	ldrb r2, [r2]
	adds r4, r4, r2
	adds r1, #0x36
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r0, r4
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r6, #1
	adds r5, #4
	cmp r6, r7
	bge _08075914
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _080758CA
_08075914:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075920: .4byte 0x02037200
_08075924: .4byte 0x0879B8BC

	thumb_func_start MinimapUpdateForExploredTiles
MinimapUpdateForExploredTiles: @ 0x08075928
	push {lr}
	ldr r0, _0807596C @ =gCurrentArea
	ldrb r0, [r0]
	cmp r0, #6
	bhi _08075982
	ldr r1, _08075970 @ =0x03000031
	ldr r0, _08075974 @ =0x03000032
	ldrb r0, [r0]
	lsls r0, r0, #5
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r3, r0, #1
	ldr r0, _08075978 @ =0x02034000
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r0, #0xc0
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08075982
	ldr r1, _0807597C @ =0x02034800
	adds r0, r3, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _08075980
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	b _08075982
	.align 2, 0
_0807596C: .4byte gCurrentArea
_08075970: .4byte 0x03000031
_08075974: .4byte 0x03000032
_08075978: .4byte 0x02034000
_0807597C: .4byte 0x02034800
_08075980:
	strh r1, [r2]
_08075982:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start unk_75988
unk_75988: @ 0x08075988
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, _080759EC @ =gNonGameplayRam
	ldr r2, _080759F0 @ =0x0000025E
	adds r0, r1, r2
	movs r3, #0
	strb r3, [r0]
	ldr r4, _080759F4 @ =0x0000025F
	adds r0, r1, r4
	strb r3, [r0]
	adds r2, #2
	adds r0, r1, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r1, r4
	strb r3, [r0]
	subs r2, #0xb
	adds r0, r1, r2
	movs r2, #0x1f
	strb r2, [r0]
	ldr r0, _080759F8 @ =0x00000256
	adds r4, r1, r0
	strb r2, [r4]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #3
	adds r0, r1, r2
	strb r3, [r0]
	ldr r6, _080759FC @ =0x02034000
	movs r5, #0
	mov ip, r1
	ldr r0, _08075A00 @ =gBackgroundPositions
	mov sb, r0
	adds r7, r4, #0
	adds r4, r6, #0
_080759DC:
	movs r2, #0
	ldrh r0, [r4]
	lsls r1, r3, #5
	cmp r0, #0xa0
	beq _08075A04
	strb r3, [r7]
	b _08075A26
	.align 2, 0
_080759EC: .4byte gNonGameplayRam
_080759F0: .4byte 0x0000025E
_080759F4: .4byte 0x0000025F
_080759F8: .4byte 0x00000256
_080759FC: .4byte 0x02034000
_08075A00: .4byte gBackgroundPositions
_08075A04:
	adds r2, #1
	cmp r2, #0x1f
	bgt _08075A1A
	adds r0, r1, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0xa0
	beq _08075A04
	strb r3, [r7]
	movs r5, #1
_08075A1A:
	cmp r5, #0
	bne _08075A26
	adds r4, #0x40
	adds r3, #1
	cmp r3, #0x1f
	ble _080759DC
_08075A26:
	movs r5, #0
	movs r3, #0x20
	ldr r4, _08075A44 @ =0x030016DB
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r6, r0
_08075A32:
	subs r1, #0x40
	subs r3, #1
	movs r2, #0
	ldrh r0, [r1]
	cmp r0, #0xa0
	beq _08075A48
	strb r3, [r4]
	b _08075A68
	.align 2, 0
_08075A44: .4byte 0x030016DB
_08075A48:
	adds r2, #1
	cmp r2, #0x1f
	bgt _08075A60
	lsls r0, r3, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0xa0
	beq _08075A48
	strb r3, [r4]
	movs r5, #1
_08075A60:
	cmp r5, #0
	bne _08075A68
	cmp r3, #0
	bgt _08075A32
_08075A68:
	movs r5, #0
	movs r3, #0
	ldr r4, _08075A7C @ =0x030016D9
	adds r1, r6, #0
_08075A70:
	movs r2, #0
	ldrh r0, [r1]
	cmp r0, #0xa0
	beq _08075A80
	strb r3, [r4]
	b _08075AA4
	.align 2, 0
_08075A7C: .4byte 0x030016D9
_08075A80:
	adds r2, #1
	cmp r2, #0x13
	bgt _08075A98
	lsls r0, r2, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0xa0
	beq _08075A80
	strb r3, [r4]
	movs r5, #1
_08075A98:
	cmp r5, #0
	bne _08075AA4
	adds r1, #2
	adds r3, #1
	cmp r3, #0x1f
	ble _08075A70
_08075AA4:
	movs r5, #0
	movs r3, #0x20
	ldr r4, _08075AC0 @ =0x030016D8
	adds r1, r6, #0
	adds r1, #0x40
_08075AAE:
	subs r1, #2
	subs r3, #1
	movs r2, #0
	ldrh r0, [r1]
	cmp r0, #0xa0
	beq _08075AC4
	strb r3, [r4]
	b _08075AE4
	.align 2, 0
_08075AC0: .4byte 0x030016D8
_08075AC4:
	adds r2, #1
	cmp r2, #0x13
	bgt _08075ADC
	lsls r0, r2, #5
	adds r0, r0, r3
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0xa0
	beq _08075AC4
	strb r3, [r4]
	movs r5, #1
_08075ADC:
	cmp r5, #0
	bne _08075AE4
	cmp r3, #0
	bgt _08075AAE
_08075AE4:
	ldr r6, _08075B50 @ =0x00000255
	add r6, ip
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, ip
	ldrb r2, [r6]
	movs r1, #0
	ldrsb r1, [r6, r1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r1, r0
	ble _08075AFE
	strb r2, [r4]
_08075AFE:
	ldr r5, _08075B54 @ =0x00000256
	add r5, ip
	ldr r3, _08075B58 @ =0x00000257
	add r3, ip
	ldrb r2, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r1, r0
	ble _08075B16
	strb r2, [r3]
_08075B16:
	ldrb r1, [r4]
	ldr r0, _08075B5C @ =0x0000025A
	add r0, ip
	strb r1, [r0]
	ldrb r1, [r6]
	ldr r0, _08075B60 @ =0x0000025B
	add r0, ip
	strb r1, [r0]
	ldrb r1, [r5]
	movs r0, #0x97
	lsls r0, r0, #2
	add r0, ip
	strb r1, [r0]
	ldrb r1, [r3]
	ldr r0, _08075B64 @ =0x0000025D
	add r0, ip
	strb r1, [r0]
	mov r1, r8
	cmp r1, #0
	beq _08075B6C
	movs r0, #0x84
	lsls r0, r0, #2
	add r0, ip
	ldrb r4, [r0]
	ldr r0, _08075B68 @ =0x00000211
	add r0, ip
	ldrb r1, [r0]
	b _08075BC6
	.align 2, 0
_08075B50: .4byte 0x00000255
_08075B54: .4byte 0x00000256
_08075B58: .4byte 0x00000257
_08075B5C: .4byte 0x0000025A
_08075B60: .4byte 0x0000025B
_08075B64: .4byte 0x0000025D
_08075B68: .4byte 0x00000211
_08075B6C:
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r0, r1
	asrs r4, r0, #1
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r0, r0, r1
	asrs r1, r0, #1
	adds r3, r1, #4
	subs r2, r1, #7
	ldr r0, _08075B98 @ =0x00000211
	add r0, ip
	ldrb r0, [r0]
	cmp r3, r0
	bge _08075B9C
	subs r0, r0, r3
	adds r1, r1, r0
	b _08075BA4
	.align 2, 0
_08075B98: .4byte 0x00000211
_08075B9C:
	cmp r2, r0
	ble _08075BA4
	subs r0, r2, r0
	subs r1, r1, r0
_08075BA4:
	adds r3, r4, #0
	adds r3, #0xc
	adds r2, r4, #0
	subs r2, #0xc
	movs r0, #0x84
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	cmp r3, r0
	bge _08075BBE
	subs r0, r0, r3
	adds r4, r4, r0
	b _08075BC6
_08075BBE:
	cmp r2, r0
	ble _08075BC6
	subs r0, r2, r0
	subs r4, r4, r0
_08075BC6:
	mov r3, ip
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r3, r2
	strb r4, [r0]
	ldr r4, _08075C54 @ =0x00000259
	adds r2, r3, r4
	strb r1, [r2]
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r4, #0x59
	adds r1, r4, #0
	subs r0, r1, r0
	mov r4, sb
	strh r0, [r4, #0xc]
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0xa
	subs r0, r0, r2
	lsls r0, r0, #3
	subs r1, r1, r0
	strh r1, [r4, #0xe]
	ldr r0, _08075C58 @ =0x00000257
	adds r4, r3, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, _08075C5C @ =0x00000256
	adds r2, r3, r1
	movs r1, #0
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	asrs r3, r0, #1
	cmp r3, #3
	ble _08075C14
	movs r3, #3
_08075C14:
	ldrb r0, [r2]
	adds r0, r0, r3
	strb r0, [r2]
	ldrb r0, [r4]
	subs r0, r0, r3
	strb r0, [r4]
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, ip
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r2, _08075C60 @ =0x00000255
	add r2, ip
	movs r1, #0
	ldrsb r1, [r2, r1]
	subs r0, r0, r1
	asrs r3, r0, #1
	cmp r3, #3
	ble _08075C3C
	movs r3, #3
_08075C3C:
	ldrb r0, [r2]
	adds r0, r0, r3
	strb r0, [r2]
	ldrb r0, [r4]
	subs r0, r0, r3
	strb r0, [r4]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08075C54: .4byte 0x00000259
_08075C58: .4byte 0x00000257
_08075C5C: .4byte 0x00000256
_08075C60: .4byte 0x00000255

	thumb_func_start MinimapUpdateForCollectedItem
MinimapUpdateForCollectedItem: @ 0x08075C64
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	subs r0, #2
	movs r1, #0xf
	bl __divsi3
	adds r5, r0, #0
	ldr r6, _08075CB8 @ =gCurrentRoomEntry
	ldrb r0, [r6, #0xe]
	adds r5, r5, r0
	subs r4, #2
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	ldrb r1, [r6, #0xf]
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r5, r0
	lsls r5, r5, #1
	ldr r0, _08075CBC @ =0x02034000
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08075CC0 @ =0x02034800
	adds r5, r5, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, _08075CC4 @ =gMinimapUpdateFlag
	movs r0, #3
	strb r0, [r1]
	bl MinimapDraw
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08075CB8: .4byte gCurrentRoomEntry
_08075CBC: .4byte 0x02034000
_08075CC0: .4byte 0x02034800
_08075CC4: .4byte gMinimapUpdateFlag

	thumb_func_start MinimapCheckIsTileExplored
MinimapCheckIsTileExplored: @ 0x08075CC8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r1, _08075D10 @ =gCurrentArea
	ldrb r0, [r1]
	cmp r0, #6
	bhi _08075D20
	adds r5, r0, #0
	lsls r5, r5, #5
	subs r0, r2, #2
	movs r1, #0xf
	bl __divsi3
	adds r4, r0, #0
	ldr r6, _08075D14 @ =gCurrentRoomEntry
	ldrb r0, [r6, #0xe]
	adds r4, r4, r0
	subs r0, r7, #2
	movs r1, #0xa
	bl __divsi3
	ldrb r1, [r6, #0xf]
	adds r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, _08075D18 @ =0x02037C00
	adds r0, r0, r1
	ldr r1, _08075D1C @ =0x0879BDDC
	lsls r4, r4, #2
	adds r4, r4, r1
	ldr r0, [r0]
	ldr r1, [r4]
	ands r0, r1
	b _08075D22
	.align 2, 0
_08075D10: .4byte gCurrentArea
_08075D14: .4byte gCurrentRoomEntry
_08075D18: .4byte 0x02037C00
_08075D1C: .4byte 0x0879BDDC
_08075D20:
	movs r0, #1
_08075D22:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start MapScreenCountTanks
MapScreenCountTanks: @ 0x08075D28
	push {r4, r5, r6, r7, lr}
	ldr r4, _08075DE4 @ =gNonGameplayRam
	ldr r7, _08075DE8 @ =0x08575F88
	ldrb r1, [r7, #0x15]
	ldr r2, _08075DEC @ =0x0000027B
	adds r0, r4, r2
	movs r6, #0
	strb r1, [r0]
	ldrb r1, [r7, #0x16]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r1, [r7, #0x17]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r5, _08075DF0 @ =gEquipment
	ldrh r0, [r5, #2]
	subs r0, #0x63
	movs r1, #0x64
	bl __divsi3
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldrh r0, [r5, #6]
	subs r0, #0xa
	movs r1, #5
	bl __divsi3
	ldr r2, _08075DF4 @ =0x0000027E
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r0, [r5, #9]
	subs r0, #0xa
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08075DF8 @ =0x00000275
	adds r3, r4, r0
	strb r6, [r3]
	ldr r1, _08075DFC @ =0x00000277
	adds r5, r4, r1
	strb r6, [r5]
	subs r2, #7
	adds r2, r2, r4
	mov ip, r2
	strb r6, [r2]
	subs r1, #1
	adds r0, r4, r1
	strb r6, [r0]
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r6, [r0]
	ldr r0, _08075E00 @ =0x0000027A
	adds r4, r4, r0
	strb r6, [r4]
	ldr r2, _08075E04 @ =gCurrentArea
	ldrb r0, [r2]
	cmp r0, #6
	bhi _08075E5C
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r7
	ldrb r0, [r0]
	strb r0, [r3]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r7, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r7, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r2]
	movs r6, #0x40
	cmp r1, #0
	beq _08075E08
	adds r1, #1
	b _08075E0A
	.align 2, 0
_08075DE4: .4byte gNonGameplayRam
_08075DE8: .4byte 0x08575F88
_08075DEC: .4byte 0x0000027B
_08075DF0: .4byte gEquipment
_08075DF4: .4byte 0x0000027E
_08075DF8: .4byte 0x00000275
_08075DFC: .4byte 0x00000277
_08075E00: .4byte 0x0000027A
_08075E04: .4byte gCurrentArea
_08075E08:
	movs r6, #0x80
_08075E0A:
	lsls r0, r1, #8
	ldr r1, _08075E30 @ =0x02037200
	adds r2, r0, r1
	movs r1, #0
	cmp r1, r6
	bge _08075E5C
	ldrb r0, [r2]
	cmp r0, #0xff
	beq _08075E5C
	ldr r3, _08075E34 @ =0x030016FC
	subs r5, r3, #2
	adds r4, r3, #2
_08075E22:
	ldrb r0, [r2, #1]
	cmp r0, #1
	bne _08075E38
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _08075E4E
	.align 2, 0
_08075E30: .4byte 0x02037200
_08075E34: .4byte 0x030016FC
_08075E38:
	cmp r0, #2
	bne _08075E44
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08075E4E
_08075E44:
	cmp r0, #3
	bne _08075E4E
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08075E4E:
	adds r1, #1
	adds r2, #4
	cmp r1, r6
	bge _08075E5C
	ldrb r0, [r2]
	cmp r0, #0xff
	bne _08075E22
_08075E5C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PauseScreenDrawIgtAndTanks
PauseScreenDrawIgtAndTanks: @ 0x08075E64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08075EA4
	ldr r0, _08075E90 @ =gNonGameplayRam
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrb r1, [r3]
	cmp r1, #1
	bne _08075E94
	movs r0, #2
	strb r0, [r3]
	movs r2, #1
	str r2, [sp]
	b _08075EB4
	.align 2, 0
_08075E90: .4byte gNonGameplayRam
_08075E94:
	cmp r1, #2
	beq _08075E9A
	b _080761B4
_08075E9A:
	movs r0, #1
	strb r0, [r3]
	movs r0, #0
	str r0, [sp]
	b _08075EB4
_08075EA4:
	ldr r2, _08075F50 @ =gNonGameplayRam
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0
	str r1, [sp]
_08075EB4:
	ldr r2, _08075F54 @ =gInGameTimer
	mov sb, r2
	ldrb r0, [r2]
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	ldr r4, _08075F58 @ =0x040000D4
	lsrs r0, r0, #0x13
	ldr r1, _08075F5C @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	ldr r2, _08075F60 @ =0x085761F0
	mov sl, r2
	ldr r5, [r2, #0x18]
	str r5, [r4, #4]
	ldr r6, _08075F64 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	mov r2, sb
	ldrb r0, [r2, #1]
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	add r0, r8
	str r0, [r4]
	mov r0, sl
	ldr r5, [r0, #0x1c]
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	mov r1, sb
	ldrb r0, [r1, #1]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x13
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	mov sb, sl
	ldr r2, [sp]
	cmp r2, #0
	bne _08075F68
	ldr r1, _08075F50 @ =gNonGameplayRam
	movs r2, #0x9f
	lsls r2, r2, #2
	b _08075F6C
	.align 2, 0
_08075F50: .4byte gNonGameplayRam
_08075F54: .4byte gInGameTimer
_08075F58: .4byte 0x040000D4
_08075F5C: .4byte 0x06017EC0
_08075F60: .4byte 0x085761F0
_08075F64: .4byte 0x84000008
_08075F68:
	ldr r1, _08075FB8 @ =gNonGameplayRam
	ldr r2, _08075FBC @ =0x00000276
_08075F6C:
	adds r0, r1, r2
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	ldr r4, _08075FC0 @ =0x040000D4
	lsls r0, r0, #5
	ldr r1, _08075FC4 @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	mov r2, sb
	ldr r5, [r2]
	str r5, [r4, #4]
	ldr r6, _08075FC8 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #5
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08075FD0
	ldr r1, _08075FB8 @ =gNonGameplayRam
	ldr r2, _08075FCC @ =0x0000027B
	b _08075FD4
	.align 2, 0
_08075FB8: .4byte gNonGameplayRam
_08075FBC: .4byte 0x00000276
_08075FC0: .4byte 0x040000D4
_08075FC4: .4byte 0x06017EC0
_08075FC8: .4byte 0x84000008
_08075FCC: .4byte 0x0000027B
_08075FD0:
	ldr r1, _08076020 @ =gNonGameplayRam
	ldr r2, _08076024 @ =0x00000275
_08075FD4:
	adds r0, r1, r2
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	ldr r4, _08076028 @ =0x040000D4
	lsls r0, r0, #5
	ldr r1, _0807602C @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	mov r2, sb
	ldr r5, [r2, #4]
	str r5, [r4, #4]
	ldr r6, _08076030 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #5
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08076038
	ldr r1, _08076020 @ =gNonGameplayRam
	ldr r2, _08076034 @ =0x0000027E
	b _0807603E
	.align 2, 0
_08076020: .4byte gNonGameplayRam
_08076024: .4byte 0x00000275
_08076028: .4byte 0x040000D4
_0807602C: .4byte 0x06017EC0
_08076030: .4byte 0x84000008
_08076034: .4byte 0x0000027E
_08076038:
	ldr r1, _0807608C @ =gNonGameplayRam
	movs r2, #0x9e
	lsls r2, r2, #2
_0807603E:
	adds r0, r1, r2
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	ldr r4, _08076090 @ =0x040000D4
	lsls r0, r0, #5
	ldr r1, _08076094 @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	mov r2, sb
	ldr r5, [r2, #8]
	str r5, [r4, #4]
	ldr r6, _08076098 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #5
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _080760A0
	ldr r1, _0807608C @ =gNonGameplayRam
	ldr r2, _0807609C @ =0x0000027D
	b _080760A4
	.align 2, 0
_0807608C: .4byte gNonGameplayRam
_08076090: .4byte 0x040000D4
_08076094: .4byte 0x06017EC0
_08076098: .4byte 0x84000008
_0807609C: .4byte 0x0000027D
_080760A0:
	ldr r1, _080760F4 @ =gNonGameplayRam
	ldr r2, _080760F8 @ =0x00000277
_080760A4:
	adds r0, r1, r2
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	ldr r4, _080760FC @ =0x040000D4
	lsls r0, r0, #5
	ldr r1, _08076100 @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	mov r2, sb
	ldr r5, [r2, #0xc]
	str r5, [r4, #4]
	ldr r6, _08076104 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #5
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08076108
	ldr r1, _080760F4 @ =gNonGameplayRam
	movs r2, #0xa0
	lsls r2, r2, #2
	b _0807610C
	.align 2, 0
_080760F4: .4byte gNonGameplayRam
_080760F8: .4byte 0x00000277
_080760FC: .4byte 0x040000D4
_08076100: .4byte 0x06017EC0
_08076104: .4byte 0x84000008
_08076108:
	ldr r1, _08076158 @ =gNonGameplayRam
	ldr r2, _0807615C @ =0x0000027A
_0807610C:
	adds r0, r1, r2
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	ldr r4, _08076160 @ =0x040000D4
	lsls r0, r0, #5
	ldr r1, _08076164 @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	mov r2, sb
	ldr r5, [r2, #0x10]
	str r5, [r4, #4]
	ldr r6, _08076168 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #5
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, [sp]
	cmp r0, #0
	bne _08076170
	ldr r1, _08076158 @ =gNonGameplayRam
	ldr r2, _0807616C @ =0x0000027F
	b _08076174
	.align 2, 0
_08076158: .4byte gNonGameplayRam
_0807615C: .4byte 0x0000027A
_08076160: .4byte 0x040000D4
_08076164: .4byte 0x06017EC0
_08076168: .4byte 0x84000008
_0807616C: .4byte 0x0000027F
_08076170:
	ldr r1, _080761C4 @ =gNonGameplayRam
	ldr r2, _080761C8 @ =0x00000279
_08076174:
	adds r0, r1, r2
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	ldr r4, _080761CC @ =0x040000D4
	lsls r0, r0, #5
	ldr r1, _080761D0 @ =0x06017EC0
	mov r8, r1
	add r0, r8
	str r0, [r4]
	mov r2, sb
	ldr r5, [r2, #0x14]
	str r5, [r4, #4]
	ldr r6, _080761D4 @ =0x84000008
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	adds r0, r7, #0
	movs r1, #0xa
	bl __modsi3
	lsls r0, r0, #5
	add r0, r8
	str r0, [r4]
	adds r5, #0x20
	str r5, [r4, #4]
	str r6, [r4, #8]
	ldr r0, [r4, #8]
_080761B4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080761C4: .4byte gNonGameplayRam
_080761C8: .4byte 0x00000279
_080761CC: .4byte 0x040000D4
_080761D0: .4byte 0x06017EC0
_080761D4: .4byte 0x84000008

	thumb_func_start PauseScreenMapDownload
PauseScreenMapDownload: @ 0x080761D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _08076210 @ =gNonGameplayRam
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r2, _08076214 @ =0x00000231
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r1, #0
	cmp r0, #6
	bls _08076204
	b _080765E2
_08076204:
	lsls r0, r0, #2
	ldr r1, _08076218 @ =_0807621C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08076210: .4byte gNonGameplayRam
_08076214: .4byte 0x00000231
_08076218: .4byte _0807621C
_0807621C: @ jump table
	.4byte _08076238 @ case 0
	.4byte _08076350 @ case 1
	.4byte _080763C4 @ case 2
	.4byte _080764D0 @ case 3
	.4byte _0807650C @ case 4
	.4byte _08076540 @ case 5
	.4byte _080765C8 @ case 6
_08076238:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #8
	bhi _08076246
	b _080765E2
_08076246:
	movs r2, #0xdb
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	subs r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0x5a
	movs r0, #0x11
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x58
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x52
	movs r0, #0x74
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x50
	ldr r3, _08076344 @ =0x0000FFF8
	strh r3, [r0]
	adds r4, r6, #0
	adds r4, #0x5b
	ldrb r1, [r4]
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r1
	strb r0, [r4]
	movs r5, #4
	ldr r0, _08076348 @ =0x0879BEBC
	mov ip, r0
	adds r4, r6, #0
	movs r7, #0
	mov sb, r3
	mov sl, r2
	movs r1, #0xd
	rsbs r1, r1, #0
	mov r8, r1
_080762A2:
	subs r5, #1
	mov r2, ip
	adds r3, r5, r2
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x36
	strb r7, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x34
	strb r7, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x35
	strb r7, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0x74
	strh r1, [r0, #0x2e]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r1, sb
	strh r1, [r0, #0x2c]
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, #0x37
	ldrb r2, [r1]
	mov r0, sl
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, #0x37
	ldrb r2, [r1]
	mov r0, r8
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	cmp r5, #0
	bgt _080762A2
	ldr r2, _0807634C @ =0x00000231
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0x80
	strb r0, [r1]
	b _080765E2
	.align 2, 0
_08076344: .4byte 0x0000FFF8
_08076348: .4byte 0x0879BEBC
_0807634C: .4byte 0x00000231
_08076350:
	ldr r0, _08076374 @ =0x00000233
	adds r3, r6, r0
	movs r0, #0
	strb r0, [r3]
	ldr r2, _08076378 @ =gBackgroundPositions
	ldrh r1, [r2, #0xe]
	ldr r0, _0807637C @ =0x000001FF
	cmp r1, r0
	bhi _08076380
	adds r0, r1, #0
	movs r1, #0x80
	lsls r1, r1, #2
	subs r1, r1, r0
	asrs r1, r1, #3
	movs r0, #0x20
	subs r0, r0, r1
	b _08076390
	.align 2, 0
_08076374: .4byte 0x00000233
_08076378: .4byte gBackgroundPositions
_0807637C: .4byte 0x000001FF
_08076380:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bls _08076392
	ldrh r0, [r2, #0xe]
	ldr r1, _080763B4 @ =0xFFFFFE00
	adds r0, r0, r1
	asrs r0, r0, #3
_08076390:
	strb r0, [r3]
_08076392:
	ldr r2, _080763B8 @ =0x00000232
	adds r0, r6, r2
	movs r4, #0
	strb r4, [r0]
	ldr r0, _080763BC @ =0x0000011B
	bl SoundPlay
	ldr r0, _080763C0 @ =0x00000231
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	b _080765E2
	.align 2, 0
_080763B4: .4byte 0xFFFFFE00
_080763B8: .4byte 0x00000232
_080763BC: .4byte 0x0000011B
_080763C0: .4byte 0x00000231
_080763C4:
	movs r5, #1
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #7
	bls _08076442
	ldr r0, _08076414 @ =0x00000232
	adds r7, r6, r0
	ldrb r4, [r7]
	cmp r4, #0x13
	bhi _0807642C
	ldr r2, _08076418 @ =0x040000D4
	ldr r1, _0807641C @ =0x00000233
	adds r3, r6, r1
	ldrb r0, [r3]
	lsls r0, r0, #6
	ldr r1, _08076420 @ =0x02034000
	adds r0, r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	lsls r0, r0, #6
	ldr r1, _08076424 @ =0x0600E000
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _08076428 @ =0x80000020
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	adds r0, r4, #1
	strb r0, [r7]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08076438
	movs r0, #0
	strb r0, [r3]
	b _08076438
	.align 2, 0
_08076414: .4byte 0x00000232
_08076418: .4byte 0x040000D4
_0807641C: .4byte 0x00000233
_08076420: .4byte 0x02034000
_08076424: .4byte 0x0600E000
_08076428: .4byte 0x80000020
_0807642C:
	ldr r2, _080764C4 @ =0x00000231
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r5, #0
_08076438:
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_08076442:
	cmp r5, #0
	bne _08076448
	b _080765E2
_08076448:
	ldr r1, _080764C8 @ =0x00000232
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r6, r2
	lsls r0, r0, #3
	ldrb r1, [r1]
	adds r0, r0, r1
	subs r0, #5
	adds r7, r6, #0
	adds r7, #0x50
	movs r4, #0
	strh r0, [r7]
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r3, r6, r0
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0807647A
	strb r4, [r3]
_0807647A:
	ldrb r5, [r3]
	ldr r0, _080764CC @ =0x0879BEBC
	adds r2, r5, r0
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrh r1, [r7]
	subs r1, #1
	strh r1, [r0, #0x2c]
	cmp r5, #2
	ble _08076496
	b _080765E2
_08076496:
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x36
	movs r1, #0x10
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x34
	strb r4, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x35
	strb r4, [r0]
	b _080765E2
	.align 2, 0
_080764C4: .4byte 0x00000231
_080764C8: .4byte 0x00000232
_080764CC: .4byte 0x0879BEBC
_080764D0:
	ldr r1, _080764F8 @ =0x040000D4
	ldr r0, _080764FC @ =0x02034000
	str r0, [r1]
	ldr r0, _08076500 @ =0x0600E000
	str r0, [r1, #4]
	ldr r0, _08076504 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _08076508 @ =0x00000231
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	b _080765E2
	.align 2, 0
_080764F8: .4byte 0x040000D4
_080764FC: .4byte 0x02034000
_08076500: .4byte 0x0600E000
_08076504: .4byte 0x80000400
_08076508: .4byte 0x00000231
_0807650C:
	movs r5, #3
	ldr r4, _08076534 @ =gMinimapUpdateFlag
_08076510:
	strb r5, [r4]
	bl MinimapDraw
	subs r5, #1
	cmp r5, #0
	bgt _08076510
	ldr r1, _08076538 @ =gNonGameplayRam
	ldr r0, _0807653C @ =0x00000231
	adds r2, r1, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r1, r2
	strb r3, [r1]
	b _080765E2
	.align 2, 0
_08076534: .4byte gMinimapUpdateFlag
_08076538: .4byte gNonGameplayRam
_0807653C: .4byte 0x00000231
_08076540:
	movs r0, #0xdb
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x5a
	strb r1, [r0]
	subs r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r5, #4
	ldr r0, _080765C0 @ =0x0879BEBC
	mov ip, r0
	adds r3, r6, #0
	movs r4, #0
	mov r2, ip
	adds r2, #4
_08076576:
	subs r2, #1
	subs r5, #1
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x36
	strb r4, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x34
	strb r4, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x35
	strb r4, [r0]
	cmp r5, #0
	bgt _08076576
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080765C4 @ =0x00000231
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080765E2
	.align 2, 0
_080765C0: .4byte 0x0879BEBC
_080765C4: .4byte 0x00000231
_080765C8:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r2, r6, r1
	ldrb r0, [r2]
	cmp r0, #0x1d
	bls _080765E2
	movs r1, #0
	strb r1, [r2]
	ldr r2, _080765F4 @ =0x00000231
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #1
	str r0, [sp]
_080765E2:
	ldr r0, [sp]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080765F4: .4byte 0x00000231

	thumb_func_start PauseScreenHandler
PauseScreenHandler: @ 0x080765F8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _0807661C @ =gNextOamSlot
	movs r1, #0
	strb r1, [r0]
	movs r7, #0
	ldr r0, _08076620 @ =0x03000B85
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #4
	bls _08076610
	b _08076872
_08076610:
	lsls r0, r1, #2
	ldr r1, _08076624 @ =_08076628
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807661C: .4byte gNextOamSlot
_08076620: .4byte 0x03000B85
_08076624: .4byte _08076628
_08076628: @ jump table
	.4byte _0807663C @ case 0
	.4byte _08076644 @ case 1
	.4byte _08076720 @ case 2
	.4byte _080767A0 @ case 3
	.4byte _08076834 @ case 4
_0807663C:
	bl PauseScreenInit
	strb r0, [r5]
	b _08076872
_08076644:
	ldr r0, _08076678 @ =gNonGameplayRam
	ldrb r3, [r0]
	cmp r3, #0
	beq _080766E0
	ldr r0, _0807667C @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08076688
	ldr r3, _08076680 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r3]
	lsls r0, r0, #8
	ldr r2, _08076684 @ =gWrittenToBldalpha_Eva
	ldrh r4, [r2]
	orrs r0, r4
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r6, r3, #0
	cmp r0, r1
	beq _080766C8
	cmp r4, #8
	beq _080766B2
	adds r0, r4, #1
	b _080766A4
	.align 2, 0
_08076678: .4byte gNonGameplayRam
_0807667C: .4byte gPauseScreenFlag
_08076680: .4byte gWrittenToBldalpha_Evb
_08076684: .4byte gWrittenToBldalpha_Eva
_08076688:
	ldr r3, _080766C0 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r3]
	lsls r0, r0, #8
	ldr r2, _080766C4 @ =gWrittenToBldalpha_Eva
	ldrh r4, [r2]
	orrs r0, r4
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r6, r3, #0
	cmp r0, r1
	beq _080766C8
	cmp r4, #8
	beq _080766B2
	adds r0, r4, #2
_080766A4:
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls _080766B2
	movs r0, #8
	strh r0, [r2]
_080766B2:
	ldrh r0, [r6]
	cmp r0, #5
	bne _080766BA
	b _080767FA
_080766BA:
	adds r0, #1
	strh r0, [r6]
	b _080767FA
	.align 2, 0
_080766C0: .4byte gWrittenToBldalpha_Evb
_080766C4: .4byte gWrittenToBldalpha_Eva
_080766C8:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r1, _080766D8 @ =0x04000050
	ldr r3, _080766DC @ =0x00003F44
	adds r0, r3, #0
	strh r0, [r1]
	b _080767FA
	.align 2, 0
_080766D8: .4byte 0x04000050
_080766DC: .4byte 0x00003F44
_080766E0:
	ldr r2, _080766F4 @ =gWrittenToBldy
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _080766FC
	cmp r1, #4
	bls _080766F8
	subs r0, #4
	strh r0, [r2]
	b _08076872
	.align 2, 0
_080766F4: .4byte gWrittenToBldy
_080766F8:
	strh r3, [r2]
	b _08076872
_080766FC:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r1, _08076718 @ =0x04000050
	movs r2, #0xfc
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0807671C @ =0x0000040C
	adds r0, r3, #0
	strh r0, [r1]
	b _08076872
	.align 2, 0
_08076718: .4byte 0x04000050
_0807671C: .4byte 0x0000040C
_08076720:
	bl PauseScreenCallCurrentHandler
	cmp r0, #0
	beq _08076776
	ldr r0, _0807674C @ =gNonGameplayRam
	ldrb r1, [r0]
	cmp r1, #0
	beq _08076764
	ldr r1, _08076750 @ =0x04000050
	ldr r2, _08076754 @ =0x00003F7F
	adds r0, r2, #0
	strh r0, [r1]
	ldr r3, _08076758 @ =gWrittenToBldalpha_Eva
	ldr r0, _0807675C @ =0x04000052
	ldrh r2, [r0]
	ldr r1, _08076760 @ =gWrittenToBldalpha_Evb
	lsrs r0, r2, #8
	strh r0, [r1]
	movs r0, #0xff
	ands r0, r2
	strh r0, [r3]
	b _0807676E
	.align 2, 0
_0807674C: .4byte gNonGameplayRam
_08076750: .4byte 0x04000050
_08076754: .4byte 0x00003F7F
_08076758: .4byte gWrittenToBldalpha_Eva
_0807675C: .4byte 0x04000052
_08076760: .4byte gWrittenToBldalpha_Evb
_08076764:
	ldr r0, _08076790 @ =gWrittenToBldy
	strh r1, [r0]
	ldr r1, _08076794 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
_0807676E:
	ldr r1, _08076798 @ =0x03000B85
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08076776:
	ldr r0, _0807679C @ =gNonGameplayRam
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08076872
	bl unk_7c440
	bl unk_7cfb0
	b _08076872
	.align 2, 0
_08076790: .4byte gWrittenToBldy
_08076794: .4byte 0x04000050
_08076798: .4byte 0x03000B85
_0807679C: .4byte gNonGameplayRam
_080767A0:
	ldr r0, _080767D4 @ =gNonGameplayRam
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807680C
	ldr r0, _080767D8 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r4, #2
	cmp r0, #4
	bne _080767B8
	movs r4, #1
_080767B8:
	ldr r2, _080767DC @ =gWrittenToBldalpha_Evb
	ldr r3, _080767E0 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	ldrh r0, [r3]
	orrs r0, r1
	adds r6, r2, #0
	adds r2, r3, #0
	cmp r0, #0
	beq _080767F4
	ldrh r0, [r2]
	cmp r0, r4
	blt _080767E4
	subs r0, r0, r4
	b _080767E6
	.align 2, 0
_080767D4: .4byte gNonGameplayRam
_080767D8: .4byte gPauseScreenFlag
_080767DC: .4byte gWrittenToBldalpha_Evb
_080767E0: .4byte gWrittenToBldalpha_Eva
_080767E4:
	movs r0, #0
_080767E6:
	strh r0, [r2]
	ldrh r0, [r6]
	cmp r0, #0
	beq _080767FA
	subs r0, #1
	strh r0, [r6]
	b _080767FA
_080767F4:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_080767FA:
	ldr r0, _08076808 @ =0x04000052
	ldrh r1, [r6]
	lsls r1, r1, #8
	ldrh r2, [r2]
	orrs r1, r2
	strh r1, [r0]
	b _08076872
	.align 2, 0
_08076808: .4byte 0x04000052
_0807680C:
	ldr r1, _08076828 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0807682C
	adds r0, #4
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls _08076872
	movs r0, #0x10
	strh r0, [r1]
	b _08076872
	.align 2, 0
_08076828: .4byte gWrittenToBldy
_0807682C:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08076872
_08076834:
	ldr r1, _08076888 @ =gPauseScreenFlag
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	bne _0807686A
	ldr r0, _0807688C @ =gEventCounter
	ldrb r0, [r0]
	cmp r0, #0x61
	bne _0807686A
	ldr r0, _08076890 @ =gPreviousCutscene
	ldrb r0, [r0]
	cmp r0, #7
	beq _0807686A
	movs r0, #5
	strb r0, [r1]
	ldr r1, _08076894 @ =gCurrentCutscene
	movs r0, #7
	strb r0, [r1]
	ldr r1, _08076898 @ =0x0201C000
	ldr r2, _0807689C @ =0x06010000
	movs r3, #0x80
	lsls r3, r3, #8
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
_0807686A:
	movs r7, #1
	ldr r1, _080768A0 @ =0x03000B85
	movs r0, #0
	strb r0, [r1]
_08076872:
	bl MapScreenUpdateArrowsAndBlinkingSquare
	bl PauseScreenProcessOam
	bl ResetFreeOam
	adds r0, r7, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08076888: .4byte gPauseScreenFlag
_0807688C: .4byte gEventCounter
_08076890: .4byte gPreviousCutscene
_08076894: .4byte gCurrentCutscene
_08076898: .4byte 0x0201C000
_0807689C: .4byte 0x06010000
_080768A0: .4byte 0x03000B85

	thumb_func_start PauseScreenVBLank
PauseScreenVBLank: @ 0x080768A4
	ldr r1, _08076908 @ =0x040000D4
	ldr r0, _0807690C @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08076910 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0xd4
	ldr r0, _08076914 @ =gNonGameplayRam
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #0x54
	ldr r0, _08076918 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #8
	ldr r0, _0807691C @ =gWrittenToMosaic_L
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r2, _08076920 @ =0x04000010
	ldr r1, _08076924 @ =gBackgroundPositions
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #2]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #4]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #6]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #8]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0xa]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0xc]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0xe]
	strh r0, [r2]
	bx lr
	.align 2, 0
_08076908: .4byte 0x040000D4
_0807690C: .4byte gOamData
_08076910: .4byte 0x84000100
_08076914: .4byte gNonGameplayRam
_08076918: .4byte gWrittenToBldy
_0807691C: .4byte gWrittenToMosaic_L
_08076920: .4byte 0x04000010
_08076924: .4byte gBackgroundPositions

	thumb_func_start PauseScreenVBLank_Unused
PauseScreenVBLank_Unused: @ 0x08076928
	push {lr}
	ldr r0, _08076968 @ =0x0400001C
	movs r2, #0
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r0, _0807696C @ =gNonGameplayRam
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r3, _08076970 @ =0x0300000A
	ldrh r1, [r3]
	cmp r1, #0
	beq _08076952
	ldr r0, _08076974 @ =0x0400000E
	strh r1, [r0]
	strh r2, [r3]
_08076952:
	ldr r2, _08076978 @ =0x04000052
	ldr r0, _0807697C @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08076980 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_08076968: .4byte 0x0400001C
_0807696C: .4byte gNonGameplayRam
_08076970: .4byte 0x0300000A
_08076974: .4byte 0x0400000E
_08076978: .4byte 0x04000052
_0807697C: .4byte gWrittenToBldalpha_Evb
_08076980: .4byte gWrittenToBldalpha_Eva

	thumb_func_start PauseScreenInitVBlank
PauseScreenInitVBlank: @ 0x08076984
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start PauseScreenInit
PauseScreenInit: @ 0x08076990
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08076A50 @ =PauseScreenInitVBlank
	bl CallbackSetVBlank
	movs r0, #1
	mov sb, r0
	ldr r1, _08076A54 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	ldr r2, _08076A58 @ =0x04000054
	ldr r1, _08076A5C @ =gWrittenToBldy
	movs r0, #0x10
	strh r0, [r1]
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #0x13
	movs r5, #0
	strh r5, [r0]
	ldr r4, _08076A60 @ =gNonGameplayRam
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08076A64 @ =gNextOamSlot
	strb r5, [r0]
	movs r3, #0xa8
	lsls r3, r3, #3
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	adds r2, r4, #0
	bl BitFill
	bl ResetFreeOam
	ldr r1, _08076A68 @ =0x040000D4
	ldr r0, _08076A6C @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08076A70 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _08076A74 @ =gPauseScreenFlag
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #4
	beq _08076A10
	ldr r1, _08076A78 @ =0x06010000
	ldr r2, _08076A7C @ =0x0201C000
	movs r3, #0x80
	lsls r3, r3, #8
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
_08076A10:
	ldr r0, _08076A80 @ =gCurrentArea
	ldrb r2, [r0]
	ldr r3, _08076A84 @ =0x00000212
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, _08076A88 @ =0x03000031
	ldrb r1, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	ldr r0, _08076A8C @ =0x03000032
	ldrb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	strb r5, [r4, #2]
	mov r0, sb
	strb r0, [r4]
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #3
	bne _08076A94
	lsls r0, r2, #0x18
	cmp r0, #0
	bne _08076AA8
	ldr r0, _08076A90 @ =gCurrentRoom
	ldrb r0, [r0]
	cmp r0, #0
	bne _08076AA8
	movs r0, #2
	strb r0, [r4]
	b _08076AA8
	.align 2, 0
_08076A50: .4byte PauseScreenInitVBlank
_08076A54: .4byte 0x04000050
_08076A58: .4byte 0x04000054
_08076A5C: .4byte gWrittenToBldy
_08076A60: .4byte gNonGameplayRam
_08076A64: .4byte gNextOamSlot
_08076A68: .4byte 0x040000D4
_08076A6C: .4byte gOamData
_08076A70: .4byte 0x84000100
_08076A74: .4byte gPauseScreenFlag
_08076A78: .4byte 0x06010000
_08076A7C: .4byte 0x0201C000
_08076A80: .4byte gCurrentArea
_08076A84: .4byte 0x00000212
_08076A88: .4byte 0x03000031
_08076A8C: .4byte 0x03000032
_08076A90: .4byte gCurrentRoom
_08076A94:
	cmp r0, #1
	bne _08076AA2
	movs r0, #2
	strb r0, [r4]
	bl unk_36c4
	b _08076AA8
_08076AA2:
	cmp r0, #4
	beq _08076AA8
	strb r5, [r4]
_08076AA8:
	ldr r4, _08076B04 @ =0x040000D4
	ldr r0, _08076B08 @ =0x085657A8
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08076B0C @ =0x80000030
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08076B10 @ =0x0856F71C
	ldr r1, _08076B14 @ =0x06010000
	bl CallLZ77UncompVram
	ldr r1, _08076B18 @ =0x08561FA8
	ldr r2, _08076B1C @ =0x06008000
	movs r3, #0xe0
	lsls r3, r3, #6
	movs r5, #0x10
	str r5, [sp]
	movs r0, #3
	bl DmaTransfer
	ldr r0, _08076B20 @ =0x08565B48
	str r0, [r4]
	ldr r0, _08076B24 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _08076B28 @ =0x80000100
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08076B2C @ =gNonGameplayRam
	ldrb r0, [r0]
	cmp r0, #0
	bne _08076B40
	ldr r0, _08076B30 @ =0x0856A254
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl CallLZ77UncompVram
	ldr r0, _08076B34 @ =0x08565808
	str r0, [r4]
	ldr r0, _08076B38 @ =0x05000060
	str r0, [r4, #4]
	ldr r0, _08076B3C @ =0x800000D0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	b _08076BAA
	.align 2, 0
_08076B04: .4byte 0x040000D4
_08076B08: .4byte 0x085657A8
_08076B0C: .4byte 0x80000030
_08076B10: .4byte 0x0856F71C
_08076B14: .4byte 0x06010000
_08076B18: .4byte 0x08561FA8
_08076B1C: .4byte 0x06008000
_08076B20: .4byte 0x08565B48
_08076B24: .4byte 0x05000200
_08076B28: .4byte 0x80000100
_08076B2C: .4byte gNonGameplayRam
_08076B30: .4byte 0x0856A254
_08076B34: .4byte 0x08565808
_08076B38: .4byte 0x05000060
_08076B3C: .4byte 0x800000D0
_08076B40:
	cmp r0, #1
	bne _08076BA0
	ldr r0, _08076B60 @ =0x0856C868
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl CallLZ77UncompVram
	ldr r0, _08076B64 @ =gEquipment
	ldrb r1, [r0, #0xc]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08076B68
	movs r3, #2
	b _08076B78
	.align 2, 0
_08076B60: .4byte 0x0856C868
_08076B64: .4byte gEquipment
_08076B68:
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r3, r0, #0x1f
	cmp r3, #0
	beq _08076BAA
_08076B78:
	ldr r2, _08076B90 @ =0x040000D4
	lsls r0, r3, #5
	ldr r1, _08076B94 @ =0x08565D48
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _08076B98 @ =0x05000200
	str r0, [r2, #4]
	ldr r0, _08076B9C @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _08076BAA
	.align 2, 0
_08076B90: .4byte 0x040000D4
_08076B94: .4byte 0x08565D48
_08076B98: .4byte 0x05000200
_08076B9C: .4byte 0x80000010
_08076BA0:
	ldr r0, _08076C44 @ =0x0856DE80
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl CallLZ77UncompVram
_08076BAA:
	ldr r1, _08076C48 @ =gNonGameplayRam
	mov r8, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _08076BD2
	ldr r1, _08076C4C @ =0x040000D4
	ldr r0, _08076C50 @ =0x06009800
	str r0, [r1]
	ldr r0, _08076C54 @ =0x06009400
	str r0, [r1, #4]
	ldr r0, _08076C58 @ =0x80000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08076C5C @ =0x085659A8
	str r0, [r1]
	ldr r0, _08076C60 @ =0x05000060
	str r0, [r1, #4]
	ldr r0, _08076C64 @ =0x800000D0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08076BD2:
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r0, #0
	strh r0, [r1]
	ldr r6, _08076C68 @ =0x02034800
	movs r0, #0xa
	adds r1, r6, #0
	bl GetMinimapData
	ldr r5, _08076C4C @ =0x040000D4
	str r6, [r5]
	ldr r0, _08076C6C @ =0x0600E800
	str r0, [r5, #4]
	ldr r7, _08076C70 @ =0x80000400
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	str r6, [r5]
	ldr r0, _08076C74 @ =0x0600F000
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	str r6, [r5]
	ldr r0, _08076C78 @ =0x0600F800
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _08076C7C @ =gCurrentArea
	ldrb r3, [r0]
	ldr r0, _08076C80 @ =0x02034000
	str r0, [r5]
	ldr r0, _08076C84 @ =0x0600E000
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	ldr r0, _08076C88 @ =0x085742E8
	ldr r4, _08076C8C @ =0x0200F800
	adds r1, r4, #0
	bl CallLZ77UncompVram
	str r4, [r5]
	ldr r0, _08076C90 @ =0x0600C000
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _08076CC8
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _08076C98
	ldr r0, _08076C94 @ =0x08573EA0
	adds r1, r6, #0
	bl CallLZ77UncompVram
	b _08076CA0
	.align 2, 0
_08076C44: .4byte 0x0856DE80
_08076C48: .4byte gNonGameplayRam
_08076C4C: .4byte 0x040000D4
_08076C50: .4byte 0x06009800
_08076C54: .4byte 0x06009400
_08076C58: .4byte 0x80000200
_08076C5C: .4byte 0x085659A8
_08076C60: .4byte 0x05000060
_08076C64: .4byte 0x800000D0
_08076C68: .4byte 0x02034800
_08076C6C: .4byte 0x0600E800
_08076C70: .4byte 0x80000400
_08076C74: .4byte 0x0600F000
_08076C78: .4byte 0x0600F800
_08076C7C: .4byte gCurrentArea
_08076C80: .4byte 0x02034000
_08076C84: .4byte 0x0600E000
_08076C88: .4byte 0x085742E8
_08076C8C: .4byte 0x0200F800
_08076C90: .4byte 0x0600C000
_08076C94: .4byte 0x08573EA0
_08076C98:
	ldr r0, _08076CB4 @ =0x085748AC
	adds r1, r6, #0
	bl CallLZ77UncompVram
_08076CA0:
	ldr r1, _08076CB8 @ =0x040000D4
	ldr r0, _08076CBC @ =0x02034800
	str r0, [r1]
	ldr r0, _08076CC0 @ =0x0600C800
	str r0, [r1, #4]
	ldr r0, _08076CC4 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08076CE6
	.align 2, 0
_08076CB4: .4byte 0x085748AC
_08076CB8: .4byte 0x040000D4
_08076CBC: .4byte 0x02034800
_08076CC0: .4byte 0x0600C800
_08076CC4: .4byte 0x80000400
_08076CC8:
	cmp r0, #1
	bne _08076CD4
	ldr r0, _08076CD0 @ =0x08574D48
	b _08076CD6
	.align 2, 0
_08076CD0: .4byte 0x08574D48
_08076CD4:
	ldr r0, _08076D10 @ =0x085753E8
_08076CD6:
	adds r1, r6, #0
	bl CallLZ77UncompVram
	str r6, [r5]
	ldr r0, _08076D14 @ =0x0600D800
	str r0, [r5, #4]
	str r7, [r5, #8]
	ldr r0, [r5, #8]
_08076CE6:
	ldr r0, _08076D18 @ =gNonGameplayRam
	ldrb r0, [r0]
	cmp r0, #0
	bne _08076D38
	ldr r0, _08076D1C @ =0x085740FC
	ldr r4, _08076D20 @ =0x02034800
	adds r1, r4, #0
	bl CallLZ77UncompVram
	ldr r1, _08076D24 @ =0x040000D4
	str r4, [r1]
	ldr r0, _08076D28 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08076D2C @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08076D30 @ =0x085745A8
	ldr r1, _08076D34 @ =0x02010000
	bl CallLZ77UncompVram
	b _08076D74
	.align 2, 0
_08076D10: .4byte 0x085753E8
_08076D14: .4byte 0x0600D800
_08076D18: .4byte gNonGameplayRam
_08076D1C: .4byte 0x085740FC
_08076D20: .4byte 0x02034800
_08076D24: .4byte 0x040000D4
_08076D28: .4byte 0x0600D000
_08076D2C: .4byte 0x80000400
_08076D30: .4byte 0x085745A8
_08076D34: .4byte 0x02010000
_08076D38:
	ldr r0, _08076D50 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _08076D5C
	ldr r0, _08076D54 @ =0x08573DA4
	ldr r1, _08076D58 @ =0x02034800
	bl CallLZ77UncompVram
	b _08076D64
	.align 2, 0
_08076D50: .4byte gPauseScreenFlag
_08076D54: .4byte 0x08573DA4
_08076D58: .4byte 0x02034800
_08076D5C:
	ldr r0, _08076DBC @ =0x08573DA4
	ldr r1, _08076DC0 @ =0x02034800
	bl CallLZ77UncompVram
_08076D64:
	ldr r1, _08076DC4 @ =0x040000D4
	ldr r0, _08076DC0 @ =0x02034800
	str r0, [r1]
	ldr r0, _08076DC8 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08076DCC @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08076D74:
	ldr r0, _08076DD0 @ =gCurrentArea
	ldrb r0, [r0]
	ldr r1, _08076DC0 @ =0x02034800
	bl GetMinimapData
	movs r1, #0
	ldr r2, _08076DD4 @ =gBackgroundPositions
	adds r0, r2, #0
	movs r3, #3
_08076D86:
	strh r1, [r0]
	strh r1, [r0, #2]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bge _08076D86
	ldr r1, _08076DD8 @ =gNonGameplayRam
	movs r0, #0
	strb r0, [r1, #7]
	strb r0, [r1, #9]
	strb r0, [r1, #6]
	strb r0, [r1, #8]
	ldr r0, _08076DDC @ =0x0879BE88
	ldr r0, [r0]
	str r0, [r1, #0x28]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #6]
	movs r0, #3
	strb r0, [r1, #1]
	ldrb r0, [r1]
	adds r5, r1, #0
	cmp r0, #0
	beq _08076DE0
	movs r0, #1
	b _08076DF6
	.align 2, 0
_08076DBC: .4byte 0x08573DA4
_08076DC0: .4byte 0x02034800
_08076DC4: .4byte 0x040000D4
_08076DC8: .4byte 0x0600D000
_08076DCC: .4byte 0x80000400
_08076DD0: .4byte gCurrentArea
_08076DD4: .4byte gBackgroundPositions
_08076DD8: .4byte gNonGameplayRam
_08076DDC: .4byte 0x0879BE88
_08076DE0:
	ldr r0, _08076DF0 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	bne _08076DF4
	movs r0, #0
	b _08076DF6
	.align 2, 0
_08076DF0: .4byte gPauseScreenFlag
_08076DF4:
	movs r0, #2
_08076DF6:
	strb r0, [r5, #1]
	ldrb r0, [r5]
	cmp r0, #0
	beq _08076E4C
	bl EventCheckSetNavigationRoomEvent
	cmp r0, #0
	beq _08076E28
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #4
	strb r0, [r1]
	ldr r4, _08076E20 @ =gCurrentArea
	ldrb r0, [r4]
	ldr r1, _08076E24 @ =0x02034000
	bl GetMinimapData
	ldrb r0, [r4]
	bl MinimapSetVisitedTilesAndCollectedItems
	b _08076E30
	.align 2, 0
_08076E20: .4byte gCurrentArea
_08076E24: .4byte 0x02034000
_08076E28:
	adds r1, r5, #0
	adds r1, #0x28
	movs r0, #0xa
	strb r0, [r1]
_08076E30:
	ldr r0, _08076E5C @ =gEventCounter
	ldrb r0, [r0]
	cmp r0, #0x5b
	bhi _08076E4C
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, _08076E60 @ =0x040000D4
	add r3, sp, #4
	str r3, [r1]
	ldr r0, _08076E64 @ =0x06017C00
	str r0, [r1, #4]
	ldr r0, _08076E68 @ =0x85000010
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08076E4C:
	ldr r0, _08076E6C @ =gNonGameplayRam
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _08076E70
	bl PauseDebugDrawEverything
	b _08076E74
	.align 2, 0
_08076E5C: .4byte gEventCounter
_08076E60: .4byte 0x040000D4
_08076E64: .4byte 0x06017C00
_08076E68: .4byte 0x85000010
_08076E6C: .4byte gNonGameplayRam
_08076E70:
	bl StatusScreenDrawEverything
_08076E74:
	movs r0, #0
	bl unk_75988
	bl ProcessPauseScreenText
	bl ProcessEasySleepText
	bl PauseScreenSetupOam
	bl NavigationConversationGetCurrentConversation
	bl NavigationConversationLoadPopUpGraphics
	bl NavigationConversationLoadSpecialGraphics
	movs r0, #0xff
	bl unk_77840
	bl unk_7ce6c
	ldr r2, _08076EF8 @ =0x04000010
	ldr r1, _08076EFC @ =gBackgroundPositions
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #2]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #4]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #6]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #8]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0xa]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0xc]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0xe]
	strh r0, [r2]
	ldr r5, _08076F00 @ =gWrittenToBldy
	movs r1, #0
	strh r1, [r5]
	ldr r4, _08076F04 @ =gWrittenToBldalpha_Evb
	strh r1, [r4]
	ldr r3, _08076F08 @ =gWrittenToBldalpha_Eva
	movs r2, #0x10
	strh r2, [r3]
	ldr r0, _08076F0C @ =gNonGameplayRam
	ldrb r0, [r0]
	cmp r0, #0
	beq _08076F18
	strh r1, [r4]
	strh r1, [r3]
	ldr r1, _08076F10 @ =0x04000050
	ldr r4, _08076F14 @ =0x00003F7F
	adds r0, r4, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0
	b _08076F1E
	.align 2, 0
_08076EF8: .4byte 0x04000010
_08076EFC: .4byte gBackgroundPositions
_08076F00: .4byte gWrittenToBldy
_08076F04: .4byte gWrittenToBldalpha_Evb
_08076F08: .4byte gWrittenToBldalpha_Eva
_08076F0C: .4byte gNonGameplayRam
_08076F10: .4byte 0x04000050
_08076F14: .4byte 0x00003F7F
_08076F18:
	strh r2, [r5]
	ldr r1, _08076F3C @ =0x04000050
	movs r0, #0xff
_08076F1E:
	strh r0, [r1]
	ldr r1, _08076F40 @ =0x04000040
	movs r0, #0xf0
	strh r0, [r1]
	ldr r0, _08076F44 @ =gNonGameplayRam
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _08076F4C
	ldr r1, _08076F48 @ =0x0400004A
	movs r0, #0x37
	strb r0, [r1]
	subs r1, #1
	movs r0, #0x3f
	b _08076F56
	.align 2, 0
_08076F3C: .4byte 0x04000050
_08076F40: .4byte 0x04000040
_08076F44: .4byte gNonGameplayRam
_08076F48: .4byte 0x0400004A
_08076F4C:
	ldr r1, _08076FDC @ =0x0400004A
	movs r0, #0x35
	strb r0, [r1]
	subs r1, #1
	movs r0, #0x3d
_08076F56:
	strb r0, [r1]
	ldr r1, _08076FE0 @ =0x04000048
	movs r0, #0x3f
	strb r0, [r1]
	adds r4, r5, #0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	movs r3, #0
	cmp r0, #1
	beq _08076F6E
	movs r3, #0xa0
_08076F6E:
	ldr r1, _08076FE4 @ =0x04000044
	lsls r0, r3, #8
	movs r2, #0xa0
	orrs r0, r2
	strh r0, [r1]
	subs r1, #2
	movs r0, #0xf0
	strh r0, [r1]
	ldr r0, _08076FE8 @ =0x04000046
	strh r2, [r0]
	ldr r0, _08076FEC @ =gWrittenToMosaic_L
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08076FF0 @ =0x0400004C
	strh r1, [r0]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08077018
	ldr r1, _08076FF4 @ =0x0400000A
	ldr r2, _08076FF8 @ =0x00001B03
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r3, _08076FFC @ =0x0000DC49
	adds r0, r3, #0
	strh r0, [r1]
	subs r1, #6
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r3, r4, r0
	movs r2, #0xbe
	lsls r2, r2, #7
	strh r2, [r3]
	ldr r0, _08077000 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08077008
	adds r1, #4
	ldr r4, _08077004 @ =0x00001A0A
	adds r0, r4, #0
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r0, r2, #0
	eors r0, r1
	strh r0, [r3]
	b _08077046
	.align 2, 0
_08076FDC: .4byte 0x0400004A
_08076FE0: .4byte 0x04000048
_08076FE4: .4byte 0x04000044
_08076FE8: .4byte 0x04000046
_08076FEC: .4byte gWrittenToMosaic_L
_08076FF0: .4byte 0x0400004C
_08076FF4: .4byte 0x0400000A
_08076FF8: .4byte 0x00001B03
_08076FFC: .4byte 0x0000DC49
_08077000: .4byte gPauseScreenFlag
_08077004: .4byte 0x00001A0A
_08077008:
	ldr r1, _08077010 @ =0x0400000C
	ldr r2, _08077014 @ =0x00001A0A
	adds r0, r2, #0
	b _08077044
	.align 2, 0
_08077010: .4byte 0x0400000C
_08077014: .4byte 0x00001A0A
_08077018:
	ldr r1, _0807706C @ =0x0400000E
	ldr r3, _08077070 @ =0x0000DC4B
	adds r0, r3, #0
	strh r0, [r1]
	subs r1, #2
	ldr r4, _08077074 @ =0x00001A02
	adds r0, r4, #0
	strh r0, [r1]
	subs r1, #4
	ldr r2, _08077078 @ =0x00001801
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r3, #0xc8
	lsls r3, r3, #5
	adds r0, r3, #0
	strh r0, [r1]
	movs r4, #0x9a
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r0, #0xfc
	lsls r0, r0, #7
_08077044:
	strh r0, [r1]
_08077046:
	ldr r0, _0807707C @ =PauseScreenVBLank
	bl CallbackSetVBlank
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r0, _08077080 @ =gNonGameplayRam
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	mov r0, sb
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807706C: .4byte 0x0400000E
_08077070: .4byte 0x0000DC4B
_08077074: .4byte 0x00001A02
_08077078: .4byte 0x00001801
_0807707C: .4byte PauseScreenVBLank
_08077080: .4byte gNonGameplayRam

	thumb_func_start GetMinimapData
GetMinimapData: @ 0x08077084
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0807709A
	ldr r0, _080770AC @ =gEventCounter
	ldrb r0, [r0]
	cmp r0, #0x5d
	bls _0807709A
	movs r1, #9
_0807709A:
	ldr r0, _080770B0 @ =0x0879BE5C
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r1, r2, #0
	bl CallLZ77UncompVram
	pop {r0}
	bx r0
	.align 2, 0
_080770AC: .4byte gEventCounter
_080770B0: .4byte 0x0879BE5C

	thumb_func_start PauseScreenCallCurrentHandler
PauseScreenCallCurrentHandler: @ 0x080770B4
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _080770E8 @ =gNonGameplayRam
	adds r5, r4, #0
	adds r5, #0x28
	ldrb r0, [r5]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080770CE
	bl CheckForMaintainedInput
_080770CE:
	ldrb r0, [r4, #6]
	adds r0, #1
	strb r0, [r4, #6]
	ldrb r0, [r5]
	cmp r0, #0xc
	bls _080770DC
	b _08077262
_080770DC:
	lsls r0, r0, #2
	ldr r1, _080770EC @ =_080770F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080770E8: .4byte gNonGameplayRam
_080770EC: .4byte _080770F0
_080770F0: @ jump table
	.4byte _08077124 @ case 0
	.4byte _0807714A @ case 1
	.4byte _08077136 @ case 2
	.4byte _08077166 @ case 3
	.4byte _08077196 @ case 4
	.4byte _080771AC @ case 5
	.4byte _080771C4 @ case 6
	.4byte _080771DC @ case 7
	.4byte _080771E2 @ case 8
	.4byte _08077208 @ case 9
	.4byte _080771E2 @ case 10
	.4byte _0807722C @ case 11
	.4byte _0807724C @ case 12
_08077124:
	ldr r2, _0807713C @ =gChangedInput
	ldr r0, _08077140 @ =gButtonAssignments
	ldrh r0, [r0, #6]
	movs r1, #2
	orrs r0, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08077144
_08077136:
	movs r6, #1
	b _08077262
	.align 2, 0
_0807713C: .4byte gChangedInput
_08077140: .4byte gButtonAssignments
_08077144:
	bl MapScreenHandler
	b _08077262
_0807714A:
	ldr r0, _0807715C @ =gNonGameplayRam
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _08077160
	bl PauseScreenMoveDebugCursor
	bl PauseDebugHandler
	b _08077262
	.align 2, 0
_0807715C: .4byte gNonGameplayRam
_08077160:
	bl StatusScreenHandler
	b _08077262
_08077166:
	ldr r4, _0807717C @ =gNonGameplayRam
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08077180
	bl unk_7c630
	b _08077262
	.align 2, 0
_0807717C: .4byte gNonGameplayRam
_08077180:
	bl NavigationConversationUpdatePopUp
	bl NavigationConversationHandler
	cmp r0, #0
	beq _08077262
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #9
	strb r0, [r1]
	b _08077262
_08077196:
	bl PauseScreenMapDownload
	cmp r0, #0
	beq _08077262
	ldr r0, _080771A8 @ =gNonGameplayRam
	adds r0, #0x28
	movs r1, #8
	strb r1, [r0]
	b _08077262
	.align 2, 0
_080771A8: .4byte gNonGameplayRam
_080771AC:
	bl EasySleepMenuHandler
	cmp r0, #0
	beq _08077262
	ldr r0, _080771C0 @ =gNonGameplayRam
	adds r0, #0x28
	movs r1, #0xc
	strb r1, [r0]
	b _08077262
	.align 2, 0
_080771C0: .4byte gNonGameplayRam
_080771C4:
	bl PauseDebugWindowAppearing
	cmp r0, #0
	beq _08077262
	ldr r1, _080771D8 @ =gNonGameplayRam
	adds r3, r1, #0
	adds r3, #0x28
	movs r2, #0
	movs r0, #1
	b _0807723E
	.align 2, 0
_080771D8: .4byte gNonGameplayRam
_080771DC:
	bl PauseDebugWindowDisappearing
	b _08077250
_080771E2:
	ldr r0, _08077204 @ =gNonGameplayRam
	adds r3, r0, #0
	adds r3, #0x28
	movs r2, #0
	movs r1, #3
	strb r1, [r3]
	movs r1, #0
	strh r2, [r0, #0xc]
	strh r2, [r0, #0xe]
	strh r2, [r0, #0x10]
	strh r2, [r0, #0x12]
	strh r2, [r0, #0x14]
	strb r1, [r0, #8]
	strb r1, [r0, #9]
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	b _0807725E
	.align 2, 0
_08077204: .4byte gNonGameplayRam
_08077208:
	ldr r0, _0807721C @ =gNonGameplayRam
	ldrb r2, [r0]
	cmp r2, #0
	beq _08077220
	adds r1, r0, #0
	adds r1, #0x28
	movs r0, #2
	strb r0, [r1]
	b _08077262
	.align 2, 0
_0807721C: .4byte gNonGameplayRam
_08077220:
	adds r0, #0x28
	strb r2, [r0]
	movs r0, #4
	bl unk_77840
	b _08077262
_0807722C:
	bl EasySleepMenuInit
	cmp r0, #0
	beq _08077262
	ldr r1, _08077248 @ =gNonGameplayRam
	adds r3, r1, #0
	adds r3, #0x28
	movs r2, #0
	movs r0, #5
_0807723E:
	strb r0, [r3]
	strb r2, [r1, #7]
	strb r2, [r1, #6]
	b _08077262
	.align 2, 0
_08077248: .4byte gNonGameplayRam
_0807724C:
	bl EasySleepMenuQuit
_08077250:
	cmp r0, #0
	beq _08077262
	ldr r0, _0807726C @ =gNonGameplayRam
	adds r2, r0, #0
	adds r2, #0x28
	movs r1, #0
	strb r1, [r2]
_0807725E:
	strb r1, [r0, #7]
	strb r1, [r0, #6]
_08077262:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807726C: .4byte gNonGameplayRam

	thumb_func_start PauseScreenMoveDebugCursor
PauseScreenMoveDebugCursor: @ 0x08077270
	push {r4, lr}
	movs r2, #0
	ldr r0, _080772AC @ =gButtonInput
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0807728A
	ldr r0, _080772B0 @ =gNonGameplayRam
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _0807728A
	movs r2, #1
_0807728A:
	cmp r2, #0
	beq _0807730E
	ldr r1, _080772B4 @ =gChangedInput
	ldrh r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _080772B8
	ldr r2, _080772B0 @ =gNonGameplayRam
	ldrh r3, [r2, #0x2c]
	movs r4, #0x2c
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _080772D2
	adds r0, r3, #0
	subs r0, #8
	b _080772D0
	.align 2, 0
_080772AC: .4byte gButtonInput
_080772B0: .4byte gNonGameplayRam
_080772B4: .4byte gChangedInput
_080772B8:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _080772D2
	ldr r2, _080772F0 @ =gNonGameplayRam
	ldrh r3, [r2, #0x2c]
	movs r4, #0x2c
	ldrsh r0, [r2, r4]
	cmp r0, #0x8f
	bgt _080772D2
	adds r0, r3, #0
	adds r0, #8
_080772D0:
	strh r0, [r2, #0x2c]
_080772D2:
	ldrh r1, [r1]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080772F4
	ldr r1, _080772F0 @ =gNonGameplayRam
	ldrh r2, [r1, #0x2e]
	movs r3, #0x2e
	ldrsh r0, [r1, r3]
	cmp r0, #0xe7
	bgt _0807730E
	adds r0, r2, #0
	adds r0, #8
	b _0807730C
	.align 2, 0
_080772F0: .4byte gNonGameplayRam
_080772F4:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807730E
	ldr r1, _08077314 @ =gNonGameplayRam
	ldrh r2, [r1, #0x2e]
	movs r4, #0x2e
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _0807730E
	adds r0, r2, #0
	subs r0, #8
_0807730C:
	strh r0, [r1, #0x2e]
_0807730E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08077314: .4byte gNonGameplayRam

	thumb_func_start PauseScreenMoveBackgroundToXPosition
PauseScreenMoveBackgroundToXPosition: @ 0x08077318
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r7, #0
	ldr r1, _08077344 @ =gBackgroundPositions
	lsls r0, r5, #2
	adds r3, r0, r1
	ldrh r2, [r3]
	movs r6, #1
	cmp r2, r4
	bls _08077334
	subs r6, #2
_08077334:
	ldr r0, _08077348 @ =gNonGameplayRam
	ldrb r0, [r0, #6]
	adds r0, #4
	cmp r0, #0x1f
	bgt _0807734C
	muls r0, r6, r0
	b _0807734E
	.align 2, 0
_08077344: .4byte gBackgroundPositions
_08077348: .4byte gNonGameplayRam
_0807734C:
	lsls r0, r6, #5
_0807734E:
	adds r0, r2, r0
	strh r0, [r3]
	cmp r6, #0
	ble _08077364
	lsls r0, r5, #2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r4
	blo _0807737A
	strh r4, [r1]
	b _08077378
_08077364:
	lsls r0, r5, #2
	adds r1, r0, r1
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, r4
	bgt _0807737A
	subs r0, r4, r0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_08077378:
	movs r7, #1
_0807737A:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start PauseScreenMoveBackgroundToYPosition
PauseScreenMoveBackgroundToYPosition: @ 0x08077384
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #0
	mov ip, r0
	ldr r1, _080773B4 @ =gBackgroundPositions
	lsls r0, r5, #2
	adds r3, r0, r1
	ldrh r2, [r3, #2]
	movs r4, #1
	adds r7, r1, #0
	cmp r2, r6
	bls _080773A4
	subs r4, #2
_080773A4:
	ldr r0, _080773B8 @ =gNonGameplayRam
	ldrb r0, [r0, #6]
	adds r0, #4
	cmp r0, #0x1f
	bgt _080773BC
	muls r0, r4, r0
	b _080773BE
	.align 2, 0
_080773B4: .4byte gBackgroundPositions
_080773B8: .4byte gNonGameplayRam
_080773BC:
	lsls r0, r4, #5
_080773BE:
	adds r0, r2, r0
	strh r0, [r3, #2]
	cmp r4, #0
	ble _080773D6
	lsls r0, r5, #2
	adds r1, r0, r7
	ldrh r1, [r1, #2]
	cmp r1, r6
	blo _080773E6
	movs r1, #1
	mov ip, r1
	b _080773EC
_080773D6:
	lsls r0, r5, #2
	adds r1, r0, r7
	movs r2, #2
	ldrsh r1, [r1, r2]
	cmp r1, r6
	bgt _080773E6
	movs r1, #1
	mov ip, r1
_080773E6:
	mov r2, ip
	cmp r2, #0
	beq _080773F0
_080773EC:
	adds r0, r0, r7
	strh r6, [r0, #2]
_080773F0:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start PauseScreenSetPauseDebugWindow
PauseScreenSetPauseDebugWindow: @ 0x080773F8
	push {lr}
	ldr r0, _08077418 @ =gBackgroundPositions
	ldrh r1, [r0, #6]
	movs r0, #0x80
	lsls r0, r0, #2
	subs r1, r0, r1
	cmp r1, #0xa0
	ble _0807740A
	movs r1, #0xa0
_0807740A:
	ldr r0, _0807741C @ =0x04000044
	lsls r1, r1, #8
	movs r2, #0xa0
	orrs r1, r2
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08077418: .4byte gBackgroundPositions
_0807741C: .4byte 0x04000044

	thumb_func_start PauseDebugWindowAppearing
PauseDebugWindowAppearing: @ 0x08077420
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08077438 @ =gNonGameplayRam
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _08077454
	cmp r0, #1
	bgt _0807743C
	cmp r0, #0
	beq _08077442
	b _08077496
	.align 2, 0
_08077438: .4byte gNonGameplayRam
_0807743C:
	cmp r0, #2
	beq _08077462
	b _08077496
_08077442:
	movs r0, #0x80
	lsls r0, r0, #2
	bl SoundPlay
	movs r0, #0x10
	movs r1, #0x29
	bl UpdateMenuOamDataId
	b _0807745A
_08077454:
	ldrb r0, [r4, #6]
	cmp r0, #0x10
	bls _08077496
_0807745A:
	movs r0, #2
	strb r0, [r4, #7]
	strb r5, [r4, #6]
	b _08077496
_08077462:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #1
	bl PauseScreenMoveBackgroundToYPosition
	cmp r0, #0
	beq _08077492
	movs r0, #0x10
	movs r1, #0x28
	bl UpdateMenuOamDataId
	movs r0, #0x11
	movs r1, #0x2a
	bl UpdateMenuOamDataId
	movs r0, #3
	bl unk_77840
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08077490
	bl PauseDebugSetupCursor
_08077490:
	movs r5, #1
_08077492:
	bl PauseScreenSetPauseDebugWindow
_08077496:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start PauseDebugWindowDisappearing
PauseDebugWindowDisappearing: @ 0x080774A0
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _080774B8 @ =gNonGameplayRam
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _080774D4
	cmp r0, #1
	bgt _080774BC
	cmp r0, #0
	beq _080774C2
	b _080774F6
	.align 2, 0
_080774B8: .4byte gNonGameplayRam
_080774BC:
	cmp r0, #2
	beq _080774E2
	b _080774F6
_080774C2:
	ldr r0, _080774D0 @ =0x00000201
	bl SoundPlay
	movs r0, #4
	bl unk_77840
	b _080774DA
	.align 2, 0
_080774D0: .4byte 0x00000201
_080774D4:
	ldrb r0, [r4, #6]
	cmp r0, #4
	bls _080774F6
_080774DA:
	movs r0, #2
	strb r0, [r4, #7]
	strb r5, [r4, #6]
	b _080774F6
_080774E2:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #1
	bl PauseScreenMoveBackgroundToYPosition
	cmp r0, #0
	beq _080774F2
	movs r5, #1
_080774F2:
	bl PauseScreenSetPauseDebugWindow
_080774F6:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EasySleepMenuInit
EasySleepMenuInit: @ 0x08077500
	push {r4, r5, lr}
	sub sp, #4
	movs r5, #0
	ldr r0, _0807751C @ =gNonGameplayRam
	ldrb r1, [r0, #7]
	adds r4, r0, #0
	cmp r1, #8
	bls _08077512
	b _080776FC
_08077512:
	lsls r0, r1, #2
	ldr r1, _08077520 @ =_08077524
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807751C: .4byte gNonGameplayRam
_08077520: .4byte _08077524
_08077524: @ jump table
	.4byte _08077548 @ case 0
	.4byte _08077564 @ case 1
	.4byte _08077588 @ case 2
	.4byte _080775A0 @ case 3
	.4byte _080775F8 @ case 4
	.4byte _08077658 @ case 5
	.4byte _08077668 @ case 6
	.4byte _08077684 @ case 7
	.4byte _080776EE @ case 8
_08077548:
	ldr r0, _08077560 @ =0x00000202
	bl SoundPlay
	movs r0, #0x11
	movs r1, #0x2b
	bl UpdateMenuOamDataId
	movs r0, #3
	bl unk_77840
	b _08077702
	.align 2, 0
_08077560: .4byte 0x00000202
_08077564:
	ldr r1, _08077578 @ =0x040000D4
	ldr r0, _0807757C @ =0x02010000
	str r0, [r1]
	ldr r0, _08077580 @ =0x0600C000
	str r0, [r1, #4]
	ldr r0, _08077584 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08077702
	.align 2, 0
_08077578: .4byte 0x040000D4
_0807757C: .4byte 0x02010000
_08077580: .4byte 0x0600C000
_08077584: .4byte 0x80000400
_08077588:
	ldr r1, _08077598 @ =0x04000050
	ldr r2, _0807759C @ =0x00003FFE
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x10
	strh r0, [r1]
	b _08077702
	.align 2, 0
_08077598: .4byte 0x04000050
_0807759C: .4byte 0x00003FFE
_080775A0:
	ldr r0, _080775D0 @ =0x040000D4
	ldr r1, _080775D4 @ =0x0200F000
	str r1, [r0]
	ldr r1, _080775D8 @ =0x0200D380
	str r1, [r0, #4]
	ldr r2, _080775DC @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080775E0 @ =0x0200F400
	str r1, [r0]
	ldr r1, _080775E4 @ =0x0200D780
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080775E8 @ =0x0200F080
	str r1, [r0]
	ldr r1, _080775EC @ =0x0200DB80
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _080775F0 @ =0x0200F480
	str r1, [r0]
	ldr r1, _080775F4 @ =0x0200DF80
	b _08077626
	.align 2, 0
_080775D0: .4byte 0x040000D4
_080775D4: .4byte 0x0200F000
_080775D8: .4byte 0x0200D380
_080775DC: .4byte 0x80000040
_080775E0: .4byte 0x0200F400
_080775E4: .4byte 0x0200D780
_080775E8: .4byte 0x0200F080
_080775EC: .4byte 0x0200DB80
_080775F0: .4byte 0x0200F480
_080775F4: .4byte 0x0200DF80
_080775F8:
	ldr r0, _08077630 @ =0x040000D4
	ldr r1, _08077634 @ =0x0200F1C0
	str r1, [r0]
	ldr r1, _08077638 @ =0x0200E380
	str r1, [r0, #4]
	ldr r2, _0807763C @ =0x80000040
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08077640 @ =0x0200F5C0
	str r1, [r0]
	ldr r1, _08077644 @ =0x0200E780
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08077648 @ =0x0200F240
	str r1, [r0]
	ldr r1, _0807764C @ =0x0200EB80
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08077650 @ =0x0200F640
	str r1, [r0]
	ldr r1, _08077654 @ =0x0200EF80
_08077626:
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	b _08077702
	.align 2, 0
_08077630: .4byte 0x040000D4
_08077634: .4byte 0x0200F1C0
_08077638: .4byte 0x0200E380
_0807763C: .4byte 0x80000040
_08077640: .4byte 0x0200F5C0
_08077644: .4byte 0x0200E780
_08077648: .4byte 0x0200F240
_0807764C: .4byte 0x0200EB80
_08077650: .4byte 0x0200F640
_08077654: .4byte 0x0200EF80
_08077658:
	ldr r1, _08077660 @ =0x0200D000
	ldr r2, _08077664 @ =0x06006000
	b _0807766C
	.align 2, 0
_08077660: .4byte 0x0200D000
_08077664: .4byte 0x06006000
_08077668:
	ldr r1, _0807767C @ =0x0200E000
	ldr r2, _08077680 @ =0x06007000
_0807766C:
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	b _08077702
	.align 2, 0
_0807767C: .4byte 0x0200E000
_08077680: .4byte 0x06007000
_08077684:
	ldrb r0, [r4, #6]
	cmp r0, #1
	bls _080776FC
	movs r0, #0
	strb r0, [r4, #6]
	ldr r1, _080776D8 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _080776DC
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _080776FC
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #2
	bl UpdateMenuOamDataId
	movs r0, #0x8c
	strh r0, [r4, #0x3a]
	movs r0, #0x44
	strh r0, [r4, #0x38]
	adds r2, r4, #0
	adds r2, #0x43
	ldrb r1, [r2]
	subs r0, #0x51
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	b _080776FC
	.align 2, 0
_080776D8: .4byte gWrittenToBldy
_080776DC:
	movs r0, #0x10
	movs r1, #0x28
	bl UpdateMenuOamDataId
	movs r0, #0x11
	movs r1, #0x2a
	bl UpdateMenuOamDataId
	b _08077702
_080776EE:
	ldr r0, _08077718 @ =gDisableSoftReset
	movs r1, #1
	strb r1, [r0]
	movs r5, #1
	movs r0, #0
	strb r0, [r4, #7]
	strb r0, [r4, #6]
_080776FC:
	movs r0, #0
	cmp r0, #0
	beq _0807770E
_08077702:
	ldr r0, _0807771C @ =gNonGameplayRam
	ldrb r1, [r0, #7]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #7]
	strb r2, [r0, #6]
_0807770E:
	adds r0, r5, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08077718: .4byte gDisableSoftReset
_0807771C: .4byte gNonGameplayRam

	thumb_func_start EasySleepMenuQuit
EasySleepMenuQuit: @ 0x08077720
	push {r4, r5, r6, lr}
	sub sp, #4
	movs r5, #0
	ldr r0, _0807773C @ =gNonGameplayRam
	ldrb r1, [r0, #7]
	adds r4, r0, #0
	cmp r1, #6
	bls _08077732
	b _08077820
_08077732:
	lsls r0, r1, #2
	ldr r1, _08077740 @ =_08077744
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807773C: .4byte gNonGameplayRam
_08077740: .4byte _08077744
_08077744: @ jump table
	.4byte _08077760 @ case 0
	.4byte _0807776C @ case 1
	.4byte _08077824 @ case 2
	.4byte _080777B8 @ case 3
	.4byte _080777D0 @ case 4
	.4byte _080777F4 @ case 5
	.4byte _08077818 @ case 6
_08077760:
	ldr r1, _08077768 @ =gDisableSoftReset
	movs r0, #0
	strb r0, [r1]
	b _08077824
	.align 2, 0
_08077768: .4byte gDisableSoftReset
_0807776C:
	ldrb r0, [r4, #6]
	cmp r0, #1
	bls _08077820
	movs r0, #0
	strb r0, [r4, #6]
	ldr r1, _080777B0 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0
	beq _08077824
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _08077820
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r1, [r2]
	ldr r0, _080777B4 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #0
	bl UpdateMenuOamDataId
	adds r2, r4, #0
	adds r2, #0x43
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _08077820
	.align 2, 0
_080777B0: .4byte gWrittenToBldy
_080777B4: .4byte 0x0000FEFF
_080777B8:
	ldr r2, _080777CC @ =0x06006000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x20
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	bl BitFill
	b _08077824
	.align 2, 0
_080777CC: .4byte 0x06006000
_080777D0:
	ldr r1, _080777E4 @ =0x040000D4
	ldr r0, _080777E8 @ =0x0200F800
	str r0, [r1]
	ldr r0, _080777EC @ =0x0600C000
	str r0, [r1, #4]
	ldr r0, _080777F0 @ =0x80000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08077824
	.align 2, 0
_080777E4: .4byte 0x040000D4
_080777E8: .4byte 0x0200F800
_080777EC: .4byte 0x0600C000
_080777F0: .4byte 0x80000400
_080777F4:
	ldr r1, _08077810 @ =0x04000050
	movs r2, #0xfc
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08077814 @ =0x0000040C
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #4
	bl unk_77840
	b _08077824
	.align 2, 0
_08077810: .4byte 0x04000050
_08077814: .4byte 0x0000040C
_08077818:
	movs r5, #1
	movs r0, #0
	strb r0, [r4, #7]
	strb r0, [r4, #6]
_08077820:
	cmp r6, #0
	beq _08077830
_08077824:
	ldr r0, _0807783C @ =gNonGameplayRam
	ldrb r1, [r0, #7]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #7]
	strb r2, [r0, #6]
_08077830:
	adds r0, r5, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0807783C: .4byte gNonGameplayRam

	thumb_func_start unk_77840
unk_77840: @ 0x08077840
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r6, #0
	ldr r1, _08077860 @ =gNonGameplayRam
	ldrb r0, [r1, #1]
	adds r5, r1, #0
	cmp r0, #0xb
	bls _08077856
	b _08077ADA
_08077856:
	lsls r0, r0, #2
	ldr r1, _08077864 @ =_08077868
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077860: .4byte gNonGameplayRam
_08077864: .4byte _08077868
_08077868: @ jump table
	.4byte _08077898 @ case 0
	.4byte _08077ADA @ case 1
	.4byte _08077ADA @ case 2
	.4byte _080778C0 @ case 3
	.4byte _080778EC @ case 4
	.4byte _08077944 @ case 5
	.4byte _0807796A @ case 6
	.4byte _080779A4 @ case 7
	.4byte _080779DC @ case 8
	.4byte _08077A24 @ case 9
	.4byte _08077A78 @ case 10
	.4byte _08077AB0 @ case 11
_08077898:
	movs r6, #5
	ldr r1, _080778B4 @ =0x0200C000
	ldr r2, _080778B8 @ =0x06007000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	ldr r1, _080778BC @ =gNonGameplayRam
	movs r0, #8
	strb r0, [r1, #1]
	b _08077ADA
	.align 2, 0
_080778B4: .4byte 0x0200C000
_080778B8: .4byte 0x06007000
_080778BC: .4byte gNonGameplayRam
_080778C0:
	movs r6, #1
	adds r1, r5, #0
	adds r1, #0xd1
	movs r0, #9
	strb r0, [r1]
	adds r1, #0xc
	strb r0, [r1]
	ldr r1, _080778E4 @ =0x0200C000
	ldr r2, _080778E8 @ =0x06007000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	movs r0, #4
	b _08077AD8
	.align 2, 0
_080778E4: .4byte 0x0200C000
_080778E8: .4byte 0x06007000
_080778EC:
	cmp r4, #1
	bne _08077908
	movs r6, #2
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	eors r0, r1
	strh r0, [r2]
	movs r0, #5
	b _08077AD8
_08077908:
	cmp r4, #3
	bne _08077924
	movs r6, #2
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _08077920 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #6
	b _08077AD8
	.align 2, 0
_08077920: .4byte 0x0000FEFF
_08077924:
	cmp r4, #5
	beq _0807792A
	b _08077ADA
_0807792A:
	movs r6, #3
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _08077940 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #6
	b _08077AD8
	.align 2, 0
_08077940: .4byte 0x0000FEFF
_08077944:
	cmp r4, #2
	bne _08077960
	movs r6, #1
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #4
	b _080779F6
_08077960:
	cmp r4, #3
	beq _08077966
	b _08077ADA
_08077966:
	movs r0, #7
	b _08077AD8
_0807796A:
	cmp r4, #4
	beq _08077970
	b _08077ADA
_08077970:
	movs r6, #1
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0807799C @ =0x0200C000
	ldr r2, _080779A0 @ =0x06007000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	strb r4, [r5, #1]
	b _08077ADA
	.align 2, 0
_0807799C: .4byte 0x0200C000
_080779A0: .4byte 0x06007000
_080779A4:
	cmp r4, #4
	beq _080779AA
	b _08077ADA
_080779AA:
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _080779D0 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080779D4 @ =0x0200C000
	ldr r2, _080779D8 @ =0x06007000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	movs r0, #5
	b _08077AD8
	.align 2, 0
_080779D0: .4byte 0x0000FEFF
_080779D4: .4byte 0x0200C000
_080779D8: .4byte 0x06007000
_080779DC:
	cmp r4, #2
	bne _08077A04
	movs r6, #4
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #9
_080779F6:
	strb r0, [r5, #1]
	ldr r0, _08077A00 @ =0x00000203
	bl SoundPlay
	b _08077ADA
	.align 2, 0
_08077A00: .4byte 0x00000203
_08077A04:
	cmp r4, #3
	beq _08077A0C
	cmp r4, #5
	bne _08077ADA
_08077A0C:
	movs r6, #6
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _08077A20 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xb
	b _08077AD8
	.align 2, 0
_08077A20: .4byte 0x0000FEFF
_08077A24:
	cmp r4, #1
	bne _08077A40
	movs r6, #5
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _08077A3C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	b _08077AD6
	.align 2, 0
_08077A3C: .4byte 0x0000FEFF
_08077A40:
	cmp r4, #3
	bne _08077A5C
	movs r6, #6
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _08077A58 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xa
	b _08077AD8
	.align 2, 0
_08077A58: .4byte 0x0000FEFF
_08077A5C:
	cmp r4, #5
	bne _08077ADA
	movs r6, #6
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _08077A74 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xa
	b _08077AD8
	.align 2, 0
_08077A74: .4byte 0x0000FEFF
_08077A78:
	cmp r4, #4
	bne _08077ADA
	movs r6, #4
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08077AA8 @ =0x0200C000
	ldr r2, _08077AAC @ =0x06007000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	movs r0, #9
	b _08077AD8
	.align 2, 0
_08077AA8: .4byte 0x0200C000
_08077AAC: .4byte 0x06007000
_08077AB0:
	cmp r4, #4
	bne _08077ADA
	movs r6, #5
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	ldr r0, _08077AEC @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08077AF0 @ =0x0200C000
	ldr r2, _08077AF4 @ =0x06007000
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
_08077AD6:
	movs r0, #8
_08077AD8:
	strb r0, [r5, #1]
_08077ADA:
	subs r0, r6, #1
	cmp r0, #5
	bls _08077AE2
	b _08077C6E
_08077AE2:
	lsls r0, r0, #2
	ldr r1, _08077AF8 @ =_08077AFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08077AEC: .4byte 0x0000FEFF
_08077AF0: .4byte 0x0200C000
_08077AF4: .4byte 0x06007000
_08077AF8: .4byte _08077AFC
_08077AFC: @ jump table
	.4byte _08077B14 @ case 0
	.4byte _08077B74 @ case 1
	.4byte _08077B94 @ case 2
	.4byte _08077BA8 @ case 3
	.4byte _08077C18 @ case 4
	.4byte _08077C60 @ case 5
_08077B14:
	ldr r4, _08077B70 @ =gNonGameplayRam
	adds r1, r4, #0
	adds r1, #0xd2
	movs r0, #0x59
	strb r0, [r1]
	adds r5, r4, #0
	adds r5, #0xd3
	ldrb r2, [r5]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r3, #2
	orrs r0, r3
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r0, r2
	strb r0, [r5]
	adds r5, #0xb
	movs r0, #0x5c
	strb r0, [r5]
	adds r5, #1
	ldrb r0, [r5]
	ands r1, r0
	orrs r1, r3
	ands r1, r2
	movs r0, #4
	orrs r1, r0
	strb r1, [r5]
	adds r0, r4, #0
	adds r0, #0xca
	movs r2, #0x74
	strh r2, [r0]
	subs r0, #2
	movs r1, #0x84
	strh r1, [r0]
	adds r0, #0xe
	strh r2, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xbe
	movs r0, #0x1c
	strh r0, [r1]
	b _08077C6E
	.align 2, 0
_08077B70: .4byte gNonGameplayRam
_08077B74:
	ldr r1, _08077B8C @ =gNonGameplayRam
	adds r2, r1, #0
	adds r2, #0xd2
	movs r0, #0
	strb r0, [r2]
	adds r2, #0xc
	strb r0, [r2]
	adds r1, #0xbe
	ldr r0, _08077B90 @ =0x0000FF9C
	strh r0, [r1]
	b _08077C6E
	.align 2, 0
_08077B8C: .4byte gNonGameplayRam
_08077B90: .4byte 0x0000FF9C
_08077B94:
	ldr r0, _08077BA4 @ =gNonGameplayRam
	adds r2, r0, #0
	adds r2, #0xd2
	movs r1, #0
	strb r1, [r2]
	adds r0, #0xde
	b _08077C6C
	.align 2, 0
_08077BA4: .4byte gNonGameplayRam
_08077BA8:
	ldr r4, _08077C14 @ =gNonGameplayRam
	adds r1, r4, #0
	adds r1, #0xd2
	movs r0, #0x59
	strb r0, [r1]
	adds r5, r4, #0
	adds r5, #0xd3
	ldrb r2, [r5]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r3, #2
	orrs r0, r3
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r0, r2
	strb r0, [r5]
	adds r5, #0xb
	movs r0, #0x5c
	strb r0, [r5]
	adds r5, #1
	ldrb r0, [r5]
	ands r1, r0
	orrs r1, r3
	ands r1, r2
	movs r0, #4
	orrs r1, r0
	strb r1, [r5]
	adds r0, r4, #0
	adds r0, #0xca
	movs r3, #0
	movs r2, #0x74
	strh r2, [r0]
	subs r0, #2
	movs r1, #0x84
	strh r1, [r0]
	adds r0, #0xe
	strh r2, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xd1
	movs r0, #9
	strb r0, [r1]
	adds r1, #0xc
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd0
	strb r3, [r0]
	adds r0, #0xc
	strb r3, [r0]
	b _08077C6E
	.align 2, 0
_08077C14: .4byte gNonGameplayRam
_08077C18:
	ldr r3, _08077C5C @ =gNonGameplayRam
	adds r1, r3, #0
	adds r1, #0xde
	movs r0, #0
	strb r0, [r1]
	subs r1, #0xc
	movs r0, #0x34
	strb r0, [r1]
	subs r1, #8
	movs r2, #0
	movs r0, #0xca
	strh r0, [r1]
	subs r1, #2
	movs r0, #0x8e
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xd1
	strb r2, [r0]
	subs r0, #1
	strb r2, [r0]
	adds r2, r3, #0
	adds r2, #0xd3
	ldrb r1, [r2]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r2]
	b _08077C6E
	.align 2, 0
_08077C5C: .4byte gNonGameplayRam
_08077C60:
	ldr r0, _08077C78 @ =gNonGameplayRam
	adds r2, r0, #0
	adds r2, #0xde
	movs r1, #0
	strb r1, [r2]
	adds r0, #0xd2
_08077C6C:
	strb r1, [r0]
_08077C6E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08077C78: .4byte gNonGameplayRam

	thumb_func_start MapScreenUpdateArrowsAndBlinkingSquare
MapScreenUpdateArrowsAndBlinkingSquare: @ 0x08077C7C
	push {r4, r5, lr}
	ldr r3, _08077D4C @ =gNonGameplayRam
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r2, _08077D50 @ =gBackgroundPositions
	ldrh r1, [r2, #0xc]
	subs r0, r0, r1
	movs r4, #0xd7
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	ldr r5, _08077D54 @ =0x00000211
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldrh r1, [r2, #0xe]
	subs r0, r0, r1
	subs r4, #2
	adds r1, r3, r4
	strh r0, [r1]
	movs r1, #1
	subs r5, #0x67
	adds r0, r3, r5
	ldrb r0, [r0]
	adds r4, r3, #0
	cmp r0, #0x12
	beq _08077CCE
	cmp r0, #0x13
	beq _08077CCE
	cmp r0, #0x14
	beq _08077CCE
	cmp r0, #0x15
	beq _08077CCE
	cmp r0, #0xe
	beq _08077CCE
	cmp r0, #0xf
	beq _08077CCE
	movs r1, #0
_08077CCE:
	cmp r1, #0
	beq _08077CFC
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldrh r1, [r2, #0xc]
	subs r0, r0, r1
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r1, r4, r3
	strh r0, [r1]
	ldr r5, _08077D58 @ =0x0000020D
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldrh r1, [r2, #0xe]
	subs r0, r0, r1
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_08077CFC:
	ldr r0, _08077D5C @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _08077D0A
	b _08077E38
_08077D0A:
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _08077D64
	ldr r3, _08077D60 @ =0x08576158
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r2, #0x80
	lsls r2, r2, #1
	strh r2, [r0, #0x2e]
	ldrb r1, [r3, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r2, [r0, #0x2e]
	ldrb r1, [r3, #8]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r2, [r0, #0x2e]
	ldrb r1, [r3, #0xc]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r2, [r0, #0x2e]
	b _08077E38
	.align 2, 0
_08077D4C: .4byte gNonGameplayRam
_08077D50: .4byte gBackgroundPositions
_08077D54: .4byte 0x00000211
_08077D58: .4byte 0x0000020D
_08077D5C: .4byte gPauseScreenFlag
_08077D60: .4byte 0x08576158
_08077D64:
	ldr r2, _08077D8C @ =0x08576158
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r4
	ldr r5, _08077D90 @ =0x0000025A
	adds r0, r4, r5
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, r1, r0
	cmp r1, #0xd
	ble _08077D94
	ldrb r0, [r2, #2]
	b _08077D9A
	.align 2, 0
_08077D8C: .4byte 0x08576158
_08077D90: .4byte 0x0000025A
_08077D94:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
_08077D9A:
	strh r0, [r3, #0x2e]
	ldrb r1, [r2, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r4
	movs r5, #0x96
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, #3
	adds r1, r4, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	cmp r0, #0xe
	ble _08077DC6
	ldrb r0, [r2, #6]
	b _08077DCC
_08077DC6:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
_08077DCC:
	strh r0, [r3, #0x2e]
	ldrb r1, [r2, #8]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r4
	ldr r5, _08077DF8 @ =0x00000259
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r5, #3
	adds r1, r4, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	cmp r0, #8
	ble _08077DFC
	ldrb r0, [r2, #0xa]
	b _08077E02
	.align 2, 0
_08077DF8: .4byte 0x00000259
_08077DFC:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
_08077E02:
	strh r0, [r3, #0x2e]
	ldrb r1, [r2, #0xc]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r4
	ldr r5, _08077E2C @ =0x0000025D
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r5, #4
	adds r1, r4, r5
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r0, r0, r1
	cmp r0, #8
	ble _08077E30
	ldrb r0, [r2, #0xe]
	b _08077E36
	.align 2, 0
_08077E2C: .4byte 0x0000025D
_08077E30:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
_08077E36:
	strh r0, [r3, #0x2e]
_08077E38:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MapScreenDrawSpecialOam
MapScreenDrawSpecialOam: @ 0x08077E40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _08077E70 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _08077E5E
	b _080780E0
_08077E5E:
	mov r0, r8
	cmp r0, #1
	beq _08077EF0
	cmp r0, #1
	bgt _08077E74
	cmp r0, #0
	beq _08077E7C
	b _08077F5A
	.align 2, 0
_08077E70: .4byte gPauseScreenFlag
_08077E74:
	mov r1, r8
	cmp r1, #2
	beq _08077F3C
	b _08077F5A
_08077E7C:
	ldr r0, _08077EE0 @ =gNonGameplayRam
	ldrb r1, [r0]
	movs r2, #3
	cmp r1, #0
	beq _08077E88
	movs r2, #1
_08077E88:
	movs r4, #0
	ldr r7, _08077EE4 @ =gEquipment
	ldr r5, _08077EE8 @ =0x08576150
	mov sb, r2
	movs r2, #4
	rsbs r2, r2, #0
	mov sl, r2
_08077E96:
	movs r6, #0
	ldrb r0, [r7, #0xd]
	adds r3, r4, #1
	cmp r0, #0xff
	beq _08077EA6
	cmp r0, r3
	blt _08077EA6
	movs r6, #1
_08077EA6:
	lsls r2, r4, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _08077EE0 @ =gNonGameplayRam
	adds r1, r1, r0
	ldr r0, _08077EEC @ =0x08576151
	adds r2, r2, r0
	ldrb r0, [r2]
	adds r0, r0, r6
	movs r2, #0x36
	strb r0, [r2, r1]
	movs r0, #0x24
	strh r0, [r1, #0x2c]
	movs r0, #0xd4
	strh r0, [r1, #0x2e]
	adds r1, #0x37
	ldrb r2, [r1]
	mov r0, sl
	ands r0, r2
	mov r2, sb
	orrs r0, r2
	strb r0, [r1]
	adds r4, r3, #0
	cmp r4, #3
	bls _08077E96
	b _08077F5A
	.align 2, 0
_08077EE0: .4byte gNonGameplayRam
_08077EE4: .4byte gEquipment
_08077EE8: .4byte 0x08576150
_08077EEC: .4byte 0x08576151
_08077EF0:
	movs r4, #0
	ldr r7, _08077F30 @ =gEquipment
	ldr r3, _08077F34 @ =gNonGameplayRam
	mov ip, r3
	ldr r5, _08077F38 @ =0x08576150
	adds r0, r5, #1
	mov sb, r0
_08077EFE:
	movs r6, #0
	ldrb r0, [r7, #0xd]
	adds r3, r4, #1
	cmp r0, #0xff
	beq _08077F0E
	cmp r0, r3
	blt _08077F0E
	movs r6, #1
_08077F0E:
	lsls r2, r4, #1
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	add r2, sb
	ldrb r1, [r2]
	adds r1, r1, r6
	adds r0, #0x36
	strb r1, [r0]
	adds r4, r3, #0
	cmp r4, #3
	bls _08077EFE
	b _08077F5A
	.align 2, 0
_08077F30: .4byte gEquipment
_08077F34: .4byte gNonGameplayRam
_08077F38: .4byte 0x08576150
_08077F3C:
	movs r4, #0
	ldr r5, _08077F84 @ =gNonGameplayRam
	movs r3, #0
	ldr r2, _08077F88 @ =0x08576150
_08077F44:
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x36
	strb r3, [r0]
	adds r2, #2
	adds r4, #1
	cmp r4, #3
	bls _08077F44
_08077F5A:
	movs r4, #0
	ldr r1, _08077F8C @ =0x03000014
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08077F68
	movs r4, #1
_08077F68:
	ldr r2, _08077F84 @ =gNonGameplayRam
	ldrb r0, [r2]
	cmp r0, #0
	beq _08077F72
	movs r4, #1
_08077F72:
	cmp r4, #0
	beq _08077F90
	ldr r3, _08077F84 @ =gNonGameplayRam
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0
	b _080780DE
	.align 2, 0
_08077F84: .4byte gNonGameplayRam
_08077F88: .4byte 0x08576150
_08077F8C: .4byte 0x03000014
_08077F90:
	mov r1, r8
	cmp r1, #0
	beq _08077F98
	b _080780E0
_08077F98:
	movs r4, #3
	cmp r0, #0
	beq _08077FA0
	movs r4, #1
_08077FA0:
	bl MapScreenCountTanks
	movs r0, #0
	bl PauseScreenDrawIgtAndTanks
	movs r6, #0
	ldr r7, _080780F0 @ =gNonGameplayRam
	ldr r2, _080780F4 @ =0x0879BE8C
	mov r8, r2
	movs r0, #3
	mov ip, r4
	mov r3, ip
	ands r3, r0
	mov ip, r3
	movs r0, #4
	rsbs r0, r0, #0
	mov sb, r0
	mov r5, r8
_08077FC4:
	lsls r3, r6, #2
	ldrb r0, [r5]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r0, r8
	adds r0, #1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, #0x36
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	adds r1, #0x37
	ldrb r2, [r1]
	mov r0, sb
	ands r0, r2
	mov r2, ip
	orrs r0, r2
	strb r0, [r1]
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r1, r8
	adds r1, #2
	adds r3, r3, r1
	ldrb r1, [r3]
	strh r1, [r0, #0x2e]
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r1, [r5, #3]
	strh r1, [r0, #0x2c]
	adds r5, #4
	adds r6, #1
	cmp r6, #3
	bls _08077FC4
	movs r6, #0
	ldr r7, _080780F8 @ =0x0879BE9C
	ldr r5, _080780F0 @ =gNonGameplayRam
	mov ip, r7
	movs r0, #3
	ands r4, r0
	mov r8, r4
	movs r3, #4
	rsbs r3, r3, #0
	mov sb, r3
	adds r4, r7, #0
_08078034:
	lsls r3, r6, #2
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	adds r1, #0x37
	ldrb r2, [r1]
	mov r0, sb
	ands r0, r2
	mov r2, r8
	orrs r0, r2
	strb r0, [r1]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r1, ip
	adds r1, #2
	adds r3, r3, r1
	ldrb r1, [r3]
	strh r1, [r0, #0x2e]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r1, [r4, #3]
	strh r1, [r0, #0x2c]
	adds r4, #4
	adds r6, #1
	cmp r6, #2
	bls _08078034
	ldr r2, _080780F0 @ =gNonGameplayRam
	ldr r3, _080780FC @ =0x00000275
	adds r0, r2, r3
	adds r3, #1
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0807809A
	ldrb r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r7, #1]
	adds r1, #0x36
	strb r0, [r1]
_0807809A:
	ldr r1, _08078100 @ =0x00000277
	adds r0, r2, r1
	movs r3, #0x9e
	lsls r3, r3, #2
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080780BC
	ldrb r0, [r7, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r7, #5]
	adds r1, #0x36
	strb r0, [r1]
_080780BC:
	ldr r1, _080780F0 @ =gNonGameplayRam
	ldr r2, _08078104 @ =0x00000279
	adds r0, r1, r2
	ldr r3, _08078108 @ =0x0000027A
	adds r1, r1, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080780E0
	ldrb r0, [r7, #8]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _080780F0 @ =gNonGameplayRam
	adds r1, r1, r0
	ldrb r0, [r7, #9]
	adds r1, #0x36
_080780DE:
	strb r0, [r1]
_080780E0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080780F0: .4byte gNonGameplayRam
_080780F4: .4byte 0x0879BE8C
_080780F8: .4byte 0x0879BE9C
_080780FC: .4byte 0x00000275
_08078100: .4byte 0x00000277
_08078104: .4byte 0x00000279
_08078108: .4byte 0x0000027A

	thumb_func_start PauseScreenSetupOam
PauseScreenSetupOam: @ 0x0807810C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080781A0 @ =gNonGameplayRam
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	strh r1, [r0, #0x14]
	strb r2, [r0, #0x17]
	strb r2, [r0, #0x18]
	adds r7, r0, #0
	movs r3, #0
	movs r6, #4
	rsbs r6, r6, #0
	movs r5, #0xd
	rsbs r5, r5, #0
	adds r2, r7, #0
	adds r2, #0x2c
	movs r4, #0x27
_0807813A:
	strb r3, [r2, #0xa]
	strb r3, [r2, #8]
	strb r3, [r2, #9]
	strh r3, [r2, #2]
	strh r3, [r2]
	ldrb r1, [r2, #0xb]
	adds r0, r6, #0
	ands r0, r1
	ands r0, r5
	strb r0, [r2, #0xb]
	adds r2, #0xc
	subs r4, #1
	cmp r4, #0
	bge _0807813A
	adds r0, r7, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #4
	beq _08078176
	ldr r0, _080781A4 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	beq _08078176
	movs r0, #0xdb
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_08078176:
	ldr r3, _080781A0 @ =gNonGameplayRam
	ldrb r0, [r3]
	cmp r0, #0
	beq _080781B0
	ldr r1, _080781A8 @ =0x000001B7
	adds r4, r3, r1
	ldrb r2, [r4]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r4]
	ldr r0, _080781AC @ =0x000001AB
	adds r3, r3, r0
	ldrb r0, [r3]
	ands r1, r0
	orrs r1, r2
	strb r1, [r3]
	b _080781C6
	.align 2, 0
_080781A0: .4byte gNonGameplayRam
_080781A4: .4byte gPauseScreenFlag
_080781A8: .4byte 0x000001B7
_080781AC: .4byte 0x000001AB
_080781B0:
	ldr r1, _080781E4 @ =0x000001B7
	adds r2, r3, r1
	ldrb r0, [r2]
	movs r1, #3
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _080781E8 @ =0x000001AB
	adds r2, r3, r0
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
_080781C6:
	bl MapScreenUpdateArrowsAndBlinkingSquare
	ldr r1, _080781EC @ =gNonGameplayRam
	adds r0, r1, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #1
	bne _080781F0
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _080781FC
	bl PauseDebugSetupCursor
	b _080781FC
	.align 2, 0
_080781E4: .4byte 0x000001B7
_080781E8: .4byte 0x000001AB
_080781EC: .4byte gNonGameplayRam
_080781F0:
	adds r2, r1, #0
	adds r2, #0x36
	movs r0, #0
	strb r0, [r2]
	strh r0, [r1, #0x2c]
	strh r0, [r1, #0x2e]
_080781FC:
	ldr r1, _08078270 @ =gNonGameplayRam
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _080782AE
	adds r1, #0xf6
	movs r0, #0x28
	strb r0, [r1]
	mov r0, ip
	adds r0, #0xec
	movs r3, #2
	strh r3, [r0]
	mov r1, ip
	adds r1, #0xee
	movs r0, #0xd6
	strh r0, [r1]
	mov r4, ip
	adds r4, #0xf7
	ldrb r2, [r4]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	movs r2, #2
	orrs r0, r2
	strb r0, [r4]
	movs r4, #0x81
	lsls r4, r4, #1
	add r4, ip
	movs r0, #0x2a
	strb r0, [r4]
	mov r0, ip
	adds r0, #0xf8
	strh r3, [r0]
	mov r3, ip
	adds r3, #0xfa
	movs r0, #0x12
	strh r0, [r3]
	ldr r3, _08078274 @ =0x00000103
	add r3, ip
	ldrb r0, [r3]
	ands r1, r0
	orrs r1, r2
	strb r1, [r3]
	ldr r1, _08078278 @ =gCurrentArea
	ldrb r0, [r1]
	cmp r0, #6
	bhi _08078280
	ldr r0, _0807827C @ =0x08576142
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r0, #1
	adds r1, r1, r0
	ldrb r1, [r1]
	movs r0, #0x12
	bl UpdateMenuOamDataId
	b _08078288
	.align 2, 0
_08078270: .4byte gNonGameplayRam
_08078274: .4byte 0x00000103
_08078278: .4byte gCurrentArea
_0807827C: .4byte 0x08576142
_08078280:
	movs r0, #0x12
	movs r1, #0
	bl UpdateMenuOamDataId
_08078288:
	ldr r2, _080783D4 @ =gNonGameplayRam
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0x74
	strh r0, [r1]
	ldr r1, _080783D8 @ =0x0000010F
	adds r2, r2, r1
	ldrb r1, [r2]
	subs r0, #0x78
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2]
_080782AE:
	movs r0, #0
	bl MapScreenDrawSpecialOam
	ldr r3, _080783D4 @ =gNonGameplayRam
	adds r1, r3, #0
	adds r1, #0xe0
	movs r2, #0
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xea
	strb r2, [r0]
	adds r7, r3, #0
	adds r4, r7, #0
	ldr r5, _080783DC @ =0x08576158
	adds r3, r5, #0
	adds r3, #0x10
	movs r6, #4
	rsbs r6, r6, #0
_080782DA:
	subs r3, #4
	ldrb r0, [r4]
	cmp r0, #0
	bne _080782F2
	ldrb r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r0, [r3, #1]
	adds r1, #0x36
	strb r0, [r1]
_080782F2:
	ldrb r0, [r3]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r4
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #0x2e]
	ldrb r0, [r3, #3]
	strh r0, [r2, #0x2c]
	adds r2, #0x37
	ldrb r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2]
	cmp r3, r5
	bgt _080782DA
	adds r5, r7, #0
	ldrb r6, [r5]
	cmp r6, #1
	bne _080783C6
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x7c
	strh r0, [r1]
	movs r0, #0xf5
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x74
	strh r0, [r1]
	movs r1, #0xf9
	lsls r1, r1, #1
	adds r1, r1, r5
	mov r8, r1
	movs r0, #0x3e
	strb r0, [r1]
	adds r2, #0xb
	adds r1, r5, r2
	ldrb r0, [r1]
	movs r2, #3
	mov sb, r2
	mov r2, sb
	orrs r0, r2
	strb r0, [r1]
	bl unk_65618
	adds r4, r0, #0
	ldr r0, _080783E0 @ =gPauseScreenFlag
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _0807836A
	movs r4, #3
	movs r0, #0x3d
	mov r1, r8
	strb r0, [r1]
_0807836A:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0807839A
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x4c
	strh r0, [r1]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x18
	strh r0, [r1]
	adds r2, #0xa
	adds r1, r5, r2
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _080783E4 @ =0x000001FF
	adds r1, r5, r0
	ldrb r0, [r1]
	mov r2, sb
	orrs r0, r2
	strb r0, [r1]
_0807839A:
	ands r6, r4
	cmp r6, #0
	beq _080783C6
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0x4c
	strh r0, [r1]
	ldr r2, _080783E8 @ =0x00000202
	adds r1, r7, r2
	movs r0, #0xd0
	strh r0, [r1]
	ldr r0, _080783EC @ =0x0000020A
	adds r1, r7, r0
	movs r0, #0x40
	strb r0, [r1]
	adds r2, #9
	adds r1, r7, r2
	ldrb r0, [r1]
	mov r2, sb
	orrs r0, r2
	strb r0, [r1]
_080783C6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080783D4: .4byte gNonGameplayRam
_080783D8: .4byte 0x0000010F
_080783DC: .4byte 0x08576158
_080783E0: .4byte gPauseScreenFlag
_080783E4: .4byte 0x000001FF
_080783E8: .4byte 0x00000202
_080783EC: .4byte 0x0000020A

	thumb_func_start PauseScreenProcessOam
PauseScreenProcessOam: @ 0x080783F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0807844C @ =gOamData
	str r0, [sp, #8]
	ldr r0, _08078450 @ =gNextOamSlot
	ldrb r1, [r0]
	lsls r0, r1, #3
	ldr r2, [sp, #8]
	adds r2, r0, r2
	str r2, [sp, #8]
	str r1, [sp]
	mov sb, r1
	movs r3, #0
	str r3, [sp, #0xc]
_08078414:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #1
	adds r1, r0, r1
	lsls r1, r1, #2
	ldr r3, _08078454 @ =gNonGameplayRam
	adds r2, r1, r3
	adds r3, r2, #0
	adds r3, #0x36
	ldrb r1, [r3]
	adds r7, r0, #0
	cmp r1, #0
	bne _0807842E
	b _08078A36
_0807842E:
	adds r2, #0x37
	ldrb r1, [r2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r0, [r3]
	cmp r0, #0x8b
	bls _08078442
	b _0807868C
_08078442:
	lsls r0, r0, #2
	ldr r1, _08078458 @ =_0807845C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807844C: .4byte gOamData
_08078450: .4byte gNextOamSlot
_08078454: .4byte gNonGameplayRam
_08078458: .4byte _0807845C
_0807845C: @ jump table
	.4byte _08078962 @ case 0
	.4byte _080786B4 @ case 1
	.4byte _080786B4 @ case 2
	.4byte _080786B4 @ case 3
	.4byte _080786B4 @ case 4
	.4byte _080786B4 @ case 5
	.4byte _080786B4 @ case 6
	.4byte _080786B4 @ case 7
	.4byte _080786B4 @ case 8
	.4byte _080786B4 @ case 9
	.4byte _0807868C @ case 10
	.4byte _080786B4 @ case 11
	.4byte _080786B4 @ case 12
	.4byte _0807868C @ case 13
	.4byte _080786B4 @ case 14
	.4byte _080786B4 @ case 15
	.4byte _080787F0 @ case 16
	.4byte _0807868C @ case 17
	.4byte _08078708 @ case 18
	.4byte _08078708 @ case 19
	.4byte _08078708 @ case 20
	.4byte _08078708 @ case 21
	.4byte _080786B4 @ case 22
	.4byte _080786B4 @ case 23
	.4byte _080786B4 @ case 24
	.4byte _080786B4 @ case 25
	.4byte _0807868C @ case 26
	.4byte _0807890C @ case 27
	.4byte _0807868C @ case 28
	.4byte _0807890C @ case 29
	.4byte _0807868C @ case 30
	.4byte _0807890C @ case 31
	.4byte _0807868C @ case 32
	.4byte _0807890C @ case 33
	.4byte _0807868C @ case 34
	.4byte _0807890C @ case 35
	.4byte _0807868C @ case 36
	.4byte _0807890C @ case 37
	.4byte _0807868C @ case 38
	.4byte _0807890C @ case 39
	.4byte _080786B4 @ case 40
	.4byte _080786B4 @ case 41
	.4byte _080786B4 @ case 42
	.4byte _080786B4 @ case 43
	.4byte _0807868C @ case 44
	.4byte _0807868C @ case 45
	.4byte _0807868C @ case 46
	.4byte _0807868C @ case 47
	.4byte _0807868C @ case 48
	.4byte _0807868C @ case 49
	.4byte _0807868C @ case 50
	.4byte _0807868C @ case 51
	.4byte _0807868C @ case 52
	.4byte _0807890C @ case 53
	.4byte _0807868C @ case 54
	.4byte _0807868C @ case 55
	.4byte _0807868C @ case 56
	.4byte _0807868C @ case 57
	.4byte _0807868C @ case 58
	.4byte _0807868C @ case 59
	.4byte _0807868C @ case 60
	.4byte _080786B4 @ case 61
	.4byte _080786B4 @ case 62
	.4byte _0807868C @ case 63
	.4byte _0807868C @ case 64
	.4byte _08078780 @ case 65
	.4byte _080787F0 @ case 66
	.4byte _08078780 @ case 67
	.4byte _0807868C @ case 68
	.4byte _08078780 @ case 69
	.4byte _08078780 @ case 70
	.4byte _0807868C @ case 71
	.4byte _08078780 @ case 72
	.4byte _08078780 @ case 73
	.4byte _08078780 @ case 74
	.4byte _080786B4 @ case 75
	.4byte _080786B4 @ case 76
	.4byte _08078780 @ case 77
	.4byte _0807868C @ case 78
	.4byte _080787F0 @ case 79
	.4byte _08078780 @ case 80
	.4byte _0807868C @ case 81
	.4byte _080787F0 @ case 82
	.4byte _08078780 @ case 83
	.4byte _0807868C @ case 84
	.4byte _080787F0 @ case 85
	.4byte _08078780 @ case 86
	.4byte _0807868C @ case 87
	.4byte _080787F0 @ case 88
	.4byte _08078780 @ case 89
	.4byte _0807868C @ case 90
	.4byte _080787F0 @ case 91
	.4byte _08078780 @ case 92
	.4byte _0807868C @ case 93
	.4byte _080787F0 @ case 94
	.4byte _08078844 @ case 95
	.4byte _080786B4 @ case 96
	.4byte _0807868C @ case 97
	.4byte _080787F0 @ case 98
	.4byte _08078898 @ case 99
	.4byte _0807868C @ case 100
	.4byte _0807890C @ case 101
	.4byte _080787F0 @ case 102
	.4byte _080786B4 @ case 103
	.4byte _0807868C @ case 104
	.4byte _0807868C @ case 105
	.4byte _0807868C @ case 106
	.4byte _0807868C @ case 107
	.4byte _0807868C @ case 108
	.4byte _0807868C @ case 109
	.4byte _0807868C @ case 110
	.4byte _0807868C @ case 111
	.4byte _0807868C @ case 112
	.4byte _0807868C @ case 113
	.4byte _0807868C @ case 114
	.4byte _0807868C @ case 115
	.4byte _0807868C @ case 116
	.4byte _0807868C @ case 117
	.4byte _0807868C @ case 118
	.4byte _0807868C @ case 119
	.4byte _0807868C @ case 120
	.4byte _0807868C @ case 121
	.4byte _0807868C @ case 122
	.4byte _0807868C @ case 123
	.4byte _0807868C @ case 124
	.4byte _0807868C @ case 125
	.4byte _0807868C @ case 126
	.4byte _0807868C @ case 127
	.4byte _0807868C @ case 128
	.4byte _0807868C @ case 129
	.4byte _0807868C @ case 130
	.4byte _0807868C @ case 131
	.4byte _0807868C @ case 132
	.4byte _0807868C @ case 133
	.4byte _0807868C @ case 134
	.4byte _0807868C @ case 135
	.4byte _0807868C @ case 136
	.4byte _0807868C @ case 137
	.4byte _0807868C @ case 138
	.4byte _0807868C @ case 139
_0807868C:
	ldr r2, _080786AC @ =0x0879BEC0
	ldr r0, _080786B0 @ =gNonGameplayRam
	ldr r3, [sp, #0xc]
	adds r1, r7, r3
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x36
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r5, [r0]
	adds r1, #0x34
	movs r0, #0
	strb r0, [r1]
	b _08078962
	.align 2, 0
_080786AC: .4byte 0x0879BEC0
_080786B0: .4byte gNonGameplayRam
_080786B4:
	ldr r2, _08078700 @ =0x0879BEC0
	ldr r1, _08078704 @ =gNonGameplayRam
	ldr r3, [sp, #0xc]
	adds r0, r7, r3
	lsls r0, r0, #2
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x36
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r5, [r0]
	adds r3, r1, #0
	adds r3, #0x34
	adds r2, r1, #0
	adds r2, #0x35
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r3]
	ldrb r0, [r0, #4]
	cmp r1, r0
	bhs _080786E4
	b _08078962
_080786E4:
	movs r0, #0
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _080786FC
	b _08078962
_080786FC:
	strb r0, [r2]
	b _08078962
	.align 2, 0
_08078700: .4byte 0x0879BEC0
_08078704: .4byte gNonGameplayRam
_08078708:
	ldr r1, _0807876C @ =0x0879BEC0
	ldr r4, _08078770 @ =gNonGameplayRam
	ldr r2, [sp, #0xc]
	adds r0, r7, r2
	lsls r0, r0, #2
	adds r2, r0, r4
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	adds r3, r2, #0
	adds r3, #0x34
	adds r2, #0x35
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r3]
	ldrb r0, [r0, #4]
	cmp r1, r0
	bhs _08078736
	b _08078962
_08078736:
	movs r0, #0
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _0807874E
	b _08078962
_0807874E:
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807875C
	b _08078962
_0807875C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08078774
	movs r0, #0x8d
	lsls r0, r0, #1
	bl SoundPlay
	b _08078962
	.align 2, 0
_0807876C: .4byte 0x0879BEC0
_08078770: .4byte gNonGameplayRam
_08078774:
	ldr r0, _0807877C @ =0x0000012B
	bl SoundPlay
	b _08078962
	.align 2, 0
_0807877C: .4byte 0x0000012B
_08078780:
	ldr r2, _080787E8 @ =0x0879BEC0
	ldr r1, _080787EC @ =gNonGameplayRam
	ldr r3, [sp, #0xc]
	adds r0, r7, r3
	lsls r0, r0, #2
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x36
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r5, [r0]
	adds r4, r3, #0
	adds r4, #0x35
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	bne _080787B4
	adds r2, r3, #0
	adds r2, #0x37
	ldrb r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
_080787B4:
	adds r2, r3, #0
	adds r2, #0x34
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r2]
	ldrb r0, [r0, #4]
	cmp r1, r0
	bhs _080787C8
	b _08078962
_080787C8:
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldrb r1, [r4]
	lsls r0, r1, #3
	adds r0, r0, r5
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _080787E0
	b _08078962
_080787E0:
	subs r0, r1, #1
	strb r0, [r4]
	b _08078962
	.align 2, 0
_080787E8: .4byte 0x0879BEC0
_080787EC: .4byte gNonGameplayRam
_080787F0:
	ldr r1, _0807883C @ =0x0879BEC0
	ldr r2, [sp, #0xc]
	adds r0, r7, r2
	lsls r0, r0, #2
	ldr r3, _08078840 @ =gNonGameplayRam
	adds r2, r0, r3
	adds r4, r2, #0
	adds r4, #0x36
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	adds r3, r2, #0
	adds r3, #0x34
	adds r2, #0x35
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r3]
	ldrb r0, [r0, #4]
	cmp r1, r0
	bhs _0807881E
	b _08078962
_0807881E:
	movs r0, #0
	strb r0, [r3]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _08078836
	b _08078962
_08078836:
	strb r0, [r4]
	strb r0, [r2]
	b _08078A36
	.align 2, 0
_0807883C: .4byte 0x0879BEC0
_08078840: .4byte gNonGameplayRam
_08078844:
	ldr r6, _08078890 @ =0x0879BEC0
	ldr r1, _08078894 @ =gNonGameplayRam
	ldr r2, [sp, #0xc]
	adds r0, r7, r2
	lsls r0, r0, #2
	adds r1, r0, r1
	adds r3, r1, #0
	adds r3, #0x36
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r5, [r0]
	adds r4, r1, #0
	adds r4, #0x34
	adds r2, r1, #0
	adds r2, #0x35
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r4]
	ldrb r0, [r0, #4]
	cmp r1, r0
	blo _08078962
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r0, #4]
	cmp r1, #0
	bne _08078962
	ldrb r0, [r3]
	adds r0, #1
	b _08078954
	.align 2, 0
_08078890: .4byte 0x0879BEC0
_08078894: .4byte gNonGameplayRam
_08078898:
	ldr r3, _08078904 @ =0x0879BEC0
	mov r8, r3
	ldr r6, _08078908 @ =gNonGameplayRam
	ldr r1, [sp, #0xc]
	adds r0, r7, r1
	lsls r0, r0, #2
	adds r1, r0, r6
	adds r3, r1, #0
	adds r3, #0x36
	ldrb r0, [r3]
	lsls r0, r0, #2
	add r0, r8
	ldr r5, [r0]
	adds r4, r1, #0
	adds r4, #0x34
	adds r2, r1, #0
	adds r2, #0x35
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r4]
	ldrb r0, [r0, #4]
	cmp r1, r0
	blo _08078962
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r0, #4]
	cmp r1, #0
	bne _08078962
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	ldrb r0, [r3]
	lsls r0, r0, #2
	add r0, r8
	ldr r5, [r0]
	strb r1, [r4]
	strb r1, [r2]
	adds r2, r6, #0
	adds r2, #0x7e
	movs r0, #0x67
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x7c
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _08078962
	.align 2, 0
_08078904: .4byte 0x0879BEC0
_08078908: .4byte gNonGameplayRam
_0807890C:
	ldr r6, _08078A5C @ =0x0879BEC0
	ldr r1, _08078A60 @ =gNonGameplayRam
	ldr r2, [sp, #0xc]
	adds r0, r7, r2
	lsls r0, r0, #2
	adds r1, r0, r1
	adds r3, r1, #0
	adds r3, #0x36
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r5, [r0]
	adds r4, r1, #0
	adds r4, #0x34
	adds r2, r1, #0
	adds r2, #0x35
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r4]
	ldrb r0, [r0, #4]
	cmp r1, r0
	blo _08078962
	movs r0, #0
	strb r0, [r4]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r1, [r0, #4]
	cmp r1, #0
	bne _08078962
	ldrb r0, [r3]
	subs r0, #1
_08078954:
	strb r0, [r3]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r5, [r0]
	strb r1, [r4]
	strb r1, [r2]
_08078962:
	ldr r2, _08078A60 @ =gNonGameplayRam
	ldr r3, [sp, #0xc]
	adds r0, r7, r3
	lsls r0, r0, #2
	adds r3, r0, r2
	adds r1, r3, #0
	adds r1, #0x34
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r0, [r3, #0x2c]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldrh r0, [r3, #0x2e]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r3, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r4, [r5]
	adds r0, r3, #0
	adds r0, #0x37
	ldrb r1, [r0]
	lsls r0, r1, #0x1e
	lsrs r6, r0, #0x1e
	lsls r1, r1, #0x1c
	lsrs r3, r1, #0x1e
	ldrh r0, [r4]
	ldr r1, [sp]
	adds r0, r1, r0
	cmp r0, #0x7f
	bgt _08078A42
	str r0, [sp]
	adds r4, #2
	cmp sb, r0
	bge _08078A36
	ldr r0, _08078A64 @ =gOamData
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	mov r8, r1
	lsls r6, r6, #2
	mov ip, r6
	lsls r7, r3, #2
	mov r2, sb
	lsls r1, r2, #3
	adds r3, r1, r0
	ldr r0, _08078A68 @ =0x000001FF
	mov sl, r0
	movs r6, #0xd
	rsbs r6, r6, #0
	ldr r1, [sp]
	subs r1, r1, r2
	mov sb, r1
_080789D6:
	ldrh r0, [r4]
	adds r4, #2
	ldr r2, [sp, #8]
	strh r0, [r2]
	adds r2, #2
	ldr r1, [sp, #4]
	adds r0, r1, r0
	strb r0, [r3]
	ldrh r1, [r4]
	adds r4, #2
	strh r1, [r2]
	adds r2, #2
	str r2, [sp, #8]
	add r1, r8
	mov r2, sl
	ands r1, r2
	ldrh r2, [r3, #2]
	ldr r0, _08078A6C @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4]
	ldr r1, [sp, #8]
	strh r0, [r1]
	adds r4, #2
	ldrb r1, [r3, #5]
	adds r0, r6, #0
	ands r0, r1
	mov r2, ip
	orrs r0, r2
	strb r0, [r3, #5]
	ldrb r1, [r3, #1]
	adds r0, r6, #0
	ands r0, r1
	orrs r0, r7
	strb r0, [r3, #1]
	ldr r0, [sp, #8]
	adds r0, #4
	str r0, [sp, #8]
	adds r3, #8
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	cmp r2, #0
	bne _080789D6
	ldr r3, [sp]
	mov sb, r3
_08078A36:
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0x27
	bgt _08078A42
	b _08078414
_08078A42:
	ldr r0, _08078A70 @ =gNextOamSlot
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08078A5C: .4byte 0x0879BEC0
_08078A60: .4byte gNonGameplayRam
_08078A64: .4byte gOamData
_08078A68: .4byte 0x000001FF
_08078A6C: .4byte 0xFFFFFE00
_08078A70: .4byte gNextOamSlot

	thumb_func_start CheckForMaintainedInput
CheckForMaintainedInput: @ 0x08078A74
	push {lr}
	sub sp, #8
	ldr r1, _08078A9C @ =0x08576210
	mov r0, sp
	movs r2, #7
	bl memcpy
	ldr r0, _08078AA0 @ =gButtonInput
	ldrh r0, [r0]
	movs r1, #0xf0
	ands r1, r0
	cmp r1, #0
	beq _08078AA8
	ldr r1, _08078AA4 @ =0x03005400
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r3, r1, #0
	b _08078AB0
	.align 2, 0
_08078A9C: .4byte 0x08576210
_08078AA0: .4byte gButtonInput
_08078AA4: .4byte 0x03005400
_08078AA8:
	ldr r0, _08078AE4 @ =0x03005400
	strb r1, [r0]
	strb r1, [r0, #1]
	adds r3, r0, #0
_08078AB0:
	ldrb r0, [r3, #1]
	mov r2, sp
	adds r1, r2, r0
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	blo _08078ADC
	ldr r2, _08078AE8 @ =gChangedInput
	ldr r0, _08078AEC @ =gButtonInput
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	strb r0, [r3]
	ldrb r0, [r3, #1]
	cmp r0, #5
	bhi _08078ADC
	adds r0, #1
	strb r0, [r3, #1]
_08078ADC:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08078AE4: .4byte 0x03005400
_08078AE8: .4byte gChangedInput
_08078AEC: .4byte gButtonInput

	thumb_func_start unk_78af0
unk_78af0: @ 0x08078AF0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r6, r3, #0
	ldr r2, _08078B14 @ =gNonGameplayRam
	cmp r3, #0
	beq _08078B7A
	movs r4, #0
	ldrh r1, [r2, #4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08078B0C
	movs r4, #3
_08078B0C:
	cmp r3, #1
	bne _08078B18
	movs r5, #0
	b _08078B38
	.align 2, 0
_08078B14: .4byte gNonGameplayRam
_08078B18:
	cmp r3, #2
	bne _08078B2C
	ldr r0, _08078B28 @ =0x0000020A
	bl SoundPlay
	movs r5, #1
	b _08078B38
	.align 2, 0
_08078B28: .4byte 0x0000020A
_08078B2C:
	cmp r6, #3
	bne _08078B38
	ldr r0, _08078B98 @ =0x0000020B
	bl SoundPlay
	movs r5, #2
_08078B38:
	adds r4, r4, r5
	ldr r0, _08078B9C @ =gNonGameplayRam
	mov ip, r0
	ldr r2, _08078BA0 @ =0x085767F0
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r0, r1, r2
	ldrb r0, [r0]
	mov r4, ip
	adds r4, #0x96
	movs r3, #0
	strb r0, [r4]
	adds r0, r2, #1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r4, #0xc
	strb r0, [r4]
	adds r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	mov r1, ip
	adds r1, #0x8a
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x94
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0xb
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	mov r2, ip
_08078B7A:
	adds r0, r2, #0
	adds r0, #0x8e
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x9a
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8c
	ldrh r1, [r0]
	adds r0, #0xc
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08078B98: .4byte 0x0000020B
_08078B9C: .4byte gNonGameplayRam
_08078BA0: .4byte 0x085767F0

	thumb_func_start PauseScreenSetNavigationTextPanelOam
PauseScreenSetNavigationTextPanelOam: @ 0x08078BA4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #1
	bne _08078BC4
	ldr r0, _08078BC0 @ =gNonGameplayRam
	adds r2, r0, #0
	adds r2, #0x66
	movs r1, #0x44
	strb r1, [r2]
	adds r0, #0x72
	movs r1, #0x47
	strb r1, [r0]
	b _08078C02
	.align 2, 0
_08078BC0: .4byte gNonGameplayRam
_08078BC4:
	cmp r4, #2
	bne _08078BE8
	ldr r1, _08078BE0 @ =gNonGameplayRam
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0x43
	strb r0, [r2]
	adds r1, #0x72
	movs r0, #0x46
	strb r0, [r1]
	ldr r0, _08078BE4 @ =0x0000020A
	bl SoundPlay
	b _08078C02
	.align 2, 0
_08078BE0: .4byte gNonGameplayRam
_08078BE4: .4byte 0x0000020A
_08078BE8:
	cmp r4, #3
	bne _08078C02
	ldr r1, _08078C3C @ =gNonGameplayRam
	adds r2, r1, #0
	adds r2, #0x66
	movs r0, #0x45
	strb r0, [r2]
	adds r1, #0x72
	movs r0, #0x48
	strb r0, [r1]
	ldr r0, _08078C40 @ =0x0000020B
	bl SoundPlay
_08078C02:
	ldr r3, _08078C3C @ =gNonGameplayRam
	cmp r4, #0
	beq _08078C1C
	adds r0, r3, #0
	adds r0, #0x64
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0xb
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08078C1C:
	adds r0, r3, #0
	adds r0, #0x5e
	ldrh r2, [r0]
	adds r0, #0xc
	strh r2, [r0]
	subs r0, #0xe
	ldrh r1, [r0]
	adds r0, #0xc
	strh r1, [r0]
	subs r0, #0x16
	strh r2, [r0]
	subs r0, #2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08078C3C: .4byte gNonGameplayRam
_08078C40: .4byte 0x0000020B

	thumb_func_start unk_78c44
unk_78c44: @ 0x08078C44
	push {r4, r5, lr}
	ldr r2, _08078C60 @ =gNonGameplayRam
	ldrh r0, [r2, #4]
	movs r1, #6
	ands r1, r0
	cmp r1, #0
	bne _08078C64
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r2, r3
	b _08078E96
	.align 2, 0
_08078C60: .4byte gNonGameplayRam
_08078C64:
	ldr r1, _08078C88 @ =0x0000023D
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #8
	bls _08078C7C
	b _08078E76
_08078C7C:
	lsls r0, r0, #2
	ldr r1, _08078C8C @ =_08078C90
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078C88: .4byte 0x0000023D
_08078C8C: .4byte _08078C90
_08078C90: @ jump table
	.4byte _08078CB4 @ case 0
	.4byte _08078CDC @ case 1
	.4byte _08078D18 @ case 2
	.4byte _08078D50 @ case 3
	.4byte _08078DA8 @ case 4
	.4byte _08078DCC @ case 5
	.4byte _08078DFC @ case 6
	.4byte _08078E34 @ case 7
	.4byte _08078E76 @ case 8
_08078CB4:
	ldr r1, _08078CD4 @ =gNonGameplayRam
	ldr r0, _08078CD8 @ =0x0000023D
	adds r3, r1, r0
	ldrb r0, [r3]
	cmp r0, #0x10
	bhi _08078CC2
	b _08078E76
_08078CC2:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	strb r2, [r3]
	b _08078E76
	.align 2, 0
_08078CD4: .4byte gNonGameplayRam
_08078CD8: .4byte 0x0000023D
_08078CDC:
	ldr r5, _08078D10 @ =gNonGameplayRam
	adds r1, r5, #0
	adds r1, #0x8e
	movs r4, #0
	movs r0, #0x74
	strh r0, [r1]
	subs r1, #2
	movs r0, #0x1c
	strh r0, [r1]
	movs r0, #2
	bl unk_78af0
	movs r0, #2
	bl MapScreenDrawSpecialOam
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08078D14 @ =0x0000023D
	adds r0, r5, r1
	strb r4, [r0]
	b _08078E76
	.align 2, 0
_08078D10: .4byte gNonGameplayRam
_08078D14: .4byte 0x0000023D
_08078D18:
	ldr r3, _08078D4C @ =gNonGameplayRam
	adds r0, r3, #0
	adds r0, #0x97
	ldrb r1, [r0]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08078D2C
	b _08078E76
_08078D2C:
	adds r0, r3, #0
	adds r0, #0xa3
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08078D3C
	b _08078E76
_08078D3C:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	b _08078DEA
	.align 2, 0
_08078D4C: .4byte gNonGameplayRam
_08078D50:
	ldr r3, _08078D9C @ =gNonGameplayRam
	ldr r2, _08078DA0 @ =0x0000023D
	adds r4, r3, r2
	ldrb r0, [r4]
	cmp r0, #0x10
	bhi _08078D5E
	b _08078E76
_08078D5E:
	ldrh r1, [r3, #4]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r3, #4]
	adds r1, r3, #0
	adds r1, #0x46
	movs r0, #8
	strh r0, [r1]
	ldr r0, _08078DA4 @ =0x085766E0
	ldrb r1, [r0, #2]
	adds r0, r3, #0
	adds r0, #0x44
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0x4e
	movs r0, #0xb
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4c
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	strb r2, [r4]
	b _08078E76
	.align 2, 0
_08078D9C: .4byte gNonGameplayRam
_08078DA0: .4byte 0x0000023D
_08078DA4: .4byte 0x085766E0
_08078DA8:
	ldr r3, _08078DC8 @ =gNonGameplayRam
	ldrh r1, [r3, #4]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _08078E76
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	b _08078DEC
	.align 2, 0
_08078DC8: .4byte gNonGameplayRam
_08078DCC:
	movs r0, #3
	bl unk_78af0
	ldr r3, _08078DF4 @ =gNonGameplayRam
	adds r0, r3, #0
	adds r0, #0x4e
	movs r2, #0
	strb r2, [r0]
	adds r0, #0x30
	strb r2, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #1
_08078DEA:
	strb r0, [r1]
_08078DEC:
	ldr r1, _08078DF8 @ =0x0000023D
	adds r0, r3, r1
	strb r2, [r0]
	b _08078E76
	.align 2, 0
_08078DF4: .4byte gNonGameplayRam
_08078DF8: .4byte 0x0000023D
_08078DFC:
	ldr r2, _08078E2C @ =gNonGameplayRam
	adds r0, r2, #0
	adds r0, #0x96
	ldrb r0, [r0]
	cmp r0, #0
	bne _08078E76
	adds r0, r2, #0
	adds r0, #0xa2
	ldrb r3, [r0]
	cmp r3, #0
	bne _08078E76
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r1, _08078E30 @ =0x0000023D
	adds r0, r2, r1
	strb r3, [r0]
	movs r0, #1
	bl MapScreenDrawSpecialOam
	b _08078E76
	.align 2, 0
_08078E2C: .4byte gNonGameplayRam
_08078E30: .4byte 0x0000023D
_08078E34:
	ldr r3, _08078E60 @ =gNonGameplayRam
	ldr r2, _08078E64 @ =0x0000023D
	adds r4, r3, r2
	ldrb r0, [r4]
	cmp r0, #0x10
	bls _08078E76
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #0
	strb r0, [r2]
	strb r1, [r4]
	ldrh r1, [r3, #4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08078E68
	movs r0, #2
	b _08078E72
	.align 2, 0
_08078E60: .4byte gNonGameplayRam
_08078E64: .4byte 0x0000023D
_08078E68:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08078E76
	movs r0, #4
_08078E72:
	eors r0, r1
	strh r0, [r3, #4]
_08078E76:
	ldr r2, _08078EA0 @ =gNonGameplayRam
	ldrb r0, [r2, #0x1b]
	cmp r0, #1
	bls _08078E98
	adds r3, r2, #0
	adds r3, #0x8a
	ldrb r0, [r3]
	cmp r0, #0x64
	bne _08078E98
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x88
	strb r1, [r0]
	adds r0, #1
_08078E96:
	strb r1, [r0]
_08078E98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08078EA0: .4byte gNonGameplayRam

	thumb_func_start NavigationConversationUpdatePanel
NavigationConversationUpdatePanel: @ 0x08078EA4
	push {r4, r5, lr}
	ldr r1, _08078EC0 @ =gNonGameplayRam
	ldrh r0, [r1, #4]
	movs r2, #1
	ands r2, r0
	adds r5, r1, #0
	cmp r2, #0
	bne _08078EC4
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _080790A8
	.align 2, 0
_08078EC0: .4byte gNonGameplayRam
_08078EC4:
	ldr r1, _08078EE8 @ =0x00000239
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0xd
	bls _08078EDC
	b _0807910E
_08078EDC:
	lsls r0, r0, #2
	ldr r1, _08078EEC @ =_08078EF0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08078EE8: .4byte 0x00000239
_08078EEC: .4byte _08078EF0
_08078EF0: @ jump table
	.4byte _08078F28 @ case 0
	.4byte _08078F3E @ case 1
	.4byte _08078F60 @ case 2
	.4byte _0807908C @ case 3
	.4byte _08078F68 @ case 4
	.4byte _08078F90 @ case 5
	.4byte _08078FE0 @ case 6
	.4byte _08079038 @ case 7
	.4byte _08079060 @ case 8
	.4byte _08079066 @ case 9
	.4byte _0807908C @ case 10
	.4byte _080790B4 @ case 11
	.4byte _080790EC @ case 12
	.4byte _0807910E @ case 13
_08078F28:
	adds r1, r5, #0
	adds r1, #0x5c
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x7c
	bne _08078F38
	b _080790D0
_08078F38:
	adds r0, r2, #0
	subs r0, #8
	b _080790C6
_08078F3E:
	ldr r2, _08078F5C @ =0x00000239
	adds r3, r5, r2
	ldrb r0, [r3]
	cmp r0, #8
	bhi _08078F4A
	b _0807910E
_08078F4A:
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0
	strb r1, [r0]
	b _0807910C
	.align 2, 0
_08078F5C: .4byte 0x00000239
_08078F60:
	movs r0, #2
	bl PauseScreenSetNavigationTextPanelOam
	b _08079040
_08078F68:
	movs r0, #3
	movs r1, #0x49
	bl UpdateMenuOamDataId
	ldr r1, _08078F88 @ =gNonGameplayRam
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	ldr r2, _08078F8C @ =0x00000239
	adds r1, r1, r2
	strb r3, [r1]
	b _0807910E
	.align 2, 0
_08078F88: .4byte gNonGameplayRam
_08078F8C: .4byte 0x00000239
_08078F90:
	adds r0, r5, #0
	adds r0, #0x5b
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08078FA0
	b _0807910E
_08078FA0:
	ldrh r1, [r5, #4]
	movs r0, #8
	movs r2, #0
	orrs r0, r1
	strh r0, [r5, #4]
	movs r0, #8
	strh r0, [r5, #0x3a]
	ldr r0, _08078FDC @ =0x085766E0
	ldrb r0, [r0]
	strh r0, [r5, #0x38]
	adds r0, r5, #0
	adds r0, #0x40
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldrb r0, [r5, #0x1c]
	cmp r0, #5
	beq _08078FCC
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0xb
	strb r0, [r1]
_08078FCC:
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	b _080790DE
	.align 2, 0
_08078FDC: .4byte 0x085766E0
_08078FE0:
	ldr r2, _08079004 @ =gNonGameplayRam
	ldrh r1, [r2, #4]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0807900C
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r1, _08079008 @ =0x00000239
	adds r0, r2, r1
	strb r3, [r0]
	b _0807901E
	.align 2, 0
_08079004: .4byte gNonGameplayRam
_08079008: .4byte 0x00000239
_0807900C:
	ldr r3, _08079030 @ =0x00000239
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _0807901E
	movs r0, #3
	movs r1, #0x4c
	bl UpdateMenuOamDataId
_0807901E:
	ldr r0, _08079034 @ =gNonGameplayRam
	ldr r2, _08079030 @ =0x00000239
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0x3c
	bls _0807910E
	movs r0, #0x3c
	strb r0, [r1]
	b _0807910E
	.align 2, 0
_08079030: .4byte 0x00000239
_08079034: .4byte gNonGameplayRam
_08079038:
	movs r0, #3
	movs r1, #0x4a
	bl UpdateMenuOamDataId
_08079040:
	ldr r1, _08079058 @ =gNonGameplayRam
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r1, r3
	ldrb r0, [r2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2]
	ldr r0, _0807905C @ =0x00000239
	adds r1, r1, r0
	strb r3, [r1]
	b _0807910E
	.align 2, 0
_08079058: .4byte gNonGameplayRam
_0807905C: .4byte 0x00000239
_08079060:
	adds r0, r5, #0
	adds r0, #0x5b
	b _08079090
_08079066:
	adds r0, r5, #0
	adds r0, #0x42
	movs r4, #0
	strb r4, [r0]
	movs r0, #3
	bl PauseScreenSetNavigationTextPanelOam
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _08079088 @ =0x00000239
	adds r0, r5, r1
	strb r4, [r0]
	b _0807910E
	.align 2, 0
_08079088: .4byte 0x00000239
_0807908C:
	adds r0, r5, #0
	adds r0, #0x67
_08079090:
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807910E
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
_080790A8:
	ldr r3, _080790B0 @ =0x00000239
	adds r0, r5, r3
	strb r2, [r0]
	b _0807910E
	.align 2, 0
_080790B0: .4byte 0x00000239
_080790B4:
	adds r1, r5, #0
	adds r1, #0x5c
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xcc
	beq _080790D0
	adds r0, r2, #0
	adds r0, #8
_080790C6:
	strh r0, [r1]
	movs r0, #0
	bl PauseScreenSetNavigationTextPanelOam
	b _0807910E
_080790D0:
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
_080790DE:
	ldr r1, _080790E8 @ =0x00000239
	adds r0, r5, r1
	strb r2, [r0]
	b _0807910E
	.align 2, 0
_080790E8: .4byte 0x00000239
_080790EC:
	ldr r2, _08079114 @ =0x00000239
	adds r3, r5, r2
	ldrb r0, [r3]
	cmp r0, #8
	bls _0807910E
	ldrh r0, [r5, #4]
	movs r1, #1
	eors r0, r1
	movs r2, #0
	strh r0, [r5, #4]
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0807910C:
	strb r2, [r3]
_0807910E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08079114: .4byte 0x00000239

	thumb_func_start GetCharacterWidth
GetCharacterWidth: @ 0x08079118
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _0807912C @ =0x0000049F
	cmp r1, r0
	bhi _08079134
	ldr r0, _08079130 @ =0x08576234
	adds r0, r1, r0
	ldrb r0, [r0]
	b _08079136
	.align 2, 0
_0807912C: .4byte 0x0000049F
_08079130: .4byte 0x08576234
_08079134:
	movs r0, #0xa
_08079136:
	pop {r1}
	bx r1
	.align 2, 0

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

	thumb_func_start DrawLocationText
DrawLocationText: @ 0x08079740
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r2, sp
	ldr r3, _080797AC @ =0x0000FFFF
	adds r1, r3, #0
	strh r1, [r2]
	ldr r4, _080797B0 @ =0x040000D4
	str r2, [r4]
	movs r6, #0x80
	lsls r6, r6, #0x12
	str r6, [r4, #4]
	ldr r1, _080797B4 @ =0x81000400
	str r1, [r4, #8]
	ldr r1, [r4, #8]
	ldr r2, _080797B8 @ =0x0879CDD8
	ldr r1, _080797BC @ =0x03000011
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #4
	movs r0, #1
	bl DrawLocationTextCharacters
	str r6, [r4]
	lsls r5, r5, #0xb
	ldr r1, _080797C0 @ =0x06014000
	adds r0, r5, r1
	str r0, [r4, #4]
	ldr r1, _080797C4 @ =0x840000E0
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080797C8 @ =0x02000400
	str r0, [r4]
	ldr r3, _080797CC @ =0x06014400
	adds r5, r5, r3
	str r5, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080797AC: .4byte 0x0000FFFF
_080797B0: .4byte 0x040000D4
_080797B4: .4byte 0x81000400
_080797B8: .4byte 0x0879CDD8
_080797BC: .4byte 0x03000011
_080797C0: .4byte 0x06014000
_080797C4: .4byte 0x840000E0
_080797C8: .4byte 0x02000400
_080797CC: .4byte 0x06014400
