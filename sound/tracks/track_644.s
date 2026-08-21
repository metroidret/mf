.align 2

.global track_644

track_644_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 120
	.byte PAN, c_v
	.byte N19, En3, v127
	.byte W19
	.byte En3, v036 @ N19
	.byte W19
	.byte En3, v012 @ N19
	.byte W56
	.byte W02
	.byte W15
	.byte FINE

track_644_1:
	.byte KEYSH, 0
	.byte VOICE, 13
	.byte VOL, 120
	.byte PAN, c_v
	.byte W22
	.byte VOICE, 13
	.byte VOL, 56
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v100 @ N14
	.byte W14
	.byte VOICE, 14
	.byte N10, Cn3, v060
	.byte W40
	.byte W15
	.byte FINE

track_644_2:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 120
	.byte PAN, c_v
	.byte N04, Fn2, v127
	.byte W10
	.byte VOICE, 16
	.byte N05, Gs2, v080
	.byte W10
	.byte VOICE, 15
	.byte VOL, 120
	.byte PAN, c_v
	.byte N03, Cs2, v127
	.byte W05
	.byte N09, Bn2, v100
	.byte W09
	.byte VOICE, 16
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
	.byte N03, Cs2, v127
	.byte W48
	.byte W03
	.byte W15
	.byte FINE

track_644_3:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte VOL, 75
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N36, Cn3, v060
	.byte W02
	.byte VOL, 83
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 93
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 108
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 120
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 120
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 84
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 67
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 72
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 80
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 91
	.byte BEND, c_v+51
	.byte W02
	.byte VOL, 108
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 120
	.byte W01
	.byte 120 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W60
	.byte W01
	.byte W15
	.byte FINE

track_644_4:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 120
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 18
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 19
	.byte N04 @ Cn3, v127
	.byte W78
	.byte W15
	.byte FINE

.align 2

track_644:
	.byte 5
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7d14
	.word track_644_0
	.word track_644_1
	.word track_644_2
	.word track_644_3
	.word track_644_4

.align 2
