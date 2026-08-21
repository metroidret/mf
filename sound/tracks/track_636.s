.align 2

.global track_636

track_636_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 60
	.byte VOL, 90
	.byte PAN, c_v
	.byte BENDR, 8
	.byte LFOS, 120
	.byte PRIO, 1
	.byte BEND, c_v-63
	.byte N15, Cn3, v127
	.byte W01
	.byte BEND, c_v-61
	.byte W01
	.byte c_v-57 @ BEND
	.byte W01
	.byte c_v-53 @ BEND
	.byte W01
	.byte c_v-48 @ BEND
	.byte W01
	.byte c_v-43 @ BEND
	.byte W01
	.byte c_v-37 @ BEND
	.byte W01
	.byte c_v-31 @ BEND
	.byte W01
	.byte c_v-23 @ BEND
	.byte W01
	.byte c_v-13 @ BEND
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte N15, Cn3, v040
	.byte W15
	.byte Cn3, v016 @ N15
	.byte W15
	.byte FINE

track_636_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N15, Cn3, v127
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+32 @ BEND
	.byte W01
	.byte c_v+43 @ BEND
	.byte W01
	.byte N15, Cn3, v020
	.byte W15
	.byte Cn3, v012 @ N15
	.byte W15
	.byte FINE

.align 2

track_636:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_636_0
	.word track_636_1

.align 2
