.align 2

.global track_548

track_548_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 69
	.byte PAN, c_v
	.byte W20
	.byte N30, Cn3, v127
	.byte W30
	.byte FINE

.align 2

track_548:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word 0x80a826c
	.word track_548_0

.align 2
