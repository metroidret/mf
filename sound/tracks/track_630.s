.align 2

.global track_630

track_630_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte PAN, c_v
	.byte BENDR, 20
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-25
	.byte N30, An2, v040
	.byte W03
	.byte VOL, 33
	.byte BEND, c_v-23
	.byte W03
	.byte VOL, 34
	.byte BEND, c_v-20
	.byte W03
	.byte VOL, 36
	.byte BEND, c_v-17
	.byte W03
	.byte VOL, 37
	.byte BEND, c_v-14
	.byte W03
	.byte VOL, 40
	.byte BEND, c_v-12
	.byte W03
	.byte VOL, 41
	.byte BEND, c_v-9
	.byte W03
	.byte VOL, 43
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 44
	.byte BEND, c_v-3
	.byte W03
	.byte c_v @ BEND
	.byte W15
	.byte VOL, 47
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
	.byte W19
	.byte FINE

track_630_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W03
	.byte N15, Bn2, v127
	.byte W15
	.byte Bn2, v060 @ N15
	.byte W15
	.byte Bn2, v020 @ N15
	.byte W15
	.byte Cn3, v100 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte Cn3, v016 @ N15
	.byte W15
	.byte FINE

.align 2

track_630:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7aa4
	.word track_630_0
	.word track_630_1

.align 2
