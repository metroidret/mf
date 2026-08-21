.align 2

.global track_100

track_100_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte FINE

.align 2

track_100:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a682c
	.word track_100_0

.align 2
