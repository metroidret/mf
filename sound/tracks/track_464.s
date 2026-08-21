.align 2

.global track_464

track_464_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 98
	.byte VOL, 127
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N18, Cn3, v020
	.byte W18
	.byte FINE

.align 2

track_464:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_464_0

.align 2
