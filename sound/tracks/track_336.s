.align 2

.global track_336

track_336_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 34
	.byte VOL, 60
	.byte PAN, c_v
	.byte N04, Fs3, v127
	.byte W04
	.byte N05, As2, v080
	.byte W05
	.byte FINE

.align 2

track_336:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_336_0

.align 2
