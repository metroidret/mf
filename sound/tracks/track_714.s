.align 2

.global track_714

track_714_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 120
	.byte N52, Cn3, v080
	.byte W52
	.byte VOICE, 1
	.byte N54 @ Cn3, v080
	.byte W08
	.byte W44
	.byte W03
	.byte VOICE, 0
	.byte TIE @ Cn3, v080
	.byte W13
	.byte W60
	.byte W60
	.byte W23
	.byte EOT @ Cn3, v080
	.byte FINE

.align 2

track_714:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_714_0

.align 2
