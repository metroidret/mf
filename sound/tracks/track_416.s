.align 2

.global track_416

track_416_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 38
	.byte VOL, 50
	.byte PAN, c_v
	.byte N06, Cn3, v127
	.byte W06
	.byte VOICE, 51
	.byte N03, Cn2, v120
	.byte W03
	.byte VOL, 46
	.byte N06, An1, v080
	.byte W01
	.byte VOL, 43
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte FINE

.align 2

track_416:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word 0x80a6d54
	.word track_416_0

.align 2
