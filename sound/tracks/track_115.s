.align 2

.global track_115

track_115_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 30
	.byte PAN, c_v
	.byte N02, Cn3, v127
	.byte W12
	.byte FINE

.align 2

track_115:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_115_0

.align 2
