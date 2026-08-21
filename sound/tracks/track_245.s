.align 2

.global track_245

track_245_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 30
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 14
	.byte VOL, 11
	.byte N03 @ Cn3, v127
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte VOICE, 36
	.byte MOD, 30
	.byte VOL, 30
	.byte LFOS, 127
	.byte MODT, 1
	.byte N06, An3 @ v127
	.byte W03
	.byte VOL, 12
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_245:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a6af0
	.word track_245_0

.align 2
