.align 2

.global track_277

track_277_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 50
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 33
	.byte N04, Fn2, v100
	.byte W04
	.byte N04 @ Fn2, v100
	.byte W04
	.byte N04 @ Fn2, v100
	.byte W04
	.byte N04 @ Fn2, v100
	.byte W04
	.byte VOICE, 39
	.byte N10, Cn3, v127
	.byte W20
	.byte FINE

track_277_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 50
	.byte PAN, c_v
	.byte W02
	.byte N03, Cn3, v040
	.byte W03
	.byte VOICE, 6
	.byte N16, Cn4, v127
	.byte W16
	.byte VOICE, 39
	.byte W10
	.byte N10, Cn3, v020
	.byte W10
	.byte FINE

.align 2

track_277:
	.byte 2
	.byte 0
	.byte 253
	.byte 0
	.word 0x80a71ec
	.word track_277_0
	.word track_277_1

.align 2
