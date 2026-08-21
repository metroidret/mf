.align 2

.global track_328

track_328_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 79
	.byte VOL, 90
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, Cn3, v100
	.byte W48
	.byte FINE

track_328_1:
	.byte KEYSH, 0
	.byte VOICE, 80
	.byte VOL, 85
	.byte PAN, c_v
	.byte W01
	.byte N04, Bn2, v120
	.byte W04
	.byte VOICE, 81
	.byte VOL, 90
	.byte N10, As2, v100
	.byte W10
	.byte N07, Fs2 @ v100
	.byte W32
	.byte W01
	.byte FINE

.align 2

track_328:
	.byte 2
	.byte 0
	.byte 189
	.byte 0
	.word 0x80a6d54
	.word track_328_0
	.word track_328_1

.align 2
