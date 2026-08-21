.align 2

.global track_343

track_343_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 18
	.byte VOL, 40
	.byte PAN, c_v
	.byte N03, Fn2, v127
	.byte W04
	.byte An2 @ N03, v127
	.byte W04
	.byte Fn2 @ N03, v127
	.byte W03
	.byte Cn2 @ N03, v127
	.byte W03
	.byte N01, Gs2 @ v127
	.byte W01
	.byte FINE

.align 2

track_343:
	.byte 1
	.byte 0
	.byte 133
	.byte 0
	.word 0x80a6d54
	.word track_343_0

.align 2
