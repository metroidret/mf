.align 2

.global track_158

track_158_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v+17
	.byte W40
	.byte N36, Fn2, v060
	.byte W03
	.byte BEND, c_v+23
	.byte W03
	.byte c_v+27 @ BEND
	.byte W03
	.byte c_v+29 @ BEND
	.byte W06
	.byte c_v+26 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W03
	.byte c_v-15 @ BEND
	.byte W03
	.byte VOL, 119
	.byte BEND, c_v-25
	.byte W02
	.byte VOL, 61
	.byte W01
	.byte BEND, c_v-34
	.byte W01
	.byte c_v-34 @ BEND
	.byte VOL, 32
	.byte W02
	.byte 14 @ VOL
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v+17
	.byte N44, En3, v100
	.byte W03
	.byte BEND, c_v+23
	.byte W03
	.byte c_v+27 @ BEND
	.byte W03
	.byte c_v+29 @ BEND
	.byte W05
	.byte W01
	.byte c_v+26 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W01
	.byte MOD, 25
	.byte LFOS, 60
	.byte W02
	.byte BEND, c_v+11
	.byte W02
	.byte c_v-1 @ BEND
	.byte W03
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-25 @ BEND
	.byte W03
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W03
	.byte c_v-21 @ BEND
	.byte VOL, 120
	.byte W02
	.byte 53 @ VOL
	.byte W01
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 29
	.byte W02
	.byte BEND, c_v-7
	.byte VOL, 14
	.byte W02
	.byte 6 @ VOL
	.byte W01
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

track_158_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 75
	.byte PAN, c_v
	.byte N07, Gn1, v020
	.byte W08
	.byte An1, v040 @ N07
	.byte W08
	.byte Bn1, v060 @ N07
	.byte W08
	.byte Cn2, v080 @ N07
	.byte W08
	.byte Dn2, v100 @ N07
	.byte W08
	.byte VOL, 94
	.byte N07, Gn1, v020
	.byte W08
	.byte An1, v040 @ N07
	.byte W08
	.byte Bn1, v060 @ N07
	.byte W08
	.byte Cn2, v080 @ N07
	.byte W08
	.byte Dn2, v100 @ N07
	.byte W10
	.byte VOL, 113
	.byte N07, Gn1, v020
	.byte W08
	.byte An1, v040 @ N07
	.byte W06
	.byte W02
	.byte Bn1, v060 @ N07
	.byte W08
	.byte Cn2, v080 @ N07
	.byte W08
	.byte Dn2, v100 @ N07
	.byte W15
	.byte FINE

track_158_2:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte MOD, 8
	.byte VOL, 37
	.byte PAN, c_v
	.byte LFOS, 60
	.byte N40, Cn2, v072
	.byte W02
	.byte VOL, 42
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 94 @ VOL
	.byte W14
	.byte 93 @ VOL
	.byte W15
	.byte 37 @ VOL
	.byte W01
	.byte N40, Cn2, v092
	.byte W02
	.byte VOL, 42
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 94 @ VOL
	.byte W13
	.byte 93 @ VOL
	.byte W17
	.byte 37 @ VOL
	.byte N36, Cn2, v120
	.byte W02
	.byte VOL, 42
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 94 @ VOL
	.byte W06
	.byte W07
	.byte 93 @ VOL
	.byte W24
	.byte W02
	.byte FINE

.align 2

track_158:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a8008
	.word track_158_0
	.word track_158_1
	.word track_158_2

.align 2
