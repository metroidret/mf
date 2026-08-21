.align 2

.global track_557

track_557_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 0
	.byte PAN, c_v
	.byte N60, An1, v127
	.byte W03
	.byte VOL, 12
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 57 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W28
	.byte FINE

track_557_1:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 100
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
	.byte W60
	.byte W03
	.byte FINE

track_557_2:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte MOD, 60
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 60
	.byte MODT, 1
	.byte N60, Cn1, v127, 43
	.byte W03
	.byte VOL, 19
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 83 @ VOL
	.byte W03
	.byte 90 @ VOL
	.byte W03
	.byte 97 @ VOL
	.byte W03
	.byte 101 @ VOL
	.byte W03
	.byte 107 @ VOL
	.byte W03
	.byte 111 @ VOL
	.byte W03
	.byte 115 @ VOL
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte 121 @ VOL
	.byte W03
	.byte 125 @ VOL
	.byte W03
	.byte 127 @ VOL
	.byte W36
	.byte W03
	.byte FINE

.align 2

track_557:
	.byte 3
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a7798
	.word track_557_0
	.word track_557_1
	.word track_557_2

.align 2
