.align 2

.global track_289

track_289_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 50
	.byte VOL, 37
	.byte PAN, c_v-24
	.byte N04, En3, v127
	.byte W04
	.byte Cn3, v060 @ N04
	.byte W04
	.byte Bn2, v020 @ N04
	.byte W07
	.byte FINE

.align 2

track_289:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_289_0

.align 2
