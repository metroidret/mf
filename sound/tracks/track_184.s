.align 2

.global track_184

track_184_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 50
	.byte PAN, c_v
	.byte N04, Bn1, v080
	.byte W04
	.byte VOICE, 6
	.byte N04, Cs2, v127
	.byte W04
	.byte VOICE, 7
	.byte N04, Fs2, v080
	.byte W04
	.byte Fs2, v052 @ N04
	.byte W04
	.byte Fs2, v020 @ N04
	.byte W04
	.byte VOICE, 10
	.byte BENDR, 12
	.byte BEND, c_v-24
	.byte N07, Cn2, v032
	.byte W02
	.byte BEND, c_v-11
	.byte W02
	.byte c_v-18 @ BEND
	.byte W02
	.byte c_v-33 @ BEND
	.byte W14
	.byte FINE

.align 2

track_184:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word 0x80a74c8
	.word track_184_0

.align 2
