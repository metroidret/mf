.align 2

.global track_629

track_629_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 100
	.byte PAN, c_v
	.byte N56, Cn1, v127
	.byte W02
	.byte VOL, 110
	.byte W02
	.byte 121 @ VOL
	.byte W01
	.byte 127 @ VOL
	.byte W42
	.byte W01
	.byte 127 @ VOL
	.byte W03
	.byte 84 @ VOL
	.byte W03
	.byte 41 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W15
	.byte FINE

track_629_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 126
	.byte N24, Ds2, v127
	.byte W72
	.byte FINE

.align 2

track_629:
	.byte 2
	.byte 0
	.byte 182
	.byte 0
	.word 0x80a7aa4
	.word track_629_0
	.word track_629_1

.align 2
