.align 2

.global track_83

track_83_0:
	.byte KEYSH, 0
	.byte TEMPO, 50
	.byte VOICE, 13
	.byte VOL, 62
	.byte PAN, c_v-8
	.byte PRIO, 110
	.byte N32, As1, v080
	.byte W36
	.byte N44 @ As1, v080
	.byte W48
	.byte N10 @ As1, v080
	.byte W12
	.byte N32 @ As1, v080
	.byte W36
	.byte N44 @ As1, v080
	.byte W48
	.byte N10 @ As1, v080
	.byte W12
	.byte TIE, As1, v068
	.byte W96
	.byte W72
	.byte EOT @ As1, v068
	.byte W24
track_83_lbl_26aa9d:
	.byte W96
	.byte GOTO
		.word track_83_lbl_26aa9d
	.byte FINE

track_83_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 23
	.byte PAN, c_v+10
	.byte PRIO, 109
	.byte TIE, An4, v040
	.byte W66
	.byte VOL, 22
	.byte W08
	.byte 20 @ VOL
	.byte W07
	.byte 18 @ VOL
	.byte W08
	.byte 17 @ VOL
	.byte W07
	.byte 15 @ VOL
	.byte W08
	.byte 14 @ VOL
	.byte W07
	.byte 12 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W04
	.byte 25 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W04
	.byte 31 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W02
	.byte EOT @ An4, v040
	.byte W02
	.byte VOL, 42
	.byte W04
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte TIE, Cn5, v032
	.byte W56
	.byte W03
	.byte VOL, 39
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W02
	.byte W02
	.byte 25 @ VOL
	.byte W05
	.byte 23 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W05
	.byte 9 @ VOL
	.byte W04
	.byte 7 @ VOL
	.byte W05
	.byte 6 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W05
	.byte 3 @ VOL
	.byte W07
	.byte EOT @ Cn5, v032
	.byte W24
track_83_lbl_26ab28:
	.byte W96
	.byte GOTO
		.word track_83_lbl_26ab28
	.byte FINE

track_83_2:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 23
	.byte PAN, c_v-4
	.byte PRIO, 108
	.byte TIE, As3, v040
	.byte W66
	.byte VOL, 22
	.byte W08
	.byte 20 @ VOL
	.byte W07
	.byte 18 @ VOL
	.byte W08
	.byte 17 @ VOL
	.byte W07
	.byte 15 @ VOL
	.byte W08
	.byte 14 @ VOL
	.byte W07
	.byte 12 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W04
	.byte 25 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W04
	.byte 31 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W02
	.byte EOT @ As3, v040
	.byte W02
	.byte VOL, 42
	.byte W04
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte TIE, Dn4, v032
	.byte W56
	.byte W03
	.byte VOL, 39
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W02
	.byte W02
	.byte 25 @ VOL
	.byte W05
	.byte 23 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W05
	.byte 9 @ VOL
	.byte W04
	.byte 7 @ VOL
	.byte W05
	.byte 6 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W05
	.byte 3 @ VOL
	.byte W07
	.byte EOT @ Dn4, v032
	.byte W24
track_83_lbl_26abb3:
	.byte W96
	.byte GOTO
		.word track_83_lbl_26abb3
	.byte FINE

track_83_3:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 23
	.byte PAN, c_v+6
	.byte PRIO, 1
	.byte TIE, Dn4, v040
	.byte W66
	.byte VOL, 22
	.byte W08
	.byte 20 @ VOL
	.byte W07
	.byte 18 @ VOL
	.byte W08
	.byte 17 @ VOL
	.byte W07
	.byte 15 @ VOL
	.byte W08
	.byte 14 @ VOL
	.byte W07
	.byte 12 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W04
	.byte 25 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W04
	.byte 31 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W02
	.byte EOT @ Dn4, v040
	.byte W02
	.byte VOL, 42
	.byte W04
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte TIE, Fn4, v032
	.byte W56
	.byte W03
	.byte VOL, 39
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W02
	.byte W02
	.byte 25 @ VOL
	.byte W05
	.byte 23 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W05
	.byte 9 @ VOL
	.byte W04
	.byte 7 @ VOL
	.byte W05
	.byte 6 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W05
	.byte 3 @ VOL
	.byte W07
	.byte EOT @ Fn4, v032
	.byte W24
track_83_lbl_26ac3e:
	.byte W96
	.byte GOTO
		.word track_83_lbl_26ac3e
	.byte FINE

.align 2

track_83:
	.byte 4
	.byte 83
	.byte 130
	.byte 128
	.word 0x80a6718
	.word track_83_0
	.word track_83_1
	.word track_83_2
	.word track_83_3

.align 2
