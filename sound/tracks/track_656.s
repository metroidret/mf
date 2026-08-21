.align 2

.global track_656

track_656_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 0
	.byte PAN, c_v
	.byte BENDR, 16
	.byte W23
	.byte VOL, 35
	.byte BEND, c_v+4
	.byte VOL, 37
	.byte N36, An2, v112
	.byte W01
	.byte BEND, c_v+10
	.byte W02
	.byte VOL, 41
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v+20
	.byte W02
	.byte VOL, 49
	.byte W01
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 53
	.byte W01
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 59
	.byte W01
	.byte BEND, c_v+36
	.byte W02
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v+41
	.byte W02
	.byte VOL, 72
	.byte W01
	.byte BEND, c_v+47
	.byte W02
	.byte VOL, 82
	.byte W01
	.byte BEND, c_v+52
	.byte W02
	.byte VOL, 91
	.byte W01
	.byte BEND, c_v+57
	.byte W02
	.byte VOL, 103
	.byte W01
	.byte BEND, c_v+63
	.byte W02
	.byte VOL, 119
	.byte W05
	.byte FINE

track_656_1:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W24
	.byte VOL, 18
	.byte BEND, c_v+11
	.byte VOL, 17
	.byte N36, Cn3, v060
	.byte W02
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte c_v+17 @ BEND
	.byte VOL, 31
	.byte W02
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 38
	.byte W01
	.byte BEND, c_v+23
	.byte W02
	.byte c_v+29 @ BEND
	.byte VOL, 48
	.byte W02
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 60
	.byte W01
	.byte BEND, c_v+37
	.byte W02
	.byte c_v+42 @ BEND
	.byte VOL, 75
	.byte W02
	.byte BEND, c_v+46
	.byte W02
	.byte c_v+49 @ BEND
	.byte W02
	.byte VOL, 98
	.byte BEND, c_v+51
	.byte W02
	.byte c_v+54 @ BEND
	.byte W01
	.byte VOL, 102
	.byte W01
	.byte BEND, c_v+57
	.byte W02
	.byte VOL, 107
	.byte BEND, c_v+59
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+62 @ BEND
	.byte W03
	.byte FINE

track_656_2:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 85
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v+59
	.byte N60, Gn2, v127
	.byte W03
	.byte VOL, 95
	.byte BEND, c_v+49
	.byte W03
	.byte VOL, 102
	.byte BEND, c_v+43
	.byte W03
	.byte VOL, 108
	.byte W03
	.byte 112 @ VOL
	.byte BEND, c_v+44
	.byte W03
	.byte VOL, 116
	.byte BEND, c_v+47
	.byte W03
	.byte VOL, 119
	.byte BEND, c_v+50
	.byte W03
	.byte c_v+51 @ BEND
	.byte VOL, 120
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte BEND, c_v+49
	.byte VOL, 116
	.byte W03
	.byte BEND, c_v+47
	.byte VOL, 112
	.byte W03
	.byte BEND, c_v+45
	.byte VOL, 106
	.byte W03
	.byte BEND, c_v+41
	.byte VOL, 99
	.byte W03
	.byte BEND, c_v+37
	.byte VOL, 91
	.byte W02
	.byte 81 @ VOL
	.byte W01
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 42
	.byte W01
	.byte BEND, c_v+28
	.byte W02
	.byte VOL, 23
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W05
	.byte FINE

track_656_3:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 85
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-1
	.byte W01
	.byte N60, An2, v127
	.byte W03
	.byte VOL, 95
	.byte BEND, c_v+14
	.byte W03
	.byte VOL, 102
	.byte BEND, c_v+25
	.byte W03
	.byte VOL, 108
	.byte BEND, c_v+35
	.byte W03
	.byte VOL, 112
	.byte BEND, c_v+42
	.byte W03
	.byte VOL, 116
	.byte BEND, c_v+47
	.byte W03
	.byte VOL, 119
	.byte BEND, c_v+50
	.byte W03
	.byte c_v+51 @ BEND
	.byte VOL, 120
	.byte W03
	.byte 119 @ VOL
	.byte W03
	.byte BEND, c_v+49
	.byte VOL, 116
	.byte W03
	.byte BEND, c_v+47
	.byte VOL, 112
	.byte W03
	.byte BEND, c_v+45
	.byte VOL, 106
	.byte W03
	.byte BEND, c_v+41
	.byte VOL, 99
	.byte BEND, c_v+41
	.byte W03
	.byte VOL, 91
	.byte W02
	.byte 81 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W04
	.byte FINE

.align 2

track_656:
	.byte 4
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a7e10
	.word track_656_0
	.word track_656_1
	.word track_656_2
	.word track_656_3

.align 2
