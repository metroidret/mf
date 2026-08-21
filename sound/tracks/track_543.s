.align 2

.global track_543

track_543_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 127
	.byte PAN, c_v+6
	.byte PRIO, 1
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v064 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W48
	.byte W01
	.byte FINE

track_543_1:
	.byte KEYSH, 0
	.byte W32
	.byte W02
	.byte VOICE, 1
	.byte VOL, 35
	.byte PAN, c_v+6
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W15
	.byte FINE

track_543_2:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W48
	.byte W01
	.byte FINE

.align 2

track_543:
	.byte 3
	.byte 0
	.byte 202
	.byte 0
	.word 0x80a808c
	.word track_543_0
	.word track_543_1
	.word track_543_2

.align 2
