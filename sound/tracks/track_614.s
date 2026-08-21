.align 2

.global track_614

track_614_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N15, Cn3, v127
	.byte W15
	.byte N14, Cn3, v060
	.byte W14
	.byte N10, Cn3, v020
	.byte W11
	.byte FINE

track_614_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 94
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte N10, Cn3, v020
	.byte W10
	.byte FINE

.align 2

track_614:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_614_0
	.word track_614_1

.align 2
