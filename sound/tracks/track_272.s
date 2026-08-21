.align 2

.global track_272

track_272_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 21
	.byte VOL, 35
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte An2 @ N02, v080
	.byte W02
	.byte VOICE, 20
	.byte BENDR, 12
	.byte BEND, c_v+17
	.byte N24, En3, v052
	.byte W02
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+11 @ BEND
	.byte W03
	.byte c_v+15 @ BEND
	.byte W20
	.byte FINE

.align 2

track_272:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_272_0

.align 2
