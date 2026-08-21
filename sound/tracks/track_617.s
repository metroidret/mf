.align 2

.global track_617

track_617_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 103
	.byte PAN, c_v
	.byte BEND, c_v
	.byte W07
	.byte N10, Bn1, v100
	.byte W24
	.byte VOICE, 4
	.byte VOL, 17
	.byte BENDR, 12
	.byte BEND, c_v-25
	.byte N20, An2, v127
	.byte W02
	.byte VOL, 23
	.byte BEND, c_v-23
	.byte W02
	.byte VOL, 28
	.byte BEND, c_v-20
	.byte W02
	.byte VOL, 33
	.byte BEND, c_v-18
	.byte W02
	.byte VOL, 37
	.byte BEND, c_v-15
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v-12
	.byte W02
	.byte VOL, 44
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 46
	.byte BEND, c_v-7
	.byte W02
	.byte VOL, 49
	.byte BEND, c_v-4
	.byte W02
	.byte VOL, 51
	.byte BEND, c_v
	.byte W17
	.byte FINE

track_617_1:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 110
	.byte PAN, c_v
	.byte PRIO, 1
	.byte W24
	.byte W03
	.byte N10, An2, v100
	.byte W10
	.byte N28, Cn3, v127
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_617:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a7aa4
	.word track_617_0
	.word track_617_1

.align 2
