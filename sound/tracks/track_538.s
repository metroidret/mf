.align 2

.global track_538

track_538_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 30
	.byte PAN, c_v
	.byte BENDR, 6
	.byte PRIO, 1
	.byte N60, Dn3, v127
	.byte W02
	.byte VOL, 39
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte 66 @ VOL
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 55
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 43
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 41
	.byte BEND, c_v+29
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v+30
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v+28
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v+25
	.byte W02
	.byte c_v+23 @ BEND
	.byte VOL, 50
	.byte W02
	.byte BEND, c_v+20
	.byte VOL, 53
	.byte W02
	.byte BEND, c_v+18
	.byte VOL, 51
	.byte W02
	.byte BEND, c_v+15
	.byte VOL, 48
	.byte W02
	.byte BEND, c_v+13
	.byte VOL, 43
	.byte W02
	.byte BEND, c_v+10
	.byte VOL, 38
	.byte W02
	.byte BEND, c_v+8
	.byte VOL, 27
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 11
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 7
	.byte W01
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte c_v+1 @ BEND
	.byte VOL, 0
	.byte W17
	.byte FINE

track_538_1:
	.byte KEYSH, 0
	.byte W15
	.byte VOICE, 3
	.byte VOL, 30
	.byte PAN, c_v
	.byte BENDR, 6
	.byte N60, Dn3, v032
	.byte W02
	.byte VOL, 39
	.byte W02
	.byte 48 @ VOL
	.byte W02
	.byte 54 @ VOL
	.byte W02
	.byte 60 @ VOL
	.byte W02
	.byte 65 @ VOL
	.byte W02
	.byte 68 @ VOL
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 68
	.byte W01
	.byte 66 @ VOL
	.byte BEND, c_v+16
	.byte W02
	.byte VOL, 55
	.byte BEND, c_v+19
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 43
	.byte BEND, c_v+26
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v+29
	.byte W02
	.byte c_v+33 @ BEND
	.byte W02
	.byte VOL, 38
	.byte BEND, c_v+30
	.byte W02
	.byte VOL, 37
	.byte BEND, c_v+28
	.byte W02
	.byte VOL, 35
	.byte BEND, c_v+25
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v+23
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+20
	.byte W02
	.byte VOL, 29
	.byte BEND, c_v+18
	.byte W02
	.byte VOL, 27
	.byte BEND, c_v+15
	.byte W02
	.byte VOL, 24
	.byte BEND, c_v+13
	.byte W02
	.byte VOL, 20
	.byte BEND, c_v+10
	.byte W02
	.byte VOL, 16
	.byte BEND, c_v+8
	.byte VOL, 14
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 9
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 6
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte VOL, 4
	.byte W01
	.byte BEND, c_v+4
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte VOL, 1
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte c_v+1 @ BEND
	.byte VOL, 0
	.byte W02
	.byte FINE

.align 2

track_538:
	.byte 2
	.byte 0
	.byte 190
	.byte 0
	.word 0x80a826c
	.word track_538_0
	.word track_538_1

.align 2
