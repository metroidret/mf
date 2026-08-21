.align 2

.global track_669

track_669_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 16
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N24, An2, v100
	.byte W48
	.byte FINE

track_669_1:
	.byte KEYSH, 0
	.byte VOICE, 17
	.byte VOL, 103
	.byte PAN, c_v
	.byte W01
	.byte N04, Bn2, v120
	.byte W04
	.byte VOICE, 18
	.byte VOL, 110
	.byte PRIO, 127
	.byte N10, As2, v100
	.byte W10
	.byte N07, Fs2 @ v100
	.byte W32
	.byte W01
	.byte FINE

.align 2

track_669:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a7f24
	.word track_669_0
	.word track_669_1

.align 2
