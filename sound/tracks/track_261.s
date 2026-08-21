.align 2

.global track_261

track_261_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 60
	.byte PAN, c_v
	.byte N07, Cn3, v127
	.byte W07
	.byte VOICE, 12
	.byte N05, Cn3, v112
	.byte W05
	.byte Bn2, v040 @ N05
	.byte W05
	.byte Gn2, v012 @ N05
	.byte W05
	.byte FINE

.align 2

track_261:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_261_0

.align 2
