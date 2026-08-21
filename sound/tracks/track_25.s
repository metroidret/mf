.align 2

.global track_25

track_25_0:
	.byte KEYSH, 0
	.byte TEMPO, 85
	.byte VOICE, 2
	.byte MOD, 6
	.byte VOL, 96
	.byte PAN, c_v
	.byte LFODL, 40
	.byte PRIO, 110
	.byte N36, Bn3, v072
	.byte W01
	.byte VOL, 94
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte N56, Dn4, v120
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte W01
	.byte 17 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W02
	.byte W72
track_25_lbl_26085b:
	.byte VOICE, 6
	.byte MOD, 0
	.byte VOL, 94
	.byte LFOS, 0
	.byte LFODL, 0
	.byte N06, Fn3, v072
	.byte W36
	.byte Fn3, v080 @ N06
	.byte W36
	.byte Fn3, v064 @ N06
	.byte W24
track_25_lbl_26086f:
	.byte W12
	.byte N06, Fn3, v064
	.byte W36
	.byte N06 @ Fn3, v064
	.byte W12
	.byte N30, Fs3, v080
	.byte W12
	.byte VOL, 47
	.byte W06
	.byte 37 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W06
	.byte PEND
track_25_lbl_260884:
	.byte VOL, 94
	.byte N06, Fn3, v064
	.byte W36
	.byte Fn3, v052 @ N06
	.byte W36
	.byte N06 @ Fn3, v052
	.byte W24
	.byte PEND
track_25_lbl_260890:
	.byte W12
	.byte N06, Fn3, v052
	.byte W36
	.byte N18, Fn3, v080
	.byte W24
	.byte En3 @ N18, v080
	.byte W24
	.byte PEND
track_25_lbl_26089c:
	.byte N06, Fn3, v064
	.byte W36
	.byte Fn3, v052 @ N06
	.byte W36
	.byte N06 @ Fn3, v052
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_26086f
	.byte PATT
		.word track_25_lbl_260884
track_25_lbl_2608b0:
	.byte W12
	.byte N30, Fs3, v092
	.byte W06
	.byte VOL, 37
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W12
	.byte 94 @ VOL
	.byte N12, Gn3, v056
	.byte W16
	.byte Gs3, v092 @ N12
	.byte W16
	.byte An3, v112 @ N12
	.byte W16
	.byte PEND
track_25_lbl_2608ca:
	.byte VOICE, 2
	.byte MOD, 1
	.byte VOL, 47
	.byte LFOS, 100
	.byte LFODL, 20
	.byte N72, As4, v056
	.byte W72
	.byte N24, An4 @ v056
	.byte W24
	.byte PEND
track_25_lbl_2608dc:
	.byte N72, Cs4, v064
	.byte W72
	.byte N24, Cn4 @ v064
	.byte W24
	.byte PEND
track_25_lbl_2608e4:
	.byte N72, Bn3, v056
	.byte W72
	.byte N24, Cn4 @ v056
	.byte W24
	.byte PEND
track_25_lbl_2608ec:
	.byte N48, As3, v056
	.byte W48
	.byte N24, Fn3, v072
	.byte W48
	.byte PEND
track_25_lbl_2608f5:
	.byte N72, Bn4, v056
	.byte W72
	.byte N24, As4 @ v056
	.byte W24
	.byte PEND
track_25_lbl_2608fd:
	.byte N72, Dn4, v060
	.byte W72
	.byte N24, Cs4, v072
	.byte W24
	.byte PEND
track_25_lbl_260906:
	.byte N72, Cn4, v068
	.byte W72
	.byte N24, Cs4, v080
	.byte W24
	.byte PEND
track_25_lbl_26090f:
	.byte N48, As3, v072
	.byte W48
	.byte N24, En4 @ v072
	.byte W48
	.byte PEND
track_25_lbl_260917:
	.byte N10, En2, v120
	.byte W16
	.byte Fn2 @ N10, v120
	.byte W16
	.byte Fs2 @ N10, v120
	.byte W16
	.byte Gn2 @ N10, v120
	.byte W16
	.byte Fs2 @ N10, v120
	.byte W16
	.byte Fn2 @ N10, v120
	.byte W16
	.byte PEND
track_25_lbl_260926:
	.byte N10, Fs2, v112
	.byte W16
	.byte Gn2 @ N10, v112
	.byte W16
	.byte Gs2 @ N10, v112
	.byte W16
	.byte An2 @ N10, v112
	.byte W16
	.byte Gs2 @ N10, v112
	.byte W16
	.byte Gn2 @ N10, v112
	.byte W16
	.byte PEND
track_25_lbl_260935:
	.byte N10, Gs2, v112
	.byte W16
	.byte An2 @ N10, v112
	.byte W16
	.byte As2 @ N10, v112
	.byte W16
	.byte Bn2 @ N10, v112
	.byte W16
	.byte As2 @ N10, v112
	.byte W16
	.byte An2 @ N10, v112
	.byte W16
	.byte PEND
track_25_lbl_260944:
	.byte N12, As2, v120
	.byte W12
	.byte Bn2 @ N12, v120
	.byte W12
	.byte Cn3 @ N12, v120
	.byte W12
	.byte Cs3 @ N12, v120
	.byte W12
	.byte N08, Bn2 @ v120
	.byte W08
	.byte Cn3 @ N08, v120
	.byte W08
	.byte Cs3 @ N08, v120
	.byte W08
	.byte Dn3 @ N08, v120
	.byte W08
	.byte Ds3 @ N08, v120
	.byte W08
	.byte En3 @ N08, v120
	.byte W08
	.byte PEND
	.byte VOICE, 6
	.byte MOD, 6
	.byte VOL, 81
	.byte LFOS, 0
	.byte LFODL, 40
	.byte N06, Fn3, v072
	.byte W36
	.byte Fn3, v080 @ N06
	.byte W36
	.byte Fn3, v064 @ N06
	.byte W24
	.byte PATT
		.word track_25_lbl_26086f
	.byte PATT
		.word track_25_lbl_260884
	.byte PATT
		.word track_25_lbl_260890
	.byte PATT
		.word track_25_lbl_26089c
	.byte PATT
		.word track_25_lbl_26086f
	.byte PATT
		.word track_25_lbl_260884
	.byte PATT
		.word track_25_lbl_2608b0
	.byte PATT
		.word track_25_lbl_2608ca
	.byte PATT
		.word track_25_lbl_2608dc
	.byte PATT
		.word track_25_lbl_2608e4
	.byte PATT
		.word track_25_lbl_2608ec
	.byte PATT
		.word track_25_lbl_2608f5
	.byte PATT
		.word track_25_lbl_2608fd
	.byte PATT
		.word track_25_lbl_260906
	.byte PATT
		.word track_25_lbl_26090f
	.byte PATT
		.word track_25_lbl_260917
	.byte PATT
		.word track_25_lbl_260926
	.byte PATT
		.word track_25_lbl_260935
	.byte PATT
		.word track_25_lbl_260944
	.byte VOICE, 2
	.byte MOD, 1
	.byte VOL, 47
	.byte LFOS, 100
	.byte LFODL, 20
	.byte TIE, Fn4, v052
	.byte W96
	.byte W24
	.byte EOT @ Fn4, v052
	.byte W24
	.byte N16, Fs4 @ v052
	.byte W16
	.byte N06, Fn4, v040
	.byte W16
	.byte En4 @ N06, v040
	.byte W16
	.byte N96, Ds4 @ v040
	.byte W96
	.byte W48
	.byte N16, En4, v052
	.byte W16
	.byte N06, Fn4 @ v052
	.byte W16
	.byte Fs4 @ N06, v052
	.byte W16
	.byte TIE, Gn4, v040
	.byte W96
	.byte W24
	.byte EOT @ Gn4, v040
	.byte W24
	.byte N16, Gs4, v052
	.byte W16
	.byte N06, Gn4, v040
	.byte W16
	.byte Fs4 @ N06, v040
	.byte W16
	.byte N96, Fn4 @ v040
	.byte W96
	.byte W12
	.byte N30, Fs4, v052
	.byte W36
	.byte N16, Gn4, v060
	.byte W16
	.byte N06, Gs4 @ v060
	.byte W16
	.byte An4 @ N06, v060
	.byte W16
	.byte N08, As4, v092
	.byte W36
	.byte N08 @ As4, v092
	.byte W36
	.byte N12, An4 @ v092
	.byte W12
	.byte N08, As4 @ v092
	.byte W12
	.byte W96
	.byte Bn4 @ N08, v092
	.byte W36
	.byte N08 @ Bn4, v092
	.byte W36
	.byte N06 @ Bn4, v092
	.byte W12
	.byte N48, Cn5 @ v092
	.byte W12
	.byte W48
	.byte N16 @ Cn5, v092
	.byte W16
	.byte Cs5 @ N16, v092
	.byte W16
	.byte N08, Dn5 @ v092
	.byte W16
	.byte GOTO
		.word track_25_lbl_26085b
	.byte FINE

track_25_1:
	.byte KEYSH, 0
	.byte PAN, c_v+10
	.byte PRIO, 109
	.byte W24
	.byte VOICE, 2
	.byte W05
	.byte VOL, 49
	.byte N66, Cs4, v072
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W08
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W04
	.byte 24 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte W72
track_25_lbl_260aa2:
	.byte VOICE, 0
	.byte VOL, 120
	.byte N06, Fs1, v040
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v092
	.byte W19
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v076
	.byte W19
	.byte N04, Fs1, v016
	.byte W05
track_25_lbl_260ad6:
	.byte N06, Fs1, v040
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v076
	.byte W24
	.byte N03, Dn1, v052
	.byte W04
	.byte N04, Dn1, v020
	.byte W08
	.byte N10, Dn1, v092
	.byte W12
	.byte N04 @ Dn1, v092
	.byte W06
	.byte Dn1, v080 @ N04
	.byte W06
	.byte Dn1, v060 @ N04
	.byte W04
	.byte Dn1, v052 @ N04
	.byte W04
	.byte Dn1, v040 @ N04
	.byte W04
	.byte Dn1, v032 @ N04
	.byte W04
	.byte Dn1, v020 @ N04
	.byte W04
	.byte N02 @ Dn1, v020
	.byte W04
	.byte PEND
track_25_lbl_260b05:
	.byte N06, Fs1, v040
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v092
	.byte W19
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v076
	.byte W19
	.byte N04, Fs1, v016
	.byte W05
	.byte PEND
track_25_lbl_260b36:
	.byte N06, Fs1, v040
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, Cs2, v100
	.byte W24
	.byte N06, Fn1, v096
	.byte W04
	.byte N03, Dn1, v020
	.byte W08
	.byte N06, Bn1, v092
	.byte W06
	.byte Bn1, v096 @ N06
	.byte W06
	.byte An1, v056 @ N06
	.byte W06
	.byte An1, v052 @ N06
	.byte W06
	.byte Gn1, v048 @ N06
	.byte W06
	.byte Gn1, v056 @ N06
	.byte W06
	.byte Fn1, v032 @ N06
	.byte W06
	.byte Fn1, v036 @ N06
	.byte W06
	.byte PEND
	.byte PATT
		.word track_25_lbl_260b05
	.byte PATT
		.word track_25_lbl_260ad6
	.byte PATT
		.word track_25_lbl_260b05
track_25_lbl_260b73:
	.byte N07, Fs1, v040
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, Cs2, v092
	.byte W36
	.byte N15, Cs2, v120
	.byte W16
	.byte N12, Cs2, v080
	.byte W16
	.byte Fn1 @ N12, v080
	.byte W16
	.byte PEND
track_25_lbl_260b8a:
	.byte VOICE, 5
	.byte N06, Cn1, v120
	.byte W12
	.byte N04 @ Cn1, v120
	.byte W12
	.byte VOICE, 0
	.byte N12, En1, v088
	.byte W12
	.byte An2, v100 @ N12
	.byte W24
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 0
	.byte N04, Dn1, v032
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte PEND
track_25_lbl_260bae:
	.byte W12
	.byte N04, Cn1, v120
	.byte W12
	.byte N04 @ Cn1, v120
	.byte W12
	.byte Ds1, v052 @ N04
	.byte W48
	.byte VOICE, 5
	.byte N04 @ Ds1, v052
	.byte W12
	.byte PEND
track_25_lbl_260bbd:
	.byte VOICE, 5
	.byte N06, Cn1, v120
	.byte W12
	.byte N04 @ Cn1, v120
	.byte W12
	.byte VOICE, 0
	.byte N12, En1, v088
	.byte W12
	.byte An2, v100 @ N12
	.byte W24
	.byte VOICE, 5
	.byte N04, Ds1, v032
	.byte W12
	.byte VOICE, 0
	.byte N04, Dn1 @ v032
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1 @ v032
	.byte W12
	.byte PEND
track_25_lbl_260bdf:
	.byte W12
	.byte VOICE, 0
	.byte N04, Cn1, v120
	.byte W12
	.byte N04 @ Cn1, v120
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 0
	.byte N12, An1, v112
	.byte W12
	.byte Gn1, v096 @ N12
	.byte W12
	.byte Gn1, v072 @ N12
	.byte W12
	.byte Fn1, v032 @ N12
	.byte W12
	.byte PEND
	.byte PATT
		.word track_25_lbl_260b8a
track_25_lbl_260c03:
	.byte W12
	.byte N04, Cn1, v120
	.byte W12
	.byte N04 @ Cn1, v120
	.byte W72
	.byte PEND
track_25_lbl_260c0b:
	.byte VOICE, 5
	.byte N04, Cn1, v120
	.byte W12
	.byte N04 @ Cn1, v120
	.byte W12
	.byte VOICE, 0
	.byte N12, En1, v088
	.byte W12
	.byte An2, v100 @ N12
	.byte W24
	.byte N04, Ds1, v032
	.byte W12
	.byte Dn1 @ N04, v032
	.byte W12
	.byte Ds1 @ N04, v032
	.byte W12
	.byte PEND
track_25_lbl_260c25:
	.byte VOICE, 0
	.byte W12
	.byte N06, Cs2, v112
	.byte W36
	.byte N15, Cs2, v092
	.byte W16
	.byte N08, An1, v100
	.byte W16
	.byte Fn1, v120 @ N08
	.byte W16
	.byte PEND
track_25_lbl_260c38:
	.byte W48
	.byte N12, Cs2, v040
	.byte W48
	.byte PEND
track_25_lbl_260c3e:
	.byte N08, Fn1, v120
	.byte W16
	.byte N08 @ Fn1, v120
	.byte W32
	.byte N12, Cs2, v072
	.byte W48
	.byte PEND
track_25_lbl_260c49:
	.byte N08, Fn1, v108
	.byte W16
	.byte Fn1, v096 @ N08
	.byte W20
	.byte N06 @ Fn1, v096
	.byte W12
	.byte N12, Cs2, v100
	.byte W48
	.byte PEND
track_25_lbl_260c57:
	.byte N12, Cs2, v064
	.byte W24
	.byte N04 @ Cs2, v064
	.byte W12
	.byte Cs2, v080 @ N04
	.byte W12
	.byte N08, Cs2, v072
	.byte W08
	.byte N08 @ Cs2, v072
	.byte W08
	.byte Cs2, v084 @ N08
	.byte W08
	.byte N06, Cs2, v072
	.byte W06
	.byte Cs2, v084 @ N06
	.byte W06
	.byte Cs2, v092 @ N06
	.byte W06
	.byte Cs2, v104 @ N06
	.byte W06
	.byte PEND
	.byte VOICE, 0
	.byte VOL, 81
	.byte N06, Fs1, v040
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v092
	.byte W19
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N06, Fs1, v020
	.byte W07
	.byte N05, Fs1, v016
	.byte W05
	.byte N12, An2, v076
	.byte W19
	.byte N04, Fs1, v016
	.byte W05
	.byte PATT
		.word track_25_lbl_260ad6
	.byte PATT
		.word track_25_lbl_260b05
	.byte PATT
		.word track_25_lbl_260b36
	.byte PATT
		.word track_25_lbl_260b05
	.byte PATT
		.word track_25_lbl_260ad6
	.byte PATT
		.word track_25_lbl_260b05
	.byte PATT
		.word track_25_lbl_260b73
	.byte PATT
		.word track_25_lbl_260b8a
	.byte PATT
		.word track_25_lbl_260bae
	.byte PATT
		.word track_25_lbl_260bbd
	.byte PATT
		.word track_25_lbl_260bdf
	.byte PATT
		.word track_25_lbl_260b8a
	.byte PATT
		.word track_25_lbl_260c03
	.byte PATT
		.word track_25_lbl_260c0b
	.byte PATT
		.word track_25_lbl_260c25
	.byte PATT
		.word track_25_lbl_260c38
	.byte PATT
		.word track_25_lbl_260c3e
	.byte PATT
		.word track_25_lbl_260c49
	.byte PATT
		.word track_25_lbl_260c57
	.byte VOICE, 5
	.byte VOL, 120
	.byte N06, Cn1, v100
	.byte W24
	.byte VOICE, 0
	.byte N12, En1, v052
	.byte W12
	.byte An2, v100 @ N12
	.byte W24
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 0
	.byte N04, Dn1, v032
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
track_25_lbl_260d2d:
	.byte VOICE, 5
	.byte N06, Cn1, v100
	.byte W12
	.byte N04 @ Cn1, v100
	.byte W12
	.byte VOICE, 0
	.byte N12, En1, v052
	.byte W12
	.byte An2, v100 @ N12
	.byte W24
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 0
	.byte N04, Dn1, v032
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte PEND
	.byte VOICE, 5
	.byte N06, Cn1, v100
	.byte W24
	.byte VOICE, 0
	.byte N12, En1, v052
	.byte W12
	.byte An2, v100 @ N12
	.byte W24
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 0
	.byte N04, Dn1, v032
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 5
	.byte N06, Cn1, v100
	.byte W12
	.byte VOICE, 0
	.byte N12, En1, v088, 57
	.byte En6 @ N12, v088
	.byte W24
	.byte N06, Bn1, v092
	.byte W18
	.byte Bn1, v096 @ N06
	.byte W10
	.byte An1, v052 @ N06
	.byte W08
	.byte Gn1, v048 @ N06
	.byte W08
	.byte Gn1, v056 @ N06
	.byte W16
	.byte PATT
		.word track_25_lbl_260d2d
	.byte PATT
		.word track_25_lbl_260d2d
	.byte PATT
		.word track_25_lbl_260d2d
	.byte VOICE, 0
	.byte W12
	.byte N06, Cs2, v112
	.byte W36
	.byte N12, En1, v060
	.byte W16
	.byte N08 @ En1, v060
	.byte W16
	.byte N08 @ En1, v060
	.byte W16
	.byte W96
	.byte N12, En1, v084
	.byte W12
	.byte Cn1 @ N12, v084
	.byte W12
	.byte Cn1, v088 @ N12
	.byte W12
	.byte N06, En1, v084
	.byte W06
	.byte N18, Cs2, v068
	.byte W22
	.byte N04, En1, v044
	.byte W07
	.byte N04 @ En1, v044
	.byte W06
	.byte N04 @ En1, v044
	.byte W06
	.byte N04 @ En1, v044
	.byte W05
	.byte N04 @ En1, v044
	.byte W08
	.byte VOICE, 5
	.byte N06, Cn1, v100
	.byte W24
	.byte VOICE, 0
	.byte W12
	.byte N12, En1, v040
	.byte W36
	.byte VOICE, 0
	.byte N04, Dn1, v032
	.byte W12
	.byte VOICE, 5
	.byte N04, Ds1, v052
	.byte W12
	.byte VOICE, 0
	.byte N06, En1, v060
	.byte W12
	.byte Dn1, v032 @ N06
	.byte W12
	.byte Dn1, v060 @ N06
	.byte W12
	.byte Dn1, v080 @ N06
	.byte W12
	.byte N08, En1, v100
	.byte W16
	.byte N08 @ En1, v100
	.byte W16
	.byte N08 @ En1, v100
	.byte W16
	.byte GOTO
		.word track_25_lbl_260aa2
	.byte FINE

track_25_2:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte PRIO, 108
	.byte W20
	.byte VOICE, 2
	.byte VOL, 64
	.byte N76, As3, v072
	.byte W01
	.byte VOL, 62
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte W02
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte W72
track_25_lbl_260e80:
	.byte VOICE, 3
	.byte VOL, 94
	.byte N06, Gn0, v112
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte Gn0, v127 @ N06
	.byte W12
	.byte N06 @ Gn0, v127
	.byte W12
	.byte N06 @ Gn0, v127
	.byte W12
	.byte Gn0, v112 @ N06
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte PEND
track_25_lbl_260e99:
	.byte N06, Gn0, v112
	.byte W12
	.byte Gn0, v100 @ N06
	.byte W12
	.byte Gn0, v092 @ N06
	.byte W12
	.byte N06 @ Gn0, v092
	.byte W12
	.byte Gn0, v116 @ N06
	.byte W12
	.byte N24, Gs0, v127
	.byte W24
	.byte N06, Gn0, v112
	.byte W12
	.byte PEND
track_25_lbl_260eb1:
	.byte N06, Gn0, v112
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte Gn0, v127 @ N06
	.byte W12
	.byte N06 @ Gn0, v127
	.byte W12
	.byte N06 @ Gn0, v127
	.byte W12
	.byte Gn0, v112 @ N06
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte PEND
track_25_lbl_260ec6:
	.byte N06, Gn0, v112
	.byte W12
	.byte N12, Gn0, v120
	.byte W36
	.byte N18, Gn0, v116
	.byte W24
	.byte Fs0, v100 @ N18
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_260e80
	.byte PATT
		.word track_25_lbl_260e99
	.byte PATT
		.word track_25_lbl_260eb1
track_25_lbl_260ee5:
	.byte W12
	.byte N24, Gs0, v112
	.byte W36
	.byte N15, Gn1, v076
	.byte W16
	.byte N12, Gn1, v112
	.byte W16
	.byte Gn1, v127 @ N12
	.byte W16
	.byte PEND
track_25_lbl_260ef6:
	.byte N20, Cs1, v100
	.byte W36
	.byte N42 @ Cs1, v100
	.byte W60
	.byte PEND
	.byte N20 @ Cs1, v100
	.byte W36
	.byte N42 @ Cs1, v100
	.byte W60
track_25_lbl_260f01:
	.byte N17, Dn1, v100
	.byte W36
	.byte N42 @ Dn1, v100
	.byte W60
	.byte PEND
track_25_lbl_260f08:
	.byte N17, Dn1, v100
	.byte W36
	.byte N44 @ Dn1, v100
	.byte W60
	.byte PEND
track_25_lbl_260f0f:
	.byte N20, Ds1, v092
	.byte W36
	.byte N44, Ds1, v100
	.byte W60
	.byte PEND
	.byte PATT
		.word track_25_lbl_260f0f
track_25_lbl_260f1d:
	.byte N20, En1, v092
	.byte W36
	.byte N44, En1, v100
	.byte W60
	.byte PEND
track_25_lbl_260f26:
	.byte W12
	.byte N24, En1, v092
	.byte W36
	.byte N36, En1, v100
	.byte W48
	.byte PEND
track_25_lbl_260f30:
	.byte N10, Cn1, v120
	.byte W16
	.byte Cs1 @ N10, v120
	.byte W16
	.byte Dn1 @ N10, v120
	.byte W16
	.byte Ds1 @ N10, v120
	.byte W16
	.byte Dn1 @ N10, v120
	.byte W16
	.byte Cs1 @ N10, v120
	.byte W16
	.byte PEND
track_25_lbl_260f3f:
	.byte N10, Dn1, v120
	.byte W16
	.byte Ds1 @ N10, v120
	.byte W16
	.byte En1 @ N10, v120
	.byte W16
	.byte Fn1 @ N10, v120
	.byte W16
	.byte En1 @ N10, v120
	.byte W16
	.byte Ds1 @ N10, v120
	.byte W16
	.byte PEND
track_25_lbl_260f4e:
	.byte N10, En1, v112
	.byte W16
	.byte Fn1 @ N10, v112
	.byte W16
	.byte Fs1 @ N10, v112
	.byte W16
	.byte Gn1 @ N10, v112
	.byte W16
	.byte Fs1 @ N10, v112
	.byte W16
	.byte Fn1 @ N10, v112
	.byte W16
	.byte PEND
track_25_lbl_260f5d:
	.byte N12, Fs1, v112
	.byte W12
	.byte Gn1 @ N12, v112
	.byte W12
	.byte Gs1, v100 @ N12
	.byte W12
	.byte An1 @ N12, v100
	.byte W12
	.byte N06, Gn1 @ v100
	.byte W08
	.byte Gs1 @ N06, v100
	.byte W08
	.byte An1 @ N06, v100
	.byte W08
	.byte As1 @ N06, v100
	.byte W08
	.byte Bn1 @ N06, v100
	.byte W08
	.byte Cn2 @ N06, v100
	.byte W08
	.byte PEND
	.byte VOICE, 3
	.byte VOL, 81
	.byte N06, Gn0, v112
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte Gn0, v127 @ N06
	.byte W12
	.byte N06 @ Gn0, v127
	.byte W12
	.byte N06 @ Gn0, v127
	.byte W12
	.byte Gn0, v112 @ N06
	.byte W12
	.byte N06 @ Gn0, v112
	.byte W12
	.byte PATT
		.word track_25_lbl_260e99
	.byte PATT
		.word track_25_lbl_260eb1
	.byte PATT
		.word track_25_lbl_260ec6
	.byte PATT
		.word track_25_lbl_260e80
	.byte PATT
		.word track_25_lbl_260e99
	.byte PATT
		.word track_25_lbl_260eb1
	.byte PATT
		.word track_25_lbl_260ee5
	.byte PATT
		.word track_25_lbl_260ef6
	.byte PATT
		.word track_25_lbl_260ef6
	.byte PATT
		.word track_25_lbl_260f01
	.byte PATT
		.word track_25_lbl_260f08
	.byte PATT
		.word track_25_lbl_260f0f
	.byte PATT
		.word track_25_lbl_260f0f
	.byte PATT
		.word track_25_lbl_260f1d
	.byte PATT
		.word track_25_lbl_260f26
	.byte PATT
		.word track_25_lbl_260f30
	.byte PATT
		.word track_25_lbl_260f3f
	.byte PATT
		.word track_25_lbl_260f4e
	.byte PATT
		.word track_25_lbl_260f5d
	.byte VOICE, 3
	.byte VOL, 94
	.byte N20, Cs1, v100
	.byte W36
	.byte N42 @ Cs1, v100
	.byte W60
	.byte N20 @ Cs1, v100
	.byte W36
	.byte N42 @ Cs1, v100
	.byte W60
	.byte N20 @ Cs1, v100
	.byte W36
	.byte N42 @ Cs1, v100
	.byte W60
	.byte N20 @ Cs1, v100
	.byte W36
	.byte N42 @ Cs1, v100
	.byte W60
	.byte N20, Ds1 @ v100
	.byte W36
	.byte N42 @ Ds1, v100
	.byte W60
	.byte N20 @ Ds1, v100
	.byte W36
	.byte N42 @ Ds1, v100
	.byte W60
	.byte N20 @ Ds1, v100
	.byte W36
	.byte N42 @ Ds1, v100
	.byte W60
	.byte N20 @ Ds1, v100
	.byte W36
	.byte N42 @ Ds1, v100
	.byte W60
	.byte N07, Fn1 @ v100
	.byte W36
	.byte N07 @ Fn1, v100
	.byte W36
	.byte N12, En1 @ v100
	.byte W12
	.byte N10, Fn1 @ v100
	.byte W12
	.byte W96
	.byte N07, Fs1 @ v100
	.byte W36
	.byte N07 @ Fs1, v100
	.byte W36
	.byte N07 @ Fs1, v100
	.byte W12
	.byte N48, Gn1 @ v100
	.byte W12
	.byte W48
	.byte N16 @ Gn1, v100
	.byte W16
	.byte N10, Gs1 @ v100
	.byte W16
	.byte An1 @ N10, v100
	.byte W16
	.byte GOTO
		.word track_25_lbl_260e80
	.byte FINE

track_25_3:
	.byte KEYSH, 0
	.byte PAN, c_v-10
	.byte PRIO, 30
	.byte W10
	.byte VOICE, 2
	.byte VOL, 80
	.byte N84, Cn4, v072
	.byte W01
	.byte VOL, 78
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W08
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W04
	.byte 24 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte W72
track_25_lbl_2610c3:
	.byte VOICE, 6
	.byte MOD, 0
	.byte VOL, 94
	.byte LFOS, 0
	.byte LFODL, 0
	.byte N06, Gn2, v072
	.byte W36
	.byte Gn2, v080 @ N06
	.byte W36
	.byte Gn2, v064 @ N06
	.byte W24
track_25_lbl_2610d7:
	.byte W12
	.byte N06, Gn2, v064
	.byte W36
	.byte N06 @ Gn2, v064
	.byte W12
	.byte N30, Gs2, v100
	.byte W12
	.byte VOL, 47
	.byte W06
	.byte 37 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W06
	.byte PEND
track_25_lbl_2610ec:
	.byte VOL, 94
	.byte N06, Gn2, v064
	.byte W36
	.byte Gn2, v052 @ N06
	.byte W36
	.byte N06 @ Gn2, v052
	.byte W24
	.byte PEND
track_25_lbl_2610f8:
	.byte W12
	.byte N06, Gn2, v052
	.byte W36
	.byte N18, Gn2, v080
	.byte W24
	.byte Fs2 @ N18, v080
	.byte W24
	.byte PEND
track_25_lbl_261104:
	.byte N06, Gn2, v064
	.byte W36
	.byte Gn2, v052 @ N06
	.byte W36
	.byte N06 @ Gn2, v052
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_2610d7
	.byte PATT
		.word track_25_lbl_2610ec
track_25_lbl_261118:
	.byte W12
	.byte N30, Gs2, v092
	.byte W06
	.byte VOL, 37
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W12
	.byte 94 @ VOL
	.byte N12, An2, v056
	.byte W16
	.byte As2, v092 @ N12
	.byte W16
	.byte Bn2, v112 @ N12
	.byte W16
	.byte PEND
track_25_lbl_261132:
	.byte VOICE, 2
	.byte MOD, 0
	.byte VOL, 37
	.byte LFODL, 0
	.byte N96, Fn4, v040
	.byte W96
	.byte PEND
	.byte Fn3 @ N96, v040
	.byte W96
	.byte TIE @ Fn3, v040
	.byte W96
	.byte W72
	.byte EOT @ Fn3, v040
	.byte W24
	.byte N96, Fs4, v068
	.byte W96
	.byte Fs3 @ N96, v068
	.byte W96
	.byte As3, v044 @ N96
	.byte W96
track_25_lbl_26114f:
	.byte N36, Gn3, v064
	.byte W48
	.byte As3, v056 @ N36
	.byte W48
	.byte PEND
	.byte W96
	.byte W96
	.byte W96
track_25_lbl_26115a:
	.byte VOICE, 0
	.byte VOL, 85
	.byte N04, Fn1, v048
	.byte W13
	.byte N07, Fn1, v056
	.byte W11
	.byte Fn1, v064 @ N07
	.byte W14
	.byte N08, Fn1, v080
	.byte W56
	.byte W02
	.byte PEND
	.byte VOICE, 6
	.byte MOD, 0
	.byte VOL, 81
	.byte LFOS, 0
	.byte LFODL, 0
	.byte N06, Gn2, v072
	.byte W36
	.byte Gn2, v080 @ N06
	.byte W36
	.byte Gn2, v064 @ N06
	.byte W24
	.byte PATT
		.word track_25_lbl_2610d7
	.byte PATT
		.word track_25_lbl_2610ec
	.byte PATT
		.word track_25_lbl_2610f8
	.byte PATT
		.word track_25_lbl_261104
	.byte PATT
		.word track_25_lbl_2610d7
	.byte PATT
		.word track_25_lbl_2610ec
	.byte PATT
		.word track_25_lbl_261118
	.byte PATT
		.word track_25_lbl_261132
	.byte N96, Fn3, v040
	.byte W96
	.byte TIE @ Fn3, v040
	.byte W96
	.byte W72
	.byte EOT @ Fn3, v040
	.byte W24
	.byte N96, Fs4, v068
	.byte W96
	.byte Fs3 @ N96, v068
	.byte W96
	.byte As3, v044 @ N96
	.byte W96
	.byte PATT
		.word track_25_lbl_26114f
	.byte W96
	.byte W96
	.byte W96
	.byte PATT
		.word track_25_lbl_26115a
	.byte VOICE, 2
	.byte MOD, 1
	.byte VOL, 47
	.byte LFOS, 100
	.byte LFODL, 20
	.byte N06, Cs4, v068
	.byte W36
	.byte N06 @ Cs4, v068
	.byte W36
	.byte N06 @ Cs4, v068
	.byte W24
	.byte W12
	.byte N06 @ Cs4, v068
	.byte W36
	.byte N30, Dn4 @ v068
	.byte W48
	.byte N06, Bn3 @ v068
	.byte W36
	.byte N06 @ Bn3, v068
	.byte W36
	.byte N06 @ Bn3, v068
	.byte W24
	.byte W12
	.byte N06 @ Bn3, v068
	.byte W36
	.byte N10, Cn4, v076
	.byte W16
	.byte Cn4, v048 @ N10
	.byte W16
	.byte N10 @ Cn4, v048
	.byte W16
	.byte N06, Ds4, v068
	.byte W36
	.byte N06 @ Ds4, v068
	.byte W36
	.byte N06 @ Ds4, v068
	.byte W24
	.byte W12
	.byte N24, Ds4, v076
	.byte W36
	.byte N10, En4 @ v076
	.byte W16
	.byte N06, En4, v048
	.byte W16
	.byte N06 @ En4, v048
	.byte W16
	.byte Ds4, v068 @ N06
	.byte W36
	.byte N06 @ Ds4, v068
	.byte W36
	.byte N12, Dn4, v088
	.byte W12
	.byte N08, Ds4, v056
	.byte W12
	.byte W12
	.byte N30, En4, v088
	.byte W36
	.byte LFOS, 0
	.byte LFODL, 0
	.byte W48
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte GOTO
		.word track_25_lbl_2610c3
	.byte FINE

track_25_4:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 79
	.byte PAN, c_v+6
	.byte PRIO, 29
	.byte VOL, 75
	.byte N96, Cn3, v040
	.byte W01
	.byte VOL, 71
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W36
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 94 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte W01
	.byte 100 @ VOL
	.byte W01
	.byte 102 @ VOL
	.byte W01
	.byte 105 @ VOL
	.byte W01
	.byte 109 @ VOL
	.byte W01
	.byte 111 @ VOL
	.byte W01
	.byte W72
track_25_lbl_2612ab:
	.byte VOICE, 0
	.byte VOL, 120
	.byte W30
	.byte W01
	.byte N05, Fs1, v016
	.byte W48
	.byte N05 @ Fs1, v016
	.byte W17
	.byte W96
track_25_lbl_2612b8:
	.byte W30
	.byte W01
	.byte N05, Fs1, v016
	.byte W48
	.byte N05 @ Fs1, v016
	.byte W17
	.byte PEND
track_25_lbl_2612c1:
	.byte W36
	.byte N03, Dn1, v056
	.byte W60
	.byte PEND
	.byte PATT
		.word track_25_lbl_2612b8
	.byte W96
	.byte PATT
		.word track_25_lbl_2612b8
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte PATT
		.word track_25_lbl_2612b8
	.byte W96
	.byte PATT
		.word track_25_lbl_2612b8
	.byte PATT
		.word track_25_lbl_2612c1
	.byte PATT
		.word track_25_lbl_2612b8
	.byte W96
	.byte PATT
		.word track_25_lbl_2612b8
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte N04, Dn1, v032
	.byte W10
	.byte En1, v064 @ N04
	.byte W36
	.byte W02
	.byte W96
	.byte W96
	.byte GOTO
		.word track_25_lbl_2612ab
	.byte FINE

track_25_5:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte PRIO, 110
	.byte W48
	.byte W48
	.byte W72
track_25_lbl_26132a:
	.byte VOICE, 7
	.byte VOL, 94
	.byte N06, Cs3, v072
	.byte W36
	.byte Cs3, v080 @ N06
	.byte W36
	.byte Cs3, v064 @ N06
	.byte W24
track_25_lbl_261338:
	.byte W12
	.byte N06, Cs3, v064
	.byte W36
	.byte N06 @ Cs3, v064
	.byte W12
	.byte N30, Dn3, v100
	.byte W36
	.byte PEND
track_25_lbl_261344:
	.byte N06, Cs3, v064
	.byte W36
	.byte Cs3, v052 @ N06
	.byte W36
	.byte N06 @ Cs3, v052
	.byte W24
	.byte PEND
track_25_lbl_26134e:
	.byte W12
	.byte N06, Cs3, v040
	.byte W36
	.byte N18, Cs3, v080
	.byte W24
	.byte Cn3 @ N18, v080
	.byte W24
	.byte PEND
	.byte PATT
		.word track_25_lbl_261344
	.byte PATT
		.word track_25_lbl_261338
	.byte PATT
		.word track_25_lbl_261344
track_25_lbl_261369:
	.byte W12
	.byte N30, Dn3, v092
	.byte W36
	.byte N12, Ds3, v056
	.byte W16
	.byte En3, v092 @ N12
	.byte W16
	.byte Fn3, v100 @ N12
	.byte W16
	.byte PEND
track_25_lbl_261379:
	.byte VOICE, 7
	.byte VOL, 90
	.byte N96, Cs4, v056
	.byte W96
	.byte PEND
	.byte Cs3 @ N96, v056
	.byte W96
	.byte TIE, Dn3 @ v056
	.byte W96
	.byte W72
	.byte EOT @ Dn3, v056
	.byte W24
	.byte N96, Ds4, v072
	.byte W96
	.byte Ds3 @ N96, v072
	.byte W96
	.byte En3, v056 @ N96
	.byte W96
track_25_lbl_261393:
	.byte N36, En3, v064
	.byte W48
	.byte N36 @ En3, v064
	.byte W48
	.byte PEND
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 7
	.byte VOL, 120
	.byte N06, Cs3, v072
	.byte W36
	.byte Cs3, v080 @ N06
	.byte W36
	.byte Cs3, v064 @ N06
	.byte W24
	.byte PATT
		.word track_25_lbl_261338
	.byte PATT
		.word track_25_lbl_261344
	.byte PATT
		.word track_25_lbl_26134e
	.byte PATT
		.word track_25_lbl_261344
	.byte PATT
		.word track_25_lbl_261338
	.byte PATT
		.word track_25_lbl_261344
	.byte PATT
		.word track_25_lbl_261369
	.byte PATT
		.word track_25_lbl_261379
	.byte N96, Cs3, v056
	.byte W96
	.byte TIE, Dn3 @ v056
	.byte W96
	.byte W72
	.byte EOT @ Dn3, v056
	.byte W24
	.byte N96, Ds4, v072
	.byte W96
	.byte Ds3 @ N96, v072
	.byte W96
	.byte En3, v056 @ N96
	.byte W96
	.byte PATT
		.word track_25_lbl_261393
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOL, 94
	.byte N06, Bn3, v068
	.byte W36
	.byte N06 @ Bn3, v068
	.byte W36
	.byte N06 @ Bn3, v068
	.byte W24
	.byte W12
	.byte N06 @ Bn3, v068
	.byte W36
	.byte N30, Cn4 @ v068
	.byte W48
	.byte N06, An3 @ v068
	.byte W36
	.byte N06 @ An3, v068
	.byte W36
	.byte N06 @ An3, v068
	.byte W24
	.byte W12
	.byte N06 @ An3, v068
	.byte W36
	.byte N10, As3, v076
	.byte W16
	.byte As3, v048 @ N10
	.byte W16
	.byte N10 @ As3, v048
	.byte W16
	.byte N06, Cs4, v068
	.byte W36
	.byte N06 @ Cs4, v068
	.byte W36
	.byte N06 @ Cs4, v068
	.byte W24
	.byte W12
	.byte N24, Cs4, v076
	.byte W36
	.byte N10, Dn4 @ v076
	.byte W16
	.byte N06, Dn4, v048
	.byte W16
	.byte N06 @ Dn4, v048
	.byte W16
	.byte Cs4, v068 @ N06
	.byte W36
	.byte N06 @ Cs4, v068
	.byte W36
	.byte N12, Cn4, v088
	.byte W12
	.byte N08, Cs4, v056
	.byte W12
	.byte W12
	.byte N30, Dn4, v088
	.byte W36
	.byte N16, Bn3, v072
	.byte W16
	.byte N06, Cn4 @ v072
	.byte W16
	.byte Cs4 @ N06, v072
	.byte W16
	.byte N08, Bn3, v100
	.byte W36
	.byte N08 @ Bn3, v100
	.byte W36
	.byte N12, As3 @ v100
	.byte W12
	.byte N08, Bn3 @ v100
	.byte W12
	.byte W96
	.byte Cn4 @ N08, v100
	.byte W36
	.byte N08 @ Cn4, v100
	.byte W36
	.byte N06 @ Cn4, v100
	.byte W12
	.byte N48, Cs4 @ v100
	.byte W12
	.byte W48
	.byte N16 @ Cs4, v100
	.byte W16
	.byte Dn4 @ N16, v100
	.byte W16
	.byte N08, Ds4 @ v100
	.byte W16
	.byte GOTO
		.word track_25_lbl_26132a
	.byte FINE

track_25_6:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte PRIO, 20
	.byte W48
	.byte W48
	.byte W72
track_25_lbl_261471:
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 8
	.byte VOL, 120
	.byte N06, Gn3, v068
	.byte W36
	.byte N06 @ Gn3, v068
	.byte W36
	.byte N06 @ Gn3, v068
	.byte W24
	.byte W12
	.byte N06 @ Gn3, v068
	.byte W36
	.byte N30, Gs3 @ v068
	.byte W48
	.byte N06, Fn3 @ v068
	.byte W36
	.byte N06 @ Fn3, v068
	.byte W36
	.byte N06 @ Fn3, v068
	.byte W24
	.byte W12
	.byte N06 @ Fn3, v068
	.byte W36
	.byte N10, Fs3, v076
	.byte W16
	.byte Fs3, v048 @ N10
	.byte W16
	.byte N10 @ Fs3, v048
	.byte W16
	.byte N06, An3, v068
	.byte W36
	.byte N06 @ An3, v068
	.byte W36
	.byte N06 @ An3, v068
	.byte W24
	.byte W12
	.byte N24, An3, v076
	.byte W36
	.byte N10, As3 @ v076
	.byte W16
	.byte N06, As3, v048
	.byte W16
	.byte N06 @ As3, v048
	.byte W16
	.byte An3, v068 @ N06
	.byte W36
	.byte N06 @ An3, v068
	.byte W36
	.byte N12, Gs3, v088
	.byte W12
	.byte N08, An3, v056
	.byte W12
	.byte W12
	.byte N30, As3, v088
	.byte W36
	.byte N16, Ds4, v072
	.byte W16
	.byte N06, En4 @ v072
	.byte W16
	.byte Fn4 @ N06, v072
	.byte W16
	.byte N08, Fn4, v100
	.byte W36
	.byte N08 @ Fn4, v100
	.byte W36
	.byte N12, En4 @ v100
	.byte W12
	.byte N08, Fn4 @ v100
	.byte W12
	.byte W96
	.byte Fs4 @ N08, v100
	.byte W36
	.byte N08 @ Fs4, v100
	.byte W36
	.byte N06 @ Fs4, v100
	.byte W12
	.byte N48, Gn4 @ v100
	.byte W12
	.byte W48
	.byte N16 @ Gn4, v100
	.byte W16
	.byte Gs4 @ N16, v100
	.byte W16
	.byte N08, An4 @ v100
	.byte W16
	.byte GOTO
		.word track_25_lbl_261471
	.byte FINE

.align 2

track_25:
	.byte 7
	.byte 25
	.byte 130
	.byte 128
	.word 0x80a5fbc
	.word track_25_0
	.word track_25_1
	.word track_25_2
	.word track_25_3
	.word track_25_4
	.word track_25_5
	.word track_25_6

.align 2
