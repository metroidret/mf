.align 2

.global track_539

track_539_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 1
	.byte VOL, 23
	.byte N60, Cs3, v127
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
	.byte 70 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W23
	.byte FINE

track_539_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 62
	.byte PAN, c_v
	.byte W15
	.byte VOL, 23
	.byte N60, Cn3, v032
	.byte W03
	.byte VOL, 29
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W04
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W05
	.byte FINE

.align 2

track_539:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a826c
	.word track_539_0
	.word track_539_1

.align 2
