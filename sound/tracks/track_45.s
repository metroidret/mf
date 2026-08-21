.align 2

.global track_45

track_45_0:
	.byte KEYSH, 0
	.byte TEMPO, 55
	.byte PAN, c_v+16
	.byte PRIO, 110
	.byte W48
track_45_lbl_264461:
	.byte VOICE, 27
	.byte VOL, 9
	.byte W07
	.byte 10 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte N48, En4, v052
	.byte W01
	.byte VOL, 23
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W36
	.byte W02
	.byte N24, Bn3 @ v052
	.byte W24
	.byte N15, As3 @ v052
	.byte W24
	.byte N48, Fs4, v040
	.byte W48
	.byte N24, Fs3 @ v040
	.byte W24
	.byte VOL, 9
	.byte N96, Bn4, v032
	.byte W04
	.byte VOL, 11
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W04
	.byte 15 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W03
	.byte 25 @ VOL
	.byte W04
	.byte 26 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W04
	.byte 33 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W04
	.byte 44 @ VOL
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
	.byte N72, As4 @ v032
	.byte W02
	.byte VOL, 51
	.byte W03
	.byte 50 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W04
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W04
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W04
	.byte 33 @ VOL
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
	.byte 23 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W04
	.byte 20 @ VOL
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
	.byte W04
	.byte 11 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte GOTO
		.word track_45_lbl_264461
	.byte FINE

track_45_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 94
	.byte PAN, c_v
	.byte PRIO, 109
	.byte W24
	.byte N06, Bn1, v056
	.byte W08
	.byte Bn1, v076 @ N06
	.byte W08
	.byte Bn1, v096 @ N06
	.byte W08
track_45_lbl_264546:
	.byte VOICE, 14
	.byte VOL, 94
	.byte N08, En1, v096
	.byte W12
	.byte N12, En1, v076
	.byte W36
	.byte VOICE, 0
	.byte VOL, 78
	.byte N36, Cs2, v032
	.byte W48
	.byte W96
	.byte W24
	.byte N08, Bn5, v020
	.byte W08
	.byte Bn5, v036 @ N08
	.byte W08
	.byte Bn5, v044 @ N08
	.byte W08
	.byte Bn5, v056 @ N08
	.byte W12
	.byte Bn5, v064 @ N08
	.byte W24
	.byte Bn5, v056 @ N08
	.byte W12
	.byte N08 @ Bn5, v056
	.byte W12
	.byte Bn5, v052 @ N08
	.byte W24
	.byte Bn5, v040 @ N08
	.byte W24
	.byte Bn5, v036 @ N08
	.byte W24
	.byte Bn5, v020 @ N08
	.byte W12
	.byte GOTO
		.word track_45_lbl_264546
	.byte FINE

track_45_2:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte PAN, c_v
	.byte PRIO, 108
	.byte W48
track_45_lbl_26458c:
	.byte VOL, 46
	.byte N92, En1, v076
	.byte W04
	.byte VOL, 26
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 48 @ VOL
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
	.byte 57 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W56
	.byte W03
	.byte 77 @ VOL
	.byte N92, En1, v088
	.byte W02
	.byte VOL, 77
	.byte W02
	.byte 76 @ VOL
	.byte W02
	.byte 75 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte N92 @ En1, v088
	.byte W02
	.byte VOL, 41
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 61 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W03
	.byte 63 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W01
	.byte N92 @ En1, v088
	.byte W02
	.byte VOL, 72
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W02
	.byte 57 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W02
	.byte 43 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 37 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W02
	.byte GOTO
		.word track_45_lbl_26458c
	.byte FINE

track_45_3:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 31
	.byte PAN, c_v+10
	.byte PRIO, 30
	.byte W48
track_45_lbl_26470c:
	.byte W96
	.byte VOL, 1
	.byte N96, Cs3, v036
	.byte W05
	.byte VOL, 3
	.byte W05
	.byte 4 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W05
	.byte 9 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W06
	.byte 17 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W06
	.byte 22 @ VOL
	.byte W06
	.byte 23 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W06
	.byte 26 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte N96, Bn2, v048
	.byte W05
	.byte VOL, 29
	.byte W06
	.byte 31 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W05
	.byte 39 @ VOL
	.byte W06
	.byte 40 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W05
	.byte 37 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W05
	.byte 26 @ VOL
	.byte N96, As2 @ v048
	.byte W06
	.byte VOL, 25
	.byte W06
	.byte 23 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W06
	.byte 20 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W06
	.byte 15 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W05
	.byte 12 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 9 @ VOL
	.byte W05
	.byte 7 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W16
	.byte GOTO
		.word track_45_lbl_26470c
	.byte FINE

track_45_4:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 31
	.byte PAN, c_v-10
	.byte PRIO, 29
	.byte W48
track_45_lbl_26478c:
	.byte W96
	.byte VOL, 1
	.byte N96, As2, v036
	.byte W05
	.byte VOL, 3
	.byte W05
	.byte 4 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W05
	.byte 9 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 12 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W06
	.byte 17 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W05
	.byte 20 @ VOL
	.byte W06
	.byte 22 @ VOL
	.byte W06
	.byte 23 @ VOL
	.byte W05
	.byte 25 @ VOL
	.byte W06
	.byte 26 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte N96, Gs2, v048
	.byte W05
	.byte VOL, 29
	.byte W06
	.byte 31 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W05
	.byte 39 @ VOL
	.byte W06
	.byte 40 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W05
	.byte 37 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W05
	.byte 26 @ VOL
	.byte N96, Fs2 @ v048
	.byte W06
	.byte VOL, 25
	.byte W06
	.byte 23 @ VOL
	.byte W05
	.byte 22 @ VOL
	.byte W06
	.byte 20 @ VOL
	.byte W06
	.byte 18 @ VOL
	.byte W05
	.byte 17 @ VOL
	.byte W06
	.byte 15 @ VOL
	.byte W06
	.byte 14 @ VOL
	.byte W05
	.byte 12 @ VOL
	.byte W06
	.byte 11 @ VOL
	.byte W06
	.byte 9 @ VOL
	.byte W05
	.byte 7 @ VOL
	.byte W06
	.byte 6 @ VOL
	.byte W06
	.byte 4 @ VOL
	.byte W16
	.byte GOTO
		.word track_45_lbl_26478c
	.byte FINE

track_45_5:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W48
track_45_lbl_26480c:
	.byte W96
	.byte VOL, 25
	.byte N96, En2, v056
	.byte W05
	.byte VOL, 26
	.byte W05
	.byte 28 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 31 @ VOL
	.byte W05
	.byte 33 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 36 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W05
	.byte 39 @ VOL
	.byte W06
	.byte 40 @ VOL
	.byte W06
	.byte 42 @ VOL
	.byte W05
	.byte 44 @ VOL
	.byte W06
	.byte 45 @ VOL
	.byte W06
	.byte 47 @ VOL
	.byte W05
	.byte 48 @ VOL
	.byte W06
	.byte 50 @ VOL
	.byte W06
	.byte 51 @ VOL
	.byte N96 @ En2, v056
	.byte W05
	.byte VOL, 53
	.byte W06
	.byte 55 @ VOL
	.byte W06
	.byte 56 @ VOL
	.byte W05
	.byte 58 @ VOL
	.byte W06
	.byte 59 @ VOL
	.byte W06
	.byte 61 @ VOL
	.byte W05
	.byte 62 @ VOL
	.byte W06
	.byte 64 @ VOL
	.byte W06
	.byte 62 @ VOL
	.byte W05
	.byte 61 @ VOL
	.byte W06
	.byte 59 @ VOL
	.byte W06
	.byte 58 @ VOL
	.byte W06
	.byte 56 @ VOL
	.byte W05
	.byte 55 @ VOL
	.byte W06
	.byte 53 @ VOL
	.byte W06
	.byte 51 @ VOL
	.byte W05
	.byte 50 @ VOL
	.byte N96 @ En2, v056
	.byte W06
	.byte VOL, 48
	.byte W06
	.byte 47 @ VOL
	.byte W05
	.byte 45 @ VOL
	.byte W06
	.byte 44 @ VOL
	.byte W06
	.byte 42 @ VOL
	.byte W05
	.byte 40 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W06
	.byte 37 @ VOL
	.byte W05
	.byte 36 @ VOL
	.byte W06
	.byte 34 @ VOL
	.byte W06
	.byte 33 @ VOL
	.byte W05
	.byte 31 @ VOL
	.byte W06
	.byte 29 @ VOL
	.byte W06
	.byte 28 @ VOL
	.byte W16
	.byte GOTO
		.word track_45_lbl_26480c
	.byte FINE

.align 2

track_45:
	.byte 6
	.byte 45
	.byte 130
	.byte 128
	.word 0x80a62f8
	.word track_45_0
	.word track_45_1
	.word track_45_2
	.word track_45_3
	.word track_45_4
	.word track_45_5

.align 2
