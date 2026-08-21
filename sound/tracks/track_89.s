.align 2

.global track_89

track_89_0:
	.byte KEYSH, 0
track_89_lbl_26d3ba:
	.byte TEMPO, 45
	.byte VOICE, 13
	.byte VOL, 39
	.byte PAN, c_v
	.byte PRIO, 110
	.byte N96, Dn2, v100
	.byte W96
	.byte As1 @ N96, v100
	.byte W96
	.byte Bn1 @ N96, v100
	.byte W96
	.byte Fs1 @ N96, v100
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W15
	.byte GOTO
		.word track_89_lbl_26d3ba
	.byte FINE

track_89_1:
	.byte KEYSH, 0
track_89_lbl_26d3db:
	.byte VOICE, 13
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 109
	.byte W12
	.byte N64, Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W12
	.byte N64 @ Ds1, v112
	.byte W84
	.byte W15
	.byte GOTO
		.word track_89_lbl_26d3db
	.byte FINE

.align 2

track_89:
	.byte 2
	.byte 89
	.byte 130
	.byte 128
	.word 0x80a62f8
	.word track_89_0
	.word track_89_1

.align 2
