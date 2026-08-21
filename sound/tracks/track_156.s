.align 2

.global track_156

track_156_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 1
	.byte BEND, c_v
	.byte N32, An2, v080
	.byte W02
	.byte BEND, c_v+7
	.byte W04
	.byte c_v+15 @ BEND
	.byte W04
	.byte c_v+19 @ BEND
	.byte VOL, 116
	.byte W02
	.byte 110 @ VOL
	.byte W02
	.byte 103 @ VOL
	.byte W02
	.byte 91 @ VOL
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v+14
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 17
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 10
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 5
	.byte BEND, c_v-8
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 0
	.byte W13
	.byte FINE

track_156_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v100
	.byte W06
	.byte N14, En3, v127
	.byte W14
	.byte Dn3, v052 @ N14
	.byte W14
	.byte N10, Cn3, v020
	.byte W10
	.byte FINE

.align 2

track_156:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a808c
	.word track_156_0
	.word track_156_1

.align 2
