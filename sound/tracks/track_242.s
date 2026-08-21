.align 2

.global track_242

track_242_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 20
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W02
	.byte VOICE, 14
	.byte VOL, 9
	.byte N03 @ Cn3, v127
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte FINE

.align 2

track_242:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a6af0
	.word track_242_0

.align 2
