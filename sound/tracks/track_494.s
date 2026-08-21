.align 2

.global track_494

track_494_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 14
	.byte PAN, c_v
	.byte N44, Gn3, v092
	.byte W02
	.byte VOL, 14
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W44
	.byte N03, Cn4, v080
	.byte W03
	.byte N04, Gn3, v120
	.byte W04
	.byte N03, Gn3, v060
	.byte W03
	.byte Gn3, v020 @ N03
	.byte W10
	.byte Cn4, v080 @ N03
	.byte W03
	.byte N04, Gn3, v120
	.byte W04
	.byte N03, Gn3, v060
	.byte W03
	.byte Gn3, v020 @ N03
	.byte W10
	.byte Cn4, v080 @ N03
	.byte W03
	.byte N04, Gn3, v120
	.byte W04
	.byte N03, Gn3, v060
	.byte W03
	.byte Gn3, v020 @ N03
	.byte W03
	.byte FINE

.align 2

track_494:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_494_0

.align 2
