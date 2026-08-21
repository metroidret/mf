.align 2

.global track_491

track_491_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 38
	.byte PAN, c_v
	.byte TIE, Gn2, v080
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte EOT @ Gn2, v080
	.byte FINE

track_491_1:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 17
	.byte PAN, c_v-14
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
	.byte W76
	.byte W96
	.byte W96
	.byte W96
	.byte FINE

.align 2

track_491:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_491_0
	.word track_491_1

.align 2
