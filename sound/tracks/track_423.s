.align 2

.global track_423

track_423_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 60
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte Gn2, v100 @ N04
	.byte W04
	.byte Cn2, v080 @ N04
	.byte W04
	.byte FINE

.align 2

track_423:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_423_0

.align 2
