.align 2

.global track_560

track_560_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte W04
	.byte N15, Cn3, v092
	.byte W15
	.byte N15 @ Cn3, v092
	.byte W15
	.byte Cn3, v080 @ N15
	.byte W24
	.byte VOL, 127
	.byte W04
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v032 @ N15
	.byte W19
	.byte VOL, 80
	.byte N15, Bn2, v127
	.byte W15
	.byte Bn2, v020 @ N15
	.byte W15
	.byte VOL, 20
	.byte W18
	.byte N24, Cn3, v127
	.byte W48
	.byte FINE

track_560_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 50
	.byte PAN, c_v
	.byte N15, Cn3, v092
	.byte W15
	.byte N15 @ Cn3, v092
	.byte W15
	.byte N15 @ Cn3, v092
	.byte W15
	.byte N13, Cn3, v060
	.byte W13
	.byte VOL, 127
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v052 @ N15
	.byte W19
	.byte VOL, 80
	.byte N15, Cn3, v127
	.byte W04
	.byte W12
	.byte Gn3, v040 @ N15
	.byte W84
	.byte FINE

track_560_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 50
	.byte PAN, c_v
	.byte W02
	.byte N04, Cn3, v080
	.byte W05
	.byte N04 @ Cn3, v080
	.byte W05
	.byte N04 @ Cn3, v080
	.byte W04
	.byte VOICE, 6
	.byte N04, Cn3, v060
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v040
	.byte W20
	.byte VOICE, 2
	.byte VOL, 10
	.byte N06 @ Cn3, v040
	.byte W06
	.byte N16, En3, v060
	.byte W15
	.byte VOL, 127
	.byte W32
	.byte W03
	.byte W96
	.byte FINE

track_560_3:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte MOD, 60
	.byte VOL, 50
	.byte PAN, c_v
	.byte LFOS, 60
	.byte MODT, 1
	.byte TIE, Cn3, v120
	.byte W03
	.byte VOL, 49
	.byte W06
	.byte 47 @ VOL
	.byte W06
	.byte 45 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 88 @ VOL
	.byte W03
	.byte 105 @ VOL
	.byte W03
	.byte 127 @ VOL
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte 112 @ VOL
	.byte W03
	.byte 105 @ VOL
	.byte W03
	.byte 98 @ VOL
	.byte W03
	.byte 91 @ VOL
	.byte W03
	.byte 85 @ VOL
	.byte W03
	.byte 79 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 57 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W06
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
	.byte 3 @ VOL
	.byte W06
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W03
	.byte EOT @ Cn3, v120
	.byte FINE

track_560_4:
	.byte KEYSH, 0
	.byte W72
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte TIE, En3, v127
	.byte W03
	.byte VOL, 125
	.byte W03
	.byte 123 @ VOL
	.byte W03
	.byte 120 @ VOL
	.byte W03
	.byte 117 @ VOL
	.byte W03
	.byte 115 @ VOL
	.byte W03
	.byte 111 @ VOL
	.byte W03
	.byte 109 @ VOL
	.byte W03
	.byte 105 @ VOL
	.byte W03
	.byte 101 @ VOL
	.byte W03
	.byte 96 @ VOL
	.byte W03
	.byte 91 @ VOL
	.byte W03
	.byte 85 @ VOL
	.byte W03
	.byte 79 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 57 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W06
	.byte 1 @ VOL
	.byte W06
	.byte 0 @ VOL
	.byte W03
	.byte EOT @ En3, v127
	.byte FINE

track_560_5:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 80
	.byte PAN, c_v
	.byte N06, Cn2, v127
	.byte W06
	.byte Fn2 @ N06, v127
	.byte W06
	.byte N06 @ Fn2, v127
	.byte W06
	.byte N06 @ Fn2, v127
	.byte W06
	.byte N04 @ Fn2, v127
	.byte W04
	.byte N06, Cn2 @ v127
	.byte W06
	.byte Fn2 @ N06, v127
	.byte W06
	.byte N06 @ Fn2, v127
	.byte W06
	.byte N06 @ Fn2, v127
	.byte W10
	.byte VOL, 127
	.byte N06, Cn2 @ v127
	.byte W06
	.byte Fn2 @ N06, v127
	.byte W06
	.byte N06 @ Fn2, v127
	.byte W06
	.byte N06 @ Fn2, v127
	.byte W06
	.byte N04 @ Fn2, v127
	.byte W04
	.byte N06, Cn2, v100
	.byte W06
	.byte Fn2 @ N06, v100
	.byte W06
	.byte N06 @ Fn2, v100
	.byte W06
	.byte N06 @ Fn2, v100
	.byte W06
	.byte N04 @ Fn2, v100
	.byte W04
	.byte N06, Cn2, v040
	.byte W06
	.byte Fn2 @ N06, v040
	.byte W06
	.byte N06 @ Fn2, v040
	.byte W06
	.byte N06 @ Fn2, v040
	.byte W06
	.byte N04 @ Fn2, v040
	.byte W56
	.byte FINE

.align 2

track_560:
	.byte 6
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a7798
	.word track_560_0
	.word track_560_1
	.word track_560_2
	.word track_560_3
	.word track_560_4
	.word track_560_5

.align 2
