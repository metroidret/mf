.align 2

.global track_161

track_161_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 113
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v060 @ N15
	.byte W15
	.byte N18, Cn3, v020
	.byte W18
	.byte FINE

track_161_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 103
	.byte PAN, c_v
	.byte N13, Cn2, v080
	.byte W16
	.byte VOL, 75
	.byte N08, Cn2, v127
	.byte W08
	.byte N15, Fn2, v100
	.byte W08
	.byte VOL, 75
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W10
	.byte FINE

.align 2

track_161:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a8008
	.word track_161_0
	.word track_161_1

.align 2
