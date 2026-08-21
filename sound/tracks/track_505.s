.align 2

.global track_505

track_505_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte VOL, 105
	.byte BEND, c_v
	.byte N10, Dn3, v016
	.byte W10
	.byte Dn3, v004 @ N10
	.byte W10
	.byte FINE

.align 2

track_505:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_505_0

.align 2
