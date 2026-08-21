.align 2

.global track_209

track_209_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N13, Cn3, v127
	.byte W16
	.byte FINE

track_209_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 60
	.byte PAN, c_v
	.byte W01
	.byte N08, Cn4, v127
	.byte W15
	.byte FINE

.align 2

track_209:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_209_0
	.word track_209_1

.align 2
