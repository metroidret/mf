.align 2

.global track_574

track_574_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 100
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W01
	.byte N19, En3, v127
	.byte W19
	.byte En3, v060 @ N19
	.byte W19
	.byte En3, v020 @ N19
	.byte W19
	.byte FINE

track_574_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte N19, Cn3, v127
	.byte W19
	.byte Cn3, v060 @ N19
	.byte W19
	.byte Cn3, v020 @ N19
	.byte W20
	.byte FINE

.align 2

track_574:
	.byte 2
	.byte 0
	.byte 227
	.byte 0
	.word 0x80a7798
	.word track_574_0
	.word track_574_1

.align 2
