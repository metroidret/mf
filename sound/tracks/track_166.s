.align 2

.global track_166

track_166_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 95
	.byte PAN, c_v
	.byte BENDR, 6
	.byte BEND, c_v+17
	.byte W02
	.byte N60, Dn3, v080
	.byte W03
	.byte BEND, c_v+23
	.byte W03
	.byte c_v+27 @ BEND
	.byte W03
	.byte c_v+29 @ BEND
	.byte W06
	.byte c_v+26 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v-1 @ BEND
	.byte W03
	.byte c_v-15 @ BEND
	.byte W03
	.byte c_v-25 @ BEND
	.byte W03
	.byte c_v-34 @ BEND
	.byte W01
	.byte c_v-34 @ BEND
	.byte W03
	.byte c_v-21 @ BEND
	.byte W03
	.byte c_v-13 @ BEND
	.byte W03
	.byte c_v-7 @ BEND
	.byte W02
	.byte VOL, 95
	.byte W01
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 58
	.byte W01
	.byte BEND, c_v-2
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte VOL, 34
	.byte W02
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 19
	.byte W02
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 9
	.byte W02
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 2
	.byte W02
	.byte 0 @ VOL
	.byte W02
	.byte FINE

track_166_1:
	.byte KEYSH, 0
	.byte VOICE, 3
	.byte VOL, 120
	.byte PAN, c_v
	.byte N64, En3, v127
	.byte W48
	.byte VOL, 118
	.byte W03
	.byte 93 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W05
	.byte FINE

.align 2

track_166:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a8008
	.word track_166_0
	.word track_166_1

.align 2
