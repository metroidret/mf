.align 2

.global track_321

track_321_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte MOD, 20
	.byte VOL, 19
	.byte PAN, c_v
	.byte LFOS, 10
	.byte N72, Cn3, v100
	.byte W96
	.byte FINE

.align 2

track_321:
	.byte 1
	.byte 0
	.byte 90
	.byte 0
	.word 0x80a6d54
	.word track_321_0

.align 2
