.align 2

.global track_455

track_455_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOL, 127
	.byte W10
	.byte VOICE, 86
	.byte N06, Cn3, v032
	.byte W23
	.byte VOICE, 87
	.byte N06 @ Cn3, v032
	.byte W06
	.byte FINE

.align 2

track_455:
	.byte 1
	.byte 0
	.byte 161
	.byte 128
	.word 0x80a8554
	.word track_455_0

.align 2
