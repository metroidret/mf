.align 2

.global track_185

track_185_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N09, Cn3, v127
	.byte W02
	.byte BEND, c_v-45
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-29 @ BEND
	.byte W02
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N09, Ds3 @ v127
	.byte W48
	.byte W02
	.byte FINE

track_185_1:
	.byte KEYSH, 0
	.byte W18
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte N06, Cn3, v100
	.byte W06
	.byte VOICE, 15
	.byte N06, Cn3, v080
	.byte W06
	.byte VOICE, 16
	.byte N03 @ Cn3, v080
	.byte W03
	.byte VOICE, 14
	.byte N06, Cn3, v052
	.byte W06
	.byte VOICE, 15
	.byte N06, Cn3, v020
	.byte W06
	.byte VOICE, 17
	.byte N03 @ Cn3, v020
	.byte W14
	.byte FINE

.align 2

track_185:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a74c8
	.word track_185_0
	.word track_185_1

.align 2
