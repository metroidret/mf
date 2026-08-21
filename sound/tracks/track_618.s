.align 2

.global track_618

track_618_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 43
	.byte PAN, c_v
	.byte N10, Cn3, v127
	.byte W20
	.byte N10 @ Cn3, v127
	.byte W22
	.byte FINE

track_618_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 110
	.byte PAN, c_v
	.byte W02
	.byte N20, Dn3, v127
	.byte W20
	.byte N20 @ Dn3, v127
	.byte W20
	.byte FINE

.align 2

track_618:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_618_0
	.word track_618_1

.align 2
