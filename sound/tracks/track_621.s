.align 2

.global track_621

track_621_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 122
	.byte W04
	.byte N15, Cn3, v127
	.byte W15
	.byte N15 @ Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte N11, Cn3, v040
	.byte W11
	.byte FINE

track_621_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 122
	.byte N15, Cn3, v127
	.byte W15
	.byte N15 @ Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte FINE

track_621_2:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 122
	.byte W02
	.byte N04, Cn3, v120
	.byte W05
	.byte N04 @ Cn3, v120
	.byte W05
	.byte Cn3, v100 @ N04
	.byte W04
	.byte VOICE, 14
	.byte N04, Cn3, v060
	.byte W04
	.byte VOICE, 15
	.byte N04 @ Cn3, v060
	.byte W16
	.byte VOL, 28
	.byte N08, Cn3, v040
	.byte W24
	.byte FINE

track_621_3:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 85
	.byte PAN, c_v+46
	.byte PRIO, 123
	.byte W01
	.byte N28, Cn3, v092
	.byte W30
	.byte Cn3, v072 @ N28
	.byte W28
	.byte W01
	.byte FINE

track_621_4:
	.byte KEYSH, 0
	.byte VOICE, 16
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 122
	.byte N05, Fn2, v127
	.byte W05
	.byte N20, Dn2 @ v127
	.byte W54
	.byte W01
	.byte FINE

.align 2

track_621:
	.byte 5
	.byte 0
	.byte 129
	.byte 0
	.word 0x80a7aa4
	.word track_621_0
	.word track_621_1
	.word track_621_2
	.word track_621_3
	.word track_621_4

.align 2
