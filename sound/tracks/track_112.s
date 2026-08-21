.align 2

.global track_112

track_112_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte PAN, c_v
	.byte VOL, 25
	.byte N08, Cn3, v127
	.byte W01
	.byte VOL, 35
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W03
	.byte N08, Cn3, v100
	.byte W04
	.byte VOL, 37
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte FINE

track_112_1:
	.byte KEYSH, 0
	.byte VOICE, 49
	.byte VOL, 35
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N10, Cn3, v080
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+11
	.byte W02
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte FINE

.align 2

track_112:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a682c
	.word track_112_0
	.word track_112_1

.align 2
