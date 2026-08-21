.align 2

.global track_558

track_558_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 33
	.byte PAN, c_v
	.byte W01
	.byte N24, Cn3, v127
	.byte W84
	.byte W02
	.byte FINE

track_558_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 60
	.byte PAN, c_v
	.byte N10, Cn3, v127
	.byte W10
	.byte N14, Cn3, v064
	.byte W76
	.byte W01
	.byte FINE

track_558_2:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte MOD, 60
	.byte VOL, 60
	.byte PAN, c_v
	.byte LFOS, 60
	.byte MODT, 1
	.byte N48, Cn3, v127
	.byte W04
	.byte VOL, 59
	.byte W04
	.byte 58 @ VOL
	.byte W04
	.byte 57 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W40
	.byte W01
	.byte FINE

track_558_3:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 60
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

track_558_4:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 23
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W05
	.byte En3, v080 @ N04
	.byte W05
	.byte Fn3 @ N04, v080
	.byte W05
	.byte Fn3, v100 @ N04
	.byte W09
	.byte En3, v127 @ N04
	.byte W05
	.byte N02, Gn3, v060
	.byte W56
	.byte W02
	.byte FINE

.align 2

track_558:
	.byte 5
	.byte 0
	.byte 253
	.byte 0
	.word 0x80a7798
	.word track_558_0
	.word track_558_1
	.word track_558_2
	.word track_558_3
	.word track_558_4

.align 2
