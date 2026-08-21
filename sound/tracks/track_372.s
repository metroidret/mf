.align 2

.global track_372

track_372_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 46
	.byte PAN, c_v
	.byte N03, An2, v080
	.byte W03
	.byte Gn3 @ N03, v080
	.byte W03
	.byte En3 @ N03, v080
	.byte W03
	.byte FINE

.align 2

track_372:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_372_0

.align 2
