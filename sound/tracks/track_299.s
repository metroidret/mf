.align 2

.global track_299

track_299_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 8
	.byte PAN, c_v
	.byte N03, Gn4, v080
	.byte W03
	.byte N04, Cn4, v120
	.byte W04
	.byte N03, Cn4, v060
	.byte W03
	.byte Cn4, v020 @ N03
	.byte W03
	.byte FINE

.align 2

track_299:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_299_0

.align 2
