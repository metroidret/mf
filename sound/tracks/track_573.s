.align 2

.global track_573

track_573_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 120
	.byte PAN, c_v
	.byte N24, Cn3, v127
	.byte W24
	.byte Cn3, v060 @ N24
	.byte W24
	.byte N20, Cn3, v020
	.byte W20
	.byte FINE

track_573_1:
	.byte KEYSH, 0
	.byte VOICE, 61
	.byte VOL, 94
	.byte PAN, c_v
	.byte N24, Cn3, v112
	.byte W24
	.byte N44, Cn3, v100
	.byte W44
	.byte FINE

.align 2

track_573:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_573_0
	.word track_573_1

.align 2
