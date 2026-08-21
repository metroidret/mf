.align 2

.global track_71

track_71_0:
	.byte KEYSH, 0
track_71_lbl_269d7a:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 39
	.byte N06, Dn3, v112
	.byte W24
	.byte Fs3 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_71_lbl_269d7a
	.byte FINE

.align 2

track_71:
	.byte 1
	.byte 71
	.byte 130
	.byte 128
	.word 0x80a5d94
	.word track_71_0

.align 2
