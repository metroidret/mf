.align 2

.global track_251

track_251_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 75
	.byte PAN, c_v
	.byte N24, Cn3, v127
	.byte W24
	.byte FINE

.align 2

track_251:
	.byte 1
	.byte 0
	.byte 190
	.byte 0
	.word 0x80a71ec
	.word track_251_0

.align 2
