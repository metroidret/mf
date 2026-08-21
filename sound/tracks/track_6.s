.align 2

.global track_6

track_6_0:
	.byte KEYSH, 0
track_6_lbl_259d92:
	.byte TEMPO, 42
	.byte PRIO, 110
	.byte W72
	.byte W72
	.byte W60
	.byte VOICE, 5
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N72, Gn1, v092
	.byte W12
	.byte W72
	.byte W18
	.byte VOICE, 8
	.byte VOL, 58
	.byte PAN, c_v-10
	.byte N48, Cn3, v080
	.byte W02
	.byte VOL, 50
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W04
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W09
	.byte 6 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W09
	.byte W72
	.byte W60
	.byte VOICE, 10
	.byte VOL, 47
	.byte N72, Fs3, v052
	.byte W12
	.byte W15
	.byte VOL, 44
	.byte W04
	.byte 40 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte W04
	.byte 34 @ VOL
	.byte W04
	.byte 31 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W04
	.byte 25 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W13
	.byte VOICE, 7
	.byte VOL, 39
	.byte PAN, c_v-4
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
track_6_lbl_259e1f:
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W12
	.byte N06, Gn3, v040
	.byte W06
	.byte N04, Gn3, v012
	.byte W06
	.byte N05, As3, v072
	.byte W06
	.byte N06, Dn4, v080
	.byte W06
	.byte PEND
track_6_lbl_259e44:
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PEND
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W12
	.byte N02 @ Gn3, v080
	.byte W02
	.byte Gn3, v072 @ N02
	.byte W02
	.byte Gn3, v052 @ N02
	.byte W02
	.byte Gn3, v040 @ N02
	.byte W02
	.byte Gn3, v032 @ N02
	.byte W02
	.byte N02 @ Gn3, v032
	.byte W02
	.byte N03 @ Gn3, v032
	.byte W03
	.byte N03 @ Gn3, v032
	.byte W03
	.byte N03 @ Gn3, v032
	.byte W03
	.byte N03 @ Gn3, v032
	.byte W03
	.byte PATT
		.word track_6_lbl_259e44
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W12
	.byte N06, Gn3, v012
	.byte W06
	.byte N04, Gn3, v040
	.byte W06
	.byte N05, As3, v072
	.byte W06
	.byte N06, Dn4, v080
	.byte W06
	.byte PATT
		.word track_6_lbl_259e44
	.byte PATT
		.word track_6_lbl_259e1f
	.byte VOICE, 10
	.byte VOL, 20
	.byte N48, Fs3, v052
	.byte W20
	.byte VOL, 23
	.byte W03
	.byte 26 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte N24, Gn3 @ v052
	.byte W24
	.byte N48, En3 @ v052
	.byte W01
	.byte VOL, 56
	.byte W07
	.byte 53 @ VOL
	.byte W08
	.byte 50 @ VOL
	.byte W08
	.byte 47 @ VOL
	.byte W04
	.byte 45 @ VOL
	.byte W04
	.byte 44 @ VOL
	.byte W04
	.byte 42 @ VOL
	.byte W04
	.byte 40 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte N24, Fs3 @ v052
	.byte W04
	.byte VOL, 36
	.byte W04
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W04
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte N72, Cs3 @ v052
	.byte W28
	.byte VOL, 31
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte N72, Dn3 @ v052
	.byte W30
	.byte W01
	.byte VOL, 61
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte VOICE, 2
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N08, Cs4, v076
	.byte W08
	.byte N05, Cs4, v060
	.byte W08
	.byte Cs4, v052 @ N05
	.byte W08
	.byte N05 @ Cs4, v052
	.byte W10
	.byte Cs4, v040 @ N05
	.byte W10
	.byte N12, Cs4, v016
	.byte W28
	.byte W72
	.byte VOICE, 10
	.byte VOL, 26
	.byte PAN, c_v-4
	.byte N48, Fs3, v052
	.byte W44
	.byte VOL, 29
	.byte W03
	.byte 31 @ VOL
	.byte W01
	.byte N24, Gn3 @ v052
	.byte W06
	.byte VOL, 34
	.byte W06
	.byte 37 @ VOL
	.byte W07
	.byte 40 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W02
	.byte N48, An3 @ v052
	.byte W02
	.byte VOL, 44
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W04
	.byte 50 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W04
	.byte 55 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W04
	.byte 59 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W07
	.byte N24, Bn3 @ v052
	.byte W24
	.byte N48, Cn4 @ v052
	.byte W32
	.byte W01
	.byte VOL, 61
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W02
	.byte N12, Bn3 @ v052
	.byte W01
	.byte VOL, 51
	.byte W02
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte N12, An3 @ v052
	.byte W02
	.byte VOL, 44
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte N48, Bn3 @ v052
	.byte W01
	.byte VOL, 40
	.byte W03
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte N24, Gn3 @ v052
	.byte W02
	.byte VOL, 40
	.byte W03
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
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W01
	.byte TIE, Gs3 @ v052
	.byte W03
	.byte VOL, 26
	.byte W05
	.byte 29 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W05
	.byte 36 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W32
	.byte W02
	.byte 39 @ VOL
	.byte W07
	.byte 36 @ VOL
	.byte W01
	.byte W08
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W44
	.byte W02
	.byte EOT @ Gs3, v052
	.byte N72, Dn3 @ v052
	.byte W40
	.byte W01
	.byte VOL, 28
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte N72 @ Dn3, v052
	.byte W01
	.byte VOL, 60
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W40
	.byte VOICE, 6
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04, Cs4, v096
	.byte W18
	.byte N04 @ Cs4, v096
	.byte W18
	.byte N06, Gs3, v060
	.byte W12
	.byte VOICE, 2
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N08, Cs4, v064
	.byte W08
	.byte N05, Cs4, v052
	.byte W08
	.byte Cs4, v040 @ N05
	.byte W08
	.byte N05 @ Cs4, v040
	.byte W10
	.byte Cs4, v032 @ N05
	.byte W10
	.byte N12, Cs4, v016
	.byte W52
	.byte VOICE, 10
	.byte PAN, c_v-4
	.byte VOL, 22
	.byte N48, Dn4, v040
	.byte W02
	.byte VOL, 25
	.byte W01
	.byte 27 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W24
	.byte W01
	.byte N12, Cs4 @ v040
	.byte W12
	.byte Bn3 @ N12, v040
	.byte W12
	.byte N48, Cs4 @ v040
	.byte W09
	.byte VOL, 58
	.byte W01
	.byte 57 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W04
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte N24, An3 @ v040
	.byte W01
	.byte VOL, 37
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte N48, Bn3, v048
	.byte W32
	.byte W01
	.byte VOL, 25
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
	.byte N24, Gn3 @ v048
	.byte W01
	.byte VOL, 34
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte N48, Bn3 @ v048
	.byte W02
	.byte VOL, 48
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W24
	.byte N24, Dn4, v040
	.byte W24
	.byte VOL, 15
	.byte N72, Fn4 @ v040
	.byte W04
	.byte VOL, 18
	.byte W05
	.byte 22 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W04
	.byte 34 @ VOL
	.byte W05
	.byte 37 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte 25 @ VOL
	.byte W06
	.byte 22 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte N72, Fs4 @ v040
	.byte W01
	.byte VOL, 7
	.byte W09
	.byte 11 @ VOL
	.byte W10
	.byte 14 @ VOL
	.byte W10
	.byte 17 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W05
	.byte 23 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W05
	.byte 26 @ VOL
	.byte W05
	.byte 28 @ VOL
	.byte W05
	.byte 29 @ VOL
	.byte W03
	.byte N72, Gn4 @ v040
	.byte W01
	.byte VOL, 31
	.byte W05
	.byte 33 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W05
	.byte 36 @ VOL
	.byte W05
	.byte 37 @ VOL
	.byte W05
	.byte 39 @ VOL
	.byte W04
	.byte 40 @ VOL
	.byte W05
	.byte 42 @ VOL
	.byte W05
	.byte 44 @ VOL
	.byte W05
	.byte 45 @ VOL
	.byte W05
	.byte 47 @ VOL
	.byte W05
	.byte 48 @ VOL
	.byte W04
	.byte 50 @ VOL
	.byte W05
	.byte 51 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W03
	.byte N72, Gs4 @ v040
	.byte W03
	.byte VOL, 51
	.byte W03
	.byte 50 @ VOL
	.byte W05
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W06
	.byte 42 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W05
	.byte 36 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte GOTO
		.word track_6_lbl_259d92
	.byte FINE

track_6_1:
	.byte KEYSH, 0
track_6_lbl_25a210:
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 109
	.byte N08, Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W54
	.byte N08 @ Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W54
	.byte N08 @ Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W54
	.byte N08 @ Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W54
	.byte N08 @ Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W42
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v040
	.byte W06
	.byte An3, v052 @ N03
	.byte W06
track_6_lbl_25a23b:
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte N06, Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W54
	.byte PEND
	.byte N06, Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W42
	.byte W01
	.byte VOICE, 7
	.byte VOL, 78
	.byte N04, Cs3, v080
	.byte W05
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v040
	.byte W06
track_6_lbl_25a261:
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte N06, Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W54
	.byte PEND
	.byte N08 @ Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W48
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v040
	.byte W06
	.byte PATT
		.word track_6_lbl_25a261
track_6_lbl_25a281:
	.byte N06, Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W42
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v040
	.byte W06
	.byte An3, v052 @ N03
	.byte W06
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a23b
track_6_lbl_25a29a:
	.byte N06, Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W48
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v040
	.byte W06
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a261
	.byte PATT
		.word track_6_lbl_25a281
	.byte PATT
		.word track_6_lbl_25a23b
	.byte PATT
		.word track_6_lbl_25a29a
	.byte PATT
		.word track_6_lbl_25a261
track_6_lbl_25a2c4:
	.byte N06, Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W54
	.byte PEND
	.byte N06 @ Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W54
	.byte PATT
		.word track_6_lbl_25a29a
	.byte PATT
		.word track_6_lbl_25a261
	.byte N06, Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W48
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v052
	.byte W06
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte N06, Cs1, v127
	.byte W18
	.byte N12 @ Cs1, v127
	.byte W48
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v052
	.byte W06
	.byte PATT
		.word track_6_lbl_25a23b
	.byte N06, Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W48
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3, v040
	.byte W06
	.byte PATT
		.word track_6_lbl_25a23b
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte VOICE, 10
	.byte VOL, 47
	.byte PAN, c_v+6
	.byte N72, Fs2, v044
	.byte W72
	.byte PATT
		.word track_6_lbl_25a23b
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte PATT
		.word track_6_lbl_25a2c4
track_6_lbl_25a33c:
	.byte N06, Cs1, v100
	.byte W18
	.byte N12 @ Cs1, v100
	.byte W54
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte PATT
		.word track_6_lbl_25a33c
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte PATT
		.word track_6_lbl_25a2c4
	.byte GOTO
		.word track_6_lbl_25a210
	.byte FINE

track_6_2:
	.byte KEYSH, 0
track_6_lbl_25a369:
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte PRIO, 108
	.byte N04, Cs3, v100
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11 @ Cs3, v020
	.byte W12
	.byte N04, Cs3, v127
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte Cs3, v052 @ N04
	.byte W12
	.byte Cs3, v127 @ N04
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W12
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte Cs3, v080 @ N04
	.byte W06
	.byte VOICE, 0
	.byte VOL, 55
	.byte N03, An3, v040
	.byte W06
	.byte VOICE, 7
	.byte VOL, 78
	.byte N04, Cs3, v127
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W12
	.byte N04, Cs3, v127
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W12
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W12
	.byte N04, Cs3, v127
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N06, Cs3, v052
	.byte W12
	.byte N04, Cs3, v127
	.byte W12
	.byte Cs3, v028 @ N04
	.byte W12
	.byte Cs3, v020 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W06
	.byte N04 @ Cs3, v020
	.byte W06
	.byte VOICE, 10
	.byte VOL, 47
	.byte PAN, c_v-4
	.byte N72, Cs3, v052
	.byte W12
	.byte W15
	.byte VOL, 75
	.byte W03
	.byte 72 @ VOL
	.byte W04
	.byte 68 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W04
	.byte 62 @ VOL
	.byte W05
	.byte 58 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W04
	.byte 51 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W04
	.byte 44 @ VOL
	.byte W04
	.byte 41 @ VOL
	.byte W04
	.byte 37 @ VOL
	.byte W16
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N04, Cs3, v127
	.byte W13
	.byte Cs3, v028 @ N04
	.byte W12
	.byte Cs3, v020 @ N04
	.byte W07
	.byte Cs3, v024 @ N04
	.byte W05
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W05
	.byte Cs3, v020 @ N04
	.byte W07
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N05, Cs3, v080
	.byte W11
track_6_lbl_25a48a:
	.byte N04, Cs3, v127
	.byte W13
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W07
	.byte Cs3, v024 @ N04
	.byte W05
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W05
	.byte Cs3, v020 @ N04
	.byte W07
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W11
	.byte PEND
track_6_lbl_25a4aa:
	.byte N04, Cs3, v127
	.byte W13
	.byte Cs3, v028 @ N04
	.byte W12
	.byte Cs3, v020 @ N04
	.byte W07
	.byte Cs3, v024 @ N04
	.byte W05
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W05
	.byte Cs3, v020 @ N04
	.byte W07
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W11
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a48a
	.byte PATT
		.word track_6_lbl_25a4aa
	.byte PATT
		.word track_6_lbl_25a48a
	.byte PATT
		.word track_6_lbl_25a4aa
	.byte PATT
		.word track_6_lbl_25a48a
	.byte VOICE, 10
	.byte VOL, 47
	.byte PAN, c_v+6
	.byte N48, Gs2, v052
	.byte W48
	.byte N24, An2, v040
	.byte W24
	.byte N48, Fs2, v052
	.byte W48
	.byte N24, Gs2 @ v052
	.byte W24
	.byte W72
	.byte W18
	.byte VOICE, 0
	.byte VOL, 47
	.byte PAN, c_v+16
	.byte N03, An3 @ v052
	.byte W54
	.byte W72
	.byte W72
	.byte VOICE, 10
	.byte VOL, 47
	.byte PAN, c_v+6
	.byte N48, Gs2, v040
	.byte W48
	.byte N24, An2, v056
	.byte W24
	.byte N48, Bn2 @ v056
	.byte W48
	.byte N24, Cs3, v064
	.byte W24
	.byte VOICE, 2
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N08, Cs4 @ v064
	.byte W08
	.byte N05, Cs4, v052
	.byte W08
	.byte Cs4, v040 @ N05
	.byte W08
	.byte N05 @ Cs4, v040
	.byte W10
	.byte Cs4, v032 @ N05
	.byte W10
	.byte N12, Cs4, v016
	.byte W28
	.byte VOICE, 10
	.byte VOL, 47
	.byte N72, Cn3, v036
	.byte W72
	.byte TIE, Fs3, v040
	.byte W72
	.byte W72
	.byte EOT @ Fs3, v040
	.byte W72
	.byte VOICE, 4
	.byte VOL, 100
	.byte PAN, c_v
	.byte N06, Cs1, v100
	.byte W18
	.byte N06 @ Cs1, v100
	.byte W06
	.byte VOICE, 0
	.byte VOL, 47
	.byte N06, Cs2, v048
	.byte W06
	.byte Cs2, v056 @ N06
	.byte W06
	.byte Cs2, v076 @ N06
	.byte W06
	.byte N06 @ Cs2, v076
	.byte W06
	.byte N04, Cs2, v092
	.byte W04
	.byte Cs2, v084 @ N04
	.byte W04
	.byte Cs2, v096 @ N04
	.byte W04
	.byte N04 @ Cs2, v096
	.byte W04
	.byte Cs2, v112 @ N04
	.byte W04
	.byte N24, Cs2, v127
	.byte W04
	.byte W72
	.byte W72
	.byte W48
	.byte VOICE, 2
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N08, Cs4, v064
	.byte W08
	.byte N05, Cs4, v052
	.byte W08
	.byte Cs4, v040 @ N05
	.byte W08
	.byte N05 @ Cs4, v040
	.byte W10
	.byte Cs4, v032 @ N05
	.byte W10
	.byte N12, Cs4, v016
	.byte W52
	.byte VOICE, 10
	.byte VOL, 47
	.byte TIE, An3, v052
	.byte W72
	.byte W48
	.byte EOT @ An3, v052
	.byte W24
	.byte VOICE, 6
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04, Cs4, v096
	.byte W18
	.byte N04 @ Cs4, v096
	.byte W18
	.byte N06, Gs3, v060
	.byte W36
	.byte N04, Dn4, v096
	.byte W18
	.byte N04 @ Dn4, v096
	.byte W18
	.byte N06, Gs3, v060
	.byte W36
	.byte N04, Ds4, v096
	.byte W18
	.byte N04 @ Ds4, v096
	.byte W18
	.byte Ds4, v084 @ N04
	.byte W18
	.byte N04 @ Ds4, v084
	.byte W18
	.byte En4, v096 @ N04
	.byte W18
	.byte En4, v076 @ N04
	.byte W18
	.byte N04 @ En4, v076
	.byte W36
	.byte GOTO
		.word track_6_lbl_25a369
	.byte FINE

track_6_3:
	.byte KEYSH, 0
track_6_lbl_25a5cb:
	.byte VOICE, 7
	.byte VOL, 39
	.byte PRIO, 0
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte PAN, c_v-4
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
track_6_lbl_25a5fe:
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W12
	.byte N06, Gn3, v040
	.byte W06
	.byte N04, Gn3, v012
	.byte W06
	.byte N05, As3, v072
	.byte W06
	.byte N06, Dn4, v080
	.byte W06
	.byte PEND
track_6_lbl_25a623:
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PEND
track_6_lbl_25a63f:
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W24
	.byte N01, Dn4, v060
	.byte W06
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PEND
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W07
	.byte N05, As3 @ v100
	.byte W06
	.byte As3, v072 @ N05
	.byte W06
	.byte N06, Gn3, v060
	.byte W12
	.byte PATT
		.word track_6_lbl_25a5fe
	.byte PATT
		.word track_6_lbl_25a623
	.byte N05, Gn3, v080
	.byte W05
	.byte N06, Gn3, v060
	.byte W06
	.byte N07, Gn3, v052
	.byte W24
	.byte W01
	.byte N10, Gn3, v092
	.byte W24
	.byte N01, As3, v060
	.byte W06
	.byte N06, Dn4, v100
	.byte W06
	.byte VOICE, 10
	.byte VOL, 47
	.byte N72, Dn3, v044
	.byte W72
	.byte VOICE, 7
	.byte VOL, 39
	.byte PAN, c_v-4
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PATT
		.word track_6_lbl_25a623
	.byte PATT
		.word track_6_lbl_25a63f
	.byte PATT
		.word track_6_lbl_25a623
	.byte PATT
		.word track_6_lbl_25a5fe
	.byte PATT
		.word track_6_lbl_25a5fe
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N06, Dn4, v060
	.byte W06
	.byte N07, Dn4, v100
	.byte W07
	.byte N01, Dn4, v060
	.byte W06
	.byte N06, Gn3, v100
	.byte W12
	.byte VOICE, 10
	.byte VOL, 47
	.byte PAN, c_v+6
	.byte N72, An3, v056
	.byte W72
	.byte Gs3 @ N72, v056
	.byte W72
	.byte VOICE, 7
	.byte VOL, 39
	.byte PAN, c_v-4
	.byte N12, Dn4, v127
	.byte W12
	.byte N18, Gn3, v108
	.byte W18
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PATT
		.word track_6_lbl_25a63f
	.byte VOICE, 10
	.byte VOL, 47
	.byte PAN, c_v+6
	.byte N72, Bn3, v048
	.byte W72
	.byte Cn4, v036 @ N72
	.byte W72
	.byte Cs4, v028 @ N72
	.byte W72
	.byte Dn4 @ N72, v028
	.byte W72
	.byte GOTO
		.word track_6_lbl_25a5cb
	.byte FINE

track_6_4:
	.byte KEYSH, 0
track_6_lbl_25a74a:
	.byte PRIO, 0
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v+6
	.byte N04, Cs3, v127
	.byte W13
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W07
	.byte Cs3, v024 @ N04
	.byte W05
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W05
	.byte Cs3, v020 @ N04
	.byte W07
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W11
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
track_6_lbl_25a780:
	.byte N04, Cs3, v127
	.byte W13
	.byte Cs3, v028 @ N04
	.byte W12
	.byte Cs3, v020 @ N04
	.byte W07
	.byte Cs3, v024 @ N04
	.byte W05
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W05
	.byte Cs3, v020 @ N04
	.byte W07
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W11
	.byte PEND
track_6_lbl_25a79d:
	.byte N04, Cs3, v127
	.byte W13
	.byte Cs3, v028 @ N04
	.byte W06
	.byte Cs3, v024 @ N04
	.byte W06
	.byte Cs3, v020 @ N04
	.byte W07
	.byte Cs3, v024 @ N04
	.byte W05
	.byte Cs3, v044 @ N04
	.byte W06
	.byte Cs3, v036 @ N04
	.byte W05
	.byte Cs3, v020 @ N04
	.byte W07
	.byte N04 @ Cs3, v020
	.byte W06
	.byte N11, Cs3, v080
	.byte W11
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte PATT
		.word track_6_lbl_25a780
	.byte PATT
		.word track_6_lbl_25a79d
	.byte GOTO
		.word track_6_lbl_25a74a
	.byte FINE

track_6_5:
	.byte KEYSH, 0
track_6_lbl_25a833:
	.byte VOICE, 7
	.byte VOL, 55
	.byte PAN, c_v+10
	.byte PRIO, 0
	.byte N03, Cn3, v072
	.byte W24
	.byte Cn3, v032 @ N03
	.byte W24
	.byte Cn3, v028 @ N03
	.byte W24
track_6_lbl_25a845:
	.byte N03, Cn3, v072
	.byte W24
	.byte Cn3, v032 @ N03
	.byte W24
	.byte Cn3, v024 @ N03
	.byte W24
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte VOICE, 7
	.byte VOL, 39
	.byte PAN, c_v-4
	.byte N12, Dn4, v127
	.byte W12
	.byte N18, Gn3, v108
	.byte W18
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
track_6_lbl_25a8df:
	.byte VOICE, 7
	.byte VOL, 55
	.byte PAN, c_v+10
	.byte N03, Cn3, v072
	.byte W24
	.byte Cn3, v032 @ N03
	.byte W24
	.byte Cn3, v024 @ N03
	.byte W24
	.byte PEND
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte PATT
		.word track_6_lbl_25a845
	.byte VOICE, 7
	.byte VOL, 39
	.byte PAN, c_v-4
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W12
	.byte N06, Gn3, v040
	.byte W06
	.byte N04, Gn3, v012
	.byte W06
	.byte N05, As3, v072
	.byte W06
	.byte N06, Dn4, v080
	.byte W06
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N06, Dn4, v060
	.byte W06
	.byte N07, Dn4, v100
	.byte W07
	.byte N01, Dn4, v060
	.byte W06
	.byte N06, Gn3, v100
	.byte W12
	.byte PATT
		.word track_6_lbl_25a8df
	.byte PATT
		.word track_6_lbl_25a845
	.byte VOICE, 7
	.byte VOL, 39
	.byte PAN, c_v-4
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
track_6_lbl_25a983:
	.byte N11, Dn4, v127
	.byte W11
	.byte N18, Gn3, v108
	.byte W19
	.byte N06, Gn3, v032
	.byte W06
	.byte N05, As3, v108
	.byte W05
	.byte N12, Dn4, v100
	.byte W13
	.byte N01, Dn4, v060
	.byte W12
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PEND
	.byte N05, As3, v080
	.byte W05
	.byte N06, As3, v108
	.byte W06
	.byte N07, Dn4, v092
	.byte W07
	.byte N06, Dn4, v072
	.byte W18
	.byte N10, Gn3, v080
	.byte W24
	.byte N01, Dn4, v060
	.byte W06
	.byte N06, Gn3 @ v060
	.byte W06
	.byte PATT
		.word track_6_lbl_25a983
	.byte GOTO
		.word track_6_lbl_25a833
	.byte FINE

track_6_6:
	.byte KEYSH, 0
track_6_lbl_25a9c7:
	.byte PRIO, 110
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 1
	.byte VOL, 55
	.byte PAN, c_v
	.byte N48, Cs3, v040
	.byte W48
	.byte N24, Dn3, v032
	.byte W24
	.byte N48, Bn2, v040
	.byte W48
	.byte N24, Cs3 @ v040
	.byte W24
	.byte N72, Gs2 @ v040
	.byte W72
	.byte An2 @ N72, v040
	.byte W72
	.byte W72
	.byte W72
	.byte N48, Cs3 @ v040
	.byte W48
	.byte N24, Dn3, v044
	.byte W24
	.byte N48, En3 @ v044
	.byte W48
	.byte N24, Fs3 @ v044
	.byte W24
	.byte N72, Gn3 @ v044
	.byte W72
	.byte Fn3, v036 @ N72
	.byte W72
	.byte Cs3 @ N72, v036
	.byte W72
	.byte Dn3, v052 @ N72
	.byte W72
	.byte Bn2, v036 @ N72
	.byte W72
	.byte Cn3 @ N72, v036
	.byte W72
	.byte W72
	.byte W72
	.byte Gn3 @ N72, v036
	.byte W72
	.byte Fs3 @ N72, v036
	.byte W72
	.byte Dn3 @ N72, v036
	.byte W72
	.byte Fn3, v040 @ N72
	.byte W72
	.byte Cs4, v048 @ N72
	.byte W72
	.byte Dn4, v036 @ N72
	.byte W72
	.byte Ds4 @ N72, v036
	.byte W72
	.byte En4 @ N72, v036
	.byte W72
	.byte GOTO
		.word track_6_lbl_25a9c7
	.byte FINE

track_6_7:
	.byte KEYSH, 0
track_6_lbl_25aa2f:
	.byte PRIO, 30
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 3
	.byte VOL, 78
	.byte PAN, c_v
	.byte N04, Bn3, v072
	.byte W18
	.byte N04 @ Bn3, v072
	.byte W54
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte N04 @ Bn3, v072
	.byte W18
	.byte N04 @ Bn3, v072
	.byte W54
	.byte Cn4 @ N04, v072
	.byte W18
	.byte N04 @ Cn4, v072
	.byte W54
	.byte Cs4 @ N04, v072
	.byte W18
	.byte N04 @ Cs4, v072
	.byte W18
	.byte Cs4, v084 @ N04
	.byte W18
	.byte N04 @ Cs4, v084
	.byte W18
	.byte Dn4, v072 @ N04
	.byte W18
	.byte Dn4, v052 @ N04
	.byte W18
	.byte N04 @ Dn4, v052
	.byte W36
	.byte GOTO
		.word track_6_lbl_25aa2f
	.byte FINE

.align 2

track_6:
	.byte 8
	.byte 6
	.byte 130
	.byte 128
	.word 0x80a5b3c
	.word track_6_0
	.word track_6_1
	.word track_6_2
	.word track_6_3
	.word track_6_4
	.word track_6_5
	.word track_6_6
	.word track_6_7

.align 2
