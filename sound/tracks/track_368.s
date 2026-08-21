.align 2

.global track_368

track_368_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 27
	.byte PAN, c_v
	.byte N06, Dn1, v127
	.byte W06
	.byte VOICE, 59
	.byte N11, Dn1, v100
	.byte W11
	.byte FINE

track_368_1:
	.byte KEYSH, 0
	.byte VOICE, 55
	.byte VOL, 28
	.byte PAN, c_v
	.byte N17, Cn3, v044
	.byte W17
	.byte FINE

.align 2

track_368:
	.byte 2
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a6d54
	.word track_368_0
	.word track_368_1

.align 2
