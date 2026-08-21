.align 2

.global track_637

track_637_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N04, An2, v100
	.byte W04
	.byte VOICE, 1
	.byte MOD, 50
	.byte VOL, 120
	.byte BENDR, 12
	.byte LFOS, 127
	.byte BEND, c_v
	.byte N16, Cn3, v127
	.byte W02
	.byte VOL, 105
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 94
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 84
	.byte BEND, c_v-23
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 72
	.byte BEND, c_v-33
	.byte W02
	.byte VOL, 68
	.byte BEND, c_v-37
	.byte W02
	.byte VOL, 64
	.byte BEND, c_v-40
	.byte W02
	.byte FINE

track_637_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 94
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+15
	.byte N20, Cn3, v127
	.byte W02
	.byte BEND, c_v+13
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W01
	.byte VOL, 94
	.byte W01
	.byte BEND, c_v-10
	.byte W01
	.byte VOL, 74
	.byte W01
	.byte BEND, c_v-31
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 51
	.byte W01
	.byte BEND, c_v-53
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v-61
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v-63
	.byte W01
	.byte FINE

.align 2

track_637:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_637_0
	.word track_637_1

.align 2
