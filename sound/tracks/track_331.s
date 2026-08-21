.align 2

.global track_331

track_331_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 40
	.byte VOL, 50
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte FINE

.align 2

track_331:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_331_0

.align 2
