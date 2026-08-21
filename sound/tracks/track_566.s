.align 2

.global track_566

track_566_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte MOD, 20
	.byte VOL, 31
	.byte PAN, c_v
	.byte LFOS, 10
	.byte N60, Cn3, v127
	.byte W12
	.byte VOL, 31
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W04
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W04
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W15
	.byte FINE

track_566_1:
	.byte KEYSH, 0
	.byte VOICE, 30
	.byte VOL, 25
	.byte PAN, c_v
	.byte W01
	.byte N03, Cn3, v060
	.byte W03
	.byte VOICE, 31
	.byte N05, Cn3, v080
	.byte W05
	.byte VOICE, 32
	.byte N05, Cn3, v100
	.byte W05
	.byte VOICE, 33
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 34
	.byte N05, Cn3, v032
	.byte W05
	.byte VOICE, 38
	.byte N05, Cn3, v012
	.byte W05
	.byte VOICE, 33
	.byte N05, Cn3, v020
	.byte W05
	.byte VOICE, 36
	.byte N05, Cn3, v032
	.byte W05
	.byte VOICE, 31
	.byte N05, Cn3, v020
	.byte W05
	.byte VOICE, 37
	.byte N05, Cn3, v012
	.byte W05
	.byte VOICE, 35
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 36
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 37
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 38
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 39
	.byte N05 @ Cn3, v127
	.byte W05
	.byte FINE

.align 2

track_566:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_566_0
	.word track_566_1

.align 2
