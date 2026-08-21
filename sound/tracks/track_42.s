.align 2

.global track_42

track_42_0:
	.byte KEYSH, 0
track_42_lbl_2631de:
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
		.word track_42_lbl_2631de
	.byte FINE

track_42_1:
	.byte KEYSH, 0
track_42_lbl_2631ff:
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
		.word track_42_lbl_2631ff
	.byte FINE

track_42_2:
	.byte KEYSH, 0
track_42_lbl_26322a:
	.byte VOICE, 12
	.byte VOL, 23
	.byte PAN, c_v
	.byte PRIO, 108
	.byte N32, Cn3, v028
	.byte W32
	.byte N32 @ Cn3, v028
	.byte W32
	.byte N32 @ Cn3, v028
	.byte W32
track_42_lbl_26323a:
	.byte N32, Cn3, v028
	.byte W32
	.byte N32 @ Cn3, v028
	.byte W32
	.byte N32 @ Cn3, v028
	.byte W32
	.byte PEND
	.byte PATT
		.word track_42_lbl_26323a
	.byte PATT
		.word track_42_lbl_26323a
	.byte PATT
		.word track_42_lbl_26323a
	.byte PATT
		.word track_42_lbl_26323a
	.byte PATT
		.word track_42_lbl_26323a
	.byte PATT
		.word track_42_lbl_26323a
	.byte N32, Cn3, v028
	.byte W15
	.byte GOTO
		.word track_42_lbl_26322a
	.byte W17
	.byte N32 @ Cn3, v028
	.byte W32
	.byte N32 @ Cn3, v028
	.byte W32
	.byte N32 @ Cn3, v028
	.byte W32
	.byte FINE

.align 2

track_42:
	.byte 3
	.byte 42
	.byte 130
	.byte 128
	.word 0x80a62f8
	.word track_42_0
	.word track_42_1
	.word track_42_2

.align 2
