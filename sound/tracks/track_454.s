.align 2

.global track_454

track_454_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 85
	.byte VOL, 127
	.byte N12, En3, v096
	.byte W12
	.byte FINE

.align 2

track_454:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_454_0

.align 2
