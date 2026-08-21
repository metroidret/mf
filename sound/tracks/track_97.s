.align 2

.global track_97

track_97_0:
	.byte KEYSH, 0
track_97_lbl_27020e:
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 78
	.byte N24, Fn3, v064
	.byte W96
	.byte W96
	.byte GOTO
		.word track_97_lbl_27020e
	.byte FINE

.align 2

track_97:
	.byte 1
	.byte 97
	.byte 130
	.byte 128
	.word 0x80a6628
	.word track_97_0

.align 2
