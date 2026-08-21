.align 2

.global track_347

track_347_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 46
	.byte VOL, 50
	.byte PAN, c_v
	.byte N05, Cn3, v127
	.byte W05
	.byte VOICE, 48
	.byte N03, Fn4, v100
	.byte W19
	.byte FINE

.align 2

track_347:
	.byte 1
	.byte 0
	.byte 131
	.byte 0
	.word 0x80a6d54
	.word track_347_0

.align 2
