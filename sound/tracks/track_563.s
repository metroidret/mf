.align 2

.global track_563

track_563_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 75
	.byte PAN, c_v
	.byte N04, Cn3, v112
	.byte W04
	.byte Cn3, v060 @ N04
	.byte W04
	.byte VOICE, 14
	.byte VOL, 120
	.byte PAN, c_v
	.byte VOL, 120
	.byte N64, Cn3, v127
	.byte W03
	.byte VOL, 118
	.byte W03
	.byte 114 @ VOL
	.byte W03
	.byte 112 @ VOL
	.byte W03
	.byte 108 @ VOL
	.byte W03
	.byte 102 @ VOL
	.byte W03
	.byte 99 @ VOL
	.byte W03
	.byte 92 @ VOL
	.byte W03
	.byte 85 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W24
	.byte W01
	.byte FINE

track_563_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N96, Cn2, v127
	.byte W03
	.byte BEND, c_v-3
	.byte W03
	.byte c_v-6 @ BEND
	.byte W03
	.byte c_v-8 @ BEND
	.byte W03
	.byte c_v-11 @ BEND
	.byte W03
	.byte c_v-14 @ BEND
	.byte W03
	.byte c_v-16 @ BEND
	.byte W03
	.byte c_v-19 @ BEND
	.byte W03
	.byte c_v-22 @ BEND
	.byte W03
	.byte c_v-24 @ BEND
	.byte W03
	.byte c_v-27 @ BEND
	.byte W03
	.byte c_v-30 @ BEND
	.byte W03
	.byte c_v-32 @ BEND
	.byte W03
	.byte c_v-35 @ BEND
	.byte W03
	.byte c_v-38 @ BEND
	.byte W03
	.byte c_v-40 @ BEND
	.byte W03
	.byte c_v-43 @ BEND
	.byte W03
	.byte c_v-46 @ BEND
	.byte W03
	.byte c_v-48 @ BEND
	.byte W03
	.byte c_v-51 @ BEND
	.byte W03
	.byte c_v-54 @ BEND
	.byte W03
	.byte c_v-56 @ BEND
	.byte W03
	.byte c_v-59 @ BEND
	.byte W03
	.byte c_v-62 @ BEND
	.byte W02
	.byte c_v-63 @ BEND
	.byte W01
	.byte VOL, 120
	.byte W03
	.byte 103 @ VOL
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_563_2:
	.byte KEYSH, 0
	.byte VOICE, 25
	.byte VOL, 37
	.byte PAN, c_v
	.byte N23, Cn3, v100
	.byte W23
	.byte N24, An2, v060
	.byte W72
	.byte W01
	.byte FINE

.align 2

track_563:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_563_0
	.word track_563_1
	.word track_563_2

.align 2
