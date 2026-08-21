.align 2

.global track_683

track_683_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 30
	.byte BEND, c_v
	.byte N20, Cn3, v127
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+1
	.byte W01
	.byte VOL, 65
	.byte W01
	.byte 66 @ VOL
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 69
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 71
	.byte W01
	.byte 74 @ VOL
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 92
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 100
	.byte BEND, c_v+11
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

.align 2

track_683:
	.byte 1
	.byte 0
	.byte 182
	.byte 0
	.word 0x80a838c
	.word track_683_0

.align 2
