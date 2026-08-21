.align 2

.global track_565

track_565_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 20
	.byte PAN, c_v
	.byte W16
	.byte N04, Cn4, v060
	.byte W08
	.byte Bn3, v080 @ N04
	.byte W08
	.byte An3, v100 @ N04
	.byte W08
	.byte Gn3, v112 @ N04
	.byte W08
	.byte Fn3, v127 @ N04
	.byte W09
	.byte VOICE, 1
	.byte VOL, 80
	.byte N15, Cn3 @ v127
	.byte W16
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W08
	.byte W07
	.byte FINE

track_565_1:
	.byte KEYSH, 0
	.byte VOICE, 28
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W12
	.byte VOL, 80
	.byte BEND, c_v+54
	.byte N60, Cn2, v112
	.byte W03
	.byte VOL, 101
	.byte W03
	.byte 113 @ VOL
	.byte W03
	.byte 121 @ VOL
	.byte W03
	.byte 127 @ VOL
	.byte W03
	.byte BEND, c_v+51
	.byte W03
	.byte c_v+40 @ BEND
	.byte W02
	.byte VOL, 127
	.byte BENDR, 24
	.byte W01
	.byte BEND, c_v+29
	.byte W02
	.byte VOL, 124
	.byte W01
	.byte BEND, c_v+18
	.byte W02
	.byte VOL, 120
	.byte W01
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 116
	.byte W01
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 111
	.byte W01
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 103
	.byte W01
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 95
	.byte W01
	.byte BEND, c_v-37
	.byte W02
	.byte VOL, 83
	.byte W01
	.byte BEND, c_v-48
	.byte W02
	.byte VOL, 68
	.byte W01
	.byte BEND, c_v-59
	.byte W02
	.byte VOL, 39
	.byte W01
	.byte BEND, c_v-63
	.byte W02
	.byte VOL, 24
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W28
	.byte W07
	.byte FINE

track_565_2:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N32, Cn5, v072
	.byte W03
	.byte VOL, 3
	.byte BEND, c_v+11
	.byte W03
	.byte VOL, 9
	.byte BEND, c_v+17
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v+18
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v+17
	.byte W03
	.byte VOL, 47
	.byte BEND, c_v+10
	.byte W03
	.byte VOL, 55
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 60
	.byte BEND, c_v-5
	.byte W03
	.byte VOL, 59
	.byte BEND, c_v-7
	.byte W03
	.byte VOL, 53
	.byte W03
	.byte 45 @ VOL
	.byte BEND, c_v-4
	.byte W07
	.byte VOL, 40
	.byte BEND, c_v
	.byte N48, Cn5, v127
	.byte W02
	.byte VOL, 69
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 91
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 107
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 119
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 125
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 127
	.byte BEND, c_v+39
	.byte W02
	.byte c_v+37 @ BEND
	.byte W01
	.byte VOL, 93
	.byte W01
	.byte BEND, c_v+32
	.byte W02
	.byte VOL, 67
	.byte BEND, c_v+49
	.byte W02
	.byte c_v+54 @ BEND
	.byte W01
	.byte VOL, 46
	.byte W01
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 31
	.byte BEND, c_v+48
	.byte W02
	.byte c_v+61 @ BEND
	.byte W01
	.byte VOL, 21
	.byte W02
	.byte BEND, c_v+60
	.byte W01
	.byte VOL, 15
	.byte W02
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 12
	.byte W02
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 9
	.byte W02
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 6
	.byte W02
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 4
	.byte W02
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 2
	.byte W02
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 1
	.byte W02
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 0
	.byte W08
	.byte W07
	.byte FINE

.align 2

track_565:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_565_0
	.word track_565_1
	.word track_565_2

.align 2
