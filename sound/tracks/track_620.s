.align 2

.global track_620

track_620_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 78
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N19, An2, v127
	.byte W19
	.byte An2, v060 @ N19
	.byte W28
	.byte W01
	.byte FINE

track_620_1:
	.byte KEYSH, 0
	.byte VOICE, 10
	.byte VOL, 86
	.byte PAN, c_v
	.byte W05
	.byte N10, Dn2, v127
	.byte W42
	.byte W01
	.byte FINE

.align 2

track_620:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_620_0
	.word track_620_1

.align 2
