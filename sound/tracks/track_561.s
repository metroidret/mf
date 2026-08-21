.align 2

.global track_561

track_561_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 12
	.byte PAN, c_v
	.byte BENDR, 11
	.byte BEND, c_v
	.byte TIE, An2, v092
	.byte W02
	.byte VOL, 15
	.byte BEND, c_v+5
	.byte W02
	.byte VOL, 18
	.byte BEND, c_v+11
	.byte W02
	.byte VOL, 22
	.byte BEND, c_v+17
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v+22
	.byte W02
	.byte VOL, 28
	.byte BEND, c_v+28
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v+34
	.byte W02
	.byte VOL, 35
	.byte BEND, c_v+39
	.byte W02
	.byte VOL, 38
	.byte BEND, c_v+45
	.byte W02
	.byte VOL, 42
	.byte BEND, c_v+51
	.byte W02
	.byte VOL, 45
	.byte BEND, c_v+56
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v+60
	.byte W02
	.byte MOD, 10
	.byte VOL, 51
	.byte LFOS, 100
	.byte W01
	.byte VOL, 52
	.byte W01
	.byte BEND, c_v+40
	.byte W03
	.byte c_v+31 @ BEND
	.byte W06
	.byte c_v+37 @ BEND
	.byte W03
	.byte c_v+48 @ BEND
	.byte W03
	.byte c_v+55 @ BEND
	.byte W03
	.byte c_v+59 @ BEND
	.byte W03
	.byte c_v+63 @ BEND
	.byte W06
	.byte c_v+61 @ BEND
	.byte W03
	.byte c_v+57 @ BEND
	.byte W01
	.byte c_v+55 @ BEND
	.byte W03
	.byte c_v+41 @ BEND
	.byte W03
	.byte c_v+32 @ BEND
	.byte W03
	.byte c_v+25 @ BEND
	.byte W03
	.byte c_v+20 @ BEND
	.byte W03
	.byte c_v+16 @ BEND
	.byte W02
	.byte c_v+15 @ BEND
	.byte W03
	.byte c_v+45 @ BEND
	.byte W03
	.byte c_v+49 @ BEND
	.byte W16
	.byte MOD, 0
	.byte VOL, 52
	.byte LFOS, 0
	.byte BEND, c_v+59
	.byte W02
	.byte VOL, 47
	.byte W01
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 43
	.byte W02
	.byte 39 @ VOL
	.byte BEND, c_v+44
	.byte W02
	.byte VOL, 34
	.byte W01
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 30
	.byte W02
	.byte 25 @ VOL
	.byte BEND, c_v+29
	.byte W02
	.byte VOL, 21
	.byte W01
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 17
	.byte W02
	.byte 12 @ VOL
	.byte BEND, c_v+14
	.byte W02
	.byte VOL, 8
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte VOL, 3
	.byte W02
	.byte 0 @ VOL
	.byte BEND, c_v
	.byte EOT @ An2, v092
	.byte W10
	.byte FINE

track_561_1:
	.byte KEYSH, 0
	.byte VOICE, 23
	.byte MOD, 60
	.byte VOL, 50
	.byte PAN, c_v
	.byte LFOS, 127
	.byte N24, Cn3, v052
	.byte W56
	.byte W02
	.byte En3, v100 @ N24
	.byte W36
	.byte W02
	.byte W10
	.byte Cn3, v040 @ N24
	.byte W24
	.byte FINE

track_561_2:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 50
	.byte PAN, c_v
	.byte W05
	.byte N12, Cn3, v060
	.byte W12
	.byte VOICE, 21
	.byte VOL, 80
	.byte N02, Cn4, v020
	.byte W02
	.byte N03, Gn3, v052
	.byte W03
	.byte N04, Cn3, v080
	.byte W04
	.byte N03, Cn3, v040
	.byte W03
	.byte VOICE, 20
	.byte W09
	.byte N24, Cn3, v060
	.byte W24
	.byte VOICE, 21
	.byte VOL, 37
	.byte N02, Dn4, v020
	.byte W03
	.byte N03, An3, v052
	.byte W04
	.byte N04, Cn3, v080
	.byte W08
	.byte VOICE, 20
	.byte W14
	.byte N24, Cn3, v060
	.byte W05
	.byte W19
	.byte VOICE, 21
	.byte VOL, 25
	.byte N04, Cn3, v072
	.byte W05
	.byte Cs4, v080 @ N04
	.byte W10
	.byte FINE

.align 2

track_561:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_561_0
	.word track_561_1
	.word track_561_2

.align 2
