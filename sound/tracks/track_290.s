.align 2

.global track_290

track_290_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 39
	.byte PAN, c_v-24
	.byte W15
	.byte N23, Cn3, v080
	.byte W23
	.byte FINE

.align 2

track_290:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_290_0

.align 2
