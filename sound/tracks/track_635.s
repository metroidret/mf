.align 2

.global track_635

track_635_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 60
	.byte VOL, 90
	.byte PAN, c_v
	.byte LFOS, 110
	.byte N24, Cn3, v127
	.byte W24
	.byte W03
	.byte FINE

track_635_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, Cn3, v127
	.byte W16
	.byte VOL, 90
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 41 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W02
	.byte 24 @ VOL
	.byte W03
	.byte FINE

.align 2

track_635:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7d14
	.word track_635_0
	.word track_635_1

.align 2
