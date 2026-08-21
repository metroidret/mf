.align 2

.global track_143

track_143_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 58
	.byte VOL, 15
	.byte PAN, c_v
	.byte N01, Cn3, v080
	.byte W02
	.byte FINE

.align 2

track_143:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_143_0

.align 2
