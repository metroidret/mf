.align 2

.global track_40

track_40_0:
	.byte KEYSH, 0
track_40_lbl_26319e:
	.byte TEMPO, 60
	.byte VOICE, 5
	.byte VOL, 39
	.byte N06, En2, v112
	.byte W24
	.byte Cn2 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_40_lbl_26319e
	.byte FINE

.align 2

track_40:
	.byte 1
	.byte 40
	.byte 130
	.byte 128
	.word 0x80a59e0
	.word track_40_0

.align 2
