.align 2

.global track_262

track_262_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 63
	.byte PAN, c_v
	.byte W03
	.byte N09, Cn3, v080
	.byte W09
	.byte N05, Cn3, v127
	.byte W05
	.byte Cn3, v060 @ N05
	.byte W05
	.byte Cn3, v040 @ N05
	.byte W05
	.byte Cn3, v020 @ N05
	.byte W13
	.byte VOICE, 42
	.byte VOL, 90
	.byte N05, Gs2, v080
	.byte W10
	.byte N03, Cs2, v127
	.byte W22
	.byte FINE

track_262_1:
	.byte KEYSH, 0
	.byte VOICE, 43
	.byte VOL, 90
	.byte PAN, c_v
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3 @ v127
	.byte W14
	.byte Dn3, v100 @ N14
	.byte W14
	.byte N19, Cn3, v060
	.byte W19
	.byte Cn3, v020 @ N19
	.byte W19
	.byte FINE

.align 2

track_262:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_262_0
	.word track_262_1

.align 2
