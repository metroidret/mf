.align 2

.global track_248

track_248_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 80
	.byte PAN, c_v
	.byte N03, Cn6, v127
	.byte W03
	.byte FINE

.align 2

track_248:
	.byte 1
	.byte 0
	.byte 188
	.byte 0
	.word 0x80a6af0
	.word track_248_0

.align 2
