.align 2

.global track_668

track_668_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W04
	.byte VOICE, 15
	.byte VOL, 62
	.byte MOD, 15
	.byte PAN, c_v
	.byte LFOS, 60
	.byte W02
	.byte N18, Fn3, v064
	.byte W03
	.byte VOL, 50
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_668:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a7f24
	.word track_668_0

.align 2
