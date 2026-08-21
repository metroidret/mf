.align 2

.global track_265

track_265_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W07
	.byte N02, Bn1, v040
	.byte W02
	.byte Bn2 @ N02, v040
	.byte W06
	.byte Fn2, v044 @ N02
	.byte W02
	.byte Cn3 @ N02, v044
	.byte W02
	.byte FINE

track_265_1:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 44
	.byte PAN, c_v
	.byte W05
	.byte N05, An2, v080
	.byte W08
	.byte Bn2 @ N05, v080
	.byte W06
	.byte FINE

track_265_2:
	.byte KEYSH, 0
	.byte VOICE, 9
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N15, Fn2, v127
	.byte W01
	.byte VOL, 70
	.byte W13
	.byte BEND, c_v-8
	.byte W01
	.byte c_v-16 @ BEND
	.byte W04
	.byte FINE

.align 2

track_265:
	.byte 3
	.byte 0
	.byte 253
	.byte 0
	.word 0x80a71ec
	.word track_265_0
	.word track_265_1
	.word track_265_2

.align 2
