.align 2

.global track_421

track_421_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 100
	.byte PAN, c_v
	.byte N05, Ds2, v127
	.byte W05
	.byte N10, An2, v080
	.byte W03
	.byte VOL, 78
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W01
	.byte FINE

.align 2

track_421:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_421_0

.align 2
