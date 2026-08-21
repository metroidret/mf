.align 2

.global track_381

track_381_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, An3, v127
	.byte W05
	.byte N09, Fn3, v112
	.byte W09
	.byte FINE

.align 2

track_381:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_381_0

.align 2
