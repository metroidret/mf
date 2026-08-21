.align 2

.global track_624

track_624_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 105
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N08, Cn3, v127
	.byte W08
	.byte VOICE, 9
	.byte VOL, 105
	.byte PAN, c_v
	.byte N18, Cn3, v100
	.byte W02
	.byte VOL, 88
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W11
	.byte FINE

track_624_1:
	.byte KEYSH, 0
	.byte W04
	.byte VOICE, 17
	.byte VOL, 82
	.byte MOD, 22
	.byte PAN, c_v
	.byte LFOS, 75
	.byte W02
	.byte N18, Fn3, v064
	.byte W03
	.byte VOL, 65
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W11
	.byte FINE

.align 2

track_624:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_624_0
	.word track_624_1

.align 2
