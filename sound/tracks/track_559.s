.align 2

.global track_559

track_559_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 75
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 16
	.byte N07 @ Cn3, v127
	.byte W07
	.byte Cn3, v052 @ N07
	.byte W07
	.byte Cn3, v012 @ N07
	.byte W76
	.byte W01
	.byte W76
	.byte W01
	.byte FINE

track_559_1:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 12
	.byte PAN, c_v
	.byte W24
	.byte N01, An3, v052
	.byte W02
	.byte VOICE, 18
	.byte N03 @ An3, v052
	.byte W06
	.byte VOICE, 17
	.byte N01, Bn3 @ v052
	.byte W02
	.byte N01 @ Bn3, v052
	.byte W02
	.byte VOICE, 18
	.byte N03 @ Bn3, v052
	.byte W06
	.byte Gn3 @ N03, v052
	.byte W06
	.byte Bn3 @ N03, v052
	.byte W04
	.byte N03 @ Bn3, v052
	.byte W04
	.byte N03 @ Bn3, v052
	.byte W06
	.byte Dn3 @ N03, v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Dn3, v052
	.byte W02
	.byte N01 @ Dn3, v052
	.byte W04
	.byte Bn3 @ N01, v052
	.byte W02
	.byte N01 @ Bn3, v052
	.byte W04
	.byte VOICE, 18
	.byte N03, Gn3 @ v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Gn3, v052
	.byte W04
	.byte En3 @ N01, v052
	.byte W10
	.byte Bn3 @ N01, v052
	.byte W02
	.byte VOICE, 18
	.byte N03 @ Bn3, v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Bn3, v052
	.byte W04
	.byte En3 @ N01, v052
	.byte W04
	.byte VOICE, 18
	.byte N03, Cn3 @ v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Cn3, v052
	.byte W02
	.byte VOICE, 18
	.byte N03 @ Cn3, v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Cn3, v052
	.byte W04
	.byte En3 @ N01, v052
	.byte W04
	.byte Bn3 @ N01, v052
	.byte W02
	.byte VOICE, 18
	.byte N03 @ Bn3, v052
	.byte W04
	.byte N03 @ Bn3, v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Bn3, v052
	.byte W04
	.byte VOICE, 18
	.byte N03, Gn3 @ v052
	.byte W06
	.byte VOICE, 17
	.byte N01, Bn3 @ v052
	.byte W02
	.byte N01 @ Bn3, v052
	.byte W04
	.byte VOICE, 18
	.byte N03, Gn3 @ v052
	.byte W04
	.byte N03 @ Gn3, v052
	.byte W04
	.byte N03 @ Gn3, v052
	.byte W06
	.byte Bn3 @ N03, v052
	.byte W04
	.byte VOICE, 17
	.byte N01 @ Bn3, v052
	.byte W01
	.byte FINE

track_559_2:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 15
	.byte PAN, c_v
	.byte W24
	.byte N04, An3, v052
	.byte W04
	.byte Fn3, v056 @ N04
	.byte W04
	.byte Gn3, v060 @ N04
	.byte W04
	.byte Cn3 @ N04, v060
	.byte W04
	.byte N04 @ Cn3, v060
	.byte W04
	.byte Gn3 @ N04, v060
	.byte W04
	.byte An3 @ N04, v060
	.byte W04
	.byte Cn4, v080 @ N04
	.byte W04
	.byte Cn4, v040 @ N04
	.byte W04
	.byte Cn4, v020 @ N04
	.byte W36
	.byte W24
	.byte VOL, 25
	.byte N04, An3, v052
	.byte W04
	.byte Fn3, v056 @ N04
	.byte W04
	.byte Gn3, v060 @ N04
	.byte W04
	.byte Cn3 @ N04, v060
	.byte W04
	.byte N04 @ Cn3, v060
	.byte W04
	.byte Gn3 @ N04, v060
	.byte W04
	.byte An3 @ N04, v060
	.byte W04
	.byte Cn4, v080 @ N04
	.byte W04
	.byte Cn4, v040 @ N04
	.byte W04
	.byte Cn4, v020 @ N04
	.byte W17
	.byte FINE

.align 2

track_559:
	.byte 3
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a7798
	.word track_559_0
	.word track_559_1
	.word track_559_2

.align 2
