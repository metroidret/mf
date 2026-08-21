.align 2

.global track_394

track_394_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 68
	.byte VOL, 56
	.byte PAN, c_v
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N30, Dn3, v060
	.byte W15
	.byte VOL, 56
	.byte W03
	.byte 52 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte VOICE, 51
	.byte VOL, 35
	.byte N03, En1 @ v060
	.byte W03
	.byte Fn1, v080 @ N03
	.byte W03
	.byte Gn1, v100 @ N03
	.byte W03
	.byte Bn1, v120 @ N03
	.byte W03
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N10, Fn1, v080
	.byte W03
	.byte BEND, c_v+12
	.byte W03
	.byte c_v+25 @ BEND
	.byte VOL, 60
	.byte W03
	.byte BEND, c_v+37
	.byte VOL, 70
	.byte W01
	.byte N10 @ Fn1, v080
	.byte W02
	.byte BEND, c_v+50
	.byte VOL, 80
	.byte W03
	.byte 90 @ VOL
	.byte BEND, c_v+63
	.byte W05
	.byte N10 @ Fn1, v080
	.byte W04
	.byte BEND, c_v+63
	.byte W03
	.byte c_v+56 @ BEND
	.byte W03
	.byte VOL, 90
	.byte BEND, c_v+50
	.byte N10 @ Fn1, v080
	.byte W03
	.byte VOL, 83
	.byte BEND, c_v+43
	.byte W03
	.byte VOL, 77
	.byte BEND, c_v+37
	.byte W03
	.byte VOL, 72
	.byte BEND, c_v+30
	.byte W01
	.byte N10 @ Fn1, v080
	.byte W02
	.byte VOL, 66
	.byte BEND, c_v+24
	.byte W03
	.byte VOL, 60
	.byte BEND, c_v+17
	.byte W03
	.byte VOL, 55
	.byte BEND, c_v+11
	.byte W02
	.byte N10 @ Fn1, v080
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+6
	.byte W03
	.byte VOL, 43
	.byte BEND, c_v+3
	.byte W03
	.byte VOL, 37
	.byte BEND, c_v+1
	.byte W03
	.byte VOL, 31
	.byte N03 @ Fn1, v080
	.byte W02
	.byte VOL, 28
	.byte W05
	.byte VOICE, 68
	.byte VOL, 42
	.byte N12, An2 @ v080
	.byte W05
	.byte VOL, 41
	.byte W03
	.byte 21 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_394:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a6d54
	.word track_394_0

.align 2
