.align 2

.global track_459

track_459_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOL, 127
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W16
	.byte VOICE, 93
	.byte N08, Cn3, v012
	.byte W08
	.byte VOICE, 94
	.byte N08, Cn3, v020
	.byte W08
	.byte FINE

.align 2

track_459:
	.byte 1
	.byte 0
	.byte 165
	.byte 128
	.word 0x80a8554
	.word track_459_0

.align 2
