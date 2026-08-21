.align 2

.global track_253

track_253_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte TIE, Cn3, v127
	.byte W01
track_253_lbl_27e566:
	.byte W92
	.byte W03
	.byte GOTO
		.word track_253_lbl_27e566
	.byte W01
	.byte EOT @ Cn3, v127
	.byte FINE

.align 2

track_253:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_253_0

.align 2
