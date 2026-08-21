.align 2

.global track_284

track_284_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 30
	.byte PAN, c_v
	.byte N05, Cn2, v127
	.byte W05
	.byte VOICE, 19
	.byte N07, Gn2 @ v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_284:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_284_0

.align 2
