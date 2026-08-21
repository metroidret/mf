.align 2

.global track_297

track_297_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N06, Cn3, v127
	.byte W06
	.byte N14, En3, v100
	.byte W14
	.byte N03, Dn3, v040
	.byte W03
	.byte FINE

track_297_1:
	.byte KEYSH, 0
	.byte VOICE, 42
	.byte VOL, 127
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W23
	.byte FINE

.align 2

track_297:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a71ec
	.word track_297_0
	.word track_297_1

.align 2
