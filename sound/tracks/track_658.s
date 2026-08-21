.align 2

.global track_658

track_658_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 85
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+39
	.byte VOL, 85
	.byte N48, Gn2, v127
	.byte W03
	.byte BEND, c_v+53
	.byte VOL, 93
	.byte W03
	.byte BEND, c_v+61
	.byte VOL, 101
	.byte W03
	.byte BEND, c_v+63
	.byte VOL, 108
	.byte W03
	.byte BEND, c_v+62
	.byte VOL, 114
	.byte W03
	.byte BEND, c_v+57
	.byte VOL, 117
	.byte W03
	.byte BEND, c_v+49
	.byte W03
	.byte c_v+37 @ BEND
	.byte VOL, 117
	.byte W03
	.byte BEND, c_v+28
	.byte VOL, 110
	.byte W03
	.byte BEND, c_v+21
	.byte VOL, 103
	.byte W03
	.byte BEND, c_v+17
	.byte VOL, 93
	.byte W03
	.byte BEND, c_v+13
	.byte VOL, 80
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_658:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7e10
	.word track_658_0

.align 2
