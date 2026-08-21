.align 2

.global track_415

track_415_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 65
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 3
	.byte BEND, c_v
	.byte N16, Cn2, v080
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v-6 @ BEND
	.byte W01
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-11 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte FINE

.align 2

track_415:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a6d54
	.word track_415_0

.align 2
