.align 2

.global track_128

track_128_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 18
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte FINE

.align 2

track_128:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_128_0

.align 2
