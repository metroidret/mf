.align 2

.global track_606

track_606_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 100
	.byte PAN, c_v
	.byte N06, An2, v100
	.byte W06
	.byte N14, Cs3, v127
	.byte W14
	.byte Bn2, v052 @ N14
	.byte W14
	.byte VOICE, 8
	.byte N10, An2, v040
	.byte W24
	.byte W02
	.byte FINE

track_606_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 100
	.byte PAN, c_v
	.byte W05
	.byte N09, Fn3, v100
	.byte W09
	.byte VOICE, 9
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
	.byte N03, Cs2, v120
	.byte W32
	.byte W03
	.byte FINE

.align 2

track_606:
	.byte 2
	.byte 0
	.byte 185
	.byte 0
	.word 0x80a7654
	.word track_606_0
	.word track_606_1

.align 2
