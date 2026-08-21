.align 2

.global track_49

track_49_0:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte PAN, c_v
	.byte PRIO, 110
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 9
	.byte W12
	.byte VOL, 3
	.byte N60, Cn3, v052
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte W14
	.byte 77 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte VOICE, 5
	.byte VOL, 86
	.byte N32, Cn3, v100
	.byte W02
	.byte BEND, c_v
	.byte W02
	.byte c_v+2 @ BEND
	.byte W04
	.byte c_v+4 @ BEND
	.byte W03
	.byte c_v+6 @ BEND
	.byte W03
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+10 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+22 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte VOL, 83
	.byte W01
	.byte BEND, c_v+40
	.byte VOL, 77
	.byte W01
	.byte BEND, c_v+44
	.byte VOL, 76
	.byte W01
	.byte BEND, c_v+50
	.byte VOL, 72
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte VOICE, 6
	.byte BEND, c_v
	.byte VOL, 69
	.byte N22, Cn3, v032
	.byte W01
	.byte VOL, 67
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte BEND, c_v+2
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v+4
	.byte W02
	.byte VOL, 58
	.byte BEND, c_v+6
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v+10
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+14
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+20
	.byte W01
	.byte c_v+22 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+29
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W02
	.byte VOL, 51
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W02
	.byte W48
track_49_lbl_265d7e:
	.byte VOICE, 0
	.byte VOL, 110
	.byte N12, Cn1, v120
	.byte W36
	.byte N18 @ Cn1, v120
	.byte W12
	.byte W48
	.byte GOTO
		.word track_49_lbl_265d7e
	.byte FINE

track_49_1:
	.byte KEYSH, 0
	.byte PRIO, 109
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 2
	.byte VOL, 43
	.byte PAN, c_v-10
	.byte BEND, c_v
	.byte N07, Cn3, v120
	.byte W48
	.byte VOICE, 11
	.byte VOL, 29
	.byte N96, Ds0 @ v120
	.byte W03
	.byte VOL, 32
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 88 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 96 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 106 @ VOL
	.byte W01
	.byte 109 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W15
	.byte W48
track_49_lbl_265dea:
	.byte N36, Ds0, v120
	.byte W36
	.byte N60 @ Ds0, v120
	.byte W12
	.byte W48
	.byte GOTO
		.word track_49_lbl_265dea
	.byte FINE

track_49_2:
	.byte KEYSH, 0
	.byte PRIO, 108
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W06
	.byte VOICE, 3
	.byte VOL, 43
	.byte PAN, c_v
	.byte N18, Cn3, v120
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 88 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 106 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W24
	.byte W02
	.byte VOICE, 11
	.byte VOL, 29
	.byte BEND, c_v
	.byte N96, Ds0 @ v120
	.byte W03
	.byte VOL, 32
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 88 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 96 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 106 @ VOL
	.byte W01
	.byte 109 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W15
	.byte W48
track_49_lbl_265e75:
	.byte N36, Ds0, v120
	.byte W36
	.byte N60 @ Ds0, v120
	.byte W12
	.byte W48
	.byte GOTO
		.word track_49_lbl_265e75
	.byte FINE

.align 2

track_49:
	.byte 3
	.byte 49
	.byte 130
	.byte 128
	.word 0x80a61fc
	.word track_49_0
	.word track_49_1
	.word track_49_2

.align 2
