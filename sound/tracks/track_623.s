.align 2

.global track_623

track_623_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 120
	.byte PAN, c_v
	.byte N06, Cn4, v127
	.byte W06
	.byte FINE

.align 2

track_623:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a7aa4
	.word track_623_0

.align 2
