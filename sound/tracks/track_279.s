.align 2

.global track_279

track_279_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 60
	.byte PAN, c_v
track_279_lbl_27f38e:
	.byte W24
	.byte W02
	.byte N02, Cn4, v020
	.byte W03
	.byte N03, Gn3, v052
	.byte W03
	.byte N04, Cn3, v080
	.byte W04
	.byte N03, Cn3, v040
	.byte W36
	.byte W02
	.byte Cn4, v080 @ N03
	.byte W04
	.byte N04, Cn3 @ v080
	.byte W18
	.byte W23
	.byte N02, Dn3 @ v080
	.byte W02
	.byte N03, Gn3, v040
	.byte W03
	.byte N04, Dn4, v060
	.byte W36
	.byte W03
	.byte N02, Dn4, v020
	.byte W03
	.byte N03, An3, v052
	.byte W04
	.byte N04, Cn3, v080
	.byte W22
	.byte W24
	.byte Cn3, v072 @ N04
	.byte W05
	.byte Cs4, v080 @ N04
	.byte W09
	.byte GOTO
		.word track_279_lbl_27f38e
	.byte FINE

track_279_1:
	.byte KEYSH, 0
	.byte VOICE, 34
	.byte VOL, 60
	.byte PAN, c_v
track_279_lbl_27f3d5:
	.byte W21
	.byte N10, Cn3, v100
	.byte W03
	.byte VOL, 33
	.byte W02
	.byte 57 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W42
	.byte N05 @ Cn3, v100
	.byte W23
	.byte W56
	.byte W03
	.byte VOL, 28
	.byte N15, Cn3, v080
	.byte W02
	.byte VOL, 43
	.byte W02
	.byte 37 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W24
	.byte W10
	.byte 60 @ VOL
	.byte N21 @ Cn3, v080
	.byte W04
	.byte VOL, 41
	.byte W02
	.byte 29 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W01
	.byte GOTO
		.word track_279_lbl_27f3d5
	.byte FINE

.align 2

track_279:
	.byte 2
	.byte 0
	.byte 190
	.byte 0
	.word 0x80a71ec
	.word track_279_0
	.word track_279_1

.align 2
