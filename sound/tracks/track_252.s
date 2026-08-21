.align 2

.global track_252

track_252_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 10
	.byte VOL, 90
	.byte PAN, c_v
	.byte LFOS, 1
	.byte TIE, Cn2, v127
	.byte W01
track_252_lbl_27e542:
	.byte W92
	.byte W03
	.byte GOTO
		.word track_252_lbl_27e542
	.byte W01
	.byte EOT @ Cn2, v127
	.byte FINE

.align 2

track_252:
	.byte 1
	.byte 0
	.byte 254
	.byte 0
	.word 0x80a71ec
	.word track_252_0

.align 2
