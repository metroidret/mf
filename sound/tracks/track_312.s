.align 2

.global track_312

track_312_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 38
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-33
	.byte TIE, Fn2, v092
	.byte W01
	.byte VOL, 43
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte BEND, c_v-31
	.byte VOL, 62
	.byte W01
	.byte 94 @ VOL
	.byte W02
	.byte BEND, c_v-28
	.byte W03
	.byte c_v-25 @ BEND
	.byte W03
	.byte c_v-23 @ BEND
	.byte W03
	.byte c_v-20 @ BEND
	.byte W03
	.byte c_v-17 @ BEND
	.byte W03
	.byte c_v-14 @ BEND
	.byte W03
	.byte VOL, 93
	.byte BEND, c_v-12
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 53
	.byte W01
	.byte BEND, c_v-6
	.byte W02
	.byte VOL, 55
	.byte W01
	.byte BEND, c_v-3
	.byte W03
	.byte c_v @ BEND
	.byte W02
	.byte VOL, 57
	.byte W01
	.byte BEND, c_v+1
	.byte W02
	.byte VOL, 59
	.byte W01
	.byte BEND, c_v+2
	.byte W02
	.byte VOL, 60
	.byte W01
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 62
	.byte W01
	.byte BEND, c_v+4
	.byte W02
	.byte VOL, 65
	.byte W01
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 66
	.byte W01
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 68
	.byte W01
	.byte BEND, c_v+8
	.byte W02
	.byte VOL, 70
	.byte W01
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 73
	.byte W01
	.byte BEND, c_v+10
	.byte W02
	.byte VOL, 76
	.byte W01
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 80
	.byte W01
	.byte BEND, c_v+12
	.byte W02
	.byte VOL, 84
	.byte W01
	.byte BEND, c_v+14
	.byte W02
	.byte VOL, 87
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 91
	.byte W01
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 97
	.byte W01
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 102
	.byte W01
	.byte BEND, c_v+18
	.byte W02
	.byte VOL, 108
	.byte W01
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 115
	.byte W01
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 120
	.byte W02
	.byte BEND, c_v+22
	.byte W02
	.byte c_v+23 @ BEND
	.byte W01
	.byte W07
	.byte EOT @ Fn2, v092
	.byte W02
	.byte FINE

track_312_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 94
	.byte PAN, c_v
	.byte TIE, Dn1, v127
	.byte W72
	.byte VOL, 94
	.byte W03
	.byte 90 @ VOL
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 84 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 68 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W01
	.byte EOT @ Dn1, v127
	.byte W02
	.byte VOL, 57
	.byte FINE

.align 2

track_312:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word 0x80a82f0
	.word track_312_0
	.word track_312_1

.align 2
