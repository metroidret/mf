.align 2

.global track_338

track_338_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 40
	.byte PAN, c_v
	.byte N04, Cn3, v112
	.byte W04
	.byte VOICE, 44
	.byte N03, Cn3, v127
	.byte W03
	.byte FINE

.align 2

track_338:
	.byte 1
	.byte 0
	.byte 138
	.byte 0
	.word 0x80a6d54
	.word track_338_0

.align 2
