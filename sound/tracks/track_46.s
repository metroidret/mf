.align 2

.global track_46

track_46_0:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 7
	.byte VOL, 0
	.byte PAN, c_v
	.byte PRIO, 110
	.byte N96, Cn3, v100
	.byte W01
	.byte VOL, 1
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte N96, Cn3, v092
	.byte W96
track_46_lbl_26493f:
	.byte TIE, Cn3, v092
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W06
	.byte EOT @ Cn3, v092
	.byte GOTO
		.word track_46_lbl_26493f
	.byte W03
	.byte FINE

track_46_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte PAN, c_v-24
	.byte PRIO, 109
	.byte W96
	.byte VOL, 0
	.byte N96, Cn3, v032
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte 1 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W36
	.byte W01
track_46_lbl_264998:
	.byte TIE, Cn3, v032
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W06
	.byte EOT @ Cn3, v032
	.byte GOTO
		.word track_46_lbl_264998
	.byte W03
	.byte FINE

track_46_2:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 23
	.byte PAN, c_v
	.byte PRIO, 108
	.byte N42, Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W10
	.byte W32
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W20
track_46_lbl_2649c3:
	.byte W23
	.byte N42, Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W30
	.byte W13
	.byte N42 @ Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W40
	.byte W03
	.byte N42 @ Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W42
	.byte W01
	.byte N42 @ Cn3, v028
	.byte W07
	.byte W36
	.byte N42 @ Cn3, v028
	.byte W42
	.byte W01
	.byte N23 @ Cn3, v028
	.byte W17
	.byte W06
	.byte GOTO
		.word track_46_lbl_2649c3
	.byte W03
	.byte FINE

track_46_3:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 30
	.byte W48
	.byte N24, As0, v092
	.byte W24
	.byte N24 @ As0, v092
	.byte W24
track_46_lbl_2649f9:
	.byte N24, As0, v092
	.byte W24
	.byte N24 @ As0, v092
	.byte W24
	.byte N24 @ As0, v092
	.byte W24
	.byte N24 @ As0, v092
	.byte W24
	.byte PEND
track_46_lbl_264a04:
	.byte PATT
		.word track_46_lbl_2649f9
	.byte PATT
		.word track_46_lbl_2649f9
	.byte PATT
		.word track_46_lbl_2649f9
	.byte N24, As0, v092
	.byte W24
	.byte N24 @ As0, v092
	.byte W24
	.byte N24 @ As0, v092
	.byte W24
	.byte N30 @ As0, v092
	.byte W24
	.byte W06
	.byte GOTO
		.word track_46_lbl_264a04
	.byte W03
	.byte FINE

track_46_4:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 70
	.byte PAN, c_v-34
	.byte PRIO, 0
	.byte W96
track_46_lbl_264a30:
	.byte W24
	.byte W01
	.byte N05, As3, v040
	.byte W08
	.byte As3, v028 @ N05
	.byte W60
	.byte W03
	.byte PEND
track_46_lbl_264a3b:
	.byte PATT
		.word track_46_lbl_264a30
	.byte PATT
		.word track_46_lbl_264a30
	.byte PATT
		.word track_46_lbl_264a30
	.byte W24
	.byte W01
	.byte N05, As3, v040
	.byte W08
	.byte N05 @ As3, v040
	.byte W60
	.byte W03
	.byte W06
	.byte GOTO
		.word track_46_lbl_264a3b
	.byte FINE

track_46_5:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte PRIO, 30
	.byte W96
	.byte W96
track_46_lbl_264a62:
	.byte VOICE, 11
	.byte VOL, 78
	.byte BENDR, 12
	.byte N44, Cn2, v032
	.byte W07
	.byte BEND, c_v
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+61 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N44 @ Cn2, v032
	.byte W08
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+61 @ BEND
	.byte W01
track_46_lbl_264b13:
	.byte BEND, c_v
	.byte N44, Cn2, v032
	.byte W08
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+61 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N44 @ Cn2, v032
	.byte W08
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+61 @ BEND
	.byte W01
	.byte PEND
	.byte PATT
		.word track_46_lbl_264b13
	.byte BEND, c_v
	.byte N44, Cn2, v032
	.byte W08
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+61 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N52 @ Cn2, v032
	.byte W08
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+44 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+61 @ BEND
	.byte W01
	.byte W04
	.byte c_v @ BEND
	.byte W02
	.byte GOTO
		.word track_46_lbl_264a62
	.byte FINE

track_46_6:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 55
	.byte PAN, c_v
	.byte PRIO, 0
	.byte W96
	.byte BEND, c_v
	.byte W03
	.byte N06, Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W03
track_46_lbl_264c96:
	.byte W12
	.byte N06, Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W09
	.byte W06
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W06
	.byte W09
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W15
	.byte N06 @ Cn4, v052
	.byte W12
	.byte W03
	.byte N06 @ Cn4, v052
	.byte W03
	.byte GOTO
		.word track_46_lbl_264c96
	.byte W03
	.byte FINE

.align 2

track_46:
	.byte 7
	.byte 46
	.byte 130
	.byte 128
	.word 0x80a62f8
	.word track_46_0
	.word track_46_1
	.word track_46_2
	.word track_46_3
	.word track_46_4
	.word track_46_5
	.word track_46_6

.align 2
