.align 2

.global track_550

track_550_0:
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
	.byte W44
	.byte W03
	.byte W92
	.byte FINE

track_550_1:
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
	.byte W48
	.byte W03
	.byte W92
	.byte FINE

track_550_2:
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
	.byte W32
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
	.byte W10
	.byte W92
	.byte FINE

track_550_3:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte W32
	.byte W01
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, Cn3, v040
	.byte W28
	.byte W01
	.byte W92
	.byte FINE

track_550_4:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 127
	.byte PAN, c_v
	.byte N05, Fn2, v127
	.byte W05
	.byte N12, Gs2 @ v127
	.byte W42
	.byte W01
	.byte VOICE, 9
	.byte N60, Dn2 @ v127
	.byte W48
	.byte W92
	.byte FINE

.align 2

track_550:
	.byte 5
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_550_0
	.word track_550_1
	.word track_550_2
	.word track_550_3
	.word track_550_4

.align 2
