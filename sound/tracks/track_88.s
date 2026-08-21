.align 2

.global track_88

track_88_0:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 7
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 110
	.byte N96, Cn1, v100
	.byte W24
	.byte W96
	.byte W96
	.byte VOICE, 3
	.byte VOL, 15
	.byte PAN, c_v+16
	.byte N08, As4, v044
	.byte W08
	.byte Bn4 @ N08, v044
	.byte W08
	.byte Cn5 @ N08, v044
	.byte W08
	.byte Cs5 @ N08, v044
	.byte W08
	.byte Cn5 @ N08, v044
	.byte W08
	.byte Cs5 @ N08, v044
	.byte W08
	.byte Dn5 @ N08, v044
	.byte W08
	.byte Ds5 @ N08, v044
	.byte W08
	.byte As4, v036 @ N08
	.byte W08
	.byte Bn4 @ N08, v036
	.byte W08
	.byte Cn5 @ N08, v036
	.byte W08
	.byte Cs5 @ N08, v036
	.byte W08
track_88_lbl_26cdef:
	.byte N08, Cn5, v036
	.byte W08
	.byte Cs5, v040 @ N08
	.byte W08
	.byte Dn5, v044 @ N08
	.byte W08
	.byte Ds5, v052 @ N08
	.byte W08
	.byte As4, v056 @ N08
	.byte W08
	.byte Bn4, v060 @ N08
	.byte W08
	.byte Cn5, v064 @ N08
	.byte W08
	.byte Cs5, v072 @ N08
	.byte W08
	.byte Cn5, v076 @ N08
	.byte W08
	.byte Cs5, v080 @ N08
	.byte W08
	.byte Dn5, v084 @ N08
	.byte W08
	.byte Ds5, v092 @ N08
	.byte W08
	.byte As4, v096 @ N08
	.byte W08
	.byte Bn4, v092 @ N08
	.byte W08
	.byte Cn5, v084 @ N08
	.byte W08
	.byte Cs5, v080 @ N08
	.byte W08
	.byte Cn5, v076 @ N08
	.byte W08
	.byte Cs5, v072 @ N08
	.byte W08
	.byte Dn5, v064 @ N08
	.byte W08
	.byte Ds5, v060 @ N08
	.byte W08
	.byte As4, v056 @ N08
	.byte W08
	.byte Bn4, v052 @ N08
	.byte W08
	.byte Cn5, v044 @ N08
	.byte W08
	.byte Cs5, v040 @ N08
	.byte W08
	.byte GOTO
		.word track_88_lbl_26cdef
	.byte W02
	.byte FINE

track_88_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 78
	.byte PAN, c_v-10
	.byte PRIO, 109
	.byte N96, Cn3, v100
	.byte W24
	.byte W72
	.byte VOICE, 5
	.byte VOL, 11
	.byte TIE, Bn3, v040
	.byte W06
	.byte VOL, 12
	.byte W05
	.byte 14 @ VOL
	.byte W07
	.byte 14 @ VOL
	.byte W05
	.byte 15 @ VOL
	.byte W01
	.byte W03
	.byte 17 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W04
	.byte 25 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 62 @ VOL
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
	.byte 70 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte EOT @ Bn3, v040
	.byte VOL, 85
	.byte N96 @ Bn3, v040
	.byte W01
	.byte VOL, 84
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
track_88_lbl_26cf18:
	.byte VOL, 31
	.byte N96, Bn3, v040
	.byte W03
	.byte VOL, 33
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W04
	.byte 47 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W04
	.byte 66 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte N96 @ Bn3, v040
	.byte W03
	.byte VOL, 83
	.byte W03
	.byte 81 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
	.byte GOTO
		.word track_88_lbl_26cf18
	.byte W02
	.byte FINE

track_88_2:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v+10
	.byte PRIO, 108
	.byte N96, Cn1, v052
	.byte W24
	.byte W72
	.byte VOICE, 3
	.byte VOL, 11
	.byte N05, En4, v020
	.byte W01
	.byte VOL, 12
	.byte W04
	.byte N05, Fn4 @ v020
	.byte W05
	.byte En4 @ N05, v020
	.byte W03
	.byte VOL, 14
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W05
	.byte En4 @ N05, v020
	.byte W04
	.byte W01
	.byte Fn4 @ N05, v020
	.byte W02
	.byte VOL, 15
	.byte W03
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 17
	.byte W03
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 18
	.byte W03
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 20
	.byte W03
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 22
	.byte W04
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 22
	.byte W04
	.byte 23 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 25
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 26
	.byte W04
	.byte 28 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 29
	.byte W02
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 31
	.byte W02
	.byte 33 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 34
	.byte W02
	.byte 36 @ VOL
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 37
	.byte W03
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 39
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 44
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 53
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 59
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 67
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 77
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 84
	.byte W02
	.byte 83 @ VOL
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 81
	.byte W02
	.byte 80 @ VOL
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 78
	.byte W02
	.byte 77 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 76
	.byte W01
	.byte 75 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 73
	.byte W02
	.byte 72 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 70
	.byte W01
	.byte 70 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 67
	.byte W01
	.byte 66 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 65
	.byte W01
	.byte 64 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 62
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 59
	.byte W02
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 56
	.byte W03
	.byte 55 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 53
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 51
	.byte W01
	.byte 51 @ VOL
	.byte W03
	.byte 49 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 48
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 46
	.byte W03
	.byte 44 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 42
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 40
	.byte W03
	.byte 39 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 37
	.byte W03
	.byte 36 @ VOL
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 34
	.byte W03
	.byte 33 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
track_88_lbl_26d10f:
	.byte VOL, 31
	.byte W03
	.byte 33 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte N05, En4, v020
	.byte W01
	.byte VOL, 33
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 37
	.byte W03
	.byte 38 @ VOL
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 40
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 41
	.byte W03
	.byte 43 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 44
	.byte W03
	.byte 46 @ VOL
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 47
	.byte W03
	.byte 48 @ VOL
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 50
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 51
	.byte W03
	.byte 53 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 55
	.byte W03
	.byte 56 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 58
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 59
	.byte W03
	.byte 61 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 62
	.byte W02
	.byte 63 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 65
	.byte W02
	.byte 66 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 67
	.byte W03
	.byte 69 @ VOL
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 70
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 72
	.byte W03
	.byte 74 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 75
	.byte W01
	.byte 75 @ VOL
	.byte W02
	.byte 77 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 78
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 83
	.byte W01
	.byte 85 @ VOL
	.byte W03
	.byte 83 @ VOL
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 82
	.byte W01
	.byte 81 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 78
	.byte W02
	.byte 77 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 77
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 74
	.byte W01
	.byte 73 @ VOL
	.byte W02
	.byte 72 @ VOL
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 71
	.byte W02
	.byte 70 @ VOL
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 69
	.byte W03
	.byte 67 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 66
	.byte W02
	.byte 64 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 62
	.byte W03
	.byte 61 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 59
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 58
	.byte W03
	.byte 56 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 55
	.byte W03
	.byte 53 @ VOL
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 51
	.byte W02
	.byte 50 @ VOL
	.byte N05, Fn4 @ v020
	.byte W03
	.byte VOL, 48
	.byte W02
	.byte N05, En4 @ v020
	.byte W01
	.byte VOL, 47
	.byte W03
	.byte 45 @ VOL
	.byte W01
	.byte N05, Fn4 @ v020
	.byte W02
	.byte VOL, 44
	.byte W03
	.byte 42 @ VOL
	.byte N05, En4 @ v020
	.byte W03
	.byte VOL, 40
	.byte W02
	.byte N05, Fn4 @ v020
	.byte W01
	.byte VOL, 39
	.byte W03
	.byte 37 @ VOL
	.byte W01
	.byte N05, En4 @ v020
	.byte W02
	.byte VOL, 36
	.byte W02
	.byte 34 @ VOL
	.byte W01
	.byte N05, Fn4, v032
	.byte W02
	.byte VOL, 33
	.byte W01
	.byte GOTO
		.word track_88_lbl_26d10f
	.byte W02
	.byte FINE

track_88_3:
	.byte KEYSH, 0
	.byte PRIO, 1
	.byte W24
	.byte W72
	.byte VOICE, 5
	.byte VOL, 11
	.byte PAN, c_v-4
	.byte TIE, Fn3, v040
	.byte W06
	.byte VOL, 12
	.byte W05
	.byte 14 @ VOL
	.byte W12
	.byte 15 @ VOL
	.byte W01
	.byte W03
	.byte 17 @ VOL
	.byte W05
	.byte 18 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W04
	.byte 22 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W04
	.byte 25 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W03
	.byte 28 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 44 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W02
	.byte 56 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W02
	.byte 62 @ VOL
	.byte W01
	.byte 62 @ VOL
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
	.byte 70 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte EOT @ Fn3, v040
	.byte VOL, 85
	.byte N96 @ Fn3, v040
	.byte W01
	.byte VOL, 84
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W02
	.byte 79 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
track_88_lbl_26d30e:
	.byte VOL, 31
	.byte N96, Fn3, v040
	.byte W03
	.byte VOL, 33
	.byte W03
	.byte 34 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W04
	.byte 47 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W04
	.byte 66 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte N96 @ Fn3, v040
	.byte W03
	.byte VOL, 83
	.byte W03
	.byte 81 @ VOL
	.byte W02
	.byte 80 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W03
	.byte 70 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 66 @ VOL
	.byte W02
	.byte 64 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 44 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
	.byte GOTO
		.word track_88_lbl_26d30e
	.byte W02
	.byte FINE

.align 2

track_88:
	.byte 4
	.byte 88
	.byte 130
	.byte 128
	.word 0x80a64c0
	.word track_88_0
	.word track_88_1
	.word track_88_2
	.word track_88_3

.align 2
