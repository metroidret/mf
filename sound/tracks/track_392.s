.align 2

.global track_392

track_392_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 70
	.byte PAN, c_v
	.byte N36, Bn1, v127
	.byte W21
	.byte VOL, 70
	.byte W03
	.byte 64 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_392:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_392_0

.align 2
