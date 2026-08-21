.align 2

.global track_99

track_99_0:
	.byte KEYSH, 0
track_99_lbl_270252:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 39
	.byte N06, Fs3, v072
	.byte W24
	.byte As3 @ N06, v072
	.byte W72
	.byte GOTO
		.word track_99_lbl_270252
	.byte FINE

.align 2

track_99:
	.byte 1
	.byte 99
	.byte 130
	.byte 128
	.word 0x80a5d94
	.word track_99_0

.align 2
