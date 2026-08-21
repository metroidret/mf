.align 2

.global track_440

track_440_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte MOD, 20
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 0
	.byte LFOS, 40
	.byte N30, Bn1, v127
	.byte W03
	.byte VOL, 64
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 78 @ VOL
	.byte W03
	.byte 80 @ VOL
	.byte W03
	.byte 76 @ VOL
	.byte LFOS, 5
	.byte W03
	.byte VOL, 67
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 35 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte FINE

.align 2

track_440:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a6d54
	.word track_440_0

.align 2
