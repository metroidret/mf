.align 2

.global track_567

track_567_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 56
	.byte PAN, c_v+36
	.byte W04
	.byte N15, Cn3, v100
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte Cn3, v080 @ N15
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte VOICE, 2
	.byte VOL, 18
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3, v127
	.byte W14
	.byte Fs3, v052 @ N14
	.byte W12
	.byte W02
	.byte VOICE, 3
	.byte N10, En3, v040
	.byte W72
	.byte W03
	.byte FINE

track_567_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 51
	.byte PAN, c_v+36
	.byte N15, Cn3, v060
	.byte W15
	.byte N15 @ Cn3, v060
	.byte W15
	.byte Cn3, v080 @ N15
	.byte W15
	.byte Cn3, v040 @ N15
	.byte W15
	.byte VOL, 14
	.byte N06, En3, v100
	.byte W06
	.byte N14, Gs3, v127
	.byte W14
	.byte Fs3, v052 @ N14
	.byte W14
	.byte VOICE, 3
	.byte N10, En3, v040
	.byte W02
	.byte W76
	.byte W01
	.byte FINE

track_567_2:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 37
	.byte PAN, c_v+36
	.byte W02
	.byte N04, Cn3, v060
	.byte W05
	.byte Cn3, v080 @ N04
	.byte W05
	.byte Cn3, v100 @ N04
	.byte W04
	.byte VOICE, 6
	.byte N04, Cn3, v127
	.byte W04
	.byte VOICE, 7
	.byte N04 @ Cn3, v127
	.byte W04
	.byte VOICE, 14
	.byte VOL, 120
	.byte PAN, c_v+46
	.byte TIE, Cn3, v100
	.byte W03
	.byte VOL, 118
	.byte W03
	.byte 115 @ VOL
	.byte W03
	.byte 112 @ VOL
	.byte W03
	.byte 109 @ VOL
	.byte W03
	.byte 106 @ VOL
	.byte W03
	.byte 102 @ VOL
	.byte W03
	.byte 97 @ VOL
	.byte W03
	.byte 90 @ VOL
	.byte W03
	.byte 82 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 13 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W06
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W09
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W09
	.byte 0 @ VOL
	.byte W08
	.byte EOT @ Cn3, v100
	.byte FINE

track_567_3:
	.byte KEYSH, 0
	.byte VOICE, 8
	.byte VOL, 120
	.byte PAN, c_v
	.byte W02
	.byte N05, Fn2, v127
	.byte W03
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte Gs2 @ N05, v127
	.byte W05
	.byte Fn2 @ N05, v127
	.byte W05
	.byte VOICE, 9
	.byte N05, En2, v100
	.byte W40
	.byte W01
	.byte W76
	.byte W01
	.byte FINE

track_567_4:
	.byte KEYSH, 0
	.byte VOICE, 40
	.byte VOL, 56
	.byte PAN, c_v+36
	.byte W02
	.byte N24, Cn3, v127
	.byte W92
	.byte W02
	.byte W76
	.byte W01
	.byte FINE

.align 2

track_567:
	.byte 5
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_567_0
	.word track_567_1
	.word track_567_2
	.word track_567_3
	.word track_567_4

.align 2
