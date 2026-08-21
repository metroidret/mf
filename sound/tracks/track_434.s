.align 2

.global track_434

track_434_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 87
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 16
	.byte PRIO, 1
	.byte BEND, c_v
	.byte N14, Cn2, v127
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte c_v+26 @ BEND
	.byte W01
	.byte c_v+31 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+57 @ BEND
	.byte W01
	.byte c_v+62 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W15
	.byte FINE

track_434_1:
	.byte KEYSH, 0
	.byte VOICE, 88
	.byte VOL, 50
	.byte PAN, c_v
	.byte W14
	.byte N07, Cn3, v072
	.byte W07
	.byte Cn3, v020 @ N07
	.byte W07
	.byte FINE

.align 2

track_434:
	.byte 2
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6d54
	.word track_434_0
	.word track_434_1

.align 2
