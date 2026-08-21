.align 2

.global track_379

track_379_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 41
	.byte VOL, 55
	.byte PAN, c_v
	.byte N05, Gs2, v080
	.byte W05
	.byte FINE

.align 2

track_379:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word 0x80a6d54
	.word track_379_0

.align 2
