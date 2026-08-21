.align 2

.global track_684

track_684_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte MOD, 10
	.byte VOL, 13
	.byte PAN, c_v
	.byte BENDR, 12
	.byte LFOS, 60
	.byte BEND, c_v
	.byte N60, Fn1, v127
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+34
	.byte VOL, 32
	.byte W01
	.byte BEND, c_v+38
	.byte VOL, 33
	.byte W01
	.byte BEND, c_v+41
	.byte VOL, 35
	.byte W01
	.byte BEND, c_v+45
	.byte VOL, 38
	.byte W01
	.byte BEND, c_v+48
	.byte VOL, 39
	.byte W01
	.byte BEND, c_v+51
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+53
	.byte VOL, 42
	.byte W01
	.byte BEND, c_v+55
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v+57
	.byte VOL, 44
	.byte W01
	.byte BEND, c_v+58
	.byte VOL, 45
	.byte W01
	.byte BEND, c_v+59
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v+61
	.byte W01
	.byte VOL, 48
	.byte W01
	.byte BEND, c_v+62
	.byte W01
	.byte c_v+63 @ BEND
	.byte W01
	.byte VOL, 49
	.byte W02
	.byte 49 @ VOL
	.byte W02
	.byte 49 @ VOL
	.byte W01
	.byte BEND, c_v+62
	.byte VOL, 48
	.byte W01
	.byte BEND, c_v+61
	.byte W02
	.byte c_v+60 @ BEND
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v+59
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v+58
	.byte VOL, 45
	.byte W01
	.byte BEND, c_v+57
	.byte VOL, 45
	.byte W01
	.byte BEND, c_v+55
	.byte VOL, 44
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte BEND, c_v+53
	.byte VOL, 42
	.byte W01
	.byte BEND, c_v+51
	.byte VOL, 40
	.byte W01
	.byte BEND, c_v+50
	.byte VOL, 39
	.byte W01
	.byte BEND, c_v+49
	.byte VOL, 39
	.byte W01
	.byte BEND, c_v+47
	.byte VOL, 37
	.byte W01
	.byte BEND, c_v+45
	.byte VOL, 35
	.byte W01
	.byte BEND, c_v+43
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v+41
	.byte VOL, 32
	.byte W01
	.byte BEND, c_v+39
	.byte VOL, 31
	.byte W01
	.byte BEND, c_v+37
	.byte VOL, 29
	.byte W01
	.byte BEND, c_v+35
	.byte VOL, 27
	.byte W01
	.byte BEND, c_v+33
	.byte VOL, 25
	.byte W01
	.byte BEND, c_v+31
	.byte VOL, 24
	.byte W01
	.byte BEND, c_v+29
	.byte VOL, 22
	.byte W01
	.byte BEND, c_v+26
	.byte VOL, 20
	.byte W01
	.byte BEND, c_v+24
	.byte VOL, 18
	.byte W01
	.byte BEND, c_v+21
	.byte VOL, 17
	.byte W01
	.byte BEND, c_v+19
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+17
	.byte VOL, 13
	.byte W01
	.byte BEND, c_v+15
	.byte VOL, 10
	.byte W01
	.byte BEND, c_v+12
	.byte VOL, 8
	.byte W01
	.byte BEND, c_v+9
	.byte VOL, 6
	.byte W01
	.byte BEND, c_v+6
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v+3
	.byte VOL, 1
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte FINE

.align 2

track_684:
	.byte 1
	.byte 0
	.byte 183
	.byte 0
	.word 0x80a838c
	.word track_684_0

.align 2
