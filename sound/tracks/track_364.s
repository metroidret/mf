.align 2

.global track_364

track_364_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 56
	.byte VOL, 37
	.byte PAN, c_v
	.byte N06, Cn2, v127
	.byte W06
	.byte VOICE, 57
	.byte N10, Cn2, v100
	.byte W10
	.byte VOICE, 58
	.byte N10 @ Cn2, v100
	.byte W10
	.byte VOICE, 59
	.byte N10, Cn2, v127
	.byte W10
	.byte VOICE, 60
	.byte N08 @ Cn2, v127
	.byte W08
	.byte FINE

track_364_1:
	.byte KEYSH, 0
	.byte VOICE, 15
	.byte VOL, 28
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 14
	.byte VOL, 42
	.byte N05, Cn3, v100
	.byte W05
	.byte VOICE, 13
	.byte N05, Cn3, v060
	.byte W05
	.byte VOICE, 55
	.byte VOL, 12
	.byte N24, Cn3, v080
	.byte W02
	.byte VOL, 15
	.byte W02
	.byte 17 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W08
	.byte FINE

.align 2

track_364:
	.byte 2
	.byte 0
	.byte 171
	.byte 0
	.word 0x80a6d54
	.word track_364_0
	.word track_364_1

.align 2
