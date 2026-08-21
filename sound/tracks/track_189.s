.align 2

.global track_189

track_189_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte MOD, 20
	.byte VOL, 120
	.byte PAN, c_v
	.byte LFOS, 10
	.byte TIE, Cn3, v127
	.byte W96
	.byte W24
	.byte EOT @ Cn3, v127
	.byte W72
	.byte FINE

track_189_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 120
	.byte PAN, c_v
	.byte N12, Fn2, v127
	.byte W24
	.byte Fn2, v100 @ N12
	.byte W24
	.byte Fn2, v127 @ N12
	.byte W24
	.byte Fn2, v100 @ N12
	.byte W24
	.byte W96
	.byte FINE

.align 2

track_189:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a74c8
	.word track_189_0
	.word track_189_1

.align 2
