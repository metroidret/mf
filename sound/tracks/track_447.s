.align 2

.global track_447

track_447_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 54
	.byte VOL, 37
	.byte PAN, c_v
	.byte W01
	.byte N30, Fn2, v127
	.byte W44
	.byte W03
	.byte FINE

track_447_1:
	.byte KEYSH, 0
	.byte VOICE, 93
	.byte VOL, 50
	.byte PAN, c_v
	.byte N23, Cn3, v127
	.byte W48
	.byte FINE

.align 2

track_447:
	.byte 2
	.byte 0
	.byte 190
	.byte 0
	.word 0x80a6d54
	.word track_447_0
	.word track_447_1

.align 2
