.align 2

.global track_108

track_108_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 31
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn2, v127
	.byte W06
	.byte Cn2, v080 @ N06
	.byte W07
	.byte Cn2, v060 @ N06
	.byte W06
	.byte Cn2, v020 @ N06
	.byte W13
	.byte FINE

track_108_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 43
	.byte PAN, c_v
	.byte W06
	.byte VOL, 15
	.byte N24, Cn2, v127
	.byte W02
	.byte VOL, 20
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 30 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 16 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_108:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a682c
	.word track_108_0
	.word track_108_1

.align 2
