.align 2

.global track_335

track_335_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 40
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+17
	.byte N23, Cn3, v127
	.byte W02
	.byte BEND, c_v+20
	.byte W01
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W03
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v-21 @ BEND
	.byte W03
	.byte c_v-27 @ BEND
	.byte W02
	.byte c_v-29 @ BEND
	.byte W01
	.byte c_v-29 @ BEND
	.byte W01
	.byte FINE

.align 2

track_335:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_335_0

.align 2
