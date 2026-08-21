.align 2

.global track_587

track_587_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 104
	.byte VOL, 127
	.byte BENDR, 12
	.byte BEND, c_v
	.byte W96
	.byte W96
	.byte W12
	.byte TIE, Cn3, v127
	.byte W84
	.byte W48
	.byte W02
	.byte VOL, 64
	.byte W44
	.byte W02
	.byte W02
	.byte 64 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W03
	.byte 62 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W04
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W03
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W04
	.byte 56 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W03
	.byte 54 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W04
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W04
	.byte 48 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W03
	.byte 46 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W04
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W04
	.byte 40 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W03
	.byte 38 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W04
	.byte 36 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W03
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W04
	.byte 32 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W04
	.byte 28 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W03
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W04
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W03
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W04
	.byte 20 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W04
	.byte 16 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W03
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W03
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W04
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W04
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W04
	.byte EOT @ Cn3, v127
	.byte VOL, 0
	.byte W40
	.byte FINE

track_587_1:
	.byte KEYSH, 0
	.byte VOICE, 105
	.byte VOL, 127
	.byte W96
	.byte W96
	.byte W12
	.byte N24, Cn1, v108
	.byte W24
	.byte Cs1, v080 @ N24
	.byte W24
	.byte Dn1, v064 @ N24
	.byte W24
	.byte Ds1, v032 @ N24
	.byte W12
	.byte W12
	.byte En1, v016 @ N24
	.byte W36
	.byte W02
	.byte TIE, Dn1, v024
	.byte W44
	.byte W02
	.byte W96
	.byte W02
	.byte EOT @ Dn1, v024
	.byte N24, Dn1, v016
	.byte W24
	.byte Dn1, v008 @ N24
	.byte W64
	.byte FINE

track_587_2:
	.byte KEYSH, 0
	.byte VOICE, 106
	.byte VOL, 127
	.byte W96
	.byte W96
	.byte W12
	.byte TIE, Cn3, v108
	.byte W84
	.byte W60
	.byte EOT @ Cn3, v108
	.byte W36
	.byte W96
	.byte W90
	.byte FINE

track_587_3:
	.byte KEYSH, 0
	.byte VOICE, 80
	.byte VOL, 127
	.byte BENDR, 60
	.byte W96
	.byte W96
	.byte W12
	.byte BEND, c_v
	.byte TIE, Gn0, v016
	.byte W01
	.byte BEND, c_v
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+3 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+7 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+11 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+13 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+16 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+17 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+18 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+19 @ BEND
	.byte W01
	.byte c_v+20 @ BEND
	.byte W01
	.byte VOL, 127
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 125
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 124
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 123
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 121
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 120
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 119
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 117
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 116
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 115
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 113
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 112
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 111
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 109
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 108
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 107
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 105
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 104
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 103
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 101
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 100
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 97
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 96
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 95
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 93
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 92
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 91
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 89
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 88
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 87
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 85
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 83
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 82
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 72
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 71
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 67
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 64
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 54
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+55
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+57
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+58
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+59
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+60
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+60
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v+61
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+61
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v+62
	.byte W01
	.byte EOT @ Gn0, v016
	.byte VOL, 0
	.byte BEND, c_v+62
	.byte W36
	.byte W96
	.byte W90
	.byte FINE

track_587_4:
	.byte KEYSH, 0
	.byte VOICE, 112
	.byte VOL, 127
	.byte BEND, c_v
	.byte W96
	.byte W96
	.byte W12
	.byte TIE, Dn3, v127
	.byte W84
	.byte W48
	.byte W02
	.byte BEND, c_v-32
	.byte W44
	.byte W02
	.byte W96
	.byte W48
	.byte W01
	.byte EOT @ Dn3, v127
	.byte W40
	.byte W01
	.byte FINE

track_587_5:
	.byte KEYSH, 0
	.byte VOICE, 110
	.byte VOL, 127
	.byte BENDR, 12
	.byte W96
	.byte W09
	.byte N92, Dn3, v012
	.byte W44
	.byte W03
	.byte VOL, 127
	.byte W01
	.byte 124 @ VOL
	.byte W01
	.byte 121 @ VOL
	.byte W01
	.byte 119 @ VOL
	.byte W01
	.byte 116 @ VOL
	.byte W01
	.byte 113 @ VOL
	.byte W01
	.byte 111 @ VOL
	.byte W01
	.byte 108 @ VOL
	.byte W01
	.byte 105 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 100 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W88
	.byte W96
	.byte W96
	.byte W90
	.byte FINE

track_587_6:
	.byte KEYSH, 0
	.byte VOICE, 11
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W96
	.byte W96
	.byte W02
	.byte VOL, 0
	.byte TIE, An2, v040
	.byte W01
	.byte VOL, 2
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 39 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 55 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 63 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 79 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 87 @ VOL
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 95 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 100 @ VOL
	.byte W01
	.byte 103 @ VOL
	.byte W01
	.byte 105 @ VOL
	.byte W01
	.byte 108 @ VOL
	.byte W01
	.byte 111 @ VOL
	.byte W01
	.byte 113 @ VOL
	.byte W01
	.byte 116 @ VOL
	.byte W01
	.byte 119 @ VOL
	.byte W01
	.byte 121 @ VOL
	.byte W01
	.byte 124 @ VOL
	.byte W01
	.byte 127 @ VOL
	.byte W44
	.byte W02
	.byte W48
	.byte W02
	.byte 54 @ VOL
	.byte BEND, c_v+54
	.byte W44
	.byte W02
	.byte W92
	.byte VOL, 54
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W02
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W03
	.byte 48 @ VOL
	.byte W01
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W03
	.byte 45 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W03
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W04
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W03
	.byte 36 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W03
	.byte 33 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte W03
	.byte 30 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W04
	.byte 27 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W03
	.byte 24 @ VOL
	.byte W01
	.byte 23 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W03
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W03
	.byte 15 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W04
	.byte 12 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W03
	.byte 9 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W04
	.byte EOT @ An2, v040
	.byte VOL, 0
	.byte FINE

track_587_7:
	.byte KEYSH, 0
	.byte VOICE, 112
	.byte VOL, 127
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte W02
	.byte TIE, En2, v064
	.byte W44
	.byte W02
	.byte VOL, 127
	.byte W01
	.byte 126 @ VOL
	.byte W01
	.byte 125 @ VOL
	.byte W01
	.byte 124 @ VOL
	.byte W01
	.byte 123 @ VOL
	.byte W01
	.byte 122 @ VOL
	.byte W01
	.byte 121 @ VOL
	.byte W01
	.byte 120 @ VOL
	.byte W02
	.byte 119 @ VOL
	.byte W01
	.byte 118 @ VOL
	.byte W01
	.byte 117 @ VOL
	.byte W01
	.byte 116 @ VOL
	.byte W01
	.byte 115 @ VOL
	.byte W01
	.byte 114 @ VOL
	.byte W01
	.byte 113 @ VOL
	.byte W01
	.byte 112 @ VOL
	.byte W02
	.byte 111 @ VOL
	.byte W01
	.byte 110 @ VOL
	.byte W01
	.byte 109 @ VOL
	.byte W01
	.byte 108 @ VOL
	.byte W01
	.byte 107 @ VOL
	.byte W01
	.byte 106 @ VOL
	.byte W01
	.byte 105 @ VOL
	.byte W01
	.byte 104 @ VOL
	.byte W02
	.byte 103 @ VOL
	.byte W01
	.byte 102 @ VOL
	.byte W01
	.byte 101 @ VOL
	.byte W01
	.byte 100 @ VOL
	.byte W01
	.byte 99 @ VOL
	.byte W01
	.byte 98 @ VOL
	.byte W01
	.byte 97 @ VOL
	.byte W01
	.byte 96 @ VOL
	.byte W02
	.byte 95 @ VOL
	.byte W01
	.byte 94 @ VOL
	.byte W01
	.byte 93 @ VOL
	.byte W01
	.byte 92 @ VOL
	.byte W01
	.byte 91 @ VOL
	.byte W01
	.byte 90 @ VOL
	.byte W01
	.byte 89 @ VOL
	.byte W01
	.byte 88 @ VOL
	.byte W02
	.byte 87 @ VOL
	.byte W01
	.byte 86 @ VOL
	.byte W01
	.byte 85 @ VOL
	.byte W01
	.byte 84 @ VOL
	.byte W01
	.byte 83 @ VOL
	.byte W01
	.byte 82 @ VOL
	.byte W01
	.byte 81 @ VOL
	.byte W01
	.byte 80 @ VOL
	.byte W03
	.byte 79 @ VOL
	.byte W01
	.byte 78 @ VOL
	.byte W01
	.byte 77 @ VOL
	.byte W01
	.byte 76 @ VOL
	.byte W01
	.byte 75 @ VOL
	.byte W01
	.byte 74 @ VOL
	.byte W01
	.byte 73 @ VOL
	.byte W01
	.byte 72 @ VOL
	.byte W02
	.byte 71 @ VOL
	.byte W01
	.byte 70 @ VOL
	.byte W01
	.byte 69 @ VOL
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 67 @ VOL
	.byte W01
	.byte 66 @ VOL
	.byte W01
	.byte 65 @ VOL
	.byte W01
	.byte 64 @ VOL
	.byte W02
	.byte 63 @ VOL
	.byte W01
	.byte 62 @ VOL
	.byte W01
	.byte 61 @ VOL
	.byte W01
	.byte 60 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 58 @ VOL
	.byte W01
	.byte 57 @ VOL
	.byte W01
	.byte 56 @ VOL
	.byte W02
	.byte 55 @ VOL
	.byte W01
	.byte 54 @ VOL
	.byte W01
	.byte 53 @ VOL
	.byte W01
	.byte 52 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 50 @ VOL
	.byte W01
	.byte 49 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W02
	.byte 47 @ VOL
	.byte W01
	.byte 46 @ VOL
	.byte W01
	.byte 45 @ VOL
	.byte W01
	.byte 44 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 42 @ VOL
	.byte W01
	.byte 41 @ VOL
	.byte W01
	.byte 40 @ VOL
	.byte W03
	.byte 39 @ VOL
	.byte W01
	.byte 38 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 36 @ VOL
	.byte W01
	.byte 35 @ VOL
	.byte W01
	.byte 34 @ VOL
	.byte W01
	.byte 33 @ VOL
	.byte W01
	.byte 32 @ VOL
	.byte W02
	.byte 31 @ VOL
	.byte W01
	.byte 30 @ VOL
	.byte W01
	.byte 29 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte W01
	.byte 27 @ VOL
	.byte W01
	.byte 26 @ VOL
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W02
	.byte 23 @ VOL
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 21 @ VOL
	.byte W01
	.byte 20 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 17 @ VOL
	.byte W01
	.byte 16 @ VOL
	.byte W02
	.byte 15 @ VOL
	.byte W01
	.byte 14 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 12 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 9 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W02
	.byte 7 @ VOL
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 4 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 1 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W02
	.byte EOT @ En2, v064
	.byte VOL, 0
	.byte W40
	.byte FINE

track_587_8:
	.byte KEYSH, 0
	.byte VOICE, 69
	.byte VOL, 127
	.byte BENDR, 24
	.byte BEND, c_v
	.byte W96
	.byte W96
	.byte W48
	.byte W02
	.byte PAN, c_v-34
	.byte BEND, c_v
	.byte TIE, Gn2, v032
	.byte W01
	.byte BEND, c_v
	.byte W01
	.byte c_v @ BEND
	.byte PAN, c_v-33
	.byte W01
	.byte BEND, c_v
	.byte W01
	.byte c_v+1 @ BEND
	.byte PAN, c_v-32
	.byte W01
	.byte BEND, c_v+1
	.byte W01
	.byte c_v+1 @ BEND
	.byte W01
	.byte c_v+2 @ BEND
	.byte PAN, c_v-31
	.byte W01
	.byte BEND, c_v+2
	.byte W01
	.byte c_v+2 @ BEND
	.byte PAN, c_v-30
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+3 @ BEND
	.byte PAN, c_v-29
	.byte W01
	.byte BEND, c_v+3
	.byte W01
	.byte c_v+4 @ BEND
	.byte W01
	.byte c_v+4 @ BEND
	.byte PAN, c_v-28
	.byte W01
	.byte BEND, c_v+4
	.byte W01
	.byte c_v+5 @ BEND
	.byte PAN, c_v-27
	.byte W01
	.byte BEND, c_v+5
	.byte W01
	.byte c_v+5 @ BEND
	.byte W01
	.byte c_v+6 @ BEND
	.byte PAN, c_v-26
	.byte W01
	.byte BEND, c_v+6
	.byte W01
	.byte c_v+6 @ BEND
	.byte PAN, c_v-25
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte c_v+7 @ BEND
	.byte PAN, c_v-24
	.byte W01
	.byte BEND, c_v+7
	.byte W01
	.byte c_v+8 @ BEND
	.byte W01
	.byte c_v+8 @ BEND
	.byte PAN, c_v-23
	.byte W01
	.byte BEND, c_v+8
	.byte W01
	.byte c_v+9 @ BEND
	.byte PAN, c_v-22
	.byte W01
	.byte BEND, c_v+9
	.byte W01
	.byte c_v+9 @ BEND
	.byte W01
	.byte PAN, c_v-21
	.byte BEND, c_v+10
	.byte W01
	.byte c_v+10 @ BEND
	.byte W01
	.byte c_v+10 @ BEND
	.byte PAN, c_v-20
	.byte W01
	.byte BEND, c_v+11
	.byte W01
	.byte c_v+11 @ BEND
	.byte PAN, c_v-19
	.byte W01
	.byte BEND, c_v+11
	.byte W01
	.byte c_v+12 @ BEND
	.byte W01
	.byte c_v+12 @ BEND
	.byte PAN, c_v-18
	.byte W01
	.byte BEND, c_v+12
	.byte W01
	.byte c_v+13 @ BEND
	.byte PAN, c_v-17
	.byte W01
	.byte BEND, c_v+13
	.byte W01
	.byte c_v+13 @ BEND
	.byte PAN, c_v-16
	.byte W01
	.byte BEND, c_v+13
	.byte W01
	.byte c_v+14 @ BEND
	.byte W01
	.byte c_v+14 @ BEND
	.byte PAN, c_v-15
	.byte W01
	.byte BEND, c_v+14
	.byte W01
	.byte c_v+15 @ BEND
	.byte PAN, c_v-14
	.byte W01
	.byte VOL, 127
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 125
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 124
	.byte BEND, c_v+16
	.byte PAN, c_v-13
	.byte W01
	.byte VOL, 123
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 122
	.byte BEND, c_v+16
	.byte PAN, c_v-12
	.byte W01
	.byte VOL, 121
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 120
	.byte BEND, c_v+17
	.byte PAN, c_v-11
	.byte W01
	.byte VOL, 119
	.byte BEND, c_v+17
	.byte W01
	.byte VOL, 118
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 117
	.byte BEND, c_v+18
	.byte PAN, c_v-10
	.byte W01
	.byte VOL, 116
	.byte BEND, c_v+18
	.byte W01
	.byte VOL, 115
	.byte BEND, c_v+19
	.byte PAN, c_v-9
	.byte W01
	.byte VOL, 114
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 113
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 112
	.byte PAN, c_v-8
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 111
	.byte BEND, c_v+20
	.byte W01
	.byte VOL, 110
	.byte BEND, c_v+20
	.byte PAN, c_v-7
	.byte W01
	.byte VOL, 109
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 107
	.byte BEND, c_v+21
	.byte PAN, c_v-6
	.byte W01
	.byte VOL, 106
	.byte BEND, c_v+21
	.byte W01
	.byte VOL, 105
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 104
	.byte BEND, c_v+22
	.byte PAN, c_v-5
	.byte W01
	.byte VOL, 103
	.byte BEND, c_v+22
	.byte W01
	.byte VOL, 102
	.byte BEND, c_v+23
	.byte PAN, c_v-4
	.byte W01
	.byte VOL, 101
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 100
	.byte BEND, c_v+23
	.byte PAN, c_v-3
	.byte W01
	.byte VOL, 99
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 98
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 97
	.byte BEND, c_v+24
	.byte PAN, c_v-2
	.byte W01
	.byte VOL, 96
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 95
	.byte BEND, c_v+25
	.byte PAN, c_v-1
	.byte W01
	.byte VOL, 94
	.byte BEND, c_v+25
	.byte W01
	.byte VOL, 93
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 92
	.byte BEND, c_v+26
	.byte PAN, c_v
	.byte W01
	.byte VOL, 91
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 89
	.byte BEND, c_v+27
	.byte PAN, c_v+1
	.byte W01
	.byte VOL, 88
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 87
	.byte BEND, c_v+27
	.byte PAN, c_v+2
	.byte W01
	.byte VOL, 86
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 85
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 84
	.byte BEND, c_v+28
	.byte PAN, c_v+3
	.byte W01
	.byte VOL, 83
	.byte BEND, c_v+28
	.byte W01
	.byte VOL, 82
	.byte BEND, c_v+29
	.byte PAN, c_v+4
	.byte W01
	.byte VOL, 81
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 80
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 79
	.byte PAN, c_v+5
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 78
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 77
	.byte BEND, c_v+30
	.byte PAN, c_v+6
	.byte W01
	.byte VOL, 76
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 75
	.byte BEND, c_v+31
	.byte PAN, c_v+7
	.byte W01
	.byte VOL, 74
	.byte BEND, c_v+31
	.byte W01
	.byte VOL, 73
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 71
	.byte BEND, c_v+32
	.byte PAN, c_v+8
	.byte W01
	.byte VOL, 70
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 69
	.byte BEND, c_v+33
	.byte PAN, c_v+9
	.byte W01
	.byte VOL, 68
	.byte BEND, c_v+33
	.byte W01
	.byte VOL, 67
	.byte BEND, c_v+33
	.byte PAN, c_v+10
	.byte W01
	.byte VOL, 66
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 65
	.byte BEND, c_v+34
	.byte W01
	.byte VOL, 64
	.byte BEND, c_v+34
	.byte PAN, c_v+11
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 62
	.byte BEND, c_v+35
	.byte PAN, c_v+12
	.byte W01
	.byte VOL, 61
	.byte BEND, c_v+35
	.byte W01
	.byte VOL, 60
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 59
	.byte BEND, c_v+36
	.byte PAN, c_v+13
	.byte W01
	.byte VOL, 58
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 57
	.byte BEND, c_v+37
	.byte PAN, c_v+14
	.byte W01
	.byte VOL, 56
	.byte BEND, c_v+37
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+37
	.byte PAN, c_v+15
	.byte W01
	.byte VOL, 53
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 52
	.byte BEND, c_v+38
	.byte W01
	.byte VOL, 51
	.byte BEND, c_v+38
	.byte PAN, c_v+16
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v+39
	.byte PAN, c_v+17
	.byte W01
	.byte VOL, 48
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 46
	.byte BEND, c_v+40
	.byte PAN, c_v+18
	.byte W01
	.byte VOL, 45
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 44
	.byte BEND, c_v+41
	.byte PAN, c_v+19
	.byte W01
	.byte VOL, 43
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 42
	.byte BEND, c_v+41
	.byte PAN, c_v+20
	.byte W01
	.byte VOL, 41
	.byte BEND, c_v+41
	.byte W01
	.byte VOL, 40
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+42
	.byte PAN, c_v+21
	.byte W01
	.byte VOL, 38
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v+43
	.byte PAN, c_v+22
	.byte W01
	.byte VOL, 35
	.byte BEND, c_v+43
	.byte W01
	.byte VOL, 34
	.byte BEND, c_v+43
	.byte PAN, c_v+23
	.byte W01
	.byte VOL, 33
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 32
	.byte BEND, c_v+44
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+44
	.byte PAN, c_v+24
	.byte W01
	.byte VOL, 30
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 29
	.byte BEND, c_v+45
	.byte PAN, c_v+25
	.byte W01
	.byte VOL, 28
	.byte BEND, c_v+45
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+46
	.byte PAN, c_v+26
	.byte W01
	.byte VOL, 25
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 24
	.byte BEND, c_v+47
	.byte PAN, c_v+27
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+47
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+47
	.byte PAN, c_v+28
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 20
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+48
	.byte PAN, c_v+29
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 16
	.byte BEND, c_v+49
	.byte PAN, c_v+30
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v+50
	.byte PAN, c_v+31
	.byte W01
	.byte VOL, 12
	.byte BEND, c_v+50
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v+51
	.byte PAN, c_v+32
	.byte W01
	.byte VOL, 10
	.byte BEND, c_v+51
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v+51
	.byte PAN, c_v+33
	.byte W01
	.byte VOL, 8
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v+52
	.byte PAN, c_v+34
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v+53
	.byte PAN, c_v+35
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v+53
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v+54
	.byte W01
	.byte VOL, 1
	.byte PAN, c_v+36
	.byte BEND, c_v+54
	.byte W01
	.byte EOT @ Gn2, v032
	.byte W68
	.byte W02
	.byte W90
	.byte FINE

.align 2

track_587:
	.byte 9
	.byte 0
	.byte 254
	.byte 128
	.word 0x80a8554
	.word track_587_0
	.word track_587_1
	.word track_587_2
	.word track_587_3
	.word track_587_4
	.word track_587_5
	.word track_587_6
	.word track_587_7
	.word track_587_8

.align 2
