.align 2

.global track_332

track_332_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 30
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte FINE

.align 2

track_332:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word 0x80a6d54
	.word track_332_0

.align 2
