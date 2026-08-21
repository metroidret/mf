.align 2

.global track_1

track_1_0:
	.byte KEYSH, 0
track_1_lbl_25895e:
	.byte TEMPO, 60
	.byte VOICE, 1
	.byte VOL, 35
	.byte N06, Cn2, v072
	.byte W24
	.byte En2 @ N06, v072
	.byte W72
	.byte GOTO
		.word track_1_lbl_25895e
	.byte FINE

.align 2

track_1:
	.byte 1
	.byte 1
	.byte 130
	.byte 128
	.word 0x80a5710
	.word track_1_0

.align 2
