.align 2

.global track_451

track_451_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 84
	.byte VOL, 127
	.byte W42
	.byte N07, Cn4, v020
	.byte W07
	.byte FINE

track_451_1:
	.byte KEYSH, 0
	.byte VOICE, 83
	.byte VOL, 127
	.byte W14
	.byte 127 @ VOL
	.byte N12, En2, v020
	.byte W01
	.byte VOL, 116
	.byte W01
	.byte 105 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte PRIO, 64
	.byte W23
	.byte FINE

.align 2

track_451:
	.byte 2
	.byte 0
	.byte 161
	.byte 128
	.word 0x80a8554
	.word track_451_0
	.word track_451_1

.align 2
