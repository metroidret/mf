.align 2

.global track_319

track_319_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte N04, Gn2, v127
	.byte W04
	.byte VOICE, 20
	.byte N06, Bn2, v064
	.byte W06
	.byte FINE

.align 2

track_319:
	.byte 1
	.byte 0
	.byte 199
	.byte 0
	.word 0x80a808c
	.word track_319_0

.align 2
