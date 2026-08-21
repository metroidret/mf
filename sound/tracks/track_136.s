.align 2

.global track_136

track_136_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N04, Cn3, v127
	.byte W04
	.byte Cn3, v040 @ N04
	.byte W04
	.byte Cn3, v012 @ N04
	.byte W04
	.byte FINE

.align 2

track_136:
	.byte 1
	.byte 0
	.byte 128
	.byte 0
	.word 0x80a682c
	.word track_136_0

.align 2
