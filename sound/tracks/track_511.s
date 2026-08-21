.align 2

.global track_511

track_511_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 79
	.byte VOL, 127
	.byte BEND, c_v
	.byte N96, Cn3, v024
	.byte W60
	.byte W36
	.byte FINE

.align 2

track_511:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_511_0

.align 2
