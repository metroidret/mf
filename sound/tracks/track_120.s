.align 2

.global track_120

track_120_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 20
	.byte PAN, c_v
	.byte N04, Cn3, v100
	.byte W04
	.byte N07, Cn3, v127
	.byte W07
	.byte FINE

.align 2

track_120:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_120_0

.align 2
