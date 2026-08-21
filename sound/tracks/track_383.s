.align 2

.global track_383

track_383_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 40
	.byte PAN, c_v
	.byte N10, Cn2, v127
	.byte W10
	.byte FINE

.align 2

track_383:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_383_0

.align 2
