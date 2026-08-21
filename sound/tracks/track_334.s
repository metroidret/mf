.align 2

.global track_334

track_334_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 40
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+15
	.byte N30, Cn3, v127
	.byte W02
	.byte BEND, c_v+14
	.byte W01
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+2 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W03
	.byte c_v-11 @ BEND
	.byte W02
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W02
	.byte c_v-23 @ BEND
	.byte W09
	.byte FINE

.align 2

track_334:
	.byte 1
	.byte 0
	.byte 172
	.byte 0
	.word 0x80a6d54
	.word track_334_0

.align 2
