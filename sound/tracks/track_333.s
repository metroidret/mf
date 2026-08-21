.align 2

.global track_333

track_333_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 14
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 13
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 12
	.byte N05 @ Cn3, v127
	.byte W05
	.byte VOICE, 11
	.byte N03 @ Cn3, v127
	.byte W04
	.byte VOICE, 42
	.byte N36, An1, v072
	.byte W36
	.byte W02
	.byte VOICE, 35
	.byte N23, Cn3, v127
	.byte W23
	.byte FINE

.align 2

track_333:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word 0x80a6d54
	.word track_333_0

.align 2
