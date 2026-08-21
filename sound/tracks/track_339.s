.align 2

.global track_339

track_339_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 30
	.byte PAN, c_v
	.byte N07, Cn3, v127
	.byte W07
	.byte FINE

.align 2

track_339:
	.byte 1
	.byte 0
	.byte 136
	.byte 0
	.word 0x80a6d54
	.word track_339_0

.align 2
