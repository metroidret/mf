.align 2

.global track_615

track_615_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W15
	.byte FINE

track_615_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 103
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N10, Cn3, v127
	.byte W10
	.byte Cn3, v060 @ N10
	.byte W10
	.byte VOICE, 3
	.byte N23, Cn3, v040
	.byte W24
	.byte W01
	.byte FINE

.align 2

track_615:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_615_0
	.word track_615_1

.align 2
