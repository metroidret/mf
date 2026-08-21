.align 2

.global track_348

track_348_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 45
	.byte PAN, c_v
	.byte N02, Gn3, v032
	.byte W02
	.byte VOICE, 50
	.byte N04, Cn3, v127
	.byte W04
	.byte FINE

.align 2

track_348:
	.byte 1
	.byte 0
	.byte 132
	.byte 0
	.word 0x80a6d54
	.word track_348_0

.align 2
