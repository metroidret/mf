.align 2

.global track_359

track_359_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 100
	.byte PAN, c_v
	.byte N05, Bn1, v127
	.byte W05
	.byte N10, Fn2, v080
	.byte W03
	.byte VOL, 78
	.byte W03
	.byte 55 @ VOL
	.byte W03
	.byte 23 @ VOL
	.byte W01
	.byte FINE

.align 2

track_359:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_359_0

.align 2
