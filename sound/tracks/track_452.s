.align 2

.global track_452

track_452_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 83
	.byte VOL, 127
	.byte W14
	.byte N18, Cn3, v020
	.byte W18
	.byte FINE

.align 2

track_452:
	.byte 1
	.byte 0
	.byte 163
	.byte 128
	.word 0x80a8554
	.word track_452_0

.align 2
