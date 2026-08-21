.align 2

.global track_572

track_572_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 23
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N28, Cn3, v127
	.byte W01
	.byte VOL, 16
	.byte W02
	.byte 33 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W03
	.byte VOICE, 47
	.byte VOL, 39
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N32, Cn3, v080
	.byte W10
	.byte VOL, 38
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_572_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 30
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte W07
	.byte N28, An2, v080
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte 31 @ VOL
	.byte BEND, c_v-28
	.byte W02
	.byte c_v-19 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte 27 @ VOL
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 26
	.byte W01
	.byte 24 @ VOL
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte 23 @ VOL
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+6
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+1
	.byte W01
	.byte c_v-3 @ BEND
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v-7
	.byte VOL, 16
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W28
	.byte FINE

.align 2

track_572:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a7798
	.word track_572_0
	.word track_572_1

.align 2
