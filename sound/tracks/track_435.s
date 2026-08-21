.align 2

.global track_435

track_435_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 87
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 16
	.byte PRIO, 1
	.byte BEND, c_v+63
	.byte N14, Bn1, v127
	.byte W01
	.byte BEND, c_v+58
	.byte W01
	.byte c_v+53 @ BEND
	.byte W01
	.byte c_v+48 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+38 @ BEND
	.byte W01
	.byte c_v+33 @ BEND
	.byte W01
	.byte c_v+29 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte VOL, 78
	.byte W01
	.byte BEND, c_v+9
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v+4
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v
	.byte VOL, 0
	.byte W04
	.byte FINE

track_435_1:
	.byte KEYSH, 0
	.byte VOICE, 88
	.byte VOL, 37
	.byte PAN, c_v
	.byte W10
	.byte N07, Cn3, v072
	.byte W07
	.byte FINE

.align 2

track_435:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6d54
	.word track_435_0
	.word track_435_1

.align 2
