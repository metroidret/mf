.align 2

.global track_152

track_152_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 42
	.byte PAN, c_v
	.byte BENDR, 16
	.byte PRIO, 1
	.byte BEND, c_v-30
	.byte N14, An2, v127
	.byte W02
	.byte VOL, 43
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v+49
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 49
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 53 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W01
	.byte FINE

track_152_1:
	.byte KEYSH, 0
	.byte VOICE, 56
	.byte VOL, 63
	.byte PAN, c_v
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_152:
	.byte 2
	.byte 0
	.byte 227
	.byte 0
	.word 0x80a682c
	.word track_152_0
	.word track_152_1

.align 2
