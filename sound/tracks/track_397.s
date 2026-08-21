.align 2

.global track_397

track_397_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 60
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 34
	.byte N10, Fn3, v100
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W06
	.byte FINE

.align 2

track_397:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_397_0

.align 2
