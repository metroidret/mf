.align 2

.global track_117

track_117_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 31
	.byte PAN, c_v
	.byte W01
	.byte N01, Cn3, v127
	.byte W10
	.byte FINE

track_117_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 50
	.byte PAN, c_v
	.byte N02, Ds3, v080
	.byte W11
	.byte FINE

.align 2

track_117:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a682c
	.word track_117_0
	.word track_117_1

.align 2
