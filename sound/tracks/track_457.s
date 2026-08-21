.align 2

.global track_457

track_457_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 92
	.byte VOL, 127
	.byte BEND, c_v
	.byte N24, Cn3, v016
	.byte W24
	.byte FINE

.align 2

track_457:
	.byte 1
	.byte 0
	.byte 162
	.byte 128
	.word 0x80a8554
	.word track_457_0

.align 2
