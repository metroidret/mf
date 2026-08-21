.align 2

.global track_107

track_107_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 23
	.byte VOL, 90
	.byte PAN, c_v
	.byte BENDR, 16
	.byte PRIO, 1
	.byte BEND, c_v-30
	.byte N16, An2, v112
	.byte W02
	.byte BEND, c_v-4
	.byte W02
	.byte c_v+23 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W09
	.byte FINE

track_107_1:
	.byte KEYSH, 0
	.byte VOICE, 24
	.byte VOL, 90
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N16, Cn3, v072
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W01
	.byte FINE

.align 2

track_107:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a682c
	.word track_107_0
	.word track_107_1

.align 2
