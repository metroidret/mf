.align 2

.global track_522

track_522_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 127
	.byte BENDR, 22
	.byte BEND, c_v
	.byte N15, Cn3, v004
	.byte W03
	.byte BEND, c_v
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte FINE

track_522_1:
	.byte KEYSH, 0
	.byte VOICE, 73
	.byte VOL, 127
	.byte BENDR, 22
	.byte BEND, c_v
	.byte N15, Fn3, v016
	.byte W03
	.byte BEND, c_v
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+37 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+58 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte FINE

.align 2

track_522:
	.byte 2
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_522_0
	.word track_522_1

.align 2
