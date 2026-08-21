.align 2

.global track_367

track_367_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 27
	.byte PAN, c_v
	.byte N15, Dn1, v127
	.byte W15
	.byte VOICE, 59
	.byte N14, Dn1, v100
	.byte W14
	.byte FINE

track_367_1:
	.byte KEYSH, 0
	.byte VOICE, 55
	.byte VOL, 28
	.byte PAN, c_v
	.byte N28, Cn3, v044
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_367:
	.byte 2
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a6d54
	.word track_367_0
	.word track_367_1

.align 2
