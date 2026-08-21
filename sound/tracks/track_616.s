.align 2

.global track_616

track_616_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 47
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v
	.byte N30, An2, v100
	.byte W01
	.byte BEND, c_v-2
	.byte W02
	.byte c_v-4 @ BEND
	.byte W02
	.byte c_v-6 @ BEND
	.byte W02
	.byte c_v-8 @ BEND
	.byte W02
	.byte c_v-10 @ BEND
	.byte W02
	.byte c_v-12 @ BEND
	.byte W02
	.byte c_v-14 @ BEND
	.byte W02
	.byte VOL, 47
	.byte BEND, c_v-16
	.byte W02
	.byte VOL, 27
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 15
	.byte BEND, c_v-20
	.byte W02
	.byte VOL, 10
	.byte BEND, c_v-22
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v-24
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v-28
	.byte W02
	.byte VOL, 0
	.byte BEND, c_v-29
	.byte W01
	.byte VOICE, 7
	.byte VOL, 86
	.byte BEND, c_v
	.byte N10, Cn2 @ v100
	.byte W28
	.byte FINE

track_616_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W13
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v020 @ N15
	.byte W15
	.byte FINE

.align 2

track_616:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_616_0
	.word track_616_1

.align 2
