.align 2

.global track_369

track_369_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 60
	.byte PAN, c_v
	.byte N11, Dn1, v080
	.byte W11
	.byte FINE

track_369_1:
	.byte KEYSH, 0
	.byte VOICE, 55
	.byte VOL, 33
	.byte PAN, c_v
	.byte N11, Cn3, v044
	.byte W11
	.byte FINE

.align 2

track_369:
	.byte 2
	.byte 0
	.byte 165
	.byte 0
	.word 0x80a6d54
	.word track_369_0
	.word track_369_1

.align 2
