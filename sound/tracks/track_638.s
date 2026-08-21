.align 2

.global track_638

track_638_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 120
	.byte PAN, c_v
	.byte N10, Cn2, v060
	.byte W10
	.byte N18, Cn3, v127
	.byte W18
	.byte Cn3, v040 @ N18
	.byte W18
	.byte N15, Cn3, v020
	.byte W15
	.byte FINE

.align 2

track_638:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_638_0

.align 2
