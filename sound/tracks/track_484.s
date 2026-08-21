.align 2

.global track_484

track_484_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 100
	.byte PAN, c_v
	.byte N36, Cn1, v127
	.byte W02
	.byte VOL, 110
	.byte W02
	.byte 121 @ VOL
	.byte W01
	.byte 127 @ VOL
	.byte W19
	.byte 127 @ VOL
	.byte W01
	.byte 115 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W48
	.byte W01
	.byte FINE

track_484_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N24, Ds2, v127
	.byte W84
	.byte FINE

.align 2

track_484:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a81e8
	.word track_484_0
	.word track_484_1

.align 2
