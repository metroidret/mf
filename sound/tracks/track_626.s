.align 2

.global track_626

track_626_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 113
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Ds3, v127
	.byte W14
	.byte Cs3, v052 @ N14
	.byte W14
	.byte VOICE, 18
	.byte N15, Cn3, v020
	.byte W28
	.byte W01
	.byte FINE

track_626_1:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 120
	.byte PAN, c_v
	.byte W05
	.byte N09, Fn3, v100
	.byte W09
	.byte VOICE, 19
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
	.byte N03, Cs2, v127
	.byte W36
	.byte W02
	.byte FINE

.align 2

track_626:
	.byte 2
	.byte 0
	.byte 250
	.byte 0
	.word 0x80a7aa4
	.word track_626_0
	.word track_626_1

.align 2
