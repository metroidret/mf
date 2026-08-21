.align 2

.global track_201

track_201_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 49
	.byte VOL, 51
	.byte PAN, c_v
	.byte N36, Cn3, v120
	.byte W44
	.byte FINE

.align 2

track_201:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_201_0

.align 2
