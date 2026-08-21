.align 2

.global track_81

track_81_0:
	.byte KEYSH, 0
track_81_lbl_26a6f6:
	.byte TEMPO, 85
	.byte VOICE, 17
	.byte VOL, 35
	.byte PAN, c_v+8
	.byte PRIO, 110
	.byte N32, Fs5, v056
	.byte W32
	.byte N14, Gn5, v060
	.byte W16
	.byte N16, An5, v056
	.byte W16
	.byte As5, v060 @ N16
	.byte W16
	.byte Bn5, v044 @ N16
	.byte W16
	.byte Ds6, v076 @ N16
	.byte W16
	.byte Dn6, v080 @ N16
	.byte W16
	.byte Cs6, v064 @ N16
	.byte W16
	.byte N18, Cn6, v076
	.byte W18
	.byte N14, Cs6, v080
	.byte W14
	.byte N16, Dn6, v064
	.byte W16
	.byte As5, v056 @ N16
	.byte W16
	.byte Bn5, v060 @ N16
	.byte W16
	.byte Cn6, v064 @ N16
	.byte W16
	.byte Dn6, v076 @ N16
	.byte W16
	.byte Ds6, v080 @ N16
	.byte W16
	.byte En6, v064 @ N16
	.byte W16
	.byte N10, Gn6, v080
	.byte W16
	.byte Fs6 @ N10, v080
	.byte W16
	.byte Fn6, v072 @ N10
	.byte W16
	.byte N36, Fs6, v076
	.byte W36
	.byte N12, Gn6, v064
	.byte W12
	.byte N36, Ds6, v076
	.byte W36
	.byte N12, En6, v064
	.byte W12
	.byte W16
	.byte N20, As5, v056
	.byte W20
	.byte N12, Bn5, v044
	.byte W28
	.byte N20, Gn5, v056
	.byte W20
	.byte N12, Gs5, v044
	.byte W12
	.byte W16
	.byte N16, Fs5, v060
	.byte W16
	.byte N12, Fn5, v064
	.byte W32
	.byte N16, Gs5, v060
	.byte W16
	.byte N12, Gn5, v044
	.byte W16
	.byte W18
	.byte N14, Bn5, v060
	.byte W14
	.byte N12, As5, v044
	.byte W32
	.byte N16, Dn6, v080
	.byte W16
	.byte N12, Cs6, v064
	.byte W16
	.byte N36, Fs6, v076
	.byte W36
	.byte N12, Gn6, v064
	.byte W28
	.byte N16, Fs4, v076
	.byte W16
	.byte Gn4, v064 @ N16
	.byte W16
	.byte W16
	.byte Fs5, v056 @ N16
	.byte W16
	.byte Gn5, v044 @ N16
	.byte W16
	.byte N10, Fs6, v080
	.byte W16
	.byte N10 @ Fs6, v080
	.byte W16
	.byte Gn6 @ N10, v080
	.byte W16
	.byte GOTO
		.word track_81_lbl_26a6f6
	.byte FINE

track_81_1:
	.byte KEYSH, 0
track_81_lbl_26a7ab:
	.byte VOICE, 18
	.byte VOL, 70
	.byte PAN, c_v+6
	.byte PRIO, 109
	.byte N12, Cs1, v124
	.byte W12
	.byte Cs2, v080 @ N12
	.byte W12
	.byte Cs3 @ N12, v080
	.byte W12
	.byte Cs1, v052 @ N12
	.byte W12
	.byte Cs1, v124 @ N12
	.byte W12
	.byte Cs2, v080 @ N12
	.byte W12
	.byte Cs3 @ N12, v080
	.byte W12
	.byte Cs1, v052 @ N12
	.byte W12
	.byte Cs1, v124 @ N12
	.byte W12
	.byte Cs2, v080 @ N12
	.byte W12
	.byte Cs3 @ N12, v080
	.byte W12
	.byte Cs1, v052 @ N12
	.byte W12
track_81_lbl_26a7d5:
	.byte N12, Dn1, v124
	.byte W12
	.byte Dn2, v080 @ N12
	.byte W12
	.byte Dn3 @ N12, v080
	.byte W12
	.byte Dn1, v052 @ N12
	.byte W12
	.byte Dn1, v124 @ N12
	.byte W12
	.byte Dn2, v080 @ N12
	.byte W12
	.byte Dn3 @ N12, v080
	.byte W12
	.byte Dn1, v052 @ N12
	.byte W12
	.byte PEND
	.byte PATT
		.word track_81_lbl_26a7d5
track_81_lbl_26a7f2:
	.byte N18, Ds1, v124
	.byte W18
	.byte N08, Ds1, v092
	.byte W18
	.byte N06, Ds1, v052
	.byte W12
	.byte N08, Ds1, v124
	.byte W16
	.byte Ds1, v092 @ N08
	.byte W20
	.byte N06, Ds1, v052
	.byte W12
	.byte PEND
	.byte PATT
		.word track_81_lbl_26a7f2
	.byte N18, En1, v124
	.byte W18
	.byte N08, En1, v092
	.byte W18
	.byte N06, En1, v052
	.byte W12
	.byte N08, En1, v124
	.byte W16
	.byte En1, v092 @ N08
	.byte W20
	.byte N06, En1, v052
	.byte W12
	.byte N08, En1, v124
	.byte W16
	.byte En1, v092 @ N08
	.byte W20
	.byte N06, En1, v052
	.byte W12
	.byte N12, En1, v124
	.byte W12
	.byte En2, v080 @ N12
	.byte W12
	.byte En3 @ N12, v080
	.byte W12
	.byte En1, v052 @ N12
	.byte W12
	.byte Fn1, v124 @ N12
	.byte W12
	.byte Fn2, v080 @ N12
	.byte W12
	.byte Fn3 @ N12, v080
	.byte W12
	.byte Fn1, v052 @ N12
	.byte W12
	.byte N08, Fn1, v124
	.byte W16
	.byte Fn1, v092 @ N08
	.byte W20
	.byte N06, Fn1, v052
	.byte W12
	.byte N08, Fn1, v124
	.byte W16
	.byte Fn1, v092 @ N08
	.byte W20
	.byte N06, Fn1, v052
	.byte W12
	.byte N08, Fn1, v124
	.byte W36
	.byte N06, Fn1, v052
	.byte W12
	.byte GOTO
		.word track_81_lbl_26a7ab
	.byte FINE

track_81_2:
	.byte KEYSH, 0
track_81_lbl_26a86e:
	.byte VOICE, 16
	.byte VOL, 90
	.byte PAN, c_v-4
	.byte PRIO, 108
	.byte N16, Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N16 @ Cs1, v116
	.byte W16
	.byte N18, Dn1 @ v116
	.byte W18
	.byte N14 @ Dn1, v116
	.byte W14
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
	.byte N16 @ Dn1, v116
	.byte W16
track_81_lbl_26a8a3:
	.byte N18, Ds1, v116
	.byte W18
	.byte N14 @ Ds1, v116
	.byte W14
	.byte N16 @ Ds1, v116
	.byte W16
	.byte N16 @ Ds1, v116
	.byte W16
	.byte N16 @ Ds1, v116
	.byte W16
	.byte N16 @ Ds1, v116
	.byte W16
	.byte PEND
	.byte PATT
		.word track_81_lbl_26a8a3
track_81_lbl_26a8b7:
	.byte N18, En1, v116
	.byte W18
	.byte N14 @ En1, v116
	.byte W14
	.byte N16 @ En1, v116
	.byte W16
	.byte N16 @ En1, v116
	.byte W16
	.byte N16 @ En1, v116
	.byte W16
	.byte N16 @ En1, v116
	.byte W16
	.byte PEND
	.byte PATT
		.word track_81_lbl_26a8b7
	.byte N18, Fn1, v116
	.byte W18
	.byte N14 @ Fn1, v116
	.byte W14
	.byte N16 @ Fn1, v116
	.byte W16
	.byte N16 @ Fn1, v116
	.byte W16
	.byte N16 @ Fn1, v116
	.byte W16
	.byte N16 @ Fn1, v116
	.byte W16
	.byte N16 @ Fn1, v116
	.byte W16
	.byte N16 @ Fn1, v116
	.byte W16
	.byte N12 @ Fn1, v116
	.byte W16
	.byte N10, Fn1, v127
	.byte W16
	.byte N10 @ Fn1, v127
	.byte W16
	.byte N10 @ Fn1, v127
	.byte W16
	.byte GOTO
		.word track_81_lbl_26a86e
	.byte FINE

track_81_3:
	.byte KEYSH, 0
track_81_lbl_26a8ef:
	.byte VOICE, 18
	.byte VOL, 21
	.byte PAN, c_v-8
	.byte PRIO, 1
	.byte N32, As3, v068
	.byte W32
	.byte N14, Bn3 @ v068
	.byte W16
	.byte N16, Cs4 @ v068
	.byte W16
	.byte Dn4 @ N16, v068
	.byte W16
	.byte Ds4 @ N16, v068
	.byte W16
	.byte Gn4 @ N16, v068
	.byte W16
	.byte Fs4 @ N16, v068
	.byte W16
	.byte Fn4 @ N16, v068
	.byte W16
	.byte N18, En4 @ v068
	.byte W18
	.byte N14, Fn4 @ v068
	.byte W14
	.byte N16, Fs4 @ v068
	.byte W16
	.byte Dn4 @ N16, v068
	.byte W16
	.byte Ds4 @ N16, v068
	.byte W16
	.byte En4 @ N16, v068
	.byte W16
	.byte Fs4 @ N16, v068
	.byte W16
	.byte Gn4 @ N16, v068
	.byte W16
	.byte Gs4 @ N16, v068
	.byte W16
	.byte N10, Bn4, v076
	.byte W16
	.byte As4 @ N10, v076
	.byte W16
	.byte An4 @ N10, v076
	.byte W16
	.byte N36, Cs5, v068
	.byte W36
	.byte N12, Dn5 @ v068
	.byte W12
	.byte N36, As4 @ v068
	.byte W36
	.byte N12, Bn4 @ v068
	.byte W12
	.byte W16
	.byte N20, Fn4 @ v068
	.byte W20
	.byte N12, Fs4 @ v068
	.byte W28
	.byte N20, Dn4 @ v068
	.byte W20
	.byte N12, Ds4 @ v068
	.byte W12
	.byte W16
	.byte N16, Cs4 @ v068
	.byte W16
	.byte N12, Cn4 @ v068
	.byte W32
	.byte N16, Ds4 @ v068
	.byte W16
	.byte N12, Dn4 @ v068
	.byte W16
	.byte W18
	.byte N14, Fs4 @ v068
	.byte W14
	.byte N12, Fn4 @ v068
	.byte W32
	.byte N16, An4 @ v068
	.byte W16
	.byte N12, Gs4 @ v068
	.byte W16
	.byte N36, As4 @ v068
	.byte W36
	.byte N12, Bn4 @ v068
	.byte W28
	.byte N16, As2 @ v068
	.byte W16
	.byte Bn2 @ N16, v068
	.byte W16
	.byte W16
	.byte As3 @ N16, v068
	.byte W16
	.byte Bn3 @ N16, v068
	.byte W16
	.byte N10, As3, v088
	.byte W16
	.byte N10 @ As3, v088
	.byte W16
	.byte Bn3 @ N10, v088
	.byte W16
	.byte GOTO
		.word track_81_lbl_26a8ef
	.byte FINE

track_81_4:
	.byte KEYSH, 0
track_81_lbl_26a97c:
	.byte VOICE, 0
	.byte VOL, 85
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, Dn1, v100
	.byte W24
	.byte N12, Cs2, v080
	.byte W24
	.byte N16, Dn1, v100
	.byte W16
	.byte N16 @ Dn1, v100
	.byte W16
	.byte Dn1, v092 @ N16
	.byte W16
	.byte N12, An1, v100
	.byte W16
	.byte N16, Gn1 @ v100
	.byte W16
	.byte Fn1 @ N16, v100
	.byte W16
	.byte N24, Dn1 @ v100
	.byte W24
	.byte N12, Cs2, v080
	.byte W24
	.byte N24, Dn1, v100
	.byte W24
	.byte N12, Cs2, v080
	.byte W24
	.byte N16, Dn1, v100
	.byte W16
	.byte Cs2, v080 @ N16
	.byte W16
	.byte N16 @ Cs2, v080
	.byte W16
	.byte N12, Dn1, v100
	.byte W12
	.byte Cs2, v080 @ N12
	.byte W12
	.byte Bn1, v120 @ N12
	.byte W12
	.byte Gn1 @ N12, v120
	.byte W12
	.byte N24, Dn1, v100
	.byte W24
	.byte N12, Cs2, v080
	.byte W24
	.byte N16, Dn1, v100
	.byte W16
	.byte Dn1, v120 @ N16
	.byte W16
	.byte N16 @ Dn1, v120
	.byte W16
	.byte N24, Dn1, v100
	.byte W18
	.byte N12, Cs2, v080
	.byte W14
	.byte N12 @ Cs2, v080
	.byte W16
	.byte N24, Dn1, v100
	.byte W24
	.byte N12, Cs2, v080
	.byte W24
	.byte N24, Dn1, v100
	.byte W32
	.byte N12, Cs2, v080
	.byte W16
	.byte N24, Dn1, v100
	.byte W32
	.byte N12, Cs2, v080
	.byte W16
	.byte N16, Dn1, v100
	.byte W16
	.byte N16 @ Dn1, v100
	.byte W16
	.byte N12, Cs2, v080
	.byte W16
	.byte N16, Dn1, v100
	.byte W16
	.byte Cs2, v060 @ N16
	.byte W16
	.byte N12, Dn1, v120
	.byte W16
	.byte N16, Dn1, v100
	.byte W18
	.byte N12, Cs2, v060
	.byte W18
	.byte Cs2, v080 @ N12
	.byte W12
	.byte N16, Cs2, v060
	.byte W16
	.byte Dn1, v100 @ N16
	.byte W16
	.byte Dn1, v120 @ N16
	.byte W16
	.byte Dn1, v092 @ N16
	.byte W16
	.byte Dn1, v100 @ N16
	.byte W16
	.byte Dn1, v120 @ N16
	.byte W16
	.byte N12, Dn1, v100
	.byte W12
	.byte Cs2, v060 @ N12
	.byte W12
	.byte N08 @ Cs2, v060
	.byte W08
	.byte Cs2, v072 @ N08
	.byte W08
	.byte Cs2, v080 @ N08
	.byte W08
	.byte GOTO
		.word track_81_lbl_26a97c
	.byte FINE

.align 2

track_81:
	.byte 5
	.byte 81
	.byte 130
	.byte 128
	.word 0x80a61fc
	.word track_81_0
	.word track_81_1
	.word track_81_2
	.word track_81_3
	.word track_81_4

.align 2
