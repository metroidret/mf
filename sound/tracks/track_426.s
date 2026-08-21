.align 2

.global track_426

track_426_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 70
	.byte VOL, 60
	.byte PAN, c_v
	.byte N12, Gn2, v080
	.byte W12
	.byte N06, Fn2, v060
	.byte W06
	.byte N06 @ Fn2, v060
	.byte W06
	.byte VOICE, 76
	.byte N04, Cn3, v100
	.byte W04
	.byte Cn3, v052 @ N04
	.byte W04
	.byte Cn3, v020 @ N04
	.byte W04
	.byte FINE

.align 2

track_426:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_426_0

.align 2
