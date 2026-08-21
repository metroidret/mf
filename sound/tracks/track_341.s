.align 2

.global track_341

track_341_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 27
	.byte PAN, c_v
	.byte N03, Fn2, v127
	.byte W05
	.byte Bn2 @ N03, v127
	.byte W03
	.byte FINE

.align 2

track_341:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_341_0

.align 2
