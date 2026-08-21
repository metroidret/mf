.align 2

.global track_223

track_223_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 47
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 7
	.byte MOD, 100
	.byte VOL, 25
	.byte LFOS, 30
	.byte N68, En1 @ v127
	.byte W68
	.byte W01
	.byte LFOS, 100
	.byte N72, An1 @ v127
	.byte W24
	.byte W36
	.byte VOL, 9
	.byte W06
	.byte 4 @ VOL
	.byte W07
	.byte FINE

track_223_1:
	.byte KEYSH, 0
	.byte VOICE, 7
	.byte VOL, 18
	.byte PAN, c_v
	.byte N03, An3, v080
	.byte W18
	.byte N03 @ An3, v080
	.byte W18
	.byte N03 @ An3, v080
	.byte W18
	.byte N03 @ An3, v080
	.byte W18
	.byte An3, v127 @ N03
	.byte W06
	.byte N03 @ An3, v127
	.byte W06
	.byte N03 @ An3, v127
	.byte W06
	.byte N03 @ An3, v127
	.byte W06
	.byte N03 @ An3, v127
	.byte W06
	.byte N03 @ An3, v127
	.byte W06
	.byte N03 @ An3, v127
	.byte W06
	.byte N03 @ An3, v127
	.byte W05
	.byte N03 @ An3, v127
	.byte W05
	.byte N03 @ An3, v127
	.byte W05
	.byte N03 @ An3, v127
	.byte W03
	.byte VOL, 9
	.byte W02
	.byte N03 @ An3, v127
	.byte W03
	.byte N03 @ An3, v127
	.byte W01
	.byte VOL, 4
	.byte W04
	.byte N03 @ An3, v127
	.byte W03
	.byte FINE

.align 2

track_223:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a6af0
	.word track_223_0
	.word track_223_1

.align 2
