.align 2

.global track_55

track_55_0:
	.byte KEYSH, 0
track_55_lbl_268efa:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 39
	.byte N06, Cn3, v112
	.byte W24
	.byte En3 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_55_lbl_268efa
	.byte FINE

.align 2

track_55:
	.byte 1
	.byte 55
	.byte 130
	.byte 128
	.word 0x80a5ca4
	.word track_55_0

.align 2
