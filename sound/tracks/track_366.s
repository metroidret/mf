.align 2

.global track_366

track_366_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 42
	.byte PAN, c_v
	.byte N15, Cn1, v127
	.byte W15
	.byte VOICE, 59
	.byte N20, Cn1, v100
	.byte W20
	.byte VOICE, 60
	.byte N20, Cn1, v127
	.byte W20
	.byte FINE

track_366_1:
	.byte KEYSH, 0
	.byte VOICE, 55
	.byte VOL, 23
	.byte PAN, c_v
	.byte W15
	.byte N32, An2, v056
	.byte W40
	.byte FINE

.align 2

track_366:
	.byte 2
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_366_0
	.word track_366_1

.align 2
