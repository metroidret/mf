.align 2

.global track_274

track_274_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 35
	.byte PAN, c_v
	.byte N16, Cn3, v080
	.byte W16
	.byte VOICE, 21
	.byte N02, Cn2, v052
	.byte W02
	.byte As2 @ N02, v052
	.byte W18
	.byte N02 @ As2, v052
	.byte W02
	.byte Cn2 @ N02, v052
	.byte W02
	.byte FINE

track_274_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 21
	.byte PAN, c_v
	.byte N12, Cn4, v068
	.byte W40
	.byte FINE

.align 2

track_274:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_274_0
	.word track_274_1

.align 2
