.align 2

.global track_458

track_458_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 91
	.byte VOL, 127
	.byte BEND, c_v
	.byte N24, Bn2, v096
	.byte W24
	.byte FINE

.align 2

track_458:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_458_0

.align 2
