.align 2

.global track_553

track_553_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 40
	.byte PAN, c_v
	.byte W04
	.byte N15, Cn3, v092
	.byte W15
	.byte N15 @ Cn3, v092
	.byte W15
	.byte Cn3, v080 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W15
	.byte VOICE, 2
	.byte VOL, 10
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3 @ v100
	.byte W14
	.byte Fs3, v040 @ N14
	.byte W12
	.byte W02
	.byte VOICE, 3
	.byte N10, En3, v020
	.byte W48
	.byte W03
	.byte FINE

track_553_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 40
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N15, Cn3, v092
	.byte W15
	.byte N15 @ Cn3, v092
	.byte W15
	.byte N15 @ Cn3, v092
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W48
	.byte W03
	.byte W52
	.byte W01
	.byte FINE

track_553_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 40
	.byte PAN, c_v
	.byte PRIO, 1
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
	.byte N14, En3, v060
	.byte W14
	.byte Dn3, v020 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, Cn3 @ v020
	.byte W22
	.byte W52
	.byte W01
	.byte FINE

track_553_3:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte TIE, Cn3, v127
	.byte W03
	.byte VOL, 125
	.byte W03
	.byte 122 @ VOL
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte 116 @ VOL
	.byte W03
	.byte 113 @ VOL
	.byte W03
	.byte 109 @ VOL
	.byte W03
	.byte 103 @ VOL
	.byte W03
	.byte 96 @ VOL
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W06
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W06
	.byte 5 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W09
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W09
	.byte 0 @ VOL
	.byte W08
	.byte EOT @ Cn3, v127
	.byte W05
	.byte FINE

track_553_4:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 5
	.byte W05
	.byte TIE, En3, v127
	.byte W03
	.byte VOL, 125
	.byte W03
	.byte 122 @ VOL
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte 116 @ VOL
	.byte W03
	.byte 113 @ VOL
	.byte W03
	.byte 109 @ VOL
	.byte W03
	.byte 103 @ VOL
	.byte W03
	.byte 96 @ VOL
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W01
	.byte W02
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W06
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W06
	.byte 5 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W09
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W09
	.byte 0 @ VOL
	.byte W03
	.byte W05
	.byte EOT @ En3, v127
	.byte FINE

.align 2

track_553:
	.byte 5
	.byte 0
	.byte 250
	.byte 0
	.word 0x80a7798
	.word track_553_0
	.word track_553_1
	.word track_553_2
	.word track_553_3
	.word track_553_4

.align 2
