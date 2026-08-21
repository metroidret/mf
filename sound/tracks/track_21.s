.align 2

.global track_21

track_21_0:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte PRIO, 110
	.byte W78
	.byte W01
	.byte VOICE, 7
	.byte VOL, 43
	.byte N92, Cn3, v056
	.byte W02
	.byte VOL, 44
	.byte W04
	.byte 45 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W04
	.byte 48 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W01
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W04
	.byte 45 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W04
	.byte 48 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W04
	.byte 51 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W04
	.byte 55 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W04
	.byte 58 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W48
	.byte W15
	.byte 50 @ VOL
	.byte TIE, Dn3 @ v056
	.byte W48
	.byte W01
	.byte VOL, 50
	.byte W32
	.byte W36
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W04
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W24
	.byte W02
	.byte EOT @ Dn3, v056
	.byte W32
	.byte W01
	.byte W66
track_21_lbl_25ff42:
	.byte W30
	.byte W96
	.byte W96
	.byte W96
	.byte W66
	.byte GOTO
		.word track_21_lbl_25ff42
	.byte FINE

track_21_1:
	.byte KEYSH, 0
	.byte PRIO, 109
	.byte W44
	.byte W01
	.byte VOICE, 4
	.byte VOL, 18
	.byte BENDR, 2
	.byte BEND, c_v+21
	.byte N36, Cn3, v056
	.byte W02
	.byte VOL, 20
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W28
	.byte W01
	.byte W72
	.byte W03
	.byte VOICE, 7
	.byte VOL, 50
	.byte BEND, c_v
	.byte N36, Cs3 @ v056
	.byte W21
	.byte W32
	.byte W01
	.byte VOICE, 12
	.byte VOL, 94
	.byte W32
	.byte W01
	.byte N06, Cn3, v120
	.byte W14
	.byte Cn3, v056 @ N06
	.byte W16
track_21_lbl_25ff99:
	.byte W06
	.byte N06, Cn3, v092
	.byte W60
	.byte Cn3, v120 @ N06
	.byte W14
	.byte Cn3, v056 @ N06
	.byte W16
	.byte PEND
	.byte PATT
		.word track_21_lbl_25ff99
	.byte W06
	.byte N06, Cn3, v092
	.byte W60
track_21_lbl_25ffaf:
	.byte N06, Cn3, v120
	.byte W14
	.byte Cn3, v056 @ N06
	.byte W16
	.byte PATT
		.word track_21_lbl_25ff99
	.byte PATT
		.word track_21_lbl_25ff99
	.byte PATT
		.word track_21_lbl_25ff99
	.byte W06
	.byte N06, Cn3, v092
	.byte W60
	.byte GOTO
		.word track_21_lbl_25ffaf
	.byte FINE

track_21_2:
	.byte KEYSH, 0
	.byte PRIO, 108
	.byte W44
	.byte W01
	.byte VOICE, 19
	.byte VOL, 23
	.byte N92, En1, v112
	.byte W48
	.byte W03
	.byte W42
	.byte TIE @ En1, v112
	.byte W36
	.byte W01
	.byte VOL, 23
	.byte W06
	.byte 25 @ VOL
	.byte W06
	.byte 26 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 31 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W06
	.byte 40 @ VOL
	.byte W06
	.byte 42 @ VOL
	.byte W06
	.byte 44 @ VOL
	.byte W06
	.byte 45 @ VOL
	.byte W06
	.byte 47 @ VOL
	.byte W06
	.byte 48 @ VOL
	.byte W06
	.byte 50 @ VOL
	.byte W05
	.byte 51 @ VOL
	.byte W06
	.byte 53 @ VOL
	.byte W01
	.byte W05
	.byte 55 @ VOL
	.byte W06
	.byte 56 @ VOL
	.byte W06
	.byte 58 @ VOL
	.byte W06
	.byte 59 @ VOL
	.byte W06
	.byte 61 @ VOL
	.byte W06
	.byte 62 @ VOL
	.byte W06
	.byte 64 @ VOL
	.byte W06
	.byte 66 @ VOL
	.byte W06
	.byte 67 @ VOL
	.byte W06
	.byte 69 @ VOL
	.byte W06
	.byte 70 @ VOL
	.byte W06
	.byte 72 @ VOL
	.byte W06
	.byte 74 @ VOL
	.byte W06
	.byte 75 @ VOL
	.byte W05
	.byte 77 @ VOL
	.byte W06
	.byte 78 @ VOL
	.byte W02
	.byte W96
	.byte W20
	.byte 77 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte EOT @ En1, v112
track_21_lbl_260080:
	.byte PRIO, 110
	.byte VOL, 45
	.byte TIE, En1, v112
	.byte W03
	.byte VOL, 47
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W08
	.byte 74 @ VOL
	.byte W08
	.byte 72 @ VOL
	.byte W08
	.byte 70 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W02
	.byte W01
	.byte 70 @ VOL
	.byte W04
	.byte 70 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W08
	.byte 74 @ VOL
	.byte W09
	.byte 72 @ VOL
	.byte W08
	.byte 70 @ VOL
	.byte W04
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte EOT @ En1, v112
	.byte VOL, 50
	.byte TIE @ En1, v112
	.byte W02
	.byte VOL, 51
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W02
	.byte 77 @ VOL
	.byte W04
	.byte 77 @ VOL
	.byte W07
	.byte 78 @ VOL
	.byte W08
	.byte 77 @ VOL
	.byte W09
	.byte 77 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W02
	.byte W01
	.byte 69 @ VOL
	.byte W06
	.byte 70 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W08
	.byte 74 @ VOL
	.byte W09
	.byte 72 @ VOL
	.byte W07
	.byte 70 @ VOL
	.byte W05
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W01
	.byte EOT @ En1, v112
	.byte GOTO
		.word track_21_lbl_260080
	.byte FINE

.align 2

track_21:
	.byte 3
	.byte 21
	.byte 130
	.byte 128
	.word 0x80a61fc
	.word track_21_0
	.word track_21_1
	.word track_21_2

.align 2
