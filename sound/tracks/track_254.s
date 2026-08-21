.align 2

.global track_254

track_254_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 50
	.byte PAN, c_v
	.byte W01
track_254_lbl_27e587:
	.byte N72, Cn3, v127
	.byte W72
	.byte N23 @ Cn3, v127
	.byte W23
	.byte N96 @ Cn3, v127
	.byte W96
	.byte N96 @ Cn3, v127
	.byte W96
	.byte N96 @ Cn3, v127
	.byte W96
	.byte GOTO
		.word track_254_lbl_27e587
	.byte FINE

.align 2

track_254:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_254_0

.align 2
