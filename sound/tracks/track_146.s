.align 2

.global track_146

track_146_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 31
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-49
	.byte N42, Cn4, v127
	.byte W01
	.byte VOL, 38
	.byte W01
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v+24
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v+35
	.byte W02
	.byte VOL, 45
	.byte W01
	.byte BEND, c_v+43
	.byte W02
	.byte VOL, 41
	.byte BEND, c_v+28
	.byte W02
	.byte VOL, 36
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 20
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 16
	.byte W01
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 13
	.byte BEND, c_v-13
	.byte W02
	.byte VOL, 10
	.byte BEND, c_v-27
	.byte W02
	.byte c_v-37 @ BEND
	.byte VOL, 8
	.byte W02
	.byte BEND, c_v-44
	.byte W01
	.byte VOL, 7
	.byte W02
	.byte BEND, c_v-51
	.byte VOL, 6
	.byte W01
	.byte BEND, c_v-57
	.byte W01
	.byte VOL, 5
	.byte W01
	.byte BEND, c_v-51
	.byte W01
	.byte VOL, 5
	.byte W02
	.byte BEND, c_v-43
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 2
	.byte W02
	.byte 2 @ VOL
	.byte W01
	.byte FINE

track_146_1:
	.byte KEYSH, 0
	.byte VOICE, 26
	.byte VOL, 3
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-48
	.byte N16, Gn3, v112
	.byte W02
	.byte VOL, 6
	.byte BEND, c_v-45
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v-39
	.byte W02
	.byte VOL, 31
	.byte BEND, c_v-31
	.byte W03
	.byte VOL, 39
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v-1
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v+39
	.byte W03
	.byte VOL, 35
	.byte N05, Gn3, v100
	.byte W07
	.byte Gn3, v052 @ N05
	.byte W08
	.byte Gn3, v016 @ N05
	.byte W12
	.byte FINE

.align 2

track_146:
	.byte 2
	.byte 0
	.byte 220
	.byte 0
	.word 0x80a682c
	.word track_146_0
	.word track_146_1

.align 2
