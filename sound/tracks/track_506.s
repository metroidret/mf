.align 2

.global track_506

track_506_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 74
	.byte VOL, 105
	.byte BEND, c_v
	.byte N03, Cn3, v016
	.byte W06
	.byte Cn3, v004 @ N03
	.byte W03
	.byte FINE

.align 2

track_506:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_506_0

.align 2
