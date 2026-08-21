.align 2

.global track_119

track_119_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 47
	.byte VOL, 70
	.byte PAN, c_v
	.byte N16, Cn3, v127
	.byte W28
	.byte FINE

.align 2

track_119:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_119_0

.align 2
