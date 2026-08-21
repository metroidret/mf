.align 2

.global track_294

track_294_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 58
	.byte MOD, 5
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 2
	.byte N96, Cn3, v080
	.byte W05
	.byte VOL, 4
	.byte W06
	.byte 10 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W06
	.byte 19 @ VOL
	.byte W06
	.byte 24 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W06
	.byte 44 @ VOL
	.byte W06
	.byte 49 @ VOL
	.byte W06
	.byte 54 @ VOL
	.byte W06
	.byte 59 @ VOL
	.byte W06
	.byte 63 @ VOL
	.byte W06
	.byte 69 @ VOL
	.byte W06
	.byte 74 @ VOL
	.byte W06
	.byte 78 @ VOL
	.byte W01
track_294_lbl_27fe83:
	.byte N96, Cn3, v080
	.byte W96
	.byte N96 @ Cn3, v080
	.byte W96
	.byte N96 @ Cn3, v080
	.byte W96
	.byte N96 @ Cn3, v080
	.byte W96
	.byte GOTO
		.word track_294_lbl_27fe83
	.byte FINE

.align 2

track_294:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_294_0

.align 2
