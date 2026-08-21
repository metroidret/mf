.align 2

.global track_536

track_536_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte PRIO, 50
	.byte VOL, 120
	.byte PAN, c_v+6
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v080 @ N15
	.byte W15
	.byte Cn3, v120 @ N15
	.byte W06
	.byte PRIO, 0
	.byte W09
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W36
	.byte W24
	.byte FINE

track_536_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v+6
	.byte PRIO, 50
	.byte W04
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v080
	.byte W06
	.byte PRIO, 0
	.byte W08
	.byte N10, Cn3, v060
	.byte W10
	.byte N14, Dn3, v040
	.byte W14
	.byte N10, Cn3, v020
	.byte W28
	.byte W24
	.byte FINE

track_536_2:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte PRIO, 50
	.byte VOL, 120
	.byte PAN, c_v
	.byte W02
	.byte VOICE, 10
	.byte N09, Fn2, v127
	.byte W09
	.byte VOICE, 11
	.byte N05, Gs2, v100
	.byte W05
	.byte N03, Ds2, v127
	.byte W03
	.byte VOICE, 10
	.byte N09, Fn2 @ v127
	.byte W09
	.byte VOICE, 11
	.byte N05, Gs2, v100
	.byte W05
	.byte N03, Ds2, v127
	.byte W03
	.byte PRIO, 0
	.byte VOICE, 10
	.byte N09, Fn2 @ v127
	.byte W09
	.byte VOICE, 11
	.byte N05, Fn2, v100
	.byte W05
	.byte N10, Ds2, v127
	.byte W44
	.byte W02
	.byte W24
	.byte FINE

track_536_3:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte PRIO, 50
	.byte VOL, 80
	.byte PAN, c_v+6
	.byte W02
	.byte N04, Cn3, v112
	.byte W05
	.byte N04 @ Cn3, v112
	.byte W05
	.byte N04 @ Cn3, v112
	.byte W04
	.byte VOICE, 6
	.byte N04 @ Cn3, v112
	.byte W04
	.byte VOICE, 7
	.byte N04 @ Cn3, v112
	.byte W04
	.byte VOICE, 5
	.byte VOL, 35
	.byte W02
	.byte N04 @ Cn3, v112
	.byte W05
	.byte N04 @ Cn3, v112
	.byte W04
	.byte VOICE, 6
	.byte W01
	.byte PRIO, 0
	.byte N04, Cn3, v072
	.byte W04
	.byte N04 @ Cn3, v072
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v032
	.byte W04
	.byte VOICE, 5
	.byte N04, Cn3, v040
	.byte W04
	.byte N04 @ Cn3, v040
	.byte W04
	.byte N04 @ Cn3, v040
	.byte W04
	.byte VOICE, 6
	.byte N04 @ Cn3, v040
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v032
	.byte W32
	.byte W24
	.byte FINE

.align 2

track_536:
	.byte 4
	.byte 0
	.byte 201
	.byte 0
	.word 0x80a808c
	.word track_536_0
	.word track_536_1
	.word track_536_2
	.word track_536_3

.align 2
