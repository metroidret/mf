.align 2

.global track_363

track_363_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 57
	.byte VOL, 60
	.byte PAN, c_v
	.byte N10, Fn1, v080
	.byte W10
	.byte VOICE, 59
	.byte N08, Cn1, v060
	.byte W08
	.byte FINE

.align 2

track_363:
	.byte 1
	.byte 0
	.byte 141
	.byte 0
	.word 0x80a6d54
	.word track_363_0

.align 2
