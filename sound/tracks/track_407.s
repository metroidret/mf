.align 2

.global track_407

track_407_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 37
	.byte PAN, c_v
	.byte N07, Fn2, v127
	.byte W07
	.byte VOICE, 38
	.byte N07, Cn2, v100
	.byte W07
	.byte VOICE, 36
	.byte N05, Cn2, v080
	.byte W05
	.byte FINE

.align 2

track_407:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_407_0

.align 2
