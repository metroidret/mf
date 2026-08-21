.align 2

.global track_622

track_622_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 22
	.byte W04
	.byte N10, Cn3, v060
	.byte W10
	.byte Cn3, v127 @ N10
	.byte W10
	.byte Cn3, v080 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W10
	.byte Cn3, v100 @ N10
	.byte W10
	.byte Cn3, v040 @ N10
	.byte W10
	.byte Cn3, v060 @ N10
	.byte W10
	.byte Cn3, v012 @ N10
	.byte W22
	.byte W96
	.byte FINE

track_622_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 22
	.byte N10, Cn3, v127
	.byte W10
	.byte Cn3, v080 @ N10
	.byte W10
	.byte Cn3, v040 @ N10
	.byte W10
	.byte Cn3, v100 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W10
	.byte Cn3, v020 @ N10
	.byte W10
	.byte Cn3, v100 @ N10
	.byte W10
	.byte Cn3, v052 @ N10
	.byte W24
	.byte W02
	.byte W96
	.byte FINE

track_622_2:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 80
	.byte PAN, c_v
	.byte PRIO, 22
	.byte W02
	.byte N04, Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 14
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 15
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 13
	.byte VOL, 127
	.byte W02
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 14
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 15
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 13
	.byte VOL, 40
	.byte W02
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 14
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 15
	.byte N04, Cn3, v060
	.byte W16
	.byte VOICE, 12
	.byte VOL, 60
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Cn3, v127
	.byte W06
	.byte W08
	.byte N12, Cn3, v052
	.byte W12
	.byte VOL, 40
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Cn3, v127
	.byte W14
	.byte N12, Cn3, v052
	.byte W12
	.byte VOL, 20
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, Cn3, v127
	.byte W14
	.byte N12, Cn3, v052
	.byte W24
	.byte FINE

track_622_3:
	.byte KEYSH, 0
	.byte W48
	.byte VOICE, 26
	.byte VOL, 127
	.byte PAN, c_v
	.byte W02
	.byte N05, Fn2, v127
	.byte W03
	.byte N12, Gs2, v112
	.byte W42
	.byte W01
	.byte W06
	.byte VOICE, 27
	.byte N24, En2, v127
	.byte W90
	.byte FINE

.align 2

track_622:
	.byte 4
	.byte 0
	.byte 222
	.byte 0
	.word 0x80a7aa4
	.word track_622_0
	.word track_622_1
	.word track_622_2
	.word track_622_3

.align 2
