.align 2

.global track_546

track_546_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 120
	.byte PAN, c_v
	.byte N40, Cn3, v127
	.byte W40
	.byte FINE

.align 2

track_546:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a826c
	.word track_546_0

.align 2
