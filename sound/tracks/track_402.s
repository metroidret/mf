.align 2

.global track_402

track_402_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-32
	.byte N14, An2, v080
	.byte W02
	.byte BEND, c_v-29
	.byte W02
	.byte c_v-26 @ BEND
	.byte W02
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W01
	.byte VOL, 70
	.byte W01
	.byte 55 @ VOL
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 29
	.byte W02
	.byte FINE

.align 2

track_402:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_402_0

.align 2
