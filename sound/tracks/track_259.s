.align 2

.global track_259

track_259_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 47
	.byte PAN, c_v
	.byte W04
	.byte N02, En3, v120
	.byte W08
	.byte En3, v052 @ N02
	.byte W08
	.byte En3, v060 @ N02
	.byte W08
	.byte Cn3, v080 @ N02
	.byte W08
	.byte VOICE, 16
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N05, Cn3, v040
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+49 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W56
	.byte W10
	.byte FINE

track_259_1:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 33
	.byte PAN, c_v
	.byte W05
	.byte N03, En2, v127
	.byte W20
	.byte Gs2, v112 @ N03
	.byte W03
	.byte As2, v127 @ N03
	.byte W68
	.byte W10
	.byte FINE

.align 2

track_259:
	.byte 2
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_259_0
	.word track_259_1

.align 2
