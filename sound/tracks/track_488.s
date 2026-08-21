.align 2

.global track_488

track_488_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 127
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte Gn2, v100 @ N04
	.byte W04
	.byte Cn2, v080 @ N04
	.byte W36
	.byte W01
	.byte FINE

track_488_1:
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
	.byte W15
	.byte FINE

track_488_2:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 127
	.byte PAN, c_v
	.byte W01
	.byte N15, An2, v127
	.byte W15
	.byte N05, Fn2 @ v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_488:
	.byte 3
	.byte 0
	.byte 225
	.byte 0
	.word 0x80a808c
	.word track_488_0
	.word track_488_1
	.word track_488_2

.align 2
