.align 2

.global track_291

track_291_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 62
	.byte PAN, c_v-24
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W05
	.byte N23, Cn3, v100
	.byte W02
	.byte BEND, c_v+1
	.byte W02
	.byte c_v+3 @ BEND
	.byte W02
	.byte c_v+4 @ BEND
	.byte W02
	.byte c_v+6 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+14 @ BEND
	.byte W02
	.byte c_v+18 @ BEND
	.byte W02
	.byte c_v+24 @ BEND
	.byte W02
	.byte c_v+31 @ BEND
	.byte W11
	.byte VOL, 62
	.byte BEND, c_v
	.byte W01
	.byte N18, Cn3, v060
	.byte W02
	.byte VOL, 59
	.byte W02
	.byte 56 @ VOL
	.byte W02
	.byte 51 @ VOL
	.byte W02
	.byte 45 @ VOL
	.byte W02
	.byte 39 @ VOL
	.byte W02
	.byte 32 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 9 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_291:
	.byte 1
	.byte 0
	.byte 252
	.byte 0
	.word 0x80a71ec
	.word track_291_0

.align 2
