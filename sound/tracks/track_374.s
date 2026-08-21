.align 2

.global track_374

track_374_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 64
	.byte VOL, 21
	.byte PAN, c_v
	.byte W10
	.byte N05, En3, v080
	.byte W05
	.byte FINE

.align 2

track_374:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a6d54
	.word track_374_0

.align 2
