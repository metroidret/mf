    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start StatusScreenHandler
StatusScreenHandler: @ 0x0807E678
	push {lr}
	ldr r0, _0807E6A0 @ =gChangedInput
	ldrh r1, [r0]
	ldr r0, _0807E6A4 @ =0x00000302
	ands r0, r1
	cmp r0, #0
	beq _0807E69A
	ldr r3, _0807E6A8 @ =gNonGameplayRam
	ldrb r2, [r3, #7]
	cmp r2, #0
	bne _0807E69A
	adds r1, r3, #0
	adds r1, #0x28
	movs r0, #7
	strb r0, [r1]
	strb r2, [r3, #6]
	strb r2, [r3, #7]
_0807E69A:
	pop {r0}
	bx r0
	.align 2, 0
_0807E6A0: .4byte gChangedInput
_0807E6A4: .4byte 0x00000302
_0807E6A8: .4byte gNonGameplayRam

	thumb_func_start StatusScreenDrawEverything
StatusScreenDrawEverything: @ 0x0807E6AC
	push {r4, lr}
	ldr r4, _0807E714 @ =gEquipment
	ldrb r1, [r4, #0xa]
	movs r0, #0
	bl StatusScreenDrawBeamOrSuit
	ldrb r1, [r4, #0xb]
	movs r0, #1
	bl StatusScreenDrawMissileOrBomb
	ldrb r1, [r4, #0xc]
	movs r0, #3
	bl StatusScreenDrawBeamOrSuit
	ldrb r1, [r4, #0xb]
	movs r0, #2
	bl StatusScreenDrawMissileOrBomb
	ldrb r1, [r4, #0xc]
	movs r0, #4
	bl StatusScreenDrawMisc
	ldrh r1, [r4]
	movs r0, #5
	movs r2, #6
	movs r3, #0
	bl StatusScreenDrawNumber
	ldrh r1, [r4, #2]
	movs r0, #6
	movs r2, #3
	movs r3, #1
	bl StatusScreenDrawNumber
	ldrb r1, [r4, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807E718
	ldrh r1, [r4, #4]
	movs r0, #7
	movs r2, #6
	movs r3, #0
	bl StatusScreenDrawNumber
	ldrh r1, [r4, #6]
	movs r0, #8
	movs r2, #3
	movs r3, #1
	bl StatusScreenDrawNumber
	b _0807E71E
	.align 2, 0
_0807E714: .4byte gEquipment
_0807E718:
	movs r0, #1
	bl StatusScreenRemoveAmmoHeader
_0807E71E:
	ldr r4, _0807E744 @ =gEquipment
	ldrb r1, [r4, #0xb]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0x30
	bne _0807E748
	ldrb r1, [r4, #8]
	movs r0, #9
	movs r2, #6
	movs r3, #0
	bl StatusScreenDrawNumber
	ldrb r1, [r4, #9]
	movs r0, #0xa
	movs r2, #3
	movs r3, #1
	bl StatusScreenDrawNumber
	b _0807E74E
	.align 2, 0
_0807E744: .4byte gEquipment
_0807E748:
	movs r0, #2
	bl StatusScreenRemoveAmmoHeader
_0807E74E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start StatusScreenDrawNumber
StatusScreenDrawNumber: @ 0x0807E754
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sl, r3
	ldr r3, _0807E7D0 @ =0x0858217C
	lsls r2, r0, #2
	adds r2, r2, r0
	adds r0, r2, r3
	ldrb r1, [r0]
	lsls r1, r1, #5
	adds r0, r3, #2
	adds r0, r2, r0
	ldrb r4, [r0]
	adds r1, r1, r4
	lsls r1, r1, #1
	ldr r0, _0807E7D4 @ =0x0600C800
	adds r0, r0, r1
	mov sb, r0
	adds r3, #3
	adds r2, r2, r3
	ldrb r0, [r2]
	subs r6, r0, r4
	ldr r1, _0807E7D8 @ =0x08576180
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r6, #1
	movs r7, #0
	movs r5, #0
	cmp r4, #0
	ble _0807E808
_0807E7AC:
	ldr r0, [sp]
	adds r1, r4, #0
	bl __divsi3
	movs r1, #0xa
	bl __modsi3
	adds r2, r0, #0
	cmp r2, #0
	bne _0807E7E0
	cmp r7, #0
	bne _0807E7DC
	movs r2, #0x8c
	mov r3, sl
	cmp r3, #0
	beq _0807E7E4
	b _0807E7F6
	.align 2, 0
_0807E7D0: .4byte 0x0858217C
_0807E7D4: .4byte 0x0600C800
_0807E7D8: .4byte 0x08576180
_0807E7DC:
	movs r2, #0x80
	b _0807E7E8
_0807E7E0:
	movs r7, #1
	adds r2, #0x80
_0807E7E4:
	cmp r2, #0
	beq _0807E7F6
_0807E7E8:
	lsls r1, r5, #1
	add r1, sb
	mov r3, r8
	lsls r0, r3, #0xc
	orrs r0, r2
	strh r0, [r1]
	b _0807E7F8
_0807E7F6:
	subs r5, #1
_0807E7F8:
	adds r0, r4, #0
	movs r1, #0xa
	bl __divsi3
	adds r4, r0, #0
	adds r5, #1
	cmp r4, #0
	bgt _0807E7AC
_0807E808:
	cmp r6, r5
	beq _0807E822
	mov r0, r8
	lsls r2, r0, #0xc
	movs r0, #0x8c
	orrs r2, r0
	lsls r0, r5, #1
	add r0, sb
_0807E818:
	strh r2, [r0]
	adds r0, #2
	adds r5, #1
	cmp r6, r5
	bne _0807E818
_0807E822:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StatusScreenDrawBeamOrSuit
StatusScreenDrawBeamOrSuit: @ 0x0807E834
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r0, #0
	mov sb, r0
	movs r2, #0
	ldr r0, _0807E964 @ =0x0857617A
	adds r1, r7, r0
	ldrb r1, [r1]
	cmp sb, r1
	bge _0807E8F8
	ldr r1, _0807E968 @ =0x0858217C
	lsls r3, r7, #2
	mov sl, r3
	adds r5, r3, r7
	ldr r0, _0807E96C @ =0x085821B3
	adds r0, #2
	adds r0, r5, r0
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r1, #3
	adds r6, r5, r0
	str r6, [sp, #0x14]
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #1
	str r0, [sp, #4]
	adds r1, #2
	adds r1, r5, r1
	ldrb r0, [r1]
	mov r8, r0
	str r5, [sp, #0xc]
	str r1, [sp, #0x10]
_0807E886:
	ldr r1, [sp, #4]
	adds r0, r1, r2
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r3, _0807E96C @ =0x085821B3
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp, #8]
	adds r6, r0, r1
	ldr r0, _0807E970 @ =0x0879BEA8
	add r0, sl
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, [sp]
	ands r0, r3
	adds r2, #1
	cmp r0, #0
	beq _0807E8EE
	mov sb, r2
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, r8
	subs r0, r0, r2
	mov r2, sb
	cmp r0, #0
	blt _0807E8EE
	ldr r3, [sp, #0xc]
	ldr r1, _0807E974 @ =0x0858217F
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r3, [sp, #0x10]
	ldrb r0, [r3]
	subs r1, r1, r0
	lsls r0, r6, #1
	ldr r6, _0807E978 @ =0x0600C800
	adds r4, r0, r6
	mov r3, ip
	lsls r0, r3, #1
	adds r3, r0, r6
	adds r1, #1
_0807E8E0:
	ldrh r0, [r4]
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _0807E8E0
_0807E8EE:
	ldr r6, _0807E964 @ =0x0857617A
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r2, r0
	blt _0807E886
_0807E8F8:
	mov r0, sb
	cmp r0, #0
	beq _0807E954
	ldr r3, _0807E968 @ =0x0858217C
	lsls r2, r7, #2
	adds r2, r2, r7
	adds r0, r2, r3
	mov r1, sb
	adds r1, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r0, r3, #2
	adds r0, r2, r0
	ldrb r4, [r0]
	adds r1, r1, r4
	mov ip, r1
	ldr r1, _0807E96C @ =0x085821B3
	adds r0, r1, #1
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, #2
	adds r1, r2, r1
	lsls r0, r0, #5
	ldrb r1, [r1]
	adds r6, r0, r1
	adds r3, #3
	adds r2, r2, r3
	ldrb r0, [r2]
	subs r1, r0, r4
	cmp r1, #0
	blt _0807E954
	lsls r0, r6, #1
	ldr r2, _0807E978 @ =0x0600C800
	adds r4, r0, r2
	mov r3, ip
	lsls r0, r3, #1
	adds r3, r0, r2
	adds r1, #1
_0807E946:
	ldrh r0, [r4]
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _0807E946
_0807E954:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E964: .4byte 0x0857617A
_0807E968: .4byte 0x0858217C
_0807E96C: .4byte 0x085821B3
_0807E970: .4byte 0x0879BEA8
_0807E974: .4byte 0x0858217F
_0807E978: .4byte 0x0600C800

	thumb_func_start StatusScreenDrawMissileOrBomb
StatusScreenDrawMissileOrBomb: @ 0x0807E97C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	movs r2, #0
	ldr r0, _0807EA30 @ =0x0857617A
	adds r1, r7, r0
	ldrb r1, [r1]
	cmp r2, r1
	bge _0807EA5C
	ldr r1, _0807EA34 @ =0x0858217C
	lsls r3, r7, #2
	mov sl, r3
	adds r5, r3, r7
	ldr r0, _0807EA38 @ =0x085821B3
	adds r0, #2
	adds r0, r5, r0
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r1, #3
	adds r0, r5, r0
	str r0, [sp, #0x14]
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, #2
	adds r1, r5, r1
	ldrb r6, [r1]
	mov sb, r6
	str r5, [sp, #0xc]
	str r1, [sp, #0x10]
	lsls r0, r0, #5
	mov ip, r0
_0807E9D0:
	mov r0, ip
	add r0, sb
	mov r8, r0
	ldr r1, _0807EA38 @ =0x085821B3
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r3, [sp, #8]
	adds r6, r0, r3
	ldr r0, _0807EA3C @ =0x0879BEA8
	add r0, sl
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r1, [sp]
	ands r0, r1
	cmp r0, #0
	beq _0807EA48
	str r2, [sp, #4]
	ldr r3, [sp, #0x14]
	ldrb r0, [r3]
	mov r1, sb
	subs r0, r0, r1
	cmp r0, #0
	blt _0807EA4C
	ldr r0, _0807EA40 @ =0x0858217F
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	ldrb r1, [r0]
	ldr r3, [sp, #0x10]
	ldrb r0, [r3]
	subs r1, r1, r0
	lsls r0, r6, #1
	ldr r6, _0807EA44 @ =0x0600C800
	adds r4, r0, r6
	mov r3, r8
	lsls r0, r3, #1
	adds r3, r0, r6
	adds r1, #1
_0807EA20:
	ldrh r0, [r4]
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _0807EA20
	b _0807EA4C
	.align 2, 0
_0807EA30: .4byte 0x0857617A
_0807EA34: .4byte 0x0858217C
_0807EA38: .4byte 0x085821B3
_0807EA3C: .4byte 0x0879BEA8
_0807EA40: .4byte 0x0858217F
_0807EA44: .4byte 0x0600C800
_0807EA48:
	cmp r2, #0
	beq _0807EAB8
_0807EA4C:
	movs r6, #0x20
	add ip, r6
	adds r2, #1
	ldr r1, _0807EAC8 @ =0x0857617A
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r2, r0
	blt _0807E9D0
_0807EA5C:
	ldr r2, [sp, #4]
	cmp r2, #0
	blt _0807EAB8
	ldr r3, _0807EACC @ =0x0858217C
	lsls r2, r7, #2
	adds r2, r2, r7
	adds r0, r2, r3
	ldr r1, [sp, #4]
	adds r1, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r0, r3, #2
	adds r0, r2, r0
	ldrb r4, [r0]
	adds r1, r1, r4
	mov r8, r1
	ldr r1, _0807EAD0 @ =0x085821B3
	adds r0, r1, #1
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, #2
	adds r1, r2, r1
	lsls r0, r0, #5
	ldrb r1, [r1]
	adds r6, r0, r1
	adds r3, #3
	adds r2, r2, r3
	ldrb r0, [r2]
	subs r1, r0, r4
	cmp r1, #0
	blt _0807EAB8
	lsls r0, r6, #1
	ldr r3, _0807EAD4 @ =0x0600C800
	adds r4, r0, r3
	mov r6, r8
	lsls r0, r6, #1
	adds r3, r0, r3
	adds r1, #1
_0807EAAA:
	ldrh r0, [r4]
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _0807EAAA
_0807EAB8:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807EAC8: .4byte 0x0857617A
_0807EACC: .4byte 0x0858217C
_0807EAD0: .4byte 0x085821B3
_0807EAD4: .4byte 0x0600C800

	thumb_func_start StatusScreenDrawMisc
StatusScreenDrawMisc: @ 0x0807EAD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r4, #0
	ldr r0, _0807EBF8 @ =0x0857617A
	mov r2, r8
	adds r1, r2, r0
	ldrb r1, [r1]
	cmp r4, r1
	bge _0807EB9C
	ldr r1, _0807EBFC @ =0x0858217C
	lsls r2, r2, #2
	mov sb, r2
	add r2, r8
	ldr r3, _0807EC00 @ =0x085821B3
	mov sl, r3
	mov r0, sl
	adds r0, #2
	adds r0, r2, r0
	ldrb r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r1, #3
	adds r6, r2, r0
	str r6, [sp, #0x1c]
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r0, #1
	str r0, [sp, #8]
	adds r1, #2
	adds r1, r2, r1
	ldrb r7, [r1]
	str r2, [sp, #0x10]
	mov ip, r1
_0807EB30:
	ldr r1, [sp, #8]
	adds r0, r1, r4
	lsls r0, r0, #5
	adds r6, r0, r7
	mov r3, sl
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	ldr r1, [sp, #0xc]
	adds r3, r0, r1
	ldr r0, _0807EC04 @ =0x0879BEA8
	add r0, sb
	ldr r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r1, [sp]
	ands r0, r1
	adds r5, r4, #1
	cmp r0, #0
	beq _0807EB90
	str r5, [sp, #4]
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4]
	subs r0, r0, r7
	cmp r0, #0
	blt _0807EB90
	ldr r1, [sp, #0x10]
	ldr r4, _0807EC08 @ =0x0858217F
	adds r0, r1, r4
	ldrb r1, [r0]
	mov r4, ip
	ldrb r0, [r4]
	subs r1, r1, r0
	lsls r0, r3, #1
	ldr r3, _0807EC0C @ =0x0600C800
	adds r4, r0, r3
	lsls r0, r6, #1
	adds r3, r0, r3
	adds r1, #1
_0807EB82:
	ldrh r0, [r4]
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _0807EB82
_0807EB90:
	adds r4, r5, #0
	ldr r0, _0807EBF8 @ =0x0857617A
	add r0, r8
	ldrb r0, [r0]
	cmp r4, r0
	blt _0807EB30
_0807EB9C:
	ldr r4, [sp, #4]
	cmp r4, #0
	beq _0807EC6C
	movs r4, #0
	ldr r1, _0807EBFC @ =0x0858217C
	mov r6, r8
	lsls r6, r6, #2
	str r6, [sp, #0x14]
	adds r7, r6, #0
	add r7, r8
	adds r2, r1, #2
	adds r0, r7, r2
	mov ip, r0
	ldr r0, _0807EC00 @ =0x085821B3
	adds r0, #2
	adds r0, r0, r7
	mov sl, r0
	adds r2, r7, r1
	mov sb, r2
	ldr r0, _0807EC00 @ =0x085821B3
	adds r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x18]
	ldr r3, _0807EC08 @ =0x0858217F
	adds r3, r7, r3
	str r3, [sp, #0x20]
_0807EBD0:
	cmp r4, #0
	bne _0807EC10
	ldr r6, [sp, #4]
	adds r6, #1
	str r6, [sp, #4]
	mov r1, sb
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #5
	mov r2, ip
	ldrb r2, [r2]
	adds r6, r0, r2
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
	lsls r0, r0, #5
	mov r1, sl
	ldrb r1, [r1]
	adds r3, r0, r1
	b _0807EC2A
	.align 2, 0
_0807EBF8: .4byte 0x0857617A
_0807EBFC: .4byte 0x0858217C
_0807EC00: .4byte 0x085821B3
_0807EC04: .4byte 0x0879BEA8
_0807EC08: .4byte 0x0858217F
_0807EC0C: .4byte 0x0600C800
_0807EC10:
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #5
	mov r3, ip
	ldrb r3, [r3]
	adds r6, r0, r3
	ldr r1, _0807EC7C @ =0x085821B3
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #5
	mov r2, sl
	ldrb r2, [r2]
	adds r3, r0, r2
_0807EC2A:
	ldr r0, [sp, #0x20]
	ldrb r1, [r0]
	mov r2, ip
	ldrb r0, [r2]
	subs r1, r1, r0
	adds r5, r4, #1
	cmp r1, #0
	blt _0807EC66
	ldr r1, [sp, #0x14]
	add r1, r8
	ldr r4, _0807EC80 @ =0x0858217F
	adds r0, r1, r4
	ldrb r2, [r0]
	ldr r0, _0807EC84 @ =0x0858217E
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r2, r2, r0
	lsls r0, r3, #1
	ldr r1, _0807EC88 @ =0x0600C800
	adds r4, r0, r1
	lsls r0, r6, #1
	adds r3, r0, r1
	adds r1, r2, #1
_0807EC58:
	ldrh r0, [r4]
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bne _0807EC58
_0807EC66:
	adds r4, r5, #0
	cmp r4, #1
	ble _0807EBD0
_0807EC6C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807EC7C: .4byte 0x085821B3
_0807EC80: .4byte 0x0858217F
_0807EC84: .4byte 0x0858217E
_0807EC88: .4byte 0x0600C800

	thumb_func_start StatusScreenRemoveAmmoHeader
StatusScreenRemoveAmmoHeader: @ 0x0807EC8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0807ECA2
	movs r1, #1
	b _0807ECA8
_0807ECA2:
	cmp r0, #2
	bne _0807ED0A
	movs r1, #2
_0807ECA8:
	ldr r0, _0807ED18 @ =0x0600C800
	mov r8, r0
	movs r3, #0
	lsls r1, r1, #2
	ldr r5, _0807ED1C @ =0x085821D6
	adds r0, r1, r5
	ldrb r0, [r0]
	mov sl, r0
	ldrb r7, [r5, #2]
	ldrb r0, [r5, #3]
	subs r0, r0, r7
	mov sb, r0
	adds r0, r5, #2
	adds r1, r1, r0
	ldrb r1, [r1]
	mov ip, r1
_0807ECC8:
	mov r1, sl
	adds r0, r1, r3
	lsls r0, r0, #5
	mov r2, ip
	adds r4, r0, r2
	ldrb r0, [r5]
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r2, r0, r7
	adds r6, r3, #1
	mov r0, sb
	cmp r0, #0
	blt _0807ED04
	ldrb r1, [r5, #3]
	ldrb r0, [r5, #2]
	subs r1, r1, r0
	lsls r0, r2, #1
	ldr r2, _0807ED18 @ =0x0600C800
	adds r3, r0, r2
	lsls r0, r4, #1
	mov r4, r8
	adds r2, r0, r4
	adds r1, #1
_0807ECF6:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _0807ECF6
_0807ED04:
	adds r3, r6, #0
	cmp r3, #1
	ble _0807ECC8
_0807ED0A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807ED18: .4byte 0x0600C800
_0807ED1C: .4byte 0x085821D6

	thumb_func_start EasySleepMenuHandler
EasySleepMenuHandler: @ 0x0807ED20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	ldr r0, _0807ED40 @ =gNonGameplayRam
	ldrb r1, [r0, #7]
	adds r3, r0, #0
	cmp r1, #5
	bls _0807ED36
	b _0807EE82
_0807ED36:
	lsls r0, r1, #2
	ldr r1, _0807ED44 @ =_0807ED48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807ED40: .4byte gNonGameplayRam
_0807ED44: .4byte _0807ED48
_0807ED48: @ jump table
	.4byte _0807ED60 @ case 0
	.4byte _0807ED90 @ case 1
	.4byte _0807EDE4 @ case 2
	.4byte _0807EDFE @ case 3
	.4byte _0807EE12 @ case 4
	.4byte _0807EE78 @ case 5
_0807ED60:
	ldr r0, _0807ED78 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807ED80
	ldr r0, _0807ED7C @ =0x000001FB
	bl SoundPlay
	movs r7, #1
	b _0807EE86
	.align 2, 0
_0807ED78: .4byte gChangedInput
_0807ED7C: .4byte 0x000001FB
_0807ED80:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0807EDD4
	movs r0, #1
	strb r0, [r3, #7]
	movs r0, #0x3c
	b _0807EDC8
_0807ED90:
	ldr r0, _0807EDB0 @ =gChangedInput
	ldrh r1, [r0]
	movs r2, #1
	ands r2, r1
	cmp r2, #0
	beq _0807EDBC
	ldr r0, _0807EDB4 @ =0x000001FB
	bl SoundPlay
	ldr r1, _0807EDB8 @ =gNonGameplayRam
	movs r2, #0
	movs r0, #2
	strb r0, [r1, #7]
	strb r2, [r1, #6]
	b _0807EE82
	.align 2, 0
_0807EDB0: .4byte gChangedInput
_0807EDB4: .4byte 0x000001FB
_0807EDB8: .4byte gNonGameplayRam
_0807EDBC:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0807EDD4
	strb r2, [r3, #7]
	movs r0, #0x8c
_0807EDC8:
	strh r0, [r3, #0x3a]
	movs r0, #0xfd
	lsls r0, r0, #1
	bl SoundPlay
	b _0807EE82
_0807EDD4:
	ldr r0, _0807EDE0 @ =0x00000302
	ands r0, r1
	cmp r0, #0
	beq _0807EE82
	movs r7, #1
	b _0807EE86
	.align 2, 0
_0807EDE0: .4byte 0x00000302
_0807EDE4:
	ldrb r0, [r3, #6]
	adds r0, #1
	strb r0, [r3, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _0807EE82
	ldrb r0, [r3, #7]
	adds r0, #1
	strb r0, [r3, #7]
	movs r0, #0
	strb r0, [r3, #6]
	b _0807EE82
_0807EDFE:
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrh r0, [r2]
	movs r1, #0x80
	eors r0, r1
	strh r0, [r2]
	ldrb r0, [r3, #7]
	adds r0, #1
	b _0807EE80
_0807EE12:
	ldr r1, _0807EE64 @ =0x04000132
	ldr r2, _0807EE68 @ =0x0000C304
	adds r0, r2, #0
	strh r0, [r1]
	ldr r6, _0807EE6C @ =0x04000208
	movs r0, #0
	mov sb, r0
	strh r0, [r6]
	ldr r5, _0807EE70 @ =0x04000200
	ldrh r4, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r1, #0
	strh r0, [r5]
	movs r2, #1
	mov r8, r2
	strh r2, [r6]
	bl SoundBias0
	svc #3
	bl SoundBias1
	mov r0, sb
	strh r0, [r6]
	strh r4, [r5]
	mov r1, r8
	strh r1, [r6]
	ldr r2, _0807EE74 @ =gNonGameplayRam
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r3, r2, r0
	ldrh r0, [r3]
	movs r1, #0x80
	eors r0, r1
	strh r0, [r3]
	movs r0, #0x8c
	strh r0, [r2, #0x3a]
	ldrb r0, [r2, #7]
	adds r0, #1
	strb r0, [r2, #7]
	b _0807EE82
	.align 2, 0
_0807EE64: .4byte 0x04000132
_0807EE68: .4byte 0x0000C304
_0807EE6C: .4byte 0x04000208
_0807EE70: .4byte 0x04000200
_0807EE74: .4byte gNonGameplayRam
_0807EE78:
	ldr r0, _0807EE9C @ =gButtonInput
	ldrh r0, [r0]
	cmp r0, #0
	bne _0807EE82
_0807EE80:
	strb r0, [r3, #7]
_0807EE82:
	cmp r7, #0
	beq _0807EE8E
_0807EE86:
	ldr r1, _0807EEA0 @ =gNonGameplayRam
	movs r0, #0
	strb r0, [r1, #7]
	strb r0, [r1, #6]
_0807EE8E:
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807EE9C: .4byte gButtonInput
_0807EEA0: .4byte gNonGameplayRam

	thumb_func_start Sram_ReadAll
Sram_ReadAll: @ 0x0807EEA4
	push {lr}
	bl Sram_ReadHeader
	bl unk_7fb84
	bl SramRead_MostRecentSaveFile
	bl SramRead_Language
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Sram_WriteHeader
Sram_WriteHeader: @ 0x0807EEBC
	push {r4, r5, lr}
	ldr r4, _0807EF1C @ =0x02038000
	movs r0, #0x30
	strb r0, [r4, #8]
	movs r0, #0x31
	strb r0, [r4, #9]
	ldr r0, _0807EF20 @ =0x03000010
	ldrb r0, [r0]
	strb r0, [r4, #0xa]
	movs r0, #2
	strb r0, [r4, #0xb]
	movs r2, #0
	adds r5, r4, #0
	adds r5, #0xc
	ldr r3, _0807EF24 @ =0x08582248
_0807EEDA:
	adds r0, r5, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0x13
	ble _0807EEDA
	movs r0, #0
	str r0, [r4]
	subs r0, #1
	str r0, [r4, #4]
	ldr r3, _0807EF1C @ =0x02038000
	movs r1, #0
	movs r2, #7
_0807EEF6:
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	subs r2, #1
	cmp r2, #0
	bge _0807EEF6
	str r1, [r4]
	mvns r0, r1
	str r0, [r4, #4]
	bl unk_c98
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807EF1C: .4byte 0x02038000
_0807EF20: .4byte 0x03000010
_0807EF24: .4byte 0x08582248

	thumb_func_start Sram_ReadHeader
Sram_ReadHeader: @ 0x0807EF28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	bl SramTestFlash
	ldr r0, _0807EFA0 @ =0x03000B8E
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807EF42
	bl ReadSramHeaderToEwram
_0807EF42:
	movs r0, #0
	bl Sram_VerifyHeader
	adds r6, r0, #0
	movs r0, #1
	bl Sram_VerifyHeader
	mov sb, r0
	movs r0, #2
	bl Sram_VerifyHeader
	mov r8, r0
	cmp r6, #0
	beq _0807F00C
	mov r0, sp
	ldr r1, _0807EFA4 @ =0x0000FFFF
	adds r2, r1, #0
	strh r2, [r0]
	ldr r4, _0807EFA8 @ =0x040000D4
	str r0, [r4]
	ldr r5, _0807EFAC @ =0x02038000
	str r5, [r4, #4]
	ldr r1, _0807EFB0 @ =0x81000040
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, r8
	cmp r0, #0
	beq _0807EFD8
	mov r0, sp
	strh r2, [r0]
	str r0, [r4]
	ldr r0, _0807EFB4 @ =0x0203F100
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, sb
	cmp r0, #0
	beq _0807EFBC
	mov r0, sp
	strh r2, [r0]
	str r0, [r4]
	ldr r0, _0807EFB8 @ =0x02038080
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	b _0807F034
	.align 2, 0
_0807EFA0: .4byte 0x03000B8E
_0807EFA4: .4byte 0x0000FFFF
_0807EFA8: .4byte 0x040000D4
_0807EFAC: .4byte 0x02038000
_0807EFB0: .4byte 0x81000040
_0807EFB4: .4byte 0x0203F100
_0807EFB8: .4byte 0x02038080
_0807EFBC:
	ldr r0, _0807EFD0 @ =0x02038080
	str r0, [r4]
	str r5, [r4, #4]
	ldr r0, _0807EFD4 @ =0x80000040
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r6, #0
	bl unk_c98
	b _0807F034
	.align 2, 0
_0807EFD0: .4byte 0x02038080
_0807EFD4: .4byte 0x80000040
_0807EFD8:
	ldr r0, _0807F000 @ =0x0203F100
	str r0, [r4]
	str r5, [r4, #4]
	ldr r7, _0807F004 @ =0x80000040
	str r7, [r4, #8]
	ldr r0, [r4, #8]
	movs r6, #0
	bl unk_c98
	mov r1, sb
	cmp r1, #0
	beq _0807F034
	str r5, [r4]
	ldr r0, _0807F008 @ =0x02038080
	str r0, [r4, #4]
	str r7, [r4, #8]
	ldr r0, [r4, #8]
	bl unk_cd8
	b _0807F034
	.align 2, 0
_0807F000: .4byte 0x0203F100
_0807F004: .4byte 0x80000040
_0807F008: .4byte 0x02038080
_0807F00C:
	ldr r4, _0807F040 @ =0x040000D4
	ldr r7, _0807F044 @ =0x02038000
	str r7, [r4]
	ldr r0, _0807F048 @ =0x02038080
	str r0, [r4, #4]
	ldr r5, _0807F04C @ =0x80000040
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl unk_cd8
	mov r0, r8
	cmp r0, #0
	beq _0807F034
	str r7, [r4]
	ldr r0, _0807F050 @ =0x0203F100
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl unk_cf0
_0807F034:
	cmp r6, #0
	bne _0807F058
	ldr r0, _0807F054 @ =0x03000010
	strb r6, [r0]
	b _0807F066
	.align 2, 0
_0807F040: .4byte 0x040000D4
_0807F044: .4byte 0x02038000
_0807F048: .4byte 0x02038080
_0807F04C: .4byte 0x80000040
_0807F050: .4byte 0x0203F100
_0807F054: .4byte 0x03000010
_0807F058:
	bl EraseSram
	ldr r1, _0807F074 @ =0x03000010
	movs r0, #0
	strb r0, [r1]
	bl Sram_WriteHeader
_0807F066:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F074: .4byte 0x03000010

	thumb_func_start Sram_VerifyHeader
Sram_VerifyHeader: @ 0x0807F078
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0
	ldr r1, _0807F0EC @ =0x0203F100
	cmp r0, #2
	beq _0807F08E
	ldr r1, _0807F0F0 @ =0x02038000
	cmp r0, #1
	bne _0807F08E
	adds r1, #0x80
_0807F08E:
	movs r2, #0
	ldr r7, [r1]
	adds r5, r1, #0
	adds r5, #0xc
	ldr r0, [r1, #4]
	mov ip, r0
	movs r3, #7
_0807F09C:
	ldm r1!, {r0}
	adds r2, r2, r0
	ldm r1!, {r0}
	adds r2, r2, r0
	ldm r1!, {r0}
	adds r2, r2, r0
	ldm r1!, {r0}
	adds r2, r2, r0
	subs r3, #1
	cmp r3, #0
	bge _0807F09C
	cmp r7, r2
	beq _0807F0BA
	movs r0, #1
	orrs r4, r0
_0807F0BA:
	movs r3, #0
	adds r2, r5, #0
	ldr r6, _0807F0F4 @ =0x08582248
	movs r5, #2
_0807F0C2:
	adds r0, r2, r3
	adds r1, r3, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0807F0D0
	orrs r4, r5
_0807F0D0:
	adds r3, #1
	cmp r3, #0x13
	ble _0807F0C2
	mov r1, ip
	mvns r0, r1
	cmp r7, r0
	beq _0807F0E2
	movs r0, #4
	orrs r4, r0
_0807F0E2:
	adds r0, r4, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807F0EC: .4byte 0x0203F100
_0807F0F0: .4byte 0x02038000
_0807F0F4: .4byte 0x08582248

	thumb_func_start Sram_ProcessIntroSave
Sram_ProcessIntroSave: @ 0x0807F0F8
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r3, r1, #0
	ldr r6, _0807F128 @ =0x03000B94
	ldr r4, _0807F12C @ =0x03000B8D
	ldrb r0, [r4]
	lsls r2, r0, #2
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r5, [r0, #0xf]
	cmp r5, #0
	beq _0807F17C
	cmp r1, #2
	bgt _0807F130
	cmp r1, #1
	blt _0807F120
	b _0807F222
_0807F120:
	cmp r1, #0
	beq _0807F136
	b _0807F21C
	.align 2, 0
_0807F128: .4byte 0x03000B94
_0807F12C: .4byte 0x03000B8D
_0807F130:
	cmp r1, #3
	beq _0807F158
	b _0807F21C
_0807F136:
	ldr r1, _0807F150 @ =gDisableSoftReset
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0807F154 @ =0x03000014
	movs r2, #1
	strb r2, [r0, #1]
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	strb r2, [r0, #0x11]
	b _0807F222
	.align 2, 0
_0807F150: .4byte gDisableSoftReset
_0807F154: .4byte 0x03000014
_0807F158:
	ldr r0, _0807F174 @ =0x0858225C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, _0807F178 @ =0x08582268
	adds r0, r2, r0
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	b _0807F21C
	.align 2, 0
_0807F174: .4byte 0x0858225C
_0807F178: .4byte 0x08582268
_0807F17C:
	cmp r1, #1
	beq _0807F1E4
	cmp r1, #1
	bgt _0807F18A
	cmp r1, #0
	beq _0807F194
	b _0807F21C
_0807F18A:
	cmp r3, #2
	beq _0807F1EA
	cmp r3, #3
	beq _0807F1F0
	b _0807F21C
_0807F194:
	ldr r1, _0807F1D8 @ =gDisableSoftReset
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0807F1DC @ =0x03000014
	movs r2, #1
	strb r2, [r3, #1]
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	strb r2, [r0, #0x11]
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #0x10]
	strb r0, [r3]
	ldr r1, _0807F1E0 @ =0x0858225C
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r3, #0xc0
	lsls r3, r3, #2
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	bl BitFill
	b _0807F222
	.align 2, 0
_0807F1D8: .4byte gDisableSoftReset
_0807F1DC: .4byte 0x03000014
_0807F1E0: .4byte 0x0858225C
_0807F1E4:
	bl Sram_WriteHeaderAndGameInfo
	b _0807F222
_0807F1EA:
	bl WriteMostRecentFileToSram
	b _0807F222
_0807F1F0:
	ldr r0, _0807F210 @ =0x0858225C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, _0807F214 @ =0x08582268
	adds r0, r2, r0
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	ldr r0, _0807F218 @ =gDisableSoftReset
	strb r5, [r0]
	b _0807F222
	.align 2, 0
_0807F210: .4byte 0x0858225C
_0807F214: .4byte 0x08582268
_0807F218: .4byte gDisableSoftReset
_0807F21C:
	ldr r1, _0807F22C @ =gDisableSoftReset
	movs r0, #0
	strb r0, [r1]
_0807F222:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807F22C: .4byte gDisableSoftReset

	thumb_func_start Sram_WriteHeaderAndGameInfo
Sram_WriteHeaderAndGameInfo: @ 0x0807F230
	push {r4, r5, r6, lr}
	ldr r5, _0807F2A0 @ =0x0858225C
	ldr r4, _0807F2A4 @ =0x03000B8D
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r6, [r0]
	ldr r1, _0807F2A8 @ =0x08582200
	adds r0, r6, #0
	bl Sram_StringCopy_MetroidEpisode4A
	movs r0, #0
	str r0, [r6, #0x10]
	subs r0, #1
	str r0, [r6, #0x14]
	ldr r1, _0807F2AC @ =0x03000014
	ldrb r0, [r1, #1]
	strb r0, [r6, #0x19]
	ldrb r0, [r1]
	strb r0, [r6, #0x18]
	adds r0, r6, #0
	adds r0, #0xf0
	ldr r1, _0807F2B0 @ =0x085821F8
	bl Sram_StringCopy_SAVE_END
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r2, [r0]
	movs r1, #0
	movs r3, #0x8f
_0807F26E:
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	subs r3, #1
	cmp r3, #0
	bge _0807F26E
	str r1, [r6, #0x10]
	mvns r0, r1
	str r0, [r6, #0x14]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807F2A0: .4byte 0x0858225C
_0807F2A4: .4byte 0x03000B8D
_0807F2A8: .4byte 0x08582200
_0807F2AC: .4byte 0x03000014
_0807F2B0: .4byte 0x085821F8

	thumb_func_start Sram_ProcessEndingSave
Sram_ProcessEndingSave: @ 0x0807F2B4
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #1
	beq _0807F2DA
	cmp r1, #1
	bgt _0807F2CA
	cmp r1, #0
	beq _0807F2D4
	b _0807F330
_0807F2CA:
	cmp r1, #2
	beq _0807F2E8
	cmp r1, #3
	beq _0807F310
	b _0807F330
_0807F2D4:
	bl ReadMostRecentFileToEwram
	b _0807F330
_0807F2DA:
	ldr r0, _0807F2E4 @ =0x03000014
	strb r1, [r0]
	bl Sram_CopyGameCompletion
	b _0807F330
	.align 2, 0
_0807F2E4: .4byte 0x03000014
_0807F2E8:
	bl WriteMostRecentFileToSram
	ldr r2, _0807F304 @ =0x03000B94
	ldr r0, _0807F308 @ =0x03000B8D
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, _0807F30C @ =0x03000014
	ldrb r1, [r1]
	strb r1, [r0, #0x10]
	b _0807F330
	.align 2, 0
_0807F304: .4byte 0x03000B94
_0807F308: .4byte 0x03000B8D
_0807F30C: .4byte 0x03000014
_0807F310:
	ldr r1, _0807F338 @ =0x0858225C
	ldr r0, _0807F33C @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r0, r1
	ldr r1, [r1]
	ldr r2, _0807F340 @ =0x08582268
	adds r0, r0, r2
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
_0807F330:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0807F338: .4byte 0x0858225C
_0807F33C: .4byte 0x03000B8D
_0807F340: .4byte 0x08582268

	thumb_func_start Sram_CopyGameCompletion
Sram_CopyGameCompletion: @ 0x0807F344
	push {r4, lr}
	ldr r2, _0807F3A0 @ =0x0858225C
	ldr r1, _0807F3A4 @ =0x03000B8D
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r3, [r0]
	movs r0, #0
	str r0, [r3, #0x10]
	subs r0, #1
	str r0, [r3, #0x14]
	ldr r0, _0807F3A8 @ =0x03000014
	ldrb r0, [r0]
	strb r0, [r3, #0x18]
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	movs r1, #0
	movs r4, #0x8f
_0807F36C:
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	subs r4, #1
	cmp r4, #0
	bge _0807F36C
	str r1, [r3, #0x10]
	mvns r0, r1
	str r0, [r3, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807F3A0: .4byte 0x0858225C
_0807F3A4: .4byte 0x03000B8D
_0807F3A8: .4byte 0x03000014

	thumb_func_start Sram_QuickSave
Sram_QuickSave: @ 0x0807F3AC
	push {lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #1
	beq _0807F3E8
	cmp r0, #1
	bgt _0807F3C4
	cmp r0, #0
	beq _0807F3CE
	b _0807F434
_0807F3C4:
	cmp r1, #2
	beq _0807F3F2
	cmp r1, #3
	beq _0807F414
	b _0807F434
_0807F3CE:
	ldr r0, _0807F3E0 @ =gDisableSoftReset
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0807F3E4 @ =0x03000B90
	strb r1, [r0]
	bl WriteMostRecentFileBackupToSram
	b _0807F43A
	.align 2, 0
_0807F3E0: .4byte gDisableSoftReset
_0807F3E4: .4byte 0x03000B90
_0807F3E8:
	bl SramWrite_WorldData
	bl SramWrite_ToEwram
	b _0807F43A
_0807F3F2:
	bl WriteMostRecentFileToSram
	ldr r2, _0807F40C @ =0x03000B94
	ldr r0, _0807F410 @ =0x03000B8D
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	b _0807F43A
	.align 2, 0
_0807F40C: .4byte 0x03000B94
_0807F410: .4byte 0x03000B8D
_0807F414:
	ldr r1, _0807F440 @ =0x0858225C
	ldr r0, _0807F444 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r0, r1
	ldr r1, [r1]
	ldr r2, _0807F448 @ =0x08582268
	adds r0, r0, r2
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
_0807F434:
	ldr r1, _0807F44C @ =gDisableSoftReset
	movs r0, #0
	strb r0, [r1]
_0807F43A:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0807F440: .4byte 0x0858225C
_0807F444: .4byte 0x03000B8D
_0807F448: .4byte 0x08582268
_0807F44C: .4byte gDisableSoftReset

	thumb_func_start SramWrite_ToEwram
SramWrite_ToEwram: @ 0x0807F450
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	ldr r4, _0807F6F8 @ =gMusicInfo
	ldrh r1, [r4, #0x1c]
	ldr r0, _0807F6FC @ =0xFFFF0000
	ands r0, r5
	orrs r0, r1
	ldrh r1, [r4, #0x1e]
	lsls r1, r1, #0x10
	ldr r3, _0807F700 @ =0x0000FFFF
	ands r0, r3
	adds r5, r0, #0
	orrs r5, r1
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	ldr r2, _0807F704 @ =0xFFFFFF00
	ands r2, r6
	orrs r2, r0
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r1, [r0]
	lsls r1, r1, #8
	ldr r0, _0807F708 @ =0xFFFF00FF
	ands r0, r2
	orrs r0, r1
	ldrh r1, [r4, #2]
	lsls r1, r1, #0x10
	ands r0, r3
	adds r6, r0, #0
	orrs r6, r1
	ldr r1, _0807F70C @ =0x0858225C
	ldr r0, _0807F710 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r1, _0807F714 @ =0x08582200
	adds r0, r4, #0
	bl Sram_StringCopy_MetroidEpisode4A
	movs r0, #0
	str r0, [r4, #0x10]
	subs r0, #1
	str r0, [r4, #0x14]
	ldr r0, _0807F718 @ =0x03000014
	ldr r0, [r0]
	str r0, [r4, #0x18]
	ldr r0, _0807F71C @ =0x03000B90
	ldrb r0, [r0]
	strb r0, [r4, #0x1c]
	ldr r0, _0807F720 @ =gCurrentArea
	ldrb r0, [r0]
	strb r0, [r4, #0x1d]
	ldr r0, _0807F724 @ =gCurrentRoom
	ldrb r0, [r0]
	strb r0, [r4, #0x1e]
	ldr r0, _0807F728 @ =gLastDoorUsed
	ldrb r0, [r0]
	strb r0, [r4, #0x1f]
	ldr r0, _0807F72C @ =gAbilityCount
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x20
	strb r1, [r0]
	ldr r0, _0807F730 @ =gEventCounter
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x21
	strb r0, [r1]
	ldr r0, _0807F734 @ =gPreviousNavigationConversation
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _0807F738 @ =gPreviousCutscene
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _0807F73C @ =0x03000031
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
	ldr r0, _0807F740 @ =0x03000032
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	ldr r0, _0807F744 @ =gSoundEventCounter
	ldrh r0, [r0]
	strh r0, [r4, #0x26]
	ldr r0, _0807F748 @ =gPreviousSoundEvent
	ldrh r0, [r0]
	strh r0, [r4, #0x28]
	ldr r0, _0807F74C @ =0x0300004D
	ldrb r0, [r0]
	adds r1, #5
	strb r0, [r1]
	ldr r0, _0807F750 @ =gSecurityHatchLevelBackup
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	ldr r0, _0807F754 @ =0x03000124
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	ldr r0, _0807F758 @ =0x03001224
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	ldr r0, _0807F75C @ =0x03001226
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	ldr r0, _0807F760 @ =gBg1XPosition
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x44
	strh r1, [r0]
	ldr r0, _0807F764 @ =gBg1YPosition
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x46
	strh r0, [r1]
	ldr r0, _0807F768 @ =0x0300122C
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x48
	strh r1, [r0]
	ldr r0, _0807F76C @ =0x0300122E
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x4a
	strh r0, [r1]
	ldr r0, _0807F770 @ =0x03001230
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x4c
	strh r1, [r0]
	ldr r0, _0807F774 @ =0x03001232
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x4e
	strh r0, [r1]
	movs r3, #0
	adds r2, r4, #0
	adds r2, #0x50
	ldr r7, _0807F778 @ =0x03000033
_0807F588:
	adds r0, r2, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #7
	ble _0807F588
	movs r3, #0
	movs r7, #0x60
	adds r7, r7, r4
	mov ip, r7
	movs r0, #0x8c
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x98
	adds r1, r1, r4
	mov sb, r1
	movs r2, #0xa4
	adds r2, r2, r4
	mov sl, r2
	adds r7, r4, #0
	adds r7, #0xb4
	str r7, [sp]
	adds r0, r4, #0
	adds r0, #0xc4
	str r0, [sp, #4]
	adds r1, r4, #0
	adds r1, #0xd4
	str r1, [sp, #8]
	adds r2, r4, #0
	adds r2, #0xd6
	str r2, [sp, #0xc]
	adds r7, #0x24
	str r7, [sp, #0x10]
	adds r0, #0x16
	str r0, [sp, #0x14]
	adds r1, #8
	str r1, [sp, #0x18]
	adds r2, #8
	str r2, [sp, #0x1c]
	adds r7, #8
	str r7, [sp, #0x20]
	adds r0, #8
	str r0, [sp, #0x24]
	adds r1, #7
	str r1, [sp, #0x28]
	adds r2, #6
	str r2, [sp, #0x2c]
	adds r7, #8
	str r7, [sp, #0x30]
	adds r0, #0xe
	str r0, [sp, #0x34]
	subs r2, #0x8c
	ldr r7, _0807F77C @ =0x0300003B
_0807F5F4:
	adds r0, r2, r3
	adds r1, r3, r7
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #7
	ble _0807F5F4
	mov r1, ip
	ldr r0, _0807F780 @ =gSamusData
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r1, r8
	ldr r0, _0807F784 @ =gSamusAnimationInfo
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	mov r1, sb
	ldr r0, _0807F788 @ =0x030012E4
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	mov r1, sl
	ldr r0, _0807F78C @ =0x030012F0
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, [sp]
	ldr r0, _0807F78C @ =0x030012F0
	adds r0, #0x10
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, [sp, #4]
	ldr r0, _0807F790 @ =gEquipment
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r7, _0807F794 @ =gPreventMovementTimer
	ldrh r0, [r7]
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r2, _0807F798 @ =gDisableDrawingSamusAndScrollingFlag
	ldrb r0, [r2]
	ldr r3, [sp, #0xc]
	strb r0, [r3]
	ldr r7, _0807F79C @ =gAtmosphericStabilizersOnline
	ldrh r0, [r7]
	ldr r1, [sp, #0x10]
	strh r0, [r1]
	ldr r2, _0807F7A0 @ =gMissileGeronsDestroyed
	ldrh r0, [r2]
	ldr r3, [sp, #0x14]
	strh r0, [r3]
	ldr r7, _0807F7A4 @ =gSuperMissileGeronsDestroyed
	ldrh r0, [r7]
	ldr r1, [sp, #0x18]
	strh r0, [r1]
	ldr r2, _0807F7A8 @ =gPowerBombGeronsDestroyed
	ldrh r0, [r2]
	ldr r3, [sp, #0x1c]
	strh r0, [r3]
	ldr r7, _0807F7AC @ =gGadorasDestroyed
	ldrh r0, [r7]
	ldr r1, [sp, #0x20]
	strh r0, [r1]
	ldr r2, _0807F7B0 @ =gMissileHatchDestroyed
	ldrb r0, [r2]
	ldr r3, [sp, #0x24]
	strb r0, [r3]
	ldr r7, _0807F7B4 @ =gWaterLowered
	ldrb r0, [r7]
	ldr r1, [sp, #0x28]
	strb r0, [r1]
	ldr r2, _0807F7B8 @ =gInGameTimer
	ldr r0, [r2]
	ldr r3, [sp, #0x2c]
	str r0, [r3]
	ldr r7, [sp, #0x30]
	str r5, [r7]
	str r6, [r7, #4]
	ldr r0, [sp, #0x34]
	ldr r1, _0807F7BC @ =0x085821F8
	bl Sram_StringCopy_SAVE_END
	ldr r1, _0807F70C @ =0x0858225C
	ldr r0, _0807F710 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	movs r3, #0x8f
_0807F6BA:
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	ldm r2!, {r0}
	adds r1, r1, r0
	subs r3, #1
	cmp r3, #0
	bge _0807F6BA
	str r1, [r4, #0x10]
	mvns r0, r1
	str r0, [r4, #0x14]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F6F8: .4byte gMusicInfo
_0807F6FC: .4byte 0xFFFF0000
_0807F700: .4byte 0x0000FFFF
_0807F704: .4byte 0xFFFFFF00
_0807F708: .4byte 0xFFFF00FF
_0807F70C: .4byte 0x0858225C
_0807F710: .4byte 0x03000B8D
_0807F714: .4byte 0x08582200
_0807F718: .4byte 0x03000014
_0807F71C: .4byte 0x03000B90
_0807F720: .4byte gCurrentArea
_0807F724: .4byte gCurrentRoom
_0807F728: .4byte gLastDoorUsed
_0807F72C: .4byte gAbilityCount
_0807F730: .4byte gEventCounter
_0807F734: .4byte gPreviousNavigationConversation
_0807F738: .4byte gPreviousCutscene
_0807F73C: .4byte 0x03000031
_0807F740: .4byte 0x03000032
_0807F744: .4byte gSoundEventCounter
_0807F748: .4byte gPreviousSoundEvent
_0807F74C: .4byte 0x0300004D
_0807F750: .4byte gSecurityHatchLevelBackup
_0807F754: .4byte 0x03000124
_0807F758: .4byte 0x03001224
_0807F75C: .4byte 0x03001226
_0807F760: .4byte gBg1XPosition
_0807F764: .4byte gBg1YPosition
_0807F768: .4byte 0x0300122C
_0807F76C: .4byte 0x0300122E
_0807F770: .4byte 0x03001230
_0807F774: .4byte 0x03001232
_0807F778: .4byte 0x03000033
_0807F77C: .4byte 0x0300003B
_0807F780: .4byte gSamusData
_0807F784: .4byte gSamusAnimationInfo
_0807F788: .4byte 0x030012E4
_0807F78C: .4byte 0x030012F0
_0807F790: .4byte gEquipment
_0807F794: .4byte gPreventMovementTimer
_0807F798: .4byte gDisableDrawingSamusAndScrollingFlag
_0807F79C: .4byte gAtmosphericStabilizersOnline
_0807F7A0: .4byte gMissileGeronsDestroyed
_0807F7A4: .4byte gSuperMissileGeronsDestroyed
_0807F7A8: .4byte gPowerBombGeronsDestroyed
_0807F7AC: .4byte gGadorasDestroyed
_0807F7B0: .4byte gMissileHatchDestroyed
_0807F7B4: .4byte gWaterLowered
_0807F7B8: .4byte gInGameTimer
_0807F7BC: .4byte 0x085821F8

	thumb_func_start SramRead_FromEwram
SramRead_FromEwram: @ 0x0807F7C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r1, _0807F9F8 @ =0x0858225C
	ldr r0, _0807F9FC @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _0807FA00 @ =0x03000014
	ldr r0, [r2, #0x18]
	str r0, [r1]
	ldr r1, _0807FA04 @ =0x03000B90
	ldrb r0, [r2, #0x1c]
	strb r0, [r1]
	ldr r1, _0807FA08 @ =gCurrentArea
	ldrb r0, [r2, #0x1d]
	strb r0, [r1]
	ldr r1, _0807FA0C @ =gCurrentRoom
	ldrb r0, [r2, #0x1e]
	strb r0, [r1]
	ldr r1, _0807FA10 @ =gLastDoorUsed
	ldrb r0, [r2, #0x1f]
	strb r0, [r1]
	ldr r1, _0807FA14 @ =gAbilityCount
	adds r0, r2, #0
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA18 @ =gEventCounter
	adds r0, r2, #0
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA1C @ =gPreviousNavigationConversation
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA20 @ =gPreviousCutscene
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA24 @ =0x03000031
	adds r0, r2, #0
	adds r0, #0x24
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA28 @ =0x03000032
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA2C @ =gSoundEventCounter
	ldrh r0, [r2, #0x26]
	strh r0, [r1]
	ldr r1, _0807FA30 @ =gPreviousSoundEvent
	ldrh r0, [r2, #0x28]
	strh r0, [r1]
	ldr r1, _0807FA34 @ =0x0300004D
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA38 @ =gSecurityHatchLevelBackup
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0807FA3C @ =0x03000124
	adds r0, r2, #0
	adds r0, #0x2c
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r1, _0807FA40 @ =0x03001224
	adds r0, r2, #0
	adds r0, #0x40
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA44 @ =0x03001226
	adds r0, r2, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA48 @ =gBg1XPosition
	adds r0, r2, #0
	adds r0, #0x44
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA4C @ =gBg1YPosition
	adds r0, r2, #0
	adds r0, #0x46
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA50 @ =0x0300122C
	adds r0, r2, #0
	adds r0, #0x48
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA54 @ =0x0300122E
	adds r0, r2, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA58 @ =0x03001230
	adds r0, r2, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0807FA5C @ =0x03001232
	adds r0, r2, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	strh r0, [r1]
	movs r3, #0
	ldr r5, _0807FA60 @ =gMusicInfo
	mov ip, r5
	ldr r5, _0807FA64 @ =0x03000033
	adds r4, r2, #0
	adds r4, #0x50
_0807F8BC:
	adds r0, r3, r5
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #7
	ble _0807F8BC
	movs r3, #0
	adds r5, r2, #0
	adds r5, #0x60
	adds r6, r2, #0
	adds r6, #0x8c
	adds r7, r2, #0
	adds r7, #0x98
	movs r0, #0xa4
	adds r0, r0, r2
	mov r8, r0
	movs r1, #0xb4
	adds r1, r1, r2
	mov sb, r1
	movs r4, #0xc4
	adds r4, r4, r2
	mov sl, r4
	adds r0, r2, #0
	adds r0, #0xd4
	str r0, [sp]
	adds r1, r2, #0
	adds r1, #0xd6
	str r1, [sp, #4]
	adds r4, r2, #0
	adds r4, #0xd8
	str r4, [sp, #8]
	adds r0, #6
	str r0, [sp, #0xc]
	adds r1, #6
	str r1, [sp, #0x10]
	adds r4, #6
	str r4, [sp, #0x14]
	adds r0, #6
	str r0, [sp, #0x18]
	adds r1, #6
	str r1, [sp, #0x1c]
	adds r4, #5
	str r4, [sp, #0x20]
	adds r0, #4
	str r0, [sp, #0x24]
	adds r1, #6
	str r1, [sp, #0x28]
	ldr r4, _0807FA68 @ =0x0300003B
	adds r2, #0x58
_0807F920:
	adds r0, r3, r4
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #7
	ble _0807F920
	ldr r1, _0807FA6C @ =gSamusData
	adds r0, r5, #0
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	ldr r1, _0807FA70 @ =gSamusAnimationInfo
	adds r0, r6, #0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r1, _0807FA74 @ =0x030012E4
	adds r0, r7, #0
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldr r1, _0807FA78 @ =0x030012F0
	mov r0, r8
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0807FA78 @ =0x030012F0
	adds r1, #0x10
	mov r0, sb
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0807FA7C @ =gEquipment
	mov r0, sl
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r4, [sp]
	ldrh r0, [r4]
	ldr r5, _0807FA80 @ =gPreventMovementTimer
	strh r0, [r5]
	ldr r1, [sp, #4]
	ldrb r0, [r1]
	ldr r2, _0807FA84 @ =gDisableDrawingSamusAndScrollingFlag
	strb r0, [r2]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	ldr r4, _0807FA88 @ =gAtmosphericStabilizersOnline
	strh r0, [r4]
	ldr r5, [sp, #0xc]
	ldrh r0, [r5]
	ldr r1, _0807FA8C @ =gMissileGeronsDestroyed
	strh r0, [r1]
	ldr r2, [sp, #0x10]
	ldrh r0, [r2]
	ldr r3, _0807FA90 @ =gSuperMissileGeronsDestroyed
	strh r0, [r3]
	ldr r4, [sp, #0x14]
	ldrh r0, [r4]
	ldr r5, _0807FA94 @ =gPowerBombGeronsDestroyed
	strh r0, [r5]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	ldr r2, _0807FA98 @ =gGadorasDestroyed
	strh r0, [r2]
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
	ldr r4, _0807FA9C @ =gMissileHatchDestroyed
	strb r0, [r4]
	ldr r5, [sp, #0x20]
	ldrb r0, [r5]
	ldr r1, _0807FAA0 @ =gWaterLowered
	strb r0, [r1]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r3, _0807FAA4 @ =gInGameTimer
	str r0, [r3]
	ldr r4, [sp, #0x28]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	mov r5, ip
	strh r0, [r5, #0x1c]
	lsrs r2, r0, #0x10
	strh r2, [r5, #0x1e]
	mov r2, ip
	adds r2, #0x20
	strb r1, [r2]
	lsrs r2, r1, #8
	mov r3, ip
	adds r3, #0x21
	strb r2, [r3]
	lsrs r0, r1, #0x10
	strh r0, [r5, #2]
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F9F8: .4byte 0x0858225C
_0807F9FC: .4byte 0x03000B8D
_0807FA00: .4byte 0x03000014
_0807FA04: .4byte 0x03000B90
_0807FA08: .4byte gCurrentArea
_0807FA0C: .4byte gCurrentRoom
_0807FA10: .4byte gLastDoorUsed
_0807FA14: .4byte gAbilityCount
_0807FA18: .4byte gEventCounter
_0807FA1C: .4byte gPreviousNavigationConversation
_0807FA20: .4byte gPreviousCutscene
_0807FA24: .4byte 0x03000031
_0807FA28: .4byte 0x03000032
_0807FA2C: .4byte gSoundEventCounter
_0807FA30: .4byte gPreviousSoundEvent
_0807FA34: .4byte 0x0300004D
_0807FA38: .4byte gSecurityHatchLevelBackup
_0807FA3C: .4byte 0x03000124
_0807FA40: .4byte 0x03001224
_0807FA44: .4byte 0x03001226
_0807FA48: .4byte gBg1XPosition
_0807FA4C: .4byte gBg1YPosition
_0807FA50: .4byte 0x0300122C
_0807FA54: .4byte 0x0300122E
_0807FA58: .4byte 0x03001230
_0807FA5C: .4byte 0x03001232
_0807FA60: .4byte gMusicInfo
_0807FA64: .4byte 0x03000033
_0807FA68: .4byte 0x0300003B
_0807FA6C: .4byte gSamusData
_0807FA70: .4byte gSamusAnimationInfo
_0807FA74: .4byte 0x030012E4
_0807FA78: .4byte 0x030012F0
_0807FA7C: .4byte gEquipment
_0807FA80: .4byte gPreventMovementTimer
_0807FA84: .4byte gDisableDrawingSamusAndScrollingFlag
_0807FA88: .4byte gAtmosphericStabilizersOnline
_0807FA8C: .4byte gMissileGeronsDestroyed
_0807FA90: .4byte gSuperMissileGeronsDestroyed
_0807FA94: .4byte gPowerBombGeronsDestroyed
_0807FA98: .4byte gGadorasDestroyed
_0807FA9C: .4byte gMissileHatchDestroyed
_0807FAA0: .4byte gWaterLowered
_0807FAA4: .4byte gInGameTimer

	thumb_func_start Sram_StringCopy_MetroidEpisode4A
Sram_StringCopy_MetroidEpisode4A: @ 0x0807FAA8
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r2, #0
_0807FAB0:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xf
	ble _0807FAB0
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Sram_StringCopy_SAVE_END
Sram_StringCopy_SAVE_END: @ 0x0807FAC4
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r2, #0
_0807FACC:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble _0807FACC
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start SramTestFlash
SramTestFlash: @ 0x0807FAE0
	push {r4, r5, lr}
	sub sp, #0x10
	movs r5, #0
	ldr r0, _0807FB3C @ =0x03000B8E
	strb r5, [r0]
	ldr r0, _0807FB40 @ =0x085821E8
	ldr r4, _0807FB44 @ =0x0E007FE0
	adds r1, r4, #0
	movs r2, #0x10
	bl SramWriteChecked
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r5, r1, #0x1f
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0x10
	bl SramWriteUnchecked
	movs r2, #0
_0807FB08:
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r2, #1
	cmp r2, #0xf
	ble _0807FB08
	ldr r1, _0807FB44 @ =0x0E007FE0
	mov r0, sp
	movs r2, #0x10
	bl SramWriteChecked
	cmp r0, #0
	beq _0807FB2A
	movs r0, #2
	orrs r5, r0
_0807FB2A:
	ldr r1, _0807FB3C @ =0x03000B8E
	rsbs r0, r5, #0
	orrs r0, r5
	lsrs r0, r0, #0x1f
	strb r0, [r1]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807FB3C: .4byte 0x03000B8E
_0807FB40: .4byte 0x085821E8
_0807FB44: .4byte 0x0E007FE0

	thumb_func_start Sram_BackupCurrentFile_Unused
Sram_BackupCurrentFile_Unused: @ 0x0807FB48
	push {lr}
	sub sp, #4
	ldr r1, _0807FB78 @ =0x0858225C
	ldr r0, _0807FB7C @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r0, r1
	ldr r1, [r1]
	ldr r2, _0807FB80 @ =0x08582268
	adds r0, r0, r2
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	bl WriteMostRecentFileBackupToSram
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0807FB78: .4byte 0x0858225C
_0807FB7C: .4byte 0x03000B8D
_0807FB80: .4byte 0x08582268

	thumb_func_start unk_7fb84
unk_7fb84: @ 0x0807FB84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	add r0, sp, #4
	movs r1, #0
	movs r2, #0x14
	bl memset
	ldr r2, _0807FC1C @ =0x03000B94
	movs r5, #2
_0807FB9E:
	adds r1, r2, #0
	add r0, sp, #4
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r2, #0x14
	subs r5, #1
	cmp r5, #0
	bge _0807FB9E
	ldr r4, _0807FC20 @ =0x03000B8D
	movs r1, #0
	strb r1, [r4]
	ldr r0, _0807FC24 @ =gIsLoadingFile
	strb r1, [r0]
	ldr r0, _0807FC28 @ =0x03000B8E
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807FBC8
	bl ReadAllFilesToEwram
_0807FBC8:
	movs r5, #0
	adds r7, r4, #0
	movs r6, #0x10
	ldr r0, _0807FC1C @ =0x03000B94
	str r0, [sp, #0x18]
	ldr r1, _0807FC2C @ =0x0858225C
	mov sl, r1
	ldr r3, _0807FC30 @ =0x0000FFFF
	mov sb, r3
	movs r4, #0x90
	lsls r4, r4, #5
	mov r8, r4
_0807FBE0:
	strb r5, [r7]
	bl unk_7fd10
	ldrb r0, [r7]
	lsls r2, r0, #2
	adds r0, r2, r0
	lsls r0, r0, #2
	ldr r1, _0807FC1C @ =0x03000B94
	adds r0, r0, r1
	ldrb r4, [r0, #1]
	cmp r4, #0
	bne _0807FC38
	mov r3, sl
	adds r0, r2, r3
	ldr r1, [r0]
	ldr r4, _0807FC34 @ =0x08582268
	adds r0, r2, r4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, #3
	movs r3, #0x90
	lsls r3, r3, #5
	bl DmaTransfer
	bl WriteMostRecentFileBackupToSram
	movs r0, #1
	ldr r1, [sp, #0x18]
	strb r0, [r1]
	b _0807FCE6
	.align 2, 0
_0807FC1C: .4byte 0x03000B94
_0807FC20: .4byte 0x03000B8D
_0807FC24: .4byte gIsLoadingFile
_0807FC28: .4byte 0x03000B8E
_0807FC2C: .4byte 0x0858225C
_0807FC30: .4byte 0x0000FFFF
_0807FC34: .4byte 0x08582268
_0807FC38:
	cmp r4, #1
	bne _0807FC60
	ldr r3, _0807FC5C @ =0x08582268
	adds r0, r2, r3
	ldr r1, [r0]
	mov r3, sl
	adds r0, r2, r3
	ldr r2, [r0]
	str r6, [sp]
	movs r0, #3
	movs r3, #0x90
	lsls r3, r3, #5
	bl DmaTransfer
	ldr r0, [sp, #0x18]
	strb r4, [r0]
	b _0807FCE6
	.align 2, 0
_0807FC5C: .4byte 0x08582268
_0807FC60:
	cmp r4, #2
	bne _0807FC94
	mov r1, sl
	adds r0, r2, r1
	ldr r2, [r0]
	str r6, [sp]
	movs r0, #3
	mov r1, sb
	mov r3, r8
	bl BitFill
	ldrb r0, [r7]
	lsls r0, r0, #2
	ldr r3, _0807FC90 @ =0x08582268
	adds r0, r0, r3
	ldr r2, [r0]
	str r6, [sp]
	movs r0, #3
	mov r1, sb
	mov r3, r8
	bl BitFill
	b _0807FCE6
	.align 2, 0
_0807FC90: .4byte 0x08582268
_0807FC94:
	cmp r4, #3
	bne _0807FCE4
	mov r4, sl
	adds r0, r2, r4
	ldr r2, [r0]
	str r6, [sp]
	movs r0, #3
	mov r1, sb
	mov r3, r8
	bl BitFill
	bl WriteMostRecentFileToSram
	ldrb r0, [r7]
	lsls r0, r0, #2
	ldr r1, _0807FCDC @ =0x08582268
	adds r0, r0, r1
	ldr r2, [r0]
	str r6, [sp]
	movs r0, #3
	mov r1, sb
	mov r3, r8
	bl BitFill
	bl WriteMostRecentFileBackupToSram
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _0807FCE0 @ =0x03000B94
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0, #1]
	b _0807FCE6
	.align 2, 0
_0807FCDC: .4byte 0x08582268
_0807FCE0: .4byte 0x03000B94
_0807FCE4:
	b _0807FCE4
_0807FCE6:
	ldr r4, [sp, #0x18]
	adds r4, #0x14
	str r4, [sp, #0x18]
	adds r5, #1
	cmp r5, #2
	bgt _0807FCF4
	b _0807FBE0
_0807FCF4:
	movs r1, #0
	ldr r0, _0807FD0C @ =0x03000B8D
	strb r1, [r0]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD0C: .4byte 0x03000B8D

	thumb_func_start unk_7fd10
unk_7fd10: @ 0x0807FD10
	push {r4, r5, lr}
	movs r0, #0
	bl unk_7fdb0
	adds r4, r0, #0
	movs r0, #1
	bl unk_7fdb0
	adds r2, r0, #0
	cmp r4, #0
	bne _0807FD40
	ldr r2, _0807FD38 @ =0x03000B94
	ldr r0, _0807FD3C @ =0x03000B8D
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	strb r4, [r0, #1]
	b _0807FDAA
	.align 2, 0
_0807FD38: .4byte 0x03000B94
_0807FD3C: .4byte 0x03000B8D
_0807FD40:
	cmp r4, #1
	bne _0807FD6C
	ldr r5, _0807FD64 @ =0x03000B94
	ldr r3, _0807FD68 @ =0x03000B8D
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	strb r4, [r0, #1]
	cmp r2, #0
	beq _0807FDAA
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	b _0807FDA6
	.align 2, 0
_0807FD64: .4byte 0x03000B94
_0807FD68: .4byte 0x03000B8D
_0807FD6C:
	ldr r4, _0807FD90 @ =0x03000B94
	ldr r3, _0807FD94 @ =0x03000B8D
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	movs r0, #3
	strb r0, [r1, #1]
	cmp r2, #0
	bne _0807FD98
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	movs r0, #1
	b _0807FDA8
	.align 2, 0
_0807FD90: .4byte 0x03000B94
_0807FD94: .4byte 0x03000B8D
_0807FD98:
	cmp r2, #1
	bne _0807FDAA
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
_0807FDA6:
	movs r0, #2
_0807FDA8:
	strb r0, [r1, #1]
_0807FDAA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start unk_7fdb0
unk_7fdb0: @ 0x0807FDB0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	movs r5, #0
	movs r7, #0
	cmp r0, #0
	bne _0807FDC8
	ldr r1, _0807FDC4 @ =0x0858225C
	b _0807FDCA
	.align 2, 0
_0807FDC4: .4byte 0x0858225C
_0807FDC8:
	ldr r1, _0807FE50 @ =0x08582268
_0807FDCA:
	ldr r0, _0807FE54 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r3, r4, #0
	movs r1, #0
	ldr r6, [r4, #0x10]
	movs r2, #0x8f
_0807FDDC:
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	ldm r3!, {r0}
	adds r1, r1, r0
	subs r2, #1
	cmp r2, #0
	bge _0807FDDC
	cmp r6, r1
	bne _0807FE0E
	ldr r0, [r4, #0x14]
	mvns r0, r0
	cmp r6, r0
	beq _0807FE12
_0807FE0E:
	movs r0, #1
	orrs r5, r0
_0807FE12:
	movs r2, #0
	ldr r6, _0807FE58 @ =0x08582200
	movs r3, #1
_0807FE18:
	adds r0, r2, r6
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0807FE26
	orrs r7, r3
_0807FE26:
	adds r2, #1
	cmp r2, #0xf
	ble _0807FE18
	adds r0, r7, #0
	adds r5, r5, r0
	cmp r5, #1
	ble _0807FE46
	ldr r1, _0807FE5C @ =0x0000FFFF
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	adds r2, r4, #0
	bl BitFill
_0807FE46:
	adds r0, r5, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807FE50: .4byte 0x08582268
_0807FE54: .4byte 0x03000B8D
_0807FE58: .4byte 0x08582200
_0807FE5C: .4byte 0x0000FFFF

	thumb_func_start SramLoad_CurrentSave
SramLoad_CurrentSave: @ 0x0807FE60
	push {lr}
	ldr r0, _0807FE8C @ =gIsLoadingFile
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0807FE88
	bl SramRead_FromEwram
	bl SramRead_WorldData
	ldr r0, _0807FE90 @ =gSamusData
	movs r2, #0
	movs r1, #0x3d
	strb r1, [r0, #1]
	adds r1, r0, #0
	adds r1, #0x21
	strb r2, [r1]
	adds r0, #0x22
	strb r2, [r0]
_0807FE88:
	pop {r0}
	bx r0
	.align 2, 0
_0807FE8C: .4byte gIsLoadingFile
_0807FE90: .4byte gSamusData

	thumb_func_start SramLoad_CurrentSave_Unused
SramLoad_CurrentSave_Unused: @ 0x0807FE94
	push {lr}
	bl SramRead_FromEwram
	bl SramRead_WorldData
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SramWrite_WorldData
SramWrite_WorldData: @ 0x0807FEA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, _0807FF5C @ =0x08582274
	ldr r0, _0807FF60 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r1, _0807FF64 @ =0x02037C00
	movs r4, #0xe0
	lsls r4, r4, #2
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	mov r2, r8
	adds r3, r4, #0
	bl DmaTransfer
	adds r7, r4, #0
	movs r5, #0
_0807FED2:
	ldr r0, _0807FF68 @ =0x03000033
	adds r0, r5, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r4, r0, r1
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _0807FEEA
	ldr r0, _0807FF6C @ =0x0000FFFC
	ands r4, r0
	adds r4, #4
_0807FEEA:
	cmp r4, #0
	beq _0807FF0E
	adds r1, r5, #0
	cmp r5, #0
	beq _0807FEF6
	adds r1, r5, #1
_0807FEF6:
	lsls r1, r1, #9
	ldr r0, _0807FF70 @ =0x02036000
	adds r1, r1, r0
	mov r0, r8
	adds r2, r0, r7
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	adds r3, r4, #0
	bl DmaTransfer
	adds r7, r7, r4
_0807FF0E:
	adds r5, #1
	cmp r5, #7
	ble _0807FED2
	movs r7, #0xc8
	lsls r7, r7, #4
	movs r5, #0
_0807FF1A:
	ldr r0, _0807FF74 @ =0x0300003B
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r4, r0, #2
	adds r6, r5, #1
	cmp r4, #0
	beq _0807FF48
	adds r1, r5, #0
	cmp r1, #0
	beq _0807FF30
	adds r1, r6, #0
_0807FF30:
	lsls r1, r1, #8
	ldr r0, _0807FF78 @ =0x02037200
	adds r1, r1, r0
	mov r0, r8
	adds r2, r0, r7
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	adds r3, r4, #0
	bl DmaTransfer
	adds r7, r7, r4
_0807FF48:
	adds r5, r6, #0
	cmp r5, #7
	ble _0807FF1A
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FF5C: .4byte 0x08582274
_0807FF60: .4byte 0x03000B8D
_0807FF64: .4byte 0x02037C00
_0807FF68: .4byte 0x03000033
_0807FF6C: .4byte 0x0000FFFC
_0807FF70: .4byte 0x02036000
_0807FF74: .4byte 0x0300003B
_0807FF78: .4byte 0x02037200

	thumb_func_start SramRead_WorldData
SramRead_WorldData: @ 0x0807FF7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, _08080044 @ =0x08582274
	ldr r0, _08080048 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0808004C @ =0x02037C00
	movs r5, #0xe0
	lsls r5, r5, #2
	movs r4, #0x10
	str r4, [sp]
	movs r0, #3
	mov r1, r8
	adds r3, r5, #0
	bl DmaTransfer
	ldr r1, _08080050 @ =0x0000FFFF
	ldr r2, _08080054 @ =0x02036000
	movs r3, #0xd8
	lsls r3, r3, #5
	str r4, [sp]
	movs r0, #3
	bl BitFill
	adds r7, r5, #0
	movs r5, #0
_0807FFBA:
	ldr r0, _08080058 @ =0x03000033
	adds r0, r5, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r4, r0, r1
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _0807FFD2
	ldr r0, _0808005C @ =0x0000FFFC
	ands r4, r0
	adds r4, #4
_0807FFD2:
	cmp r4, #0
	beq _0807FFF6
	adds r2, r5, #0
	cmp r5, #0
	beq _0807FFDE
	adds r2, r5, #1
_0807FFDE:
	mov r0, r8
	adds r1, r0, r7
	lsls r2, r2, #9
	ldr r0, _08080054 @ =0x02036000
	adds r2, r2, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	adds r3, r4, #0
	bl DmaTransfer
	adds r7, r7, r4
_0807FFF6:
	adds r5, #1
	cmp r5, #7
	ble _0807FFBA
	movs r7, #0xc8
	lsls r7, r7, #4
	movs r5, #0
_08080002:
	ldr r0, _08080060 @ =0x0300003B
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r4, r0, #2
	adds r6, r5, #1
	cmp r4, #0
	beq _08080030
	adds r2, r5, #0
	cmp r2, #0
	beq _08080018
	adds r2, r6, #0
_08080018:
	mov r0, r8
	adds r1, r0, r7
	lsls r2, r2, #8
	ldr r0, _08080064 @ =0x02037200
	adds r2, r2, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	adds r3, r4, #0
	bl DmaTransfer
	adds r7, r7, r4
_08080030:
	adds r5, r6, #0
	cmp r5, #7
	ble _08080002
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080044: .4byte 0x08582274
_08080048: .4byte 0x03000B8D
_0808004C: .4byte 0x02037C00
_08080050: .4byte 0x0000FFFF
_08080054: .4byte 0x02036000
_08080058: .4byte 0x03000033
_0808005C: .4byte 0x0000FFFC
_08080060: .4byte 0x0300003B
_08080064: .4byte 0x02037200

	thumb_func_start SramWrite_MostRecentSaveFile
SramWrite_MostRecentSaveFile: @ 0x08080068
	push {r4, r5, lr}
	ldr r5, _080800E4 @ =0x0203F000
	adds r3, r5, #0
	movs r1, #0
	movs r0, #0x1e
	strb r0, [r5]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	ldr r0, _080800E8 @ =0x0000FFFF
	strh r0, [r5, #4]
	ldr r0, _080800EC @ =0x03000B8D
	ldrb r0, [r0]
	strb r0, [r5, #0x16]
	ldr r2, _080800F0 @ =0x08582288
	adds r1, r5, #6
	movs r4, #0xf
_0808008C:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, #0x10]
	strb r0, [r1, #0x11]
	adds r2, #1
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _0808008C
	movs r1, #0
	movs r4, #7
_080800A2:
	ldrh r0, [r3]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	adds r3, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r3, #2
	lsrs r0, r0, #0x10
	ldrh r2, [r3]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	adds r3, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _080800A2
	strh r1, [r5, #2]
	ldr r2, _080800E8 @ =0x0000FFFF
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r5, #4]
	bl unk_dd4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080800E4: .4byte 0x0203F000
_080800E8: .4byte 0x0000FFFF
_080800EC: .4byte 0x03000B8D
_080800F0: .4byte 0x08582288

	thumb_func_start SramRead_MostRecentSaveFile
SramRead_MostRecentSaveFile: @ 0x080800F4
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, _08080194 @ =0x0203F000
	mov ip, r0
	ldrb r0, [r0]
	movs r1, #0x1e
	eors r0, r1
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r4, r1, #0x1f
	ldr r6, _08080198 @ =0x03000B8D
	cmp r4, #0
	bne _080801A0
	mov r1, ip
	movs r3, #0
	ldrh r5, [r1, #2]
	movs r2, #7
_08080116:
	ldrh r0, [r1]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	adds r1, #2
	lsrs r0, r0, #0x10
	ldrh r3, [r1]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	adds r1, #2
	lsrs r0, r0, #0x10
	ldrh r3, [r1]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	adds r1, #2
	lsrs r0, r0, #0x10
	ldrh r3, [r1]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08080116
	cmp r5, r3
	beq _0808014A
	movs r4, #2
_0808014A:
	cmp r4, #0
	bne _080801A0
	movs r2, #0
	ldr r0, _0808019C @ =0x08582288
	mov r3, ip
	ldrb r1, [r3, #6]
	adds r3, r0, #0
	ldrb r0, [r3]
	cmp r1, r0
	bne _080801A0
_0808015E:
	mov r0, ip
	adds r0, #0x17
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x10
	adds r1, r2, r1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080801A0
	adds r2, #1
	cmp r2, #0xf
	bgt _0808018A
	mov r0, ip
	adds r0, #6
	adds r0, r0, r2
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0808015E
	movs r4, #3
_0808018A:
	cmp r4, #0
	bne _080801A0
	mov r1, ip
	ldrb r0, [r1, #0x16]
	b _080801BA
	.align 2, 0
_08080194: .4byte 0x0203F000
_08080198: .4byte 0x03000B8D
_0808019C: .4byte 0x08582288
_080801A0:
	mov r1, sp
	ldr r2, _080801C4 @ =0x0000FFFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080801C8 @ =0x040000D4
	mov r3, sp
	str r3, [r1]
	ldr r0, _080801CC @ =0x0203F000
	str r0, [r1, #4]
	ldr r0, _080801D0 @ =0x81000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
_080801BA:
	strb r0, [r6]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080801C4: .4byte 0x0000FFFF
_080801C8: .4byte 0x040000D4
_080801CC: .4byte 0x0203F000
_080801D0: .4byte 0x81000020

	thumb_func_start SramWrite_Language
SramWrite_Language: @ 0x080801D4
	push {r4, r5, lr}
	ldr r5, _08080254 @ =0x0203F040
	adds r3, r5, #0
	movs r1, #0
	movs r0, #0x1f
	strb r0, [r5]
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	ldr r0, _08080258 @ =0x0000FFFF
	strh r0, [r5, #4]
	ldr r0, _0808025C @ =0x03000011
	ldrb r0, [r0]
	strb r0, [r5, #0x16]
	ldr r2, _08080260 @ =0x085822A8
	adds r1, r5, #6
	movs r4, #0xf
_080801F8:
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, #0x10]
	strb r0, [r1, #0x11]
	adds r2, #1
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080801F8
	movs r1, #0
	movs r4, #7
_0808020E:
	ldrh r0, [r3]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	adds r3, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r3, #2
	lsrs r0, r0, #0x10
	ldrh r2, [r3]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	adds r3, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _0808020E
	strh r1, [r5, #2]
	ldr r2, _08080258 @ =0x0000FFFF
	adds r0, r2, #0
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #0
	bl unk_dec
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08080254: .4byte 0x0203F040
_08080258: .4byte 0x0000FFFF
_0808025C: .4byte 0x03000011
_08080260: .4byte 0x085822A8

	thumb_func_start SramRead_Language
SramRead_Language: @ 0x08080264
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	mov r8, r0
	ldr r1, _080802E8 @ =0x08582280
	mov sb, r1
	ldr r6, _080802EC @ =0x040000D4
	ldr r2, _080802F0 @ =0x81000020
	mov sl, r2
_0808027E:
	mov r1, r8
	lsls r0, r1, #2
	add r0, sb
	ldr r5, [r0]
	adds r2, r5, #0
	ldrb r1, [r5]
	movs r0, #0x1f
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
	cmp r4, #0
	bne _08080326
	movs r1, #0
	ldrh r7, [r5, #2]
	movs r3, #7
_0808029E:
	ldrh r0, [r2]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	adds r2, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r2, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r2, #2
	lsrs r0, r0, #0x10
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808029E
	cmp r7, r1
	beq _080802D2
	movs r4, #2
_080802D2:
	cmp r4, #0
	bne _08080326
	movs r3, #0
	ldr r0, _080802F4 @ =0x085822A8
	ldrb r1, [r5, #6]
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r1, r0
	beq _080802FC
	b _08080324
	.align 2, 0
_080802E8: .4byte 0x08582280
_080802EC: .4byte 0x040000D4
_080802F0: .4byte 0x81000020
_080802F4: .4byte 0x085822A8
_080802F8:
	movs r4, #4
	b _08080326
_080802FC:
	adds r0, r5, #0
	adds r0, #0x17
	adds r0, r0, r3
	adds r1, r2, #0
	adds r1, #0x10
	adds r1, r3, r1
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080802F8
	adds r3, #1
	cmp r3, #0xf
	bgt _08080326
	adds r0, r5, #6
	adds r0, r0, r3
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _080802FC
_08080324:
	movs r4, #3
_08080326:
	mov r1, r8
	cmp r1, #0
	bne _0808034C
	cmp r4, #0
	bne _08080384
	mov r2, sb
	ldr r0, [r2]
	str r0, [r6]
	ldr r0, [r2, #4]
	str r0, [r6, #4]
	ldr r0, _08080348 @ =0x80000020
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	movs r0, #1
	bl unk_dec
	b _08080390
	.align 2, 0
_08080348: .4byte 0x80000020
_0808034C:
	cmp r4, #0
	beq _080803A0
	mov r0, sp
	movs r1, #0
	strh r1, [r0]
	str r0, [r6]
	mov r2, sb
	ldr r0, [r2]
	str r0, [r6, #4]
	mov r0, sl
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	movs r0, #0
	bl unk_dec
	mov r0, sp
	movs r1, #0
	strh r1, [r0]
	str r0, [r6]
	mov r2, sb
	ldr r0, [r2, #4]
	str r0, [r6, #4]
	mov r0, sl
	str r0, [r6, #8]
	ldr r0, [r6, #8]
	movs r0, #1
	bl unk_dec
_08080384:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #1
	bgt _08080390
	b _0808027E
_08080390:
	cmp r4, #0
	bne _080803C8
	ldr r1, _0808039C @ =0x03000011
	ldrb r0, [r5, #0x16]
	b _080803CC
	.align 2, 0
_0808039C: .4byte 0x03000011
_080803A0:
	ldr r1, _080803BC @ =0x040000D4
	ldr r2, _080803C0 @ =0x08582280
	ldr r0, [r2, #4]
	str r0, [r1]
	ldr r0, [r2]
	str r0, [r1, #4]
	ldr r0, _080803C4 @ =0x80000020
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	bl unk_dec
	b _08080390
	.align 2, 0
_080803BC: .4byte 0x040000D4
_080803C0: .4byte 0x08582280
_080803C4: .4byte 0x80000020
_080803C8:
	ldr r1, _080803E0 @ =0x03000011
	movs r0, #0
_080803CC:
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080803E0: .4byte 0x03000011

	thumb_func_start Sram_InitSaveFile
Sram_InitSaveFile: @ 0x080803E4
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r2, _080804C8 @ =0x02037C00
	movs r3, #0xe0
	lsls r3, r3, #2
	movs r4, #0x10
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	bl BitFill
	ldr r5, _080804CC @ =0x0000FFFF
	ldr r2, _080804D0 @ =0x02036000
	movs r3, #0x90
	lsls r3, r3, #5
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	bl BitFill
	ldr r2, _080804D4 @ =0x02037200
	movs r3, #0x90
	lsls r3, r3, #4
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	bl BitFill
	movs r1, #0
	ldr r4, _080804D8 @ =0x03000033
	movs r2, #0
	ldr r3, _080804DC @ =0x0300003B
_08080424:
	adds r0, r1, r4
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, #1
	cmp r1, #7
	ble _08080424
	ldr r1, _080804E0 @ =gInGameTimer
	ldr r0, _080804E4 @ =0x085822D4
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080804E8 @ =gDisableDrawingSamusAndScrollingFlag
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	bl EventSet
	ldr r0, _080804EC @ =gPreviousNavigationConversation
	movs r3, #0xff
	strb r3, [r0]
	ldr r0, _080804F0 @ =gPreviousSoundEvent
	movs r1, #0xff
	strh r1, [r0]
	ldr r2, _080804F4 @ =gEquipment
	ldrb r0, [r2, #0xd]
	orrs r0, r3
	strb r0, [r2, #0xd]
	ldr r0, _080804F8 @ =gSecurityHatchLevel
	strb r1, [r0]
	ldr r0, _080804FC @ =gSecurityHatchLevelBackup
	strb r1, [r0]
	movs r1, #0
	strb r1, [r2, #0xe]
	ldr r0, _08080500 @ =gAbilityCount
	strb r1, [r0]
	ldr r0, _08080504 @ =gCurrentArea
	strb r1, [r0]
	ldr r0, _08080508 @ =gPreviousArea
	strb r1, [r0]
	ldr r0, _0808050C @ =gCurrentRoom
	strb r1, [r0]
	ldr r0, _08080510 @ =gLastDoorUsed
	strb r1, [r0]
	ldr r0, _08080514 @ =0x0300004C
	strb r1, [r0]
	ldr r0, _08080518 @ =0x0300004D
	strb r1, [r0]
	ldr r0, _0808051C @ =0x0879B894
	ldr r2, [r0]
	ldrb r0, [r2, #2]
	movs r6, #7
	ldrsb r6, [r2, r6]
	ldr r3, _08080520 @ =gPreviousXPosition
	ldr r4, _08080524 @ =gSamusData
	lsls r1, r0, #6
	adds r0, r6, #0
	adds r0, #8
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r5, #0
	strh r1, [r4, #0x16]
	strh r1, [r3]
	ldrb r0, [r2, #5]
	adds r0, #1
	movs r6, #8
	ldrsb r6, [r2, r6]
	ldr r2, _08080528 @ =gPreviousYPosition
	lsls r0, r0, #6
	lsls r1, r6, #2
	adds r0, r0, r1
	subs r0, #1
	strh r0, [r4, #0x18]
	strh r0, [r2]
	bl LoadInitialMinimap
	ldr r0, _0808052C @ =gIsLoadingFile
	strb r5, [r0]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080804C8: .4byte 0x02037C00
_080804CC: .4byte 0x0000FFFF
_080804D0: .4byte 0x02036000
_080804D4: .4byte 0x02037200
_080804D8: .4byte 0x03000033
_080804DC: .4byte 0x0300003B
_080804E0: .4byte gInGameTimer
_080804E4: .4byte 0x085822D4
_080804E8: .4byte gDisableDrawingSamusAndScrollingFlag
_080804EC: .4byte gPreviousNavigationConversation
_080804F0: .4byte gPreviousSoundEvent
_080804F4: .4byte gEquipment
_080804F8: .4byte gSecurityHatchLevel
_080804FC: .4byte gSecurityHatchLevelBackup
_08080500: .4byte gAbilityCount
_08080504: .4byte gCurrentArea
_08080508: .4byte gPreviousArea
_0808050C: .4byte gCurrentRoom
_08080510: .4byte gLastDoorUsed
_08080514: .4byte 0x0300004C
_08080518: .4byte 0x0300004D
_0808051C: .4byte 0x0879B894
_08080520: .4byte gPreviousXPosition
_08080524: .4byte gSamusData
_08080528: .4byte gPreviousYPosition
_0808052C: .4byte gIsLoadingFile

	thumb_func_start Sram_ResetForDemo
Sram_ResetForDemo: @ 0x08080530
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _080805F0 @ =gPauseDebugOptions
	ldr r0, _080805F4 @ =0x085822E4
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r2, _080805F8 @ =gButtonAssignments
	ldr r0, _080805FC @ =0x085822C8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r5, _08080600 @ =0x0000FFFF
	ldr r2, _08080604 @ =0x02037C00
	movs r3, #0xe0
	lsls r3, r3, #2
	movs r4, #0x10
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	bl BitFill
	ldr r2, _08080608 @ =0x02036000
	movs r3, #0x90
	lsls r3, r3, #5
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	bl BitFill
	ldr r2, _0808060C @ =0x02037200
	movs r3, #0x90
	lsls r3, r3, #4
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	bl BitFill
	movs r1, #0
	ldr r4, _08080610 @ =0x03000033
	movs r2, #0
	ldr r3, _08080614 @ =0x0300003B
_08080584:
	adds r0, r1, r4
	strb r2, [r0]
	adds r0, r1, r3
	strb r2, [r0]
	adds r1, #1
	cmp r1, #7
	ble _08080584
	ldr r1, _08080618 @ =gInGameTimer
	ldr r0, _0808061C @ =0x085822D4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08080620 @ =gDisableDrawingSamusAndScrollingFlag
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08080624 @ =gPreviousNavigationConversation
	movs r0, #0xff
	strb r0, [r2]
	ldr r2, _08080628 @ =gPreviousSoundEvent
	movs r0, #0xff
	strh r0, [r2]
	ldr r0, _0808062C @ =0x0300004C
	strb r1, [r0]
	ldr r0, _08080630 @ =0x0300004D
	strb r1, [r0]
	ldr r0, _08080634 @ =gIsLoadingFile
	strb r1, [r0]
	ldr r0, _08080638 @ =gUnk_3000be3
	strb r1, [r0]
	ldr r0, _0808063C @ =0x03000018
	strb r1, [r0]
	ldr r0, _08080640 @ =gDisableSoftReset
	strb r1, [r0]
	ldr r2, _08080644 @ =gMaxInGameTimeFlag
	movs r0, #1
	strb r0, [r2]
	ldr r0, _08080648 @ =0x03000022
	strb r1, [r0]
	ldr r0, _0808064C @ =gSkipDoorTransition
	strb r1, [r0]
	ldr r0, _08080650 @ =gPauseScreenFlag
	strb r1, [r0]
	ldr r0, _08080654 @ =0x03000B85
	strb r1, [r0]
	ldr r0, _08080658 @ =0x0300002B
	strb r1, [r0]
	ldr r0, _0808065C @ =gSamusDoorPositionOffset
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08080660 @ =gDebugFlag
	strb r1, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080805F0: .4byte gPauseDebugOptions
_080805F4: .4byte 0x085822E4
_080805F8: .4byte gButtonAssignments
_080805FC: .4byte 0x085822C8
_08080600: .4byte 0x0000FFFF
_08080604: .4byte 0x02037C00
_08080608: .4byte 0x02036000
_0808060C: .4byte 0x02037200
_08080610: .4byte 0x03000033
_08080614: .4byte 0x0300003B
_08080618: .4byte gInGameTimer
_0808061C: .4byte 0x085822D4
_08080620: .4byte gDisableDrawingSamusAndScrollingFlag
_08080624: .4byte gPreviousNavigationConversation
_08080628: .4byte gPreviousSoundEvent
_0808062C: .4byte 0x0300004C
_08080630: .4byte 0x0300004D
_08080634: .4byte gIsLoadingFile
_08080638: .4byte gUnk_3000be3
_0808063C: .4byte 0x03000018
_08080640: .4byte gDisableSoftReset
_08080644: .4byte gMaxInGameTimeFlag
_08080648: .4byte 0x03000022
_0808064C: .4byte gSkipDoorTransition
_08080650: .4byte gPauseScreenFlag
_08080654: .4byte 0x03000B85
_08080658: .4byte 0x0300002B
_0808065C: .4byte gSamusDoorPositionOffset
_08080660: .4byte gDebugFlag

	thumb_func_start Sram_CheckLoadSaveFile
Sram_CheckLoadSaveFile: @ 0x08080664
	push {r4, r5, r6, lr}
	ldr r2, _080806BC @ =gButtonAssignments
	ldr r0, _080806C0 @ =0x085822C8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080806C4 @ =gPauseDebugOptions
	ldr r0, _080806C8 @ =0x085822E4
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r2, _080806CC @ =gIsLoadingFile
	ldr r6, _080806D0 @ =0x03000B94
	ldr r4, _080806D4 @ =0x03000B8D
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0]
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #0
	bne _080806DC
	bl Sram_InitSaveFile
	ldr r2, _080806D8 @ =0x03000014
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #0x10]
	strb r0, [r2]
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #0x11]
	strb r0, [r2, #1]
	strb r5, [r2, #2]
	b _080806E0
	.align 2, 0
_080806BC: .4byte gButtonAssignments
_080806C0: .4byte 0x085822C8
_080806C4: .4byte gPauseDebugOptions
_080806C8: .4byte 0x085822E4
_080806CC: .4byte gIsLoadingFile
_080806D0: .4byte 0x03000B94
_080806D4: .4byte 0x03000B8D
_080806D8: .4byte 0x03000014
_080806DC:
	bl SramLoad_CurrentSave
_080806E0:
	ldr r0, _08080718 @ =gUnk_3000be3
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0808071C @ =0x03000018
	strb r1, [r0]
	ldr r0, _08080720 @ =gDisableSoftReset
	strb r1, [r0]
	ldr r0, _08080724 @ =gMaxInGameTimeFlag
	strb r1, [r0]
	ldr r0, _08080728 @ =0x03000022
	strb r1, [r0]
	ldr r0, _0808072C @ =gSkipDoorTransition
	strb r1, [r0]
	ldr r0, _08080730 @ =gPauseScreenFlag
	strb r1, [r0]
	ldr r0, _08080734 @ =0x03000B85
	strb r1, [r0]
	ldr r0, _08080738 @ =0x0300002B
	strb r1, [r0]
	ldr r0, _0808073C @ =gSamusDoorPositionOffset
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08080740 @ =gDebugFlag
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080718: .4byte gUnk_3000be3
_0808071C: .4byte 0x03000018
_08080720: .4byte gDisableSoftReset
_08080724: .4byte gMaxInGameTimeFlag
_08080728: .4byte 0x03000022
_0808072C: .4byte gSkipDoorTransition
_08080730: .4byte gPauseScreenFlag
_08080734: .4byte 0x03000B85
_08080738: .4byte 0x0300002B
_0808073C: .4byte gSamusDoorPositionOffset
_08080740: .4byte gDebugFlag

	thumb_func_start Sram_EraseFile
Sram_EraseFile: @ 0x08080744
	push {r4, r5, lr}
	sub sp, #0x18
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	add r0, sp, #4
	movs r1, #0
	movs r2, #0x14
	bl memset
	cmp r4, #0
	bne _08080798
	ldr r1, _08080784 @ =gDisableSoftReset
	movs r0, #1
	strb r0, [r1]
	ldr r2, _08080788 @ =0x03000B94
	ldr r3, _0808078C @ =0x03000B8D
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	add r0, sp, #4
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4}
	stm r1!, {r2, r4}
	ldr r1, _08080790 @ =0x0000FFFF
	ldr r2, _08080794 @ =0x0858225C
	ldrb r0, [r3]
	b _080807AE
	.align 2, 0
_08080784: .4byte gDisableSoftReset
_08080788: .4byte 0x03000B94
_0808078C: .4byte 0x03000B8D
_08080790: .4byte 0x0000FFFF
_08080794: .4byte 0x0858225C
_08080798:
	cmp r4, #1
	bne _080807A2
	bl WriteMostRecentFileToSram
	b _080807DE
_080807A2:
	cmp r4, #2
	bne _080807D0
	ldr r1, _080807C4 @ =0x0000FFFF
	ldr r2, _080807C8 @ =0x08582268
	ldr r0, _080807CC @ =0x03000B8D
	ldrb r0, [r0]
_080807AE:
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl BitFill
	b _080807DE
	.align 2, 0
_080807C4: .4byte 0x0000FFFF
_080807C8: .4byte 0x08582268
_080807CC: .4byte 0x03000B8D
_080807D0:
	cmp r5, #3
	bne _080807D8
	bl WriteMostRecentFileBackupToSram
_080807D8:
	ldr r1, _080807E8 @ =gDisableSoftReset
	movs r0, #0
	strb r0, [r1]
_080807DE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080807E8: .4byte gDisableSoftReset

	thumb_func_start Sram_CopyFile
Sram_CopyFile: @ 0x080807EC
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r2, r6, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0
	cmp r1, #0
	bne _08080844
	ldr r1, _08080834 @ =gDisableSoftReset
	movs r0, #1
	strb r0, [r1]
	ldr r4, _08080838 @ =0x03000B94
	lsls r3, r6, #2
	adds r1, r3, r6
	lsls r1, r1, #2
	ldr r5, _0808083C @ =0x03000B8D
	ldrb r2, [r5]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r4
	adds r0, r0, r4
	ldm r0!, {r2, r4, r6}
	stm r1!, {r2, r4, r6}
	ldm r0!, {r2, r4}
	stm r1!, {r2, r4}
	ldr r2, _08080840 @ =0x0858225C
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r0]
	adds r3, r3, r2
	ldr r2, [r3]
	b _08080872
	.align 2, 0
_08080834: .4byte gDisableSoftReset
_08080838: .4byte 0x03000B94
_0808083C: .4byte 0x03000B8D
_08080840: .4byte 0x0858225C
_08080844:
	cmp r1, #1
	bne _0808085C
	ldr r4, _08080858 @ =0x03000B8D
	ldrb r5, [r4]
	strb r6, [r4]
	bl WriteMostRecentFileToSram
	strb r5, [r4]
	b _080808A2
	.align 2, 0
_08080858: .4byte 0x03000B8D
_0808085C:
	cmp r1, #2
	bne _0808088C
	ldr r2, _08080884 @ =0x08582268
	ldr r0, _08080888 @ =0x03000B8D
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r2
	ldr r2, [r0]
_08080872:
	movs r3, #0x90
	lsls r3, r3, #5
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	bl DmaTransfer
	b _080808A2
	.align 2, 0
_08080884: .4byte 0x08582268
_08080888: .4byte 0x03000B8D
_0808088C:
	cmp r0, #3
	bne _0808089C
	ldr r4, _080808AC @ =0x03000B8D
	ldrb r5, [r4]
	strb r2, [r4]
	bl WriteMostRecentFileBackupToSram
	strb r5, [r4]
_0808089C:
	ldr r1, _080808B0 @ =gDisableSoftReset
	movs r0, #0
	strb r0, [r1]
_080808A2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080808AC: .4byte 0x03000B8D
_080808B0: .4byte gDisableSoftReset

	thumb_func_start Sram_WriteFileInfo
Sram_WriteFileInfo: @ 0x080808B4
	push {r4, lr}
	movs r4, #0
	movs r3, #0
	ldr r2, _08080948 @ =0x03000B94
_080808BC:
	lsls r1, r4, #2
	ldrb r0, [r2]
	cmp r0, #1
	bne _0808091A
	ldr r0, _0808094C @ =0x0858225C
	adds r0, r1, r0
	ldr r1, [r0]
	ldrb r0, [r1, #0x1d]
	strb r0, [r2, #2]
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r2, #3]
	adds r0, r1, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	strh r0, [r2, #4]
	adds r0, r1, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	strh r0, [r2, #6]
	adds r0, r1, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	strh r0, [r2, #8]
	adds r0, r1, #0
	adds r0, #0xca
	ldrh r0, [r0]
	strh r0, [r2, #0xa]
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	strb r0, [r2, #0xc]
	adds r0, r1, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	strb r0, [r2, #0xd]
	adds r0, r1, #0
	adds r0, #0xe5
	ldrb r0, [r0]
	strb r0, [r2, #0xe]
	ldrb r0, [r1, #0x1c]
	strb r0, [r2, #0xf]
	ldrb r0, [r1, #0x18]
	strb r0, [r2, #0x10]
	ldrb r0, [r1, #0x19]
	strb r0, [r2, #0x11]
_0808091A:
	ldrb r0, [r2]
	cmp r0, #0
	beq _08080926
	ldrb r0, [r2, #0xf]
	cmp r0, #0
	bne _0808093A
_08080926:
	strb r3, [r2]
	strb r3, [r2, #2]
	strb r3, [r2, #3]
	strh r3, [r2, #4]
	strh r3, [r2, #6]
	strh r3, [r2, #8]
	strh r3, [r2, #0xa]
	strb r3, [r2, #0xc]
	strb r3, [r2, #0xd]
	strb r3, [r2, #0xe]
_0808093A:
	adds r2, #0x14
	adds r4, #1
	cmp r4, #2
	ble _080808BC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080948: .4byte 0x03000B94
_0808094C: .4byte 0x0858225C

	thumb_func_start Sram_LoadingfileVblank
Sram_LoadingfileVblank: @ 0x08080950
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	add sp, #4
	bx lr

	thumb_func_start Sram_AfterLoadingFileVblank
Sram_AfterLoadingFileVblank: @ 0x0808095C
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Sram_ChecLoadSaveFileWithBlank
Sram_ChecLoadSaveFileWithBlank: @ 0x08080968
	push {lr}
	ldr r0, _08080988 @ =Sram_AfterLoadingFileVblank
	bl CallbackSetVBlank
	bl Sram_CheckLoadSaveFile
	ldr r0, _0808098C @ =Sram_LoadingfileVblank
	bl CallbackSetVBlank
	ldr r0, _08080990 @ =gIsLoadingFile
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_08080988: .4byte Sram_AfterLoadingFileVblank
_0808098C: .4byte Sram_LoadingfileVblank
_08080990: .4byte gIsLoadingFile

	thumb_func_start Sram_SetCurrentFile
Sram_SetCurrentFile: @ 0x08080994
	push {r4, lr}
	ldr r1, _080809B8 @ =0x03000B8D
	ldrb r4, [r1]
	strb r0, [r1]
	ldr r2, _080809BC @ =0x03000B94
	ldrb r1, [r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080809C0
	cmp r0, #1
	ble _080809CE
	cmp r0, #2
	beq _080809C6
	b _080809CE
	.align 2, 0
_080809B8: .4byte 0x03000B8D
_080809BC: .4byte 0x03000B94
_080809C0:
	bl WriteMostRecentFileToSram
	b _080809CE
_080809C6:
	bl WriteMostRecentFileToSram
	bl WriteMostRecentFileBackupToSram
_080809CE:
	ldr r3, _080809E8 @ =0x03000B94
	ldr r2, _080809EC @ =0x03000B8D
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0, #1]
	strb r4, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080809E8: .4byte 0x03000B94
_080809EC: .4byte 0x03000B8D

	thumb_func_start EraseSramMenuHandler
EraseSramMenuHandler: @ 0x080809F0
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r0, _08080A18 @ =gNonGameplayRam
	ldrh r1, [r0, #4]
	adds r1, #1
	strh r1, [r0, #4]
	ldr r1, _08080A1C @ =gSubGameMode1
	movs r3, #0
	ldrsh r2, [r1, r3]
	adds r3, r0, #0
	adds r5, r1, #0
	cmp r2, #6
	bls _08080A0C
	b _08080AFA
_08080A0C:
	lsls r0, r2, #2
	ldr r1, _08080A20 @ =_08080A24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08080A18: .4byte gNonGameplayRam
_08080A1C: .4byte gSubGameMode1
_08080A20: .4byte _08080A24
_08080A24: @ jump table
	.4byte _08080A40 @ case 0
	.4byte _08080A50 @ case 1
	.4byte _08080A74 @ case 2
	.4byte _08080AB0 @ case 3
	.4byte _08080ABC @ case 4
	.4byte _08080ACC @ case 5
	.4byte _08080AE2 @ case 6
_08080A40:
	bl EraseSramMenuInit
	ldr r1, _08080A4C @ =gSubGameMode1
	ldrh r0, [r1]
	b _08080AEA
	.align 2, 0
_08080A4C: .4byte gSubGameMode1
_08080A50:
	ldr r4, _08080A60 @ =gWrittenToBldy
	ldrh r1, [r4]
	adds r2, r1, #0
	cmp r2, #0
	beq _08080A64
	subs r0, r1, #1
	strh r0, [r4]
	b _08080AFA
	.align 2, 0
_08080A60: .4byte gWrittenToBldy
_08080A64:
	movs r0, #0xef
	strh r0, [r3, #6]
	strb r1, [r3, #8]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	strh r2, [r3, #4]
	b _08080AFA
_08080A74:
	ldr r4, _08080A98 @ =gSubGameMode2
	bl EraseSramProcessInput
	strb r0, [r4]
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	beq _08080AFA
	ldr r1, _08080A9C @ =gNonGameplayRam
	movs r0, #0
	strh r0, [r1, #4]
	cmp r2, #1
	bne _08080AA4
	ldr r1, _08080AA0 @ =gSubGameMode1
	movs r0, #5
	strh r0, [r1]
	b _08080AFA
	.align 2, 0
_08080A98: .4byte gSubGameMode2
_08080A9C: .4byte gNonGameplayRam
_08080AA0: .4byte gSubGameMode1
_08080AA4:
	ldr r1, _08080AAC @ =gSubGameMode1
	movs r0, #3
	strh r0, [r1]
	b _08080AFA
	.align 2, 0
_08080AAC: .4byte gSubGameMode1
_08080AB0:
	ldrh r0, [r3, #4]
	cmp r0, #0x28
	bls _08080AFA
	movs r1, #0
	movs r0, #0xff
	b _08080AD6
_08080ABC:
	ldr r1, _08080AC8 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bls _08080AEA
	b _08080AF8
	.align 2, 0
_08080AC8: .4byte gWrittenToBldy
_08080ACC:
	ldrh r0, [r3, #4]
	cmp r0, #0x28
	bls _08080AFA
	movs r1, #0
	movs r0, #0xbf
_08080AD6:
	strh r0, [r3, #6]
	strh r1, [r3, #4]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _08080AFA
_08080AE2:
	ldr r1, _08080AF0 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _08080AF4
_08080AEA:
	adds r0, #1
	strh r0, [r1]
	b _08080AFA
	.align 2, 0
_08080AF0: .4byte gWrittenToBldy
_08080AF4:
	bl EraseSram
_08080AF8:
	movs r6, #1
_08080AFA:
	bl EraseSramProcessOam
	bl ResetFreeOam
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EraseSramProcessInput
EraseSramProcessInput: @ 0x08080B0C
	push {r4, lr}
	movs r4, #0
	ldr r0, _08080B24 @ =gNonGameplayRam
	ldrb r1, [r0, #1]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08080B28
	bl EraseSramApplyInput
	b _08080B2E
	.align 2, 0
_08080B24: .4byte gNonGameplayRam
_08080B28:
	bl EraseSramCheckForInput
	adds r4, r0, #0
_08080B2E:
	ldr r0, _08080B44 @ =gNonGameplayRam
	ldr r3, _08080B48 @ =gWrittenToBldy
	ldrh r1, [r3]
	ldrb r2, [r0, #8]
	adds r0, r1, #0
	cmp r2, r0
	beq _08080B50
	cmp r2, r0
	bls _08080B4C
	adds r0, r1, #1
	b _08080B4E
	.align 2, 0
_08080B44: .4byte gNonGameplayRam
_08080B48: .4byte gWrittenToBldy
_08080B4C:
	subs r0, r1, #1
_08080B4E:
	strh r0, [r3]
_08080B50:
	bl EraseSramUpdateCursorPosition
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EraseSramApplyInput
EraseSramApplyInput: @ 0x08080B5C
	push {lr}
	ldr r1, _08080B84 @ =gNonGameplayRam
	ldrb r0, [r1, #0x16]
	adds r2, r1, #0
	cmp r0, #2
	beq _08080BE2
	ldrb r1, [r2, #1]
	movs r0, #0x7f
	ands r0, r1
	movs r3, #0
	strb r0, [r2, #1]
	strb r0, [r2]
	ldrb r0, [r2, #1]
	cmp r0, #1
	beq _08080B9C
	cmp r0, #1
	bgt _08080B88
	cmp r0, #0
	beq _08080B92
	b _08080BC6
	.align 2, 0
_08080B84: .4byte gNonGameplayRam
_08080B88:
	cmp r0, #2
	beq _08080BB4
	cmp r0, #3
	beq _08080BBC
	b _08080BC6
_08080B92:
	ldr r0, _08080B98 @ =0x0858B3B0
	b _08080B9E
	.align 2, 0
_08080B98: .4byte 0x0858B3B0
_08080B9C:
	ldr r0, _08080BB0 @ =0x0858B3B1
_08080B9E:
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x2e
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x22
	strb r3, [r0]
	b _08080BC6
	.align 2, 0
_08080BB0: .4byte 0x0858B3B1
_08080BB4:
	ldr r0, _08080BB8 @ =0x0858B3B2
	b _08080BBE
	.align 2, 0
_08080BB8: .4byte 0x0858B3B2
_08080BBC:
	ldr r0, _08080BE8 @ =0x0858B3B3
_08080BBE:
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x22
	strb r0, [r1]
_08080BC6:
	adds r0, r2, #0
	adds r0, #0x20
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0xb
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #1
	strb r0, [r2, #0x16]
	strb r1, [r2, #0x14]
	strb r1, [r2, #0x15]
_08080BE2:
	pop {r0}
	bx r0
	.align 2, 0
_08080BE8: .4byte 0x0858B3B3

	thumb_func_start EraseSramCheckForInput
EraseSramCheckForInput: @ 0x08080BEC
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
	ldr r0, _08080C08 @ =gNonGameplayRam
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #1
	beq _08080C3A
	cmp r1, #1
	bgt _08080C0C
	cmp r1, #0
	beq _08080C16
	b _08080CCA
	.align 2, 0
_08080C08: .4byte gNonGameplayRam
_08080C0C:
	cmp r1, #2
	beq _08080C62
	cmp r1, #3
	beq _08080C94
	b _08080CCA
_08080C16:
	ldr r0, _08080C28 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08080C2C
	movs r0, #0x81
	b _08080CA2
	.align 2, 0
_08080C28: .4byte gChangedInput
_08080C2C:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08080CCA
	movs r5, #2
	movs r4, #1
	b _08080CD0
_08080C3A:
	ldr r0, _08080C4C @ =gChangedInput
	ldrh r2, [r0]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08080C50
	movs r0, #0x80
	b _08080CA2
	.align 2, 0
_08080C4C: .4byte gChangedInput
_08080C50:
	ands r1, r2
	cmp r1, #0
	beq _08080CCA
	movs r0, #0x82
	strb r0, [r3, #1]
	movs r4, #1
	movs r0, #4
	strb r0, [r3, #8]
	b _08080CCA
_08080C62:
	ldr r0, _08080C74 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08080C78
	movs r0, #0x83
	b _08080CA2
	.align 2, 0
_08080C74: .4byte gChangedInput
_08080C78:
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08080CCA
	movs r0, #0x80
	strb r0, [r3, #1]
	strb r5, [r3, #8]
	movs r0, #1
	ands r0, r1
	movs r4, #3
	cmp r0, #0
	beq _08080CCA
	movs r4, #1
	b _08080CCA
_08080C94:
	ldr r0, _08080CA8 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08080CAC
	movs r0, #0x82
_08080CA2:
	strb r0, [r3, #1]
	movs r4, #4
	b _08080CCA
	.align 2, 0
_08080CA8: .4byte gChangedInput
_08080CAC:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08080CBA
	movs r5, #1
	movs r4, #2
	b _08080CD0
_08080CBA:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08080CCA
	movs r0, #0x80
	strb r0, [r3, #1]
	movs r4, #3
	strb r5, [r3, #8]
_08080CCA:
	movs r0, #0
	cmp r0, #0
	beq _08080CDA
_08080CD0:
	movs r1, #0
	movs r0, #2
	strb r0, [r3, #0x16]
	strb r1, [r3, #0x14]
	strb r1, [r3, #0x15]
_08080CDA:
	ldr r0, _08080CF4 @ =0x0858B3B4
	lsls r1, r4, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08080CEA
	bl SoundPlay
_08080CEA:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08080CF4: .4byte 0x0858B3B4

	thumb_func_start EraseSramMenuInit
EraseSramMenuInit: @ 0x08080CF8
	push {r4, r5, lr}
	sub sp, #4
	ldr r3, _08080E4C @ =0x04000208
	movs r5, #0
	strh r5, [r3]
	ldr r2, _08080E50 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _08080E54 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08080E58 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08080E5C @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _08080E60 @ =EraseSramLoadingVBlank
	bl CallbackSetVBlank
	ldr r1, _08080E64 @ =0x04000050
	movs r0, #0xbf
	strh r0, [r1]
	ldr r0, _08080E68 @ =gWrittenToBldy
	movs r1, #0x10
	strh r1, [r0]
	ldr r0, _08080E6C @ =0x04000054
	strh r1, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r1, _08080E70 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r4, _08080E74 @ =gNonGameplayRam
	str r4, [r1, #4]
	ldr r0, _08080E78 @ =0x85000150
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl ClearGfxRam
	ldr r0, _08080E7C @ =gNextOamSlot
	strb r5, [r0]
	bl ResetFreeOam
	ldr r1, _08080E80 @ =0x03000011
	ldrb r0, [r1]
	strb r0, [r4, #2]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08080D66
	movs r0, #2
	strb r0, [r4, #2]
	strb r5, [r1]
_08080D66:
	ldr r1, _08080E84 @ =0x04000006
	ldrh r0, [r1]
	subs r0, #0x15
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08080E88 @ =0x085823D0
	ldr r3, _08080E8C @ =0x085822F0
	ldr r4, _08080E90 @ =0x0858340C
	cmp r0, #0x8b
	bhi _08080D86
_08080D7A:
	ldrh r0, [r1]
	subs r0, #0x15
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x8b
	bls _08080D7A
_08080D86:
	ldr r0, _08080E70 @ =0x040000D4
	str r2, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _08080E94 @ =0x80000100
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r3, [r0]
	ldr r1, _08080E98 @ =0x05000200
	str r1, [r0, #4]
	ldr r1, _08080E9C @ =0x80000070
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _08080EA0 @ =0x06001000
	adds r0, r4, #0
	bl LZ77UncompVram
	ldr r0, _08080EA4 @ =0x08582BBC
	ldr r1, _08080EA8 @ =0x06012000
	bl LZ77UncompVram
	ldr r5, _08080EAC @ =0x0879C228
	ldr r4, _08080E74 @ =gNonGameplayRam
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r1, r5, #4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08080EB0 @ =0x06011000
	bl LZ77UncompVram
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r1, _08080EB4 @ =0x06010000
	bl LZ77UncompVram
	ldr r0, _08080EB8 @ =0x0858ABE4
	ldr r1, _08080EBC @ =0x0600D000
	bl LZ77UncompVram
	ldr r0, _08080EC0 @ =0x0858ADF0
	ldr r1, _08080EC4 @ =0x0600F000
	bl LZ77UncompVram
	ldr r0, _08080EC8 @ =0x04000008
	movs r1, #0
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	ldr r2, _08080ECC @ =0x0400000A
	ldr r3, _08080ED0 @ =0x00001A01
	adds r0, r3, #0
	strh r0, [r2]
	adds r2, #4
	ldr r3, _08080ED4 @ =0x00001E03
	adds r0, r3, #0
	strh r0, [r2]
	ldr r0, _08080ED8 @ =gWrittenToBldalpha_Evb
	strh r1, [r0]
	ldr r0, _08080EDC @ =0x04000052
	strh r1, [r0]
	ldr r0, _08080EE0 @ =gUnk_3000be3
	strb r1, [r0]
	ldr r0, _08080EE4 @ =gBg1XPosition
	strh r1, [r0]
	ldr r0, _08080EE8 @ =gBg1YPosition
	strh r1, [r0]
	ldr r0, _08080EEC @ =0x03001230
	strh r1, [r0]
	ldr r0, _08080EF0 @ =0x03001232
	strh r1, [r0]
	bl EraseSramResetOam
	bl EraseSramProcessOam
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xd0
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _08080EF4 @ =EraseSramVBlank
	bl CallbackSetVBlank
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08080E4C: .4byte 0x04000208
_08080E50: .4byte 0x04000004
_08080E54: .4byte 0x0000FFEF
_08080E58: .4byte 0x04000200
_08080E5C: .4byte 0x0000FFFD
_08080E60: .4byte EraseSramLoadingVBlank
_08080E64: .4byte 0x04000050
_08080E68: .4byte gWrittenToBldy
_08080E6C: .4byte 0x04000054
_08080E70: .4byte 0x040000D4
_08080E74: .4byte gNonGameplayRam
_08080E78: .4byte 0x85000150
_08080E7C: .4byte gNextOamSlot
_08080E80: .4byte 0x03000011
_08080E84: .4byte 0x04000006
_08080E88: .4byte 0x085823D0
_08080E8C: .4byte 0x085822F0
_08080E90: .4byte 0x0858340C
_08080E94: .4byte 0x80000100
_08080E98: .4byte 0x05000200
_08080E9C: .4byte 0x80000070
_08080EA0: .4byte 0x06001000
_08080EA4: .4byte 0x08582BBC
_08080EA8: .4byte 0x06012000
_08080EAC: .4byte 0x0879C228
_08080EB0: .4byte 0x06011000
_08080EB4: .4byte 0x06010000
_08080EB8: .4byte 0x0858ABE4
_08080EBC: .4byte 0x0600D000
_08080EC0: .4byte 0x0858ADF0
_08080EC4: .4byte 0x0600F000
_08080EC8: .4byte 0x04000008
_08080ECC: .4byte 0x0400000A
_08080ED0: .4byte 0x00001A01
_08080ED4: .4byte 0x00001E03
_08080ED8: .4byte gWrittenToBldalpha_Evb
_08080EDC: .4byte 0x04000052
_08080EE0: .4byte gUnk_3000be3
_08080EE4: .4byte gBg1XPosition
_08080EE8: .4byte gBg1YPosition
_08080EEC: .4byte 0x03001230
_08080EF0: .4byte 0x03001232
_08080EF4: .4byte EraseSramVBlank

	thumb_func_start EraseSramResetOam
EraseSramResetOam: @ 0x08080EF8
	push {lr}
	ldr r3, _08080F48 @ =gNonGameplayRam
	movs r1, #0
	strb r1, [r3]
	movs r0, #0x80
	strb r0, [r3, #1]
	ldr r0, _08080F4C @ =0x0858B3B0
	ldrb r0, [r0]
	adds r2, r3, #0
	adds r2, #0x2e
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r2, _08080F50 @ =0x0858B3BE
	ldrb r0, [r2, #1]
	strh r0, [r3, #0x24]
	ldrb r0, [r2]
	strh r0, [r3, #0x26]
	movs r0, #1
	strb r0, [r3, #0x16]
	strb r1, [r3, #0x14]
	strb r1, [r3, #0x15]
	adds r0, r3, #0
	adds r0, #0x22
	strb r1, [r0]
	subs r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldrb r0, [r2, #3]
	strh r0, [r3, #0x18]
	ldrb r0, [r2, #2]
	strh r0, [r3, #0x1a]
	bl EraseSramUpdateCursorPosition
	pop {r0}
	bx r0
	.align 2, 0
_08080F48: .4byte gNonGameplayRam
_08080F4C: .4byte 0x0858B3B0
_08080F50: .4byte 0x0858B3BE

	thumb_func_start EraseSramUpdateCursorPosition
EraseSramUpdateCursorPosition: @ 0x08080F54
	push {r4, r5, r6, lr}
	ldr r4, _08080F94 @ =gNonGameplayRam
	ldr r6, _08080F98 @ =0x0858B3BE
	ldrb r2, [r4]
	lsrs r2, r2, #1
	lsls r2, r2, #1
	adds r3, r6, #1
	adds r3, r2, r3
	ldr r5, _08080F9C @ =0x0858B3C2
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r1, r5, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r4, #0xc]
	adds r2, r2, r6
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r4, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080F94: .4byte gNonGameplayRam
_08080F98: .4byte 0x0858B3BE
_08080F9C: .4byte 0x0858B3C2

	thumb_func_start EraseSramVBlank
EraseSramVBlank: @ 0x08080FA0
	push {lr}
	ldr r1, _08080FF0 @ =0x040000D4
	ldr r0, _08080FF4 @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08080FF8 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r1, #0x80
	ldr r0, _08080FFC @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	subs r1, #0x40
	ldr r0, _08081000 @ =gBg1XPosition
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08081004 @ =gBg1YPosition
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #6
	ldr r0, _08081008 @ =0x03001230
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0808100C @ =0x03001232
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r2, _08081010 @ =gNonGameplayRam
	ldrh r1, [r2, #6]
	cmp r1, #0
	beq _08080FEC
	ldr r0, _08081014 @ =0x04000050
	strh r1, [r0]
	movs r0, #0
	strh r0, [r2, #6]
_08080FEC:
	pop {r0}
	bx r0
	.align 2, 0
_08080FF0: .4byte 0x040000D4
_08080FF4: .4byte gOamData
_08080FF8: .4byte 0x84000100
_08080FFC: .4byte gWrittenToBldy
_08081000: .4byte gBg1XPosition
_08081004: .4byte gBg1YPosition
_08081008: .4byte 0x03001230
_0808100C: .4byte 0x03001232
_08081010: .4byte gNonGameplayRam
_08081014: .4byte 0x04000050

	thumb_func_start EraseSramLoadingVBlank
EraseSramLoadingVBlank: @ 0x08081018
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EraseSramProcessOam
EraseSramProcessOam: @ 0x08081024
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _0808114C @ =gNextOamSlot
	movs r0, #0
	strb r0, [r1]
	ldr r5, _08081150 @ =gOamData
	movs r0, #0
	str r0, [sp]
	movs r6, #0
	movs r4, #0
_08081040:
	lsls r0, r4, #1
	adds r1, r0, r4
	lsls r1, r1, #2
	ldr r2, _08081154 @ =gNonGameplayRam
	adds r3, r1, r2
	ldrb r1, [r3, #0x16]
	adds r2, r0, #0
	adds r0, r4, #1
	mov r8, r0
	cmp r1, #0
	beq _0808112C
	adds r0, r1, #0
	cmp r0, #0
	beq _08081092
	cmp r0, #0
	blt _08081092
	cmp r0, #6
	bgt _08081092
	ldr r1, _08081158 @ =0x0879C260
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r7, [r0]
	ldrb r0, [r3, #0x15]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r1, [r3, #0x14]
	ldrb r0, [r0, #4]
	cmp r1, r0
	blo _08081092
	movs r0, #0
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x15]
	adds r0, #1
	strb r0, [r3, #0x15]
	ldrb r0, [r3, #0x15]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _08081092
	strb r0, [r3, #0x15]
_08081092:
	adds r2, r2, r4
	lsls r2, r2, #2
	ldr r1, _08081154 @ =gNonGameplayRam
	adds r2, r2, r1
	ldrb r0, [r2, #0x14]
	adds r0, #1
	strb r0, [r2, #0x14]
	ldr r1, _0808115C @ =gBg1YPosition
	ldrh r0, [r2, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r1, _08081160 @ =gBg1XPosition
	ldrh r0, [r2, #0xe]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrb r0, [r2, #0x15]
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r3, [r7]
	ldrh r0, [r3]
	ldr r2, [sp]
	adds r2, r2, r0
	str r2, [sp]
	adds r3, #2
	adds r4, #1
	mov r8, r4
	cmp r6, r2
	bge _0808112C
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	lsls r0, r6, #3
	ldr r1, _08081150 @ =gOamData
	adds r4, r0, r1
	ldr r2, _08081164 @ =0x000001FF
	mov sl, r2
	ldr r0, [sp]
	subs r6, r0, r6
_080810E8:
	ldrh r0, [r3]
	adds r3, #2
	strh r0, [r5]
	adds r5, #2
	add r0, sb
	strb r0, [r4]
	ldrh r1, [r3]
	adds r3, #2
	strh r1, [r5]
	adds r5, #2
	add r1, ip
	mov r2, sl
	ands r1, r2
	ldrh r2, [r4, #2]
	ldr r0, _08081168 @ =0xFFFFFE00
	ands r0, r2
	orrs r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3]
	strh r0, [r5]
	adds r3, #2
	ldrb r1, [r4, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #5]
	adds r5, #4
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bne _080810E8
	ldr r6, [sp]
_0808112C:
	mov r4, r8
	cmp r4, #2
	ble _08081040
	mov r0, sp
	ldrb r1, [r0]
	ldr r0, _0808114C @ =gNextOamSlot
	strb r1, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808114C: .4byte gNextOamSlot
_08081150: .4byte gOamData
_08081154: .4byte gNonGameplayRam
_08081158: .4byte 0x0879C260
_0808115C: .4byte gBg1YPosition
_08081160: .4byte gBg1XPosition
_08081164: .4byte 0x000001FF
_08081168: .4byte 0xFFFFFE00
