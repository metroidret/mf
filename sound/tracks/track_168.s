.align 2

.global track_168

track_168_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 77
	.byte PAN, c_v
	.byte BENDR, 4
	.byte BEND, c_v+63
	.byte N40, Dn3, v088
	.byte W03
	.byte VOL, 95
	.byte W03
	.byte 100 @ VOL
	.byte W03
	.byte 94 @ VOL
	.byte BEND, c_v+58
	.byte W03
	.byte VOL, 78
	.byte BEND, c_v+47
	.byte W03
	.byte VOL, 57
	.byte BEND, c_v+34
	.byte W03
	.byte VOL, 32
	.byte BEND, c_v+19
	.byte W03
	.byte VOL, 4
	.byte W01
	.byte 0 @ VOL
	.byte W18
	.byte FINE

.align 2

track_168:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a8008
	.word track_168_0

.align 2
