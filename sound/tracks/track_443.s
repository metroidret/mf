.align 2

.global track_443

track_443_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 91
	.byte VOL, 70
	.byte PAN, c_v
	.byte N42, Cn3, v100
	.byte W42
	.byte FINE

.align 2

track_443:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a6d54
	.word track_443_0

.align 2
