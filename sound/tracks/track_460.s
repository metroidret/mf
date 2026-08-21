.align 2

.global track_460

track_460_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 95
	.byte VOL, 127
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N18, Dn3, v064
	.byte W18
	.byte FINE

.align 2

track_460:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_460_0

.align 2
