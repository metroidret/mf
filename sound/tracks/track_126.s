.align 2

.global track_126

track_126_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 80
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte VOICE, 1
	.byte N02, Cn3, v127
	.byte W02
	.byte FINE

.align 2

track_126:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_126_0

.align 2
