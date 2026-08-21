.align 2

.global track_499

track_499_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 56
	.byte VOL, 60
	.byte PAN, c_v
	.byte N40, Cn3, v127
	.byte W96
	.byte W48
	.byte FINE

track_499_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 28
	.byte PAN, c_v
	.byte W40
	.byte N14, En3, v127
	.byte W14
	.byte Cn3, v060 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, Cn3, v040
	.byte W28
	.byte W48
	.byte FINE

track_499_2:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 51
	.byte PAN, c_v
	.byte N05, Fn2, v127
	.byte W05
	.byte N12, Gs2 @ v127
	.byte W42
	.byte W01
	.byte VOICE, 9
	.byte N48, Dn2 @ v127
	.byte W48
	.byte W48
	.byte FINE

.align 2

track_499:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_499_0
	.word track_499_1
	.word track_499_2

.align 2
