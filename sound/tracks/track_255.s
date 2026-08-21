.align 2

.global track_255

track_255_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte MOD, 50
	.byte VOL, 90
	.byte PAN, c_v
	.byte LFOS, 10
	.byte PRIO, 127
	.byte W01
track_255_lbl_27e5b9:
	.byte N72, Cs2, v127
	.byte W72
	.byte LFOS, 25
	.byte N23 @ Cs2, v127
	.byte W23
	.byte LFOS, 40
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 70
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 100
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 127
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 80
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 40
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 10
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 50
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 80
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 127
	.byte N96 @ Cs2, v127
	.byte W96
	.byte LFOS, 50
	.byte TIE @ Cs2, v127
	.byte W96
	.byte W48
	.byte EOT @ Cs2, v127
	.byte GOTO
		.word track_255_lbl_27e5b9
	.byte FINE

track_255_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 42
	.byte PAN, c_v
	.byte N24, Cn2, v127
	.byte W01
track_255_lbl_27e601:
	.byte W92
	.byte W03
	.byte N24, Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W96
	.byte N24 @ Cn2, v127
	.byte W48
	.byte GOTO
		.word track_255_lbl_27e601
	.byte FINE

.align 2

track_255:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a71ec
	.word track_255_0
	.word track_255_1

.align 2
