.align 2

.global track_14

track_14_0:
	.byte KEYSH, 0
track_14_lbl_25f726:
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 70
	.byte N24, Fn3, v064
	.byte W96
	.byte W96
	.byte GOTO
		.word track_14_lbl_25f726
	.byte FINE

.align 2

track_14:
	.byte 1
	.byte 14
	.byte 130
	.byte 128
	.word 0x80a5f68
	.word track_14_0

.align 2
