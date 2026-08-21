.align 2

.global track_298

track_298_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 120
	.byte PAN, c_v
	.byte N16, Cn3, v127
	.byte W16
	.byte FINE

.align 2

track_298:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_298_0

.align 2
