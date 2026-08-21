.align 2

.global track_431

track_431_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 31
	.byte PAN, c_v
	.byte N04, Dn4, v080
	.byte W04
	.byte FINE

.align 2

track_431:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_431_0

.align 2
