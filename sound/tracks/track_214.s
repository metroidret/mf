.align 2

.global track_214

track_214_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 9
	.byte N10, Cn3, v040
	.byte W24
	.byte W02
	.byte FINE

track_214_1:
	.byte KEYSH, 0
	.byte VOICE, 30
	.byte VOL, 51
	.byte PAN, c_v
	.byte N15, Cn3, v100
	.byte W15
	.byte N30, Cn3, v044
	.byte W30
	.byte VOICE, 10
	.byte VOL, 70
	.byte N01, Cs2, v127
	.byte W15
	.byte FINE

.align 2

track_214:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_214_0
	.word track_214_1

.align 2
