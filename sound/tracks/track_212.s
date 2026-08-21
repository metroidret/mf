.align 2

.global track_212

track_212_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 75
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N13, Cn3, v127
	.byte W28
	.byte W01
	.byte FINE

track_212_1:
	.byte KEYSH, 0
	.byte VOICE, 27
	.byte VOL, 120
	.byte PAN, c_v
	.byte N04, Gs3, v127
	.byte W05
	.byte Ds3, v100 @ N04
	.byte W04
	.byte VOICE, 28
	.byte N04, Fs3, v080
	.byte W20
	.byte FINE

.align 2

track_212:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_212_0
	.word track_212_1

.align 2
