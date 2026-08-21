.align 2

.global track_301

track_301_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 30
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 13
	.byte N07 @ Cn3, v127
	.byte W07
	.byte Cn3, v052 @ N07
	.byte W07
	.byte Cn3, v012 @ N07
	.byte W07
	.byte FINE

.align 2

track_301:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_301_0

.align 2
