.align 2

.global track_713

track_713_0:
	.byte KEYSH, 0
track_713_lbl_27be36:
	.byte TEMPO, 75
	.byte VOICE, 19
	.byte VOL, 120
	.byte TIE, Cn3, v080
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W24
	.byte EOT @ Cn3, v080
	.byte W36
	.byte W60
	.byte W24
	.byte GOTO
		.word track_713_lbl_27be36
	.byte FINE

.align 2

track_713:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_713_0

.align 2
