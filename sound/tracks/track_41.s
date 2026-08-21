.align 2

.global track_41

track_41_0:
	.byte KEYSH, 0
track_41_lbl_2631be:
	.byte TEMPO, 60
	.byte VOICE, 5
	.byte VOL, 39
	.byte N06, Fs2, v112
	.byte W24
	.byte Dn2 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_41_lbl_2631be
	.byte FINE

.align 2

track_41:
	.byte 1
	.byte 41
	.byte 130
	.byte 128
	.word 0x80a59e0
	.word track_41_0

.align 2
