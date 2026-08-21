.align 2

.global track_556

track_556_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 25
	.byte PAN, c_v-64
	.byte PRIO, 123
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

track_556_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 25
	.byte PAN, c_v-64
	.byte PRIO, 123
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

track_556_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 25
	.byte PAN, c_v-64
	.byte PRIO, 123
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
	.byte VOL, 12
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

track_556_3:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 40
	.byte PAN, c_v
	.byte PRIO, 122
	.byte TIE, Gn3, v127
	.byte W03
	.byte VOL, 39
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W06
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W06
	.byte 0 @ VOL
	.byte W06
	.byte 0 @ VOL
	.byte W03
	.byte EOT @ Gn3, v127
	.byte W68
	.byte FINE

track_556_4:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 40
	.byte PAN, c_v-64
	.byte PRIO, 122
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

track_556:
	.byte 5
	.byte 0
	.byte 129
	.byte 0
	.word 0x80a7798
	.word track_556_0
	.word track_556_1
	.word track_556_2
	.word track_556_3
	.word track_556_4

.align 2
