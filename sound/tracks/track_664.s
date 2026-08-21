.align 2

.global track_664

track_664_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 113
	.byte PAN, c_v
	.byte N15, Cn3, v120
	.byte W15
	.byte VOICE, 12
	.byte N18, Ds2, v127
	.byte W44
	.byte W01
	.byte FINE

track_664_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 120
	.byte PAN, c_v
	.byte N04, Bn2, v080
	.byte W05
	.byte Bn2, v127 @ N04
	.byte W05
	.byte Bn2, v100 @ N04
	.byte W04
	.byte VOICE, 10
	.byte N04, Bn2, v080
	.byte W04
	.byte VOICE, 11
	.byte N04, Bn2, v040
	.byte W42
	.byte FINE

.align 2

track_664:
	.byte 2
	.byte 0
	.byte 198
	.byte 0
	.word 0x80a7f24
	.word track_664_0
	.word track_664_1

.align 2
