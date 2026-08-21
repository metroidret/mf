.align 2

.global track_670

track_670_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3, v100
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N05, Cn3, v020
	.byte W05
	.byte FINE

track_670_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte W04
	.byte N09, Fn3, v100
	.byte W11
	.byte VOICE, 10
	.byte N05, An2, v127
	.byte W10
	.byte N03, Fn2 @ v127
	.byte W14
	.byte FINE

.align 2

track_670:
	.byte 2
	.byte 0
	.byte 178
	.byte 0
	.word 0x80a808c
	.word track_670_0
	.word track_670_1

.align 2
