.align 2

.global track_376

track_376_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 62
	.byte VOL, 60
	.byte PAN, c_v
	.byte N11, Fn3, v127
	.byte W11
	.byte FINE

.align 2

track_376:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_376_0

.align 2
