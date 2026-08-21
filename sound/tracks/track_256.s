.align 2

.global track_256

track_256_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte MOD, 50
	.byte VOL, 90
	.byte PAN, c_v
	.byte LFOS, 10
	.byte N96, Ds2, v127
	.byte W03
	.byte VOL, 89
	.byte W06
	.byte 87 @ VOL
	.byte W06
	.byte 85 @ VOL
	.byte W06
	.byte 83 @ VOL
	.byte W06
	.byte 82 @ VOL
	.byte W06
	.byte 80 @ VOL
	.byte W06
	.byte 77 @ VOL
	.byte W06
	.byte 76 @ VOL
	.byte W06
	.byte 74 @ VOL
	.byte W06
	.byte 72 @ VOL
	.byte W06
	.byte 70 @ VOL
	.byte W06
	.byte 69 @ VOL
	.byte W06
	.byte 67 @ VOL
	.byte W06
	.byte 65 @ VOL
	.byte W06
	.byte 63 @ VOL
	.byte W06
	.byte 62 @ VOL
	.byte W03
	.byte LFOS, 40
	.byte N96 @ Ds2, v127
	.byte W03
	.byte VOL, 60
	.byte W06
	.byte 58 @ VOL
	.byte W06
	.byte 56 @ VOL
	.byte W06
	.byte 54 @ VOL
	.byte W06
	.byte 53 @ VOL
	.byte W06
	.byte 51 @ VOL
	.byte W06
	.byte 49 @ VOL
	.byte W06
	.byte 47 @ VOL
	.byte W06
	.byte 46 @ VOL
	.byte W06
	.byte 43 @ VOL
	.byte W06
	.byte 41 @ VOL
	.byte W06
	.byte 40 @ VOL
	.byte W06
	.byte 38 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W03
	.byte LFOS, 70
	.byte N96 @ Ds2, v127
	.byte W03
	.byte VOL, 31
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 27 @ VOL
	.byte W06
	.byte 26 @ VOL
	.byte W06
	.byte 24 @ VOL
	.byte W06
	.byte 21 @ VOL
	.byte W06
	.byte 20 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W06
	.byte 17 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W06
	.byte 13 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 9 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W03
	.byte LFOS, 100
	.byte N12 @ Ds2, v127
	.byte W03
	.byte VOL, 2
	.byte W06
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
track_256_lbl_27e6bc:
	.byte W84
	.byte W96
	.byte W96
	.byte W12
	.byte GOTO
		.word track_256_lbl_27e6bc
	.byte FINE

track_256_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 42
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N24, Cn2, v127
	.byte W48
	.byte Cn2, v080 @ N24
	.byte W48
	.byte Cn2, v040 @ N24
	.byte W48
	.byte Cn2, v020 @ N24
	.byte W24
	.byte VOICE, 4
	.byte VOL, 10
	.byte N24, Cn3, v080
	.byte W03
	.byte VOL, 13
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte N24 @ Cn3, v080
	.byte W03
	.byte VOL, 36
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte N24 @ Cn3, v080
	.byte W03
	.byte VOL, 55
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 68 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte N24 @ Cn3, v080
	.byte W03
	.byte VOL, 71
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 79 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte N24 @ Cn3, v080
	.byte W03
	.byte VOL, 81
	.byte W03
	.byte 82 @ VOL
	.byte W06
	.byte 84 @ VOL
	.byte W03
	.byte 85 @ VOL
	.byte W06
	.byte 87 @ VOL
	.byte W03
	.byte N12 @ Cn3, v080
	.byte W03
	.byte VOL, 88
	.byte W06
	.byte 90 @ VOL
	.byte W03
track_256_lbl_27e73f:
	.byte N96, Cn3, v080
	.byte W84
	.byte W12
	.byte N96 @ Cn3, v080
	.byte W84
	.byte W12
	.byte N96 @ Cn3, v080
	.byte W84
	.byte W12
	.byte GOTO
		.word track_256_lbl_27e73f
	.byte FINE

.align 2

track_256:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a71ec
	.word track_256_0
	.word track_256_1

.align 2
