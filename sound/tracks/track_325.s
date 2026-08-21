.align 2

.global track_325

track_325_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 120
	.byte PAN, c_v
	.byte N04, Cn3, v080
	.byte W05
	.byte Cn3, v127 @ N04
	.byte W05
	.byte Cn3, v100 @ N04
	.byte W04
	.byte VOICE, 20
	.byte N04, Cn3, v080
	.byte W04
	.byte VOICE, 21
	.byte N04, Cn3, v040
	.byte W30
	.byte FINE

track_325_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 113
	.byte PAN, c_v
	.byte W04
	.byte N28, Ds2, v127
	.byte W44
	.byte FINE

.align 2

track_325:
	.byte 2
	.byte 0
	.byte 189
	.byte 0
	.word 0x80a6d54
	.word track_325_0
	.word track_325_1

.align 2
