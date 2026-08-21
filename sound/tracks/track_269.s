.align 2

.global track_269

track_269_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 30
	.byte VOL, 5
	.byte PAN, c_v
	.byte N72, Cn3, v080
	.byte W02
	.byte VOL, 7
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W08
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W01
	.byte FINE

track_269_1:
	.byte KEYSH, 0
	.byte VOICE, 32
	.byte MOD, 35
	.byte VOL, 33
	.byte PAN, c_v
	.byte LFOS, 110
	.byte MODT, 1
	.byte W09
	.byte N44, Fs4, v072
	.byte W64
	.byte FINE

track_269_2:
	.byte KEYSH, 0
	.byte VOICE, 31
	.byte MOD, 10
	.byte VOL, 44
	.byte PAN, c_v
	.byte LFOS, 127
	.byte MODT, 1
	.byte W16
	.byte N32, Gn3, v072
	.byte W56
	.byte W01
	.byte FINE

.align 2

track_269:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_269_0
	.word track_269_1
	.word track_269_2

.align 2
