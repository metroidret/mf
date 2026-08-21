.align 2

.global track_352

track_352_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 60
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 37
	.byte N05, Cn3, v120
	.byte W05
	.byte Fn3 @ N05, v120
	.byte W05
	.byte Cn3 @ N05, v120
	.byte W05
	.byte An2 @ N05, v120
	.byte W05
	.byte FINE

.align 2

track_352:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_352_0

.align 2
