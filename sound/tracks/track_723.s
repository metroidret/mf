.align 2

.global track_723

track_723_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 80
	.byte N48, Cn3, v080
	.byte W48
	.byte W02
	.byte VOICE, 22
	.byte N52 @ Cn3, v080
	.byte W10
	.byte W42
	.byte W01
	.byte VOICE, 23
	.byte TIE @ Cn3, v080
	.byte W17
	.byte W60
	.byte W60
	.byte W07
	.byte EOT @ Cn3, v080
	.byte FINE

.align 2

track_723:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_723_0

.align 2
