.align 2

.global track_121

track_121_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 80
	.byte PAN, c_v
	.byte N04, Cn3, v127
	.byte W04
	.byte Cn3, v080 @ N04
	.byte W04
	.byte VOICE, 43
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N20, En1, v040
	.byte W06
	.byte BEND, c_v-2
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-7 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 69
	.byte BEND, c_v-22
	.byte W02
	.byte VOL, 50
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 25
	.byte W24
	.byte W01
	.byte FINE

.align 2

track_121:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_121_0

.align 2
