.align 2

.global track_609

track_609_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 17
	.byte BENDR, 12
	.byte BEND, c_v-45
	.byte TIE, Cn3, v100
	.byte W02
	.byte VOL, 18
	.byte BEND, c_v-44
	.byte W02
	.byte c_v-43 @ BEND
	.byte W02
	.byte VOL, 19
	.byte BEND, c_v-41
	.byte W03
	.byte VOL, 19
	.byte BEND, c_v-40
	.byte W01
	.byte TIE, Dn3 @ v100
	.byte W01
	.byte BEND, c_v-38
	.byte W02
	.byte c_v-36 @ BEND
	.byte W03
	.byte VOL, 21
	.byte BEND, c_v-34
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v-32
	.byte W02
	.byte VOL, 23
	.byte BEND, c_v-29
	.byte N92, En3 @ v100
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-27
	.byte W03
	.byte VOL, 26
	.byte BEND, c_v-24
	.byte W02
	.byte c_v-21 @ BEND
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-17
	.byte W01
	.byte N72, Fn3 @ v100
	.byte W02
	.byte VOL, 31
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 35
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 38
	.byte BEND, c_v+3
	.byte W02
	.byte N54, Gn3 @ v100
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v+26
	.byte W03
	.byte VOL, 55
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v+44
	.byte N32, An3 @ v100
	.byte W02
	.byte VOL, 71
	.byte BEND, c_v+49
	.byte W02
	.byte VOL, 82
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 90
	.byte BEND, c_v+57
	.byte W03
	.byte VOL, 97
	.byte BEND, c_v+59
	.byte W02
	.byte VOL, 103
	.byte BEND, c_v+61
	.byte W02
	.byte VOL, 106
	.byte BEND, c_v+63
	.byte W03
	.byte VOL, 109
	.byte W02
	.byte 108 @ VOL
	.byte W02
	.byte 106 @ VOL
	.byte W02
	.byte 105 @ VOL
	.byte W03
	.byte 103 @ VOL
	.byte W02
	.byte 101 @ VOL
	.byte W02
	.byte 97 @ VOL
	.byte W03
	.byte 89 @ VOL
	.byte W02
	.byte 81 @ VOL
	.byte W02
	.byte 74 @ VOL
	.byte W02
	.byte 67 @ VOL
	.byte W03
	.byte 61 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 50 @ VOL
	.byte W01
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 35 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W03
	.byte 19 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 11 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W01
	.byte EOT, Dn3 @ v100
	.byte W01
	.byte VOL, 6
	.byte W02
	.byte 4 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte EOT, Cn3 @ v100
	.byte FINE

.align 2

track_609:
	.byte 1
	.byte 0
	.byte 185
	.byte 0
	.word 0x80a7654
	.word track_609_0

.align 2
