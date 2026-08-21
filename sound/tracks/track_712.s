.align 2

.global track_712

track_712_0:
	.byte KEYSH, 0
track_712_lbl_27be0e:
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 80
	.byte TIE, Cn3, v080
	.byte W60
	.byte W60
	.byte W60
	.byte W36
	.byte EOT @ Cn3, v080
	.byte W24
	.byte W60
	.byte W36
	.byte GOTO
		.word track_712_lbl_27be0e
	.byte FINE

.align 2

track_712:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_712_0

.align 2
