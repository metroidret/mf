.align 2

.global track_75

track_75_0:
	.byte KEYSH, 0
track_75_lbl_26a6d6:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 39
	.byte N06, Gs3, v112
	.byte W24
	.byte En3 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_75_lbl_26a6d6
	.byte FINE

.align 2

track_75:
	.byte 1
	.byte 75
	.byte 130
	.byte 128
	.word 0x80a5d94
	.word track_75_0

.align 2
