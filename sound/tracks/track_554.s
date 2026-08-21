.align 2

.global track_554

track_554_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 30
	.byte PAN, c_v
	.byte TIE, Cn3, v127
	.byte W96
	.byte W24
	.byte EOT @ Cn3, v127
	.byte FINE

.align 2

track_554:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_554_0

.align 2
