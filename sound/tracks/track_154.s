.align 2

.global track_154

track_154_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 80
	.byte PAN, c_v
	.byte N12, Gn3, v127
	.byte W12
	.byte Gn3, v040 @ N12
	.byte W12
	.byte Gn3, v012 @ N12
	.byte W12
	.byte FINE

.align 2

track_154:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a682c
	.word track_154_0

.align 2
