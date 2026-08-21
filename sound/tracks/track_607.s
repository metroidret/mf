.align 2

.global track_607

track_607_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 80
	.byte PAN, c_v
	.byte BENDR, 30
	.byte PRIO, 127
	.byte BEND, c_v
	.byte N10, Cn2, v127
	.byte W02
	.byte BEND, c_v+2
	.byte W02
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+27 @ BEND
	.byte W01
	.byte c_v+54 @ BEND
	.byte W06
	.byte FINE

.align 2

track_607:
	.byte 1
	.byte 0
	.byte 185
	.byte 0
	.word 0x80a7654
	.word track_607_0

.align 2
