.align 2

.global track_433

track_433_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 36
	.byte VOL, 62
	.byte PAN, c_v
	.byte N04, Gs2, v127
	.byte W04
	.byte Cs2, v080 @ N04
	.byte W04
	.byte An1, v052 @ N04
	.byte W04
	.byte FINE

.align 2

track_433:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_433_0

.align 2
