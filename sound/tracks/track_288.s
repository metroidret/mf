.align 2

.global track_288

track_288_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte MOD, 20
	.byte VOL, 60
	.byte PAN, c_v
	.byte LFOS, 30
	.byte W01
track_288_lbl_27f787:
	.byte TIE, Cn2, v127
	.byte W92
	.byte W03
	.byte W07
	.byte EOT @ Cn2, v127
	.byte TIE @ Cn2, v127
	.byte W88
	.byte W01
	.byte W13
	.byte EOT @ Cn2, v127
	.byte GOTO
		.word track_288_lbl_27f787
	.byte FINE

track_288_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 18
	.byte PAN, c_v
	.byte PRIO, 127
	.byte W01
track_288_lbl_27f7a4:
	.byte N10, Gn3, v100
	.byte W48
	.byte W03
	.byte N10 @ Gn3, v100
	.byte W44
	.byte W07
	.byte N10 @ Gn3, v100
	.byte W48
	.byte W03
	.byte N10 @ Gn3, v100
	.byte W36
	.byte W02
	.byte W13
	.byte GOTO
		.word track_288_lbl_27f7a4
	.byte FINE

.align 2

track_288:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_288_0
	.word track_288_1

.align 2
