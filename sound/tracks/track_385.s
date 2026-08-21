.align 2

.global track_385

track_385_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 34
	.byte PAN, c_v
	.byte W02
	.byte N05, An2, v127
	.byte W05
	.byte N09, Cn3, v112
	.byte W09
	.byte FINE

track_385_1:
	.byte KEYSH, 0
	.byte VOICE, 40
	.byte VOL, 40
	.byte PAN, c_v
	.byte N02, As3, v127
	.byte W16
	.byte FINE

.align 2

track_385:
	.byte 2
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_385_0
	.word track_385_1

.align 2
