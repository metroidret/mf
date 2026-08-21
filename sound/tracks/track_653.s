.align 2

.global track_653

track_653_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 8
	.byte N44, Bn3, v127
	.byte W44
	.byte W03
	.byte N90, Gn3, v040
	.byte W48
	.byte W01
	.byte W16
	.byte VOL, 78
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W56
	.byte FINE

track_653_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 56
	.byte PAN, c_v
	.byte PRIO, 5
	.byte N15, Cn3, v127
	.byte W15
	.byte N18, Cn3, v040
	.byte W30
	.byte VOICE, 2
	.byte MOD, 100
	.byte VOL, 71
	.byte LFOS, 10
	.byte PRIO, 2
	.byte TIE, Cn3, v127
	.byte W16
	.byte VOL, 67
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W02
	.byte W01
	.byte 23 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W06
	.byte 3 @ VOL
	.byte W09
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W09
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W09
	.byte 0 @ VOL
	.byte W14
	.byte EOT @ Cn3, v127
	.byte FINE

.align 2

track_653:
	.byte 2
	.byte 0
	.byte 219
	.byte 0
	.word 0x80a7e10
	.word track_653_0
	.word track_653_1

.align 2
