.align 2

.global track_314

track_314_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 90
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte Gn2, v100 @ N04
	.byte W04
	.byte Cn2, v080 @ N04
	.byte W48
	.byte W02
	.byte FINE

track_314_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W28
	.byte FINE

track_314_2:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 127
	.byte PAN, c_v
	.byte W01
	.byte N15, An2, v127
	.byte W15
	.byte N05, Fn2 @ v127
	.byte W42
	.byte FINE

.align 2

track_314:
	.byte 3
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a808c
	.word track_314_0
	.word track_314_1
	.word track_314_2

.align 2
