.align 2

.global track_324

track_324_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 120
	.byte PAN, c_v
	.byte N05, En2, v127
	.byte W05
	.byte N04, Bn3 @ v127
	.byte W04
	.byte Cn4, v100 @ N04
	.byte W04
	.byte Gn3, v080 @ N04
	.byte W04
	.byte En3, v052 @ N04
	.byte W30
	.byte W01
	.byte FINE

track_324_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 113
	.byte PAN, c_v
	.byte W04
	.byte N28, Fn2, v127
	.byte W44
	.byte FINE

.align 2

track_324:
	.byte 2
	.byte 0
	.byte 189
	.byte 0
	.word 0x80a6d54
	.word track_324_0
	.word track_324_1

.align 2
