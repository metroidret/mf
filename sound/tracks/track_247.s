.align 2

.global track_247

track_247_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+15
	.byte N36, Cn4, v127
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v+31
	.byte W02
	.byte c_v+45 @ BEND
	.byte W01
	.byte VOL, 43
	.byte W01
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 50
	.byte W01
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 52
	.byte W03
	.byte 55 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 28 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 14 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W02
	.byte 6 @ VOL
	.byte W02
	.byte 3 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_247:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a6af0
	.word track_247_0

.align 2
