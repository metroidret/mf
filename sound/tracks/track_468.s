.align 2

.global track_468

track_468_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 101
	.byte VOL, 127
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N08, Cn3, v012
	.byte W08
	.byte FINE

.align 2

track_468:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_468_0

.align 2
