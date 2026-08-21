.align 2

.global track_389

track_389_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 66
	.byte VOL, 55
	.byte PAN, c_v
	.byte N36, Cn1, v100
	.byte W02
	.byte VOL, 60
	.byte W02
	.byte 66 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W10
	.byte 70 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W20
	.byte FINE

track_389_1:
	.byte KEYSH, 0
	.byte VOICE, 67
	.byte VOL, 60
	.byte PAN, c_v
	.byte N24, Ds2, v127
	.byte W56
	.byte W02
	.byte FINE

.align 2

track_389:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_389_0
	.word track_389_1

.align 2
