.align 2

.global track_355

track_355_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 60
	.byte PAN, c_v
	.byte N04, Dn2, v127
	.byte W04
	.byte An1, v080 @ N04
	.byte W04
	.byte Fn1, v052 @ N04
	.byte W04
	.byte FINE

.align 2

track_355:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_355_0

.align 2
