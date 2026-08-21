.align 2

.global track_60

track_60_0:
	.byte KEYSH, 0
	.byte TEMPO, 30
	.byte VOICE, 5
	.byte VOL, 70
	.byte PAN, c_v+10
	.byte PRIO, 110
	.byte W72
	.byte W02
	.byte N10, Cn2, v048
	.byte W10
	.byte N08, Cs2, v064
	.byte W08
	.byte N07, Fn2, v068
	.byte W07
	.byte An2, v056 @ N07
	.byte W07
	.byte N06, Cn3 @ v056
	.byte W06
	.byte N07, Cs3, v068
	.byte W07
	.byte N06, Fn3 @ v068
	.byte W06
	.byte N07, An3, v080
	.byte W07
	.byte Cn4, v064 @ N07
	.byte W07
	.byte Cs4, v052 @ N07
	.byte W05
	.byte W02
	.byte Fn4 @ N07, v052
	.byte W07
	.byte An4 @ N07, v052
	.byte W07
	.byte N08, Cn5, v064
	.byte W08
	.byte Cs5, v036 @ N08
	.byte W08
	.byte Fn5 @ N08, v036
	.byte W08
	.byte An5, v024 @ N08
	.byte W32
track_60_lbl_268f5a:
	.byte W12
	.byte VOICE, 6
	.byte VOL, 70
	.byte N12, Cn3, v032
	.byte W12
	.byte N48, An3 @ v032
	.byte W08
	.byte VOL, 69
	.byte W01
	.byte 68 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
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
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte VOICE, 5
	.byte VOL, 70
	.byte N11, Cs5, v040
	.byte W11
	.byte N08, Fn4, v028
	.byte W08
	.byte An4, v040 @ N08
	.byte W08
	.byte N07, Fn3, v072
	.byte W07
	.byte Cn4, v064 @ N07
	.byte W07
	.byte Cs4, v056 @ N07
	.byte W07
	.byte An4, v072 @ N07
	.byte W07
	.byte Cn4, v080 @ N07
	.byte W07
	.byte Cs4, v044 @ N07
	.byte W07
	.byte N09, An3, v072
	.byte W03
	.byte W06
	.byte Fn3, v060 @ N09
	.byte W09
	.byte Cn3, v068 @ N09
	.byte W09
	.byte Fn2, v028 @ N09
	.byte W48
	.byte W03
	.byte N09 @ Fn2, v028
	.byte W09
	.byte N06, An2, v072
	.byte W06
	.byte Cn3, v084 @ N06
	.byte W06
	.byte Cs3, v100 @ N06
	.byte W06
	.byte Fn3 @ N06, v100
	.byte W06
	.byte An3 @ N06, v100
	.byte W06
	.byte Cn4, v080 @ N06
	.byte W06
	.byte Cs4, v052 @ N06
	.byte W06
	.byte N07, Fn4, v048
	.byte W07
	.byte An4, v052 @ N07
	.byte W07
	.byte N04, Cn5, v032
	.byte W04
	.byte W02
	.byte N06, Cs5, v020
	.byte W06
	.byte Cn5 @ N06, v020
	.byte W06
	.byte An4 @ N06, v020
	.byte W06
	.byte Fn4, v028 @ N06
	.byte W06
	.byte Cs4 @ N06, v028
	.byte W06
	.byte Cn4, v052 @ N06
	.byte W06
	.byte An3 @ N06, v052
	.byte W06
	.byte Fn3, v056 @ N06
	.byte W06
	.byte N08, Cs3, v064
	.byte W08
	.byte Cn3, v056 @ N08
	.byte W08
	.byte N06, Fn2, v060
	.byte W06
	.byte Gn2, v068 @ N06
	.byte W06
	.byte As2, v072 @ N06
	.byte W06
	.byte Cn3 @ N06, v072
	.byte W06
	.byte En3, v080 @ N06
	.byte W06
	.byte Gn3, v072 @ N06
	.byte W06
	.byte As3, v076 @ N06
	.byte W06
	.byte Cn4, v064 @ N06
	.byte W06
	.byte En4, v020 @ N06
	.byte W06
	.byte N08, Gn4 @ v020
	.byte W08
	.byte As4 @ N08, v020
	.byte W08
	.byte Cn5 @ N08, v020
	.byte W08
	.byte N06, Cs5 @ v020
	.byte W07
	.byte Cn5 @ N06, v020
	.byte W07
	.byte An4 @ N06, v020
	.byte W06
	.byte Fn4, v028 @ N06
	.byte W06
	.byte Cs4 @ N06, v028
	.byte W06
	.byte Cn4, v052 @ N06
	.byte W06
	.byte An3 @ N06, v052
	.byte W06
	.byte Fn3, v056 @ N06
	.byte W06
	.byte Cs3, v032 @ N06
	.byte W06
	.byte Cn3, v040 @ N06
	.byte W06
	.byte An2 @ N06, v040
	.byte W06
	.byte Fn2, v052 @ N06
	.byte W04
	.byte W02
	.byte Gn2, v060 @ N06
	.byte W06
	.byte As2 @ N06, v060
	.byte W06
	.byte Cn3, v052 @ N06
	.byte W06
	.byte En3, v048 @ N06
	.byte W06
	.byte Gn3, v040 @ N06
	.byte W44
	.byte W02
	.byte VOICE, 6
	.byte VOL, 34
	.byte N72, Fn3, v044
	.byte W04
	.byte VOL, 32
	.byte W05
	.byte 31 @ VOL
	.byte W05
	.byte 29 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W05
	.byte 26 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W05
	.byte 21 @ VOL
	.byte W05
	.byte 19 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W02
	.byte VOICE, 5
	.byte VOL, 70
	.byte W01
	.byte N07, Cn5, v036
	.byte W07
	.byte Cn4 @ N07, v036
	.byte W07
	.byte N06, Gn4 @ v036
	.byte W06
	.byte Gn3, v084 @ N06
	.byte W06
	.byte En4, v072 @ N06
	.byte W06
	.byte En3, v080 @ N06
	.byte W06
	.byte Cn4, v076 @ N06
	.byte W06
	.byte Cn3 @ N06, v076
	.byte W06
	.byte N08, Gn3 @ v076
	.byte W08
	.byte Gn2, v068 @ N08
	.byte W13
	.byte VOICE, 6
	.byte VOL, 28
	.byte N72, Fn3, v056
	.byte W03
	.byte VOL, 26
	.byte W04
	.byte 25 @ VOL
	.byte W04
	.byte 24 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 14 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte N96, En3 @ v056
	.byte W02
	.byte VOL, 25
	.byte W04
	.byte 24 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 14 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W04
	.byte 7 @ VOL
	.byte W04
	.byte 5 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W04
	.byte 2 @ VOL
	.byte W04
	.byte 1 @ VOL
	.byte W04
	.byte W72
track_60_lbl_26911a:
	.byte VOICE, 9
	.byte VOL, 42
	.byte N24, Fn4, v052
	.byte W24
	.byte N36, En4 @ v052
	.byte W36
	.byte N12, Cn4, v060
	.byte W12
	.byte PEND
track_60_lbl_26912a:
	.byte N48, Cs4, v060
	.byte W48
	.byte N24, Gs3, v072
	.byte W24
	.byte PEND
	.byte As3, v052 @ N24
	.byte W24
	.byte N36, Ds3, v072
	.byte W36
	.byte N12, Fn3, v080
	.byte W12
	.byte N48, As2 @ v080
	.byte W72
	.byte PATT
		.word track_60_lbl_26911a
	.byte PATT
		.word track_60_lbl_26912a
track_60_lbl_26914b:
	.byte N12, As3, v080
	.byte W12
	.byte TIE, Fn4, v052
	.byte W60
	.byte PEND
	.byte W66
	.byte EOT @ Fn4, v052
	.byte W06
	.byte VOICE, 10
	.byte N12, Fn4, v040
	.byte W12
	.byte As4 @ N12, v040
	.byte W12
	.byte Gs4 @ N12, v040
	.byte W12
	.byte N36, Cs5 @ v040
	.byte W10
	.byte VOL, 36
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte N12, Cn5 @ v040
	.byte W12
	.byte Fn4 @ N12, v040
	.byte W12
	.byte As4 @ N12, v040
	.byte W12
	.byte N24, Ds4 @ v040
	.byte W03
	.byte VOL, 41
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte N12, Fn4, v032
	.byte W12
	.byte N72, As3, v040
	.byte W18
	.byte VOL, 41
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 32 @ VOL
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
	.byte W03
	.byte 24 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W01
	.byte W72
	.byte VOICE, 10
	.byte VOL, 42
	.byte N12, Fn4 @ v040
	.byte W12
	.byte As4 @ N12, v040
	.byte W12
	.byte Gs4 @ N12, v040
	.byte W12
	.byte VOL, 36
	.byte N24, Ds5 @ v040
	.byte W03
	.byte VOL, 34
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte N24, Cs5 @ v040
	.byte W12
	.byte W12
	.byte N12, Cn5, v032
	.byte W12
	.byte Gs4 @ N12, v032
	.byte W12
	.byte N24, As4 @ v032
	.byte W03
	.byte VOL, 34
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte N12, Ds5 @ v032
	.byte W12
	.byte N72, Fn5, v020
	.byte W10
	.byte VOL, 34
	.byte W04
	.byte 32 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W04
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W02
	.byte W72
track_60_lbl_26928c:
	.byte VOICE, 9
	.byte VOL, 42
	.byte N24, Fn4, v052
	.byte W24
	.byte N36, En4 @ v052
	.byte W36
	.byte VOICE, 10
	.byte N12, Cn4, v060
	.byte W12
	.byte PEND
track_60_lbl_26929e:
	.byte VOICE, 9
	.byte N48, Cs4, v060
	.byte W48
	.byte N24, Gs3, v072
	.byte W24
	.byte PEND
	.byte As3, v052 @ N24
	.byte W24
	.byte N48, Ds3, v072
	.byte W36
	.byte N12, Fn3, v080
	.byte W12
	.byte N48, As2 @ v080
	.byte W72
	.byte PATT
		.word track_60_lbl_26928c
	.byte PATT
		.word track_60_lbl_26929e
	.byte PATT
		.word track_60_lbl_26914b
	.byte W66
	.byte EOT @ As2, v080
	.byte W06
	.byte W24
	.byte N18, Fn3, v056
	.byte W48
	.byte W24
	.byte N20 @ Fn3, v056
	.byte W36
	.byte N12, Cn3, v060
	.byte W12
	.byte N36, Fn3, v072
	.byte W36
	.byte N12, Ds3 @ v072
	.byte W12
	.byte N24, Gs2 @ v072
	.byte W24
	.byte N48, As2, v060
	.byte W72
	.byte W24
	.byte N18, As3 @ v060
	.byte W48
	.byte N72, As3, v040
	.byte W72
	.byte As2, v072 @ N72
	.byte W72
	.byte N48, An2, v060
	.byte W72
	.byte GOTO
		.word track_60_lbl_268f5a
	.byte FINE

track_60_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte PAN, c_v
	.byte PRIO, 109
	.byte W72
	.byte VOICE, 6
	.byte VOL, 53
	.byte TIE, Fn2, v072
	.byte W02
	.byte VOL, 55
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W42
	.byte W01
	.byte W72
	.byte EOT @ Fn2, v072
track_60_lbl_269323:
	.byte VOICE, 7
	.byte VOL, 28
	.byte PAN, c_v-10
	.byte N72, Cn5, v020
	.byte W72
	.byte Cs5 @ N72, v020
	.byte W72
	.byte Cn5 @ N72, v020
	.byte W72
	.byte Cs5 @ N72, v020
	.byte W72
	.byte VOICE, 4
	.byte VOL, 25
	.byte PAN, c_v-10
	.byte N24, Fs4, v052
	.byte W24
	.byte N48, Fn4 @ v052
	.byte W20
	.byte VOL, 24
	.byte W01
	.byte 21 @ VOL
	.byte W24
	.byte W03
	.byte N72, En4, v048
	.byte W72
	.byte VOL, 42
	.byte PAN, c_v
	.byte N24, Fs3, v056
	.byte W24
	.byte VOL, 21
	.byte N48, Fn3 @ v056
	.byte W48
	.byte N72, En3, v068
	.byte W72
	.byte VOICE, 8
	.byte VOL, 42
	.byte TIE, As2, v076
	.byte W72
	.byte W54
	.byte EOT @ As2, v076
	.byte W06
	.byte N08, As1, v096
	.byte W12
	.byte TIE @ As1, v096
	.byte W72
	.byte W56
	.byte EOT @ As1, v096
	.byte W04
	.byte N08 @ As1, v096
	.byte W12
	.byte N60, As1, v084
	.byte W21
	.byte VOL, 41
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W24
	.byte W01
	.byte 49 @ VOL
	.byte PAN, c_v
	.byte N72, As1, v112
	.byte W72
	.byte Gs1 @ N72, v112
	.byte W72
	.byte TIE, Fs1 @ v112
	.byte W72
	.byte W48
	.byte EOT @ Fs1, v112
	.byte N24, Gs1 @ v112
	.byte W24
	.byte N72, As1 @ v112
	.byte W72
	.byte Gs1 @ N72, v112
	.byte W72
	.byte TIE, Fs1 @ v112
	.byte W72
track_60_lbl_2693b0:
	.byte W48
	.byte EOT @ Fs1, v112
	.byte N24, Gs1, v124
	.byte W24
	.byte PEND
	.byte N72, As1 @ v124
	.byte W72
	.byte Gs1, v112 @ N72
	.byte W72
	.byte TIE, Fs1, v092
	.byte W72
track_60_lbl_2693c1:
	.byte W48
	.byte EOT @ Fs1, v092
	.byte N24, Gs1, v112
	.byte W24
	.byte PEND
	.byte N72, As1 @ v112
	.byte W72
	.byte Gs1 @ N72, v112
	.byte W72
	.byte TIE, Fs1, v104
	.byte W72
	.byte PATT
		.word track_60_lbl_2693c1
track_60_lbl_2693d6:
	.byte N72, As1, v104
	.byte W72
	.byte PEND
	.byte Gs1, v112 @ N72
	.byte W72
	.byte TIE, Fs1, v104
	.byte W72
	.byte W48
	.byte EOT @ Fs1, v104
	.byte N24, Gs1 @ v104
	.byte W24
	.byte N72, As1, v112
	.byte W72
	.byte Gs1 @ N72, v112
	.byte W72
	.byte TIE, Fs1 @ v112
	.byte W72
	.byte PATT
		.word track_60_lbl_2693b0
	.byte PATT
		.word track_60_lbl_2693d6
	.byte N72, Gs1, v112
	.byte W72
	.byte TIE, Fs1, v104
	.byte W72
	.byte W48
	.byte EOT @ Fs1, v104
	.byte N24, Gs1 @ v104
	.byte W24
	.byte N72, As1, v112
	.byte W72
	.byte Gs1 @ N72, v112
	.byte W72
	.byte TIE, Fs1 @ v112
	.byte W72
	.byte W48
	.byte EOT @ Fs1, v112
	.byte N24, Fs1, v124
	.byte W24
	.byte GOTO
		.word track_60_lbl_269323
	.byte FINE

track_60_2:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 14
	.byte PAN, c_v+10
	.byte PRIO, 108
	.byte N24, Cs4, v064
	.byte W24
	.byte VOL, 7
	.byte N72, Gs4 @ v064
	.byte W06
	.byte VOL, 8
	.byte W05
	.byte 9 @ VOL
	.byte W05
	.byte 11 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte W24
	.byte TIE, An4 @ v064
	.byte W01
	.byte VOL, 31
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W07
	.byte 14 @ VOL
	.byte W19
	.byte W04
	.byte 12 @ VOL
	.byte W24
	.byte W03
	.byte 11 @ VOL
	.byte W24
	.byte W03
	.byte 9 @ VOL
	.byte W14
	.byte EOT @ An4, v064
track_60_lbl_269477:
	.byte VOICE, 6
	.byte VOL, 36
	.byte PAN, c_v
	.byte N72, Fn2, v080
	.byte W02
	.byte VOL, 37
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W40
	.byte W01
	.byte N72 @ Fn2, v080
	.byte W08
	.byte VOL, 69
	.byte W03
	.byte 68 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte N72 @ Fn2, v080
	.byte W04
	.byte VOL, 39
	.byte W01
	.byte 41 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W40
	.byte W01
	.byte N72 @ Fn2, v080
	.byte W09
	.byte VOL, 68
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W04
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte N72, As1 @ v080
	.byte W01
	.byte VOL, 36
	.byte W02
	.byte 38 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W40
	.byte W01
	.byte N72 @ As1, v080
	.byte W08
	.byte VOL, 69
	.byte W03
	.byte 68 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte N72 @ As1, v080
	.byte W01
	.byte VOL, 36
	.byte W03
	.byte 39 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W40
	.byte W01
	.byte N72 @ As1, v080
	.byte W08
	.byte VOL, 69
	.byte W03
	.byte 68 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 60 @ VOL
	.byte W05
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte PAN, c_v-10
	.byte N72, An3, v036
	.byte W02
	.byte VOL, 9
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W05
	.byte 26 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W05
	.byte 21 @ VOL
	.byte W05
	.byte 19 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W05
	.byte 14 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte N60, Gs3, v044
	.byte W02
	.byte VOL, 17
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W04
	.byte 29 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W04
	.byte N12, As3 @ v044
	.byte W12
	.byte N72, An3 @ v044
	.byte W01
	.byte VOL, 39
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte N96, Gs3 @ v044
	.byte W02
	.byte VOL, 25
	.byte W04
	.byte 24 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W04
	.byte 14 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W04
	.byte 11 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W04
	.byte 7 @ VOL
	.byte W04
	.byte 5 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W04
	.byte 2 @ VOL
	.byte W04
	.byte 1 @ VOL
	.byte W04
	.byte W72
	.byte VOICE, 4
	.byte VOL, 11
	.byte PAN, c_v-10
	.byte N96, As3, v048
	.byte W02
	.byte VOL, 12
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W05
	.byte 32 @ VOL
	.byte W05
	.byte 29 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W02
track_60_lbl_269726:
	.byte W03
	.byte VOL, 18
	.byte W05
	.byte 15 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W60
	.byte W02
	.byte PEND
	.byte W72
	.byte W72
track_60_lbl_269732:
	.byte VOL, 11
	.byte N96, As3, v056
	.byte W02
	.byte VOL, 12
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W05
	.byte 32 @ VOL
	.byte W05
	.byte 29 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W02
	.byte PEND
	.byte PATT
		.word track_60_lbl_269726
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
	.byte VOL, 11
	.byte N96, As3, v048
	.byte W02
	.byte VOL, 12
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W05
	.byte 32 @ VOL
	.byte W05
	.byte 29 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W02
	.byte PATT
		.word track_60_lbl_269726
	.byte W72
	.byte W72
	.byte PATT
		.word track_60_lbl_269732
	.byte PATT
		.word track_60_lbl_269726
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 7
	.byte VOL, 28
	.byte N72, As4, v032
	.byte W72
	.byte An4 @ N72, v032
	.byte W72
	.byte Gs4 @ N72, v032
	.byte W07
	.byte VOL, 26
	.byte W04
	.byte 25 @ VOL
	.byte W04
	.byte 24 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W05
	.byte 21 @ VOL
	.byte W04
	.byte 19 @ VOL
	.byte W04
	.byte 18 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W04
	.byte 14 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W05
	.byte 11 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W04
	.byte 8 @ VOL
	.byte W04
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W02
	.byte 5 @ VOL
	.byte W01
	.byte W24
	.byte 28 @ VOL
	.byte N48, Fn4 @ v032
	.byte W01
	.byte VOL, 26
	.byte W03
	.byte 25 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W04
	.byte 21 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W01
	.byte W72
	.byte W72
	.byte GOTO
		.word track_60_lbl_269477
	.byte FINE

track_60_3:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 8
	.byte PAN, c_v-10
	.byte PRIO, 30
	.byte TIE, Fn3, v064
	.byte W12
	.byte VOL, 7
	.byte W17
	.byte 8 @ VOL
	.byte W04
	.byte 9 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W07
	.byte 14 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte W24
	.byte W01
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W06
	.byte 21 @ VOL
	.byte W12
	.byte 19 @ VOL
	.byte W08
	.byte 18 @ VOL
	.byte W01
	.byte W09
	.byte 17 @ VOL
	.byte W10
	.byte 15 @ VOL
	.byte W11
	.byte 14 @ VOL
	.byte W18
	.byte EOT @ Fn3, v064
	.byte W24
track_60_lbl_269890:
	.byte W72
	.byte W72
	.byte W12
	.byte VOICE, 6
	.byte VOL, 70
	.byte N60, Cn3, v032
	.byte W12
	.byte N48, An3 @ v032
	.byte W08
	.byte VOL, 69
	.byte W01
	.byte 68 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
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
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte W72
	.byte W12
	.byte 70 @ VOL
	.byte N60, As2 @ v032
	.byte W20
	.byte VOL, 69
	.byte W01
	.byte 68 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
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
	.byte 46 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W02
	.byte VOICE, 4
	.byte N48, Fn4, v048
	.byte W13
	.byte VOL, 19
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W24
	.byte W02
	.byte W12
	.byte VOICE, 6
	.byte VOL, 70
	.byte N60, As2, v032
	.byte W20
	.byte VOL, 69
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
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
	.byte 46 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte VOICE, 4
	.byte VOL, 21
	.byte N48, Fn3, v056
	.byte W13
	.byte VOL, 19
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W24
	.byte W02
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
	.byte W72
	.byte W72
	.byte VOICE, 7
	.byte VOL, 28
	.byte N72, As4, v032
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte GOTO
		.word track_60_lbl_269890
	.byte FINE

track_60_4:
	.byte KEYSH, 0
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W72
	.byte W72
	.byte W72
track_60_lbl_269a0b:
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
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte W72
	.byte VOICE, 12
	.byte VOL, 42
	.byte W24
	.byte N18, As2, v052
	.byte W48
	.byte W24
	.byte N20, Cn3 @ v052
	.byte W48
	.byte W72
	.byte W72
	.byte W24
	.byte N18, Fn3, v060
	.byte W48
	.byte N48, Gs3, v052
	.byte W48
	.byte N24, Cs3, v064
	.byte W24
	.byte W72
	.byte W72
	.byte GOTO
		.word track_60_lbl_269a0b
	.byte FINE

.align 2

track_60:
	.byte 5
	.byte 60
	.byte 130
	.byte 128
	.word 0x80a5cf8
	.word track_60_0
	.word track_60_1
	.word track_60_2
	.word track_60_3
	.word track_60_4

.align 2
