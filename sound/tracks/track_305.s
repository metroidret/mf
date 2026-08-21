.align 2

.global track_305

track_305_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 9
	.byte PRIO, 1
	.byte BEND, c_v-1
	.byte N28, Cn3, v127
	.byte W02
	.byte BEND, c_v+9
	.byte W02
	.byte c_v+12 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v-5 @ BEND
	.byte W02
	.byte c_v+63 @ BEND
	.byte W02
	.byte c_v+61 @ BEND
	.byte W02
	.byte c_v+58 @ BEND
	.byte W02
	.byte c_v+53 @ BEND
	.byte W02
	.byte c_v+49 @ BEND
	.byte W02
	.byte c_v+41 @ BEND
	.byte W01
	.byte VOL, 120
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 32
	.byte W01
	.byte BEND, c_v-9
	.byte W01
	.byte VOL, 10
	.byte W01
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 0
	.byte W14
	.byte FINE

track_305_1:
	.byte KEYSH, 0
	.byte W13
	.byte VOICE, 11
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 9
	.byte BEND, c_v-1
	.byte N30, Cn3, v040
	.byte W02
	.byte VOL, 111
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 102
	.byte BEND, c_v+12
	.byte W02
	.byte VOL, 94
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 86
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 69
	.byte BEND, c_v+63
	.byte W02
	.byte VOL, 61
	.byte BEND, c_v+61
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v+58
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v+49
	.byte W02
	.byte VOL, 28
	.byte BEND, c_v+41
	.byte W02
	.byte VOL, 20
	.byte BEND, c_v+9
	.byte W02
	.byte VOL, 12
	.byte BEND, c_v-9
	.byte W02
	.byte VOL, 3
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_305:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a82f0
	.word track_305_0
	.word track_305_1

.align 2
