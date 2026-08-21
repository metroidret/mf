.align 2

.global track_370

track_370_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 61
	.byte VOL, 60
	.byte PAN, c_v
	.byte N07, An2, v092
	.byte W07
	.byte FINE

.align 2

track_370:
	.byte 1
	.byte 0
	.byte 167
	.byte 0
	.word 0x80a6d54
	.word track_370_0

.align 2
