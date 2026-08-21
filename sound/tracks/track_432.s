.align 2

.global track_432

track_432_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 95
	.byte VOL, 50
	.byte PAN, c_v
	.byte W09
	.byte N18, Cn3, v040
	.byte W18
	.byte N12, Cs3, v060
	.byte W12
	.byte Cs3, v080 @ N12
	.byte W12
	.byte N10, Dn3, v100
	.byte W10
	.byte N10 @ Dn3, v100
	.byte W10
	.byte N12, Cs3, v080
	.byte W12
	.byte Cs3, v060 @ N12
	.byte W12
	.byte N18, Cn3, v040
	.byte W01
	.byte W17
	.byte FINE

.align 2

track_432:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_432_0

.align 2
