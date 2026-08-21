.align 2

.global track_742

track_742_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 80
	.byte N48, Cn3, v080
	.byte W48
	.byte VOICE, 1
	.byte N54 @ Cn3, v080
	.byte W12
	.byte W42
	.byte W01
	.byte VOICE, 26
	.byte N84 @ Cn3, v080
	.byte W17
	.byte W60
	.byte W07
	.byte FINE

.align 2

track_742:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_742_0

.align 2
