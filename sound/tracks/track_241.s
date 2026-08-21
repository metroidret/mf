.align 2

.global track_241

track_241_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N05, Cn3, v040
	.byte W05
	.byte VOICE, 37
	.byte MOD, 110
	.byte VOL, 80
	.byte LFOS, 45
	.byte N60, Cn4, v100
	.byte W03
	.byte VOL, 85
	.byte W02
	.byte 89 @ VOL
	.byte W02
	.byte 88 @ VOL
	.byte W06
	.byte 87 @ VOL
	.byte W02
	.byte 86 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W02
	.byte 82 @ VOL
	.byte W02
	.byte 81 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_241_1:
	.byte KEYSH, 0
	.byte VOICE, 39
	.byte VOL, 77
	.byte PAN, c_v
	.byte BENDR, 20
	.byte W05
	.byte BEND, c_v+7
	.byte N60, Ds3, v127
	.byte W03
	.byte VOL, 77
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte BEND, c_v+5
	.byte VOL, 74
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte BEND, c_v+3
	.byte VOL, 70
	.byte W03
	.byte BEND, c_v+2
	.byte VOL, 67
	.byte W03
	.byte BEND, c_v-1
	.byte VOL, 63
	.byte W03
	.byte BEND, c_v-5
	.byte VOL, 58
	.byte W03
	.byte 50 @ VOL
	.byte BEND, c_v-9
	.byte VOL, 50
	.byte W03
	.byte 38 @ VOL
	.byte BEND, c_v-14
	.byte W03
	.byte VOL, 30
	.byte BEND, c_v-20
	.byte W03
	.byte VOL, 23
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-39
	.byte W03
	.byte VOL, 13
	.byte BEND, c_v-45
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-51
	.byte W03
	.byte VOL, 7
	.byte BEND, c_v-55
	.byte W03
	.byte VOL, 5
	.byte BEND, c_v-59
	.byte W03
	.byte VOL, 3
	.byte BEND, c_v-61
	.byte W03
	.byte VOL, 2
	.byte W03
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_241:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_241_0
	.word track_241_1

.align 2
