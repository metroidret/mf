.align 2

.global track_652

track_652_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 9
	.byte N68, En3, v127
	.byte W68
	.byte N90, Cn3, v040
	.byte W28
	.byte W36
	.byte W03
	.byte VOL, 90
	.byte W03
	.byte 58 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 17 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_652_1:
	.byte KEYSH, 0
	.byte VOICE, 6
	.byte VOL, 63
	.byte PAN, c_v
	.byte PRIO, 6
	.byte N15, Cn3, v127
	.byte W15
	.byte N18, Cn3, v040
	.byte W30
	.byte W01
	.byte VOICE, 2
	.byte VOL, 90
	.byte PRIO, 1
	.byte N56, Cn3, v127
	.byte W32
	.byte W01
	.byte VOL, 90
	.byte W03
	.byte 53 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W02
	.byte W01
	.byte 5 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W54
	.byte W01
	.byte FINE

.align 2

track_652:
	.byte 2
	.byte 0
	.byte 219
	.byte 0
	.word 0x80a7e10
	.word track_652_0
	.word track_652_1

.align 2
