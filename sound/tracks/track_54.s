.align 2

.global track_54

track_54_0:
	.byte KEYSH, 0
track_54_lbl_268612:
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 28
	.byte PAN, c_v
	.byte PRIO, 109
	.byte N48, Fs5, v076
	.byte W48
	.byte N07, Gn5, v084
	.byte W12
	.byte Gn5, v064 @ N07
	.byte W12
track_54_lbl_268627:
	.byte N48, Fs5, v060
	.byte W48
	.byte N07, Gn5, v084
	.byte W12
	.byte Gn5, v064 @ N07
	.byte W12
	.byte PEND
track_54_lbl_268633:
	.byte N48, En5, v060
	.byte W48
	.byte N07, Fn5, v084
	.byte W12
	.byte Fn5, v064 @ N07
	.byte W12
	.byte PEND
	.byte PATT
		.word track_54_lbl_268633
	.byte N48, Fs5, v076
	.byte W48
	.byte N07, Gn5, v084
	.byte W12
	.byte Gn5, v064 @ N07
	.byte W12
	.byte PATT
		.word track_54_lbl_268627
	.byte PATT
		.word track_54_lbl_268633
	.byte N40, En5, v052
	.byte W05
	.byte VOL, 55
	.byte W09
	.byte 53 @ VOL
	.byte W06
	.byte 52 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte N06, Ds5, v064
	.byte W08
	.byte N08, Ds5, v072
	.byte W08
	.byte En5, v076 @ N08
	.byte W08
	.byte Fn5, v080 @ N08
	.byte W08
	.byte GOTO
		.word track_54_lbl_268612
	.byte FINE

track_54_1:
	.byte KEYSH, 0
track_54_lbl_268699:
	.byte VOICE, 18
	.byte VOL, 56
	.byte PAN, c_v-4
	.byte PRIO, 108
	.byte N08, Cs1, v084
	.byte W08
	.byte Cs2, v056 @ N08
	.byte W08
	.byte Cs3, v052 @ N08
	.byte W08
	.byte N06, Cs4, v016
	.byte W08
	.byte Cs4, v012 @ N06
	.byte W16
	.byte N04, Cs4, v016
	.byte W12
	.byte Cs3, v048 @ N04
	.byte W12
track_54_lbl_2686b9:
	.byte N08, Cs1, v084
	.byte W08
	.byte Cs2, v056 @ N08
	.byte W08
	.byte Cs3, v052 @ N08
	.byte W08
	.byte N06, Cs4, v016
	.byte W08
	.byte Cs4, v012 @ N06
	.byte W16
	.byte N04, Cs4, v016
	.byte W12
	.byte Cs3, v048 @ N04
	.byte W12
	.byte PEND
track_54_lbl_2686d2:
	.byte N08, Bn0, v084
	.byte W08
	.byte Bn1 @ N08, v084
	.byte W08
	.byte Bn2, v052 @ N08
	.byte W08
	.byte N06, Bn3, v016
	.byte W08
	.byte Bn3, v012 @ N06
	.byte W16
	.byte N04, Cn4, v016
	.byte W12
	.byte Cn3, v048 @ N04
	.byte W12
	.byte PEND
	.byte PATT
		.word track_54_lbl_2686d2
	.byte PATT
		.word track_54_lbl_2686b9
	.byte PATT
		.word track_54_lbl_2686b9
	.byte PATT
		.word track_54_lbl_2686d2
	.byte N08, Bn0, v084
	.byte W08
	.byte Bn1 @ N08, v084
	.byte W08
	.byte Bn2, v052 @ N08
	.byte W08
	.byte N06, Bn3, v016
	.byte W08
	.byte Bn3, v012 @ N06
	.byte W08
	.byte Ds3, v056 @ N06
	.byte W08
	.byte Ds3, v072 @ N06
	.byte W08
	.byte En3 @ N06, v072
	.byte W08
	.byte Fn3 @ N06, v072
	.byte W08
	.byte GOTO
		.word track_54_lbl_268699
	.byte FINE

track_54_2:
	.byte KEYSH, 0
track_54_lbl_268720:
	.byte VOICE, 18
	.byte VOL, 21
	.byte PAN, c_v+16
	.byte PRIO, 108
	.byte N48, As3, v068
	.byte W48
	.byte N06, Bn3, v072
	.byte W12
	.byte N06 @ Bn3, v072
	.byte W12
track_54_lbl_268732:
	.byte N48, As3, v072
	.byte W48
	.byte N06, Bn3 @ v072
	.byte W12
	.byte N06 @ Bn3, v072
	.byte W12
	.byte PEND
track_54_lbl_26873c:
	.byte N48, Gs3, v068
	.byte W48
	.byte N06, Cn4, v072
	.byte W12
	.byte N06 @ Cn4, v072
	.byte W12
	.byte PEND
	.byte PATT
		.word track_54_lbl_26873c
	.byte N48, As3, v068
	.byte W48
	.byte N06, Bn3, v072
	.byte W12
	.byte N06 @ Bn3, v072
	.byte W12
	.byte PATT
		.word track_54_lbl_268732
	.byte PATT
		.word track_54_lbl_26873c
	.byte N48, Gs3, v068
	.byte W48
	.byte N24, Cn4, v072
	.byte W24
	.byte GOTO
		.word track_54_lbl_268720
	.byte FINE

track_54_3:
	.byte KEYSH, 0
track_54_lbl_268770:
	.byte VOICE, 16
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 29
	.byte N08, Cs1, v116
	.byte W72
	.byte N08 @ Cs1, v116
	.byte W72
	.byte Bn0 @ N08, v116
	.byte W72
	.byte N08 @ Bn0, v116
	.byte W72
	.byte Cs1 @ N08, v116
	.byte W72
	.byte N12 @ Cs1, v116
	.byte W72
	.byte Bn0 @ N12, v116
	.byte W72
	.byte N12 @ Bn0, v116
	.byte W48
	.byte N08, Ds1, v124
	.byte W08
	.byte En1 @ N08, v124
	.byte W08
	.byte Fn1 @ N08, v124
	.byte W08
	.byte GOTO
		.word track_54_lbl_268770
	.byte FINE

track_54_4:
	.byte KEYSH, 0
track_54_lbl_26879a:
	.byte VOICE, 0
	.byte VOL, 85
	.byte PRIO, 1
	.byte N24, Dn1, v100
	.byte W24
	.byte Cs2, v048 @ N24
	.byte W24
	.byte N06, Cs2, v040
	.byte W06
	.byte Cs2, v048 @ N06
	.byte W06
	.byte N06 @ Cs2, v048
	.byte W06
	.byte N24 @ Cs2, v048
	.byte W06
track_54_lbl_2687b2:
	.byte W24
	.byte N24, Cs2, v048
	.byte W24
	.byte N08, En1, v072
	.byte W08
	.byte En1, v036 @ N08
	.byte W08
	.byte N08 @ En1, v036
	.byte W08
	.byte PEND
track_54_lbl_2687c1:
	.byte N24, Cs2, v012
	.byte W24
	.byte Cs2, v048 @ N24
	.byte W24
	.byte N06, Cs2, v040
	.byte W06
	.byte Cs2, v048 @ N06
	.byte W06
	.byte N06 @ Cs2, v048
	.byte W06
	.byte N24 @ Cs2, v048
	.byte W06
	.byte PEND
	.byte W24
	.byte N03, Fs1, v020
	.byte N24, Cs2, v048
	.byte W03
	.byte N03, Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte N03 @ Fs1, v020
	.byte W03
	.byte Fs1, v032 @ N03
	.byte W03
	.byte Fs1, v040 @ N03
	.byte W03
	.byte Fs1, v052 @ N03
	.byte W03
	.byte Fs1, v060 @ N03
	.byte W03
	.byte Fs1, v072 @ N03
	.byte W03
	.byte Fs1, v080 @ N03
	.byte W03
	.byte Fs1, v092 @ N03
	.byte W03
	.byte N24, Cs2, v032
	.byte W24
	.byte Cs2, v048 @ N24
	.byte W24
	.byte N06, Cs2, v040
	.byte W06
	.byte Cs2, v048 @ N06
	.byte W06
	.byte N06 @ Cs2, v048
	.byte W06
	.byte N24 @ Cs2, v048
	.byte W06
	.byte PATT
		.word track_54_lbl_2687b2
	.byte PATT
		.word track_54_lbl_2687c1
	.byte W24
	.byte N24, Cs2, v048
	.byte W24
	.byte N06, Dn1, v120
	.byte W08
	.byte Dn1, v112 @ N06
	.byte W08
	.byte N06 @ Dn1, v112
	.byte W08
	.byte GOTO
		.word track_54_lbl_26879a
	.byte FINE

.align 2

track_54:
	.byte 5
	.byte 54
	.byte 130
	.byte 128
	.word 0x80a61fc
	.word track_54_0
	.word track_54_1
	.word track_54_2
	.word track_54_3
	.word track_54_4

.align 2
