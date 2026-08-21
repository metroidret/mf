.align 2

.global track_466

track_466_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 85
	.byte VOL, 127
	.byte BEND, c_v
	.byte W36
	.byte W02
	.byte N06, Bn5, v008
	.byte W09
	.byte Fn6 @ N06, v008
	.byte W07
	.byte Ds5 @ N06, v008
	.byte W06
	.byte FINE

.align 2

track_466:
	.byte 1
	.byte 0
	.byte 165
	.byte 128
	.word 0x80a8554
	.word track_466_0

.align 2
