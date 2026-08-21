.align 2

.global track_500

track_500_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 40
	.byte PAN, c_v
	.byte N02, Cn2, v127
	.byte W04
	.byte FINE

.align 2

track_500:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a7750
	.word track_500_0

.align 2
