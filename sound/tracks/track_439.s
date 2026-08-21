.align 2

.global track_439

track_439_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 52
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3, v100
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W10
	.byte FINE

track_439_1:
	.byte KEYSH, 0
	.byte VOICE, 86
	.byte VOL, 80
	.byte PAN, c_v
	.byte W04
	.byte N09, Fn3, v100
	.byte W11
	.byte VOICE, 85
	.byte N05, An2, v127
	.byte W10
	.byte N03, Fn2 @ v127
	.byte W19
	.byte FINE

.align 2

track_439:
	.byte 2
	.byte 0
	.byte 182
	.byte 0
	.word 0x80a6d54
	.word track_439_0
	.word track_439_1

.align 2
