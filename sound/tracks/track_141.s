.align 2

.global track_141

track_141_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 45
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 127
	.byte BEND, c_v
	.byte N15, Bn3, v064
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+21 @ BEND
	.byte W01
	.byte c_v+24 @ BEND
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_141:
	.byte 1
	.byte 0
	.byte 129
	.byte 128
	.word 0x80a682c
	.word track_141_0

.align 2
