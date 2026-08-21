.align 2

.global track_193

track_193_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v+59
	.byte N24, Cn3, v127
	.byte W01
	.byte VOL, 79
	.byte W01
	.byte 77 @ VOL
	.byte BEND, c_v+56
	.byte W03
	.byte VOL, 75
	.byte BEND, c_v+53
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte VOL, 71
	.byte W02
	.byte 67 @ VOL
	.byte BEND, c_v+35
	.byte W02
	.byte c_v+19 @ BEND
	.byte W01
	.byte VOL, 63
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v-29
	.byte W02
	.byte VOL, 43
	.byte BEND, c_v-47
	.byte W02
	.byte c_v-53 @ BEND
	.byte W01
	.byte VOL, 32
	.byte W01
	.byte BEND, c_v-59
	.byte W01
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v-63
	.byte W54
	.byte FINE

track_193_1:
	.byte KEYSH, 0
	.byte VOICE, 22
	.byte VOL, 127
	.byte PAN, c_v
	.byte N24, Cn2, v112
	.byte W03
	.byte As2, v127 @ N24
	.byte W24
	.byte VOICE, 23
	.byte N24, En2, v080
	.byte W48
	.byte W03
	.byte FINE

.align 2

track_193:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a74c8
	.word track_193_0
	.word track_193_1

.align 2
