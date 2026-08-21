.align 2

.global track_479

track_479_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 69
	.byte PAN, c_v
	.byte BENDR, 10
	.byte BEND, c_v
	.byte N36, Cn3, v120
	.byte W02
	.byte VOL, 73
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte W02
	.byte 81 @ VOL
	.byte W02
	.byte 82 @ VOL
	.byte W02
	.byte 83 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W07
	.byte 83 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte BEND, c_v-1
	.byte VOL, 54
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte BEND, c_v-5
	.byte W01
	.byte c_v-7 @ BEND
	.byte VOL, 28
	.byte W01
	.byte BEND, c_v-9
	.byte W01
	.byte c_v-12 @ BEND
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v-16
	.byte W01
	.byte c_v-19 @ BEND
	.byte VOL, 8
	.byte W01
	.byte BEND, c_v-25
	.byte W01
	.byte c_v-29 @ BEND
	.byte VOL, 4
	.byte W01
	.byte BEND, c_v-37
	.byte W01
	.byte c_v-47 @ BEND
	.byte VOL, 0
	.byte W01
	.byte BEND, c_v-58
	.byte FINE

.align 2

track_479:
	.byte 1
	.byte 0
	.byte 227
	.byte 0
	.word 0x80a81e8
	.word track_479_0

.align 2
