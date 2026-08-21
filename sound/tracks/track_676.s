.align 2

.global track_676

track_676_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 90
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v127 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W36
	.byte FINE

track_676_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 90
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

track_676_2:
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
	.byte Ds2, v127 @ N05
	.byte W54
	.byte FINE

track_676_3:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 90
	.byte PAN, c_v
	.byte W02
	.byte N04, Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 6
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 7
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 5
	.byte VOL, 30
	.byte W02
	.byte N04 @ Cn3, v127
	.byte W05
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 6
	.byte W01
	.byte N04, Cn3, v080
	.byte W04
	.byte N04 @ Cn3, v080
	.byte W04
	.byte VOICE, 7
	.byte N04, Cn3, v040
	.byte W52
	.byte FINE

track_676_4:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte MOD, 0
	.byte VOL, 60
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v-1
	.byte N72, Gn2, v127
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 85
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 93
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 101
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 106
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 110
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 113
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 117
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 119
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 121
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 123
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 124
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 126
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 127
	.byte BEND, c_v+55
	.byte W01
	.byte c_v+54 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte BENDR, 20
	.byte BEND, c_v+25
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+28 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+55 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte MOD, 40
	.byte LFOS, 60
	.byte W01
	.byte BEND, c_v+62
	.byte W03
	.byte c_v+61 @ BEND
	.byte W03
	.byte c_v+60 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W04
	.byte c_v+58 @ BEND
	.byte W01
	.byte VOL, 127
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 125
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 123
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 121
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 118
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 115
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 113
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 110
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 107
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 103
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 96
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 92
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 87
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 82
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 0
	.byte W24
	.byte W01
	.byte FINE

track_676_5:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte PAN, c_v
	.byte BENDR, 10
	.byte PRIO, 1
	.byte BEND, c_v-1
	.byte VOL, 65
	.byte N84, Dn1, v120
	.byte W01
	.byte BEND, c_v+3
	.byte VOL, 69
	.byte W01
	.byte BEND, c_v+7
	.byte VOL, 74
	.byte W01
	.byte BEND, c_v+10
	.byte VOL, 78
	.byte W01
	.byte BEND, c_v+13
	.byte VOL, 81
	.byte W01
	.byte BEND, c_v+15
	.byte VOL, 85
	.byte W01
	.byte BEND, c_v+17
	.byte VOL, 89
	.byte W01
	.byte BEND, c_v+19
	.byte VOL, 91
	.byte W01
	.byte BEND, c_v+20
	.byte VOL, 94
	.byte W01
	.byte BEND, c_v+21
	.byte VOL, 97
	.byte W01
	.byte BEND, c_v+22
	.byte VOL, 99
	.byte W01
	.byte BEND, c_v+23
	.byte VOL, 101
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 104 @ VOL
	.byte W01
	.byte BEND, c_v+22
	.byte VOL, 105
	.byte W01
	.byte 107 @ VOL
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 109
	.byte W01
	.byte BEND, c_v+20
	.byte W01
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte VOL, 107
	.byte BEND, c_v+12
	.byte W01
	.byte VOL, 105
	.byte BEND, c_v+10
	.byte W01
	.byte VOL, 103
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 102
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 97
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 91
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 87
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 85
	.byte BEND, c_v+21
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+51
	.byte W01
	.byte c_v+63 @ BEND
	.byte VOL, 88
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 99 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 111 @ VOL
	.byte W01
	.byte 114 @ VOL
	.byte W01
	.byte 117 @ VOL
	.byte W01
	.byte 119 @ VOL
	.byte W01
	.byte BEND, c_v+62
	.byte VOL, 121
	.byte W01
	.byte 123 @ VOL
	.byte W01
	.byte 125 @ VOL
	.byte W01
	.byte BEND, c_v+61
	.byte VOL, 126
	.byte W01
	.byte 127 @ VOL
	.byte W03
	.byte 126 @ VOL
	.byte W01
	.byte 125 @ VOL
	.byte W01
	.byte 122 @ VOL
	.byte W01
	.byte BEND, c_v+60
	.byte VOL, 119
	.byte W01
	.byte BEND, c_v+59
	.byte VOL, 115
	.byte W01
	.byte 112 @ VOL
	.byte W01
	.byte BEND, c_v+58
	.byte VOL, 107
	.byte W01
	.byte BEND, c_v+57
	.byte VOL, 85
	.byte W01
	.byte BEND, c_v+56
	.byte VOL, 69
	.byte W01
	.byte BEND, c_v+55
	.byte VOL, 53
	.byte W01
	.byte BEND, c_v+53
	.byte VOL, 41
	.byte W01
	.byte BEND, c_v+51
	.byte VOL, 29
	.byte W01
	.byte BEND, c_v+49
	.byte VOL, 23
	.byte W01
	.byte BEND, c_v+48
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+46
	.byte VOL, 13
	.byte W01
	.byte BEND, c_v+44
	.byte VOL, 9
	.byte W01
	.byte BEND, c_v+42
	.byte VOL, 5
	.byte W01
	.byte BEND, c_v+40
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v+37
	.byte VOL, 0
	.byte W01
	.byte BEND, c_v+35
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W13
	.byte FINE

.align 2

track_676:
	.byte 6
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a808c
	.word track_676_0
	.word track_676_1
	.word track_676_2
	.word track_676_3
	.word track_676_4
	.word track_676_5

.align 2
