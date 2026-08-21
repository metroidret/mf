.align 2

.global track_602

track_602_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte N28, Cn3, v100
	.byte W04
	.byte VOL, 40
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W03
	.byte FINE

track_602_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 50
	.byte PAN, c_v
	.byte W04
	.byte N28, Cn3, v127
	.byte W04
	.byte VOL, 40
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_602:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a7654
	.word track_602_0
	.word track_602_1

.align 2
