.align 2

.global track_480

track_480_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N64, Cn3, v112
	.byte W48
	.byte VOL, 127
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W32
	.byte W15
	.byte 127 @ VOL
	.byte BEND, c_v-26
	.byte N64, Cn3, v127
	.byte W03
	.byte BEND, c_v-24
	.byte W03
	.byte c_v-21 @ BEND
	.byte W03
	.byte c_v-18 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-9 @ BEND
	.byte W03
	.byte c_v-2 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W03
	.byte c_v+22 @ BEND
	.byte W03
	.byte c_v+21 @ BEND
	.byte W12
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+19 @ BEND
	.byte W06
	.byte c_v+18 @ BEND
	.byte W03
	.byte c_v+16 @ BEND
	.byte W03
	.byte c_v+14 @ BEND
	.byte W03
	.byte c_v+11 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W03
	.byte c_v+3 @ BEND
	.byte W09
	.byte VOL, 127
	.byte BENDR, 10
	.byte BEND, c_v
	.byte N64, Dn3, v020
	.byte W09
	.byte W16
	.byte BEND, c_v-1
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W01
	.byte VOL, 125
	.byte W01
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 93
	.byte W01
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 65
	.byte W02
	.byte 46 @ VOL
	.byte W01
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 9
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte BEND, c_v-13
	.byte W17
	.byte c_v-21 @ BEND
	.byte FINE

track_480_1:
	.byte KEYSH, 0
	.byte W54
	.byte W01
	.byte VOICE, 17
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 10
	.byte N64, Cn3, v080
	.byte W12
	.byte BEND, c_v-1
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W10
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W44
	.byte VOICE, 16
	.byte VOL, 127
	.byte BENDR, 10
	.byte BEND, c_v
	.byte N64, Dn3, v127
	.byte W24
	.byte W01
	.byte BEND, c_v-1
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W01
	.byte VOL, 125
	.byte W01
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 93
	.byte W01
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 65
	.byte W02
	.byte 46 @ VOL
	.byte W01
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 13
	.byte W01
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 9
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte BEND, c_v-13
	.byte W02
	.byte c_v-21 @ BEND
	.byte W48
	.byte FINE

track_480_2:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 85
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W06
	.byte W09
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W24
	.byte W03
	.byte W68
	.byte W03
	.byte FINE

track_480_3:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 85
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte N10, Cn3, v040
	.byte W10
	.byte N14, Dn3 @ v040
	.byte W14
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W06
	.byte W08
	.byte N10, Cn3, v040
	.byte W10
	.byte N14, Dn3 @ v040
	.byte W14
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte N10, Cn3, v040
	.byte W10
	.byte N14, Dn3 @ v040
	.byte W14
	.byte W68
	.byte W03
	.byte FINE

track_480_4:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 105
	.byte PAN, c_v
	.byte W05
	.byte N09, Fn2, v100
	.byte W09
	.byte VOICE, 11
	.byte W01
	.byte N05, Gs2 @ v100
	.byte W10
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
	.byte VOICE, 10
	.byte N09, Fn2 @ v127
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
	.byte VOICE, 10
	.byte N09, Fn2 @ v127
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
	.byte VOICE, 10
	.byte N09, Fn2 @ v127
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
	.byte VOICE, 10
	.byte N09, Fn2 @ v127
	.byte W09
	.byte VOICE, 11
	.byte N05, Gs2, v100
	.byte W05
	.byte N03, Ds2, v127
	.byte W30
	.byte W01
	.byte W68
	.byte W03
	.byte FINE

track_480_5:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 55
	.byte PAN, c_v
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
	.byte VOL, 15
	.byte W02
	.byte N04 @ Cn3, v112
	.byte W05
	.byte N04 @ Cn3, v112
	.byte W04
	.byte VOICE, 6
	.byte W01
	.byte N04, Cn3, v072
	.byte W04
	.byte N04 @ Cn3, v072
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v032
	.byte W16
	.byte VOL, 75
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
	.byte N04, Cn3, v072
	.byte W04
	.byte N04 @ Cn3, v072
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v032
	.byte W24
	.byte VOL, 35
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
	.byte VOL, 55
	.byte W02
	.byte N04 @ Cn3, v112
	.byte W05
	.byte N04 @ Cn3, v112
	.byte W04
	.byte VOICE, 6
	.byte W01
	.byte N04, Cn3, v072
	.byte W04
	.byte N04 @ Cn3, v072
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v040
	.byte W20
	.byte W68
	.byte W03
	.byte FINE

.align 2

track_480:
	.byte 6
	.byte 0
	.byte 254
	.byte 0
	.word 0x80a808c
	.word track_480_0
	.word track_480_1
	.word track_480_2
	.word track_480_3
	.word track_480_4
	.word track_480_5

.align 2
