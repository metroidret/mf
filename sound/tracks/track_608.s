.align 2

.global track_608

track_608_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 31
	.byte PAN, c_v
	.byte N03, Cn3, v127
	.byte W03
	.byte VOICE, 16
	.byte MOD, 100
	.byte VOL, 17
	.byte LFOS, 30
	.byte N68, En1 @ v127
	.byte W68
	.byte W01
	.byte LFOS, 100
	.byte N72, An1 @ v127
	.byte W24
	.byte W36
	.byte VOL, 6
	.byte W06
	.byte 3 @ VOL
	.byte W07
	.byte FINE

track_608_1:
	.byte KEYSH, 0
	.byte VOICE, 16
	.byte VOL, 12
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
	.byte VOL, 6
	.byte W02
	.byte N03 @ An3, v127
	.byte W03
	.byte N03 @ An3, v127
	.byte W01
	.byte VOL, 3
	.byte W04
	.byte N03 @ An3, v127
	.byte W03
	.byte FINE

.align 2

track_608:
	.byte 2
	.byte 0
	.byte 185
	.byte 0
	.word 0x80a7654
	.word track_608_0
	.word track_608_1

.align 2
