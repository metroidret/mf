.align 2

.global track_613

track_613_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 1
	.byte N04, Cn3, v127
	.byte W04
	.byte VOICE, 1
	.byte N28, Gn3, v080
	.byte W08
	.byte VOL, 110
	.byte W02
	.byte 106 @ VOL
	.byte W02
	.byte 103 @ VOL
	.byte W02
	.byte 97 @ VOL
	.byte W02
	.byte 92 @ VOL
	.byte W02
	.byte 85 @ VOL
	.byte W02
	.byte 77 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 38 @ VOL
	.byte W02
	.byte 17 @ VOL
	.byte W01
	.byte FINE

track_613_1:
	.byte KEYSH, 0
	.byte VOICE, 4
	.byte VOL, 51
	.byte PAN, c_v
	.byte BENDR, 12
	.byte W07
	.byte BEND, c_v
	.byte N10, Cn3, v092
	.byte W02
	.byte BEND, c_v+3
	.byte W02
	.byte c_v+8 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W02
	.byte c_v+25 @ BEND
	.byte W18
	.byte FINE

.align 2

track_613:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_613_0
	.word track_613_1

.align 2
