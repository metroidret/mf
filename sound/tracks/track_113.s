.align 2

.global track_113

track_113_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 35
	.byte PAN, c_v
	.byte N01, Cn5, v127
	.byte W01
	.byte As4 @ N01, v127
	.byte W01
	.byte FINE

.align 2

track_113:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_113_0

.align 2
