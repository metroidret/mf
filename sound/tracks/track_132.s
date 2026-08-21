.align 2

.global track_132

track_132_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 50
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte FINE

.align 2

track_132:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_132_0

.align 2
