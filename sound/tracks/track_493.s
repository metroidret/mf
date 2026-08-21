.align 2

.global track_493

track_493_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 48
	.byte VOL, 50
	.byte PAN, c_v
	.byte TIE, Cn3, v080
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte EOT @ Cn3, v080
	.byte FINE

.align 2

track_493:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_493_0

.align 2
