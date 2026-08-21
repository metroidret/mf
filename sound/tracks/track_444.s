.align 2

.global track_444

track_444_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 96
	.byte MOD, 40
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 120
	.byte N18, Gn2, v100
	.byte W18
	.byte FINE

.align 2

track_444:
	.byte 1
	.byte 0
	.byte 175
	.byte 0
	.word 0x80a6d54
	.word track_444_0

.align 2
