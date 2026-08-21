.align 2

.global track_537

track_537_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte VOL, 23
	.byte N90, Cn3, v127
	.byte W03
	.byte VOL, 29
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 76 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W06
	.byte 49 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte BEND, c_v
	.byte VOL, 65
	.byte W03
	.byte BEND, c_v+1
	.byte VOL, 74
	.byte W05
	.byte 82 @ VOL
	.byte W01
	.byte BEND, c_v+3
	.byte W05
	.byte VOL, 84
	.byte W01
	.byte BEND, c_v+5
	.byte W03
	.byte c_v+7 @ BEND
	.byte W03
	.byte c_v+9 @ BEND
	.byte W02
	.byte VOL, 82
	.byte W01
	.byte BEND, c_v+13
	.byte W03
	.byte c_v+17 @ BEND
	.byte W02
	.byte VOL, 81
	.byte W01
	.byte BEND, c_v+22
	.byte W02
	.byte VOL, 79
	.byte W07
	.byte W15
	.byte FINE

track_537_1:
	.byte KEYSH, 0
	.byte W20
	.byte VOICE, 3
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v
	.byte VOL, 23
	.byte N90, Cn3, v032
	.byte W03
	.byte VOL, 29
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 76 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W06
	.byte 49 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte BEND, c_v
	.byte VOL, 65
	.byte W01
	.byte 66 @ VOL
	.byte W02
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 56
	.byte W03
	.byte 47 @ VOL
	.byte W02
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 38
	.byte W03
	.byte 32 @ VOL
	.byte W02
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 25
	.byte W02
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 22
	.byte W02
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 16
	.byte W02
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 14
	.byte W02
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 13
	.byte W03
	.byte FINE

.align 2

track_537:
	.byte 2
	.byte 0
	.byte 254
	.byte 0
	.word 0x80a826c
	.word track_537_0
	.word track_537_1

.align 2
