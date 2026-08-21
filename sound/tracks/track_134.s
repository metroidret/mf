.align 2

.global track_134

track_134_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 14
	.byte VOL, 27
	.byte PAN, c_v
	.byte N03, Cn3, v092
	.byte W03
	.byte FINE

.align 2

track_134:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word 0x80a682c
	.word track_134_0

.align 2
