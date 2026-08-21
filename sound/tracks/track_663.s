.align 2

.global track_663

track_663_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 62
	.byte PAN, c_v
	.byte N07, Cn3, v080
	.byte W12
	.byte VOICE, 3
	.byte VOL, 78
	.byte PAN, c_v
	.byte N15 @ Cn3, v080
	.byte W20
	.byte N16, An2, v064
	.byte W20
	.byte N15, Cn3 @ v064
	.byte W20
	.byte N16, An2 @ v064
	.byte W21
	.byte VOICE, 4
	.byte VOL, 62
	.byte PAN, c_v
	.byte N11, Cn3, v080
	.byte W03
	.byte W08
	.byte FINE

.align 2

track_663:
	.byte 1
	.byte 0
	.byte 179
	.byte 0
	.word 0x80a7f24
	.word track_663_0

.align 2
