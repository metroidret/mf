.align 2

.global track_206

track_206_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 110
	.byte PAN, c_v
	.byte N13, Cn3, v127
	.byte W13
	.byte FINE

.align 2

track_206:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_206_0

.align 2
