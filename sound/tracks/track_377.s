.align 2

.global track_377

track_377_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 63
	.byte VOL, 10
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-15
	.byte N48, En2, v127
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v-9
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+15
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte BEND, c_v+22
	.byte W01
	.byte c_v+23 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte VOL, 13
	.byte W03
	.byte 13 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte BEND, c_v+25
	.byte W03
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 14
	.byte W03
	.byte 15 @ VOL
	.byte W04
	.byte 17 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W02
	.byte 18 @ VOL
	.byte W02
	.byte 19 @ VOL
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 22 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W02
	.byte 26 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte FINE

.align 2

track_377:
	.byte 1
	.byte 0
	.byte 141
	.byte 0
	.word 0x80a6d54
	.word track_377_0

.align 2
