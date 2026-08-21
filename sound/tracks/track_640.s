.align 2

.global track_640

track_640_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 80
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 120
	.byte BEND, c_v-49
	.byte N28, En2, v127
	.byte W01
	.byte VOL, 58
	.byte W01
	.byte 61 @ VOL
	.byte BEND, c_v-20
	.byte W01
	.byte VOL, 65
	.byte W01
	.byte 68 @ VOL
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 74
	.byte W01
	.byte 81 @ VOL
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 90
	.byte BEND, c_v+15
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+10 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+35 @ BEND
	.byte W02
	.byte c_v+38 @ BEND
	.byte W02
	.byte c_v+36 @ BEND
	.byte W02
	.byte c_v+30 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W04
	.byte FINE

track_640_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W05
	.byte N11, An2, v100
	.byte W11
	.byte VOICE, 5
	.byte N11, Gn2, v120
	.byte W13
	.byte FINE

.align 2

track_640:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a7d14
	.word track_640_0
	.word track_640_1

.align 2
