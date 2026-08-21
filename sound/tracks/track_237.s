.align 2

.global track_237

track_237_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOL, 59
	.byte PAN, c_v
	.byte W05
	.byte VOICE, 40
	.byte N06, Gn3, v080
	.byte W06
	.byte VOICE, 31
	.byte VOL, 22
	.byte BENDR, 12
	.byte BEND, c_v+8
	.byte N32, Cn3 @ v080
	.byte W03
	.byte VOL, 25
	.byte BEND, c_v+7
	.byte W03
	.byte VOL, 29
	.byte BEND, c_v+6
	.byte W03
	.byte VOL, 27
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 20
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 15
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 14
	.byte W02
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 9
	.byte W02
	.byte 6 @ VOL
	.byte BEND, c_v+3
	.byte W03
	.byte VOL, 5
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 5
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 5
	.byte W02
	.byte BEND, c_v
	.byte W01
	.byte VOL, 3
	.byte W03
	.byte BEND, c_v
	.byte W01
	.byte VOL, 2
	.byte W13
	.byte FINE

track_237_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 95
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N05, Cn3, v040
	.byte W05
	.byte VOICE, 21
	.byte N06, Cn3, v120
	.byte W06
	.byte VOICE, 17
	.byte N06, Cn3, v100
	.byte W06
	.byte VOICE, 18
	.byte N06, Cn3, v080
	.byte W01
	.byte VOL, 82
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte VOICE, 17
	.byte VOL, 74
	.byte N06, Cn3, v040
	.byte W06
	.byte VOICE, 18
	.byte N06 @ Cn3, v040
	.byte W01
	.byte VOL, 67
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte VOICE, 17
	.byte VOL, 44
	.byte N06, Cn3, v020
	.byte W06
	.byte VOICE, 18
	.byte N06, Cn3, v016
	.byte W04
	.byte VOL, 24
	.byte W02
	.byte VOICE, 17
	.byte N06, Cn3, v020
	.byte W01
	.byte VOL, 7
	.byte W03
	.byte 5 @ VOL
	.byte W02
	.byte VOICE, 18
	.byte N06, Cn3, v012
	.byte W01
	.byte VOL, 2
	.byte W03
	.byte 0 @ VOL
	.byte W02
	.byte FINE

.align 2

track_237:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_237_0
	.word track_237_1

.align 2
