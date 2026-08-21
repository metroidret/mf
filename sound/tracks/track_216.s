.align 2

.global track_216

track_216_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 0
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W08
	.byte VOL, 23
	.byte N36, Cn3, v127
	.byte W02
	.byte VOL, 28
	.byte W07
	.byte 33 @ VOL
	.byte W05
	.byte 34 @ VOL
	.byte W02
	.byte 34 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W02
	.byte 40 @ VOL
	.byte W02
	.byte 42 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W03
	.byte 91 @ VOL
	.byte W11
	.byte FINE

track_216_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 75
	.byte PAN, c_v
	.byte W08
	.byte N02, Cn3, v080
	.byte W02
	.byte Dn3, v100 @ N02
	.byte W02
	.byte En3, v127 @ N02
	.byte W02
	.byte Fn3, v100 @ N02
	.byte W02
	.byte Gn3, v080 @ N02
	.byte W02
	.byte An3, v100 @ N02
	.byte W02
	.byte Bn3, v127 @ N02
	.byte W02
	.byte Cn4, v100 @ N02
	.byte W02
	.byte Bn3, v080 @ N02
	.byte W02
	.byte An3, v100 @ N02
	.byte W02
	.byte VOICE, 4
	.byte N02, Cn3, v056
	.byte W02
	.byte Gs3, v092 @ N02
	.byte W02
	.byte Fs3, v068 @ N02
	.byte W02
	.byte Cs4, v100 @ N02
	.byte W02
	.byte An3, v076 @ N02
	.byte W02
	.byte En4, v127 @ N02
	.byte W02
	.byte En3, v088 @ N02
	.byte W02
	.byte An2, v080 @ N02
	.byte W02
	.byte Fn4, v052 @ N02
	.byte W12
	.byte FINE

.align 2

track_216:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6af0
	.word track_216_0
	.word track_216_1

.align 2
