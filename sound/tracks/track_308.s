.align 2

.global track_308

track_308_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 110
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W48
	.byte W03
	.byte FINE

track_308_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 110
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
	.byte W44
	.byte W02
	.byte FINE

track_308_2:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 110
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
	.byte N20, Fn2 @ v127
	.byte W48
	.byte W03
	.byte FINE

track_308_3:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 90
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
	.byte VOL, 20
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
	.byte W52
	.byte FINE

track_308_4:
	.byte KEYSH, 0
	.byte W14
	.byte BEND, c_v+20
	.byte W01
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte N48, Cn3, v127
	.byte W01
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 103
	.byte W01
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 117
	.byte W01
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte BEND, c_v+32
	.byte W02
	.byte c_v+28 @ BEND
	.byte W02
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+2 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W04
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+53 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W02
	.byte c_v+35 @ BEND
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+63
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 0
	.byte W32
	.byte W02
	.byte FINE

track_308_5:
	.byte KEYSH, 0
	.byte W28
	.byte W01
	.byte BEND, c_v+20
	.byte W01
	.byte VOICE, 19
	.byte VOL, 78
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte N48, Cn3, v040
	.byte W01
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 103
	.byte W01
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 117
	.byte W01
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte BEND, c_v+32
	.byte W02
	.byte c_v+28 @ BEND
	.byte W02
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+2 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W04
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+53 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W02
	.byte c_v+35 @ BEND
	.byte W01
	.byte VOL, 127
	.byte W01
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+63
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 0
	.byte W19
	.byte FINE

.align 2

track_308:
	.byte 6
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a808c
	.word track_308_0
	.word track_308_1
	.word track_308_2
	.word track_308_3
	.word track_308_4
	.word track_308_5

.align 2
