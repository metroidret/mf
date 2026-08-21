.align 2

.global track_215

track_215_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N13, Cn3, v127
	.byte W18
	.byte FINE

track_215_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 70
	.byte PAN, c_v
	.byte N03, Fs3, v127
	.byte W05
	.byte N08, Cn4 @ v127
	.byte W08
	.byte N05, Cn3, v052
	.byte W05
	.byte FINE

.align 2

track_215:
	.byte 2
	.byte 0
	.byte 195
	.byte 0
	.word 0x80a6af0
	.word track_215_0
	.word track_215_1

.align 2
