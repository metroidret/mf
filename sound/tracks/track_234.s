.align 2

.global track_234

track_234_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v+57
	.byte N13, Cn3, v100
	.byte W16
	.byte FINE

track_234_1:
	.byte KEYSH, 0
	.byte VOICE, 37
	.byte MOD, 100
	.byte VOL, 44
	.byte PAN, c_v
	.byte LFOS, 100
	.byte N16, Cn4, v088
	.byte W16
	.byte FINE

.align 2

track_234:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_234_0
	.word track_234_1

.align 2
