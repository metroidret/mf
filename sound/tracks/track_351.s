.align 2

.global track_351

track_351_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 50
	.byte PAN, c_v
	.byte N06, Fn3, v127
	.byte W06
	.byte N07, Cn3, v052
	.byte W07
	.byte FINE

.align 2

track_351:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_351_0

.align 2
