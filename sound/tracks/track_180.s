.align 2

.global track_180

track_180_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 100
	.byte PAN, c_v
	.byte N01, Gn2, v127
	.byte W01
	.byte N04, As2 @ v127
	.byte W04
	.byte Dn2 @ N04, v127
	.byte W04
	.byte An1 @ N04, v127
	.byte W04
	.byte En1 @ N04, v127
	.byte W04
	.byte Cn1 @ N04, v127
	.byte W04
	.byte FINE

.align 2

track_180:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a74c8
	.word track_180_0

.align 2
