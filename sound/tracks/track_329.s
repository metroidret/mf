.align 2

.global track_329

track_329_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 85
	.byte VOL, 127
	.byte PAN, c_v
	.byte W10
	.byte N05, Fn2, v100
	.byte W05
	.byte N10, Gs2 @ v100
	.byte W36
	.byte W02
	.byte FINE

track_329_1:
	.byte KEYSH, 0
	.byte VOICE, 86
	.byte VOL, 127
	.byte PAN, c_v
	.byte N02, Gn3, v127
	.byte W02
	.byte VOICE, 84
	.byte N04, Gn2 @ v127
	.byte W04
	.byte Fn2 @ N04, v127
	.byte W04
	.byte VOICE, 82
	.byte N04, Cn3, v080
	.byte W05
	.byte VOICE, 84
	.byte N04, Gn2, v127
	.byte W05
	.byte An2, v100 @ N04
	.byte W04
	.byte VOICE, 83
	.byte N04, An2, v060
	.byte W04
	.byte VOICE, 84
	.byte N04, Gn2, v040
	.byte W24
	.byte W01
	.byte FINE

.align 2

track_329:
	.byte 2
	.byte 0
	.byte 189
	.byte 0
	.word 0x80a6d54
	.word track_329_0
	.word track_329_1

.align 2
