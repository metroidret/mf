.align 2

.global track_686

track_686_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte MOD, 20
	.byte VOL, 50
	.byte PAN, c_v
	.byte LFOS, 10
	.byte N72, Cn3, v100
	.byte W48
	.byte W02
	.byte VOL, 46
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W24
	.byte W01
	.byte W96
	.byte W22
	.byte FINE

track_686_1:
	.byte KEYSH, 0
	.byte W96
	.byte W12
	.byte VOICE, 1
	.byte VOL, 80
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 2
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 3
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 4
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 5
	.byte N05, Cn3, v032
	.byte W05
	.byte VOICE, 9
	.byte N05, Cn3, v012
	.byte W05
	.byte VOICE, 4
	.byte N05, Cn3, v020
	.byte W05
	.byte VOICE, 7
	.byte N05, Cn3, v032
	.byte W05
	.byte VOICE, 2
	.byte N05, Cn3, v020
	.byte W05
	.byte VOICE, 8
	.byte N05, Cn3, v012
	.byte W05
	.byte VOICE, 6
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 7
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 8
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 9
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 10
	.byte N05 @ Cn3, v127
	.byte W06
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 14
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 13
	.byte N05 @ Cn3, v127
	.byte W02
	.byte W03
	.byte VOICE, 12
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 11
	.byte N03 @ Cn3, v127
	.byte W04
	.byte VOICE, 17
	.byte N05, Cn3, v100
	.byte W05
	.byte VOICE, 16
	.byte N05, Cn3, v080
	.byte W05
	.byte FINE

.align 2

track_686:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a6d54
	.word track_686_0
	.word track_686_1

.align 2
