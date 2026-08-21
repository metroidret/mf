.align 2

.global track_568

track_568_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W36
track_568_lbl_283647:
	.byte VOL, 42
	.byte N06, Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W06
	.byte W04
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
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W07
	.byte W07
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
	.byte W11
	.byte W01
	.byte N06, Cn3, v100
	.byte W10
	.byte N06 @ Cn3, v100
	.byte W05
	.byte W01
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W20
	.byte GOTO
		.word track_568_lbl_283647
	.byte FINE

track_568_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 120
	.byte PAN, c_v
	.byte W05
	.byte N09, Fn3, v100
	.byte W09
	.byte VOICE, 41
	.byte W01
	.byte N10, Gs2 @ v100
	.byte W10
	.byte N24, Cs2, v127
	.byte W44
	.byte W01
track_568_lbl_2836b7:
	.byte W04
	.byte VOICE, 1
	.byte VOL, 42
	.byte W01
	.byte N05, Fn3, v100
	.byte W10
	.byte N05 @ Fn3, v100
	.byte W10
	.byte N05 @ Fn3, v100
	.byte W01
	.byte W09
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
	.byte W10
	.byte N05 @ Fn3, v100
	.byte W10
	.byte N09 @ Fn3, v100
	.byte W08
	.byte W01
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
	.byte W24
	.byte W01
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
	.byte N28, Cs2, v127
	.byte W28
	.byte W01
	.byte GOTO
		.word track_568_lbl_2836b7
	.byte FINE

track_568_2:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 2
	.byte BEND, c_v
	.byte N72, Cn3, v100
	.byte W23
	.byte VOL, 119
	.byte W02
	.byte 102 @ VOL
	.byte W02
	.byte 91 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 67
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W05
	.byte BEND, c_v-19
	.byte VOL, 59
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
track_568_lbl_28375f:
	.byte W24
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v
	.byte W01
	.byte N72, Cn3, v100
	.byte W24
	.byte VOL, 29
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte BEND, c_v+9
	.byte VOL, 11
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W02
	.byte BEND, c_v-19
	.byte W04
	.byte VOL, 2
	.byte W06
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W06
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W24
	.byte W02
	.byte 42 @ VOL
	.byte BEND, c_v
	.byte W01
	.byte N72, Cn3, v060
	.byte W24
	.byte VOL, 29
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte BEND, c_v+9
	.byte VOL, 11
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W02
	.byte BEND, c_v-19
	.byte W04
	.byte VOL, 2
	.byte W06
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W06
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W24
	.byte W03
	.byte W48
	.byte W01
	.byte GOTO
		.word track_568_lbl_28375f
	.byte FINE

.align 2

track_568:
	.byte 3
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a7798
	.word track_568_0
	.word track_568_1
	.word track_568_2

.align 2
