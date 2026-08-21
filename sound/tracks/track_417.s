.align 2

.global track_417

track_417_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 70
	.byte PAN, c_v
	.byte N04, Gn2, v127
	.byte W04
	.byte Gn3 @ N04, v127
	.byte W04
	.byte Cn3, v100 @ N04
	.byte W04
	.byte N06, Dn3 @ v100
	.byte W06
	.byte FINE

.align 2

track_417:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_417_0

.align 2
