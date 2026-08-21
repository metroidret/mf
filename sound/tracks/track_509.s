.align 2

.global track_509

track_509_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 76
	.byte VOL, 100
	.byte BENDR, 12
	.byte BEND, c_v+61
	.byte N12, Cn3, v072
	.byte W01
	.byte BEND, c_v+55
	.byte W01
	.byte c_v+50 @ BEND
	.byte W01
	.byte c_v+45 @ BEND
	.byte W01
	.byte c_v+39 @ BEND
	.byte W01
	.byte c_v+34 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte FINE

.align 2

track_509:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_509_0

.align 2
