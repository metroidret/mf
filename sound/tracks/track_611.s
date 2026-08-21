.align 2

.global track_611

track_611_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 75
	.byte PAN, c_v
	.byte N05, Dn2, v127
	.byte W06
	.byte Dn2, v112 @ N05
	.byte W07
	.byte N30, Cn2, v127
	.byte W01
	.byte VOL, 75
	.byte W02
	.byte 73 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W02
	.byte 69 @ VOL
	.byte W02
	.byte 66 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_611:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_611_0

.align 2
