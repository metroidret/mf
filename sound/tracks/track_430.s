.align 2

.global track_430

track_430_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 39
	.byte PAN, c_v
	.byte N03, Fn4, v100
	.byte W03
	.byte N04, Dn4, v080
	.byte W04
	.byte FINE

.align 2

track_430:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_430_0

.align 2
