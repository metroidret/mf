.align 2

.global track_625

track_625_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 120
	.byte PAN, c_v
	.byte N05, Bn4, v127
	.byte W15
	.byte Bn4, v040 @ N05
	.byte W11
	.byte N15, Cn3, v020
	.byte W15
	.byte FINE

.align 2

track_625:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_625_0

.align 2
