.align 2

.global track_547

track_547_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 103
	.byte PAN, c_v
	.byte N28, Cn3, v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_547:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a826c
	.word track_547_0

.align 2
