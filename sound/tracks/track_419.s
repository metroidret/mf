.align 2

.global track_419

track_419_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 62
	.byte MOD, 80
	.byte VOL, 25
	.byte PAN, c_v
	.byte LFOS, 80
	.byte N11, Dn3, v127
	.byte W04
	.byte VOL, 31
	.byte W07
	.byte FINE

.align 2

track_419:
	.byte 1
	.byte 0
	.byte 151
	.byte 0
	.word 0x80a6d54
	.word track_419_0

.align 2
