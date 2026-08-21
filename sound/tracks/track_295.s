.align 2

.global track_295

track_295_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 59
	.byte VOL, 78
	.byte PAN, c_v
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_295:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_295_0

.align 2
