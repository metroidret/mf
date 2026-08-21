.align 2

.global track_354

track_354_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Bn1, v060
	.byte W05
	.byte VOICE, 49
	.byte W01
	.byte N05, Cn2, v112
	.byte W05
	.byte N04, Cn2, v080
	.byte W04
	.byte Cn2, v040 @ N04
	.byte W04
	.byte FINE

.align 2

track_354:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_354_0

.align 2
