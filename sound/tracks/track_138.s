.align 2

.global track_138

track_138_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 42
	.byte VOL, 56
	.byte PAN, c_v
	.byte N23, Cn3, v127
	.byte W23
	.byte FINE

.align 2

track_138:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a682c
	.word track_138_0

.align 2
