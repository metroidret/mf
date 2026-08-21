.align 2

.global track_240

track_240_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 80
	.byte PAN, c_v
	.byte N60, Cn3, v127
	.byte W60
	.byte W03
	.byte FINE

.align 2

track_240:
	.byte 1
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_240_0

.align 2
