.align 2

.global track_139

track_139_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 40
	.byte PAN, c_v
	.byte N28, Cn3, v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_139:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a682c
	.word track_139_0

.align 2
