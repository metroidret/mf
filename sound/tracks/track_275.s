.align 2

.global track_275

track_275_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 35
	.byte PAN, c_v
	.byte W08
	.byte N02, As2, v052
	.byte W08
	.byte N02 @ As2, v052
	.byte W02
	.byte Cn2 @ N02, v052
	.byte W10
	.byte FINE

track_275_1:
	.byte KEYSH, 0
	.byte VOL, 35
	.byte PAN, c_v
	.byte W17
	.byte VOICE, 20
	.byte N11, Cn2, v080
	.byte W11
	.byte FINE

.align 2

track_275:
	.byte 2
	.byte 0
	.byte 253
	.byte 0
	.word 0x80a71ec
	.word track_275_0
	.word track_275_1

.align 2
