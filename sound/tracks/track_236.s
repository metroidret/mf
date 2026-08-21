.align 2

.global track_236

track_236_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 43
	.byte VOL, 55
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

track_236_1:
	.byte KEYSH, 0
	.byte VOICE, 44
	.byte VOL, 52
	.byte PAN, c_v
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N13, Cn1, v100
	.byte W03
	.byte BEND, c_v+13
	.byte W03
	.byte c_v+25 @ BEND
	.byte W03
	.byte c_v+38 @ BEND
	.byte W03
	.byte c_v+50 @ BEND
	.byte W03
	.byte c_v+63 @ BEND
	.byte W01
	.byte FINE

.align 2

track_236:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_236_0
	.word track_236_1

.align 2
