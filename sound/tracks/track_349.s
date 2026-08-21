.align 2

.global track_349

track_349_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 55
	.byte PAN, c_v
	.byte N06, Cn3, v127
	.byte W06
	.byte VOICE, 47
	.byte MOD, 100
	.byte LFOS, 127
	.byte N24, Cn4, v036
	.byte W30
	.byte FINE

.align 2

track_349:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a6d54
	.word track_349_0

.align 2
