.align 2

.global track_422

track_422_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 25
	.byte PAN, c_v
	.byte N08, Cn3, v080
	.byte W11
	.byte N08 @ Cn3, v080
	.byte W08
	.byte FINE

.align 2

track_422:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_422_0

.align 2
