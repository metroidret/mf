.align 2

.global track_391

track_391_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 51
	.byte VOL, 33
	.byte PAN, c_v
	.byte N06, Fn1, v060
	.byte W06
	.byte An1, v080 @ N06
	.byte W06
	.byte Bn1, v100 @ N06
	.byte W06
	.byte Dn2, v120 @ N06
	.byte W06
	.byte BENDR, 12
	.byte BEND, c_v
	.byte VOL, 40
	.byte N10, Cn1, v080
	.byte W03
	.byte BEND, c_v+12
	.byte VOL, 48
	.byte W03
	.byte BEND, c_v+25
	.byte VOL, 57
	.byte W03
	.byte BEND, c_v+37
	.byte VOL, 66
	.byte W01
	.byte N10 @ Cn1, v080
	.byte W02
	.byte BEND, c_v+50
	.byte VOL, 75
	.byte W03
	.byte 85 @ VOL
	.byte BEND, c_v+63
	.byte W05
	.byte N10 @ Cn1, v080
	.byte W04
	.byte BEND, c_v+63
	.byte W03
	.byte c_v+56 @ BEND
	.byte W03
	.byte VOL, 85
	.byte BEND, c_v+50
	.byte N10 @ Cn1, v080
	.byte W03
	.byte VOL, 78
	.byte BEND, c_v+43
	.byte W03
	.byte VOL, 73
	.byte BEND, c_v+37
	.byte W03
	.byte VOL, 68
	.byte BEND, c_v+30
	.byte W01
	.byte N10 @ Cn1, v080
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v+24
	.byte W03
	.byte VOL, 57
	.byte BEND, c_v+17
	.byte W03
	.byte VOL, 52
	.byte BEND, c_v+11
	.byte W02
	.byte N10 @ Cn1, v080
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v+6
	.byte W03
	.byte VOL, 40
	.byte BEND, c_v+3
	.byte W03
	.byte VOL, 35
	.byte BEND, c_v+1
	.byte W03
	.byte VOL, 30
	.byte N03 @ Cn1, v080
	.byte W02
	.byte VOL, 26
	.byte W01
	.byte FINE

.align 2

track_391:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a6d54
	.word track_391_0

.align 2
