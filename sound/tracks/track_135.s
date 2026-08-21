.align 2

.global track_135

track_135_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 50
	.byte PAN, c_v
	.byte N01, Cn5, v020
	.byte W01
	.byte VOICE, 9
	.byte N02, Cn3, v127
	.byte W02
	.byte FINE

.align 2

track_135:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a682c
	.word track_135_0

.align 2
