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
	ldr r0, _080998A8 @ =NewFileIntroVBlank
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
_080998A8: .4byte NewFileIntroVBlank

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

	thumb_func_start NewFileIntroVBlank
NewFileIntroVBlank: @ 0x080998F4
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

