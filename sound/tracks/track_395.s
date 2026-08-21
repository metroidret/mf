.align 2

.global track_395

track_395_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 90
	.byte PAN, c_v
	.byte N36, Gn1, v127
	.byte W21
	.byte VOL, 90
	.byte W03
	.byte 82 @ VOL
	.byte W03
	.byte 75 @ VOL
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_395:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_395_0

.align 2
