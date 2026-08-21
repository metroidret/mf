.align 2

.global track_675

track_675_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte MOD, 60
	.byte VOL, 0
	.byte PAN, c_v
	.byte LFOS, 60
	.byte MODT, 1
	.byte PRIO, 1
	.byte TIE, Cn3, v096
	.byte W03
	.byte VOL, 17
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 68 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 85 @ VOL
	.byte W03
	.byte 91 @ VOL
	.byte W03
	.byte 95 @ VOL
	.byte W03
	.byte 101 @ VOL
	.byte W03
	.byte 104 @ VOL
	.byte W03
	.byte 108 @ VOL
	.byte W03
	.byte 112 @ VOL
	.byte W03
	.byte 114 @ VOL
	.byte W03
	.byte 118 @ VOL
	.byte W03
	.byte 120 @ VOL
	.byte W24
	.byte 120 @ VOL
	.byte W03
	.byte 97 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W03
	.byte EOT @ Cn3, v096
	.byte FINE

track_675_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v-1
	.byte W06
	.byte c_v @ BEND
	.byte TIE, Cn1, v092
	.byte W02
	.byte VOL, 68
	.byte W01
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 76
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 82
	.byte W01
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 89
	.byte W01
	.byte BEND, c_v+27
	.byte W02
	.byte VOL, 91
	.byte W01
	.byte BEND, c_v+30
	.byte W02
	.byte VOL, 93
	.byte W01
	.byte BEND, c_v+31
	.byte W12
	.byte c_v+30 @ BEND
	.byte W02
	.byte VOL, 92
	.byte W01
	.byte BEND, c_v+29
	.byte W02
	.byte VOL, 91
	.byte W03
	.byte 89 @ VOL
	.byte W01
	.byte BEND, c_v+27
	.byte W02
	.byte VOL, 87
	.byte W01
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 86
	.byte W01
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 85
	.byte W01
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 83
	.byte W01
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 81
	.byte W01
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 78
	.byte W01
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 53
	.byte W01
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 38
	.byte W01
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 27
	.byte W01
	.byte BEND, c_v+8
	.byte W02
	.byte VOL, 21
	.byte W01
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+4
	.byte W02
	.byte VOL, 10
	.byte W01
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 8
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W01
	.byte BEND, c_v+2
	.byte W02
	.byte VOL, 4
	.byte W04
	.byte BEND, c_v+1
	.byte W02
	.byte VOL, 2
	.byte W06
	.byte 0 @ VOL
	.byte W06
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v
	.byte W03
	.byte EOT @ Cn1, v092
	.byte FINE

.align 2

track_675:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word 0x80a808c
	.word track_675_0
	.word track_675_1

.align 2
