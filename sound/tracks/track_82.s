.align 2

.global track_82

track_82_0:
	.byte KEYSH, 0
track_82_lbl_26aa5e:
	.byte TEMPO, 60
	.byte VOICE, 5
	.byte VOL, 94
	.byte N03, Gn3, v088
	.byte W48
	.byte Cn3 @ N03, v088
	.byte W48
	.byte GOTO
		.word track_82_lbl_26aa5e
	.byte FINE

.align 2

track_82:
	.byte 1
	.byte 82
	.byte 130
	.byte 128
	.word 0x80a59e0
	.word track_82_0

.align 2
