.align 2

.global track_239

track_239_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 90
	.byte PAN, c_v
	.byte N56, Cn3, v127
	.byte W60
	.byte W03
	.byte FINE

.align 2

track_239:
	.byte 1
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_239_0

.align 2
