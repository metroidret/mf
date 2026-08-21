.align 2

.global track_424

track_424_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 55
	.byte PAN, c_v
	.byte N04, Cn2, v100
	.byte W04
	.byte N10, Fn2, v127
	.byte W06
	.byte VOL, 34
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte FINE

.align 2

track_424:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_424_0

.align 2
