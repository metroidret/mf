.align 2

.global track_280

track_280_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 9
	.byte PAN, c_v
	.byte W01
track_280_lbl_27f43f:
	.byte N48, Fn2, v127
	.byte W05
	.byte VOL, 11
	.byte W06
	.byte 14 @ VOL
	.byte W06
	.byte 15 @ VOL
	.byte W06
	.byte 15 @ VOL
	.byte W06
	.byte 15 @ VOL
	.byte W06
	.byte 13 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 9 @ VOL
	.byte W01
	.byte N48 @ Fn2, v127
	.byte W05
	.byte VOL, 7
	.byte W06
	.byte 4 @ VOL
	.byte W06
	.byte 3 @ VOL
	.byte W12
	.byte 3 @ VOL
	.byte W06
	.byte 5 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W06
	.byte 8 @ VOL
	.byte W01
	.byte N48 @ Fn2, v127
	.byte W05
	.byte VOL, 9
	.byte W06
	.byte 10 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W06
	.byte 10 @ VOL
	.byte W06
	.byte 9 @ VOL
	.byte W06
	.byte 8 @ VOL
	.byte W01
	.byte N48 @ Fn2, v127
	.byte W05
	.byte VOL, 7
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 5 @ VOL
	.byte W09
	.byte 5 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte W01
	.byte GOTO
		.word track_280_lbl_27f43f
	.byte FINE

.align 2

track_280:
	.byte 1
	.byte 0
	.byte 145
	.byte 0
	.word 0x80a71ec
	.word track_280_0

.align 2
