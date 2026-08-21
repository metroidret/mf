.align 2

.global track_482

track_482_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte N30, Cn3, v127
	.byte W30
	.byte FINE

.align 2

track_482:
	.byte 1
	.byte 0
	.byte 223
	.byte 0
	.word 0x80a81e8
	.word track_482_0

.align 2
