.align 2

.global track_429

track_429_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 50
	.byte PAN, c_v
	.byte N03, Fn4, v100
	.byte W24
	.byte FINE

.align 2

track_429:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_429_0

.align 2
