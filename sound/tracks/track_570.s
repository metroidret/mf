.align 2

.global track_570

track_570_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 0
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W16
	.byte N28, Cn3, v120
	.byte W01
	.byte VOL, 32
	.byte W02
	.byte 66 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W04
	.byte FINE

track_570_1:
	.byte KEYSH, 0
	.byte VOICE, 46
	.byte VOL, 59
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-39
	.byte N20, Cn3, v100
	.byte W01
	.byte VOL, 54
	.byte W01
	.byte 49 @ VOL
	.byte BEND, c_v-28
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte 41 @ VOL
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 38
	.byte W01
	.byte 37 @ VOL
	.byte BEND, c_v-11
	.byte W01
	.byte VOL, 35
	.byte W01
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 36
	.byte W01
	.byte 37 @ VOL
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 38
	.byte W01
	.byte 41 @ VOL
	.byte BEND, c_v+7
	.byte VOL, 62
	.byte W01
	.byte BEND, c_v+6
	.byte VOL, 59
	.byte W01
	.byte BEND, c_v+5
	.byte VOL, 54
	.byte W01
	.byte BEND, c_v+3
	.byte VOL, 48
	.byte W01
	.byte BEND, c_v+1
	.byte VOL, 29
	.byte W01
	.byte BEND, c_v-3
	.byte VOL, 30
	.byte W01
	.byte BEND, c_v-7
	.byte VOL, 33
	.byte W01
	.byte 41 @ VOL
	.byte W24
	.byte W01
	.byte FINE

.align 2

track_570:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_570_0
	.word track_570_1

.align 2
