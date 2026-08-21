.align 2

.global track_510

track_510_0:
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
	.byte W10
	.byte FINE

track_510_1:
	.byte KEYSH, 0
	.byte VOICE, 78
	.byte VOL, 127
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W10
	.byte N12, Cn3, v016
	.byte W12
	.byte FINE

.align 2

track_510:
	.byte 2
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_510_0
	.word track_510_1

.align 2
