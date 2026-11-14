    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start NewFileIntroCheckMonologueEnded
NewFileIntroCheckMonologueEnded: @ 0x08097DD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	mov r8, r0
	ldr r6, _08097E0C @ =gNonGameplayRam
	movs r0, #0x83
	lsls r0, r0, #2
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r4, r0, #1
	strh r4, [r7]
	ldr r3, [r6]
	ldrh r2, [r3]
	adds r5, r2, #0
	movs r0, #0xff
	lsls r0, r0, #8
	mov ip, r0
	cmp r5, ip
	bne _08097E14
	mov r0, r8
	strh r0, [r7]
	ldr r7, _08097E10 @ =0x00000213
	adds r1, r6, r7
	movs r0, #0x64
	strb r0, [r1]
	movs r0, #1
	mov r8, r0
	b _08097E96
	.align 2, 0
_08097E0C: .4byte gNonGameplayRam
_08097E10: .4byte 0x00000213
_08097E14:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r5, r0
	bne _08097E68
	mov r0, r8
	strh r0, [r7]
	movs r7, #0x86
	lsls r7, r7, #2
	adds r4, r6, r7
	ldrb r1, [r4]
	cmp r1, #1
	bne _08097E96
	adds r2, r3, #2
	str r2, [r6]
	subs r7, #5
	adds r0, r6, r7
	strb r1, [r0]
	ldrh r1, [r3, #2]
	movs r0, #0xfd
	lsls r0, r0, #8
	cmp r1, r0
	bne _08097E46
	movs r0, #2
	strb r0, [r4]
	b _08097E96
_08097E46:
	cmp r1, ip
	beq _08097E5C
	cmp r1, r5
	bne _08097E62
	movs r0, #4
	strb r0, [r4]
	adds r0, r2, #2
	str r0, [r6]
	ldrh r0, [r2, #2]
	cmp r0, ip
	bne _08097E96
_08097E5C:
	movs r0, #3
	strb r0, [r4]
	b _08097E96
_08097E62:
	movs r0, #0
	strb r0, [r4]
	b _08097E96
_08097E68:
	mov r0, ip
	ands r0, r2
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _08097E82
	movs r1, #0xff
	ands r1, r2
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _08097E96
	b _08097E8A
_08097E82:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _08097E96
_08097E8A:
	ldr r0, _08097EA4 @ =0x00000213
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	strh r0, [r7]
_08097E96:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08097EA4: .4byte 0x00000213

	thumb_func_start EndingCheckMonologueEnded
EndingCheckMonologueEnded: @ 0x08097EA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0
	mov r8, r0
	ldr r6, _08097EE4 @ =gNonGameplayRam
	movs r0, #0x83
	lsls r0, r0, #2
	adds r7, r6, r0
	ldrh r0, [r7]
	adds r4, r0, #1
	strh r4, [r7]
	ldr r3, [r6]
	ldrh r2, [r3]
	adds r5, r2, #0
	movs r0, #0xff
	lsls r0, r0, #8
	mov ip, r0
	cmp r5, ip
	bne _08097EEC
	mov r0, r8
	strh r0, [r7]
	ldr r7, _08097EE8 @ =0x00000213
	adds r1, r6, r7
	movs r0, #0x64
	strb r0, [r1]
	movs r0, #1
	mov r8, r0
	b _08097F6E
	.align 2, 0
_08097EE4: .4byte gNonGameplayRam
_08097EE8: .4byte 0x00000213
_08097EEC:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r5, r0
	bne _08097F40
	mov r0, r8
	strh r0, [r7]
	movs r7, #0x86
	lsls r7, r7, #2
	adds r4, r6, r7
	ldrb r1, [r4]
	cmp r1, #1
	bne _08097F6E
	adds r2, r3, #2
	str r2, [r6]
	subs r7, #5
	adds r0, r6, r7
	strb r1, [r0]
	ldrh r1, [r3, #2]
	movs r0, #0xfd
	lsls r0, r0, #8
	cmp r1, r0
	bne _08097F1E
	movs r0, #2
	strb r0, [r4]
	b _08097F6E
_08097F1E:
	cmp r1, ip
	beq _08097F34
	cmp r1, r5
	bne _08097F3A
	movs r0, #4
	strb r0, [r4]
	adds r0, r2, #2
	str r0, [r6]
	ldrh r0, [r2, #2]
	cmp r0, ip
	bne _08097F6E
_08097F34:
	movs r0, #3
	strb r0, [r4]
	b _08097F6E
_08097F3A:
	movs r0, #0
	strb r0, [r4]
	b _08097F6E
_08097F40:
	mov r0, ip
	ands r0, r2
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _08097F5A
	movs r1, #0xff
	ands r1, r2
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _08097F6E
	b _08097F62
_08097F5A:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08097F6E
_08097F62:
	ldr r0, _08097F7C @ =0x00000213
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	mov r0, r8
	strh r0, [r7]
_08097F6E:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08097F7C: .4byte 0x00000213

	thumb_func_start SpecialCutsceneProcessMonologue
SpecialCutsceneProcessMonologue: @ 0x08097F80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r5, _08097FF0 @ =gNonGameplayRam
	ldr r2, [r5]
	ldrh r3, [r2]
	adds r1, r3, #0
	movs r6, #0xff
	lsls r6, r6, #8
	adds r4, r5, #0
	cmp r1, r6
	bne _08097F9C
	b _08098142
_08097F9C:
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r1, r0
	bne _08097FF8
	ldrh r0, [r4, #0xc]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1b
	bhi _08097FD4
	adds r6, r4, #0
	adds r5, #0x14
	movs r3, #0xff
_08097FB6:
	ldrh r1, [r6, #0xe]
	lsrs r1, r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r2, r0
	adds r0, r0, r5
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1b
	bls _08097FB6
_08097FD4:
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	adds r0, #2
	strh r0, [r4, #0xe]
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	ldr r2, _08097FF4 @ =0x00000212
	adds r0, r4, r2
	strb r1, [r0]
	b _08098142
	.align 2, 0
_08097FF0: .4byte gNonGameplayRam
_08097FF4: .4byte 0x00000212
_08097FF8:
	movs r0, #0xfd
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809807C
	movs r2, #0
	str r2, [sp, #4]
	ldr r1, _08098064 @ =0x040000D4
	add r5, sp, #4
	str r5, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08098068 @ =0x85001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r3, #0
	strh r2, [r4, #0x12]
	strh r2, [r4, #0x10]
	strh r2, [r4, #0xe]
	strh r2, [r4, #0xc]
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	ldr r5, _0809806C @ =0x00000212
	adds r0, r4, r5
	strb r3, [r0]
	str r2, [sp, #4]
	add r0, sp, #4
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x14
	str r0, [r1, #4]
	ldr r3, _08098070 @ =0x8500003F
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	str r2, [sp, #4]
	add r2, sp, #4
	str r2, [r1]
	movs r5, #0x88
	lsls r5, r5, #1
	adds r0, r4, r5
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #0x12
	str r0, [r1]
	ldr r0, _08098074 @ =0x06004800
	str r0, [r1, #4]
	ldr r0, _08098078 @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08098142
	.align 2, 0
_08098064: .4byte 0x040000D4
_08098068: .4byte 0x85001200
_0809806C: .4byte 0x00000212
_08098070: .4byte 0x8500003F
_08098074: .4byte 0x06004800
_08098078: .4byte 0x84000200
_0809807C:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809808C
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	b _08098142
_0809808C:
	adds r0, r6, #0
	ands r0, r3
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _0809809E
	adds r0, r2, #2
	str r0, [r4]
	b _08098142
_0809809E:
	ldrh r4, [r5, #0xc]
	lsls r4, r4, #5
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #0xa
	adds r4, r4, r0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r4, r4, r0
	ldrh r0, [r2]
	bl TextGetCharacterWidth
	mov r8, r0
	ldr r0, [r5]
	ldrh r0, [r0]
	mov r1, r8
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _08098150 @ =0x00000212
	adds r6, r5, r1
	ldrb r3, [r6]
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	bl TextDrawCharacter
	ldrh r0, [r5, #0xc]
	cmp r0, #0x1b
	bhi _0809813A
	ldrh r1, [r5, #0xe]
	lsrs r1, r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	adds r7, r5, #0
	adds r7, #0x14
	adds r0, r0, r7
	movs r1, #4
	strb r1, [r0]
	ldrb r0, [r6]
	add r0, r8
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r5, #0
	cmp r0, #7
	bls _0809813A
	adds r2, r4, #0
	adds r3, r6, #0
	adds r4, r7, #0
_08098104:
	ldrb r0, [r3]
	adds r1, r0, #0
	subs r1, #8
	strb r1, [r3]
	ldrh r0, [r2, #0xc]
	adds r0, #1
	strh r0, [r2, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _0809813A
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _08098134
	ldrh r0, [r2, #0xe]
	lsrs r0, r0, #1
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldrh r5, [r2, #0xc]
	adds r1, r1, r5
	adds r1, r1, r4
	movs r0, #4
	strb r0, [r1]
_08098134:
	ldrb r0, [r3]
	cmp r0, #7
	bhi _08098104
_0809813A:
	ldr r1, _08098154 @ =gNonGameplayRam
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_08098142:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098150: .4byte 0x00000212
_08098154: .4byte gNonGameplayRam

	thumb_func_start unk_98158
unk_98158: @ 0x08098158
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r1, _08098198 @ =gNonGameplayRam
	ldrh r6, [r1, #0x10]
	ldrh r0, [r1, #0x12]
	lsrs r7, r0, #1
	ldrh r0, [r1, #0xe]
	lsrs r0, r0, #1
	str r1, [sp, #8]
	cmp r7, r0
	bls _08098178
	b _0809827C
_08098178:
	str r1, [sp]
_0809817A:
	ldr r2, [sp]
	ldr r0, [r2]
	ldrh r0, [r0]
	movs r3, #0xfc
	lsls r3, r3, #8
	cmp r0, r3
	bne _0809819C
	ldrh r0, [r1, #0xc]
	cmp r0, #0x1b
	bhi _080981B6
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	b _080981BA
	.align 2, 0
_08098198: .4byte gNonGameplayRam
_0809819C:
	ldrh r0, [r1, #0xe]
	lsrs r0, r0, #1
	cmp r7, r0
	bne _080981B6
	ldr r1, [sp]
	ldrh r0, [r1, #0xc]
	movs r2, #0x1c
	mov ip, r2
	cmp r0, #0x1b
	bhi _080981BA
	adds r3, r0, #0
	mov ip, r3
	b _080981BA
_080981B6:
	movs r5, #0x1c
	mov ip, r5
_080981BA:
	adds r0, r7, #1
	str r0, [sp, #4]
	cmp r6, ip
	bhs _08098268
	ldr r1, _08098230 @ =gNonGameplayRam
	mov r8, r1
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	mov sl, r0
	ldr r2, _08098234 @ =0x00000FFF
	mov sb, r2
_080981D2:
	mov r3, sl
	adds r2, r6, r3
	ldr r5, _08098238 @ =0x03001594
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, #5
	bne _0809825A
	movs r0, #0
	strb r0, [r1]
	ldr r0, [sp, #8]
	adds r0, #0x14
	adds r2, r2, r0
	ldrb r0, [r2]
	subs r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _08098244
	lsls r2, r6, #1
	lsls r0, r7, #7
	adds r2, r2, r0
	ldr r0, _0809823C @ =0x06004842
	adds r0, r2, r0
	str r0, [sp, #0xc]
	ldr r1, _08098240 @ =0x06004882
	adds r2, r2, r1
	ldrh r3, [r0]
	ldrh r4, [r2]
	lsrs r0, r3, #0xc
	lsrs r1, r4, #0xc
	subs r0, #1
	lsls r0, r0, #0x10
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r0, #4
	mov r5, sb
	ands r3, r5
	orrs r0, r3
	ldr r3, [sp, #0xc]
	strh r0, [r3]
	lsrs r1, r1, #4
	ands r4, r5
	orrs r1, r4
	strh r1, [r2]
	b _0809825E
	.align 2, 0
_08098230: .4byte gNonGameplayRam
_08098234: .4byte 0x00000FFF
_08098238: .4byte 0x03001594
_0809823C: .4byte 0x06004842
_08098240: .4byte 0x06004882
_08098244:
	cmp r0, #0
	bne _08098252
	mov r5, r8
	strh r6, [r5, #0x10]
	lsls r0, r7, #1
	strh r0, [r5, #0x12]
	b _0809825E
_08098252:
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
	b _08098268
_0809825A:
	adds r0, #1
	strb r0, [r1]
_0809825E:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, ip
	blo _080981D2
_08098268:
	movs r6, #0
	ldr r1, [sp, #4]
	lsls r0, r1, #0x10
	lsrs r7, r0, #0x10
	ldr r1, [sp, #8]
	ldrh r0, [r1, #0xe]
	lsrs r0, r0, #1
	cmp r7, r0
	bhi _0809827C
	b _0809817A
_0809827C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start EndingProcessAdamText
EndingProcessAdamText: @ 0x0809828C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r7, #0
	ldr r5, _080982E8 @ =gNonGameplayRam
	movs r0, #0x83
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r2, r0, #1
	movs r1, #0
	mov sb, r1
	strh r2, [r6]
	ldr r3, [r5]
	ldrh r4, [r3]
	adds r1, r4, #0
	movs r0, #0xff
	lsls r0, r0, #8
	mov ip, r0
	cmp r1, ip
	bne _080982FC
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080982C4
	b _08098492
_080982C4:
	strh r7, [r6]
	str r7, [sp, #4]
	ldr r1, _080982EC @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _080982F0 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _080982F4 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	strh r7, [r5, #0xe]
	strh r7, [r5, #0xc]
	ldr r1, _080982F8 @ =0x00000212
	adds r0, r5, r1
	mov r1, sb
	strb r1, [r0]
	movs r7, #1
	b _08098492
	.align 2, 0
_080982E8: .4byte gNonGameplayRam
_080982EC: .4byte 0x040000D4
_080982F0: .4byte 0x0600D000
_080982F4: .4byte 0x85000400
_080982F8: .4byte 0x00000212
_080982FC:
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809836C
	ldrh r0, [r5, #0xe]
	cmp r0, #1
	bhi _0809832C
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08098314
	b _08098492
_08098314:
	strh r7, [r6]
	movs r0, #2
	strh r0, [r5, #0xe]
	strh r7, [r5, #0xc]
	ldr r1, _08098328 @ =0x00000212
	adds r0, r5, r1
	mov r1, sb
	strb r1, [r0]
	b _08098408
	.align 2, 0
_08098328: .4byte 0x00000212
_0809832C:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7d
	bhi _08098336
	b _08098492
_08098336:
	strh r7, [r6]
	strh r7, [r5, #0xe]
	strh r7, [r5, #0xc]
	ldr r1, _0809835C @ =0x00000212
	adds r0, r5, r1
	mov r1, sb
	strb r1, [r0]
	adds r0, r3, #2
	str r0, [r5]
	str r7, [sp, #4]
	ldr r1, _08098360 @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _08098364 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08098368 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08098492
	.align 2, 0
_0809835C: .4byte 0x00000212
_08098360: .4byte 0x040000D4
_08098364: .4byte 0x0600D000
_08098368: .4byte 0x85000400
_0809836C:
	movs r0, #0xfd
	lsls r0, r0, #8
	mov r8, r0
	cmp r1, r8
	bne _080983B8
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08098380
	b _08098492
_08098380:
	strh r7, [r6]
	str r7, [sp, #4]
	ldr r1, _080983A8 @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _080983AC @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _080983B0 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	strh r7, [r5, #0xe]
	strh r7, [r5, #0xc]
	adds r0, r3, #2
	str r0, [r5]
	ldr r1, _080983B4 @ =0x00000212
	adds r0, r5, r1
	mov r1, sb
	strb r1, [r0]
	b _08098492
	.align 2, 0
_080983A8: .4byte 0x040000D4
_080983AC: .4byte 0x0600D000
_080983B0: .4byte 0x85000400
_080983B4: .4byte 0x00000212
_080983B8:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r1, r0
	bne _080983EE
	strh r7, [r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #1
	bne _08098492
	adds r0, r3, #2
	str r0, [r5]
	ldrh r0, [r3, #2]
	cmp r0, r8
	bne _080983DE
	movs r0, #2
	strb r0, [r1]
	b _08098492
_080983DE:
	cmp r0, ip
	bne _080983E8
	movs r0, #3
	strb r0, [r1]
	b _08098492
_080983E8:
	mov r0, sb
	strb r0, [r1]
	b _08098492
_080983EE:
	mov r0, ip
	ands r0, r4
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _0809840E
	movs r1, #0xff
	ands r1, r4
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _08098492
	strh r7, [r6]
_08098408:
	adds r0, r3, #2
	str r0, [r5]
	b _08098492
_0809840E:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08098492
	strh r7, [r6]
	ldrh r4, [r5, #0xc]
	lsls r4, r4, #5
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #0xa
	adds r4, r4, r0
	ldr r1, _080984A4 @ =0x0600D000
	adds r4, r4, r1
	ldrh r0, [r3]
	bl TextGetCharacterWidth
	mov r8, r0
	ldr r0, [r5]
	ldrh r0, [r0]
	mov r1, r8
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _080984A8 @ =0x00000212
	adds r6, r5, r1
	ldrb r3, [r6]
	str r7, [sp]
	adds r1, r4, #0
	bl TextDrawCharacter
	ldr r1, [r5]
	ldrh r0, [r1]
	cmp r0, #0x40
	beq _08098454
	movs r1, #1
	bl PlayCharacterAppearingSound
_08098454:
	ldrh r0, [r5, #0xc]
	adds r4, r5, #0
	cmp r0, #0x1f
	bhi _0809848C
	ldrb r0, [r6]
	add r0, r8
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0809848C
	adds r3, r4, #0
	adds r2, r6, #0
_0809846E:
	ldrb r0, [r2]
	adds r1, r0, #0
	subs r1, #8
	strb r1, [r2]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bhi _0809848C
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _0809846E
_0809848C:
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
_08098492:
	adds r0, r7, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080984A4: .4byte 0x0600D000
_080984A8: .4byte 0x00000212

	thumb_func_start IntroProcessText
IntroProcessText: @ 0x080984AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r0, #0
	mov r8, r0
	ldr r5, _08098514 @ =gNonGameplayRam
	movs r1, #0x83
	lsls r1, r1, #2
	adds r7, r5, r1
	ldrh r0, [r7]
	adds r2, r0, #1
	movs r0, #0
	mov sl, r0
	strh r2, [r7]
	ldr r6, [r5]
	ldrh r4, [r6]
	adds r3, r4, #0
	movs r1, #0xff
	lsls r1, r1, #8
	mov ip, r1
	cmp r3, ip
	bne _08098528
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bhi _080984E8
	b _080986D2
_080984E8:
	mov r0, r8
	strh r0, [r7]
	mov r1, r8
	str r1, [sp, #4]
	ldr r1, _08098518 @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _0809851C @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08098520 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	strh r1, [r5, #0xe]
	strh r1, [r5, #0xc]
	ldr r1, _08098524 @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	movs r0, #1
	mov r8, r0
	b _080986D2
	.align 2, 0
_08098514: .4byte gNonGameplayRam
_08098518: .4byte 0x040000D4
_0809851C: .4byte 0x0600D000
_08098520: .4byte 0x85000400
_08098524: .4byte 0x00000212
_08098528:
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r3, r0
	bne _0809859C
	ldrh r0, [r5, #0xe]
	cmp r0, #1
	bhi _08098558
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _08098540
	b _080986D2
_08098540:
	mov r1, r8
	strh r1, [r7]
	movs r0, #2
	strh r0, [r5, #0xe]
	strh r1, [r5, #0xc]
	ldr r1, _08098554 @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	b _08098654
	.align 2, 0
_08098554: .4byte 0x00000212
_08098558:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7a
	bhi _08098562
	b _080986D2
_08098562:
	mov r0, r8
	strh r0, [r7]
	strh r0, [r5, #0xe]
	strh r0, [r5, #0xc]
	ldr r1, _0809858C @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	adds r0, r6, #2
	str r0, [r5]
	mov r0, r8
	str r0, [sp, #4]
	ldr r1, _08098590 @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _08098594 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08098598 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _080986D2
	.align 2, 0
_0809858C: .4byte 0x00000212
_08098590: .4byte 0x040000D4
_08098594: .4byte 0x0600D000
_08098598: .4byte 0x85000400
_0809859C:
	movs r1, #0xfd
	lsls r1, r1, #8
	mov sb, r1
	cmp r3, sb
	bne _080985EC
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bhi _080985B0
	b _080986D2
_080985B0:
	mov r0, r8
	strh r0, [r7]
	mov r1, r8
	str r1, [sp, #4]
	ldr r1, _080985DC @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _080985E0 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _080985E4 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	strh r1, [r5, #0xe]
	strh r1, [r5, #0xc]
	adds r0, r6, #2
	str r0, [r5]
	ldr r1, _080985E8 @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	b _080986D2
	.align 2, 0
_080985DC: .4byte 0x040000D4
_080985E0: .4byte 0x0600D000
_080985E4: .4byte 0x85000400
_080985E8: .4byte 0x00000212
_080985EC:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r3, r0
	bne _08098638
	mov r0, r8
	strh r0, [r7]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #1
	bne _080986D2
	adds r1, r6, #2
	str r1, [r5]
	ldrh r0, [r6, #2]
	cmp r0, sb
	bne _08098614
	movs r0, #2
	strb r0, [r2]
	b _080986D2
_08098614:
	cmp r0, ip
	beq _08098626
	cmp r0, r3
	bne _08098632
	adds r0, r1, #2
	str r0, [r5]
	ldrh r0, [r1, #2]
	cmp r0, ip
	bne _0809862C
_08098626:
	movs r0, #3
	strb r0, [r2]
	b _080986D2
_0809862C:
	movs r0, #4
	strb r0, [r2]
	b _080986D2
_08098632:
	mov r0, sl
	strb r0, [r2]
	b _080986D2
_08098638:
	mov r0, ip
	ands r0, r4
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _0809865A
	movs r1, #0xff
	ands r1, r4
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _080986D2
	mov r1, r8
	strh r1, [r7]
_08098654:
	adds r0, r6, #2
	str r0, [r5]
	b _080986D2
_0809865A:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080986D2
	mov r0, r8
	strh r0, [r7]
	ldrh r4, [r5, #0xc]
	lsls r4, r4, #5
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #0xa
	adds r4, r4, r0
	ldr r1, _080986E4 @ =0x0600D000
	adds r4, r4, r1
	ldrh r0, [r6]
	bl TextGetCharacterWidth
	adds r7, r0, #0
	ldr r0, [r5]
	ldrh r0, [r0]
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _080986E8 @ =0x00000212
	adds r6, r5, r1
	ldrb r3, [r6]
	mov r1, r8
	str r1, [sp]
	adds r1, r4, #0
	bl TextDrawCharacter
	ldrh r0, [r5, #0xc]
	cmp r0, #0x1f
	bhi _080986CA
	ldrb r0, [r6]
	adds r0, r0, r7
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080986CA
	adds r3, r5, #0
	adds r2, r6, #0
_080986AC:
	ldrb r0, [r2]
	adds r1, r0, #0
	subs r1, #8
	strb r1, [r2]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bhi _080986CA
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _080986AC
_080986CA:
	ldr r1, _080986EC @ =gNonGameplayRam
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_080986D2:
	mov r0, r8
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080986E4: .4byte 0x0600D000
_080986E8: .4byte 0x00000212
_080986EC: .4byte gNonGameplayRam

	thumb_func_start NewFileIntroProcessAdamText
NewFileIntroProcessAdamText: @ 0x080986F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r0, #0
	mov r8, r0
	ldr r5, _08098758 @ =gNonGameplayRam
	movs r1, #0x83
	lsls r1, r1, #2
	adds r7, r5, r1
	ldrh r0, [r7]
	adds r2, r0, #1
	movs r0, #0
	mov sl, r0
	strh r2, [r7]
	ldr r6, [r5]
	ldrh r4, [r6]
	adds r3, r4, #0
	movs r1, #0xff
	lsls r1, r1, #8
	mov ip, r1
	cmp r3, ip
	bne _0809876C
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bhi _0809872C
	b _08098924
_0809872C:
	mov r0, r8
	strh r0, [r7]
	mov r1, r8
	str r1, [sp, #4]
	ldr r1, _0809875C @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _08098760 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08098764 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	strh r1, [r5, #0xe]
	strh r1, [r5, #0xc]
	ldr r1, _08098768 @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	movs r0, #1
	mov r8, r0
	b _08098924
	.align 2, 0
_08098758: .4byte gNonGameplayRam
_0809875C: .4byte 0x040000D4
_08098760: .4byte 0x0600D000
_08098764: .4byte 0x85000400
_08098768: .4byte 0x00000212
_0809876C:
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r3, r0
	bne _080987E0
	ldrh r0, [r5, #0xe]
	cmp r0, #1
	bhi _0809879C
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _08098784
	b _08098924
_08098784:
	mov r1, r8
	strh r1, [r7]
	movs r0, #2
	strh r0, [r5, #0xe]
	strh r1, [r5, #0xc]
	ldr r1, _08098798 @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	b _08098898
	.align 2, 0
_08098798: .4byte 0x00000212
_0809879C:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7a
	bhi _080987A6
	b _08098924
_080987A6:
	mov r0, r8
	strh r0, [r7]
	strh r0, [r5, #0xe]
	strh r0, [r5, #0xc]
	ldr r1, _080987D0 @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	adds r0, r6, #2
	str r0, [r5]
	mov r0, r8
	str r0, [sp, #4]
	ldr r1, _080987D4 @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _080987D8 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _080987DC @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _08098924
	.align 2, 0
_080987D0: .4byte 0x00000212
_080987D4: .4byte 0x040000D4
_080987D8: .4byte 0x0600D000
_080987DC: .4byte 0x85000400
_080987E0:
	movs r1, #0xfd
	lsls r1, r1, #8
	mov sb, r1
	cmp r3, sb
	bne _08098830
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bhi _080987F4
	b _08098924
_080987F4:
	mov r0, r8
	strh r0, [r7]
	mov r1, r8
	str r1, [sp, #4]
	ldr r1, _08098820 @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _08098824 @ =0x0600D000
	str r0, [r1, #4]
	ldr r0, _08098828 @ =0x85000400
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r1, r8
	strh r1, [r5, #0xe]
	strh r1, [r5, #0xc]
	adds r0, r6, #2
	str r0, [r5]
	ldr r1, _0809882C @ =0x00000212
	adds r0, r5, r1
	mov r1, sl
	strb r1, [r0]
	b _08098924
	.align 2, 0
_08098820: .4byte 0x040000D4
_08098824: .4byte 0x0600D000
_08098828: .4byte 0x85000400
_0809882C: .4byte 0x00000212
_08098830:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r3, r0
	bne _0809887C
	mov r0, r8
	strh r0, [r7]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #1
	bne _08098924
	adds r1, r6, #2
	str r1, [r5]
	ldrh r0, [r6, #2]
	cmp r0, sb
	bne _08098858
	movs r0, #2
	strb r0, [r2]
	b _08098924
_08098858:
	cmp r0, ip
	beq _0809886A
	cmp r0, r3
	bne _08098876
	adds r0, r1, #2
	str r0, [r5]
	ldrh r0, [r1, #2]
	cmp r0, ip
	bne _08098870
_0809886A:
	movs r0, #3
	strb r0, [r2]
	b _08098924
_08098870:
	movs r0, #4
	strb r0, [r2]
	b _08098924
_08098876:
	mov r0, sl
	strb r0, [r2]
	b _08098924
_0809887C:
	mov r0, ip
	ands r0, r4
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _0809889E
	movs r1, #0xff
	ands r1, r4
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _08098924
	mov r1, r8
	strh r1, [r7]
_08098898:
	adds r0, r6, #2
	str r0, [r5]
	b _08098924
_0809889E:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _08098924
	mov r0, r8
	strh r0, [r7]
	ldrh r4, [r5, #0xc]
	lsls r4, r4, #5
	ldrh r0, [r5, #0xe]
	lsls r0, r0, #0xa
	adds r4, r4, r0
	ldr r1, _08098938 @ =0x0600D000
	adds r4, r4, r1
	ldrh r0, [r6]
	bl TextGetCharacterWidth
	adds r7, r0, #0
	ldr r0, [r5]
	ldrh r0, [r0]
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _0809893C @ =0x00000212
	adds r6, r5, r1
	ldrb r3, [r6]
	mov r1, r8
	str r1, [sp]
	adds r1, r4, #0
	bl TextDrawCharacter
	ldr r1, [r5]
	ldrh r0, [r1]
	cmp r0, #0x40
	beq _080988E6
	movs r1, #1
	bl PlayCharacterAppearingSound
_080988E6:
	ldrh r0, [r5, #0xc]
	adds r4, r5, #0
	cmp r0, #0x1f
	bhi _0809891E
	ldrb r0, [r6]
	adds r0, r0, r7
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0809891E
	adds r3, r4, #0
	adds r2, r6, #0
_08098900:
	ldrb r0, [r2]
	adds r1, r0, #0
	subs r1, #8
	strb r1, [r2]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bhi _0809891E
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _08098900
_0809891E:
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
_08098924:
	mov r0, r8
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08098938: .4byte 0x0600D000
_0809893C: .4byte 0x00000212

	thumb_func_start Dma3Transfer_Unused1
Dma3Transfer_Unused1: @ 0x08098940
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	lsls r2, r2, #0x15
	movs r3, #0
	cmp r3, r7
	bhs _08098976
	ldr r1, _0809897C @ =0x040000D4
	lsrs r2, r2, #0x12
	movs r0, #0x84
	lsls r0, r0, #0x18
	orrs r2, r0
	movs r6, #0x80
	lsls r6, r6, #3
_08098960:
	str r5, [r1]
	str r4, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, r5, r6
	adds r4, r4, r6
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r7
	blo _08098960
_08098976:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809897C: .4byte 0x040000D4

	thumb_func_start Dma3Transfer_Unused2
Dma3Transfer_Unused2: @ 0x08098980
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	lsls r2, r2, #0x11
	movs r3, #0
	cmp r3, r6
	bhs _080989B2
	ldr r1, _080989B8 @ =0x040000D4
	lsrs r2, r2, #0x11
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r2, r0
_0809899C:
	str r5, [r1]
	str r4, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	adds r5, #0x40
	adds r4, #0x40
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r6
	blo _0809899C
_080989B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080989B8: .4byte 0x040000D4

	thumb_func_start Dma3Clear_Unused
Dma3Clear_Unused: @ 0x080989BC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r1, r1, #0x15
	movs r2, #0
	cmp r2, r5
	bhs _080989F6
	movs r7, #0
	ldr r3, _08098A00 @ =0x040000D4
	lsrs r1, r1, #0x12
	movs r0, #0x85
	lsls r0, r0, #0x18
	orrs r1, r0
	movs r6, #0x80
	lsls r6, r6, #3
_080989DE:
	str r7, [sp]
	mov r0, sp
	str r0, [r3]
	str r4, [r3, #4]
	str r1, [r3, #8]
	ldr r0, [r3, #8]
	adds r4, r4, r6
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r5
	blo _080989DE
_080989F6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098A00: .4byte 0x040000D4

	thumb_func_start unk_98a04
unk_98a04: @ 0x08098A04
	push {r4, r5, r6, r7, lr}
	movs r3, #0
	ldr r0, _08098A48 @ =gNonGameplayRam
	mov ip, r0
	movs r7, #0x88
	lsls r7, r7, #1
	add r7, ip
	movs r6, #0x96
	lsls r6, r6, #1
	add r6, ip
	movs r5, #0xb2
	lsls r5, r5, #1
	add r5, ip
	movs r4, #0xa4
	lsls r4, r4, #1
	add r4, ip
_08098A24:
	adds r0, r3, r7
	adds r1, r3, r6
	ldrb r2, [r1]
	ldrb r0, [r0]
	cmp r0, r2
	bhi _08098A50
	movs r2, #0
	strb r2, [r1]
	adds r1, r3, r5
	movs r0, #1
	strb r0, [r1]
	adds r1, r3, r4
	ldrb r0, [r1]
	cmp r0, #0x25
	bhi _08098A4C
	adds r0, #1
	b _08098A52
	.align 2, 0
_08098A48: .4byte gNonGameplayRam
_08098A4C:
	strb r2, [r1]
	b _08098A54
_08098A50:
	adds r0, r2, #1
_08098A52:
	strb r0, [r1]
_08098A54:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _08098A24
	movs r0, #0x8d
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0x9b
	lsls r2, r2, #1
	add r2, ip
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r0, r1
	bhi _08098A96
	movs r3, #0
	strb r3, [r2]
	movs r1, #0xb7
	lsls r1, r1, #1
	add r1, ip
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #1
	add r1, ip
	ldrb r0, [r1]
	cmp r0, #0xe
	bhi _08098A92
	adds r0, #1
	strb r0, [r1]
	b _08098A9A
_08098A92:
	strb r3, [r1]
	b _08098A9A
_08098A96:
	adds r0, r1, #1
	strb r0, [r2]
_08098A9A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start NewFileIntroSamusGettingCuredSetupWindow
NewFileIntroSamusGettingCuredSetupWindow: @ 0x08098AA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _08098AE4 @ =0x040000D4
	ldr r0, _08098AE8 @ =0x02001000
	str r0, [r1]
	ldr r0, _08098AEC @ =0x02002000
	str r0, [r1, #4]
	ldr r0, _08098AF0 @ =0x84000058
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08098AF4 @ =gNonGameplayRam
	ldr r2, _08098AF8 @ =0x000001F5
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _08098AFC @ =0x000001F3
	adds r0, r1, r3
	ldrb r3, [r0]
	subs r0, r2, r3
	lsls r0, r0, #0x10
	adds r7, r2, r3
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08098B00
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r3, #1
	movs r2, #0
	cmp r5, r0
	ble _08098B02
	movs r2, #0xa1
	b _08098B02
	.align 2, 0
_08098AE4: .4byte 0x040000D4
_08098AE8: .4byte 0x02001000
_08098AEC: .4byte 0x02002000
_08098AF0: .4byte 0x84000058
_08098AF4: .4byte gNonGameplayRam
_08098AF8: .4byte 0x000001F5
_08098AFC: .4byte 0x000001F3
_08098B00:
	movs r5, #0
_08098B02:
	cmp r7, #0x9f
	ble _08098B08
	movs r7, #0xa0
_08098B08:
	ldr r0, _08098BBC @ =0x083E3294
	ldr r6, _08098BC0 @ =0x000001F3
	adds r1, r1, r6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	mov ip, r1
	ldr r4, _08098BC4 @ =0x02001000
	movs r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r7, #0x10
	cmp r6, r0
	bge _08098B3E
	movs r2, #0
	adds r3, r0, #0
_08098B2A:
	strh r2, [r4]
	adds r4, #2
	lsls r0, r6, #0x10
	movs r6, #0x80
	lsls r6, r6, #9
	adds r0, r0, r6
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	blt _08098B2A
_08098B3E:
	lsls r0, r6, #0x10
	asrs r3, r1, #0x10
	cmp r0, r1
	bgt _08098B98
	ldr r0, _08098BC8 @ =0x03001678
	mov r8, r0
	adds r7, r3, #0
_08098B4C:
	mov r1, r8
	ldrb r2, [r1]
	lsls r0, r5, #2
	add r0, ip
	ldrh r1, [r0, #2]
	adds r1, r2, r1
	lsls r1, r1, #0x10
	ldrh r0, [r0]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsrs r3, r1, #0x10
	cmp r1, #0
	bge _08098B6A
	movs r3, #0
_08098B6A:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _08098B74
	movs r2, #0xf0
_08098B74:
	lsls r1, r3, #0x10
	asrs r1, r1, #8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r4]
	adds r4, #2
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r6, #0x10
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _08098B4C
_08098B98:
	lsls r1, r6, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0x9f
	bgt _08098BB2
	movs r2, #0
_08098BA2:
	strh r2, [r4]
	adds r4, #2
	movs r3, #0x80
	lsls r3, r3, #9
	adds r1, r1, r3
	asrs r0, r1, #0x10
	cmp r0, #0x9f
	ble _08098BA2
_08098BB2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098BBC: .4byte 0x083E3294
_08098BC0: .4byte 0x000001F3
_08098BC4: .4byte 0x02001000
_08098BC8: .4byte 0x03001678

	thumb_func_start SpecialCutsceneFadeIn
SpecialCutsceneFadeIn: @ 0x08098BCC
	push {lr}
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
	ldr r1, _08098BE8 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0
	beq _08098BE2
	subs r0, #1
	strh r0, [r1]
_08098BE2:
	pop {r0}
	bx r0
	.align 2, 0
_08098BE8: .4byte gWrittenToBldy

	thumb_func_start SpecialCutsceneFadOut
SpecialCutsceneFadOut: @ 0x08098BEC
	push {lr}
	bl SpecialCutsceneProcessOam
	bl SpecialCutsceneDrawAllOam
	ldr r1, _08098C08 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _08098C02
	adds r0, #1
	strh r0, [r1]
_08098C02:
	pop {r0}
	bx r0
	.align 2, 0
_08098C08: .4byte gWrittenToBldy

	thumb_func_start NewFileIntroProcessTextCursor
NewFileIntroProcessTextCursor: @ 0x08098C0C
	push {lr}
	adds r2, r0, #0
	ldr r0, _08098C28 @ =gNonGameplayRam
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r1, r0
	bne _08098C2C
	movs r0, #0xeb
	strh r0, [r2, #0xc]
	movs r0, #0x98
	strh r0, [r2, #0xe]
	b _08098C32
	.align 2, 0
_08098C28: .4byte gNonGameplayRam
_08098C2C:
	movs r0, #0x82
	lsls r0, r0, #1
	strh r0, [r2, #0xc]
_08098C32:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start SpecialCutsceneClearOam
SpecialCutsceneClearOam: @ 0x08098C38
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r6, _08098C68 @ =gNonGameplayRam
	movs r4, #0x8d
	lsls r4, r4, #2
	movs r5, #2
	rsbs r5, r5, #0
_08098C46:
	lsls r1, r3, #3
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r6
	adds r1, r1, r4
	ldrb r2, [r1]
	adds r0, r5, #0
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x13
	bls _08098C46
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098C68: .4byte gNonGameplayRam

	thumb_func_start SpecialCutsceneEnableOam
SpecialCutsceneEnableOam: @ 0x08098C6C
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r6, _08098CA4 @ =gNonGameplayRam
	movs r5, #0x8b
	lsls r5, r5, #2
	movs r4, #0x8d
	lsls r4, r4, #2
	movs r3, #1
_08098C7C:
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, r6
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08098C94
	adds r1, r1, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
_08098C94:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x13
	bls _08098C7C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098CA4: .4byte gNonGameplayRam

	thumb_func_start SpecialCutsceneDestroyOamOfType
SpecialCutsceneDestroyOamOfType: @ 0x08098CA8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	ldr r6, _08098CE0 @ =gNonGameplayRam
	movs r7, #2
	rsbs r7, r7, #0
	movs r5, #0x8b
	lsls r5, r5, #2
_08098CBA:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r2, r0, r6
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, r4
	bne _08098CE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r2, r2, r0
	ldrb r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r2]
	b _08098CEE
	.align 2, 0
_08098CE0: .4byte gNonGameplayRam
_08098CE4:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x13
	bls _08098CBA
_08098CEE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start SpecialCutsceneProcessOam
SpecialCutsceneProcessOam: @ 0x08098CF4
	push {r4, r5, r6, lr}
	ldr r0, _08098D44 @ =gNonGameplayRam
	ldr r1, _08098D48 @ =0x00000215
	adds r2, r0, r1
	movs r1, #0
	strb r1, [r2]
	movs r4, #0
	adds r5, r0, #0
	adds r6, r2, #0
_08098D06:
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r2, r0, #2
	adds r0, r2, r5
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08098D34
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r1, r2, r1
	subs r3, #0x10
	adds r0, r5, r3
	adds r0, r2, r0
	ldr r1, [r1]
	bl _call_via_r1
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_08098D34:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x13
	bls _08098D06
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098D44: .4byte gNonGameplayRam
_08098D48: .4byte 0x00000215

	thumb_func_start SpecialCutsceneDrawAllOam
SpecialCutsceneDrawAllOam: @ 0x08098D4C
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, _08098D94 @ =gNonGameplayRam
	movs r0, #0x87
	lsls r0, r0, #2
	adds r6, r5, r0
_08098D58:
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r1, r0, #2
	adds r0, r1, r5
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08098D74
	adds r0, r1, r6
	bl SpecialCutsceneDrawOam
_08098D74:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x13
	bls _08098D58
	bl ResetFreeOam
	ldr r0, _08098D98 @ =gNextOamSlot
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08098D9C @ =0x03001238
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098D94: .4byte gNonGameplayRam
_08098D98: .4byte gNextOamSlot
_08098D9C: .4byte 0x03001238

	thumb_func_start SpecialCutsceneDrawOam
SpecialCutsceneDrawOam: @ 0x08098DA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	ldr r3, _08098E9C @ =gNextOamSlot
	ldrb r0, [r3]
	lsls r0, r0, #3
	ldr r2, _08098EA0 @ =gOamData
	adds r0, r0, r2
	mov ip, r0
	mov r0, sb
	ldrb r5, [r0, #0x11]
	lsls r1, r5, #3
	ldr r0, [r0, #0x1c]
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	mov r1, sb
	ldrb r1, [r1, #0x12]
	cmp r0, r1
	bne _08098DDA
	adds r0, r5, #1
	movs r1, #0
	mov r2, sb
	strb r0, [r2, #0x11]
	strb r1, [r2, #0x12]
	adds r4, #8
_08098DDA:
	ldrb r1, [r4, #4]
	cmp r1, #0
	bne _08098DEA
	mov r3, sb
	ldrb r0, [r3, #0x11]
	lsls r0, r0, #3
	subs r4, r4, r0
	strb r1, [r3, #0x11]
_08098DEA:
	ldr r4, [r4]
	mov sl, r4
	ldrh r4, [r4]
	str r4, [sp, #0x20]
	movs r5, #2
	add sl, r5
	mov r0, sb
	ldrb r1, [r0, #0x18]
	lsls r0, r1, #0x1d
	lsrs r0, r0, #0x1e
	cmp r0, #0
	beq _08098E04
	b _08098F78
_08098E04:
	movs r1, #0
	str r1, [sp, #0x1c]
	cmp r1, r4
	blt _08098E10
	bl _0809975A
_08098E10:
	ldr r2, _08098EA4 @ =0x000001FF
	adds r7, r2, #0
	movs r3, #3
	mov r8, r3
_08098E18:
	mov r4, sl
	ldrh r6, [r4]
	movs r5, #2
	add sl, r5
	mov r0, sl
	ldrh r5, [r0]
	movs r1, #2
	add sl, r1
	mov r2, ip
	strh r6, [r2]
	add ip, r1
	mov r3, ip
	strh r5, [r3]
	add ip, r1
	mov r4, sl
	ldrh r0, [r4]
	mov r1, ip
	strh r0, [r1]
	movs r2, #2
	add sl, r2
	add ip, r2
	ldr r3, _08098E9C @ =gNextOamSlot
	ldrb r0, [r3]
	ldr r4, [sp, #0x1c]
	adds r3, r0, r4
	mov r1, sb
	ldrb r0, [r1, #0x18]
	lsls r0, r0, #0x19
	lsrs r1, r0, #0x1f
	cmp r1, #1
	bne _08098EAC
	lsls r4, r3, #3
	ldr r3, _08098EA0 @ =gOamData
	adds r2, r4, r3
	ldrb r3, [r2, #3]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x1f
	eors r0, r1
	lsls r0, r0, #4
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, #3]
	lsrs r1, r1, #6
	ldrb r0, [r2, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, _08098EA8 @ =0x0863A184
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #3
	adds r0, r5, r0
	mov r2, sb
	ldrh r1, [r2, #0xc]
	subs r0, r1, r0
	ands r0, r7
	str r0, [sp]
	ldrh r0, [r2, #0xe]
	adds r6, r6, r0
	movs r0, #0xff
	ands r6, r0
	str r6, [sp, #4]
	b _08098EC2
	.align 2, 0
_08098E9C: .4byte gNextOamSlot
_08098EA0: .4byte gOamData
_08098EA4: .4byte 0x000001FF
_08098EA8: .4byte 0x0863A184
_08098EAC:
	mov r4, sb
	ldrh r0, [r4, #0xe]
	adds r6, r6, r0
	movs r0, #0xff
	ands r6, r0
	str r6, [sp, #4]
	ldrh r0, [r4, #0xc]
	adds r5, r5, r0
	ands r5, r7
	str r5, [sp]
	lsls r4, r3, #3
_08098EC2:
	ldr r5, _08098F68 @ =gOamData
	adds r3, r4, r5
	mov r0, sp
	ldrb r0, [r0, #4]
	strb r0, [r3]
	ldr r1, [sp]
	ands r1, r7
	str r1, [sp]
	ldrh r1, [r3, #2]
	ldr r0, _08098F6C @ =0xFFFFFE00
	ands r0, r1
	ldr r2, [sp]
	orrs r0, r2
	strh r0, [r3, #2]
	mov r4, sb
	ldrb r0, [r4, #0x1a]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	mov r5, r8
	ands r0, r5
	lsls r0, r0, #2
	ldrb r2, [r3, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #5]
	lsrs r2, r1, #4
	ldrb r0, [r4, #0x1a]
	lsrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #4
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r3, #5]
	ldrh r2, [r3, #4]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	ldr r0, [r4, #0x18]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x16
	adds r1, r1, r0
	ldr r4, _08098F70 @ =0x000003FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _08098F74 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	mov r5, sb
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1e
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #2
	ldrb r2, [r3, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #1]
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	lsls r0, r0, #4
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #1]
	movs r3, #2
	add ip, r3
	ldr r4, [sp, #0x1c]
	adds r4, #1
	str r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	cmp r4, r5
	bge _08098F64
	b _08098E18
_08098F64:
	b _0809975A
	.align 2, 0
_08098F68: .4byte gOamData
_08098F6C: .4byte 0xFFFFFE00
_08098F70: .4byte 0x000003FF
_08098F74: .4byte 0xFFFFFC00
_08098F78:
	cmp r0, #1
	beq _08098F7E
	b _08099400
_08098F7E:
	mov r2, sb
	ldrh r0, [r2, #0xc]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldrh r0, [r2, #0xe]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r0, r1, #0x19
	cmp r0, #0
	blt _08098FA0
	ldrh r3, [r2, #6]
	str r3, [sp, #0x14]
	b _08098FAC
_08098FA0:
	mov r4, sb
	ldrh r0, [r4, #6]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
_08098FAC:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _08098FBA
	mov r5, sb
	ldrh r5, [r5, #6]
	str r5, [sp, #0x18]
	b _08098FC6
_08098FBA:
	mov r1, sb
	ldrh r0, [r1, #6]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
_08098FC6:
	movs r2, #0
	str r2, [sp, #0x28]
	movs r3, #0
	str r3, [sp, #0x1c]
	ldr r4, [sp, #0x14]
	lsls r4, r4, #0x10
	str r4, [sp, #0x34]
	ldr r5, [sp, #0x20]
	cmp r3, r5
	blt _08098FDC
	b _0809925C
_08098FDC:
	mov r0, sl
	ldrh r6, [r0]
	movs r1, #2
	add sl, r1
	mov r2, sl
	ldrh r5, [r2]
	add sl, r1
	mov r3, ip
	strh r6, [r3]
	add ip, r1
	mov r4, ip
	strh r5, [r4]
	add ip, r1
	mov r1, sl
	ldrh r0, [r1]
	mov r2, ip
	strh r0, [r2]
	movs r3, #2
	add sl, r3
	add ip, r3
	ldr r4, _08099098 @ =gNextOamSlot
	ldrb r0, [r4]
	ldr r1, [sp, #0x1c]
	adds r3, r0, r1
	lsls r0, r3, #3
	ldr r2, _0809909C @ =gOamData
	adds r0, r0, r2
	mov r8, r0
	ldrb r7, [r0, #3]
	lsrs r1, r7, #6
	ldrb r0, [r0, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r4, _080990A0 @ =0x0863A184
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #2
	str r0, [sp, #8]
	ldr r0, _080990A4 @ =0x0863A190
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #2
	str r0, [sp, #0xc]
	ldr r1, [sp, #4]
	adds r6, r6, r1
	movs r0, #0xff
	ands r6, r0
	ldr r2, [sp]
	adds r4, r5, r2
	ldr r5, _080990A8 @ =0x000001FF
	adds r0, r5, #0
	ands r4, r0
	subs r1, r4, r2
	ldr r0, [sp, #8]
	adds r1, r0, r1
	ldr r5, [sp, #4]
	subs r2, r6, r5
	ldr r0, [sp, #0xc]
	adds r2, r0, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r5, [sp, #0x34]
	asrs r0, r5, #0x10
	muls r0, r1, r0
	asrs r0, r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r1, [sp, #0x18]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	muls r0, r2, r0
	asrs r0, r0, #8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r7, #0x1b
	cmp r0, #0
	bge _080990AC
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r7
	mov r5, r8
	strb r0, [r5, #3]
	movs r0, #1
	str r0, [sp, #0x28]
	movs r1, #1
	str r1, [sp, #0x24]
	b _080990B0
	.align 2, 0
_08099098: .4byte gNextOamSlot
_0809909C: .4byte gOamData
_080990A0: .4byte 0x0863A184
_080990A4: .4byte 0x0863A190
_080990A8: .4byte 0x000001FF
_080990AC:
	movs r5, #0
	str r5, [sp, #0x24]
_080990B0:
	lsls r0, r3, #3
	ldr r1, _080993E4 @ =gOamData
	adds r7, r0, r1
	ldrb r1, [r7, #3]
	lsls r0, r1, #0x1a
	cmp r0, #0
	bge _080990D0
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r7, #3]
	ldr r3, [sp, #0x18]
	lsls r0, r3, #0x10
	rsbs r0, r0, #0
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
_080990D0:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r4, [sp, #0x10]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r5, [sp]
	subs r4, r4, r5
	ldr r0, [sp, #8]
	mov r8, r0
	add r4, r8
	ldr r1, [sp, #4]
	subs r3, r6, r1
	ldr r6, [sp, #0xc]
	adds r3, r6, r3
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, sb
	ldrb r1, [r2, #0x15]
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r5, _080993E8 @ =0x080A4FA4
	adds r0, r0, r5
	movs r2, #0
	ldrsh r5, [r0, r2]
	adds r2, r4, #0
	muls r2, r5, r2
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r1, r1, #1
	ldr r0, _080993E8 @ =0x080A4FA4
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	adds r0, r3, #0
	muls r0, r1, r0
	subs r2, r2, r0
	lsls r2, r2, #8
	adds r0, r4, #0
	muls r0, r1, r0
	adds r1, r3, #0
	muls r1, r5, r1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r2, r2, #0x10
	mov r1, r8
	subs r2, r2, r1
	asrs r0, r0, #0x10
	subs r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r3, [sp, #4]
	adds r0, r6, r3
	subs r0, #0x40
	strb r0, [r7]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r4, [sp]
	adds r2, r2, r4
	subs r2, #0x40
	ldr r4, _080993EC @ =0x000001FF
	ands r2, r4
	ldrh r0, [r7, #2]
	ldr r1, _080993F0 @ =0xFFFFFE00
	adds r3, r1, #0
	ands r3, r0
	orrs r3, r2
	strh r3, [r7, #2]
	ldr r5, [sp, #0x24]
	cmp r5, #1
	bne _08099180
	lsls r0, r3, #0x17
	lsrs r0, r0, #0x17
	subs r0, #1
	ands r0, r4
	ands r3, r1
	orrs r3, r0
	strh r3, [r7, #2]
_08099180:
	ldrb r1, [r7, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r3, #1
	orrs r0, r3
	strb r0, [r7, #1]
	ldr r1, _080993F4 @ =0x03001238
	ldrb r0, [r1]
	ldr r2, [sp, #0x24]
	adds r0, r0, r2
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080991A6
	ldrb r0, [r7, #3]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r7, #3]
_080991A6:
	ldr r4, _080993F4 @ =0x03001238
	ldrb r0, [r4]
	ldr r5, [sp, #0x24]
	adds r0, r0, r5
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080991BE
	ldrb r0, [r7, #3]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r7, #3]
_080991BE:
	ldr r0, _080993F4 @ =0x03001238
	ldrb r1, [r0]
	ldr r2, [sp, #0x24]
	adds r1, r1, r2
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r2, [r7, #3]
	subs r0, #0x16
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, #3]
	mov r4, sb
	ldrb r0, [r4, #0x1a]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	movs r5, #3
	ands r0, r5
	lsls r0, r0, #2
	ldrb r2, [r7, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #5]
	lsrs r2, r1, #4
	ldrb r0, [r4, #0x1a]
	lsrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #4
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r7, #5]
	ldrh r2, [r7, #4]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	ldr r0, [r4, #0x18]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x16
	adds r1, r1, r0
	ldr r4, _080993F8 @ =0x000003FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _080993FC @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #4]
	mov r5, sb
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1e
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	ldrb r2, [r7, #1]
	subs r1, #0x10
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #1]
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	ands r0, r3
	lsls r0, r0, #4
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #1]
	movs r3, #2
	add ip, r3
	ldr r4, [sp, #0x1c]
	adds r4, #1
	str r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	cmp r4, r5
	bge _0809925C
	b _08098FDC
_0809925C:
	ldr r1, _080993F4 @ =0x03001238
	ldrb r0, [r1]
	lsls r0, r0, #0x1a
	lsrs r7, r0, #0x18
	mov r2, sb
	ldrb r0, [r2, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r3, _080993E8 @ =0x080A4FA4
	adds r0, r0, r3
	movs r5, #0
	ldrsh r4, [r0, r5]
	ldr r0, [sp, #0x34]
	asrs r0, r0, #0x10
	mov sl, r0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	ldr r1, _080993E4 @ =gOamData
	mov r8, r1
	lsls r1, r7, #3
	add r1, r8
	strh r0, [r1, #6]
	mov r2, sb
	ldrb r0, [r2, #0x15]
	lsls r0, r0, #1
	ldr r3, _080993E8 @ =0x080A4FA4
	adds r0, r0, r3
	movs r5, #0
	ldrsh r4, [r0, r5]
	mov r0, sl
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #1
	lsls r1, r1, #3
	add r1, r8
	strh r0, [r1, #6]
	mov r1, sb
	ldrb r0, [r1, #0x15]
	lsls r0, r0, #1
	ldr r2, _080993E8 @ =0x080A4FA4
	adds r0, r0, r2
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [sp, #0x18]
	lsls r0, r3, #0x10
	asrs r6, r0, #0x10
	adds r0, r6, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #2
	lsls r1, r1, #3
	add r1, r8
	strh r0, [r1, #6]
	mov r4, sb
	ldrb r0, [r4, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r5, _080993E8 @ =0x080A4FA4
	adds r0, r0, r5
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r6, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #3
	lsls r1, r1, #3
	add r1, r8
	strh r0, [r1, #6]
	ldr r2, _080993F4 @ =0x03001238
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, [sp, #0x28]
	cmp r3, #1
	beq _08099328
	b _0809975A
_08099328:
	ldrb r0, [r2]
	lsls r0, r0, #0x1a
	lsrs r7, r0, #0x18
	mov r4, sb
	ldrb r0, [r4, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r5, [r0, r1]
	mov r2, sl
	rsbs r4, r2, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl FixedMultiplication
	lsls r1, r7, #3
	add r1, r8
	strh r0, [r1, #6]
	mov r3, sb
	ldrb r0, [r3, #0x15]
	lsls r0, r0, #1
	ldr r5, _080993E8 @ =0x080A4FA4
	adds r0, r0, r5
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r0, r4, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl FixedMultiplication
	adds r1, r7, #1
	lsls r1, r1, #3
	add r1, r8
	strh r0, [r1, #6]
	mov r2, sb
	ldrb r0, [r2, #0x15]
	lsls r0, r0, #1
	ldr r3, _080993E8 @ =0x080A4FA4
	adds r0, r0, r3
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #2
	lsls r1, r1, #3
	add r1, r8
	strh r0, [r1, #6]
	mov r4, sb
	ldrb r0, [r4, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r5, _080993E8 @ =0x080A4FA4
	adds r0, r0, r5
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r6, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #3
	lsls r1, r1, #3
	add r1, r8
	strh r0, [r1, #6]
	ldr r2, _080993F4 @ =0x03001238
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0809975A
	.align 2, 0
_080993E4: .4byte gOamData
_080993E8: .4byte 0x080A4FA4
_080993EC: .4byte 0x000001FF
_080993F0: .4byte 0xFFFFFE00
_080993F4: .4byte 0x03001238
_080993F8: .4byte 0x000003FF
_080993FC: .4byte 0xFFFFFC00
_08099400:
	cmp r0, #3
	beq _08099406
	b _0809975A
_08099406:
	mov r3, sb
	ldrh r0, [r3, #0xc]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldrh r0, [r3, #0xe]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r0, r1, #0x19
	cmp r0, #0
	blt _08099428
	ldrh r4, [r3, #6]
	str r4, [sp, #0x14]
	b _08099434
_08099428:
	mov r5, sb
	ldrh r0, [r5, #6]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
_08099434:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _08099440
	mov r0, sb
	ldrh r0, [r0, #6]
	b _0809944A
_08099440:
	mov r1, sb
	ldrh r0, [r1, #6]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0809944A:
	str r0, [sp, #0x18]
	movs r2, #0
	str r2, [sp, #0x1c]
	ldr r3, [sp, #0x20]
	cmp r2, r3
	blt _08099458
	b _08099696
_08099458:
	mov r4, sl
	ldrh r6, [r4]
	movs r5, #2
	add sl, r5
	mov r0, sl
	ldrh r5, [r0]
	movs r1, #2
	add sl, r1
	mov r2, ip
	strh r6, [r2]
	add ip, r1
	mov r3, ip
	strh r5, [r3]
	add ip, r1
	mov r4, sl
	ldrh r0, [r4]
	mov r1, ip
	strh r0, [r1]
	movs r2, #2
	add sl, r2
	add ip, r2
	ldr r3, _0809977C @ =gNextOamSlot
	ldrb r0, [r3]
	ldr r4, [sp, #0x1c]
	adds r3, r0, r4
	lsls r0, r3, #3
	ldr r1, _08099780 @ =gOamData
	adds r7, r0, r1
	ldrb r2, [r7, #3]
	mov r8, r2
	mov r3, r8
	lsrs r1, r3, #6
	ldrb r0, [r7, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r4, _08099784 @ =0x0863A184
	adds r0, r1, r4
	ldrb r2, [r0]
	ldr r0, _08099788 @ =0x0863A190
	adds r1, r1, r0
	ldrb r3, [r1]
	ldr r1, [sp, #4]
	adds r6, r6, r1
	movs r0, #0xff
	ands r6, r0
	ldr r0, [sp]
	adds r4, r5, r0
	ldr r1, _0809978C @ =0x000001FF
	adds r0, r1, #0
	ands r4, r0
	ldr r5, [sp]
	subs r1, r4, r5
	lsls r2, r2, #2
	str r2, [sp, #0x2c]
	adds r1, r2, r1
	ldr r0, [sp, #4]
	subs r2, r6, r0
	lsls r3, r3, #2
	str r3, [sp, #0x30]
	adds r2, r3, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #0x14]
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	adds r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r5, [sp, #0x18]
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
	adds r0, r2, #0
	muls r0, r5, r0
	asrs r0, r0, #8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r1, r8
	lsls r0, r1, #0x1b
	cmp r0, #0
	bge _08099518
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r7, #3]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x14]
_08099518:
	ldrb r1, [r7, #3]
	lsls r0, r1, #0x1a
	cmp r0, #0
	bge _08099530
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r7, #3]
	rsbs r0, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
_08099530:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #0x10]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r5, [sp]
	subs r4, r4, r5
	ldr r0, [sp, #0x2c]
	adds r4, r0, r4
	ldr r1, [sp, #4]
	subs r3, r6, r1
	ldr r2, [sp, #0x30]
	adds r3, r2, r3
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r5, sb
	ldrb r1, [r5, #0x15]
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r2, _08099790 @ =0x080A4FA4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r5, [r0, r2]
	adds r2, r4, #0
	muls r2, r5, r2
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r1, r1, #1
	ldr r0, _08099790 @ =0x080A4FA4
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	adds r0, r3, #0
	muls r0, r1, r0
	subs r2, r2, r0
	lsls r2, r2, #8
	adds r0, r4, #0
	muls r0, r1, r0
	adds r1, r3, #0
	muls r1, r5, r1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r3, [sp, #0x2c]
	lsls r1, r3, #1
	asrs r2, r2, #0x10
	subs r2, r2, r1
	ldr r4, [sp, #0x30]
	lsls r1, r4, #1
	asrs r0, r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r5, [sp, #4]
	adds r0, r6, r5
	subs r0, #0x40
	strb r0, [r7]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r0, [sp]
	adds r2, r2, r0
	subs r2, #0x40
	ldr r0, _0809978C @ =0x000001FF
	ands r2, r0
	ldrh r1, [r7, #2]
	ldr r0, _08099794 @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r7, #2]
	ldrb r0, [r7, #1]
	movs r3, #3
	orrs r0, r3
	strb r0, [r7, #1]
	ldr r2, _08099798 @ =0x03001238
	ldrb r1, [r2]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080995EC
	ldrb r0, [r7, #3]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r7, #3]
_080995EC:
	ldr r4, _08099798 @ =0x03001238
	ldrb r1, [r4]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080995FE
	ldrb r0, [r7, #3]
	orrs r0, r2
	strb r0, [r7, #3]
_080995FE:
	ldr r5, _08099798 @ =0x03001238
	ldrb r0, [r5]
	movs r1, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r2, [r7, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7, #3]
	mov r1, sb
	ldrb r0, [r1, #0x1a]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	ands r0, r3
	lsls r0, r0, #2
	ldrb r2, [r7, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #5]
	lsrs r2, r1, #4
	mov r4, sb
	ldrb r0, [r4, #0x1a]
	lsrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #4
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r7, #5]
	ldrh r2, [r7, #4]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	ldr r0, [r4, #0x18]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x16
	adds r1, r1, r0
	ldr r5, _0809979C @ =0x000003FF
	adds r0, r5, #0
	ands r1, r0
	ldr r0, _080997A0 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #4]
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1e
	ands r0, r3
	lsls r0, r0, #2
	ldrb r2, [r7, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #1]
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1f
	lsls r0, r0, #4
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, #1]
	movs r3, #2
	add ip, r3
	ldr r4, [sp, #0x1c]
	adds r4, #1
	str r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	cmp r4, r5
	bge _08099696
	b _08099458
_08099696:
	ldr r1, _08099798 @ =0x03001238
	ldrb r0, [r1]
	lsls r0, r0, #0x1a
	lsrs r7, r0, #0x18
	mov r2, sb
	ldrb r0, [r2, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r3, _08099790 @ =0x080A4FA4
	adds r0, r0, r3
	movs r4, #0
	ldrsh r5, [r0, r4]
	ldr r0, [sp, #0x14]
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl FixedMultiplication
	ldr r6, _08099780 @ =gOamData
	lsls r1, r7, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	mov r1, sb
	ldrb r0, [r1, #0x15]
	lsls r0, r0, #1
	ldr r2, _08099790 @ =0x080A4FA4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	adds r0, r4, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl FixedMultiplication
	adds r1, r7, #1
	lsls r1, r1, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	mov r4, sb
	ldrb r0, [r4, #0x15]
	lsls r0, r0, #1
	ldr r5, _08099790 @ =0x080A4FA4
	adds r0, r0, r5
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r0, [sp, #0x18]
	lsls r5, r0, #0x10
	asrs r5, r5, #0x10
	adds r0, r5, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #2
	lsls r1, r1, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	mov r1, sb
	ldrb r0, [r1, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r2, _08099790 @ =0x080A4FA4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r4, [r0, r3]
	adds r0, r5, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #3
	lsls r1, r1, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	ldr r4, _08099798 @ =0x03001238
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0809975A:
	ldr r0, _0809977C @ =gNextOamSlot
	ldrb r1, [r0]
	ldr r5, [sp, #0x20]
	adds r1, r1, r5
	strb r1, [r0]
	mov r1, sb
	ldrb r0, [r1, #0x12]
	adds r0, #1
	strb r0, [r1, #0x12]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809977C: .4byte gNextOamSlot
_08099780: .4byte gOamData
_08099784: .4byte 0x0863A184
_08099788: .4byte 0x0863A190
_0809978C: .4byte 0x000001FF
_08099790: .4byte 0x080A4FA4
_08099794: .4byte 0xFFFFFE00
_08099798: .4byte 0x03001238
_0809979C: .4byte 0x000003FF
_080997A0: .4byte 0xFFFFFC00

	thumb_func_start NewFileIntroInit
NewFileIntroInit: @ 0x080997A4
	push {r4, lr}
	sub sp, #4
	ldr r3, _08099864 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _08099868 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _0809986C @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08099870 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08099874 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _08099878 @ =unk_99940
	bl CallbackSetVBlank
	ldr r1, _0809987C @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	ldr r0, _08099880 @ =gWrittenToBldy
	movs r1, #0x10
	strh r1, [r0]
	ldr r0, _08099884 @ =0x04000054
	strh r1, [r0]
	ldr r0, _08099888 @ =gNextOamSlot
	strb r4, [r0]
	bl ResetFreeOam
	movs r2, #0
	str r2, [sp]
	ldr r1, _0809988C @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08099890 @ =gNonGameplayRam
	str r0, [r1, #4]
	ldr r0, _08099894 @ =0x85000150
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08099898 @ =0x00007FFF
	str r0, [sp]
	mov r0, sp
	str r0, [r1]
	movs r3, #0xa0
	lsls r3, r3, #0x13
	str r3, [r1, #4]
	ldr r0, _0809989C @ =0x85000080
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	strh r2, [r3]
	str r2, [sp]
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080998A0 @ =0x85004000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080998A4 @ =0x0400000E
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	adds r0, #8
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	subs r0, #0x1e
	strh r2, [r0]
	ldr r0, _080998A8 @ =NewFileIntroVblank
	bl CallbackSetVBlank
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099864: .4byte 0x04000208
_08099868: .4byte 0x04000004
_0809986C: .4byte 0x0000FFEF
_08099870: .4byte 0x04000200
_08099874: .4byte 0x0000FFFD
_08099878: .4byte unk_99940
_0809987C: .4byte 0x04000050
_08099880: .4byte gWrittenToBldy
_08099884: .4byte 0x04000054
_08099888: .4byte gNextOamSlot
_0809988C: .4byte 0x040000D4
_08099890: .4byte gNonGameplayRam
_08099894: .4byte 0x85000150
_08099898: .4byte 0x00007FFF
_0809989C: .4byte 0x85000080
_080998A0: .4byte 0x85004000
_080998A4: .4byte 0x0400000E
_080998A8: .4byte NewFileIntroVblank

	thumb_func_start SpecialCutsceneGetRandomNumber
SpecialCutsceneGetRandomNumber: @ 0x080998AC
	push {r4, lr}
	ldr r3, _080998E0 @ =0x03005404
	ldrh r1, [r3]
	lsls r0, r1, #2
	adds r1, r1, r0
	ldr r2, _080998E4 @ =gFrameCounter8Bit
	ldr r4, _080998E8 @ =0x00003573
	adds r0, r4, #0
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r1, r0
	strh r1, [r3]
	ldr r2, _080998EC @ =sRandomNumberTable
	ldr r0, _080998F0 @ =gFrameCounter16Bit
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	ldrb r1, [r3, #1]
	adds r0, r0, r1
	strb r0, [r3, #1]
	ldrb r0, [r3, #1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080998E0: .4byte 0x03005404
_080998E4: .4byte gFrameCounter8Bit
_080998E8: .4byte 0x00003573
_080998EC: .4byte sRandomNumberTable
_080998F0: .4byte gFrameCounter16Bit

	thumb_func_start NewFileIntroVblank
NewFileIntroVblank: @ 0x080998F4
	ldr r1, _08099920 @ =0x040000D4
	ldr r0, _08099924 @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08099928 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r2, _0809992C @ =0x04000052
	ldr r0, _08099930 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _08099934 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08099938 @ =0x04000054
	ldr r0, _0809993C @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_08099920: .4byte 0x040000D4
_08099924: .4byte gOamData
_08099928: .4byte 0x84000100
_0809992C: .4byte 0x04000052
_08099930: .4byte gWrittenToBldalpha_Evb
_08099934: .4byte gWrittenToBldalpha_Eva
_08099938: .4byte 0x04000054
_0809993C: .4byte gWrittenToBldy

	thumb_func_start unk_99940
unk_99940: @ 0x08099940
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneHandler
CutsceneHandler: @ 0x0809994C
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08099964 @ =gSubGameMode1
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _0809997A
	cmp r0, #1
	bgt _08099968
	cmp r0, #0
	beq _08099972
	b _080999BA
	.align 2, 0
_08099964: .4byte gSubGameMode1
_08099968:
	cmp r0, #2
	beq _08099992
	cmp r0, #3
	beq _080999A0
	b _080999BA
_08099972:
	bl CutsceneInit
	movs r0, #2
	b _080999B8
_0809997A:
	ldr r1, _08099988 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809998C
	subs r0, #1
	strh r0, [r1]
	b _080999BA
	.align 2, 0
_08099988: .4byte gWrittenToBldy
_0809998C:
	ldrh r0, [r4]
	adds r0, #1
	b _080999B8
_08099992:
	bl CutsceneProcess
	cmp r0, #0
	beq _080999BA
	ldrh r0, [r4]
	adds r0, #1
	b _080999B8
_080999A0:
	ldr r1, _080999B0 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _080999B4
	adds r0, #1
	strh r0, [r1]
	b _080999BA
	.align 2, 0
_080999B0: .4byte gWrittenToBldy
_080999B4:
	movs r5, #1
	movs r0, #0
_080999B8:
	strh r0, [r4]
_080999BA:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneInit
CutsceneInit: @ 0x080999C4
	push {r4, r5, lr}
	sub sp, #4
	ldr r3, _08099A90 @ =0x04000208
	movs r5, #0
	strh r5, [r3]
	ldr r2, _08099A94 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _08099A98 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08099A9C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08099AA0 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _08099AA4 @ =unk_99af8
	bl CallbackSetVBlank
	ldr r1, _08099AA8 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	ldr r0, _08099AAC @ =gWrittenToBldy
	movs r1, #0x10
	strh r1, [r0]
	ldr r0, _08099AB0 @ =0x04000054
	strh r1, [r0]
	ldr r4, _08099AB4 @ =0x040000D4
	ldr r0, _08099AB8 @ =0x06010000
	str r0, [r4]
	ldr r0, _08099ABC @ =0x0201C000
	str r0, [r4, #4]
	ldr r0, _08099AC0 @ =0x84002000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08099AC4 @ =gNextOamSlot
	strb r5, [r0]
	bl ResetFreeOam
	movs r1, #0
	str r1, [sp]
	mov r0, sp
	str r0, [r4]
	ldr r0, _08099AC8 @ =gNonGameplayRam
	str r0, [r4, #4]
	ldr r0, _08099ACC @ =0x85000150
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08099AD0 @ =0x00007FFF
	str r0, [sp]
	mov r0, sp
	str r0, [r4]
	movs r2, #0xa0
	lsls r2, r2, #0x13
	str r2, [r4, #4]
	ldr r0, _08099AD4 @ =0x85000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	strh r1, [r2]
	str r1, [sp]
	mov r0, sp
	str r0, [r4]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08099AD8 @ =0x85004000
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08099ADC @ =0x0400000E
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r0, #8
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	subs r0, #0x1e
	strh r1, [r0]
	ldr r0, _08099AE0 @ =CutsceneVblank
	bl CallbackSetVBlank
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099A90: .4byte 0x04000208
_08099A94: .4byte 0x04000004
_08099A98: .4byte 0x0000FFEF
_08099A9C: .4byte 0x04000200
_08099AA0: .4byte 0x0000FFFD
_08099AA4: .4byte unk_99af8
_08099AA8: .4byte 0x04000050
_08099AAC: .4byte gWrittenToBldy
_08099AB0: .4byte 0x04000054
_08099AB4: .4byte 0x040000D4
_08099AB8: .4byte 0x06010000
_08099ABC: .4byte 0x0201C000
_08099AC0: .4byte 0x84002000
_08099AC4: .4byte gNextOamSlot
_08099AC8: .4byte gNonGameplayRam
_08099ACC: .4byte 0x85000150
_08099AD0: .4byte 0x00007FFF
_08099AD4: .4byte 0x85000080
_08099AD8: .4byte 0x85004000
_08099ADC: .4byte 0x0400000E
_08099AE0: .4byte CutsceneVblank

	thumb_func_start CutsceneVblank
CutsceneVblank: @ 0x08099AE4
	ldr r0, _08099AF0 @ =0x04000054
	ldr r1, _08099AF4 @ =gWrittenToBldy
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.align 2, 0
_08099AF0: .4byte 0x04000054
_08099AF4: .4byte gWrittenToBldy

	thumb_func_start unk_99af8
unk_99af8: @ 0x08099AF8
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneProcess
CutsceneProcess: @ 0x08099B04
	push {r4, lr}
	movs r4, #0
	ldr r0, _08099B1C @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0xb
	bhi _08099BA0
	lsls r0, r0, #2
	ldr r1, _08099B20 @ =_08099B24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08099B1C: .4byte gCurrentCutscene
_08099B20: .4byte _08099B24
_08099B24: @ jump table
	.4byte _08099B54 @ case 0
	.4byte _08099B5C @ case 1
	.4byte _08099B64 @ case 2
	.4byte _08099B6C @ case 3
	.4byte _08099B74 @ case 4
	.4byte _08099B7C @ case 5
	.4byte _08099B84 @ case 6
	.4byte _08099B54 @ case 7
	.4byte _08099B8C @ case 8
	.4byte _08099B92 @ case 9
	.4byte _08099B92 @ case 10
	.4byte _08099B98 @ case 11
_08099B54:
	movs r0, #0
	bl CutsceneInternalMonologue
	b _08099B9C
_08099B5C:
	movs r0, #0
	bl CutsceneElevatorMonologue
	b _08099B9C
_08099B64:
	movs r0, #0
	bl CutsceneElevatorMonologue
	b _08099B9C
_08099B6C:
	movs r0, #0
	bl CutsceneElevatorMonologue
	b _08099B9C
_08099B74:
	movs r0, #1
	bl CutsceneElevatorMonologue
	b _08099B9C
_08099B7C:
	movs r0, #0
	bl CutsceneElevatorMonologue
	b _08099B9C
_08099B84:
	movs r0, #0
	bl CutsceneFederationMonologue
	b _08099B9C
_08099B8C:
	bl CutsceneSecretConversation
	b _08099B9C
_08099B92:
	bl CutsceneRestrictedLabDetaching
	b _08099B9C
_08099B98:
	bl CutsceneBslExploding
_08099B9C:
	cmp r0, #0
	beq _08099BA2
_08099BA0:
	movs r4, #1
_08099BA2:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneElevatorMonologue
CutsceneElevatorMonologue: @ 0x08099BAC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r5, #0
	ldr r4, _08099BC8 @ =gNonGameplayRam
	ldrh r0, [r4, #8]
	cmp r0, #1
	beq _08099BE2
	cmp r0, #1
	bgt _08099BCC
	cmp r0, #0
	beq _08099BD6
	b _08099C2A
	.align 2, 0
_08099BC8: .4byte gNonGameplayRam
_08099BCC:
	cmp r0, #2
	beq _08099BFC
	cmp r0, #3
	beq _08099C1C
	b _08099C2A
_08099BD6:
	movs r0, #1
	strh r0, [r4, #8]
	adds r0, r1, #0
	bl CutsceneElevatorMonologueInit
	b _08099C2A
_08099BE2:
	bl CutsceneMonologueFadeIn
	ldr r0, _08099BF8 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099C2A
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _08099C2A
	.align 2, 0
_08099BF8: .4byte gWrittenToBldy
_08099BFC:
	bl CutsceneElevatorMonologueProcess
	cmp r0, #0
	beq _08099C2A
	movs r0, #3
	strh r0, [r4, #8]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xa8
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x50
	movs r0, #0xff
	strh r0, [r1]
	b _08099C2A
_08099C1C:
	bl CutsceneMonologueFadeOut
	ldr r0, _08099C34 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _08099C2A
	movs r5, #1
_08099C2A:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08099C34: .4byte gWrittenToBldy

	thumb_func_start CutsceneElevatorMonologueInit
CutsceneElevatorMonologueInit: @ 0x08099C38
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	mov r8, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r3, _08099D84 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _08099D88 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _08099D8C @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _08099D90 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _08099D94 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _08099D98 @ =unk_9a31c
	bl CallbackSetVBlank
	movs r1, #0x80
	lsls r1, r1, #0x13
	mov sb, r1
	strh r4, [r1]
	ldr r1, _08099D9C @ =0x0879C514
	ldr r6, _08099DA0 @ =gCurrentCutscene
	ldrb r0, [r6]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08099DA4 @ =0x06012000
	bl LZ77UncompVram
	ldr r0, _08099DA8 @ =0x0865FB5C
	ldr r1, _08099DAC @ =0x06017C00
	bl LZ77UncompVram
	ldr r4, _08099DB0 @ =0x040000D4
	ldr r0, _08099DB4 @ =0x086638A0
	str r0, [r4]
	ldr r0, _08099DB8 @ =0x050003E0
	str r0, [r4, #4]
	ldr r0, _08099DBC @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08099DC0 @ =0x0879C4CC
	ldrb r0, [r6]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4]
	ldr r0, _08099DC4 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _08099DC8 @ =0x84000030
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08099DCC @ =0x0879C4F0
	ldrb r0, [r6]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldr r1, _08099DD0 @ =0x0879C538
	ldrb r0, [r6]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08099DD4 @ =0x0600D000
	bl LZ77UncompVram
	ldr r0, _08099DD8 @ =0x08662804
	movs r5, #0x80
	lsls r5, r5, #0x12
	adds r1, r5, #0
	bl LZ77UncompWram
	ldr r0, _08099DDC @ =0x08663598
	ldr r1, _08099DE0 @ =0x0600D800
	bl LZ77UncompVram
	str r5, [r4]
	ldr r0, _08099DE4 @ =0x0600C800
	str r0, [r4, #4]
	ldr r0, _08099DE8 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08099DEC @ =0x086636A0
	str r0, [r4]
	movs r2, #0xa0
	lsls r2, r2, #0x13
	str r2, [r4, #4]
	ldr r0, _08099DF0 @ =0x84000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08099DF4 @ =0x0879C4A8
	ldrb r0, [r6]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4]
	str r2, [r4, #4]
	ldr r0, _08099DF8 @ =0x84000058
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08099DFC @ =0x04000012
	movs r0, #4
	strh r0, [r1]
	subs r1, #0xa
	ldr r2, _08099E00 @ =0x00001908
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08099E04 @ =0x00001B01
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0xfe
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r1, _08099E08 @ =gWrittenToBldy
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x10
	bl CutsceneElevatorMonologueSetupOam
	movs r0, #2
	movs r1, #0x78
	movs r2, #0x78
	bl CutsceneElevatorMonologueSetupOam
	movs r0, #3
	movs r1, #0x78
	movs r2, #0x78
	bl CutsceneElevatorMonologueSetupOam
	mov r0, r8
	cmp r0, #0
	bne _08099E0C
	movs r0, #4
	movs r1, #0x78
	movs r2, #0x68
	bl CutsceneElevatorMonologueSetupOam
	b _08099E16
	.align 2, 0
_08099D84: .4byte 0x04000208
_08099D88: .4byte 0x04000004
_08099D8C: .4byte 0x0000FFEF
_08099D90: .4byte 0x04000200
_08099D94: .4byte 0x0000FFFD
_08099D98: .4byte unk_9a31c
_08099D9C: .4byte 0x0879C514
_08099DA0: .4byte gCurrentCutscene
_08099DA4: .4byte 0x06012000
_08099DA8: .4byte 0x0865FB5C
_08099DAC: .4byte 0x06017C00
_08099DB0: .4byte 0x040000D4
_08099DB4: .4byte 0x086638A0
_08099DB8: .4byte 0x050003E0
_08099DBC: .4byte 0x84000008
_08099DC0: .4byte 0x0879C4CC
_08099DC4: .4byte 0x05000200
_08099DC8: .4byte 0x84000030
_08099DCC: .4byte 0x0879C4F0
_08099DD0: .4byte 0x0879C538
_08099DD4: .4byte 0x0600D000
_08099DD8: .4byte 0x08662804
_08099DDC: .4byte 0x08663598
_08099DE0: .4byte 0x0600D800
_08099DE4: .4byte 0x0600C800
_08099DE8: .4byte 0x84000200
_08099DEC: .4byte 0x086636A0
_08099DF0: .4byte 0x84000080
_08099DF4: .4byte 0x0879C4A8
_08099DF8: .4byte 0x84000058
_08099DFC: .4byte 0x04000012
_08099E00: .4byte 0x00001908
_08099E04: .4byte 0x00001B01
_08099E08: .4byte gWrittenToBldy
_08099E0C:
	movs r0, #5
	movs r1, #0x78
	movs r2, #0x68
	bl CutsceneElevatorMonologueSetupOam
_08099E16:
	ldr r2, _08099E50 @ =gNonGameplayRam
	ldr r0, _08099E54 @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	strh r0, [r2, #0xa]
	ldr r1, _08099E58 @ =0x0879C5A4
	ldr r0, _08099E5C @ =0x03000011
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r1, [r2, #0xa]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2, #0xc]
	bl CutsceneMonologueDrawAllOam
	ldr r0, _08099E60 @ =CutsceneElevatorMonologueVblank
	bl CallbackSetVBlank
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08099E50: .4byte gNonGameplayRam
_08099E54: .4byte gCurrentCutscene
_08099E58: .4byte 0x0879C5A4
_08099E5C: .4byte 0x03000011
_08099E60: .4byte CutsceneElevatorMonologueVblank

	thumb_func_start CutsceneElevatorMonologueProcess
CutsceneElevatorMonologueProcess: @ 0x08099E64
	push {r4, lr}
	bl CutsceneMonologueProcessSpecialTextCharacters
	adds r4, r0, #0
	ldr r1, _08099E7C @ =gNonGameplayRam
	ldrb r0, [r1, #0x17]
	cmp r0, #0
	beq _08099E80
	cmp r0, #1
	beq _08099E86
	b _08099E8E
	.align 2, 0
_08099E7C: .4byte gNonGameplayRam
_08099E80:
	movs r0, #0x64
	strb r0, [r1, #0x17]
	b _08099E8E
_08099E86:
	movs r0, #0x64
	strb r0, [r1, #0x17]
	bl CutsceneMonologueProcessText
_08099E8E:
	bl CutsceneMonologueProcessOam
	bl CutsceneMonologueDrawAllOam
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneElevatorMonologueSetupOam
CutsceneElevatorMonologueSetupOam: @ 0x08099EA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r6, #0
	ldr r1, _08099EEC @ =gNonGameplayRam
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08099EE2
	adds r3, r1, #0
	adds r1, r2, #0
_08099EC8:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #4
	bhi _08099EE6
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08099EC8
_08099EE2:
	cmp r6, #4
	bls _08099EF0
_08099EE6:
	movs r0, #5
	b _0809A06C
	.align 2, 0
_08099EEC: .4byte gNonGameplayRam
_08099EF0:
	adds r0, r6, #0
	bl CutsceneMonologueResetOam
	ldr r3, _08099F50 @ =gNonGameplayRam
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r5, r0, #3
	adds r2, r5, r3
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r7, [r0]
	adds r1, #2
	adds r0, r2, r1
	mov r1, r8
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r4, [r0]
	ldr r0, _08099F54 @ =0x00000219
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	cmp r4, #1
	bne _08099F68
	ldr r0, _08099F58 @ =0x00000221
	adds r1, r2, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r0, _08099F5C @ =0x00000222
	adds r1, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r5, r0
	ldr r1, _08099F60 @ =0x08663E5C
	str r1, [r0]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r5, r0
	ldr r1, _08099F64 @ =CutsceneMonologueProcessCursor
	b _0809A068
	.align 2, 0
_08099F50: .4byte gNonGameplayRam
_08099F54: .4byte 0x00000219
_08099F58: .4byte 0x00000221
_08099F5C: .4byte 0x00000222
_08099F60: .4byte 0x08663E5C
_08099F64: .4byte CutsceneMonologueProcessCursor
_08099F68:
	cmp r4, #2
	bne _08099FA8
	ldr r0, _08099F98 @ =0x0000021F
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r3, r0
	adds r1, r5, r1
	ldr r2, _08099F9C @ =0x0879C55C
	ldr r0, _08099FA0 @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r5, r0
	ldr r1, _08099FA4 @ =unk_9d09c
	b _0809A068
	.align 2, 0
_08099F98: .4byte 0x0000021F
_08099F9C: .4byte 0x0879C55C
_08099FA0: .4byte gCurrentCutscene
_08099FA4: .4byte unk_9d09c
_08099FA8:
	cmp r4, #3
	bne _08099FF4
	ldr r0, _08099FE0 @ =0x0000021E
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _08099FE4 @ =0x0000021F
	adds r0, r2, r1
	strb r4, [r0]
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r3, r0
	adds r1, r5, r1
	ldr r2, _08099FE8 @ =0x0879C55C
	ldr r0, _08099FEC @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r5, r0
	ldr r1, _08099FF0 @ =unk_9d09c
	b _0809A068
	.align 2, 0
_08099FE0: .4byte 0x0000021E
_08099FE4: .4byte 0x0000021F
_08099FE8: .4byte 0x0879C55C
_08099FEC: .4byte gCurrentCutscene
_08099FF0: .4byte unk_9d09c
_08099FF4:
	cmp r4, #4
	bne _0809A038
	ldr r0, _0809A028 @ =0x0000021F
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r2, r3, r1
	adds r2, r5, r2
	ldr r1, _0809A02C @ =0x0879C55C
	ldr r0, _0809A030 @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r5, r0
	ldr r1, _0809A034 @ =CutsceneProcessElevatorScrolling
	b _0809A068
	.align 2, 0
_0809A028: .4byte 0x0000021F
_0809A02C: .4byte 0x0879C55C
_0809A030: .4byte gCurrentCutscene
_0809A034: .4byte CutsceneProcessElevatorScrolling
_0809A038:
	cmp r4, #5
	bne _0809A06A
	ldr r0, _0809A078 @ =0x0000021F
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r2, r3, r1
	adds r2, r5, r2
	ldr r1, _0809A07C @ =0x0879C55C
	ldr r0, _0809A080 @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #3
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r5, r0
	ldr r1, _0809A084 @ =unk_9a1a8
_0809A068:
	str r1, [r0]
_0809A06A:
	adds r0, r6, #0
_0809A06C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809A078: .4byte 0x0000021F
_0809A07C: .4byte 0x0879C55C
_0809A080: .4byte gCurrentCutscene
_0809A084: .4byte unk_9a1a8

	thumb_func_start CutsceneProcessElevatorScrolling
CutsceneProcessElevatorScrolling: @ 0x0809A088
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #2]
	adds r0, #2
	movs r5, #0
	strh r0, [r4, #2]
	ldr r3, _0809A0F8 @ =0x0400001A
	ldr r2, _0809A0FC @ =gNonGameplayRam
	ldrh r0, [r2, #0x12]
	subs r0, #1
	strh r0, [r2, #0x12]
	ldr r6, _0809A100 @ =0x0000FFFF
	adds r1, r6, #0
	ands r0, r1
	strh r0, [r3]
	ldrb r3, [r4, #9]
	adds r6, r2, #0
	cmp r3, #0
	bne _0809A124
	ldr r0, _0809A104 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809A19A
	ldr r0, _0809A108 @ =gWrittenToBldalpha_Eva
	strh r3, [r0]
	ldr r0, _0809A10C @ =gWrittenToBldalpha_Evb
	movs r2, #0x10
	strh r2, [r0]
	ldr r0, _0809A110 @ =0x04000048
	strh r3, [r0]
	ldr r1, _0809A114 @ =0x0400004A
	ldr r5, _0809A118 @ =0x0000331D
	adds r0, r5, #0
	strh r0, [r1]
	ldr r0, _0809A11C @ =0x04000016
	strh r3, [r6, #0x14]
	strh r3, [r0]
	adds r0, #0x3c
	lsls r2, r2, #8
	strh r2, [r0]
	adds r1, #6
	ldr r6, _0809A120 @ =0x00001042
	adds r0, r6, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x82
	lsls r3, r3, #8
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strb r0, [r4, #9]
	b _0809A19A
	.align 2, 0
_0809A0F8: .4byte 0x0400001A
_0809A0FC: .4byte gNonGameplayRam
_0809A100: .4byte 0x0000FFFF
_0809A104: .4byte gWrittenToBldy
_0809A108: .4byte gWrittenToBldalpha_Eva
_0809A10C: .4byte gWrittenToBldalpha_Evb
_0809A110: .4byte 0x04000048
_0809A114: .4byte 0x0400004A
_0809A118: .4byte 0x0000331D
_0809A11C: .4byte 0x04000016
_0809A120: .4byte 0x00001042
_0809A124:
	cmp r3, #1
	bne _0809A164
	ldr r2, _0809A138 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	cmp r1, #0xa
	bne _0809A13C
	movs r0, #2
	strb r0, [r4, #9]
	strb r5, [r4, #8]
	b _0809A14E
	.align 2, 0
_0809A138: .4byte gWrittenToBldalpha_Eva
_0809A13C:
	ldrb r0, [r4, #8]
	cmp r0, #3
	bls _0809A14A
	strb r5, [r4, #8]
	adds r0, r1, #1
	strh r0, [r2]
	b _0809A14E
_0809A14A:
	adds r0, #1
	strb r0, [r4, #8]
_0809A14E:
	ldr r0, _0809A15C @ =0x04000016
	ldrh r1, [r6, #0x14]
	subs r1, #3
	strh r1, [r6, #0x14]
	ldr r5, _0809A160 @ =0x0000FFFF
	adds r2, r5, #0
	b _0809A196
	.align 2, 0
_0809A15C: .4byte 0x04000016
_0809A160: .4byte 0x0000FFFF
_0809A164:
	ldr r2, _0809A174 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	cmp r1, #4
	bne _0809A178
	movs r0, #1
	strb r0, [r4, #9]
	strb r5, [r4, #8]
	b _0809A18A
	.align 2, 0
_0809A174: .4byte gWrittenToBldalpha_Eva
_0809A178:
	ldrb r0, [r4, #8]
	cmp r0, #3
	bls _0809A186
	strb r5, [r4, #8]
	subs r0, r1, #1
	strh r0, [r2]
	b _0809A18A
_0809A186:
	adds r0, #1
	strb r0, [r4, #8]
_0809A18A:
	ldr r0, _0809A1A0 @ =0x04000016
	ldrh r1, [r6, #0x14]
	subs r1, #3
	strh r1, [r6, #0x14]
	ldr r6, _0809A1A4 @ =0x0000FFFF
	adds r2, r6, #0
_0809A196:
	ands r1, r2
	strh r1, [r0]
_0809A19A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A1A0: .4byte 0x04000016
_0809A1A4: .4byte 0x0000FFFF

	thumb_func_start unk_9a1a8
unk_9a1a8: @ 0x0809A1A8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #2]
	subs r0, #2
	movs r5, #0
	strh r0, [r4, #2]
	ldr r3, _0809A218 @ =0x0400001A
	ldr r2, _0809A21C @ =gNonGameplayRam
	ldrh r0, [r2, #0x12]
	adds r0, #1
	strh r0, [r2, #0x12]
	ldr r6, _0809A220 @ =0x0000FFFF
	adds r1, r6, #0
	ands r0, r1
	strh r0, [r3]
	ldrb r3, [r4, #9]
	adds r6, r2, #0
	cmp r3, #0
	bne _0809A244
	ldr r0, _0809A224 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809A2BA
	ldr r0, _0809A228 @ =gWrittenToBldalpha_Eva
	strh r3, [r0]
	ldr r0, _0809A22C @ =gWrittenToBldalpha_Evb
	movs r2, #0x10
	strh r2, [r0]
	ldr r0, _0809A230 @ =0x04000048
	strh r3, [r0]
	ldr r1, _0809A234 @ =0x0400004A
	ldr r5, _0809A238 @ =0x0000331D
	adds r0, r5, #0
	strh r0, [r1]
	ldr r0, _0809A23C @ =0x04000016
	strh r3, [r6, #0x14]
	strh r3, [r0]
	adds r0, #0x3c
	lsls r2, r2, #8
	strh r2, [r0]
	adds r1, #6
	ldr r6, _0809A240 @ =0x00001042
	adds r0, r6, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x82
	lsls r3, r3, #8
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strb r0, [r4, #9]
	b _0809A2BA
	.align 2, 0
_0809A218: .4byte 0x0400001A
_0809A21C: .4byte gNonGameplayRam
_0809A220: .4byte 0x0000FFFF
_0809A224: .4byte gWrittenToBldy
_0809A228: .4byte gWrittenToBldalpha_Eva
_0809A22C: .4byte gWrittenToBldalpha_Evb
_0809A230: .4byte 0x04000048
_0809A234: .4byte 0x0400004A
_0809A238: .4byte 0x0000331D
_0809A23C: .4byte 0x04000016
_0809A240: .4byte 0x00001042
_0809A244:
	cmp r3, #1
	bne _0809A284
	ldr r2, _0809A258 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	cmp r1, #0xa
	bne _0809A25C
	movs r0, #2
	strb r0, [r4, #9]
	strb r5, [r4, #8]
	b _0809A26E
	.align 2, 0
_0809A258: .4byte gWrittenToBldalpha_Eva
_0809A25C:
	ldrb r0, [r4, #8]
	cmp r0, #3
	bls _0809A26A
	strb r5, [r4, #8]
	adds r0, r1, #1
	strh r0, [r2]
	b _0809A26E
_0809A26A:
	adds r0, #1
	strb r0, [r4, #8]
_0809A26E:
	ldr r0, _0809A27C @ =0x04000016
	ldrh r1, [r6, #0x14]
	adds r1, #3
	strh r1, [r6, #0x14]
	ldr r5, _0809A280 @ =0x0000FFFF
	adds r2, r5, #0
	b _0809A2B6
	.align 2, 0
_0809A27C: .4byte 0x04000016
_0809A280: .4byte 0x0000FFFF
_0809A284:
	ldr r2, _0809A294 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	cmp r1, #4
	bne _0809A298
	movs r0, #1
	strb r0, [r4, #9]
	strb r5, [r4, #8]
	b _0809A2AA
	.align 2, 0
_0809A294: .4byte gWrittenToBldalpha_Eva
_0809A298:
	ldrb r0, [r4, #8]
	cmp r0, #3
	bls _0809A2A6
	strb r5, [r4, #8]
	subs r0, r1, #1
	strh r0, [r2]
	b _0809A2AA
_0809A2A6:
	adds r0, #1
	strb r0, [r4, #8]
_0809A2AA:
	ldr r0, _0809A2C0 @ =0x04000016
	ldrh r1, [r6, #0x14]
	adds r1, #3
	strh r1, [r6, #0x14]
	ldr r6, _0809A2C4 @ =0x0000FFFF
	adds r2, r6, #0
_0809A2B6:
	ands r1, r2
	strh r1, [r0]
_0809A2BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A2C0: .4byte 0x04000016
_0809A2C4: .4byte 0x0000FFFF

	thumb_func_start CutsceneElevatorMonologueVblank
CutsceneElevatorMonologueVblank: @ 0x0809A2C8
	push {lr}
	ldr r1, _0809A2FC @ =0x040000D4
	ldr r0, _0809A300 @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0809A304 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl unk_9cc4c
	ldr r2, _0809A308 @ =0x04000052
	ldr r0, _0809A30C @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _0809A310 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0809A314 @ =0x04000054
	ldr r0, _0809A318 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809A2FC: .4byte 0x040000D4
_0809A300: .4byte gOamData
_0809A304: .4byte 0x84000100
_0809A308: .4byte 0x04000052
_0809A30C: .4byte gWrittenToBldalpha_Evb
_0809A310: .4byte gWrittenToBldalpha_Eva
_0809A314: .4byte 0x04000054
_0809A318: .4byte gWrittenToBldy

	thumb_func_start unk_9a31c
unk_9a31c: @ 0x0809A31C
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneInternalMonologue
CutsceneInternalMonologue: @ 0x0809A328
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r5, #0
	ldr r4, _0809A344 @ =gNonGameplayRam
	ldrh r0, [r4, #8]
	cmp r0, #1
	beq _0809A35E
	cmp r0, #1
	bgt _0809A348
	cmp r0, #0
	beq _0809A352
	b _0809A39E
	.align 2, 0
_0809A344: .4byte gNonGameplayRam
_0809A348:
	cmp r0, #2
	beq _0809A378
	cmp r0, #3
	beq _0809A390
	b _0809A39E
_0809A352:
	movs r0, #1
	strh r0, [r4, #8]
	adds r0, r1, #0
	bl CutsceneInternalMonologueInit
	b _0809A39E
_0809A35E:
	bl CutsceneMonologueFadeIn
	ldr r0, _0809A374 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809A39E
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0809A39E
	.align 2, 0
_0809A374: .4byte gWrittenToBldy
_0809A378:
	bl CutsceneInternalMonologueProcess
	cmp r0, #0
	beq _0809A39E
	movs r0, #3
	strh r0, [r4, #8]
	ldr r1, _0809A38C @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	b _0809A39E
	.align 2, 0
_0809A38C: .4byte 0x04000050
_0809A390:
	bl CutsceneMonologueFadeOut
	ldr r0, _0809A3A8 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _0809A39E
	movs r5, #1
_0809A39E:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809A3A8: .4byte gWrittenToBldy

	thumb_func_start CutsceneInternalMonologueInit
CutsceneInternalMonologueInit: @ 0x0809A3AC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r3, _0809A484 @ =0x04000208
	movs r6, #0
	strh r6, [r3]
	ldr r2, _0809A488 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _0809A48C @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0809A490 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0809A494 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0809A498 @ =unk_9a63c
	bl CallbackSetVBlank
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	strh r6, [r0]
	ldr r0, _0809A49C @ =0x0865FB5C
	ldr r1, _0809A4A0 @ =0x06017C00
	bl LZ77UncompVram
	ldr r4, _0809A4A4 @ =0x040000D4
	ldr r0, _0809A4A8 @ =0x086638A0
	str r0, [r4]
	ldr r0, _0809A4AC @ =0x050003E0
	str r0, [r4, #4]
	ldr r0, _0809A4B0 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809A4B4 @ =0x08662804
	movs r5, #0x80
	lsls r5, r5, #0x12
	adds r1, r5, #0
	bl LZ77UncompWram
	str r5, [r4]
	ldr r0, _0809A4B8 @ =0x0600C800
	str r0, [r4, #4]
	ldr r0, _0809A4BC @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809A4C0 @ =0x086636A0
	str r0, [r4]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r4, #4]
	ldr r0, _0809A4C4 @ =0x84000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	strh r6, [r1]
	ldr r1, _0809A4C8 @ =0x04000012
	movs r0, #4
	strh r0, [r1]
	subs r1, #0xa
	ldr r2, _0809A4CC @ =0x00001908
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0x88
	lsls r1, r1, #5
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r1, _0809A4D0 @ =gWrittenToBldy
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x10
	bl CutsceneInternalMonologueSetupOam
	ldr r2, _0809A4D4 @ =gNonGameplayRam
	ldr r0, _0809A4D8 @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	strh r0, [r2, #0xa]
	ldr r1, _0809A4DC @ =0x0879C5A4
	ldr r0, _0809A4E0 @ =0x03000011
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r1, [r2, #0xa]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2, #0xc]
	bl CutsceneMonologueDrawAllOam
	ldr r0, _0809A4E4 @ =CutsceneInternalMonologueVblank
	bl CallbackSetVBlank
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A484: .4byte 0x04000208
_0809A488: .4byte 0x04000004
_0809A48C: .4byte 0x0000FFEF
_0809A490: .4byte 0x04000200
_0809A494: .4byte 0x0000FFFD
_0809A498: .4byte unk_9a63c
_0809A49C: .4byte 0x0865FB5C
_0809A4A0: .4byte 0x06017C00
_0809A4A4: .4byte 0x040000D4
_0809A4A8: .4byte 0x086638A0
_0809A4AC: .4byte 0x050003E0
_0809A4B0: .4byte 0x84000008
_0809A4B4: .4byte 0x08662804
_0809A4B8: .4byte 0x0600C800
_0809A4BC: .4byte 0x84000200
_0809A4C0: .4byte 0x086636A0
_0809A4C4: .4byte 0x84000080
_0809A4C8: .4byte 0x04000012
_0809A4CC: .4byte 0x00001908
_0809A4D0: .4byte gWrittenToBldy
_0809A4D4: .4byte gNonGameplayRam
_0809A4D8: .4byte gCurrentCutscene
_0809A4DC: .4byte 0x0879C5A4
_0809A4E0: .4byte 0x03000011
_0809A4E4: .4byte CutsceneInternalMonologueVblank

	thumb_func_start CutsceneInternalMonologueProcess
CutsceneInternalMonologueProcess: @ 0x0809A4E8
	push {r4, lr}
	bl CutsceneMonologueProcessSpecialTextCharacters
	adds r4, r0, #0
	ldr r1, _0809A500 @ =gNonGameplayRam
	ldrb r0, [r1, #0x17]
	cmp r0, #0
	beq _0809A504
	cmp r0, #1
	beq _0809A50A
	b _0809A512
	.align 2, 0
_0809A500: .4byte gNonGameplayRam
_0809A504:
	movs r0, #0x64
	strb r0, [r1, #0x17]
	b _0809A512
_0809A50A:
	movs r0, #0x64
	strb r0, [r1, #0x17]
	bl CutsceneMonologueProcessText
_0809A512:
	bl CutsceneMonologueProcessOam
	bl CutsceneMonologueDrawAllOam
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneInternalMonologueSetupOam
CutsceneInternalMonologueSetupOam: @ 0x0809A524
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r4, #0
	ldr r1, _0809A570 @ =gNonGameplayRam
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A566
	adds r3, r1, #0
	adds r1, r2, #0
_0809A54C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bhi _0809A56A
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809A54C
_0809A566:
	cmp r4, #4
	bls _0809A574
_0809A56A:
	movs r0, #5
	b _0809A5DC
	.align 2, 0
_0809A570: .4byte gNonGameplayRam
_0809A574:
	adds r0, r4, #0
	bl CutsceneMonologueResetOam
	ldr r5, _0809A5E8 @ =gNonGameplayRam
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r3, r0, #3
	adds r2, r3, r5
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r7, [r0]
	adds r1, #2
	adds r0, r2, r1
	mov r1, r8
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r6, [r0]
	ldr r0, _0809A5EC @ =0x00000219
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	cmp r6, #1
	bne _0809A5DA
	ldr r0, _0809A5F0 @ =0x0000021F
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0809A5F4 @ =0x00000221
	adds r1, r2, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r0, _0809A5F8 @ =0x00000222
	adds r1, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r3, r0
	ldr r1, _0809A5FC @ =0x08663E5C
	str r1, [r0]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r3, r0
	ldr r1, _0809A600 @ =CutsceneMonologueProcessCursor
	str r1, [r0]
_0809A5DA:
	adds r0, r4, #0
_0809A5DC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809A5E8: .4byte gNonGameplayRam
_0809A5EC: .4byte 0x00000219
_0809A5F0: .4byte 0x0000021F
_0809A5F4: .4byte 0x00000221
_0809A5F8: .4byte 0x00000222
_0809A5FC: .4byte 0x08663E5C
_0809A600: .4byte CutsceneMonologueProcessCursor

	thumb_func_start CutsceneInternalMonologueVblank
CutsceneInternalMonologueVblank: @ 0x0809A604
	push {lr}
	ldr r1, _0809A628 @ =0x040000D4
	ldr r0, _0809A62C @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0809A630 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl unk_9cc4c
	ldr r1, _0809A634 @ =0x04000054
	ldr r0, _0809A638 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809A628: .4byte 0x040000D4
_0809A62C: .4byte gOamData
_0809A630: .4byte 0x84000100
_0809A634: .4byte 0x04000054
_0809A638: .4byte gWrittenToBldy

	thumb_func_start unk_9a63c
unk_9a63c: @ 0x0809A63C
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneFederationMonologue
CutsceneFederationMonologue: @ 0x0809A648
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r5, #0
	ldr r4, _0809A664 @ =gNonGameplayRam
	ldrh r0, [r4, #8]
	cmp r0, #1
	beq _0809A67E
	cmp r0, #1
	bgt _0809A668
	cmp r0, #0
	beq _0809A672
	b _0809A6BE
	.align 2, 0
_0809A664: .4byte gNonGameplayRam
_0809A668:
	cmp r0, #2
	beq _0809A698
	cmp r0, #3
	beq _0809A6B0
	b _0809A6BE
_0809A672:
	movs r0, #1
	strh r0, [r4, #8]
	adds r0, r1, #0
	bl CutsceneFederationMonologueInit
	b _0809A6BE
_0809A67E:
	bl CutsceneMonologueFadeIn
	ldr r0, _0809A694 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809A6BE
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0809A6BE
	.align 2, 0
_0809A694: .4byte gWrittenToBldy
_0809A698:
	bl CutsceneFederationMonologueProcess
	cmp r0, #0
	beq _0809A6BE
	movs r0, #3
	strh r0, [r4, #8]
	ldr r1, _0809A6AC @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	b _0809A6BE
	.align 2, 0
_0809A6AC: .4byte 0x04000050
_0809A6B0:
	bl CutsceneMonologueFadeOut
	ldr r0, _0809A6C8 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _0809A6BE
	movs r5, #1
_0809A6BE:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809A6C8: .4byte gWrittenToBldy

	thumb_func_start CutsceneFederationMonologueInit
CutsceneFederationMonologueInit: @ 0x0809A6CC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r3, _0809A7CC @ =0x04000208
	movs r6, #0
	strh r6, [r3]
	ldr r2, _0809A7D0 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _0809A7D4 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0809A7D8 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0809A7DC @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0809A7E0 @ =unk_9a99c
	bl CallbackSetVBlank
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	strh r6, [r0]
	ldr r0, _0809A7E4 @ =0x0865FB5C
	ldr r1, _0809A7E8 @ =0x06017C00
	bl LZ77UncompVram
	ldr r4, _0809A7EC @ =0x040000D4
	ldr r0, _0809A7F0 @ =0x086638A0
	str r0, [r4]
	ldr r0, _0809A7F4 @ =0x050003E0
	str r0, [r4, #4]
	ldr r0, _0809A7F8 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809A7FC @ =0x086724C0
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldr r0, _0809A800 @ =0x08674AD8
	ldr r1, _0809A804 @ =0x0600D000
	bl LZ77UncompVram
	ldr r0, _0809A808 @ =0x08662804
	movs r5, #0x80
	lsls r5, r5, #0x12
	adds r1, r5, #0
	bl LZ77UncompWram
	str r5, [r4]
	ldr r0, _0809A80C @ =0x0600C800
	str r0, [r4, #4]
	ldr r0, _0809A810 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809A814 @ =0x08674958
	str r0, [r4]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r4, #4]
	ldr r0, _0809A818 @ =0x84000060
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809A81C @ =0x08663820
	str r0, [r4]
	ldr r0, _0809A820 @ =0x05000180
	str r0, [r4, #4]
	ldr r0, _0809A824 @ =0x84000020
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	strh r6, [r1]
	ldr r1, _0809A828 @ =0x04000012
	movs r0, #4
	strh r0, [r1]
	subs r1, #0xa
	ldr r2, _0809A82C @ =0x00001908
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	adds r2, #0xfb
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #5
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r1, _0809A830 @ =gWrittenToBldy
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x10
	bl CutsceneFederationMonologueSetupOam
	ldr r2, _0809A834 @ =gNonGameplayRam
	ldr r0, _0809A838 @ =gCurrentCutscene
	ldrb r0, [r0]
	subs r0, #1
	strh r0, [r2, #0xa]
	ldr r1, _0809A83C @ =0x0879C5A4
	ldr r0, _0809A840 @ =0x03000011
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r1, [r2, #0xa]
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2, #0xc]
	bl CutsceneMonologueDrawAllOam
	ldr r0, _0809A844 @ =CutsceneFederationMonologueVblank
	bl CallbackSetVBlank
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A7CC: .4byte 0x04000208
_0809A7D0: .4byte 0x04000004
_0809A7D4: .4byte 0x0000FFEF
_0809A7D8: .4byte 0x04000200
_0809A7DC: .4byte 0x0000FFFD
_0809A7E0: .4byte unk_9a99c
_0809A7E4: .4byte 0x0865FB5C
_0809A7E8: .4byte 0x06017C00
_0809A7EC: .4byte 0x040000D4
_0809A7F0: .4byte 0x086638A0
_0809A7F4: .4byte 0x050003E0
_0809A7F8: .4byte 0x84000008
_0809A7FC: .4byte 0x086724C0
_0809A800: .4byte 0x08674AD8
_0809A804: .4byte 0x0600D000
_0809A808: .4byte 0x08662804
_0809A80C: .4byte 0x0600C800
_0809A810: .4byte 0x84000200
_0809A814: .4byte 0x08674958
_0809A818: .4byte 0x84000060
_0809A81C: .4byte 0x08663820
_0809A820: .4byte 0x05000180
_0809A824: .4byte 0x84000020
_0809A828: .4byte 0x04000012
_0809A82C: .4byte 0x00001908
_0809A830: .4byte gWrittenToBldy
_0809A834: .4byte gNonGameplayRam
_0809A838: .4byte gCurrentCutscene
_0809A83C: .4byte 0x0879C5A4
_0809A840: .4byte 0x03000011
_0809A844: .4byte CutsceneFederationMonologueVblank

	thumb_func_start CutsceneFederationMonologueProcess
CutsceneFederationMonologueProcess: @ 0x0809A848
	push {r4, lr}
	bl CutsceneMonologueProcessSpecialTextCharacters
	adds r4, r0, #0
	ldr r1, _0809A860 @ =gNonGameplayRam
	ldrb r0, [r1, #0x17]
	cmp r0, #0
	beq _0809A864
	cmp r0, #1
	beq _0809A86A
	b _0809A872
	.align 2, 0
_0809A860: .4byte gNonGameplayRam
_0809A864:
	movs r0, #0x64
	strb r0, [r1, #0x17]
	b _0809A872
_0809A86A:
	movs r0, #0x64
	strb r0, [r1, #0x17]
	bl CutsceneMonologueProcessText
_0809A872:
	bl CutsceneMonologueProcessOam
	bl CutsceneMonologueDrawAllOam
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneFederationMonologueSetupOam
CutsceneFederationMonologueSetupOam: @ 0x0809A884
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r4, #0
	ldr r1, _0809A8D0 @ =gNonGameplayRam
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A8C6
	adds r3, r1, #0
	adds r1, r2, #0
_0809A8AC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bhi _0809A8CA
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809A8AC
_0809A8C6:
	cmp r4, #4
	bls _0809A8D4
_0809A8CA:
	movs r0, #5
	b _0809A93C
	.align 2, 0
_0809A8D0: .4byte gNonGameplayRam
_0809A8D4:
	adds r0, r4, #0
	bl CutsceneMonologueResetOam
	ldr r5, _0809A948 @ =gNonGameplayRam
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r3, r0, #3
	adds r2, r3, r5
	movs r1, #0x85
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r7, [r0]
	adds r1, #2
	adds r0, r2, r1
	mov r1, r8
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r6, [r0]
	ldr r0, _0809A94C @ =0x00000219
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	cmp r6, #1
	bne _0809A93A
	ldr r0, _0809A950 @ =0x0000021F
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0809A954 @ =0x00000221
	adds r1, r2, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r0, _0809A958 @ =0x00000222
	adds r1, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r3, r0
	ldr r1, _0809A95C @ =0x08663E5C
	str r1, [r0]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r3, r0
	ldr r1, _0809A960 @ =CutsceneMonologueProcessCursor
	str r1, [r0]
_0809A93A:
	adds r0, r4, #0
_0809A93C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809A948: .4byte gNonGameplayRam
_0809A94C: .4byte 0x00000219
_0809A950: .4byte 0x0000021F
_0809A954: .4byte 0x00000221
_0809A958: .4byte 0x00000222
_0809A95C: .4byte 0x08663E5C
_0809A960: .4byte CutsceneMonologueProcessCursor

	thumb_func_start CutsceneFederationMonologueVblank
CutsceneFederationMonologueVblank: @ 0x0809A964
	push {lr}
	ldr r1, _0809A988 @ =0x040000D4
	ldr r0, _0809A98C @ =gOamData
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _0809A990 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl unk_9cc4c
	ldr r1, _0809A994 @ =0x04000054
	ldr r0, _0809A998 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809A988: .4byte 0x040000D4
_0809A98C: .4byte gOamData
_0809A990: .4byte 0x84000100
_0809A994: .4byte 0x04000054
_0809A998: .4byte gWrittenToBldy

	thumb_func_start unk_9a99c
unk_9a99c: @ 0x0809A99C
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneSecretConversation
CutsceneSecretConversation: @ 0x0809A9A8
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _0809A9C0 @ =gNonGameplayRam
	ldrh r0, [r4]
	cmp r0, #1
	beq _0809A9D8
	cmp r0, #1
	bgt _0809A9C4
	cmp r0, #0
	beq _0809A9CE
	b _0809AA20
	.align 2, 0
_0809A9C0: .4byte gNonGameplayRam
_0809A9C4:
	cmp r0, #2
	beq _0809A9F2
	cmp r0, #3
	beq _0809AA12
	b _0809AA20
_0809A9CE:
	movs r0, #1
	strh r0, [r4]
	bl CutsceneSecretConversationInit
	b _0809AA20
_0809A9D8:
	ldr r1, _0809A9E8 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809A9EC
	subs r0, #1
	strh r0, [r1]
	b _0809AA20
	.align 2, 0
_0809A9E8: .4byte gWrittenToBldy
_0809A9EC:
	movs r0, #2
	strh r0, [r4]
	b _0809AA20
_0809A9F2:
	bl CutsceneSecretConversationProcess
	cmp r0, #0
	beq _0809AA20
	movs r0, #3
	strh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x50
	movs r0, #0xff
	strh r0, [r1]
	b _0809AA20
_0809AA12:
	bl CutsceneFadeOut
	ldr r0, _0809AA28 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _0809AA20
	movs r5, #1
_0809AA20:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809AA28: .4byte gWrittenToBldy

	thumb_func_start CutsceneSecretConversationInit
CutsceneSecretConversationInit: @ 0x0809AA2C
	push {r4, r5, lr}
	ldr r3, _0809AAF4 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _0809AAF8 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _0809AAFC @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0809AB00 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0809AB04 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0809AB08 @ =unk_9ae0c
	bl CallbackSetVBlank
	movs r5, #0x80
	lsls r5, r5, #0x13
	strh r4, [r5]
	ldr r0, _0809AB0C @ =0x0867815C
	ldr r1, _0809AB10 @ =0x06014000
	bl LZ77UncompVram
	ldr r4, _0809AB14 @ =0x040000D4
	ldr r0, _0809AB18 @ =0x086788A8
	str r0, [r4]
	ldr r0, _0809AB1C @ =0x05000300
	str r0, [r4, #4]
	ldr r0, _0809AB20 @ =0x84000010
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809AB24 @ =0x08675098
	ldr r1, _0809AB28 @ =0x06000800
	bl LZ77UncompVram
	ldr r0, _0809AB2C @ =0x08677914
	ldr r1, _0809AB30 @ =0x0600C000
	bl LZ77UncompVram
	ldr r0, _0809AB34 @ =0x08677C90
	ldr r1, _0809AB38 @ =0x0600C800
	bl LZ77UncompVram
	ldr r0, _0809AB3C @ =0x08677874
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0809AB40 @ =0x84000028
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809AB44 @ =0x08677C10
	str r0, [r4]
	ldr r0, _0809AB48 @ =0x050001E0
	str r0, [r4, #4]
	ldr r0, _0809AB4C @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #1
	movs r1, #0x78
	movs r2, #0x80
	bl CutsceneSecretConversationSetupOam
	movs r0, #2
	movs r1, #0x78
	movs r2, #0x80
	bl CutsceneSecretConversationSetupOam
	movs r0, #3
	movs r1, #0x78
	movs r2, #0x80
	bl CutsceneSecretConversationSetupOam
	ldr r1, _0809AB50 @ =0x0400000A
	ldr r2, _0809AB54 @ =0x00001802
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0809AB58 @ =0x00001903
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r5]
	ldr r1, _0809AB5C @ =gWrittenToBldy
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	bl CutsceneDrawAllOam
	ldr r0, _0809AB60 @ =CutsceneSecretConversationVblank
	bl CallbackSetVBlank
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AAF4: .4byte 0x04000208
_0809AAF8: .4byte 0x04000004
_0809AAFC: .4byte 0x0000FFEF
_0809AB00: .4byte 0x04000200
_0809AB04: .4byte 0x0000FFFD
_0809AB08: .4byte unk_9ae0c
_0809AB0C: .4byte 0x0867815C
_0809AB10: .4byte 0x06014000
_0809AB14: .4byte 0x040000D4
_0809AB18: .4byte 0x086788A8
_0809AB1C: .4byte 0x05000300
_0809AB20: .4byte 0x84000010
_0809AB24: .4byte 0x08675098
_0809AB28: .4byte 0x06000800
_0809AB2C: .4byte 0x08677914
_0809AB30: .4byte 0x0600C000
_0809AB34: .4byte 0x08677C90
_0809AB38: .4byte 0x0600C800
_0809AB3C: .4byte 0x08677874
_0809AB40: .4byte 0x84000028
_0809AB44: .4byte 0x08677C10
_0809AB48: .4byte 0x050001E0
_0809AB4C: .4byte 0x84000008
_0809AB50: .4byte 0x0400000A
_0809AB54: .4byte 0x00001802
_0809AB58: .4byte 0x00001903
_0809AB5C: .4byte gWrittenToBldy
_0809AB60: .4byte CutsceneSecretConversationVblank

	thumb_func_start CutsceneSecretConversationProcess
CutsceneSecretConversationProcess: @ 0x0809AB64
	push {r4, lr}
	movs r4, #0
	ldr r1, _0809AB7C @ =gNonGameplayRam
	ldrb r0, [r1, #0x10]
	cmp r0, #1
	beq _0809ABAA
	cmp r0, #1
	bgt _0809AB80
	cmp r0, #0
	beq _0809AB86
	b _0809ABBE
	.align 2, 0
_0809AB7C: .4byte gNonGameplayRam
_0809AB80:
	cmp r0, #2
	beq _0809ABB4
	b _0809ABBE
_0809AB86:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _0809ABAE
	movs r0, #1
	strb r0, [r1, #0x10]
	strh r4, [r1, #8]
	movs r0, #4
	movs r1, #0x78
	movs r2, #0x44
	bl CutsceneSecretConversationSetupOam
	bl CutsceneProcessOam
	b _0809ABAE
_0809ABAA:
	bl CutsceneProcessOam
_0809ABAE:
	bl CutsceneDrawAllOam
	b _0809ABBE
_0809ABB4:
	bl CutsceneProcessOam
	bl CutsceneDrawAllOam
	movs r4, #1
_0809ABBE:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneSecretConversationSetupOam
CutsceneSecretConversationSetupOam: @ 0x0809ABC8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r5, #0
	ldr r1, _0809ABE0 @ =gNonGameplayRam
	adds r0, r1, #0
	b _0809ABF6
	.align 2, 0
_0809ABE0: .4byte gNonGameplayRam
_0809ABE4:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bhi _0809AC02
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
_0809ABF6:
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809ABE4
	cmp r5, #0xf
	bls _0809AC06
_0809AC02:
	movs r0, #0x10
	b _0809ACC2
_0809AC06:
	movs r0, #0
	str r0, [sp]
	ldr r1, _0809AC54 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r4, r0, #2
	ldr r3, _0809AC58 @ =0x0300149C
	adds r0, r4, r3
	str r0, [r1, #4]
	ldr r0, _0809AC5C @ =0x85000009
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r0, r3, #0
	subs r0, #0x18
	adds r0, r4, r0
	strh r7, [r0, #0x18]
	strh r2, [r0, #0x1a]
	adds r1, r0, #0
	adds r1, #0x28
	strb r6, [r1]
	adds r0, #0x2e
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	cmp r6, #1
	bne _0809AC68
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809AC60 @ =0x086793B0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809AC64 @ =unk_9db70
	b _0809ACBE
	.align 2, 0
_0809AC54: .4byte 0x040000D4
_0809AC58: .4byte 0x0300149C
_0809AC5C: .4byte 0x85000009
_0809AC60: .4byte 0x086793B0
_0809AC64: .4byte unk_9db70
_0809AC68:
	cmp r6, #2
	bne _0809AC88
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809AC80 @ =0x08679280
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809AC84 @ =CutsceneSecretConversationProcessNavigationPanel
	b _0809ACBE
	.align 2, 0
_0809AC80: .4byte 0x08679280
_0809AC84: .4byte CutsceneSecretConversationProcessNavigationPanel
_0809AC88:
	cmp r6, #3
	bne _0809ACA8
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809ACA0 @ =0x086793A0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809ACA4 @ =unk_9db70
	b _0809ACBE
	.align 2, 0
_0809ACA0: .4byte 0x086793A0
_0809ACA4: .4byte unk_9db70
_0809ACA8:
	cmp r6, #4
	bne _0809ACC0
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809ACCC @ =0x086792D0
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809ACD0 @ =CutsceneSecretConversationProcessIncomingDispatch
_0809ACBE:
	str r1, [r0]
_0809ACC0:
	adds r0, r5, #0
_0809ACC2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809ACCC: .4byte 0x086792D0
_0809ACD0: .4byte CutsceneSecretConversationProcessIncomingDispatch

	thumb_func_start CutsceneSecretConversationProcessNavigationPanel
CutsceneSecretConversationProcessNavigationPanel: @ 0x0809ACD4
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x14]
	cmp r1, #0
	bne _0809ACEA
	movs r0, #1
	strb r0, [r2, #0x14]
	strb r1, [r2, #0x12]
	strb r1, [r2, #0x11]
	ldr r0, _0809ACF0 @ =0x086792A8
	str r0, [r2, #0x1c]
_0809ACEA:
	pop {r0}
	bx r0
	.align 2, 0
_0809ACF0: .4byte 0x086792A8

	thumb_func_start CutsceneSecretConversationProcessIncomingDispatch
CutsceneSecretConversationProcessIncomingDispatch: @ 0x0809ACF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r5, [r4, #0x14]
	cmp r5, #0
	bne _0809AD3C
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #3
	ldr r1, [r4, #0x1c]
	adds r6, r1, r0
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _0809AD16
	ldr r0, _0809AD34 @ =0x0000022F
	bl SoundPlay
	movs r0, #1
	strb r0, [r4, #0x13]
_0809AD16:
	ldrb r0, [r6, #4]
	ldrb r1, [r4, #0x12]
	cmp r0, r1
	bne _0809AD5A
	ldrb r0, [r6, #0xc]
	cmp r0, #0
	bne _0809AD5A
	movs r0, #1
	strb r0, [r4, #0x14]
	strb r5, [r4, #0x13]
	strb r5, [r4, #0x12]
	strb r5, [r4, #0x11]
	ldr r0, _0809AD38 @ =0x08679350
	str r0, [r4, #0x1c]
	b _0809AD5A
	.align 2, 0
_0809AD34: .4byte 0x0000022F
_0809AD38: .4byte 0x08679350
_0809AD3C:
	cmp r5, #1
	bne _0809AD5A
	ldrb r0, [r4, #0x13]
	adds r0, #1
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb4
	bne _0809AD5A
	movs r0, #2
	strb r0, [r4, #0x14]
	movs r1, #0
	strb r1, [r4, #0x13]
	ldr r1, _0809AD60 @ =gNonGameplayRam
	strb r0, [r1, #0x10]
_0809AD5A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AD60: .4byte gNonGameplayRam

	thumb_func_start CutsceneSecretConversationVblank
CutsceneSecretConversationVblank: @ 0x0809AD64
	push {lr}
	ldr r2, _0809AD98 @ =0x040000D4
	ldr r0, _0809AD9C @ =gOamData
	str r0, [r2]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r2, #4]
	ldr r0, _0809ADA0 @ =0x84000100
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r1, _0809ADA4 @ =0x04000054
	ldr r0, _0809ADA8 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809ADAC @ =gNonGameplayRam
	ldrb r0, [r1, #0x11]
	adds r0, #1
	strb r0, [r1, #0x11]
	ldrb r0, [r1, #0x11]
	cmp r0, #0xe
	beq _0809ADC4
	cmp r0, #0xe
	bgt _0809ADB0
	cmp r0, #7
	beq _0809ADBA
	b _0809ADFA
	.align 2, 0
_0809AD98: .4byte 0x040000D4
_0809AD9C: .4byte gOamData
_0809ADA0: .4byte 0x84000100
_0809ADA4: .4byte 0x04000054
_0809ADA8: .4byte gWrittenToBldy
_0809ADAC: .4byte gNonGameplayRam
_0809ADB0:
	cmp r0, #0x15
	beq _0809ADCC
	cmp r0, #0x1c
	beq _0809ADE8
	b _0809ADFA
_0809ADBA:
	ldr r0, _0809ADC0 @ =0x08677C30
	b _0809ADCE
	.align 2, 0
_0809ADC0: .4byte 0x08677C30
_0809ADC4:
	ldr r0, _0809ADC8 @ =0x08677C50
	b _0809ADCE
	.align 2, 0
_0809ADC8: .4byte 0x08677C50
_0809ADCC:
	ldr r0, _0809ADDC @ =0x08677C70
_0809ADCE:
	str r0, [r2]
	ldr r0, _0809ADE0 @ =0x050001E0
	str r0, [r2, #4]
	ldr r0, _0809ADE4 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0809ADFA
	.align 2, 0
_0809ADDC: .4byte 0x08677C70
_0809ADE0: .4byte 0x050001E0
_0809ADE4: .4byte 0x84000008
_0809ADE8:
	ldr r0, _0809AE00 @ =0x08677C10
	str r0, [r2]
	ldr r0, _0809AE04 @ =0x050001E0
	str r0, [r2, #4]
	ldr r0, _0809AE08 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	strb r0, [r1, #0x11]
_0809ADFA:
	pop {r0}
	bx r0
	.align 2, 0
_0809AE00: .4byte 0x08677C10
_0809AE04: .4byte 0x050001E0
_0809AE08: .4byte 0x84000008

	thumb_func_start unk_9ae0c
unk_9ae0c: @ 0x0809AE0C
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneRestrictedLabDetaching
CutsceneRestrictedLabDetaching: @ 0x0809AE18
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _0809AE30 @ =gNonGameplayRam
	ldrh r0, [r4]
	cmp r0, #1
	beq _0809AE48
	cmp r0, #1
	bgt _0809AE34
	cmp r0, #0
	beq _0809AE3E
	b _0809AE96
	.align 2, 0
_0809AE30: .4byte gNonGameplayRam
_0809AE34:
	cmp r0, #2
	beq _0809AE70
	cmp r0, #3
	beq _0809AE88
	b _0809AE96
_0809AE3E:
	movs r0, #1
	strh r0, [r4]
	bl CutsceneRestrictedLabDetachingInit
	b _0809AE96
_0809AE48:
	ldr r5, _0809AE6C @ =gWrittenToBldy
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _0809AE58
	movs r0, #0x92
	lsls r0, r0, #2
	bl SoundPlay_3b1c
_0809AE58:
	bl CutsceneFadeIn
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809AE96
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0809AE96
	.align 2, 0
_0809AE6C: .4byte gWrittenToBldy
_0809AE70:
	bl CutsceneRestrictedLabDetachingProcess
	cmp r0, #0
	beq _0809AE96
	movs r0, #3
	strh r0, [r4]
	ldr r1, _0809AE84 @ =0x04000050
	movs r0, #0xbf
	strh r0, [r1]
	b _0809AE96
	.align 2, 0
_0809AE84: .4byte 0x04000050
_0809AE88:
	bl CutsceneFadeOut
	ldr r0, _0809AEA0 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _0809AE96
	movs r6, #1
_0809AE96:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809AEA0: .4byte gWrittenToBldy

	thumb_func_start CutsceneRestrictedLabDetachingInit
CutsceneRestrictedLabDetachingInit: @ 0x0809AEA4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r3, _0809AF9C @ =0x04000208
	movs r5, #0
	strh r5, [r3]
	ldr r2, _0809AFA0 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _0809AFA4 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0809AFA8 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0809AFAC @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0809AFB0 @ =unk_9c1bc
	bl CallbackSetVBlank
	bl unk_36c4
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	strh r5, [r0]
	ldr r0, _0809AFB4 @ =0x0867D7CC
	ldr r1, _0809AFB8 @ =0x06010000
	bl LZ77UncompVram
	ldr r4, _0809AFBC @ =0x040000D4
	ldr r0, _0809AFC0 @ =0x0868121C
	str r0, [r4]
	ldr r0, _0809AFC4 @ =0x05000200
	str r0, [r4, #4]
	ldr r6, _0809AFC8 @ =0x84000080
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809AFCC @ =0x08679420
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldr r0, _0809AFD0 @ =0x086820A4
	ldr r1, _0809AFD4 @ =0x0600E000
	bl LZ77UncompVram
	ldr r0, _0809AFD8 @ =0x08681A1C
	ldr r1, _0809AFDC @ =0x0600E800
	bl LZ77UncompVram
	ldr r0, _0809AFE0 @ =0x0868259C
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r1, [r4, #8]
	strh r5, [r0]
	ldr r1, _0809AFE4 @ =0x0400000A
	movs r2, #0xe8
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	subs r2, #0xfd
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r1, _0809AFE8 @ =gWrittenToBldy
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #1
	movs r1, #0x96
	movs r2, #0x5a
	bl CutsceneRestrictedLabDetachingSetupOam
	movs r0, #3
	movs r1, #0x96
	movs r2, #0x5a
	bl CutsceneRestrictedLabDetachingSetupOam
	movs r0, #2
	movs r1, #0x96
	movs r2, #0x5a
	bl CutsceneRestrictedLabDetachingSetupOam
	movs r0, #4
	movs r1, #0x78
	movs r2, #0
	bl CutsceneRestrictedLabDetachingSetupOam
	bl CutsceneProcessOam
	bl CutsceneDrawAllOam
	ldr r0, _0809AFEC @ =gNonGameplayRam
	movs r1, #0
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	movs r1, #0xc
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r1, _0809AFF0 @ =0x0868101C
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0809AFF4 @ =0x05000120
	str r0, [r4, #4]
	ldr r0, _0809AFF8 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809AFFC @ =CutsceneRestrictedLabDetachingVblank
	bl CallbackSetVBlank
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809AF9C: .4byte 0x04000208
_0809AFA0: .4byte 0x04000004
_0809AFA4: .4byte 0x0000FFEF
_0809AFA8: .4byte 0x04000200
_0809AFAC: .4byte 0x0000FFFD
_0809AFB0: .4byte unk_9c1bc
_0809AFB4: .4byte 0x0867D7CC
_0809AFB8: .4byte 0x06010000
_0809AFBC: .4byte 0x040000D4
_0809AFC0: .4byte 0x0868121C
_0809AFC4: .4byte 0x05000200
_0809AFC8: .4byte 0x84000080
_0809AFCC: .4byte 0x08679420
_0809AFD0: .4byte 0x086820A4
_0809AFD4: .4byte 0x0600E000
_0809AFD8: .4byte 0x08681A1C
_0809AFDC: .4byte 0x0600E800
_0809AFE0: .4byte 0x0868259C
_0809AFE4: .4byte 0x0400000A
_0809AFE8: .4byte gWrittenToBldy
_0809AFEC: .4byte gNonGameplayRam
_0809AFF0: .4byte 0x0868101C
_0809AFF4: .4byte 0x05000120
_0809AFF8: .4byte 0x84000008
_0809AFFC: .4byte CutsceneRestrictedLabDetachingVblank

	thumb_func_start CutsceneRestrictedLabDetachingProcess
CutsceneRestrictedLabDetachingProcess: @ 0x0809B000
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	movs r7, #0
	ldr r0, _0809B01C @ =gNonGameplayRam
	ldrb r1, [r0, #0x10]
	adds r5, r0, #0
	cmp r1, #0xa
	bls _0809B012
	b _0809B356
_0809B012:
	lsls r0, r1, #2
	ldr r1, _0809B020 @ =_0809B024
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809B01C: .4byte gNonGameplayRam
_0809B020: .4byte _0809B024
_0809B024: @ jump table
	.4byte _0809B050 @ case 0
	.4byte _0809B068 @ case 1
	.4byte _0809B178 @ case 2
	.4byte _0809B356 @ case 3
	.4byte _0809B356 @ case 4
	.4byte _0809B1B0 @ case 5
	.4byte _0809B218 @ case 6
	.4byte _0809B236 @ case 7
	.4byte _0809B268 @ case 8
	.4byte _0809B2C8 @ case 9
	.4byte _0809B308 @ case 10
_0809B050:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #1
	beq _0809B060
	b _0809B356
_0809B060:
	movs r0, #0
	strh r0, [r5, #8]
	strb r1, [r5, #0x10]
	b _0809B356
_0809B068:
	ldrh r0, [r5, #8]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _0809B0C0
	mov r4, sp
	adds r4, #6
	movs r0, #2
	add r1, sp, #4
	adds r2, r4, #0
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x14
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4]
	subs r2, #0x14
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #6
	str r0, [sp]
	movs r0, #0x11
	bl unk_9c0b4
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x46
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4]
	subs r2, #0x1a
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #1
	rsbs r3, r3, #0
	movs r0, #4
	b _0809B156
_0809B0C0:
	cmp r0, #0x10
	bne _0809B10C
	mov r4, sp
	adds r4, #6
	movs r0, #2
	add r1, sp, #4
	adds r2, r4, #0
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x1e
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4]
	subs r2, #0x1e
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #2
	rsbs r3, r3, #0
	movs r5, #8
	str r5, [sp]
	movs r0, #0x11
	bl unk_9c0b4
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x32
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4]
	subs r2, #8
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #1
	rsbs r3, r3, #0
	str r5, [sp]
	b _0809B158
_0809B10C:
	cmp r0, #0x14
	bne _0809B160
	mov r4, sp
	adds r4, #6
	movs r0, #2
	add r1, sp, #4
	adds r2, r4, #0
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x50
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4]
	subs r2, #0xe
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #3
	rsbs r3, r3, #0
	movs r0, #6
	str r0, [sp]
	movs r0, #0x11
	bl unk_9c0b4
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0xa
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4]
	subs r2, #0x12
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #2
_0809B156:
	str r0, [sp]
_0809B158:
	movs r0, #0x11
	bl unk_9c0b4
	b _0809B356
_0809B160:
	cmp r0, #0xaa
	beq _0809B166
	b _0809B356
_0809B166:
	strh r1, [r5, #8]
	movs r0, #2
	strb r0, [r5, #0x10]
	ldr r0, _0809B174 @ =gWrittenToBldy
	strh r1, [r0]
	b _0809B356
	.align 2, 0
_0809B174: .4byte gWrittenToBldy
_0809B178:
	ldr r1, _0809B1A0 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bls _0809B1B8
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #0
	str r0, [sp, #8]
	ldr r1, _0809B1A4 @ =0x040000D4
	add r0, sp, #8
	str r0, [r1]
	ldr r2, _0809B1A8 @ =0x0300149C
	str r2, [r1, #4]
	ldr r0, _0809B1AC @ =0x85000090
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r2, #0x18
	movs r0, #5
	strb r0, [r2, #0x10]
	b _0809B356
	.align 2, 0
_0809B1A0: .4byte gWrittenToBldy
_0809B1A4: .4byte 0x040000D4
_0809B1A8: .4byte 0x0300149C
_0809B1AC: .4byte 0x85000090
_0809B1B0:
	ldr r1, _0809B1C0 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0809B1C4
_0809B1B8:
	adds r0, #2
	strh r0, [r1]
	b _0809B356
	.align 2, 0
_0809B1C0: .4byte gWrittenToBldy
_0809B1C4:
	movs r5, #0
	str r5, [sp, #8]
	ldr r1, _0809B208 @ =0x040000D4
	add r0, sp, #8
	str r0, [r1]
	ldr r4, _0809B20C @ =0x0300149C
	str r4, [r1, #4]
	ldr r0, _0809B210 @ =0x85000090
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	subs r4, #0x18
	strh r5, [r4, #8]
	movs r0, #4
	movs r1, #0
	movs r2, #0
	bl CutsceneRestrictedLabDetachingSetupOam
	movs r0, #0x1e
	movs r1, #0xcd
	movs r2, #0xa
	bl CutsceneRestrictedLabDetachingSetupOam
	movs r0, #0xc
	movs r1, #0x8c
	movs r2, #0x50
	bl CutsceneRestrictedLabDetachingSetupOam
	ldr r0, _0809B214 @ =0x04000018
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	movs r0, #6
	strb r0, [r4, #0x10]
	b _0809B356
	.align 2, 0
_0809B208: .4byte 0x040000D4
_0809B20C: .4byte 0x0300149C
_0809B210: .4byte 0x85000090
_0809B214: .4byte 0x04000018
_0809B218:
	ldr r2, _0809B228 @ =gWrittenToBldy
	ldrh r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _0809B22C
	subs r0, #2
	strh r0, [r2]
	b _0809B356
	.align 2, 0
_0809B228: .4byte gWrittenToBldy
_0809B22C:
	strh r1, [r2]
	strh r1, [r5, #8]
	movs r0, #7
	strb r0, [r5, #0x10]
	b _0809B356
_0809B236:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bne _0809B258
	ldr r0, _0809B250 @ =gWrittenToBldalpha_Eva
	movs r1, #0xa
	strh r1, [r0]
	ldr r0, _0809B254 @ =gWrittenToBldalpha_Evb
	strh r1, [r0]
	b _0809B356
	.align 2, 0
_0809B250: .4byte gWrittenToBldalpha_Eva
_0809B254: .4byte gWrittenToBldalpha_Evb
_0809B258:
	cmp r0, #0x96
	beq _0809B25E
	b _0809B356
_0809B25E:
	movs r0, #0
	strh r0, [r5, #8]
	movs r0, #8
	strb r0, [r5, #0x10]
	b _0809B356
_0809B268:
	ldrh r0, [r5, #8]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _0809B356
	ldr r1, _0809B2C0 @ =0x04000050
	ldr r2, _0809B2C4 @ =0x00001C42
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	mov r4, sp
	adds r4, #6
	movs r0, #0xc
	add r1, sp, #4
	adds r2, r4, #0
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType
	movs r0, #0xc
	bl CutsceneDestroyOamOfType
	add r0, sp, #4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r2, [r4, r3]
	str r6, [sp]
	movs r0, #0x10
	movs r3, #0
	bl unk_9c0b4
	strh r6, [r5, #8]
	movs r0, #9
	strb r0, [r5, #0x10]
	b _0809B356
	.align 2, 0
_0809B2C0: .4byte 0x04000050
_0809B2C4: .4byte 0x00001C42
_0809B2C8:
	ldrh r0, [r5, #8]
	adds r1, r0, #1
	movs r3, #0
	strh r1, [r5, #8]
	ldrh r2, [r5, #0xc]
	movs r4, #0xc
	ldrsh r0, [r5, r4]
	cmp r0, #0xe
	bgt _0809B2EE
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _0809B356
	strh r3, [r5, #8]
	movs r0, #1
	strh r0, [r5, #0xa]
	adds r0, r2, #1
	strh r0, [r5, #0xc]
	b _0809B356
_0809B2EE:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0809B356
	strh r3, [r5, #8]
	ldr r0, _0809B304 @ =gWrittenToBldy
	movs r1, #0x10
	strh r1, [r0]
	movs r0, #0xa
	strb r0, [r5, #0x10]
	b _0809B356
	.align 2, 0
_0809B304: .4byte gWrittenToBldy
_0809B308:
	adds r3, r5, #0
	ldrh r0, [r3, #8]
	adds r2, r0, #1
	movs r4, #0
	strh r2, [r3, #8]
	ldr r6, _0809B32C @ =gWrittenToBldalpha_Eva
	ldrh r1, [r6]
	cmp r1, #0xf
	bhi _0809B330
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _0809B356
	strh r4, [r3, #8]
	adds r0, r1, #1
	strh r0, [r6]
	b _0809B356
	.align 2, 0
_0809B32C: .4byte gWrittenToBldalpha_Eva
_0809B330:
	ldr r1, _0809B368 @ =0x04000050
	movs r0, #0xbf
	strh r0, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _0809B356
	strh r4, [r5, #8]
	str r4, [sp, #8]
	adds r1, #0x84
	add r0, sp, #8
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x18
	str r0, [r1, #4]
	ldr r0, _0809B36C @ =0x85000090
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r7, #1
_0809B356:
	bl CutsceneProcessOam
	bl CutsceneDrawAllOam
	adds r0, r7, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B368: .4byte 0x04000050
_0809B36C: .4byte 0x85000090

	thumb_func_start CutsceneRestrictedLabDetachingProcessFallingLab
CutsceneRestrictedLabDetachingProcessFallingLab: @ 0x0809B370
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _0809B388
	ldrh r0, [r2]
	strh r0, [r2, #6]
	ldrh r0, [r2, #2]
	strh r0, [r2, #8]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _0809B3A4
_0809B388:
	cmp r0, #1
	bne _0809B3A4
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x11
	ldrh r3, [r2, #6]
	adds r1, r1, r3
	strh r1, [r2]
	lsrs r0, r0, #0x12
	ldrh r1, [r2, #8]
	subs r1, r1, r0
	strh r1, [r2, #2]
_0809B3A4:
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0809B3E8
	movs r0, #0
	strb r0, [r2, #0x13]
	ldrh r1, [r2, #0xe]
	cmp r1, #0xdb
	bhi _0809B3C2
	ldrh r0, [r2, #4]
	adds r0, #2
	b _0809B3D8
_0809B3C2:
	ldr r0, _0809B3D0 @ =0x000001B7
	cmp r1, r0
	bhi _0809B3D4
	ldrh r0, [r2, #4]
	adds r0, #4
	b _0809B3D8
	.align 2, 0
_0809B3D0: .4byte 0x000001B7
_0809B3D4:
	ldrh r0, [r2, #4]
	adds r0, #6
_0809B3D8:
	strh r0, [r2, #4]
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r0, _0809B438 @ =0x000001FF
	cmp r1, r0
	ble _0809B3E8
	adds r0, #1
	strh r0, [r2, #4]
_0809B3E8:
	ldrh r0, [r2, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r2, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne _0809B40A
	strh r1, [r2, #0xa]
	ldrh r0, [r2, #0xc]
	adds r0, #1
	strh r0, [r2, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble _0809B40A
	strh r1, [r2, #0xc]
_0809B40A:
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x99
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809B428
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r0, #0x32
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809B428
	cmp r1, #0xb0
	ble _0809B434
_0809B428:
	movs r0, #0
	strb r0, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r2, #0x16]
_0809B434:
	pop {r0}
	bx r0
	.align 2, 0
_0809B438: .4byte 0x000001FF

	thumb_func_start CutsceneRestrictedLabDetachingSetupOam
CutsceneRestrictedLabDetachingSetupOam: @ 0x0809B43C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	movs r0, #0
	mov r8, r0
	ldr r1, _0809B490 @ =gNonGameplayRam
	adds r0, r1, #0
	adds r0, #0x28
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	beq _0809B484
_0809B466:
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0xf
	bhi _0809B48A
	lsls r0, r0, #3
	add r0, r8
	lsls r0, r0, #2
	adds r0, r0, r1
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809B466
_0809B484:
	mov r2, r8
	cmp r2, #0xf
	bls _0809B494
_0809B48A:
	movs r0, #0x10
	b _0809B896
	.align 2, 0
_0809B490: .4byte gNonGameplayRam
_0809B494:
	movs r0, #0
	str r0, [sp]
	ldr r1, _0809B500 @ =0x040000D4
	mov r3, sp
	str r3, [r1]
	mov r0, r8
	lsls r2, r0, #3
	adds r0, r2, r0
	lsls r5, r0, #2
	ldr r3, _0809B504 @ =0x0300149C
	mov ip, r3
	adds r0, r5, r3
	str r0, [r1, #4]
	ldr r0, _0809B508 @ =0x85000009
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, ip
	subs r0, #0x18
	adds r3, r5, r0
	mov r0, sb
	strh r0, [r3, #0x18]
	strh r6, [r3, #0x1a]
	adds r0, r3, #0
	adds r0, #0x28
	strb r4, [r0]
	adds r6, r3, #0
	adds r6, #0x2e
	ldrb r1, [r6]
	movs r0, #1
	orrs r1, r0
	strb r1, [r6]
	cmp r4, #1
	bne _0809B510
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	ldrb r0, [r6]
	movs r1, #6
	orrs r0, r1
	strb r0, [r6]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B50C @ =0x08680D54
	b _0809B570
	.align 2, 0
_0809B500: .4byte 0x040000D4
_0809B504: .4byte 0x0300149C
_0809B508: .4byte 0x85000009
_0809B50C: .4byte 0x08680D54
_0809B510:
	cmp r4, #2
	bne _0809B544
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	ldrb r0, [r6]
	movs r1, #6
	orrs r0, r1
	strb r0, [r6]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B540 @ =0x08680D64
	b _0809B570
	.align 2, 0
_0809B540: .4byte 0x08680D64
_0809B544:
	cmp r4, #3
	bne _0809B588
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	ldrb r0, [r6]
	movs r1, #6
	orrs r0, r1
	strb r0, [r6]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B580 @ =0x08680D74
_0809B570:
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B584 @ =CutsceneRestrictedLabDetachingProcessBslPart
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B580: .4byte 0x08680D74
_0809B584: .4byte CutsceneRestrictedLabDetachingProcessBslPart
_0809B588:
	cmp r4, #4
	bne _0809B5A4
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r6]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B5A0 @ =CutsceneRestrictedLabDetachingProcessScrolling
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B5A0: .4byte CutsceneRestrictedLabDetachingProcessScrolling
_0809B5A4:
	cmp r4, #5
	bne _0809B5B8
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B5B4 @ =0x08680E2C
	b _0809B5D6
	.align 2, 0
_0809B5B4: .4byte 0x08680E2C
_0809B5B8:
	cmp r4, #6
	bne _0809B5EC
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B5E4 @ =0x08680E3C
_0809B5D6:
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B5E8 @ =unk_9ba50
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B5E4: .4byte 0x08680E3C
_0809B5E8: .4byte unk_9ba50
_0809B5EC:
	cmp r4, #7
	bne _0809B620
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B618 @ =0x08680DA4
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B61C @ =unk_9bac0
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B618: .4byte 0x08680DA4
_0809B61C: .4byte unk_9bac0
_0809B620:
	cmp r4, #8
	bne _0809B654
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B64C @ =0x08680D94
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B650 @ =unk_9bb30
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B64C: .4byte 0x08680D94
_0809B650: .4byte unk_9bb30
_0809B654:
	cmp r4, #9
	bne _0809B69C
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	adds r2, r3, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldrb r1, [r6]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r6]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r5, r0
	ldr r1, _0809B694 @ =0x08680D84
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B698 @ =unk_9bc04
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B694: .4byte 0x08680D84
_0809B698: .4byte unk_9bc04
_0809B69C:
	cmp r4, #0xa
	bne _0809B6B8
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r6]
	mov r0, ip
	adds r0, #0x20
	adds r0, r5, r0
	ldr r1, _0809B6B4 @ =unk_9bcdc
	str r1, [r0]
	b _0809B894
	.align 2, 0
_0809B6B4: .4byte unk_9bcdc
_0809B6B8:
	cmp r4, #0xb
	bne _0809B6DC
	add r2, r8
	lsls r2, r2, #2
	adds r0, r7, #0
	adds r0, #0x34
	adds r0, r2, r0
	ldr r1, _0809B6D4 @ =0x08680DCC
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B6D8 @ =unk_9bac0
	b _0809B892
	.align 2, 0
_0809B6D4: .4byte 0x08680DCC
_0809B6D8: .4byte unk_9bac0
_0809B6DC:
	cmp r4, #0xc
	bne _0809B72C
	add r2, r8
	lsls r2, r2, #2
	adds r3, r2, r7
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	adds r4, r3, #0
	adds r4, #0x30
	ldrb r1, [r4]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	adds r3, #0x2e
	ldrb r1, [r3]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0x34
	adds r0, r2, r0
	ldr r1, _0809B724 @ =0x08680FEC
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B728 @ =unk_9bd24
	b _0809B892
	.align 2, 0
_0809B724: .4byte 0x08680FEC
_0809B728: .4byte unk_9bd24
_0809B72C:
	cmp r4, #0xd
	bne _0809B77C
	add r2, r8
	lsls r2, r2, #2
	adds r3, r2, r7
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	adds r4, r3, #0
	adds r4, #0x30
	ldrb r1, [r4]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	adds r3, #0x2e
	ldrb r1, [r3]
	movs r0, #7
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0x34
	adds r0, r2, r0
	ldr r1, _0809B774 @ =0x08680FC4
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B778 @ =unk_9bdf8
	b _0809B892
	.align 2, 0
_0809B774: .4byte 0x08680FC4
_0809B778: .4byte unk_9bdf8
_0809B77C:
	cmp r4, #0xe
	bne _0809B7A0
	add r2, r8
	lsls r2, r2, #2
	adds r1, r2, r7
	adds r1, #0x2e
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B79C @ =unk_9be8c
	b _0809B892
	.align 2, 0
_0809B79C: .4byte unk_9be8c
_0809B7A0:
	cmp r4, #0xf
	bne _0809B7C4
	add r2, r8
	lsls r2, r2, #2
	adds r1, r2, r7
	adds r1, #0x2e
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B7C0 @ =unk_9bf54
	b _0809B892
	.align 2, 0
_0809B7C0: .4byte unk_9bf54
_0809B7C4:
	cmp r4, #0x10
	bne _0809B80C
	add r2, r8
	lsls r2, r2, #2
	adds r3, r2, r7
	adds r4, r3, #0
	adds r4, #0x2e
	ldrb r1, [r4]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4]
	adds r3, #0x30
	ldrb r1, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0x34
	adds r0, r2, r0
	ldr r1, _0809B804 @ =0x08680F9C
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B808 @ =unk_9bfb8
	b _0809B892
	.align 2, 0
_0809B804: .4byte 0x08680F9C
_0809B808: .4byte unk_9bfb8
_0809B80C:
	cmp r4, #0x11
	bne _0809B830
	add r2, r8
	lsls r2, r2, #2
	adds r0, r7, #0
	adds r0, #0x34
	adds r0, r2, r0
	ldr r1, _0809B828 @ =0x08680F74
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B82C @ =unk_9bfb8
	b _0809B892
	.align 2, 0
_0809B828: .4byte 0x08680F74
_0809B82C: .4byte unk_9bfb8
_0809B830:
	cmp r4, #0x12
	bne _0809B854
	add r2, r8
	lsls r2, r2, #2
	adds r1, r2, r7
	adds r1, #0x2e
	ldrb r3, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B850 @ =unk_9c04c
	b _0809B892
	.align 2, 0
_0809B850: .4byte unk_9c04c
_0809B854:
	cmp r4, #0x1e
	bne _0809B894
	add r2, r8
	lsls r2, r2, #2
	adds r3, r2, r7
	movs r0, #0xd0
	lsls r0, r0, #1
	strh r0, [r3, #0x1c]
	adds r4, r3, #0
	adds r4, #0x30
	ldrb r1, [r4]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	adds r3, #0x2e
	ldrb r0, [r3]
	movs r1, #6
	orrs r0, r1
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0x34
	adds r0, r2, r0
	ldr r1, _0809B8A4 @ =0x08680F2C
	str r1, [r0]
	adds r0, r7, #0
	adds r0, #0x38
	adds r2, r2, r0
	ldr r0, _0809B8A8 @ =CutsceneRestrictedLabDetachingProcessFallingLab
_0809B892:
	str r0, [r2]
_0809B894:
	mov r0, r8
_0809B896:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809B8A4: .4byte 0x08680F2C
_0809B8A8: .4byte CutsceneRestrictedLabDetachingProcessFallingLab

	thumb_func_start CutsceneRestrictedLabDetachingProcessBslPart
CutsceneRestrictedLabDetachingProcessBslPart: @ 0x0809B8AC
	push {r4, lr}
	adds r2, r0, #0
	ldrb r3, [r2, #0x14]
	cmp r3, #0
	bne _0809B98C
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0809B8CC
	strb r3, [r2, #0x13]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0809B8CC:
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	movs r4, #6
	ldrsh r1, [r2, r4]
	cmp r1, #1
	beq _0809B90C
	cmp r1, #1
	bgt _0809B8E4
	cmp r1, #0
	beq _0809B8EA
	b _0809B954
_0809B8E4:
	cmp r1, #2
	beq _0809B930
	b _0809B954
_0809B8EA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _0809B964
	strh r3, [r2, #0xe]
	ldrh r0, [r2, #4]
	adds r0, #2
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	ldr r1, _0809B908 @ =0x017F0000
	cmp r0, r1
	ble _0809B964
	movs r0, #1
	strh r0, [r2, #6]
	b _0809B964
	.align 2, 0
_0809B908: .4byte 0x017F0000
_0809B90C:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _0809B964
	strh r3, [r2, #0xe]
	ldrh r0, [r2, #4]
	adds r0, #2
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	ldr r1, _0809B92C @ =0x019F0000
	cmp r0, r1
	ble _0809B964
	movs r0, #2
	strh r0, [r2, #6]
	b _0809B964
	.align 2, 0
_0809B92C: .4byte 0x019F0000
_0809B930:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _0809B964
	strh r3, [r2, #0xe]
	ldrh r0, [r2, #4]
	adds r0, #2
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	ldr r1, _0809B950 @ =0x01BF0000
	cmp r0, r1
	ble _0809B964
	movs r0, #3
	strh r0, [r2, #6]
	b _0809B964
	.align 2, 0
_0809B950: .4byte 0x01BF0000
_0809B954:
	ldrh r0, [r2, #0xe]
	cmp r0, #7
	bne _0809B964
	movs r0, #0
	strh r0, [r2, #0xe]
	ldrh r0, [r2, #4]
	adds r0, #2
	strh r0, [r2, #4]
_0809B964:
	movs r1, #4
	ldrsh r0, [r2, r1]
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _0809B972
	strh r1, [r2, #4]
_0809B972:
	ldr r0, _0809B988 @ =gNonGameplayRam
	ldrb r1, [r0, #0x10]
	cmp r1, #1
	bne _0809BA1C
	movs r0, #0
	strb r1, [r2, #0x14]
	strb r0, [r2, #0x13]
	strh r0, [r2, #6]
	strh r0, [r2, #0xe]
	b _0809BA1C
	.align 2, 0
_0809B988: .4byte gNonGameplayRam
_0809B98C:
	cmp r3, #1
	bne _0809B9C0
	ldrb r0, [r2, #0x13]
	adds r0, #1
	movs r1, #0
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0809B9A8
	strb r1, [r2, #0x13]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0809B9A8:
	ldrb r0, [r2, #0x10]
	cmp r0, #3
	bne _0809B9B6
	ldrh r0, [r2, #2]
	adds r0, #6
	strh r0, [r2, #2]
	strh r0, [r2, #8]
_0809B9B6:
	strh r1, [r2, #0xe]
	strh r1, [r2, #0xa]
	movs r0, #2
	strb r0, [r2, #0x14]
	b _0809BA1C
_0809B9C0:
	cmp r3, #2
	bne _0809BA1C
	ldrb r0, [r2, #0x13]
	adds r0, #1
	movs r1, #0
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0809B9DC
	strb r1, [r2, #0x13]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0809B9DC:
	ldrh r0, [r2, #0xa]
	adds r0, #1
	strh r0, [r2, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bne _0809BA00
	strh r1, [r2, #0xa]
	ldrh r0, [r2, #4]
	adds r0, #2
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	ble _0809BA00
	strh r1, [r2, #4]
_0809BA00:
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	ldrb r0, [r2, #0x10]
	cmp r0, #3
	bne _0809BA1C
	ldrh r0, [r2, #0xe]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	asrs r0, r0, #0xa
	ldrh r1, [r2, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
_0809BA1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneRestrictedLabDetachingProcessScrolling
CutsceneRestrictedLabDetachingProcessScrolling: @ 0x0809BA24
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bne _0809BA40
	movs r0, #0
	strb r0, [r2, #0x13]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0809BA40:
	ldr r1, _0809BA4C @ =0x0400001C
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809BA4C: .4byte 0x0400001C

	thumb_func_start unk_9ba50
unk_9ba50: @ 0x0809BA50
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _0809BA68
	ldrh r0, [r2]
	strh r0, [r2, #6]
	ldrh r0, [r2, #2]
	strh r0, [r2, #8]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _0809BA92
_0809BA68:
	cmp r0, #1
	bne _0809BA92
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #6]
	adds r0, r0, r1
	strh r0, [r2]
	movs r0, #0xa
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
_0809BA92:
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809BAB0
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809BAB0
	cmp r1, #0xb0
	ble _0809BABC
_0809BAB0:
	movs r0, #0
	strb r0, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r2, #0x16]
_0809BABC:
	pop {r0}
	bx r0

	thumb_func_start unk_9bac0
unk_9bac0: @ 0x0809BAC0
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _0809BAD8
	ldrh r0, [r2]
	strh r0, [r2, #6]
	ldrh r0, [r2, #2]
	strh r0, [r2, #8]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _0809BB02
_0809BAD8:
	cmp r0, #1
	bne _0809BB02
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #6]
	adds r0, r0, r1
	strh r0, [r2]
	movs r0, #0xa
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
_0809BB02:
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809BB20
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809BB20
	cmp r1, #0xb0
	ble _0809BB2C
_0809BB20:
	movs r0, #0
	strb r0, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r2, #0x16]
_0809BB2C:
	pop {r0}
	bx r0

	thumb_func_start unk_9bb30
unk_9bb30: @ 0x0809BB30
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x14]
	cmp r0, #0
	bne _0809BB48
	ldrh r0, [r3]
	strh r0, [r3, #6]
	ldrh r0, [r3, #2]
	strh r0, [r3, #8]
	movs r0, #1
	strb r0, [r3, #0x14]
	b _0809BB6A
_0809BB48:
	cmp r0, #1
	bne _0809BB6A
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldrh r0, [r3, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsrs r1, r1, #4
	ldrh r0, [r3, #6]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r3, #0xe]
	lsrs r0, r0, #3
	ldrh r1, [r3, #8]
	adds r0, r0, r1
	strh r0, [r3, #2]
_0809BB6A:
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bne _0809BB8C
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrh r0, [r3, #4]
	subs r0, #2
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0809BB8C
	movs r0, #2
	strh r0, [r3, #4]
_0809BB8C:
	ldrh r0, [r3, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	bne _0809BBC6
	strh r1, [r3, #0xa]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0809BBAE
	strh r1, [r3, #0xc]
_0809BBAE:
	ldr r2, _0809BBF4 @ =0x040000D4
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	lsls r0, r0, #5
	ldr r1, _0809BBF8 @ =0x0868161C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0809BBFC @ =0x05000220
	str r0, [r2, #4]
	ldr r0, _0809BC00 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0809BBC6:
	ldrh r0, [r3]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809BBE4
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809BBE4
	cmp r1, #0xb0
	ble _0809BBF0
_0809BBE4:
	movs r0, #0
	strb r0, [r3, #0x10]
	ldrb r1, [r3, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r3, #0x16]
_0809BBF0:
	pop {r0}
	bx r0
	.align 2, 0
_0809BBF4: .4byte 0x040000D4
_0809BBF8: .4byte 0x0868161C
_0809BBFC: .4byte 0x05000220
_0809BC00: .4byte 0x84000008

	thumb_func_start unk_9bc04
unk_9bc04: @ 0x0809BC04
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x14]
	cmp r0, #0
	bne _0809BC1C
	ldrh r0, [r3]
	strh r0, [r3, #6]
	ldrh r0, [r3, #2]
	strh r0, [r3, #8]
	movs r0, #1
	strb r0, [r3, #0x14]
	b _0809BC42
_0809BC1C:
	cmp r0, #1
	bne _0809BC42
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldrh r1, [r3, #0xe]
	movs r0, #0xb
	muls r0, r1, r0
	lsrs r0, r0, #6
	ldrh r1, [r3, #6]
	adds r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r3, #0xe]
	lsls r1, r0, #3
	adds r1, r1, r0
	asrs r1, r1, #6
	ldrh r0, [r3, #8]
	subs r0, r0, r1
	strh r0, [r3, #2]
_0809BC42:
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bne _0809BC64
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrh r0, [r3, #4]
	subs r0, #2
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0809BC64
	movs r0, #2
	strh r0, [r3, #4]
_0809BC64:
	ldrh r0, [r3, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne _0809BC9E
	strh r1, [r3, #0xa]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0809BC86
	strh r1, [r3, #0xc]
_0809BC86:
	ldr r2, _0809BCCC @ =0x040000D4
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	lsls r0, r0, #5
	ldr r1, _0809BCD0 @ =0x0868141C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0809BCD4 @ =0x05000200
	str r0, [r2, #4]
	ldr r0, _0809BCD8 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0809BC9E:
	ldrh r0, [r3]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809BCBC
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809BCBC
	cmp r1, #0xb0
	ble _0809BCC8
_0809BCBC:
	movs r0, #0
	strb r0, [r3, #0x10]
	ldrb r1, [r3, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r3, #0x16]
_0809BCC8:
	pop {r0}
	bx r0
	.align 2, 0
_0809BCCC: .4byte 0x040000D4
_0809BCD0: .4byte 0x0868141C
_0809BCD4: .4byte 0x05000200
_0809BCD8: .4byte 0x84000008

	thumb_func_start unk_9bcdc
unk_9bcdc: @ 0x0809BCDC
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x14]
	cmp r0, #0
	bne _0809BD00
	ldr r1, _0809BCFC @ =0x04000018
	ldrh r0, [r3]
	strh r0, [r1]
	ldrh r0, [r3]
	strh r0, [r3, #6]
	ldrh r0, [r3, #2]
	strh r0, [r3, #8]
	movs r0, #1
	strb r0, [r3, #0x14]
	b _0809BD1C
	.align 2, 0
_0809BCFC: .4byte 0x04000018
_0809BD00:
	cmp r0, #1
	bne _0809BD1C
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r2, _0809BD20 @ =0x04000018
	movs r0, #0xc
	ldrsh r1, [r3, r0]
	ldrh r0, [r3, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2]
_0809BD1C:
	pop {r0}
	bx r0
	.align 2, 0
_0809BD20: .4byte 0x04000018

	thumb_func_start unk_9bd24
unk_9bd24: @ 0x0809BD24
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x14]
	cmp r0, #0
	bne _0809BD3C
	ldrh r0, [r3]
	strh r0, [r3, #6]
	ldrh r0, [r3, #2]
	strh r0, [r3, #8]
	movs r0, #1
	strb r0, [r3, #0x14]
	b _0809BD5A
_0809BD3C:
	cmp r0, #1
	bne _0809BD5A
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldrh r1, [r3, #0xe]
	lsrs r1, r1, #3
	ldrh r0, [r3, #6]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r3, #0xe]
	lsrs r0, r0, #4
	ldrh r1, [r3, #8]
	adds r0, r0, r1
	strh r0, [r3, #2]
_0809BD5A:
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0809BD7E
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrh r0, [r3, #4]
	subs r0, #4
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _0809BD7E
	movs r0, #2
	strh r0, [r3, #4]
_0809BD7E:
	ldrh r0, [r3, #0xa]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0809BDB8
	strh r1, [r3, #0xa]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0809BDA0
	strh r1, [r3, #0xc]
_0809BDA0:
	ldr r2, _0809BDE8 @ =0x040000D4
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	lsls r0, r0, #5
	ldr r1, _0809BDEC @ =0x0868181C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0809BDF0 @ =0x05000260
	str r0, [r2, #4]
	ldr r0, _0809BDF4 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_0809BDB8:
	ldrh r0, [r3]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809BDD6
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809BDD6
	cmp r1, #0xb0
	ble _0809BDE2
_0809BDD6:
	movs r0, #0
	strb r0, [r3, #0x10]
	ldrb r1, [r3, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r3, #0x16]
_0809BDE2:
	pop {r0}
	bx r0
	.align 2, 0
_0809BDE8: .4byte 0x040000D4
_0809BDEC: .4byte 0x0868181C
_0809BDF0: .4byte 0x05000260
_0809BDF4: .4byte 0x84000008

	thumb_func_start unk_9bdf8
unk_9bdf8: @ 0x0809BDF8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _0809BE10
	ldrh r0, [r2]
	strh r0, [r2, #6]
	ldrh r0, [r2, #2]
	strh r0, [r2, #8]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _0809BE3A
_0809BE10:
	cmp r0, #1
	bne _0809BE3A
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #6]
	adds r0, r0, r1
	strh r0, [r2]
	movs r0, #0xa
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
_0809BE3A:
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _0809BE5E
	movs r0, #0
	strb r0, [r2, #0x13]
	ldrh r0, [r2, #4]
	subs r0, #4
	strh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bgt _0809BE5E
	movs r0, #2
	strh r0, [r2, #4]
_0809BE5E:
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809BE7C
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809BE7C
	cmp r1, #0xb0
	ble _0809BE88
_0809BE7C:
	movs r0, #0
	strb r0, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r2, #0x16]
_0809BE88:
	pop {r0}
	bx r0

	thumb_func_start unk_9be8c
unk_9be8c: @ 0x0809BE8C
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x14]
	cmp r0, #0
	bne _0809BEBC
	ldr r1, _0809BEAC @ =0x040000D4
	ldr r0, _0809BEB0 @ =0x0868101C
	str r0, [r1]
	ldr r0, _0809BEB4 @ =0x05000120
	str r0, [r1, #4]
	ldr r0, _0809BEB8 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #1
	strb r0, [r3, #0x14]
	b _0809BF46
	.align 2, 0
_0809BEAC: .4byte 0x040000D4
_0809BEB0: .4byte 0x0868101C
_0809BEB4: .4byte 0x05000120
_0809BEB8: .4byte 0x84000008
_0809BEBC:
	cmp r0, #1
	bne _0809BF14
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _0809BF46
	movs r0, #0
	strb r0, [r3, #0x13]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	ble _0809BEE8
	movs r0, #0xf
	strh r0, [r3, #0xc]
	movs r0, #2
	strb r0, [r3, #0x14]
_0809BEE8:
	ldr r2, _0809BF04 @ =0x040000D4
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	lsls r0, r0, #5
	ldr r1, _0809BF08 @ =0x0868101C
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0809BF0C @ =0x05000120
	str r0, [r2, #4]
	ldr r0, _0809BF10 @ =0x84000008
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	b _0809BF46
	.align 2, 0
_0809BF04: .4byte 0x040000D4
_0809BF08: .4byte 0x0868101C
_0809BF0C: .4byte 0x05000120
_0809BF10: .4byte 0x84000008
_0809BF14:
	cmp r0, #2
	bne _0809BF46
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _0809BF46
	movs r0, #0
	strb r0, [r3, #0x13]
	ldr r1, _0809BF4C @ =gWrittenToBldalpha_Eva
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0809BF46
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0809BF46
	ldr r1, _0809BF50 @ =gWrittenToBldalpha_Evb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0809BF46:
	pop {r0}
	bx r0
	.align 2, 0
_0809BF4C: .4byte gWrittenToBldalpha_Eva
_0809BF50: .4byte gWrittenToBldalpha_Evb

	thumb_func_start unk_9bf54
unk_9bf54: @ 0x0809BF54
	push {lr}
	adds r3, r0, #0
	ldrb r0, [r3, #0x13]
	adds r0, #1
	strb r0, [r3, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0809BF7E
	movs r0, #0
	strb r0, [r3, #0x13]
	ldr r1, _0809BFAC @ =gNonGameplayRam
	ldrh r0, [r1, #0xa]
	adds r0, #2
	strh r0, [r1, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble _0809BF7E
	movs r0, #0xa0
	strh r0, [r1, #0xa]
_0809BF7E:
	ldrb r0, [r3, #0x12]
	adds r0, #1
	strb r0, [r3, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bne _0809BF90
	movs r0, #0
	strb r0, [r3, #0x12]
_0809BF90:
	ldr r1, _0809BFB0 @ =0x04000014
	ldr r2, _0809BFB4 @ =sRandomNumberTable
	ldrb r0, [r3, #0x12]
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	adds r1, #2
	ldrb r0, [r3, #0x12]
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809BFAC: .4byte gNonGameplayRam
_0809BFB0: .4byte 0x04000014
_0809BFB4: .4byte sRandomNumberTable

	thumb_func_start unk_9bfb8
unk_9bfb8: @ 0x0809BFB8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _0809BFD0
	ldrh r0, [r2]
	strh r0, [r2, #6]
	ldrh r0, [r2, #2]
	strh r0, [r2, #8]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _0809BFFA
_0809BFD0:
	cmp r0, #1
	bne _0809BFFA
	ldrh r0, [r2, #0xe]
	adds r0, #1
	strh r0, [r2, #0xe]
	movs r0, #0xc
	ldrsh r1, [r2, r0]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #6]
	adds r0, r0, r1
	strh r0, [r2]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	ldrh r0, [r2, #0xe]
	muls r0, r1, r0
	asrs r0, r0, #6
	ldrh r1, [r2, #8]
	adds r0, r0, r1
	strh r0, [r2, #2]
_0809BFFA:
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0809C018
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0809C018
	cmp r1, #0xb0
	ble _0809C024
_0809C018:
	movs r0, #0
	strb r0, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	subs r0, #2
	ands r0, r1
	strb r0, [r2, #0x16]
_0809C024:
	ldrb r0, [r2, #0x11]
	lsls r0, r0, #3
	ldr r1, [r2, #0x1c]
	adds r1, r1, r0
	ldrb r0, [r1, #4]
	ldrb r3, [r2, #0x12]
	cmp r0, r3
	bne _0809C046
	ldrb r1, [r1, #0xc]
	cmp r1, #0
	bne _0809C046
	strb r1, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #0x16]
_0809C046:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start unk_9c04c
unk_9c04c: @ 0x0809C04C
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x28
	bne _0809C070
	movs r0, #0
	strb r0, [r2, #0x13]
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	ble _0809C070
	subs r0, r1, #1
	strh r0, [r2]
_0809C070:
	ldr r1, _0809C07C @ =0x04000018
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809C07C: .4byte 0x04000018

	thumb_func_start unk_9c080
unk_9c080: @ 0x0809C080
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
	bl CutsceneRestrictedLabDetachingSetupOam
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0809C0B0 @ =gNonGameplayRam
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	strh r4, [r1, #0x24]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809C0B0: .4byte gNonGameplayRam

	thumb_func_start unk_9c0b4
unk_9c0b4: @ 0x0809C0B4
	push {r4, r5, lr}
	adds r5, r3, #0
	ldr r4, [sp, #0xc]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	bl CutsceneRestrictedLabDetachingSetupOam
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0809C0EC @ =gNonGameplayRam
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	strh r4, [r1, #0x22]
	strh r5, [r1, #0x24]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809C0EC: .4byte gNonGameplayRam

	thumb_func_start CutsceneRestrictedLabDetachingGetPositionOfOamByType
CutsceneRestrictedLabDetachingGetPositionOfOamByType: @ 0x0809C0F0
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0
	ldr r6, _0809C118 @ =gNonGameplayRam
_0809C0FC:
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r6
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, r5
	bne _0809C11C
	ldrh r0, [r3, #0x18]
	strh r0, [r4]
	ldrh r0, [r3, #0x1a]
	b _0809C130
	.align 2, 0
_0809C118: .4byte gNonGameplayRam
_0809C11C:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xf
	bls _0809C0FC
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	strh r0, [r4]
	movs r0, #0xc8
_0809C130:
	strh r0, [r2]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start CutsceneRestrictedLabDetachingVblank
CutsceneRestrictedLabDetachingVblank: @ 0x0809C138
	push {lr}
	ldr r3, _0809C18C @ =0x040000D4
	ldr r0, _0809C190 @ =gOamData
	str r0, [r3]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r3, #4]
	ldr r0, _0809C194 @ =0x84000100
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r2, _0809C198 @ =0x04000052
	ldr r0, _0809C19C @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _0809C1A0 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0809C1A4 @ =0x04000054
	ldr r0, _0809C1A8 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809C1AC @ =gNonGameplayRam
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	cmp r0, #1
	bne _0809C188
	movs r0, #0
	strh r0, [r1, #0xa]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	ldr r1, _0809C1B0 @ =0x0868101C
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _0809C1B4 @ =0x05000120
	str r0, [r3, #4]
	ldr r0, _0809C1B8 @ =0x84000008
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_0809C188:
	pop {r0}
	bx r0
	.align 2, 0
_0809C18C: .4byte 0x040000D4
_0809C190: .4byte gOamData
_0809C194: .4byte 0x84000100
_0809C198: .4byte 0x04000052
_0809C19C: .4byte gWrittenToBldalpha_Evb
_0809C1A0: .4byte gWrittenToBldalpha_Eva
_0809C1A4: .4byte 0x04000054
_0809C1A8: .4byte gWrittenToBldy
_0809C1AC: .4byte gNonGameplayRam
_0809C1B0: .4byte 0x0868101C
_0809C1B4: .4byte 0x05000120
_0809C1B8: .4byte 0x84000008

	thumb_func_start unk_9c1bc
unk_9c1bc: @ 0x0809C1BC
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneBslExploding
CutsceneBslExploding: @ 0x0809C1C8
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, _0809C1E0 @ =gNonGameplayRam
	ldrh r0, [r4]
	cmp r0, #1
	beq _0809C1F8
	cmp r0, #1
	bgt _0809C1E4
	cmp r0, #0
	beq _0809C1EE
	b _0809C246
	.align 2, 0
_0809C1E0: .4byte gNonGameplayRam
_0809C1E4:
	cmp r0, #2
	beq _0809C220
	cmp r0, #3
	beq _0809C238
	b _0809C246
_0809C1EE:
	movs r0, #1
	strh r0, [r4]
	bl CutsceneBslExplodingInit
	b _0809C246
_0809C1F8:
	ldr r5, _0809C218 @ =gWrittenToBldy
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _0809C206
	ldr r0, _0809C21C @ =0x00000247
	bl SoundPlay_3b1c
_0809C206:
	bl CutsceneFadeIn
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809C246
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0809C246
	.align 2, 0
_0809C218: .4byte gWrittenToBldy
_0809C21C: .4byte 0x00000247
_0809C220:
	bl CutsceneBslExplodingProcess
	cmp r0, #0
	beq _0809C246
	movs r0, #3
	strh r0, [r4]
	ldr r1, _0809C234 @ =0x04000050
	movs r0, #0xbf
	strh r0, [r1]
	b _0809C246
	.align 2, 0
_0809C234: .4byte 0x04000050
_0809C238:
	bl CutsceneFadeOut
	ldr r0, _0809C250 @ =gWrittenToBldy
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _0809C246
	movs r6, #1
_0809C246:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809C250: .4byte gWrittenToBldy

	thumb_func_start CutsceneBslExplodingInit
CutsceneBslExplodingInit: @ 0x0809C254
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r3, _0809C360 @ =0x04000208
	movs r5, #0
	strh r5, [r3]
	ldr r2, _0809C364 @ =0x04000004
	ldrh r1, [r2]
	ldr r0, _0809C368 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0809C36C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _0809C370 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0809C374 @ =unk_9c92c
	bl CallbackSetVBlank
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	strh r5, [r0]
	ldr r0, _0809C378 @ =0x0867D7CC
	ldr r1, _0809C37C @ =0x06010000
	bl LZ77UncompVram
	ldr r4, _0809C380 @ =0x040000D4
	ldr r0, _0809C384 @ =0x0868121C
	str r0, [r4]
	ldr r0, _0809C388 @ =0x05000200
	str r0, [r4, #4]
	ldr r6, _0809C38C @ =0x84000080
	str r6, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0809C390 @ =0x08679420
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UncompVram
	ldr r0, _0809C394 @ =0x08681A1C
	ldr r1, _0809C398 @ =0x0600E000
	bl LZ77UncompVram
	ldr r0, _0809C39C @ =0x086820A4
	ldr r1, _0809C3A0 @ =0x0600E800
	bl LZ77UncompVram
	ldr r0, _0809C3A4 @ =0x086827A8
	ldr r1, _0809C3A8 @ =0x0600F000
	bl LZ77UncompVram
	ldr r0, _0809C3AC @ =0x08682BFC
	ldr r1, _0809C3B0 @ =0x0600F800
	bl LZ77UncompVram
	ldr r0, _0809C3B4 @ =0x0868259C
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	str r6, [r4, #8]
	ldr r1, [r4, #8]
	strh r5, [r0]
	ldr r1, _0809C3B8 @ =0x04000008
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0809C3BC @ =0x00001D03
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0xfd
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0809C3C0 @ =0x00001F03
	adds r0, r2, #0
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, _0809C3C4 @ =gWrittenToBldy
	movs r2, #0x10
	strh r2, [r0]
	ldr r1, _0809C3C8 @ =gWrittenToBldalpha_Eva
	movs r0, #8
	strh r0, [r1]
	ldr r0, _0809C3CC @ =gWrittenToBldalpha_Evb
	strh r2, [r0]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl CutsceneBslExplodingSetupOam
	movs r0, #0x14
	movs r1, #0x70
	movs r2, #0x58
	movs r3, #0
	bl CutsceneBslExplodingSetupOam
	ldr r0, _0809C3D0 @ =gNonGameplayRam
	movs r1, #0
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	movs r1, #0xc
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r1, _0809C3D4 @ =0x0868101C
	adds r0, r0, r1
	str r0, [r4]
	ldr r0, _0809C3D8 @ =0x05000120
	str r0, [r4, #4]
	ldr r0, _0809C3DC @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	bl CutsceneDrawAllOam
	ldr r0, _0809C3E0 @ =CutsceneBslExplodingVblank
	bl CallbackSetVBlank
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C360: .4byte 0x04000208
_0809C364: .4byte 0x04000004
_0809C368: .4byte 0x0000FFEF
_0809C36C: .4byte 0x04000200
_0809C370: .4byte 0x0000FFFD
_0809C374: .4byte unk_9c92c
_0809C378: .4byte 0x0867D7CC
_0809C37C: .4byte 0x06010000
_0809C380: .4byte 0x040000D4
_0809C384: .4byte 0x0868121C
_0809C388: .4byte 0x05000200
_0809C38C: .4byte 0x84000080
_0809C390: .4byte 0x08679420
_0809C394: .4byte 0x08681A1C
_0809C398: .4byte 0x0600E000
_0809C39C: .4byte 0x086820A4
_0809C3A0: .4byte 0x0600E800
_0809C3A4: .4byte 0x086827A8
_0809C3A8: .4byte 0x0600F000
_0809C3AC: .4byte 0x08682BFC
_0809C3B0: .4byte 0x0600F800
_0809C3B4: .4byte 0x0868259C
_0809C3B8: .4byte 0x04000008
_0809C3BC: .4byte 0x00001D03
_0809C3C0: .4byte 0x00001F03
_0809C3C4: .4byte gWrittenToBldy
_0809C3C8: .4byte gWrittenToBldalpha_Eva
_0809C3CC: .4byte gWrittenToBldalpha_Evb
_0809C3D0: .4byte gNonGameplayRam
_0809C3D4: .4byte 0x0868101C
_0809C3D8: .4byte 0x05000120
_0809C3DC: .4byte 0x84000008
_0809C3E0: .4byte CutsceneBslExplodingVblank

	thumb_func_start CutsceneBslExplodingProcess
CutsceneBslExplodingProcess: @ 0x0809C3E4
	push {r4, r5, lr}
	movs r5, #0
	ldr r1, _0809C404 @ =gNonGameplayRam
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	ldrb r0, [r1, #0x10]
	adds r4, r1, #0
	cmp r0, #6
	bls _0809C3FA
	b _0809C5E2
_0809C3FA:
	lsls r0, r0, #2
	ldr r1, _0809C408 @ =_0809C40C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0809C404: .4byte gNonGameplayRam
_0809C408: .4byte _0809C40C
_0809C40C: @ jump table
	.4byte _0809C428 @ case 0
	.4byte _0809C432 @ case 1
	.4byte _0809C464 @ case 2
	.4byte _0809C4CC @ case 3
	.4byte _0809C4FC @ case 4
	.4byte _0809C52C @ case 5
	.4byte _0809C5B4 @ case 6
_0809C428:
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #0x10]
	b _0809C5E2
_0809C432:
	ldrh r0, [r4, #8]
	cmp r0, #0xf
	beq _0809C43A
	b _0809C5E2
_0809C43A:
	ldr r1, _0809C45C @ =0x04000050
	ldr r2, _0809C460 @ =0x00001C44
	adds r0, r2, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #2
	strb r0, [r4, #0x10]
	b _0809C5E2
	.align 2, 0
_0809C45C: .4byte 0x04000050
_0809C460: .4byte 0x00001C44
_0809C464:
	ldr r2, _0809C484 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	cmp r1, #0xf
	bhi _0809C48C
	ldrh r0, [r4, #8]
	cmp r0, #1
	bne _0809C47A
	movs r0, #0
	strh r0, [r4, #8]
	adds r0, r1, #2
	strh r0, [r2]
_0809C47A:
	ldr r1, _0809C488 @ =gWrittenToBldy
	movs r0, #0x10
	strh r0, [r1]
	b _0809C5E2
	.align 2, 0
_0809C484: .4byte gWrittenToBldalpha_Eva
_0809C488: .4byte gWrittenToBldy
_0809C48C:
	ldrh r0, [r4, #8]
	cmp r0, #0x28
	beq _0809C494
	b _0809C5E2
_0809C494:
	ldr r1, _0809C4C8 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	subs r1, #0x50
	movs r2, #0x90
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #1
	bl CutsceneDestroyOamOfType
	movs r0, #0x14
	bl CutsceneDestroyOamOfType
	movs r0, #0x15
	movs r1, #0x78
	movs r2, #0x5a
	movs r3, #1
	bl CutsceneBslExplodingSetupOam
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #3
	strb r0, [r4, #0x10]
	b _0809C5E2
	.align 2, 0
_0809C4C8: .4byte 0x04000050
_0809C4CC:
	ldrh r0, [r4, #8]
	cmp r0, #1
	beq _0809C4D4
	b _0809C5E2
_0809C4D4:
	ldr r1, _0809C4F0 @ =gWrittenToBldy
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0809C4F4 @ =gWrittenToBldalpha_Eva
	movs r1, #0xa
	strh r1, [r0]
	ldr r0, _0809C4F8 @ =gWrittenToBldalpha_Evb
	strh r1, [r0]
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #4
	strb r0, [r4, #0x10]
	b _0809C5E2
	.align 2, 0
_0809C4F0: .4byte gWrittenToBldy
_0809C4F4: .4byte gWrittenToBldalpha_Eva
_0809C4F8: .4byte gWrittenToBldalpha_Evb
_0809C4FC:
	ldrh r0, [r4, #8]
	cmp r0, #0x3c
	bne _0809C5E2
	ldr r1, _0809C524 @ =0x04000050
	ldr r3, _0809C528 @ =0x00001E41
	adds r0, r3, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #5
	strb r0, [r4, #0x10]
	b _0809C5E2
	.align 2, 0
_0809C524: .4byte 0x04000050
_0809C528: .4byte 0x00001E41
_0809C52C:
	ldrh r1, [r4, #0xc]
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #0xe
	bgt _0809C59A
	ldrh r0, [r4, #8]
	cmp r0, #4
	bne _0809C5E2
	movs r0, #0
	strh r0, [r4, #8]
	movs r0, #1
	strh r0, [r4, #0xa]
	adds r0, r1, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _0809C570
	movs r0, #0x16
	movs r1, #0x78
	movs r2, #0x60
	movs r3, #0
	bl CutsceneBslExplodingSetupOam
	movs r0, #0x16
	movs r1, #0x5f
	movs r2, #0x50
	movs r3, #0
	bl CutsceneBslExplodingSetupOam
	movs r0, #0x16
	movs r1, #0x8c
	movs r2, #0x69
	b _0809C592
_0809C570:
	cmp r0, #2
	bne _0809C588
	movs r0, #0x16
	movs r1, #0x78
	movs r2, #0x54
	movs r3, #0
	bl CutsceneBslExplodingSetupOam
	movs r0, #0x16
	movs r1, #0x91
	movs r2, #0x55
	b _0809C592
_0809C588:
	cmp r0, #3
	bne _0809C5E2
	movs r0, #0x16
	movs r1, #0x60
	movs r2, #0x6a
_0809C592:
	movs r3, #0
	bl CutsceneBslExplodingSetupOam
	b _0809C5E2
_0809C59A:
	ldrh r0, [r4, #8]
	cmp r0, #0xf
	bne _0809C5E2
	movs r0, #0
	strh r0, [r4, #8]
	ldr r1, _0809C5B0 @ =gWrittenToBldy
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #6
	strb r0, [r4, #0x10]
	b _0809C5E2
	.align 2, 0
_0809C5B0: .4byte gWrittenToBldy
_0809C5B4:
	ldr r2, _0809C5CC @ =gWrittenToBldalpha_Eva
	ldrh r1, [r2]
	cmp r1, #0xf
	bhi _0809C5D0
	ldrh r0, [r4, #8]
	cmp r0, #6
	bne _0809C5E2
	movs r0, #0
	strh r0, [r4, #8]
	adds r0, r1, #1
	strh r0, [r2]
	b _0809C5E2
	.align 2, 0
_0809C5CC: .4byte gWrittenToBldalpha_Eva
_0809C5D0:
	ldr r0, _0809C5F4 @ =0x04000050
	movs r1, #0xbf
	strh r1, [r0]
	ldrh r0, [r4, #8]
	cmp r0, #0x10
	bne _0809C5E2
	movs r0, #0
	strh r0, [r4, #8]
	movs r5, #1
_0809C5E2:
	bl CutsceneProcessOam
	bl CutsceneDrawAllOam
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809C5F4: .4byte 0x04000050

	thumb_func_start CutsceneBslExplodingProcessScrolling
CutsceneBslExplodingProcessScrolling: @ 0x0809C5F8
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x13]
	adds r0, #1
	strb r0, [r2, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bne _0809C614
	movs r0, #0
	strb r0, [r2, #0x13]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0809C614:
	ldr r1, _0809C620 @ =0x0400001C
	ldrh r0, [r2]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0809C620: .4byte 0x0400001C

	thumb_func_start CutsceneBslExplodingProcessBslFar
CutsceneBslExplodingProcessBslFar: @ 0x0809C624
	push {r4, lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x14]
	cmp r1, #0
	bne _0809C654
	ldr r3, _0809C64C @ =gNonGameplayRam
	ldrb r0, [r3, #0x10]
	cmp r0, #5
	bne _0809C67A
	movs r4, #0xc
	ldrsh r0, [r3, r4]
	cmp r0, #5
	bne _0809C67A
	strb r1, [r2, #0x12]
	strb r1, [r2, #0x11]
	ldr r0, _0809C650 @ =0x08680ECC
	str r0, [r2, #0x1c]
	movs r0, #1
	strb r0, [r2, #0x14]
	b _0809C67A
	.align 2, 0
_0809C64C: .4byte gNonGameplayRam
_0809C650: .4byte 0x08680ECC
_0809C654:
	cmp r1, #1
	bne _0809C67A
	ldrb r0, [r2, #0x11]
	lsls r0, r0, #3
	ldr r1, [r2, #0x1c]
	adds r1, r1, r0
	ldrb r0, [r1, #4]
	ldrb r3, [r2, #0x12]
	cmp r0, r3
	bne _0809C67A
	ldrb r1, [r1, #0xc]
	cmp r1, #0
	bne _0809C67A
	strb r1, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #0x16]
_0809C67A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start CutsceneBslExplodingProcessExplosions
CutsceneBslExplodingProcessExplosions: @ 0x0809C680
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #0x11]
	lsls r0, r0, #3
	ldr r1, [r2, #0x1c]
	adds r1, r1, r0
	ldrb r0, [r1, #4]
	ldrb r3, [r2, #0x12]
	cmp r0, r3
	bne _0809C6A6
	ldrb r1, [r1, #0xc]
	cmp r1, #0
	bne _0809C6A6
	strb r1, [r2, #0x10]
	ldrb r1, [r2, #0x16]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #0x16]
_0809C6A6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneBslExplodingSetupOam
CutsceneBslExplodingSetupOam: @ 0x0809C6AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x18
	cmp r3, #0
	bne _0809C708
	movs r2, #0
	ldr r1, _0809C704 @ =gNonGameplayRam
	adds r0, r1, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809C6F8
	adds r3, r1, #0
_0809C6D8:
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0xf
	bgt _0809C742
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C6D8
_0809C6F8:
	lsls r0, r2, #0x18
	asrs r1, r0, #0x18
	adds r6, r0, #0
	cmp r1, #0xf
	ble _0809C74C
	b _0809C742
	.align 2, 0
_0809C704: .4byte gNonGameplayRam
_0809C708:
	movs r2, #0xf
	ldr r1, _0809C748 @ =gNonGameplayRam
	movs r3, #0x91
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809C73A
	adds r3, r1, #0
_0809C71A:
	lsls r0, r2, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	blt _0809C742
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C71A
_0809C73A:
	lsls r0, r2, #0x18
	adds r6, r0, #0
	cmp r6, #0
	bge _0809C74C
_0809C742:
	movs r0, #0x10
	b _0809C83A
	.align 2, 0
_0809C748: .4byte gNonGameplayRam
_0809C74C:
	movs r0, #0
	str r0, [sp]
	ldr r2, _0809C7A0 @ =0x040000D4
	mov r3, sp
	str r3, [r2]
	asrs r1, r6, #0x18
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r4, r0, #2
	ldr r0, _0809C7A4 @ =0x0300149C
	mov ip, r0
	adds r0, r4, r0
	str r0, [r2, #4]
	ldr r0, _0809C7A8 @ =0x85000009
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	mov r0, ip
	subs r0, #0x18
	adds r2, r4, r0
	mov r1, r8
	strh r1, [r2, #0x18]
	strh r7, [r2, #0x1a]
	adds r0, r2, #0
	adds r0, #0x28
	strb r5, [r0]
	adds r3, r2, #0
	adds r3, #0x2e
	ldrb r1, [r3]
	movs r0, #1
	orrs r1, r0
	strb r1, [r3]
	cmp r5, #1
	bne _0809C7B0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r3]
	mov r0, ip
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809C7AC @ =CutsceneBslExplodingProcessScrolling
	b _0809C836
	.align 2, 0
_0809C7A0: .4byte 0x040000D4
_0809C7A4: .4byte 0x0300149C
_0809C7A8: .4byte 0x85000009
_0809C7AC: .4byte CutsceneBslExplodingProcessScrolling
_0809C7B0:
	cmp r5, #0x14
	bne _0809C7E0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809C7D8 @ =0x08680FFC
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809C7DC @ =unk_9db70
	b _0809C836
	.align 2, 0
_0809C7D8: .4byte 0x08680FFC
_0809C7DC: .4byte unk_9db70
_0809C7E0:
	cmp r5, #0x15
	bne _0809C810
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809C808 @ =0x0868100C
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809C80C @ =CutsceneBslExplodingProcessBslFar
	b _0809C836
	.align 2, 0
_0809C808: .4byte 0x0868100C
_0809C80C: .4byte CutsceneBslExplodingProcessBslFar
_0809C810:
	cmp r5, #0x16
	bne _0809C838
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r1, _0809C848 @ =0x08680ECC
	str r1, [r0]
	mov r0, ip
	adds r0, #0x20
	adds r0, r4, r0
	ldr r1, _0809C84C @ =CutsceneBslExplodingProcessExplosions
_0809C836:
	str r1, [r0]
_0809C838:
	lsrs r0, r6, #0x18
_0809C83A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809C848: .4byte 0x08680ECC
_0809C84C: .4byte CutsceneBslExplodingProcessExplosions

	thumb_func_start CutsceneBslExplodingGetOamInfoByType
CutsceneBslExplodingGetOamInfoByType: @ 0x0809C850
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r2, #0
	ldr r7, _0809C880 @ =gNonGameplayRam
_0809C85E:
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, r6
	bne _0809C884
	ldrh r0, [r1, #0x18]
	strh r0, [r4]
	ldrh r0, [r1, #0x1a]
	strh r0, [r5]
	ldrh r0, [r1, #0x1c]
	strh r0, [r3]
	adds r0, r2, #0
	b _0809C8A2
	.align 2, 0
_0809C880: .4byte gNonGameplayRam
_0809C884:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _0809C85E
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	strh r0, [r4]
	movs r0, #0xc8
	strh r0, [r5]
	subs r1, #0x2c
	adds r0, r1, #0
	strh r0, [r3]
	movs r0, #0
_0809C8A2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start CutsceneBslExplodingVblank
CutsceneBslExplodingVblank: @ 0x0809C8A8
	push {lr}
	ldr r3, _0809C8FC @ =0x040000D4
	ldr r0, _0809C900 @ =gOamData
	str r0, [r3]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r3, #4]
	ldr r0, _0809C904 @ =0x84000100
	str r0, [r3, #8]
	ldr r0, [r3, #8]
	ldr r2, _0809C908 @ =0x04000052
	ldr r0, _0809C90C @ =gWrittenToBldalpha_Evb
	ldrh r0, [r0]
	lsls r0, r0, #8
	ldr r1, _0809C910 @ =gWrittenToBldalpha_Eva
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0809C914 @ =0x04000054
	ldr r0, _0809C918 @ =gWrittenToBldy
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809C91C @ =gNonGameplayRam
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	cmp r0, #1
	bne _0809C8F8
	movs r0, #0
	strh r0, [r1, #0xa]
	movs r2, #0xc
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	ldr r1, _0809C920 @ =0x0868101C
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _0809C924 @ =0x05000120
	str r0, [r3, #4]
	ldr r0, _0809C928 @ =0x84000008
	str r0, [r3, #8]
	ldr r0, [r3, #8]
_0809C8F8:
	pop {r0}
	bx r0
	.align 2, 0
_0809C8FC: .4byte 0x040000D4
_0809C900: .4byte gOamData
_0809C904: .4byte 0x84000100
_0809C908: .4byte 0x04000052
_0809C90C: .4byte gWrittenToBldalpha_Evb
_0809C910: .4byte gWrittenToBldalpha_Eva
_0809C914: .4byte 0x04000054
_0809C918: .4byte gWrittenToBldy
_0809C91C: .4byte gNonGameplayRam
_0809C920: .4byte 0x0868101C
_0809C924: .4byte 0x05000120
_0809C928: .4byte 0x84000008

	thumb_func_start unk_9c92c
unk_9c92c: @ 0x0809C92C
	push {lr}
	bl UpdateAudio
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start CutsceneMonologueProcessCursor
CutsceneMonologueProcessCursor: @ 0x0809C938
	push {lr}
	adds r2, r0, #0
	ldr r3, _0809C954 @ =gNonGameplayRam
	ldr r0, [r3, #0xc]
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809C958
	movs r0, #0
	strb r0, [r2, #4]
	strb r0, [r2, #5]
	b _0809C9F4
	.align 2, 0
_0809C954: .4byte gNonGameplayRam
_0809C958:
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r1, r0
	beq _0809C9E0
	movs r0, #0xfd
	lsls r0, r0, #8
	cmp r1, r0
	beq _0809C9C2
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809C9E0
	ldrb r1, [r2, #9]
	cmp r1, #0
	bne _0809C9B4
	ldr r0, _0809C990 @ =gChangedInput
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809C994
	movs r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r2]
	strb r1, [r2, #7]
	strb r1, [r2, #6]
	b _0809C9F4
	.align 2, 0
_0809C990: .4byte gChangedInput
_0809C994:
	ldr r0, _0809C9B0 @ =0x08663E74
	str r0, [r2, #0x10]
	movs r1, #0
	movs r0, #0x76
	strh r0, [r2]
	ldrh r0, [r3, #2]
	lsls r0, r0, #3
	adds r0, #0x18
	strh r0, [r2, #2]
	strb r1, [r2, #7]
	strb r1, [r2, #6]
	movs r0, #1
	strb r0, [r2, #9]
	b _0809C9F4
	.align 2, 0
_0809C9B0: .4byte 0x08663E74
_0809C9B4:
	cmp r1, #1
	bne _0809C9F4
	ldr r0, _0809C9D8 @ =gChangedInput
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0809C9F4
_0809C9C2:
	ldr r0, _0809C9DC @ =0x08663E5C
	str r0, [r2, #0x10]
	movs r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r2]
	strb r1, [r2, #7]
	strb r1, [r2, #6]
	strb r1, [r2, #9]
	b _0809C9F4
	.align 2, 0
_0809C9D8: .4byte gChangedInput
_0809C9DC: .4byte 0x08663E5C
_0809C9E0:
	ldrh r0, [r3]
	lsls r0, r0, #3
	ldrb r1, [r3, #0x18]
	adds r1, #0xc
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	lsls r0, r0, #3
	adds r0, #0xc
	strh r0, [r2, #2]
_0809C9F4:
	pop {r0}
	bx r0

	thumb_func_start CutsceneMonologueProcessSpecialTextCharacters
CutsceneMonologueProcessSpecialTextCharacters: @ 0x0809C9F8
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r0, _0809CA10 @ =gButtonInput
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809CA18
	ldr r1, _0809CA14 @ =gNonGameplayRam
	ldrh r0, [r1, #0x10]
	adds r0, #2
	b _0809CA1E
	.align 2, 0
_0809CA10: .4byte gButtonInput
_0809CA14: .4byte gNonGameplayRam
_0809CA18:
	ldr r1, _0809CA40 @ =gNonGameplayRam
	ldrh r0, [r1, #0x10]
	adds r0, #1
_0809CA1E:
	strh r0, [r1, #0x10]
	adds r5, r1, #0
	adds r3, r5, #0
	ldr r0, [r3, #0xc]
	ldrh r2, [r0]
	adds r1, r2, #0
	movs r4, #0xff
	lsls r4, r4, #8
	cmp r1, r4
	bne _0809CA44
	movs r0, #0
	strh r0, [r3, #0x10]
	movs r0, #0x64
	strb r0, [r3, #0x17]
	movs r6, #1
	b _0809CA92
	.align 2, 0
_0809CA40: .4byte gNonGameplayRam
_0809CA44:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809CA64
	ldr r0, _0809CA60 @ =gChangedInput
	ldrh r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0809CA80
	movs r1, #0
	movs r0, #1
	b _0809CA7E
	.align 2, 0
_0809CA60: .4byte gChangedInput
_0809CA64:
	adds r0, r4, #0
	ands r0, r2
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _0809CA84
	movs r0, #0xff
	ands r0, r2
	ldrh r1, [r3, #0x10]
	cmp r0, r1
	bhi _0809CA92
	movs r1, #0
	movs r0, #1
_0809CA7E:
	strb r0, [r3, #0x17]
_0809CA80:
	strh r1, [r3, #0x10]
	b _0809CA92
_0809CA84:
	ldrh r0, [r5, #0x10]
	cmp r0, #2
	bls _0809CA92
	movs r1, #0
	movs r0, #1
	strb r0, [r5, #0x17]
	strh r1, [r5, #0x10]
_0809CA92:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start CutsceneMonologueProcessText
CutsceneMonologueProcessText: @ 0x0809CA9C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, _0809CB04 @ =gNonGameplayRam
	ldr r2, [r5, #0xc]
	ldrh r3, [r2]
	adds r1, r3, #0
	movs r6, #0xff
	lsls r6, r6, #8
	adds r4, r5, #0
	cmp r1, r6
	bne _0809CAB4
	b _0809CC3A
_0809CAB4:
	movs r0, #0xfe
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809CB08
	ldrh r0, [r4]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1b
	bhi _0809CAEC
	adds r6, r4, #0
	adds r5, #0x1c
	movs r3, #0xff
_0809CACE:
	ldrh r1, [r6, #2]
	lsrs r1, r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r2, r0
	adds r0, r0, r5
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1b
	bls _0809CACE
_0809CAEC:
	movs r1, #0
	movs r0, #0
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, #2
	strh r0, [r4, #2]
	ldr r0, [r4, #0xc]
	adds r0, #2
	str r0, [r4, #0xc]
	strb r1, [r4, #0x18]
	b _0809CC3A
	.align 2, 0
_0809CB04: .4byte gNonGameplayRam
_0809CB08:
	movs r0, #0xfd
	lsls r0, r0, #8
	cmp r1, r0
	bne _0809CB84
	movs r2, #0
	str r2, [sp, #4]
	ldr r1, _0809CB6C @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	ldr r0, _0809CB70 @ =0x06008000
	str r0, [r1, #4]
	ldr r0, _0809CB74 @ =0x85001200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r3, #0
	strh r2, [r4, #6]
	strh r2, [r4, #4]
	strh r2, [r4, #2]
	strh r2, [r4]
	ldr r0, [r4, #0xc]
	adds r0, #2
	str r0, [r4, #0xc]
	strb r3, [r4, #0x18]
	str r2, [sp, #4]
	add r0, sp, #4
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x1c
	str r0, [r1, #4]
	ldr r3, _0809CB78 @ =0x8500003F
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	str r2, [sp, #4]
	add r2, sp, #4
	str r2, [r1]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r4, r2
	str r0, [r1, #4]
	str r3, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #0x12
	str r0, [r1]
	ldr r0, _0809CB7C @ =0x0600C800
	str r0, [r1, #4]
	ldr r0, _0809CB80 @ =0x84000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	b _0809CC3A
	.align 2, 0
_0809CB6C: .4byte 0x040000D4
_0809CB70: .4byte 0x06008000
_0809CB74: .4byte 0x85001200
_0809CB78: .4byte 0x8500003F
_0809CB7C: .4byte 0x0600C800
_0809CB80: .4byte 0x84000200
_0809CB84:
	movs r0, #0xfc
	lsls r0, r0, #8
	cmp r1, r0
	beq _0809CB98
	adds r0, r6, #0
	ands r0, r3
	movs r1, #0xe1
	lsls r1, r1, #8
	cmp r0, r1
	bne _0809CB9E
_0809CB98:
	adds r0, r2, #2
	str r0, [r4, #0xc]
	b _0809CC3A
_0809CB9E:
	ldrh r4, [r5]
	lsls r4, r4, #5
	ldrh r0, [r5, #2]
	lsls r0, r0, #0xa
	adds r4, r4, r0
	ldr r0, _0809CC44 @ =0x06008000
	adds r4, r4, r0
	ldrh r0, [r2]
	bl TextGetCharacterWidth
	adds r6, r0, #0
	ldr r0, [r5, #0xc]
	ldrh r0, [r0]
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r5, #0x18]
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	bl TextDrawCharacter
	ldrh r0, [r5]
	cmp r0, #0x1b
	bhi _0809CC32
	ldrh r1, [r5, #2]
	lsrs r1, r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r5]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldrb r0, [r5, #0x18]
	adds r0, r0, r6
	strb r0, [r5, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r5, #0
	cmp r0, #7
	bls _0809CC32
	adds r2, r4, #0
_0809CBF8:
	ldrb r0, [r2, #0x18]
	adds r1, r0, #0
	subs r1, #8
	strb r1, [r2, #0x18]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1b
	bhi _0809CC32
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0809CC2C
	ldrh r1, [r2, #2]
	lsrs r1, r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x1c
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
_0809CC2C:
	ldrb r0, [r2, #0x18]
	cmp r0, #7
	bhi _0809CBF8
_0809CC32:
	ldr r1, _0809CC48 @ =gNonGameplayRam
	ldr r0, [r1, #0xc]
	adds r0, #2
	str r0, [r1, #0xc]
_0809CC3A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809CC44: .4byte 0x06008000
_0809CC48: .4byte gNonGameplayRam

	thumb_func_start unk_9cc4c
unk_9cc4c: @ 0x0809CC4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r1, _0809CC8C @ =gNonGameplayRam
	ldrh r6, [r1, #4]
	ldrh r0, [r1, #6]
	lsrs r7, r0, #1
	ldrh r0, [r1, #2]
	lsrs r0, r0, #1
	str r1, [sp, #4]
	cmp r7, r0
	bls _0809CC6C
	b _0809CD70
_0809CC6C:
	str r1, [sp]
_0809CC6E:
	ldr r2, [sp]
	ldr r0, [r2, #0xc]
	ldrh r0, [r0]
	movs r3, #0xfc
	lsls r3, r3, #8
	cmp r0, r3
	bne _0809CC90
	ldrh r0, [r1]
	cmp r0, #0x1b
	bhi _0809CCAA
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	b _0809CCAE
	.align 2, 0
_0809CC8C: .4byte gNonGameplayRam
_0809CC90:
	ldrh r0, [r1, #2]
	lsrs r0, r0, #1
	cmp r7, r0
	bne _0809CCAA
	ldr r1, [sp]
	ldrh r0, [r1]
	movs r2, #0x1c
	mov ip, r2
	cmp r0, #0x1b
	bhi _0809CCAE
	adds r3, r0, #0
	mov ip, r3
	b _0809CCAE
_0809CCAA:
	movs r5, #0x1c
	mov ip, r5
_0809CCAE:
	adds r0, r7, #1
	str r0, [sp, #8]
	cmp r6, ip
	bhs _0809CD5C
	ldr r1, _0809CD24 @ =gNonGameplayRam
	mov r8, r1
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	mov sl, r0
	ldr r2, _0809CD28 @ =0x00000FFF
	mov sb, r2
_0809CCC6:
	mov r3, sl
	adds r2, r6, r3
	ldr r5, _0809CD2C @ =0x0300159C
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, #5
	bne _0809CD4E
	movs r0, #0
	strb r0, [r1]
	ldr r0, [sp, #4]
	adds r0, #0x1c
	adds r2, r2, r0
	ldrb r0, [r2]
	subs r1, r0, #1
	strb r1, [r2]
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble _0809CD38
	lsls r2, r6, #1
	lsls r0, r7, #7
	adds r2, r2, r0
	ldr r0, _0809CD30 @ =0x0600C842
	adds r0, r2, r0
	str r0, [sp, #0xc]
	ldr r1, _0809CD34 @ =0x0600C882
	adds r2, r2, r1
	ldrh r3, [r0]
	ldrh r4, [r2]
	lsrs r0, r3, #0xc
	lsrs r1, r4, #0xc
	subs r0, #1
	lsls r0, r0, #0x10
	subs r1, #1
	lsls r1, r1, #0x10
	lsrs r0, r0, #4
	mov r5, sb
	ands r3, r5
	orrs r0, r3
	ldr r3, [sp, #0xc]
	strh r0, [r3]
	lsrs r1, r1, #4
	ands r4, r5
	orrs r1, r4
	strh r1, [r2]
	b _0809CD52
	.align 2, 0
_0809CD24: .4byte gNonGameplayRam
_0809CD28: .4byte 0x00000FFF
_0809CD2C: .4byte 0x0300159C
_0809CD30: .4byte 0x0600C842
_0809CD34: .4byte 0x0600C882
_0809CD38:
	cmp r0, #0
	bne _0809CD46
	lsls r0, r7, #1
	mov r5, r8
	strh r0, [r5, #6]
	strh r6, [r5, #4]
	b _0809CD52
_0809CD46:
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
	b _0809CD5C
_0809CD4E:
	adds r0, #1
	strb r0, [r1]
_0809CD52:
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, ip
	blo _0809CCC6
_0809CD5C:
	movs r6, #0
	ldr r1, [sp, #8]
	lsls r0, r1, #0x10
	lsrs r7, r0, #0x10
	ldr r1, [sp, #4]
	ldrh r0, [r1, #2]
	lsrs r0, r0, #1
	cmp r7, r0
	bhi _0809CD70
	b _0809CC6E
_0809CD70:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start CutsceneMonologueFadeIn
CutsceneMonologueFadeIn: @ 0x0809CD80
	push {lr}
	bl CutsceneMonologueProcessOam
	bl CutsceneMonologueDrawAllOam
	ldr r3, _0809CDAC @ =gWrittenToBldy
	ldrh r2, [r3]
	adds r0, r2, #0
	cmp r0, #0
	beq _0809CDD0
	cmp r0, #0xb
	bls _0809CDB4
	ldr r1, _0809CDB0 @ =gNonGameplayRam
	ldrb r0, [r1, #0x16]
	adds r0, #1
	strb r0, [r1, #0x16]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0809CDD0
	b _0809CDC8
	.align 2, 0
_0809CDAC: .4byte gWrittenToBldy
_0809CDB0: .4byte gNonGameplayRam
_0809CDB4:
	cmp r0, #6
	bls _0809CDCC
	ldr r1, _0809CDD4 @ =gNonGameplayRam
	ldrb r0, [r1, #0x16]
	adds r0, #1
	strb r0, [r1, #0x16]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _0809CDD0
_0809CDC8:
	movs r0, #0
	strb r0, [r1, #0x16]
_0809CDCC:
	subs r0, r2, #1
	strh r0, [r3]
_0809CDD0:
	pop {r0}
	bx r0
	.align 2, 0
_0809CDD4: .4byte gNonGameplayRam

	thumb_func_start CutsceneMonologueFadeOut
CutsceneMonologueFadeOut: @ 0x0809CDD8
	push {lr}
	bl CutsceneMonologueProcessOam
	bl CutsceneMonologueDrawAllOam
	ldr r3, _0809CE04 @ =gWrittenToBldy
	ldrh r2, [r3]
	adds r0, r2, #0
	cmp r0, #0xf
	bhi _0809CE28
	cmp r0, #5
	bhi _0809CE0C
	ldr r1, _0809CE08 @ =gNonGameplayRam
	ldrb r0, [r1, #0x16]
	adds r0, #1
	strb r0, [r1, #0x16]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0809CE28
	b _0809CE20
	.align 2, 0
_0809CE04: .4byte gWrittenToBldy
_0809CE08: .4byte gNonGameplayRam
_0809CE0C:
	cmp r0, #0xa
	bhi _0809CE24
	ldr r1, _0809CE2C @ =gNonGameplayRam
	ldrb r0, [r1, #0x16]
	adds r0, #1
	strb r0, [r1, #0x16]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _0809CE28
_0809CE20:
	movs r0, #0
	strb r0, [r1, #0x16]
_0809CE24:
	adds r0, r2, #1
	strh r0, [r3]
_0809CE28:
	pop {r0}
	bx r0
	.align 2, 0
_0809CE2C: .4byte gNonGameplayRam

	thumb_func_start CutsceneMonologueProcessOam
CutsceneMonologueProcessOam: @ 0x0809CE30
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, _0809CE70 @ =gNonGameplayRam
	movs r0, #0x85
	lsls r0, r0, #2
	adds r6, r5, r0
_0809CE3C:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r2, r0, #3
	adds r0, r2, r5
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809CE60
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r1, r2, r1
	adds r0, r2, r6
	ldr r1, [r1]
	bl _call_via_r1
_0809CE60:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bls _0809CE3C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809CE70: .4byte gNonGameplayRam

	thumb_func_start CutsceneMonologueDrawAllOam
CutsceneMonologueDrawAllOam: @ 0x0809CE74
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, _0809CEB4 @ =gNonGameplayRam
	movs r0, #0x85
	lsls r0, r0, #2
	adds r6, r5, r0
_0809CE80:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r1, r0, #3
	adds r0, r1, r5
	ldr r2, _0809CEB8 @ =0x00000219
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809CE98
	adds r0, r1, r6
	bl CutsceneMnologueDrawOam
_0809CE98:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bls _0809CE80
	bl ResetFreeOam
	ldr r1, _0809CEBC @ =gNextOamSlot
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809CEB4: .4byte gNonGameplayRam
_0809CEB8: .4byte 0x00000219
_0809CEBC: .4byte gNextOamSlot

	thumb_func_start CutsceneMnologueDrawOam
CutsceneMnologueDrawOam: @ 0x0809CEC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r2, _0809CF80 @ =gNextOamSlot
	ldrb r0, [r2]
	lsls r0, r0, #3
	ldr r1, _0809CF84 @ =gOamData
	adds r7, r0, r1
	ldrb r4, [r5, #6]
	lsls r1, r4, #3
	ldr r0, [r5, #0x10]
	adds r3, r0, r1
	ldrb r0, [r3, #4]
	ldrb r2, [r5, #7]
	cmp r0, r2
	bne _0809CEF0
	adds r0, r4, #1
	movs r1, #0
	strb r0, [r5, #6]
	strb r1, [r5, #7]
	adds r3, #8
_0809CEF0:
	ldrb r1, [r3, #4]
	cmp r1, #0
	bne _0809CEFE
	ldrb r0, [r5, #6]
	lsls r0, r0, #3
	subs r3, r3, r0
	strb r1, [r5, #6]
_0809CEFE:
	ldr r6, [r3]
	ldrh r3, [r6]
	mov sl, r3
	adds r6, #2
	movs r4, #0
	mov sb, r4
	cmp sb, sl
	blt _0809CF10
	b _0809D014
_0809CF10:
	ldrh r0, [r6]
	mov r8, r0
	adds r6, #2
	ldrh r1, [r6]
	mov ip, r1
	adds r6, #2
	strh r0, [r7]
	adds r7, #2
	strh r1, [r7]
	adds r7, #2
	ldrh r0, [r6]
	strh r0, [r7]
	adds r6, #2
	adds r7, #2
	ldr r2, _0809CF80 @ =gNextOamSlot
	ldrb r0, [r2]
	mov r4, sb
	adds r3, r0, r4
	ldrb r1, [r5, #0xc]
	cmp r1, #1
	bne _0809CF90
	lsls r4, r3, #3
	ldr r0, _0809CF84 @ =gOamData
	adds r2, r4, r0
	ldrb r3, [r2, #3]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x1f
	eors r0, r1
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #4
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, #3]
	lsrs r1, r1, #6
	ldrb r0, [r2, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r2, _0809CF88 @ =0x0868279C
	adds r1, r1, r2
	ldrb r0, [r1]
	lsls r0, r0, #3
	add r0, ip
	ldrh r1, [r5]
	subs r2, r1, r0
	ldr r3, _0809CF8C @ =0x000001FF
	ands r2, r3
	ldrh r0, [r5, #2]
	mov r3, r8
	adds r1, r3, r0
	movs r0, #0xff
	ands r1, r0
	b _0809CFA6
	.align 2, 0
_0809CF80: .4byte gNextOamSlot
_0809CF84: .4byte gOamData
_0809CF88: .4byte 0x0868279C
_0809CF8C: .4byte 0x000001FF
_0809CF90:
	ldrh r0, [r5, #2]
	mov r4, r8
	adds r1, r4, r0
	movs r0, #0xff
	ands r1, r0
	ldrh r0, [r5]
	mov r4, ip
	adds r2, r4, r0
	ldr r0, _0809D030 @ =0x000001FF
	ands r2, r0
	lsls r4, r3, #3
_0809CFA6:
	ldr r0, _0809D034 @ =gOamData
	adds r3, r4, r0
	strb r1, [r3]
	ldr r1, _0809D030 @ =0x000001FF
	ands r2, r1
	ldrh r1, [r3, #2]
	ldr r0, _0809D038 @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	ldrb r1, [r5, #0xb]
	movs r2, #3
	ands r1, r2
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	lsrs r2, r0, #4
	ldrb r4, [r5, #0xd]
	adds r2, r2, r4
	lsls r2, r2, #4
	movs r1, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #5]
	ldrh r2, [r3, #4]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	ldrh r0, [r5, #0xe]
	adds r1, r1, r0
	ldr r4, _0809D03C @ =0x000003FF
	adds r0, r4, #0
	ands r1, r0
	ldr r0, _0809D040 @ =0xFFFFFC00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #4]
	ldrb r1, [r5, #0xa]
	movs r0, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #1]
	subs r0, #0x10
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #1]
	adds r7, #2
	movs r1, #1
	add sb, r1
	cmp sb, sl
	bge _0809D014
	b _0809CF10
_0809D014:
	ldr r2, _0809D044 @ =gNextOamSlot
	ldrb r0, [r2]
	add r0, sl
	strb r0, [r2]
	ldrb r0, [r5, #7]
	adds r0, #1
	strb r0, [r5, #7]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809D030: .4byte 0x000001FF
_0809D034: .4byte gOamData
_0809D038: .4byte 0xFFFFFE00
_0809D03C: .4byte 0x000003FF
_0809D040: .4byte 0xFFFFFC00
_0809D044: .4byte gNextOamSlot

	thumb_func_start CutsceneMonologueResetOam
CutsceneMonologueResetOam: @ 0x0809D048
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0809D08C @ =gNonGameplayRam
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r2, _0809D090 @ =0x0000021A
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0809D094 @ =0x0000021B
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #2
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _0809D098 @ =0x00000222
	adds r1, r1, r0
	strh r2, [r1]
	bx lr
	.align 2, 0
_0809D08C: .4byte gNonGameplayRam
_0809D090: .4byte 0x0000021A
_0809D094: .4byte 0x0000021B
_0809D098: .4byte 0x00000222

	thumb_func_start unk_9d09c
unk_9d09c: @ 0x0809D09C
	bx lr
	.align 2, 0

	thumb_func_start unk_9d0a0
unk_9d0a0: @ 0x0809D0A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0809D0E4 @ =0x040000D4
	ldr r0, _0809D0E8 @ =0x02001000
	str r0, [r1]
	ldr r0, _0809D0EC @ =0x02002000
	str r0, [r1, #4]
	ldr r0, _0809D0F0 @ =0x84000054
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _0809D0F4 @ =gNonGameplayRam
	ldrh r0, [r3, #0xe]
	ldrh r2, [r3, #0xa]
	subs r1, r0, r2
	lsls r1, r1, #0x10
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsrs r2, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0
	bge _0809D0F8
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0xa
	ldrsh r0, [r3, r1]
	lsls r0, r0, #1
	movs r2, #0
	cmp r5, r0
	ble _0809D0FA
	movs r2, #0xa1
	b _0809D0FA
	.align 2, 0
_0809D0E4: .4byte 0x040000D4
_0809D0E8: .4byte 0x02001000
_0809D0EC: .4byte 0x02002000
_0809D0F0: .4byte 0x84000054
_0809D0F4: .4byte gNonGameplayRam
_0809D0F8:
	movs r5, #0
_0809D0FA:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _0809D104
	movs r7, #0xa0
_0809D104:
	ldr r0, _0809D1B8 @ =0x083E3294
	movs r4, #0xa
	ldrsh r1, [r3, r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	mov ip, r1
	ldr r4, _0809D1BC @ =0x02001000
	movs r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r2, r7, #0x10
	cmp r6, r0
	bge _0809D138
	movs r7, #0
	adds r1, r0, #0
_0809D124:
	strh r7, [r4]
	adds r4, #2
	lsls r0, r6, #0x10
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r0, r3
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	blt _0809D124
_0809D138:
	lsls r0, r6, #0x10
	asrs r1, r2, #0x10
	cmp r0, r2
	bgt _0809D192
	ldr r0, _0809D1C0 @ =gNonGameplayRam
	mov r8, r0
	adds r7, r1, #0
_0809D146:
	lsls r0, r5, #2
	add r0, ip
	mov r2, r8
	ldrh r1, [r2, #0xc]
	ldrh r2, [r0, #2]
	adds r2, r1, r2
	lsls r2, r2, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsrs r1, r2, #0x10
	cmp r2, #0
	bge _0809D164
	movs r1, #0
_0809D164:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _0809D16E
	movs r3, #0xf0
_0809D16E:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	strh r0, [r4]
	adds r4, #2
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r0, r6, #0x10
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r0, r3
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r7
	ble _0809D146
_0809D192:
	lsls r1, r6, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0x9f
	bgt _0809D1AC
	movs r2, #0
_0809D19C:
	strh r2, [r4]
	adds r4, #2
	movs r0, #0x80
	lsls r0, r0, #9
	adds r1, r1, r0
	asrs r0, r1, #0x10
	cmp r0, #0x9f
	ble _0809D19C
_0809D1AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809D1B8: .4byte 0x083E3294
_0809D1BC: .4byte 0x02001000
_0809D1C0: .4byte gNonGameplayRam

	thumb_func_start unk_9d1c4
unk_9d1c4: @ 0x0809D1C4
	ldr r0, _0809D1D8 @ =0x04000006
	ldrh r0, [r0]
	ldr r1, _0809D1DC @ =0x04000040
	lsls r0, r0, #0x10
	asrs r0, r0, #0xf
	ldr r2, _0809D1E0 @ =0x02002000
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	bx lr
	.align 2, 0
_0809D1D8: .4byte 0x04000006
_0809D1DC: .4byte 0x04000040
_0809D1E0: .4byte 0x02002000

	thumb_func_start CutsceneMonologueDestroyOamOfType
CutsceneMonologueDestroyOamOfType: @ 0x0809D1E4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	ldr r6, _0809D214 @ =gNonGameplayRam
	movs r7, #2
	rsbs r7, r7, #0
	movs r5, #0
_0809D1F4:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r2, r0, r6
	adds r1, r2, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, r4
	bne _0809D218
	strb r5, [r1]
	adds r2, #0x2e
	ldrb r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r2]
	b _0809D222
	.align 2, 0
_0809D214: .4byte gNonGameplayRam
_0809D218:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _0809D1F4
_0809D222:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start CutsceneFadeIn
CutsceneFadeIn: @ 0x0809D228
	push {lr}
	bl CutsceneProcessOam
	bl CutsceneDrawAllOam
	ldr r1, _0809D244 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809D23E
	subs r0, #1
	strh r0, [r1]
_0809D23E:
	pop {r0}
	bx r0
	.align 2, 0
_0809D244: .4byte gWrittenToBldy

	thumb_func_start CutsceneFadeOut
CutsceneFadeOut: @ 0x0809D248
	push {lr}
	bl CutsceneProcessOam
	bl CutsceneDrawAllOam
	ldr r1, _0809D264 @ =gWrittenToBldy
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0809D25E
	adds r0, #1
	strh r0, [r1]
_0809D25E:
	pop {r0}
	bx r0
	.align 2, 0
_0809D264: .4byte gWrittenToBldy

	thumb_func_start CutsceneDestroyOamOfType
CutsceneDestroyOamOfType: @ 0x0809D268
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	ldr r6, _0809D298 @ =gNonGameplayRam
	movs r7, #2
	rsbs r7, r7, #0
	movs r5, #0
_0809D278:
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r2, r0, r6
	adds r1, r2, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, r4
	bne _0809D29C
	strb r5, [r1]
	adds r2, #0x2e
	ldrb r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r2]
	b _0809D2A6
	.align 2, 0
_0809D298: .4byte gNonGameplayRam
_0809D29C:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _0809D278
_0809D2A6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start CutsceneProcessOam
CutsceneProcessOam: @ 0x0809D2AC
	push {r4, r5, lr}
	ldr r1, _0809D2F0 @ =gNonGameplayRam
	movs r0, #0
	strb r0, [r1, #0x12]
	movs r5, #0
	adds r4, r1, #0
_0809D2B8:
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r2, r0, #2
	adds r0, r2, r4
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809D2E0
	adds r1, r4, #0
	adds r1, #0x38
	adds r1, r2, r1
	adds r0, r4, #0
	adds r0, #0x18
	adds r0, r2, r0
	ldr r1, [r1]
	bl _call_via_r1
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
_0809D2E0:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bls _0809D2B8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809D2F0: .4byte gNonGameplayRam

	thumb_func_start CutsceneDrawAllOam
CutsceneDrawAllOam: @ 0x0809D2F4
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r5, _0809D334 @ =gNonGameplayRam
	adds r6, r5, #0
	adds r6, #0x18
_0809D2FE:
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r1, r0, #2
	adds r0, r1, r5
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _0809D316
	adds r0, r1, r6
	bl CutsceneDrawOam
_0809D316:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _0809D2FE
	bl ResetFreeOam
	ldr r0, _0809D338 @ =gNextOamSlot
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0809D33C @ =0x03001238
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D334: .4byte gNonGameplayRam
_0809D338: .4byte gNextOamSlot
_0809D33C: .4byte 0x03001238

	thumb_func_start CutsceneDrawOam
CutsceneDrawOam: @ 0x0809D340
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	ldr r3, _0809D438 @ =gNextOamSlot
	ldrb r0, [r3]
	lsls r0, r0, #3
	ldr r2, _0809D43C @ =gOamData
	adds r0, r0, r2
	mov ip, r0
	mov r0, r8
	ldrb r5, [r0, #0x11]
	lsls r1, r5, #3
	ldr r0, [r0, #0x1c]
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	mov r1, r8
	ldrb r1, [r1, #0x12]
	cmp r0, r1
	bne _0809D37A
	adds r0, r5, #1
	movs r1, #0
	mov r2, r8
	strb r0, [r2, #0x11]
	strb r1, [r2, #0x12]
	adds r4, #8
_0809D37A:
	ldrb r1, [r4, #4]
	cmp r1, #0
	bne _0809D38A
	mov r3, r8
	ldrb r0, [r3, #0x11]
	lsls r0, r0, #3
	subs r4, r4, r0
	strb r1, [r3, #0x11]
_0809D38A:
	ldr r4, [r4]
	mov sl, r4
	ldrh r4, [r4]
	str r4, [sp, #0x18]
	movs r0, #2
	add sl, r0
	mov r2, r8
	ldrb r1, [r2, #0x16]
	lsls r0, r1, #0x1d
	lsrs r0, r0, #0x1e
	cmp r0, #0
	beq _0809D3A4
	b _0809D504
_0809D3A4:
	movs r3, #0
	str r3, [sp, #0x14]
	cmp r3, r4
	blt _0809D3AE
	b _0809DB26
_0809D3AE:
	ldr r4, _0809D440 @ =0x000001FF
	adds r6, r4, #0
	movs r0, #3
	mov sb, r0
_0809D3B6:
	mov r1, sl
	ldrh r5, [r1]
	movs r2, #2
	add sl, r2
	mov r3, sl
	ldrh r7, [r3]
	add sl, r2
	mov r4, ip
	strh r5, [r4]
	add ip, r2
	mov r0, ip
	strh r7, [r0]
	add ip, r2
	mov r1, sl
	ldrh r0, [r1]
	mov r2, ip
	strh r0, [r2]
	movs r3, #2
	add sl, r3
	add ip, r3
	ldr r4, _0809D438 @ =gNextOamSlot
	ldrb r0, [r4]
	ldr r1, [sp, #0x14]
	adds r3, r0, r1
	mov r2, r8
	ldrb r0, [r2, #0x16]
	lsls r0, r0, #0x19
	lsrs r1, r0, #0x1f
	cmp r1, #1
	bne _0809D448
	lsls r4, r3, #3
	ldr r3, _0809D43C @ =gOamData
	adds r2, r4, r3
	ldrb r3, [r2, #3]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x1f
	eors r0, r1
	lsls r0, r0, #4
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, #3]
	lsrs r1, r1, #6
	ldrb r0, [r2, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, _0809D444 @ =0x0863A184
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #3
	adds r0, r7, r0
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r1, r0
	ands r0, r6
	str r0, [sp]
	ldrh r0, [r2, #2]
	adds r5, r5, r0
	movs r0, #0xff
	ands r5, r0
	str r5, [sp, #4]
	b _0809D45E
	.align 2, 0
_0809D438: .4byte gNextOamSlot
_0809D43C: .4byte gOamData
_0809D440: .4byte 0x000001FF
_0809D444: .4byte 0x0863A184
_0809D448:
	mov r4, r8
	ldrh r0, [r4, #2]
	adds r5, r5, r0
	movs r0, #0xff
	ands r5, r0
	str r5, [sp, #4]
	ldrh r0, [r4]
	adds r0, r7, r0
	ands r0, r6
	str r0, [sp]
	lsls r4, r3, #3
_0809D45E:
	ldr r0, _0809D4F4 @ =gOamData
	adds r3, r4, r0
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r3]
	ldr r2, [sp]
	ands r2, r6
	ldrh r1, [r3, #2]
	ldr r0, _0809D4F8 @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r3, #2]
	mov r4, r8
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #2
	ldrb r2, [r3, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #5]
	lsrs r2, r1, #4
	ldrb r0, [r4, #0x18]
	lsrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #4
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r3, #5]
	ldrh r5, [r3, #4]
	lsls r2, r5, #0x16
	lsrs r2, r2, #0x16
	ldrb r4, [r4, #0x17]
	mov r1, r8
	ldrb r0, [r1, #0x18]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #8
	orrs r0, r4
	adds r2, r2, r0
	ldr r4, _0809D4FC @ =0x000003FF
	adds r0, r4, #0
	ands r2, r0
	ldr r0, _0809D500 @ =0xFFFFFC00
	ands r0, r5
	orrs r0, r2
	strh r0, [r3, #4]
	mov r0, r8
	ldrb r1, [r0, #0x16]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1e
	mov r2, sb
	ands r1, r2
	lsls r1, r1, #2
	ldrb r2, [r3, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #1]
	movs r3, #2
	add ip, r3
	ldr r4, [sp, #0x14]
	adds r4, #1
	str r4, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r4, r0
	bge _0809D4F2
	b _0809D3B6
_0809D4F2:
	b _0809DB26
	.align 2, 0
_0809D4F4: .4byte gOamData
_0809D4F8: .4byte 0xFFFFFE00
_0809D4FC: .4byte 0x000003FF
_0809D500: .4byte 0xFFFFFC00
_0809D504:
	cmp r0, #1
	beq _0809D50A
	b _0809D7D4
_0809D50A:
	mov r2, r8
	ldrh r0, [r2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r0, r1, #0x19
	cmp r0, #0
	blt _0809D52C
	ldrh r3, [r2, #4]
	str r3, [sp, #0xc]
	b _0809D538
_0809D52C:
	mov r4, r8
	ldrh r0, [r4, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
_0809D538:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0809D544
	mov r0, r8
	ldrh r0, [r0, #4]
	b _0809D54E
_0809D544:
	mov r1, r8
	ldrh r0, [r1, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0809D54E:
	str r0, [sp, #0x10]
	movs r2, #0
	b _0809D782
_0809D554:
	mov r4, sl
	ldrh r5, [r4]
	movs r0, #2
	add sl, r0
	mov r1, sl
	ldrh r7, [r1]
	add sl, r0
	mov r2, ip
	strh r5, [r2]
	add ip, r0
	mov r3, ip
	strh r7, [r3]
	add ip, r0
	mov r4, sl
	ldrh r0, [r4]
	mov r1, ip
	strh r0, [r1]
	movs r2, #2
	add sl, r2
	add ip, r2
	ldr r3, _0809D7AC @ =gNextOamSlot
	ldrb r0, [r3]
	ldr r4, [sp, #0x14]
	adds r3, r0, r4
	lsls r0, r3, #3
	ldr r1, _0809D7B0 @ =gOamData
	adds r6, r0, r1
	ldrb r2, [r6, #3]
	mov sb, r2
	mov r3, sb
	lsrs r1, r3, #6
	ldrb r0, [r6, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r4, _0809D7B4 @ =0x0863A184
	adds r0, r1, r4
	ldrb r2, [r0]
	ldr r0, _0809D7B8 @ =0x0863A190
	adds r1, r1, r0
	ldrb r3, [r1]
	ldr r1, [sp, #4]
	adds r5, r5, r1
	movs r0, #0xff
	ands r5, r0
	ldr r0, [sp]
	adds r4, r7, r0
	ldr r1, _0809D7BC @ =0x000001FF
	adds r0, r1, #0
	ands r4, r0
	ldr r0, [sp]
	subs r1, r4, r0
	lsls r2, r2, #2
	str r2, [sp, #0x1c]
	adds r1, r2, r1
	ldr r0, [sp, #4]
	subs r2, r5, r0
	lsls r3, r3, #2
	str r3, [sp, #0x20]
	adds r2, r3, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #0xc]
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	adds r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x10
	asrs r7, r0, #0x10
	adds r0, r2, #0
	muls r0, r7, r0
	asrs r0, r0, #8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r1, sb
	lsls r0, r1, #0x1b
	cmp r0, #0
	bge _0809D612
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r6, #3]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
_0809D612:
	ldrb r1, [r6, #3]
	lsls r0, r1, #0x1a
	cmp r0, #0
	bge _0809D62A
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r6, #3]
	rsbs r0, r7, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
_0809D62A:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #8]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, [sp]
	subs r4, r4, r0
	ldr r1, [sp, #0x1c]
	adds r4, r1, r4
	ldr r2, [sp, #4]
	subs r3, r5, r2
	ldr r0, [sp, #0x20]
	adds r3, r0, r3
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, r8
	ldrb r1, [r2, #0x15]
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r2, _0809D7C0 @ =0x080A4FA4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r5, [r0, r2]
	adds r2, r4, #0
	muls r2, r5, r2
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r1, r1, #1
	ldr r0, _0809D7C0 @ =0x080A4FA4
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	adds r0, r3, #0
	muls r0, r1, r0
	subs r2, r2, r0
	lsls r2, r2, #8
	adds r0, r4, #0
	muls r0, r1, r0
	adds r1, r3, #0
	muls r1, r5, r1
	adds r0, r0, r1
	lsls r0, r0, #8
	asrs r2, r2, #0x10
	ldr r1, [sp, #0x1c]
	subs r2, r2, r1
	asrs r0, r0, #0x10
	ldr r3, [sp, #0x20]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r4, [sp, #4]
	adds r0, r5, r4
	subs r0, #0x40
	strb r0, [r6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r0, [sp]
	adds r2, r2, r0
	subs r2, #0x40
	ldr r0, _0809D7BC @ =0x000001FF
	ands r2, r0
	ldrh r1, [r6, #2]
	ldr r0, _0809D7C4 @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r6, #2]
	ldrb r1, [r6, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #1]
	ldr r2, _0809D7C8 @ =0x03001238
	ldrb r1, [r2]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809D6E8
	ldrb r0, [r6, #3]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r6, #3]
_0809D6E8:
	ldr r3, _0809D7C8 @ =0x03001238
	ldrb r1, [r3]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809D6FA
	ldrb r0, [r6, #3]
	orrs r0, r2
	strb r0, [r6, #3]
_0809D6FA:
	ldr r4, _0809D7C8 @ =0x03001238
	ldrb r0, [r4]
	movs r1, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r2, [r6, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #3]
	mov r1, r8
	ldrb r0, [r1, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #2
	ldrb r2, [r6, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, #5]
	lsrs r2, r1, #4
	mov r3, r8
	ldrb r0, [r3, #0x18]
	lsrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #4
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r6, #5]
	ldrh r4, [r6, #4]
	lsls r2, r4, #0x16
	lsrs r2, r2, #0x16
	ldrb r3, [r3, #0x17]
	mov r1, r8
	ldrb r0, [r1, #0x18]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #8
	orrs r0, r3
	adds r2, r2, r0
	ldr r3, _0809D7CC @ =0x000003FF
	adds r0, r3, #0
	ands r2, r0
	ldr r0, _0809D7D0 @ =0xFFFFFC00
	ands r0, r4
	orrs r0, r2
	strh r0, [r6, #4]
	mov r4, r8
	ldrb r1, [r4, #0x16]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1e
	movs r0, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r6, #1]
	subs r0, #0x10
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #1]
	movs r1, #2
	add ip, r1
	ldr r2, [sp, #0x14]
	adds r2, #1
_0809D782:
	str r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	cmp r2, r3
	bge _0809D78C
	b _0809D554
_0809D78C:
	ldr r4, _0809D7C8 @ =0x03001238
	ldrb r0, [r4]
	lsls r0, r0, #0x1a
	lsrs r7, r0, #0x18
	mov r1, r8
	ldrb r0, [r1, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r2, _0809D7C0 @ =0x080A4FA4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	ldr r0, [sp, #0xc]
	lsls r4, r0, #0x10
	b _0809DA7E
	.align 2, 0
_0809D7AC: .4byte gNextOamSlot
_0809D7B0: .4byte gOamData
_0809D7B4: .4byte 0x0863A184
_0809D7B8: .4byte 0x0863A190
_0809D7BC: .4byte 0x000001FF
_0809D7C0: .4byte 0x080A4FA4
_0809D7C4: .4byte 0xFFFFFE00
_0809D7C8: .4byte 0x03001238
_0809D7CC: .4byte 0x000003FF
_0809D7D0: .4byte 0xFFFFFC00
_0809D7D4:
	cmp r0, #3
	beq _0809D7DA
	b _0809DB26
_0809D7DA:
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldrh r0, [r3, #2]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	lsls r0, r1, #0x19
	cmp r0, #0
	blt _0809D7FC
	ldrh r4, [r3, #4]
	str r4, [sp, #0xc]
	b _0809D808
_0809D7FC:
	mov r2, r8
	ldrh r0, [r2, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
_0809D808:
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _0809D816
	mov r3, r8
	ldrh r3, [r3, #4]
	str r3, [sp, #0x10]
	b _0809D822
_0809D816:
	mov r4, r8
	ldrh r0, [r4, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
_0809D822:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	cmp r0, r1
	blt _0809D82E
	b _0809DA62
_0809D82E:
	mov r2, sl
	ldrh r5, [r2]
	movs r3, #2
	add sl, r3
	mov r4, sl
	ldrh r7, [r4]
	add sl, r3
	mov r0, ip
	strh r5, [r0]
	add ip, r3
	mov r1, ip
	strh r7, [r1]
	add ip, r3
	mov r2, sl
	ldrh r0, [r2]
	mov r3, ip
	strh r0, [r3]
	movs r4, #2
	add sl, r4
	add ip, r4
	ldr r1, _0809DB48 @ =gNextOamSlot
	ldrb r0, [r1]
	ldr r2, [sp, #0x14]
	adds r3, r0, r2
	lsls r0, r3, #3
	ldr r3, _0809DB4C @ =gOamData
	adds r6, r0, r3
	ldrb r4, [r6, #3]
	mov sb, r4
	mov r0, sb
	lsrs r1, r0, #6
	ldrb r0, [r6, #1]
	lsrs r0, r0, #6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r2, _0809DB50 @ =0x0863A184
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _0809DB54 @ =0x0863A190
	adds r1, r1, r3
	ldrb r3, [r1]
	ldr r4, [sp, #4]
	adds r5, r5, r4
	movs r0, #0xff
	ands r5, r0
	ldr r0, [sp]
	adds r4, r7, r0
	ldr r1, _0809DB58 @ =0x000001FF
	adds r0, r1, #0
	ands r4, r0
	ldr r0, [sp]
	subs r1, r4, r0
	lsls r2, r2, #2
	str r2, [sp, #0x24]
	adds r1, r2, r1
	ldr r0, [sp, #4]
	subs r2, r5, r0
	lsls r3, r3, #2
	str r3, [sp, #0x28]
	adds r2, r3, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #0xc]
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	adds r0, r1, #0
	muls r0, r3, r0
	asrs r0, r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x10
	asrs r7, r0, #0x10
	adds r0, r2, #0
	muls r0, r7, r0
	asrs r0, r0, #8
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r1, sb
	lsls r0, r1, #0x1b
	cmp r0, #0
	bge _0809D8EC
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r6, #3]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
_0809D8EC:
	ldrb r1, [r6, #3]
	lsls r0, r1, #0x1a
	cmp r0, #0
	bge _0809D904
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r6, #3]
	rsbs r0, r7, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
_0809D904:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r3, [sp, #8]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, [sp]
	subs r4, r4, r0
	ldr r1, [sp, #0x24]
	adds r4, r1, r4
	ldr r2, [sp, #4]
	subs r3, r5, r2
	ldr r0, [sp, #0x28]
	adds r3, r0, r3
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, r8
	ldrb r1, [r2, #0x15]
	adds r0, r1, #0
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r2, _0809DB5C @ =0x080A4FA4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r5, [r0, r2]
	adds r2, r4, #0
	muls r2, r5, r2
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r1, r1, #1
	ldr r0, _0809DB5C @ =0x080A4FA4
	adds r1, r1, r0
	movs r0, #0
	ldrsh r1, [r1, r0]
	adds r0, r3, #0
	muls r0, r1, r0
	subs r2, r2, r0
	lsls r2, r2, #8
	adds r0, r4, #0
	muls r0, r1, r0
	adds r1, r3, #0
	muls r1, r5, r1
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r3, [sp, #0x24]
	lsls r1, r3, #1
	asrs r2, r2, #0x10
	subs r2, r2, r1
	ldr r4, [sp, #0x28]
	lsls r1, r4, #1
	asrs r0, r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r1, [sp, #4]
	adds r0, r5, r1
	subs r0, #0x40
	strb r0, [r6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r3, [sp]
	adds r2, r2, r3
	subs r2, #0x40
	ldr r0, _0809DB58 @ =0x000001FF
	ands r2, r0
	ldrh r1, [r6, #2]
	ldr r0, _0809DB60 @ =0xFFFFFE00
	ands r0, r1
	orrs r0, r2
	strh r0, [r6, #2]
	ldrb r0, [r6, #1]
	movs r5, #3
	orrs r0, r5
	strb r0, [r6, #1]
	ldr r4, _0809DB64 @ =0x03001238
	ldrb r1, [r4]
	movs r2, #0x10
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809D9C0
	ldrb r0, [r6, #3]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r6, #3]
_0809D9C0:
	ldr r0, _0809DB64 @ =0x03001238
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809D9D2
	ldrb r0, [r6, #3]
	orrs r0, r2
	strb r0, [r6, #3]
_0809D9D2:
	ldr r1, _0809DB64 @ =0x03001238
	ldrb r0, [r1]
	movs r1, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r2, [r6, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #3]
	mov r2, r8
	ldrb r0, [r2, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	ands r0, r5
	lsls r0, r0, #2
	ldrb r2, [r6, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, #5]
	lsrs r2, r1, #4
	mov r3, r8
	ldrb r0, [r3, #0x18]
	lsrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #4
	movs r0, #0xf
	ands r1, r0
	orrs r1, r2
	strb r1, [r6, #5]
	ldrh r4, [r6, #4]
	lsls r2, r4, #0x16
	lsrs r2, r2, #0x16
	ldrb r3, [r3, #0x17]
	mov r1, r8
	ldrb r0, [r1, #0x18]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #8
	orrs r0, r3
	adds r2, r2, r0
	ldr r3, _0809DB68 @ =0x000003FF
	adds r0, r3, #0
	ands r2, r0
	ldr r0, _0809DB6C @ =0xFFFFFC00
	ands r0, r4
	orrs r0, r2
	strh r0, [r6, #4]
	mov r4, r8
	ldrb r1, [r4, #0x16]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1e
	ands r1, r5
	lsls r1, r1, #2
	ldrb r2, [r6, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, #1]
	movs r0, #2
	add ip, r0
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	cmp r1, r2
	bge _0809DA62
	b _0809D82E
_0809DA62:
	ldr r3, _0809DB64 @ =0x03001238
	ldrb r0, [r3]
	lsls r0, r0, #0x1a
	lsrs r7, r0, #0x18
	mov r4, r8
	ldrb r0, [r4, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r1, _0809DB5C @ =0x080A4FA4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	ldr r3, [sp, #0xc]
	lsls r4, r3, #0x10
_0809DA7E:
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl FixedMultiplication
	ldr r6, _0809DB4C @ =gOamData
	lsls r1, r7, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	mov r1, r8
	ldrb r0, [r1, #0x15]
	lsls r0, r0, #1
	ldr r2, _0809DB5C @ =0x080A4FA4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	adds r0, r4, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r5, #0
	bl FixedMultiplication
	adds r1, r7, #1
	lsls r1, r1, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	mov r4, r8
	ldrb r0, [r4, #0x15]
	lsls r0, r0, #1
	ldr r1, _0809DB5C @ =0x080A4FA4
	adds r0, r0, r1
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, [sp, #0x10]
	lsls r5, r2, #0x10
	asrs r5, r5, #0x10
	adds r0, r5, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #2
	lsls r1, r1, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	mov r3, r8
	ldrb r0, [r3, #0x15]
	adds r0, #0x40
	lsls r0, r0, #1
	ldr r4, _0809DB5C @ =0x080A4FA4
	adds r0, r0, r4
	movs r1, #0
	ldrsh r4, [r0, r1]
	adds r0, r5, #0
	bl FixedInverse
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl FixedMultiplication
	adds r1, r7, #3
	lsls r1, r1, #3
	adds r1, r1, r6
	strh r0, [r1, #6]
	ldr r2, _0809DB64 @ =0x03001238
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_0809DB26:
	ldr r0, _0809DB48 @ =gNextOamSlot
	ldrb r1, [r0]
	ldr r3, [sp, #0x18]
	adds r1, r1, r3
	strb r1, [r0]
	mov r4, r8
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809DB48: .4byte gNextOamSlot
_0809DB4C: .4byte gOamData
_0809DB50: .4byte 0x0863A184
_0809DB54: .4byte 0x0863A190
_0809DB58: .4byte 0x000001FF
_0809DB5C: .4byte 0x080A4FA4
_0809DB60: .4byte 0xFFFFFE00
_0809DB64: .4byte 0x03001238
_0809DB68: .4byte 0x000003FF
_0809DB6C: .4byte 0xFFFFFC00

	thumb_func_start unk_9db70
unk_9db70: @ 0x0809DB70
	bx lr
	.align 2, 0

