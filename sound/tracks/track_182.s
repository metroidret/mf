.align 2

.global track_182

track_182_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 60
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte VOICE, 2
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 3
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 4
	.byte N04 @ Cn3, v127
	.byte W04
	.byte FINE

.align 2

track_182:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word 0x80a74c8
	.word track_182_0

.align 2
