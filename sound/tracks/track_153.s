.align 2

.global track_153

track_153_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W32
	.byte W03
	.byte PRIO, 1
	.byte W01
	.byte VOICE, 52
	.byte VOL, 110
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N15, Cn3, v112
	.byte W15
	.byte VOICE, 55
	.byte N09, Ds3, v060
	.byte W09
	.byte Ds3, v032 @ N09
	.byte W09
	.byte VOICE, 53
	.byte VOL, 56
	.byte BENDR, 12
	.byte BEND, c_v+5
	.byte N54, Cn3, v064
	.byte W03
	.byte VOL, 61
	.byte BEND, c_v+13
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v+22
	.byte W03
	.byte VOL, 77
	.byte BEND, c_v+31
	.byte W03
	.byte VOL, 87
	.byte BEND, c_v+43
	.byte W03
	.byte VOL, 103
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 110
	.byte W02
	.byte BEND, c_v+61
	.byte W03
	.byte c_v+62 @ BEND
	.byte W03
	.byte c_v+59 @ BEND
	.byte W03
	.byte c_v+52 @ BEND
	.byte W03
	.byte VOL, 110
	.byte BEND, c_v+42
	.byte W03
	.byte VOL, 108
	.byte BEND, c_v+29
	.byte W03
	.byte c_v+17 @ BEND
	.byte W03
	.byte VOL, 106
	.byte BEND, c_v+8
	.byte W03
	.byte VOL, 104
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 102
	.byte BEND, c_v+1
	.byte W03
	.byte VOL, 97
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 92
	.byte BEND, c_v+13
	.byte W03
	.byte VOL, 84
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v+22
	.byte N48, Cn3, v060
	.byte W03
	.byte VOL, 77
	.byte BEND, c_v+31
	.byte W03
	.byte VOL, 87
	.byte BEND, c_v+43
	.byte W03
	.byte VOL, 103
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 110
	.byte W02
	.byte BEND, c_v+61
	.byte W03
	.byte c_v+62 @ BEND
	.byte W03
	.byte c_v+59 @ BEND
	.byte W03
	.byte c_v+52 @ BEND
	.byte W03
	.byte VOL, 110
	.byte BEND, c_v+42
	.byte W03
	.byte VOL, 108
	.byte BEND, c_v+29
	.byte W03
	.byte c_v+17 @ BEND
	.byte W03
	.byte VOL, 106
	.byte BEND, c_v+8
	.byte W03
	.byte VOL, 104
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 102
	.byte BEND, c_v+1
	.byte W03
	.byte VOL, 97
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 92
	.byte BEND, c_v+13
	.byte W03
	.byte VOL, 84
	.byte BEND, c_v+22
	.byte W01
track_153_lbl_27d0fe:
	.byte VOL, 68
	.byte BEND, c_v+22
	.byte N48, Cn3, v052
	.byte W03
	.byte VOL, 77
	.byte BEND, c_v+31
	.byte W03
	.byte VOL, 87
	.byte BEND, c_v+43
	.byte W03
	.byte VOL, 103
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 110
	.byte W02
	.byte BEND, c_v+61
	.byte W03
	.byte c_v+62 @ BEND
	.byte W03
	.byte c_v+59 @ BEND
	.byte W01
	.byte W02
	.byte c_v+52 @ BEND
	.byte W03
	.byte VOL, 110
	.byte BEND, c_v+42
	.byte W03
	.byte VOL, 108
	.byte BEND, c_v+29
	.byte W03
	.byte c_v+17 @ BEND
	.byte W03
	.byte VOL, 106
	.byte BEND, c_v+8
	.byte W03
	.byte VOL, 104
	.byte BEND, c_v+2
	.byte W03
	.byte VOL, 102
	.byte BEND, c_v+1
	.byte W03
	.byte VOL, 97
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 92
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 84
	.byte BEND, c_v+22
	.byte W01
	.byte GOTO
		.word track_153_lbl_27d0fe
	.byte FINE

track_153_1:
	.byte KEYSH, 0
	.byte VOICE, 53
	.byte VOL, 8
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-63
	.byte N56, Cn3, v080
	.byte W03
	.byte VOL, 10
	.byte BEND, c_v-61
	.byte W03
	.byte VOL, 12
	.byte BEND, c_v-59
	.byte W03
	.byte VOL, 14
	.byte BEND, c_v-57
	.byte W03
	.byte VOL, 17
	.byte BEND, c_v-54
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-51
	.byte W03
	.byte VOL, 23
	.byte BEND, c_v-47
	.byte W03
	.byte VOL, 26
	.byte BEND, c_v-44
	.byte W03
	.byte VOL, 30
	.byte BEND, c_v-39
	.byte W03
	.byte VOL, 34
	.byte BEND, c_v-35
	.byte W03
	.byte VOL, 38
	.byte BEND, c_v-29
	.byte W03
	.byte VOL, 43
	.byte BEND, c_v-23
	.byte W02
	.byte PRIO, 0
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v-15
	.byte W03
	.byte VOL, 53
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 60
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v+17
	.byte W03
	.byte VOL, 76
	.byte BEND, c_v+31
	.byte W03
	.byte VOL, 85
	.byte BEND, c_v+44
	.byte W02
	.byte VOL, 95
	.byte BEND, c_v+54
	.byte W02
	.byte VOL, 106
	.byte BEND, c_v+61
	.byte W01
	.byte VOICE, 54
	.byte VOL, 86
	.byte BEND, c_v
	.byte TIE, Cn3, v120
	.byte W05
	.byte VOL, 84
	.byte W03
	.byte 83 @ VOL
	.byte W03
	.byte 82 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W02
	.byte W01
	.byte 65 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte MOD, 20
	.byte LFOS, 20
	.byte VOL, 26
	.byte W01
	.byte EOT @ Cn3, v120
track_153_lbl_27d224:
	.byte N48, Cn3, v120
	.byte W03
	.byte VOL, 23
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W01
	.byte W02
	.byte 23 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte GOTO
		.word track_153_lbl_27d224
	.byte FINE

.align 2

track_153:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a682c
	.word track_153_0
	.word track_153_1

.align 2
