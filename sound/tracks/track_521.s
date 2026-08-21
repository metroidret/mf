.align 2

.global track_521

track_521_0:
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
	.byte W36
	.byte FINE

track_521_1:
	.byte KEYSH, 0
	.byte VOICE, 89
	.byte VOL, 127
	.byte BEND, c_v
	.byte W16
	.byte N32, Fn3, v024
	.byte W32
	.byte FINE

.align 2

track_521:
	.byte 2
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_521_0
	.word track_521_1

.align 2
