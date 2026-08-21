.align 2

.global track_131

track_131_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 50
	.byte PAN, c_v
	.byte N02, Ds4, v100
	.byte W02
	.byte VOICE, 11
	.byte N04, Cn3, v127
	.byte W04
	.byte FINE

.align 2

track_131:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_131_0

.align 2
