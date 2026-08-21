.align 2

.global track_674

track_674_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 75
	.byte PAN, c_v
	.byte N18, Cn3, v127
	.byte W18
	.byte FINE

.align 2

track_674:
	.byte 1
	.byte 0
	.byte 198
	.byte 0
	.word 0x80a838c
	.word track_674_0

.align 2
