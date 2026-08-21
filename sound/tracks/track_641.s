.align 2

.global track_641

track_641_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 75
	.byte PAN, c_v
	.byte N11, Cn3, v127
	.byte W13
	.byte VOICE, 5
	.byte N07, Cn3, v100
	.byte W07
	.byte FINE

.align 2

track_641:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_641_0

.align 2
