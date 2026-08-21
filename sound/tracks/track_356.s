.align 2

.global track_356

track_356_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 25
	.byte PAN, c_v
	.byte N04, An3, v080
	.byte W04
	.byte Cn4, v052 @ N04
	.byte W04
	.byte Fn4 @ N04, v052
	.byte W04
	.byte FINE

.align 2

track_356:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_356_0

.align 2
