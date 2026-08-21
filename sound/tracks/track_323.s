.align 2

.global track_323

track_323_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 45
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
	.byte VOICE, 17
	.byte N05, Cn3, v100
	.byte W05
	.byte VOICE, 16
	.byte N05, Cn3, v080
	.byte W05
	.byte FINE

.align 2

track_323:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a6d54
	.word track_323_0

.align 2
