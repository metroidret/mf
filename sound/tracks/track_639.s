.align 2

.global track_639

track_639_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 110
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-63
	.byte N24, Cn3, v127
	.byte W02
	.byte BEND, c_v-61
	.byte W02
	.byte c_v-59 @ BEND
	.byte W02
	.byte c_v-54 @ BEND
	.byte W02
	.byte c_v-51 @ BEND
	.byte W02
	.byte c_v-45 @ BEND
	.byte W02
	.byte c_v-40 @ BEND
	.byte W02
	.byte c_v-34 @ BEND
	.byte W02
	.byte c_v-26 @ BEND
	.byte W02
	.byte c_v-17 @ BEND
	.byte W02
	.byte c_v-6 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+26 @ BEND
	.byte W03
	.byte FINE

track_639_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 75
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-63
	.byte N24, Cn3, v127
	.byte W02
	.byte BEND, c_v-60
	.byte W02
	.byte c_v-57 @ BEND
	.byte W02
	.byte c_v-53 @ BEND
	.byte W02
	.byte c_v-49 @ BEND
	.byte W02
	.byte c_v-45 @ BEND
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-32 @ BEND
	.byte W02
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+35 @ BEND
	.byte W03
	.byte FINE

.align 2

track_639:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_639_0
	.word track_639_1

.align 2
