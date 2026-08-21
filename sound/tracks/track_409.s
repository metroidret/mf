.align 2

.global track_409

track_409_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 25
	.byte PAN, c_v
	.byte N10, Gn1, v080
	.byte W03
	.byte VOL, 28
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 31 @ VOL
	.byte W01
	.byte VOICE, 14
	.byte N10, An1 @ v080
	.byte W02
	.byte VOL, 30
	.byte W03
	.byte 29 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W02
	.byte FINE

.align 2

track_409:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_409_0

.align 2
