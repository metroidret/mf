.align 2

.global track_665

track_665_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 80
	.byte PAN, c_v
	.byte N18, Gn3, v127
	.byte W36
	.byte W02
	.byte FINE

track_665_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W02
	.byte N24, Fn2, v127
	.byte W09
	.byte VOL, 127
	.byte W01
	.byte 109 @ VOL
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W13
	.byte FINE

track_665_2:
	.byte KEYSH, 0
	.byte VOICE, 12
	.byte VOL, 120
	.byte PAN, c_v
	.byte N13, Fn2, v127
	.byte W36
	.byte W02
	.byte FINE

.align 2

track_665:
	.byte 3
	.byte 0
	.byte 190
	.byte 0
	.word 0x80a7f24
	.word track_665_0
	.word track_665_1
	.word track_665_2

.align 2
