.align 2

.global track_612

track_612_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 69
	.byte PAN, c_v
	.byte N10, Dn3, v060
	.byte W01
	.byte VOL, 77
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W05
	.byte 77 @ VOL
	.byte N10, Fn3, v080
	.byte W01
	.byte VOL, 90
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W21
	.byte FINE

track_612_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N15, En3, v127
	.byte W15
	.byte VOICE, 1
	.byte N28, Cn3 @ v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_612:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a7aa4
	.word track_612_0
	.word track_612_1

.align 2
