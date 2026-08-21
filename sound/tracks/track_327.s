.align 2

.global track_327

track_327_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 93
	.byte VOL, 56
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N23, Cn3, v127
	.byte W48
	.byte FINE

track_327_1:
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

track_327:
	.byte 2
	.byte 0
	.byte 189
	.byte 0
	.word 0x80a6d54
	.word track_327_0
	.word track_327_1

.align 2
