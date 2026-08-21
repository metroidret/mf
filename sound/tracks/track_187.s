.align 2

.global track_187

track_187_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v-45
	.byte VOL, 59
	.byte N36, Cn3, v127
	.byte W02
	.byte BEND, c_v-37
	.byte VOL, 81
	.byte W02
	.byte BEND, c_v-28
	.byte VOL, 98
	.byte W02
	.byte BEND, c_v-15
	.byte VOL, 110
	.byte W01
	.byte BEND, c_v-9
	.byte W02
	.byte c_v+48 @ BEND
	.byte VOL, 119
	.byte W02
	.byte BEND, c_v+58
	.byte VOL, 123
	.byte W02
	.byte 126 @ VOL
	.byte BEND, c_v+63
	.byte W05
	.byte VOL, 123
	.byte W02
	.byte 116 @ VOL
	.byte W02
	.byte 107 @ VOL
	.byte W03
	.byte 95 @ VOL
	.byte W02
	.byte 83 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W02
	.byte 33 @ VOL
	.byte W14
	.byte FINE

.align 2

track_187:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a74c8
	.word track_187_0

.align 2
