.align 2

.global track_542

track_542_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 37
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N18, Cn2, v127
	.byte W06
	.byte VOL, 75
	.byte W06
	.byte 113 @ VOL
	.byte W12
	.byte VOICE, 5
	.byte VOL, 120
	.byte N04, An3 @ v127
	.byte W04
	.byte VOICE, 6
	.byte VOL, 120
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N15, Cn4, v080
	.byte W02
	.byte VOL, 115
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 108
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 99
	.byte BEND, c_v+21
	.byte W02
	.byte VOL, 85
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 34
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 9
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_542:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a826c
	.word track_542_0

.align 2
