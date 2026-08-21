.align 2

.global track_420

track_420_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 60
	.byte PAN, c_v
	.byte N05, En3, v127
	.byte W05
	.byte VOICE, 36
	.byte N05, Fn3, v100
	.byte W05
	.byte FINE

.align 2

track_420:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_420_0

.align 2
