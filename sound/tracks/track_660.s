.align 2

.global track_660

track_660_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 75
	.byte PAN, c_v
	.byte N15, Cn3, v120
	.byte W15
	.byte VOICE, 13
	.byte N18, Ds2, v127
	.byte W44
	.byte W01
	.byte FINE

track_660_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 2
	.byte N04, Bn2, v080
	.byte W05
	.byte Bn2, v127 @ N04
	.byte W05
	.byte Bn2, v100 @ N04
	.byte W04
	.byte VOICE, 16
	.byte N04, Bn2, v080
	.byte W04
	.byte VOICE, 17
	.byte N04, Bn2, v040
	.byte W42
	.byte FINE

.align 2

track_660:
	.byte 2
	.byte 0
	.byte 250
	.byte 0
	.word 0x80a7e10
	.word track_660_0
	.word track_660_1

.align 2
