.align 2

.global track_453

track_453_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 84
	.byte VOL, 127
	.byte N07, En3, v016
	.byte W14
	.byte Cn4, v020 @ N07
	.byte W07
	.byte FINE

.align 2

track_453:
	.byte 1
	.byte 0
	.byte 162
	.byte 128
	.word 0x80a8554
	.word track_453_0

.align 2
