.align 2

.global track_218

track_218_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N09, Cn3, v127
	.byte W09
	.byte N10, Cn3, v040
	.byte W36
	.byte FINE

track_218_1:
	.byte KEYSH, 0
	.byte VOICE, 30
	.byte VOL, 60
	.byte PAN, c_v
	.byte N15, Cn3, v100
	.byte W15
	.byte N30, Cn3, v020
	.byte W30
	.byte FINE

.align 2

track_218:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_218_0
	.word track_218_1

.align 2
