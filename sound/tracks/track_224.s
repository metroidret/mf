.align 2

.global track_224

track_224_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 20
	.byte BENDR, 12
	.byte BEND, c_v-45
	.byte TIE, Cn3, v100
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v-44
	.byte W02
	.byte c_v-43 @ BEND
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v-41
	.byte W03
	.byte VOL, 23
	.byte BEND, c_v-40
	.byte W01
	.byte TIE, Dn3 @ v100
	.byte W01
	.byte BEND, c_v-38
	.byte W02
	.byte c_v-36 @ BEND
	.byte W03
	.byte VOL, 25
	.byte BEND, c_v-34
	.byte W02
	.byte VOL, 26
	.byte BEND, c_v-32
	.byte W02
	.byte VOL, 27
	.byte BEND, c_v-29
	.byte N92, En3 @ v100
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v-27
	.byte W03
	.byte VOL, 31
	.byte BEND, c_v-24
	.byte W02
	.byte c_v-21 @ BEND
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v-17
	.byte W01
	.byte N72, Fn3 @ v100
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 41
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v+3
	.byte W02
	.byte N54, Gn3 @ v100
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 54
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v+26
	.byte W03
	.byte VOL, 64
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 69
	.byte BEND, c_v+44
	.byte N32, An3 @ v100
	.byte W02
	.byte VOL, 83
	.byte BEND, c_v+49
	.byte W02
	.byte VOL, 95
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 104
	.byte BEND, c_v+57
	.byte W03
	.byte VOL, 112
	.byte BEND, c_v+59
	.byte W02
	.byte VOL, 119
	.byte BEND, c_v+61
	.byte W02
	.byte VOL, 123
	.byte BEND, c_v+63
	.byte W03
	.byte VOL, 126
	.byte W02
	.byte 125 @ VOL
	.byte W02
	.byte 123 @ VOL
	.byte W02
	.byte 122 @ VOL
	.byte W03
	.byte 119 @ VOL
	.byte W02
	.byte 117 @ VOL
	.byte W02
	.byte 112 @ VOL
	.byte W03
	.byte 103 @ VOL
	.byte W02
	.byte 94 @ VOL
	.byte W02
	.byte 86 @ VOL
	.byte W02
	.byte 78 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W02
	.byte 58 @ VOL
	.byte W01
	.byte W02
	.byte 52 @ VOL
	.byte W02
	.byte 46 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 36 @ VOL
	.byte W03
	.byte 32 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W02
	.byte 13 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W01
	.byte EOT, Dn3 @ v100
	.byte W01
	.byte VOL, 7
	.byte W02
	.byte 5 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W02
	.byte 1 @ VOL
	.byte W02
	.byte EOT, Cn3 @ v100
	.byte FINE

.align 2

track_224:
	.byte 1
	.byte 0
	.byte 253
	.byte 0
	.word 0x80a6af0
	.word track_224_0

.align 2
