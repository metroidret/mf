.align 2

.global track_195

track_195_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 32
	.byte VOL, 31
	.byte PAN, c_v
	.byte W05
	.byte N36, Cn3, v100
	.byte W42
	.byte W01
	.byte FINE

.align 2

track_195:
	.byte 1
	.byte 0
	.byte 170
	.byte 0
	.word 0x80a74c8
	.word track_195_0

.align 2
