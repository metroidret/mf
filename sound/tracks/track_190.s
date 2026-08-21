.align 2

.global track_190

track_190_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+48
	.byte N15, Cn3, v127
	.byte W02
	.byte VOL, 119
	.byte BEND, c_v+47
	.byte W03
	.byte VOL, 112
	.byte BEND, c_v+45
	.byte W02
	.byte VOL, 106
	.byte BEND, c_v+43
	.byte W02
	.byte VOL, 101
	.byte BEND, c_v+41
	.byte W02
	.byte VOL, 95
	.byte BEND, c_v+39
	.byte W03
	.byte VOL, 91
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 85
	.byte BEND, c_v+25
	.byte W03
	.byte VOL, 83
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 81
	.byte BEND, c_v+5
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte VOL, 79
	.byte W09
	.byte 81 @ VOL
	.byte N24 @ Cn3, v127
	.byte W01
	.byte BEND, c_v-35
	.byte W02
	.byte VOL, 83
	.byte BEND, c_v-12
	.byte W02
	.byte VOL, 85
	.byte BEND, c_v+11
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte VOL, 87
	.byte W01
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 91
	.byte W01
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 95
	.byte BEND, c_v+58
	.byte W02
	.byte c_v+61 @ BEND
	.byte VOL, 99
	.byte W02
	.byte 104 @ VOL
	.byte BEND, c_v+63
	.byte W02
	.byte c_v+58 @ BEND
	.byte VOL, 115
	.byte W02
	.byte BEND, c_v+55
	.byte VOL, 127
	.byte W02
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 124
	.byte BEND, c_v+33
	.byte W01
	.byte BENDR, 18
	.byte N10 @ Cn3, v127
	.byte W01
	.byte VOL, 122
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 120
	.byte BEND, c_v+47
	.byte W02
	.byte c_v+55 @ BEND
	.byte W01
	.byte VOL, 117
	.byte W01
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 115
	.byte W01
	.byte 114 @ VOL
	.byte W28
	.byte W01
	.byte W30
	.byte FINE

track_190_1:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 80
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W18
	.byte As2, v080 @ N15
	.byte W21
	.byte N10, Cn2, v127
	.byte W10
	.byte N10 @ Cn2, v127
	.byte W10
	.byte N10 @ Cn2, v127
	.byte W10
	.byte N20, Gn2 @ v127
	.byte W20
	.byte N05, Gs2, v052
	.byte W05
	.byte N02, As2, v020
	.byte W02
	.byte VOICE, 21
	.byte N06, Dn2, v127
	.byte W30
	.byte FINE

.align 2

track_190:
	.byte 2
	.byte 0
	.byte 221
	.byte 0
	.word 0x80a74c8
	.word track_190_0
	.word track_190_1

.align 2
