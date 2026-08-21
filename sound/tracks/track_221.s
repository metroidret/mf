.align 2

.global track_221

track_221_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 35
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte FINE

.align 2

track_221:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a6af0
	.word track_221_0

.align 2
