.align 2

.global track_520

track_520_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 75
	.byte VOL, 127
	.byte BEND, c_v
	.byte N06, As3, v072
	.byte W06
	.byte As3, v020 @ N06
	.byte W06
	.byte As3, v012 @ N06
	.byte W20
	.byte FINE

track_520_1:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 49
	.byte VOL, 127
	.byte N02, Fn6, v016
	.byte W04
	.byte As5 @ N02, v016
	.byte W04
	.byte Cn6 @ N02, v016
	.byte W04
	.byte Fn5 @ N02, v016
	.byte W08
	.byte FINE

track_520_2:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 127
	.byte BEND, c_v+6
	.byte W18
	.byte N02, Fn6, v012
	.byte W04
	.byte As5 @ N02, v012
	.byte W04
	.byte Cn6 @ N02, v012
	.byte W04
	.byte Fn5 @ N02, v012
	.byte W02
	.byte FINE

.align 2

track_520:
	.byte 3
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_520_0
	.word track_520_1
	.word track_520_2

.align 2
