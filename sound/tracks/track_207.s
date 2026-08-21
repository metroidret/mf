.align 2

.global track_207

track_207_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte W08
	.byte VOL, 18
	.byte N36, Fn2, v127
	.byte W02
	.byte VOL, 21
	.byte W07
	.byte 23 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W07
	.byte FINE

.align 2

track_207:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6af0
	.word track_207_0

.align 2
