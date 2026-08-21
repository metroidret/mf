.align 2

.global track_181

track_181_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 100
	.byte PAN, c_v
	.byte N01, Cn1, v127
	.byte W01
	.byte N04, En1 @ v127
	.byte W04
	.byte Fs1 @ N04, v127
	.byte W04
	.byte As1 @ N04, v127
	.byte W04
	.byte Cn2 @ N04, v127
	.byte W04
	.byte As1 @ N04, v127
	.byte W04
	.byte FINE

.align 2

track_181:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a74c8
	.word track_181_0

.align 2
