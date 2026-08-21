.align 2

.global track_634

track_634_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte VOL, 120
	.byte PAN, c_v
	.byte W05
	.byte N40, Cn3, v127
	.byte W40
	.byte FINE

.align 2

track_634:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_634_0

.align 2
