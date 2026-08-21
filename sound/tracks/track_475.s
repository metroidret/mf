.align 2

.global track_475

track_475_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 90
	.byte PAN, c_v
	.byte N04, Cn3, v127, 65
	.byte W04
	.byte Gn2 @ N04, v127
	.byte W04
	.byte Cn2 @ N04, v127
	.byte W04
	.byte N06, Bn1 @ v127
	.byte W06
	.byte FINE

.align 2

track_475:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_475_0

.align 2
