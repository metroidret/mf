.align 2

.global track_165

track_165_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N06, Cn4, v127
	.byte W06
	.byte FINE

.align 2

track_165:
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.word 0x80a8008
	.word track_165_0

.align 2
