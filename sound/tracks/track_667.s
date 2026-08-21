.align 2

.global track_667

track_667_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte PAN, c_v
	.byte PRIO, 3
	.byte W05
	.byte VOICE, 6
	.byte VOL, 70
	.byte BENDR, 12
	.byte BEND, c_v+1
	.byte N48, Dn3, v100
	.byte W02
	.byte BEND, c_v+11
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W03
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte VOL, 70
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_667_1:
	.byte KEYSH, 0
	.byte W05
	.byte VOICE, 7
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-48
	.byte N48, Cn3, v040
	.byte W02
	.byte BEND, c_v+29
	.byte W02
	.byte c_v+52 @ BEND
	.byte W03
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v+59 @ BEND
	.byte W02
	.byte c_v+53 @ BEND
	.byte W03
	.byte c_v+47 @ BEND
	.byte W01
	.byte VOL, 70
	.byte W01
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 54
	.byte W01
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 38
	.byte W02
	.byte BEND, c_v+1
	.byte VOL, 23
	.byte W01
	.byte 22 @ VOL
	.byte BEND, c_v-1
	.byte W01
	.byte c_v-17 @ BEND
	.byte W01
	.byte VOL, 19
	.byte W01
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 13
	.byte W03
	.byte 11 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_667:
	.byte 2
	.byte 0
	.byte 177
	.byte 0
	.word 0x80a7f24
	.word track_667_0
	.word track_667_1

.align 2
