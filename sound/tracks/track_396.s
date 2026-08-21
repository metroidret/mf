.align 2

.global track_396

track_396_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 45
	.byte VOL, 40
	.byte PAN, c_v
	.byte N05, Bn2, v127
	.byte W05
	.byte VOICE, 64
	.byte N09, Cn3, v032
	.byte W09
	.byte FINE

.align 2

track_396:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_396_0

.align 2
