.align 2

.global track_711

track_711_0:
	.byte KEYSH, 0
track_711_lbl_27bdea:
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 80
	.byte TIE, Cn3, v080
	.byte W60
	.byte W60
	.byte W24
	.byte EOT @ Cn3, v080
	.byte W36
	.byte W60
	.byte W24
	.byte GOTO
		.word track_711_lbl_27bdea
	.byte FINE

.align 2

track_711:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_711_0

.align 2
