.align 2

.global track_98

track_98_0:
	.byte KEYSH, 0
track_98_lbl_27022e:
	.byte TEMPO, 42
	.byte VOICE, 1
	.byte VOL, 78
	.byte N06, En2, v112
	.byte W12
	.byte Fs2 @ N06, v112
	.byte W12
	.byte Gs2 @ N06, v112
	.byte W48
	.byte N06 @ Gs2, v112
	.byte W24
	.byte GOTO
		.word track_98_lbl_27022e
	.byte FINE

.align 2

track_98:
	.byte 1
	.byte 98
	.byte 130
	.byte 128
	.word 0x80a5d94
	.word track_98_0

.align 2
