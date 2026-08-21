.align 2

.global track_271

track_271_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N40, Gn3, v052
	.byte W02
	.byte BEND, c_v+3
	.byte W03
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+10 @ BEND
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+17 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W05
	.byte c_v+22 @ BEND
	.byte W02
	.byte c_v+23 @ BEND
	.byte W12
	.byte c_v+24 @ BEND
	.byte W06
	.byte FINE

track_271_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 45
	.byte PAN, c_v
	.byte W16
	.byte N02, Bn1, v040
	.byte W02
	.byte Bn2 @ N02, v040
	.byte W21
	.byte An2, v052 @ N02
	.byte W02
	.byte Cn3 @ N02, v052
	.byte W02
	.byte FINE

.align 2

track_271:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_271_0
	.word track_271_1

.align 2
