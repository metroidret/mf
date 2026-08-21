.align 2

.global track_706

track_706_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 80
	.byte N84, Cn3, v080
	.byte W60
	.byte W24
	.byte FINE

.align 2

track_706:
	.byte 1
	.byte 0
	.byte 255
	.byte 128
	.word 0x80a8af4
	.word track_706_0

.align 2
