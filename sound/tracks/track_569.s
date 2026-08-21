.align 2

.global track_569

track_569_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 85
	.byte PAN, c_v+6
	.byte PRIO, 1
track_569_lbl_2837ec:
	.byte N06, Cn3, v100
	.byte W09
	.byte N06 @ Cn3, v100
	.byte W11
	.byte N06 @ Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W13
	.byte W02
	.byte N06, Cn3, v100
	.byte W07
	.byte W03
	.byte N06 @ Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W11
	.byte W03
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W01
	.byte W10
	.byte W01
	.byte N06, Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W24
	.byte W02
	.byte GOTO
		.word track_569_lbl_2837ec
	.byte FINE

track_569_1:
	.byte KEYSH, 0
	.byte VOL, 85
	.byte PAN, c_v+6
track_569_lbl_283848:
	.byte W03
	.byte VOICE, 1
	.byte W02
	.byte N05, Fn3, v100
	.byte W10
	.byte N05 @ Fn3, v100
	.byte W10
	.byte N05 @ Fn3, v100
	.byte W10
	.byte N05 @ Fn3, v100
	.byte W10
	.byte N09 @ Fn3, v100
	.byte W09
	.byte VOICE, 41
	.byte W01
	.byte N10, Gs2 @ v100
	.byte W10
	.byte N28, Cs2, v127
	.byte W22
	.byte VOICE, 1
	.byte W07
	.byte N05, Fn3, v100
	.byte W02
	.byte W08
	.byte N05 @ Fn3, v100
	.byte W10
	.byte N09 @ Fn3, v100
	.byte W09
	.byte VOICE, 41
	.byte W01
	.byte N10, Gs2 @ v100
	.byte W10
	.byte N28, Cs2, v127
	.byte W24
	.byte W01
	.byte VOICE, 1
	.byte W03
	.byte N09, Fn3, v100
	.byte W09
	.byte VOICE, 41
	.byte W01
	.byte N10, Gs2 @ v100
	.byte W10
	.byte N24, Cs2, v127
	.byte W10
	.byte W15
	.byte VOICE, 1
	.byte W01
	.byte N05, Fn3, v100
	.byte W10
	.byte N09 @ Fn3, v100
	.byte W09
	.byte VOICE, 41
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
	.byte N36, Cs2, v127
	.byte W32
	.byte W03
	.byte GOTO
		.word track_569_lbl_283848
	.byte W01
	.byte FINE

track_569_2:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte PAN, c_v+6
	.byte BENDR, 12
	.byte PRIO, 2
	.byte BEND, c_v
track_569_lbl_2838b2:
	.byte VOL, 75
	.byte BEND, c_v
	.byte W01
	.byte N72, Cn3, v080
	.byte W23
	.byte VOL, 74
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 40
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W01
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 17
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W24
	.byte W02
	.byte W60
	.byte W01
	.byte 75 @ VOL
	.byte BEND, c_v
	.byte W01
	.byte N72, Cn3, v052
	.byte W23
	.byte VOL, 74
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W01
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 30
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W01
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 18
	.byte W04
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W44
	.byte W02
	.byte GOTO
		.word track_569_lbl_2838b2
	.byte FINE

.align 2

track_569:
	.byte 3
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a7798
	.word track_569_0
	.word track_569_1
	.word track_569_2

.align 2
