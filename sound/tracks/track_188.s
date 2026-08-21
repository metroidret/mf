.align 2

.global track_188

track_188_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 25
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v+19
	.byte N15, Cn3, v127
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v+11
	.byte W01
	.byte c_v+11 @ BEND
	.byte W02
	.byte VOL, 52
	.byte BEND, c_v-6
	.byte W02
	.byte c_v-24 @ BEND
	.byte VOL, 49
	.byte W01
	.byte BEND, c_v-39
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte BEND, c_v-45
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-47
	.byte VOL, 27
	.byte W44
	.byte W03
	.byte FINE

track_188_1:
	.byte KEYSH, 0
	.byte VOICE, 19
	.byte VOL, 80
	.byte PAN, c_v
	.byte N24, En2, v127
	.byte W60
	.byte FINE

.align 2

track_188:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a74c8
	.word track_188_0
	.word track_188_1

.align 2
