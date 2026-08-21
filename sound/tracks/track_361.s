.align 2

.global track_361

track_361_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 28
	.byte PAN, c_v
	.byte N18, An1, v060
	.byte W06
	.byte VOL, 18
	.byte W06
	.byte 9 @ VOL
	.byte W06
	.byte FINE

.align 2

track_361:
	.byte 1
	.byte 0
	.byte 141
	.byte 0
	.word 0x80a6d54
	.word track_361_0

.align 2
