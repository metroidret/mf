.align 2

.global track_90

track_90_0:
	.byte KEYSH, 0
	.byte TEMPO, 73
	.byte VOICE, 7
	.byte VOL, 60
	.byte PAN, c_v+6
	.byte PRIO, 110
	.byte N06, Fs4, v060
	.byte W08
	.byte N05, Fn4, v040
	.byte W08
	.byte En4 @ N05, v040
	.byte W08
	.byte Fs4 @ N05, v040
	.byte W08
	.byte Fn4 @ N05, v040
	.byte W08
	.byte En4 @ N05, v040
	.byte W08
	.byte Fs4 @ N05, v040
	.byte W08
	.byte Fn4 @ N05, v040
	.byte W08
	.byte En4 @ N05, v040
	.byte W08
	.byte Dn4, v060 @ N05
	.byte W08
	.byte Ds4 @ N05, v060
	.byte W08
	.byte En4 @ N05, v060
	.byte W08
track_90_lbl_26d43d:
	.byte N06, Fs4, v032
	.byte W08
	.byte N05, Fn4, v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte N06, Fs4 @ v020
	.byte W08
	.byte N05, Fn4 @ v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte N06, Fs4 @ v020
	.byte W08
	.byte N05, Fn4 @ v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte Dn4, v032 @ N05
	.byte W08
	.byte Ds4 @ N05, v032
	.byte W08
	.byte En4, v040 @ N05
	.byte W08
	.byte Fs4, v052 @ N05
	.byte W08
	.byte Fn4 @ N05, v052
	.byte W08
	.byte En4 @ N05, v052
	.byte W08
	.byte Fs4 @ N05, v052
	.byte W08
	.byte Fn4 @ N05, v052
	.byte W08
	.byte En4 @ N05, v052
	.byte W08
	.byte Fs4 @ N05, v052
	.byte W08
	.byte Fn4 @ N05, v052
	.byte W08
	.byte En4 @ N05, v052
	.byte W08
	.byte Dn4 @ N05, v052
	.byte W08
	.byte Ds4 @ N05, v052
	.byte W08
	.byte En4 @ N05, v052
	.byte W08
	.byte W08
	.byte N06, Cn4, v032, 78
	.byte W08
	.byte Cn4 @ N06, v032
	.byte N06, Fs4 @ v032
	.byte W16
	.byte Cs4, v044, 79 @ N06
	.byte W08
	.byte Cs4, v036, 79 @ N06
	.byte W16
	.byte Cn4 @ N06, v036
	.byte N06, Fs4 @ v036
	.byte W08
	.byte Cn4 @ N06, v036
	.byte N06, Fs4 @ v036
	.byte W16
	.byte Ds4, v048, 81 @ N06
	.byte W08
	.byte Ds4 @ N06, v048
	.byte N06, An4 @ v048
	.byte W08
	.byte W08
	.byte Dn4, v032, 80 @ N06
	.byte W08
	.byte Dn4 @ N06, v032
	.byte N06, Gs4 @ v032
	.byte W16
	.byte Ds4, v036, 81 @ N06
	.byte W08
	.byte Ds4 @ N06, v036
	.byte N06, An4 @ v036
	.byte W16
	.byte Dn4 @ N06, v036
	.byte N06, Gs4 @ v036
	.byte W08
	.byte Dn4 @ N06, v036
	.byte N06, Gs4 @ v036
	.byte W16
	.byte Fn4, v056, 83 @ N06
	.byte W08
	.byte Fn4, v052, 83 @ N06
	.byte W08
	.byte W08
	.byte En4 @ N06, v052
	.byte N06, As4 @ v052
	.byte W08
	.byte En4 @ N06, v052
	.byte N06, As4 @ v052
	.byte W16
	.byte Fn4, v064, 83 @ N06
	.byte W08
	.byte Fn4 @ N06, v064
	.byte N06, Bn4 @ v064
	.byte W16
	.byte Fs4, v068, 84 @ N06
	.byte W08
	.byte Fs4 @ N06, v068
	.byte N06, Cn5 @ v068
	.byte W16
	.byte Gn4, v072, 85 @ N06
	.byte W08
	.byte Gn4 @ N06, v072
	.byte N06, Cs5 @ v072
	.byte W08
	.byte W08
	.byte En4, v076, 82 @ N06
	.byte W08
	.byte En4 @ N06, v076
	.byte N06, As4 @ v076
	.byte W16
	.byte Fn4 @ N06, v076
	.byte N06, Bn4 @ v076
	.byte W08
	.byte Fn4 @ N06, v076
	.byte N06, Bn4 @ v076
	.byte W16
	.byte Cn5 @ N06, v076
	.byte W08
	.byte N06 @ Cn5, v076
	.byte W16
	.byte Cs5 @ N06, v076
	.byte W08
	.byte N06 @ Cs5, v076
	.byte W08
	.byte Fs4, v032 @ N06
	.byte W08
	.byte N05, Fn4, v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte Fs4 @ N05, v020
	.byte W08
	.byte Fn4 @ N05, v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte Fs4 @ N05, v020
	.byte W08
	.byte Fn4 @ N05, v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte Dn4, v032 @ N05
	.byte W08
	.byte Ds4 @ N05, v032
	.byte W08
	.byte En4, v040 @ N05
	.byte W08
	.byte GOTO
		.word track_90_lbl_26d43d
	.byte FINE

track_90_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 43
	.byte PAN, c_v-4
	.byte PRIO, 109
	.byte N06, En4, v060
	.byte W08
	.byte N05, Ds4, v040
	.byte W08
	.byte Dn4 @ N05, v040
	.byte W08
	.byte En4 @ N05, v040
	.byte W08
	.byte Ds4 @ N05, v040
	.byte W08
	.byte Dn4 @ N05, v040
	.byte W08
	.byte En4 @ N05, v040
	.byte W08
	.byte Ds4 @ N05, v040
	.byte W08
	.byte Dn4 @ N05, v040
	.byte W08
	.byte Cn4, v060 @ N05
	.byte W08
	.byte Cs4 @ N05, v060
	.byte W08
	.byte Dn4 @ N05, v060
	.byte W08
track_90_lbl_26d53f:
	.byte N06, En4, v032
	.byte W08
	.byte N05, Ds4, v020
	.byte W08
	.byte Dn4 @ N05, v020
	.byte W08
	.byte N06, En4 @ v020
	.byte W08
	.byte N05, Ds4 @ v020
	.byte W08
	.byte Dn4 @ N05, v020
	.byte W08
	.byte N06, En4 @ v020
	.byte W08
	.byte N05, Ds4 @ v020
	.byte W08
	.byte Dn4 @ N05, v020
	.byte W08
	.byte Cn4, v032 @ N05
	.byte W08
	.byte Cs4 @ N05, v032
	.byte W08
	.byte Dn4, v040 @ N05
	.byte W08
	.byte En4, v052 @ N05
	.byte W08
	.byte Ds4 @ N05, v052
	.byte W08
	.byte Dn4 @ N05, v052
	.byte W08
	.byte En4 @ N05, v052
	.byte W08
	.byte Ds4 @ N05, v052
	.byte W08
	.byte Dn4 @ N05, v052
	.byte W08
	.byte En4 @ N05, v052
	.byte W08
	.byte Ds4 @ N05, v052
	.byte W08
	.byte Dn4 @ N05, v052
	.byte W08
	.byte Cn4 @ N05, v052
	.byte W08
	.byte Cs4 @ N05, v052
	.byte W08
	.byte Dn4 @ N05, v052
	.byte W08
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 10
	.byte VOL, 91
	.byte N24, Gn3 @ v052
	.byte W01
	.byte VOL, 89
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte N24, Gs3, v064
	.byte W01
	.byte VOL, 61
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte N24, Gn3, v052, 69
	.byte En4 @ N24, v052
	.byte W01
	.byte VOL, 67
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte N24, Gs3, v064, 70
	.byte En5 @ N24, v064
	.byte W01
	.byte VOL, 88
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 94 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 96 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte W01
	.byte 99 @ VOL
	.byte W01
	.byte 100 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 102 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 104 @ VOL
	.byte W01
	.byte 105 @ VOL
	.byte W03
	.byte VOICE, 7
	.byte VOL, 43
	.byte N06, En4, v052
	.byte W08
	.byte N05, Ds4, v032
	.byte W08
	.byte Dn4, v020 @ N05
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte Ds4 @ N05, v020
	.byte W08
	.byte Dn4 @ N05, v020
	.byte W08
	.byte En4 @ N05, v020
	.byte W08
	.byte Ds4 @ N05, v020
	.byte W08
	.byte Dn4 @ N05, v020
	.byte W08
	.byte Cn4, v032 @ N05
	.byte W08
	.byte Cs4 @ N05, v032
	.byte W08
	.byte Dn4, v040 @ N05
	.byte W08
	.byte GOTO
		.word track_90_lbl_26d53f
	.byte FINE

track_90_2:
	.byte KEYSH, 0
	.byte PAN, c_v+16
	.byte PRIO, 108
	.byte W96
track_90_lbl_26d67b:
	.byte VOICE, 7
	.byte VOL, 43
	.byte N06, An3, v032
	.byte W08
	.byte N05, Gs3, v020
	.byte W08
	.byte Gn3 @ N05, v020
	.byte W08
	.byte N06, An3 @ v020
	.byte W08
	.byte N05, Gs3 @ v020
	.byte W08
	.byte Gn3 @ N05, v020
	.byte W08
	.byte N06, An3 @ v020
	.byte W08
	.byte N05, Gs3 @ v020
	.byte W08
	.byte Gn3 @ N05, v020
	.byte W08
	.byte N07, Fn3, v032
	.byte W08
	.byte Fs3 @ N07, v032
	.byte W08
	.byte Gn3, v040 @ N07
	.byte W08
	.byte VOICE, 2
	.byte VOL, 103
	.byte N24, Cn2, v120
	.byte W24
	.byte N24 @ Cn2, v120
	.byte W24
	.byte N24 @ Cn2, v120
	.byte W24
	.byte Gs1 @ N24, v120
	.byte W24
	.byte N08, Cn2, v100
	.byte W08
	.byte N16, Cn2, v080
	.byte W16
	.byte N08, Cn2, v072
	.byte W08
	.byte N16 @ Cn2, v072
	.byte W16
	.byte N08, Cn2, v064
	.byte W08
	.byte N16 @ Cn2, v064
	.byte W16
	.byte N08, Cn2, v072
	.byte W08
	.byte N16 @ Cn2, v072
	.byte W16
	.byte N08, Cn2, v092
	.byte W08
	.byte N16 @ Cn2, v092
	.byte W16
	.byte N08, Cn2, v096
	.byte W08
	.byte N16 @ Cn2, v096
	.byte W16
	.byte N08, Cn2, v104
	.byte W08
	.byte N16 @ Cn2, v104
	.byte W16
	.byte N08, Cn2, v120
	.byte W08
	.byte Cn2, v124 @ N08
	.byte W08
	.byte N08 @ Cn2, v124
	.byte W08
	.byte N24, Cn2, v112
	.byte W24
	.byte Cn2, v127 @ N24
	.byte W24
	.byte N24 @ Cn2, v127
	.byte W24
	.byte N07, Gs1 @ v127
	.byte W08
	.byte An1 @ N07, v127
	.byte W08
	.byte N12, As1 @ v127
	.byte W08
	.byte W96
	.byte W96
	.byte GOTO
		.word track_90_lbl_26d67b
	.byte FINE

track_90_3:
	.byte KEYSH, 0
	.byte PAN, c_v-14
	.byte PRIO, 30
	.byte W96
track_90_lbl_26d705:
	.byte W96
	.byte VOICE, 7
	.byte VOL, 43
	.byte N06, An3, v052
	.byte W08
	.byte Gs3 @ N06, v052
	.byte W08
	.byte Gn3 @ N06, v052
	.byte W08
	.byte An3 @ N06, v052
	.byte W08
	.byte Gs3 @ N06, v052
	.byte W08
	.byte Gn3 @ N06, v052
	.byte W08
	.byte An3 @ N06, v052
	.byte W08
	.byte Gs3 @ N06, v052
	.byte W08
	.byte Gn3 @ N06, v052
	.byte W08
	.byte Fn3 @ N06, v052
	.byte W08
	.byte Fs3 @ N06, v052
	.byte W08
	.byte Gn3 @ N06, v052
	.byte W08
	.byte VOICE, 14
	.byte VOL, 86
	.byte N06, Cn5 @ v052
	.byte W08
	.byte N05, Cn5, v032
	.byte W16
	.byte N06, Cn5, v052
	.byte W08
	.byte N05, Cn5, v032
	.byte W16
	.byte N06, Cn5, v052
	.byte W08
	.byte N05, Cn5, v032
	.byte W16
	.byte N06, Cn5, v052
	.byte W08
	.byte N05, Cn5, v032
	.byte W16
track_90_lbl_26d747:
	.byte N06, Cn5, v060
	.byte W08
	.byte N05, Cn5, v040
	.byte W16
	.byte N06, Cn5, v060
	.byte W08
	.byte N05, Cn5, v040
	.byte W16
	.byte N06, Cn5, v060
	.byte W08
	.byte N05, Cn5, v040
	.byte W16
	.byte N06, Cn5, v060
	.byte W08
	.byte N05, Cn5, v040
	.byte W16
	.byte PEND
	.byte PATT
		.word track_90_lbl_26d747
	.byte W72
	.byte VOICE, 10
	.byte VOL, 87
	.byte N24, Gn3, v052
	.byte W01
	.byte VOL, 88
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 94 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 96 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte W01
	.byte 99 @ VOL
	.byte W01
	.byte 100 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 102 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 104 @ VOL
	.byte W01
	.byte 105 @ VOL
	.byte W03
	.byte W96
	.byte GOTO
		.word track_90_lbl_26d705
	.byte FINE

track_90_4:
	.byte KEYSH, 0
	.byte PAN, c_v+6
	.byte PRIO, 1
	.byte W96
track_90_lbl_26d7af:
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte VOICE, 7
	.byte VOL, 60
	.byte W08
	.byte N06, Fs4, v076
	.byte W08
	.byte N06 @ Fs4, v076
	.byte W16
	.byte Gn4 @ N06, v076
	.byte W08
	.byte N06 @ Gn4, v076
	.byte W08
	.byte W96
	.byte GOTO
		.word track_90_lbl_26d7af
	.byte FINE

track_90_5:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 86
	.byte PAN, c_v-20
	.byte PRIO, 30
	.byte W96
track_90_lbl_26d7d6:
	.byte W96
	.byte N06, Cn2, v100
	.byte W08
	.byte Bn1 @ N06, v100
	.byte W08
	.byte As1 @ N06, v100
	.byte W08
	.byte Cn2 @ N06, v100
	.byte W08
	.byte Bn1 @ N06, v100
	.byte W08
	.byte As1 @ N06, v100
	.byte W08
	.byte Cn2 @ N06, v100
	.byte W08
	.byte Bn1 @ N06, v100
	.byte W08
	.byte As1 @ N06, v100
	.byte W08
	.byte Gs1 @ N06, v100
	.byte W08
	.byte An1 @ N06, v100
	.byte W08
	.byte As1 @ N06, v100
	.byte W08
	.byte Cn2 @ N06, v100
	.byte W08
	.byte Cn2, v080 @ N06
	.byte W16
	.byte Cn2, v072 @ N06
	.byte W08
	.byte N06 @ Cn2, v072
	.byte W16
	.byte Cn2, v064 @ N06
	.byte W08
	.byte N06 @ Cn2, v064
	.byte W16
	.byte Cn2, v072 @ N06
	.byte W08
	.byte N06 @ Cn2, v072
	.byte W16
	.byte Cn2, v092 @ N06
	.byte W08
	.byte N14 @ Cn2, v092
	.byte W16
	.byte N06, Cn2, v096
	.byte W08
	.byte N14 @ Cn2, v096
	.byte W16
	.byte N06, Cn2, v104
	.byte W08
	.byte N14 @ Cn2, v104
	.byte W16
	.byte N06, Cn2, v120
	.byte W08
	.byte Cn2, v124 @ N06
	.byte W08
	.byte N06 @ Cn2, v124
	.byte W08
	.byte N22, Cn2, v112
	.byte W24
	.byte Cn2, v127 @ N22
	.byte W24
	.byte N22 @ Cn2, v127
	.byte W24
	.byte N07, Gs1 @ v127
	.byte W08
	.byte An1 @ N07, v127
	.byte W08
	.byte N12, As1 @ v127
	.byte W08
	.byte W96
	.byte W96
	.byte GOTO
		.word track_90_lbl_26d7d6
	.byte FINE

.align 2

track_90:
	.byte 6
	.byte 90
	.byte 130
	.byte 128
	.word 0x80a5bd8
	.word track_90_0
	.word track_90_1
	.word track_90_2
	.word track_90_3
	.word track_90_4
	.word track_90_5

.align 2
