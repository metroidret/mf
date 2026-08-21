.align 2

.global track_118

track_118_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 60
	.byte PAN, c_v
	.byte N28, Cn3, v127
	.byte W42
	.byte FINE

.align 2

track_118:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_118_0

.align 2
