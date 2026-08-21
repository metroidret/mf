.align 2

.global track_631

track_631_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N04, Cn3, v127
	.byte W04
	.byte VOICE, 1
	.byte N15, Gn3, v112
	.byte W08
	.byte VOL, 120
	.byte W02
	.byte 116 @ VOL
	.byte W02
	.byte 112 @ VOL
	.byte W02
	.byte 106 @ VOL
	.byte W01
	.byte N13, Gn3, v044
	.byte W06
	.byte VOL, 120
	.byte W02
	.byte 116 @ VOL
	.byte W02
	.byte 112 @ VOL
	.byte W02
	.byte 106 @ VOL
	.byte W01
	.byte N24, Gn3, v016
	.byte W06
	.byte VOL, 120
	.byte W02
	.byte 116 @ VOL
	.byte W02
	.byte 112 @ VOL
	.byte W02
	.byte 106 @ VOL
	.byte W02
	.byte 101 @ VOL
	.byte W02
	.byte 93 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W05
	.byte FINE

track_631_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W07
	.byte BEND, c_v
	.byte N10, Cn3, v092
	.byte W02
	.byte BEND, c_v+3
	.byte W02
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W48
	.byte FINE

track_631_2:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W04
	.byte N56, Cn5, v127
	.byte W02
	.byte VOL, 65
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 85
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 101
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 112
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 118
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 120
	.byte BEND, c_v+39
	.byte W03
	.byte VOL, 89
	.byte BEND, c_v+37
	.byte W01
	.byte c_v+30 @ BEND
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v+54
	.byte W03
	.byte VOL, 38
	.byte BEND, c_v+49
	.byte W03
	.byte VOL, 30
	.byte BEND, c_v+55
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v+60
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v+63
	.byte W03
	.byte VOL, 16
	.byte W03
	.byte 12 @ VOL
	.byte BEND, c_v+62
	.byte W03
	.byte VOL, 9
	.byte BEND, c_v+61
	.byte W03
	.byte VOL, 6
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W02
	.byte FINE

.align 2

track_631:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7aa4
	.word track_631_0
	.word track_631_1
	.word track_631_2

.align 2
