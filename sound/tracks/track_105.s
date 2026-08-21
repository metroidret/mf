.align 2

.global track_105

track_105_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 43
	.byte PAN, c_v
	.byte N07, Cn3, v127
	.byte W07
	.byte FINE

.align 2

track_105:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a682c
	.word track_105_0

.align 2
