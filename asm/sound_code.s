	.include "asm/macros.inc"

	.syntax unified

	thumb_func_start CallSoundCodeB
CallSoundCodeB: @ 0x08003D68
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7, lr}
	add r4, pc, #0x0 @ =SoundCodeB
	bx r4

	arm_func_start SoundCodeB
SoundCodeB: @ 0x08003D78
	ldr r4, _08003E08 @ =gMusicInfo
	ldrb ip, [r4, #4]
	mov lr, #0x600
	b _08003D90
_08003D88:
	subs r3, r3, #1
	beq _08003DF8
_08003D90:
	ldrsb r6, [r0, lr]
	ldrsb r7, [r1, lr]
	ldrsb r4, [r0], #1
	ldrsb r5, [r1], #1
	ldrsb sl, [r0, lr]
	ldrsb fp, [r1, lr]
	ldrsb r8, [r0], #1
	ldrsb sb, [r1], #1
	add r6, r6, r4
	add r6, r6, r5
	add r6, r6, r7
	add r8, r8, sb
	add r8, r8, sl
	add r8, r8, fp
	mul r6, ip, r6
	mul r8, ip, r8
	asrs r6, r6, #9
	addmi r6, r6, #1
	asrs r8, r8, #9
	addmi r8, r8, #1
	lsl r6, r6, #7
	lsl r8, r8, #7
	mov r7, r6
	mov sb, r8
	stm r2!, {r6, r7, r8, sb}
	b _08003D88
_08003DF8:
	mov r0, r2
	pop {r8, sb, sl, fp, lr}
	pop {r4, r5, r6, r7}
	bx lr
	.align 2, 0
_08003E08: .4byte gMusicInfo

	thumb_func_start CallSoundCodeC
CallSoundCodeC: @ 0x08003E0C
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7, lr}
	add r4, pc, #0x0 @ =SoundCodeC
	bx r4

	arm_func_start SoundCodeC
SoundCodeC: @ 0x08003E1C
	mov r3, #0x600
	add r3, r0, r3
	mov ip, #0
	sub ip, ip, #1
	lsr ip, ip, #0x17
	ldr lr, _08003EB8 @ =0x080A548A
	b _08003E40
_08003E38:
	subs r2, r2, #1
	beq _08003EA8
_08003E40:
	ldm r1!, {r4, r5, r6, r7, r8, sb, sl, fp}
	and r4, ip, r4, lsr #7
	and r5, ip, r5, lsr #7
	and r6, ip, r6, lsr #7
	and r7, ip, r7, lsr #7
	and r8, ip, r8, lsr #7
	and sb, ip, sb, lsr #7
	and sl, ip, sl, lsr #7
	and fp, ip, fp, lsr #7
	ldrb r4, [lr, r4]
	ldrb r5, [lr, r5]
	ldrb r6, [lr, r6]
	ldrb r7, [lr, r7]
	ldrb r8, [lr, r8]
	ldrb sb, [lr, sb]
	ldrb sl, [lr, sl]
	ldrb fp, [lr, fp]
	orr r4, r4, r6, lsl #8
	orr r4, r4, r8, lsl #16
	orr r4, r4, sl, lsl #24
	str r4, [r0], #4
	orr r5, r5, r7, lsl #8
	orr r5, r5, sb, lsl #16
	orr r5, r5, fp, lsl #24
	str r5, [r3], #4
	b _08003E38
_08003EA8:
	mov r0, r1
	pop {r8, sb, sl, fp, lr}
	pop {r4, r5, r6, r7}
	bx lr
	.align 2, 0
_08003EB8: .4byte 0x080A548A

	thumb_func_start CallSoundCodeA
CallSoundCodeA: @ 0x08003EBC
	push {r4, r5, r6, r7}
	mov r3, r8
	mov r4, sb
	mov r5, sl
	mov r6, fp
	push {r3, r4, r5, r6, lr}
	add r4, pc, #0x0 @ =SoundCodeA
	bx r4

	arm_func_start SoundCodeA
SoundCodeA: @ 0x08003ECC
	ldr r12, [r0, #0x18]
	ldrb r11, [r0, #0x11]
	ldrb r10, [r0, #0x12]
	ldr r9, [r0, #0x24]
	ldr r3, [r0, #0x20]
	ldr r8, [r3, #0xc]
	ldrb r4, [r0, #1]
	cmp r4, #0x20
	beq _08004318
	cmp r4, #8
	beq _080041EC
	mov r7, #0
	sub r7, r7, #1
	lsr r7, r7, #0x12
	ldr r6, [r0, #0x1c]
	stmdb sp!, {r0}
	ldrh r0, [r3, #2]
	ldr lr, [r3, #8]
	sub lr, lr, r8
	b _08003F24
_08003F1C:
	subs r2, r2, #1
	beq _08004500
_08003F24:
	add r4, r12, r6, lsl #2
	subs r4, r8, r4, lsr #0xe
	bgt _08004128
	mov r5, r12, lsr #0xe
	ands r0, r0, r0
	bne _08004010
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, r8
	bge _080044F0
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, r8
	bge _080044F0
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, r8
	bge _080044F0
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	b _080044F0
_08004010:
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, r8
	blt _08004058
	and r3, r12, r7
	add r5, r5, lr
	add r12, r3, r5, lsl #0xe
	b _08004158
_08004058:
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, r8
	blt _080040A0
	and r3, r12, r7
	add r5, r5, lr
	add r12, r3, r5, lsl #0xe
	b _08004188
_080040A0:
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, r8
	blt _080040E8
	and r3, r12, r7
	add r5, r5, lr
	add r12, r3, r5, lsl #0xe
	b _080041B8
_080040E8:
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	and r3, r12, r7
	add r5, r5, lr
	add r12, r3, r5, lsl #0xe
	b _08003F1C
_08004128:
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
_08004158:
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
_08004188:
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
_080041B8:
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	b _08003F1C
_080041EC:
	stmdb sp!, {r0}
	ldrh r7, [r3, #2]
	ldr r6, [r3, #8]
	b _08004204
_080041FC:
	subs r2, r2, #1
	beq _08004500
_08004204:
	add r4, r12, #4
	cmp r4, r8
	blt _080042C4
	ldsb r3, [r9, r12]
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, #1
	cmp r12, r8
	bne _0800423C
	ands r7, r7, r7
	beq _080044F0
	mov r12, r6
_0800423C:
	ldsb r3, [r9, r12]
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, #1
	cmp r12, r8
	bne _08004268
	ands r7, r7, r7
	beq _080044F0
	mov r12, r6
_08004268:
	ldsb r3, [r9, r12]
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, #1
	cmp r12, r8
	bne _08004294
	ands r7, r7, r7
	beq _080044F0
	mov r12, r6
_08004294:
	ldsb r3, [r9, r12]
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, #1
	cmp r12, r8
	bne _080041FC
	ands r7, r7, r7
	beq _080044F0
	mov r12, r6
	b _080041FC
_080042C4:
	ldmia r1, {r3, r4, r5, lr}
	ldsb r0, [r9, r12]
	mla r3, r0, r11, r3
	mla r4, r0, r10, r4
	add r12, r12, #1
	ldsb r0, [r9, r12]
	mla r5, r0, r11, r5
	mla lr, r0, r10, lr
	add r12, r12, #1
	stmia r1!, {r3, r4, r5, lr}
	ldmia r1, {r3, r4, r5, lr}
	ldsb r0, [r9, r12]
	mla r3, r0, r11, r3
	mla r4, r0, r10, r4
	add r12, r12, #1
	ldsb r0, [r9, r12]
	mla r5, r0, r11, r5
	mla lr, r0, r10, lr
	add r12, r12, #1
	stmia r1!, {r3, r4, r5, lr}
	b _080041FC
_08004318:
	mov r7, #0
	sub r7, r7, #1
	mov r4, r7
	mov r7, r7, lsr #0x12
	ldr r6, [r0, #0x1c]
	eor r6, r6, r4
	add r6, r6, #1
	stmdb sp!, {r0}
	ldrh r0, [r3, #2]
	b _08004348
_08004340:
	subs r2, r2, #1
	beq _08004500
_08004348:
	add r4, r12, r6, lsl #2
	movs r4, r4, asr #0xe
	bgt _0800442C
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, #0
	ble _080044F0
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, #0
	ble _080044F0
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	cmp r5, #0
	ble _080044F0
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	b _080044F0
_0800442C:
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	mov r5, r12, lsr #0xe
	ldsb r3, [r5, r9]!
	ldsb r4, [r5, #1]
	sub r4, r4, r3
	and r5, r12, r7
	mul r4, r5, r4
	add r3, r3, r4, lsr #0xe
	ldmia r1, {r4, r5}
	mla r4, r3, r11, r4
	mla r5, r3, r10, r5
	stmia r1!, {r4, r5}
	add r12, r12, r6
	b _08004340
_080044F0:
	ldmia sp!, {r0}
	mov r4, #0
	strb r4, [r0, #0]
	b _08004508
_08004500:
	ldmia sp!, {r0}
	str r12, [r0, #0x18]
_08004508:
	pop {r8-r11, lr}
	pop {r4-r7}
	bx lr

	thumb_func_start CallGetNoteFrequency
CallGetNoteFrequency: @ 0x08004514
	add r2, pc, #0x0
	bx r2

	arm_func_start GetNoteFrequency
GetNoteFrequency: @ 0x08004518
	umull r2, r3, r0, r1
	mov r2, r2, lsr #0x12
	mov r3, r3, lsl #0xe
	add r3, r3, r2
	add r0, r3, #0x0
	bx lr

	thumb_func_start unk_4530
unk_4530: @ 0x08004530
	add r0, pc, #0x0
	bx r0

	arm_func_start unk_4534
unk_4534: @ 0x08004534
	ldr r0, =gMusicInfo
	ldrb r1, [r0, #0x10]
	add r1, r1, #1
	ldrb r3, [r0, #0xe]
	cmp r1, r3
	bne lbl_08004594
	ldr r3, =0x80a568c
	ldr r3, [r3]
	ldr r12, =0x80a5690
	ldr r12, [r12]
	str r12, [r3]
	str r12, [r3, #0xc]
	nop
	mov r12, #0x50
	lsl r12, r12, #0x4
	strh r12, [r3, #0x2]
	strh r12, [r3, #0xe]
	mov r12, #0xb6
	lsl r12, r12, #0x8
	strh r12, [r3, #0x2]
	mov r12, #0xf6
	lsl r12, r12, #0x8
	strh r12, [r3, #0xe]
	mov r1, #0x0
lbl_08004594:
	strb r1, [r0, #0x10]
	bx lr
	.align 2, 0
	.pool
