.align 2

.global track_632

track_632_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 120
	.byte PAN, c_v
	.byte N15, Cn3, v120
	.byte W15
	.byte VOICE, 25
	.byte N18, Ds2, v127
	.byte W32
	.byte W01
	.byte FINE

track_632_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 127
	.byte PAN, c_v
	.byte N04, Bn2, v080
	.byte W05
	.byte Bn2, v127 @ N04
	.byte W05
	.byte Bn2, v100 @ N04
	.byte W04
	.byte VOICE, 23
	.byte N04, Bn2, v080
	.byte W04
	.byte VOICE, 24
	.byte N04, Bn2, v040
	.byte W30
	.byte FINE

.align 2

track_632:
	.byte 2
	.byte 0
	.byte 255
	.byte 0
	.word 0x80a7aa4
	.word track_632_0
	.word track_632_1

.align 2
