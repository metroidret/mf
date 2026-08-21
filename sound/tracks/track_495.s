.align 2

.global track_495

track_495_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 52
	.byte VOL, 40
	.byte PAN, c_v
	.byte W48
	.byte W01
	.byte N05, Ds2, v080
	.byte W05
	.byte VOICE, 53
	.byte N28, As2 @ v080
	.byte W07
	.byte VOL, 40
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_495_1:
	.byte KEYSH, 0
	.byte VOICE, 54
	.byte VOL, 25
	.byte PAN, c_v
	.byte N15, En3, v060
	.byte W01
	.byte VOL, 28
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W10
	.byte VOICE, 16
	.byte N07, Cn3, v127
	.byte W07
	.byte Cn3, v060 @ N07
	.byte W07
	.byte Cn3, v020 @ N07
	.byte W54
	.byte FINE

.align 2

track_495:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_495_0
	.word track_495_1

.align 2
