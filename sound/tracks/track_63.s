.align 2

.global track_63

track_63_0:
	.byte KEYSH, 0
track_63_lbl_27193a:
	.byte TEMPO, 72
	.byte VOICE, 0
	.byte VOL, 127
	.byte PRIO, 110
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v072
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v076
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v076
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v080
	.byte W12
track_63_lbl_271962:
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v052
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v064
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3 @ v068
	.byte W12
	.byte N06, Cn2 @ v068
	.byte W12
	.byte N12, Fs3 @ v068
	.byte W12
	.byte PEND
track_63_lbl_271980:
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v072
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v076
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v076
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v080
	.byte W12
	.byte PEND
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
track_63_lbl_2719b5:
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v052
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3, v064
	.byte W12
	.byte N06, Cn2, v068
	.byte W12
	.byte N12, Fs3 @ v068
	.byte W06
	.byte N06, Cn2 @ v068
	.byte W18
	.byte N06 @ Cn2, v068
	.byte N12, Fs3 @ v068
	.byte W12
	.byte PEND
	.byte PRIO, 110
	.byte N06, Cn2 @ v068
	.byte W06
	.byte PRIO, 0
	.byte W06
	.byte PRIO, 110
	.byte N12, Fs3, v072
	.byte W12
	.byte N06, Cn2, v068
	.byte W06
	.byte PRIO, 0
	.byte W06
	.byte PRIO, 110
	.byte N12, Fs3, v076
	.byte W12
	.byte N06, Cn2, v068
	.byte W06
	.byte PRIO, 0
	.byte W06
	.byte PRIO, 110
	.byte N12, Fs3, v076
	.byte W12
	.byte N06, Cn2, v068
	.byte W06
	.byte PRIO, 0
	.byte W06
	.byte PRIO, 110
	.byte N12, Fs3, v080
	.byte W12
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_2719b5
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_2719b5
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_271962
	.byte PATT
		.word track_63_lbl_271980
	.byte PATT
		.word track_63_lbl_2719b5
	.byte GOTO
		.word track_63_lbl_27193a
	.byte W24
	.byte FINE

track_63_1:
	.byte KEYSH, 0
track_63_lbl_271a71:
	.byte VOICE, 3
	.byte VOL, 127
	.byte PAN, c_v-1
	.byte PRIO, 110
	.byte N04, Cs2, v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Fs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs4 @ v080
	.byte W06
	.byte PAN, c_v+1
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, En4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, Fs3 @ v080
	.byte W06
	.byte Gs4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v080
	.byte W06
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, Fs4 @ v080
	.byte W06
	.byte En5 @ N04, v080
	.byte W06
track_63_lbl_271abe:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, Fs3, v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, En3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, En4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fs3 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Bn3 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, Fs4 @ v080
	.byte W06
	.byte Cs4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v080
	.byte W06
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v080
	.byte W06
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, Bn3 @ v080
	.byte W06
	.byte Bn4 @ N04, v080
	.byte W06
	.byte PEND
track_63_lbl_271b08:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, Cs2, v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Fs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, En4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, Fs3 @ v080
	.byte W06
	.byte Gs4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v080
	.byte W06
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, Fs4 @ v080
	.byte W06
	.byte En5 @ N04, v080
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_271abe
	.byte PATT
		.word track_63_lbl_271b08
	.byte PATT
		.word track_63_lbl_271abe
	.byte PATT
		.word track_63_lbl_271b08
track_63_lbl_271b66:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, Fs3, v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, En3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, En4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fs3 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Bn3 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, Fs4 @ v080
	.byte W06
	.byte Cs4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v080
	.byte W06
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v080
	.byte W06
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte PRIO, 0
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PRIO, 110
	.byte Bn4 @ N04, v080
	.byte W06
	.byte PEND
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte PRIO, 0
	.byte N04, Cs2 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte PRIO, 110
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte PRIO, 0
	.byte N04, Cs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Fs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cs4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte PRIO, 110
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte PRIO, 0
	.byte N04, Cs3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, En4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, Fs3 @ v080
	.byte W06
	.byte PRIO, 110
	.byte Gs4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte PRIO, 0
	.byte N04, En3 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v080
	.byte W06
	.byte PRIO, 110
	.byte Gs3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte PRIO, 0
	.byte N04, Fs4 @ v080
	.byte W06
	.byte En5 @ N04, v080
	.byte W06
	.byte PATT
		.word track_63_lbl_271abe
	.byte PATT
		.word track_63_lbl_271b08
	.byte PATT
		.word track_63_lbl_271abe
	.byte PATT
		.word track_63_lbl_271b08
	.byte PATT
		.word track_63_lbl_271abe
	.byte PATT
		.word track_63_lbl_271b08
	.byte PATT
		.word track_63_lbl_271b66
track_63_lbl_271c31:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, Fn2, v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Cn4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fn3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, As3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fn4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Cn4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fn3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gs4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, As3 @ v080
	.byte W06
	.byte Cn5 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, Gs3 @ v080
	.byte W06
	.byte Ds4 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, Gs4 @ v080
	.byte W06
	.byte Cn4 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, As4 @ v080
	.byte W06
	.byte Gs5 @ N04, v080
	.byte W06
	.byte PEND
track_63_lbl_271c7b:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, As3, v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Cn4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fn4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cn4 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gs4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, As3 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Ds4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, As4 @ v080
	.byte W06
	.byte Fn4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, Gs3 @ v080
	.byte W06
	.byte Cn4 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, Gs4 @ v080
	.byte W06
	.byte Cn4 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, Ds4 @ v080
	.byte W06
	.byte Ds5 @ N04, v080
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_271c31
	.byte PATT
		.word track_63_lbl_271c7b
	.byte PATT
		.word track_63_lbl_271c31
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, As3, v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Cn4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Fn4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gs3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Cn4 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gs4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, As3 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Ds4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, As4 @ v080
	.byte W06
	.byte Fn4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, Gs3 @ v080
	.byte W06
	.byte Cn4 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, Gs4 @ v080
	.byte W06
	.byte Cn4 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte PRIO, 0
	.byte N04, Ds4 @ v080
	.byte W06
	.byte PRIO, 110
	.byte Ds5 @ N04, v080
	.byte W06
track_63_lbl_271d21:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, En2, v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, En3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, An3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, En4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, En3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gn4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, An3 @ v080
	.byte W06
	.byte Bn4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, Gn3 @ v080
	.byte W06
	.byte Dn4 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, Gn4 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, An4 @ v080
	.byte W06
	.byte Gn5 @ N04, v080
	.byte W06
	.byte PEND
track_63_lbl_271d6b:
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, An3, v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, En4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gn3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gn4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, An3 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Dn4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, An4 @ v080
	.byte W06
	.byte En4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, Gn3 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, Gn4 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte N04, Dn4 @ v080
	.byte W06
	.byte Dn5 @ N04, v080
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_271d21
	.byte PATT
		.word track_63_lbl_271d6b
	.byte PATT
		.word track_63_lbl_271d21
	.byte VOICE, 3
	.byte PAN, c_v-1
	.byte N04, An3, v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, En4 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Gn3 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, Bn3 @ v080
	.byte W06
	.byte PAN, c_v+34
	.byte N04, Gn4 @ v080
	.byte W06
	.byte PAN, c_v-1
	.byte N04, An3 @ v080
	.byte W06
	.byte PAN, c_v-32
	.byte N04, Dn4 @ v080
	.byte W06
	.byte VOICE, 4
	.byte PAN, c_v-1
	.byte N04, An4 @ v080
	.byte W06
	.byte En4 @ N04, v080
	.byte W06
	.byte VOICE, 5
	.byte N04, Gn3 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 4
	.byte N04, Gn4 @ v080
	.byte W06
	.byte Bn3 @ N04, v080
	.byte W06
	.byte VOICE, 3
	.byte PRIO, 0
	.byte N04, Dn4 @ v080
	.byte W06
	.byte PRIO, 110
	.byte Dn5 @ N04, v080
	.byte W06
	.byte GOTO
		.word track_63_lbl_271a71
	.byte FINE

track_63_2:
	.byte KEYSH, 0
track_63_lbl_271e19:
	.byte VOL, 127
	.byte W12
	.byte VOICE, 3
	.byte N04, Cs2, v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte Cs3 @ N04, v032
	.byte W06
	.byte Fs3 @ N04, v032
	.byte W06
	.byte Cs4 @ N04, v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte Cs3 @ N04, v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Fs3 @ v032
	.byte W06
	.byte Gs4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
track_63_lbl_271e45:
	.byte VOICE, 3
	.byte N04, Fs4, v032
	.byte W06
	.byte En5 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, Fs3 @ v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte Cs4 @ N04, v032
	.byte W06
	.byte En3 @ N04, v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte Fs3 @ N04, v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Fs4 @ v032
	.byte W06
	.byte Cs4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte PEND
track_63_lbl_271e76:
	.byte VOICE, 3
	.byte N04, Bn3, v032
	.byte W06
	.byte Bn4 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, Cs2 @ v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte Cs3 @ N04, v032
	.byte W06
	.byte Fs3 @ N04, v032
	.byte W06
	.byte Cs4 @ N04, v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte Cs3 @ N04, v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Fs3 @ v032
	.byte W06
	.byte Gs4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, En3 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, En4 @ v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_271e45
	.byte PATT
		.word track_63_lbl_271e76
	.byte PATT
		.word track_63_lbl_271e45
	.byte PATT
		.word track_63_lbl_271e76
	.byte PATT
		.word track_63_lbl_271e45
	.byte PATT
		.word track_63_lbl_271e76
	.byte PATT
		.word track_63_lbl_271e45
	.byte PATT
		.word track_63_lbl_271e76
	.byte PATT
		.word track_63_lbl_271e45
	.byte PATT
		.word track_63_lbl_271e76
	.byte PATT
		.word track_63_lbl_271e45
	.byte PATT
		.word track_63_lbl_271e76
	.byte PATT
		.word track_63_lbl_271e45
	.byte VOICE, 3
	.byte N04, Bn3, v032
	.byte W06
	.byte Bn4 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, Fn2 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte Fn3 @ N04, v032
	.byte W06
	.byte As3 @ N04, v032
	.byte W06
	.byte Fn4 @ N04, v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte Fn3 @ N04, v032
	.byte W06
	.byte Gs4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, As3 @ v032
	.byte W06
	.byte Cn5 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, Gs3 @ v032
	.byte W06
	.byte Ds4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Gs4 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
track_63_lbl_271f18:
	.byte VOICE, 3
	.byte N04, As4, v032
	.byte W06
	.byte Gs5 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, As3 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte Fn4 @ N04, v032
	.byte W06
	.byte Gs3 @ N04, v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte Gs4 @ N04, v032
	.byte W06
	.byte As3 @ N04, v032
	.byte W06
	.byte Ds4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, As4 @ v032
	.byte W06
	.byte Fn4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, Gs3 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Gs4 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte PEND
track_63_lbl_271f49:
	.byte VOICE, 3
	.byte N04, Ds4, v032
	.byte W06
	.byte Ds5 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, Fn2 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte Fn3 @ N04, v032
	.byte W06
	.byte As3 @ N04, v032
	.byte W06
	.byte Fn4 @ N04, v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte Fn3 @ N04, v032
	.byte W06
	.byte Gs4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, As3 @ v032
	.byte W06
	.byte Cn5 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, Gs3 @ v032
	.byte W06
	.byte Ds4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Gs4 @ v032
	.byte W06
	.byte Cn4 @ N04, v032
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_271f18
	.byte PATT
		.word track_63_lbl_271f49
	.byte PATT
		.word track_63_lbl_271f18
	.byte VOICE, 3
	.byte N04, Ds4, v032
	.byte W06
	.byte Ds5 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, En2 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte En3 @ N04, v032
	.byte W06
	.byte An3 @ N04, v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte En3 @ N04, v032
	.byte W06
	.byte Gn4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, An3 @ v032
	.byte W06
	.byte Bn4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, Gn3 @ v032
	.byte W06
	.byte Dn4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Gn4 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
track_63_lbl_271fb9:
	.byte VOICE, 3
	.byte N04, An4, v032
	.byte W06
	.byte Gn5 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, An3 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte Gn3 @ N04, v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte Gn4 @ N04, v032
	.byte W06
	.byte An3 @ N04, v032
	.byte W06
	.byte Dn4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, An4 @ v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, Gn3 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Gn4 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte PEND
track_63_lbl_271fea:
	.byte VOICE, 3
	.byte N04, Dn4, v032
	.byte W06
	.byte Dn5 @ N04, v032
	.byte W06
	.byte VOICE, 3
	.byte N04, En2 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte En3 @ N04, v032
	.byte W06
	.byte An3 @ N04, v032
	.byte W06
	.byte En4 @ N04, v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte En3 @ N04, v032
	.byte W06
	.byte Gn4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, An3 @ v032
	.byte W06
	.byte Bn4 @ N04, v032
	.byte W06
	.byte VOICE, 5
	.byte N04, Gn3 @ v032
	.byte W06
	.byte Dn4 @ N04, v032
	.byte W06
	.byte VOICE, 4
	.byte N04, Gn4 @ v032
	.byte W06
	.byte Bn3 @ N04, v032
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_271fb9
	.byte PATT
		.word track_63_lbl_271fea
	.byte PATT
		.word track_63_lbl_271fb9
	.byte GOTO
		.word track_63_lbl_271e19
	.byte VOICE, 3
	.byte N04, Dn4, v032
	.byte W06
	.byte Dn5 @ N04, v032
	.byte W18
	.byte FINE

track_63_3:
	.byte KEYSH, 0
track_63_lbl_27203a:
	.byte VOICE, 26
	.byte VOL, 127
	.byte PRIO, 110
	.byte TIE, Cs2, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte EOT @ Cs2, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte TIE @ Cs2, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte EOT @ Cs2, v127
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
	.byte GOTO
		.word track_63_lbl_27203a
	.byte FINE

track_63_4:
	.byte KEYSH, 0
track_63_lbl_27206a:
	.byte VOICE, 21
	.byte VOL, 127
	.byte PRIO, 110
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte PRIO, 110
	.byte TIE, Gs3, v008
	.byte W96
	.byte An3 @ TIE, v008
	.byte W96
	.byte EOT, Gs3 @ v008
	.byte TIE, Bn3 @ v008
	.byte W96
	.byte EOT, An3 @ v008
	.byte TIE, En4 @ v008
	.byte W96
	.byte EOT, Bn3 @ v008
	.byte VOL, 127
	.byte W06
	.byte 119 @ VOL
	.byte W06
	.byte 111 @ VOL
	.byte W06
	.byte 103 @ VOL
	.byte W06
	.byte 95 @ VOL
	.byte W06
	.byte 87 @ VOL
	.byte W06
	.byte 79 @ VOL
	.byte W06
	.byte 71 @ VOL
	.byte W06
	.byte 63 @ VOL
	.byte W06
	.byte 55 @ VOL
	.byte W06
	.byte 47 @ VOL
	.byte W06
	.byte 39 @ VOL
	.byte W06
	.byte 31 @ VOL
	.byte W06
	.byte 23 @ VOL
	.byte W06
	.byte 15 @ VOL
	.byte W06
	.byte 7 @ VOL
	.byte W06
	.byte EOT @ Bn3, v008
	.byte VOL, 0
	.byte W96
	.byte W96
	.byte W96
	.byte VOICE, 21
	.byte VOL, 127
	.byte PRIO, 110
	.byte TIE, Gs3 @ v008
	.byte W96
	.byte An3 @ TIE, v008
	.byte W96
	.byte EOT, Gs3 @ v008
	.byte TIE, Bn3 @ v008
	.byte W96
	.byte EOT, An3 @ v008
	.byte TIE, En4 @ v008
	.byte W96
	.byte EOT, Bn3 @ v008
	.byte TIE, Fn4 @ v008
	.byte W96
	.byte EOT, En4 @ v008
	.byte W96
	.byte EOT @ En4, v008
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
	.byte GOTO
		.word track_63_lbl_27206a
	.byte FINE

track_63_5:
	.byte KEYSH, 0
track_63_lbl_2720df:
	.byte VOICE, 18
	.byte VOL, 127
	.byte N96, Dn2, v127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte N96 @ Dn2, v127
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
	.byte GOTO
		.word track_63_lbl_2720df
	.byte FINE

track_63_6:
	.byte KEYSH, 0
track_63_lbl_27210b:
	.byte VOICE, 38
	.byte VOL, 127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_63_lbl_272113:
	.byte PAN, c_v-1
	.byte N03, Cs4, v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Gs5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Cs5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Fs5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Cs6 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Gs5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Cs5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, En6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fs5 @ v036
	.byte W06
	.byte Gs6 @ N03, v036
	.byte W06
	.byte En5 @ N03, v036
	.byte W06
	.byte Bn5 @ N03, v036
	.byte W06
	.byte En6 @ N03, v036
	.byte W06
	.byte Gs5 @ N03, v036
	.byte W06
	.byte Fs6 @ N03, v036
	.byte W06
	.byte En7 @ N03, v036
	.byte W06
	.byte PEND
track_63_lbl_272150:
	.byte PAN, c_v-1
	.byte N03, Fs5, v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Gs5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Cs6 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, En5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Gs5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, En6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fs5 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Bn5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fs6 @ v036
	.byte W06
	.byte Cs6 @ N03, v036
	.byte W06
	.byte En5 @ N03, v036
	.byte W06
	.byte Gs5 @ N03, v036
	.byte W06
	.byte En6 @ N03, v036
	.byte W06
	.byte Gs5 @ N03, v036
	.byte W06
	.byte Bn5 @ N03, v036
	.byte W06
	.byte Bn6 @ N03, v036
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_272113
	.byte PATT
		.word track_63_lbl_272150
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte PATT
		.word track_63_lbl_272113
	.byte PATT
		.word track_63_lbl_272150
	.byte PATT
		.word track_63_lbl_272113
	.byte PATT
		.word track_63_lbl_272150
track_63_lbl_2721af:
	.byte PAN, c_v-1
	.byte N03, Fn4, v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Cn6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fn5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, As5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fn6 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Cn6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fn5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Gs6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, As5 @ v036
	.byte W06
	.byte Cn7 @ N03, v036
	.byte W06
	.byte Gs5 @ N03, v036
	.byte W06
	.byte Ds6 @ N03, v036
	.byte W06
	.byte Gs6 @ N03, v036
	.byte W06
	.byte Cn6 @ N03, v036
	.byte W06
	.byte As6 @ N03, v036
	.byte W06
	.byte Gs7 @ N03, v036
	.byte W06
	.byte PEND
track_63_lbl_2721ec:
	.byte PAN, c_v-1
	.byte N03, As5, v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Cn6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Fn6 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Gs5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Cn6 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Gs6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, As5 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Ds6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, As6 @ v036
	.byte W06
	.byte Fn6 @ N03, v036
	.byte W06
	.byte Gs5 @ N03, v036
	.byte W06
	.byte Cn6 @ N03, v036
	.byte W06
	.byte Gs6 @ N03, v036
	.byte W06
	.byte Cn6 @ N03, v036
	.byte W06
	.byte Ds6 @ N03, v036
	.byte W06
	.byte Ds7 @ N03, v036
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_2721af
	.byte PATT
		.word track_63_lbl_2721ec
	.byte PATT
		.word track_63_lbl_2721af
	.byte PATT
		.word track_63_lbl_2721ec
track_63_lbl_27223d:
	.byte PAN, c_v-1
	.byte N03, En4, v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Bn5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, En5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, An5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, En6 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Bn5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, En5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Gn6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, An5 @ v036
	.byte W06
	.byte Bn6 @ N03, v036
	.byte W06
	.byte Gn5 @ N03, v036
	.byte W06
	.byte Dn6 @ N03, v036
	.byte W06
	.byte Gn6 @ N03, v036
	.byte W06
	.byte Bn5 @ N03, v036
	.byte W06
	.byte An6 @ N03, v036
	.byte W06
	.byte Gn7 @ N03, v036
	.byte W06
	.byte PEND
track_63_lbl_27227a:
	.byte PAN, c_v-1
	.byte N03, An5, v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Bn5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, En6 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Gn5 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, Bn5 @ v036
	.byte W06
	.byte PAN, c_v-32
	.byte N03, Gn6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, An5 @ v036
	.byte W06
	.byte PAN, c_v+34
	.byte N03, Dn6 @ v036
	.byte W06
	.byte PAN, c_v-1
	.byte N03, An6 @ v036
	.byte W06
	.byte En6 @ N03, v036
	.byte W06
	.byte Gn5 @ N03, v036
	.byte W06
	.byte Bn5 @ N03, v036
	.byte W06
	.byte Gn6 @ N03, v036
	.byte W06
	.byte Bn5 @ N03, v036
	.byte W06
	.byte Dn6 @ N03, v036
	.byte W06
	.byte Dn7 @ N03, v036
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_27223d
	.byte PATT
		.word track_63_lbl_27227a
	.byte PATT
		.word track_63_lbl_27223d
	.byte PATT
		.word track_63_lbl_27227a
	.byte GOTO
		.word track_63_lbl_27210b
	.byte FINE

track_63_7:
	.byte KEYSH, 0
track_63_lbl_2722d3:
	.byte VOICE, 39
	.byte VOL, 127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
track_63_lbl_2722db:
	.byte W12
	.byte N03, Cs4, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cs5 @ N03, v016
	.byte W06
	.byte Fs5 @ N03, v016
	.byte W06
	.byte Cs6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cs5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Fs5 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte PEND
track_63_lbl_2722fb:
	.byte N03, Fs6, v016
	.byte W06
	.byte En7 @ N03, v016
	.byte W06
	.byte Fs5 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cs6 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Fs5 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte Fs6 @ N03, v016
	.byte W06
	.byte Cs6 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte PEND
track_63_lbl_27231e:
	.byte N03, Bn5, v016
	.byte W06
	.byte Bn6 @ N03, v016
	.byte W06
	.byte Cs4 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cs5 @ N03, v016
	.byte W06
	.byte Fs5 @ N03, v016
	.byte W06
	.byte Cs6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cs5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Fs5 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_2722fb
	.byte N03, Bn5, v016
	.byte W06
	.byte Bn6 @ N03, v016
	.byte W90
	.byte W96
	.byte W96
	.byte W96
	.byte PATT
		.word track_63_lbl_2722db
	.byte PATT
		.word track_63_lbl_2722fb
	.byte PATT
		.word track_63_lbl_27231e
	.byte PATT
		.word track_63_lbl_2722fb
	.byte N03, Bn5, v016
	.byte W06
	.byte Bn6 @ N03, v016
	.byte W06
	.byte Fn4 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Fn5 @ N03, v016
	.byte W06
	.byte As5 @ N03, v016
	.byte W06
	.byte Fn6 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Fn5 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte As5 @ N03, v016
	.byte W06
	.byte Cn7 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Ds6 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
track_63_lbl_272385:
	.byte N03, As6, v016
	.byte W06
	.byte Gs7 @ N03, v016
	.byte W06
	.byte As5 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Fn6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte As5 @ N03, v016
	.byte W06
	.byte Ds6 @ N03, v016
	.byte W06
	.byte As6 @ N03, v016
	.byte W06
	.byte Fn6 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte PEND
track_63_lbl_2723a8:
	.byte N03, Ds6, v016
	.byte W06
	.byte Ds7 @ N03, v016
	.byte W06
	.byte Fn4 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Fn5 @ N03, v016
	.byte W06
	.byte As5 @ N03, v016
	.byte W06
	.byte Fn6 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte Fn5 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte As5 @ N03, v016
	.byte W06
	.byte Cn7 @ N03, v016
	.byte W06
	.byte Gs5 @ N03, v016
	.byte W06
	.byte Ds6 @ N03, v016
	.byte W06
	.byte Gs6 @ N03, v016
	.byte W06
	.byte Cn6 @ N03, v016
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_272385
	.byte PATT
		.word track_63_lbl_2723a8
	.byte PATT
		.word track_63_lbl_272385
	.byte N03, Ds6, v016
	.byte W06
	.byte Ds7 @ N03, v016
	.byte W06
	.byte En4 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte An5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte Gn6 @ N03, v016
	.byte W06
	.byte An5 @ N03, v016
	.byte W06
	.byte Bn6 @ N03, v016
	.byte W06
	.byte Gn5 @ N03, v016
	.byte W06
	.byte Dn6 @ N03, v016
	.byte W06
	.byte Gn6 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
track_63_lbl_2723fc:
	.byte N03, An6, v016
	.byte W06
	.byte Gn7 @ N03, v016
	.byte W06
	.byte An5 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Gn5 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte Gn6 @ N03, v016
	.byte W06
	.byte An5 @ N03, v016
	.byte W06
	.byte Dn6 @ N03, v016
	.byte W06
	.byte An6 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Gn5 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte Gn6 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte PEND
track_63_lbl_27241f:
	.byte N03, Dn6, v016
	.byte W06
	.byte Dn7 @ N03, v016
	.byte W06
	.byte En4 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte An5 @ N03, v016
	.byte W06
	.byte En6 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte En5 @ N03, v016
	.byte W06
	.byte Gn6 @ N03, v016
	.byte W06
	.byte An5 @ N03, v016
	.byte W06
	.byte Bn6 @ N03, v016
	.byte W06
	.byte Gn5 @ N03, v016
	.byte W06
	.byte Dn6 @ N03, v016
	.byte W06
	.byte Gn6 @ N03, v016
	.byte W06
	.byte Bn5 @ N03, v016
	.byte W06
	.byte PEND
	.byte PATT
		.word track_63_lbl_2723fc
	.byte PATT
		.word track_63_lbl_27241f
	.byte PATT
		.word track_63_lbl_2723fc
	.byte GOTO
		.word track_63_lbl_2722d3
	.byte N03, Dn6, v016
	.byte W06
	.byte Dn7 @ N03, v016
	.byte W18
	.byte FINE

track_63_8:
	.byte KEYSH, 0
track_63_lbl_27245f:
	.byte VOICE, 40
	.byte MOD, 2
	.byte VOL, 127
	.byte LFOS, 80
	.byte LFODL, 32
	.byte PRIO, 110
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
	.byte N24, Fn2, v044
	.byte W24
	.byte Gs2 @ N24, v044
	.byte W24
	.byte N72, Gn2 @ v044
	.byte W72
	.byte N24, Ds2 @ v044
	.byte W24
	.byte N48, Fn2 @ v044
	.byte W48
	.byte TIE, Cn2 @ v044
	.byte W48
	.byte W72
	.byte EOT @ Cn2, v044
	.byte W24
	.byte W96
	.byte W96
	.byte W48
	.byte N24, En2 @ v044
	.byte W24
	.byte Gn2 @ N24, v044
	.byte W24
	.byte N72, Fs2 @ v044
	.byte W72
	.byte N24, Dn2 @ v044
	.byte W24
	.byte N96, En2 @ v044
	.byte W96
	.byte Bn2 @ N96, v044
	.byte W96
	.byte GOTO
		.word track_63_lbl_27245f
	.byte W24
	.byte FINE

track_63_9:
	.byte KEYSH, 0
track_63_lbl_2724af:
	.byte VOICE, 40
	.byte MOD, 2
	.byte VOL, 127
	.byte LFOS, 80
	.byte LFODL, 32
	.byte BEND, c_v+4
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
	.byte W72
	.byte N24, Fn2, v016
	.byte W24
	.byte Gs2 @ N24, v016
	.byte W24
	.byte N72, Gn2 @ v016
	.byte W72
	.byte N24, Ds2 @ v016
	.byte W24
	.byte N48, Fn2 @ v016
	.byte W48
	.byte TIE, Cn2 @ v016
	.byte W24
	.byte W96
	.byte EOT @ Cn2, v016
	.byte W96
	.byte W96
	.byte W72
	.byte N24, En2 @ v016
	.byte W24
	.byte Gn2 @ N24, v016
	.byte W24
	.byte N72, Fs2 @ v016
	.byte W72
	.byte N24, Dn2 @ v016
	.byte W24
	.byte N96, En2 @ v016
	.byte W72
	.byte W24
	.byte Bn2 @ N96, v016
	.byte W72
	.byte GOTO
		.word track_63_lbl_2724af
	.byte W24
	.byte FINE

.align 2

track_63:
	.byte 10
	.byte 63
	.byte 130
	.byte 128
	.word 0x80a8554
	.word track_63_0
	.word track_63_1
	.word track_63_2
	.word track_63_3
	.word track_63_4
	.word track_63_5
	.word track_63_6
	.word track_63_7
	.word track_63_8
	.word track_63_9

.align 2
