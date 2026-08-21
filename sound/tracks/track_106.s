.align 2

.global track_106

track_106_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 16
	.byte BEND, c_v-32
	.byte N60, An2, v127
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-27
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 20
	.byte BEND, c_v-11
	.byte W03
	.byte VOL, 24
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 27
	.byte BEND, c_v-1
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v+4
	.byte W03
	.byte VOL, 36
	.byte BEND, c_v+10
	.byte W03
	.byte VOL, 41
	.byte BEND, c_v+15
	.byte W03
	.byte VOL, 47
	.byte BEND, c_v+20
	.byte W03
	.byte VOL, 53
	.byte BEND, c_v+26
	.byte W03
	.byte VOL, 61
	.byte BEND, c_v+31
	.byte W03
	.byte VOL, 71
	.byte BEND, c_v+36
	.byte W02
	.byte VOL, 90
	.byte W01
	.byte BEND, c_v+41
	.byte W03
	.byte c_v+47 @ BEND
	.byte W03
	.byte c_v+52 @ BEND
	.byte W03
	.byte c_v+57 @ BEND
	.byte W03
	.byte c_v+63 @ BEND
	.byte W06
	.byte c_v-30 @ BEND
	.byte N16, An2, v112
	.byte W02
	.byte BEND, c_v-4
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W09
	.byte c_v-30 @ BEND
	.byte N16 @ An2, v112
	.byte W02
	.byte BEND, c_v-4
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W09
	.byte c_v-30 @ BEND
	.byte N16 @ An2, v112
	.byte W02
	.byte BEND, c_v-4
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W09
	.byte FINE

track_106_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 7
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N60, Cn3, v072
	.byte W02
	.byte VOL, 9
	.byte BEND, c_v+1
	.byte W02
	.byte VOL, 12
	.byte W02
	.byte 16 @ VOL
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 19
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 38
	.byte W02
	.byte 43 @ VOL
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 48
	.byte W02
	.byte 55 @ VOL
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 68
	.byte W02
	.byte 74 @ VOL
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 82
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 84
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 85
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v+29
	.byte W02
	.byte VOL, 88
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 90
	.byte BEND, c_v+37
	.byte W02
	.byte c_v+42 @ BEND
	.byte W02
	.byte c_v+46 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+54 @ BEND
	.byte W02
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+62 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte N16 @ Cn3, v072
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W04
	.byte c_v @ BEND
	.byte N16 @ Cn3, v072
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W04
	.byte c_v @ BEND
	.byte N16 @ Cn3, v072
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W01
	.byte FINE

.align 2

track_106:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a682c
	.word track_106_0
	.word track_106_1

.align 2
