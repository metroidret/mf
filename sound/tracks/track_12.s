.align 2

.global track_12

track_12_0:
	.byte KEYSH, 0
track_12_lbl_25f6e6:
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 70
	.byte N24, Fn3, v064
	.byte W96
	.byte W96
	.byte GOTO
		.word track_12_lbl_25f6e6
	.byte FINE

.align 2

track_12:
	.byte 1
	.byte 12
	.byte 130
	.byte 128
	.word 0x80a5f68
	.word track_12_0

.align 2
