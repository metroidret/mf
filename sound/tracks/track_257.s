.align 2

.global track_257

track_257_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 18
	.byte PAN, c_v
	.byte N12, Cn4, v068
	.byte W24
	.byte FINE

track_257_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 25
	.byte PAN, c_v
	.byte N16, Cn3, v127
	.byte W14
	.byte VOL, 12
	.byte W01
	.byte 6 @ VOL
	.byte W09
	.byte FINE

.align 2

track_257:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_257_0
	.word track_257_1

.align 2
