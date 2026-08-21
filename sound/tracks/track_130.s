.align 2

.global track_130

track_130_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 75
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte FINE

.align 2

track_130:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_130_0

.align 2
