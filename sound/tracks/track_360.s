.align 2

.global track_360

track_360_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 9
	.byte PAN, c_v
	.byte N18, Cn2, v080
	.byte W06
	.byte VOL, 18
	.byte W06
	.byte 28 @ VOL
	.byte W06
	.byte FINE

.align 2

track_360:
	.byte 1
	.byte 0
	.byte 141
	.byte 0
	.word 0x80a6d54
	.word track_360_0

.align 2
