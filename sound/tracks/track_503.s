.align 2

.global track_503

track_503_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 52
	.byte VOL, 127
	.byte N02, Fn3, v012
	.byte W04
	.byte Fn3, v004 @ N02
	.byte W02
	.byte FINE

.align 2

track_503:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_503_0

.align 2
