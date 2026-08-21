.align 2

.global track_650

track_650_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 63
	.byte PAN, c_v
	.byte PRIO, 3
	.byte N90, Gn3, v127
	.byte W72
	.byte VOL, 62
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W09
	.byte W92
	.byte W03
	.byte FINE

track_650_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte MOD, 100
	.byte VOL, 56
	.byte PAN, c_v
	.byte LFOS, 10
	.byte PRIO, 2
	.byte W44
	.byte W03
	.byte TIE, Cn3, v127
	.byte W16
	.byte VOL, 53
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 24 @ VOL
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
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W06
	.byte 2 @ VOL
	.byte W09
	.byte 1 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W09
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W09
	.byte 0 @ VOL
	.byte W14
	.byte EOT @ Cn3, v127
	.byte FINE

.align 2

track_650:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word 0x80a7e10
	.word track_650_0
	.word track_650_1

.align 2
