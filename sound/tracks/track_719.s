.align 2

.global track_719

track_719_0:
	.byte KEYSH, 0
track_719_lbl_27bf36:
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 80
	.byte TIE, Cn3, v080
	.byte W60
	.byte W60
	.byte W36
	.byte EOT @ Cn3, v080
	.byte W24
	.byte W60
	.byte W36
	.byte GOTO
		.word track_719_lbl_27bf36
	.byte FINE

.align 2

track_719:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_719_0

.align 2
