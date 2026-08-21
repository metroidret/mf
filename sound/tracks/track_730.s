.align 2

.global track_730

track_730_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 80
	.byte TIE, Cn3, v080
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W12
	.byte EOT @ Cn3, v080
	.byte W48
	.byte W60
	.byte TIE @ Cn3, v080
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W60
	.byte W12
	.byte EOT @ Cn3, v080
	.byte FINE

.align 2

track_730:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_730_0

.align 2
