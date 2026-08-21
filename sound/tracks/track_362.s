.align 2

.global track_362

track_362_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 60
	.byte PAN, c_v
	.byte N08, En2, v080
	.byte W08
	.byte VOICE, 59
	.byte N08 @ En2, v080
	.byte W08
	.byte En2, v040 @ N08
	.byte W08
	.byte FINE

.align 2

track_362:
	.byte 1
	.byte 0
	.byte 167
	.byte 0
	.word 0x80a6d54
	.word track_362_0

.align 2
