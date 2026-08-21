	.include "asm/macros.inc"

	.syntax unified

	thumb_func_start InitTrack
InitTrack: @ 0x080045A8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r6, [r4, #0x1c]
	cmp r6, #0
	bne _0800465C
	movs r6, #1
	strb r6, [r4, #0x1c]
	ldrb r6, [r4, #0x1e]
	movs r7, #1
	ands r6, r7
	bne _08004658
	ldr r6, [r5]
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	bne _080045D4
	bl ResetTrack
	movs r2, #0
	strb r2, [r4]
	b _08004658
_080045D4:
	ldr r7, [r4]
	movs r3, #2
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	ands r3, r2
	beq _080045FA
	movs r3, #0x1d
	ldrb r3, [r4, r3]
	cmp r3, #0
	beq _080045F4
	lsls r1, r6, #8
	lsrs r1, r1, #0x18
	lsrs r2, r7, #0x18
	cmp r2, r1
	ble _080045F4
	b _08004658
_080045F4:
	adds r0, r4, #0
	bl ResetTrack
_080045FA:
	movs r3, #2
	lsls r2, r6, #8
	orrs r2, r3
	ldr r0, [r5, #4]
	str r2, [r4]
	str r0, [r4, #0x14]
	str r5, [r4, #0x10]
	lsls r3, r3, #7
	strh r3, [r4, #0xc]
	lsrs r2, r6, #0x1f
	beq _08004616
	lsrs r0, r6, #0x18
	bl DoSoundAction
_08004616:
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r7, [r4, #0x18]
	movs r0, #0x10
	str r0, [sp]
	movs r0, #3
	movs r1, #0
_08004624:
	adds r2, r7, #0
	movs r3, #0x50
	muls r3, r6, r3
	bl BitFill
	movs r0, #1
	movs r2, #0x40
	lsls r1, r2, #0x10
	lsls r2, r2, #8
	orrs r1, r2
_08004638:
	movs r3, #0xc
	lsls r3, r3, #8
	movs r2, #2
	orrs r2, r3
	adds r5, #8
	b _0800464C
_08004644:
	subs r6, #1
	beq _08004658
	adds r7, #0x50
	adds r5, #4
_0800464C:
	ldr r3, [r5]
	strb r0, [r7]
	strh r2, [r7, #0x1a]
	str r1, [r7, #4]
	str r3, [r7, #0x24]
	b _08004644
_08004658:
	movs r6, #0
	strb r6, [r4, #0x1c]
_0800465C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start StopMusicOrSound
StopMusicOrSound: @ 0x08004664
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r6, [r7, #0x1c]
	cmp r6, #0
	bne _080046E0
	movs r6, #1
	strb r6, [r7, #0x1c]
	ldrb r6, [r7, #0x1e]
	movs r5, #1
	ands r5, r6
	bne _080046DC
	ldrb r4, [r7]
	movs r5, #2
	ands r4, r5
	beq _080046DC
	movs r4, #1
	strb r4, [r7]
	movs r4, #0
	strb r4, [r7, #2]
	movs r4, #2
	ands r4, r6
	beq _08004696
	movs r4, #0xfd
	ands r4, r6
	strb r4, [r7, #0x1e]
_08004696:
	ldrb r6, [r7, #1]
	ldr r5, [r7, #0x18]
	b _080046A2
_0800469C:
	subs r6, #1
	beq _080046DC
	adds r5, #0x50
_080046A2:
	ldr r4, [r5, #0x4c]
	cmp r4, #0
	beq _080046BE
	movs r3, #7
	movs r2, #0x34
	ldrb r1, [r5, r2]
	ands r1, r3
	subs r1, #1
	adds r0, r4, #0
	bl ClearRegistersForPsg
	movs r3, #0
	strb r3, [r4]
	str r3, [r4, #0x24]
_080046BE:
	ldr r0, [r5, #0x48]
	movs r1, #0
_080046C2:
	cmp r0, #0
	beq _080046D4
	ldr r2, [r0, #0x30]
	strb r1, [r0]
	str r1, [r0, #0x28]
	str r1, [r0, #0x30]
	str r1, [r0, #0x2c]
	adds r0, r2, #0
	b _080046C2
_080046D4:
	movs r0, #0
	str r0, [r5, #0x4c]
	str r0, [r5, #0x48]
	b _0800469C
_080046DC:
	movs r6, #0
	strb r6, [r7, #0x1c]
_080046E0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start ResetTrack
ResetTrack: @ 0x080046E8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r6, [r7, #0x1e]
	movs r5, #1
	ands r5, r6
	bne _08004756
	ldrb r4, [r7]
	movs r5, #2
	ands r4, r5
	beq _08004756
	movs r4, #1
	strb r4, [r7]
	movs r4, #0
	strb r4, [r7, #2]
	movs r4, #2
	ands r4, r6
	beq _08004710
	movs r4, #0xfd
	ands r4, r6
	strb r4, [r7, #0x1e]
_08004710:
	ldrb r6, [r7, #1]
	ldr r5, [r7, #0x18]
	b _0800471C
_08004716:
	subs r6, #1
	beq _08004756
	adds r5, #0x50
_0800471C:
	ldr r4, [r5, #0x4c]
	cmp r4, #0
	beq _08004738
	movs r3, #7
	movs r2, #0x34
	ldrb r1, [r5, r2]
	ands r1, r3
	subs r1, #1
	adds r0, r4, #0
	bl ClearRegistersForPsg
	movs r3, #0
	strb r3, [r4]
	str r3, [r4, #0x24]
_08004738:
	ldr r0, [r5, #0x48]
	movs r1, #0
_0800473C:
	cmp r0, #0
	beq _0800474E
	ldr r2, [r0, #0x30]
	strb r1, [r0]
	str r1, [r0, #0x28]
	str r1, [r0, #0x30]
	str r1, [r0, #0x2c]
	adds r0, r2, #0
	b _0800473C
_0800474E:
	movs r0, #0
	str r0, [r5, #0x4c]
	str r0, [r5, #0x48]
	b _08004716
_08004756:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start unk_475c
unk_475c: @ 0x0800475C
	adds r3, r0, #0
	ldr r0, [r3, #0xc]
	lsls r1, r0, #0x10
	adds r1, r0, r1
	lsrs r1, r1, #0x10
	movs r2, #0xff
	lsls r0, r2, #8
	ands r0, r1
	beq _08004774
	lsrs r0, r1, #8
	ands r1, r2
	b _08004776
_08004774:
	movs r0, #0
_08004776:
	strh r1, [r3, #0xe]
	bx lr
	.align 2, 0

	thumb_func_start unk_477c
unk_477c: @ 0x0800477C
	ldr r2, [r1, #0x24]
	ldrb r3, [r2, #1]
	adds r2, #2
	str r2, [r1, #0x24]
	lsls r2, r3, #1
	strh r2, [r0, #0xa]
	cmp r2, #0x96
	beq _0800479C
	movs r1, #0x1b
	movs r3, #0x4e
	lsls r1, r1, #8
	orrs r1, r3
	lsls r2, r2, #8
	muls r1, r2, r1
	lsrs r1, r1, #0x14
	b _080047A0
_0800479C:
	movs r1, #1
	lsls r1, r1, #8
_080047A0:
	movs r3, #0
	strh r1, [r0, #0xc]
	strh r3, [r0, #0xe]
	bx lr

	thumb_func_start UpdateAudio
UpdateAudio: @ 0x080047A8
	push {r4, r5, r6, lr}
	ldr r4, _08004810 @ =0x080A8CDC
	ldr r6, _08004814 @ =gMusicInfo
	movs r0, #0x21
	ldrb r0, [r6, r0]
	movs r1, #0x11
	cmp r0, r1
	beq _080047D8
	ldr r5, _08004818 @ =0x00000008
	b _080047C4
_080047BC:
	subs r5, #1
	cmp r5, #0
	beq _080047F4
	adds r4, #0xc
_080047C4:
	ldr r0, [r4]
	cmp r0, #0
	beq _080047BC
	ldrb r3, [r0]
	movs r1, #2
	ands r3, r1
	beq _080047BC
	bl UpdateTrack
	b _080047BC
_080047D8:
	movs r0, #0x20
	ldrb r0, [r6, r0]
	movs r1, #0
	cmp r0, r1
	beq _080047E4
	movs r1, #0xc
_080047E4:
	adds r4, r4, r1
	ldr r0, [r4]
	ldrb r3, [r0]
	movs r1, #2
	ands r3, r1
	beq _080047F4
	bl UpdateTrack
_080047F4:
	ldrb r5, [r6, #1]
	cmp r5, #0
	bne _08004806
	movs r5, #1
	strb r5, [r6, #1]
	bl UpdatePsgSounds
	bl UpdateMusic
_08004806:
	movs r0, #0
	strb r0, [r6, #1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004810: .4byte 0x080A8CDC
_08004814: .4byte gMusicInfo
_08004818: .4byte 0x00000008

	thumb_func_start unk_481c
unk_481c: @ 0x0800481C
	push {r4, r5, lr}
	ldr r1, [r0, #0x40]
	ldrb r2, [r0, #1]
	ldrb r3, [r0]
	movs r4, #0xf0
	ands r3, r4
	cmp r3, #0x80
	bne _0800484C
	movs r3, #0xc
	muls r2, r3, r2
	adds r1, r1, r2
	ldrb r2, [r1, #1]
	movs r3, #0x35
	strb r2, [r0, r3]
	ldrb r2, [r1, #3]
	cmp r2, #0
	bne _08004844
	movs r2, #0x40
	strb r2, [r0, #6]
	b _08004858
_08004844:
	subs r2, #0x80
	bmi _08004858
	strb r2, [r0, #6]
	b _08004858
_0800484C:
	ldr r3, [r0, #0x44]
	adds r3, r3, r2
	ldrb r3, [r3]
	movs r4, #0xc
	muls r3, r4, r3
	adds r1, r1, r3
_08004858:
	ldr r2, [r1]
	lsls r3, r2, #0x18
	lsrs r3, r3, #0x18
	movs r4, #0x34
	strb r3, [r0, r4]
	lsls r4, r2, #8
	lsrs r4, r4, #0x18
	movs r5, #0x36
	strb r4, [r0, r5]
	movs r4, #7
	ands r3, r4
	bne _08004876
	ldr r3, [r1, #4]
	str r3, [r0, #0x38]
	b _080048B6
_08004876:
	cmp r3, #2
	bgt _08004894
	lsrs r3, r2, #0x18
	movs r4, #0x80
	ands r4, r3
	bne _0800488A
	movs r4, #0x70
	ands r4, r3
	beq _0800488A
	b _0800488C
_0800488A:
	movs r3, #8
_0800488C:
	movs r4, #0x37
	strb r3, [r0, r4]
	movs r4, #6
	b _080048AE
_08004894:
	cmp r3, #3
	bne _080048A8
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r5, #4]
	bl UploadSampleToWaveRam
	adds r0, r4, #0
	adds r1, r5, #0
	b _080048B6
_080048A8:
	cmp r3, #4
	bne _080048B6
	movs r4, #3
_080048AE:
	ldr r3, [r1, #4]
	lsls r3, r4
	movs r4, #0x38
	strb r3, [r0, r4]
_080048B6:
	ldr r2, [r1, #8]
	str r2, [r0, #0x3c]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start unk_48c0
unk_48c0: @ 0x080048C0
	movs r1, #0x19
	ldrsb r1, [r0, r1]
	cmp r1, #0
	ble _080048CA
	adds r1, #1
_080048CA:
	ldr r2, [r0, #0x1c]
	ldrb r3, [r0, #0x1a]
	muls r1, r3, r1
	lsls r1, r1, #2
	lsls r3, r2, #0x18
	asrs r3, r3, #0x18
	lsls r3, r3, #8
	adds r1, r1, r3
	lsls r3, r2, #0x10
	asrs r3, r3, #0x18
	lsls r3, r3, #8
	adds r1, r1, r3
	lsls r3, r2, #8
	asrs r3, r3, #0x16
	lsls r3, r3, #2
	adds r1, r1, r3
	lsrs r2, r2, #0x18
	adds r1, r1, r2
	movs r3, #0x10
	ldr r2, [r0, r3]
	movs r3, #0xff
	ands r3, r2
	beq _08004912
	movs r3, #0xff
	lsls r3, r3, #8
	ands r3, r2
	beq _08004912
	lsls r3, r2, #8
	lsrs r3, r3, #0x18
	cmp r3, #0
	bne _08004912
	asrs r2, r2, #0x18
	lsls r2, r2, #2
	movs r3, #0xc
	muls r2, r3, r2
	adds r1, r1, r2
_08004912:
	asrs r2, r1, #8
	strb r2, [r0, #0x17]
	strb r1, [r0, #0x18]
	bx lr
	.align 2, 0

	thumb_func_start unk_491c
unk_491c: @ 0x0800491C
	push {r4}
	ldr r1, [r0, #4]
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r1, #0x10
	lsrs r3, r3, #0x18
	muls r2, r3, r2
	lsrs r2, r2, #5
	ldrh r3, [r0, #0x12]
	lsls r4, r3, #0x18
	lsrs r4, r4, #0x18
	cmp r4, #1
	bne _08004946
	lsls r4, r3, #0x10
	asrs r4, r4, #0x18
	adds r4, #0x41
	muls r2, r4, r2
	asrs r2, r2, #6
	cmp r2, #0xff
	blt _08004946
	movs r2, #0xff
_08004946:
	lsls r4, r1, #8
	lsrs r4, r4, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r4
	subs r1, #0x40
	cmp r1, #0x3f
	blt _08004958
	movs r1, #0x3f
	b _08004962
_08004958:
	movs r4, #0x40
	rsbs r4, r4, #0
	cmp r1, r4
	bpl _08004962
	rsbs r1, r4, #0
_08004962:
	lsls r4, r3, #0x18
	lsrs r4, r4, #0x18
	cmp r4, #2
	bne _08004980
	lsls r4, r3, #0x10
	asrs r4, r4, #0x18
	adds r1, r1, r4
	cmp r1, #0x3f
	blt _08004978
	movs r1, #0x3f
	b _08004980
_08004978:
	movs r4, #0x40
	adds r3, r1, r4
	bpl _08004980
	rsbs r1, r4, #0
_08004980:
	movs r4, #0x40
	adds r3, r1, r4
	muls r3, r2, r3
	lsrs r3, r3, #7
	subs r4, r4, r1
	muls r4, r2, r4
	lsrs r4, r4, #7
	lsls r4, r4, #8
	orrs r3, r4
	strh r3, [r0, #8]
	pop {r4}
	bx lr

	thumb_func_start unk_4998
unk_4998: @ 0x08004998
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldrb r1, [r4, #0x13]
	movs r2, #2
	orrs r1, r2
	strb r1, [r4, #0x13]
	bl unk_1e14
	ldr r0, [r5, #0x48]
	cmp r0, #0
	beq _080049B4
	str r4, [r0, #0x2c]
_080049B4:
	str r0, [r4, #0x30]
	movs r1, #0
	str r1, [r4, #0x2c]
	str r5, [r4, #0x28]
	str r4, [r5, #0x48]
	movs r1, #0x34
	ldrb r0, [r5, r1]
	ldrb r1, [r5, #6]
	lsls r0, r0, #8
	lsls r6, r6, #0x10
	lsls r1, r1, #0x18
	movs r2, #1
	orrs r0, r1
	orrs r0, r2
	orrs r0, r6
	str r0, [r4]
	ldr r0, [r5, #0x3c]
	str r0, [r4, #8]
	ldr r0, [r5, #0xc]
	str r0, [r4, #0xc]
	movs r1, #0x10
	movs r2, #0xc
	ldr r0, [r5, #0x38]
	adds r1, r1, r0
	adds r2, r2, r0
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	str r2, [r4, #0x14]
	ldrh r1, [r5]
	lsrs r2, r1, #8
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	strb r2, [r4, #6]
	movs r3, #0xf0
	ands r1, r3
	cmp r1, #0x80
	bne _08004A02
	movs r3, #0x35
	ldrb r2, [r5, r3]
_08004A02:
	strb r2, [r4, #7]
	movs r3, #0x17
	ldrsb r1, [r5, r3]
	adds r1, r1, r2
	bmi _08004A14
	cmp r1, #0x7f
	ble _08004A16
	movs r1, #0x7f
	b _08004A16
_08004A14:
	movs r1, #0
_08004A16:
	ldrb r2, [r5, #0x18]
	bl MidiKey2Freq
	ldr r1, _08004A38 @ =gMusicInfo
	ldrh r2, [r1, #0x12]
	cmp r0, r2
	bne _08004A2A
	movs r0, #0x40
	lsls r0, r0, #8
	b _08004A30
_08004A2A:
	ldr r1, [r1, #0x18]
	bl CallGetNoteFrequency
_08004A30:
	str r0, [r4, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08004A38: .4byte gMusicInfo

	thumb_func_start unk_4a3c
unk_4a3c: @ 0x08004A3C
	ldr r1, [r0, #0x24]
	adds r1, #1
	movs r2, #3
	ands r2, r1
	bne _08004A4A
	ldr r2, [r1]
	b _08004A76
_08004A4A:
	movs r2, #1
	ands r2, r1
	bne _08004A5C
	ldrh r2, [r1]
	adds r1, #2
	ldrh r3, [r1]
	lsls r3, r3, #0x10
	orrs r2, r3
	b _08004A76
_08004A5C:
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	lsls r3, r3, #8
	orrs r2, r3
	adds r1, #1
	ldrb r3, [r1]
	lsls r3, r3, #0x10
	orrs r2, r3
	adds r1, #1
	ldrb r3, [r1]
	lsls r3, r3, #0x18
	orrs r2, r3
_08004A76:
	str r2, [r0, #0x24]
	bx lr
	.align 2, 0

	thumb_func_start unk_4a7c
unk_4a7c: @ 0x08004A7C
	ldr r1, [r0, #0x24]
	adds r1, #1
	movs r2, #3
	ands r2, r1
	bne _08004A8C
	ldr r2, [r1]
	adds r1, #4
	b _08004ABC
_08004A8C:
	movs r2, #1
	ands r2, r1
	bne _08004AA0
	ldrh r2, [r1]
	adds r1, #2
	ldrh r3, [r1]
	lsls r3, r3, #0x10
	orrs r2, r3
	adds r1, #2
	b _08004ABC
_08004AA0:
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	lsls r3, r3, #8
	orrs r2, r3
	adds r1, #1
	ldrb r3, [r1]
	lsls r3, r3, #0x10
	orrs r2, r3
	adds r1, #1
	ldrb r3, [r1]
	lsls r3, r3, #0x18
	orrs r2, r3
	adds r1, #1
_08004ABC:
	str r2, [r0, #0x24]
	adds r0, #0x28
	ldr r2, [r0]
	cmp r2, #0
	beq _08004AD6
	adds r0, #4
	ldr r2, [r0]
	cmp r2, #0
	beq _08004AD6
	adds r0, #4
	ldr r2, [r0]
	cmp r2, #0
	bne _08004AD8
_08004AD6:
	str r1, [r0]
_08004AD8:
	bx lr
	.align 2, 0

	thumb_func_start UploadSampleToWaveRam
UploadSampleToWaveRam: @ 0x08004ADC
	ldr r3, _08004B08 @ =0x04000070
	movs r2, #0x40
	strb r2, [r3]
	ldr r1, _08004B0C @ =0x04000090
	ldr r2, [r0]
	str r2, [r1]
	adds r0, #4
	adds r1, #4
	ldr r2, [r0]
	str r2, [r1]
	adds r0, #4
	adds r1, #4
	ldr r2, [r0]
	str r2, [r1]
	adds r0, #4
	adds r1, #4
	ldr r2, [r0]
	str r2, [r1]
	movs r2, #0
	strb r2, [r3]
	bx lr
	.align 2, 0
_08004B08: .4byte 0x04000070
_08004B0C: .4byte 0x04000090

	thumb_func_start unk_4b10
unk_4b10: @ 0x08004B10
	push {r4, r5}
	ldr r4, [r0, #0x10]
	ldrh r5, [r0, #0x14]
	ldr r1, [r0, #0x24]
	movs r2, #0x34
	ldrb r1, [r1, r2]
	cmp r1, #8
	ble _08004B4A
	movs r2, #4
	movs r3, #0x89
	lsls r2, r2, #0x18
	orrs r2, r3
	ldrb r2, [r2]
	lsrs r2, r2, #6
	lsls r2, r2, #6
	movs r3, #0x40
	cmp r2, r3
	bge _08004B38
	adds r5, #2
	b _08004B40
_08004B38:
	movs r3, #0x80
	cmp r2, r3
	bge _08004B4A
	adds r5, #1
_08004B40:
	movs r2, #0xc7
	movs r3, #0xfe
	lsls r2, r2, #8
	orrs r2, r3
	ands r5, r2
_08004B4A:
	movs r2, #4
	movs r3, #0x60
	lsls r2, r2, #0x18
	orrs r2, r3
	movs r3, #7
	ands r1, r3
	lsls r3, r4, #8
	lsrs r3, r3, #0x10
	cmp r1, #1
	beq _08004B6C
	cmp r1, #2
	beq _08004B7E
	cmp r1, #3
	beq _08004B84
	cmp r1, #4
	beq _08004B8C
	b _08004B90
_08004B6C:
	strb r4, [r2]
	strh r3, [r2, #2]
	strh r5, [r2, #4]
	mov r8, r8
	mov r8, r8
	mov r8, r8
	mov r8, r8
	strh r5, [r2, #4]
	b _08004B90
_08004B7E:
	strh r3, [r2, #8]
	strh r5, [r2, #0xc]
	b _08004B90
_08004B84:
	strb r4, [r2, #0x10]
	strh r3, [r2, #0x12]
	strh r5, [r2, #0x14]
	b _08004B90
_08004B8C:
	strh r3, [r2, #0x18]
	strh r5, [r2, #0x1c]
_08004B90:
	lsls r5, r5, #0x11
	lsrs r5, r5, #0x11
	strh r5, [r0, #0x14]
	pop {r4, r5}
	bx lr
	.align 2, 0
