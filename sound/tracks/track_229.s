.align 2

.global track_229

track_229_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-47
	.byte N64, Cn3, v100
	.byte W02
	.byte BEND, c_v-43
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-34 @ BEND
	.byte W03
	.byte c_v-30 @ BEND
	.byte W02
	.byte c_v-25 @ BEND
	.byte W02
	.byte c_v-21 @ BEND
	.byte W03
	.byte c_v-16 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v-3 @ BEND
	.byte W03
	.byte c_v+1 @ BEND
	.byte W02
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+10 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+28 @ BEND
	.byte W03
	.byte c_v+32 @ BEND
	.byte W02
	.byte c_v+37 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W03
	.byte c_v+46 @ BEND
	.byte W16
	.byte FINE

track_229_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 27
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N64, Cn3, v100
	.byte W02
	.byte BEND, c_v-44
	.byte W03
	.byte c_v-40 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-33 @ BEND
	.byte W02
	.byte c_v-30 @ BEND
	.byte W03
	.byte c_v-26 @ BEND
	.byte W02
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v-19 @ BEND
	.byte W03
	.byte c_v-16 @ BEND
	.byte W02
	.byte c_v-13 @ BEND
	.byte W02
	.byte c_v-9 @ BEND
	.byte W02
	.byte c_v-6 @ BEND
	.byte W03
	.byte c_v-2 @ BEND
	.byte W02
	.byte c_v+1 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+18 @ BEND
	.byte W03
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W02
	.byte c_v+29 @ BEND
	.byte W03
	.byte c_v+32 @ BEND
	.byte W11
	.byte FINE

.align 2

track_229:
	.byte 2
	.byte 0
	.byte 196
	.byte 0
	.word 0x80a6af0
	.word track_229_0
	.word track_229_1

.align 2
