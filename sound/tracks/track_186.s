.align 2

.global track_186

track_186_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 12
	.byte VOL, 60
	.byte PAN, c_v
	.byte N09, An2, v100
	.byte W16
	.byte Bn2, v127 @ N09
	.byte W09
	.byte FINE

.align 2

track_186:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a74c8
	.word track_186_0

.align 2
