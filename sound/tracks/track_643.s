.align 2

.global track_643

track_643_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 120
	.byte PAN, c_v
	.byte W10
	.byte N11, Cn3, v127
	.byte W11
	.byte VOICE, 9
	.byte N04, Cn3, v060
	.byte W04
	.byte Cn3, v032 @ N04
	.byte W04
	.byte Cn3, v012 @ N04
	.byte W15
	.byte FINE

track_643_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v-63
	.byte W10
	.byte N32, Cn4, v127
	.byte W02
	.byte BEND, c_v-60
	.byte W02
	.byte c_v-55 @ BEND
	.byte W02
	.byte c_v-48 @ BEND
	.byte W02
	.byte c_v-37 @ BEND
	.byte W02
	.byte c_v-23 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W02
	.byte VOL, 120
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 84
	.byte BEND, c_v+41
	.byte W02
	.byte VOL, 59
	.byte BEND, c_v+51
	.byte W02
	.byte VOL, 39
	.byte BEND, c_v+57
	.byte W02
	.byte VOL, 27
	.byte BEND, c_v+61
	.byte W02
	.byte VOL, 19
	.byte W02
	.byte 13 @ VOL
	.byte W02
	.byte 8 @ VOL
	.byte W02
	.byte 4 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_643:
	.byte 2
	.byte 0
	.byte 190
	.byte 0
	.word 0x80a7d14
	.word track_643_0
	.word track_643_1

.align 2
