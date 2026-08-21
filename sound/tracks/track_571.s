.align 2

.global track_571

track_571_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 37
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W24
	.byte W02
	.byte N28, Cn3, v127
	.byte W01
	.byte VOL, 25
	.byte W02
	.byte 52 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W32
	.byte W01
	.byte FINE

track_571_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 48
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte N28, An2, v100
	.byte W01
	.byte VOL, 49
	.byte W01
	.byte 51 @ VOL
	.byte BEND, c_v-28
	.byte W02
	.byte c_v-19 @ BEND
	.byte W02
	.byte c_v-11 @ BEND
	.byte W01
	.byte VOL, 49
	.byte W01
	.byte 44 @ VOL
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 42
	.byte W01
	.byte 39 @ VOL
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 37
	.byte W01
	.byte 37 @ VOL
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+6
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+1
	.byte W01
	.byte c_v-3 @ BEND
	.byte VOL, 24
	.byte W01
	.byte BEND, c_v-7
	.byte VOL, 27
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W24
	.byte W03
	.byte VOICE, 47
	.byte VOL, 62
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N32, Cn3, v080
	.byte W10
	.byte VOL, 62
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_571:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_571_0
	.word track_571_1

.align 2
