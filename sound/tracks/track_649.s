.align 2

.global track_649

track_649_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 4
	.byte N90, Cn3, v127
	.byte W96
	.byte W20
	.byte FINE

track_649_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W48
	.byte N68, Cn3, v127
	.byte W42
	.byte VOL, 70
	.byte W03
	.byte 45 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W03
	.byte 20 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W02
	.byte FINE

.align 2

track_649:
	.byte 2
	.byte 0
	.byte 225
	.byte 0
	.word 0x80a7e10
	.word track_649_0
	.word track_649_1

.align 2
