.align 2

.global track_191

track_191_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 90
	.byte PAN, c_v
	.byte BENDR, 1
	.byte BEND, c_v
	.byte N32, An2, v100
	.byte W02
	.byte BEND, c_v+7
	.byte W04
	.byte c_v+15 @ BEND
	.byte W04
	.byte c_v+19 @ BEND
	.byte VOL, 87
	.byte W02
	.byte 82 @ VOL
	.byte W02
	.byte 77 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 53
	.byte BEND, c_v+14
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 21
	.byte BEND, c_v+7
	.byte W02
	.byte VOL, 13
	.byte BEND, c_v+3
	.byte W02
	.byte VOL, 7
	.byte BEND, c_v-3
	.byte W02
	.byte VOL, 4
	.byte BEND, c_v-8
	.byte W02
	.byte VOL, 1
	.byte BEND, c_v-13
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

track_191_1:
	.byte KEYSH, 0
	.byte VOICE, 29
	.byte VOL, 90
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte VOICE, 30
	.byte VOL, 14
	.byte N12, Cn3, v040
	.byte W02
	.byte VOL, 23
	.byte W03
	.byte 34 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W02
	.byte 77 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W20
	.byte FINE

.align 2

track_191:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a74c8
	.word track_191_0
	.word track_191_1

.align 2
