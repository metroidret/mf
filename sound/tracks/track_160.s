.align 2

.global track_160

track_160_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 120
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N10, Cn3, v127
	.byte W10
	.byte En3, v060 @ N10
	.byte W10
	.byte N15, En3, v020
	.byte W06
	.byte VOL, 120
	.byte W01
	.byte 116 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W06
	.byte FINE

track_160_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v+31
	.byte VOL, 93
	.byte N40, Dn3, v088
	.byte W03
	.byte BEND, c_v+43
	.byte VOL, 118
	.byte BEND, c_v+44
	.byte W03
	.byte VOL, 120
	.byte BEND, c_v+47
	.byte W03
	.byte VOL, 116
	.byte BEND, c_v+41
	.byte W03
	.byte VOL, 112
	.byte BEND, c_v+32
	.byte W03
	.byte VOL, 106
	.byte BEND, c_v+27
	.byte W03
	.byte VOL, 101
	.byte BEND, c_v+25
	.byte W03
	.byte VOL, 95
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_160:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a8008
	.word track_160_0
	.word track_160_1

.align 2
