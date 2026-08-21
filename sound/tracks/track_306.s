.align 2

.global track_306

track_306_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3, v100
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W60
	.byte W02
	.byte W84
	.byte FINE

track_306_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte W04
	.byte N09, Fn3, v100
	.byte W11
	.byte VOICE, 10
	.byte N05, An2, v127
	.byte W10
	.byte N03, Fn2 @ v127
	.byte W68
	.byte W03
	.byte W84
	.byte FINE

track_306_2:
	.byte KEYSH, 0
	.byte W15
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3, v100
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W44
	.byte W03
	.byte W84
	.byte FINE

track_306_3:
	.byte KEYSH, 0
	.byte W15
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte W04
	.byte N09, Fn3, v100
	.byte W11
	.byte VOICE, 10
	.byte N05, An2, v127
	.byte W10
	.byte N03, Fn2 @ v127
	.byte W56
	.byte W84
	.byte FINE

track_306_4:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 61
	.byte PAN, c_v
	.byte BENDR, 10
	.byte PRIO, 1
	.byte BEND, c_v+23
	.byte TIE, Cn3, v080
	.byte W02
	.byte VOL, 81
	.byte W02
	.byte 92 @ VOL
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 100
	.byte BEND, c_v+19
	.byte W02
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W02
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+62 @ BEND
	.byte W01
	.byte MOD, 20
	.byte LFOS, 60
	.byte W01
	.byte BEND, c_v+61
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+56 @ BEND
	.byte W02
	.byte c_v+51 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+26 @ BEND
	.byte W02
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+59 @ BEND
	.byte W48
	.byte W01
	.byte W48
	.byte VOL, 100
	.byte W02
	.byte 85 @ VOL
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte EOT @ Cn3, v080
	.byte FINE

.align 2

track_306:
	.byte 5
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a808c
	.word track_306_0
	.word track_306_1
	.word track_306_2
	.word track_306_3
	.word track_306_4

.align 2
