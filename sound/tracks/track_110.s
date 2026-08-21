.align 2

.global track_110

track_110_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 65
	.byte PAN, c_v
	.byte N07, Cn3, v127
	.byte W10
	.byte N06, Cn3, v060
	.byte W06
	.byte FINE

.align 2

track_110:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_110_0

.align 2
