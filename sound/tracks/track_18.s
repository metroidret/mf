.align 2

.global track_18

track_18_0:
	.byte KEYSH, 0
track_18_lbl_25fdfe:
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 70
	.byte N24, Fn3, v064
	.byte W96
	.byte W96
	.byte GOTO
		.word track_18_lbl_25fdfe
	.byte FINE

.align 2

track_18:
	.byte 1
	.byte 18
	.byte 130
	.byte 128
	.word 0x80a5f68
	.word track_18_0

.align 2
