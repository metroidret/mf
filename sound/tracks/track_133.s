.align 2

.global track_133

track_133_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 35
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte FINE

.align 2

track_133:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a682c
	.word track_133_0

.align 2
