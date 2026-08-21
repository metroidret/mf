.align 2

.global track_70

track_70_0:
	.byte KEYSH, 0
track_70_lbl_269d5a:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 39
	.byte N06, En3, v112
	.byte W24
	.byte Cn3 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_70_lbl_269d5a
	.byte FINE

.align 2

track_70:
	.byte 1
	.byte 70
	.byte 130
	.byte 128
	.word 0x80a5d94
	.word track_70_0

.align 2
