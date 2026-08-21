.align 2

.global track_285

track_285_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Gn2, v127
	.byte W05
	.byte VOICE, 19
	.byte N07, Cn2 @ v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_285:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_285_0

.align 2
