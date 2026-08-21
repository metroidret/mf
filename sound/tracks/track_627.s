.align 2

.global track_627

track_627_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N04, Cn3, v080
	.byte W04
	.byte VOICE, 11
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W28
	.byte W01
	.byte FINE

track_627_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 110
	.byte PAN, c_v
	.byte W05
	.byte N10, Dn2, v127
	.byte W42
	.byte W01
	.byte FINE

.align 2

track_627:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a7aa4
	.word track_627_0
	.word track_627_1

.align 2
