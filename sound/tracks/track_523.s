.align 2

.global track_523

track_523_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 127
	.byte BENDR, 26
	.byte BEND, c_v+63
	.byte N15, En2, v004
	.byte W01
	.byte BEND, c_v+59
	.byte W01
	.byte c_v+55 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte FINE

track_523_1:
	.byte KEYSH, 0
	.byte VOICE, 73
	.byte VOL, 127
	.byte BENDR, 26
	.byte BEND, c_v+63
	.byte N15, An2, v016
	.byte W01
	.byte BEND, c_v+59
	.byte W01
	.byte c_v+55 @ BEND
	.byte W01
	.byte c_v+51 @ BEND
	.byte W01
	.byte c_v+46 @ BEND
	.byte W01
	.byte c_v+42 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte FINE

.align 2

track_523:
	.byte 2
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_523_0
	.word track_523_1

.align 2
