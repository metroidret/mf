.align 2

.global track_467

track_467_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 99
	.byte VOL, 127
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N36, Cn3, v036
	.byte W36
	.byte W01
	.byte FINE

.align 2

track_467:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_467_0

.align 2
