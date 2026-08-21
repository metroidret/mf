.align 2

.global track_501

track_501_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte VOL, 127
	.byte N02, Cs4, v012
	.byte W04
	.byte Cs4, v004 @ N02
	.byte W02
	.byte FINE

.align 2

track_501:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_501_0

.align 2
