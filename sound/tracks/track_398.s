.align 2

.global track_398

track_398_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 66
	.byte VOL, 31
	.byte PAN, c_v
	.byte N96, Cn1, v127
	.byte W02
	.byte VOL, 40
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W06
	.byte 48 @ VOL
	.byte W06
	.byte 46 @ VOL
	.byte W06
	.byte 43 @ VOL
	.byte W06
	.byte 40 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 24 @ VOL
	.byte W06
	.byte 19 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W05
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_398_1:
	.byte KEYSH, 0
	.byte VOICE, 67
	.byte VOL, 39
	.byte PAN, c_v
	.byte N48, Ds2, v127
	.byte W96
	.byte FINE

.align 2

track_398:
	.byte 2
	.byte 0
	.byte 150
	.byte 0
	.word 0x80a6d54
	.word track_398_0
	.word track_398_1

.align 2
