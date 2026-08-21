.align 2

.global track_19

track_19_0:
	.byte KEYSH, 0
track_19_lbl_25fe1e:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 35
	.byte N06, Dn3, v112
	.byte W24
	.byte Fs3 @ N06, v112
	.byte W72
	.byte GOTO
		.word track_19_lbl_25fe1e
	.byte FINE

.align 2

track_19:
	.byte 1
	.byte 19
	.byte 130
	.byte 128
	.word 0x80a5f68
	.word track_19_0

.align 2
