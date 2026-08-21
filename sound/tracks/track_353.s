.align 2

.global track_353

track_353_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 40
	.byte PAN, c_v
	.byte N07, En2, v020
	.byte W07
	.byte En2, v052 @ N07
	.byte W07
	.byte En2, v080 @ N07
	.byte W07
	.byte En2, v127 @ N07
	.byte W07
	.byte FINE

.align 2

track_353:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word 0x80a6d54
	.word track_353_0

.align 2
