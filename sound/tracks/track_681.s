.align 2

.global track_681

track_681_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3, v100
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W30
	.byte W01
	.byte FINE

track_681_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 120
	.byte PAN, c_v
	.byte W15
	.byte VOICE, 10
	.byte N05, An2, v127
	.byte W10
	.byte N03, Fn2 @ v127
	.byte W40
	.byte FINE

track_681_2:
	.byte KEYSH, 0
	.byte W20
	.byte VOICE, 25
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v
	.byte N30, Gn2, v112
	.byte W01
	.byte BEND, c_v+18
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W01
	.byte c_v+60 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+57 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte VOL, 120
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-4
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-11
	.byte W16
	.byte FINE

track_681_3:
	.byte KEYSH, 0
	.byte W17
	.byte VOICE, 24
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 10
	.byte PRIO, 1
	.byte BEND, c_v
	.byte VOL, 61
	.byte BEND, c_v
	.byte N48, Dn1, v112
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 69
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 85
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 88
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 91
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 93
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 95
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 97
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 98
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 99
	.byte W01
	.byte 101 @ VOL
	.byte BEND, c_v+30
	.byte W02
	.byte VOL, 102
	.byte BEND, c_v+31
	.byte W03
	.byte c_v+30 @ BEND
	.byte W02
	.byte c_v+29 @ BEND
	.byte W02
	.byte VOL, 101
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 97
	.byte W01
	.byte BEND, c_v+23
	.byte VOL, 96
	.byte W01
	.byte BEND, c_v+19
	.byte VOL, 93
	.byte W01
	.byte BEND, c_v+17
	.byte VOL, 89
	.byte W01
	.byte BEND, c_v+13
	.byte VOL, 68
	.byte W01
	.byte BEND, c_v+11
	.byte VOL, 53
	.byte W01
	.byte BEND, c_v+9
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+7
	.byte VOL, 31
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte BEND, c_v+5
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+4
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+3
	.byte VOL, 11
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte BEND, c_v+2
	.byte VOL, 4
	.byte W01
	.byte BEND, c_v+1
	.byte VOL, 3
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v
	.byte W01
	.byte FINE

track_681_4:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 56
	.byte PAN, c_v
	.byte N36, Cn3, v127
	.byte W64
	.byte W01
	.byte FINE

.align 2

track_681:
	.byte 5
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a808c
	.word track_681_0
	.word track_681_1
	.word track_681_2
	.word track_681_3
	.word track_681_4

.align 2
