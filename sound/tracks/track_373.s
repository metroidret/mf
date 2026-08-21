.align 2

.global track_373

track_373_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, An2, v100
	.byte W06
	.byte An2, v040 @ N05
	.byte W05
	.byte An2, v020 @ N05
	.byte W05
	.byte FINE

.align 2

track_373:
	.byte 1
	.byte 0
	.byte 140
	.byte 0
	.word 0x80a6d54
	.word track_373_0

.align 2
