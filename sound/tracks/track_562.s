.align 2

.global track_562

track_562_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 2
	.byte W04
	.byte N10, Cn3, v060
	.byte W10
	.byte Cn3, v127 @ N10
	.byte W10
	.byte Cn3, v080 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W10
	.byte Cn3, v100 @ N10
	.byte W10
	.byte Cn3, v040 @ N10
	.byte W10
	.byte Cn3, v060 @ N10
	.byte W10
	.byte Cn3, v012 @ N10
	.byte W22
	.byte W96
	.byte FINE

track_562_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 2
	.byte N10, Cn3, v127
	.byte W10
	.byte Cn3, v080 @ N10
	.byte W10
	.byte Cn3, v040 @ N10
	.byte W10
	.byte Cn3, v100 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W10
	.byte Cn3, v020 @ N10
	.byte W10
	.byte Cn3, v100 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W24
	.byte W02
	.byte W96
	.byte FINE

track_562_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 2
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
	.byte W04
	.byte VOICE, 5
	.byte VOL, 120
	.byte W02
	.byte N04 @ Cn3, v127
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
	.byte W04
	.byte VOICE, 5
	.byte VOL, 37
	.byte W02
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 6
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v060
	.byte W16
	.byte VOICE, 2
	.byte VOL, 56
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Cn3, v127
	.byte W06
	.byte W08
	.byte N12, Cn3, v052
	.byte W12
	.byte VOL, 37
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Cn3, v127
	.byte W14
	.byte N12, Cn3, v052
	.byte W12
	.byte VOL, 18
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Cn3, v127
	.byte W14
	.byte N12, Cn3, v052
	.byte W24
	.byte FINE

track_562_3:
	.byte KEYSH, 0
	.byte W48
	.byte VOICE, 8
	.byte VOL, 120
	.byte PAN, c_v
	.byte W02
	.byte N05, Fn2, v127
	.byte W03
	.byte N12, Gs2, v112
	.byte W42
	.byte W01
	.byte W06
	.byte VOICE, 9
	.byte N24, En2, v127
	.byte W90
	.byte FINE

track_562_4:
	.byte KEYSH, 0
	.byte W48
	.byte VOICE, 20
	.byte MOD, 10
	.byte VOL, 76
	.byte PAN, c_v
	.byte LFOS, 20
	.byte N36, As2, v120
	.byte W02
	.byte VOL, 59
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W04
	.byte 82 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W14
	.byte W21
	.byte N14, As2, v080
	.byte W32
	.byte VOL, 37
	.byte N32, As2, v040
	.byte W02
	.byte VOL, 57
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 82 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W04
	.byte 84 @ VOL
	.byte W02
	.byte 81 @ VOL
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W11
	.byte FINE

track_562_5:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 120
	.byte PAN, c_v
	.byte W84
	.byte W01
	.byte N02, Cn4, v020
	.byte W02
	.byte N03, Gn3, v052
	.byte W03
	.byte N04, Cn3, v080
	.byte W04
	.byte N03, Cn3, v040
	.byte W02
	.byte W32
	.byte W02
	.byte VOL, 56
	.byte N02, Dn4, v020
	.byte W03
	.byte N03, An3, v052
	.byte W04
	.byte N04, Cn3, v080
	.byte W44
	.byte W02
	.byte VOL, 18
	.byte N04, Cn3, v072
	.byte W05
	.byte Cs4, v080 @ N04
	.byte W04
	.byte FINE

.align 2

track_562:
	.byte 6
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_562_0
	.word track_562_1
	.word track_562_2
	.word track_562_3
	.word track_562_4
	.word track_562_5

.align 2
