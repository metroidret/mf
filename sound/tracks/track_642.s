.align 2

.global track_642

track_642_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte MOD, 127
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 80
	.byte PRIO, 1
	.byte BEND, c_v+32
	.byte VOL, 56
	.byte N16, Cn3, v127
	.byte W02
	.byte VOL, 52
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 50
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 52
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 56
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v-47
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v-59
	.byte W01
	.byte c_v-63 @ BEND
	.byte W01
	.byte FINE

track_642_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte MOD, 70
	.byte VOL, 57
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 120
	.byte BEND, c_v+32
	.byte N16, Cn3, v127
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 63
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 61
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 56
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v-47
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v-59
	.byte W01
	.byte c_v-63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_642:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_642_0
	.word track_642_1

.align 2
