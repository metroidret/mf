.align 2

.global track_96

track_96_0:
	.byte KEYSH, 0
	.byte TEMPO, 30
	.byte VOICE, 19
	.byte VOL, 62
	.byte PAN, c_v+20
	.byte PRIO, 110
	.byte TIE, Bn0, v120
	.byte W96
track_96_lbl_26ff84:
	.byte W13
	.byte VOL, 64
	.byte W02
	.byte 66 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W03
	.byte 83 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W03
	.byte 86 @ VOL
	.byte W03
	.byte 88 @ VOL
	.byte W03
	.byte 89 @ VOL
	.byte W02
	.byte 91 @ VOL
	.byte W03
	.byte 92 @ VOL
	.byte W03
	.byte 94 @ VOL
	.byte W02
	.byte 92 @ VOL
	.byte W02
	.byte 90 @ VOL
	.byte W02
	.byte 88 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W02
	.byte 81 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 73 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte PEND
track_96_lbl_26ffd1:
	.byte W28
	.byte VOL, 64
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W02
	.byte 81 @ VOL
	.byte W02
	.byte 82 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W02
	.byte 88 @ VOL
	.byte W01
	.byte 89 @ VOL
	.byte W02
	.byte 92 @ VOL
	.byte W02
	.byte 90 @ VOL
	.byte W02
	.byte 88 @ VOL
	.byte W02
	.byte 87 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W02
	.byte 84 @ VOL
	.byte W02
	.byte 82 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W02
	.byte 77 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W07
	.byte EOT @ Bn0, v120
	.byte PEND
track_96_lbl_270017:
	.byte VOL, 62
	.byte TIE, Bn0, v120
	.byte W96
	.byte PATT
		.word track_96_lbl_26ff84
	.byte PATT
		.word track_96_lbl_26ffd1
	.byte GOTO
		.word track_96_lbl_270017
	.byte FINE

track_96_1:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 7
	.byte PAN, c_v-10
	.byte PRIO, 109
	.byte TIE, Fs2, v052
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
track_96_lbl_2700ae:
	.byte W02
	.byte VOL, 28
	.byte W02
	.byte 29 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W06
	.byte 26 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W06
	.byte 23 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W06
	.byte 20 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W06
	.byte 17 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W05
	.byte 11 @ VOL
	.byte W06
	.byte 9 @ VOL
	.byte W05
	.byte 7 @ VOL
	.byte W08
	.byte PEND
track_96_lbl_2700d5:
	.byte W28
	.byte VOL, 9
	.byte W01
	.byte 11 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte EOT @ Fs2, v052
	.byte PEND
track_96_lbl_270117:
	.byte VOL, 7
	.byte TIE, Fs2, v052
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte PATT
		.word track_96_lbl_2700ae
	.byte PATT
		.word track_96_lbl_2700d5
	.byte GOTO
		.word track_96_lbl_270117
	.byte FINE

track_96_2:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 62
	.byte PAN, c_v-20
	.byte PRIO, 108
	.byte W12
	.byte TIE, Bn0, v040
	.byte W84
	.byte W96
	.byte W32
	.byte VOL, 61
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte EOT @ Bn0, v040
track_96_lbl_2701ef:
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_96_lbl_2701ef
	.byte FINE

.align 2

track_96:
	.byte 3
	.byte 96
	.byte 130
	.byte 128
	.word 0x80a6628
	.word track_96_0
	.word track_96_1
	.word track_96_2

.align 2
