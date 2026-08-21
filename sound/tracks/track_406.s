.align 2

.global track_406

track_406_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 72
	.byte MOD, 60
	.byte VOL, 37
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N32, Cn3, v100
	.byte W05
	.byte VOL, 37
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_406:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_406_0

.align 2
