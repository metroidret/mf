.align 2

.global track_340

track_340_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 50
	.byte PAN, c_v
	.byte N04, Dn1, v080
	.byte W04
	.byte Cn2, v127 @ N04
	.byte W04
	.byte N10, Gn1, v080
	.byte W10
	.byte FINE

.align 2

track_340:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_340_0

.align 2
