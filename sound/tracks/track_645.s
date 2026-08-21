.align 2

.global track_645

track_645_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte MOD, 0
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 0
	.byte BEND, c_v
	.byte N36, Cn3, v127
	.byte W02
	.byte VOL, 69
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 77
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 90
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 100
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 100
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 55
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 66
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 76
	.byte BEND, c_v+51
	.byte W02
	.byte VOL, 90
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 100
	.byte W01
	.byte 100 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W06
	.byte FINE

track_645_1:
	.byte KEYSH, 0
	.byte W05
	.byte VOICE, 11
	.byte MOD, 0
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 0
	.byte BEND, c_v
	.byte N36, Cn3, v100
	.byte W02
	.byte VOL, 69
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 77
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 90
	.byte BEND, c_v+33
	.byte W02
	.byte VOL, 100
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 100
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 70
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 55
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 60
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 66
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 76
	.byte BEND, c_v+51
	.byte W02
	.byte VOL, 90
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 100
	.byte W01
	.byte 100 @ VOL
	.byte W02
	.byte 59 @ VOL
	.byte W02
	.byte 29 @ VOL
	.byte W02
	.byte 12 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_645:
	.byte 2
	.byte 0
	.byte 182
	.byte 0
	.word 0x80a7d14
	.word track_645_0
	.word track_645_1

.align 2
