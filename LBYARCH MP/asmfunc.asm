section .data
kilometer dd 1000.0
millisecond dd 3600.0

section .text
bits 64
default rel
global x64Acceleration

x64Acceleration:
;rcx = y
;rdx = array
;r8 = output

	xor r9, r9

	movss xmm1, [kilometer]
	movss xmm2, [millisecond]

L1:	movss xmm4, [rdx]
	add rdx, 4
	movss xmm5, [rdx]
	add rdx, 4
	movss xmm6, [rdx]
	add rdx, 4

	vsubss xmm7, xmm5, xmm4	 ;final - initial
	vmulss xmm8, xmm7, xmm1  ;velocity * 1000
	vdivss xmm9, xmm8, xmm2  ;m/s
	vdivss xmm10, xmm9, xmm6 ;aceleration
	cvtss2si r9D, xmm10		 ;round to integer

	mov [r8], r9D
	add r8, 4

	LOOP L1

	ret