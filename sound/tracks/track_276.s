.align 2

.global track_276

track_276_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 33
	.byte VOL, 40
	.byte PAN, c_v
	.byte W05
	.byte N05, Cn3, v080
	.byte W05
	.byte N05 @ Cn3, v080
	.byte W05
	.byte N05 @ Cn3, v080
	.byte W05
	.byte N05 @ Cn3, v080
	.byte W05
	.byte Bn2, v052 @ N05
	.byte W05
	.byte FINE

track_276_1:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 20
	.byte N20, Cn3, v040
	.byte W24
	.byte W01
	.byte FINE

.align 2

track_276:
	.byte 2
	.byte 0
	.byte 253
	.byte 0
	.word 0x80a71ec
	.word track_276_0
	.word track_276_1

.align 2
