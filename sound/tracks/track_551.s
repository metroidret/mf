.align 2

.global track_551

track_551_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 127
	.byte PAN, c_v
	.byte W04
	.byte N15, Cn3, v127
	.byte W15
	.byte N15 @ Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W15
	.byte VOICE, 2
	.byte VOL, 60
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3, v127
	.byte W14
	.byte Fs3, v052 @ N14
	.byte W12
	.byte W02
	.byte VOICE, 3
	.byte N10, En3, v040
	.byte W48
	.byte W03
	.byte FINE

track_551_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte N15 @ Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W13
	.byte VOL, 60
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3, v127
	.byte W14
	.byte Fs3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, En3, v040
	.byte W04
	.byte W52
	.byte W01
	.byte FINE

track_551_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 127
	.byte PAN, c_v
	.byte W02
	.byte N04, Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 6
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 7
	.byte N04 @ Cn3, v127
	.byte W20
	.byte VOICE, 2
	.byte VOL, 60
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, Cn3, v040
	.byte W22
	.byte W52
	.byte W01
	.byte FINE

track_551_3:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 127
	.byte PAN, c_v
	.byte W02
	.byte N05, Fn2, v127
	.byte W03
	.byte N12, Gs2 @ v127
	.byte W48
	.byte W01
	.byte VOICE, 9
	.byte N24, En2 @ v127
	.byte W42
	.byte W52
	.byte W01
	.byte FINE

.align 2

track_551:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_551_0
	.word track_551_1
	.word track_551_2
	.word track_551_3

.align 2
