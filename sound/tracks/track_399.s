.align 2

.global track_399

track_399_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 66
	.byte VOL, 43
	.byte PAN, c_v
	.byte N13, Fn1, v127
	.byte W01
	.byte VOL, 46
	.byte W01
	.byte 50 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W12
	.byte FINE

track_399_1:
	.byte KEYSH, 0
	.byte VOICE, 54
	.byte VOL, 43
	.byte PAN, c_v
	.byte N03, An2, v127
	.byte W24
	.byte FINE

.align 2

track_399:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_399_0
	.word track_399_1

.align 2
