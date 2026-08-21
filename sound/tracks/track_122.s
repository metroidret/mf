.align 2

.global track_122

track_122_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 80
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte Cn3, v080 @ N04
	.byte W04
	.byte VOICE, 43
	.byte MOD, 50
	.byte LFOS, 50
	.byte MODT, 1
	.byte N20, En1, v040
	.byte W40
	.byte FINE

.align 2

track_122:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_122_0

.align 2
