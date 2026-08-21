.align 2

.global track_549

track_549_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 69
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 3
	.byte BEND, c_v+49
	.byte N32, Gn2, v127
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v+43
	.byte W02
	.byte VOL, 73
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 75
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 80
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 88
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 101
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 110
	.byte BEND, c_v+49
	.byte W02
	.byte c_v+57 @ BEND
	.byte W02
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v+37 @ BEND
	.byte W02
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte VOL, 110
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 54
	.byte BEND, c_v-1
	.byte W02
	.byte VOL, 30
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte FINE

.align 2

track_549:
	.byte 1
	.byte 0
	.byte 202
	.byte 0
	.word 0x80a826c
	.word track_549_0

.align 2
