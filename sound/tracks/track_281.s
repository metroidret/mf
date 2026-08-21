.align 2

.global track_281

track_281_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte MOD, 30
	.byte VOL, 7
	.byte PAN, c_v
	.byte LFOS, 127
	.byte MODT, 1
	.byte TIE, Cn4, v080
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
track_281_lbl_27f4bb:
	.byte W92
	.byte GOTO
		.word track_281_lbl_27f4bb
	.byte W01
	.byte EOT @ Cn4, v080
	.byte FINE

.align 2

track_281:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_281_0

.align 2
