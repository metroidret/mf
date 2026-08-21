.align 2

.global track_273

track_273_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte PAN, c_v
track_273_lbl_27f08c:
	.byte VOL, 3
	.byte BENDR, 12
	.byte BEND, c_v-48
	.byte N16, Gn3, v080
	.byte W03
	.byte VOL, 6
	.byte BEND, c_v-45
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 31
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 39
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v-1
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v+39
	.byte W03
	.byte VOL, 35
	.byte N05, Gn3, v100
	.byte W07
	.byte Gn3, v052 @ N05
	.byte W08
	.byte Gn3, v016 @ N05
	.byte W15
	.byte GOTO
		.word track_273_lbl_27f08c
	.byte FINE

track_273_1:
	.byte KEYSH, 0
	.byte VOL, 43
	.byte PAN, c_v
track_273_lbl_27f0cc:
	.byte VOICE, 24
	.byte W02
	.byte N03, Cn3, v032
	.byte W03
	.byte En3, v040 @ N03
	.byte W03
	.byte An3, v052 @ N03
	.byte W03
	.byte Bn3 @ N03, v052
	.byte W03
	.byte Cn4 @ N03, v052
	.byte W03
	.byte Dn4 @ N03, v052
	.byte W03
	.byte VOICE, 25
	.byte N03, Fn4, v040
	.byte W24
	.byte W03
	.byte GOTO
		.word track_273_lbl_27f0cc
	.byte FINE

track_273_2:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte MOD, 15
	.byte VOL, 50
	.byte PAN, c_v
	.byte LFOS, 120
track_273_lbl_27f0f8:
	.byte TIE, Cs4, v080
	.byte W44
	.byte W03
	.byte GOTO
		.word track_273_lbl_27f0f8
	.byte W48
	.byte W01
	.byte EOT @ Cs4, v080
	.byte W01
	.byte FINE

.align 2

track_273:
	.byte 3
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a71ec
	.word track_273_0
	.word track_273_1
	.word track_273_2

.align 2
