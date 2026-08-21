.align 2

.global track_268

track_268_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 36
	.byte PAN, c_v
	.byte N24, Fn2, v127
	.byte W02
	.byte VOL, 52
	.byte W02
	.byte 57 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_268:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_268_0

.align 2
