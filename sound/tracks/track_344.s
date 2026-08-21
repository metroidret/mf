.align 2

.global track_344

track_344_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 42
	.byte PAN, c_v
	.byte N03, An2, v100
	.byte W04
	.byte Cn3, v127 @ N03
	.byte W03
	.byte FINE

.align 2

track_344:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_344_0

.align 2
