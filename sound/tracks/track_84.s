.align 2

.global track_84

track_84_0:
	.byte KEYSH, 0
track_84_lbl_26ac62:
	.byte TEMPO, 39
	.byte VOICE, 1
	.byte VOL, 94
	.byte PAN, c_v
	.byte N06, En3, v112
	.byte W48
	.byte Fs3 @ N06, v112
	.byte W48
	.byte GOTO
		.word track_84_lbl_26ac62
	.byte FINE

.align 2

track_84:
	.byte 1
	.byte 84
	.byte 130
	.byte 128
	.word 0x80a62f8
	.word track_84_0

.align 2
