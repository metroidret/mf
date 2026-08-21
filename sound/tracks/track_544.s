.align 2

.global track_544

track_544_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte FINE

.align 2

track_544:
	.byte 1
	.byte 0
	.byte 227
	.byte 0
	.word 0x80a826c
	.word track_544_0

.align 2
