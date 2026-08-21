.align 2

.global track_514

track_514_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 82
	.byte VOL, 127
	.byte N02, Cn3, v012
	.byte W02
	.byte FINE

.align 2

track_514:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_514_0

.align 2
