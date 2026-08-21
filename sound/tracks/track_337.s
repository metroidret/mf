.align 2

.global track_337

track_337_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 45
	.byte PAN, c_v
	.byte N03, Cn2, v080
	.byte W03
	.byte Gn2, v100 @ N03
	.byte W04
	.byte Cn3, v127 @ N03
	.byte W23
	.byte N06, En3 @ v127
	.byte W06
	.byte N04, En3, v052
	.byte W04
	.byte En3, v020 @ N04
	.byte W04
	.byte FINE

.align 2

track_337:
	.byte 1
	.byte 0
	.byte 137
	.byte 0
	.word 0x80a6d54
	.word track_337_0

.align 2
