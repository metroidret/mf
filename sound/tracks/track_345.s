.align 2

.global track_345

track_345_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 42
	.byte PAN, c_v
	.byte N03, An2, v127
	.byte W06
	.byte Cn3 @ N03, v127
	.byte W08
	.byte Cn3, v100 @ N03
	.byte W08
	.byte Cn3, v080 @ N03
	.byte W08
	.byte Cn3, v052 @ N03
	.byte W03
	.byte FINE

.align 2

track_345:
	.byte 1
	.byte 0
	.byte 134
	.byte 0
	.word 0x80a6d54
	.word track_345_0

.align 2
