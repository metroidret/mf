.align 2

.global track_365

track_365_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 56
	.byte VOL, 23
	.byte PAN, c_v
	.byte N11, Cn1, v127
	.byte W11
	.byte VOICE, 57
	.byte N20 @ Cn1, v127
	.byte W20
	.byte VOICE, 58
	.byte N20, Cn1, v100
	.byte W20
	.byte VOICE, 59
	.byte N20, Cn1, v127
	.byte W20
	.byte FINE

track_365_1:
	.byte KEYSH, 0
	.byte VOICE, 55
	.byte VOL, 28
	.byte PAN, c_v
	.byte W24
	.byte N44, Fn2, v056
	.byte W44
	.byte W03
	.byte FINE

.align 2

track_365:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_365_0
	.word track_365_1

.align 2
