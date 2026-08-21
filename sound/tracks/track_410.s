.align 2

.global track_410

track_410_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 72
	.byte VOL, 39
	.byte PAN, c_v
	.byte N08, Cn5, v052
	.byte W02
	.byte VOL, 46
	.byte W01
	.byte 50 @ VOL
	.byte W05
	.byte VOICE, 66
	.byte N22, Gn1, v127
	.byte W08
	.byte VOL, 50
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W04
	.byte FINE

track_410_1:
	.byte KEYSH, 0
	.byte VOICE, 73
	.byte VOL, 50
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N10, As4, v127
	.byte W10
	.byte PRIO, 0
	.byte N20, Gn2, v100
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_410:
	.byte 2
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_410_0
	.word track_410_1

.align 2
