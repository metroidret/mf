.align 2

.global track_357

track_357_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 31
	.byte PAN, c_v
	.byte N04, Cn5, v060
	.byte W04
	.byte As4 @ N04, v060
	.byte W04
	.byte Gs4 @ N04, v060
	.byte W04
	.byte Fs4 @ N04, v060
	.byte W04
	.byte FINE

.align 2

track_357:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word 0x80a6d54
	.word track_357_0

.align 2
