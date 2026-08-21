.align 2

.global track_300

track_300_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 60
	.byte PAN, c_v
	.byte BENDR, 12
track_300_lbl_27ff62:
	.byte VOL, 4
	.byte BEND, c_v
	.byte W01
	.byte N28, An2, v032
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W44
	.byte W03
	.byte 4 @ VOL
	.byte W01
	.byte N28 @ An2, v032
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte BEND, c_v+12
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-5
	.byte W02
	.byte c_v-13 @ BEND
	.byte W01
	.byte VOL, 43
	.byte W01
	.byte BEND, c_v-17
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 35
	.byte BEND, c_v-23
	.byte W01
	.byte VOL, 34
	.byte W02
	.byte 25 @ VOL
	.byte W01
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte 18 @ VOL
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 19
	.byte W01
	.byte 29 @ VOL
	.byte BEND, c_v-11
	.byte W02
	.byte c_v-1 @ BEND
	.byte W44
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte N28 @ An2, v032
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v-12
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-5
	.byte W02
	.byte c_v+1 @ BEND
	.byte W01
	.byte VOL, 43
	.byte W01
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 35
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte 18 @ VOL
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 19
	.byte W01
	.byte 29 @ VOL
	.byte BEND, c_v+2
	.byte W02
	.byte c_v-1 @ BEND
	.byte W21
	.byte W23
	.byte GOTO
		.word track_300_lbl_27ff62
	.byte FINE

track_300_1:
	.byte KEYSH, 0
	.byte VOICE, 60
	.byte PAN, c_v
	.byte BENDR, 15
track_300_lbl_280019:
	.byte W56
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v
	.byte W02
	.byte N28, Gn2, v020
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W13
	.byte W11
	.byte N28, Bn2, v012
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v-12
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-5
	.byte W02
	.byte c_v+1 @ BEND
	.byte W01
	.byte VOL, 43
	.byte W01
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 35
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte 18 @ VOL
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 19
	.byte W01
	.byte 29 @ VOL
	.byte BEND, c_v+2
	.byte W02
	.byte c_v-1 @ BEND
	.byte W56
	.byte W03
	.byte W23
	.byte GOTO
		.word track_300_lbl_280019
	.byte FINE

.align 2

track_300:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a71ec
	.word track_300_0
	.word track_300_1

.align 2
