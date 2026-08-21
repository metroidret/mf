.align 2

.global track_425

track_425_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 0
	.byte PAN, c_v
	.byte W20
	.byte N10, Fn3, v052
	.byte W10
	.byte Gn3 @ N10, v052
	.byte W10
	.byte An3 @ N10, v052
	.byte W10
	.byte Gn3 @ N10, v052
	.byte W10
	.byte Fn3 @ N10, v052
	.byte W10
	.byte En3 @ N10, v052
	.byte W10
	.byte FINE

.align 2

track_425:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_425_0

.align 2
