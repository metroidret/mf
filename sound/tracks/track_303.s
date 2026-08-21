.align 2

.global track_303

track_303_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 66
	.byte PAN, c_v
	.byte W04
	.byte N15, Cn3, v060
	.byte W15
	.byte N15 @ Cn3, v060
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte N15 @ Cn3, v127
	.byte W15
	.byte VOICE, 2
	.byte VOL, 18
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3, v127
	.byte W14
	.byte Fs3, v052 @ N14
	.byte W12
	.byte W02
	.byte VOICE, 3
	.byte N10, En3, v040
	.byte W10
	.byte FINE

track_303_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 66
	.byte PAN, c_v
	.byte N15, Cn3, v060
	.byte W15
	.byte N15 @ Cn3, v060
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte N15 @ Cn3, v127
	.byte W15
	.byte VOL, 18
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3, v127
	.byte W14
	.byte Fs3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, En3, v040
	.byte W02
	.byte W12
	.byte FINE

track_303_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 56
	.byte PAN, c_v
	.byte W02
	.byte N04, Cn3, v060
	.byte W05
	.byte Cn3, v080 @ N04
	.byte W05
	.byte Cn3, v100 @ N04
	.byte W04
	.byte VOICE, 6
	.byte N04, Cn3, v127
	.byte W04
	.byte VOICE, 7
	.byte N04 @ Cn3, v127
	.byte W76
	.byte W12
	.byte FINE

track_303_3:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 120
	.byte PAN, c_v
	.byte W02
	.byte N05, Fn2, v127
	.byte W03
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte N01 @ Fn2, v127
	.byte W48
	.byte W03
	.byte W12
	.byte FINE

.align 2

track_303:
	.byte 4
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a808c
	.word track_303_0
	.word track_303_1
	.word track_303_2
	.word track_303_3

.align 2
