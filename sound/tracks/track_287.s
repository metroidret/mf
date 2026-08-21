.align 2

.global track_287

track_287_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte MOD, 20
	.byte VOL, 62
	.byte PAN, c_v
	.byte LFOS, 30
	.byte PRIO, 1
	.byte W01
track_287_lbl_27f635:
	.byte TIE, Fn2, v127
	.byte W92
	.byte W03
	.byte W07
	.byte EOT @ Fn2, v127
	.byte TIE @ Fn2, v127
	.byte W88
	.byte W01
	.byte W13
	.byte EOT @ Fn2, v127
	.byte GOTO
		.word track_287_lbl_27f635
	.byte FINE

track_287_1:
	.byte KEYSH, 0
	.byte VOICE, 55
	.byte VOL, 51
	.byte PAN, c_v
	.byte BENDR, 2
	.byte BEND, c_v-33
	.byte W01
track_287_lbl_27f654:
	.byte N44, Cn3, v072
	.byte W03
	.byte VOL, 58
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 66
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 73
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 74
	.byte BEND, c_v
	.byte W03
	.byte VOL, 75
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 76
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 77
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte BEND, c_v+10
	.byte W02
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 9
	.byte W03
	.byte 5 @ VOL
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 3
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 0
	.byte W01
	.byte BEND, c_v-33
	.byte W02
	.byte N44, Cn3, v060
	.byte W03
	.byte VOL, 58
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 66
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 73
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 74
	.byte BEND, c_v
	.byte W03
	.byte VOL, 75
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 76
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 77
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte BEND, c_v+10
	.byte W02
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 9
	.byte W03
	.byte 5 @ VOL
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 3
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 0
	.byte W04
	.byte W32
	.byte W02
	.byte N44 @ Cn3, v060
	.byte W03
	.byte VOL, 58
	.byte BEND, c_v-22
	.byte W03
	.byte VOL, 66
	.byte BEND, c_v-13
	.byte W03
	.byte VOL, 73
	.byte BEND, c_v-6
	.byte W03
	.byte VOL, 74
	.byte BEND, c_v
	.byte W03
	.byte VOL, 75
	.byte BEND, c_v+5
	.byte W03
	.byte VOL, 76
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 77
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte BEND, c_v+10
	.byte W02
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 9
	.byte W03
	.byte 5 @ VOL
	.byte W01
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 3
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 0
	.byte W18
	.byte W13
	.byte GOTO
		.word track_287_lbl_27f654
	.byte FINE

track_287_2:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 62
	.byte PAN, c_v
	.byte PRIO, 127
	.byte W01
track_287_lbl_27f74a:
	.byte N03, En4, v100
	.byte W42
	.byte W01
	.byte N06, Cn4 @ v100
	.byte W36
	.byte W02
	.byte N10, Gn4 @ v100
	.byte W14
	.byte W32
	.byte W02
	.byte N05, Cn4 @ v100
	.byte W60
	.byte W02
	.byte W13
	.byte GOTO
		.word track_287_lbl_27f74a
	.byte FINE

.align 2

track_287:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_287_0
	.word track_287_1
	.word track_287_2

.align 2
