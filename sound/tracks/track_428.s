.align 2

.global track_428

track_428_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 23
	.byte PAN, c_v
	.byte N04, Gn2, v100
	.byte W06
	.byte VOICE, 76
	.byte N04, Gn2, v080
	.byte W06
	.byte An2, v100 @ N04
	.byte W07
	.byte En3, v120 @ N04
	.byte W04
	.byte FINE

.align 2

track_428:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_428_0

.align 2
