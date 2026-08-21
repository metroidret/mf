.align 2

.global track_605

track_605_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 90
	.byte PAN, c_v
	.byte N13, Cn3, v127
	.byte W52
	.byte FINE

track_605_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte PAN, c_v
	.byte W08
	.byte VOL, 14
	.byte N36, Cn3, v127
	.byte W02
	.byte VOL, 14
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W16
	.byte FINE

.align 2

track_605:
	.byte 2
	.byte 0
	.byte 185
	.byte 0
	.word 0x80a7654
	.word track_605_0
	.word track_605_1

.align 2
