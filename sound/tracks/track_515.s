.align 2

.global track_515

track_515_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W06
	.byte VOICE, 73
	.byte VOL, 127
	.byte N02, Cs5, v032
	.byte W02
	.byte Gs5, v016 @ N02
	.byte W02
	.byte Fs5, v032 @ N02
	.byte W02
	.byte Cs6, v016 @ N02
	.byte W02
	.byte FINE

track_515_1:
	.byte KEYSH, 0
	.byte VOICE, 60
	.byte VOL, 24
	.byte BEND, c_v+6
	.byte N02, Cs2, v040
	.byte W02
	.byte Gs2, v024 @ N02
	.byte W02
	.byte Fs2, v040 @ N02
	.byte W02
	.byte Cs3, v024 @ N02
	.byte W08
	.byte FINE

.align 2

track_515:
	.byte 2
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_515_0
	.word track_515_1

.align 2
