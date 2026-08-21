.align 2

.global track_708

track_708_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 15
	.byte VOL, 80
	.byte N84, Cn3, v080
	.byte W60
	.byte W24
	.byte FINE

.align 2

track_708:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_708_0

.align 2
