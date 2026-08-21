.align 2

.global track_155

track_155_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 86
	.byte PAN, c_v+22
	.byte W04
	.byte N15, Cn3, v112
	.byte W15
	.byte Cn3, v100 @ N15
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W44
	.byte W03
	.byte W72
	.byte FINE

track_155_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 86
	.byte PAN, c_v+22
	.byte N15, Cn3, v112
	.byte W15
	.byte Dn3, v100 @ N15
	.byte W15
	.byte Bn2, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W48
	.byte W03
	.byte W72
	.byte FINE

track_155_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 90
	.byte PAN, c_v+22
	.byte W02
	.byte N04, Cn3, v100
	.byte W05
	.byte Dn3 @ N04, v100
	.byte W05
	.byte Cn3 @ N04, v100
	.byte W04
	.byte VOICE, 6
	.byte N04, Cn3, v127
	.byte W04
	.byte VOICE, 7
	.byte N04, En3 @ v127
	.byte W32
	.byte VOICE, 2
	.byte VOL, 51
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, Cn3, v040
	.byte W10
	.byte W72
	.byte FINE

track_155_3:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 86
	.byte PAN, c_v+26
	.byte W32
	.byte W01
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, Cn3, v040
	.byte W28
	.byte W01
	.byte W72
	.byte FINE

track_155_4:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 110
	.byte PAN, c_v+22
	.byte N05, Fn2, v127
	.byte W05
	.byte N12, Gs2 @ v127
	.byte W42
	.byte W01
	.byte VOICE, 9
	.byte PAN, c_v+22
	.byte N60, Dn2 @ v127
	.byte W48
	.byte W72
	.byte FINE

.align 2

track_155:
	.byte 5
	.byte 0
	.byte 254
	.byte 0
	.word 0x80a808c
	.word track_155_0
	.word track_155_1
	.word track_155_2
	.word track_155_3
	.word track_155_4

.align 2
