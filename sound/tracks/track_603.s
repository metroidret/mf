.align 2

.global track_603

track_603_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 18
	.byte PAN, c_v
	.byte N08, An2, v127
	.byte W01
	.byte VOL, 28
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W03
	.byte N08, An2, v100
	.byte W03
	.byte VOL, 47
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte FINE

track_603_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 18
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N08, An2, v100
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 36
	.byte BEND, c_v+47
	.byte W01
	.byte c_v @ BEND
	.byte N08 @ An2, v100
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

.align 2

track_603:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7654
	.word track_603_0
	.word track_603_1

.align 2
