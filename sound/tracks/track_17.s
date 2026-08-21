.align 2

.global track_17

track_17_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 56
	.byte PAN, c_v
	.byte PRIO, 110
	.byte N32, Dn3, v060
	.byte W36
	.byte Fn3 @ N32, v060
	.byte W36
	.byte Dn3 @ N32, v060
	.byte W24
	.byte W12
	.byte Cn3 @ N32, v060
	.byte W36
	.byte N66, An2 @ v060
	.byte W48
	.byte W24
	.byte W02
	.byte N66 @ An2, v060
	.byte W68
	.byte W02
	.byte W18
	.byte 0xB6

track_17_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 56
	.byte PAN, c_v+4
	.byte PRIO, 109
	.byte N32, As2, v060
	.byte W36
	.byte N32 @ As2, v060
	.byte W36
	.byte N32 @ As2, v060
	.byte W24
	.byte W12
	.byte N32 @ As2, v060
	.byte W36
	.byte N66, Dn2 @ v060
	.byte W48
	.byte W24
	.byte W02
	.byte N66 @ Dn2, v060
	.byte W68
	.byte W02
	.byte W18
	.byte 0xB6

track_17_2:
	.byte KEYSH, 0
	.byte PAN, c_v-4
	.byte PRIO, 108
	.byte W12
	.byte VOICE, 9
	.byte W48
	.byte VOL, 1
	.byte N78, Gs2, v100
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W01
	.byte 117 @ VOL
	.byte W24
	.byte W36
	.byte W02
	.byte 113 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W07
	.byte VOICE, 5
	.byte VOL, 94
	.byte N60, Dn1, v127
	.byte W30
	.byte W01
	.byte VOL, 91
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W02
	.byte 94 @ VOL
	.byte N66 @ Dn1, v127
	.byte W36
	.byte W01
	.byte VOL, 90
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W08
	.byte W18
	.byte 0xB6

track_17_3:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 113
	.byte PAN, c_v
	.byte PRIO, 30
	.byte N78, Gs2, v127
	.byte W66
	.byte W01
	.byte VOL, 102
	.byte W01
	.byte 94 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W19
	.byte W96
	.byte W96
	.byte W18
	.byte 0xB6

.align 2

track_17:
	.byte 4
	.byte 17
	.byte 130
	.byte 128
	.word 0x80a6094
	.word track_17_0
	.word track_17_1
	.word track_17_2
	.word track_17_3

.align 2
