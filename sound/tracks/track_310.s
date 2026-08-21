.align 2

.global track_310

track_310_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 62
	.byte PAN, c_v
	.byte N24, Cn3, v127
	.byte W24
	.byte FINE

.align 2

track_310:
	.byte 1
	.byte 0
	.byte 198
	.byte 0
	.word 0x80a82f0
	.word track_310_0

.align 2
