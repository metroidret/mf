.align 2

.global track_114

track_114_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 35
	.byte PAN, c_v
	.byte N01, Cn5, v127
	.byte W01
	.byte N02, As4 @ v127
	.byte W02
	.byte FINE

.align 2

track_114:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_114_0

.align 2
