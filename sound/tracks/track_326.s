.align 2

.global track_326

track_326_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 77
	.byte VOL, 75
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 3
	.byte BEND, c_v+49
	.byte N32, Cn3, v127
	.byte W02
	.byte VOL, 76
	.byte BEND, c_v+43
	.byte W02
	.byte VOL, 80
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 82
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 87
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 96
	.byte BEND, c_v+31
	.byte W02
	.byte VOL, 110
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 120
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
	.byte VOL, 120
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v-1
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 17
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 12
	.byte W24
	.byte W03
	.byte FINE

track_326_1:
	.byte KEYSH, 0
	.byte VOICE, 78
	.byte VOL, 56
	.byte PAN, c_v
	.byte N15, Cn3, v127
	.byte W15
	.byte Cn3, v032 @ N15
	.byte W15
	.byte N30, Cn3, v012
	.byte W30
	.byte FINE

.align 2

track_326:
	.byte 2
	.byte 0
	.byte 198
	.byte 0
	.word 0x80a6d54
	.word track_326_0
	.word track_326_1

.align 2
