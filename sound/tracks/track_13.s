.align 2

.global track_13

track_13_0:
	.byte KEYSH, 0
track_13_lbl_25f706:
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 70
	.byte N24, Fn3, v064
	.byte W96
	.byte W96
	.byte GOTO
		.word track_13_lbl_25f706
	.byte FINE

.align 2

track_13:
	.byte 1
	.byte 13
	.byte 130
	.byte 128
	.word 0x80a5f68
	.word track_13_0

.align 2
