.align 2

.global track_476

track_476_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 25
	.byte PAN, c_v
	.byte N48, Bn2, v060
	.byte W03
	.byte VOL, 32
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W13
	.byte FINE

track_476_1:
	.byte KEYSH, 0
	.byte W12
	.byte VOICE, 1
	.byte VOL, 25
	.byte PAN, c_v
	.byte N48, Bn2, v016
	.byte W03
	.byte VOL, 32
	.byte W03
	.byte 38 @ VOL
	.byte W03
	.byte 43 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 56 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte 40 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_476:
	.byte 2
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a81e8
	.word track_476_0
	.word track_476_1

.align 2
