.align 2

.global track_375

track_375_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 64
	.byte VOL, 21
	.byte PAN, c_v
	.byte N05, Fn2, v080
	.byte W05
	.byte Cn3 @ N05, v080
	.byte W05
	.byte VOICE, 63
	.byte VOL, 10
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N72, Fn2, v127
	.byte W02
	.byte BEND, c_v+3
	.byte W02
	.byte c_v+7 @ BEND
	.byte W02
	.byte VOL, 11
	.byte BEND, c_v+10
	.byte W02
	.byte c_v+13 @ BEND
	.byte W02
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+19 @ BEND
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte BEND, c_v+21
	.byte W03
	.byte c_v+25 @ BEND
	.byte W02
	.byte VOL, 12
	.byte BEND, c_v+27
	.byte W02
	.byte c_v+29 @ BEND
	.byte W02
	.byte VOL, 13
	.byte BEND, c_v+30
	.byte W01
	.byte c_v+31 @ BEND
	.byte W02
	.byte c_v+33 @ BEND
	.byte W01
	.byte VOL, 14
	.byte W02
	.byte BEND, c_v+34
	.byte W01
	.byte c_v+35 @ BEND
	.byte W01
	.byte VOL, 15
	.byte W01
	.byte BEND, c_v+36
	.byte W02
	.byte VOL, 15
	.byte W02
	.byte 16 @ VOL
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+40
	.byte W02
	.byte VOL, 18
	.byte W02
	.byte 20 @ VOL
	.byte W02
	.byte 21 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W11
	.byte 34 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W02
	.byte 27 @ VOL
	.byte W02
	.byte 25 @ VOL
	.byte W01
	.byte FINE

.align 2

track_375:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_375_0

.align 2
