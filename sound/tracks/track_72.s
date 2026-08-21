.align 2

.global track_72

track_72_0:
	.byte KEYSH, 0
track_72_lbl_269d9a:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 31
	.byte N06, Cn3, v112
	.byte W24
	.byte En3 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_72_lbl_269d9a
	.byte FINE

.align 2

track_72:
	.byte 1
	.byte 72
	.byte 130
	.byte 128
	.word 0x80a59e0
	.word track_72_0

.align 2
