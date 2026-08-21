.align 2

.global track_213

track_213_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W08
	.byte VOL, 18
	.byte N36, Cn3, v127
	.byte W02
	.byte VOL, 21
	.byte W07
	.byte 23 @ VOL
	.byte W05
	.byte 24 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W03
	.byte 29 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W03
	.byte 72 @ VOL
	.byte W07
	.byte FINE

track_213_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 47
	.byte PAN, c_v
	.byte W08
	.byte N04, Cn3, v080
	.byte W04
	.byte Dn3, v100 @ N04
	.byte W04
	.byte En3, v127 @ N04
	.byte W04
	.byte Fn3, v100 @ N04
	.byte W04
	.byte Gn3, v080 @ N04
	.byte W04
	.byte An3, v100 @ N04
	.byte W04
	.byte Bn3, v127 @ N04
	.byte W04
	.byte Cn4, v100 @ N04
	.byte W04
	.byte Bn3, v080 @ N04
	.byte W04
	.byte An3, v100 @ N04
	.byte W08
	.byte FINE

.align 2

track_213:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6af0
	.word track_213_0
	.word track_213_1

.align 2
